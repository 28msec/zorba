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
#line 793 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

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
#line 686 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 103: /* "\"'DOUBLE'\"" */
#line 685 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 127: /* "\"'INTEGER'\"" */
#line 684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 276: /* "VersionDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 277: /* "MainModule" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 278: /* "LibraryModule" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 279: /* "ModuleDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 280: /* "Prolog" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 281: /* "SIND_DeclList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 282: /* "VFO_DeclList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 283: /* "SIND_Decl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 284: /* "VFO_Decl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 285: /* "Setter" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "Import" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "NamespaceDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "BoundarySpaceDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "DefaultNamespaceDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "OptionDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "OrderingModeDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "EmptyOrderDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "CopyNamespacesDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "DefaultCollationDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "BaseURIDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "SchemaImport" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "URILiteralList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "SchemaPrefix" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "ModuleImport" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "VarDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 346 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "ConstructionDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "FunctionSig" */
#line 698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 356 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "Block" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 361 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "BlockBody" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 366 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "ExitExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 371 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "WhileExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 376 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "FlowCtlStatement" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 381 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "FunctionDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 386 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "ParamList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 391 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "Param" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 396 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "EnclosedExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 401 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "BracedExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 406 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "QueryBody" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 411 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "Expr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 416 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "ExprSingle" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 421 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "FLWORExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 426 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "ReturnExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 431 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "FLWORWinCond" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 436 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "WindowClause" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 441 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "CountClause" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 446 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "ForLetWinClause" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 451 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "FLWORClauseList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 456 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "ForClause" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 461 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "VarInDeclList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 466 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "VarInDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 471 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "PositionalVar" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "LetClause" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 481 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "VarGetsDeclList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 486 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "EvalVarDeclList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 491 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "VarGetsDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 496 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "WindowVarDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 501 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "WindowVars" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 506 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "WindowVars3" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 511 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "WindowVars2" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 516 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "EvalVarDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 521 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "WhereClause" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "GroupByClause" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "GroupSpecList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 536 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "GroupSpec" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "GroupCollationSpec" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "OrderByClause" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 551 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "OrderSpecList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 556 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "OrderSpec" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 561 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "OrderModifier" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 566 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "OrderDirSpec" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 571 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "OrderEmptySpec" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 576 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "OrderCollationSpec" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 581 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "QuantifiedExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 586 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "QVarInDeclList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 591 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "QVarInDecl" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 596 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "TypeswitchExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 601 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CaseClauseList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 606 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "CaseClause" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 611 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IfExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 616 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "OrExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 621 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "AndExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 626 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "ComparisonExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 631 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FTContainsExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 636 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "RangeExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 641 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "AdditiveExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 646 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "MultiplicativeExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 651 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "UnionExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 656 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "IntersectExceptExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 661 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "InstanceofExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 666 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "TreatExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 671 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "CastableExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 676 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "CastExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 681 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "UnaryExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 686 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "SignList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 691 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "ValueExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 696 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ValueComp" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 701 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "NodeComp" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 706 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ValidateExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 711 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ExtensionExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 716 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "PragmaList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 721 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "Pragma" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 726 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "PathExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 731 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "RelativePathExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 736 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "StepExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 741 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "AxisStep" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 746 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ForwardStep" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 751 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "ForwardAxis" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 756 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "AbbrevForwardStep" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 761 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ReverseStep" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 766 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ReverseAxis" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 771 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "NodeTest" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 776 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "NameTest" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 781 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "Wildcard" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 786 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "FilterExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 791 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "PredicateList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 796 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "Predicate" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 801 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "PrimaryExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 806 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "Literal" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 811 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "NumericLiteral" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 816 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "VarRef" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 821 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ParenthesizedExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 826 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ContextItemExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 831 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "OrderedExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 836 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "UnorderedExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 841 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "FunctionCall" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 846 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "ArgList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 851 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "Constructor" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 856 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "DirectConstructor" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 861 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "DirElemConstructor" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 866 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "DirElemContentList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 871 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "DirAttributeList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 876 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "DirAttr" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 881 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "DirAttributeValue" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 886 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "Opt_QuoteAttrContentList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 891 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "QuoteAttrContentList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 896 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "Opt_AposAttrContentList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 901 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "AposAttrContentList" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 906 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "QuoteAttrValueContent" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 911 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "AposAttrValueContent" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 916 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "DirElemContent" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 921 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "CommonContent" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 926 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "DirCommentConstructor" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 931 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "DirPIConstructor" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 936 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "CDataSection" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 941 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "ComputedConstructor" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 946 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "CompDocConstructor" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 951 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "CompElemConstructor" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 956 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "CompAttrConstructor" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 961 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "CompTextConstructor" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 966 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "CompCommentConstructor" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 971 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CompPIConstructor" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 976 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "SingleType" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 981 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "TypeDeclaration" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 986 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "SequenceType" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 991 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OccurrenceIndicator" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 996 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "ItemType" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1001 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "AtomicType" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1006 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "KindTest" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1011 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "AnyKindTest" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1016 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "DocumentTest" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1021 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "TextTest" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1026 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "CommentTest" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1031 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "PITest" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1036 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "AttributeTest" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1041 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "SchemaAttributeTest" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1046 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "ElementTest" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1051 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "SchemaElementTest" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1056 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "TypeName" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1061 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "TypeName_WITH_HOOK" */
#line 694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1066 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "StringLiteral" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1071 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "InsertExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1076 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "DeleteExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1081 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ReplaceExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1086 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "RenameExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1091 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "TransformExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1096 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "VarNameList" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1101 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "VarNameDecl" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1106 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "TryExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1111 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "CatchListExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1116 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "CatchExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1121 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "EvalExpr" */
#line 696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1126 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
#line 1207 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
	  case 3:
#line 811 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 4:
#line 821 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 826 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 832 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 7:
#line 837 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 8:
#line 849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		;}
    break;

  case 9:
#line 854 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    ;}
    break;

  case 10:
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 11:
#line 871 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		;}
    break;

  case 12:
#line 883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 13:
#line 895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval)));
		;}
    break;

  case 14:
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 15:
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 16:
#line 919 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 17:
#line 931 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 18:
#line 937 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 951 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 20:
#line 957 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 39:
#line 1021 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 40:
#line 1033 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 41:
#line 1038 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 42:
#line 1049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 43:
#line 1055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 44:
#line 1067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 45:
#line 1080 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		;}
    break;

  case 46:
#line 1091 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 47:
#line 1096 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 48:
#line 1108 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 49:
#line 1113 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 50:
#line 1124 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 51:
#line 1130 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 52:
#line 1136 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 53:
#line 1142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 54:
#line 1161 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 55:
#line 1172 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 56:
#line 1183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 57:
#line 1190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		;}
    break;

  case 58:
#line 1197 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 59:
#line 1204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 60:
#line 1217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 61:
#line 1223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 62:
#line 1238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 63:
#line 1242 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 64:
#line 1252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 65:
#line 1258 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		;}
    break;

  case 66:
#line 1265 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 67:
#line 1271 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		;}
    break;

  case 68:
#line 1285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								NULL,
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 69:
#line 1292 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (4)].sval)),
								NULL,
								NULL);
		;}
    break;

  case 70:
#line 1299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (4)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 71:
#line 1306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (5)].node)),
								NULL);
		;}
    break;

  case 72:
#line 1319 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 73:
#line 1324 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 74:
#line 1336 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 75:
#line 1340 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 76:
#line 1344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 77:
#line 1348 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 78:
#line 1355 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    ;}
    break;

  case 79:
#line 1362 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = new BlockBody (LOC ((yyloc)));
      blk->add ((yysemantic_stack_[(2) - (1)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 80:
#line 1368 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 81:
#line 1377 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 82:
#line 1384 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr)));
    ;}
    break;

  case 83:
#line 1391 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 84:
#line 1395 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 85:
#line 1402 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval))),
                &* (yysemantic_stack_[(5) - (4)].fnsig)->param, &* (yysemantic_stack_[(5) - (4)].fnsig)->ret, NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
		;}
    break;

  case 86:
#line 1410 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval))),
                &* (yysemantic_stack_[(5) - (4)].fnsig)->param, &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
								(yysemantic_stack_[(5) - (5)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
		;}
    break;

  case 87:
#line 1419 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
								&* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern_update);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 88:
#line 1428 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
                &* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_update);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 89:
#line 1437 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
                &* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 90:
#line 1452 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 91:
#line 1460 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 92:
#line 1474 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 93:
#line 1480 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 94:
#line 1492 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 95:
#line 1500 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 96:
#line 1511 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 97:
#line 1522 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = new Expr(LOC ((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 98:
#line 1528 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 115:
#line 1564 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 116:
#line 1573 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 117:
#line 1580 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    ;}
    break;

  case 118:
#line 1584 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    ;}
    break;

  case 119:
#line 1592 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    ;}
    break;

  case 120:
#line 1596 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    ;}
    break;

  case 121:
#line 1600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    ;}
    break;

  case 122:
#line 1607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 123:
#line 1611 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 124:
#line 1618 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)), dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 125:
#line 1623 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    ;}
    break;

  case 126:
#line 1632 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 135:
#line 1650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 136:
#line 1656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 137:
#line 1665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    ;}
    break;

  case 138:
#line 1669 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    ;}
    break;

  case 139:
#line 1679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		;}
    break;

  case 140:
#line 1690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 141:
#line 1696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 142:
#line 1710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 143:
#line 1717 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 144:
#line 1725 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 145:
#line 1734 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 146:
#line 1744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 147:
#line 1752 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 148:
#line 1761 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 149:
#line 1770 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 150:
#line 1785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 151:
#line 1797 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 152:
#line 1808 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 153:
#line 1820 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 154:
#line 1826 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 155:
#line 1838 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 156:
#line 1844 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 157:
#line 1858 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 158:
#line 1866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 159:
#line 1875 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 160:
#line 1883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 161:
#line 1895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 162:
#line 1901 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 164:
#line 1912 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)), "", "");
    ;}
    break;

  case 165:
#line 1916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
    ;}
    break;

  case 166:
#line 1924 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    ;}
    break;

  case 167:
#line 1928 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    ;}
    break;

  case 169:
#line 1937 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)));
    ;}
    break;

  case 170:
#line 1941 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 171:
#line 1945 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)), "");
    ;}
    break;

  case 172:
#line 1952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 173:
#line 1967 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 174:
#line 1975 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 175:
#line 1985 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 176:
#line 1991 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 177:
#line 2002 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 178:
#line 2008 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 179:
#line 2017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 180:
#line 2027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 181:
#line 2032 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 182:
#line 2044 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 183:
#line 2050 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 184:
#line 2064 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 185:
#line 2070 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 186:
#line 2082 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 187:
#line 2089 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 188:
#line 2096 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 189:
#line 2103 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 190:
#line 2110 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 191:
#line 2117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 192:
#line 2124 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 193:
#line 2137 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 194:
#line 2141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 195:
#line 2151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 196:
#line 2156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 197:
#line 2167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 198:
#line 2178 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 199:
#line 2185 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 200:
#line 2198 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 201:
#line 2205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 202:
#line 2217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 203:
#line 2223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 204:
#line 2236 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 205:
#line 2243 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 206:
#line 2257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 207:
#line 2263 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 208:
#line 2275 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 209:
#line 2281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 210:
#line 2294 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 211:
#line 2305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 212:
#line 2309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 213:
#line 2320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 214:
#line 2324 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 215:
#line 2343 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 216:
#line 2347 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 217:
#line 2355 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 218:
#line 2363 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 219:
#line 2371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 220:
#line 2378 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 221:
#line 2379 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 222:
#line 2387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 223:
#line 2395 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 224:
#line 2403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 225:
#line 2417 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 226:
#line 2421 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 227:
#line 2428 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 228:
#line 2441 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 229:
#line 2445 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 230:
#line 2456 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 231:
#line 2460 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 232:
#line 2464 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 233:
#line 2474 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 234:
#line 2478 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 235:
#line 2482 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 236:
#line 2486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 237:
#line 2490 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 238:
#line 2500 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 239:
#line 2504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 240:
#line 2509 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 241:
#line 2520 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 242:
#line 2524 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 243:
#line 2528 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 244:
#line 2538 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 245:
#line 2542 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 246:
#line 2554 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 247:
#line 2558 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 248:
#line 2570 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 249:
#line 2574 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 250:
#line 2586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 251:
#line 2590 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 252:
#line 2602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 253:
#line 2606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 254:
#line 2618 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 255:
#line 2622 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 256:
#line 2626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 257:
#line 2630 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 258:
#line 2642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 259:
#line 2646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 260:
#line 2650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 261:
#line 2660 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 262:
#line 2664 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 263:
#line 2668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 264:
#line 2672 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 265:
#line 2676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 266:
#line 2680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 267:
#line 2690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 268:
#line 2694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 269:
#line 2698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 270:
#line 2708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 271:
#line 2712 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "strict",
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 272:
#line 2718 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "lax",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 273:
#line 2724 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "skip",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 274:
#line 2736 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 275:
#line 2742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 276:
#line 2754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 277:
#line 2760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 278:
#line 2774 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 279:
#line 2780 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 280:
#line 2822 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 281:
#line 2826 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 282:
#line 2830 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 283:
#line 2834 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 284:
#line 2846 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    ;}
    break;

  case 285:
#line 2856 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (as != NULL ?
             new RelativePathExpr(LOC ((yyloc)),
                                  ParseConstants::st_slash,
                                  new ContextItemExpr(LOC((yyloc)), true),
                                  (yysemantic_stack_[(1) - (1)].expr)) :
             (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 286:
#line 2867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 287:
#line 2872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 288:
#line 2882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 289:
#line 2886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 290:
#line 2896 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 291:
#line 2902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 292:
#line 2908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 293:
#line 2914 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 294:
#line 2926 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 295:
#line 2932 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 296:
#line 2943 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 297:
#line 2947 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 298:
#line 2951 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 299:
#line 2955 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 300:
#line 2959 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 301:
#line 2963 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 302:
#line 2967 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 303:
#line 2977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 304:
#line 2981 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 305:
#line 2991 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 306:
#line 2997 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 307:
#line 3009 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 308:
#line 3013 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 309:
#line 3017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 310:
#line 3021 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 311:
#line 3025 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 312:
#line 3040 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 313:
#line 3044 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 314:
#line 3054 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 315:
#line 3058 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 316:
#line 3068 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 317:
#line 3075 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 318:
#line 3082 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 319:
#line 3095 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 320:
#line 3099 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 321:
#line 3111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 322:
#line 3117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 323:
#line 3131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 324:
#line 3142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 325:
#line 3146 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 326:
#line 3150 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 327:
#line 3154 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 328:
#line 3158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 329:
#line 3162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 330:
#line 3166 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 331:
#line 3170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 332:
#line 3180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 333:
#line 3184 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 334:
#line 3194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 335:
#line 3199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 336:
#line 3204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 337:
#line 3215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 338:
#line 3225 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 339:
#line 3229 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 340:
#line 3240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 341:
#line 3250 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 342:
#line 3261 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 343:
#line 3317 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 344:
#line 3323 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 345:
#line 3335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 346:
#line 3341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 347:
#line 3353 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 348:
#line 3357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 3367 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 3371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 3375 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 352:
#line 3385 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 353:
#line 3393 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 354:
#line 3401 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 355:
#line 3409 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 356:
#line 3417 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 357:
#line 3425 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 358:
#line 3440 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 359:
#line 3446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 360:
#line 3458 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 361:
#line 3464 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 362:
#line 3477 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 365:
#line 3494 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 366:
#line 3499 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 367:
#line 3510 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 368:
#line 3514 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 369:
#line 3521 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 370:
#line 3527 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 371:
#line 3533 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 372:
#line 3541 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 373:
#line 3555 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 374:
#line 3559 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 375:
#line 3566 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 376:
#line 3572 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 377:
#line 3578 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 378:
#line 3586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 379:
#line 3600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 380:
#line 3605 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 381:
#line 3616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 382:
#line 3621 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 383:
#line 3632 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 384:
#line 3637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 385:
#line 3642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 386:
#line 3648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 387:
#line 3660 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 388:
#line 3666 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 389:
#line 3671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 390:
#line 3676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 391:
#line 3687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 392:
#line 3692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 393:
#line 3707 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 394:
#line 3712 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 395:
#line 3729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 396:
#line 3744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 397:
#line 3748 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 398:
#line 3752 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 399:
#line 3756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 400:
#line 3760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 401:
#line 3764 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 402:
#line 3774 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 403:
#line 3785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 404:
#line 3791 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 405:
#line 3797 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 406:
#line 3802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 407:
#line 3824 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 408:
#line 3830 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 409:
#line 3836 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 410:
#line 3841 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 411:
#line 3852 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 412:
#line 3863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 413:
#line 3874 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 414:
#line 3880 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 415:
#line 3886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 416:
#line 3891 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 417:
#line 3902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 418:
#line 3908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 419:
#line 3920 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 420:
#line 3932 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 421:
#line 3938 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 422:
#line 3944 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 423:
#line 3981 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 424:
#line 3986 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 425:
#line 3991 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 426:
#line 4002 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 427:
#line 4006 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 428:
#line 4010 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 429:
#line 4020 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 430:
#line 4031 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 431:
#line 4035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 432:
#line 4039 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 433:
#line 4043 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 434:
#line 4047 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 435:
#line 4051 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 436:
#line 4055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 437:
#line 4059 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 438:
#line 4063 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 439:
#line 4073 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 440:
#line 4083 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 441:
#line 4087 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 442:
#line 4092 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 443:
#line 4103 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 444:
#line 4113 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 445:
#line 4123 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 446:
#line 4127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 447:
#line 4131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 448:
#line 4141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 449:
#line 4147 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 450:
#line 4153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 451:
#line 4159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 452:
#line 4165 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 453:
#line 4177 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 454:
#line 4188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		;}
    break;

  case 455:
#line 4195 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
                           NULL,
                           true);
		;}
    break;

  case 456:
#line 4202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		;}
    break;

  case 457:
#line 4209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		;}
    break;

  case 458:
#line 4216 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 459:
#line 4223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		;}
    break;

  case 460:
#line 4230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 461:
#line 4243 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 462:
#line 4264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 463:
#line 4271 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 464:
#line 4291 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 465:
#line 4331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 466:
#line 4336 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 467:
#line 4339 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 468:
#line 4347 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 469:
#line 4353 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 470:
#line 4359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 471:
#line 4365 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 472:
#line 4371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 473:
#line 4378 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 474:
#line 4384 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 475:
#line 4390 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 476:
#line 4396 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 477:
#line 4402 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 478:
#line 4414 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 479:
#line 4419 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 480:
#line 4429 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 481:
#line 4435 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 482:
#line 4447 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 483:
#line 4473 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 484:
#line 4484 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 485:
#line 4490 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 486:
#line 4503 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 487:
#line 4517 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 488:
#line 4524 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 489:
#line 4531 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 490:
#line 4542 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 491:
#line 4549 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 492:
#line 4557 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 493:
#line 4566 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(14) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (9)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (12)].sval)),
                          (yysemantic_stack_[(14) - (14)].expr));
    ;}
    break;

  case 495:
#line 4582 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 496:
#line 4599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 497:
#line 4600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty"); ;}
    break;

  case 498:
#line 4601 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("attribute"); ;}
    break;

  case 499:
#line 4602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("comment"); ;}
    break;

  case 500:
#line 4603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document-node"); ;}
    break;

  case 501:
#line 4604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("element"); ;}
    break;

  case 502:
#line 4605 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("item"); ;}
    break;

  case 503:
#line 4606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("if"); ;}
    break;

  case 504:
#line 4607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("node"); ;}
    break;

  case 505:
#line 4608 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("processing-instruction"); ;}
    break;

  case 506:
#line 4609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-attribute"); ;}
    break;

  case 507:
#line 4610 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-element"); ;}
    break;

  case 508:
#line 4611 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("text"); ;}
    break;

  case 509:
#line 4612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("typeswitch"); ;}
    break;

  case 510:
#line 4613 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty-sequence"); ;}
    break;

  case 511:
#line 4614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("boundary-space"); ;}
    break;

  case 512:
#line 4615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ft-option"); ;}
    break;

  case 513:
#line 4616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("base-uri"); ;}
    break;

  case 514:
#line 4617 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lax"); ;}
    break;

  case 515:
#line 4618 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strict"); ;}
    break;

  case 516:
#line 4619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("idiv"); ;}
    break;

  case 517:
#line 4620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document"); ;}
    break;

  case 518:
#line 4621 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("not"); ;}
    break;

  case 519:
#line 4622 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sensitive"); ;}
    break;

  case 520:
#line 4623 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insensitive"); ;}
    break;

  case 521:
#line 4624 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("diacritics"); ;}
    break;

  case 522:
#line 4625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("without"); ;}
    break;

  case 523:
#line 4626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stemming"); ;}
    break;

  case 524:
#line 4627 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("thesaurus"); ;}
    break;

  case 525:
#line 4628 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stop"); ;}
    break;

  case 526:
#line 4629 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("wildcards"); ;}
    break;

  case 527:
#line 4630 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("entire"); ;}
    break;

  case 528:
#line 4631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("content"); ;}
    break;

  case 529:
#line 4632 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("word"); ;}
    break;

  case 530:
#line 4633 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("start"); ;}
    break;

  case 531:
#line 4634 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("end"); ;}
    break;

  case 532:
#line 4635 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("most"); ;}
    break;

  case 533:
#line 4636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("skip"); ;}
    break;

  case 534:
#line 4637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy"); ;}
    break;

  case 535:
#line 4638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("value"); ;}
    break;

  case 536:
#line 4639 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("eq"); ;}
    break;

  case 537:
#line 4640 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ne"); ;}
    break;

  case 538:
#line 4641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lt"); ;}
    break;

  case 539:
#line 4642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("le"); ;}
    break;

  case 540:
#line 4643 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("gt"); ;}
    break;

  case 541:
#line 4644 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ge"); ;}
    break;

  case 542:
#line 4645 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("at"); ;}
    break;

  case 543:
#line 4646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("variable"); ;}
    break;

  case 544:
#line 4647 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("return"); ;}
    break;

  case 545:
#line 4648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("for"); ;}
    break;

  case 546:
#line 4649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("outer"); ;}
    break;

  case 547:
#line 4650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sliding"); ;}
    break;

  case 548:
#line 4651 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("tumbling"); ;}
    break;

  case 549:
#line 4652 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("previous"); ;}
    break;

  case 550:
#line 4653 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("next"); ;}
    break;

  case 551:
#line 4654 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("only"); ;}
    break;

  case 552:
#line 4655 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("when"); ;}
    break;

  case 553:
#line 4656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("count"); ;}
    break;

  case 554:
#line 4657 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("in"); ;}
    break;

  case 555:
#line 4658 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("let"); ;}
    break;

  case 556:
#line 4659 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("where"); ;}
    break;

  case 557:
#line 4660 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("by"); ;}
    break;

  case 558:
#line 4661 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("group"); ;}
    break;

  case 559:
#line 4662 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("order"); ;}
    break;

  case 560:
#line 4663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stable"); ;}
    break;

  case 561:
#line 4664 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ascending"); ;}
    break;

  case 562:
#line 4665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("descending"); ;}
    break;

  case 563:
#line 4666 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("greatest"); ;}
    break;

  case 564:
#line 4667 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("least"); ;}
    break;

  case 565:
#line 4668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("collation"); ;}
    break;

  case 566:
#line 4669 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("some"); ;}
    break;

  case 567:
#line 4670 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("every"); ;}
    break;

  case 568:
#line 4671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("satisfies"); ;}
    break;

  case 569:
#line 4672 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("case"); ;}
    break;

  case 570:
#line 4673 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("as"); ;}
    break;

  case 571:
#line 4674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("then"); ;}
    break;

  case 572:
#line 4675 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("else"); ;}
    break;

  case 573:
#line 4676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("or"); ;}
    break;

  case 574:
#line 4677 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("and"); ;}
    break;

  case 575:
#line 4678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("instance"); ;}
    break;

  case 576:
#line 4679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("of"); ;}
    break;

  case 577:
#line 4680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("castable"); ;}
    break;

  case 578:
#line 4681 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("to"); ;}
    break;

  case 579:
#line 4682 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("div"); ;}
    break;

  case 580:
#line 4683 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("mod"); ;}
    break;

  case 581:
#line 4684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("union"); ;}
    break;

  case 582:
#line 4685 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("intersect"); ;}
    break;

  case 583:
#line 4686 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("except"); ;}
    break;

  case 584:
#line 4687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("validate"); ;}
    break;

  case 585:
#line 4688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cast"); ;}
    break;

  case 586:
#line 4689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("treat"); ;}
    break;

  case 587:
#line 4690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("is"); ;}
    break;

  case 588:
#line 4691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("preserve"); ;}
    break;

  case 589:
#line 4692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strip"); ;}
    break;

  case 590:
#line 4693 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("namespace"); ;}
    break;

  case 591:
#line 4694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("external"); ;}
    break;

  case 592:
#line 4695 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("encoding"); ;}
    break;

  case 593:
#line 4696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-preserve"); ;}
    break;

  case 594:
#line 4697 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("inherit"); ;}
    break;

  case 595:
#line 4698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-inherit"); ;}
    break;

  case 596:
#line 4699 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("declare"); ;}
    break;

  case 597:
#line 4700 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("construction"); ;}
    break;

  case 598:
#line 4701 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordering"); ;}
    break;

  case 599:
#line 4702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("default"); ;}
    break;

  case 600:
#line 4703 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy-namespaces"); ;}
    break;

  case 601:
#line 4704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("option"); ;}
    break;

  case 602:
#line 4705 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("version"); ;}
    break;

  case 603:
#line 4706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("import"); ;}
    break;

  case 604:
#line 4707 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema"); ;}
    break;

  case 605:
#line 4708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("function"); ;}
    break;

  case 606:
#line 4709 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("score"); ;}
    break;

  case 607:
#line 4710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ftcontains"); ;}
    break;

  case 608:
#line 4711 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("weight"); ;}
    break;

  case 609:
#line 4712 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("window"); ;}
    break;

  case 610:
#line 4713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("distance"); ;}
    break;

  case 611:
#line 4714 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("occurs"); ;}
    break;

  case 612:
#line 4715 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("times"); ;}
    break;

  case 613:
#line 4716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("same"); ;}
    break;

  case 614:
#line 4717 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("different"); ;}
    break;

  case 615:
#line 4718 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lowercase"); ;}
    break;

  case 616:
#line 4719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("uppercase"); ;}
    break;

  case 617:
#line 4720 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("relationship"); ;}
    break;

  case 618:
#line 4721 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("levels"); ;}
    break;

  case 619:
#line 4722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("language"); ;}
    break;

  case 620:
#line 4723 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("any"); ;}
    break;

  case 621:
#line 4724 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("all"); ;}
    break;

  case 622:
#line 4725 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("phrase"); ;}
    break;

  case 623:
#line 4726 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exactly"); ;}
    break;

  case 624:
#line 4727 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("from"); ;}
    break;

  case 625:
#line 4728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("words"); ;}
    break;

  case 626:
#line 4729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentences"); ;}
    break;

  case 627:
#line 4730 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentence"); ;}
    break;

  case 628:
#line 4731 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("paragraph"); ;}
    break;

  case 629:
#line 4732 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("replace"); ;}
    break;

  case 630:
#line 4733 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("modify"); ;}
    break;

  case 631:
#line 4734 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("first"); ;}
    break;

  case 632:
#line 4735 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insert"); ;}
    break;

  case 633:
#line 4736 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("bofer"); ;}
    break;

  case 634:
#line 4737 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("after"); ;}
    break;

  case 635:
#line 4738 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("revalidation"); ;}
    break;

  case 636:
#line 4739 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("with"); ;}
    break;

  case 637:
#line 4740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("nodes"); ;}
    break;

  case 638:
#line 4741 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("rename"); ;}
    break;

  case 639:
#line 4742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("last"); ;}
    break;

  case 640:
#line 4743 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("delete"); ;}
    break;

  case 641:
#line 4744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("into"); ;}
    break;

  case 642:
#line 4745 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("updating"); ;}
    break;

  case 643:
#line 4746 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordered"); ;}
    break;

  case 644:
#line 4747 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("unordered"); ;}
    break;

  case 645:
#line 4759 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 646:
#line 4765 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 647:
#line 4782 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 648:
#line 4786 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 649:
#line 4790 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 650:
#line 4794 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 651:
#line 4804 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 652:
#line 4807 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 653:
#line 4810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 654:
#line 4813 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 655:
#line 4822 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 656:
#line 4825 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 657:
#line 4834 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 658:
#line 4837 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 659:
#line 4846 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 660:
#line 4849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 661:
#line 4858 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 662:
#line 4861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 663:
#line 4870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 664:
#line 4873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 665:
#line 4876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 666:
#line 4885 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 667:
#line 4888 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 668:
#line 4897 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 669:
#line 4901 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, static_cast<Expr *> ((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 670:
#line 4911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 671:
#line 4914 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 672:
#line 4917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 673:
#line 4920 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 674:
#line 4923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 675:
#line 4932 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 676:
#line 4941 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 677:
#line 4945 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 678:
#line 4949 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 679:
#line 4953 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 680:
#line 4957 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 681:
#line 4961 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 682:
#line 4965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 683:
#line 4975 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 684:
#line 4978 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 685:
#line 4981 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 686:
#line 4984 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 687:
#line 4993 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 688:
#line 4996 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 689:
#line 4999 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 690:
#line 5002 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 691:
#line 5011 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 692:
#line 5014 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 693:
#line 5023 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 694:
#line 5026 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 695:
#line 5029 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 696:
#line 5032 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 697:
#line 5035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 698:
#line 5038 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 699:
#line 5041 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 700:
#line 5050 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 701:
#line 5053 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 702:
#line 5062 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 703:
#line 5065 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 704:
#line 5068 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 705:
#line 5071 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 706:
#line 5080 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 707:
#line 5083 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 708:
#line 5086 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 709:
#line 5089 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 710:
#line 5092 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 711:
#line 5101 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 712:
#line 5104 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 713:
#line 5113 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 714:
#line 5116 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 715:
#line 5125 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 716:
#line 5128 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 717:
#line 5137 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 718:
#line 5140 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 719:
#line 5149 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 720:
#line 5158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 721:
#line 5161 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 722:
#line 5170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 723:
#line 5173 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 724:
#line 5176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 725:
#line 5185 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 726:
#line 5188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 727:
#line 5191 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 728:
#line 5194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 729:
#line 5197 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 730:
#line 5206 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 731:
#line 5210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 732:
#line 5214 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 733:
#line 5218 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 734:
#line 5228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 735:
#line 5237 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 736:
#line 5247 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 737:
#line 5256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 738:
#line 5259 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 739:
#line 5268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 740:
#line 5271 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 741:
#line 5274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 742:
#line 5283 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 743:
#line 5286 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 744:
#line 5295 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6479 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -925;
  const short int
  xquery_parser::yypact_[] =
  {
      1241,  -925,  -925,  -925,  -925,  -105,   112,    15,   377,   172,
    6208,    -9,   433,   516,    26,  -925,  -925,   192,    49,  -925,
     610,    69,  -925,   106,  -925,  -925,  -925,   237,  -925,   184,
     506,   298,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
     329,  -925,   254,   275,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  6449,  -925,  5475,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  7654,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   355,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    4479,  1740,  7654,  -925,  -925,  -925,  -925,  -925,  -925,   342,
    -925,  -925,  -925,  -925,   464,  -925,  5967,  -925,  -925,  -925,
    -925,  -925,  7654,  -925,  -925,  5226,  -925,  -925,  -925,  -925,
    -925,  -925,   416,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,    11,   318,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,   293,   450,   476,  -925,   414,   393,  -925,  -925,  -925,
    -925,  -925,  -925,   512,  -925,   501,   540,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  1491,   646,  -925,  1989,  -925,  -925,   571,
    4479,   503,   521,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,   592,  -925,  -925,
    -925,  -925,   258,  7654,  -925,  -925,  -925,  -925,  -925,   561,
     642,  -925,   502,   481,   -48,   -11,   -63,    31,  -925,   648,
     542,   638,   640,  4728,  -925,  -925,  -925,   -24,  -925,  -925,
    5226,  -925,   369,  -925,   595,  5475,  -925,   595,  5475,  -925,
    -925,  -925,  -925,   595,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,   598,  -925,  4479,  -925,  4479,  4479,   602,   603,
     604,  4479,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    4479,  6690,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
     605,  4479,  4479,   562,  4479,   573,  7654,   701,   702,  7654,
     271,   -14,   721,    -6,   313,   643,   110,   724,   477,    32,
    4479,  -925,  4479,    28,   612,    91,   249,  7654,   724,  7654,
    4479,   493,   494,  -925,   647,   649,  -925,  7654,    17,  4479,
    6931,   616,   615,   617,   618,   619,   620,  -925,  -925,  -925,
    7654,  2238,   -20,  -925,    38,   726,  4479,    34,  -925,   741,
     593,  -925,  4479,   564,  -925,   739,  4479,  4479,   596,  4479,
    4479,  4479,  4479,   549,  7654,  4479,  7654,  -925,  -925,  -925,
    -925,    26,   610,  -925,  -925,   571,   725,  4479,   622,   237,
     506,   298,   663,   623,   624,  4479,  4479,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,   675,  -925,    -2,  4977,  4977,  4977,
    -925,  4977,  4977,  -925,  4977,  -925,  4977,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  4977,  4977,     6,  4977,  4977,  4977,
    4977,  4977,  4977,  4977,  4977,  4977,  4977,  4977,   556,   691,
     694,   697,  -925,  -925,  -925,  2487,  -925,  -925,  5226,  5226,
    4479,   595,  -925,  -925,   595,  -925,   595,  2736,  -925,   611,
      12,  4479,  4479,  4479,    78,    14,  -925,    83,   165,  2985,
     150,   201,  -925,   262,  -925,   644,  7654,  7654,   755,  -925,
    -925,  -925,  -925,  -925,  -925,   687,   688,  -925,  -925,  7654,
     645,   650,   721,   673,   670,  -925,  -925,  -925,   445,    42,
     447,   763,  -925,  -925,   372,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,   170,   323,   621,  -925,   625,  3234,   724,
     706,   754,   724,   721,   709,    -4,  -925,    41,   679,   703,
    -925,   -26,   633,  -925,  -925,  7654,   -12,  -925,   631,   615,
     254,  -925,   632,   634,   345,  -925,   181,   191,  3483,     4,
    -925,   -18,  -925,  -925,  7654,   726,  -925,   136,   349,  -925,
    -925,  -925,  -925,   360,  -925,   -33,  -925,  -925,  -925,   -21,
      95,   723,   581,   597,    10,  -925,   681,   639,    68,  -925,
    -925,   651,  -925,    23,  -925,  -925,   660,  7654,  4479,   711,
    -925,  -925,   712,  7413,   713,  4479,   714,   -71,   690,   -25,
     642,  -925,  -925,  -925,  -925,  -925,  4977,  -925,  -925,  -925,
    4479,     6,   213,  -925,   565,   239,   585,   586,  -925,  -925,
     580,   388,   -11,   -11,   188,   -63,   -63,   -63,   -63,    31,
      31,  -925,  -925,  7413,  7413,  7654,  7654,  -925,   361,  -925,
    -925,   -17,  -925,  -925,  -925,   193,   692,  -925,   362,   373,
     375,   740,   693,  7654,  -925,  7654,  -925,  -925,   379,  -925,
    -925,  -925,   231,   326,   644,   644,  -925,   381,   411,   485,
     721,   721,  -925,   590,   721,  -925,  -925,   572,  -925,  -925,
     570,   367,  -925,  -925,  -925,  -925,  -925,  -925,   575,  -925,
    -925,   652,   700,  -925,  -925,  -925,   385,   717,   721,   695,
     727,   756,   721,   733,  4479,  4479,   710,   721,   737,  4479,
     716,   -37,  -925,   394,   613,  -925,  -925,   513,   -12,  -925,
    -925,  -925,   708,  7654,  -925,  7654,  -925,  -925,   390,  4479,
    -925,   816,  -925,   230,  -925,    27,  -925,  -925,   822,  -925,
     479,  4479,  4479,  4479,   483,  4479,  4479,  4479,  4479,  4479,
    4479,   744,  4479,  4479,   626,   715,   746,   725,  4479,  -925,
     453,   758,  -925,  7654,   759,  -925,  7654,   718,   719,  -925,
     382,  -925,  -925,  -925,  7654,  -925,  7654,  4479,   729,  4479,
    4479,   -57,   730,  -925,   391,   685,  -925,   627,  -925,   224,
    -925,   408,    46,   629,     6,   408,  4977,  4977,   276,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,     6,   731,    46,  -925,
     606,   802,  -925,  -925,  -925,  -925,  -925,   728,  -925,  -925,
    -925,  4479,  -925,  -925,  -925,  -925,  -925,  7172,   324,  -925,
    3732,   698,   699,   742,   704,   705,  -925,  7654,   788,   211,
    -925,  -925,  4479,  -925,   484,   692,  -925,  -925,  -925,  -925,
    -925,  4479,   541,  -925,  -925,  -925,  -925,  -925,   628,   216,
     847,  -925,    40,  -925,  -925,  4479,  3981,  -925,   721,   781,
    -925,  -925,  -925,   721,   781,  7654,  -925,  -925,  4479,   720,
    7654,  -925,  4479,  4479,   750,  4479,   747,  -925,   774,   775,
    4479,  7654,   641,   815,  -925,  -925,  -925,  4230,   732,  -925,
     734,  -925,  -925,  -925,   768,  -925,   187,  -925,  -925,   876,
    -925,  -925,  4479,  7654,  -925,  -925,   268,  -925,  -925,  -925,
     722,   672,   677,  -925,  -925,  -925,   680,   682,  -925,  -925,
    -925,  -925,  -925,   666,  7654,   736,  -925,   751,   626,  -925,
    4479,  7654,   758,  -925,   721,  -925,   594,  -925,   198,   799,
    -925,  4479,   803,   711,  -925,   743,   745,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  4479,  -925,  -925,  4479,   770,  4479,
    -925,  -925,  4977,  -925,  -925,  -925,  -925,  -925,    33,  4977,
    4977,   397,  -925,   585,  -925,  -925,   145,  4977,  -925,  -925,
     586,     6,   657,  -925,  -925,  -925,  -925,  7654,   748,   164,
    -925,  -925,   396,  -925,  -925,  -925,  -925,  -925,   817,  7413,
     798,   832,   404,  -925,  -925,  -925,  -925,  -925,  4479,   -34,
     891,   893,   -34,    30,   212,   219,   808,  -925,   405,   836,
     721,   781,  -925,  -925,  -925,  -925,  -925,  -925,  4479,  -925,
    4479,  7654,  7654,  -925,   545,  -925,  4479,  -925,   407,  -925,
    -925,   816,  7654,   280,  -925,   409,   816,  7654,  -925,  -925,
    4479,  4479,  4479,  4479,  4479,  -925,  4479,  5724,  -925,   757,
    -925,  -925,  -925,  -925,   799,  -925,  -925,  -925,   721,  -925,
    -925,  -925,  -925,  -925,  -925,  4479,  -925,   -63,  4977,  4977,
     -63,   467,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
     840,  4479,  7654,  4479,  -925,  -925,  -925,  -925,  7413,  -925,
    -925,   216,   216,   -34,  -925,  -925,  -925,    37,   -34,   898,
     683,   841,  -925,   841,  -925,  4479,  -925,   721,  -925,  -925,
    -925,   863,  -925,  -925,  -925,  -925,    -8,   816,  7654,  -925,
     749,   816,  -925,  -925,  -925,  -925,  -925,  -925,   246,  -925,
    -925,  -925,  -925,   -63,   -63,  4977,  7413,  -925,   761,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,    46,  -925,   253,  -925,
     277,  -925,   781,   827,   148,   356,  -925,   753,   816,  -925,
     760,   829,   801,   -63,   766,  4479,   707,   841,  -925,  -925,
    7654,  -925,  -925,   855,   325,  -925,  -925,  -925,  -925,   773,
     429,  -925,  -925,  -925,   762,  -925,  7654,  -925,  4479,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
     279,  -925,   838,   801,  7654,  -925,   282,   839,   801,  7654,
    -925,   771,   801,  -925
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   317,   318,   496,   464,     0,     0,     0,   584,   509,
     501,   517,   508,   499,   596,   605,   642,   503,   505,   532,
     603,   566,   560,     0,   601,   529,   604,   555,   597,     0,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   598,
       0,   513,   507,   500,   600,   575,   506,   511,   308,   311,
     574,   570,   561,   542,   498,   298,     0,   569,   577,   585,
     296,   565,   334,   543,   599,   297,   300,   562,   579,     0,
     340,   306,   336,   572,   497,   563,   564,   592,   567,   583,
     591,   302,   301,   516,   554,   594,   335,   582,   587,   502,
       0,     0,     0,   255,   580,   590,   595,   593,   573,   643,
     559,   557,   558,   307,     0,   254,     0,   310,   309,   588,
     544,   568,     0,   299,   284,     0,   316,   589,   571,   578,
     586,   581,   644,   536,   541,   540,   539,   538,   537,   510,
     556,     0,     0,   602,   530,   634,   633,   635,   515,   514,
     533,   640,   504,   632,   637,   638,   629,   535,   576,   631,
     641,   639,   630,   534,   636,     0,     0,   621,   620,   519,
     512,   521,   520,   614,   610,   527,   531,   528,   623,   624,
     607,   518,   619,   618,   615,   611,   628,   622,   617,   613,
     606,   627,   626,   612,   616,   608,   609,   522,   523,   525,
     625,   524,   526,     0,     0,     2,     0,     4,     6,     0,
       0,     0,     0,    17,    19,    21,    22,    23,    29,    24,
      27,    28,    33,    34,    35,    30,    31,    37,    38,    25,
      32,   114,   111,   112,   113,    26,    11,    96,    97,    99,
     129,   135,     0,     0,   127,   128,   100,   101,   102,   103,
     211,   213,   215,   225,   228,   230,   233,   238,   241,   244,
     246,   248,   250,     0,   252,   258,   260,     0,   276,   259,
     280,   283,   285,   288,   290,     0,   295,   292,     0,   303,
     313,   315,   289,   319,   324,   332,   325,   326,   327,   330,
     331,   328,   329,   347,   349,   350,   351,   348,   396,   397,
     398,   399,   400,   401,   312,   438,   430,   437,   436,   435,
     432,   434,   431,   433,   333,    36,   104,   105,   107,   106,
     108,   109,   314,   110,     0,    83,     0,     0,     0,     0,
       0,     0,   584,   509,   501,   517,   508,   499,   596,   503,
     505,   603,   566,   555,   545,   546,   507,   500,   498,   567,
       0,     0,   643,   644,   640,   504,   632,   638,   629,   534,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   495,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,     0,    84,     0,     0,     0,
       0,     0,   501,   508,   499,   505,   498,   304,   314,   337,
       0,     0,     0,   338,     0,   363,     0,     0,   279,     0,
       0,   282,     0,     0,   392,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     1,     5,
       7,     0,     0,    12,    10,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   134,   130,
     136,   131,   133,   132,   139,   140,     0,     0,     0,     0,
     269,     0,     0,   267,     0,   220,     0,   268,   261,   266,
     265,   264,   263,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   257,   256,   253,     0,   277,   281,     0,     0,
       0,   291,   321,   294,   293,   305,   320,     0,    81,     0,
       0,     0,     0,     0,     0,     0,   454,     0,     0,     0,
       0,     0,   443,     0,   444,     0,     0,     0,     0,    72,
      73,    46,    47,   494,    55,     0,     0,    40,    41,     0,
       0,     0,     0,     0,     0,   465,   466,   467,     0,     0,
       0,     0,   683,   684,     0,    45,   676,   677,   678,   679,
     680,   681,   682,     0,     0,     0,   445,     0,     0,     0,
      64,     0,     0,     0,    56,     0,   200,     0,     0,   152,
     153,     0,     0,   117,   118,     0,     0,   138,     0,     0,
       0,   440,     0,     0,     0,   448,     0,     0,     0,     0,
      78,     0,    79,   339,   364,   363,   360,     0,     0,   394,
     393,   278,   453,     0,   391,     0,   478,   479,   439,     0,
       0,     0,     0,     0,     0,   484,     0,     0,     0,   155,
     172,     0,    18,     0,    20,    98,     0,     0,     0,     0,
     116,   173,     0,     0,     0,     0,     0,     0,     0,     0,
     212,   214,   218,   224,   223,   222,     0,   219,   216,   217,
       0,     0,     0,   668,   226,   647,   655,   657,   659,   661,
     663,   666,   232,   231,   229,   235,   236,   237,   234,   239,
     240,   243,   242,     0,     0,     0,     0,   274,     0,   286,
     287,     0,   322,   343,   345,     0,     0,   270,     0,     0,
       0,     0,     0,     0,   458,     0,   455,   403,     0,   402,
     411,   412,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,    54,     0,     0,   685,   686,     0,   687,   691,
       0,     0,   720,   689,   690,   719,   688,   692,     0,   699,
     721,     0,     0,   447,   446,   413,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   646,     0,     0,   119,   120,     0,   125,   461,
     441,   442,     0,     0,   451,     0,   449,   407,     0,     0,
      80,   363,   361,     0,   352,     0,   341,   342,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,   126,
     184,   180,   182,     0,   174,   175,     0,   502,   510,   419,
     420,   426,   427,   429,     0,   142,     0,     0,     0,     0,
       0,     0,     0,   221,     0,     0,   662,     0,   227,     0,
     675,     0,     0,     0,     0,     0,     0,     0,   648,   652,
     670,   651,   674,   672,   671,   673,     0,     0,     0,   664,
     727,   725,   729,   667,   245,   247,   249,   417,   251,   275,
     323,     0,   344,    82,   271,   272,   273,     0,     0,   206,
       0,     0,     0,   462,     0,     0,   404,     0,    74,     0,
      90,    85,     0,    86,     0,     0,    52,    53,    50,    51,
      69,     0,     0,    42,    43,    48,    49,    39,     0,     0,
       0,   694,     0,   693,   710,     0,     0,   414,     0,    66,
      60,    63,    62,     0,    58,     0,   198,   202,     0,     0,
       0,   157,     0,     0,     0,     0,     0,   121,     0,     0,
       0,     0,   166,     0,   163,   168,   124,     0,     0,   462,
       0,   408,   199,   364,     0,   353,     0,   387,   384,     0,
     388,   389,     0,     0,   390,   383,     0,   358,   386,   385,
       0,     0,     0,   471,   472,   468,     0,     0,   476,   477,
     473,   482,   480,     0,     0,     0,   486,     0,   487,   488,
       0,     0,   181,   193,     0,   194,     0,   185,   186,   187,
     188,     0,   177,     0,   141,     0,     0,   423,   425,   424,
     421,   150,   151,   144,     0,   146,   143,     0,     0,     0,
     669,   665,     0,   722,   723,   743,   742,   738,     0,     0,
       0,     0,   724,   656,   737,   649,     0,     0,   654,   653,
     658,     0,     0,   728,   726,   418,   346,     0,     0,     0,
     207,   405,     0,   459,   460,   463,   456,   457,    92,     0,
       0,    75,     0,    87,    88,    89,    68,    71,     0,   708,
       0,     0,   706,   702,     0,     0,     0,   415,     0,    65,
       0,    59,   201,   203,    13,   154,   159,   158,     0,   161,
       0,     0,     0,   123,   164,   167,     0,   409,     0,   452,
     450,   363,     0,     0,   395,     0,   363,     0,   359,     9,
       0,     0,     0,     0,     0,   485,     0,     0,   489,     0,
     156,   197,   195,   196,   189,   190,   191,   183,     0,   178,
     176,   428,   422,   148,   145,     0,   147,   744,     0,     0,
     730,     0,   741,   740,   739,   734,   735,   650,   660,   736,
       0,     0,     0,     0,   406,    93,    76,    91,     0,    95,
      70,     0,     0,   709,   711,   713,   715,     0,   707,     0,
       0,     0,   697,     0,   695,     0,   416,     0,    61,   160,
     162,   171,   170,   165,   122,   410,     0,   363,     0,    94,
       0,   363,   469,   470,   474,   475,   481,   483,     0,   645,
     192,   179,   149,   732,   731,     0,     0,   208,     0,   204,
      77,   718,   717,   712,   716,   714,   703,   704,     0,   700,
       0,   210,    67,     0,   373,   367,   362,     0,   363,   354,
       0,     0,     0,   733,     0,     0,     0,     0,   698,   696,
       0,   381,   375,     0,   374,   376,   382,   379,   369,     0,
     368,   370,   380,   356,     0,   355,     0,   490,     0,   205,
     705,   701,   169,   366,   377,   378,   365,   371,   372,   357,
       0,   209,     0,     0,     0,   491,     0,     0,     0,     0,
     492,     0,     0,   493
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -925,  -925,   764,  -925,   752,   765,  -925,   767,  -925,   504,
     505,  -414,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -738,  -925,  -925,  -925,  -925,
      -7,  -669,  -925,  -925,  -925,  -925,  -925,  -925,  -118,  -925,
    -884,   769,   -87,  -210,  -925,  -925,  -925,  -925,   176,  -925,
    -925,   735,  -925,  -925,  -925,  -925,  -925,   130,  -427,  -557,
    -925,  -925,  -925,    19,  -925,  -925,  -147,     8,   -40,  -925,
    -925,  -925,   -51,  -925,  -925,   146,   -46,  -925,  -925,   -42,
    -919,  -925,   558,    35,  -925,  -925,    81,  -925,  -925,   507,
     510,  -925,  -423,  -816,   491,   226,  -474,   225,   227,  -925,
    -925,  -925,  -925,  -925,   738,  -925,  -925,  -925,  -925,  -925,
     772,  -925,  -925,   -97,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,   -28,  -155,  -925,  -925,   343,   147,  -925,  -465,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -766,  -925,
       7,  -925,   366,  -592,  -925,  -925,  -925,  -925,  -925,  -278,
    -271,  -924,  -584,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,   289,  -576,  -663,  -925,  -925,    43,  -626,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,   588,   589,  -619,
     273,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,    -5,
    -925,  -925,    -3,  -360,  -341,   -10,  -925,   319,  -925,  -925,
     138,   127,   -55,   322,  -925,  -925,   139,  -925,  -632,  -925,
    -925,  -925,  -925,  -185,  -719,  -925,   -83,  -450,  -925,  -500,
    -925,  -925,  -925,  -925,  -835,  -925,  -925,  -925,  -925,   -44,
     149,  -925
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   919,   573,   218,   219,   220,
     713,   221,   401,   222,   223,   224,   225,   889,   890,   964,
     893,   226,   227,   228,   229,   447,   384,   767,   768,   230,
     448,   231,   450,   232,   233,   234,   454,   455,   942,   648,
     235,   579,   628,   580,   586,   943,   944,   945,   629,   451,
     452,   814,   815,  1129,   453,   811,   812,   997,   998,   999,
    1000,   236,   575,   576,   237,   878,   879,   238,   239,   240,
     241,   656,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   474,   475,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   501,   502,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   695,   282,   283,   284,
     966,   605,   606,   607,  1226,  1249,  1250,  1243,  1244,  1251,
    1245,   967,   968,   285,   286,   969,   287,   288,   289,   290,
     291,   292,   293,   866,   649,   819,  1010,   820,   821,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   881,
     882,   304,   305,   306,   307,   308,   309,   310,   624,   625,
     311,   988,   989,   920,   374,   312,   313,   664,   848,   665,
     666,   667,   668,   669,   670,   671,   849,   850,   555,   556,
     557,   558,   559,  1218,  1219,   560,  1163,  1072,  1167,  1164,
     561,   562,   852,   863,  1031,   853,   854,   859,   855,  1145,
    1027,   838
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       350,   756,   534,   402,   404,   761,   675,   676,   677,   678,
    1064,   663,   913,   783,   924,   570,   574,   822,   411,   965,
     864,   865,   634,  1042,   760,     4,   544,   873,   397,   647,
    1035,   413,   567,   851,   957,   958,   652,   578,   653,   654,
     609,   655,  1108,   657,   391,   371,   398,   565,   764,   589,
     643,   658,   659,   644,   827,   790,  1214,   822,   822,   399,
     356,   357,   358,   356,   357,   358,   371,  1224,  1017,   437,
     359,   437,   437,   359,   643,  1138,   644,   788,   360,  1125,
    1126,  1161,   405,   590,   933,   753,   884,   480,   477,   361,
     828,   362,   832,   753,   363,   759,   409,   364,    62,   801,
     830,   437,   410,   437,   508,   478,   509,   495,  1028,    72,
     533,   314,   959,   481,   548,   484,   365,   643,   910,   365,
     366,   805,   351,   645,  1028,   485,   482,   437,   479,   960,
     106,   961,   531,    86,  1074,   789,   727,   660,   535,   315,
     661,  1139,   540,   902,  1162,   870,   486,   541,   602,   316,
     780,  1241,  1225,   536,   948,   957,   950,   806,   962,   487,
     483,   754,    92,   497,   367,   532,   755,   437,   377,   779,
     582,   794,   703,   697,   646,   702,   791,   792,   104,  1108,
     372,   591,   722,   373,   765,  1081,   610,   936,   646,   954,
     965,   793,   566,  1075,   957,   958,   663,   663,   542,   963,
     965,  1215,   603,   414,   934,  1200,   616,   617,   646,   619,
     620,   621,   622,   751,  1048,   627,  1039,   766,   131,   646,
     646,  1147,   831,   456,   802,   368,  1065,   635,   747,   569,
     510,   750,     4,   833,   514,   640,   641,   503,  1170,   437,
     505,   662,   701,   646,   378,   784,   369,   704,   549,   369,
     960,   822,   961,   515,   705,   398,   550,   543,   398,   437,
    1242,  1029,  1030,  1152,   520,   521,   728,   523,   533,   551,
     773,   552,   959,  1169,  1018,   957,   958,  1029,  1030,   962,
     775,   553,   871,   563,   554,   564,   994,   957,   958,   960,
     437,   961,   795,   796,  1070,   729,   730,   694,   731,   732,
    1060,  1171,   594,   438,   996,    62,   321,   797,  1173,   439,
     785,   709,   440,   441,   601,   380,    72,   839,   962,   608,
     442,   548,    92,   484,   477,   613,   370,  1153,  1241,   706,
     887,   518,   957,   485,   741,  1231,   379,   965,   104,   955,
      86,   478,  1237,   571,   660,   774,   525,   661,  1257,   528,
    1071,   437,   385,   959,   839,   776,   386,   872,   548,  1102,
     903,   904,   710,   957,   907,   959,  1237,   577,  1272,   581,
     960,  1277,   961,  1036,  1247,  1061,  1172,   588,   131,   663,
     597,  1236,   960,  1174,   961,   840,  1142,   572,   387,  1275,
     577,   663,  1143,   634,  1280,   888,  1156,   929,  1283,   962,
    1144,   689,   690,    92,   956,   443,   877,   444,   688,   388,
    1232,   962,   437,   691,   626,    92,   630,  1238,  1049,   104,
    1023,   445,   840,   711,   698,   699,   700,   960,   810,   961,
     529,   104,   708,   822,   437,   825,   957,  1264,   437,  1222,
    1107,  1239,   891,  1273,   530,   910,  1278,  1247,   446,   437,
     437,   437,  1188,  1024,   400,   549,   962,   892,   960,   131,
     961,   911,   437,   550,   437,   841,   842,   843,   437,  1248,
     643,   131,   537,   406,   437,   844,   551,   407,   552,   437,
     437,   746,  1155,   845,   742,   437,   538,   962,   553,   846,
     847,   554,   549,   437,   437,  1210,   437,   416,   437,   417,
     550,   912,   841,   842,   843,  1007,   772,   896,   317,  1186,
     786,   778,   415,   551,  1190,   552,   714,   715,  1261,   935,
     845,   787,   869,   874,   897,   553,  1037,   847,   554,   719,
     993,   960,   822,   961,   875,  1008,   876,   898,   498,   499,
     886,   994,  1267,  1234,   926,   927,   917,   412,  1137,   931,
     995,   951,  1020,  1009,   899,  1140,  1141,  1154,  1079,   996,
     962,   643,   381,   382,   352,  1159,  1176,   353,  1185,   952,
    1189,   938,   939,   834,   940,   763,   663,   318,   319,   320,
     822,   973,   974,   975,   418,   978,   979,   980,   981,   982,
     983,   644,   985,   986,   781,  1227,   736,   422,   810,  1230,
    1063,   900,   423,   938,   939,   383,   901,   431,   860,   861,
     504,   424,   941,   459,   432,   892,   506,  1013,   421,  1015,
    1016,   460,   461,   644,   462,   737,   738,   809,   739,   740,
     862,   463,   425,   823,  1121,   464,  1254,   465,  1142,   426,
    1246,  1252,   466,  1205,  1143,   484,   428,   354,   692,  1025,
     355,   692,  1144,   692,  1026,   485,   375,  1067,   467,   376,
    1246,  1046,  1068,  1213,  1203,  1204,  1252,   725,  1213,   733,
     726,   435,   734,   823,   823,   823,   823,   545,   546,   547,
     419,   437,   420,   468,   469,   470,   471,   472,   473,   436,
     971,  1066,   972,   883,   976,   883,   977,   905,   906,   938,
     939,  1122,  1123,   672,   673,  1076,   457,   894,   895,   679,
     680,  1211,  1212,   681,   682,   476,   458,   488,  1083,   489,
    1178,   490,  1086,  1087,   491,  1089,   522,   500,   867,   867,
    1093,  1233,   507,   511,   512,   513,   519,   524,   526,   527,
     533,   371,   539,   568,   583,   584,   585,   598,   587,   341,
     604,   353,   355,   373,   390,   611,   614,   612,   615,   623,
     618,   633,   637,   949,   642,   949,   683,   684,  1201,   636,
     685,   638,   639,   686,   716,   696,   717,   718,   712,   723,
    1119,   724,   735,   720,   748,   743,   749,   752,   721,   744,
     757,   810,   758,  1052,   762,   769,   770,   799,   771,   798,
     804,   800,   803,  1002,  1133,  1062,   456,  1134,   808,  1136,
     813,   816,   824,   826,  1011,   829,  1012,   837,   856,   807,
     858,   857,   877,    90,   880,   909,   908,   915,   918,  1078,
     914,   916,   925,   921,   923,   928,   930,   932,   922,   947,
     953,   970,   937,   984,   987,   991,   990,  1001,  1003,  1021,
    1044,  1045,  1005,  1006,  1014,  1019,  1041,  1022,  1160,  1032,
    1098,  1043,  1053,  1054,  1059,  1055,  1073,   823,  1056,  1057,
    1080,  1088,  1090,  1091,  1092,  1105,  1096,  1058,  1179,  1101,
    1180,  1104,  1114,  1069,  1110,  1117,  1184,   994,  1084,  1111,
    1109,  1128,  1112,   643,  1113,  1135,  1099,   887,  1100,  1116,
    1192,  1193,  1194,  1195,  1196,  1149,  1197,  1131,  1158,  1132,
    1165,  1151,  1166,  1175,  1177,   577,  1206,  1216,  1199,   910,
     581,  1217,  1223,  1229,  1235,  1202,  1240,  1253,  1256,  1258,
    1263,  1094,   892,  1266,  1255,  1282,  1269,  1274,  1279,   631,
     632,  1207,  1157,  1209,   946,  1260,  1004,  1183,   429,  1085,
    1095,  1120,  1130,  1106,   992,  1127,  1124,   427,   599,  1050,
    1082,   430,  1198,  1103,   650,  1221,   433,   449,   651,   434,
     674,   782,  1268,  1265,   626,   868,   592,   593,   885,  1115,
     835,   630,  1033,  1040,   836,  1118,  1148,  1038,  1220,  1168,
       0,   494,  1146,     0,  1034,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1259,     0,     0,     0,   496,
       0,     0,     0,     0,     0,     0,     0,  1150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1271,   823,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1181,  1182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1187,     0,     0,     0,     0,  1191,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   398,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1208,     0,     0,     0,     0,     0,   823,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1228,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   823,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1270,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,  1276,     0,     5,     6,     0,  1281,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
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
     102,   103,   104,     0,   105,   106,     0,     0,   107,   108,
     109,     0,     0,     0,   110,     0,   111,   112,   113,     0,
     114,   115,   116,     0,   117,     0,   118,   119,   120,   121,
     122,     0,   123,   124,   125,   126,   127,   128,     0,     0,
     129,   130,   131,     0,   132,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,     0,   170,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     5,     6,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
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
     102,   103,   104,     0,   105,   106,     0,     0,   107,   108,
     109,     0,     0,     0,   110,     0,   111,   112,   113,     0,
     114,   115,   116,     0,   117,     0,   118,   119,   120,   121,
     122,     0,   123,   124,   125,   126,   127,   128,     0,     0,
     129,   130,   131,     0,   132,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,     0,   170,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     0,     0,     7,
       8,     9,    10,    11,    12,    13,   328,    15,    16,     0,
      17,    18,    19,   331,    21,    22,     0,    24,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     0,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    60,    61,     0,
       0,     0,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,     0,    73,    74,    75,    76,     0,
      77,     0,     0,     0,    78,    79,    80,    81,    82,     0,
       0,     0,     0,     0,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,    91,    92,    93,    94,    95,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,   105,   106,     0,     0,   107,   108,   109,
       0,     0,     0,   110,   403,   111,   112,   113,     0,   114,
     115,   116,     0,   117,     0,   118,   119,   120,   121,   122,
       0,   123,   124,   125,   126,   127,   128,     0,     0,   129,
     130,   131,     0,     0,   133,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,     0,   170,   171,     0,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     5,     6,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     0,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    60,    61,     0,     0,
       0,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,     0,    73,    74,    75,    76,     0,    77,
       0,     0,     0,    78,    79,    80,    81,    82,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     0,    91,    92,    93,    94,    95,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,   105,   106,     0,     0,   107,   108,   109,     0,
       0,     0,   110,     0,   111,   112,   113,     0,   114,   115,
     116,     0,   117,     0,   118,   119,   120,   121,   122,     0,
     123,   124,   125,   126,   127,   128,     0,     0,   129,   130,
     131,     0,     0,   133,     0,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,     0,   170,   171,     0,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     0,     0,     7,     8,     9,
      10,    11,    12,    13,   328,    15,    16,     0,    17,    18,
      19,   331,    21,    22,     0,    24,    25,    26,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,     0,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    60,    61,     0,     0,     0,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,     0,    73,    74,    75,    76,     0,    77,     0,
       0,     0,    78,    79,    80,    81,    82,     0,     0,     0,
       0,     0,    83,    84,    85,    86,    87,    88,    89,    90,
       0,     0,    91,    92,    93,    94,    95,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,   105,   106,     0,     0,   107,   108,   109,     0,   600,
       0,   110,     0,   111,   112,   113,     0,   114,   115,   116,
       0,   117,     0,   118,   119,   120,   121,   122,     0,   123,
     124,   125,   126,   127,   128,     0,     0,   129,   130,   131,
       0,     0,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,     0,   170,   171,     0,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,     5,     6,     0,     0,     7,     8,     9,    10,
      11,    12,    13,   328,    15,    16,     0,    17,    18,    19,
     331,    21,    22,     0,    24,    25,    26,     0,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     0,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    60,    61,     0,     0,     0,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,     0,    73,    74,    75,    76,     0,    77,     0,     0,
       0,    78,    79,    80,    81,    82,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    88,    89,    90,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
     105,   106,     0,     0,   107,   108,   109,     0,   687,     0,
     110,     0,   111,   112,   113,     0,   114,   115,   116,     0,
     117,     0,   118,   119,   120,   121,   122,     0,   123,   124,
     125,   126,   127,   128,     0,     0,   129,   130,   131,     0,
       0,   133,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
       0,   170,   171,     0,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     0,     0,     7,     8,     9,    10,    11,
      12,    13,   328,    15,    16,     0,    17,    18,    19,   331,
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
      97,    98,    99,   100,   101,   102,   103,   104,     0,   105,
     106,     0,     0,   107,   108,   109,     0,     0,     0,   110,
     693,   111,   112,   113,     0,   114,   115,   116,     0,   117,
       0,   118,   119,   120,   121,   122,     0,   123,   124,   125,
     126,   127,   128,     0,     0,   129,   130,   131,     0,     0,
     133,     0,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,     0,
     170,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       5,     6,     0,     0,     7,     8,     9,    10,    11,    12,
      13,   328,    15,    16,     0,    17,    18,    19,   331,    21,
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
      98,    99,   100,   101,   102,   103,   104,     0,   105,   106,
       0,     0,   107,   108,   109,     0,   707,     0,   110,     0,
     111,   112,   113,     0,   114,   115,   116,     0,   117,     0,
     118,   119,   120,   121,   122,     0,   123,   124,   125,   126,
     127,   128,     0,     0,   129,   130,   131,     0,     0,   133,
       0,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,     0,   170,
     171,     0,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     5,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
     328,    15,    16,     0,    17,    18,    19,   331,    21,    22,
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
      99,   100,   101,   102,   103,   104,     0,   105,   106,     0,
       0,   107,   108,   109,     0,   745,     0,   110,     0,   111,
     112,   113,     0,   114,   115,   116,     0,   117,     0,   118,
     119,   120,   121,   122,     0,   123,   124,   125,   126,   127,
     128,     0,     0,   129,   130,   131,     0,     0,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,     0,   170,   171,
       0,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     0,     5,     6,
       0,     0,     7,     8,     9,    10,    11,    12,    13,   328,
      15,    16,     0,    17,    18,    19,   331,    21,    22,     0,
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
     100,   101,   102,   103,   104,     0,   105,   106,     0,     0,
     107,   108,   109,     0,   777,     0,   110,     0,   111,   112,
     113,     0,   114,   115,   116,     0,   117,     0,   118,   119,
     120,   121,   122,     0,   123,   124,   125,   126,   127,   128,
       0,     0,   129,   130,   131,     0,     0,   133,     0,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,     0,   170,   171,     0,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     0,
       0,     7,     8,     9,    10,    11,    12,    13,   328,    15,
      16,     0,    17,    18,    19,   331,    21,    22,     0,    24,
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
     101,   102,   103,   104,     0,   105,   106,     0,     0,   107,
     108,   109,     0,  1051,     0,   110,     0,   111,   112,   113,
       0,   114,   115,   116,     0,   117,     0,   118,   119,   120,
     121,   122,     0,   123,   124,   125,   126,   127,   128,     0,
       0,   129,   130,   131,     0,     0,   133,     0,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,     0,   170,   171,     0,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     5,     6,     0,     0,
       7,     8,     9,    10,    11,    12,    13,   328,    15,    16,
       0,    17,    18,    19,   331,    21,    22,     0,    24,    25,
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
     102,   103,   104,     0,   105,   106,     0,     0,   107,   108,
     109,     0,  1077,     0,   110,     0,   111,   112,   113,     0,
     114,   115,   116,     0,   117,     0,   118,   119,   120,   121,
     122,     0,   123,   124,   125,   126,   127,   128,     0,     0,
     129,   130,   131,     0,     0,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,     0,   170,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     0,     0,     7,
       8,     9,    10,    11,    12,    13,   328,    15,    16,     0,
      17,    18,    19,   331,    21,    22,     0,    24,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     0,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    60,    61,     0,
       0,     0,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,     0,    73,    74,    75,    76,     0,
      77,     0,     0,     0,    78,    79,    80,    81,    82,     0,
       0,     0,     0,     0,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,    91,    92,    93,    94,    95,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,   105,   106,     0,     0,   107,   108,   109,
       0,  1097,     0,   110,     0,   111,   112,   113,     0,   114,
     115,   116,     0,   117,     0,   118,   119,   120,   121,   122,
       0,   123,   124,   125,   126,   127,   128,     0,     0,   129,
     130,   131,     0,     0,   133,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,     0,   170,   171,     0,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     5,     6,     0,     0,     7,     8,
       9,    10,    11,    12,    13,   328,    15,    16,     0,    17,
      18,    19,   331,    21,    22,     0,    24,    25,    26,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     0,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    60,    61,     0,     0,
       0,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,     0,    73,    74,    75,    76,     0,    77,
       0,     0,     0,    78,    79,    80,    81,    82,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     0,    91,    92,    93,    94,    95,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,   105,   106,     0,     0,   107,   108,   109,     0,
       0,     0,   110,     0,   111,   112,   113,     0,   114,   115,
     116,     0,   117,     0,   118,   119,   120,   121,   122,     0,
     123,   124,   125,   126,   127,   128,     0,     0,   129,   130,
     131,     0,     0,   133,     0,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,     0,   170,   171,     0,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,   323,
      10,    11,    12,    13,   328,    15,    16,     0,   329,    18,
      19,   331,   332,    22,     0,    24,    25,    26,     0,   333,
      28,     0,   334,   335,    32,    33,    34,    35,    36,    37,
      38,    39,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,     0,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    60,    61,     0,     0,     0,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,     0,    73,    74,    75,    76,     0,    77,     0,
       0,     0,   339,    79,    80,    81,    82,     0,     0,     0,
       0,     0,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    91,    92,   492,    94,    95,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,   493,   106,     0,     0,   107,   108,   109,     0,     0,
       0,   110,     0,   111,   112,   113,     0,   114,   115,   116,
       0,   117,     0,   118,   119,   120,   121,   122,     0,   123,
     124,   125,   126,   127,   128,     0,     0,   129,   130,   131,
       0,     0,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   344,   142,   346,   144,   347,   348,   147,   148,   149,
     150,   151,   152,   349,   154,     0,     0,     0,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,     0,   170,   171,     0,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,   323,    10,
      11,    12,    13,   328,    15,    16,     0,   329,    18,    19,
     331,   332,    22,     0,    24,    25,    26,     0,   333,    28,
       0,   334,   335,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     0,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    60,    61,     0,     0,     0,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,     0,    73,    74,    75,    76,     0,    77,     0,     0,
       0,   339,    79,    80,    81,    82,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
     105,   106,     0,     0,   107,   108,   109,     0,     0,     0,
     110,     0,   111,   112,   113,     0,   114,   115,   116,     0,
     117,     0,   118,   119,   120,   121,   122,     0,   123,   124,
     125,   126,   127,   128,     0,     0,   129,   130,   131,     0,
       0,   133,     0,   134,   135,   136,   137,   138,   139,   140,
     344,   142,   346,   144,   347,   348,   147,   148,   149,   150,
     151,   152,   349,   154,     0,     0,     0,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
       0,   170,   171,     0,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   322,   323,    10,    11,
      12,    13,   328,    15,    16,     0,   329,    18,    19,   331,
     332,    22,     0,    24,    25,    26,     0,   333,    28,     0,
     334,   335,    32,    33,    34,    35,    36,    37,    38,    39,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,     0,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    60,    61,     0,     0,     0,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
       0,    73,    74,    75,    76,     0,    77,     0,     0,     0,
     339,    79,    80,    81,    82,     0,     0,     0,     0,     0,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      91,    92,     0,    94,    95,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
       0,     0,     0,   107,   108,   109,     0,     0,     0,   110,
       0,   111,   112,   113,     0,     0,     0,   116,     0,   117,
       0,   118,   119,   120,   121,   122,     0,   123,   124,   125,
     126,   127,   128,     0,     0,   129,   130,   131,     0,     0,
     133,     0,   134,   135,   136,   137,   138,   139,   140,   344,
     142,   346,   144,   347,   348,   147,   148,   149,   150,   151,
     152,   349,   154,     0,     0,     0,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,     0,
     170,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   322,   323,   392,   325,   393,
     394,   328,    15,    16,     0,   329,   395,    19,   331,   332,
      22,     0,    24,    25,    26,     0,   333,    28,     0,   334,
     335,    32,    33,    34,    35,    36,    37,    38,    39,     0,
      41,    42,    43,    44,    45,    46,    47,     0,     0,    50,
       0,    51,    52,    53,   396,     0,     0,    57,    58,    59,
       0,     0,     0,    61,     0,     0,     0,     0,    63,    64,
       0,     0,    67,    68,     0,     0,     0,     0,     0,     0,
      73,    74,    75,    76,     0,    77,     0,     0,     0,   339,
      79,    80,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,     0,    87,    88,    89,     0,     0,     0,     0,
       0,     0,    94,    95,     0,     0,     0,     0,    96,    97,
      98,   342,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,     0,     0,     0,   110,     0,
     111,   112,     0,     0,     0,     0,   116,     0,   117,     0,
     118,   119,   120,   121,   343,     0,   123,   124,   125,   126,
     127,   128,     0,     0,   129,   130,     0,     0,     0,   133,
       0,   134,   135,   136,   137,   138,   139,   140,   344,   142,
     346,   144,   347,   348,   147,   148,   149,   150,   151,   152,
     349,   154,     0,     0,     0,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,     0,   170,
     171,     0,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   322,   323,   324,   325,   326,   327,
     328,    15,    16,     0,   329,   330,    19,   331,   332,    22,
       0,    24,    25,    26,     0,   333,    28,     0,   334,   335,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    41,
     336,   337,    44,    45,    46,    47,     0,     0,    50,     0,
      51,    52,    53,   338,     0,     0,    57,    58,    59,     0,
       0,     0,    61,     0,     0,     0,     0,    63,    64,     0,
       0,    67,    68,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,     0,    77,     0,     0,     0,   339,    79,
      80,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,     0,    87,    88,    89,     0,     0,     0,     0,     0,
       0,    94,    95,     0,     0,     0,     0,    96,    97,    98,
     342,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,     0,     0,     0,   110,     0,   111,
       0,     0,     0,     0,     0,   116,     0,   117,     0,   118,
     119,   120,   121,   343,     0,   123,   124,   125,   126,   127,
     128,     0,     0,   129,   130,     0,     0,     0,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   344,   345,   346,
     144,   347,   348,   147,   148,   149,   150,   151,   152,   349,
     154,     0,     0,     0,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,     0,   170,   171,
       0,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   408,     0,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   322,   323,   324,
     325,   326,   327,   328,    15,    16,     0,   329,   330,    19,
     331,   332,    22,     0,    24,    25,    26,     0,   333,    28,
       0,   334,   335,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    41,   336,   337,    44,    45,    46,    47,     0,
       0,    50,     0,    51,    52,    53,   338,     0,     0,    57,
      58,    59,     0,     0,     0,    61,     0,     0,     0,     0,
      63,    64,     0,     0,    67,    68,     0,     0,     0,     0,
       0,     0,    73,    74,    75,    76,     0,    77,     0,     0,
       0,   339,    79,    80,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    85,     0,    87,    88,    89,     0,     0,
       0,     0,     0,     0,    94,    95,     0,     0,     0,     0,
      96,    97,    98,   342,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,     0,     0,     0,
     110,     0,   111,     0,     0,     0,     0,     0,     0,     0,
     117,     0,   118,   119,   120,   121,   343,     0,   123,   124,
     125,   126,   127,   128,     0,     0,   129,   130,     0,     0,
       0,   133,     0,   134,   135,   136,   137,   138,   139,   140,
     344,   345,   346,   144,   347,   348,   147,   148,   149,   150,
     151,   152,   349,   154,     0,     0,     0,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
       0,   170,   171,     0,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   322,   323,
     324,   325,   326,   327,   328,    15,    16,     0,   329,   330,
      19,   331,   332,    22,     0,    24,    25,    26,     0,   333,
      28,     0,   334,   335,    32,    33,    34,    35,    36,    37,
      38,    39,     0,    41,   336,   337,    44,    45,    46,    47,
       0,     0,    50,     0,    51,    52,    53,   338,     0,     0,
      57,    58,    59,     0,     0,     0,    61,     0,     0,     0,
       0,    63,    64,     0,     0,    67,    68,     0,     0,     0,
       0,     0,     0,    73,    74,    75,    76,     0,    77,     0,
       0,     0,   339,    79,    80,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,     0,    87,    88,    89,   340,
       0,     0,   341,     0,     0,    94,    95,     0,     0,     0,
       0,    96,    97,    98,   342,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,     0,     0,
       0,   110,     0,   111,     0,     0,     0,     0,     0,     0,
       0,   117,     0,   118,   119,   120,   121,   343,     0,   123,
     124,   125,   126,   127,   128,     0,     0,   129,   130,     0,
       0,     0,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   344,   345,   346,   144,   347,   348,   147,   148,   149,
     150,   151,   152,   349,   154,     0,     0,     0,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,     0,   170,   171,     0,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   322,
     323,   324,   325,   326,   327,   328,    15,    16,     0,   329,
     330,    19,   331,   332,    22,     0,    24,    25,    26,     0,
     333,    28,     0,   334,   335,    32,    33,    34,    35,    36,
      37,    38,    39,     0,    41,   336,   337,    44,    45,    46,
      47,     0,     0,    50,     0,    51,    52,    53,   338,     0,
       0,    57,    58,    59,     0,     0,     0,    61,     0,     0,
       0,     0,    63,    64,     0,     0,    67,    68,     0,     0,
       0,     0,     0,     0,    73,    74,    75,    76,     0,    77,
       0,     0,     0,   339,    79,    80,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,     0,    87,    88,    89,
     389,     0,     0,   390,     0,     0,    94,    95,     0,     0,
       0,     0,    96,    97,    98,   342,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,     0,
       0,     0,   110,     0,   111,     0,     0,     0,     0,     0,
       0,     0,   117,     0,   118,   119,   120,   121,   343,     0,
     123,   124,   125,   126,   127,   128,     0,     0,   129,   130,
       0,     0,     0,   133,     0,   134,   135,   136,   137,   138,
     139,   140,   344,   345,   346,   144,   347,   348,   147,   148,
     149,   150,   151,   152,   349,   154,     0,     0,     0,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,     0,   170,   171,     0,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     322,   323,   324,   325,   326,   327,   328,    15,    16,     0,
     329,   330,    19,   331,   332,    22,     0,    24,    25,    26,
       0,   333,    28,     0,   334,   335,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    41,   336,   337,    44,    45,
      46,    47,     0,     0,    50,     0,    51,    52,    53,   338,
       0,     0,    57,    58,    59,     0,     0,     0,    61,     0,
       0,     0,     0,    63,    64,     0,     0,    67,    68,     0,
       0,     0,     0,     0,     0,    73,    74,    75,    76,     0,
      77,     0,     0,     0,   339,    79,    80,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,     0,    87,    88,
      89,     0,     0,     0,     0,     0,     0,    94,    95,     0,
       0,     0,     0,    96,    97,    98,   342,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
       0,     0,     0,   110,   516,   111,     0,     0,     0,     0,
       0,   517,     0,   117,     0,   118,   119,   120,   121,   343,
       0,   123,   124,   125,   126,   127,   128,     0,     0,   129,
     130,     0,     0,     0,   133,     0,   134,   135,   136,   137,
     138,   139,   140,   344,   345,   346,   144,   347,   348,   147,
     148,   149,   150,   151,   152,   349,   154,     0,     0,     0,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,     0,   170,   171,     0,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   322,   323,   324,   325,   326,   327,   328,    15,    16,
       0,   329,   330,    19,   331,   332,    22,     0,    24,    25,
      26,     0,   333,    28,     0,   334,   335,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    41,   336,   337,    44,
      45,    46,    47,     0,     0,    50,     0,    51,    52,    53,
     338,     0,     0,    57,    58,    59,     0,     0,     0,    61,
       0,     0,     0,     0,    63,    64,     0,     0,    67,    68,
       0,     0,     0,     0,     0,     0,    73,    74,    75,    76,
       0,    77,     0,     0,     0,   339,    79,    80,     0,     0,
       0,     0,     0,     0,     0,    83,    84,    85,     0,    87,
      88,    89,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,    96,    97,    98,   342,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,     0,     0,   110,   595,   111,     0,     0,     0,
       0,     0,   596,     0,   117,     0,   118,   119,   120,   121,
     343,     0,   123,   124,   125,   126,   127,   128,     0,     0,
     129,   130,     0,     0,     0,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   344,   345,   346,   144,   347,   348,
     147,   148,   149,   150,   151,   152,   349,   154,     0,     0,
       0,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,     0,   170,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   322,   323,   392,   325,   393,   394,   328,    15,
      16,     0,   329,   395,    19,   331,   332,    22,     0,    24,
      25,    26,     0,   333,    28,     0,   334,   335,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    41,    42,    43,
      44,    45,    46,    47,     0,     0,    50,     0,    51,    52,
      53,   396,     0,     0,    57,    58,    59,     0,     0,     0,
      61,     0,     0,     0,     0,    63,    64,     0,     0,    67,
      68,  1047,     0,     0,     0,     0,     0,    73,    74,    75,
      76,     0,    77,     0,     0,     0,   339,    79,    80,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,     0,
      87,    88,   817,     0,     0,     0,     0,     0,     0,    94,
      95,     0,     0,     0,     0,    96,    97,    98,   342,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,     0,     0,     0,   110,     0,   111,   112,     0,
       0,     0,     0,     0,     0,   117,     0,   118,   119,   120,
     121,   343,     0,   123,   124,   125,   126,   127,   128,     0,
       0,   818,   130,     0,     0,     0,   133,     0,   134,   135,
     136,   137,   138,   139,   140,   344,   142,   346,   144,   347,
     348,   147,   148,   149,   150,   151,   152,   349,   154,     0,
       0,     0,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,     0,   170,   171,     0,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,   323,   392,   325,   393,   394,   328,
      15,    16,     0,   329,   395,    19,   331,   332,    22,     0,
      24,    25,    26,     0,   333,    28,     0,   334,   335,    32,
      33,    34,    35,    36,    37,    38,    39,     0,    41,    42,
      43,    44,    45,    46,    47,     0,     0,    50,     0,    51,
      52,    53,   396,     0,     0,    57,    58,    59,     0,     0,
       0,    61,     0,     0,     0,     0,    63,    64,     0,     0,
      67,    68,     0,     0,     0,     0,     0,     0,    73,    74,
      75,    76,     0,    77,     0,     0,     0,   339,    79,    80,
       0,     0,     0,     0,     0,     0,     0,    83,    84,    85,
       0,    87,    88,   817,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,     0,     0,    96,    97,    98,   342,
     100,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,     0,     0,   110,     0,   111,   112,
       0,     0,     0,     0,     0,     0,   117,     0,   118,   119,
     120,   121,   343,     0,   123,   124,   125,   126,   127,   128,
       0,     0,   818,   130,     0,     0,     0,   133,     0,   134,
     135,   136,   137,   138,   139,   140,   344,   142,   346,   144,
     347,   348,   147,   148,   149,   150,   151,   152,   349,   154,
       0,     0,     0,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,     0,   170,   171,     0,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   322,   323,   324,   325,   326,   327,
     328,    15,    16,     0,   329,   330,    19,   331,   332,    22,
       0,    24,    25,    26,     0,   333,    28,     0,   334,   335,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    41,
     336,   337,    44,    45,    46,    47,     0,     0,    50,     0,
      51,    52,    53,   338,     0,     0,    57,    58,    59,     0,
       0,     0,    61,     0,     0,     0,     0,    63,    64,     0,
       0,    67,    68,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,     0,    77,     0,     0,     0,   339,    79,
      80,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,     0,    87,    88,    89,     0,     0,     0,     0,     0,
       0,    94,    95,     0,     0,     0,     0,    96,    97,    98,
     342,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,     0,     0,     0,   110,     0,   111,
       0,     0,     0,     0,     0,     0,     0,   117,     0,   118,
     119,   120,   121,   343,     0,   123,   124,   125,   126,   127,
     128,     0,     0,   129,   130,     0,     0,     0,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   344,   345,   346,
     144,   347,   348,   147,   148,   149,   150,   151,   152,   349,
     154,     0,     0,     0,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,     0,   170,   171,
       0,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        10,   577,   362,    90,    91,   581,   480,   481,   482,   483,
     894,   476,   731,   605,   752,   375,   376,   643,   115,   785,
     683,   684,   436,   858,   581,    19,   367,   696,    56,   456,
     846,    20,   373,   665,     7,     8,   459,   378,   461,   462,
       6,   464,   966,   466,    54,    17,    56,    19,    60,    32,
      76,   474,   475,    78,   125,    76,    19,   683,   684,    69,
      37,    38,    39,    37,    38,    39,    17,    75,   125,    89,
      47,    89,    89,    47,    76,    42,    78,   110,    52,   998,
     999,   115,    92,    66,   121,    89,   705,    98,   136,    63,
     647,    65,   649,    89,    68,   121,   106,    71,    92,    89,
     125,    89,   112,    89,   314,   153,   316,   131,    78,   103,
      19,   216,    85,   124,    82,   178,    93,    76,    78,    93,
      94,    53,   131,   125,    78,   188,   137,    89,   176,   102,
     154,   104,   146,   127,    94,   168,    94,   131,   144,    27,
     134,   108,    32,   719,   178,   162,   115,    37,   168,   134,
     168,     3,   160,   159,   773,     7,   775,    89,   131,   128,
     171,   165,   135,   260,   138,   179,   125,    89,    99,   165,
     380,    76,    89,   161,   245,   161,   197,   198,   151,  1103,
     131,   164,   542,   134,   196,   923,   152,   763,   245,   781,
     956,   212,   164,   912,     7,     8,   661,   662,    88,   172,
     966,   164,   164,   192,   761,  1124,   416,   417,   245,   419,
     420,   421,   422,   573,   877,   425,   848,   229,   191,   245,
     245,  1037,   649,   233,   214,   199,   895,   437,   569,   138,
     317,   572,    19,   656,   321,   445,   446,   265,  1073,    89,
     268,   235,   164,   245,   138,   109,   223,   164,   216,   223,
     102,   877,   104,   340,    89,   265,   224,   147,   268,    89,
     112,   231,   232,    99,   351,   352,   224,   354,    19,   237,
      89,   239,    85,   243,   831,     7,     8,   231,   232,   131,
      89,   249,    89,   370,   252,   372,    88,     7,     8,   102,
      89,   104,   197,   198,    78,   253,   254,   507,   256,   257,
      89,    89,   389,    45,   106,    92,   134,   212,    89,    51,
     174,   161,    54,    55,   401,   131,   103,    78,   131,   406,
      62,    82,   135,   178,   136,   412,   134,   163,     3,   164,
      99,   341,     7,   188,   164,    89,    99,  1103,   151,   109,
     127,   153,    89,    94,   131,   164,   356,   134,  1232,   359,
     134,    89,    54,    85,    78,   164,    27,   164,    82,   172,
     720,   721,   161,     7,   724,    85,    89,   377,    89,   379,
     102,    89,   104,   847,    18,   164,   164,   387,   191,   844,
     390,  1216,   102,   164,   104,   146,   241,   138,   134,  1273,
     400,   856,   247,   807,  1278,   164,  1059,   757,  1282,   131,
     255,   498,   499,   135,   174,   147,    82,   149,   495,   134,
     164,   131,    89,   500,   424,   135,   426,   164,    94,   151,
     196,   163,   146,   161,   511,   512,   513,   102,   638,   104,
     159,   151,   519,  1059,    89,   645,     7,   112,    89,  1177,
     172,   164,   116,   164,   173,    78,   164,    18,   190,    89,
      89,    89,   172,   229,    99,   216,   131,   131,   102,   191,
     104,    94,    89,   224,    89,   226,   227,   228,    89,   113,
      76,   191,   159,   131,    89,   236,   237,    13,   239,    89,
      89,   568,  1058,   244,   161,    89,   173,   131,   249,   250,
     251,   252,   216,    89,    89,  1158,    89,   204,    89,   206,
     224,   134,   226,   227,   228,   123,   161,   126,   131,  1101,
     161,   598,   194,   237,  1106,   239,   526,   527,  1237,   125,
     244,   161,   161,   161,   143,   249,   250,   251,   252,   539,
      77,   102,  1158,   104,   161,   153,   161,   126,   169,   170,
     161,    88,   113,  1206,   754,   755,   161,   131,  1022,   759,
      97,   161,   161,   171,   143,  1029,  1030,   161,   918,   106,
     131,    76,    56,    57,   131,   161,   161,   134,   161,   779,
     161,    58,    59,   660,    61,   585,  1041,   200,   201,   202,
    1206,   791,   792,   793,   134,   795,   796,   797,   798,   799,
     800,    78,   802,   803,   604,  1187,   224,   204,   808,  1191,
     116,   116,   209,    58,    59,    99,   121,    36,   220,   221,
     267,    99,    99,   111,    43,   131,   273,   827,   204,   829,
     830,   119,   120,    78,   122,   253,   254,   637,   256,   257,
     242,   129,   131,   643,   994,   133,  1228,   135,   241,    99,
    1224,  1225,   140,   176,   247,   178,     0,   131,   501,   241,
     134,   504,   255,   506,   246,   188,    46,   116,   156,    49,
    1244,   871,   121,  1163,  1138,  1139,  1250,   222,  1168,   222,
     225,   168,   225,   683,   684,   685,   686,   200,   201,   202,
     204,    89,   206,   181,   182,   183,   184,   185,   186,   168,
     211,   901,   213,   703,   211,   705,   213,   107,   108,    58,
      59,   107,   108,   477,   478,   915,   145,   714,   715,   484,
     485,  1161,  1162,   486,   487,   234,    74,    69,   928,   177,
    1080,    83,   932,   933,    84,   935,   164,   132,   685,   686,
     940,  1205,   134,   131,   131,   131,   131,   164,    37,    37,
      19,    17,    99,   131,   251,   251,    99,   131,    99,   134,
      24,   134,   134,   134,   134,    14,   192,   164,    19,   210,
     164,    36,    99,   773,    89,   775,   210,    76,  1128,   147,
      76,   148,   148,    76,    19,   164,    89,    89,   134,   106,
     990,   111,    19,   138,    78,   164,    32,    78,   138,   164,
     111,  1001,    89,   880,   161,   164,   164,   216,   164,    76,
     161,   204,   121,   813,  1014,   892,   816,  1017,   148,  1019,
      99,    99,    99,    99,   824,   125,   826,   252,   233,   168,
     240,   235,    82,   131,   131,   255,   254,   175,   111,   916,
     255,   131,    99,   138,    78,   125,    99,   121,   111,   131,
      24,    19,   229,    99,   218,    99,   131,    89,    89,   164,
      48,   123,   134,   134,   125,   125,   125,   230,  1068,   230,
     947,   255,   164,   164,    76,   123,    19,   877,   164,   164,
      89,   121,   125,    99,    99,   962,    61,   887,  1088,   111,
    1090,     5,   216,   255,   212,   134,  1096,    88,   168,   212,
     168,    88,   212,    76,   212,   125,   164,    99,   164,   163,
    1110,  1111,  1112,  1113,  1114,   248,  1116,   164,    76,   164,
      19,   163,    19,   105,    78,   925,    76,    19,   161,    78,
     930,   238,    59,   174,   163,  1135,    99,   174,    99,   163,
      75,   941,   131,   160,   174,   164,   174,    99,    99,   435,
     435,  1151,  1060,  1153,   768,   238,   816,  1094,   196,   930,
     942,   991,  1003,   963,   808,  1001,   998,   193,   400,   878,
     925,   196,  1117,   956,   457,  1175,   199,   232,   458,   200,
     479,   605,  1250,  1244,   984,   686,   388,   388,   705,   984,
     661,   991,   844,   856,   662,   988,  1041,   848,  1173,  1072,
      -1,   253,  1036,    -1,   845,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1235,    -1,    -1,    -1,   257,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1047,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1258,  1059,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1091,  1092,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1102,    -1,    -1,    -1,    -1,  1107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1152,    -1,    -1,    -1,    -1,    -1,  1158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1256,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,
      19,    -1,    -1,    -1,  1274,    -1,    25,    26,    -1,  1279,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
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
     149,   150,   151,    -1,   153,   154,    -1,    -1,   157,   158,
     159,    -1,    -1,    -1,   163,    -1,   165,   166,   167,    -1,
     169,   170,   171,    -1,   173,    -1,   175,   176,   177,   178,
     179,    -1,   181,   182,   183,   184,   185,   186,    -1,    -1,
     189,   190,   191,    -1,   193,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,   234,   235,    -1,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
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
     149,   150,   151,    -1,   153,   154,    -1,    -1,   157,   158,
     159,    -1,    -1,    -1,   163,    -1,   165,   166,   167,    -1,
     169,   170,   171,    -1,   173,    -1,   175,   176,   177,   178,
     179,    -1,   181,   182,   183,   184,   185,   186,    -1,    -1,
     189,   190,   191,    -1,   193,   194,    -1,   196,   197,   198,
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
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,   153,   154,    -1,    -1,   157,   158,   159,
      -1,    -1,    -1,   163,   164,   165,   166,   167,    -1,   169,
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
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    -1,    -1,    87,    88,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,   103,    -1,   105,   106,   107,   108,    -1,   110,
      -1,    -1,    -1,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,   153,   154,    -1,    -1,   157,   158,   159,    -1,
      -1,    -1,   163,    -1,   165,   166,   167,    -1,   169,   170,
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
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
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
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
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
     144,   145,   146,   147,   148,   149,   150,   151,    -1,   153,
     154,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,   163,
     164,   165,   166,   167,    -1,   169,   170,   171,    -1,   173,
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
     145,   146,   147,   148,   149,   150,   151,    -1,   153,   154,
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
     146,   147,   148,   149,   150,   151,    -1,   153,   154,    -1,
      -1,   157,   158,   159,    -1,   161,    -1,   163,    -1,   165,
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
     147,   148,   149,   150,   151,    -1,   153,   154,    -1,    -1,
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
     148,   149,   150,   151,    -1,   153,   154,    -1,    -1,   157,
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
     149,   150,   151,    -1,   153,   154,    -1,    -1,   157,   158,
     159,    -1,   161,    -1,   163,    -1,   165,   166,   167,    -1,
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
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,   149,
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
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,   153,   154,    -1,    -1,   157,   158,   159,    -1,
      -1,    -1,   163,    -1,   165,   166,   167,    -1,   169,   170,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    -1,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    87,    88,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,    -1,   105,   106,   107,   108,    -1,   110,    -1,
      -1,    -1,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,   153,   154,    -1,    -1,   157,   158,   159,    -1,    -1,
      -1,   163,    -1,   165,   166,   167,    -1,   169,   170,   171,
      -1,   173,    -1,   175,   176,   177,   178,   179,    -1,   181,
     182,   183,   184,   185,   186,    -1,    -1,   189,   190,   191,
      -1,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,   234,   235,    -1,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    -1,    47,    48,    49,    -1,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    -1,    87,    88,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,    -1,   105,   106,   107,   108,    -1,   110,    -1,    -1,
      -1,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
     153,   154,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,
     163,    -1,   165,   166,   167,    -1,   169,   170,   171,    -1,
     173,    -1,   175,   176,   177,   178,   179,    -1,   181,   182,
     183,   184,   185,   186,    -1,    -1,   189,   190,   191,    -1,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,   234,   235,    -1,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    -1,    47,    48,    49,    -1,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    87,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
      -1,   105,   106,   107,   108,    -1,   110,    -1,    -1,    -1,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
     134,   135,    -1,   137,   138,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,   163,
      -1,   165,   166,   167,    -1,    -1,    -1,   171,    -1,   173,
      -1,   175,   176,   177,   178,   179,    -1,   181,   182,   183,
     184,   185,   186,    -1,    -1,   189,   190,   191,    -1,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
     234,   235,    -1,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,    -1,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,   173,    -1,
     175,   176,   177,   178,   179,    -1,   181,   182,   183,   184,
     185,   186,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,
      -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,   234,
     235,    -1,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     126,    -1,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,   163,    -1,   165,
      -1,    -1,    -1,    -1,    -1,   171,    -1,   173,    -1,   175,
     176,   177,   178,   179,    -1,   181,   182,   183,   184,   185,
     186,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,   234,   235,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    -1,    47,    48,    49,    -1,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    69,    70,    71,    -1,
      -1,    74,    -1,    76,    77,    78,    79,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,
      93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,    -1,   110,    -1,    -1,
      -1,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,    -1,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
     163,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   124,   125,   126,    -1,   128,   129,   130,   131,
      -1,    -1,   134,    -1,    -1,   137,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   163,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,
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
     131,    -1,    -1,   134,    -1,    -1,   137,   138,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,    -1,
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
     251,   252,   253,   254,   255,   256,   257,    17,    -1,    -1,
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
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,    -1,
      -1,   171,    -1,   173,    -1,   175,   176,   177,   178,   179,
      -1,   181,   182,   183,   184,   185,   186,    -1,    -1,   189,
     190,    -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,   235,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    -1,    47,    48,
      49,    -1,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    74,    -1,    76,    77,    78,
      79,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,    88,
      -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
      -1,   110,    -1,    -1,    -1,   114,   115,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,    -1,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,
      -1,    -1,   171,    -1,   173,    -1,   175,   176,   177,   178,
     179,    -1,   181,   182,   183,   184,   185,   186,    -1,    -1,
     189,   190,    -1,    -1,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,   234,   235,    -1,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    49,    -1,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,
      88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,    -1,   110,    -1,    -1,    -1,   114,   115,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,    -1,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,   163,    -1,   165,   166,    -1,
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
      -1,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   163,    -1,   165,   166,
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
     126,    -1,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
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
     256,   257
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
     147,   148,   149,   150,   151,   153,   154,   157,   158,   159,
     163,   165,   166,   167,   169,   170,   171,   173,   175,   176,
     177,   178,   179,   181,   182,   183,   184,   185,   186,   189,
     190,   191,   193,   194,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     234,   235,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   300,   301,
     302,   304,   306,   307,   308,   309,   314,   315,   316,   317,
     322,   324,   326,   327,   328,   333,   354,   357,   360,   361,
     362,   363,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   410,   411,   412,   426,   427,   429,   430,   431,
     432,   433,   434,   435,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   454,   455,   456,   457,   458,   459,
     460,   463,   468,   469,   216,    27,   134,   131,   200,   201,
     202,   134,    30,    31,    32,    33,    34,    35,    36,    40,
      41,    43,    44,    51,    54,    55,    66,    67,    79,   114,
     131,   134,   146,   179,   203,   204,   205,   207,   208,   215,
     468,   131,   131,   134,   131,   134,    37,    38,    39,    47,
      52,    63,    65,    68,    71,    93,    94,   138,   199,   223,
     134,    17,   131,   134,   467,    46,    49,    99,   138,    99,
     131,    56,    57,    99,   319,    54,    27,   134,   134,   131,
     134,   468,    32,    34,    35,    41,    79,   394,   468,   468,
      99,   305,   315,   164,   315,   468,   131,    13,    15,   468,
     468,   386,   131,    20,   192,   194,   204,   206,   134,   204,
     206,   204,   204,   209,    99,   131,    99,   275,     0,   277,
     278,    36,    43,   280,   314,   168,   168,    89,    45,    51,
      54,    55,    62,   147,   149,   163,   190,   318,   323,   324,
     325,   342,   343,   347,   329,   330,   468,   145,    74,   111,
     119,   120,   122,   129,   133,   135,   140,   156,   181,   182,
     183,   184,   185,   186,   378,   379,   234,   136,   153,   176,
      98,   124,   137,   171,   178,   188,   115,   128,    69,   177,
      83,    84,   136,   153,   377,   131,   383,   386,   169,   170,
     132,   398,   399,   394,   398,   394,   398,   134,   316,   316,
     315,   131,   131,   131,   315,   315,   164,   171,   468,   131,
     315,   315,   164,   315,   164,   468,    37,    37,   468,   159,
     173,   146,   179,    19,   466,   144,   159,   159,   173,    99,
      32,    37,    88,   147,   467,   200,   201,   202,    82,   216,
     224,   237,   239,   249,   252,   481,   482,   483,   484,   485,
     488,   493,   494,   315,   315,    19,   164,   467,   131,   138,
     466,    94,   138,   299,   466,   355,   356,   468,   467,   334,
     336,   468,   316,   251,   251,    99,   337,    99,   468,    32,
      66,   164,   450,   451,   315,   164,   171,   468,   131,   355,
     161,   315,   168,   164,    24,   414,   415,   416,   315,     6,
     152,    14,   164,   315,   192,    19,   316,   316,   164,   316,
     316,   316,   316,   210,   461,   462,   468,   316,   335,   341,
     468,   282,   283,    36,   284,   316,   147,    99,   148,   148,
     316,   316,    89,    76,    78,   125,   245,   331,   332,   437,
     362,   363,   365,   365,   365,   365,   364,   365,   365,   365,
     131,   134,   235,   401,   470,   472,   473,   474,   475,   476,
     477,   478,   368,   368,   367,   369,   369,   369,   369,   370,
     370,   371,   371,   210,    76,    76,    76,   161,   315,   386,
     386,   315,   399,   164,   316,   409,   164,   161,   315,   315,
     315,   164,   161,    89,   164,    89,   164,   161,   315,   161,
     161,   161,   134,   303,   468,   468,    19,    89,    89,   468,
     138,   138,   466,   106,   111,   222,   225,    94,   224,   253,
     254,   256,   257,   222,   225,    19,   224,   253,   254,   256,
     257,   164,   161,   164,   164,   161,   315,   467,    78,    32,
     467,   466,    78,    89,   165,   125,   437,   111,    89,   121,
     332,   437,   161,   468,    60,   196,   229,   320,   321,   164,
     164,   164,   161,    89,   164,    89,   164,   161,   315,   165,
     168,   468,   415,   416,   109,   174,   161,   161,   110,   168,
      76,   197,   198,   212,    76,   197,   198,   212,    76,   216,
     204,    89,   214,   121,   161,    53,    89,   168,   148,   468,
     316,   348,   349,    99,   344,   345,    99,   130,   189,   438,
     440,   441,   442,   468,    99,   316,    99,   125,   332,   125,
     125,   331,   332,   365,   315,   470,   476,   252,   504,    78,
     146,   226,   227,   228,   236,   244,   250,   251,   471,   479,
     480,   481,   495,   498,   499,   501,   233,   235,   240,   500,
     220,   221,   242,   496,   438,   438,   436,   441,   436,   161,
     162,    89,   164,   304,   161,   161,   161,    82,   358,   359,
     131,   452,   453,   468,   452,   453,   161,    99,   164,   310,
     311,   116,   131,   313,   303,   303,   126,   143,   126,   143,
     116,   121,   437,   466,   466,   107,   108,   466,   254,   255,
      78,    94,   134,   487,   255,   175,   131,   161,   111,   298,
     466,   138,   111,    78,   298,    99,   316,   316,   125,   466,
      99,   316,   121,   121,   332,   125,   437,   229,    58,    59,
      61,    99,   331,   338,   339,   340,   321,   131,   452,   468,
     452,   161,   316,    24,   416,   109,   174,     7,     8,    85,
     102,   104,   131,   172,   312,   411,   413,   424,   425,   428,
      19,   211,   213,   316,   316,   316,   211,   213,   316,   316,
     316,   316,   316,   316,    99,   316,   316,   218,   464,   465,
     131,    99,   348,    77,    88,    97,   106,   350,   351,   352,
     353,    89,   468,    89,   330,   134,   134,   123,   153,   171,
     439,   468,   468,   316,   125,   316,   316,   125,   332,   125,
     161,   164,   230,   196,   229,   241,   246,   503,    78,   231,
     232,   497,   230,   473,   503,   366,   369,   250,   479,   481,
     474,   125,   497,   255,    48,   123,   316,    99,   438,    94,
     359,   161,   315,   164,   164,   123,   164,   164,   468,    76,
      89,   164,   315,   116,   313,   304,   316,   116,   121,   255,
      78,   134,   490,    19,    94,   487,   316,   161,   315,   466,
      89,   298,   356,   316,   168,   336,   316,   316,   121,   316,
     125,    99,    99,   316,   468,   340,    61,   161,   315,   164,
     164,   111,   172,   413,     5,   315,   468,   172,   424,   168,
     212,   212,   212,   212,   216,   462,   163,   134,   465,   316,
     341,   466,   107,   108,   352,   353,   353,   349,    88,   346,
     345,   164,   164,   316,   316,   125,   316,   369,    42,   108,
     369,   369,   241,   247,   255,   502,   502,   366,   475,   248,
     468,   163,    99,   163,   161,   437,   438,   311,    76,   161,
     316,   115,   178,   489,   492,    19,    19,   491,   489,   243,
     497,    89,   164,    89,   164,   105,   161,    78,   466,   316,
     316,   468,   468,   339,   316,   161,   416,   468,   172,   161,
     416,   468,   316,   316,   316,   316,   316,   316,   395,   161,
     353,   466,   316,   369,   369,   176,    76,   316,   468,   316,
     438,   490,   490,   492,    19,   164,    19,   238,   486,   487,
     486,   316,   298,    59,    75,   160,   417,   416,   468,   174,
     416,    89,   164,   369,   438,   163,   497,    89,   164,   164,
      99,     3,   112,   420,   421,   423,   425,    18,   113,   418,
     419,   422,   425,   174,   416,   174,    99,   313,   163,   316,
     238,   487,   468,    75,   112,   423,   160,   113,   422,   174,
     468,   316,    89,   164,    99,   313,   468,    89,   164,    99,
     313,   468,   164,   313
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
     525,   526,   527
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   273,   274,   274,   275,   275,   275,   275,   276,   276,
     277,   277,   278,   279,   280,   280,   280,   281,   281,   282,
     282,   283,   283,   283,   283,   284,   284,   284,   284,   285,
     285,   285,   285,   285,   285,   285,   285,   286,   286,   287,
     288,   288,   289,   289,   290,   291,   292,   292,   293,   293,
     294,   294,   294,   294,   295,   296,   297,   297,   297,   297,
     298,   298,   299,   299,   300,   300,   300,   300,   301,   301,
     301,   301,   302,   302,   303,   303,   303,   303,   304,   305,
     305,   306,   307,   308,   308,   309,   309,   309,   309,   309,
     310,   310,   311,   311,   312,   313,   314,   315,   315,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   317,   318,   319,   319,   320,
     320,   320,   321,   321,   322,   322,   323,   324,   324,   324,
     325,   325,   325,   325,   325,   326,   326,   327,   327,   328,
     329,   329,   330,   330,   330,   330,   330,   330,   330,   330,
     331,   332,   333,   334,   334,   335,   335,   336,   336,   336,
     336,   337,   337,   338,   338,   338,   339,   339,   339,   340,
     340,   340,   341,   342,   343,   344,   344,   345,   345,   346,
     347,   347,   348,   348,   349,   349,   350,   350,   350,   350,
     350,   350,   350,   351,   351,   352,   352,   353,   354,   354,
     355,   355,   356,   356,   357,   357,   358,   358,   359,   359,
     360,   361,   361,   362,   362,   363,   363,   363,   363,   363,
     364,   363,   363,   363,   363,   365,   365,   365,   366,   366,
     367,   367,   367,   368,   368,   368,   368,   368,   369,   369,
     369,   370,   370,   370,   371,   371,   372,   372,   373,   373,
     374,   374,   375,   375,   376,   376,   376,   376,   377,   377,
     377,   378,   378,   378,   378,   378,   378,   379,   379,   379,
     380,   380,   380,   380,   381,   381,   382,   382,   383,   383,
     384,   384,   384,   384,   385,   386,   386,   386,   387,   387,
     388,   388,   388,   388,   389,   389,   390,   390,   390,   390,
     390,   390,   390,   391,   391,   392,   392,   393,   393,   393,
     393,   393,   394,   394,   395,   395,   396,   396,   396,   397,
     397,   398,   398,   399,   400,   400,   400,   400,   400,   400,
     400,   400,   401,   401,   402,   402,   402,   403,   404,   404,
     405,   406,   407,   408,   408,   409,   409,   410,   410,   411,
     411,   411,   412,   412,   412,   412,   412,   412,   413,   413,
     414,   414,   415,   416,   416,   417,   417,   418,   418,   419,
     419,   419,   419,   420,   420,   421,   421,   421,   421,   422,
     422,   423,   423,   424,   424,   424,   424,   425,   425,   425,
     425,   426,   426,   427,   427,   428,   429,   429,   429,   429,
     429,   429,   430,   431,   431,   431,   431,   432,   432,   432,
     432,   433,   434,   435,   435,   435,   435,   436,   436,   437,
     438,   438,   438,   439,   439,   439,   440,   440,   440,   441,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   443,
     444,   444,   444,   445,   446,   447,   447,   447,   448,   448,
     448,   448,   448,   449,   450,   450,   450,   450,   450,   450,
     450,   451,   452,   453,   454,   455,   455,   455,   456,   456,
     456,   456,   456,   456,   456,   456,   456,   456,   457,   457,
     458,   458,   459,   460,   461,   461,   462,   463,   464,   464,
     465,   465,   465,   465,   466,   467,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   469,   469,   470,   470,   470,
     470,   471,   471,   471,   471,   472,   472,   473,   473,   474,
     474,   475,   475,   476,   476,   476,   477,   477,   478,   478,
     479,   479,   479,   479,   479,   480,   481,   481,   481,   481,
     481,   481,   481,   482,   482,   482,   482,   483,   483,   483,
     483,   484,   484,   485,   485,   485,   485,   485,   485,   485,
     486,   486,   487,   487,   487,   487,   488,   488,   488,   488,
     488,   489,   489,   490,   490,   491,   491,   492,   492,   493,
     494,   494,   495,   495,   495,   496,   496,   496,   496,   496,
     497,   497,   497,   497,   498,   499,   500,   501,   501,   502,
     502,   502,   503,   503,   504
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     1,     2,     4,     6,
       2,     1,     2,     6,     2,     2,     4,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       3,     3,     5,     5,     4,     3,     3,     3,     5,     5,
       5,     5,     5,     5,     4,     3,     3,     4,     5,     6,
       1,     3,     3,     3,     3,     6,     5,     8,     6,     5,
       7,     6,     3,     3,     2,     3,     4,     5,     3,     2,
       3,     3,     5,     2,     2,     5,     5,     6,     6,     6,
       1,     3,     2,     3,     3,     3,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     2,     4,     3,     5,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     2,
       1,     4,     3,     4,     4,     5,     4,     5,     5,     6,
       3,     3,     3,     1,     4,     1,     4,     3,     4,     4,
       5,     4,     5,     1,     2,     3,     1,     2,     1,     6,
       3,     3,     1,     2,     3,     1,     3,     2,     3,     2,
       3,     4,     1,     3,     1,     2,     1,     1,     1,     2,
       2,     2,     3,     1,     1,     2,     2,     2,     5,     5,
       1,     4,     3,     4,     8,    10,     1,     2,     4,     7,
       8,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       0,     4,     3,     3,     3,     1,     3,     4,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     4,     1,     4,     1,     4,
       1,     4,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     5,     5,     3,     4,     1,     2,     3,     2,
       1,     2,     2,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     4,     4,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     4,     5,     8,     9,     9,    10,     1,     2,
       1,     2,     6,     0,     1,     3,     3,     0,     1,     1,
       1,     2,     2,     0,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     4,     4,     5,     6,     7,     4,     5,     6,
       7,     4,     4,     4,     5,     6,     7,     1,     2,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     4,     4,     3,     3,     3,     4,     4,     3,     4,
       6,     4,     6,     3,     3,     4,     6,     6,     4,     6,
       6,     4,     1,     2,     1,     3,     3,     3,     5,     7,
       7,     5,     5,     5,     7,     7,     5,     5,     3,     3,
       5,     7,     5,     7,     1,     4,     3,     5,     1,     2,
       5,     8,    11,    14,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     7,     4,     1,     2,     3,
       4,     1,     1,     2,     2,     1,     3,     1,     3,     1,
       4,     1,     2,     1,     2,     3,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     5,     7,     5,     7,     2,
       1,     3,     2,     4,     4,     6,     4,     5,     4,     5,
       3,     1,     2,     2,     3,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     1,     2,     1,
       2,     3,     3,     4,     3,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     3
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
  "\"'BOM_UTF8'\"", "FTCONTAINS_REDUCE", "RANGE_REDUCE", "ADDITIVE_REDUCE",
  "MULTIPLICATIVE_REDUCE", "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE",
  "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR", "UNARY_PREC",
  "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR", "OCCURS_PLUS", "OCCURS_HOOK",
  "STEP_REDUCE", "$accept", "Module", "ModuleWithoutBOM", "VersionDecl",
  "MainModule", "LibraryModule", "ModuleDecl", "Prolog", "SIND_DeclList",
  "VFO_DeclList", "SIND_Decl", "VFO_Decl", "Setter", "Import",
  "NamespaceDecl", "BoundarySpaceDecl", "DefaultNamespaceDecl",
  "OptionDecl", "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "DefaultCollationDecl", "BaseURIDecl",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "VarDecl", "ConstructionDecl", "FunctionSig", "Block", "BlockBody",
  "ExitExpr", "WhileExpr", "FlowCtlStatement", "FunctionDecl", "ParamList",
  "Param", "EnclosedExpr", "BracedExpr", "QueryBody", "Expr", "ExprSingle",
  "FLWORExpr", "ReturnExpr", "WindowType", "FLWORWinCondType",
  "FLWORWinCond", "WindowClause", "CountClause", "ForLetWinClause",
  "FLWORClause", "FLWORClauseList", "ForDollar", "ForClause",
  "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
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
       274,     0,    -1,   275,    -1,   258,   275,    -1,   277,    -1,
     276,   277,    -1,   278,    -1,   276,   278,    -1,   193,   194,
      19,   168,    -1,   193,   194,    19,   110,    19,   168,    -1,
     280,   314,    -1,   314,    -1,   279,   280,    -1,    46,   138,
     467,   111,   466,   168,    -1,   281,   168,    -1,   282,   168,
      -1,   281,   168,   282,   168,    -1,   283,    -1,   281,   168,
     283,    -1,   284,    -1,   282,   168,   284,    -1,   285,    -1,
     286,    -1,   287,    -1,   289,    -1,   301,    -1,   309,    -1,
     290,    -1,   291,    -1,   288,    -1,   295,    -1,   296,    -1,
     302,    -1,   292,    -1,   293,    -1,   294,    -1,   455,    -1,
     297,    -1,   300,    -1,    36,   138,   467,   111,   466,    -1,
      36,    71,   159,    -1,    36,    71,   173,    -1,    36,    94,
      32,   138,   466,    -1,    36,    94,    37,   138,   466,    -1,
      36,    47,   468,    19,    -1,    36,   223,   481,    -1,    36,
      63,   146,    -1,    36,    63,   179,    -1,    36,    94,   147,
     106,   107,    -1,    36,    94,   147,   106,   108,    -1,    36,
      68,   159,    89,   126,    -1,    36,    68,   159,    89,   143,
      -1,    36,    68,   144,    89,   126,    -1,    36,    68,   144,
      89,   143,    -1,    36,    94,    88,   466,    -1,    36,    65,
     466,    -1,    43,    49,   466,    -1,    43,    49,   299,   466,
      -1,    43,    49,   466,    78,   298,    -1,    43,    49,   299,
     466,    78,   298,    -1,   466,    -1,   298,    89,   466,    -1,
     138,   467,   111,    -1,    94,    32,   138,    -1,    43,    46,
     466,    -1,    43,    46,   138,   467,   111,   466,    -1,    43,
      46,   466,    78,   298,    -1,    43,    46,   138,   467,   111,
     466,    78,   298,    -1,    36,    93,    99,   468,   121,   316,
      -1,    36,    93,    99,   468,   116,    -1,    36,    93,    99,
     468,   437,   121,   316,    -1,    36,    93,    99,   468,   437,
     116,    -1,    36,    52,   159,    -1,    36,    52,   173,    -1,
     134,   164,    -1,   134,   310,   164,    -1,   134,   164,    76,
     438,    -1,   134,   310,   164,    76,   438,    -1,   131,   305,
     161,    -1,   315,   168,    -1,   305,   315,   168,    -1,    25,
     216,   316,    -1,    29,   134,   316,   164,   304,    -1,    26,
      27,    -1,    64,    27,    -1,    36,    37,   468,   303,   116,
      -1,    36,    37,   468,   303,   313,    -1,    36,    38,    37,
     468,   303,   116,    -1,    36,    38,    37,   468,   303,   313,
      -1,    36,    39,    37,   468,   303,   304,    -1,   311,    -1,
     310,    89,   311,    -1,    99,   468,    -1,    99,   468,   437,
      -1,   131,   315,   161,    -1,   131,   315,   161,    -1,   315,
      -1,   316,    -1,   315,    89,   316,    -1,   317,    -1,   354,
      -1,   357,    -1,   360,    -1,   361,    -1,   456,    -1,   457,
      -1,   459,    -1,   458,    -1,   460,    -1,   463,    -1,   469,
      -1,   306,    -1,   307,    -1,   308,    -1,   304,    -1,   326,
     318,    -1,   163,   316,    -1,    56,   251,    -1,    57,   251,
      -1,   196,    -1,   229,    -1,    60,   229,    -1,   320,   338,
      61,   316,    -1,   320,    61,   316,    -1,    54,   319,   337,
     321,   321,    -1,    54,   319,   337,   321,    -1,    62,    99,
     468,    -1,   328,    -1,   333,    -1,   322,    -1,   324,    -1,
     342,    -1,   347,    -1,   343,    -1,   323,    -1,   324,    -1,
     326,   325,    -1,    54,    99,    -1,    55,    54,    99,    -1,
     327,   329,    -1,   330,    -1,   329,    89,    99,   330,    -1,
     468,   125,   316,    -1,   468,   437,   125,   316,    -1,   468,
     331,   125,   316,    -1,   468,   437,   331,   125,   316,    -1,
     468,   332,   125,   316,    -1,   468,   437,   332,   125,   316,
      -1,   468,   331,   332,   125,   316,    -1,   468,   437,   331,
     332,   125,   316,    -1,    78,    99,   468,    -1,   245,    99,
     468,    -1,    51,    99,   334,    -1,   336,    -1,   334,    89,
      99,   336,    -1,   341,    -1,   335,    89,    99,   341,    -1,
     468,   121,   316,    -1,   468,   437,   121,   316,    -1,   468,
     332,   121,   316,    -1,   468,   437,   332,   121,   316,    -1,
      99,   468,   125,   316,    -1,    99,   468,   437,   125,   316,
      -1,   339,    -1,    99,   468,    -1,    99,   468,   339,    -1,
     331,    -1,   331,   340,    -1,   340,    -1,    58,    99,   468,
      59,    99,   468,    -1,    59,    99,   468,    -1,    58,    99,
     468,    -1,   468,    -1,   190,   316,    -1,   149,   148,   344,
      -1,   345,    -1,   344,    89,   345,    -1,    99,   468,    -1,
      99,   468,   346,    -1,    88,   466,    -1,   147,   148,   348,
      -1,    45,   147,   148,   348,    -1,   349,    -1,   348,    89,
     349,    -1,   316,    -1,   316,   350,    -1,   351,    -1,   352,
      -1,   353,    -1,   351,   352,    -1,   351,   353,    -1,   352,
     353,    -1,   351,   352,   353,    -1,    77,    -1,    97,    -1,
     106,   107,    -1,   106,   108,    -1,    88,   466,    -1,    44,
      99,   355,   165,   316,    -1,   114,    99,   355,   165,   316,
      -1,   356,    -1,   355,    89,    99,   356,    -1,   468,   125,
     316,    -1,   468,   437,   125,   316,    -1,    31,   134,   315,
     164,   358,    94,   163,   316,    -1,    31,   134,   315,   164,
     358,    94,    99,   468,   163,   316,    -1,   359,    -1,   358,
     359,    -1,    82,   438,   163,   316,    -1,    82,    99,   468,
      76,   438,   163,   316,    -1,    40,   134,   315,   164,   175,
     316,   105,   316,    -1,   362,    -1,   361,   145,   362,    -1,
     363,    -1,   362,    74,   363,    -1,   365,    -1,   365,   378,
     365,    -1,   365,   379,   365,    -1,   365,   111,   365,    -1,
     365,   140,   365,    -1,    -1,   365,   135,   364,   365,    -1,
     365,   133,   365,    -1,   365,   122,   365,    -1,   365,   120,
     365,    -1,   366,    -1,   366,   234,   470,    -1,   366,   234,
     470,   504,    -1,   367,    -1,   367,   176,   367,    -1,   368,
      -1,   367,   153,   368,    -1,   367,   136,   368,    -1,   369,
      -1,   368,   171,   369,    -1,   368,    98,   369,    -1,   368,
     124,   369,    -1,   368,   137,   369,    -1,   370,    -1,   369,
     178,   370,    -1,   369,   188,   370,    -1,   371,    -1,   370,
     128,   371,    -1,   370,   115,   371,    -1,   372,    -1,   372,
      69,   210,   438,    -1,   373,    -1,   373,   177,    76,   438,
      -1,   374,    -1,   374,    83,    76,   436,    -1,   375,    -1,
     375,    84,    76,   436,    -1,   377,    -1,   376,   377,    -1,
     153,    -1,   136,    -1,   376,   153,    -1,   376,   136,    -1,
     380,    -1,   384,    -1,   381,    -1,   181,    -1,   186,    -1,
     185,    -1,   184,    -1,   183,    -1,   182,    -1,   129,    -1,
     156,    -1,   119,    -1,    30,   131,   315,   161,    -1,    30,
     200,   131,   315,   161,    -1,    30,   201,   131,   315,   161,
      -1,    30,   202,   131,   315,   161,    -1,   382,   131,   161,
      -1,   382,   131,   315,   161,    -1,   383,    -1,   382,   383,
      -1,   154,   468,    14,    -1,   154,    15,    -1,   385,    -1,
     385,   386,    -1,   170,   386,    -1,   386,    -1,   169,    -1,
     387,    -1,   387,   169,   386,    -1,   387,   170,   386,    -1,
     388,    -1,   397,    -1,   389,    -1,   389,   398,    -1,   392,
      -1,   392,   398,    -1,   390,   394,    -1,   391,    -1,    87,
      -1,    95,    -1,    80,    -1,   167,    -1,    96,    -1,   118,
      -1,   117,    -1,   394,    -1,    81,   394,    -1,   393,   394,
      -1,   101,    -1,   150,    -1,    72,    -1,   158,    -1,   157,
      -1,    73,    -1,   442,    -1,   395,    -1,   468,    -1,   396,
      -1,   171,    -1,     9,    -1,    16,    -1,   400,    -1,   400,
     398,    -1,   399,    -1,   398,   399,    -1,   132,   315,   162,
      -1,   401,    -1,   403,    -1,   404,    -1,   405,    -1,   408,
      -1,   410,    -1,   406,    -1,   407,    -1,   402,    -1,   454,
      -1,    92,    -1,   127,    -1,   103,    -1,    99,   468,    -1,
     134,   164,    -1,   134,   315,   164,    -1,   100,    -1,   146,
     131,   315,   161,    -1,   179,   131,   315,   161,    -1,   468,
     134,   164,    -1,   468,   134,   409,   164,    -1,   316,    -1,
     409,    89,   316,    -1,   411,    -1,   429,    -1,   412,    -1,
     426,    -1,   427,    -1,   135,   468,   416,   109,    -1,   135,
     468,   414,   416,   109,    -1,   135,   468,   416,   174,   172,
     468,   416,   174,    -1,   135,   468,   416,   174,   413,   172,
     468,   416,   174,    -1,   135,   468,   414,   416,   174,   172,
     468,   416,   174,    -1,   135,   468,   414,   416,   174,   413,
     172,   468,   416,   174,    -1,   424,    -1,   413,   424,    -1,
     415,    -1,   414,   415,    -1,    24,   468,   416,   111,   416,
     417,    -1,    -1,    24,    -1,   160,   418,   160,    -1,    75,
     420,    75,    -1,    -1,   419,    -1,   113,    -1,   422,    -1,
     419,   113,    -1,   419,   422,    -1,    -1,   421,    -1,   112,
      -1,   423,    -1,   421,   112,    -1,   421,   423,    -1,    18,
      -1,   425,    -1,     3,    -1,   425,    -1,   411,    -1,     8,
      -1,   428,    -1,   425,    -1,     7,    -1,   102,    -1,   104,
      -1,   312,    -1,   191,    20,   192,    -1,   191,   192,    -1,
     151,    13,   152,    -1,   151,    13,     6,    -1,    85,     5,
      -1,   430,    -1,   431,    -1,   432,    -1,   433,    -1,   434,
      -1,   435,    -1,    33,   131,   315,   161,    -1,    32,   468,
     131,   161,    -1,    32,   468,   131,   315,   161,    -1,    32,
     131,   315,   161,   131,   161,    -1,    32,   131,   315,   161,
     131,   315,   161,    -1,    79,   468,   131,   161,    -1,    79,
     468,   131,   315,   161,    -1,    79,   131,   315,   161,   131,
     161,    -1,    79,   131,   315,   161,   131,   315,   161,    -1,
      34,   131,   315,   161,    -1,    35,   131,   315,   161,    -1,
      41,   467,   131,   161,    -1,    41,   467,   131,   315,   161,
      -1,    41,   131,   315,   161,   131,   161,    -1,    41,   131,
     315,   161,   131,   315,   161,    -1,   441,    -1,   441,   123,
      -1,    76,   438,    -1,   440,    -1,   440,   439,    -1,   189,
     134,   164,    -1,   123,    -1,   171,    -1,   153,    -1,   441,
      -1,   442,    -1,   130,   134,   164,    -1,   468,    -1,   444,
      -1,   450,    -1,   448,    -1,   451,    -1,   449,    -1,   447,
      -1,   446,    -1,   445,    -1,   443,    -1,   204,   134,   164,
      -1,    67,   134,   164,    -1,    67,   134,   450,   164,    -1,
      67,   134,   451,   164,    -1,    34,   134,   164,    -1,    35,
     134,   164,    -1,    41,   134,   164,    -1,    41,   134,   467,
     164,    -1,    41,   134,    19,   164,    -1,    79,   134,   164,
      -1,    79,   134,   468,   164,    -1,    79,   134,   468,    89,
     452,   164,    -1,    79,   134,   171,   164,    -1,    79,   134,
     171,    89,   452,   164,    -1,   166,   468,   164,    -1,    32,
     134,   164,    -1,    32,   134,   468,   164,    -1,    32,   134,
     468,    89,   452,   164,    -1,    32,   134,   468,    89,   453,
     164,    -1,    32,   134,   171,   164,    -1,    32,   134,   171,
      89,   452,   164,    -1,    32,   134,   171,    89,   453,   164,
      -1,    66,   134,   468,   164,    -1,   468,    -1,   468,   123,
      -1,    19,    -1,    36,   199,   200,    -1,    36,   199,   201,
      -1,    36,   199,   202,    -1,   205,   204,   316,   212,   316,
      -1,   205,   204,   316,    76,   211,   212,   316,    -1,   205,
     204,   316,    76,   213,   212,   316,    -1,   205,   204,   316,
     197,   316,    -1,   205,   204,   316,   198,   316,    -1,   205,
     206,   316,   212,   316,    -1,   205,   206,   316,    76,   211,
     212,   316,    -1,   205,   206,   316,    76,   213,   212,   316,
      -1,   205,   206,   316,   197,   316,    -1,   205,   206,   316,
     198,   316,    -1,   203,   204,   316,    -1,   203,   206,   316,
      -1,   208,   204,   316,   216,   316,    -1,   208,   209,   210,
     204,   316,   216,   316,    -1,   207,   204,   316,    76,   316,
      -1,   215,    99,   461,   214,   316,   163,   316,    -1,   462,
      -1,   461,    89,    99,   462,    -1,   468,   121,   316,    -1,
     217,   131,   316,   161,   464,    -1,   465,    -1,   464,   465,
      -1,   218,   134,   395,   164,   313,    -1,   218,   134,   395,
      89,    99,   468,   164,   313,    -1,   218,   134,   395,    89,
      99,   468,    89,    99,   468,   164,   313,    -1,   218,   134,
     395,    89,    99,   468,    89,    99,   468,    89,    99,   468,
     164,   313,    -1,    19,    -1,    17,    -1,    17,    -1,   106,
      -1,    79,    -1,    35,    -1,    67,    -1,    32,    -1,   130,
      -1,    40,    -1,   204,    -1,    41,    -1,    70,    -1,    66,
      -1,    34,    -1,    31,    -1,   189,    -1,    71,    -1,   223,
      -1,    65,    -1,   201,    -1,   200,    -1,   124,    -1,    33,
      -1,   235,    -1,   222,    -1,   225,    -1,   224,    -1,   252,
      -1,   253,    -1,   256,    -1,   254,    -1,   257,    -1,   228,
      -1,   230,    -1,    48,    -1,   196,    -1,   229,    -1,    42,
      -1,   202,    -1,   215,    -1,   209,    -1,   181,    -1,   186,
      -1,   185,    -1,   184,    -1,   183,    -1,   182,    -1,    78,
      -1,    93,    -1,   163,    -1,    54,    -1,    55,    -1,    56,
      -1,    57,    -1,    58,    -1,    59,    -1,    60,    -1,    61,
      -1,    62,    -1,   125,    -1,    51,    -1,   190,    -1,   148,
      -1,   149,    -1,   147,    -1,    45,    -1,    77,    -1,    97,
      -1,   107,    -1,   108,    -1,    88,    -1,    44,    -1,   114,
      -1,   165,    -1,    82,    -1,    76,    -1,   175,    -1,   105,
      -1,   145,    -1,    74,    -1,    69,    -1,   210,    -1,    83,
      -1,   176,    -1,    98,    -1,   137,    -1,   178,    -1,   128,
      -1,   115,    -1,    30,    -1,    84,    -1,   177,    -1,   129,
      -1,   159,    -1,   173,    -1,   138,    -1,   116,    -1,   110,
      -1,   144,    -1,   126,    -1,   143,    -1,    36,    -1,    52,
      -1,    63,    -1,    94,    -1,    68,    -1,    47,    -1,   194,
      -1,    43,    -1,    49,    -1,    37,    -1,   245,    -1,   234,
      -1,   250,    -1,   251,    -1,   227,    -1,   240,    -1,   248,
      -1,   244,    -1,   226,    -1,   239,    -1,   249,    -1,   243,
      -1,   238,    -1,   237,    -1,   221,    -1,   220,    -1,   242,
      -1,   231,    -1,   232,    -1,   255,    -1,   247,    -1,   246,
      -1,   241,    -1,   208,    -1,   214,    -1,   211,    -1,   205,
      -1,   198,    -1,   197,    -1,   199,    -1,   216,    -1,   206,
      -1,   207,    -1,   213,    -1,   203,    -1,   212,    -1,    38,
      -1,   146,    -1,   179,    -1,   219,    99,   335,    53,   131,
     316,   161,    -1,    53,   131,   316,   161,    -1,   472,    -1,
     472,   471,    -1,   472,   250,   366,    -1,   472,   471,   250,
     366,    -1,   481,    -1,   479,    -1,   471,   481,    -1,   471,
     479,    -1,   473,    -1,   472,   236,   473,    -1,   474,    -1,
     473,   233,   474,    -1,   475,    -1,   474,   235,   125,   475,
      -1,   476,    -1,   235,   476,    -1,   477,    -1,   477,   500,
      -1,   134,   470,   164,    -1,   478,    -1,   478,   496,    -1,
     401,    -1,   131,   315,   161,    -1,   480,    -1,   499,    -1,
     498,    -1,   501,    -1,   495,    -1,   146,    -1,   482,    -1,
     483,    -1,   484,    -1,   485,    -1,   488,    -1,   493,    -1,
     494,    -1,   239,    -1,   249,    -1,    82,   222,    -1,    82,
     225,    -1,   216,   224,    -1,   252,   224,    -1,   224,   222,
      -1,   224,   225,    -1,   216,   253,    -1,   252,   253,    -1,
     216,   256,   487,    -1,   216,   256,    94,    -1,   216,   256,
     134,   487,   164,    -1,   216,   256,   134,   487,    89,   486,
     164,    -1,   216,   256,   134,    94,   164,    -1,   216,   256,
     134,    94,    89,   486,   164,    -1,   252,   256,    -1,   487,
      -1,   486,    89,   487,    -1,    78,    19,    -1,    78,    19,
     243,    19,    -1,    78,    19,   497,   238,    -1,    78,    19,
     243,    19,   497,   238,    -1,   216,   254,   255,   490,    -1,
     216,   254,   255,   490,   489,    -1,   216,    94,   254,   255,
      -1,   216,    94,   254,   255,   489,    -1,   252,   254,   255,
      -1,   492,    -1,   489,   492,    -1,    78,    19,    -1,   134,
     491,   164,    -1,    19,    -1,   491,    19,    -1,   178,   490,
      -1,   115,   490,    -1,   237,    19,    -1,   216,   257,    -1,
     252,   257,    -1,    78,   196,    -1,    78,   229,    -1,   228,
     230,    -1,   221,    -1,   221,    48,    -1,   220,    -1,   220,
     255,    -1,   242,    -1,   231,   369,    -1,    78,   108,   369,
      -1,    78,    42,   369,    -1,   232,   369,   176,   369,    -1,
     227,   497,   502,    -1,   251,   369,   502,    -1,   240,   497,
     248,    -1,   244,   503,    -1,   226,   503,    -1,   255,    -1,
     247,    -1,   241,    -1,   246,    -1,   241,    -1,   252,   230,
     369,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    15,    18,    23,
      30,    33,    35,    38,    45,    48,    51,    56,    58,    62,
      64,    68,    70,    72,    74,    76,    78,    80,    82,    84,
      86,    88,    90,    92,    94,    96,    98,   100,   102,   104,
     110,   114,   118,   124,   130,   135,   139,   143,   147,   153,
     159,   165,   171,   177,   183,   188,   192,   196,   201,   207,
     214,   216,   220,   224,   228,   232,   239,   245,   254,   261,
     267,   275,   282,   286,   290,   293,   297,   302,   308,   312,
     315,   319,   323,   329,   332,   335,   341,   347,   354,   361,
     368,   370,   374,   377,   381,   385,   389,   391,   393,   397,
     399,   401,   403,   405,   407,   409,   411,   413,   415,   417,
     419,   421,   423,   425,   427,   429,   432,   435,   438,   441,
     443,   445,   448,   453,   457,   463,   468,   472,   474,   476,
     478,   480,   482,   484,   486,   488,   490,   493,   496,   500,
     503,   505,   510,   514,   519,   524,   530,   535,   541,   547,
     554,   558,   562,   566,   568,   573,   575,   580,   584,   589,
     594,   600,   605,   611,   613,   616,   620,   622,   625,   627,
     634,   638,   642,   644,   647,   651,   653,   657,   660,   664,
     667,   671,   676,   678,   682,   684,   687,   689,   691,   693,
     696,   699,   702,   706,   708,   710,   713,   716,   719,   725,
     731,   733,   738,   742,   747,   756,   767,   769,   772,   777,
     785,   794,   796,   800,   802,   806,   808,   812,   816,   820,
     824,   825,   830,   834,   838,   842,   844,   848,   853,   855,
     859,   861,   865,   869,   871,   875,   879,   883,   887,   889,
     893,   897,   899,   903,   907,   909,   914,   916,   921,   923,
     928,   930,   935,   937,   940,   942,   944,   947,   950,   952,
     954,   956,   958,   960,   962,   964,   966,   968,   970,   972,
     974,   979,   985,   991,   997,  1001,  1006,  1008,  1011,  1015,
    1018,  1020,  1023,  1026,  1028,  1030,  1032,  1036,  1040,  1042,
    1044,  1046,  1049,  1051,  1054,  1057,  1059,  1061,  1063,  1065,
    1067,  1069,  1071,  1073,  1075,  1078,  1081,  1083,  1085,  1087,
    1089,  1091,  1093,  1095,  1097,  1099,  1101,  1103,  1105,  1107,
    1109,  1112,  1114,  1117,  1121,  1123,  1125,  1127,  1129,  1131,
    1133,  1135,  1137,  1139,  1141,  1143,  1145,  1147,  1150,  1153,
    1157,  1159,  1164,  1169,  1173,  1178,  1180,  1184,  1186,  1188,
    1190,  1192,  1194,  1199,  1205,  1214,  1224,  1234,  1245,  1247,
    1250,  1252,  1255,  1262,  1263,  1265,  1269,  1273,  1274,  1276,
    1278,  1280,  1283,  1286,  1287,  1289,  1291,  1293,  1296,  1299,
    1301,  1303,  1305,  1307,  1309,  1311,  1313,  1315,  1317,  1319,
    1321,  1323,  1327,  1330,  1334,  1338,  1341,  1343,  1345,  1347,
    1349,  1351,  1353,  1358,  1363,  1369,  1376,  1384,  1389,  1395,
    1402,  1410,  1415,  1420,  1425,  1431,  1438,  1446,  1448,  1451,
    1454,  1456,  1459,  1463,  1465,  1467,  1469,  1471,  1473,  1477,
    1479,  1481,  1483,  1485,  1487,  1489,  1491,  1493,  1495,  1497,
    1501,  1505,  1510,  1515,  1519,  1523,  1527,  1532,  1537,  1541,
    1546,  1553,  1558,  1565,  1569,  1573,  1578,  1585,  1592,  1597,
    1604,  1611,  1616,  1618,  1621,  1623,  1627,  1631,  1635,  1641,
    1649,  1657,  1663,  1669,  1675,  1683,  1691,  1697,  1703,  1707,
    1711,  1717,  1725,  1731,  1739,  1741,  1746,  1750,  1756,  1758,
    1761,  1767,  1776,  1788,  1803,  1805,  1807,  1809,  1811,  1813,
    1815,  1817,  1819,  1821,  1823,  1825,  1827,  1829,  1831,  1833,
    1835,  1837,  1839,  1841,  1843,  1845,  1847,  1849,  1851,  1853,
    1855,  1857,  1859,  1861,  1863,  1865,  1867,  1869,  1871,  1873,
    1875,  1877,  1879,  1881,  1883,  1885,  1887,  1889,  1891,  1893,
    1895,  1897,  1899,  1901,  1903,  1905,  1907,  1909,  1911,  1913,
    1915,  1917,  1919,  1921,  1923,  1925,  1927,  1929,  1931,  1933,
    1935,  1937,  1939,  1941,  1943,  1945,  1947,  1949,  1951,  1953,
    1955,  1957,  1959,  1961,  1963,  1965,  1967,  1969,  1971,  1973,
    1975,  1977,  1979,  1981,  1983,  1985,  1987,  1989,  1991,  1993,
    1995,  1997,  1999,  2001,  2003,  2005,  2007,  2009,  2011,  2013,
    2015,  2017,  2019,  2021,  2023,  2025,  2027,  2029,  2031,  2033,
    2035,  2037,  2039,  2041,  2043,  2045,  2047,  2049,  2051,  2053,
    2055,  2057,  2059,  2061,  2063,  2065,  2067,  2069,  2071,  2073,
    2075,  2077,  2079,  2081,  2083,  2085,  2087,  2089,  2091,  2093,
    2095,  2097,  2099,  2101,  2103,  2105,  2113,  2118,  2120,  2123,
    2127,  2132,  2134,  2136,  2139,  2142,  2144,  2148,  2150,  2154,
    2156,  2161,  2163,  2166,  2168,  2171,  2175,  2177,  2180,  2182,
    2186,  2188,  2190,  2192,  2194,  2196,  2198,  2200,  2202,  2204,
    2206,  2208,  2210,  2212,  2214,  2216,  2219,  2222,  2225,  2228,
    2231,  2234,  2237,  2240,  2244,  2248,  2254,  2262,  2268,  2276,
    2279,  2281,  2285,  2288,  2293,  2298,  2305,  2310,  2316,  2321,
    2327,  2331,  2333,  2336,  2339,  2343,  2345,  2348,  2351,  2354,
    2357,  2360,  2363,  2366,  2369,  2372,  2374,  2377,  2379,  2382,
    2384,  2387,  2391,  2395,  2400,  2404,  2408,  2412,  2415,  2418,
    2420,  2422,  2424,  2426,  2428
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   809,   809,   810,   820,   825,   831,   836,   848,   853,
     863,   870,   882,   894,   906,   912,   918,   930,   936,   950,
     956,   970,   971,   972,   973,   979,   980,   981,   984,   991,
     992,   993,   994,   995,   996,   997,  1000,  1007,  1008,  1020,
    1032,  1037,  1048,  1054,  1066,  1079,  1090,  1095,  1107,  1112,
    1123,  1129,  1135,  1141,  1160,  1171,  1182,  1189,  1196,  1203,
    1216,  1222,  1237,  1241,  1251,  1257,  1264,  1270,  1284,  1291,
    1298,  1305,  1318,  1323,  1335,  1339,  1343,  1347,  1354,  1361,
    1367,  1376,  1383,  1390,  1394,  1401,  1409,  1418,  1427,  1436,
    1451,  1459,  1473,  1479,  1491,  1499,  1510,  1521,  1527,  1539,
    1540,  1541,  1542,  1543,  1546,  1547,  1548,  1549,  1550,  1551,
    1552,  1553,  1554,  1555,  1556,  1563,  1572,  1579,  1583,  1591,
    1595,  1599,  1606,  1610,  1617,  1622,  1631,  1640,  1641,  1642,
    1646,  1646,  1646,  1646,  1646,  1649,  1655,  1664,  1668,  1678,
    1689,  1695,  1709,  1716,  1724,  1733,  1743,  1751,  1760,  1769,
    1784,  1796,  1807,  1819,  1825,  1837,  1843,  1857,  1865,  1874,
    1882,  1894,  1900,  1910,  1911,  1915,  1923,  1927,  1932,  1936,
    1940,  1944,  1951,  1966,  1974,  1984,  1990,  2001,  2007,  2016,
    2026,  2031,  2043,  2049,  2063,  2069,  2081,  2088,  2095,  2102,
    2109,  2116,  2123,  2136,  2140,  2150,  2155,  2166,  2177,  2184,
    2197,  2204,  2216,  2222,  2235,  2242,  2256,  2262,  2274,  2280,
    2293,  2304,  2308,  2319,  2323,  2342,  2346,  2354,  2362,  2370,
    2378,  2378,  2386,  2394,  2402,  2416,  2420,  2427,  2440,  2444,
    2455,  2459,  2463,  2473,  2477,  2481,  2485,  2489,  2499,  2503,
    2508,  2519,  2523,  2527,  2537,  2541,  2553,  2557,  2569,  2573,
    2585,  2589,  2601,  2605,  2617,  2621,  2625,  2629,  2641,  2645,
    2649,  2659,  2663,  2667,  2671,  2675,  2679,  2689,  2693,  2697,
    2707,  2711,  2717,  2723,  2735,  2741,  2753,  2759,  2773,  2780,
    2821,  2825,  2829,  2833,  2845,  2855,  2866,  2871,  2881,  2885,
    2895,  2901,  2907,  2913,  2925,  2931,  2942,  2946,  2950,  2954,
    2958,  2962,  2966,  2976,  2980,  2990,  2996,  3008,  3012,  3016,
    3020,  3024,  3039,  3043,  3053,  3057,  3067,  3074,  3081,  3094,
    3098,  3110,  3116,  3130,  3141,  3145,  3149,  3153,  3157,  3161,
    3165,  3169,  3179,  3183,  3193,  3198,  3203,  3214,  3224,  3228,
    3239,  3249,  3260,  3316,  3322,  3334,  3340,  3352,  3356,  3366,
    3370,  3374,  3384,  3392,  3400,  3408,  3416,  3424,  3439,  3445,
    3457,  3463,  3476,  3485,  3487,  3493,  3498,  3510,  3513,  3520,
    3526,  3532,  3540,  3555,  3558,  3565,  3571,  3577,  3585,  3599,
    3604,  3615,  3620,  3631,  3636,  3641,  3647,  3659,  3665,  3670,
    3675,  3686,  3691,  3706,  3711,  3728,  3743,  3747,  3751,  3755,
    3759,  3763,  3773,  3784,  3790,  3796,  3801,  3823,  3829,  3835,
    3840,  3851,  3862,  3873,  3879,  3885,  3890,  3901,  3907,  3919,
    3931,  3937,  3943,  3980,  3985,  3990,  4001,  4005,  4009,  4019,
    4030,  4034,  4038,  4042,  4046,  4050,  4054,  4058,  4062,  4072,
    4082,  4086,  4091,  4102,  4112,  4122,  4126,  4130,  4140,  4146,
    4152,  4158,  4164,  4176,  4187,  4194,  4201,  4208,  4215,  4222,
    4229,  4242,  4263,  4270,  4290,  4330,  4335,  4338,  4346,  4352,
    4358,  4364,  4370,  4377,  4383,  4389,  4395,  4401,  4413,  4418,
    4428,  4434,  4446,  4472,  4483,  4489,  4502,  4516,  4523,  4530,
    4541,  4548,  4556,  4565,  4578,  4581,  4599,  4600,  4601,  4602,
    4603,  4604,  4605,  4606,  4607,  4608,  4609,  4610,  4611,  4612,
    4613,  4614,  4615,  4616,  4617,  4618,  4619,  4620,  4621,  4622,
    4623,  4624,  4625,  4626,  4627,  4628,  4629,  4630,  4631,  4632,
    4633,  4634,  4635,  4636,  4637,  4638,  4639,  4640,  4641,  4642,
    4643,  4644,  4645,  4646,  4647,  4648,  4649,  4650,  4651,  4652,
    4653,  4654,  4655,  4656,  4657,  4658,  4659,  4660,  4661,  4662,
    4663,  4664,  4665,  4666,  4667,  4668,  4669,  4670,  4671,  4672,
    4673,  4674,  4675,  4676,  4677,  4678,  4679,  4680,  4681,  4682,
    4683,  4684,  4685,  4686,  4687,  4688,  4689,  4690,  4691,  4692,
    4693,  4694,  4695,  4696,  4697,  4698,  4699,  4700,  4701,  4702,
    4703,  4704,  4705,  4706,  4707,  4708,  4709,  4710,  4711,  4712,
    4713,  4714,  4715,  4716,  4717,  4718,  4719,  4720,  4721,  4722,
    4723,  4724,  4725,  4726,  4727,  4728,  4729,  4730,  4731,  4732,
    4733,  4734,  4735,  4736,  4737,  4738,  4739,  4740,  4741,  4742,
    4743,  4744,  4745,  4746,  4747,  4758,  4764,  4781,  4785,  4789,
    4793,  4803,  4806,  4809,  4812,  4821,  4824,  4833,  4836,  4845,
    4848,  4857,  4860,  4869,  4872,  4875,  4884,  4887,  4896,  4900,
    4910,  4913,  4916,  4919,  4922,  4931,  4940,  4944,  4948,  4952,
    4956,  4960,  4964,  4974,  4977,  4980,  4983,  4992,  4995,  4998,
    5001,  5010,  5013,  5022,  5025,  5028,  5031,  5034,  5037,  5040,
    5049,  5052,  5061,  5064,  5067,  5070,  5079,  5082,  5085,  5088,
    5091,  5100,  5103,  5112,  5115,  5124,  5127,  5136,  5139,  5148,
    5157,  5160,  5169,  5172,  5175,  5184,  5187,  5190,  5193,  5196,
    5205,  5209,  5213,  5217,  5227,  5236,  5246,  5255,  5258,  5267,
    5270,  5273,  5282,  5285,  5294
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
     265,   266,   267,   268,   269,   270,   271,   272
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 7911;
  const int xquery_parser::yynnts_ = 232;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 428;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 273;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 527;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


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

