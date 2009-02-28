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
#line 804 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"

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
        case 94: /* "\"'DECIMAL'\"" */
#line 697 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 105: /* "\"'DOUBLE'\"" */
#line 696 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 129: /* "\"'INTEGER'\"" */
#line 695 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 277: /* "VersionDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 278: /* "MainModule" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 279: /* "LibraryModule" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 280: /* "ModuleDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 281: /* "Prolog" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 282: /* "SIND_DeclList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 283: /* "VFO_DeclList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 284: /* "SIND_Decl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 285: /* "VFO_Decl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "Setter" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "Import" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "NamespaceDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "BoundarySpaceDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "DefaultNamespaceDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "OptionDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "OrderingModeDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "EmptyOrderDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "CopyNamespacesDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "DefaultCollationDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "BaseURIDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "SchemaImport" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "URILiteralList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "SchemaPrefix" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "ModuleImport" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "VarDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 346 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "ConstructionDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "FunctionSig" */
#line 709 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 356 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "Block" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 361 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "BlockBody" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 366 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "AssignExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 371 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "ExitExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 376 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "WhileExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 381 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "FlowCtlStatement" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 386 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "FunctionDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 391 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "ParamList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 396 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "Param" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 401 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "EnclosedExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 406 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "BracedExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 411 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "QueryBody" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 416 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "Expr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 421 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "ExprSingle" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 426 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "FLWORExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 431 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "ReturnExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 436 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "FLWORWinCond" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 441 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "WindowClause" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 446 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "CountClause" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 451 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "ForLetWinClause" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 456 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "FLWORClauseList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 461 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "ForClause" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 466 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "VarInDeclList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 471 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "VarInDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "PositionalVar" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 481 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "LetClause" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 486 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "VarGetsDeclList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 491 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "EvalVarDeclList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 496 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "VarGetsDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 501 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "WindowVarDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 506 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "WindowVars" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 511 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "WindowVars3" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 516 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "WindowVars2" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 521 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "EvalVarDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "WhereClause" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "GroupByClause" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 536 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "GroupSpecList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "GroupSpec" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "GroupCollationSpec" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 551 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "OrderByClause" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 556 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "OrderSpecList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 561 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "OrderSpec" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 566 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "OrderModifier" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 571 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "OrderDirSpec" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 576 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "OrderEmptySpec" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 581 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "OrderCollationSpec" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 586 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "QuantifiedExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 591 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "QVarInDeclList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 596 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "QVarInDecl" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 601 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "TypeswitchExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 606 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "CaseClauseList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 611 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "CaseClause" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 616 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IfExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 621 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "OrExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 626 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "AndExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 631 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "ComparisonExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 636 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FTContainsExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 641 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "RangeExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 646 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "AdditiveExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 651 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "MultiplicativeExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 656 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "UnionExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 661 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "IntersectExceptExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 666 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "InstanceofExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 671 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "TreatExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 676 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "CastableExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 681 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "CastExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 686 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "UnaryExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 691 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "SignList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 696 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "ValueExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 701 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ValueComp" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 706 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "NodeComp" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 711 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "ValidateExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 716 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "ExtensionExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 721 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "PragmaList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 726 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "Pragma" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 731 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "PathExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 736 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "RelativePathExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 741 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "StepExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 746 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "AxisStep" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 751 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ForwardStep" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 756 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ForwardAxis" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 761 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "AbbrevForwardStep" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 766 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "ReverseStep" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 771 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ReverseAxis" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 776 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "NodeTest" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 781 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "NameTest" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 786 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "Wildcard" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 791 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FilterExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 796 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "PredicateList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 801 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "Predicate" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 806 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "PrimaryExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 811 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "Literal" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 816 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "NumericLiteral" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 821 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "VarRef" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 826 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "ParenthesizedExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 831 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ContextItemExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 836 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "OrderedExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 841 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "UnorderedExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 846 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "FunctionCall" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 851 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ArgList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 856 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "Constructor" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 861 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "DirectConstructor" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 866 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "DirElemConstructor" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 871 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "DirElemContentList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 876 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "DirAttributeList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 881 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "DirAttr" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 886 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "DirAttributeValue" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 891 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "Opt_QuoteAttrContentList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 896 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "QuoteAttrContentList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 901 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "Opt_AposAttrContentList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 906 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "AposAttrContentList" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 911 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "QuoteAttrValueContent" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 916 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "AposAttrValueContent" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 921 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "DirElemContent" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 926 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "CommonContent" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 931 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "DirCommentConstructor" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 936 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "DirPIConstructor" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 941 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "CDataSection" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 946 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "ComputedConstructor" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 951 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "CompDocConstructor" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 956 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "CompElemConstructor" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 961 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "CompAttrConstructor" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 966 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CompTextConstructor" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 971 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "CompCommentConstructor" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 976 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "CompPIConstructor" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 981 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "SingleType" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 986 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "TypeDeclaration" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 991 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "SequenceType" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 996 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OccurrenceIndicator" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1001 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "ItemType" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1006 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "AtomicType" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1011 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "KindTest" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1016 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "AnyKindTest" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1021 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "DocumentTest" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1026 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "TextTest" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1031 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "CommentTest" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1036 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "PITest" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1041 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "AttributeTest" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1046 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "SchemaAttributeTest" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1051 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "ElementTest" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1056 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SchemaElementTest" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1061 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "TypeName" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1066 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "TypeName_WITH_HOOK" */
#line 705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1071 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "StringLiteral" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1076 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "InsertExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1081 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "DeleteExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1086 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ReplaceExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1091 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "RenameExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1096 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "TransformExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1101 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "VarNameList" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1106 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "VarNameDecl" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1111 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "TryExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1116 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "CatchListExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1121 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "CatchExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1126 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "EvalExpr" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1131 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 102 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}
  /* Line 547 of yacc.c.  */
#line 1212 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
#line 822 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 4:
#line 832 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 837 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 843 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 7:
#line 848 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 8:
#line 860 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		;}
    break;

  case 9:
#line 865 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    ;}
    break;

  case 10:
#line 875 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 11:
#line 882 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		;}
    break;

  case 12:
#line 894 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 13:
#line 906 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval)));
		;}
    break;

  case 14:
#line 918 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 15:
#line 924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 16:
#line 930 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 17:
#line 942 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 18:
#line 948 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 962 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 20:
#line 968 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 39:
#line 1032 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 40:
#line 1044 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 41:
#line 1049 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 42:
#line 1060 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 43:
#line 1066 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 44:
#line 1078 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 45:
#line 1091 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		;}
    break;

  case 46:
#line 1102 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 47:
#line 1107 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 48:
#line 1119 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 49:
#line 1124 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 50:
#line 1135 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 51:
#line 1141 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 52:
#line 1147 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 53:
#line 1153 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 54:
#line 1172 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 55:
#line 1183 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 56:
#line 1194 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 57:
#line 1201 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		;}
    break;

  case 58:
#line 1208 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 59:
#line 1215 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 60:
#line 1228 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 61:
#line 1234 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 62:
#line 1249 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 63:
#line 1253 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 64:
#line 1263 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 65:
#line 1269 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		;}
    break;

  case 66:
#line 1276 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 67:
#line 1282 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		;}
    break;

  case 68:
#line 1296 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								NULL,
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 69:
#line 1303 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (4)].sval)),
								NULL,
								NULL);
		;}
    break;

  case 70:
#line 1310 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (4)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 71:
#line 1317 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (5)].node)),
								NULL);
		;}
    break;

  case 72:
#line 1330 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 73:
#line 1335 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 74:
#line 1347 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 75:
#line 1351 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 76:
#line 1355 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 77:
#line 1359 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 78:
#line 1366 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    ;}
    break;

  case 79:
#line 1373 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = new BlockBody (LOC ((yyloc)));
      blk->add ((yysemantic_stack_[(2) - (1)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 80:
#line 1379 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 81:
#line 1388 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), driver.symtab.get ((off_t)(yysemantic_stack_[(5) - (3)].sval)), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 82:
#line 1395 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 83:
#line 1402 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr)));
    ;}
    break;

  case 84:
#line 1409 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 85:
#line 1413 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 86:
#line 1420 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval))),
                &* (yysemantic_stack_[(5) - (4)].fnsig)->param, &* (yysemantic_stack_[(5) - (4)].fnsig)->ret, NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
		;}
    break;

  case 87:
#line 1428 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval))),
                &* (yysemantic_stack_[(5) - (4)].fnsig)->param, &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
								(yysemantic_stack_[(5) - (5)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
		;}
    break;

  case 88:
#line 1437 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
								&* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern_update);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 89:
#line 1446 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
                &* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_update);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 90:
#line 1455 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
                &* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 91:
#line 1470 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 92:
#line 1478 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 93:
#line 1492 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 94:
#line 1498 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 95:
#line 1510 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 96:
#line 1518 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 97:
#line 1529 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 98:
#line 1540 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = new Expr(LOC ((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 99:
#line 1546 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 117:
#line 1586 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 118:
#line 1595 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 119:
#line 1602 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    ;}
    break;

  case 120:
#line 1606 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    ;}
    break;

  case 121:
#line 1614 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    ;}
    break;

  case 122:
#line 1618 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    ;}
    break;

  case 123:
#line 1622 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    ;}
    break;

  case 124:
#line 1629 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 125:
#line 1633 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 126:
#line 1640 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)), dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 127:
#line 1645 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    ;}
    break;

  case 128:
#line 1654 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 137:
#line 1672 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 138:
#line 1678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 139:
#line 1687 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    ;}
    break;

  case 140:
#line 1691 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    ;}
    break;

  case 141:
#line 1701 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		;}
    break;

  case 142:
#line 1712 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 143:
#line 1718 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 144:
#line 1732 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 145:
#line 1739 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 146:
#line 1747 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 147:
#line 1756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 148:
#line 1766 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 149:
#line 1774 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 150:
#line 1783 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 151:
#line 1792 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 152:
#line 1807 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 153:
#line 1819 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 154:
#line 1830 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 155:
#line 1842 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 156:
#line 1848 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 157:
#line 1860 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 158:
#line 1866 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 159:
#line 1880 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 160:
#line 1888 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 161:
#line 1897 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 162:
#line 1905 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 163:
#line 1917 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 164:
#line 1923 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 166:
#line 1934 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)), "", "");
    ;}
    break;

  case 167:
#line 1938 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
    ;}
    break;

  case 168:
#line 1946 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    ;}
    break;

  case 169:
#line 1950 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    ;}
    break;

  case 171:
#line 1959 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)));
    ;}
    break;

  case 172:
#line 1963 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 173:
#line 1967 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)), "");
    ;}
    break;

  case 174:
#line 1974 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 175:
#line 1989 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 176:
#line 1997 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 177:
#line 2007 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 178:
#line 2013 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 179:
#line 2024 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 180:
#line 2030 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 181:
#line 2039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 182:
#line 2049 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 183:
#line 2054 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 184:
#line 2066 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 185:
#line 2072 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 186:
#line 2086 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 187:
#line 2092 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 188:
#line 2104 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 189:
#line 2111 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 190:
#line 2118 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 191:
#line 2125 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 192:
#line 2132 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 193:
#line 2139 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 194:
#line 2146 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 195:
#line 2159 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 196:
#line 2163 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 197:
#line 2173 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 198:
#line 2178 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 199:
#line 2189 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 200:
#line 2200 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 201:
#line 2207 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 202:
#line 2220 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 203:
#line 2227 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 204:
#line 2239 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 205:
#line 2245 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 206:
#line 2258 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 207:
#line 2265 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 208:
#line 2279 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 209:
#line 2285 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 210:
#line 2297 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 211:
#line 2303 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 212:
#line 2316 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 213:
#line 2327 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 214:
#line 2331 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 215:
#line 2342 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 216:
#line 2346 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 217:
#line 2365 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 218:
#line 2369 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 219:
#line 2377 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 220:
#line 2385 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 221:
#line 2393 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 222:
#line 2400 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 223:
#line 2401 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 224:
#line 2409 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 225:
#line 2417 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 226:
#line 2425 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 227:
#line 2439 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 228:
#line 2443 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 229:
#line 2450 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 230:
#line 2463 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 231:
#line 2467 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 232:
#line 2478 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 233:
#line 2482 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 234:
#line 2486 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 235:
#line 2496 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 236:
#line 2500 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 237:
#line 2504 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 238:
#line 2508 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 239:
#line 2512 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 240:
#line 2522 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 241:
#line 2526 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 242:
#line 2531 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 243:
#line 2542 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 244:
#line 2546 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 245:
#line 2550 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 246:
#line 2560 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 247:
#line 2564 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 248:
#line 2576 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 249:
#line 2580 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 250:
#line 2592 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 251:
#line 2596 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 252:
#line 2608 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 253:
#line 2612 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 254:
#line 2624 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 255:
#line 2628 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 256:
#line 2640 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 257:
#line 2644 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 258:
#line 2648 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 259:
#line 2652 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 260:
#line 2664 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 261:
#line 2668 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 262:
#line 2672 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 263:
#line 2682 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 264:
#line 2686 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 265:
#line 2690 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 266:
#line 2694 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 267:
#line 2698 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 268:
#line 2702 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 269:
#line 2712 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 270:
#line 2716 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 271:
#line 2720 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 272:
#line 2730 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 273:
#line 2734 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "strict",
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 274:
#line 2740 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "lax",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 275:
#line 2746 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "skip",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 276:
#line 2758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 277:
#line 2764 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 278:
#line 2776 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 279:
#line 2782 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 280:
#line 2796 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 281:
#line 2802 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 282:
#line 2844 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 283:
#line 2848 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 284:
#line 2852 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 285:
#line 2856 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 286:
#line 2868 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    ;}
    break;

  case 287:
#line 2878 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 288:
#line 2889 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 289:
#line 2894 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 290:
#line 2904 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 291:
#line 2908 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 292:
#line 2918 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 293:
#line 2924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 294:
#line 2930 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 295:
#line 2936 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 296:
#line 2948 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 297:
#line 2954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 298:
#line 2965 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 299:
#line 2969 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 300:
#line 2973 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 301:
#line 2977 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 302:
#line 2981 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 303:
#line 2985 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 304:
#line 2989 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 305:
#line 2999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 306:
#line 3003 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 307:
#line 3013 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 308:
#line 3019 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 309:
#line 3031 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 310:
#line 3035 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 311:
#line 3039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 312:
#line 3043 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 313:
#line 3047 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 314:
#line 3062 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 315:
#line 3066 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 316:
#line 3076 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 317:
#line 3080 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 318:
#line 3090 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 319:
#line 3097 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 320:
#line 3104 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 321:
#line 3117 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 322:
#line 3121 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 323:
#line 3133 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 324:
#line 3139 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 325:
#line 3153 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 326:
#line 3164 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 327:
#line 3168 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 328:
#line 3172 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 329:
#line 3176 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 330:
#line 3180 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 331:
#line 3184 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 332:
#line 3188 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 333:
#line 3192 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 334:
#line 3202 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 335:
#line 3206 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 336:
#line 3216 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 337:
#line 3221 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 338:
#line 3226 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 339:
#line 3237 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 340:
#line 3247 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 341:
#line 3251 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 342:
#line 3262 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 343:
#line 3272 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 344:
#line 3283 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 345:
#line 3339 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 346:
#line 3345 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 347:
#line 3357 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 348:
#line 3363 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 349:
#line 3375 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 3379 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 3389 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 352:
#line 3393 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 353:
#line 3397 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 354:
#line 3407 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 355:
#line 3415 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 356:
#line 3423 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 357:
#line 3431 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 358:
#line 3439 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 359:
#line 3447 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 360:
#line 3462 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 361:
#line 3468 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 362:
#line 3480 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 363:
#line 3486 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 364:
#line 3499 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 367:
#line 3516 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 368:
#line 3521 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 369:
#line 3532 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 370:
#line 3536 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 371:
#line 3543 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 372:
#line 3549 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 373:
#line 3555 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 374:
#line 3563 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 375:
#line 3577 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 376:
#line 3581 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 377:
#line 3588 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 378:
#line 3594 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 379:
#line 3600 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 380:
#line 3608 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 381:
#line 3622 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 382:
#line 3627 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 383:
#line 3638 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 384:
#line 3643 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 385:
#line 3654 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 386:
#line 3659 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 387:
#line 3664 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 388:
#line 3670 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 389:
#line 3682 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 390:
#line 3688 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 391:
#line 3693 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 392:
#line 3698 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 393:
#line 3709 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 394:
#line 3714 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 395:
#line 3729 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 396:
#line 3734 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 397:
#line 3751 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 398:
#line 3766 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 399:
#line 3770 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 400:
#line 3774 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 401:
#line 3778 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 402:
#line 3782 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 403:
#line 3786 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 404:
#line 3796 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 405:
#line 3807 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 406:
#line 3813 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 407:
#line 3819 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 408:
#line 3824 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 409:
#line 3846 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 410:
#line 3852 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 411:
#line 3858 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 412:
#line 3863 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 413:
#line 3874 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 414:
#line 3885 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 415:
#line 3896 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 416:
#line 3902 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 417:
#line 3908 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 418:
#line 3913 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 419:
#line 3924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 420:
#line 3930 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 421:
#line 3942 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 422:
#line 3954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 423:
#line 3960 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 424:
#line 3966 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 425:
#line 4003 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 426:
#line 4008 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 427:
#line 4013 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 428:
#line 4024 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 429:
#line 4028 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 430:
#line 4032 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 431:
#line 4042 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 432:
#line 4053 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 433:
#line 4057 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 434:
#line 4061 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 435:
#line 4065 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 436:
#line 4069 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 437:
#line 4073 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 438:
#line 4077 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 439:
#line 4081 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 440:
#line 4085 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 441:
#line 4095 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 442:
#line 4105 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 443:
#line 4109 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 444:
#line 4114 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 445:
#line 4125 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 446:
#line 4135 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 447:
#line 4145 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 448:
#line 4149 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 449:
#line 4153 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 450:
#line 4163 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 451:
#line 4169 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 452:
#line 4175 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 453:
#line 4181 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 454:
#line 4187 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 455:
#line 4199 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 456:
#line 4210 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		;}
    break;

  case 457:
#line 4217 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
                           NULL,
                           true);
		;}
    break;

  case 458:
#line 4224 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		;}
    break;

  case 459:
#line 4231 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		;}
    break;

  case 460:
#line 4238 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 461:
#line 4245 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		;}
    break;

  case 462:
#line 4252 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 463:
#line 4265 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 464:
#line 4286 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 465:
#line 4293 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 466:
#line 4313 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 467:
#line 4353 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 468:
#line 4358 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 469:
#line 4361 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 470:
#line 4369 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 471:
#line 4375 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 472:
#line 4381 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 473:
#line 4387 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 474:
#line 4393 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 475:
#line 4400 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 476:
#line 4406 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 477:
#line 4412 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 478:
#line 4418 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 479:
#line 4424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 480:
#line 4436 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 481:
#line 4441 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 482:
#line 4451 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 483:
#line 4457 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 484:
#line 4469 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 485:
#line 4495 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 486:
#line 4506 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 487:
#line 4512 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 488:
#line 4525 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 489:
#line 4539 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 490:
#line 4546 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 491:
#line 4553 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 492:
#line 4564 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 493:
#line 4571 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 494:
#line 4579 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 495:
#line 4588 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(14) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (9)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (12)].sval)),
                          (yysemantic_stack_[(14) - (14)].expr));
    ;}
    break;

  case 497:
#line 4604 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 498:
#line 4621 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 499:
#line 4622 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty"); ;}
    break;

  case 500:
#line 4623 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("attribute"); ;}
    break;

  case 501:
#line 4624 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("comment"); ;}
    break;

  case 502:
#line 4625 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document-node"); ;}
    break;

  case 503:
#line 4626 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("element"); ;}
    break;

  case 504:
#line 4627 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("item"); ;}
    break;

  case 505:
#line 4628 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("if"); ;}
    break;

  case 506:
#line 4629 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("node"); ;}
    break;

  case 507:
#line 4630 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("processing-instruction"); ;}
    break;

  case 508:
#line 4631 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-attribute"); ;}
    break;

  case 509:
#line 4632 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-element"); ;}
    break;

  case 510:
#line 4633 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("text"); ;}
    break;

  case 511:
#line 4634 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("typeswitch"); ;}
    break;

  case 512:
#line 4635 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty-sequence"); ;}
    break;

  case 513:
#line 4636 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("boundary-space"); ;}
    break;

  case 514:
#line 4637 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ft-option"); ;}
    break;

  case 515:
#line 4638 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("base-uri"); ;}
    break;

  case 516:
#line 4639 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lax"); ;}
    break;

  case 517:
#line 4640 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strict"); ;}
    break;

  case 518:
#line 4641 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("idiv"); ;}
    break;

  case 519:
#line 4642 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document"); ;}
    break;

  case 520:
#line 4643 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("not"); ;}
    break;

  case 521:
#line 4644 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sensitive"); ;}
    break;

  case 522:
#line 4645 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insensitive"); ;}
    break;

  case 523:
#line 4646 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("diacritics"); ;}
    break;

  case 524:
#line 4647 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("without"); ;}
    break;

  case 525:
#line 4648 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stemming"); ;}
    break;

  case 526:
#line 4649 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("thesaurus"); ;}
    break;

  case 527:
#line 4650 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stop"); ;}
    break;

  case 528:
#line 4651 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("wildcards"); ;}
    break;

  case 529:
#line 4652 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("entire"); ;}
    break;

  case 530:
#line 4653 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("content"); ;}
    break;

  case 531:
#line 4654 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("word"); ;}
    break;

  case 532:
#line 4655 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("start"); ;}
    break;

  case 533:
#line 4656 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("end"); ;}
    break;

  case 534:
#line 4657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("most"); ;}
    break;

  case 535:
#line 4658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("skip"); ;}
    break;

  case 536:
#line 4659 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy"); ;}
    break;

  case 537:
#line 4660 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("value"); ;}
    break;

  case 538:
#line 4661 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("eq"); ;}
    break;

  case 539:
#line 4662 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ne"); ;}
    break;

  case 540:
#line 4663 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lt"); ;}
    break;

  case 541:
#line 4664 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("le"); ;}
    break;

  case 542:
#line 4665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("gt"); ;}
    break;

  case 543:
#line 4666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ge"); ;}
    break;

  case 544:
#line 4667 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("at"); ;}
    break;

  case 545:
#line 4668 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("variable"); ;}
    break;

  case 546:
#line 4669 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("return"); ;}
    break;

  case 547:
#line 4670 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("for"); ;}
    break;

  case 548:
#line 4671 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("outer"); ;}
    break;

  case 549:
#line 4672 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sliding"); ;}
    break;

  case 550:
#line 4673 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("tumbling"); ;}
    break;

  case 551:
#line 4674 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("previous"); ;}
    break;

  case 552:
#line 4675 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("next"); ;}
    break;

  case 553:
#line 4676 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("only"); ;}
    break;

  case 554:
#line 4677 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("when"); ;}
    break;

  case 555:
#line 4678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("count"); ;}
    break;

  case 556:
#line 4679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("in"); ;}
    break;

  case 557:
#line 4680 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("let"); ;}
    break;

  case 558:
#line 4681 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("where"); ;}
    break;

  case 559:
#line 4682 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("by"); ;}
    break;

  case 560:
#line 4683 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("group"); ;}
    break;

  case 561:
#line 4684 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("order"); ;}
    break;

  case 562:
#line 4685 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stable"); ;}
    break;

  case 563:
#line 4686 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ascending"); ;}
    break;

  case 564:
#line 4687 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("descending"); ;}
    break;

  case 565:
#line 4688 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("greatest"); ;}
    break;

  case 566:
#line 4689 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("least"); ;}
    break;

  case 567:
#line 4690 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("collation"); ;}
    break;

  case 568:
#line 4691 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("some"); ;}
    break;

  case 569:
#line 4692 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("every"); ;}
    break;

  case 570:
#line 4693 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("satisfies"); ;}
    break;

  case 571:
#line 4694 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("case"); ;}
    break;

  case 572:
#line 4695 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("as"); ;}
    break;

  case 573:
#line 4696 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("then"); ;}
    break;

  case 574:
#line 4697 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("else"); ;}
    break;

  case 575:
#line 4698 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("or"); ;}
    break;

  case 576:
#line 4699 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("and"); ;}
    break;

  case 577:
#line 4700 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("instance"); ;}
    break;

  case 578:
#line 4701 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("of"); ;}
    break;

  case 579:
#line 4702 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("castable"); ;}
    break;

  case 580:
#line 4703 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("to"); ;}
    break;

  case 581:
#line 4704 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("div"); ;}
    break;

  case 582:
#line 4705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("mod"); ;}
    break;

  case 583:
#line 4706 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("union"); ;}
    break;

  case 584:
#line 4707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("intersect"); ;}
    break;

  case 585:
#line 4708 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("except"); ;}
    break;

  case 586:
#line 4709 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("validate"); ;}
    break;

  case 587:
#line 4710 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cast"); ;}
    break;

  case 588:
#line 4711 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("treat"); ;}
    break;

  case 589:
#line 4712 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("is"); ;}
    break;

  case 590:
#line 4713 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("preserve"); ;}
    break;

  case 591:
#line 4714 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strip"); ;}
    break;

  case 592:
#line 4715 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("namespace"); ;}
    break;

  case 593:
#line 4716 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("external"); ;}
    break;

  case 594:
#line 4717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("encoding"); ;}
    break;

  case 595:
#line 4718 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-preserve"); ;}
    break;

  case 596:
#line 4719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("inherit"); ;}
    break;

  case 597:
#line 4720 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-inherit"); ;}
    break;

  case 598:
#line 4721 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("declare"); ;}
    break;

  case 599:
#line 4722 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("construction"); ;}
    break;

  case 600:
#line 4723 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordering"); ;}
    break;

  case 601:
#line 4724 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("default"); ;}
    break;

  case 602:
#line 4725 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy-namespaces"); ;}
    break;

  case 603:
#line 4726 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("option"); ;}
    break;

  case 604:
#line 4727 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("version"); ;}
    break;

  case 605:
#line 4728 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("import"); ;}
    break;

  case 606:
#line 4729 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema"); ;}
    break;

  case 607:
#line 4730 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("module"); ;}
    break;

  case 608:
#line 4731 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("function"); ;}
    break;

  case 609:
#line 4732 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("score"); ;}
    break;

  case 610:
#line 4733 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ftcontains"); ;}
    break;

  case 611:
#line 4734 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("weight"); ;}
    break;

  case 612:
#line 4735 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("window"); ;}
    break;

  case 613:
#line 4736 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("distance"); ;}
    break;

  case 614:
#line 4737 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("occurs"); ;}
    break;

  case 615:
#line 4738 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("times"); ;}
    break;

  case 616:
#line 4739 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("same"); ;}
    break;

  case 617:
#line 4740 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("different"); ;}
    break;

  case 618:
#line 4741 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lowercase"); ;}
    break;

  case 619:
#line 4742 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("uppercase"); ;}
    break;

  case 620:
#line 4743 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("relationship"); ;}
    break;

  case 621:
#line 4744 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("levels"); ;}
    break;

  case 622:
#line 4745 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("language"); ;}
    break;

  case 623:
#line 4746 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("any"); ;}
    break;

  case 624:
#line 4747 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("all"); ;}
    break;

  case 625:
#line 4748 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("phrase"); ;}
    break;

  case 626:
#line 4749 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exactly"); ;}
    break;

  case 627:
#line 4750 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("from"); ;}
    break;

  case 628:
#line 4751 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("words"); ;}
    break;

  case 629:
#line 4752 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentences"); ;}
    break;

  case 630:
#line 4753 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentence"); ;}
    break;

  case 631:
#line 4754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("paragraph"); ;}
    break;

  case 632:
#line 4755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("replace"); ;}
    break;

  case 633:
#line 4756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("modify"); ;}
    break;

  case 634:
#line 4757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("first"); ;}
    break;

  case 635:
#line 4758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insert"); ;}
    break;

  case 636:
#line 4759 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("bofer"); ;}
    break;

  case 637:
#line 4760 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("after"); ;}
    break;

  case 638:
#line 4761 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("revalidation"); ;}
    break;

  case 639:
#line 4762 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("with"); ;}
    break;

  case 640:
#line 4763 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("nodes"); ;}
    break;

  case 641:
#line 4764 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("rename"); ;}
    break;

  case 642:
#line 4765 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("last"); ;}
    break;

  case 643:
#line 4766 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("delete"); ;}
    break;

  case 644:
#line 4767 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("into"); ;}
    break;

  case 645:
#line 4768 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("updating"); ;}
    break;

  case 646:
#line 4769 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordered"); ;}
    break;

  case 647:
#line 4770 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("unordered"); ;}
    break;

  case 648:
#line 4771 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exit"); ;}
    break;

  case 649:
#line 4772 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("loop"); ;}
    break;

  case 650:
#line 4773 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("break"); ;}
    break;

  case 651:
#line 4774 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cont"); ;}
    break;

  case 652:
#line 4775 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("set"); ;}
    break;

  case 653:
#line 4787 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 654:
#line 4793 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 655:
#line 4810 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 656:
#line 4814 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 657:
#line 4818 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 658:
#line 4822 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 659:
#line 4832 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 660:
#line 4835 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 661:
#line 4838 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 662:
#line 4841 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 663:
#line 4850 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 664:
#line 4853 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 665:
#line 4862 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 666:
#line 4865 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 667:
#line 4874 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 668:
#line 4877 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 669:
#line 4886 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 670:
#line 4889 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 671:
#line 4898 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 672:
#line 4901 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 673:
#line 4904 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 674:
#line 4913 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 675:
#line 4916 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 676:
#line 4925 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 677:
#line 4929 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, static_cast<Expr *> ((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 678:
#line 4939 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 679:
#line 4942 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 680:
#line 4945 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 681:
#line 4948 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 682:
#line 4951 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 683:
#line 4960 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 684:
#line 4969 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 685:
#line 4973 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 686:
#line 4977 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 687:
#line 4981 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 688:
#line 4985 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 689:
#line 4989 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 690:
#line 4993 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 691:
#line 5003 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 692:
#line 5006 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 693:
#line 5009 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 694:
#line 5012 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 695:
#line 5021 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 696:
#line 5024 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 697:
#line 5027 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 698:
#line 5030 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 699:
#line 5039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 700:
#line 5042 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 701:
#line 5051 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 702:
#line 5054 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 703:
#line 5057 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 704:
#line 5060 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 705:
#line 5063 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 706:
#line 5066 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 707:
#line 5069 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 708:
#line 5078 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 709:
#line 5081 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 710:
#line 5090 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 711:
#line 5093 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 712:
#line 5096 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 713:
#line 5099 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 714:
#line 5108 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 715:
#line 5111 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 716:
#line 5114 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 717:
#line 5117 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 718:
#line 5120 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 719:
#line 5129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 720:
#line 5132 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 721:
#line 5141 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 722:
#line 5144 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 723:
#line 5153 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 724:
#line 5156 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 725:
#line 5165 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 726:
#line 5168 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 727:
#line 5177 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 728:
#line 5186 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 729:
#line 5189 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 730:
#line 5198 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 731:
#line 5201 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 732:
#line 5204 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 733:
#line 5213 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 734:
#line 5216 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 735:
#line 5219 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 736:
#line 5222 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 737:
#line 5225 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 738:
#line 5234 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 739:
#line 5238 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 740:
#line 5242 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 741:
#line 5246 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 742:
#line 5256 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 743:
#line 5265 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 744:
#line 5275 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 745:
#line 5284 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 746:
#line 5287 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 747:
#line 5296 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 748:
#line 5299 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 749:
#line 5302 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 750:
#line 5311 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 751:
#line 5314 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 752:
#line 5323 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6521 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -942;
  const short int
  xquery_parser::yypact_[] =
  {
      1251,  -942,  -942,  -942,  -942,  -116,   101,  -942,    88,   356,
     134,  6218,   267,   316,   508,    52,  -942,  -942,   193,    47,
    -942,   610,   203,  -942,   208,  -942,  -942,  -942,   361,   426,
    -942,   340,    54,   510,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,   512,  -942,   447,   479,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  6459,  -942,  5485,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  7664,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
     478,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  4240,  1501,  7664,  -942,  -942,  -942,  -942,  -942,
    -942,   498,  -942,  -942,  -942,  -942,   623,  -942,  5977,  -942,
    -942,  -942,  -942,  -942,  7664,  -942,  -942,  5236,  -942,  -942,
    -942,  -942,  -942,  -942,   515,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,    14,   482,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,    73,   525,   467,  -942,   451,   286,  -942,
    -942,  -942,  -942,  -942,  -942,   563,  -942,   553,   588,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  1750,   700,  -942,  4489,  -942,
    -942,    86,  4240,   537,   546,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
     626,  -942,  -942,  -942,  -942,   400,  7664,  -942,  -942,  -942,
    -942,  -942,   572,   642,  -942,   566,   486,   415,   294,   111,
      -9,  -942,   651,   544,   640,   641,  4738,  -942,  -942,  -942,
     304,  -942,  -942,  5236,  -942,   330,  -942,   594,  5485,  -942,
     594,  5485,  -942,  -942,  -942,  -942,   594,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,   593,  -942,  4240,  -942,  4240,
    4240,   597,   598,   599,  4240,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  4240,  6700,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,   601,  4240,
    4240,   569,  4240,   573,  7664,   702,   703,  7664,   148,   -41,
     722,   414,   250,   643,   279,   725,   466,    58,  4240,  -942,
    4240,    46,   612,    89,   144,  7664,   725,  7664,  7664,  4240,
     494,   495,  -942,   653,   654,  -942,  7664,    18,  4240,  6941,
     624,   620,   622,   625,   627,   628,  -942,  -942,  -942,  7664,
    1999,   -39,  -942,   -16,   734,  4240,    48,  -942,   745,   596,
    -942,  4240,   574,  -942,   746,  4240,  4240,   602,  4240,  4240,
    4240,  4240,   554,  7664,  4240,  7664,  -942,  -942,  -942,  -942,
      52,   610,  -942,  -942,    86,   732,  4240,   621,   426,    54,
     510,   670,   629,   630,  4240,  4240,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,   681,  -942,   -38,  4987,  4987,  4987,  -942,
    4987,  4987,  -942,  4987,  -942,  4987,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  4987,  4987,    10,  4987,  4987,  4987,  4987,
    4987,  4987,  4987,  4987,  4987,  4987,  4987,   565,   699,   704,
     705,  -942,  -942,  -942,  2248,  -942,  -942,  5236,  5236,  4240,
     594,  -942,  -942,   594,  -942,   594,  2497,  -942,   615,    -4,
    4240,  4240,  4240,   -10,   159,  -942,    -3,     8,  2746,   165,
     171,  -942,   188,  -942,   648,  7664,  7664,   758,  -942,  -942,
    -942,  -942,  -942,  -942,   694,   695,  -942,  -942,  7664,   649,
     650,   722,   680,   678,  -942,  -942,  -942,   439,   190,   440,
     772,  -942,  -942,   347,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,    43,   196,   632,  -942,   633,  2995,   725,   713,
     761,   725,   722,   715,   -23,  -942,     1,   683,   674,   709,
    -942,   -46,   638,  -942,  -942,  7664,   -19,  -942,   636,   620,
     447,  -942,   637,   639,   227,  -942,    77,   122,  3244,   -13,
    -942,   -18,  -942,  -942,  7664,   734,  -942,   -31,   228,  -942,
    -942,  -942,  -942,   239,  -942,   280,  -942,  -942,  -942,     7,
      38,   726,   589,   603,    20,  -942,   687,   655,    69,  -942,
    -942,   644,  -942,    23,  -942,  -942,   661,  7664,  4240,   711,
    -942,  -942,   716,  7423,   718,  4240,   719,   -60,   696,   -32,
     642,  -942,  -942,  -942,  -942,  -942,  4987,  -942,  -942,  -942,
    4240,    10,   438,  -942,   568,   189,   591,   586,  -942,  -942,
     587,   385,   294,   294,   -28,   111,   111,   111,   111,    -9,
      -9,  -942,  -942,  7423,  7423,  7664,  7664,  -942,   244,  -942,
    -942,   -15,  -942,  -942,  -942,   150,   701,  -942,   249,   256,
     296,   743,   706,  7664,  -942,  7664,  -942,  -942,   302,  -942,
    -942,  -942,   231,   459,   648,   648,  -942,   384,   410,   458,
     722,   722,  -942,   571,   722,  -942,  -942,   581,  -942,  -942,
     582,   398,  -942,  -942,  -942,  -942,  -942,  -942,   585,  -942,
    -942,   660,   707,  -942,  -942,  -942,   318,   729,   722,   708,
     730,   764,   722,   744,  4240,  4240,   720,   722,  4240,   748,
    4240,   723,   -64,  -942,   175,   634,  -942,  -942,   443,   -19,
    -942,  -942,  -942,   717,  7664,  -942,  7664,  -942,  -942,   319,
    4240,  -942,   826,  -942,   262,  -942,    85,  -942,  -942,   832,
    -942,   461,  4240,  4240,  4240,   464,  4240,  4240,  4240,  4240,
    4240,  4240,   752,  4240,  4240,   646,   724,   754,   732,  4240,
    -942,   518,   767,  -942,  7664,   768,  -942,  7664,   727,   731,
    -942,   373,  -942,  -942,  -942,  7664,  -942,  7664,  4240,   733,
    4240,  4240,   -29,   735,  -942,   344,   710,  -942,   635,  -942,
      96,  -942,   387,    -6,   647,    10,   387,  4987,  4987,   371,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,    10,   742,    -6,
    -942,   605,   822,  -942,  -942,  -942,  -942,  -942,   749,  -942,
    -942,  -942,  4240,  -942,  -942,  -942,  -942,  -942,  7182,   534,
    -942,  3493,   714,   736,   750,   737,   738,  -942,  7664,   795,
     154,  -942,  -942,  4240,  -942,   492,   701,  -942,  -942,  -942,
    -942,  -942,  4240,   520,  -942,  -942,  -942,  -942,  -942,   645,
     343,   859,  -942,   484,  -942,  -942,  4240,  3742,  -942,   722,
     790,  -942,  -942,  -942,   722,   790,  7664,  -942,  -942,  4240,
     712,  -942,  7664,  -942,  4240,  4240,   760,  4240,   757,  -942,
     784,   785,  4240,  7664,   631,   825,  -942,  -942,  -942,  3991,
     739,  -942,   740,  -942,  -942,  -942,   776,  -942,   157,  -942,
    -942,   884,  -942,  -942,  4240,  7664,  -942,  -942,   162,  -942,
    -942,  -942,   721,   682,   684,  -942,  -942,  -942,   685,   686,
    -942,  -942,  -942,  -942,  -942,   676,  7664,   747,  -942,   771,
     646,  -942,  4240,  7664,   767,  -942,   722,  -942,   584,  -942,
     380,   806,  -942,  4240,   810,   711,  -942,   751,   753,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  4240,  -942,  -942,  4240,
     781,  4240,  -942,  -942,  4987,  -942,  -942,  -942,  -942,  -942,
      59,  4987,  4987,   397,  -942,   591,  -942,  -942,   -75,  4987,
    -942,  -942,   586,    10,   662,  -942,  -942,  -942,  -942,  7664,
     755,   141,  -942,  -942,   345,  -942,  -942,  -942,  -942,  -942,
     831,  7423,   809,   835,   370,  -942,  -942,  -942,  -942,  -942,
    4240,   164,   894,   895,   164,   -34,   167,   173,   811,  -942,
     372,   836,   722,   790,  -942,  -942,  -942,  -942,  -942,  -942,
    4240,  -942,  4240,  7664,  7664,  -942,   552,  -942,  4240,  -942,
     389,  -942,  -942,   826,  7664,   168,  -942,   393,   826,  7664,
    -942,  -942,  4240,  4240,  4240,  4240,  4240,  -942,  4240,  5734,
    -942,   759,  -942,  -942,  -942,  -942,   806,  -942,  -942,  -942,
     722,  -942,  -942,  -942,  -942,  -942,  -942,  4240,  -942,   111,
    4987,  4987,   111,   469,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,   843,  4240,  7664,  4240,  -942,  -942,  -942,  -942,
    7423,  -942,  -942,   343,   343,   164,  -942,  -942,  -942,    24,
     164,   903,   688,   846,  -942,   846,  -942,  4240,  -942,   722,
    -942,  -942,  -942,   867,  -942,  -942,  -942,  -942,    -5,   826,
    7664,  -942,   756,   826,  -942,  -942,  -942,  -942,  -942,  -942,
     180,  -942,  -942,  -942,  -942,   111,   111,  4987,  7423,  -942,
     765,  -942,  -942,  -942,  -942,  -942,  -942,  -942,    -6,  -942,
     191,  -942,   201,  -942,   790,   828,   299,   246,  -942,   762,
     826,  -942,   769,   833,   800,   111,   770,  4240,   697,   846,
    -942,  -942,  7664,  -942,  -942,   860,   362,  -942,  -942,  -942,
    -942,   778,   435,  -942,  -942,  -942,   773,  -942,  7664,  -942,
    4240,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,   206,  -942,   840,   800,  7664,  -942,   223,   842,
     800,  7664,  -942,   780,   800,  -942
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   319,   320,   498,   466,   648,   650,   649,     0,   586,
     511,   503,   519,   510,   501,   598,   608,   645,   505,   507,
     534,   605,   568,   562,   607,   603,   531,   606,   652,   557,
     599,     0,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   600,   651,   515,   509,   502,   602,   577,   508,   513,
     310,   313,   576,   572,   563,   544,   500,   300,     0,   571,
     579,   587,   298,   567,   336,   545,   601,   299,   302,   564,
     581,     0,   342,   308,   338,   574,   499,   565,   566,   594,
     569,   585,   593,   304,   303,   518,   556,   596,   337,   584,
     589,   504,     0,     0,     0,   257,   582,   592,   597,   595,
     575,   646,   561,   559,   560,   309,     0,   256,     0,   312,
     311,   590,   546,   570,     0,   301,   286,     0,   318,   591,
     573,   580,   588,   583,   647,   538,   543,   542,   541,   540,
     539,   512,   558,     0,     0,   604,   532,   637,   636,   638,
     517,   516,   535,   643,   506,   635,   640,   641,   632,   537,
     578,   634,   644,   642,   633,   536,   639,     0,     0,   624,
     623,   521,   514,   523,   522,   617,   613,   529,   533,   530,
     626,   627,   610,   520,   622,   621,   618,   614,   631,   625,
     620,   616,   609,   630,   629,   615,   619,   611,   612,   524,
     525,   527,   628,   526,   528,     0,     0,     2,     0,     4,
       6,     0,     0,     0,     0,    17,    19,    21,    22,    23,
      29,    24,    27,    28,    33,    34,    35,    30,    31,    37,
      38,    25,    32,   116,   115,   112,   113,   114,    26,    11,
      97,    98,   100,   131,   137,     0,     0,   129,   130,   101,
     102,   103,   104,   213,   215,   217,   227,   230,   232,   235,
     240,   243,   246,   248,   250,   252,     0,   254,   260,   262,
       0,   278,   261,   282,   285,   287,   290,   292,     0,   297,
     294,     0,   305,   315,   317,   291,   321,   326,   334,   327,
     328,   329,   332,   333,   330,   331,   349,   351,   352,   353,
     350,   398,   399,   400,   401,   402,   403,   314,   440,   432,
     439,   438,   437,   434,   436,   433,   435,   335,    36,   105,
     106,   108,   107,   109,   110,   316,   111,     0,    84,     0,
       0,     0,     0,     0,     0,   648,   650,   586,   511,   503,
     519,   510,   501,   598,   505,   507,   605,   568,   607,   652,
     557,   547,   548,   651,   509,   502,   500,   569,     0,     0,
     646,   647,   643,   506,   635,   641,   632,   536,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   497,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   139,     0,     0,    85,     0,     0,     0,     0,
       0,   503,   510,   501,   507,   500,   306,   316,   339,     0,
       0,     0,   340,     0,   365,     0,     0,   281,     0,     0,
     284,     0,     0,   394,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     1,     5,     7,
       0,     0,    12,    10,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,   136,   132,   138,
     133,   135,   134,   141,   142,     0,     0,     0,     0,   271,
       0,     0,   269,     0,   222,     0,   270,   263,   268,   267,
     266,   265,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,   258,   255,     0,   279,   283,     0,     0,     0,
     293,   323,   296,   295,   307,   322,     0,    82,     0,     0,
       0,     0,     0,     0,     0,   456,     0,     0,     0,     0,
       0,   445,     0,   446,     0,     0,     0,     0,    72,    73,
      46,    47,   496,    55,     0,     0,    40,    41,     0,     0,
       0,     0,     0,     0,   467,   468,   469,     0,     0,     0,
       0,   691,   692,     0,    45,   684,   685,   686,   687,   688,
     689,   690,     0,     0,     0,   447,     0,     0,     0,    64,
       0,     0,     0,    56,     0,   202,     0,     0,     0,   154,
     155,     0,     0,   119,   120,     0,     0,   140,     0,     0,
       0,   442,     0,     0,     0,   450,     0,     0,     0,     0,
      78,     0,    79,   341,   366,   365,   362,     0,     0,   396,
     395,   280,   455,     0,   393,     0,   480,   481,   441,     0,
       0,     0,     0,     0,     0,   486,     0,     0,     0,   157,
     174,     0,    18,     0,    20,    99,     0,     0,     0,     0,
     118,   175,     0,     0,     0,     0,     0,     0,     0,     0,
     214,   216,   220,   226,   225,   224,     0,   221,   218,   219,
       0,     0,     0,   676,   228,   655,   663,   665,   667,   669,
     671,   674,   234,   233,   231,   237,   238,   239,   236,   241,
     242,   245,   244,     0,     0,     0,     0,   276,     0,   288,
     289,     0,   324,   345,   347,     0,     0,   272,     0,     0,
       0,     0,     0,     0,   460,     0,   457,   405,     0,   404,
     413,   414,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,    54,     0,     0,   693,   694,     0,   695,   699,
       0,     0,   728,   697,   698,   727,   696,   700,     0,   707,
     729,     0,     0,   449,   448,   415,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   654,     0,     0,   121,   122,     0,   127,
     463,   443,   444,     0,     0,   453,     0,   451,   409,     0,
       0,    80,   365,   363,     0,   354,     0,   343,   344,     0,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
     128,   186,   182,   184,     0,   176,   177,     0,   504,   512,
     421,   422,   428,   429,   431,     0,   144,     0,     0,     0,
       0,     0,     0,     0,   223,     0,     0,   670,     0,   229,
       0,   683,     0,     0,     0,     0,     0,     0,     0,   656,
     660,   678,   659,   682,   680,   679,   681,     0,     0,     0,
     672,   735,   733,   737,   675,   247,   249,   251,   419,   253,
     277,   325,     0,   346,    83,   273,   274,   275,     0,     0,
     208,     0,     0,     0,   464,     0,     0,   406,     0,    74,
       0,    91,    86,     0,    87,     0,     0,    52,    53,    50,
      51,    69,     0,     0,    42,    43,    48,    49,    39,     0,
       0,     0,   702,     0,   701,   718,     0,     0,   416,     0,
      66,    60,    63,    62,     0,    58,     0,   200,   204,     0,
       0,    81,     0,   159,     0,     0,     0,     0,     0,   123,
       0,     0,     0,     0,   168,     0,   165,   170,   126,     0,
       0,   464,     0,   410,   201,   366,     0,   355,     0,   389,
     386,     0,   390,   391,     0,     0,   392,   385,     0,   360,
     388,   387,     0,     0,     0,   473,   474,   470,     0,     0,
     478,   479,   475,   484,   482,     0,     0,     0,   488,     0,
     489,   490,     0,     0,   183,   195,     0,   196,     0,   187,
     188,   189,   190,     0,   179,     0,   143,     0,     0,   425,
     427,   426,   423,   152,   153,   146,     0,   148,   145,     0,
       0,     0,   677,   673,     0,   730,   731,   751,   750,   746,
       0,     0,     0,     0,   732,   664,   745,   657,     0,     0,
     662,   661,   666,     0,     0,   736,   734,   420,   348,     0,
       0,     0,   209,   407,     0,   461,   462,   465,   458,   459,
      93,     0,     0,    75,     0,    88,    89,    90,    68,    71,
       0,   716,     0,     0,   714,   710,     0,     0,     0,   417,
       0,    65,     0,    59,   203,   205,    13,   156,   161,   160,
       0,   163,     0,     0,     0,   125,   166,   169,     0,   411,
       0,   454,   452,   365,     0,     0,   397,     0,   365,     0,
     361,     9,     0,     0,     0,     0,     0,   487,     0,     0,
     491,     0,   158,   199,   197,   198,   191,   192,   193,   185,
       0,   180,   178,   430,   424,   150,   147,     0,   149,   752,
       0,     0,   738,     0,   749,   748,   747,   742,   743,   658,
     668,   744,     0,     0,     0,     0,   408,    94,    76,    92,
       0,    96,    70,     0,     0,   717,   719,   721,   723,     0,
     715,     0,     0,     0,   705,     0,   703,     0,   418,     0,
      61,   162,   164,   173,   172,   167,   124,   412,     0,   365,
       0,    95,     0,   365,   471,   472,   476,   477,   483,   485,
       0,   653,   194,   181,   151,   740,   739,     0,     0,   210,
       0,   206,    77,   726,   725,   720,   724,   722,   711,   712,
       0,   708,     0,   212,    67,     0,   375,   369,   364,     0,
     365,   356,     0,     0,     0,   741,     0,     0,     0,     0,
     706,   704,     0,   383,   377,     0,   376,   378,   384,   381,
     371,     0,   370,   372,   382,   358,     0,   357,     0,   492,
       0,   207,   713,   709,   171,   368,   379,   380,   367,   373,
     374,   359,     0,   211,     0,     0,     0,   493,     0,     0,
       0,     0,   494,     0,     0,   495
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -942,  -942,   763,  -942,   774,   775,  -942,   766,  -942,   500,
     503,  -437,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -759,  -942,  -942,  -942,  -942,
     -26,  -678,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -124,
    -942,  -886,   777,   -35,  -293,  -942,  -942,  -942,  -942,   172,
    -942,  -942,   728,  -942,  -942,  -942,  -942,  -942,   123,  -440,
    -575,  -942,  -942,  -942,    11,  -942,  -942,  -154,     2,   -48,
    -942,  -942,  -942,   -58,  -942,  -942,   140,   -53,  -942,  -942,
     -49,  -941,  -942,   556,    26,  -942,  -942,    79,  -942,  -942,
     504,   499,  -942,  -434,  -828,   481,   209,  -480,   212,   215,
    -942,  -942,  -942,  -942,  -942,   741,  -942,  -942,  -942,  -942,
    -942,   779,  -942,  -942,  -112,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,   -37,  -158,  -942,  -942,  -150,    72,  -942,  -484,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -774,
    -942,     6,  -942,   360,  -613,  -942,  -942,  -942,  -942,  -942,
    -286,  -278,  -922,  -642,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,   284,  -571,  -687,  -942,  -942,    17,
    -640,  -942,  -942,  -942,  -942,  -942,  -942,  -942,   590,   592,
    -294,   266,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
     -14,  -942,  -942,   -17,  -366,  -348,   -11,  -942,   313,  -942,
    -942,   131,   121,   -63,   321,  -942,  -942,   132,  -942,  -644,
    -942,  -942,  -942,  -942,  -191,  -727,  -942,   -89,  -459,  -942,
    -525,  -942,  -942,  -942,  -942,  -846,  -942,  -942,  -942,  -942,
     -52,   142,  -942
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   930,   582,   220,   221,   222,
     723,   223,   410,   224,   225,   226,   227,   228,   900,   901,
     976,   904,   229,   230,   231,   232,   456,   393,   778,   779,
     233,   457,   234,   459,   235,   236,   237,   463,   464,   954,
     658,   238,   589,   638,   590,   596,   955,   956,   957,   639,
     460,   461,   825,   826,  1141,   462,   822,   823,  1009,  1010,
    1011,  1012,   239,   584,   585,   240,   889,   890,   241,   242,
     243,   244,   666,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   483,   484,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   510,   511,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   705,   285,   286,
     287,   978,   615,   616,   617,  1238,  1261,  1262,  1255,  1256,
    1263,  1257,   979,   980,   288,   289,   981,   290,   291,   292,
     293,   294,   295,   296,   877,   659,   830,  1022,   831,   832,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     892,   893,   307,   308,   309,   310,   311,   312,   313,   634,
     635,   314,  1000,  1001,   931,   382,   315,   316,   674,   859,
     675,   676,   677,   678,   679,   680,   681,   860,   861,   564,
     565,   566,   567,   568,  1230,  1231,   569,  1175,  1084,  1179,
    1176,   570,   571,   863,   874,  1043,   864,   865,   870,   866,
    1157,  1039,   849
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       358,   673,   794,   935,   543,   420,   875,   876,   644,   685,
     686,   687,   688,   833,   924,   766,   771,   579,   583,  1076,
     772,   406,   977,  1054,   517,   657,   518,   553,   884,  1047,
       4,   862,   653,   576,   662,   422,   663,   664,   587,   665,
     653,   667,   654,   775,  1226,   400,  1040,   407,   654,   668,
     669,   599,   446,   833,   833,   619,  1120,   411,   413,   945,
     408,   364,   365,   366,   379,   379,   574,   838,   763,  1137,
    1138,   367,  1236,   446,  1040,   446,   446,   770,   763,   653,
     795,   446,   839,   414,   843,   801,   600,   446,   713,   655,
     364,   365,   366,   969,   970,   841,   592,   418,  1029,   715,
     367,   317,  1150,   419,    64,   493,   368,   540,   495,   542,
     486,   812,   390,   391,   494,    74,   805,   369,   373,   370,
     513,   496,   371,   440,   816,   372,   515,   487,   765,   318,
     441,   612,   626,   627,   446,   629,   630,   631,   632,    88,
     541,   637,   557,   670,   764,   796,   671,   373,   374,   881,
     613,   506,   791,   645,   790,   392,   711,  1237,   913,   707,
     817,   650,   651,   714,   542,   969,   970,  1154,   784,  1151,
     969,   970,   971,  1155,   716,  1093,   969,   970,   776,   966,
     380,  1156,   656,   381,   601,   732,   656,   673,   673,   972,
    1227,   973,   375,  1120,   977,  1212,  1087,   946,  1041,  1042,
     656,  1060,   620,   948,   977,   802,   803,   423,   656,   751,
    1181,   777,   575,   786,   656,  1051,   761,   656,   974,   842,
     804,  1159,    94,   704,   319,   465,  1041,  1042,  1077,   578,
     757,   512,   844,   760,   514,   813,   806,   807,   106,  1182,
     580,   882,  1164,   785,   971,  1072,   672,   377,   833,   971,
     446,   808,   376,   653,   969,   971,   446,   407,  1183,   975,
     407,   972,   446,   973,  1185,  1259,   972,  1030,   973,   850,
     324,  1243,   972,   557,   973,   558,   377,   133,   425,   446,
     426,  1173,  1249,   559,   581,   519,   737,   446,   787,   523,
     974,   493,  1249,  1035,    94,   974,   560,  1284,   561,    94,
     494,   974,   947,  1253,   385,    94,  1165,   969,   562,   538,
     106,   563,   549,   524,  1289,   106,   883,   550,   446,   446,
    1073,   106,   712,   539,   529,   530,  1036,   532,   719,   378,
     446,  1114,   898,  1184,   720,   446,  1119,   851,   527,  1186,
     446,   977,  1200,   572,  1174,   573,  1244,   446,   386,   133,
     972,   721,   973,   534,   133,   821,   537,  1250,  1269,   752,
     133,  1260,   836,   604,   914,   915,  1253,  1251,   918,   551,
     969,   673,  1285,   967,   586,   611,   588,   591,  1048,   974,
     618,   644,  1248,   673,  1168,   598,   623,   446,   607,  1290,
     783,   797,   799,   446,   489,   699,   700,   899,   586,  1287,
     359,   940,   798,   972,  1292,   973,   558,   880,  1295,   446,
     446,   546,   885,  1254,   559,   738,   852,   853,   854,   886,
     490,   895,   636,  1082,   640,   547,   855,   560,   552,   561,
    1234,   833,   974,   491,   856,   446,   446,   504,   968,   562,
     857,   858,   563,   969,   739,   740,   447,   741,   742,   360,
     800,   850,   361,   448,  1259,   557,   449,   450,     4,   887,
     108,   446,   387,   446,   451,   897,   972,   492,   973,   698,
    1006,   937,   938,   389,   701,   941,  1276,   943,   921,  1083,
     446,   928,   963,  1222,   446,   708,   709,   710,  1008,   320,
     960,   431,   962,   718,   922,   974,   432,   964,  1019,  1167,
    1198,   507,   508,   950,   951,  1202,   952,  1032,  1166,   985,
     986,   987,   907,   990,   991,   992,   993,   994,   995,   851,
     997,   998,  1273,   654,   724,   725,   821,   388,  1020,   908,
     833,  1246,    64,  1171,   923,  1188,   653,   729,   909,   972,
     395,   973,   756,    74,   953,  1025,  1021,  1027,  1028,   452,
    1279,   453,  1197,   486,  1149,   910,  1201,   321,   322,   323,
     544,  1152,  1153,  1091,   921,   454,   394,    88,   974,   673,
     487,   670,   746,   789,   671,   545,   911,   902,   833,   409,
    1086,   912,   702,   396,   774,   702,  1239,   702,   558,  1058,
    1242,   455,   903,   488,  1258,  1264,   559,  1005,   852,   853,
     854,   747,   748,   792,   749,   750,   871,   872,  1006,   560,
    1075,   561,   950,   951,  1258,   397,   856,  1007,   888,  1078,
    1264,   562,  1049,   858,   563,   903,  1008,  1266,   873,  1037,
    1061,   415,   654,  1088,  1038,   845,   820,   416,  1079,  1154,
    1133,   362,   834,  1080,   363,  1155,  1095,  1217,   421,   493,
    1225,  1098,  1099,  1156,  1101,  1225,   430,   383,   494,  1105,
     384,   427,   735,   743,   433,   736,   744,   554,   555,   556,
    1215,  1216,   428,   983,   429,   984,   988,   424,   989,   468,
     916,   917,   834,   834,   834,   834,   434,   469,   470,   435,
     471,   950,   951,  1134,  1135,   682,   683,   472,   905,   906,
     437,   473,   894,   474,   894,   689,   690,   444,   475,  1131,
     691,   692,   878,   878,  1223,  1224,   445,   446,   467,   466,
     821,   485,   497,   498,   476,   499,  1190,   500,   509,   516,
     520,   521,   522,  1145,   528,   531,  1146,  1245,  1148,   533,
     535,   536,   542,   379,   548,   577,   593,   594,   477,   478,
     479,   480,   481,   482,   595,   597,   349,   608,   361,   614,
     621,   363,   622,   381,   399,   633,   625,   624,   628,   643,
     646,   647,   652,   961,  1213,   961,   693,   694,   726,   648,
     649,   706,   695,   696,   722,   727,   728,  1172,   733,   730,
     731,   734,   745,   758,   759,   762,   767,   768,   753,   754,
     769,   773,   780,   781,   809,   782,   810,  1191,   811,  1192,
     814,   819,   824,  1014,   818,  1196,   465,   827,   815,   835,
     837,   848,   868,   840,  1023,   867,  1024,   888,   869,  1204,
    1205,  1206,  1207,  1208,    92,  1209,   919,   926,   920,   891,
     927,   925,   929,   933,   934,   936,   944,   939,   932,   942,
     959,   965,   982,   996,  1214,  1003,  1064,  1002,  1013,  1015,
    1026,  1055,  1031,  1017,   949,   999,  1034,  1018,  1074,  1053,
    1219,  1056,  1221,  1071,  1057,  1067,  1033,   834,  1044,  1085,
    1065,  1092,  1096,  1100,  1102,  1103,  1104,  1070,  1108,  1113,
    1116,  1121,  1090,  1126,  1233,  1122,  1006,  1123,  1124,  1125,
    1140,  1081,  1066,  1068,  1069,  1111,  1112,  1129,  1147,   653,
     898,  1161,  1128,  1170,  1177,  1178,  1189,  1143,  1187,  1144,
    1163,  1218,  1211,  1228,  1110,   586,   921,  1229,  1235,  1252,
    1247,   591,  1241,   903,  1268,  1270,  1272,  1275,  1265,  1117,
    1278,  1286,  1106,  1291,   641,  1267,  1294,   642,  1169,  1281,
    1016,   958,  1195,  1097,  1271,  1132,  1107,  1142,   436,  1004,
    1139,  1136,  1094,   458,  1118,   609,   661,   442,  1062,   684,
     660,  1210,   438,   439,  1115,   793,  1280,  1283,  1277,   443,
     879,   896,  1127,  1130,   846,   636,  1045,   602,  1052,   603,
    1160,  1050,   640,   847,  1232,  1180,  1158,   503,  1046,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,     0,     0,  1162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     834,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1193,  1194,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1199,     0,     0,     0,     0,  1203,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   407,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1220,     0,     0,     0,     0,     0,   834,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1240,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   834,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1274,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1282,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,  1288,     0,     5,     6,     7,
    1293,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     0,
      62,    63,     0,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,     0,    75,    76,
      77,    78,     0,    79,     0,     0,     0,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   107,   108,     0,     0,
     109,   110,   111,     0,     0,     0,   112,     0,   113,   114,
     115,     0,   116,   117,   118,     0,   119,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,   131,   132,   133,     0,   134,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   172,   173,     0,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     7,
       0,     8,     9,    10,    11,    12,    13,    14,   333,    16,
      17,     0,    18,    19,    20,   336,    22,    23,   338,    25,
      26,    27,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     0,
      62,    63,     0,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,     0,    75,    76,
      77,    78,     0,    79,     0,     0,     0,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   107,   108,     0,     0,
     109,   110,   111,     0,     0,     0,   112,   412,   113,   114,
     115,     0,   116,   117,   118,     0,   119,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,   131,   132,   133,     0,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   172,   173,     0,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     5,     6,     7,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,     0,     0,    62,
      63,     0,     0,     0,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,    74,     0,    75,    76,    77,
      78,     0,    79,     0,     0,     0,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,   107,   108,     0,     0,   109,
     110,   111,     0,     0,     0,   112,     0,   113,   114,   115,
       0,   116,   117,   118,     0,   119,     0,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
     131,   132,   133,     0,   134,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     0,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,     0,   172,   173,     0,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     8,
       9,    10,    11,    12,    13,    14,   333,    16,    17,     0,
      18,    19,    20,   336,    22,    23,   338,    25,    26,    27,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,    62,    63,
       0,     0,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,    74,     0,    75,    76,    77,    78,
       0,    79,     0,     0,     0,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,     0,     0,   109,   110,
     111,     0,   610,     0,   112,     0,   113,   114,   115,     0,
     116,   117,   118,     0,   119,     0,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,   131,
     132,   133,     0,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,   172,   173,     0,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     5,     6,     7,     0,     8,     9,
      10,    11,    12,    13,    14,   333,    16,    17,     0,    18,
      19,    20,   336,    22,    23,   338,    25,    26,    27,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,     0,    62,    63,     0,
       0,     0,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,    74,     0,    75,    76,    77,    78,     0,
      79,     0,     0,     0,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,   107,   108,     0,     0,   109,   110,   111,
       0,   697,     0,   112,     0,   113,   114,   115,     0,   116,
     117,   118,     0,   119,     0,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,   131,   132,
     133,     0,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,     0,   172,   173,     0,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     0,     8,     9,    10,
      11,    12,    13,    14,   333,    16,    17,     0,    18,    19,
      20,   336,    22,    23,   338,    25,    26,    27,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     0,     0,    62,    63,     0,     0,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    74,     0,    75,    76,    77,    78,     0,    79,
       0,     0,     0,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,     0,     0,   109,   110,   111,     0,
       0,     0,   112,   703,   113,   114,   115,     0,   116,   117,
     118,     0,   119,     0,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,   131,   132,   133,
       0,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,     0,   172,   173,     0,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,     5,     6,     7,     0,     8,     9,    10,    11,
      12,    13,    14,   333,    16,    17,     0,    18,    19,    20,
     336,    22,    23,   338,    25,    26,    27,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,     0,     0,    62,    63,     0,     0,     0,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,    74,     0,    75,    76,    77,    78,     0,    79,     0,
       0,     0,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,   107,   108,     0,     0,   109,   110,   111,     0,   717,
       0,   112,     0,   113,   114,   115,     0,   116,   117,   118,
       0,   119,     0,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,   131,   132,   133,     0,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
       0,   172,   173,     0,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     7,     0,     8,     9,    10,    11,    12,
      13,    14,   333,    16,    17,     0,    18,    19,    20,   336,
      22,    23,   338,    25,    26,    27,     0,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,     0,     0,    62,    63,     0,     0,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
      74,     0,    75,    76,    77,    78,     0,    79,     0,     0,
       0,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,     0,     0,   109,   110,   111,     0,   755,     0,
     112,     0,   113,   114,   115,     0,   116,   117,   118,     0,
     119,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,   131,   132,   133,     0,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
     172,   173,     0,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     8,     9,    10,    11,    12,    13,
      14,   333,    16,    17,     0,    18,    19,    20,   336,    22,
      23,   338,    25,    26,    27,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     0,     0,    62,    63,     0,     0,     0,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,    74,
       0,    75,    76,    77,    78,     0,    79,     0,     0,     0,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
      93,    94,    95,    96,    97,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     0,   107,
     108,     0,     0,   109,   110,   111,     0,   788,     0,   112,
       0,   113,   114,   115,     0,   116,   117,   118,     0,   119,
       0,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,   131,   132,   133,     0,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,     0,   172,
     173,     0,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     5,
       6,     7,     0,     8,     9,    10,    11,    12,    13,    14,
     333,    16,    17,     0,    18,    19,    20,   336,    22,    23,
     338,    25,    26,    27,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,     0,    62,    63,     0,     0,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,    74,     0,
      75,    76,    77,    78,     0,    79,     0,     0,     0,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,   107,   108,
       0,     0,   109,   110,   111,     0,  1063,     0,   112,     0,
     113,   114,   115,     0,   116,   117,   118,     0,   119,     0,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   131,   132,   133,     0,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,     0,   172,   173,
       0,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     0,     5,     6,
       7,     0,     8,     9,    10,    11,    12,    13,    14,   333,
      16,    17,     0,    18,    19,    20,   336,    22,    23,   338,
      25,    26,    27,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
       0,    62,    63,     0,     0,     0,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,    74,     0,    75,
      76,    77,    78,     0,    79,     0,     0,     0,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,   107,   108,     0,
       0,   109,   110,   111,     0,  1089,     0,   112,     0,   113,
     114,   115,     0,   116,   117,   118,     0,   119,     0,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
       0,     0,   131,   132,   133,     0,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,     0,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,     0,   172,   173,     0,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     7,
       0,     8,     9,    10,    11,    12,    13,    14,   333,    16,
      17,     0,    18,    19,    20,   336,    22,    23,   338,    25,
      26,    27,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     0,
      62,    63,     0,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,     0,    75,    76,
      77,    78,     0,    79,     0,     0,     0,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   107,   108,     0,     0,
     109,   110,   111,     0,  1109,     0,   112,     0,   113,   114,
     115,     0,   116,   117,   118,     0,   119,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,   131,   132,   133,     0,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   172,   173,     0,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     5,     6,     7,     0,
       8,     9,    10,    11,    12,    13,    14,   333,    16,    17,
       0,    18,    19,    20,   336,    22,    23,   338,    25,    26,
      27,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,     0,     0,    62,
      63,     0,     0,     0,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,    74,     0,    75,    76,    77,
      78,     0,    79,     0,     0,     0,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,   107,   108,     0,     0,   109,
     110,   111,     0,     0,     0,   112,     0,   113,   114,   115,
       0,   116,   117,   118,     0,   119,     0,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
     131,   132,   133,     0,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     0,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,     0,   172,   173,     0,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,    62,    63,
       0,     0,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,    74,     0,    75,    76,    77,    78,
       0,    79,     0,     0,     0,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,     0,     0,   109,   110,
     111,     0,     0,     0,   112,     0,   113,   114,   115,     0,
     116,   117,   118,     0,   119,     0,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,   131,
     132,   133,     0,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,   172,   173,     0,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     0,   325,   326,     7,     0,     0,     9,
     328,    11,    12,    13,    14,   333,    16,    17,     0,   334,
      19,    20,   336,   337,    23,   338,    25,    26,    27,     0,
     339,   340,    30,     0,   341,   342,    34,    35,    36,    37,
      38,    39,    40,    41,   343,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,     0,    62,    63,     0,
       0,     0,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,    74,     0,    75,    76,    77,    78,     0,
      79,     0,     0,     0,   347,    81,    82,    83,    84,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,    93,    94,   501,    96,    97,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,   502,   108,     0,     0,   109,   110,   111,
       0,     0,     0,   112,     0,   113,   114,   115,     0,   116,
     117,   118,     0,   119,     0,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,   131,   132,
     133,     0,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   352,   144,   354,   146,   355,   356,   149,   150,
     151,   152,   153,   154,   357,   156,     0,     0,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,     0,   172,   173,     0,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,   325,   326,     7,     0,     0,     9,   328,
      11,    12,    13,    14,   333,    16,    17,     0,   334,    19,
      20,   336,   337,    23,   338,    25,    26,    27,     0,   339,
     340,    30,     0,   341,   342,    34,    35,    36,    37,    38,
      39,    40,    41,   343,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     0,     0,    62,    63,     0,     0,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    74,     0,    75,    76,    77,    78,     0,    79,
       0,     0,     0,   347,    81,    82,    83,    84,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,     0,     0,   109,   110,   111,     0,
       0,     0,   112,     0,   113,   114,   115,     0,   116,   117,
     118,     0,   119,     0,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,   131,   132,   133,
       0,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   352,   144,   354,   146,   355,   356,   149,   150,   151,
     152,   153,   154,   357,   156,     0,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,     0,   172,   173,     0,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,   325,   326,     7,     0,     0,   327,   328,    11,
      12,    13,    14,   333,    16,    17,     0,   334,    19,    20,
     336,   337,    23,   338,    25,    26,    27,     0,   339,   340,
      30,     0,   341,   342,    34,    35,    36,    37,    38,    39,
      40,    41,   343,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,     0,     0,    62,    63,     0,     0,     0,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,    74,     0,    75,    76,    77,    78,     0,    79,     0,
       0,     0,   347,    81,    82,    83,    84,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     0,    93,    94,     0,    96,    97,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,     0,     0,   109,   110,   111,     0,     0,
       0,   112,     0,   113,   114,   115,     0,     0,     0,   118,
       0,   119,     0,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,   131,   132,   133,     0,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     352,   144,   354,   146,   355,   356,   149,   150,   151,   152,
     153,   154,   357,   156,     0,     0,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
       0,   172,   173,     0,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
       0,   325,   326,     7,     0,     0,   327,   328,   401,   330,
     402,   403,   333,    16,    17,     0,   334,   404,    20,   336,
     337,    23,   338,    25,    26,    27,     0,   339,   340,    30,
       0,   341,   342,    34,    35,    36,    37,    38,    39,    40,
      41,   343,    43,    44,    45,    46,    47,    48,    49,     0,
       0,    52,     0,    53,    54,    55,   405,     0,     0,    59,
      60,    61,     0,     0,     0,    63,     0,     0,     0,     0,
      65,    66,     0,     0,    69,    70,     0,     0,     0,     0,
       0,     0,    75,    76,    77,    78,     0,    79,     0,     0,
       0,   347,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,     0,    89,    90,    91,     0,     0,
       0,     0,     0,     0,    96,    97,     0,     0,     0,     0,
      98,    99,   100,   350,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
     112,     0,   113,   114,     0,     0,     0,     0,   118,     0,
     119,     0,   120,   121,   122,   123,   351,   125,   126,   127,
     128,   129,   130,     0,     0,   131,   132,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   352,
     144,   354,   146,   355,   356,   149,   150,   151,   152,   153,
     154,   357,   156,     0,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
     172,   173,     0,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     0,     0,     0,     0,     0,     0,
     325,   326,     7,     0,     0,   327,   328,   329,   330,   331,
     332,   333,    16,    17,     0,   334,   335,    20,   336,   337,
      23,   338,    25,    26,    27,     0,   339,   340,    30,     0,
     341,   342,    34,    35,    36,    37,    38,    39,    40,    41,
     343,    43,   344,   345,    46,    47,    48,    49,     0,     0,
      52,     0,    53,    54,    55,   346,     0,     0,    59,    60,
      61,     0,     0,     0,    63,     0,     0,     0,     0,    65,
      66,     0,     0,    69,    70,     0,     0,     0,     0,     0,
       0,    75,    76,    77,    78,     0,    79,     0,     0,     0,
     347,    81,    82,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,     0,    89,    90,    91,     0,     0,     0,
       0,     0,     0,    96,    97,     0,     0,     0,     0,    98,
      99,   100,   350,   102,   103,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,     0,     0,     0,   112,
       0,   113,     0,     0,     0,     0,     0,   118,     0,   119,
       0,   120,   121,   122,   123,   351,   125,   126,   127,   128,
     129,   130,     0,     0,   131,   132,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   352,   353,
     354,   146,   355,   356,   149,   150,   151,   152,   153,   154,
     357,   156,     0,     0,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,     0,   172,
     173,     0,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   417,     0,     3,     0,     0,     0,     0,
       0,     0,     0,   325,   326,     7,     0,     0,   327,   328,
     329,   330,   331,   332,   333,    16,    17,     0,   334,   335,
      20,   336,   337,    23,   338,    25,    26,    27,     0,   339,
     340,    30,     0,   341,   342,    34,    35,    36,    37,    38,
      39,    40,    41,   343,    43,   344,   345,    46,    47,    48,
      49,     0,     0,    52,     0,    53,    54,    55,   346,     0,
       0,    59,    60,    61,     0,     0,     0,    63,     0,     0,
       0,     0,    65,    66,     0,     0,    69,    70,     0,     0,
       0,     0,     0,     0,    75,    76,    77,    78,     0,    79,
       0,     0,     0,   347,    81,    82,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,     0,    89,    90,    91,
       0,     0,     0,     0,     0,     0,    96,    97,     0,     0,
       0,     0,    98,    99,   100,   350,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,     0,
       0,     0,   112,     0,   113,     0,     0,     0,     0,     0,
       0,     0,   119,     0,   120,   121,   122,   123,   351,   125,
     126,   127,   128,   129,   130,     0,     0,   131,   132,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   352,   353,   354,   146,   355,   356,   149,   150,   151,
     152,   153,   154,   357,   156,     0,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,     0,   172,   173,     0,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     3,     0,     0,     0,
       0,     0,     0,     0,   325,   326,     7,     0,     0,   327,
     328,   329,   330,   331,   332,   333,    16,    17,     0,   334,
     335,    20,   336,   337,    23,   338,    25,    26,    27,     0,
     339,   340,    30,     0,   341,   342,    34,    35,    36,    37,
      38,    39,    40,    41,   343,    43,   344,   345,    46,    47,
      48,    49,     0,     0,    52,     0,    53,    54,    55,   346,
       0,     0,    59,    60,    61,     0,     0,     0,    63,     0,
       0,     0,     0,    65,    66,     0,     0,    69,    70,     0,
       0,     0,     0,     0,     0,    75,    76,    77,    78,     0,
      79,     0,     0,     0,   347,    81,    82,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,     0,    89,    90,
      91,   348,     0,     0,   349,     0,     0,    96,    97,     0,
       0,     0,     0,    98,    99,   100,   350,   102,   103,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
       0,     0,     0,   112,     0,   113,     0,     0,     0,     0,
       0,     0,     0,   119,     0,   120,   121,   122,   123,   351,
     125,   126,   127,   128,   129,   130,     0,     0,   131,   132,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   352,   353,   354,   146,   355,   356,   149,   150,
     151,   152,   153,   154,   357,   156,     0,     0,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,     0,   172,   173,     0,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     3,     0,     0,
       0,     0,     0,     0,     0,   325,   326,     7,     0,     0,
     327,   328,   329,   330,   331,   332,   333,    16,    17,     0,
     334,   335,    20,   336,   337,    23,   338,    25,    26,    27,
       0,   339,   340,    30,     0,   341,   342,    34,    35,    36,
      37,    38,    39,    40,    41,   343,    43,   344,   345,    46,
      47,    48,    49,     0,     0,    52,     0,    53,    54,    55,
     346,     0,     0,    59,    60,    61,     0,     0,     0,    63,
       0,     0,     0,     0,    65,    66,     0,     0,    69,    70,
       0,     0,     0,     0,     0,     0,    75,    76,    77,    78,
       0,    79,     0,     0,     0,   347,    81,    82,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,     0,    89,
      90,    91,   398,     0,     0,   399,     0,     0,    96,    97,
       0,     0,     0,     0,    98,    99,   100,   350,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     0,     0,     0,   112,     0,   113,     0,     0,     0,
       0,     0,     0,     0,   119,     0,   120,   121,   122,   123,
     351,   125,   126,   127,   128,   129,   130,     0,     0,   131,
     132,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   352,   353,   354,   146,   355,   356,   149,
     150,   151,   152,   153,   154,   357,   156,     0,     0,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,   172,   173,     0,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,     3,     0,
       0,     0,     0,     0,     0,     0,   325,   326,     7,     0,
       0,   327,   328,   329,   330,   331,   332,   333,    16,    17,
       0,   334,   335,    20,   336,   337,    23,   338,    25,    26,
      27,     0,   339,   340,    30,     0,   341,   342,    34,    35,
      36,    37,    38,    39,    40,    41,   343,    43,   344,   345,
      46,    47,    48,    49,     0,     0,    52,     0,    53,    54,
      55,   346,     0,     0,    59,    60,    61,     0,     0,     0,
      63,     0,     0,     0,     0,    65,    66,     0,     0,    69,
      70,     0,     0,     0,     0,     0,     0,    75,    76,    77,
      78,     0,    79,     0,     0,     0,   347,    81,    82,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,     0,
      89,    90,    91,     0,     0,     0,     0,     0,     0,    96,
      97,     0,     0,     0,     0,    98,    99,   100,   350,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,     0,     0,   112,   525,   113,     0,     0,
       0,     0,     0,   526,     0,   119,     0,   120,   121,   122,
     123,   351,   125,   126,   127,   128,   129,   130,     0,     0,
     131,   132,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   352,   353,   354,   146,   355,   356,
     149,   150,   151,   152,   153,   154,   357,   156,     0,     0,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,     0,   172,   173,     0,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     3,
       0,     0,     0,     0,     0,     0,     0,   325,   326,     7,
       0,     0,   327,   328,   329,   330,   331,   332,   333,    16,
      17,     0,   334,   335,    20,   336,   337,    23,   338,    25,
      26,    27,     0,   339,   340,    30,     0,   341,   342,    34,
      35,    36,    37,    38,    39,    40,    41,   343,    43,   344,
     345,    46,    47,    48,    49,     0,     0,    52,     0,    53,
      54,    55,   346,     0,     0,    59,    60,    61,     0,     0,
       0,    63,     0,     0,     0,     0,    65,    66,     0,     0,
      69,    70,     0,     0,     0,     0,     0,     0,    75,    76,
      77,    78,     0,    79,     0,     0,     0,   347,    81,    82,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
       0,    89,    90,    91,     0,     0,     0,     0,     0,     0,
      96,    97,     0,     0,     0,     0,    98,    99,   100,   350,
     102,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,     0,     0,     0,   112,   605,   113,     0,
       0,     0,     0,     0,   606,     0,   119,     0,   120,   121,
     122,   123,   351,   125,   126,   127,   128,   129,   130,     0,
       0,   131,   132,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   352,   353,   354,   146,   355,
     356,   149,   150,   151,   152,   153,   154,   357,   156,     0,
       0,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   172,   173,     0,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       3,     0,     0,     0,     0,     0,     0,     0,   325,   326,
       7,     0,     0,   327,   328,   401,   330,   402,   403,   333,
      16,    17,     0,   334,   404,    20,   336,   337,    23,   338,
      25,    26,    27,     0,   339,   340,    30,     0,   341,   342,
      34,    35,    36,    37,    38,    39,    40,    41,   343,    43,
      44,    45,    46,    47,    48,    49,     0,     0,    52,     0,
      53,    54,    55,   405,     0,     0,    59,    60,    61,     0,
       0,     0,    63,     0,     0,     0,     0,    65,    66,     0,
       0,    69,    70,  1059,     0,     0,     0,     0,     0,    75,
      76,    77,    78,     0,    79,     0,     0,     0,   347,    81,
      82,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,     0,    89,    90,   828,     0,     0,     0,     0,     0,
       0,    96,    97,     0,     0,     0,     0,    98,    99,   100,
     350,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,     0,     0,     0,   112,     0,   113,
     114,     0,     0,     0,     0,     0,     0,   119,     0,   120,
     121,   122,   123,   351,   125,   126,   127,   128,   129,   130,
       0,     0,   829,   132,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   352,   144,   354,   146,
     355,   356,   149,   150,   151,   152,   153,   154,   357,   156,
       0,     0,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,     0,   172,   173,     0,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     3,     0,     0,     0,     0,     0,     0,     0,   325,
     326,     7,     0,     0,   327,   328,   401,   330,   402,   403,
     333,    16,    17,     0,   334,   404,    20,   336,   337,    23,
     338,    25,    26,    27,     0,   339,   340,    30,     0,   341,
     342,    34,    35,    36,    37,    38,    39,    40,    41,   343,
      43,    44,    45,    46,    47,    48,    49,     0,     0,    52,
       0,    53,    54,    55,   405,     0,     0,    59,    60,    61,
       0,     0,     0,    63,     0,     0,     0,     0,    65,    66,
       0,     0,    69,    70,     0,     0,     0,     0,     0,     0,
      75,    76,    77,    78,     0,    79,     0,     0,     0,   347,
      81,    82,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,     0,    89,    90,   828,     0,     0,     0,     0,
       0,     0,    96,    97,     0,     0,     0,     0,    98,    99,
     100,   350,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,     0,     0,     0,   112,     0,
     113,   114,     0,     0,     0,     0,     0,     0,   119,     0,
     120,   121,   122,   123,   351,   125,   126,   127,   128,   129,
     130,     0,     0,   829,   132,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   352,   144,   354,
     146,   355,   356,   149,   150,   151,   152,   153,   154,   357,
     156,     0,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,     0,   172,   173,
       0,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     3,     0,     0,     0,     0,     0,     0,     0,
     325,   326,     7,     0,     0,   327,   328,   329,   330,   331,
     332,   333,    16,    17,     0,   334,   335,    20,   336,   337,
      23,   338,    25,    26,    27,     0,   339,   340,    30,     0,
     341,   342,    34,    35,    36,    37,    38,    39,    40,    41,
     343,    43,   344,   345,    46,    47,    48,    49,     0,     0,
      52,     0,    53,    54,    55,   346,     0,     0,    59,    60,
      61,     0,     0,     0,    63,     0,     0,     0,     0,    65,
      66,     0,     0,    69,    70,     0,     0,     0,     0,     0,
       0,    75,    76,    77,    78,     0,    79,     0,     0,     0,
     347,    81,    82,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,     0,    89,    90,    91,     0,     0,     0,
       0,     0,     0,    96,    97,     0,     0,     0,     0,    98,
      99,   100,   350,   102,   103,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,     0,     0,     0,   112,
       0,   113,     0,     0,     0,     0,     0,     0,     0,   119,
       0,   120,   121,   122,   123,   351,   125,   126,   127,   128,
     129,   130,     0,     0,   131,   132,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   352,   353,
     354,   146,   355,   356,   149,   150,   151,   152,   153,   154,
     357,   156,     0,     0,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,     0,   172,
     173,     0,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        11,   485,   615,   762,   370,   117,   693,   694,   445,   489,
     490,   491,   492,   653,   741,   586,   591,   383,   384,   905,
     591,    58,   796,   869,   317,   465,   319,   375,   706,   857,
      20,   675,    78,   381,   468,    21,   470,   471,   386,   473,
      78,   475,    80,    62,    20,    56,    80,    58,    80,   483,
     484,    33,    91,   693,   694,     7,   978,    92,    93,   123,
      71,    38,    39,    40,    18,    18,    20,   127,    91,  1010,
    1011,    48,    77,    91,    80,    91,    91,   123,    91,    78,
     111,    91,   657,    94,   659,    78,    68,    91,    91,   127,
      38,    39,    40,     8,     9,   127,   389,   108,   127,    91,
      48,   217,    43,   114,    94,   180,    54,   148,   117,    20,
     138,    91,    58,    59,   189,   105,    78,    65,    95,    67,
     270,   130,    70,    37,    55,    73,   276,   155,   127,    28,
      44,   170,   425,   426,    91,   428,   429,   430,   431,   129,
     181,   434,    84,   133,   167,   176,   136,    95,    96,   164,
     166,   263,   170,   446,   167,   101,   166,   162,   729,   163,
      91,   454,   455,   166,    20,     8,     9,   242,    91,   110,
       8,     9,    87,   248,   166,   934,     8,     9,   197,   792,
     133,   256,   246,   136,   166,   551,   246,   671,   672,   104,
     166,   106,   140,  1115,   968,  1136,   923,   772,   232,   233,
     246,   888,   154,   774,   978,   198,   199,   193,   246,   166,
     244,   230,   166,    91,   246,   859,   582,   246,   133,   659,
     213,  1049,   137,   516,   136,   236,   232,   233,   906,   140,
     578,   268,   666,   581,   271,   215,   198,   199,   153,  1085,
      96,    91,   101,   166,    87,    91,   236,   224,   888,    87,
      91,   213,   200,    78,     8,    87,    91,   268,    91,   174,
     271,   104,    91,   106,    91,    19,   104,   842,   106,    80,
     136,    91,   104,    84,   106,   217,   224,   192,   205,    91,
     207,   117,    91,   225,   140,   320,    96,    91,   166,   324,
     133,   180,    91,   197,   137,   133,   238,    91,   240,   137,
     189,   133,   127,     4,   101,   137,   165,     8,   250,   161,
     153,   253,    33,   348,    91,   153,   166,    38,    91,    91,
     166,   153,   163,   175,   359,   360,   230,   362,   163,   136,
      91,   174,   101,   166,   163,    91,   174,   148,   349,   166,
      91,  1115,   174,   378,   180,   380,   166,    91,   140,   192,
     104,   163,   106,   364,   192,   648,   367,   166,  1244,   163,
     192,   115,   655,   398,   730,   731,     4,   166,   734,    90,
       8,   855,   166,   111,   385,   410,   387,   388,   858,   133,
     415,   818,  1228,   867,  1071,   396,   421,    91,   399,   166,
     163,   163,   112,    91,   100,   507,   508,   166,   409,  1285,
     133,   767,   163,   104,  1290,   106,   217,   163,  1294,    91,
      91,   161,   163,   114,   225,   225,   227,   228,   229,   163,
     126,   715,   433,    80,   435,   175,   237,   238,   149,   240,
    1189,  1071,   133,   139,   245,    91,    91,   133,   176,   250,
     251,   252,   253,     8,   254,   255,    46,   257,   258,   133,
     170,    80,   136,    53,    19,    84,    56,    57,    20,   163,
     156,    91,   101,    91,    64,   163,   104,   173,   106,   504,
      90,   764,   765,   133,   509,   768,   114,   770,    80,   136,
      91,   163,   163,  1170,    91,   520,   521,   522,   108,   133,
     784,   205,   786,   528,    96,   133,   210,   790,   125,  1070,
    1113,   171,   172,    60,    61,  1118,    63,   163,   163,   802,
     803,   804,   128,   806,   807,   808,   809,   810,   811,   148,
     813,   814,  1249,    80,   535,   536,   819,   101,   155,   145,
    1170,  1218,    94,   163,   136,   163,    78,   548,   128,   104,
      28,   106,   577,   105,   101,   838,   173,   840,   841,   149,
     115,   151,   163,   138,  1034,   145,   163,   201,   202,   203,
     146,  1041,  1042,   929,    80,   165,    56,   129,   133,  1053,
     155,   133,   225,   608,   136,   161,   118,   118,  1218,   101,
      96,   123,   510,   136,   595,   513,  1199,   515,   217,   882,
    1203,   191,   133,   178,  1236,  1237,   225,    79,   227,   228,
     229,   254,   255,   614,   257,   258,   221,   222,    90,   238,
     118,   240,    60,    61,  1256,   136,   245,    99,    84,   912,
    1262,   250,   251,   252,   253,   133,   108,  1240,   243,   242,
      96,   133,    80,   926,   247,   670,   647,    14,   118,   242,
    1006,   133,   653,   123,   136,   248,   939,   178,   133,   180,
    1175,   944,   945,   256,   947,  1180,   205,    47,   189,   952,
      50,   136,   223,   223,   101,   226,   226,   201,   202,   203,
    1150,  1151,   205,   212,   207,   214,   212,   195,   214,   113,
     109,   110,   693,   694,   695,   696,   133,   121,   122,   101,
     124,    60,    61,   109,   110,   486,   487,   131,   724,   725,
       0,   135,   713,   137,   715,   493,   494,   170,   142,  1002,
     495,   496,   695,   696,  1173,  1174,   170,    91,    76,   147,
    1013,   235,    71,   179,   158,    85,  1092,    86,   134,   136,
     133,   133,   133,  1026,   133,   166,  1029,  1217,  1031,   166,
      38,    38,    20,    18,   101,   133,   252,   252,   182,   183,
     184,   185,   186,   187,   101,   101,   136,   133,   136,    25,
      15,   136,   166,   136,   136,   211,    20,   193,   166,    37,
     149,   101,    91,   784,  1140,   786,   211,    78,    20,   150,
     150,   166,    78,    78,   136,    91,    91,  1080,   108,   140,
     140,   113,    20,    80,    33,    80,   113,   123,   166,   166,
      91,   163,   166,   166,    78,   166,   217,  1100,   205,  1102,
     123,   150,   101,   824,   170,  1108,   827,   101,   163,   101,
     101,   253,   236,   127,   835,   234,   837,    84,   241,  1122,
    1123,  1124,  1125,  1126,   133,  1128,   255,   177,   256,   133,
     133,   256,   113,   113,    80,   101,   123,   127,   140,   101,
     133,    25,    20,   101,  1147,   101,   891,   133,    91,    91,
     127,   256,   127,   136,   230,   219,   231,   136,   903,   127,
    1163,    49,  1165,    78,   125,   125,   166,   888,   231,    20,
     166,    91,   170,   123,   127,   101,   101,   898,    63,   113,
       6,   170,   927,   217,  1187,   213,    90,   213,   213,   213,
      90,   256,   166,   166,   166,   166,   166,   136,   127,    78,
     101,   249,   165,    78,    20,    20,    80,   166,   107,   166,
     165,    78,   163,    20,   959,   936,    80,   239,    61,   101,
     165,   942,   176,   133,   101,   165,   239,    77,   176,   974,
     162,   101,   953,   101,   444,   176,   166,   444,  1072,   176,
     827,   779,  1106,   942,  1247,  1003,   954,  1015,   195,   819,
    1013,  1010,   936,   235,   975,   409,   467,   201,   889,   488,
     466,  1129,   198,   198,   968,   615,  1262,  1270,  1256,   202,
     696,   715,   996,  1000,   671,   996,   855,   397,   867,   397,
    1053,   859,  1003,   672,  1185,  1084,  1048,   256,   856,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1059,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1071,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1103,  1104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1114,    -1,    -1,    -1,    -1,  1119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1164,    -1,    -1,    -1,    -1,    -1,  1170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1200,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1268,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,  1286,    -1,    26,    27,    28,
    1291,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    -1,
      89,    90,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,   105,    -1,   107,   108,
     109,   110,    -1,   112,    -1,    -1,    -1,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,   155,   156,    -1,    -1,
     159,   160,   161,    -1,    -1,    -1,   165,    -1,   167,   168,
     169,    -1,   171,   172,   173,    -1,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,   190,   191,   192,    -1,   194,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,   235,   236,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    -1,
      89,    90,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,   105,    -1,   107,   108,
     109,   110,    -1,   112,    -1,    -1,    -1,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,   155,   156,    -1,    -1,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,    -1,   171,   172,   173,    -1,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,   190,   191,   192,    -1,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,   235,   236,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    -1,    89,
      90,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,   105,    -1,   107,   108,   109,
     110,    -1,   112,    -1,    -1,    -1,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,    -1,   159,
     160,   161,    -1,    -1,    -1,   165,    -1,   167,   168,   169,
      -1,   171,   172,   173,    -1,   175,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
     190,   191,   192,    -1,   194,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,   235,   236,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    -1,    89,    90,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,   105,    -1,   107,   108,   109,   110,
      -1,   112,    -1,    -1,    -1,   116,   117,   118,   119,   120,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,    -1,    -1,   159,   160,
     161,    -1,   163,    -1,   165,    -1,   167,   168,   169,    -1,
     171,   172,   173,    -1,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,   190,
     191,   192,    -1,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,   235,   236,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    -1,    89,    90,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,   105,    -1,   107,   108,   109,   110,    -1,
     112,    -1,    -1,    -1,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,    -1,    -1,   159,   160,   161,
      -1,   163,    -1,   165,    -1,   167,   168,   169,    -1,   171,
     172,   173,    -1,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,   190,   191,
     192,    -1,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,   235,   236,    -1,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    -1,    89,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,   105,    -1,   107,   108,   109,   110,    -1,   112,
      -1,    -1,    -1,   116,   117,   118,   119,   120,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,   155,   156,    -1,    -1,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,    -1,   171,   172,
     173,    -1,   175,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,   190,   191,   192,
      -1,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,   235,   236,    -1,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    -1,    89,    90,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,   105,    -1,   107,   108,   109,   110,    -1,   112,    -1,
      -1,    -1,   116,   117,   118,   119,   120,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,    -1,    -1,   159,   160,   161,    -1,   163,
      -1,   165,    -1,   167,   168,   169,    -1,   171,   172,   173,
      -1,   175,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,   190,   191,   192,    -1,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,   235,   236,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
     105,    -1,   107,   108,   109,   110,    -1,   112,    -1,    -1,
      -1,   116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
     155,   156,    -1,    -1,   159,   160,   161,    -1,   163,    -1,
     165,    -1,   167,   168,   169,    -1,   171,   172,   173,    -1,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,   190,   191,   192,    -1,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
     235,   236,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    -1,    89,    90,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,   105,
      -1,   107,   108,   109,   110,    -1,   112,    -1,    -1,    -1,
     116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,    -1,   159,   160,   161,    -1,   163,    -1,   165,
      -1,   167,   168,   169,    -1,   171,   172,   173,    -1,   175,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,   190,   191,   192,    -1,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,   235,
     236,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    -1,    89,    90,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,   105,    -1,
     107,   108,   109,   110,    -1,   112,    -1,    -1,    -1,   116,
     117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
      -1,    -1,   159,   160,   161,    -1,   163,    -1,   165,    -1,
     167,   168,   169,    -1,   171,   172,   173,    -1,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,   190,   191,   192,    -1,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,   235,   236,
      -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      -1,    89,    90,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,   105,    -1,   107,
     108,   109,   110,    -1,   112,    -1,    -1,    -1,   116,   117,
     118,   119,   120,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
      -1,   159,   160,   161,    -1,   163,    -1,   165,    -1,   167,
     168,   169,    -1,   171,   172,   173,    -1,   175,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,   190,   191,   192,    -1,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,   235,   236,    -1,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    -1,
      89,    90,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,   105,    -1,   107,   108,
     109,   110,    -1,   112,    -1,    -1,    -1,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,   155,   156,    -1,    -1,
     159,   160,   161,    -1,   163,    -1,   165,    -1,   167,   168,
     169,    -1,   171,   172,   173,    -1,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,   190,   191,   192,    -1,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,   235,   236,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    -1,    89,
      90,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,   105,    -1,   107,   108,   109,
     110,    -1,   112,    -1,    -1,    -1,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,    -1,   159,
     160,   161,    -1,    -1,    -1,   165,    -1,   167,   168,   169,
      -1,   171,   172,   173,    -1,   175,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
     190,   191,   192,    -1,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,   235,   236,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    -1,    89,    90,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,   105,    -1,   107,   108,   109,   110,
      -1,   112,    -1,    -1,    -1,   116,   117,   118,   119,   120,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,    -1,    -1,   159,   160,
     161,    -1,    -1,    -1,   165,    -1,   167,   168,   169,    -1,
     171,   172,   173,    -1,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,   190,
     191,   192,    -1,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,   235,   236,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    -1,    89,    90,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,   105,    -1,   107,   108,   109,   110,    -1,
     112,    -1,    -1,    -1,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,    -1,    -1,   159,   160,   161,
      -1,    -1,    -1,   165,    -1,   167,   168,   169,    -1,   171,
     172,   173,    -1,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,   190,   191,
     192,    -1,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,   235,   236,    -1,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    -1,    89,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,   105,    -1,   107,   108,   109,   110,    -1,   112,
      -1,    -1,    -1,   116,   117,   118,   119,   120,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,   155,   156,    -1,    -1,   159,   160,   161,    -1,
      -1,    -1,   165,    -1,   167,   168,   169,    -1,   171,   172,
     173,    -1,   175,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,   190,   191,   192,
      -1,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,   235,   236,    -1,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    -1,    89,    90,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,   105,    -1,   107,   108,   109,   110,    -1,   112,    -1,
      -1,    -1,   116,   117,   118,   119,   120,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,   136,   137,    -1,   139,   140,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,    -1,    -1,
      -1,   165,    -1,   167,   168,   169,    -1,    -1,    -1,   173,
      -1,   175,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,   190,   191,   192,    -1,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,   235,   236,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,    76,    -1,    78,    79,    80,    81,    -1,    -1,    84,
      85,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,
      95,    96,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,   110,    -1,   112,    -1,    -1,
      -1,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,    -1,   130,   131,   132,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,
     165,    -1,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,   190,   191,    -1,    -1,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
     235,   236,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
      76,    -1,    78,    79,    80,    81,    -1,    -1,    84,    85,
      86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    95,
      96,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,   112,    -1,    -1,    -1,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,    -1,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,   165,
      -1,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,   235,
     236,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    16,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    76,    -1,    78,    79,    80,    81,    -1,
      -1,    84,    85,    86,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    -1,    95,    96,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,   110,    -1,   112,
      -1,    -1,    -1,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,    -1,   130,   131,   132,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,
      -1,    -1,   165,    -1,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   175,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,   190,   191,    -1,
      -1,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,   235,   236,    -1,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    -1,    76,    -1,    78,    79,    80,    81,
      -1,    -1,    84,    85,    86,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    -1,    95,    96,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
     112,    -1,    -1,    -1,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,    -1,   130,   131,
     132,   133,    -1,    -1,   136,    -1,    -1,   139,   140,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
      -1,    -1,    -1,   165,    -1,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,   190,   191,
      -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,   235,   236,    -1,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    76,    -1,    78,    79,    80,
      81,    -1,    -1,    84,    85,    86,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,
      -1,   112,    -1,    -1,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,   130,
     131,   132,   133,    -1,    -1,   136,    -1,    -1,   139,   140,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,    -1,    -1,    -1,   165,    -1,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,   190,
     191,    -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,   235,   236,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    -1,    76,    -1,    78,    79,
      80,    81,    -1,    -1,    84,    85,    86,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,   112,    -1,    -1,    -1,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,
     130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,   175,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
     190,   191,    -1,    -1,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,   235,   236,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    76,    -1,    78,
      79,    80,    81,    -1,    -1,    84,    85,    86,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,   110,    -1,   112,    -1,    -1,    -1,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
      -1,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,   190,   191,    -1,    -1,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,   235,   236,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    -1,    76,    -1,
      78,    79,    80,    81,    -1,    -1,    84,    85,    86,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    -1,    95,    96,    -1,
      -1,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,   112,    -1,    -1,    -1,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,    -1,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,    -1,    -1,    -1,   165,    -1,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,   190,   191,    -1,    -1,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,   235,   236,    -1,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    76,
      -1,    78,    79,    80,    81,    -1,    -1,    84,    85,    86,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    95,    96,
      -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,   110,    -1,   112,    -1,    -1,    -1,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,    -1,   130,   131,   132,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   140,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,   165,    -1,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,   235,   236,
      -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
      76,    -1,    78,    79,    80,    81,    -1,    -1,    84,    85,
      86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    95,
      96,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,   112,    -1,    -1,    -1,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,    -1,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,   165,
      -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,   235,
     236,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    10,    17,    18,    20,    26,    27,    28,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    89,    90,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   105,   107,   108,   109,   110,   112,
     116,   117,   118,   119,   120,   126,   127,   128,   129,   130,
     131,   132,   133,   136,   137,   138,   139,   140,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   155,   156,   159,
     160,   161,   165,   167,   168,   169,   171,   172,   173,   175,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   190,   191,   192,   194,   195,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   235,   236,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     301,   302,   303,   305,   307,   308,   309,   310,   311,   316,
     317,   318,   319,   324,   326,   328,   329,   330,   335,   356,
     359,   362,   363,   364,   365,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   412,   413,   414,   428,   429,
     431,   432,   433,   434,   435,   436,   437,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   456,   457,   458,
     459,   460,   461,   462,   465,   470,   471,   217,    28,   136,
     133,   201,   202,   203,   136,    26,    27,    31,    32,    33,
      34,    35,    36,    37,    41,    42,    44,    45,    47,    52,
      53,    56,    57,    66,    68,    69,    81,   116,   133,   136,
     148,   181,   204,   205,   206,   208,   209,   216,   470,   133,
     133,   136,   133,   136,    38,    39,    40,    48,    54,    65,
      67,    70,    73,    95,    96,   140,   200,   224,   136,    18,
     133,   136,   469,    47,    50,   101,   140,   101,   101,   133,
      58,    59,   101,   321,    56,    28,   136,   136,   133,   136,
     470,    33,    35,    36,    42,    81,   396,   470,   470,   101,
     306,   317,   166,   317,   470,   133,    14,    16,   470,   470,
     388,   133,    21,   193,   195,   205,   207,   136,   205,   207,
     205,   205,   210,   101,   133,   101,   276,     0,   278,   279,
      37,    44,   281,   316,   170,   170,    91,    46,    53,    56,
      57,    64,   149,   151,   165,   191,   320,   325,   326,   327,
     344,   345,   349,   331,   332,   470,   147,    76,   113,   121,
     122,   124,   131,   135,   137,   142,   158,   182,   183,   184,
     185,   186,   187,   380,   381,   235,   138,   155,   178,   100,
     126,   139,   173,   180,   189,   117,   130,    71,   179,    85,
      86,   138,   155,   379,   133,   385,   388,   171,   172,   134,
     400,   401,   396,   400,   396,   400,   136,   318,   318,   317,
     133,   133,   133,   317,   317,   166,   173,   470,   133,   317,
     317,   166,   317,   166,   470,    38,    38,   470,   161,   175,
     148,   181,    20,   468,   146,   161,   161,   175,   101,    33,
      38,    90,   149,   469,   201,   202,   203,    84,   217,   225,
     238,   240,   250,   253,   483,   484,   485,   486,   487,   490,
     495,   496,   317,   317,    20,   166,   469,   133,   140,   468,
      96,   140,   300,   468,   357,   358,   470,   469,   470,   336,
     338,   470,   318,   252,   252,   101,   339,   101,   470,    33,
      68,   166,   452,   453,   317,   166,   173,   470,   133,   357,
     163,   317,   170,   166,    25,   416,   417,   418,   317,     7,
     154,    15,   166,   317,   193,    20,   318,   318,   166,   318,
     318,   318,   318,   211,   463,   464,   470,   318,   337,   343,
     470,   283,   284,    37,   285,   318,   149,   101,   150,   150,
     318,   318,    91,    78,    80,   127,   246,   333,   334,   439,
     364,   365,   367,   367,   367,   367,   366,   367,   367,   367,
     133,   136,   236,   403,   472,   474,   475,   476,   477,   478,
     479,   480,   370,   370,   369,   371,   371,   371,   371,   372,
     372,   373,   373,   211,    78,    78,    78,   163,   317,   388,
     388,   317,   401,   166,   318,   411,   166,   163,   317,   317,
     317,   166,   163,    91,   166,    91,   166,   163,   317,   163,
     163,   163,   136,   304,   470,   470,    20,    91,    91,   470,
     140,   140,   468,   108,   113,   223,   226,    96,   225,   254,
     255,   257,   258,   223,   226,    20,   225,   254,   255,   257,
     258,   166,   163,   166,   166,   163,   317,   469,    80,    33,
     469,   468,    80,    91,   167,   127,   439,   113,   123,    91,
     123,   334,   439,   163,   470,    62,   197,   230,   322,   323,
     166,   166,   166,   163,    91,   166,    91,   166,   163,   317,
     167,   170,   470,   417,   418,   111,   176,   163,   163,   112,
     170,    78,   198,   199,   213,    78,   198,   199,   213,    78,
     217,   205,    91,   215,   123,   163,    55,    91,   170,   150,
     470,   318,   350,   351,   101,   346,   347,   101,   132,   190,
     440,   442,   443,   444,   470,   101,   318,   101,   127,   334,
     127,   127,   333,   334,   367,   317,   472,   478,   253,   506,
      80,   148,   227,   228,   229,   237,   245,   251,   252,   473,
     481,   482,   483,   497,   500,   501,   503,   234,   236,   241,
     502,   221,   222,   243,   498,   440,   440,   438,   443,   438,
     163,   164,    91,   166,   305,   163,   163,   163,    84,   360,
     361,   133,   454,   455,   470,   454,   455,   163,   101,   166,
     312,   313,   118,   133,   315,   304,   304,   128,   145,   128,
     145,   118,   123,   439,   468,   468,   109,   110,   468,   255,
     256,    80,    96,   136,   489,   256,   177,   133,   163,   113,
     299,   468,   140,   113,    80,   299,   101,   318,   318,   127,
     468,   318,   101,   318,   123,   123,   334,   127,   439,   230,
      60,    61,    63,   101,   333,   340,   341,   342,   323,   133,
     454,   470,   454,   163,   318,    25,   418,   111,   176,     8,
       9,    87,   104,   106,   133,   174,   314,   413,   415,   426,
     427,   430,    20,   212,   214,   318,   318,   318,   212,   214,
     318,   318,   318,   318,   318,   318,   101,   318,   318,   219,
     466,   467,   133,   101,   350,    79,    90,    99,   108,   352,
     353,   354,   355,    91,   470,    91,   332,   136,   136,   125,
     155,   173,   441,   470,   470,   318,   127,   318,   318,   127,
     334,   127,   163,   166,   231,   197,   230,   242,   247,   505,
      80,   232,   233,   499,   231,   475,   505,   368,   371,   251,
     481,   483,   476,   127,   499,   256,    49,   125,   318,   101,
     440,    96,   361,   163,   317,   166,   166,   125,   166,   166,
     470,    78,    91,   166,   317,   118,   315,   305,   318,   118,
     123,   256,    80,   136,   492,    20,    96,   489,   318,   163,
     317,   468,    91,   299,   358,   318,   170,   338,   318,   318,
     123,   318,   127,   101,   101,   318,   470,   342,    63,   163,
     317,   166,   166,   113,   174,   415,     6,   317,   470,   174,
     426,   170,   213,   213,   213,   213,   217,   464,   165,   136,
     467,   318,   343,   468,   109,   110,   354,   355,   355,   351,
      90,   348,   347,   166,   166,   318,   318,   127,   318,   371,
      43,   110,   371,   371,   242,   248,   256,   504,   504,   368,
     477,   249,   470,   165,   101,   165,   163,   439,   440,   313,
      78,   163,   318,   117,   180,   491,   494,    20,    20,   493,
     491,   244,   499,    91,   166,    91,   166,   107,   163,    80,
     468,   318,   318,   470,   470,   341,   318,   163,   418,   470,
     174,   163,   418,   470,   318,   318,   318,   318,   318,   318,
     397,   163,   355,   468,   318,   371,   371,   178,    78,   318,
     470,   318,   440,   492,   492,   494,    20,   166,    20,   239,
     488,   489,   488,   318,   299,    61,    77,   162,   419,   418,
     470,   176,   418,    91,   166,   371,   440,   165,   499,    91,
     166,   166,   101,     4,   114,   422,   423,   425,   427,    19,
     115,   420,   421,   424,   427,   176,   418,   176,   101,   315,
     165,   318,   239,   489,   470,    77,   114,   425,   162,   115,
     424,   176,   470,   318,    91,   166,   101,   315,   470,    91,
     166,   101,   315,   470,   166,   315
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
     525,   526,   527,   528
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   274,   275,   275,   276,   276,   276,   276,   277,   277,
     278,   278,   279,   280,   281,   281,   281,   282,   282,   283,
     283,   284,   284,   284,   284,   285,   285,   285,   285,   286,
     286,   286,   286,   286,   286,   286,   286,   287,   287,   288,
     289,   289,   290,   290,   291,   292,   293,   293,   294,   294,
     295,   295,   295,   295,   296,   297,   298,   298,   298,   298,
     299,   299,   300,   300,   301,   301,   301,   301,   302,   302,
     302,   302,   303,   303,   304,   304,   304,   304,   305,   306,
     306,   307,   308,   309,   310,   310,   311,   311,   311,   311,
     311,   312,   312,   313,   313,   314,   315,   316,   317,   317,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   319,   320,   321,
     321,   322,   322,   322,   323,   323,   324,   324,   325,   326,
     326,   326,   327,   327,   327,   327,   327,   328,   328,   329,
     329,   330,   331,   331,   332,   332,   332,   332,   332,   332,
     332,   332,   333,   334,   335,   336,   336,   337,   337,   338,
     338,   338,   338,   339,   339,   340,   340,   340,   341,   341,
     341,   342,   342,   342,   343,   344,   345,   346,   346,   347,
     347,   348,   349,   349,   350,   350,   351,   351,   352,   352,
     352,   352,   352,   352,   352,   353,   353,   354,   354,   355,
     356,   356,   357,   357,   358,   358,   359,   359,   360,   360,
     361,   361,   362,   363,   363,   364,   364,   365,   365,   365,
     365,   365,   366,   365,   365,   365,   365,   367,   367,   367,
     368,   368,   369,   369,   369,   370,   370,   370,   370,   370,
     371,   371,   371,   372,   372,   372,   373,   373,   374,   374,
     375,   375,   376,   376,   377,   377,   378,   378,   378,   378,
     379,   379,   379,   380,   380,   380,   380,   380,   380,   381,
     381,   381,   382,   382,   382,   382,   383,   383,   384,   384,
     385,   385,   386,   386,   386,   386,   387,   388,   388,   388,
     389,   389,   390,   390,   390,   390,   391,   391,   392,   392,
     392,   392,   392,   392,   392,   393,   393,   394,   394,   395,
     395,   395,   395,   395,   396,   396,   397,   397,   398,   398,
     398,   399,   399,   400,   400,   401,   402,   402,   402,   402,
     402,   402,   402,   402,   403,   403,   404,   404,   404,   405,
     406,   406,   407,   408,   409,   410,   410,   411,   411,   412,
     412,   413,   413,   413,   414,   414,   414,   414,   414,   414,
     415,   415,   416,   416,   417,   418,   418,   419,   419,   420,
     420,   421,   421,   421,   421,   422,   422,   423,   423,   423,
     423,   424,   424,   425,   425,   426,   426,   426,   426,   427,
     427,   427,   427,   428,   428,   429,   429,   430,   431,   431,
     431,   431,   431,   431,   432,   433,   433,   433,   433,   434,
     434,   434,   434,   435,   436,   437,   437,   437,   437,   438,
     438,   439,   440,   440,   440,   441,   441,   441,   442,   442,
     442,   443,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   445,   446,   446,   446,   447,   448,   449,   449,   449,
     450,   450,   450,   450,   450,   451,   452,   452,   452,   452,
     452,   452,   452,   453,   454,   455,   456,   457,   457,   457,
     458,   458,   458,   458,   458,   458,   458,   458,   458,   458,
     459,   459,   460,   460,   461,   462,   463,   463,   464,   465,
     466,   466,   467,   467,   467,   467,   468,   469,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   471,   471,   472,   472,   472,   472,   473,
     473,   473,   473,   474,   474,   475,   475,   476,   476,   477,
     477,   478,   478,   478,   479,   479,   480,   480,   481,   481,
     481,   481,   481,   482,   483,   483,   483,   483,   483,   483,
     483,   484,   484,   484,   484,   485,   485,   485,   485,   486,
     486,   487,   487,   487,   487,   487,   487,   487,   488,   488,
     489,   489,   489,   489,   490,   490,   490,   490,   490,   491,
     491,   492,   492,   493,   493,   494,   494,   495,   496,   496,
     497,   497,   497,   498,   498,   498,   498,   498,   499,   499,
     499,   499,   500,   501,   502,   503,   503,   504,   504,   504,
     505,   505,   506
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
       3,     5,     3,     5,     2,     2,     5,     5,     6,     6,
       6,     1,     3,     2,     3,     3,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     1,     2,     4,     3,     5,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     2,     1,     4,     3,     4,     4,     5,     4,     5,
       5,     6,     3,     3,     3,     1,     4,     1,     4,     3,
       4,     4,     5,     4,     5,     1,     2,     3,     1,     2,
       1,     6,     3,     3,     1,     2,     3,     1,     3,     2,
       3,     2,     3,     4,     1,     3,     1,     2,     1,     1,
       1,     2,     2,     2,     3,     1,     1,     2,     2,     2,
       5,     5,     1,     4,     3,     4,     8,    10,     1,     2,
       4,     7,     8,     1,     3,     1,     3,     1,     3,     3,
       3,     3,     0,     4,     3,     3,     3,     1,     3,     4,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     4,     1,     4,
       1,     4,     1,     4,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     5,     5,     3,     4,     1,     2,
       3,     2,     1,     2,     2,     1,     1,     1,     3,     3,
       1,     1,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     1,     4,     4,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     4,     5,     8,     9,     9,    10,
       1,     2,     1,     2,     6,     0,     1,     3,     3,     0,
       1,     1,     1,     2,     2,     0,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     4,     4,     5,     6,     7,     4,
       5,     6,     7,     4,     4,     4,     5,     6,     7,     1,
       2,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     4,     4,     3,     3,     3,     4,     4,
       3,     4,     6,     4,     6,     3,     3,     4,     6,     6,
       4,     6,     6,     4,     1,     2,     1,     3,     3,     3,
       5,     7,     7,     5,     5,     5,     7,     7,     5,     5,
       3,     3,     5,     7,     5,     7,     1,     4,     3,     5,
       1,     2,     5,     8,    11,    14,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     7,     4,     1,     2,     3,     4,     1,
       1,     2,     2,     1,     3,     1,     3,     1,     4,     1,
       2,     1,     2,     3,     1,     2,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     5,     7,     5,     7,     2,     1,     3,
       2,     4,     4,     6,     4,     5,     4,     5,     3,     1,
       2,     2,     3,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     1,     2,     1,     2,     3,
       3,     4,     3,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const xquery_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\"'unrecognized'\"",
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
  "\"'word'\"", "\"'schema'\"", "\"'space'\"", "\"'set'\"", "\"'let'\"",
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
  "\"'treat'\"", "\"'union'\"", "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"",
  "\"'gt'\"", "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"",
  "\"'|'\"", "\"'empty-sequence'\"", "\"'where'\"", "\"'<!--'\"",
  "\"'-->'\"", "\"'xquery'\"", "\"'version'\"", "\"'#)'\"", "\"'start'\"",
  "\"'after'\"", "\"'before'\"", "\"'revalidation'\"", "\"'strict'\"",
  "\"'lax'\"", "\"'skip'\"", "\"'delete'\"", "\"'node'\"", "\"'insert'\"",
  "\"'nodes'\"", "\"'rename'\"", "\"'replace'\"", "\"'value'\"",
  "\"'of'\"", "\"'first'\"", "\"'into'\"", "\"'last'\"", "\"'modify'\"",
  "\"'copy'\"", "\"'with'\"", "\"'try'\"", "\"'catch'\"", "\"'using'\"",
  "\"'all'\"", "\"'any'\"", "\"'casesensitive'\"", "\"'ft-option'\"",
  "\"'diacritics'\"", "\"'insensitive'\"", "\"'different'\"",
  "\"'distance'\"", "\"'entire'\"", "\"'end'\"", "\"'content'\"",
  "\"'exactly'\"", "\"'from'\"", "\"'&&'\"", "\"'ftcontains'\"",
  "\"'not'\"", "\"'||'\"", "\"'language'\"", "\"'levels'\"",
  "\"'lowercase'\"", "\"'occurs'\"", "\"'paragraph'\"", "\"'phrase'\"",
  "\"'relationship'\"", "\"'same'\"", "\"'score'\"", "\"'sentence'\"",
  "\"'sentences'\"", "\"'times'\"", "\"'uppercase'\"", "\"'weight'\"",
  "\"'window'\"", "\"'without'\"", "\"'stemming'\"", "\"'stop'\"",
  "\"'words'\"", "\"'thesaurus'\"", "\"'wildcards'\"", "\"'BOM_UTF8'\"",
  "FTCONTAINS_REDUCE", "RANGE_REDUCE", "ADDITIVE_REDUCE",
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
  "AssignExpr", "ExitExpr", "WhileExpr", "FlowCtlStatement",
  "FunctionDecl", "ParamList", "Param", "EnclosedExpr", "BracedExpr",
  "QueryBody", "Expr", "ExprSingle", "FLWORExpr", "ReturnExpr",
  "WindowType", "FLWORWinCondType", "FLWORWinCond", "WindowClause",
  "CountClause", "ForLetWinClause", "FLWORClause", "FLWORClauseList",
  "ForDollar", "ForClause", "VarInDeclList", "VarInDecl", "PositionalVar",
  "FTScoreVar", "LetClause", "VarGetsDeclList", "EvalVarDeclList",
  "VarGetsDecl", "WindowVarDecl", "WindowVars", "WindowVars3",
  "WindowVars2", "EvalVarDecl", "WhereClause", "GroupByClause",
  "GroupSpecList", "GroupSpec", "GroupCollationSpec", "OrderByClause",
  "OrderSpecList", "OrderSpec", "OrderModifier", "OrderDirSpec",
  "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
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
       275,     0,    -1,   276,    -1,   259,   276,    -1,   278,    -1,
     277,   278,    -1,   279,    -1,   277,   279,    -1,   194,   195,
      20,   170,    -1,   194,   195,    20,   112,    20,   170,    -1,
     281,   316,    -1,   316,    -1,   280,   281,    -1,    47,   140,
     469,   113,   468,   170,    -1,   282,   170,    -1,   283,   170,
      -1,   282,   170,   283,   170,    -1,   284,    -1,   282,   170,
     284,    -1,   285,    -1,   283,   170,   285,    -1,   286,    -1,
     287,    -1,   288,    -1,   290,    -1,   302,    -1,   311,    -1,
     291,    -1,   292,    -1,   289,    -1,   296,    -1,   297,    -1,
     303,    -1,   293,    -1,   294,    -1,   295,    -1,   457,    -1,
     298,    -1,   301,    -1,    37,   140,   469,   113,   468,    -1,
      37,    73,   161,    -1,    37,    73,   175,    -1,    37,    96,
      33,   140,   468,    -1,    37,    96,    38,   140,   468,    -1,
      37,    48,   470,    20,    -1,    37,   224,   483,    -1,    37,
      65,   148,    -1,    37,    65,   181,    -1,    37,    96,   149,
     108,   109,    -1,    37,    96,   149,   108,   110,    -1,    37,
      70,   161,    91,   128,    -1,    37,    70,   161,    91,   145,
      -1,    37,    70,   146,    91,   128,    -1,    37,    70,   146,
      91,   145,    -1,    37,    96,    90,   468,    -1,    37,    67,
     468,    -1,    44,    50,   468,    -1,    44,    50,   300,   468,
      -1,    44,    50,   468,    80,   299,    -1,    44,    50,   300,
     468,    80,   299,    -1,   468,    -1,   299,    91,   468,    -1,
     140,   469,   113,    -1,    96,    33,   140,    -1,    44,    47,
     468,    -1,    44,    47,   140,   469,   113,   468,    -1,    44,
      47,   468,    80,   299,    -1,    44,    47,   140,   469,   113,
     468,    80,   299,    -1,    37,    95,   101,   470,   123,   318,
      -1,    37,    95,   101,   470,   118,    -1,    37,    95,   101,
     470,   439,   123,   318,    -1,    37,    95,   101,   470,   439,
     118,    -1,    37,    54,   161,    -1,    37,    54,   175,    -1,
     136,   166,    -1,   136,   312,   166,    -1,   136,   166,    78,
     440,    -1,   136,   312,   166,    78,   440,    -1,   133,   306,
     163,    -1,   317,   170,    -1,   306,   317,   170,    -1,    52,
     101,   470,   123,   318,    -1,    26,   217,   318,    -1,    30,
     136,   318,   166,   305,    -1,    27,    28,    -1,    66,    28,
      -1,    37,    38,   470,   304,   118,    -1,    37,    38,   470,
     304,   315,    -1,    37,    39,    38,   470,   304,   118,    -1,
      37,    39,    38,   470,   304,   315,    -1,    37,    40,    38,
     470,   304,   305,    -1,   313,    -1,   312,    91,   313,    -1,
     101,   470,    -1,   101,   470,   439,    -1,   133,   317,   163,
      -1,   133,   317,   163,    -1,   317,    -1,   318,    -1,   317,
      91,   318,    -1,   319,    -1,   356,    -1,   359,    -1,   362,
      -1,   363,    -1,   458,    -1,   459,    -1,   461,    -1,   460,
      -1,   462,    -1,   465,    -1,   471,    -1,   308,    -1,   309,
      -1,   310,    -1,   307,    -1,   305,    -1,   328,   320,    -1,
     165,   318,    -1,    58,   252,    -1,    59,   252,    -1,   197,
      -1,   230,    -1,    62,   230,    -1,   322,   340,    63,   318,
      -1,   322,    63,   318,    -1,    56,   321,   339,   323,   323,
      -1,    56,   321,   339,   323,    -1,    64,   101,   470,    -1,
     330,    -1,   335,    -1,   324,    -1,   326,    -1,   344,    -1,
     349,    -1,   345,    -1,   325,    -1,   326,    -1,   328,   327,
      -1,    56,   101,    -1,    57,    56,   101,    -1,   329,   331,
      -1,   332,    -1,   331,    91,   101,   332,    -1,   470,   127,
     318,    -1,   470,   439,   127,   318,    -1,   470,   333,   127,
     318,    -1,   470,   439,   333,   127,   318,    -1,   470,   334,
     127,   318,    -1,   470,   439,   334,   127,   318,    -1,   470,
     333,   334,   127,   318,    -1,   470,   439,   333,   334,   127,
     318,    -1,    80,   101,   470,    -1,   246,   101,   470,    -1,
      53,   101,   336,    -1,   338,    -1,   336,    91,   101,   338,
      -1,   343,    -1,   337,    91,   101,   343,    -1,   470,   123,
     318,    -1,   470,   439,   123,   318,    -1,   470,   334,   123,
     318,    -1,   470,   439,   334,   123,   318,    -1,   101,   470,
     127,   318,    -1,   101,   470,   439,   127,   318,    -1,   341,
      -1,   101,   470,    -1,   101,   470,   341,    -1,   333,    -1,
     333,   342,    -1,   342,    -1,    60,   101,   470,    61,   101,
     470,    -1,    61,   101,   470,    -1,    60,   101,   470,    -1,
     470,    -1,   191,   318,    -1,   151,   150,   346,    -1,   347,
      -1,   346,    91,   347,    -1,   101,   470,    -1,   101,   470,
     348,    -1,    90,   468,    -1,   149,   150,   350,    -1,    46,
     149,   150,   350,    -1,   351,    -1,   350,    91,   351,    -1,
     318,    -1,   318,   352,    -1,   353,    -1,   354,    -1,   355,
      -1,   353,   354,    -1,   353,   355,    -1,   354,   355,    -1,
     353,   354,   355,    -1,    79,    -1,    99,    -1,   108,   109,
      -1,   108,   110,    -1,    90,   468,    -1,    45,   101,   357,
     167,   318,    -1,   116,   101,   357,   167,   318,    -1,   358,
      -1,   357,    91,   101,   358,    -1,   470,   127,   318,    -1,
     470,   439,   127,   318,    -1,    32,   136,   317,   166,   360,
      96,   165,   318,    -1,    32,   136,   317,   166,   360,    96,
     101,   470,   165,   318,    -1,   361,    -1,   360,   361,    -1,
      84,   440,   165,   318,    -1,    84,   101,   470,    78,   440,
     165,   318,    -1,    41,   136,   317,   166,   177,   318,   107,
     318,    -1,   364,    -1,   363,   147,   364,    -1,   365,    -1,
     364,    76,   365,    -1,   367,    -1,   367,   380,   367,    -1,
     367,   381,   367,    -1,   367,   113,   367,    -1,   367,   142,
     367,    -1,    -1,   367,   137,   366,   367,    -1,   367,   135,
     367,    -1,   367,   124,   367,    -1,   367,   122,   367,    -1,
     368,    -1,   368,   235,   472,    -1,   368,   235,   472,   506,
      -1,   369,    -1,   369,   178,   369,    -1,   370,    -1,   369,
     155,   370,    -1,   369,   138,   370,    -1,   371,    -1,   370,
     173,   371,    -1,   370,   100,   371,    -1,   370,   126,   371,
      -1,   370,   139,   371,    -1,   372,    -1,   371,   180,   372,
      -1,   371,   189,   372,    -1,   373,    -1,   372,   130,   373,
      -1,   372,   117,   373,    -1,   374,    -1,   374,    71,   211,
     440,    -1,   375,    -1,   375,   179,    78,   440,    -1,   376,
      -1,   376,    85,    78,   438,    -1,   377,    -1,   377,    86,
      78,   438,    -1,   379,    -1,   378,   379,    -1,   155,    -1,
     138,    -1,   378,   155,    -1,   378,   138,    -1,   382,    -1,
     386,    -1,   383,    -1,   182,    -1,   187,    -1,   186,    -1,
     185,    -1,   184,    -1,   183,    -1,   131,    -1,   158,    -1,
     121,    -1,    31,   133,   317,   163,    -1,    31,   201,   133,
     317,   163,    -1,    31,   202,   133,   317,   163,    -1,    31,
     203,   133,   317,   163,    -1,   384,   133,   163,    -1,   384,
     133,   317,   163,    -1,   385,    -1,   384,   385,    -1,   156,
     470,    15,    -1,   156,    16,    -1,   387,    -1,   387,   388,
      -1,   172,   388,    -1,   388,    -1,   171,    -1,   389,    -1,
     389,   171,   388,    -1,   389,   172,   388,    -1,   390,    -1,
     399,    -1,   391,    -1,   391,   400,    -1,   394,    -1,   394,
     400,    -1,   392,   396,    -1,   393,    -1,    89,    -1,    97,
      -1,    82,    -1,   169,    -1,    98,    -1,   120,    -1,   119,
      -1,   396,    -1,    83,   396,    -1,   395,   396,    -1,   103,
      -1,   152,    -1,    74,    -1,   160,    -1,   159,    -1,    75,
      -1,   444,    -1,   397,    -1,   470,    -1,   398,    -1,   173,
      -1,    10,    -1,    17,    -1,   402,    -1,   402,   400,    -1,
     401,    -1,   400,   401,    -1,   134,   317,   164,    -1,   403,
      -1,   405,    -1,   406,    -1,   407,    -1,   410,    -1,   412,
      -1,   408,    -1,   409,    -1,   404,    -1,   456,    -1,    94,
      -1,   129,    -1,   105,    -1,   101,   470,    -1,   136,   166,
      -1,   136,   317,   166,    -1,   102,    -1,   148,   133,   317,
     163,    -1,   181,   133,   317,   163,    -1,   470,   136,   166,
      -1,   470,   136,   411,   166,    -1,   318,    -1,   411,    91,
     318,    -1,   413,    -1,   431,    -1,   414,    -1,   428,    -1,
     429,    -1,   137,   470,   418,   111,    -1,   137,   470,   416,
     418,   111,    -1,   137,   470,   418,   176,   174,   470,   418,
     176,    -1,   137,   470,   418,   176,   415,   174,   470,   418,
     176,    -1,   137,   470,   416,   418,   176,   174,   470,   418,
     176,    -1,   137,   470,   416,   418,   176,   415,   174,   470,
     418,   176,    -1,   426,    -1,   415,   426,    -1,   417,    -1,
     416,   417,    -1,    25,   470,   418,   113,   418,   419,    -1,
      -1,    25,    -1,   162,   420,   162,    -1,    77,   422,    77,
      -1,    -1,   421,    -1,   115,    -1,   424,    -1,   421,   115,
      -1,   421,   424,    -1,    -1,   423,    -1,   114,    -1,   425,
      -1,   423,   114,    -1,   423,   425,    -1,    19,    -1,   427,
      -1,     4,    -1,   427,    -1,   413,    -1,     9,    -1,   430,
      -1,   427,    -1,     8,    -1,   104,    -1,   106,    -1,   314,
      -1,   192,    21,   193,    -1,   192,   193,    -1,   153,    14,
     154,    -1,   153,    14,     7,    -1,    87,     6,    -1,   432,
      -1,   433,    -1,   434,    -1,   435,    -1,   436,    -1,   437,
      -1,    34,   133,   317,   163,    -1,    33,   470,   133,   163,
      -1,    33,   470,   133,   317,   163,    -1,    33,   133,   317,
     163,   133,   163,    -1,    33,   133,   317,   163,   133,   317,
     163,    -1,    81,   470,   133,   163,    -1,    81,   470,   133,
     317,   163,    -1,    81,   133,   317,   163,   133,   163,    -1,
      81,   133,   317,   163,   133,   317,   163,    -1,    35,   133,
     317,   163,    -1,    36,   133,   317,   163,    -1,    42,   469,
     133,   163,    -1,    42,   469,   133,   317,   163,    -1,    42,
     133,   317,   163,   133,   163,    -1,    42,   133,   317,   163,
     133,   317,   163,    -1,   443,    -1,   443,   125,    -1,    78,
     440,    -1,   442,    -1,   442,   441,    -1,   190,   136,   166,
      -1,   125,    -1,   173,    -1,   155,    -1,   443,    -1,   444,
      -1,   132,   136,   166,    -1,   470,    -1,   446,    -1,   452,
      -1,   450,    -1,   453,    -1,   451,    -1,   449,    -1,   448,
      -1,   447,    -1,   445,    -1,   205,   136,   166,    -1,    69,
     136,   166,    -1,    69,   136,   452,   166,    -1,    69,   136,
     453,   166,    -1,    35,   136,   166,    -1,    36,   136,   166,
      -1,    42,   136,   166,    -1,    42,   136,   469,   166,    -1,
      42,   136,    20,   166,    -1,    81,   136,   166,    -1,    81,
     136,   470,   166,    -1,    81,   136,   470,    91,   454,   166,
      -1,    81,   136,   173,   166,    -1,    81,   136,   173,    91,
     454,   166,    -1,   168,   470,   166,    -1,    33,   136,   166,
      -1,    33,   136,   470,   166,    -1,    33,   136,   470,    91,
     454,   166,    -1,    33,   136,   470,    91,   455,   166,    -1,
      33,   136,   173,   166,    -1,    33,   136,   173,    91,   454,
     166,    -1,    33,   136,   173,    91,   455,   166,    -1,    68,
     136,   470,   166,    -1,   470,    -1,   470,   125,    -1,    20,
      -1,    37,   200,   201,    -1,    37,   200,   202,    -1,    37,
     200,   203,    -1,   206,   205,   318,   213,   318,    -1,   206,
     205,   318,    78,   212,   213,   318,    -1,   206,   205,   318,
      78,   214,   213,   318,    -1,   206,   205,   318,   198,   318,
      -1,   206,   205,   318,   199,   318,    -1,   206,   207,   318,
     213,   318,    -1,   206,   207,   318,    78,   212,   213,   318,
      -1,   206,   207,   318,    78,   214,   213,   318,    -1,   206,
     207,   318,   198,   318,    -1,   206,   207,   318,   199,   318,
      -1,   204,   205,   318,    -1,   204,   207,   318,    -1,   209,
     205,   318,   217,   318,    -1,   209,   210,   211,   205,   318,
     217,   318,    -1,   208,   205,   318,    78,   318,    -1,   216,
     101,   463,   215,   318,   165,   318,    -1,   464,    -1,   463,
      91,   101,   464,    -1,   470,   123,   318,    -1,   218,   133,
     318,   163,   466,    -1,   467,    -1,   466,   467,    -1,   219,
     136,   397,   166,   315,    -1,   219,   136,   397,    91,   101,
     470,   166,   315,    -1,   219,   136,   397,    91,   101,   470,
      91,   101,   470,   166,   315,    -1,   219,   136,   397,    91,
     101,   470,    91,   101,   470,    91,   101,   470,   166,   315,
      -1,    20,    -1,    18,    -1,    18,    -1,   108,    -1,    81,
      -1,    36,    -1,    69,    -1,    33,    -1,   132,    -1,    41,
      -1,   205,    -1,    42,    -1,    72,    -1,    68,    -1,    35,
      -1,    32,    -1,   190,    -1,    73,    -1,   224,    -1,    67,
      -1,   202,    -1,   201,    -1,   126,    -1,    34,    -1,   236,
      -1,   223,    -1,   226,    -1,   225,    -1,   253,    -1,   254,
      -1,   257,    -1,   255,    -1,   258,    -1,   229,    -1,   231,
      -1,    49,    -1,   197,    -1,   230,    -1,    43,    -1,   203,
      -1,   216,    -1,   210,    -1,   182,    -1,   187,    -1,   186,
      -1,   185,    -1,   184,    -1,   183,    -1,    80,    -1,    95,
      -1,   165,    -1,    56,    -1,    57,    -1,    58,    -1,    59,
      -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,
      -1,   127,    -1,    53,    -1,   191,    -1,   150,    -1,   151,
      -1,   149,    -1,    46,    -1,    79,    -1,    99,    -1,   109,
      -1,   110,    -1,    90,    -1,    45,    -1,   116,    -1,   167,
      -1,    84,    -1,    78,    -1,   177,    -1,   107,    -1,   147,
      -1,    76,    -1,    71,    -1,   211,    -1,    85,    -1,   178,
      -1,   100,    -1,   139,    -1,   180,    -1,   130,    -1,   117,
      -1,    31,    -1,    86,    -1,   179,    -1,   131,    -1,   161,
      -1,   175,    -1,   140,    -1,   118,    -1,   112,    -1,   146,
      -1,   128,    -1,   145,    -1,    37,    -1,    54,    -1,    65,
      -1,    96,    -1,    70,    -1,    48,    -1,   195,    -1,    44,
      -1,    50,    -1,    47,    -1,    38,    -1,   246,    -1,   235,
      -1,   251,    -1,   252,    -1,   228,    -1,   241,    -1,   249,
      -1,   245,    -1,   227,    -1,   240,    -1,   250,    -1,   244,
      -1,   239,    -1,   238,    -1,   222,    -1,   221,    -1,   243,
      -1,   232,    -1,   233,    -1,   256,    -1,   248,    -1,   247,
      -1,   242,    -1,   209,    -1,   215,    -1,   212,    -1,   206,
      -1,   199,    -1,   198,    -1,   200,    -1,   217,    -1,   207,
      -1,   208,    -1,   214,    -1,   204,    -1,   213,    -1,    39,
      -1,   148,    -1,   181,    -1,    26,    -1,    28,    -1,    27,
      -1,    66,    -1,    52,    -1,   220,   101,   337,    55,   133,
     318,   163,    -1,    55,   133,   318,   163,    -1,   474,    -1,
     474,   473,    -1,   474,   251,   368,    -1,   474,   473,   251,
     368,    -1,   483,    -1,   481,    -1,   473,   483,    -1,   473,
     481,    -1,   475,    -1,   474,   237,   475,    -1,   476,    -1,
     475,   234,   476,    -1,   477,    -1,   476,   236,   127,   477,
      -1,   478,    -1,   236,   478,    -1,   479,    -1,   479,   502,
      -1,   136,   472,   166,    -1,   480,    -1,   480,   498,    -1,
     403,    -1,   133,   317,   163,    -1,   482,    -1,   501,    -1,
     500,    -1,   503,    -1,   497,    -1,   148,    -1,   484,    -1,
     485,    -1,   486,    -1,   487,    -1,   490,    -1,   495,    -1,
     496,    -1,   240,    -1,   250,    -1,    84,   223,    -1,    84,
     226,    -1,   217,   225,    -1,   253,   225,    -1,   225,   223,
      -1,   225,   226,    -1,   217,   254,    -1,   253,   254,    -1,
     217,   257,   489,    -1,   217,   257,    96,    -1,   217,   257,
     136,   489,   166,    -1,   217,   257,   136,   489,    91,   488,
     166,    -1,   217,   257,   136,    96,   166,    -1,   217,   257,
     136,    96,    91,   488,   166,    -1,   253,   257,    -1,   489,
      -1,   488,    91,   489,    -1,    80,    20,    -1,    80,    20,
     244,    20,    -1,    80,    20,   499,   239,    -1,    80,    20,
     244,    20,   499,   239,    -1,   217,   255,   256,   492,    -1,
     217,   255,   256,   492,   491,    -1,   217,    96,   255,   256,
      -1,   217,    96,   255,   256,   491,    -1,   253,   255,   256,
      -1,   494,    -1,   491,   494,    -1,    80,    20,    -1,   136,
     493,   166,    -1,    20,    -1,   493,    20,    -1,   180,   492,
      -1,   117,   492,    -1,   238,    20,    -1,   217,   258,    -1,
     253,   258,    -1,    80,   197,    -1,    80,   230,    -1,   229,
     231,    -1,   222,    -1,   222,    49,    -1,   221,    -1,   221,
     256,    -1,   243,    -1,   232,   371,    -1,    80,   110,   371,
      -1,    80,    43,   371,    -1,   233,   371,   178,   371,    -1,
     228,   499,   504,    -1,   252,   371,   504,    -1,   241,   499,
     249,    -1,   245,   505,    -1,   227,   505,    -1,   256,    -1,
     248,    -1,   242,    -1,   247,    -1,   242,    -1,   253,   231,
     371,    -1
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
     315,   319,   325,   329,   335,   338,   341,   347,   353,   360,
     367,   374,   376,   380,   383,   387,   391,   395,   397,   399,
     403,   405,   407,   409,   411,   413,   415,   417,   419,   421,
     423,   425,   427,   429,   431,   433,   435,   437,   440,   443,
     446,   449,   451,   453,   456,   461,   465,   471,   476,   480,
     482,   484,   486,   488,   490,   492,   494,   496,   498,   501,
     504,   508,   511,   513,   518,   522,   527,   532,   538,   543,
     549,   555,   562,   566,   570,   574,   576,   581,   583,   588,
     592,   597,   602,   608,   613,   619,   621,   624,   628,   630,
     633,   635,   642,   646,   650,   652,   655,   659,   661,   665,
     668,   672,   675,   679,   684,   686,   690,   692,   695,   697,
     699,   701,   704,   707,   710,   714,   716,   718,   721,   724,
     727,   733,   739,   741,   746,   750,   755,   764,   775,   777,
     780,   785,   793,   802,   804,   808,   810,   814,   816,   820,
     824,   828,   832,   833,   838,   842,   846,   850,   852,   856,
     861,   863,   867,   869,   873,   877,   879,   883,   887,   891,
     895,   897,   901,   905,   907,   911,   915,   917,   922,   924,
     929,   931,   936,   938,   943,   945,   948,   950,   952,   955,
     958,   960,   962,   964,   966,   968,   970,   972,   974,   976,
     978,   980,   982,   987,   993,   999,  1005,  1009,  1014,  1016,
    1019,  1023,  1026,  1028,  1031,  1034,  1036,  1038,  1040,  1044,
    1048,  1050,  1052,  1054,  1057,  1059,  1062,  1065,  1067,  1069,
    1071,  1073,  1075,  1077,  1079,  1081,  1083,  1086,  1089,  1091,
    1093,  1095,  1097,  1099,  1101,  1103,  1105,  1107,  1109,  1111,
    1113,  1115,  1117,  1120,  1122,  1125,  1129,  1131,  1133,  1135,
    1137,  1139,  1141,  1143,  1145,  1147,  1149,  1151,  1153,  1155,
    1158,  1161,  1165,  1167,  1172,  1177,  1181,  1186,  1188,  1192,
    1194,  1196,  1198,  1200,  1202,  1207,  1213,  1222,  1232,  1242,
    1253,  1255,  1258,  1260,  1263,  1270,  1271,  1273,  1277,  1281,
    1282,  1284,  1286,  1288,  1291,  1294,  1295,  1297,  1299,  1301,
    1304,  1307,  1309,  1311,  1313,  1315,  1317,  1319,  1321,  1323,
    1325,  1327,  1329,  1331,  1335,  1338,  1342,  1346,  1349,  1351,
    1353,  1355,  1357,  1359,  1361,  1366,  1371,  1377,  1384,  1392,
    1397,  1403,  1410,  1418,  1423,  1428,  1433,  1439,  1446,  1454,
    1456,  1459,  1462,  1464,  1467,  1471,  1473,  1475,  1477,  1479,
    1481,  1485,  1487,  1489,  1491,  1493,  1495,  1497,  1499,  1501,
    1503,  1505,  1509,  1513,  1518,  1523,  1527,  1531,  1535,  1540,
    1545,  1549,  1554,  1561,  1566,  1573,  1577,  1581,  1586,  1593,
    1600,  1605,  1612,  1619,  1624,  1626,  1629,  1631,  1635,  1639,
    1643,  1649,  1657,  1665,  1671,  1677,  1683,  1691,  1699,  1705,
    1711,  1715,  1719,  1725,  1733,  1739,  1747,  1749,  1754,  1758,
    1764,  1766,  1769,  1775,  1784,  1796,  1811,  1813,  1815,  1817,
    1819,  1821,  1823,  1825,  1827,  1829,  1831,  1833,  1835,  1837,
    1839,  1841,  1843,  1845,  1847,  1849,  1851,  1853,  1855,  1857,
    1859,  1861,  1863,  1865,  1867,  1869,  1871,  1873,  1875,  1877,
    1879,  1881,  1883,  1885,  1887,  1889,  1891,  1893,  1895,  1897,
    1899,  1901,  1903,  1905,  1907,  1909,  1911,  1913,  1915,  1917,
    1919,  1921,  1923,  1925,  1927,  1929,  1931,  1933,  1935,  1937,
    1939,  1941,  1943,  1945,  1947,  1949,  1951,  1953,  1955,  1957,
    1959,  1961,  1963,  1965,  1967,  1969,  1971,  1973,  1975,  1977,
    1979,  1981,  1983,  1985,  1987,  1989,  1991,  1993,  1995,  1997,
    1999,  2001,  2003,  2005,  2007,  2009,  2011,  2013,  2015,  2017,
    2019,  2021,  2023,  2025,  2027,  2029,  2031,  2033,  2035,  2037,
    2039,  2041,  2043,  2045,  2047,  2049,  2051,  2053,  2055,  2057,
    2059,  2061,  2063,  2065,  2067,  2069,  2071,  2073,  2075,  2077,
    2079,  2081,  2083,  2085,  2087,  2089,  2091,  2093,  2095,  2097,
    2099,  2101,  2103,  2105,  2107,  2109,  2111,  2113,  2115,  2117,
    2119,  2121,  2123,  2125,  2133,  2138,  2140,  2143,  2147,  2152,
    2154,  2156,  2159,  2162,  2164,  2168,  2170,  2174,  2176,  2181,
    2183,  2186,  2188,  2191,  2195,  2197,  2200,  2202,  2206,  2208,
    2210,  2212,  2214,  2216,  2218,  2220,  2222,  2224,  2226,  2228,
    2230,  2232,  2234,  2236,  2239,  2242,  2245,  2248,  2251,  2254,
    2257,  2260,  2264,  2268,  2274,  2282,  2288,  2296,  2299,  2301,
    2305,  2308,  2313,  2318,  2325,  2330,  2336,  2341,  2347,  2351,
    2353,  2356,  2359,  2363,  2365,  2368,  2371,  2374,  2377,  2380,
    2383,  2386,  2389,  2392,  2394,  2397,  2399,  2402,  2404,  2407,
    2411,  2415,  2420,  2424,  2428,  2432,  2435,  2438,  2440,  2442,
    2444,  2446,  2448
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   820,   820,   821,   831,   836,   842,   847,   859,   864,
     874,   881,   893,   905,   917,   923,   929,   941,   947,   961,
     967,   981,   982,   983,   984,   990,   991,   992,   995,  1002,
    1003,  1004,  1005,  1006,  1007,  1008,  1011,  1018,  1019,  1031,
    1043,  1048,  1059,  1065,  1077,  1090,  1101,  1106,  1118,  1123,
    1134,  1140,  1146,  1152,  1171,  1182,  1193,  1200,  1207,  1214,
    1227,  1233,  1248,  1252,  1262,  1268,  1275,  1281,  1295,  1302,
    1309,  1316,  1329,  1334,  1346,  1350,  1354,  1358,  1365,  1372,
    1378,  1387,  1394,  1401,  1408,  1412,  1419,  1427,  1436,  1445,
    1454,  1469,  1477,  1491,  1497,  1509,  1517,  1528,  1539,  1545,
    1557,  1558,  1559,  1560,  1561,  1564,  1565,  1566,  1567,  1568,
    1570,  1571,  1574,  1575,  1576,  1577,  1578,  1585,  1594,  1601,
    1605,  1613,  1617,  1621,  1628,  1632,  1639,  1644,  1653,  1662,
    1663,  1664,  1668,  1668,  1668,  1668,  1668,  1671,  1677,  1686,
    1690,  1700,  1711,  1717,  1731,  1738,  1746,  1755,  1765,  1773,
    1782,  1791,  1806,  1818,  1829,  1841,  1847,  1859,  1865,  1879,
    1887,  1896,  1904,  1916,  1922,  1932,  1933,  1937,  1945,  1949,
    1954,  1958,  1962,  1966,  1973,  1988,  1996,  2006,  2012,  2023,
    2029,  2038,  2048,  2053,  2065,  2071,  2085,  2091,  2103,  2110,
    2117,  2124,  2131,  2138,  2145,  2158,  2162,  2172,  2177,  2188,
    2199,  2206,  2219,  2226,  2238,  2244,  2257,  2264,  2278,  2284,
    2296,  2302,  2315,  2326,  2330,  2341,  2345,  2364,  2368,  2376,
    2384,  2392,  2400,  2400,  2408,  2416,  2424,  2438,  2442,  2449,
    2462,  2466,  2477,  2481,  2485,  2495,  2499,  2503,  2507,  2511,
    2521,  2525,  2530,  2541,  2545,  2549,  2559,  2563,  2575,  2579,
    2591,  2595,  2607,  2611,  2623,  2627,  2639,  2643,  2647,  2651,
    2663,  2667,  2671,  2681,  2685,  2689,  2693,  2697,  2701,  2711,
    2715,  2719,  2729,  2733,  2739,  2745,  2757,  2763,  2775,  2781,
    2795,  2802,  2843,  2847,  2851,  2855,  2867,  2877,  2888,  2893,
    2903,  2907,  2917,  2923,  2929,  2935,  2947,  2953,  2964,  2968,
    2972,  2976,  2980,  2984,  2988,  2998,  3002,  3012,  3018,  3030,
    3034,  3038,  3042,  3046,  3061,  3065,  3075,  3079,  3089,  3096,
    3103,  3116,  3120,  3132,  3138,  3152,  3163,  3167,  3171,  3175,
    3179,  3183,  3187,  3191,  3201,  3205,  3215,  3220,  3225,  3236,
    3246,  3250,  3261,  3271,  3282,  3338,  3344,  3356,  3362,  3374,
    3378,  3388,  3392,  3396,  3406,  3414,  3422,  3430,  3438,  3446,
    3461,  3467,  3479,  3485,  3498,  3507,  3509,  3515,  3520,  3532,
    3535,  3542,  3548,  3554,  3562,  3577,  3580,  3587,  3593,  3599,
    3607,  3621,  3626,  3637,  3642,  3653,  3658,  3663,  3669,  3681,
    3687,  3692,  3697,  3708,  3713,  3728,  3733,  3750,  3765,  3769,
    3773,  3777,  3781,  3785,  3795,  3806,  3812,  3818,  3823,  3845,
    3851,  3857,  3862,  3873,  3884,  3895,  3901,  3907,  3912,  3923,
    3929,  3941,  3953,  3959,  3965,  4002,  4007,  4012,  4023,  4027,
    4031,  4041,  4052,  4056,  4060,  4064,  4068,  4072,  4076,  4080,
    4084,  4094,  4104,  4108,  4113,  4124,  4134,  4144,  4148,  4152,
    4162,  4168,  4174,  4180,  4186,  4198,  4209,  4216,  4223,  4230,
    4237,  4244,  4251,  4264,  4285,  4292,  4312,  4352,  4357,  4360,
    4368,  4374,  4380,  4386,  4392,  4399,  4405,  4411,  4417,  4423,
    4435,  4440,  4450,  4456,  4468,  4494,  4505,  4511,  4524,  4538,
    4545,  4552,  4563,  4570,  4578,  4587,  4600,  4603,  4621,  4622,
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
    4743,  4744,  4745,  4746,  4747,  4748,  4749,  4750,  4751,  4752,
    4753,  4754,  4755,  4756,  4757,  4758,  4759,  4760,  4761,  4762,
    4763,  4764,  4765,  4766,  4767,  4768,  4769,  4770,  4771,  4772,
    4773,  4774,  4775,  4786,  4792,  4809,  4813,  4817,  4821,  4831,
    4834,  4837,  4840,  4849,  4852,  4861,  4864,  4873,  4876,  4885,
    4888,  4897,  4900,  4903,  4912,  4915,  4924,  4928,  4938,  4941,
    4944,  4947,  4950,  4959,  4968,  4972,  4976,  4980,  4984,  4988,
    4992,  5002,  5005,  5008,  5011,  5020,  5023,  5026,  5029,  5038,
    5041,  5050,  5053,  5056,  5059,  5062,  5065,  5068,  5077,  5080,
    5089,  5092,  5095,  5098,  5107,  5110,  5113,  5116,  5119,  5128,
    5131,  5140,  5143,  5152,  5155,  5164,  5167,  5176,  5185,  5188,
    5197,  5200,  5203,  5212,  5215,  5218,  5221,  5224,  5233,  5237,
    5241,  5245,  5255,  5264,  5274,  5283,  5286,  5295,  5298,  5301,
    5310,  5313,  5322
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
     265,   266,   267,   268,   269,   270,   271,   272,   273
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 7922;
  const int xquery_parser::yynnts_ = 233;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 437;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 274;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 528;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5330 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"


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
  driver.set_expr (new ParseErrorNode (driver.createQueryLoc (loc), XPST0003, msg));
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

