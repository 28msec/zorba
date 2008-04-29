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
#line 753 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 51 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"

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
#line 653 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).decval; };
#line 211 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 80: /* "\"'DOUBLE'\"" */
#line 652 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).dval; };
#line 216 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 111: /* "\"'INTEGER'\"" */
#line 651 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).ival; };
#line 221 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "VersionDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "MainModule" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "LibraryModule" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "ModuleDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "Prolog" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "SIND_DeclList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "VFO_DeclList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "SIND_Decl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "VFO_Decl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "Setter" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "Import" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "NamespaceDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "BoundarySpaceDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "DefaultNamespaceDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "OptionDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "OrderingModeDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "EmptyOrderDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "CopyNamespacesDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "DefaultCollationDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "BaseURIDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "SchemaImport" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "URILiteralList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "SchemaPrefix" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "ModuleImport" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "VarDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 346 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "ConstructionDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "FunctionDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 356 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "ParamList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 361 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "Param" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 366 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "EnclosedExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 371 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "NonNodeEnclosedExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 376 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "QueryBody" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 381 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "Expr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 386 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "ExprSingle" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 391 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "FLWORExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 396 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "ForLetClauseList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 401 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "ForLetClause" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 406 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "ForClause" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 411 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "VarInDeclList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 416 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VarInDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 421 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "PositionalVar" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 426 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "LetClause" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 431 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "VarGetsDeclList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 436 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "EvalVarDeclList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 441 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "VarGetsDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 446 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "EvalVarDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 451 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "WhereClause" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 456 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "GroupByClause" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 461 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "GroupSpecList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 466 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "GroupSpec" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 471 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "GroupCollationSpec" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "LetClauseList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 481 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "OrderByClause" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 486 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "OrderSpecList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 491 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "OrderSpec" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 496 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "OrderModifier" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 501 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "OrderDirSpec" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 506 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "OrderEmptySpec" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 511 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "OrderCollationSpec" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 516 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "QuantifiedExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 521 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "QVarInDeclList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "QVarInDecl" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "TypeswitchExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 536 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CaseClauseList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CaseClause" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "IfExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 551 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "OrExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 556 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "AndExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 561 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "ComparisonExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 566 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "RangeExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 571 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "AdditiveExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 576 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "MultiplicativeExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 581 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "UnionExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 586 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IntersectExceptExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 591 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "InstanceofExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 596 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "TreatExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 601 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "CastableExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 606 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "CastExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 611 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "UnaryExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 616 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "SignList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 621 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ValueExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "GeneralComp" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 631 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "ValueComp" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 636 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "NodeComp" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 641 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "ValidateExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 646 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "ExtensionExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 651 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "PragmaList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 656 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "Pragma" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 661 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "PathExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 666 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "RelativePathExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 671 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "StepExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 676 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "AxisStep" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 681 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ForwardStep" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 686 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "ForwardAxis" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 691 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "AbbrevForwardStep" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 696 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ReverseStep" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 701 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "ReverseAxis" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 706 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "NodeTest" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 711 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "NameTest" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 716 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "Wildcard" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 721 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "FilterExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 726 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "PredicateList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 731 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Predicate" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 736 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "PrimaryExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 741 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "Literal" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 746 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "NumericLiteral" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 751 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "VarRef" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 756 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ParenthesizedExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 761 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ContextItemExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 766 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "OrderedExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 771 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "UnorderedExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 776 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "FunctionCall" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 781 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ArgList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 786 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "Constructor" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 791 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "DirectConstructor" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 796 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "DirElemConstructor" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 801 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "DirElemContentList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 806 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "DirAttributeList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 811 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "DirAttr" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 816 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "DirAttributeValue" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 821 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "Opt_QuoteAttrContentList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 826 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "QuoteAttrContentList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 831 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "Opt_AposAttrContentList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 836 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "AposAttrContentList" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 841 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "QuoteAttrValueContent" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 846 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "AposAttrValueContent" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 851 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "DirElemContent" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 856 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "CommonContent" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 861 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "DirCommentConstructor" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 866 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "DirPIConstructor" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 871 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "CDataSection" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 876 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "ComputedConstructor" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 881 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "CompDocConstructor" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 886 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "CompElemConstructor" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 891 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "CompAttrConstructor" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 896 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "CompTextConstructor" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 901 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "CompCommentConstructor" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 906 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "CompPIConstructor" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 911 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "SingleType" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 916 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "TypeDeclaration" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 921 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "SequenceType" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 926 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "OccurrenceIndicator" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 931 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "ItemType" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 936 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "AtomicType" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 941 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "KindTest" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 946 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "AnyKindTest" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 951 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "DocumentTest" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 956 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "TextTest" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 961 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "CommentTest" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 966 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "PITest" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 971 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "AttributeTest" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 976 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "SchemaAttributeTest" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 981 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "ElementTest" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 986 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "SchemaElementTest" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 991 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "TypeName" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 996 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "TypeName_WITH_HOOK" */
#line 657 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 1001 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "StringLiteral" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1006 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "TryExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1011 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "CatchListExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1016 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "CatchExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1021 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "EvalExpr" */
#line 658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1026 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 84 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}
  /* Line 547 of yacc.c.  */
#line 1107 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
#line 774 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 3:
#line 782 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 791 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]" << endl;
#endif
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 5:
#line 798 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]" << endl;
#endif
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		;}
    break;

  case 6:
#line 812 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]" << endl;
#endif
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), encoding);
		;}
    break;

  case 7:
#line 820 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]" << endl;
#endif
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (2)].sval)), SYMTAB ((yysemantic_stack_[(5) - (4)].sval)));
    ;}
    break;

  case 8:
#line 833 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 843 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 858 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 873 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 888 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 897 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 906 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 921 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 930 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 947 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 956 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 973 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 980 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 987 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 994 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 1006 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 1013 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 1020 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 1029 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 1042 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 1049 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 1056 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1063 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1070 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1077 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1084 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1093 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1106 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1113 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1131 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1146 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1154 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1168 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1177 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1192 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1208 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]" << endl;
#endif
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1222 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1230 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1245 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1253 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1267 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1276 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1285 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1294 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1316 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]" << endl;
#endif
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1330 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]" << endl;
#endif
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1344 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1354 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1364 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1374 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1390 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1399 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1417 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1424 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 62:
#line 1437 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1446 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1456 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1465 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1482 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1492 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1502 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1512 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1528 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1536 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1550 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1560 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1571 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1582 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1594 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1606 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1618 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1630 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1642 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1652 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1663 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1674 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1686 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1698 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1710 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1722 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1740 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1751 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1768 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1777 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1792 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1803 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NonNodeEnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 94:
#line 1817 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]" << endl;
#endif
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 95:
#line 1831 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1840 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1855 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1862 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1869 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1876 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1883 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1892 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1899 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1906 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1913 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1920 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 107:
#line 1927 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
      cout << "ExprSingle [TryExpr]" << endl;
#endif
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 108:
#line 1934 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 109:
#line 1944 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1954 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1965 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1976 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1988 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2003 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2018 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2033 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2054 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2063 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2078 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 120:
#line 2085 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 121:
#line 2098 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]" << endl;
#endif
			(yyval.node) = new ForClause(LOC ((yyloc)),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 122:
#line 2112 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2121 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2138 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2148 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2159 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2171 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2184 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2195 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2207 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2219 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2237 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]" << endl;
#endif
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 133:
#line 2252 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]" << endl;
#endif
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 134:
#line 2266 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]" << endl;
#endif
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 135:
#line 2281 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2290 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2305 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2314 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2331 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2342 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2354 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2365 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2380 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 144:
#line 2384 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name));
                           
    ;}
    break;

  case 145:
#line 2398 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]" << endl;
#endif
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 146:
#line 2409 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2419 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2429 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2439 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2452 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2461 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2475 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2484 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2496 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupCollationSpec [ ]" << endl;
#endif
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 155:
#line 2506 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2516 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2531 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]" << endl;
#endif
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 158:
#line 2539 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2554 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2563 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2580 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2589 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2604 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2614 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2624 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2644 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2654 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2664 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2680 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 171:
#line 2687 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 172:
#line 2700 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 173:
#line 2708 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 174:
#line 2722 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]" << endl;
#endif
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 175:
#line 2736 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2746 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2762 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2772 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2787 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2796 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2812 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2822 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2839 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2848 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2863 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2872 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2888 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]" << endl;
#endif
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 188:
#line 2902 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 189:
#line 2909 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]" << endl;
#endif
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 190:
#line 2923 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 191:
#line 2930 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]" << endl;
#endif
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 192:
#line 2952 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 193:
#line 2959 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2970 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2981 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2998 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 197:
#line 3005 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3015 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3031 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 200:
#line 3038 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]" << endl;
#endif
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 201:
#line 3052 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 202:
#line 3059 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 203:
#line 3066 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 204:
#line 3079 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]" << endl;
#endif
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 205:
#line 3086 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 206:
#line 3093 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 207:
#line 3100 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 208:
#line 3107 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 209:
#line 3120 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 3127 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 211:
#line 3135 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 212:
#line 3149 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 213:
#line 3156 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 214:
#line 3163 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 215:
#line 3176 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 216:
#line 3183 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3198 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 218:
#line 3205 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3220 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 220:
#line 3227 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3242 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 222:
#line 3249 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3264 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 224:
#line 3271 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3286 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]" << endl;
#endif
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 226:
#line 3293 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]" << endl;
#endif
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 227:
#line 3300 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 228:
#line 3307 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3322 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 230:
#line 3329 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 231:
#line 3336 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 232:
#line 3350 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq);
		;}
    break;

  case 233:
#line 3357 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne);
		;}
    break;

  case 234:
#line 3364 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt);
		;}
    break;

  case 235:
#line 3371 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_le);
		;}
    break;

  case 236:
#line 3378 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt);
		;}
    break;

  case 237:
#line 3385 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge);
		;}
    break;

  case 238:
#line 3398 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 239:
#line 3405 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 240:
#line 3412 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 241:
#line 3419 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 242:
#line 3426 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 243:
#line 3433 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 244:
#line 3446 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 245:
#line 3453 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 246:
#line 3460 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 247:
#line 3474 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 248:
#line 3481 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3496 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3505 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3520 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3529 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3546 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3554 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 255:
#line 3597 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 256:
#line 3604 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 257:
#line 3611 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 258:
#line 3618 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3648 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 261:
#line 3656 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 262:
#line 3669 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 263:
#line 3676 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 264:
#line 3689 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3698 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3707 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3716 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3731 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3740 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]" << endl;
#endif
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 270:
#line 3754 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 271:
#line 3761 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 272:
#line 3768 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 273:
#line 3775 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 274:
#line 3782 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 275:
#line 3789 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 276:
#line 3796 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 277:
#line 3809 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 278:
#line 3816 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 279:
#line 3829 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3838 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3853 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 282:
#line 3860 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 283:
#line 3867 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 284:
#line 3874 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 285:
#line 3881 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 286:
#line 3899 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 287:
#line 3906 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 288:
#line 3919 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]" << endl;
#endif
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 289:
#line 3926 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]" << endl;
#endif
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 290:
#line 3939 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3949 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3959 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3975 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]" << endl;
#endif
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 294:
#line 3982 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3997 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4006 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4023 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 298:
#line 4037 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 4044 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 4051 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 4058 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 4065 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 4072 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 304:
#line 4079 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 305:
#line 4086 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 306:
#line 4099 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 307:
#line 4106 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 308:
#line 4119 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.decval);
      delete yylval.decval;
		;}
    break;

  case 309:
#line 4127 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.ival);
      delete yylval.ival;
		;}
    break;

  case 310:
#line 4135 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.dval);
      delete yylval.dval;
		;}
    break;

  case 311:
#line 4149 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]" << endl;
#endif
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 312:
#line 4162 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 313:
#line 4169 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 314:
#line 4183 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]" << endl;
#endif
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 315:
#line 4196 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 316:
#line 4210 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 317:
#line 4269 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4278 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4293 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4302 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4317 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 322:
#line 4324 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 323:
#line 4337 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 324:
#line 4344 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 325:
#line 4351 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 326:
#line 4364 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4375 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4386 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4397 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4408 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4419 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4437 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4446 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4461 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4470 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4487 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4502 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 338:
#line 4510 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 339:
#line 4524 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]" << endl;
#endif
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 340:
#line 4531 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 341:
#line 4538 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4547 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4556 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4567 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4584 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 346:
#line 4591 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 347:
#line 4598 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4607 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4616 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4627 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4644 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 352:
#line 4652 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 353:
#line 4666 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 354:
#line 4674 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 355:
#line 4688 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]" << endl;
#endif
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 356:
#line 4696 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]" << endl;
#endif
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 357:
#line 4704 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4713 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4728 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4737 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 361:
#line 4745 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 362:
#line 4753 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 363:
#line 4767 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]" << endl;
#endif
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 364:
#line 4775 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "DirCommentConstructor [ ]" << endl;
#endif
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 365:
#line 4793 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 366:
#line 4801 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4821 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]" << endl;
#endif
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 368:
#line 4839 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 369:
#line 4846 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 370:
#line 4853 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 371:
#line 4860 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 372:
#line 4867 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 373:
#line 4874 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 374:
#line 4887 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 375:
#line 4901 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4910 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4919 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 378:
#line 4927 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 379:
#line 4955 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4964 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4973 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 382:
#line 4981 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 383:
#line 4995 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 384:
#line 5009 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 385:
#line 5023 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5032 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5041 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 388:
#line 5049 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 389:
#line 5063 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5072 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5087 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]" << endl;
#endif
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 392:
#line 5101 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5110 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5119 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 395:
#line 5159 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 396:
#line 5167 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 397:
#line 5175 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 398:
#line 5189 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 399:
#line 5196 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 400:
#line 5203 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]" << endl;
#endif
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 401:
#line 5216 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]" << endl;
#endif
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 402:
#line 5230 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 403:
#line 5237 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 404:
#line 5244 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 405:
#line 5251 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 406:
#line 5258 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 407:
#line 5265 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 408:
#line 5272 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 409:
#line 5279 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 410:
#line 5286 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 411:
#line 5299 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]" << endl;
#endif
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 412:
#line 5312 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 413:
#line 5319 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 414:
#line 5327 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 415:
#line 5341 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]" << endl;
#endif
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 416:
#line 5354 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]" << endl;
#endif
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 417:
#line 5367 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 418:
#line 5374 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 419:
#line 5381 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 420:
#line 5394 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5403 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5412 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5421 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5430 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5445 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 426:
#line 5459 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5468 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5477 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5486 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5495 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5505 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5515 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5531 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 434:
#line 5555 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]" << endl;
#endif
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 435:
#line 5565 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5588 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]" << endl;
#endif
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 437:
#line 5631 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [strict]" << endl;
#endif
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 438:
#line 5639 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [lax]" << endl;
#endif
    ;}
    break;

  case 439:
#line 5645 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [skip]" << endl;
#endif
    ;}
    break;

  case 440:
#line 5656 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5665 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5674 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5683 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5692 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5702 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5711 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5720 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5729 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5738 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5753 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodeExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 451:
#line 5761 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodesExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 452:
#line 5774 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5783 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5798 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 455:
#line 5827 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]" << endl;
#endif
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(6) - (2)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(6) - (4)].expr), (yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 456:
#line 5841 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5850 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5866 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "VarNameDecl [" << driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)) << "]" << endl;
#endif
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 459:
#line 5883 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TryExpr []" << endl;
#endif
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 460:
#line 5893 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5903 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5917 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5927 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5947 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(5) - (2)].node)),
                          (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 465:
#line 5953 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(3) - (2)].expr));
    ;}
    break;

  case 466:
#line 5970 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]" << endl;
#endif
		;}
    break;

  case 467:
#line 5976 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]" << endl;
#endif
		;}
    break;

  case 468:
#line 5982 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]" << endl;
#endif
		;}
    break;

  case 469:
#line 5988 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]" << endl;
#endif
		;}
    break;

  case 470:
#line 6000 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]" << endl;
#endif
		;}
    break;

  case 471:
#line 6006 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]" << endl;
#endif
		;}
    break;

  case 472:
#line 6012 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]" << endl;
#endif
		;}
    break;

  case 473:
#line 6018 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]" << endl;
#endif
		;}
    break;

  case 474:
#line 6030 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]" << endl;
#endif
		;}
    break;

  case 475:
#line 6036 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]" << endl;
#endif
		;}
    break;

  case 476:
#line 6048 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]" << endl;
#endif
		;}
    break;

  case 477:
#line 6054 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]" << endl;
#endif
		;}
    break;

  case 478:
#line 6066 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]" << endl;
#endif
		;}
    break;

  case 479:
#line 6072 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]" << endl;
#endif
		;}
    break;

  case 480:
#line 6084 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]" << endl;
#endif
		;}
    break;

  case 481:
#line 6090 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]" << endl;
#endif
		;}
    break;

  case 482:
#line 6102 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]" << endl;
#endif
		;}
    break;

  case 483:
#line 6108 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]" << endl;
#endif
		;}
    break;

  case 484:
#line 6114 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]" << endl;
#endif
		;}
    break;

  case 485:
#line 6126 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]" << endl;
#endif
		;}
    break;

  case 486:
#line 6132 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]" << endl;
#endif
		;}
    break;

  case 487:
#line 6144 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]" << endl;
#endif
		;}
    break;

  case 488:
#line 6150 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]" << endl;
#endif
		;}
    break;

  case 489:
#line 6162 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]" << endl;
#endif
		;}
    break;

  case 490:
#line 6168 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]" << endl;
#endif
		;}
    break;

  case 491:
#line 6174 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]" << endl;
#endif
		;}
    break;

  case 492:
#line 6180 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]" << endl;
#endif
		;}
    break;

  case 493:
#line 6186 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]" << endl;
#endif
		;}
    break;

  case 494:
#line 6198 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]" << endl;
#endif
		;}
    break;

  case 495:
#line 6210 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 496:
#line 6217 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 497:
#line 6224 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 498:
#line 6231 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 499:
#line 6238 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 500:
#line 6245 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 501:
#line 6252 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 502:
#line 6265 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]" << endl;
#endif
		;}
    break;

  case 503:
#line 6271 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]" << endl;
#endif
		;}
    break;

  case 504:
#line 6277 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]" << endl;
#endif
		;}
    break;

  case 505:
#line 6283 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]" << endl;
#endif
		;}
    break;

  case 506:
#line 6295 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]" << endl;
#endif
		;}
    break;

  case 507:
#line 6301 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]" << endl;
#endif
		;}
    break;

  case 508:
#line 6307 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]" << endl;
#endif
		;}
    break;

  case 509:
#line 6313 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]" << endl;
#endif
		;}
    break;

  case 510:
#line 6325 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]" << endl;
#endif
		;}
    break;

  case 511:
#line 6331 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]" << endl;
#endif
		;}
    break;

  case 512:
#line 6343 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]" << endl;
#endif
		;}
    break;

  case 513:
#line 6349 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]" << endl;
#endif
		;}
    break;

  case 514:
#line 6355 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]" << endl;
#endif
		;}
    break;

  case 515:
#line 6361 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]" << endl;
#endif
		;}
    break;

  case 516:
#line 6367 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]" << endl;
#endif
		;}
    break;

  case 517:
#line 6373 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]" << endl;
#endif
		;}
    break;

  case 518:
#line 6379 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]" << endl;
#endif
		;}
    break;

  case 519:
#line 6391 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]" << endl;
#endif
		;}
    break;

  case 520:
#line 6397 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]" << endl;
#endif
		;}
    break;

  case 521:
#line 6409 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]" << endl;
#endif
		;}
    break;

  case 522:
#line 6415 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]" << endl;
#endif
		;}
    break;

  case 523:
#line 6421 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]" << endl;
#endif
		;}
    break;

  case 524:
#line 6427 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]" << endl;
#endif
		;}
    break;

  case 525:
#line 6439 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]" << endl;
#endif
		;}
    break;

  case 526:
#line 6445 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]" << endl;
#endif
		;}
    break;

  case 527:
#line 6451 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]" << endl;
#endif
		;}
    break;

  case 528:
#line 6457 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]" << endl;
#endif
		;}
    break;

  case 529:
#line 6463 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]" << endl;
#endif
		;}
    break;

  case 530:
#line 6475 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 531:
#line 6481 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 532:
#line 6493 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]" << endl;
#endif
		;}
    break;

  case 533:
#line 6499 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]" << endl;
#endif
		;}
    break;

  case 534:
#line 6511 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 535:
#line 6517 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 536:
#line 6529 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]" << endl;
#endif
		;}
    break;

  case 537:
#line 6535 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]" << endl;
#endif
		;}
    break;

  case 538:
#line 6547 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]" << endl;
#endif
		;}
    break;

  case 539:
#line 6559 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]" << endl;
#endif
		;}
    break;

  case 540:
#line 6565 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]" << endl;
#endif
		;}
    break;

  case 541:
#line 6577 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]" << endl;
#endif
		;}
    break;

  case 542:
#line 6583 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]" << endl;
#endif
		;}
    break;

  case 543:
#line 6589 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]" << endl;
#endif
		;}
    break;

  case 544:
#line 6601 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]" << endl;
#endif
		;}
    break;

  case 545:
#line 6607 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]" << endl;
#endif
		;}
    break;

  case 546:
#line 6613 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]" << endl;
#endif
		;}
    break;

  case 547:
#line 6619 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]" << endl;
#endif
		;}
    break;

  case 548:
#line 6625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]" << endl;
#endif
		;}
    break;

  case 549:
#line 6637 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 550:
#line 6644 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 551:
#line 6651 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 552:
#line 6658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 553:
#line 6671 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]" << endl;
#endif
		;}
    break;

  case 554:
#line 6683 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]" << endl;
#endif
		;}
    break;

  case 555:
#line 6695 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]" << endl;
#endif
		;}
    break;

  case 556:
#line 6707 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]" << endl;
#endif
		;}
    break;

  case 557:
#line 6713 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]" << endl;
#endif
		;}
    break;

  case 558:
#line 6725 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]" << endl;
#endif
		;}
    break;

  case 559:
#line 6731 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]" << endl;
#endif
		;}
    break;

  case 560:
#line 6737 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 561:
#line 6749 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]" << endl;
#endif
		;}
    break;

  case 562:
#line 6755 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 563:
#line 6767 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ ]" << endl;
#endif
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 7449 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -683;
  const short int
  xquery_parser::yypact_[] =
  {
       778,  1200,  1411,  -683,  -683,   -24,  -683,   -16,  -683,  -683,
    -683,  3099,    72,  1087,  -683,  3099,   -39,  -683,   308,   -45,
     165,   185,   337,    -3,    13,   366,   121,   150,   349,   -31,
     358,   439,  -683,  -683,  3099,   359,   443,  -683,  -683,  -683,
    3099,    73,   471,  -683,  -683,   479,  3099,   144,    47,  -683,
     482,  1622,  -683,   496,   236,  3099,  -683,   498,    64,  -683,
     533,  -683,  -683,    62,   493,   501,  -683,  3641,  3479,   471,
    -683,   507,  3099,   371,  3099,  3099,  3099,    15,   494,   370,
    3099,  3099,  3099,  3099,  3099,  3099,  3099,   518,   432,   530,
    3099,  3695,   558,   989,  -683,  -683,   374,  3099,   395,   398,
    -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,
    -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,
     522,  -683,  -683,   195,  -683,  -683,  -683,  -683,  -683,  -683,
     441,   551,  -683,  3821,   346,   -36,   221,   190,   400,  -683,
     480,   414,   556,   564,   565,  -683,  -683,  -683,   -19,  -683,
    -683,  -683,   453,  -683,   499,  1087,  -683,   499,  1087,  -683,
    -683,  -683,  -683,   499,  -683,  -683,  -683,  -683,  -683,  -683,
    -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,
    -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,
    -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,
    -683,  -683,  -683,  -683,    95,  -683,    97,  1833,  3099,   130,
      84,  -683,    87,  -683,  -683,   132,  -683,  -683,  -683,  -683,
    -683,  -683,   561,   578,  -683,   604,   613,  -683,  -683,   523,
     560,   628,  -683,  -683,   538,   413,   135,  -683,   509,   515,
    -683,   140,    98,  -683,   102,   274,    14,  -683,    -7,   629,
    -683,   109,   647,   668,   649,   559,   672,   664,   -12,   642,
    -683,  -683,   111,   602,  -683,   141,   105,   534,   537,  -683,
     675,  -683,   583,  3099,   540,   542,  -683,  -683,    36,    24,
     142,  -683,   112,   143,   208,   506,  -683,   196,  -683,  -683,
    -683,  -683,  -683,   451,   454,   673,   488,   495,   614,   -11,
    -683,  3099,   -12,     9,  -683,  -683,   562,  -683,  -683,  -683,
    -683,   692,  -683,  -683,  -683,  -683,  -683,  -683,  -683,   186,
    -683,  -683,   297,   255,  -683,  -683,  -683,  -683,  -683,  -683,
    -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,   374,    -1,
    3099,  3099,   645,  3099,  3099,  3099,  -683,   181,   187,   563,
    3310,  3310,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,
    -683,  -683,  -683,  -683,  -683,  -683,  -683,  3310,  3310,  3310,
       3,  3310,  3310,  3310,  3310,  3310,  3310,  3310,  3310,  3310,
    3310,  3310,   516,   516,   703,   703,  -683,  -683,  -683,  2044,
    -683,  3479,  3479,  3099,   499,  -683,  -683,   499,  -683,   499,
    -683,  -683,  -683,  -683,   113,   220,   609,   705,  -683,   705,
    -683,  -683,    20,   219,  -683,  -683,   183,   701,  -683,   283,
     516,  -683,  3099,    37,  -683,  -683,  -683,   618,   714,  -683,
     714,  -683,  3099,   630,   660,  3099,   663,  3099,   666,   -18,
     635,    -5,   669,   567,   721,   658,   721,  -683,   661,   716,
    3099,   648,   -30,   676,  -683,   728,  -683,  -683,  -683,  -683,
    -683,  -683,  2255,   232,  -683,  -683,  3099,   665,  -683,    29,
      33,  -683,  -683,   717,  -683,  -683,  -683,   731,  -683,  3099,
    3099,  3099,  3099,  3099,  3099,  3099,  3099,  3099,  3099,  3099,
    3099,  3099,  3099,   681,  3099,   603,   686,  3099,  -683,  -683,
     297,   297,   186,  -683,   739,   740,   186,   741,  -683,   273,
    -683,   601,  -683,  -683,  -683,   457,   719,  -683,   742,    21,
    -683,  -683,   719,  -683,  3099,   204,   610,  3099,   611,  3099,
     551,  -683,  -683,  -683,  -683,  3099,     3,   446,  -683,   511,
    3592,   532,   526,  -683,  -683,   527,   239,   221,   221,   -23,
     190,   190,   190,   190,   400,   400,  -683,  -683,  -683,  -683,
    -683,  -683,   497,  -683,  -683,  -683,  -683,   671,  -683,  -683,
     240,  -683,  -683,    26,  -683,  3099,  -683,  -683,  2466,  -683,
     616,   617,  -683,  -683,  -683,  -683,   752,    61,   114,  -683,
    -683,   333,   115,  -683,  -683,  -683,  3099,  2677,   677,   619,
     621,   623,   624,  -683,  3099,   471,  -683,   760,  -683,   761,
    3099,   680,  3099,  3099,   -17,   683,   479,  3099,  -683,   744,
     768,   744,  -683,   721,  -683,  3099,  3099,   694,   482,   634,
    -683,   256,   685,  -683,    94,  -683,  -683,   794,  -683,  -683,
    3099,   783,  -683,  -683,    38,  -683,  -683,  -683,  -683,   124,
    -683,   434,    81,  -683,   639,  -683,  -683,  -683,  -683,  -683,
    -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,   518,
     650,   587,   530,   653,  -683,  -683,  -683,  -683,  -683,    91,
     186,   249,   116,   118,    -1,  -683,   786,  -683,  -683,  -683,
    -683,    51,   765,  -683,  3099,   766,   645,  -683,  -683,   -41,
    -683,  3099,   655,  3099,  -683,  3099,  -683,   258,   659,  -683,
    3310,  -683,  -683,  -683,  -683,   225,   311,  -683,     3,   225,
    3310,  3310,  3638,  -683,  -683,  -683,  -683,  -683,  -683,  -683,
       3,     3,   311,  -683,  -683,  -683,  -683,  -683,  -683,  -683,
    -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,   264,
    -683,  -683,   788,   516,  -683,  3099,  -683,   749,   351,   516,
    -683,  -683,   426,  -683,  -683,   265,  -683,  -683,  -683,  -683,
    -683,  -683,  -683,  -683,  -683,  -683,  3099,  -683,  -683,  3099,
     718,  3099,  -683,   743,   803,   811,   744,  -683,  -683,  3099,
    -683,  -683,  -683,  2888,    77,   444,  -683,  -683,   267,   688,
     827,  -683,   830,   138,   825,   698,   261,  -683,  -683,  -683,
    3099,    48,   587,  -683,  -683,  -683,  -683,  -683,  3310,  3310,
    3310,  3310,   835,   620,   828,  -683,   828,  -683,  -683,   765,
    -683,  -683,  -683,   839,  -683,  -683,  -683,  -683,  -683,  3099,
    -683,  -683,  -683,  -683,   190,  -683,  -683,  -683,   229,   532,
    -683,  -683,   279,  3310,  -683,  -683,   526,  -683,   612,  -683,
    -683,   280,   268,  -683,   516,  -683,  -683,   381,   516,  -683,
    -683,  -683,  -683,  -683,  3099,  -683,  3099,  -683,   721,  -683,
    -683,   269,  -683,  -683,   834,   176,  -683,  -683,  -683,  -683,
     711,   543,  -683,  -683,  -683,  -683,   695,   697,   852,   842,
    3099,   851,  3099,  -683,   122,  -683,   190,   190,   190,   290,
     311,  -683,   123,  -683,   126,  -683,  -683,  -683,  -683,  -683,
    -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,   388,  -683,
    -683,   391,  -683,  -683,   744,  -683,  -683,  -683,  -683,  -683,
    -683,  -683,  -683,  -683,   704,   516,  -683,   720,  -683,   804,
     771,  3310,   636,   828,  -683,  -683,  -683,  -683,  -683,  -683,
    -683,   732,  3099,   861,  -683,   190,  -683,  -683,  3099,  -683,
     730,  -683,   771,  -683
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
       0,     0,     0,     0,     0,     0,     0,     0,   465,   538,
       0,     0,   528,   530,     0,     0,   525,     0,   513,     0,
     512,     0,    16,    18,    96,   161,   157,   159,     0,   146,
     150,   109,   158,   145,     0,     0,     0,     0,     0,     0,
     189,   191,   194,   193,   195,     0,     0,     0,   487,   197,
     466,   474,   476,   478,   480,   482,   485,   203,   202,   200,
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
       0,     0,     0,     0,   537,   536,   531,   532,   534,     0,
     526,   521,     0,     0,    14,   170,     0,   171,   172,   173,
     162,   163,   164,   165,     0,   152,     0,   155,   148,   147,
     110,     0,     0,     0,   113,     0,   111,     0,     0,   481,
       0,   198,   494,   542,   541,     0,     0,   543,     0,     0,
       0,     0,   467,   471,   489,   470,   493,   491,   490,   492,
       0,     0,     0,   483,   546,   547,   544,   545,   548,   486,
     395,   397,   396,   393,   390,   250,   297,   320,   381,     0,
     422,   424,    90,     0,    72,     0,    73,     0,     0,     0,
      80,    81,     0,    68,   377,     0,   435,   428,   429,   431,
     432,   180,   178,   132,   133,   126,     0,   128,   125,     0,
       0,     0,   123,     0,     0,    63,    57,   141,   140,     0,
     136,    11,   386,     0,   345,   339,   336,   367,     0,     0,
       0,   333,     0,     0,     0,     0,     0,   184,     7,   457,
       0,     0,   459,   460,   138,   464,   535,   533,     0,     0,
       0,     0,     0,     0,     0,   516,     0,   514,   174,   166,
     167,   168,   160,     0,   153,   151,   156,   149,   114,     0,
     112,   115,   488,   484,   563,   562,   561,   557,     0,   475,
     556,   468,     0,     0,   473,   472,   477,   479,     0,   382,
      91,     0,     0,    89,     0,    74,    75,     0,     0,    82,
      83,   378,   130,   127,     0,   129,     0,    59,     0,   142,
     387,     0,   353,   347,     0,   346,   348,   354,   351,   341,
       0,   340,   342,   352,    92,   328,     0,     0,     0,     0,
       0,     0,     0,   455,     0,   461,   550,   551,   549,     0,
     522,   523,     0,   519,     0,   169,   154,   116,   560,   559,
     558,   553,   554,   469,   555,    76,    77,    93,     0,    84,
      85,     0,   131,   187,    65,   388,   338,   349,   350,   337,
     343,   344,   329,   330,     0,     0,   185,     0,   181,     0,
       0,     0,     0,     0,   517,   515,    78,    79,    86,    87,
     331,     0,     0,     0,   462,   552,   524,   520,     0,   182,
       0,   186,     0,   463
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -683,  -683,  -683,   799,   800,  -683,   798,  -683,   557,   566,
    -324,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,
    -683,  -683,  -683,  -683,  -428,  -683,  -683,  -683,  -683,  -683,
     477,   145,  -683,  -556,   801,    30,   -80,  -683,  -683,   777,
    -683,  -683,   293,   464,  -226,  -479,  -683,  -683,   -42,   234,
    -477,   568,  -683,   211,  -683,  -683,  -296,   569,   216,  -683,
    -683,   223,  -633,  -683,   843,   306,  -683,  -683,   266,  -683,
    -683,   572,   574,   288,  -645,   546,   241,  -363,   222,   291,
    -683,  -683,  -683,  -683,  -683,   772,  -683,  -683,  -683,  -683,
    -683,  -683,   775,  -683,   -43,  -683,  -683,  -683,  -683,  -683,
    -683,  -683,    82,   117,  -683,  -683,   167,   -68,  -683,  -350,
    -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -450,
    -683,   285,  -683,   459,  -683,  -683,  -683,  -683,  -683,    41,
      50,  -589,  -493,  -683,  -683,  -683,  -683,  -683,  -683,  -683,
    -683,  -683,  -683,   552,  -212,  -374,  -683,  -683,   289,  -366,
    -683,  -683,  -683,  -683,  -683,  -683,  -683,   901,   903,   153,
     513,  -683,  -683,  -683,  -683,  -683,  -683,  -683,  -683,   270,
    -683,  -683,   137,  -683,   411,  -683,  -683,   233,   226,   224,
     415,  -683,  -683,   235,  -683,  -511,  -683,  -683,  -683,  -683,
     133,  -316,  -683,   456,   180,  -683,  -453,  -683,  -683,  -683,
    -683,  -682,  -683,  -683,  -683,  -683,   108,   244,  -683
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
     306,   550,   551,   552,   553,   513,   564,   564,   621,   643,
     538,   420,   440,   423,   276,   277,   420,     6,   436,   725,
     436,   204,   206,   433,   848,   761,   441,   493,   635,   636,
     697,   209,   698,   285,   467,   215,   593,   635,   636,   676,
     858,   526,   528,   467,   564,   801,    17,   496,   830,   831,
       3,    26,   434,    28,   236,    30,    31,     4,   213,   696,
     241,   626,   254,   637,   340,   851,   251,   272,    50,   267,
     882,   262,   637,    39,   434,   265,   635,   371,   268,   450,
     610,   779,   210,   242,   753,   214,   389,   207,   686,   208,
     371,   437,   280,   613,   282,   283,   284,   232,   638,   218,
     639,   468,   372,   457,    49,   816,   255,   638,   535,   639,
     648,   216,   651,   225,   536,   372,   794,   403,   219,   582,
      60,   595,   407,   635,   636,   409,   688,   689,   596,   226,
      50,   229,   373,   340,   640,   340,   428,   635,   636,   806,
     430,   233,   583,   640,   345,   754,   638,   340,   639,   340,
     340,   575,   757,   757,   824,   230,   826,   883,   637,   252,
     949,   953,    57,   256,   953,   435,   755,   273,   340,   882,
     340,    57,   637,   340,   746,   635,   538,   538,   340,   340,
     340,   340,   640,   683,   643,   786,   915,   466,   469,   643,
     641,    71,   866,   638,   494,   639,   870,   649,   923,   800,
      71,   855,   286,   611,   801,   615,   345,   638,    70,   639,
     836,   495,   837,   438,   269,    77,   627,   676,   952,   702,
     497,    91,   211,   243,    77,   438,   438,   396,   405,   640,
     398,   438,   212,   244,   408,   537,   438,   410,   438,   458,
     795,   817,   400,   640,   401,   638,   340,   639,   429,   586,
     514,   515,   431,   521,   515,   523,   937,    57,   340,   443,
     253,   454,   473,   576,   758,   762,   825,   805,   827,   500,
     340,    57,   950,   954,   477,   564,   955,   406,   340,   411,
     507,   640,   424,    45,   374,   802,    71,   427,   456,   472,
     474,   887,   893,   463,   340,   926,   340,   420,   507,   898,
      71,   930,   340,   340,    50,   340,   340,   340,   222,   220,
      77,   341,   342,   508,   397,   375,   574,   341,   584,   574,
     399,   574,   504,   217,    77,   341,   342,   901,   221,   223,
     524,   682,   594,   587,   341,   376,   527,   844,   571,   572,
     344,   585,   603,   643,   343,   606,   344,   608,   852,   586,
     513,   478,   224,   701,   344,   475,   759,   501,   538,   231,
     624,   378,   957,   344,   925,   959,   509,   577,   234,   861,
     538,   538,   432,   379,   864,   867,   633,   564,   780,   632,
     345,   377,   887,   564,   964,   755,   264,   745,   893,   655,
     656,   657,   658,   659,   660,   661,   662,   663,   664,   665,
     666,   667,   668,   792,   670,   842,   973,   673,   505,   570,
     902,   859,   871,   573,   894,   927,   935,   760,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    41,   591,   700,   865,   420,   704,   755,   706,
     934,   227,   228,   635,   558,   906,   907,   908,   909,   868,
     378,   734,   735,   736,   737,   235,   755,   888,   951,   240,
       6,   378,   379,    12,   845,   929,   818,   819,   918,   846,
      47,    48,   956,   379,   919,   958,    16,   820,   821,   738,
     928,   685,   631,   380,   931,   747,   755,   245,   564,    17,
     822,   920,   564,   755,   686,   248,   755,   421,   258,    35,
     804,   263,   381,   274,   422,   266,   763,    41,   287,   237,
     869,   275,    65,   638,   771,   639,    39,   279,   918,   687,
     775,   281,   777,   778,   919,   889,   558,   783,   818,   819,
     860,   755,   688,   689,   298,   787,   788,   301,   559,   820,
     821,   920,   635,   270,   271,    12,   302,    49,   333,   640,
     338,   535,   581,   339,    54,   707,   888,   536,    16,     1,
     340,   961,   288,   289,   290,    79,     2,     3,   350,   564,
      58,   599,   351,   601,     4,     5,   790,   370,   965,     6,
     382,    35,     7,   383,     8,     9,    64,    65,   384,    41,
     554,   555,    10,    11,    12,    13,    91,   385,   749,   412,
      73,    14,   547,   548,   515,   393,    15,    16,    17,   391,
     392,   838,   638,   840,   639,   841,   413,   765,   560,   414,
     559,   740,   741,   742,   940,    32,    33,   967,   415,    34,
      35,    36,    37,    38,   416,    39,    54,    40,    41,   417,
     479,   480,   418,   484,   485,   532,   533,   534,   640,   419,
      43,    44,    58,   481,   482,   483,   486,   487,   488,   425,
     798,   556,   557,   567,   567,   426,    49,   442,    64,    65,
     674,   675,   444,   445,   446,   447,    51,   448,   386,   449,
     453,   455,    73,   461,   459,    54,   872,   460,   462,   873,
     464,   875,   465,   476,    55,   490,   489,    56,    57,   879,
     560,    58,   491,   387,    60,   492,   499,    61,    62,   498,
      63,   518,   529,   558,   578,   579,   590,    64,    65,    66,
     903,    67,    68,   597,   598,    70,   605,    71,   604,   607,
      72,    73,   609,   612,   617,   616,   618,   620,    75,   625,
     622,   623,   628,   629,   634,   654,    76,   669,   651,   917,
     671,    77,   672,   677,   678,   681,   684,   694,   695,   703,
     705,   710,   730,   731,   744,   732,   750,   751,   752,   767,
     766,   768,     1,   769,   770,   862,   773,   774,   776,     2,
       3,   781,   784,   785,   932,   789,   933,     4,     5,   791,
     793,   797,     6,   799,   808,     7,   811,     8,     9,   810,
     815,   828,   686,   833,   839,    10,    11,    12,    13,   843,
     946,   420,   948,   881,    14,   586,   874,   876,   877,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   878,   896,    32,    33,
     897,   899,    34,    35,    36,    37,    38,   900,    39,   910,
      40,    41,   895,   507,   916,   911,   936,   939,   924,   942,
      42,   943,   944,    43,    44,   945,    45,   947,   960,   962,
     963,   966,   969,    46,    47,    48,   755,   970,   971,    49,
     972,   968,   334,   335,   336,   511,   592,    50,   337,    51,
     346,    52,   863,    53,   512,   614,   814,   835,    54,   782,
     832,   772,   278,   522,   829,   525,   388,    55,   807,   549,
      56,    57,   530,   390,    58,   531,    59,    60,   904,   650,
      61,    62,   941,    63,   803,   938,   238,   568,   239,   809,
      64,    65,    66,   602,    67,    68,    69,   708,    70,   905,
      71,   849,   709,    72,    73,   857,   856,   854,    74,   914,
     922,    75,   680,   850,     0,     0,     0,     0,     0,    76,
       0,     0,     0,     0,    77,     0,    78,     0,     0,    79,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     1,    87,     0,    88,     0,    89,    90,
       2,     3,     0,     0,     0,     0,     0,     0,     4,     5,
      91,     0,     0,     6,     0,     0,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,     0,    32,
      33,     0,     0,    34,    35,    36,    37,    38,     0,    39,
       0,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,     0,    43,    44,     0,    45,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     3,
      49,     0,     0,     0,     0,     0,     4,   213,    50,     0,
      51,     0,    52,     0,    53,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,    12,     0,    55,     0,
       0,    56,    57,     0,     0,    58,     0,    59,    60,    16,
       0,    61,    62,     0,    63,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,    67,    68,    69,     0,    70,
       0,    71,    35,     0,    72,    73,     0,     0,     0,    74,
      41,     0,    75,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,    77,     0,     0,     0,     0,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     1,    87,     0,    88,     0,    89,
      90,     2,     3,     0,     0,     0,     0,    54,     0,     4,
       5,    91,     0,     0,     6,     0,     0,     7,     0,     8,
       9,     0,     0,    58,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,    64,
      65,    15,    16,    17,     0,     0,     0,    70,     0,     0,
       0,     0,     0,    73,     0,     0,     0,     0,     0,     0,
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
      90,   374,   375,   376,   377,   339,   382,   383,   446,   469,
     370,    33,   248,   235,    67,    68,    33,    24,    35,   540,
      35,     1,     2,   245,   716,   591,   248,    48,     9,    10,
     519,    11,   519,    28,    20,    15,   420,     9,    10,   502,
     732,   347,   348,    20,   420,   644,    53,    48,   691,   692,
      12,    62,    48,    64,    34,    66,    67,    19,    20,    48,
      40,   101,    25,    44,    48,   720,    46,    15,   119,    15,
       3,    51,    44,    80,    48,    55,     9,   123,    24,   101,
     108,   108,    20,    20,    33,    13,   115,   121,    47,   115,
     123,   108,    72,   108,    74,    75,    76,   138,    79,   154,
      81,    87,   148,     8,   111,    24,    69,    79,   115,    81,
      87,   160,    41,   126,   121,   148,    32,   207,   173,   109,
     149,    94,    48,     9,    10,    48,    85,    86,   101,   126,
     119,    20,   178,    48,   115,    48,    48,     9,    10,    68,
      48,   182,   132,   115,   195,    94,    79,    48,    81,    48,
      48,    48,    48,    48,    48,    15,    48,    90,    44,    25,
      48,    48,   143,   126,    48,   161,   115,   115,    48,     3,
      48,   143,    44,    48,   158,     9,   536,   537,    48,    48,
      48,    48,   115,   509,   644,   623,   829,   161,   174,   649,
     171,   172,   758,    79,   215,    81,   762,   174,   853,   171,
     172,   722,   197,   439,   803,   441,   195,    79,   170,    81,
     699,   301,   699,   253,   160,   196,   452,   680,   910,   525,
     221,   232,   160,   160,   196,   253,   253,   155,   208,   115,
     158,   253,   170,   170,   160,   242,   253,   160,   253,   144,
     156,   160,   157,   115,   157,    79,    48,    81,   160,    76,
     340,   341,   160,   343,   344,   345,    90,   143,    48,   160,
     126,   160,   160,   160,   160,   160,   160,   651,   160,    93,
      48,   143,   160,   160,    88,   651,   160,   157,    48,   157,
      35,   115,   157,    98,    73,   171,   172,   157,   157,   157,
     157,   794,   795,   273,    48,   861,    48,    33,    35,   171,
     172,   867,    48,    48,   119,    48,    48,    48,   133,   154,
     196,   140,   141,    68,   157,   104,   394,   140,   109,   397,
     163,   399,    35,    25,   196,   140,   141,    76,   173,   154,
     159,    68,   422,   160,   140,   124,   159,   710,   391,   392,
     169,   132,   432,   803,   159,   435,   169,   437,   721,    76,
     684,   165,    25,   159,   169,   157,    33,   181,   718,    20,
     450,   181,   928,   169,    94,   931,   121,   157,    20,   753,
     730,   731,   108,   193,    33,   759,   466,   753,   614,   157,
     195,   170,   885,   759,   950,   115,   160,   157,   891,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   157,   494,   157,   972,   497,   121,   389,
     159,   157,   157,   393,   157,   157,   157,    94,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    83,   160,   524,    94,    33,   527,   115,   529,
     878,    85,    86,     9,    20,   818,   819,   820,   821,    33,
     181,   222,   223,   224,   225,    26,   115,    23,   178,    26,
      24,   181,   193,    39,   249,    94,   227,   228,   249,   254,
     106,   107,    94,   193,   255,    94,    52,   238,   239,   250,
     864,    34,   462,    93,   868,   575,   115,    26,   864,    53,
     251,   272,   868,   115,    47,    26,   115,    94,    26,    75,
      76,    15,   112,    20,   101,    17,   596,    83,    24,   160,
      94,    20,   163,    79,   604,    81,    80,    20,   249,    72,
     610,   160,   612,   613,   255,    91,    20,   617,   227,   228,
     752,   115,    85,    86,    26,   625,   626,   115,   114,   238,
     239,   272,     9,    20,    21,    39,    26,   111,     0,   115,
     165,   115,   409,   165,   130,   535,    23,   121,    52,     4,
      48,   945,   202,   203,   204,   201,    11,    12,   137,   945,
     146,   428,    31,   430,    19,    20,   628,   241,   951,    24,
     110,    75,    27,   179,    29,    30,   162,   163,    42,    83,
     378,   379,    37,    38,    39,    40,   232,    43,   578,    48,
     176,    46,   371,   372,   694,   116,    51,    52,    53,   166,
     167,   701,    79,   703,    81,   705,    48,   597,   194,    25,
     114,   134,   135,   136,    91,    70,    71,   953,    25,    74,
      75,    76,    77,    78,   121,    80,   130,    82,    83,    89,
     199,   200,    24,   199,   200,   367,   368,   369,   115,   121,
      95,    96,   146,   212,   213,   214,   212,   213,   214,   160,
     640,   380,   381,   384,   385,   160,   111,    48,   162,   163,
     500,   501,    35,    15,    35,   126,   121,    15,   123,    25,
      48,    89,   176,    18,   160,   130,   776,   160,   115,   779,
     160,   781,   160,   197,   139,   217,    33,   142,   143,   789,
     194,   146,   217,   148,   149,   101,    24,   152,   153,   157,
     155,    76,   159,    20,   115,    20,    25,   162,   163,   164,
     810,   166,   167,   115,    20,   170,    76,   172,   108,    76,
     175,   176,    76,   108,   177,    76,    25,    89,   183,   101,
      89,    35,    76,    25,    89,    24,   191,    76,    41,   839,
     157,   196,    76,    24,    24,    24,   165,    48,    26,   159,
     159,   260,   240,   247,   103,   248,   160,   160,    26,   160,
     103,   160,     4,   160,   160,   755,    26,    26,   108,    11,
      12,   108,    48,    25,   874,   101,   876,    19,    20,   165,
     115,     7,    24,    20,   165,    27,   219,    29,    30,   159,
     157,    25,    47,    47,   159,    37,    38,    39,    40,   160,
     900,    33,   902,   793,    46,    76,   108,    84,    25,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    35,    20,    70,    71,
      20,    26,    74,    75,    76,    77,    78,   159,    80,    24,
      82,    83,   174,    35,    25,   245,    32,   156,   256,   174,
      92,   174,    20,    95,    96,    33,    98,    26,   174,   159,
      76,   245,   962,   105,   106,   107,   115,    26,   968,   111,
     160,   159,    93,    93,    96,   338,   419,   119,    97,   121,
     123,   123,   757,   125,   338,   441,   672,   696,   130,   616,
     694,   605,    69,   344,   691,   347,   144,   139,   652,   373,
     142,   143,   350,   148,   146,   351,   148,   149,   811,   470,
     152,   153,   891,   155,   649,   885,    35,   385,    35,   669,
     162,   163,   164,   430,   166,   167,   168,   536,   170,   812,
     172,   718,   537,   175,   176,   731,   730,   722,   180,   826,
     852,   183,   506,   719,    -1,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,    -1,    -1,   201,
      -1,    -1,    -1,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,    -1,     4,   216,    -1,   218,    -1,   220,   221,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
     232,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    70,
      71,    -1,    -1,    74,    75,    76,    77,    78,    -1,    80,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,    12,
     111,    -1,    -1,    -1,    -1,    -1,    19,    20,   119,    -1,
     121,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,   139,    -1,
      -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,    52,
      -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,    -1,   166,   167,   168,    -1,   170,
      -1,   172,    75,    -1,   175,   176,    -1,    -1,    -1,   180,
      83,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,    -1,     4,   216,    -1,   218,    -1,   220,
     221,    11,    12,    -1,    -1,    -1,    -1,   130,    -1,    19,
      20,   232,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,   146,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,   162,
     163,    51,    52,    53,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
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
      26,   320,   160,   317
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
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
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
     387,    48,    76,    26,   160,   317,    -1,   220,   331,   221,
     320,   157,    -1,   221,   320,   157,    -1,   460,    -1,   460,
     459,    -1,   460,   258,   358,    -1,   460,   459,   258,   358,
      -1,   469,    -1,   467,    -1,   459,   469,    -1,   459,   467,
      -1,   461,    -1,   460,   243,   461,    -1,   462,    -1,   461,
     240,   462,    -1,   463,    -1,   462,   247,   463,    -1,   464,
      -1,   242,   464,    -1,   465,    -1,   465,   488,    -1,   121,
     458,   160,    -1,   466,    -1,   466,   484,    -1,   393,    -1,
     115,   319,   157,    -1,   468,    -1,   487,    -1,   486,    -1,
     489,    -1,   483,    -1,   138,    -1,   470,    -1,   471,    -1,
     472,    -1,   473,    -1,   476,    -1,   481,    -1,   482,    -1,
     246,    -1,   257,    -1,   231,    -1,   230,    -1,   267,    -1,
     261,    -1,   234,    -1,   233,    -1,   268,    -1,   262,    -1,
     270,   475,    -1,   270,    68,    -1,   270,   121,   475,   160,
      -1,   270,   121,   475,    48,   474,   160,    -1,   270,   121,
      68,   160,    -1,   270,   121,    68,    48,   474,   160,    -1,
     264,    -1,   475,    -1,   474,    48,   475,    -1,    35,    24,
      -1,    35,    24,   251,    24,    -1,    35,    24,   485,   245,
      -1,    35,    24,   251,    24,   485,   245,    -1,   269,   478,
      -1,   269,   478,   477,    -1,   266,    -1,   266,   477,    -1,
     263,    -1,   480,    -1,   477,   480,    -1,    35,    24,    -1,
     121,   479,   160,    -1,    24,    -1,   479,    24,    -1,   181,
     478,    -1,    93,   478,    -1,   244,    24,    -1,   271,    -1,
     265,    -1,   229,    -1,   226,    -1,   237,    -1,   224,    -1,
     225,    -1,   222,    -1,   223,    -1,   250,    -1,   238,   361,
      -1,   227,   361,    -1,   228,   361,    -1,   239,   361,   178,
     361,    -1,   236,   485,   490,    -1,   259,   361,   490,    -1,
     248,   485,   256,    -1,   252,   491,    -1,   235,   491,    -1,
     272,    -1,   255,    -1,   249,    -1,   254,    -1,   249,    -1,
     260,   361,    -1
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
    1569,  1571,  1574,  1579,  1587,  1593,  1597,  1599,  1602,  1606,
    1611,  1613,  1615,  1618,  1621,  1623,  1627,  1629,  1633,  1635,
    1639,  1641,  1644,  1646,  1649,  1653,  1655,  1658,  1660,  1664,
    1666,  1668,  1670,  1672,  1674,  1676,  1678,  1680,  1682,  1684,
    1686,  1688,  1690,  1692,  1694,  1696,  1698,  1700,  1702,  1704,
    1706,  1708,  1710,  1713,  1716,  1721,  1728,  1733,  1740,  1742,
    1744,  1748,  1751,  1756,  1761,  1768,  1771,  1775,  1777,  1780,
    1782,  1784,  1787,  1790,  1794,  1796,  1799,  1802,  1805,  1808,
    1810,  1812,  1814,  1816,  1818,  1820,  1822,  1824,  1826,  1828,
    1831,  1834,  1837,  1842,  1846,  1850,  1854,  1857,  1860,  1862,
    1864,  1866,  1868,  1870
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
    2341,  2353,  2364,  2379,  2383,  2397,  2408,  2418,  2428,  2438,
    2451,  2460,  2474,  2483,  2495,  2505,  2515,  2530,  2538,  2553,
    2562,  2579,  2588,  2603,  2613,  2623,  2633,  2643,  2653,  2663,
    2679,  2686,  2699,  2707,  2721,  2735,  2745,  2761,  2771,  2786,
    2795,  2811,  2821,  2838,  2847,  2862,  2871,  2887,  2901,  2908,
    2922,  2929,  2951,  2958,  2969,  2980,  2997,  3004,  3014,  3030,
    3037,  3051,  3058,  3065,  3078,  3085,  3092,  3099,  3106,  3119,
    3126,  3134,  3148,  3155,  3162,  3175,  3182,  3197,  3204,  3219,
    3226,  3241,  3248,  3263,  3270,  3285,  3292,  3299,  3306,  3321,
    3328,  3335,  3349,  3356,  3363,  3370,  3377,  3384,  3397,  3404,
    3411,  3418,  3425,  3432,  3445,  3452,  3459,  3473,  3480,  3495,
    3504,  3519,  3528,  3545,  3554,  3596,  3603,  3610,  3617,  3633,
    3647,  3655,  3668,  3675,  3688,  3697,  3706,  3715,  3730,  3739,
    3753,  3760,  3767,  3774,  3781,  3788,  3795,  3808,  3815,  3828,
    3837,  3852,  3859,  3866,  3873,  3880,  3898,  3905,  3918,  3925,
    3938,  3948,  3958,  3974,  3981,  3996,  4005,  4022,  4036,  4043,
    4050,  4057,  4064,  4071,  4078,  4085,  4098,  4105,  4118,  4126,
    4134,  4148,  4161,  4168,  4182,  4195,  4209,  4268,  4277,  4292,
    4301,  4316,  4323,  4336,  4343,  4350,  4363,  4374,  4385,  4396,
    4407,  4418,  4436,  4445,  4460,  4469,  4486,  4501,  4509,  4524,
    4530,  4537,  4546,  4555,  4566,  4584,  4590,  4597,  4606,  4615,
    4626,  4643,  4651,  4665,  4673,  4687,  4695,  4703,  4712,  4727,
    4736,  4744,  4752,  4766,  4774,  4792,  4800,  4820,  4838,  4845,
    4852,  4859,  4866,  4873,  4886,  4900,  4909,  4918,  4926,  4954,
    4963,  4972,  4980,  4994,  5008,  5022,  5031,  5040,  5048,  5062,
    5071,  5086,  5100,  5109,  5118,  5158,  5166,  5174,  5188,  5195,
    5202,  5215,  5229,  5236,  5243,  5250,  5257,  5264,  5271,  5278,
    5285,  5298,  5311,  5318,  5326,  5340,  5353,  5366,  5373,  5380,
    5393,  5402,  5411,  5420,  5429,  5444,  5458,  5467,  5476,  5485,
    5494,  5504,  5514,  5530,  5554,  5564,  5587,  5630,  5638,  5644,
    5655,  5664,  5673,  5682,  5691,  5701,  5710,  5719,  5728,  5737,
    5752,  5760,  5773,  5782,  5797,  5826,  5840,  5849,  5865,  5882,
    5892,  5902,  5916,  5926,  5946,  5952,  5969,  5975,  5981,  5987,
    5999,  6005,  6011,  6017,  6029,  6035,  6047,  6053,  6065,  6071,
    6083,  6089,  6101,  6107,  6113,  6125,  6131,  6143,  6149,  6161,
    6167,  6173,  6179,  6185,  6197,  6209,  6216,  6223,  6230,  6237,
    6244,  6251,  6264,  6270,  6276,  6282,  6294,  6300,  6306,  6312,
    6324,  6330,  6342,  6348,  6354,  6360,  6366,  6372,  6378,  6390,
    6396,  6408,  6414,  6420,  6426,  6438,  6444,  6450,  6456,  6462,
    6474,  6480,  6492,  6498,  6510,  6516,  6528,  6534,  6546,  6558,
    6564,  6576,  6582,  6588,  6600,  6606,  6612,  6618,  6624,  6636,
    6643,  6650,  6657,  6670,  6682,  6694,  6706,  6712,  6724,  6730,
    6736,  6748,  6754,  6766
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

#line 6776 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"



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

