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
#line 786 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 51 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"

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
        case 92: /* "\"'DECIMAL'\"" */
#line 679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 103: /* "\"'DOUBLE'\"" */
#line 678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 127: /* "\"'INTEGER'\"" */
#line 677 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 274: /* "VersionDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 275: /* "MainModule" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 276: /* "LibraryModule" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 277: /* "ModuleDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 278: /* "Prolog" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 279: /* "SIND_DeclList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 280: /* "VFO_DeclList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 281: /* "SIND_Decl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 282: /* "VFO_Decl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 283: /* "Setter" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 284: /* "Import" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 285: /* "NamespaceDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "BoundarySpaceDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "DefaultNamespaceDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "OptionDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "OrderingModeDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "EmptyOrderDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "CopyNamespacesDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "DefaultCollationDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "BaseURIDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "SchemaImport" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "URILiteralList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "SchemaPrefix" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "ModuleImport" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "VarDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 346 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "ConstructionDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "FunctionSig" */
#line 691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 356 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "Block" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 361 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "BlockBody" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 366 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "ExitExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 371 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "WhileExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 376 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "FlowCtlStatement" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 381 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "FunctionDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 386 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "ParamList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 391 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "Param" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 396 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "EnclosedExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 401 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "BracedExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 406 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "QueryBody" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 411 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "Expr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 416 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "ExprSingle" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 421 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "FLWORExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 426 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "FLWORWinCond" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 431 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "WindowClause" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 436 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "CountClause" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 441 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "ForLetWinClause" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 446 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "FLWORClauseList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 451 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "ForClause" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 456 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VarInDeclList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 461 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VarInDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 466 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "PositionalVar" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 471 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "LetClause" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "VarGetsDeclList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 481 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "EvalVarDeclList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 486 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "VarGetsDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 491 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "WindowVarDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 496 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "WindowVars" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 501 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "WindowVars3" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 506 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "WindowVars2" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 511 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "EvalVarDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 516 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "WhereClause" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 521 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "GroupByClause" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "GroupSpecList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "GroupSpec" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 536 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "GroupCollationSpec" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "OrderByClause" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "OrderSpecList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 551 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "OrderSpec" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 556 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "OrderModifier" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 561 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "OrderDirSpec" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 566 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "OrderEmptySpec" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 571 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "OrderCollationSpec" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 576 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "QuantifiedExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 581 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "QVarInDeclList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 586 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "QVarInDecl" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 591 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "TypeswitchExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 596 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CaseClauseList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 601 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CaseClause" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 606 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "IfExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 611 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "OrExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 616 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "AndExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 621 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "ComparisonExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 626 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "FTContainsExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 631 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "RangeExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 636 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "AdditiveExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 641 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "MultiplicativeExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 646 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "UnionExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 651 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "IntersectExceptExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 656 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "InstanceofExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 661 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "TreatExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 666 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CastableExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 671 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "CastExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 676 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "UnaryExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 681 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "SignList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 686 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "ValueExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 691 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "ValueComp" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 696 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "NodeComp" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 701 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "ValidateExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 706 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ExtensionExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 711 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "PragmaList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 716 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "Pragma" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 721 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "PathExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 726 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "RelativePathExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 731 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "StepExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 736 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "AxisStep" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 741 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ForwardStep" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 746 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ForwardAxis" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 751 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "AbbrevForwardStep" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 756 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ReverseStep" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 761 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "ReverseAxis" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 766 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "NodeTest" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 771 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "NameTest" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 776 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "Wildcard" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 781 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FilterExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 786 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "PredicateList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 791 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "Predicate" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 796 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "PrimaryExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 801 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "Literal" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 806 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "NumericLiteral" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 811 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "VarRef" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 816 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ParenthesizedExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 821 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ContextItemExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 826 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "OrderedExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 831 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "UnorderedExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 836 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FunctionCall" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 841 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "ArgList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 846 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "Constructor" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 851 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "DirectConstructor" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 856 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "DirElemConstructor" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 861 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "DirElemContentList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 866 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "DirAttributeList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 871 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "DirAttr" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 876 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "DirAttributeValue" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 881 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "Opt_QuoteAttrContentList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 886 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "QuoteAttrContentList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 891 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "Opt_AposAttrContentList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 896 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "AposAttrContentList" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 901 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "QuoteAttrValueContent" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 906 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "AposAttrValueContent" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 911 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "DirElemContent" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 916 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "CommonContent" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 921 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "DirCommentConstructor" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 926 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "DirPIConstructor" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 931 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "CDataSection" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 936 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "ComputedConstructor" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 941 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "CompDocConstructor" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 946 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "CompElemConstructor" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 951 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "CompAttrConstructor" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 956 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "CompTextConstructor" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 961 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "CompCommentConstructor" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 966 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "CompPIConstructor" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 971 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "SingleType" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 976 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "TypeDeclaration" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 981 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "SequenceType" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 986 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OccurrenceIndicator" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 991 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "ItemType" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 996 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "AtomicType" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1001 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "KindTest" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1006 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "AnyKindTest" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1011 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "DocumentTest" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1016 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "TextTest" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1021 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "CommentTest" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1026 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "PITest" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1031 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "AttributeTest" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1036 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "SchemaAttributeTest" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1041 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "ElementTest" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1046 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "SchemaElementTest" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1051 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "TypeName" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1056 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "TypeName_WITH_HOOK" */
#line 687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1061 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "StringLiteral" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1066 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "InsertExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1071 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "DeleteExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1076 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ReplaceExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1081 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "RenameExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1086 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "TransformExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1091 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "VarNameList" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1096 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "VarNameDecl" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1101 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "TryExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1106 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "CatchListExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1111 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CatchExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1116 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "EvalExpr" */
#line 689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1121 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 95 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}
  /* Line 547 of yacc.c.  */
#line 1202 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
#line 806 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 3:
#line 811 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 4:
#line 817 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 822 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 834 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		;}
    break;

  case 7:
#line 839 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    ;}
    break;

  case 8:
#line 849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 9:
#line 856 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		;}
    break;

  case 10:
#line 868 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 11:
#line 880 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval)));
		;}
    break;

  case 12:
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 13:
#line 898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 14:
#line 904 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 15:
#line 916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 16:
#line 922 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 17:
#line 936 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 18:
#line 942 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 37:
#line 1006 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 38:
#line 1018 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1023 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1034 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 41:
#line 1040 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 42:
#line 1052 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 43:
#line 1065 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		;}
    break;

  case 44:
#line 1076 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1081 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1093 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1098 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1109 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 49:
#line 1115 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 50:
#line 1121 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 51:
#line 1127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 52:
#line 1146 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 53:
#line 1157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 54:
#line 1168 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 55:
#line 1175 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		;}
    break;

  case 56:
#line 1182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 57:
#line 1189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 58:
#line 1202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 59:
#line 1208 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 60:
#line 1223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 62:
#line 1237 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 63:
#line 1243 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		;}
    break;

  case 64:
#line 1250 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 65:
#line 1256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		;}
    break;

  case 66:
#line 1270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								NULL,
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 67:
#line 1277 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (4)].sval)),
								NULL,
								NULL);
		;}
    break;

  case 68:
#line 1284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (4)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 69:
#line 1291 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (5)].node)),
								NULL);
		;}
    break;

  case 70:
#line 1304 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 73:
#line 1325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 74:
#line 1329 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 75:
#line 1333 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 76:
#line 1340 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    ;}
    break;

  case 77:
#line 1347 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = new BlockBody (LOC ((yyloc)));
      blk->add ((yysemantic_stack_[(2) - (1)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 78:
#line 1353 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 79:
#line 1362 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 80:
#line 1369 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr)));
    ;}
    break;

  case 81:
#line 1376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 82:
#line 1380 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 83:
#line 1387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval))),
                &* (yysemantic_stack_[(5) - (4)].fnsig)->param, &* (yysemantic_stack_[(5) - (4)].fnsig)->ret, NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
		;}
    break;

  case 84:
#line 1395 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval))),
                &* (yysemantic_stack_[(5) - (4)].fnsig)->param, &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
								(yysemantic_stack_[(5) - (5)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
		;}
    break;

  case 85:
#line 1404 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
								&* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern_update);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 86:
#line 1413 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
                &* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_update);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 87:
#line 1422 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
                &* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 88:
#line 1437 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 89:
#line 1445 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 90:
#line 1459 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 91:
#line 1465 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 92:
#line 1477 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1485 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 94:
#line 1496 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 95:
#line 1507 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = new Expr(LOC ((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 96:
#line 1513 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 113:
#line 1549 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr), driver.theCompilerCB->m_config.force_gflwor);
    ;}
    break;

  case 114:
#line 1557 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    ;}
    break;

  case 115:
#line 1561 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    ;}
    break;

  case 116:
#line 1569 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    ;}
    break;

  case 117:
#line 1573 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    ;}
    break;

  case 118:
#line 1577 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    ;}
    break;

  case 119:
#line 1584 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 120:
#line 1588 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 121:
#line 1595 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)), dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 122:
#line 1600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    ;}
    break;

  case 123:
#line 1609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 132:
#line 1627 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 133:
#line 1633 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 134:
#line 1642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    ;}
    break;

  case 135:
#line 1646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    ;}
    break;

  case 136:
#line 1656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		;}
    break;

  case 137:
#line 1667 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 138:
#line 1673 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 139:
#line 1687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 140:
#line 1694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 141:
#line 1702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 142:
#line 1711 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 143:
#line 1721 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 144:
#line 1729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 145:
#line 1738 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 146:
#line 1747 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 147:
#line 1762 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 148:
#line 1774 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 149:
#line 1785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 150:
#line 1797 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 151:
#line 1803 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 152:
#line 1815 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 153:
#line 1821 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 154:
#line 1835 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 155:
#line 1843 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 156:
#line 1852 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 157:
#line 1860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 158:
#line 1872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 159:
#line 1878 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 161:
#line 1889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)), "", "");
    ;}
    break;

  case 162:
#line 1893 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
    ;}
    break;

  case 163:
#line 1901 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    ;}
    break;

  case 164:
#line 1905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    ;}
    break;

  case 166:
#line 1914 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)));
    ;}
    break;

  case 167:
#line 1918 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 168:
#line 1922 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)), "");
    ;}
    break;

  case 169:
#line 1929 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 170:
#line 1944 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 171:
#line 1952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 172:
#line 1962 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 173:
#line 1968 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 174:
#line 1979 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 175:
#line 1985 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 176:
#line 1994 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 177:
#line 2004 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 178:
#line 2009 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 179:
#line 2021 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 180:
#line 2027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 181:
#line 2041 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 182:
#line 2047 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 183:
#line 2059 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 184:
#line 2066 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 185:
#line 2073 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 186:
#line 2080 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 187:
#line 2087 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 188:
#line 2094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 189:
#line 2101 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 190:
#line 2114 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 191:
#line 2118 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 192:
#line 2128 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 193:
#line 2133 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 194:
#line 2144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 195:
#line 2155 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 196:
#line 2162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 197:
#line 2175 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 198:
#line 2182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 199:
#line 2194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 200:
#line 2200 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 201:
#line 2213 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 202:
#line 2220 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 203:
#line 2234 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 204:
#line 2240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 205:
#line 2252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 206:
#line 2258 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 207:
#line 2271 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 208:
#line 2282 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 2286 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 210:
#line 2297 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 211:
#line 2301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 212:
#line 2320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 213:
#line 2324 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 214:
#line 2332 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 215:
#line 2340 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 216:
#line 2348 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 217:
#line 2355 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 218:
#line 2356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 219:
#line 2364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 220:
#line 2372 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 221:
#line 2380 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 222:
#line 2394 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 223:
#line 2398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 224:
#line 2405 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 225:
#line 2418 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 226:
#line 2422 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 227:
#line 2433 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 228:
#line 2437 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 229:
#line 2441 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 230:
#line 2451 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 231:
#line 2455 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 232:
#line 2459 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 233:
#line 2463 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 234:
#line 2467 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 235:
#line 2477 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 236:
#line 2481 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 237:
#line 2486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 238:
#line 2497 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 239:
#line 2501 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 240:
#line 2505 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 241:
#line 2515 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 242:
#line 2519 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 243:
#line 2531 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 244:
#line 2535 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 245:
#line 2547 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 246:
#line 2551 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 247:
#line 2563 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 248:
#line 2567 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 249:
#line 2579 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 250:
#line 2583 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 251:
#line 2595 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 252:
#line 2599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 253:
#line 2603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 254:
#line 2607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 255:
#line 2619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 256:
#line 2623 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 257:
#line 2627 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 258:
#line 2637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 259:
#line 2641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 260:
#line 2645 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 261:
#line 2649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 262:
#line 2653 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 263:
#line 2657 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 264:
#line 2667 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 265:
#line 2671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 266:
#line 2675 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 267:
#line 2685 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 268:
#line 2689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "strict",
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 269:
#line 2695 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "lax",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 270:
#line 2701 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "skip",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 271:
#line 2713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 272:
#line 2719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 273:
#line 2731 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 274:
#line 2737 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 275:
#line 2751 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 276:
#line 2757 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 277:
#line 2799 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 278:
#line 2803 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 279:
#line 2807 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 280:
#line 2811 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 281:
#line 2823 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    ;}
    break;

  case 282:
#line 2833 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 283:
#line 2844 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 284:
#line 2849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 285:
#line 2859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 286:
#line 2863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 287:
#line 2873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 288:
#line 2879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 289:
#line 2885 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 290:
#line 2891 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 291:
#line 2903 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 292:
#line 2909 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 293:
#line 2920 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 294:
#line 2924 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 295:
#line 2928 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 296:
#line 2932 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 297:
#line 2936 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 298:
#line 2940 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 299:
#line 2944 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 300:
#line 2954 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 301:
#line 2958 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 302:
#line 2968 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 303:
#line 2974 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 304:
#line 2986 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 305:
#line 2990 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 306:
#line 2994 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 307:
#line 2998 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 308:
#line 3002 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 309:
#line 3017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 310:
#line 3021 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 311:
#line 3031 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 312:
#line 3035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 313:
#line 3045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 314:
#line 3052 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 315:
#line 3059 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 316:
#line 3072 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 317:
#line 3076 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 318:
#line 3088 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 319:
#line 3094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 320:
#line 3108 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 321:
#line 3119 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 322:
#line 3123 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 323:
#line 3127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 324:
#line 3131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 325:
#line 3135 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 326:
#line 3139 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 327:
#line 3143 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 328:
#line 3147 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 329:
#line 3157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 330:
#line 3161 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 331:
#line 3171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 332:
#line 3176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 333:
#line 3181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 334:
#line 3192 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 335:
#line 3202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 336:
#line 3206 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 337:
#line 3217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 338:
#line 3227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 339:
#line 3238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 340:
#line 3294 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 341:
#line 3300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 342:
#line 3312 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 343:
#line 3318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 344:
#line 3330 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 345:
#line 3334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 346:
#line 3344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 347:
#line 3348 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 348:
#line 3352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 3362 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 350:
#line 3370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 351:
#line 3378 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 352:
#line 3386 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 353:
#line 3394 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 354:
#line 3402 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 355:
#line 3417 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 356:
#line 3423 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 357:
#line 3435 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 358:
#line 3441 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 359:
#line 3454 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 362:
#line 3471 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 363:
#line 3476 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 364:
#line 3487 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 365:
#line 3491 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 366:
#line 3498 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 367:
#line 3504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 368:
#line 3510 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 369:
#line 3518 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 370:
#line 3532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 371:
#line 3536 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 372:
#line 3543 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 373:
#line 3549 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 374:
#line 3555 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 375:
#line 3563 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 376:
#line 3577 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 377:
#line 3582 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 378:
#line 3593 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 379:
#line 3598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 380:
#line 3609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 381:
#line 3614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 382:
#line 3619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 383:
#line 3625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 384:
#line 3637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 385:
#line 3643 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 386:
#line 3648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 387:
#line 3653 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 388:
#line 3664 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 389:
#line 3669 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 390:
#line 3684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 391:
#line 3689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 392:
#line 3706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 393:
#line 3721 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 394:
#line 3725 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 395:
#line 3729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 396:
#line 3733 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 397:
#line 3737 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 398:
#line 3741 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 399:
#line 3751 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 400:
#line 3762 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 401:
#line 3768 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 402:
#line 3774 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 403:
#line 3779 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 404:
#line 3801 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 405:
#line 3807 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 406:
#line 3813 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 407:
#line 3818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 408:
#line 3829 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 409:
#line 3840 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 410:
#line 3851 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 411:
#line 3857 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 412:
#line 3863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 413:
#line 3868 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 414:
#line 3879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 415:
#line 3885 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 416:
#line 3897 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 417:
#line 3909 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 418:
#line 3915 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 419:
#line 3921 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 420:
#line 3958 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 421:
#line 3963 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 422:
#line 3968 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 423:
#line 3979 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 424:
#line 3983 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 425:
#line 3987 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 426:
#line 3997 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 427:
#line 4008 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 428:
#line 4012 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 429:
#line 4016 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 430:
#line 4020 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 431:
#line 4024 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 432:
#line 4028 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 433:
#line 4032 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 434:
#line 4036 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 435:
#line 4040 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 436:
#line 4050 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 437:
#line 4060 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 438:
#line 4064 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 439:
#line 4069 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 440:
#line 4080 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 441:
#line 4090 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 442:
#line 4100 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 443:
#line 4104 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 444:
#line 4108 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 445:
#line 4118 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 446:
#line 4124 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 447:
#line 4130 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 448:
#line 4136 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 449:
#line 4142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 450:
#line 4154 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 451:
#line 4165 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL);
		;}
    break;

  case 452:
#line 4171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
									NULL);
		;}
    break;

  case 453:
#line 4177 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 454:
#line 4183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 455:
#line 4189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 456:
#line 4196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 457:
#line 4203 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 458:
#line 4216 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 459:
#line 4237 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 460:
#line 4244 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 461:
#line 4264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 462:
#line 4304 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 463:
#line 4309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 464:
#line 4312 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 465:
#line 4320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 466:
#line 4326 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 467:
#line 4332 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 468:
#line 4338 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 469:
#line 4344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 470:
#line 4351 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 471:
#line 4357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 472:
#line 4363 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 473:
#line 4369 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 474:
#line 4375 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 475:
#line 4387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 476:
#line 4392 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 477:
#line 4402 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 478:
#line 4408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 479:
#line 4420 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 480:
#line 4446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 481:
#line 4457 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 482:
#line 4463 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 483:
#line 4476 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 484:
#line 4490 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 485:
#line 4497 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 486:
#line 4504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 487:
#line 4515 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 488:
#line 4522 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 489:
#line 4530 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 490:
#line 4539 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(14) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (9)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (12)].sval)),
                          (yysemantic_stack_[(14) - (14)].expr));
    ;}
    break;

  case 492:
#line 4555 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    std::string tmp = driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval));
    for (unsigned int i = 0; i<tmp.size(); i++)
      if (tmp[i] == ':')
      {
        error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
        YYERROR;
      }
    (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval);
  ;}
    break;

  case 493:
#line 4572 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 494:
#line 4573 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty"); ;}
    break;

  case 495:
#line 4574 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("attribute"); ;}
    break;

  case 496:
#line 4575 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("comment"); ;}
    break;

  case 497:
#line 4576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document-node"); ;}
    break;

  case 498:
#line 4577 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("element"); ;}
    break;

  case 499:
#line 4578 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("item"); ;}
    break;

  case 500:
#line 4579 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("if"); ;}
    break;

  case 501:
#line 4580 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("node"); ;}
    break;

  case 502:
#line 4581 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("processing-instruction"); ;}
    break;

  case 503:
#line 4582 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-attribute"); ;}
    break;

  case 504:
#line 4583 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-element"); ;}
    break;

  case 505:
#line 4584 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("text"); ;}
    break;

  case 506:
#line 4585 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("typeswitch"); ;}
    break;

  case 507:
#line 4586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty-sequence"); ;}
    break;

  case 508:
#line 4587 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("boundary-space"); ;}
    break;

  case 509:
#line 4588 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ft-option"); ;}
    break;

  case 510:
#line 4589 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("base-uri"); ;}
    break;

  case 511:
#line 4590 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lax"); ;}
    break;

  case 512:
#line 4591 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strict"); ;}
    break;

  case 513:
#line 4592 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("idiv"); ;}
    break;

  case 514:
#line 4593 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document"); ;}
    break;

  case 515:
#line 4594 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("not"); ;}
    break;

  case 516:
#line 4595 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sensitive"); ;}
    break;

  case 517:
#line 4596 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insensitive"); ;}
    break;

  case 518:
#line 4597 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("diacritics"); ;}
    break;

  case 519:
#line 4598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("without"); ;}
    break;

  case 520:
#line 4599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stemming"); ;}
    break;

  case 521:
#line 4600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("thesaurus"); ;}
    break;

  case 522:
#line 4601 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stop"); ;}
    break;

  case 523:
#line 4602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("wildcards"); ;}
    break;

  case 524:
#line 4603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("entire"); ;}
    break;

  case 525:
#line 4604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("content"); ;}
    break;

  case 526:
#line 4605 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("word"); ;}
    break;

  case 527:
#line 4606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("start"); ;}
    break;

  case 528:
#line 4607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("end"); ;}
    break;

  case 529:
#line 4608 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("most"); ;}
    break;

  case 530:
#line 4609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("skip"); ;}
    break;

  case 531:
#line 4610 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy"); ;}
    break;

  case 532:
#line 4611 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("value"); ;}
    break;

  case 533:
#line 4612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("eq"); ;}
    break;

  case 534:
#line 4613 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ne"); ;}
    break;

  case 535:
#line 4614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lt"); ;}
    break;

  case 536:
#line 4615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("le"); ;}
    break;

  case 537:
#line 4616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("gt"); ;}
    break;

  case 538:
#line 4617 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ge"); ;}
    break;

  case 539:
#line 4618 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("at"); ;}
    break;

  case 540:
#line 4619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("variable"); ;}
    break;

  case 541:
#line 4620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("return"); ;}
    break;

  case 542:
#line 4621 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("for"); ;}
    break;

  case 543:
#line 4622 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("outer"); ;}
    break;

  case 544:
#line 4623 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sliding"); ;}
    break;

  case 545:
#line 4624 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("tumbling"); ;}
    break;

  case 546:
#line 4625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("previous"); ;}
    break;

  case 547:
#line 4626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("next"); ;}
    break;

  case 548:
#line 4627 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("only"); ;}
    break;

  case 549:
#line 4628 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("when"); ;}
    break;

  case 550:
#line 4629 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("count"); ;}
    break;

  case 551:
#line 4630 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("in"); ;}
    break;

  case 552:
#line 4631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("let"); ;}
    break;

  case 553:
#line 4632 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("where"); ;}
    break;

  case 554:
#line 4633 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("by"); ;}
    break;

  case 555:
#line 4634 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("order"); ;}
    break;

  case 556:
#line 4635 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stable"); ;}
    break;

  case 557:
#line 4636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ascending"); ;}
    break;

  case 558:
#line 4637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("descending"); ;}
    break;

  case 559:
#line 4638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("greatest"); ;}
    break;

  case 560:
#line 4639 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("least"); ;}
    break;

  case 561:
#line 4640 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("collation"); ;}
    break;

  case 562:
#line 4641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("some"); ;}
    break;

  case 563:
#line 4642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("every"); ;}
    break;

  case 564:
#line 4643 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("satisfies"); ;}
    break;

  case 565:
#line 4644 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("case"); ;}
    break;

  case 566:
#line 4645 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("as"); ;}
    break;

  case 567:
#line 4646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("then"); ;}
    break;

  case 568:
#line 4647 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("else"); ;}
    break;

  case 569:
#line 4648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("or"); ;}
    break;

  case 570:
#line 4649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("and"); ;}
    break;

  case 571:
#line 4650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("instance"); ;}
    break;

  case 572:
#line 4651 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("of"); ;}
    break;

  case 573:
#line 4652 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("castable"); ;}
    break;

  case 574:
#line 4653 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("to"); ;}
    break;

  case 575:
#line 4654 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("div"); ;}
    break;

  case 576:
#line 4655 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("mod"); ;}
    break;

  case 577:
#line 4656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("union"); ;}
    break;

  case 578:
#line 4657 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("intersect"); ;}
    break;

  case 579:
#line 4658 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("except"); ;}
    break;

  case 580:
#line 4659 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("validate"); ;}
    break;

  case 581:
#line 4660 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cast"); ;}
    break;

  case 582:
#line 4661 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("treat"); ;}
    break;

  case 583:
#line 4662 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("is"); ;}
    break;

  case 584:
#line 4663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("preserve"); ;}
    break;

  case 585:
#line 4664 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strip"); ;}
    break;

  case 586:
#line 4665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("namespace"); ;}
    break;

  case 587:
#line 4666 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("external"); ;}
    break;

  case 588:
#line 4667 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("encoding"); ;}
    break;

  case 589:
#line 4668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-preserve"); ;}
    break;

  case 590:
#line 4669 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("inherit"); ;}
    break;

  case 591:
#line 4670 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-inherit"); ;}
    break;

  case 592:
#line 4671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("declare"); ;}
    break;

  case 593:
#line 4672 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("construction"); ;}
    break;

  case 594:
#line 4673 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordering"); ;}
    break;

  case 595:
#line 4674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("default"); ;}
    break;

  case 596:
#line 4675 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy-namespaces"); ;}
    break;

  case 597:
#line 4676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("option"); ;}
    break;

  case 598:
#line 4677 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("version"); ;}
    break;

  case 599:
#line 4678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("import"); ;}
    break;

  case 600:
#line 4679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema"); ;}
    break;

  case 601:
#line 4680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("function"); ;}
    break;

  case 602:
#line 4681 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("score"); ;}
    break;

  case 603:
#line 4682 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ftcontains"); ;}
    break;

  case 604:
#line 4683 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("weight"); ;}
    break;

  case 605:
#line 4684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("window"); ;}
    break;

  case 606:
#line 4685 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("distance"); ;}
    break;

  case 607:
#line 4686 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("occurs"); ;}
    break;

  case 608:
#line 4687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("times"); ;}
    break;

  case 609:
#line 4688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("same"); ;}
    break;

  case 610:
#line 4689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("different"); ;}
    break;

  case 611:
#line 4690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lowercase"); ;}
    break;

  case 612:
#line 4691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("uppercase"); ;}
    break;

  case 613:
#line 4692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("relationship"); ;}
    break;

  case 614:
#line 4693 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("levels"); ;}
    break;

  case 615:
#line 4694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("language"); ;}
    break;

  case 616:
#line 4695 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("any"); ;}
    break;

  case 617:
#line 4696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("all"); ;}
    break;

  case 618:
#line 4697 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("phrase"); ;}
    break;

  case 619:
#line 4698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exactly"); ;}
    break;

  case 620:
#line 4699 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("from"); ;}
    break;

  case 621:
#line 4700 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("words"); ;}
    break;

  case 622:
#line 4701 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentences"); ;}
    break;

  case 623:
#line 4702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentence"); ;}
    break;

  case 624:
#line 4703 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("paragraph"); ;}
    break;

  case 625:
#line 4704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("replace"); ;}
    break;

  case 626:
#line 4705 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("modify"); ;}
    break;

  case 627:
#line 4706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("first"); ;}
    break;

  case 628:
#line 4707 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insert"); ;}
    break;

  case 629:
#line 4708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("bofer"); ;}
    break;

  case 630:
#line 4709 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("after"); ;}
    break;

  case 631:
#line 4710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("revalidation"); ;}
    break;

  case 632:
#line 4711 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("with"); ;}
    break;

  case 633:
#line 4712 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("nodes"); ;}
    break;

  case 634:
#line 4713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("rename"); ;}
    break;

  case 635:
#line 4714 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("last"); ;}
    break;

  case 636:
#line 4715 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("delete"); ;}
    break;

  case 637:
#line 4716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("into"); ;}
    break;

  case 638:
#line 4717 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("updating"); ;}
    break;

  case 639:
#line 4718 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordered"); ;}
    break;

  case 640:
#line 4719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("unordered"); ;}
    break;

  case 641:
#line 4731 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 642:
#line 4737 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 643:
#line 4754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 644:
#line 4758 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 645:
#line 4762 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 646:
#line 4766 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 647:
#line 4776 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 648:
#line 4779 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 649:
#line 4782 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 650:
#line 4785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 651:
#line 4794 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 652:
#line 4797 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 653:
#line 4806 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 654:
#line 4809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 655:
#line 4818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 656:
#line 4821 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 657:
#line 4830 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 658:
#line 4833 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 659:
#line 4842 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 660:
#line 4845 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 661:
#line 4848 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 662:
#line 4857 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 663:
#line 4860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 664:
#line 4869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 665:
#line 4873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, static_cast<Expr *> ((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 666:
#line 4883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 667:
#line 4886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 668:
#line 4889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 669:
#line 4892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 670:
#line 4895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 671:
#line 4904 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 672:
#line 4913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 673:
#line 4917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 674:
#line 4921 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 675:
#line 4925 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 676:
#line 4929 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 677:
#line 4933 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 678:
#line 4937 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 679:
#line 4947 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 680:
#line 4950 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 681:
#line 4953 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 682:
#line 4956 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 683:
#line 4965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 684:
#line 4968 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 685:
#line 4971 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 686:
#line 4974 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 687:
#line 4983 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 688:
#line 4986 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 689:
#line 4995 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 690:
#line 4998 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 691:
#line 5001 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 692:
#line 5004 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 693:
#line 5007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 694:
#line 5010 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 695:
#line 5013 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 696:
#line 5022 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 697:
#line 5025 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 698:
#line 5034 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 699:
#line 5037 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 700:
#line 5040 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 701:
#line 5043 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 702:
#line 5052 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 703:
#line 5055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 704:
#line 5058 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 705:
#line 5061 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 706:
#line 5064 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 707:
#line 5073 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 708:
#line 5076 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 709:
#line 5085 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 710:
#line 5088 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 711:
#line 5097 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 712:
#line 5100 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 713:
#line 5109 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 714:
#line 5112 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 715:
#line 5121 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 716:
#line 5130 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 717:
#line 5133 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 718:
#line 5142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 719:
#line 5145 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 720:
#line 5148 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 721:
#line 5157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 722:
#line 5160 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 723:
#line 5163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 724:
#line 5166 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 725:
#line 5169 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 726:
#line 5178 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 727:
#line 5182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 728:
#line 5186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 729:
#line 5190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 730:
#line 5200 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 731:
#line 5209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 732:
#line 5219 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 733:
#line 5228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 734:
#line 5231 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 735:
#line 5240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 736:
#line 5243 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 737:
#line 5246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 738:
#line 5255 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 739:
#line 5258 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 740:
#line 5267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6449 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -904;
  const short int
  xquery_parser::yypact_[] =
  {
      1236,  -904,  -904,  -904,  -904,   -93,   104,     6,   262,    33,
    5953,   131,   205,   451,    16,  -904,  -904,   155,   129,  -904,
     569,   208,  -904,   180,  -904,  -904,  -904,   350,  -904,   301,
     439,   446,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
     452,  -904,   349,   373,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  6194,  -904,  5220,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  7399,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,   420,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    4224,  1485,  7399,  -904,  -904,  -904,  -904,  -904,  -904,   438,
    -904,  -904,  -904,   571,  -904,  5712,  -904,  -904,  -904,  -904,
    -904,  7399,  -904,  -904,  4971,  -904,  -904,  -904,  -904,  -904,
    -904,   470,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
      13,   430,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
     421,   480,   426,  -904,   416,   177,  -904,  -904,  -904,  -904,
    -904,  -904,   530,  -904,   502,   560,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,   672,  1734,  -904,  -904,    98,  4224,   505,   506,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,   586,  -904,  -904,  -904,  -904,   268,
    7399,  -904,  -904,  -904,  -904,  -904,   531,   603,  -904,   768,
     444,   384,   236,   296,   240,  -904,   610,   503,   598,   599,
    4473,  -904,  -904,  -904,   326,  -904,  -904,  4971,  -904,   219,
    -904,   550,  5220,  -904,   550,  5220,  -904,  -904,  -904,  -904,
     550,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,   551,
    -904,  4224,  -904,  4224,  4224,   553,   555,   556,  4224,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  4224,  6435,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,   558,  4224,  4224,
     527,  4224,   528,  7399,   656,   657,  7399,   429,   -34,   676,
     -12,   432,   600,   261,   680,   442,    20,  4224,  -904,  4224,
      43,   567,    85,   153,  7399,   680,  7399,  4224,   449,   450,
    -904,   604,   605,  -904,  7399,    53,  4224,  6676,   574,   575,
     576,   577,   578,   579,  -904,  -904,  -904,  7399,  1983,    -9,
    -904,   -13,   684,  4224,    50,  -904,   700,   552,  -904,  4224,
     523,  -904,   699,  4224,  4224,   557,  4224,  4224,  4224,  4224,
     509,  7399,  4224,  7399,  -904,  -904,  -904,    16,   569,  -904,
    -904,    98,   686,  4224,   582,   350,   439,   446,   625,   583,
     584,  4224,  4224,  -904,  -904,  -904,  -904,  -904,  -904,   637,
    -904,   -33,  4722,  4722,  4722,  -904,  4722,  4722,  -904,  4722,
    -904,  4722,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  4722,
    4722,     8,  4722,  4722,  4722,  4722,  4722,  4722,  4722,  4722,
    4722,  4722,  4722,   520,   658,   659,   661,  -904,  -904,  -904,
    2232,  -904,  -904,  4971,  4971,  4224,   550,  -904,  -904,   550,
    -904,   550,  2481,  -904,   580,    87,  4224,  4224,  4224,    10,
     184,  -904,    17,    28,  2730,   210,   231,  -904,   253,  -904,
     607,  7399,  7399,   714,  -904,  -904,  -904,  -904,  -904,  -904,
     653,   654,  -904,  -904,  7399,   608,   609,   676,   639,   641,
    -904,  -904,  -904,   394,    14,   401,   731,  -904,  -904,   310,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,    94,   258,
     589,  -904,   590,  2979,   680,   677,   725,   680,   676,   681,
      -3,  -904,    38,   655,   678,  -904,   -18,   611,  -904,  -904,
    7399,   -11,  -904,   612,   575,   349,  -904,   613,   614,   263,
    -904,    97,   130,  3228,     4,  -904,     9,  -904,  -904,  7399,
     684,  -904,   -26,   267,  -904,  -904,  -904,  -904,   286,  -904,
       3,  -904,  -904,  -904,    84,    89,   692,   559,   565,   -32,
    -904,   650,   618,    69,  -904,  -904,   615,  -904,    27,  -904,
    -904,   632,  7399,  4224,   674,  -904,  -904,   682,  7158,   683,
    4224,   685,   -58,   660,   -36,   603,  -904,  -904,  -904,  -904,
    -904,  4722,  -904,  -904,  -904,  4224,     8,   306,  -904,   534,
     512,   554,   562,  -904,  -904,   548,   351,   236,   236,   -15,
     296,   296,   296,   296,   240,   240,  -904,  -904,  7158,  7158,
    7399,  7399,  -904,   287,  -904,  -904,    18,  -904,  -904,  -904,
     160,   662,  -904,   307,   312,   316,   707,   664,  7399,  -904,
    7399,  -904,  -904,   317,  -904,  -904,  -904,   206,   125,   607,
     607,  -904,     0,   435,   441,   676,   676,  -904,   541,   676,
    -904,  -904,   536,  -904,  -904,   537,   398,  -904,  -904,  -904,
    -904,  -904,  -904,   544,  -904,  -904,   616,   669,  -904,  -904,
    -904,   327,   693,   676,   667,   695,   729,   676,   709,  4224,
    4224,   687,   676,   711,  4224,   702,   -46,  -904,    39,   585,
    -904,  -904,   487,   -11,  -904,  -904,  -904,   690,  7399,  -904,
    7399,  -904,  -904,   332,  4224,  -904,   789,  -904,   357,  -904,
     149,  -904,  -904,   805,  -904,   424,  4224,  4224,  4224,   434,
    4224,  4224,  4224,  4224,  4224,  4224,   726,  4224,  4224,   617,
     696,   727,   686,  4224,  -904,   462,   739,  -904,  7399,   740,
    -904,  7399,   697,   698,  -904,   387,  -904,  -904,  -904,  7399,
    -904,  7399,  4224,   705,  4224,  4224,   -47,   708,  -904,   333,
     670,  -904,   606,  -904,   -80,  -904,   241,   -28,   619,     8,
     241,  4722,  4722,   624,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,     8,   712,   -28,  -904,   587,   790,  -904,  -904,  -904,
    -904,  -904,   720,  -904,  -904,  -904,  4224,  -904,  -904,  -904,
    -904,  -904,  6917,   347,  -904,  3477,   689,   691,   721,   694,
     701,  -904,  7399,   769,   165,  -904,  -904,  4224,  -904,   425,
     662,  -904,  -904,  -904,  -904,  -904,  4224,   476,  -904,  -904,
    -904,  -904,  -904,   591,   391,   828,  -904,   381,  -904,  -904,
    4224,  3726,  -904,   676,   765,  -904,  -904,  -904,   676,   765,
    7399,  -904,  -904,  4224,   688,  7399,  -904,  4224,  4224,   743,
    4224,   735,  -904,   767,   770,  4224,  7399,   484,   806,  -904,
    -904,  -904,  3975,   713,  -904,   716,  -904,  -904,  -904,   760,
    -904,   181,  -904,  -904,   873,  -904,  -904,  4224,  7399,  -904,
    -904,   295,  -904,  -904,  -904,   715,   679,   704,  -904,  -904,
    -904,   706,   710,  -904,  -904,  -904,  -904,  -904,   666,  7399,
     723,  -904,   750,   617,  -904,  4224,  7399,   739,  -904,   676,
    -904,   543,  -904,    30,   801,  -904,  4224,   804,   674,  -904,
     730,   732,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  4224,
    -904,  -904,  4224,   773,  4224,  -904,  -904,  4722,  -904,  -904,
    -904,  -904,  -904,    29,  4722,  4722,   340,  -904,   554,  -904,
    -904,    86,  4722,  -904,  -904,   562,     8,   645,  -904,  -904,
    -904,  -904,  7399,   736,    -2,  -904,  -904,   355,  -904,  -904,
    -904,  -904,  -904,   819,  7158,   803,   824,   361,  -904,  -904,
    -904,  -904,  -904,  4224,   247,   885,   886,   247,    -6,   186,
     199,   802,  -904,   362,   831,   676,   765,  -904,  -904,  -904,
    -904,  -904,  -904,  4224,  -904,  4224,  7399,  7399,  -904,   412,
    -904,  4224,  -904,   366,  -904,  -904,   789,  7399,   445,  -904,
     367,   789,  7399,  -904,  -904,  4224,  4224,  4224,  4224,  4224,
    -904,  4224,  5469,  -904,   745,  -904,  -904,  -904,  -904,   801,
    -904,  -904,  -904,   676,  -904,  -904,  -904,  -904,  -904,  -904,
    4224,  -904,   296,  4722,  4722,   296,   422,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,   835,  4224,  7399,  4224,  -904,
    -904,  -904,  -904,  7158,  -904,  -904,   391,   391,   247,  -904,
    -904,  -904,    42,   247,   893,   675,   836,  -904,   836,  -904,
    4224,  -904,   676,  -904,  -904,  -904,   858,  -904,  -904,  -904,
    -904,    -5,   789,  7399,  -904,   746,   789,  -904,  -904,  -904,
    -904,  -904,  -904,   201,  -904,  -904,  -904,  -904,   296,   296,
    4722,  7158,  -904,   756,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,   -28,  -904,   203,  -904,   215,  -904,   765,   822,    66,
     204,  -904,   749,   789,  -904,   751,   829,   796,   296,   766,
    4224,   717,   836,  -904,  -904,  7399,  -904,  -904,   855,   308,
    -904,  -904,  -904,  -904,   771,   341,  -904,  -904,  -904,   758,
    -904,  7399,  -904,  4224,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,   220,  -904,   834,   796,  7399,
    -904,   221,   837,   796,  7399,  -904,   774,   796,  -904
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   314,   315,   493,   461,     0,     0,     0,   580,   506,
     498,   514,   505,   496,   592,   601,   638,   500,   502,   529,
     599,   562,   556,     0,   597,   526,   600,   552,   593,     0,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   594,
       0,   510,   504,   497,   596,   571,   503,   508,   305,   308,
     570,   566,   557,   539,   495,   295,     0,   565,   573,   581,
     293,   561,   331,   540,   595,   294,   297,   558,   575,     0,
     337,   303,   333,   568,   494,   559,   560,   588,   563,   579,
     587,   299,   298,   513,   551,   590,   332,   578,   583,   499,
       0,     0,     0,   252,   576,   586,   591,   589,   569,   639,
     555,   554,   304,     0,   251,     0,   307,   306,   584,   541,
     564,     0,   296,   281,     0,   313,   585,   567,   574,   582,
     577,   640,   533,   538,   537,   536,   535,   534,   507,   553,
       0,     0,   598,   527,   630,   629,   631,   512,   511,   530,
     636,   501,   628,   633,   634,   625,   532,   572,   627,   637,
     635,   626,   531,   632,     0,     0,   617,   616,   516,   509,
     518,   517,   610,   606,   524,   528,   525,   619,   620,   603,
     515,   615,   614,   611,   607,   624,   618,   613,   609,   602,
     623,   622,   608,   612,   604,   605,   519,   520,   522,   621,
     521,   523,     0,     0,     2,     4,     0,     0,     0,     0,
      15,    17,    19,    20,    21,    27,    22,    25,    26,    31,
      32,    33,    28,    29,    35,    36,    23,    30,   112,   109,
     110,   111,    24,     9,    94,    95,    97,   126,   132,     0,
       0,   124,   125,    98,    99,   100,   101,   208,   210,   212,
     222,   225,   227,   230,   235,   238,   241,   243,   245,   247,
       0,   249,   255,   257,     0,   273,   256,   277,   280,   282,
     285,   287,     0,   292,   289,     0,   300,   310,   312,   286,
     316,   321,   329,   322,   323,   324,   327,   328,   325,   326,
     344,   346,   347,   348,   345,   393,   394,   395,   396,   397,
     398,   309,   435,   427,   434,   433,   432,   429,   431,   428,
     430,   330,    34,   102,   103,   105,   104,   106,   107,   311,
     108,     0,    81,     0,     0,     0,     0,     0,     0,   580,
     506,   498,   514,   505,   496,   592,   500,   502,   599,   562,
     552,   542,   543,   504,   497,   495,   563,     0,     0,   639,
     640,   636,   501,   628,   634,   625,   531,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   492,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,     0,     0,    82,     0,     0,     0,     0,     0,   498,
     505,   496,   502,   495,   301,   311,   334,     0,     0,     0,
     335,     0,   360,     0,     0,   276,     0,     0,   279,     0,
       0,   389,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     3,     5,     0,     0,    10,
       8,    12,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   127,   133,   128,   130,   129,   136,
     137,     0,     0,     0,     0,   266,     0,     0,   264,     0,
     217,     0,   265,   258,   263,   262,   261,   260,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,   253,   250,
       0,   274,   278,     0,     0,     0,   288,   318,   291,   290,
     302,   317,     0,    79,     0,     0,     0,     0,     0,     0,
       0,   451,     0,     0,     0,     0,     0,   440,     0,   441,
       0,     0,     0,     0,    70,    71,    44,    45,   491,    53,
       0,     0,    38,    39,     0,     0,     0,     0,     0,     0,
     462,   463,   464,     0,     0,     0,     0,   679,   680,     0,
      43,   672,   673,   674,   675,   676,   677,   678,     0,     0,
       0,   442,     0,     0,     0,    62,     0,     0,     0,    54,
       0,   197,     0,     0,   149,   150,     0,     0,   114,   115,
       0,     0,   135,     0,     0,     0,   437,     0,     0,     0,
     445,     0,     0,     0,     0,    76,     0,    77,   336,   361,
     360,   357,     0,     0,   391,   390,   275,   450,     0,   388,
       0,   475,   476,   436,     0,     0,     0,     0,     0,     0,
     481,     0,     0,     0,   152,   169,     0,    16,     0,    18,
      96,     0,     0,     0,     0,   113,   170,     0,     0,     0,
       0,     0,     0,     0,     0,   209,   211,   215,   221,   220,
     219,     0,   216,   213,   214,     0,     0,     0,   664,   223,
     643,   651,   653,   655,   657,   659,   662,   229,   228,   226,
     232,   233,   234,   231,   236,   237,   240,   239,     0,     0,
       0,     0,   271,     0,   283,   284,     0,   319,   340,   342,
       0,     0,   267,     0,     0,     0,     0,     0,     0,   455,
       0,   452,   400,     0,   399,   408,   409,     0,     0,     0,
       0,    42,     0,     0,     0,     0,     0,    52,     0,     0,
     681,   682,     0,   683,   687,     0,     0,   716,   685,   686,
     715,   684,   688,     0,   695,   717,     0,     0,   444,   443,
     410,     0,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   642,     0,     0,
     116,   117,     0,   122,   458,   438,   439,     0,     0,   448,
       0,   446,   404,     0,     0,    78,   360,   358,     0,   349,
       0,   338,   339,     0,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,   123,   181,   177,   179,     0,   171,
     172,     0,   499,   507,   416,   417,   423,   424,   426,     0,
     139,     0,     0,     0,     0,     0,     0,     0,   218,     0,
       0,   658,     0,   224,     0,   671,     0,     0,     0,     0,
       0,     0,     0,   644,   648,   666,   647,   670,   668,   667,
     669,     0,     0,     0,   660,   723,   721,   725,   663,   242,
     244,   246,   414,   248,   272,   320,     0,   341,    80,   268,
     269,   270,     0,     0,   203,     0,     0,     0,   459,     0,
       0,   401,     0,    72,     0,    88,    83,     0,    84,     0,
       0,    50,    51,    48,    49,    67,     0,     0,    40,    41,
      46,    47,    37,     0,     0,     0,   690,     0,   689,   706,
       0,     0,   411,     0,    64,    58,    61,    60,     0,    56,
       0,   195,   199,     0,     0,     0,   154,     0,     0,     0,
       0,     0,   118,     0,     0,     0,     0,   163,     0,   160,
     165,   121,     0,     0,   459,     0,   405,   196,   361,     0,
     350,     0,   384,   381,     0,   385,   386,     0,     0,   387,
     380,     0,   355,   383,   382,     0,     0,     0,   468,   469,
     465,     0,     0,   473,   474,   470,   479,   477,     0,     0,
       0,   483,     0,   484,   485,     0,     0,   178,   190,     0,
     191,     0,   182,   183,   184,   185,     0,   174,     0,   138,
       0,     0,   420,   422,   421,   418,   147,   148,   141,     0,
     143,   140,     0,     0,     0,   665,   661,     0,   718,   719,
     739,   738,   734,     0,     0,     0,     0,   720,   652,   733,
     645,     0,     0,   650,   649,   654,     0,     0,   724,   722,
     415,   343,     0,     0,     0,   204,   402,     0,   456,   457,
     460,   453,   454,    90,     0,     0,    73,     0,    85,    86,
      87,    66,    69,     0,   704,     0,     0,   702,   698,     0,
       0,     0,   412,     0,    63,     0,    57,   198,   200,    11,
     151,   156,   155,     0,   158,     0,     0,     0,   120,   161,
     164,     0,   406,     0,   449,   447,   360,     0,     0,   392,
       0,   360,     0,   356,     7,     0,     0,     0,     0,     0,
     482,     0,     0,   486,     0,   153,   194,   192,   193,   186,
     187,   188,   180,     0,   175,   173,   425,   419,   145,   142,
       0,   144,   740,     0,     0,   726,     0,   737,   736,   735,
     730,   731,   646,   656,   732,     0,     0,     0,     0,   403,
      91,    74,    89,     0,    93,    68,     0,     0,   705,   707,
     709,   711,     0,   703,     0,     0,     0,   693,     0,   691,
       0,   413,     0,    59,   157,   159,   168,   167,   162,   119,
     407,     0,   360,     0,    92,     0,   360,   466,   467,   471,
     472,   478,   480,     0,   641,   189,   176,   146,   728,   727,
       0,     0,   205,     0,   201,    75,   714,   713,   708,   712,
     710,   699,   700,     0,   696,     0,   207,    65,     0,   370,
     364,   359,     0,   360,   351,     0,     0,     0,   729,     0,
       0,     0,     0,   694,   692,     0,   378,   372,     0,   371,
     373,   379,   376,   366,     0,   365,   367,   377,   353,     0,
     352,     0,   487,     0,   202,   701,   697,   166,   363,   374,
     375,   362,   368,   369,   354,     0,   206,     0,     0,     0,
     488,     0,     0,     0,     0,   489,     0,     0,   490
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -904,  -904,  -904,   741,   742,  -904,   744,  -904,   508,   511,
    -411,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -734,  -904,  -904,  -904,  -904,   -57,
    -662,  -904,  -904,  -904,  -904,  -904,  -904,  -118,  -904,  -873,
     747,   -72,  -289,  -904,  -904,  -904,   193,  -904,  -904,   718,
    -904,  -904,  -904,  -904,  -904,   132,  -420,  -548,  -904,  -904,
    -904,    21,  -904,  -904,  -144,    22,   -29,  -904,  -904,  -904,
     -40,  -904,  -904,   157,   -35,  -904,  -904,   -31,  -903,  -904,
     566,    45,  -904,  -904,    93,  -904,  -904,   515,   517,  -904,
    -422,  -801,   494,   182,  -473,   183,   175,  -904,  -904,  -904,
    -904,  -904,   722,  -904,  -904,  -904,  -904,  -904,   719,  -904,
    -904,   -91,  -904,  -904,  -904,  -904,  -904,  -904,  -904,   -30,
    -141,  -904,  -904,   342,   112,  -904,  -461,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -760,  -904,    23,  -904,
     375,  -583,  -904,  -904,  -904,  -904,  -904,  -268,  -261,  -884,
    -666,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,   298,  -564,  -672,  -904,  -904,   -16,  -627,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,   595,   596,  -595,   282,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,     5,  -904,  -904,
       2,  -358,  -334,   -10,  -904,   330,  -904,  -904,   144,   136,
     -48,   334,  -904,  -904,   146,  -904,  -622,  -904,  -904,  -904,
    -904,  -178,  -717,  -904,   -75,  -490,  -904,  -554,  -904,  -904,
    -904,  -904,  -828,  -904,  -904,  -904,  -904,   -38,   154,  -904
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   914,   568,   215,   216,   217,   708,
     218,   398,   219,   220,   221,   222,   884,   885,   959,   888,
     223,   224,   225,   226,   381,   762,   763,   227,   443,   228,
     445,   229,   230,   231,   449,   450,   937,   643,   232,   574,
     623,   575,   581,   938,   939,   940,   624,   446,   447,   809,
     810,  1124,   448,   806,   807,   992,   993,   994,   995,   233,
     570,   571,   234,   873,   874,   235,   236,   237,   238,   651,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   469,   470,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   496,   497,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   690,   279,   280,   281,   961,   600,
     601,   602,  1221,  1244,  1245,  1238,  1239,  1246,  1240,   962,
     963,   282,   283,   964,   284,   285,   286,   287,   288,   289,
     290,   861,   644,   814,  1005,   815,   816,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   876,   877,   301,
     302,   303,   304,   305,   306,   307,   619,   620,   308,   983,
     984,   915,   371,   309,   310,   659,   843,   660,   661,   662,
     663,   664,   665,   666,   844,   845,   550,   551,   552,   553,
     554,  1213,  1214,   555,  1158,  1067,  1162,  1159,   556,   557,
     847,   858,  1026,   848,   849,   854,   850,  1140,  1022,   833
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       347,   529,   670,   671,   672,   673,   859,   860,   751,   908,
     658,   817,   756,   919,   565,   569,  1059,   778,   399,   401,
     960,   629,   503,   408,   504,  1037,   394,     4,   755,   868,
     539,   642,   647,   410,   648,   649,   562,   650,   846,   652,
    1030,   573,   639,   638,   388,   639,   395,   653,   654,   759,
    1023,   817,   817,   353,   354,   355,   604,   796,   638,   396,
     368,  1209,   560,   356,   353,   354,   355,   822,   357,  1236,
    1219,  1133,  1023,   952,   356,   928,   433,  1103,  1012,   358,
     433,   359,   402,   779,   360,   584,   748,   361,   577,   825,
    1120,  1121,   640,   748,   823,   406,   827,  1147,   433,   433,
      62,   407,   543,   754,   528,   879,   698,   433,   722,   362,
     363,    72,   526,   783,   638,   638,  1018,   700,   989,   585,
     362,   472,   800,   311,   611,   612,   891,   614,   615,   616,
     617,   312,   530,   622,   427,    86,   991,  1134,   473,   655,
     313,   428,   656,   892,   630,   527,   368,   531,   780,  1019,
     897,   598,   635,   636,   364,  1220,   952,   953,   801,   597,
     785,  1148,   749,   750,   930,   789,   492,   318,   955,   774,
     956,   784,   528,   943,   696,   945,   433,   775,  1237,   717,
     865,   699,   797,   433,  1076,   760,   768,   641,   952,   953,
    1070,   960,   701,   949,   931,   658,   658,   957,   641,   641,
    1043,   960,   605,  1024,  1025,   411,  1210,   561,   929,   641,
     746,   952,   641,   689,  1103,   365,  1195,   586,   761,   770,
     451,  1034,  1242,   564,   826,  1024,  1025,   641,  1060,   828,
     742,  1142,   498,   745,   954,   500,   544,  1164,   723,   366,
    1165,   886,   505,   657,   545,   817,   509,   566,   692,   866,
     366,   955,   395,   956,  1055,   395,   887,   546,   736,   547,
     369,   769,   348,   370,   479,   510,   954,   724,   725,   548,
     726,   727,   549,   433,   480,  1166,   515,   516,  1013,   518,
     957,   786,   787,   955,    92,   956,   790,   791,  1168,   367,
    1226,   567,  1232,   535,   771,   558,   788,   559,   536,   433,
     103,   792,   952,   953,  1232,   882,   955,   374,   956,  1267,
    1272,  1236,   957,   434,   589,   952,    92,  1243,   375,   435,
     433,   958,   436,   437,   867,     4,   596,  1137,   513,  1056,
     438,   603,   103,  1138,   475,   957,   349,   608,   960,   350,
     130,  1139,   433,   520,   805,   697,   523,   433,   952,   537,
    1167,   820,   433,  1097,  1252,   481,   433,   898,   899,  1242,
     476,   902,  1156,  1169,   572,  1227,   576,  1233,   482,  1031,
     883,   704,   130,   477,   583,   433,   433,   592,   658,  1234,
     954,   419,  1151,  1231,  1268,  1273,   420,   572,   493,   494,
     658,   629,   705,   314,   924,  1270,   433,   955,    62,   956,
    1275,   433,   684,   685,  1278,   433,   433,   478,   538,    72,
     955,   621,   956,   625,   706,   439,   433,   440,   683,   737,
    1259,   433,   433,   686,   767,  1157,   957,   817,   781,   872,
      92,   441,   377,    86,   693,   694,   695,   655,  1217,   957,
     656,  1044,   703,   955,   433,   956,   103,   782,   864,   376,
     433,   433,   952,   953,  1262,   433,   433,   490,   442,   905,
     921,   922,   315,   316,   317,   926,   950,  1102,   869,  1065,
     933,   934,   957,   870,   479,  1069,   905,   871,   881,   383,
     105,  1205,  1020,   384,   480,   947,   130,  1021,   912,  1150,
     639,   741,   906,   946,  1015,   378,   379,   968,   969,   970,
     382,   973,   974,   975,   976,   977,   978,   385,   980,   981,
    1002,   709,   710,  1181,   805,  1256,  1149,   638,  1185,   397,
     472,   773,  1154,  1171,   714,  1066,   817,  1180,  1184,  1229,
     954,   951,   907,  1008,   731,  1010,  1011,   473,   380,   988,
    1003,  1058,   933,   934,  1132,   933,   934,   955,   935,   956,
     989,  1135,  1136,  1241,  1247,  1074,   887,   895,  1004,   990,
     474,   893,   896,   732,   733,   639,   734,   735,   991,   403,
     758,   855,   856,  1241,   817,   658,   957,  1041,   894,  1247,
      92,  1137,   351,   829,   404,   352,   936,  1138,   524,   776,
     834,   532,  1062,   857,   543,  1139,   103,  1063,  1200,  1222,
     479,   409,   525,  1225,  1208,   533,   499,  1061,   687,  1208,
     480,   687,   501,   687,   415,   372,   720,  1183,   373,   721,
     418,  1071,   804,   728,   412,   413,   729,   414,   818,   421,
     416,  1116,   417,   422,  1078,   966,   130,   967,  1081,  1082,
    1249,  1084,   540,   541,   542,   971,  1088,   972,   900,   901,
    1117,  1118,   889,   890,   667,   668,   676,   677,   835,   423,
    1198,  1199,   674,   675,   862,   862,  1206,  1207,   818,   818,
     818,   818,   424,   431,   432,   433,   452,   453,   471,   483,
     484,   485,   495,   486,   506,   502,   507,   508,   878,   514,
     878,   517,   519,   521,   522,   528,  1114,   368,   563,   534,
     578,   579,   834,   580,   582,   593,   543,   805,   599,   338,
     350,   352,   370,   387,   606,   609,   607,  1173,   610,   618,
    1128,   613,   628,  1129,   632,  1131,   637,  1228,   544,   631,
     678,   633,   634,   711,   679,   680,   545,   681,   836,   837,
     838,   707,   712,   713,   691,   718,   715,   716,   839,   546,
     730,   547,   719,   738,   739,   743,   840,   744,   944,   747,
     944,   548,   841,   842,   549,  1196,   752,   753,   793,   795,
     835,   798,   757,   808,  1155,   794,   764,   765,   766,   799,
     803,   811,   819,   802,   821,   824,   832,   851,   853,   872,
     903,   910,   904,    90,  1174,   875,  1175,   852,   997,   909,
     911,   451,  1179,  1047,   913,   916,   917,   918,   920,  1006,
     925,  1007,   923,   948,   932,  1057,  1187,  1188,  1189,  1190,
    1191,   942,  1192,   927,   965,   979,   986,   985,   996,   998,
    1009,  1000,  1001,  1014,  1016,   982,  1017,  1036,  1039,  1073,
     544,  1197,  1038,  1040,  1050,  1054,  1064,  1068,   545,  1027,
     836,   837,   838,  1048,  1075,  1049,  1079,  1202,  1051,  1204,
    1085,   546,   818,   547,  1083,  1052,  1086,  1091,   840,  1087,
    1093,  1096,  1053,   548,  1032,   842,   549,  1094,  1099,   454,
    1095,  1216,  1109,  1104,  1112,  1100,  1111,   455,   456,   989,
     457,  1105,  1123,  1144,  1126,   638,  1127,   458,  1130,  1146,
    1153,   459,   882,   460,  1160,  1161,  1194,  1170,   461,  1172,
     572,  1201,  1211,  1212,   905,   576,  1106,  1218,  1107,  1230,
    1224,  1235,  1108,  1248,   462,  1250,  1089,   887,  1251,  1253,
    1258,  1261,  1264,  1269,   425,   426,  1274,  1152,  1277,   626,
     429,  1254,   627,   999,   430,  1178,  1080,   444,  1101,   463,
     464,   465,   466,   467,   468,  1255,   941,  1115,  1125,  1090,
     987,  1122,  1119,   594,  1266,  1077,  1045,   645,   669,   621,
     646,  1193,   489,   491,  1098,   777,   625,  1263,  1260,   863,
     587,   588,   880,  1028,  1110,  1113,   830,  1035,  1143,  1033,
    1215,   831,  1163,  1141,  1029,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   818,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1176,  1177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1182,     0,     0,
       0,     0,  1186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   395,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1203,     0,     0,
       0,     0,     0,   818,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1223,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   818,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1265,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,  1271,
       0,     5,     6,     0,  1276,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,     0,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    60,    61,     0,     0,     0,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
       0,    73,    74,    75,    76,     0,    77,     0,     0,     0,
      78,    79,    80,    81,    82,     0,     0,     0,     0,     0,
      83,    84,    85,    86,    87,    88,    89,    90,     0,     0,
      91,    92,    93,    94,    95,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,     0,   102,   103,     0,   104,
     105,     0,     0,   106,   107,   108,     0,     0,     0,   109,
       0,   110,   111,   112,     0,   113,   114,   115,     0,   116,
       0,   117,   118,   119,   120,   121,     0,   122,   123,   124,
     125,   126,   127,     0,     0,   128,   129,   130,     0,   131,
     132,     0,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,     0,
     169,   170,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       5,     6,     0,     0,     7,     8,     9,    10,    11,    12,
      13,   325,    15,    16,     0,    17,    18,    19,   328,    21,
      22,     0,    24,    25,    26,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
       0,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    60,    61,     0,     0,     0,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,     0,
      73,    74,    75,    76,     0,    77,     0,     0,     0,    78,
      79,    80,    81,    82,     0,     0,     0,     0,     0,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,    91,
      92,    93,    94,    95,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,     0,   102,   103,     0,   104,   105,
       0,     0,   106,   107,   108,     0,     0,     0,   109,   400,
     110,   111,   112,     0,   113,   114,   115,     0,   116,     0,
     117,   118,   119,   120,   121,     0,   122,   123,   124,   125,
     126,   127,     0,     0,   128,   129,   130,     0,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,     0,   169,
     170,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     5,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,     0,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    60,    61,     0,     0,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,     0,    73,
      74,    75,    76,     0,    77,     0,     0,     0,    78,    79,
      80,    81,    82,     0,     0,     0,     0,     0,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,     0,   102,   103,     0,   104,   105,     0,
       0,   106,   107,   108,     0,     0,     0,   109,     0,   110,
     111,   112,     0,   113,   114,   115,     0,   116,     0,   117,
     118,   119,   120,   121,     0,   122,   123,   124,   125,   126,
     127,     0,     0,   128,   129,   130,     0,     0,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,     0,   169,   170,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     0,     5,     6,
       0,     0,     7,     8,     9,    10,    11,    12,    13,   325,
      15,    16,     0,    17,    18,    19,   328,    21,    22,     0,
      24,    25,    26,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,     0,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      60,    61,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,     0,    73,    74,
      75,    76,     0,    77,     0,     0,     0,    78,    79,    80,
      81,    82,     0,     0,     0,     0,     0,    83,    84,    85,
      86,    87,    88,    89,    90,     0,     0,    91,    92,    93,
      94,    95,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,     0,   102,   103,     0,   104,   105,     0,     0,
     106,   107,   108,     0,   595,     0,   109,     0,   110,   111,
     112,     0,   113,   114,   115,     0,   116,     0,   117,   118,
     119,   120,   121,     0,   122,   123,   124,   125,   126,   127,
       0,     0,   128,   129,   130,     0,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,   169,   170,     0,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     0,
       0,     7,     8,     9,    10,    11,    12,    13,   325,    15,
      16,     0,    17,    18,    19,   328,    21,    22,     0,    24,
      25,    26,     0,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,     0,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
      61,     0,     0,     0,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,     0,    73,    74,    75,
      76,     0,    77,     0,     0,     0,    78,    79,    80,    81,
      82,     0,     0,     0,     0,     0,    83,    84,    85,    86,
      87,    88,    89,    90,     0,     0,    91,    92,    93,    94,
      95,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,     0,   102,   103,     0,   104,   105,     0,     0,   106,
     107,   108,     0,   682,     0,   109,     0,   110,   111,   112,
       0,   113,   114,   115,     0,   116,     0,   117,   118,   119,
     120,   121,     0,   122,   123,   124,   125,   126,   127,     0,
       0,   128,   129,   130,     0,     0,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,     0,   169,   170,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     5,     6,     0,     0,
       7,     8,     9,    10,    11,    12,    13,   325,    15,    16,
       0,    17,    18,    19,   328,    21,    22,     0,    24,    25,
      26,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,     0,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    60,    61,
       0,     0,     0,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,     0,    73,    74,    75,    76,
       0,    77,     0,     0,     0,    78,    79,    80,    81,    82,
       0,     0,     0,     0,     0,    83,    84,    85,    86,    87,
      88,    89,    90,     0,     0,    91,    92,    93,    94,    95,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
       0,   102,   103,     0,   104,   105,     0,     0,   106,   107,
     108,     0,     0,     0,   109,   688,   110,   111,   112,     0,
     113,   114,   115,     0,   116,     0,   117,   118,   119,   120,
     121,     0,   122,   123,   124,   125,   126,   127,     0,     0,
     128,   129,   130,     0,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,     0,   169,   170,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     0,     0,     7,
       8,     9,    10,    11,    12,    13,   325,    15,    16,     0,
      17,    18,    19,   328,    21,    22,     0,    24,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     0,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    60,    61,     0,
       0,     0,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,     0,    73,    74,    75,    76,     0,
      77,     0,     0,     0,    78,    79,    80,    81,    82,     0,
       0,     0,     0,     0,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,    91,    92,    93,    94,    95,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,     0,
     102,   103,     0,   104,   105,     0,     0,   106,   107,   108,
       0,   702,     0,   109,     0,   110,   111,   112,     0,   113,
     114,   115,     0,   116,     0,   117,   118,   119,   120,   121,
       0,   122,   123,   124,   125,   126,   127,     0,     0,   128,
     129,   130,     0,     0,   132,     0,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,     0,   169,   170,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     5,     6,     0,     0,     7,     8,
       9,    10,    11,    12,    13,   325,    15,    16,     0,    17,
      18,    19,   328,    21,    22,     0,    24,    25,    26,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     0,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    60,    61,     0,     0,
       0,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,     0,    73,    74,    75,    76,     0,    77,
       0,     0,     0,    78,    79,    80,    81,    82,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     0,    91,    92,    93,    94,    95,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,     0,   102,
     103,     0,   104,   105,     0,     0,   106,   107,   108,     0,
     740,     0,   109,     0,   110,   111,   112,     0,   113,   114,
     115,     0,   116,     0,   117,   118,   119,   120,   121,     0,
     122,   123,   124,   125,   126,   127,     0,     0,   128,   129,
     130,     0,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,     0,   169,   170,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     0,     0,     7,     8,     9,
      10,    11,    12,    13,   325,    15,    16,     0,    17,    18,
      19,   328,    21,    22,     0,    24,    25,    26,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,     0,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    60,    61,     0,     0,     0,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,     0,    73,    74,    75,    76,     0,    77,     0,
       0,     0,    78,    79,    80,    81,    82,     0,     0,     0,
       0,     0,    83,    84,    85,    86,    87,    88,    89,    90,
       0,     0,    91,    92,    93,    94,    95,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,     0,   102,   103,
       0,   104,   105,     0,     0,   106,   107,   108,     0,   772,
       0,   109,     0,   110,   111,   112,     0,   113,   114,   115,
       0,   116,     0,   117,   118,   119,   120,   121,     0,   122,
     123,   124,   125,   126,   127,     0,     0,   128,   129,   130,
       0,     0,   132,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,     0,   169,   170,     0,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,     5,     6,     0,     0,     7,     8,     9,    10,
      11,    12,    13,   325,    15,    16,     0,    17,    18,    19,
     328,    21,    22,     0,    24,    25,    26,     0,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     0,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    60,    61,     0,     0,     0,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,     0,    73,    74,    75,    76,     0,    77,     0,     0,
       0,    78,    79,    80,    81,    82,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    88,    89,    90,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,     0,   102,   103,     0,
     104,   105,     0,     0,   106,   107,   108,     0,  1046,     0,
     109,     0,   110,   111,   112,     0,   113,   114,   115,     0,
     116,     0,   117,   118,   119,   120,   121,     0,   122,   123,
     124,   125,   126,   127,     0,     0,   128,   129,   130,     0,
       0,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
       0,   169,   170,     0,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     0,     0,     7,     8,     9,    10,    11,
      12,    13,   325,    15,    16,     0,    17,    18,    19,   328,
      21,    22,     0,    24,    25,    26,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,     0,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    60,    61,     0,     0,     0,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
       0,    73,    74,    75,    76,     0,    77,     0,     0,     0,
      78,    79,    80,    81,    82,     0,     0,     0,     0,     0,
      83,    84,    85,    86,    87,    88,    89,    90,     0,     0,
      91,    92,    93,    94,    95,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,     0,   102,   103,     0,   104,
     105,     0,     0,   106,   107,   108,     0,  1072,     0,   109,
       0,   110,   111,   112,     0,   113,   114,   115,     0,   116,
       0,   117,   118,   119,   120,   121,     0,   122,   123,   124,
     125,   126,   127,     0,     0,   128,   129,   130,     0,     0,
     132,     0,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,     0,
     169,   170,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       5,     6,     0,     0,     7,     8,     9,    10,    11,    12,
      13,   325,    15,    16,     0,    17,    18,    19,   328,    21,
      22,     0,    24,    25,    26,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
       0,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    60,    61,     0,     0,     0,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,     0,
      73,    74,    75,    76,     0,    77,     0,     0,     0,    78,
      79,    80,    81,    82,     0,     0,     0,     0,     0,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,    91,
      92,    93,    94,    95,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,     0,   102,   103,     0,   104,   105,
       0,     0,   106,   107,   108,     0,  1092,     0,   109,     0,
     110,   111,   112,     0,   113,   114,   115,     0,   116,     0,
     117,   118,   119,   120,   121,     0,   122,   123,   124,   125,
     126,   127,     0,     0,   128,   129,   130,     0,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,     0,   169,
     170,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     5,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
     325,    15,    16,     0,    17,    18,    19,   328,    21,    22,
       0,    24,    25,    26,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,     0,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    60,    61,     0,     0,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,     0,    73,
      74,    75,    76,     0,    77,     0,     0,     0,    78,    79,
      80,    81,    82,     0,     0,     0,     0,     0,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,     0,   102,   103,     0,   104,   105,     0,
       0,   106,   107,   108,     0,     0,     0,   109,     0,   110,
     111,   112,     0,   113,   114,   115,     0,   116,     0,   117,
     118,   119,   120,   121,     0,   122,   123,   124,   125,   126,
     127,     0,     0,   128,   129,   130,     0,     0,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,     0,   169,   170,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,   320,    10,    11,    12,    13,   325,
      15,    16,     0,   326,    18,    19,   328,   329,    22,     0,
      24,    25,    26,     0,   330,    28,     0,   331,   332,    32,
      33,    34,    35,    36,    37,    38,    39,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,     0,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      60,    61,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,     0,    73,    74,
      75,    76,     0,    77,     0,     0,     0,   336,    79,    80,
      81,    82,     0,     0,     0,     0,     0,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    91,    92,   487,
      94,    95,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,     0,   102,   103,     0,   488,   105,     0,     0,
     106,   107,   108,     0,     0,     0,   109,     0,   110,   111,
     112,     0,   113,   114,   115,     0,   116,     0,   117,   118,
     119,   120,   121,     0,   122,   123,   124,   125,   126,   127,
       0,     0,   128,   129,   130,     0,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   341,   141,   343,   143,
     344,   345,   146,   147,   148,   149,   150,   151,   346,   153,
       0,     0,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,   169,   170,     0,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,   320,    10,    11,    12,    13,   325,    15,
      16,     0,   326,    18,    19,   328,   329,    22,     0,    24,
      25,    26,     0,   330,    28,     0,   331,   332,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,     0,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
      61,     0,     0,     0,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,     0,    73,    74,    75,
      76,     0,    77,     0,     0,     0,   336,    79,    80,    81,
      82,     0,     0,     0,     0,     0,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    91,    92,    93,    94,
      95,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,     0,   102,   103,     0,   104,   105,     0,     0,   106,
     107,   108,     0,     0,     0,   109,     0,   110,   111,   112,
       0,   113,   114,   115,     0,   116,     0,   117,   118,   119,
     120,   121,     0,   122,   123,   124,   125,   126,   127,     0,
       0,   128,   129,   130,     0,     0,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   341,   141,   343,   143,   344,
     345,   146,   147,   148,   149,   150,   151,   346,   153,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,     0,   169,   170,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   319,   320,    10,    11,    12,    13,   325,    15,    16,
       0,   326,    18,    19,   328,   329,    22,     0,    24,    25,
      26,     0,   330,    28,     0,   331,   332,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,     0,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    60,    61,
       0,     0,     0,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,     0,    73,    74,    75,    76,
       0,    77,     0,     0,     0,   336,    79,    80,    81,    82,
       0,     0,     0,     0,     0,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,    91,    92,     0,    94,    95,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
       0,   102,   103,     0,     0,     0,     0,     0,   106,   107,
     108,     0,     0,     0,   109,     0,   110,   111,   112,     0,
       0,     0,   115,     0,   116,     0,   117,   118,   119,   120,
     121,     0,   122,   123,   124,   125,   126,   127,     0,     0,
     128,   129,   130,     0,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   341,   141,   343,   143,   344,   345,
     146,   147,   148,   149,   150,   151,   346,   153,     0,     0,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,     0,   169,   170,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     319,   320,   389,   322,   390,   391,   325,    15,    16,     0,
     326,   392,    19,   328,   329,    22,     0,    24,    25,    26,
       0,   330,    28,     0,   331,   332,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    41,    42,    43,    44,    45,
      46,    47,     0,     0,    50,     0,    51,    52,    53,   393,
       0,     0,    57,    58,    59,     0,     0,     0,    61,     0,
       0,     0,     0,    63,    64,     0,     0,    67,    68,     0,
       0,     0,     0,     0,     0,    73,    74,    75,    76,     0,
      77,     0,     0,     0,   336,    79,    80,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,     0,    87,    88,
      89,     0,     0,     0,     0,     0,     0,    94,    95,     0,
       0,     0,     0,    96,    97,    98,   339,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,   109,     0,   110,   111,     0,     0,     0,
       0,   115,     0,   116,     0,   117,   118,   119,   120,   340,
       0,   122,   123,   124,   125,   126,   127,     0,     0,   128,
     129,     0,     0,     0,   132,     0,   133,   134,   135,   136,
     137,   138,   139,   341,   141,   343,   143,   344,   345,   146,
     147,   148,   149,   150,   151,   346,   153,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,     0,   169,   170,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
     320,   321,   322,   323,   324,   325,    15,    16,     0,   326,
     327,    19,   328,   329,    22,     0,    24,    25,    26,     0,
     330,    28,     0,   331,   332,    32,    33,    34,    35,    36,
      37,    38,    39,     0,    41,   333,   334,    44,    45,    46,
      47,     0,     0,    50,     0,    51,    52,    53,   335,     0,
       0,    57,    58,    59,     0,     0,     0,    61,     0,     0,
       0,     0,    63,    64,     0,     0,    67,    68,     0,     0,
       0,     0,     0,     0,    73,    74,    75,    76,     0,    77,
       0,     0,     0,   336,    79,    80,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,     0,    87,    88,    89,
       0,     0,     0,     0,     0,     0,    94,    95,     0,     0,
       0,     0,    96,    97,    98,   339,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,   109,     0,   110,     0,     0,     0,     0,     0,
     115,     0,   116,     0,   117,   118,   119,   120,   340,     0,
     122,   123,   124,   125,   126,   127,     0,     0,   128,   129,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   341,   342,   343,   143,   344,   345,   146,   147,
     148,   149,   150,   151,   346,   153,     0,     0,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,     0,   169,   170,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   405,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   319,   320,   321,   322,   323,   324,   325,    15,
      16,     0,   326,   327,    19,   328,   329,    22,     0,    24,
      25,    26,     0,   330,    28,     0,   331,   332,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    41,   333,   334,
      44,    45,    46,    47,     0,     0,    50,     0,    51,    52,
      53,   335,     0,     0,    57,    58,    59,     0,     0,     0,
      61,     0,     0,     0,     0,    63,    64,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,    73,    74,    75,
      76,     0,    77,     0,     0,     0,   336,    79,    80,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,     0,
      87,    88,    89,     0,     0,     0,     0,     0,     0,    94,
      95,     0,     0,     0,     0,    96,    97,    98,   339,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,     0,   109,     0,   110,     0,     0,
       0,     0,     0,     0,     0,   116,     0,   117,   118,   119,
     120,   340,     0,   122,   123,   124,   125,   126,   127,     0,
       0,   128,   129,     0,     0,     0,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   341,   342,   343,   143,   344,
     345,   146,   147,   148,   149,   150,   151,   346,   153,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,     0,   169,   170,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,   320,   321,   322,   323,   324,   325,
      15,    16,     0,   326,   327,    19,   328,   329,    22,     0,
      24,    25,    26,     0,   330,    28,     0,   331,   332,    32,
      33,    34,    35,    36,    37,    38,    39,     0,    41,   333,
     334,    44,    45,    46,    47,     0,     0,    50,     0,    51,
      52,    53,   335,     0,     0,    57,    58,    59,     0,     0,
       0,    61,     0,     0,     0,     0,    63,    64,     0,     0,
      67,    68,     0,     0,     0,     0,     0,     0,    73,    74,
      75,    76,     0,    77,     0,     0,     0,   336,    79,    80,
       0,     0,     0,     0,     0,     0,     0,    83,    84,    85,
       0,    87,    88,    89,   337,     0,     0,   338,     0,     0,
      94,    95,     0,     0,     0,     0,    96,    97,    98,   339,
     100,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,     0,   109,     0,   110,     0,
       0,     0,     0,     0,     0,     0,   116,     0,   117,   118,
     119,   120,   340,     0,   122,   123,   124,   125,   126,   127,
       0,     0,   128,   129,     0,     0,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   341,   342,   343,   143,
     344,   345,   146,   147,   148,   149,   150,   151,   346,   153,
       0,     0,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,   169,   170,     0,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   319,   320,   321,   322,   323,   324,
     325,    15,    16,     0,   326,   327,    19,   328,   329,    22,
       0,    24,    25,    26,     0,   330,    28,     0,   331,   332,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    41,
     333,   334,    44,    45,    46,    47,     0,     0,    50,     0,
      51,    52,    53,   335,     0,     0,    57,    58,    59,     0,
       0,     0,    61,     0,     0,     0,     0,    63,    64,     0,
       0,    67,    68,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,     0,    77,     0,     0,     0,   336,    79,
      80,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,     0,    87,    88,    89,   386,     0,     0,   387,     0,
       0,    94,    95,     0,     0,     0,     0,    96,    97,    98,
     339,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,     0,   109,     0,   110,
       0,     0,     0,     0,     0,     0,     0,   116,     0,   117,
     118,   119,   120,   340,     0,   122,   123,   124,   125,   126,
     127,     0,     0,   128,   129,     0,     0,     0,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   341,   342,   343,
     143,   344,   345,   146,   147,   148,   149,   150,   151,   346,
     153,     0,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,     0,   169,   170,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   319,   320,   321,   322,   323,
     324,   325,    15,    16,     0,   326,   327,    19,   328,   329,
      22,     0,    24,    25,    26,     0,   330,    28,     0,   331,
     332,    32,    33,    34,    35,    36,    37,    38,    39,     0,
      41,   333,   334,    44,    45,    46,    47,     0,     0,    50,
       0,    51,    52,    53,   335,     0,     0,    57,    58,    59,
       0,     0,     0,    61,     0,     0,     0,     0,    63,    64,
       0,     0,    67,    68,     0,     0,     0,     0,     0,     0,
      73,    74,    75,    76,     0,    77,     0,     0,     0,   336,
      79,    80,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,     0,    87,    88,    89,     0,     0,     0,     0,
       0,     0,    94,    95,     0,     0,     0,     0,    96,    97,
      98,   339,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,   109,   511,
     110,     0,     0,     0,     0,     0,   512,     0,   116,     0,
     117,   118,   119,   120,   340,     0,   122,   123,   124,   125,
     126,   127,     0,     0,   128,   129,     0,     0,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   341,   342,
     343,   143,   344,   345,   146,   147,   148,   149,   150,   151,
     346,   153,     0,     0,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,     0,   169,
     170,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   319,   320,   321,   322,
     323,   324,   325,    15,    16,     0,   326,   327,    19,   328,
     329,    22,     0,    24,    25,    26,     0,   330,    28,     0,
     331,   332,    32,    33,    34,    35,    36,    37,    38,    39,
       0,    41,   333,   334,    44,    45,    46,    47,     0,     0,
      50,     0,    51,    52,    53,   335,     0,     0,    57,    58,
      59,     0,     0,     0,    61,     0,     0,     0,     0,    63,
      64,     0,     0,    67,    68,     0,     0,     0,     0,     0,
       0,    73,    74,    75,    76,     0,    77,     0,     0,     0,
     336,    79,    80,     0,     0,     0,     0,     0,     0,     0,
      83,    84,    85,     0,    87,    88,    89,     0,     0,     0,
       0,     0,     0,    94,    95,     0,     0,     0,     0,    96,
      97,    98,   339,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,   109,
     590,   110,     0,     0,     0,     0,     0,   591,     0,   116,
       0,   117,   118,   119,   120,   340,     0,   122,   123,   124,
     125,   126,   127,     0,     0,   128,   129,     0,     0,     0,
     132,     0,   133,   134,   135,   136,   137,   138,   139,   341,
     342,   343,   143,   344,   345,   146,   147,   148,   149,   150,
     151,   346,   153,     0,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,     0,
     169,   170,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   319,   320,   389,
     322,   390,   391,   325,    15,    16,     0,   326,   392,    19,
     328,   329,    22,     0,    24,    25,    26,     0,   330,    28,
       0,   331,   332,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    41,    42,    43,    44,    45,    46,    47,     0,
       0,    50,     0,    51,    52,    53,   393,     0,     0,    57,
      58,    59,     0,     0,     0,    61,     0,     0,     0,     0,
      63,    64,     0,     0,    67,    68,  1042,     0,     0,     0,
       0,     0,    73,    74,    75,    76,     0,    77,     0,     0,
       0,   336,    79,    80,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    85,     0,    87,    88,   812,     0,     0,
       0,     0,     0,     0,    94,    95,     0,     0,     0,     0,
      96,    97,    98,   339,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
     109,     0,   110,   111,     0,     0,     0,     0,     0,     0,
     116,     0,   117,   118,   119,   120,   340,     0,   122,   123,
     124,   125,   126,   127,     0,     0,   813,   129,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     341,   141,   343,   143,   344,   345,   146,   147,   148,   149,
     150,   151,   346,   153,     0,     0,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
       0,   169,   170,     0,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   319,   320,
     389,   322,   390,   391,   325,    15,    16,     0,   326,   392,
      19,   328,   329,    22,     0,    24,    25,    26,     0,   330,
      28,     0,   331,   332,    32,    33,    34,    35,    36,    37,
      38,    39,     0,    41,    42,    43,    44,    45,    46,    47,
       0,     0,    50,     0,    51,    52,    53,   393,     0,     0,
      57,    58,    59,     0,     0,     0,    61,     0,     0,     0,
       0,    63,    64,     0,     0,    67,    68,     0,     0,     0,
       0,     0,     0,    73,    74,    75,    76,     0,    77,     0,
       0,     0,   336,    79,    80,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,     0,    87,    88,   812,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,    96,    97,    98,   339,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,   109,     0,   110,   111,     0,     0,     0,     0,     0,
       0,   116,     0,   117,   118,   119,   120,   340,     0,   122,
     123,   124,   125,   126,   127,     0,     0,   813,   129,     0,
       0,     0,   132,     0,   133,   134,   135,   136,   137,   138,
     139,   341,   141,   343,   143,   344,   345,   146,   147,   148,
     149,   150,   151,   346,   153,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,     0,   169,   170,     0,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
     320,   321,   322,   323,   324,   325,    15,    16,     0,   326,
     327,    19,   328,   329,    22,     0,    24,    25,    26,     0,
     330,    28,     0,   331,   332,    32,    33,    34,    35,    36,
      37,    38,    39,     0,    41,   333,   334,    44,    45,    46,
      47,     0,     0,    50,     0,    51,    52,    53,   335,     0,
       0,    57,    58,    59,     0,     0,     0,    61,     0,     0,
       0,     0,    63,    64,     0,     0,    67,    68,     0,     0,
       0,     0,     0,     0,    73,    74,    75,    76,     0,    77,
       0,     0,     0,   336,    79,    80,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,     0,    87,    88,    89,
       0,     0,     0,     0,     0,     0,    94,    95,     0,     0,
       0,     0,    96,    97,    98,   339,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,   109,     0,   110,     0,     0,     0,     0,     0,
       0,     0,   116,     0,   117,   118,   119,   120,   340,     0,
     122,   123,   124,   125,   126,   127,     0,     0,   128,   129,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   341,   342,   343,   143,   344,   345,   146,   147,
     148,   149,   150,   151,   346,   153,     0,     0,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,     0,   169,   170,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        10,   359,   475,   476,   477,   478,   678,   679,   572,   726,
     471,   638,   576,   747,   372,   373,   889,   600,    90,    91,
     780,   432,   311,   114,   313,   853,    56,    19,   576,   691,
     364,   451,   454,    20,   456,   457,   370,   459,   660,   461,
     841,   375,    78,    76,    54,    78,    56,   469,   470,    60,
      78,   678,   679,    37,    38,    39,     6,    89,    76,    69,
      17,    19,    19,    47,    37,    38,    39,   125,    52,     3,
      75,    42,    78,     7,    47,   121,    89,   961,   125,    63,
      89,    65,    92,   109,    68,    32,    89,    71,   377,   125,
     993,   994,   125,    89,   642,   105,   644,    99,    89,    89,
      92,   111,    82,   121,    19,   700,    89,    89,    94,    93,
      94,   103,   146,   110,    76,    76,   196,    89,    88,    66,
      93,   136,    53,   216,   413,   414,   126,   416,   417,   418,
     419,    27,   144,   422,    36,   127,   106,   108,   153,   131,
     134,    43,   134,   143,   433,   179,    17,   159,   174,   229,
     714,   164,   441,   442,   138,   160,     7,     8,    89,   168,
      76,   163,   165,   125,   125,    76,   257,   134,   102,   165,
     104,   168,    19,   768,   164,   770,    89,   168,   112,   537,
     162,   164,   214,    89,   918,   196,    89,   245,     7,     8,
     907,   951,   164,   776,   758,   656,   657,   131,   245,   245,
     872,   961,   152,   231,   232,   192,   164,   164,   756,   245,
     568,     7,   245,   502,  1098,   199,  1119,   164,   229,    89,
     230,   843,    18,   138,   644,   231,   232,   245,   890,   651,
     564,  1032,   262,   567,    85,   265,   216,   243,   224,   223,
    1068,   116,   314,   235,   224,   872,   318,    94,   161,    89,
     223,   102,   262,   104,    89,   265,   131,   237,   164,   239,
     131,   164,   131,   134,   178,   337,    85,   253,   254,   249,
     256,   257,   252,    89,   188,    89,   348,   349,   826,   351,
     131,   197,   198,   102,   135,   104,   197,   198,    89,   134,
      89,   138,    89,    32,   164,   367,   212,   369,    37,    89,
     151,   212,     7,     8,    89,    99,   102,    99,   104,    89,
      89,     3,   131,    45,   386,     7,   135,   113,   138,    51,
      89,   172,    54,    55,   164,    19,   398,   241,   338,   164,
      62,   403,   151,   247,    98,   131,   131,   409,  1098,   134,
     191,   255,    89,   353,   633,   161,   356,    89,     7,    88,
     164,   640,    89,   172,  1227,   115,    89,   715,   716,    18,
     124,   719,   115,   164,   374,   164,   376,   164,   128,   842,
     164,   161,   191,   137,   384,    89,    89,   387,   839,   164,
      85,   204,  1054,  1211,   164,   164,   209,   397,   169,   170,
     851,   802,   161,   131,   752,  1268,    89,   102,    92,   104,
    1273,    89,   493,   494,  1277,    89,    89,   171,   147,   103,
     102,   421,   104,   423,   161,   147,    89,   149,   490,   161,
     112,    89,    89,   495,   161,   178,   131,  1054,   161,    82,
     135,   163,   131,   127,   506,   507,   508,   131,  1172,   131,
     134,    94,   514,   102,    89,   104,   151,   161,   161,    99,
      89,    89,     7,     8,   113,    89,    89,   131,   190,    78,
     749,   750,   200,   201,   202,   754,   109,   172,   161,    78,
      58,    59,   131,   161,   178,    94,    78,   161,   161,    27,
     154,  1153,   241,   134,   188,   774,   191,   246,   161,  1053,
      78,   563,    94,   161,   161,    56,    57,   786,   787,   788,
      54,   790,   791,   792,   793,   794,   795,   134,   797,   798,
     123,   521,   522,  1096,   803,  1232,   161,    76,  1101,    99,
     136,   593,   161,   161,   534,   134,  1153,   161,   161,  1201,
      85,   174,   134,   822,   224,   824,   825,   153,    99,    77,
     153,   116,    58,    59,  1017,    58,    59,   102,    61,   104,
      88,  1024,  1025,  1219,  1220,   913,   131,   116,   171,    97,
     176,   126,   121,   253,   254,    78,   256,   257,   106,   131,
     580,   220,   221,  1239,  1201,  1036,   131,   866,   143,  1245,
     135,   241,   131,   655,    13,   134,    99,   247,   159,   599,
      78,   159,   116,   242,    82,   255,   151,   121,   176,  1182,
     178,   131,   173,  1186,  1158,   173,   264,   896,   496,  1163,
     188,   499,   270,   501,   134,    46,   222,   172,    49,   225,
     204,   910,   632,   222,   194,   204,   225,   206,   638,    99,
     204,   989,   206,   131,   923,   211,   191,   213,   927,   928,
    1223,   930,   200,   201,   202,   211,   935,   213,   107,   108,
     107,   108,   709,   710,   472,   473,   481,   482,   146,    99,
    1133,  1134,   479,   480,   680,   681,  1156,  1157,   678,   679,
     680,   681,     0,   168,   168,    89,   145,    74,   234,    69,
     177,    83,   132,    84,   131,   134,   131,   131,   698,   131,
     700,   164,   164,    37,    37,    19,   985,    17,   131,    99,
     251,   251,    78,    99,    99,   131,    82,   996,    24,   134,
     134,   134,   134,   134,    14,   192,   164,  1075,    19,   210,
    1009,   164,    36,  1012,    99,  1014,    89,  1200,   216,   147,
     210,   148,   148,    19,    76,    76,   224,    76,   226,   227,
     228,   134,    89,    89,   164,   106,   138,   138,   236,   237,
      19,   239,   111,   164,   164,    78,   244,    32,   768,    78,
     770,   249,   250,   251,   252,  1123,   111,    89,    76,   204,
     146,   121,   161,    99,  1063,   216,   164,   164,   164,   161,
     148,    99,    99,   168,    99,   125,   252,   233,   240,    82,
     254,   175,   255,   131,  1083,   131,  1085,   235,   808,   255,
     131,   811,  1091,   875,   111,   138,   111,    78,    99,   819,
      99,   821,   125,    24,   229,   887,  1105,  1106,  1107,  1108,
    1109,   131,  1111,   121,    19,    99,    99,   131,    89,    89,
     125,   134,   134,   125,   164,   218,   230,   125,    48,   911,
     216,  1130,   255,   123,   123,    76,   255,    19,   224,   230,
     226,   227,   228,   164,    89,   164,   168,  1146,   164,  1148,
     125,   237,   872,   239,   121,   164,    99,    61,   244,    99,
     942,   111,   882,   249,   250,   251,   252,   164,     5,   111,
     164,  1170,   216,   168,   134,   957,   163,   119,   120,    88,
     122,   212,    88,   248,   164,    76,   164,   129,   125,   163,
      76,   133,    99,   135,    19,    19,   161,   105,   140,    78,
     920,    76,    19,   238,    78,   925,   212,    59,   212,   163,
     174,    99,   212,   174,   156,   174,   936,   131,    99,   163,
      75,   160,   174,    99,   193,   193,    99,  1055,   164,   431,
     196,  1230,   431,   811,   197,  1089,   925,   229,   958,   181,
     182,   183,   184,   185,   186,   238,   763,   986,   998,   937,
     803,   996,   993,   397,  1253,   920,   873,   452,   474,   979,
     453,  1112,   250,   254,   951,   600,   986,  1245,  1239,   681,
     385,   385,   700,   839,   979,   983,   656,   851,  1036,   843,
    1168,   657,  1067,  1031,   840,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1042,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1054,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1086,  1087,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1097,    -1,    -1,
      -1,    -1,  1102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1147,    -1,    -1,
      -1,    -1,    -1,  1153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1251,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    19,    -1,    -1,    -1,  1269,
      -1,    25,    26,    -1,  1274,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    87,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
      -1,   105,   106,   107,   108,    -1,   110,    -1,    -1,    -1,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,    -1,   150,   151,    -1,   153,
     154,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,   163,
      -1,   165,   166,   167,    -1,   169,   170,   171,    -1,   173,
      -1,   175,   176,   177,   178,   179,    -1,   181,   182,   183,
     184,   185,   186,    -1,    -1,   189,   190,   191,    -1,   193,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
     234,   235,    -1,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    -1,    87,    88,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,    -1,
     105,   106,   107,   108,    -1,   110,    -1,    -1,    -1,   114,
     115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,    -1,   150,   151,    -1,   153,   154,
      -1,    -1,   157,   158,   159,    -1,    -1,    -1,   163,   164,
     165,   166,   167,    -1,   169,   170,   171,    -1,   173,    -1,
     175,   176,   177,   178,   179,    -1,   181,   182,   183,   184,
     185,   186,    -1,    -1,   189,   190,   191,    -1,    -1,   194,
      -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,   234,
     235,    -1,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    87,    88,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,   103,    -1,   105,
     106,   107,   108,    -1,   110,    -1,    -1,    -1,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,    -1,   150,   151,    -1,   153,   154,    -1,
      -1,   157,   158,   159,    -1,    -1,    -1,   163,    -1,   165,
     166,   167,    -1,   169,   170,   171,    -1,   173,    -1,   175,
     176,   177,   178,   179,    -1,   181,   182,   183,   184,   185,
     186,    -1,    -1,   189,   190,   191,    -1,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,   234,   235,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    -1,
      47,    48,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    -1,    -1,
      87,    88,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,   103,    -1,   105,   106,
     107,   108,    -1,   110,    -1,    -1,    -1,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,    -1,   150,   151,    -1,   153,   154,    -1,    -1,
     157,   158,   159,    -1,   161,    -1,   163,    -1,   165,   166,
     167,    -1,   169,   170,   171,    -1,   173,    -1,   175,   176,
     177,   178,   179,    -1,   181,   182,   183,   184,   185,   186,
      -1,    -1,   189,   190,   191,    -1,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,   234,   235,    -1,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    87,
      88,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,    -1,   105,   106,   107,
     108,    -1,   110,    -1,    -1,    -1,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,    -1,   150,   151,    -1,   153,   154,    -1,    -1,   157,
     158,   159,    -1,   161,    -1,   163,    -1,   165,   166,   167,
      -1,   169,   170,   171,    -1,   173,    -1,   175,   176,   177,
     178,   179,    -1,   181,   182,   183,   184,   185,   186,    -1,
      -1,   189,   190,   191,    -1,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,   234,   235,    -1,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    -1,    47,    48,
      49,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    -1,    87,    88,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,   103,    -1,   105,   106,   107,   108,
      -1,   110,    -1,    -1,    -1,   114,   115,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
      -1,   150,   151,    -1,   153,   154,    -1,    -1,   157,   158,
     159,    -1,    -1,    -1,   163,   164,   165,   166,   167,    -1,
     169,   170,   171,    -1,   173,    -1,   175,   176,   177,   178,
     179,    -1,   181,   182,   183,   184,   185,   186,    -1,    -1,
     189,   190,   191,    -1,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,   234,   235,    -1,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    87,    88,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,    -1,   105,   106,   107,   108,    -1,
     110,    -1,    -1,    -1,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,    -1,
     150,   151,    -1,   153,   154,    -1,    -1,   157,   158,   159,
      -1,   161,    -1,   163,    -1,   165,   166,   167,    -1,   169,
     170,   171,    -1,   173,    -1,   175,   176,   177,   178,   179,
      -1,   181,   182,   183,   184,   185,   186,    -1,    -1,   189,
     190,   191,    -1,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,   235,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    -1,    47,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    -1,    -1,    87,    88,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,   103,    -1,   105,   106,   107,   108,    -1,   110,
      -1,    -1,    -1,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,    -1,   150,
     151,    -1,   153,   154,    -1,    -1,   157,   158,   159,    -1,
     161,    -1,   163,    -1,   165,   166,   167,    -1,   169,   170,
     171,    -1,   173,    -1,   175,   176,   177,   178,   179,    -1,
     181,   182,   183,   184,   185,   186,    -1,    -1,   189,   190,
     191,    -1,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,   234,   235,    -1,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    87,    88,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,    -1,   105,   106,   107,   108,    -1,   110,    -1,
      -1,    -1,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,    -1,   150,   151,
      -1,   153,   154,    -1,    -1,   157,   158,   159,    -1,   161,
      -1,   163,    -1,   165,   166,   167,    -1,   169,   170,   171,
      -1,   173,    -1,   175,   176,   177,   178,   179,    -1,   181,
     182,   183,   184,   185,   186,    -1,    -1,   189,   190,   191,
      -1,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,   234,   235,    -1,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    -1,    47,    48,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    -1,    87,    88,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,    -1,   105,   106,   107,   108,    -1,   110,    -1,    -1,
      -1,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,    -1,   150,   151,    -1,
     153,   154,    -1,    -1,   157,   158,   159,    -1,   161,    -1,
     163,    -1,   165,   166,   167,    -1,   169,   170,   171,    -1,
     173,    -1,   175,   176,   177,   178,   179,    -1,   181,   182,
     183,   184,   185,   186,    -1,    -1,   189,   190,   191,    -1,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,   234,   235,    -1,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    -1,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    87,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
      -1,   105,   106,   107,   108,    -1,   110,    -1,    -1,    -1,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,    -1,   150,   151,    -1,   153,
     154,    -1,    -1,   157,   158,   159,    -1,   161,    -1,   163,
      -1,   165,   166,   167,    -1,   169,   170,   171,    -1,   173,
      -1,   175,   176,   177,   178,   179,    -1,   181,   182,   183,
     184,   185,   186,    -1,    -1,   189,   190,   191,    -1,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
     234,   235,    -1,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    -1,    87,    88,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,    -1,
     105,   106,   107,   108,    -1,   110,    -1,    -1,    -1,   114,
     115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,    -1,   150,   151,    -1,   153,   154,
      -1,    -1,   157,   158,   159,    -1,   161,    -1,   163,    -1,
     165,   166,   167,    -1,   169,   170,   171,    -1,   173,    -1,
     175,   176,   177,   178,   179,    -1,   181,   182,   183,   184,
     185,   186,    -1,    -1,   189,   190,   191,    -1,    -1,   194,
      -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,   234,
     235,    -1,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    87,    88,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,   103,    -1,   105,
     106,   107,   108,    -1,   110,    -1,    -1,    -1,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,    -1,   150,   151,    -1,   153,   154,    -1,
      -1,   157,   158,   159,    -1,    -1,    -1,   163,    -1,   165,
     166,   167,    -1,   169,   170,   171,    -1,   173,    -1,   175,
     176,   177,   178,   179,    -1,   181,   182,   183,   184,   185,
     186,    -1,    -1,   189,   190,   191,    -1,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,   234,   235,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    -1,
      47,    48,    49,    -1,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    -1,    -1,
      87,    88,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,   103,    -1,   105,   106,
     107,   108,    -1,   110,    -1,    -1,    -1,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,    -1,   150,   151,    -1,   153,   154,    -1,    -1,
     157,   158,   159,    -1,    -1,    -1,   163,    -1,   165,   166,
     167,    -1,   169,   170,   171,    -1,   173,    -1,   175,   176,
     177,   178,   179,    -1,   181,   182,   183,   184,   185,   186,
      -1,    -1,   189,   190,   191,    -1,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,   234,   235,    -1,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    49,    -1,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    87,
      88,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,    -1,   105,   106,   107,
     108,    -1,   110,    -1,    -1,    -1,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,    -1,   150,   151,    -1,   153,   154,    -1,    -1,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,   165,   166,   167,
      -1,   169,   170,   171,    -1,   173,    -1,   175,   176,   177,
     178,   179,    -1,   181,   182,   183,   184,   185,   186,    -1,
      -1,   189,   190,   191,    -1,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,   234,   235,    -1,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    -1,    47,    48,
      49,    -1,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    -1,    87,    88,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,   103,    -1,   105,   106,   107,   108,
      -1,   110,    -1,    -1,    -1,   114,   115,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,   134,   135,    -1,   137,   138,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
      -1,   150,   151,    -1,    -1,    -1,    -1,    -1,   157,   158,
     159,    -1,    -1,    -1,   163,    -1,   165,   166,   167,    -1,
      -1,    -1,   171,    -1,   173,    -1,   175,   176,   177,   178,
     179,    -1,   181,   182,   183,   184,   185,   186,    -1,    -1,
     189,   190,   191,    -1,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,   234,   235,    -1,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      -1,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    74,    -1,    76,    77,    78,    79,
      -1,    -1,    82,    83,    84,    -1,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    93,    94,    -1,    -1,    97,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,    -1,
     110,    -1,    -1,    -1,   114,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,    -1,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,   163,    -1,   165,   166,    -1,    -1,    -1,
      -1,   171,    -1,   173,    -1,   175,   176,   177,   178,   179,
      -1,   181,   182,   183,   184,   185,   186,    -1,    -1,   189,
     190,    -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,   235,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    -1,    47,    48,    49,    -1,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    69,    70,
      71,    -1,    -1,    74,    -1,    76,    77,    78,    79,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    88,    -1,    -1,
      -1,    -1,    93,    94,    -1,    -1,    97,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,    -1,   110,
      -1,    -1,    -1,   114,   115,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,    -1,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,   163,    -1,   165,    -1,    -1,    -1,    -1,    -1,
     171,    -1,   173,    -1,   175,   176,   177,   178,   179,    -1,
     181,   182,   183,   184,   185,   186,    -1,    -1,   189,   190,
      -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,   234,   235,    -1,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    15,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    49,    -1,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,
      88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    97,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,    -1,   110,    -1,    -1,    -1,   114,   115,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,    -1,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,   163,    -1,   165,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   176,   177,
     178,   179,    -1,   181,   182,   183,   184,   185,   186,    -1,
      -1,   189,   190,    -1,    -1,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,   234,   235,    -1,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    -1,
      47,    48,    49,    -1,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    74,    -1,    76,
      77,    78,    79,    -1,    -1,    82,    83,    84,    -1,    -1,
      -1,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,
      97,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,    -1,   110,    -1,    -1,    -1,   114,   115,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
      -1,   128,   129,   130,   131,    -1,    -1,   134,    -1,    -1,
     137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   163,    -1,   165,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   176,
     177,   178,   179,    -1,   181,   182,   183,   184,   185,   186,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,   234,   235,    -1,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    -1,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    74,    -1,
      76,    77,    78,    79,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,
      -1,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,    -1,   110,    -1,    -1,    -1,   114,   115,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,    -1,   128,   129,   130,   131,    -1,    -1,   134,    -1,
      -1,   137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,   163,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,
     176,   177,   178,   179,    -1,   181,   182,   183,   184,   185,
     186,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,   234,   235,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,    -1,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    74,
      -1,    76,    77,    78,    79,    -1,    -1,    82,    83,    84,
      -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,    93,    94,
      -1,    -1,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,    -1,   110,    -1,    -1,    -1,   114,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,    -1,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,   164,
     165,    -1,    -1,    -1,    -1,    -1,   171,    -1,   173,    -1,
     175,   176,   177,   178,   179,    -1,   181,   182,   183,   184,
     185,   186,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,
      -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,   234,
     235,    -1,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    -1,    47,    48,    49,    -1,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      74,    -1,    76,    77,    78,    79,    -1,    -1,    82,    83,
      84,    -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,    93,
      94,    -1,    -1,    97,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,    -1,   110,    -1,    -1,    -1,
     114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,    -1,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,
     164,   165,    -1,    -1,    -1,    -1,    -1,   171,    -1,   173,
      -1,   175,   176,   177,   178,   179,    -1,   181,   182,   183,
     184,   185,   186,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
     234,   235,    -1,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    -1,    47,    48,    49,    -1,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    69,    70,    71,    -1,
      -1,    74,    -1,    76,    77,    78,    79,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,
      93,    94,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,    -1,   110,    -1,    -1,
      -1,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,    -1,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
     163,    -1,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,
     173,    -1,   175,   176,   177,   178,   179,    -1,   181,   182,
     183,   184,   185,   186,    -1,    -1,   189,   190,    -1,    -1,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,   234,   235,    -1,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    -1,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    74,    -1,    76,    77,    78,    79,    -1,    -1,
      82,    83,    84,    -1,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,    -1,   110,    -1,
      -1,    -1,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,    -1,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   163,    -1,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,   173,    -1,   175,   176,   177,   178,   179,    -1,   181,
     182,   183,   184,   185,   186,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,   234,   235,    -1,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    -1,    47,    48,    49,    -1,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    69,    70,
      71,    -1,    -1,    74,    -1,    76,    77,    78,    79,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    88,    -1,    -1,
      -1,    -1,    93,    94,    -1,    -1,    97,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,    -1,   110,
      -1,    -1,    -1,   114,   115,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,    -1,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,   163,    -1,   165,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   173,    -1,   175,   176,   177,   178,   179,    -1,
     181,   182,   183,   184,   185,   186,    -1,    -1,   189,   190,
      -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,   234,   235,    -1,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,     9,    16,    17,    19,    25,    26,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      87,    88,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   103,   105,   106,   107,   108,   110,   114,   115,
     116,   117,   118,   124,   125,   126,   127,   128,   129,   130,
     131,   134,   135,   136,   137,   138,   143,   144,   145,   146,
     147,   148,   150,   151,   153,   154,   157,   158,   159,   163,
     165,   166,   167,   169,   170,   171,   173,   175,   176,   177,
     178,   179,   181,   182,   183,   184,   185,   186,   189,   190,
     191,   193,   194,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   234,
     235,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   298,   299,   300,   302,   304,
     305,   306,   307,   312,   313,   314,   315,   319,   321,   323,
     324,   325,   330,   351,   354,   357,   358,   359,   360,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   407,
     408,   409,   423,   424,   426,   427,   428,   429,   430,   431,
     432,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   451,   452,   453,   454,   455,   456,   457,   460,   465,
     466,   216,    27,   134,   131,   200,   201,   202,   134,    30,
      31,    32,    33,    34,    35,    36,    40,    41,    43,    44,
      51,    54,    55,    66,    67,    79,   114,   131,   134,   146,
     179,   203,   204,   205,   207,   208,   215,   465,   131,   131,
     134,   131,   134,    37,    38,    39,    47,    52,    63,    65,
      68,    71,    93,    94,   138,   199,   223,   134,    17,   131,
     134,   464,    46,    49,    99,   138,    99,   131,    56,    57,
      99,   316,    54,    27,   134,   134,   131,   134,   465,    32,
      34,    35,    41,    79,   391,   465,   465,    99,   303,   313,
     164,   313,   465,   131,    13,    15,   465,   465,   383,   131,
      20,   192,   194,   204,   206,   134,   204,   206,   204,   204,
     209,    99,   131,    99,     0,   275,   276,    36,    43,   278,
     312,   168,   168,    89,    45,    51,    54,    55,    62,   147,
     149,   163,   190,   320,   321,   322,   339,   340,   344,   326,
     327,   465,   145,    74,   111,   119,   120,   122,   129,   133,
     135,   140,   156,   181,   182,   183,   184,   185,   186,   375,
     376,   234,   136,   153,   176,    98,   124,   137,   171,   178,
     188,   115,   128,    69,   177,    83,    84,   136,   153,   374,
     131,   380,   383,   169,   170,   132,   395,   396,   391,   395,
     391,   395,   134,   314,   314,   313,   131,   131,   131,   313,
     313,   164,   171,   465,   131,   313,   313,   164,   313,   164,
     465,    37,    37,   465,   159,   173,   146,   179,    19,   463,
     144,   159,   159,   173,    99,    32,    37,    88,   147,   464,
     200,   201,   202,    82,   216,   224,   237,   239,   249,   252,
     478,   479,   480,   481,   482,   485,   490,   491,   313,   313,
      19,   164,   464,   131,   138,   463,    94,   138,   297,   463,
     352,   353,   465,   464,   331,   333,   465,   314,   251,   251,
      99,   334,    99,   465,    32,    66,   164,   447,   448,   313,
     164,   171,   465,   131,   352,   161,   313,   168,   164,    24,
     411,   412,   413,   313,     6,   152,    14,   164,   313,   192,
      19,   314,   314,   164,   314,   314,   314,   314,   210,   458,
     459,   465,   314,   332,   338,   465,   280,   281,    36,   282,
     314,   147,    99,   148,   148,   314,   314,    89,    76,    78,
     125,   245,   328,   329,   434,   359,   360,   362,   362,   362,
     362,   361,   362,   362,   362,   131,   134,   235,   398,   467,
     469,   470,   471,   472,   473,   474,   475,   365,   365,   364,
     366,   366,   366,   366,   367,   367,   368,   368,   210,    76,
      76,    76,   161,   313,   383,   383,   313,   396,   164,   314,
     406,   164,   161,   313,   313,   313,   164,   161,    89,   164,
      89,   164,   161,   313,   161,   161,   161,   134,   301,   465,
     465,    19,    89,    89,   465,   138,   138,   463,   106,   111,
     222,   225,    94,   224,   253,   254,   256,   257,   222,   225,
      19,   224,   253,   254,   256,   257,   164,   161,   164,   164,
     161,   313,   464,    78,    32,   464,   463,    78,    89,   165,
     125,   434,   111,    89,   121,   329,   434,   161,   465,    60,
     196,   229,   317,   318,   164,   164,   164,   161,    89,   164,
      89,   164,   161,   313,   165,   168,   465,   412,   413,   109,
     174,   161,   161,   110,   168,    76,   197,   198,   212,    76,
     197,   198,   212,    76,   216,   204,    89,   214,   121,   161,
      53,    89,   168,   148,   465,   314,   345,   346,    99,   341,
     342,    99,   130,   189,   435,   437,   438,   439,   465,    99,
     314,    99,   125,   329,   125,   125,   328,   329,   362,   313,
     467,   473,   252,   501,    78,   146,   226,   227,   228,   236,
     244,   250,   251,   468,   476,   477,   478,   492,   495,   496,
     498,   233,   235,   240,   497,   220,   221,   242,   493,   435,
     435,   433,   438,   433,   161,   162,    89,   164,   302,   161,
     161,   161,    82,   355,   356,   131,   449,   450,   465,   449,
     450,   161,    99,   164,   308,   309,   116,   131,   311,   301,
     301,   126,   143,   126,   143,   116,   121,   434,   463,   463,
     107,   108,   463,   254,   255,    78,    94,   134,   484,   255,
     175,   131,   161,   111,   296,   463,   138,   111,    78,   296,
      99,   314,   314,   125,   463,    99,   314,   121,   121,   329,
     125,   434,   229,    58,    59,    61,    99,   328,   335,   336,
     337,   318,   131,   449,   465,   449,   161,   314,    24,   413,
     109,   174,     7,     8,    85,   102,   104,   131,   172,   310,
     408,   410,   421,   422,   425,    19,   211,   213,   314,   314,
     314,   211,   213,   314,   314,   314,   314,   314,   314,    99,
     314,   314,   218,   461,   462,   131,    99,   345,    77,    88,
      97,   106,   347,   348,   349,   350,    89,   465,    89,   327,
     134,   134,   123,   153,   171,   436,   465,   465,   314,   125,
     314,   314,   125,   329,   125,   161,   164,   230,   196,   229,
     241,   246,   500,    78,   231,   232,   494,   230,   470,   500,
     363,   366,   250,   476,   478,   471,   125,   494,   255,    48,
     123,   314,    99,   435,    94,   356,   161,   313,   164,   164,
     123,   164,   164,   465,    76,    89,   164,   313,   116,   311,
     302,   314,   116,   121,   255,    78,   134,   487,    19,    94,
     484,   314,   161,   313,   463,    89,   296,   353,   314,   168,
     333,   314,   314,   121,   314,   125,    99,    99,   314,   465,
     337,    61,   161,   313,   164,   164,   111,   172,   410,     5,
     313,   465,   172,   421,   168,   212,   212,   212,   212,   216,
     459,   163,   134,   462,   314,   338,   463,   107,   108,   349,
     350,   350,   346,    88,   343,   342,   164,   164,   314,   314,
     125,   314,   366,    42,   108,   366,   366,   241,   247,   255,
     499,   499,   363,   472,   248,   465,   163,    99,   163,   161,
     434,   435,   309,    76,   161,   314,   115,   178,   486,   489,
      19,    19,   488,   486,   243,   494,    89,   164,    89,   164,
     105,   161,    78,   463,   314,   314,   465,   465,   336,   314,
     161,   413,   465,   172,   161,   413,   465,   314,   314,   314,
     314,   314,   314,   392,   161,   350,   463,   314,   366,   366,
     176,    76,   314,   465,   314,   435,   487,   487,   489,    19,
     164,    19,   238,   483,   484,   483,   314,   296,    59,    75,
     160,   414,   413,   465,   174,   413,    89,   164,   366,   435,
     163,   494,    89,   164,   164,    99,     3,   112,   417,   418,
     420,   422,    18,   113,   415,   416,   419,   422,   174,   413,
     174,    99,   311,   163,   314,   238,   484,   465,    75,   112,
     420,   160,   113,   419,   174,   465,   314,    89,   164,    99,
     311,   465,    89,   164,    99,   311,   465,   164,   311
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
     525,   526
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   272,   273,   273,   273,   273,   274,   274,   275,   275,
     276,   277,   278,   278,   278,   279,   279,   280,   280,   281,
     281,   281,   281,   282,   282,   282,   282,   283,   283,   283,
     283,   283,   283,   283,   283,   284,   284,   285,   286,   286,
     287,   287,   288,   289,   290,   290,   291,   291,   292,   292,
     292,   292,   293,   294,   295,   295,   295,   295,   296,   296,
     297,   297,   298,   298,   298,   298,   299,   299,   299,   299,
     300,   300,   301,   301,   301,   301,   302,   303,   303,   304,
     305,   306,   306,   307,   307,   307,   307,   307,   308,   308,
     309,   309,   310,   311,   312,   313,   313,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   315,   316,   316,   317,   317,   317,   318,
     318,   319,   319,   320,   321,   321,   321,   322,   322,   322,
     322,   322,   323,   323,   324,   324,   325,   326,   326,   327,
     327,   327,   327,   327,   327,   327,   327,   328,   329,   330,
     331,   331,   332,   332,   333,   333,   333,   333,   334,   334,
     335,   335,   335,   336,   336,   336,   337,   337,   337,   338,
     339,   340,   341,   341,   342,   342,   343,   344,   344,   345,
     345,   346,   346,   347,   347,   347,   347,   347,   347,   347,
     348,   348,   349,   349,   350,   351,   351,   352,   352,   353,
     353,   354,   354,   355,   355,   356,   356,   357,   358,   358,
     359,   359,   360,   360,   360,   360,   360,   361,   360,   360,
     360,   360,   362,   362,   362,   363,   363,   364,   364,   364,
     365,   365,   365,   365,   365,   366,   366,   366,   367,   367,
     367,   368,   368,   369,   369,   370,   370,   371,   371,   372,
     372,   373,   373,   373,   373,   374,   374,   374,   375,   375,
     375,   375,   375,   375,   376,   376,   376,   377,   377,   377,
     377,   378,   378,   379,   379,   380,   380,   381,   381,   381,
     381,   382,   383,   383,   383,   384,   384,   385,   385,   385,
     385,   386,   386,   387,   387,   387,   387,   387,   387,   387,
     388,   388,   389,   389,   390,   390,   390,   390,   390,   391,
     391,   392,   392,   393,   393,   393,   394,   394,   395,   395,
     396,   397,   397,   397,   397,   397,   397,   397,   397,   398,
     398,   399,   399,   399,   400,   401,   401,   402,   403,   404,
     405,   405,   406,   406,   407,   407,   408,   408,   408,   409,
     409,   409,   409,   409,   409,   410,   410,   411,   411,   412,
     413,   413,   414,   414,   415,   415,   416,   416,   416,   416,
     417,   417,   418,   418,   418,   418,   419,   419,   420,   420,
     421,   421,   421,   421,   422,   422,   422,   422,   423,   423,
     424,   424,   425,   426,   426,   426,   426,   426,   426,   427,
     428,   428,   428,   428,   429,   429,   429,   429,   430,   431,
     432,   432,   432,   432,   433,   433,   434,   435,   435,   435,
     436,   436,   436,   437,   437,   437,   438,   439,   439,   439,
     439,   439,   439,   439,   439,   439,   440,   441,   441,   441,
     442,   443,   444,   444,   444,   445,   445,   445,   445,   445,
     446,   447,   447,   447,   447,   447,   447,   447,   448,   449,
     450,   451,   452,   452,   452,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   454,   454,   455,   455,   456,
     457,   458,   458,   459,   460,   461,   461,   462,   462,   462,
     462,   463,   464,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   466,   466,   467,   467,   467,   467,   468,   468,   468,
     468,   469,   469,   470,   470,   471,   471,   472,   472,   473,
     473,   473,   474,   474,   475,   475,   476,   476,   476,   476,
     476,   477,   478,   478,   478,   478,   478,   478,   478,   479,
     479,   479,   479,   480,   480,   480,   480,   481,   481,   482,
     482,   482,   482,   482,   482,   482,   483,   483,   484,   484,
     484,   484,   485,   485,   485,   485,   485,   486,   486,   487,
     487,   488,   488,   489,   489,   490,   491,   491,   492,   492,
     492,   493,   493,   493,   493,   493,   494,   494,   494,   494,
     495,   496,   497,   498,   498,   499,   499,   499,   500,   500,
     501
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     4,     6,     2,     1,
       2,     6,     2,     2,     4,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     3,     3,
       5,     5,     4,     3,     3,     3,     5,     5,     5,     5,
       5,     5,     4,     3,     3,     4,     5,     6,     1,     3,
       3,     3,     3,     6,     5,     8,     6,     5,     7,     6,
       3,     3,     2,     3,     4,     5,     3,     2,     3,     3,
       5,     2,     2,     5,     5,     6,     6,     6,     1,     3,
       2,     3,     3,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     2,     1,     1,     2,     4,
       3,     5,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     2,     1,     4,     3,
       4,     4,     5,     4,     5,     5,     6,     3,     3,     3,
       1,     4,     1,     4,     3,     4,     4,     5,     4,     5,
       1,     2,     3,     1,     2,     1,     6,     3,     3,     1,
       2,     3,     1,     3,     2,     3,     2,     3,     4,     1,
       3,     1,     2,     1,     1,     1,     2,     2,     2,     3,
       1,     1,     2,     2,     2,     5,     5,     1,     4,     3,
       4,     8,    10,     1,     2,     4,     7,     8,     1,     3,
       1,     3,     1,     3,     3,     3,     3,     0,     4,     3,
       3,     3,     1,     3,     4,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     4,     1,     4,     1,     4,     1,     4,     1,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     5,
       5,     3,     4,     1,     2,     3,     2,     1,     2,     2,
       1,     1,     1,     3,     3,     1,     1,     1,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     1,     4,     4,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     4,
       5,     8,     9,     9,    10,     1,     2,     1,     2,     6,
       0,     1,     3,     3,     0,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     4,
       4,     5,     6,     7,     4,     5,     6,     7,     4,     4,
       4,     5,     6,     7,     1,     2,     2,     1,     2,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     4,
       3,     3,     3,     4,     4,     3,     4,     6,     4,     6,
       3,     3,     4,     6,     6,     4,     6,     6,     4,     1,
       2,     1,     3,     3,     3,     5,     7,     7,     5,     5,
       5,     7,     7,     5,     5,     3,     3,     5,     7,     5,
       7,     1,     4,     3,     5,     1,     2,     5,     8,    11,
      14,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     7,     4,     1,     2,     3,     4,     1,     1,     2,
       2,     1,     3,     1,     3,     1,     4,     1,     2,     1,
       2,     3,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     5,     7,     5,     7,     2,     1,     3,     2,     4,
       4,     6,     4,     5,     4,     5,     3,     1,     2,     2,
       3,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     2,     1,     2,     1,     2,     3,     3,     4,
       3,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const xquery_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined",
  "\"'apos attribute content'\"", "\"'char literal'\"",
  "\"'char literal]]>'\"", "\"'char literal and pi end'\"",
  "\"'#charref;'\"", "\"'element content'\"", "\"'pref:*'\"",
  "\"'&entity;'\"", "\"'comment literal'\"", "\"'pi <NCName {>'\"",
  "\"'pi target'\"", "\"'pragma literal'\"", "\"'QName #)'\"",
  "\"'*:QName'\"", "\"'QName_sval'\"", "\"'quote attribute content'\"",
  "\"'STRING'\"", "\"'XML comment'\"", "\"'QName'\"", "\"'URI'\"",
  "\"'NCName'\"", "\"<blank>\"", "\"'exit'\"", "\"'break'\"", "\"'loop'\"",
  "\"'continue'\"", "\"'while'\"", "\"'validate'\"", "\"'typeswitch'\"",
  "\"'element'\"", "\"'document'\"", "\"'text'\"", "\"'comment'\"",
  "\"'declare'\"", "\"'function'\"", "\"'updating'\"", "\"'sequential'\"",
  "\"'if'\"", "\"'processing-instruction'\"", "\"'most'\"", "\"'import'\"",
  "\"'some'\"", "\"'stable'\"", "\"'module'\"", "\"'option'\"",
  "\"'word'\"", "\"'schema'\"", "\"'space'\"", "\"'let'\"",
  "\"'construction'\"", "\"'eval'\"", "\"'for'\"", "\"'outer'\"",
  "\"'sliding'\"", "\"'tumbling'\"", "\"'previous'\"", "\"'next'\"",
  "\"'only'\"", "\"'when'\"", "\"'count'\"", "\"'ordering'\"",
  "\"'cont'\"", "\"'base-uri'\"", "\"'schema-element'\"",
  "\"'document-node'\"", "\"'copy-namespaces'\"", "\"'instance'\"",
  "\"'schema-attribute'\"", "\"'boundary-space'\"", "\"'ancestor::'\"",
  "\"'ancestor-or-self::'\"", "\"'and'\"", "\"'''\"", "\"'as'\"",
  "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'attribute::'\"",
  "\"'@'\"", "\"'case'\"", "\"'castable'\"", "\"'cast'\"", "\"'CDATA[['\"",
  "\"']]'\"", "\"'child::'\"", "\"'collation'\"", "\"','\"", "\"'(:'\"",
  "\"':)'\"", "\"'DECIMAL'\"", "\"'variable'\"", "\"'default'\"",
  "\"'descendant::'\"", "\"'descendant-or-self::'\"", "\"'descending'\"",
  "\"'div'\"", "\"'$'\"", "\"'.'\"", "\"'..'\"", "\"'{{'\"",
  "\"'DOUBLE'\"", "\"'<double {>'\"", "\"'else'\"", "\"'empty'\"",
  "\"'greatest'\"", "\"'least'\"", "\"'/>'\"", "\"'encoding'\"", "\"'='\"",
  "\"''''\"", "\"'\\\"\\\"'\"", "\"'every'\"", "\"'except'\"",
  "\"'external'\"", "\"'following::'\"", "\"'following-sibling::'\"",
  "\"'follows'\"", "\"'>='\"", "\"':='\"", "\"'>'\"", "\"'?'\"",
  "\"'idiv'\"", "\"'in'\"", "\"'inherit'\"", "\"'INTEGER'\"",
  "\"'intersect'\"", "\"'is'\"", "\"'item'\"", "\"'{'\"", "\"'['\"",
  "\"'<='\"", "\"'('\"", "\"'<'\"", "\"'-'\"", "\"'mod'\"",
  "\"'namespace'\"", "\"'nan'\"", "\"'!='\"", "\"'nodecomp'\"",
  "\"'?\\?'\"", "\"'<no inherit>'\"", "\"'<no preserve>'\"", "\"'or'\"",
  "\"'ordered'\"", "\"'order'\"", "\"'by'\"", "\"'group'\"",
  "\"'parent::'\"", "\"'<?'\"", "\"'?>'\"", "\"'+'\"",
  "\"'PRAGMA BEGIN'\"", "\"'PRAGMA END'\"", "\"'<<'\"",
  "\"'preceding::'\"", "\"'preceding-sibling::'\"", "\"'preserve'\"",
  "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'return'\"", "\"')'\"",
  "\"'satisfies'\"", "\"'<schema attribute ('\"", "\"'self::'\"",
  "\"';'\"", "\"'/'\"", "\"'//'\"", "\"'*'\"", "\"</ (start tag end)\"",
  "\"'strip'\"", "\"> (tag end)\"", "\"'then'\"", "\"'to'\"",
  "\"'treat'\"", "\"'union'\"", "\"'unordered'\"", "\"'unrecognized'\"",
  "\"'eq'\"", "\"'ge'\"", "\"'gt'\"", "\"'le'\"", "\"'lt'\"", "\"'ne'\"",
  "\"'VALUECOMP'\"", "\"'|'\"", "\"'empty-sequence'\"", "\"'where'\"",
  "\"'<!--'\"", "\"'-->'\"", "\"'xquery'\"", "\"'version'\"", "\"'#)'\"",
  "\"'start'\"", "\"'after'\"", "\"'before'\"", "\"'revalidation'\"",
  "\"'strict'\"", "\"'lax'\"", "\"'skip'\"", "\"'delete'\"", "\"'node'\"",
  "\"'insert'\"", "\"'nodes'\"", "\"'rename'\"", "\"'replace'\"",
  "\"'value'\"", "\"'of'\"", "\"'first'\"", "\"'into'\"", "\"'last'\"",
  "\"'modify'\"", "\"'copy'\"", "\"'with'\"", "\"'try'\"", "\"'catch'\"",
  "\"'using'\"", "\"'all'\"", "\"'any'\"", "\"'casesensitive'\"",
  "\"'ft-option'\"", "\"'diacritics'\"", "\"'insensitive'\"",
  "\"'different'\"", "\"'distance'\"", "\"'entire'\"", "\"'end'\"",
  "\"'content'\"", "\"'exactly'\"", "\"'from'\"", "\"'&&'\"",
  "\"'ftcontains'\"", "\"'not'\"", "\"'||'\"", "\"'language'\"",
  "\"'levels'\"", "\"'lowercase'\"", "\"'occurs'\"", "\"'paragraph'\"",
  "\"'phrase'\"", "\"'relationship'\"", "\"'same'\"", "\"'score'\"",
  "\"'sentence'\"", "\"'sentences'\"", "\"'times'\"", "\"'uppercase'\"",
  "\"'weight'\"", "\"'window'\"", "\"'without'\"", "\"'stemming'\"",
  "\"'stop'\"", "\"'words'\"", "\"'thesaurus'\"", "\"'wildcards'\"",
  "FTCONTAINS_REDUCE", "RANGE_REDUCE", "ADDITIVE_REDUCE",
  "MULTIPLICATIVE_REDUCE", "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE",
  "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR", "UNARY_PREC",
  "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR", "OCCURS_PLUS", "OCCURS_HOOK",
  "STEP_REDUCE", "$accept", "Module", "VersionDecl", "MainModule",
  "LibraryModule", "ModuleDecl", "Prolog", "SIND_DeclList", "VFO_DeclList",
  "SIND_Decl", "VFO_Decl", "Setter", "Import", "NamespaceDecl",
  "BoundarySpaceDecl", "DefaultNamespaceDecl", "OptionDecl",
  "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "DefaultCollationDecl", "BaseURIDecl",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "VarDecl", "ConstructionDecl", "FunctionSig", "Block", "BlockBody",
  "ExitExpr", "WhileExpr", "FlowCtlStatement", "FunctionDecl", "ParamList",
  "Param", "EnclosedExpr", "BracedExpr", "QueryBody", "Expr", "ExprSingle",
  "FLWORExpr", "WindowType", "FLWORWinCondType", "FLWORWinCond",
  "WindowClause", "CountClause", "ForLetWinClause", "FLWORClause",
  "FLWORClauseList", "ForDollar", "ForClause", "VarInDeclList",
  "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
  "VarGetsDeclList", "EvalVarDeclList", "VarGetsDecl", "WindowVarDecl",
  "WindowVars", "WindowVars3", "WindowVars2", "EvalVarDecl", "WhereClause",
  "GroupByClause", "GroupSpecList", "GroupSpec", "GroupCollationSpec",
  "OrderByClause", "OrderSpecList", "OrderSpec", "OrderModifier",
  "OrderDirSpec", "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
  "QVarInDeclList", "QVarInDecl", "TypeswitchExpr", "CaseClauseList",
  "CaseClause", "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr", "@1",
  "FTContainsExpr", "RangeExpr", "AdditiveExpr", "MultiplicativeExpr",
  "UnionExpr", "IntersectExceptExpr", "InstanceofExpr", "TreatExpr",
  "CastableExpr", "CastExpr", "UnaryExpr", "SignList", "ValueExpr",
  "ValueComp", "NodeComp", "ValidateExpr", "ExtensionExpr", "PragmaList",
  "Pragma", "PathExpr", "LeadingSlash", "RelativePathExpr", "StepExpr",
  "AxisStep", "ForwardStep", "ForwardAxis", "AbbrevForwardStep",
  "ReverseStep", "ReverseAxis", "NodeTest", "NameTest", "Wildcard",
  "FilterExpr", "PredicateList", "Predicate", "PrimaryExpr", "Literal",
  "NumericLiteral", "VarRef", "ParenthesizedExpr", "ContextItemExpr",
  "OrderedExpr", "UnorderedExpr", "FunctionCall", "ArgList", "Constructor",
  "DirectConstructor", "DirElemConstructor", "DirElemContentList",
  "DirAttributeList", "DirAttr", "OptionalBlank", "DirAttributeValue",
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
  "VarNameDecl", "TryExpr", "CatchListExpr", "CatchExpr", "URI_LITERAL",
  "NCNAME", "QNAME", "EvalExpr", "FTSelection",
  "FTMatchOptionProximityList", "FTOr", "FTAnd", "FTMildnot", "FTUnaryNot",
  "FTWordsSelection", "FTWords", "FTWordsValue", "FTProximity",
  "FTOrderedIndicator", "FTMatchOption", "FTCaseOption",
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
       273,     0,    -1,   275,    -1,   274,   275,    -1,   276,    -1,
     274,   276,    -1,   193,   194,    19,   168,    -1,   193,   194,
      19,   110,    19,   168,    -1,   278,   312,    -1,   312,    -1,
     277,   278,    -1,    46,   138,   464,   111,   463,   168,    -1,
     279,   168,    -1,   280,   168,    -1,   279,   168,   280,   168,
      -1,   281,    -1,   279,   168,   281,    -1,   282,    -1,   280,
     168,   282,    -1,   283,    -1,   284,    -1,   285,    -1,   287,
      -1,   299,    -1,   307,    -1,   288,    -1,   289,    -1,   286,
      -1,   293,    -1,   294,    -1,   300,    -1,   290,    -1,   291,
      -1,   292,    -1,   452,    -1,   295,    -1,   298,    -1,    36,
     138,   464,   111,   463,    -1,    36,    71,   159,    -1,    36,
      71,   173,    -1,    36,    94,    32,   138,   463,    -1,    36,
      94,    37,   138,   463,    -1,    36,    47,   465,    19,    -1,
      36,   223,   478,    -1,    36,    63,   146,    -1,    36,    63,
     179,    -1,    36,    94,   147,   106,   107,    -1,    36,    94,
     147,   106,   108,    -1,    36,    68,   159,    89,   126,    -1,
      36,    68,   159,    89,   143,    -1,    36,    68,   144,    89,
     126,    -1,    36,    68,   144,    89,   143,    -1,    36,    94,
      88,   463,    -1,    36,    65,   463,    -1,    43,    49,   463,
      -1,    43,    49,   297,   463,    -1,    43,    49,   463,    78,
     296,    -1,    43,    49,   297,   463,    78,   296,    -1,   463,
      -1,   296,    89,   463,    -1,   138,   464,   111,    -1,    94,
      32,   138,    -1,    43,    46,   463,    -1,    43,    46,   138,
     464,   111,   463,    -1,    43,    46,   463,    78,   296,    -1,
      43,    46,   138,   464,   111,   463,    78,   296,    -1,    36,
      93,    99,   465,   121,   314,    -1,    36,    93,    99,   465,
     116,    -1,    36,    93,    99,   465,   434,   121,   314,    -1,
      36,    93,    99,   465,   434,   116,    -1,    36,    52,   159,
      -1,    36,    52,   173,    -1,   134,   164,    -1,   134,   308,
     164,    -1,   134,   164,    76,   435,    -1,   134,   308,   164,
      76,   435,    -1,   131,   303,   161,    -1,   313,   168,    -1,
     303,   313,   168,    -1,    25,   216,   314,    -1,    29,   134,
     314,   164,   302,    -1,    26,    27,    -1,    64,    27,    -1,
      36,    37,   465,   301,   116,    -1,    36,    37,   465,   301,
     311,    -1,    36,    38,    37,   465,   301,   116,    -1,    36,
      38,    37,   465,   301,   311,    -1,    36,    39,    37,   465,
     301,   302,    -1,   309,    -1,   308,    89,   309,    -1,    99,
     465,    -1,    99,   465,   434,    -1,   131,   313,   161,    -1,
     131,   313,   161,    -1,   313,    -1,   314,    -1,   313,    89,
     314,    -1,   315,    -1,   351,    -1,   354,    -1,   357,    -1,
     358,    -1,   453,    -1,   454,    -1,   456,    -1,   455,    -1,
     457,    -1,   460,    -1,   466,    -1,   304,    -1,   305,    -1,
     306,    -1,   302,    -1,   323,   163,   314,    -1,    56,   251,
      -1,    57,   251,    -1,   196,    -1,   229,    -1,    60,   229,
      -1,   317,   335,    61,   314,    -1,   317,    61,   314,    -1,
      54,   316,   334,   318,   318,    -1,    54,   316,   334,   318,
      -1,    62,    99,   465,    -1,   325,    -1,   330,    -1,   319,
      -1,   321,    -1,   339,    -1,   344,    -1,   340,    -1,   320,
      -1,   321,    -1,   323,   322,    -1,    54,    99,    -1,    55,
      54,    99,    -1,   324,   326,    -1,   327,    -1,   326,    89,
      99,   327,    -1,   465,   125,   314,    -1,   465,   434,   125,
     314,    -1,   465,   328,   125,   314,    -1,   465,   434,   328,
     125,   314,    -1,   465,   329,   125,   314,    -1,   465,   434,
     329,   125,   314,    -1,   465,   328,   329,   125,   314,    -1,
     465,   434,   328,   329,   125,   314,    -1,    78,    99,   465,
      -1,   245,    99,   465,    -1,    51,    99,   331,    -1,   333,
      -1,   331,    89,    99,   333,    -1,   338,    -1,   332,    89,
      99,   338,    -1,   465,   121,   314,    -1,   465,   434,   121,
     314,    -1,   465,   329,   121,   314,    -1,   465,   434,   329,
     121,   314,    -1,    99,   465,   125,   314,    -1,    99,   465,
     434,   125,   314,    -1,   336,    -1,    99,   465,    -1,    99,
     465,   336,    -1,   328,    -1,   328,   337,    -1,   337,    -1,
      58,    99,   465,    59,    99,   465,    -1,    59,    99,   465,
      -1,    58,    99,   465,    -1,   465,    -1,   190,   314,    -1,
     149,   148,   341,    -1,   342,    -1,   341,    89,   342,    -1,
      99,   465,    -1,    99,   465,   343,    -1,    88,   463,    -1,
     147,   148,   345,    -1,    45,   147,   148,   345,    -1,   346,
      -1,   345,    89,   346,    -1,   314,    -1,   314,   347,    -1,
     348,    -1,   349,    -1,   350,    -1,   348,   349,    -1,   348,
     350,    -1,   349,   350,    -1,   348,   349,   350,    -1,    77,
      -1,    97,    -1,   106,   107,    -1,   106,   108,    -1,    88,
     463,    -1,    44,    99,   352,   165,   314,    -1,   114,    99,
     352,   165,   314,    -1,   353,    -1,   352,    89,    99,   353,
      -1,   465,   125,   314,    -1,   465,   434,   125,   314,    -1,
      31,   134,   313,   164,   355,    94,   163,   314,    -1,    31,
     134,   313,   164,   355,    94,    99,   465,   163,   314,    -1,
     356,    -1,   355,   356,    -1,    82,   435,   163,   314,    -1,
      82,    99,   465,    76,   435,   163,   314,    -1,    40,   134,
     313,   164,   175,   314,   105,   314,    -1,   359,    -1,   358,
     145,   359,    -1,   360,    -1,   359,    74,   360,    -1,   362,
      -1,   362,   375,   362,    -1,   362,   376,   362,    -1,   362,
     111,   362,    -1,   362,   140,   362,    -1,    -1,   362,   135,
     361,   362,    -1,   362,   133,   362,    -1,   362,   122,   362,
      -1,   362,   120,   362,    -1,   363,    -1,   363,   234,   467,
      -1,   363,   234,   467,   501,    -1,   364,    -1,   364,   176,
     364,    -1,   365,    -1,   364,   153,   365,    -1,   364,   136,
     365,    -1,   366,    -1,   365,   171,   366,    -1,   365,    98,
     366,    -1,   365,   124,   366,    -1,   365,   137,   366,    -1,
     367,    -1,   366,   178,   367,    -1,   366,   188,   367,    -1,
     368,    -1,   367,   128,   368,    -1,   367,   115,   368,    -1,
     369,    -1,   369,    69,   210,   435,    -1,   370,    -1,   370,
     177,    76,   435,    -1,   371,    -1,   371,    83,    76,   433,
      -1,   372,    -1,   372,    84,    76,   433,    -1,   374,    -1,
     373,   374,    -1,   153,    -1,   136,    -1,   373,   153,    -1,
     373,   136,    -1,   377,    -1,   381,    -1,   378,    -1,   181,
      -1,   186,    -1,   185,    -1,   184,    -1,   183,    -1,   182,
      -1,   129,    -1,   156,    -1,   119,    -1,    30,   131,   313,
     161,    -1,    30,   200,   131,   313,   161,    -1,    30,   201,
     131,   313,   161,    -1,    30,   202,   131,   313,   161,    -1,
     379,   131,   161,    -1,   379,   131,   313,   161,    -1,   380,
      -1,   379,   380,    -1,   154,   465,    14,    -1,   154,    15,
      -1,   382,    -1,   382,   383,    -1,   170,   383,    -1,   383,
      -1,   169,    -1,   384,    -1,   384,   169,   383,    -1,   384,
     170,   383,    -1,   385,    -1,   394,    -1,   386,    -1,   386,
     395,    -1,   389,    -1,   389,   395,    -1,   387,   391,    -1,
     388,    -1,    87,    -1,    95,    -1,    80,    -1,   167,    -1,
      96,    -1,   118,    -1,   117,    -1,   391,    -1,    81,   391,
      -1,   390,   391,    -1,   101,    -1,   150,    -1,    72,    -1,
     158,    -1,   157,    -1,    73,    -1,   439,    -1,   392,    -1,
     465,    -1,   393,    -1,   171,    -1,     9,    -1,    16,    -1,
     397,    -1,   397,   395,    -1,   396,    -1,   395,   396,    -1,
     132,   313,   162,    -1,   398,    -1,   400,    -1,   401,    -1,
     402,    -1,   405,    -1,   407,    -1,   403,    -1,   404,    -1,
     399,    -1,   451,    -1,    92,    -1,   127,    -1,   103,    -1,
      99,   465,    -1,   134,   164,    -1,   134,   313,   164,    -1,
     100,    -1,   146,   131,   313,   161,    -1,   179,   131,   313,
     161,    -1,   465,   134,   164,    -1,   465,   134,   406,   164,
      -1,   314,    -1,   406,    89,   314,    -1,   408,    -1,   426,
      -1,   409,    -1,   423,    -1,   424,    -1,   135,   465,   413,
     109,    -1,   135,   465,   411,   413,   109,    -1,   135,   465,
     413,   174,   172,   465,   413,   174,    -1,   135,   465,   413,
     174,   410,   172,   465,   413,   174,    -1,   135,   465,   411,
     413,   174,   172,   465,   413,   174,    -1,   135,   465,   411,
     413,   174,   410,   172,   465,   413,   174,    -1,   421,    -1,
     410,   421,    -1,   412,    -1,   411,   412,    -1,    24,   465,
     413,   111,   413,   414,    -1,    -1,    24,    -1,   160,   415,
     160,    -1,    75,   417,    75,    -1,    -1,   416,    -1,   113,
      -1,   419,    -1,   416,   113,    -1,   416,   419,    -1,    -1,
     418,    -1,   112,    -1,   420,    -1,   418,   112,    -1,   418,
     420,    -1,    18,    -1,   422,    -1,     3,    -1,   422,    -1,
     408,    -1,     8,    -1,   425,    -1,   422,    -1,     7,    -1,
     102,    -1,   104,    -1,   310,    -1,   191,    20,   192,    -1,
     191,   192,    -1,   151,    13,   152,    -1,   151,    13,     6,
      -1,    85,     5,    -1,   427,    -1,   428,    -1,   429,    -1,
     430,    -1,   431,    -1,   432,    -1,    33,   131,   313,   161,
      -1,    32,   465,   131,   161,    -1,    32,   465,   131,   313,
     161,    -1,    32,   131,   313,   161,   131,   161,    -1,    32,
     131,   313,   161,   131,   313,   161,    -1,    79,   465,   131,
     161,    -1,    79,   465,   131,   313,   161,    -1,    79,   131,
     313,   161,   131,   161,    -1,    79,   131,   313,   161,   131,
     313,   161,    -1,    34,   131,   313,   161,    -1,    35,   131,
     313,   161,    -1,    41,   464,   131,   161,    -1,    41,   464,
     131,   313,   161,    -1,    41,   131,   313,   161,   131,   161,
      -1,    41,   131,   313,   161,   131,   313,   161,    -1,   438,
      -1,   438,   123,    -1,    76,   435,    -1,   437,    -1,   437,
     436,    -1,   189,   134,   164,    -1,   123,    -1,   171,    -1,
     153,    -1,   438,    -1,   439,    -1,   130,   134,   164,    -1,
     465,    -1,   441,    -1,   447,    -1,   445,    -1,   448,    -1,
     446,    -1,   444,    -1,   443,    -1,   442,    -1,   440,    -1,
     204,   134,   164,    -1,    67,   134,   164,    -1,    67,   134,
     447,   164,    -1,    67,   134,   448,   164,    -1,    34,   134,
     164,    -1,    35,   134,   164,    -1,    41,   134,   164,    -1,
      41,   134,   464,   164,    -1,    41,   134,    19,   164,    -1,
      79,   134,   164,    -1,    79,   134,   465,   164,    -1,    79,
     134,   465,    89,   449,   164,    -1,    79,   134,   171,   164,
      -1,    79,   134,   171,    89,   449,   164,    -1,   166,   465,
     164,    -1,    32,   134,   164,    -1,    32,   134,   465,   164,
      -1,    32,   134,   465,    89,   449,   164,    -1,    32,   134,
     465,    89,   450,   164,    -1,    32,   134,   171,   164,    -1,
      32,   134,   171,    89,   449,   164,    -1,    32,   134,   171,
      89,   450,   164,    -1,    66,   134,   465,   164,    -1,   465,
      -1,   465,   123,    -1,    19,    -1,    36,   199,   200,    -1,
      36,   199,   201,    -1,    36,   199,   202,    -1,   205,   204,
     314,   212,   314,    -1,   205,   204,   314,    76,   211,   212,
     314,    -1,   205,   204,   314,    76,   213,   212,   314,    -1,
     205,   204,   314,   197,   314,    -1,   205,   204,   314,   198,
     314,    -1,   205,   206,   314,   212,   314,    -1,   205,   206,
     314,    76,   211,   212,   314,    -1,   205,   206,   314,    76,
     213,   212,   314,    -1,   205,   206,   314,   197,   314,    -1,
     205,   206,   314,   198,   314,    -1,   203,   204,   314,    -1,
     203,   206,   314,    -1,   208,   204,   314,   216,   314,    -1,
     208,   209,   210,   204,   314,   216,   314,    -1,   207,   204,
     314,    76,   314,    -1,   215,    99,   458,   214,   314,   163,
     314,    -1,   459,    -1,   458,    89,    99,   459,    -1,   465,
     121,   314,    -1,   217,   131,   314,   161,   461,    -1,   462,
      -1,   461,   462,    -1,   218,   134,   392,   164,   311,    -1,
     218,   134,   392,    89,    99,   465,   164,   311,    -1,   218,
     134,   392,    89,    99,   465,    89,    99,   465,   164,   311,
      -1,   218,   134,   392,    89,    99,   465,    89,    99,   465,
      89,    99,   465,   164,   311,    -1,    19,    -1,    17,    -1,
      17,    -1,   106,    -1,    79,    -1,    35,    -1,    67,    -1,
      32,    -1,   130,    -1,    40,    -1,   204,    -1,    41,    -1,
      70,    -1,    66,    -1,    34,    -1,    31,    -1,   189,    -1,
      71,    -1,   223,    -1,    65,    -1,   201,    -1,   200,    -1,
     124,    -1,    33,    -1,   235,    -1,   222,    -1,   225,    -1,
     224,    -1,   252,    -1,   253,    -1,   256,    -1,   254,    -1,
     257,    -1,   228,    -1,   230,    -1,    48,    -1,   196,    -1,
     229,    -1,    42,    -1,   202,    -1,   215,    -1,   209,    -1,
     181,    -1,   186,    -1,   185,    -1,   184,    -1,   183,    -1,
     182,    -1,    78,    -1,    93,    -1,   163,    -1,    54,    -1,
      55,    -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,   125,    -1,    51,    -1,
     190,    -1,   148,    -1,   147,    -1,    45,    -1,    77,    -1,
      97,    -1,   107,    -1,   108,    -1,    88,    -1,    44,    -1,
     114,    -1,   165,    -1,    82,    -1,    76,    -1,   175,    -1,
     105,    -1,   145,    -1,    74,    -1,    69,    -1,   210,    -1,
      83,    -1,   176,    -1,    98,    -1,   137,    -1,   178,    -1,
     128,    -1,   115,    -1,    30,    -1,    84,    -1,   177,    -1,
     129,    -1,   159,    -1,   173,    -1,   138,    -1,   116,    -1,
     110,    -1,   144,    -1,   126,    -1,   143,    -1,    36,    -1,
      52,    -1,    63,    -1,    94,    -1,    68,    -1,    47,    -1,
     194,    -1,    43,    -1,    49,    -1,    37,    -1,   245,    -1,
     234,    -1,   250,    -1,   251,    -1,   227,    -1,   240,    -1,
     248,    -1,   244,    -1,   226,    -1,   239,    -1,   249,    -1,
     243,    -1,   238,    -1,   237,    -1,   221,    -1,   220,    -1,
     242,    -1,   231,    -1,   232,    -1,   255,    -1,   247,    -1,
     246,    -1,   241,    -1,   208,    -1,   214,    -1,   211,    -1,
     205,    -1,   198,    -1,   197,    -1,   199,    -1,   216,    -1,
     206,    -1,   207,    -1,   213,    -1,   203,    -1,   212,    -1,
      38,    -1,   146,    -1,   179,    -1,   219,    99,   332,    53,
     131,   314,   161,    -1,    53,   131,   314,   161,    -1,   469,
      -1,   469,   468,    -1,   469,   250,   363,    -1,   469,   468,
     250,   363,    -1,   478,    -1,   476,    -1,   468,   478,    -1,
     468,   476,    -1,   470,    -1,   469,   236,   470,    -1,   471,
      -1,   470,   233,   471,    -1,   472,    -1,   471,   235,   125,
     472,    -1,   473,    -1,   235,   473,    -1,   474,    -1,   474,
     497,    -1,   134,   467,   164,    -1,   475,    -1,   475,   493,
      -1,   398,    -1,   131,   313,   161,    -1,   477,    -1,   496,
      -1,   495,    -1,   498,    -1,   492,    -1,   146,    -1,   479,
      -1,   480,    -1,   481,    -1,   482,    -1,   485,    -1,   490,
      -1,   491,    -1,   239,    -1,   249,    -1,    82,   222,    -1,
      82,   225,    -1,   216,   224,    -1,   252,   224,    -1,   224,
     222,    -1,   224,   225,    -1,   216,   253,    -1,   252,   253,
      -1,   216,   256,   484,    -1,   216,   256,    94,    -1,   216,
     256,   134,   484,   164,    -1,   216,   256,   134,   484,    89,
     483,   164,    -1,   216,   256,   134,    94,   164,    -1,   216,
     256,   134,    94,    89,   483,   164,    -1,   252,   256,    -1,
     484,    -1,   483,    89,   484,    -1,    78,    19,    -1,    78,
      19,   243,    19,    -1,    78,    19,   494,   238,    -1,    78,
      19,   243,    19,   494,   238,    -1,   216,   254,   255,   487,
      -1,   216,   254,   255,   487,   486,    -1,   216,    94,   254,
     255,    -1,   216,    94,   254,   255,   486,    -1,   252,   254,
     255,    -1,   489,    -1,   486,   489,    -1,    78,    19,    -1,
     134,   488,   164,    -1,    19,    -1,   488,    19,    -1,   178,
     487,    -1,   115,   487,    -1,   237,    19,    -1,   216,   257,
      -1,   252,   257,    -1,    78,   196,    -1,    78,   229,    -1,
     228,   230,    -1,   221,    -1,   221,    48,    -1,   220,    -1,
     220,   255,    -1,   242,    -1,   231,   366,    -1,    78,   108,
     366,    -1,    78,    42,   366,    -1,   232,   366,   176,   366,
      -1,   227,   494,   499,    -1,   251,   366,   499,    -1,   240,
     494,   248,    -1,   244,   500,    -1,   226,   500,    -1,   255,
      -1,   247,    -1,   241,    -1,   246,    -1,   241,    -1,   252,
     230,   366,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    18,    25,    28,
      30,    33,    40,    43,    46,    51,    53,    57,    59,    63,
      65,    67,    69,    71,    73,    75,    77,    79,    81,    83,
      85,    87,    89,    91,    93,    95,    97,    99,   105,   109,
     113,   119,   125,   130,   134,   138,   142,   148,   154,   160,
     166,   172,   178,   183,   187,   191,   196,   202,   209,   211,
     215,   219,   223,   227,   234,   240,   249,   256,   262,   270,
     277,   281,   285,   288,   292,   297,   303,   307,   310,   314,
     318,   324,   327,   330,   336,   342,   349,   356,   363,   365,
     369,   372,   376,   380,   384,   386,   388,   392,   394,   396,
     398,   400,   402,   404,   406,   408,   410,   412,   414,   416,
     418,   420,   422,   424,   428,   431,   434,   436,   438,   441,
     446,   450,   456,   461,   465,   467,   469,   471,   473,   475,
     477,   479,   481,   483,   486,   489,   493,   496,   498,   503,
     507,   512,   517,   523,   528,   534,   540,   547,   551,   555,
     559,   561,   566,   568,   573,   577,   582,   587,   593,   598,
     604,   606,   609,   613,   615,   618,   620,   627,   631,   635,
     637,   640,   644,   646,   650,   653,   657,   660,   664,   669,
     671,   675,   677,   680,   682,   684,   686,   689,   692,   695,
     699,   701,   703,   706,   709,   712,   718,   724,   726,   731,
     735,   740,   749,   760,   762,   765,   770,   778,   787,   789,
     793,   795,   799,   801,   805,   809,   813,   817,   818,   823,
     827,   831,   835,   837,   841,   846,   848,   852,   854,   858,
     862,   864,   868,   872,   876,   880,   882,   886,   890,   892,
     896,   900,   902,   907,   909,   914,   916,   921,   923,   928,
     930,   933,   935,   937,   940,   943,   945,   947,   949,   951,
     953,   955,   957,   959,   961,   963,   965,   967,   972,   978,
     984,   990,   994,   999,  1001,  1004,  1008,  1011,  1013,  1016,
    1019,  1021,  1023,  1025,  1029,  1033,  1035,  1037,  1039,  1042,
    1044,  1047,  1050,  1052,  1054,  1056,  1058,  1060,  1062,  1064,
    1066,  1068,  1071,  1074,  1076,  1078,  1080,  1082,  1084,  1086,
    1088,  1090,  1092,  1094,  1096,  1098,  1100,  1102,  1105,  1107,
    1110,  1114,  1116,  1118,  1120,  1122,  1124,  1126,  1128,  1130,
    1132,  1134,  1136,  1138,  1140,  1143,  1146,  1150,  1152,  1157,
    1162,  1166,  1171,  1173,  1177,  1179,  1181,  1183,  1185,  1187,
    1192,  1198,  1207,  1217,  1227,  1238,  1240,  1243,  1245,  1248,
    1255,  1256,  1258,  1262,  1266,  1267,  1269,  1271,  1273,  1276,
    1279,  1280,  1282,  1284,  1286,  1289,  1292,  1294,  1296,  1298,
    1300,  1302,  1304,  1306,  1308,  1310,  1312,  1314,  1316,  1320,
    1323,  1327,  1331,  1334,  1336,  1338,  1340,  1342,  1344,  1346,
    1351,  1356,  1362,  1369,  1377,  1382,  1388,  1395,  1403,  1408,
    1413,  1418,  1424,  1431,  1439,  1441,  1444,  1447,  1449,  1452,
    1456,  1458,  1460,  1462,  1464,  1466,  1470,  1472,  1474,  1476,
    1478,  1480,  1482,  1484,  1486,  1488,  1490,  1494,  1498,  1503,
    1508,  1512,  1516,  1520,  1525,  1530,  1534,  1539,  1546,  1551,
    1558,  1562,  1566,  1571,  1578,  1585,  1590,  1597,  1604,  1609,
    1611,  1614,  1616,  1620,  1624,  1628,  1634,  1642,  1650,  1656,
    1662,  1668,  1676,  1684,  1690,  1696,  1700,  1704,  1710,  1718,
    1724,  1732,  1734,  1739,  1743,  1749,  1751,  1754,  1760,  1769,
    1781,  1796,  1798,  1800,  1802,  1804,  1806,  1808,  1810,  1812,
    1814,  1816,  1818,  1820,  1822,  1824,  1826,  1828,  1830,  1832,
    1834,  1836,  1838,  1840,  1842,  1844,  1846,  1848,  1850,  1852,
    1854,  1856,  1858,  1860,  1862,  1864,  1866,  1868,  1870,  1872,
    1874,  1876,  1878,  1880,  1882,  1884,  1886,  1888,  1890,  1892,
    1894,  1896,  1898,  1900,  1902,  1904,  1906,  1908,  1910,  1912,
    1914,  1916,  1918,  1920,  1922,  1924,  1926,  1928,  1930,  1932,
    1934,  1936,  1938,  1940,  1942,  1944,  1946,  1948,  1950,  1952,
    1954,  1956,  1958,  1960,  1962,  1964,  1966,  1968,  1970,  1972,
    1974,  1976,  1978,  1980,  1982,  1984,  1986,  1988,  1990,  1992,
    1994,  1996,  1998,  2000,  2002,  2004,  2006,  2008,  2010,  2012,
    2014,  2016,  2018,  2020,  2022,  2024,  2026,  2028,  2030,  2032,
    2034,  2036,  2038,  2040,  2042,  2044,  2046,  2048,  2050,  2052,
    2054,  2056,  2058,  2060,  2062,  2064,  2066,  2068,  2070,  2072,
    2074,  2076,  2078,  2080,  2082,  2084,  2086,  2088,  2090,  2092,
    2094,  2096,  2104,  2109,  2111,  2114,  2118,  2123,  2125,  2127,
    2130,  2133,  2135,  2139,  2141,  2145,  2147,  2152,  2154,  2157,
    2159,  2162,  2166,  2168,  2171,  2173,  2177,  2179,  2181,  2183,
    2185,  2187,  2189,  2191,  2193,  2195,  2197,  2199,  2201,  2203,
    2205,  2207,  2210,  2213,  2216,  2219,  2222,  2225,  2228,  2231,
    2235,  2239,  2245,  2253,  2259,  2267,  2270,  2272,  2276,  2279,
    2284,  2289,  2296,  2301,  2307,  2312,  2318,  2322,  2324,  2327,
    2330,  2334,  2336,  2339,  2342,  2345,  2348,  2351,  2354,  2357,
    2360,  2363,  2365,  2368,  2370,  2373,  2375,  2378,  2382,  2386,
    2391,  2395,  2399,  2403,  2406,  2409,  2411,  2413,  2415,  2417,
    2419
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   805,   805,   810,   816,   821,   833,   838,   848,   855,
     867,   879,   891,   897,   903,   915,   921,   935,   941,   955,
     956,   957,   958,   964,   965,   966,   969,   976,   977,   978,
     979,   980,   981,   982,   985,   992,   993,  1005,  1017,  1022,
    1033,  1039,  1051,  1064,  1075,  1080,  1092,  1097,  1108,  1114,
    1120,  1126,  1145,  1156,  1167,  1174,  1181,  1188,  1201,  1207,
    1222,  1226,  1236,  1242,  1249,  1255,  1269,  1276,  1283,  1290,
    1303,  1308,  1320,  1324,  1328,  1332,  1339,  1346,  1352,  1361,
    1368,  1375,  1379,  1386,  1394,  1403,  1412,  1421,  1436,  1444,
    1458,  1464,  1476,  1484,  1495,  1506,  1512,  1524,  1525,  1526,
    1527,  1528,  1531,  1532,  1533,  1534,  1535,  1536,  1537,  1538,
    1539,  1540,  1541,  1548,  1556,  1560,  1568,  1572,  1576,  1583,
    1587,  1594,  1599,  1608,  1617,  1618,  1619,  1623,  1623,  1623,
    1623,  1623,  1626,  1632,  1641,  1645,  1655,  1666,  1672,  1686,
    1693,  1701,  1710,  1720,  1728,  1737,  1746,  1761,  1773,  1784,
    1796,  1802,  1814,  1820,  1834,  1842,  1851,  1859,  1871,  1877,
    1887,  1888,  1892,  1900,  1904,  1909,  1913,  1917,  1921,  1928,
    1943,  1951,  1961,  1967,  1978,  1984,  1993,  2003,  2008,  2020,
    2026,  2040,  2046,  2058,  2065,  2072,  2079,  2086,  2093,  2100,
    2113,  2117,  2127,  2132,  2143,  2154,  2161,  2174,  2181,  2193,
    2199,  2212,  2219,  2233,  2239,  2251,  2257,  2270,  2281,  2285,
    2296,  2300,  2319,  2323,  2331,  2339,  2347,  2355,  2355,  2363,
    2371,  2379,  2393,  2397,  2404,  2417,  2421,  2432,  2436,  2440,
    2450,  2454,  2458,  2462,  2466,  2476,  2480,  2485,  2496,  2500,
    2504,  2514,  2518,  2530,  2534,  2546,  2550,  2562,  2566,  2578,
    2582,  2594,  2598,  2602,  2606,  2618,  2622,  2626,  2636,  2640,
    2644,  2648,  2652,  2656,  2666,  2670,  2674,  2684,  2688,  2694,
    2700,  2712,  2718,  2730,  2736,  2750,  2757,  2798,  2802,  2806,
    2810,  2822,  2832,  2843,  2848,  2858,  2862,  2872,  2878,  2884,
    2890,  2902,  2908,  2919,  2923,  2927,  2931,  2935,  2939,  2943,
    2953,  2957,  2967,  2973,  2985,  2989,  2993,  2997,  3001,  3016,
    3020,  3030,  3034,  3044,  3051,  3058,  3071,  3075,  3087,  3093,
    3107,  3118,  3122,  3126,  3130,  3134,  3138,  3142,  3146,  3156,
    3160,  3170,  3175,  3180,  3191,  3201,  3205,  3216,  3226,  3237,
    3293,  3299,  3311,  3317,  3329,  3333,  3343,  3347,  3351,  3361,
    3369,  3377,  3385,  3393,  3401,  3416,  3422,  3434,  3440,  3453,
    3462,  3464,  3470,  3475,  3487,  3490,  3497,  3503,  3509,  3517,
    3532,  3535,  3542,  3548,  3554,  3562,  3576,  3581,  3592,  3597,
    3608,  3613,  3618,  3624,  3636,  3642,  3647,  3652,  3663,  3668,
    3683,  3688,  3705,  3720,  3724,  3728,  3732,  3736,  3740,  3750,
    3761,  3767,  3773,  3778,  3800,  3806,  3812,  3817,  3828,  3839,
    3850,  3856,  3862,  3867,  3878,  3884,  3896,  3908,  3914,  3920,
    3957,  3962,  3967,  3978,  3982,  3986,  3996,  4007,  4011,  4015,
    4019,  4023,  4027,  4031,  4035,  4039,  4049,  4059,  4063,  4068,
    4079,  4089,  4099,  4103,  4107,  4117,  4123,  4129,  4135,  4141,
    4153,  4164,  4170,  4176,  4182,  4188,  4195,  4202,  4215,  4236,
    4243,  4263,  4303,  4308,  4311,  4319,  4325,  4331,  4337,  4343,
    4350,  4356,  4362,  4368,  4374,  4386,  4391,  4401,  4407,  4419,
    4445,  4456,  4462,  4475,  4489,  4496,  4503,  4514,  4521,  4529,
    4538,  4551,  4554,  4572,  4573,  4574,  4575,  4576,  4577,  4578,
    4579,  4580,  4581,  4582,  4583,  4584,  4585,  4586,  4587,  4588,
    4589,  4590,  4591,  4592,  4593,  4594,  4595,  4596,  4597,  4598,
    4599,  4600,  4601,  4602,  4603,  4604,  4605,  4606,  4607,  4608,
    4609,  4610,  4611,  4612,  4613,  4614,  4615,  4616,  4617,  4618,
    4619,  4620,  4621,  4622,  4623,  4624,  4625,  4626,  4627,  4628,
    4629,  4630,  4631,  4632,  4633,  4634,  4635,  4636,  4637,  4638,
    4639,  4640,  4641,  4642,  4643,  4644,  4645,  4646,  4647,  4648,
    4649,  4650,  4651,  4652,  4653,  4654,  4655,  4656,  4657,  4658,
    4659,  4660,  4661,  4662,  4663,  4664,  4665,  4666,  4667,  4668,
    4669,  4670,  4671,  4672,  4673,  4674,  4675,  4676,  4677,  4678,
    4679,  4680,  4681,  4682,  4683,  4684,  4685,  4686,  4687,  4688,
    4689,  4690,  4691,  4692,  4693,  4694,  4695,  4696,  4697,  4698,
    4699,  4700,  4701,  4702,  4703,  4704,  4705,  4706,  4707,  4708,
    4709,  4710,  4711,  4712,  4713,  4714,  4715,  4716,  4717,  4718,
    4719,  4730,  4736,  4753,  4757,  4761,  4765,  4775,  4778,  4781,
    4784,  4793,  4796,  4805,  4808,  4817,  4820,  4829,  4832,  4841,
    4844,  4847,  4856,  4859,  4868,  4872,  4882,  4885,  4888,  4891,
    4894,  4903,  4912,  4916,  4920,  4924,  4928,  4932,  4936,  4946,
    4949,  4952,  4955,  4964,  4967,  4970,  4973,  4982,  4985,  4994,
    4997,  5000,  5003,  5006,  5009,  5012,  5021,  5024,  5033,  5036,
    5039,  5042,  5051,  5054,  5057,  5060,  5063,  5072,  5075,  5084,
    5087,  5096,  5099,  5108,  5111,  5120,  5129,  5132,  5141,  5144,
    5147,  5156,  5159,  5162,  5165,  5168,  5177,  5181,  5185,  5189,
    5199,  5208,  5218,  5227,  5230,  5239,  5242,  5245,  5254,  5257,
    5266
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
     265,   266,   267,   268,   269,   270,   271
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 7656;
  const int xquery_parser::yynnts_ = 230;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 424;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 272;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 526;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_ofor = "ofor";

}

/*
	The error member function registers the errors to the driver.
*/

void xquery_parser::error(zorba::xquery_parser::location_type const& loc, std::string const& msg)
{
  driver.set_expr (new ParseErrorNode (driver.createQueryLoc (loc), msg));
}

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

