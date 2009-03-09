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
#line 816 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"

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
#line 709 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 105: /* "\"'DOUBLE'\"" */
#line 708 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 129: /* "\"'INTEGER'\"" */
#line 707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 277: /* "VersionDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 278: /* "MainModule" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 279: /* "LibraryModule" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 280: /* "ModuleDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 281: /* "Prolog" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 282: /* "SIND_DeclList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 283: /* "VFO_DeclList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 284: /* "SIND_Decl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 285: /* "VFO_Decl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "Setter" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "Import" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "NamespaceDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "BoundarySpaceDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "DefaultNamespaceDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "OptionDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "OrderingModeDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "EmptyOrderDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "CopyNamespacesDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "DefaultCollationDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "BaseURIDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "SchemaImport" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "URILiteralList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "SchemaPrefix" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "ModuleImport" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "VarNameAndType" */
#line 721 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };
#line 346 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "VarDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "ConstructionDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 356 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "FunctionSig" */
#line 721 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 361 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "Block" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 366 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "BlockBody" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 371 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "AssignExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 376 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "ExitExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 381 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "WhileExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 386 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "FlowCtlStatement" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 391 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "FunctionDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 396 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "ParamList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 401 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "Param" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 406 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "EnclosedExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 411 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "BracedExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 416 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "QueryBody" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 421 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "Expr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 426 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "ExprSingle" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 431 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "FLWORExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 436 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "ReturnExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 441 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "FLWORWinCond" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 446 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "WindowClause" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 451 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "CountClause" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 456 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "ForLetWinClause" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 461 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "FLWORClauseList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 466 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "ForClause" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 471 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "VarInDeclList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "VarInDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 481 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "PositionalVar" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 486 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "LetClause" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 491 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "VarGetsDeclList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 496 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "EvalVarDeclList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 501 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "VarGetsDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 506 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "WindowVarDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 511 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "WindowVars" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 516 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "WindowVars3" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 521 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "WindowVars2" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "EvalVarDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "WhereClause" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 536 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "GroupByClause" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "GroupSpecList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "GroupSpec" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 551 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "GroupCollationSpec" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 556 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "OrderByClause" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 561 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "OrderSpecList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 566 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "OrderSpec" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 571 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "OrderModifier" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 576 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "OrderDirSpec" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 581 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "OrderEmptySpec" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 586 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "OrderCollationSpec" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 591 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "QuantifiedExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 596 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "QVarInDeclList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 601 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "QVarInDecl" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 606 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "TypeswitchExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 611 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "CaseClauseList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 616 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "CaseClause" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 621 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IfExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 626 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "OrExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 631 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "AndExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 636 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "ComparisonExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 641 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FTContainsExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 646 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "RangeExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 651 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "AdditiveExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 656 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "MultiplicativeExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 661 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "UnionExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 666 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "IntersectExceptExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 671 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "InstanceofExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 676 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "TreatExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 681 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "CastableExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 686 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "CastExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 691 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "UnaryExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 696 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "SignList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 701 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ValueExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 706 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ValueComp" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 711 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "NodeComp" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 716 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "ValidateExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 721 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ExtensionExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 726 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "PragmaList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 731 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Pragma" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 736 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "PathExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 741 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "RelativePathExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 746 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "StepExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 751 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "AxisStep" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 756 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ForwardStep" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 761 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ForwardAxis" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 766 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "AbbrevForwardStep" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 771 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ReverseStep" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 776 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ReverseAxis" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 781 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "NodeTest" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 786 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "NameTest" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 791 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "Wildcard" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 796 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "FilterExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 801 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "PredicateList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 806 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "Predicate" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 811 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "PrimaryExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 816 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "Literal" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 821 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "NumericLiteral" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 826 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarRef" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 831 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ParenthesizedExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 836 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "ContextItemExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 841 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "OrderedExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 846 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "UnorderedExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 851 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "FunctionCall" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 856 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "ArgList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 861 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "Constructor" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 866 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "DirectConstructor" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 871 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "DirElemConstructor" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 876 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "DirElemContentList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 881 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "DirAttributeList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 886 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "DirAttr" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 891 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "DirAttributeValue" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 896 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "Opt_QuoteAttrContentList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 901 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "QuoteAttrContentList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 906 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "Opt_AposAttrContentList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 911 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "AposAttrContentList" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 916 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "QuoteAttrValueContent" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 921 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "AposAttrValueContent" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 926 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "DirElemContent" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 931 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "CommonContent" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 936 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "DirCommentConstructor" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 941 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "DirPIConstructor" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 946 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "CDataSection" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 951 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "ComputedConstructor" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 956 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "CompDocConstructor" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 961 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "CompElemConstructor" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 966 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CompAttrConstructor" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 971 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "CompTextConstructor" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 976 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "CompCommentConstructor" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 981 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "CompPIConstructor" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 986 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "SingleType" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 991 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "TypeDeclaration" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 996 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "SequenceType" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1001 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OccurrenceIndicator" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1006 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "ItemType" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1011 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "AtomicType" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1016 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "KindTest" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1021 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "AnyKindTest" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1026 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "DocumentTest" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1031 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "TextTest" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1036 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "CommentTest" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1041 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "PITest" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1046 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "AttributeTest" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1051 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SchemaAttributeTest" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1056 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "ElementTest" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1061 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SchemaElementTest" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1066 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "TypeName" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1071 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "TypeName_WITH_HOOK" */
#line 717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1076 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "StringLiteral" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1081 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "InsertExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1086 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "DeleteExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1091 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ReplaceExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1096 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "RenameExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1101 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "TransformExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1106 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "VarNameList" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1111 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "VarNameDecl" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1116 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "TryExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1121 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "CatchListExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1126 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "CatchExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1131 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "EvalExpr" */
#line 719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1136 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 112 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}
  /* Line 547 of yacc.c.  */
#line 1217 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
#line 834 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 4:
#line 844 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 849 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 855 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 7:
#line 860 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 8:
#line 872 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		;}
    break;

  case 9:
#line 877 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    ;}
    break;

  case 10:
#line 887 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 11:
#line 894 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		;}
    break;

  case 12:
#line 906 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 13:
#line 918 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval)));
		;}
    break;

  case 14:
#line 930 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 15:
#line 936 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 16:
#line 942 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 17:
#line 954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 18:
#line 960 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 974 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 20:
#line 980 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 39:
#line 1044 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 40:
#line 1056 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 41:
#line 1061 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 42:
#line 1072 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 43:
#line 1078 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 44:
#line 1090 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 45:
#line 1103 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		;}
    break;

  case 46:
#line 1114 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 47:
#line 1119 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 48:
#line 1131 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 49:
#line 1136 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 50:
#line 1147 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 51:
#line 1153 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 52:
#line 1159 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 53:
#line 1165 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 54:
#line 1184 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 55:
#line 1195 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 56:
#line 1206 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 57:
#line 1213 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		;}
    break;

  case 58:
#line 1220 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 59:
#line 1227 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 60:
#line 1240 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 61:
#line 1246 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 62:
#line 1261 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 63:
#line 1265 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 64:
#line 1275 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 65:
#line 1281 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		;}
    break;

  case 66:
#line 1288 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 67:
#line 1294 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		;}
    break;

  case 68:
#line 1305 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (driver.symtab.get((off_t) (yysemantic_stack_[(2) - (2)].sval)), NULL);
    ;}
    break;

  case 69:
#line 1309 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (driver.symtab.get((off_t) (yysemantic_stack_[(3) - (2)].sval)),
                               dynamic_cast<TypeDeclaration *> ((yysemantic_stack_[(3) - (3)].node)));
    ;}
    break;

  case 70:
#line 1319 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(5) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								nt->name,
								nt->type,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 71:
#line 1327 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(4) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
		;}
    break;

  case 72:
#line 1333 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(6) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
		;}
    break;

  case 73:
#line 1345 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 74:
#line 1350 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 75:
#line 1362 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 76:
#line 1366 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 77:
#line 1370 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 78:
#line 1374 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 79:
#line 1381 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    ;}
    break;

  case 80:
#line 1388 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = new BlockBody (LOC ((yyloc)));
      blk->add ((yysemantic_stack_[(2) - (1)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 81:
#line 1394 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 82:
#line 1403 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), driver.symtab.get ((off_t)(yysemantic_stack_[(5) - (3)].sval)), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 83:
#line 1410 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 84:
#line 1417 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr)));
    ;}
    break;

  case 85:
#line 1424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 86:
#line 1428 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 87:
#line 1435 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval))),
                &* (yysemantic_stack_[(5) - (4)].fnsig)->param, &* (yysemantic_stack_[(5) - (4)].fnsig)->ret, NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
		;}
    break;

  case 88:
#line 1443 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval))),
                &* (yysemantic_stack_[(5) - (4)].fnsig)->param, &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
								(yysemantic_stack_[(5) - (5)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
		;}
    break;

  case 89:
#line 1452 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
								&* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern_update);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 90:
#line 1461 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
                &* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_update);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 91:
#line 1470 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
                &* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 92:
#line 1485 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 93:
#line 1493 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 94:
#line 1507 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 95:
#line 1513 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 96:
#line 1525 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 97:
#line 1533 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 98:
#line 1544 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 99:
#line 1555 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = new Expr(LOC ((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 100:
#line 1561 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 118:
#line 1601 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 119:
#line 1610 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 120:
#line 1617 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    ;}
    break;

  case 121:
#line 1621 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    ;}
    break;

  case 122:
#line 1629 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    ;}
    break;

  case 123:
#line 1633 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    ;}
    break;

  case 124:
#line 1637 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    ;}
    break;

  case 125:
#line 1644 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 126:
#line 1648 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 127:
#line 1655 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)), dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 128:
#line 1660 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    ;}
    break;

  case 129:
#line 1669 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 138:
#line 1687 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 139:
#line 1693 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 140:
#line 1702 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    ;}
    break;

  case 141:
#line 1706 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    ;}
    break;

  case 142:
#line 1716 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		;}
    break;

  case 143:
#line 1727 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 144:
#line 1733 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 145:
#line 1747 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 146:
#line 1754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 147:
#line 1762 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 148:
#line 1771 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 149:
#line 1781 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 150:
#line 1789 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 151:
#line 1798 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 152:
#line 1807 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 153:
#line 1822 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 154:
#line 1834 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 155:
#line 1845 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 156:
#line 1857 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 157:
#line 1863 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 158:
#line 1875 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 159:
#line 1881 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 160:
#line 1895 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 161:
#line 1903 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 162:
#line 1912 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 163:
#line 1920 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 164:
#line 1932 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 165:
#line 1938 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 167:
#line 1949 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)), "", "");
    ;}
    break;

  case 168:
#line 1953 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
    ;}
    break;

  case 169:
#line 1961 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    ;}
    break;

  case 170:
#line 1965 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    ;}
    break;

  case 172:
#line 1974 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)));
    ;}
    break;

  case 173:
#line 1978 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 174:
#line 1982 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)), "");
    ;}
    break;

  case 175:
#line 1989 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 176:
#line 2004 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 177:
#line 2012 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 178:
#line 2022 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 179:
#line 2028 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 180:
#line 2039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 181:
#line 2045 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 182:
#line 2054 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 183:
#line 2064 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 184:
#line 2069 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 185:
#line 2081 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 186:
#line 2087 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 187:
#line 2101 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 188:
#line 2107 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 189:
#line 2119 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 190:
#line 2126 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 191:
#line 2133 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 192:
#line 2140 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 193:
#line 2147 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 194:
#line 2154 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 195:
#line 2161 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 196:
#line 2174 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 197:
#line 2178 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 198:
#line 2188 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 199:
#line 2193 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 200:
#line 2204 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 201:
#line 2215 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 202:
#line 2222 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 203:
#line 2235 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 204:
#line 2242 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 205:
#line 2254 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 206:
#line 2260 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 207:
#line 2273 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 208:
#line 2280 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 209:
#line 2294 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 210:
#line 2300 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 211:
#line 2312 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 212:
#line 2318 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 213:
#line 2331 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 214:
#line 2342 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 215:
#line 2346 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 216:
#line 2357 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 217:
#line 2361 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 218:
#line 2380 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 219:
#line 2384 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 220:
#line 2392 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 221:
#line 2400 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 222:
#line 2408 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 223:
#line 2415 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 224:
#line 2416 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 225:
#line 2424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 226:
#line 2432 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 227:
#line 2440 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 228:
#line 2454 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 229:
#line 2458 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 230:
#line 2465 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 231:
#line 2478 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 232:
#line 2482 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 233:
#line 2493 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 234:
#line 2497 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 235:
#line 2501 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 236:
#line 2511 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 237:
#line 2515 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 238:
#line 2519 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 239:
#line 2523 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 240:
#line 2527 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 241:
#line 2537 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 242:
#line 2541 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 243:
#line 2546 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 244:
#line 2557 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 245:
#line 2561 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 246:
#line 2565 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 247:
#line 2575 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 248:
#line 2579 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 249:
#line 2591 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 250:
#line 2595 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 251:
#line 2607 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 252:
#line 2611 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 253:
#line 2623 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 254:
#line 2627 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 255:
#line 2639 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 256:
#line 2643 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 257:
#line 2655 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 258:
#line 2659 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 259:
#line 2663 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 260:
#line 2667 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 261:
#line 2679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 262:
#line 2683 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 263:
#line 2687 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 264:
#line 2697 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 265:
#line 2701 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 266:
#line 2705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 267:
#line 2709 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 268:
#line 2713 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 269:
#line 2717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 270:
#line 2727 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 271:
#line 2731 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 272:
#line 2735 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 273:
#line 2745 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 274:
#line 2749 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "strict",
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 275:
#line 2755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "lax",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 276:
#line 2761 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "skip",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 277:
#line 2773 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 278:
#line 2779 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 279:
#line 2791 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 280:
#line 2797 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 281:
#line 2811 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 282:
#line 2817 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 283:
#line 2859 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 284:
#line 2863 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 285:
#line 2867 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 286:
#line 2871 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 287:
#line 2883 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    ;}
    break;

  case 288:
#line 2893 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 289:
#line 2904 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 290:
#line 2909 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 291:
#line 2919 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 292:
#line 2923 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 293:
#line 2933 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 294:
#line 2939 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 295:
#line 2945 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 296:
#line 2951 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 297:
#line 2963 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 298:
#line 2969 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 299:
#line 2980 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 300:
#line 2984 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 301:
#line 2988 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 302:
#line 2992 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 303:
#line 2996 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 304:
#line 3000 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 305:
#line 3004 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 306:
#line 3014 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 307:
#line 3018 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 308:
#line 3028 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 309:
#line 3034 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 310:
#line 3046 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 311:
#line 3050 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 312:
#line 3054 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 313:
#line 3058 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 314:
#line 3062 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 315:
#line 3077 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 316:
#line 3081 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 317:
#line 3091 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 318:
#line 3095 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 319:
#line 3105 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 320:
#line 3112 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 321:
#line 3119 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 322:
#line 3132 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 323:
#line 3136 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 324:
#line 3148 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 325:
#line 3154 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 326:
#line 3168 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 327:
#line 3179 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 328:
#line 3183 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 329:
#line 3187 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 330:
#line 3191 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 331:
#line 3195 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 332:
#line 3199 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 333:
#line 3203 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 334:
#line 3207 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 335:
#line 3217 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 336:
#line 3221 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 337:
#line 3231 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 338:
#line 3236 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 339:
#line 3241 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 340:
#line 3252 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 341:
#line 3262 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 342:
#line 3266 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 343:
#line 3277 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 344:
#line 3287 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 345:
#line 3298 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 346:
#line 3354 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 347:
#line 3360 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 348:
#line 3372 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 349:
#line 3378 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 350:
#line 3390 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 3394 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 352:
#line 3404 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 353:
#line 3408 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 354:
#line 3412 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 355:
#line 3422 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 356:
#line 3430 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 357:
#line 3438 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 358:
#line 3446 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 359:
#line 3454 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 360:
#line 3462 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 361:
#line 3477 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 362:
#line 3483 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 363:
#line 3495 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 364:
#line 3501 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 365:
#line 3514 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 368:
#line 3531 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 369:
#line 3536 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 370:
#line 3547 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 371:
#line 3551 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 372:
#line 3558 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 373:
#line 3564 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 374:
#line 3570 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 375:
#line 3578 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 376:
#line 3592 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 377:
#line 3596 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 378:
#line 3603 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 379:
#line 3609 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 380:
#line 3615 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 381:
#line 3623 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 382:
#line 3637 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 383:
#line 3642 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 384:
#line 3653 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 385:
#line 3658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 386:
#line 3669 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 387:
#line 3674 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 388:
#line 3679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 389:
#line 3685 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 390:
#line 3697 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 391:
#line 3703 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 392:
#line 3708 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 393:
#line 3713 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 394:
#line 3724 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 395:
#line 3729 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 396:
#line 3744 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 397:
#line 3749 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 398:
#line 3766 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 399:
#line 3781 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 400:
#line 3785 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 401:
#line 3789 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 402:
#line 3793 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 403:
#line 3797 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 404:
#line 3801 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 405:
#line 3811 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 406:
#line 3822 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 407:
#line 3828 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 408:
#line 3834 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 409:
#line 3839 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 410:
#line 3861 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 411:
#line 3867 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 412:
#line 3873 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 413:
#line 3878 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 414:
#line 3889 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 415:
#line 3900 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 416:
#line 3911 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 417:
#line 3917 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 418:
#line 3923 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 419:
#line 3928 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 420:
#line 3939 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 421:
#line 3945 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 422:
#line 3957 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 423:
#line 3969 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 424:
#line 3975 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 425:
#line 3981 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 426:
#line 4018 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 427:
#line 4023 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 428:
#line 4028 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 429:
#line 4039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 430:
#line 4043 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 431:
#line 4047 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 432:
#line 4057 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 433:
#line 4068 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 434:
#line 4072 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 435:
#line 4076 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 436:
#line 4080 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 437:
#line 4084 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 438:
#line 4088 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 439:
#line 4092 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 440:
#line 4096 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 441:
#line 4100 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 442:
#line 4110 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 443:
#line 4120 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 444:
#line 4124 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 445:
#line 4129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 446:
#line 4140 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 447:
#line 4150 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 448:
#line 4160 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 449:
#line 4164 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 450:
#line 4168 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 451:
#line 4178 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 452:
#line 4184 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 453:
#line 4190 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 454:
#line 4196 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 455:
#line 4202 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 456:
#line 4214 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 457:
#line 4225 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		;}
    break;

  case 458:
#line 4232 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
                           NULL,
                           true);
		;}
    break;

  case 459:
#line 4239 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		;}
    break;

  case 460:
#line 4246 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		;}
    break;

  case 461:
#line 4253 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 462:
#line 4260 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		;}
    break;

  case 463:
#line 4267 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 464:
#line 4280 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 465:
#line 4301 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 466:
#line 4308 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 467:
#line 4328 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 468:
#line 4368 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 469:
#line 4373 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 470:
#line 4376 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 471:
#line 4384 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 472:
#line 4390 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 473:
#line 4396 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 474:
#line 4402 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 475:
#line 4408 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 476:
#line 4415 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 477:
#line 4421 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 478:
#line 4427 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 479:
#line 4433 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 480:
#line 4439 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 481:
#line 4451 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 482:
#line 4456 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 483:
#line 4466 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 484:
#line 4472 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 485:
#line 4484 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 486:
#line 4510 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 487:
#line 4521 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 488:
#line 4527 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 489:
#line 4540 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 490:
#line 4554 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 491:
#line 4561 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 492:
#line 4568 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 493:
#line 4579 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 494:
#line 4586 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 495:
#line 4594 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 496:
#line 4603 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(14) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (9)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (12)].sval)),
                          (yysemantic_stack_[(14) - (14)].expr));
    ;}
    break;

  case 498:
#line 4619 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 499:
#line 4636 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 500:
#line 4637 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty"); ;}
    break;

  case 501:
#line 4638 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("attribute"); ;}
    break;

  case 502:
#line 4639 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("comment"); ;}
    break;

  case 503:
#line 4640 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document-node"); ;}
    break;

  case 504:
#line 4641 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("element"); ;}
    break;

  case 505:
#line 4642 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("item"); ;}
    break;

  case 506:
#line 4643 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("if"); ;}
    break;

  case 507:
#line 4644 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("node"); ;}
    break;

  case 508:
#line 4645 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("processing-instruction"); ;}
    break;

  case 509:
#line 4646 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-attribute"); ;}
    break;

  case 510:
#line 4647 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-element"); ;}
    break;

  case 511:
#line 4648 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("text"); ;}
    break;

  case 512:
#line 4649 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("typeswitch"); ;}
    break;

  case 513:
#line 4650 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty-sequence"); ;}
    break;

  case 514:
#line 4651 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("boundary-space"); ;}
    break;

  case 515:
#line 4652 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ft-option"); ;}
    break;

  case 516:
#line 4653 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("base-uri"); ;}
    break;

  case 517:
#line 4654 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lax"); ;}
    break;

  case 518:
#line 4655 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strict"); ;}
    break;

  case 519:
#line 4656 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("idiv"); ;}
    break;

  case 520:
#line 4657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document"); ;}
    break;

  case 521:
#line 4658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("not"); ;}
    break;

  case 522:
#line 4659 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sensitive"); ;}
    break;

  case 523:
#line 4660 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insensitive"); ;}
    break;

  case 524:
#line 4661 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("diacritics"); ;}
    break;

  case 525:
#line 4662 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("without"); ;}
    break;

  case 526:
#line 4663 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stemming"); ;}
    break;

  case 527:
#line 4664 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("thesaurus"); ;}
    break;

  case 528:
#line 4665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stop"); ;}
    break;

  case 529:
#line 4666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("wildcards"); ;}
    break;

  case 530:
#line 4667 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("entire"); ;}
    break;

  case 531:
#line 4668 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("content"); ;}
    break;

  case 532:
#line 4669 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("word"); ;}
    break;

  case 533:
#line 4670 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("start"); ;}
    break;

  case 534:
#line 4671 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("end"); ;}
    break;

  case 535:
#line 4672 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("most"); ;}
    break;

  case 536:
#line 4673 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("skip"); ;}
    break;

  case 537:
#line 4674 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy"); ;}
    break;

  case 538:
#line 4675 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("value"); ;}
    break;

  case 539:
#line 4676 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("eq"); ;}
    break;

  case 540:
#line 4677 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ne"); ;}
    break;

  case 541:
#line 4678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lt"); ;}
    break;

  case 542:
#line 4679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("le"); ;}
    break;

  case 543:
#line 4680 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("gt"); ;}
    break;

  case 544:
#line 4681 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ge"); ;}
    break;

  case 545:
#line 4682 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("at"); ;}
    break;

  case 546:
#line 4683 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("variable"); ;}
    break;

  case 547:
#line 4684 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("return"); ;}
    break;

  case 548:
#line 4685 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("for"); ;}
    break;

  case 549:
#line 4686 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("outer"); ;}
    break;

  case 550:
#line 4687 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sliding"); ;}
    break;

  case 551:
#line 4688 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("tumbling"); ;}
    break;

  case 552:
#line 4689 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("previous"); ;}
    break;

  case 553:
#line 4690 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("next"); ;}
    break;

  case 554:
#line 4691 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("only"); ;}
    break;

  case 555:
#line 4692 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("when"); ;}
    break;

  case 556:
#line 4693 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("count"); ;}
    break;

  case 557:
#line 4694 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("in"); ;}
    break;

  case 558:
#line 4695 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("let"); ;}
    break;

  case 559:
#line 4696 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("where"); ;}
    break;

  case 560:
#line 4697 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("by"); ;}
    break;

  case 561:
#line 4698 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("group"); ;}
    break;

  case 562:
#line 4699 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("order"); ;}
    break;

  case 563:
#line 4700 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stable"); ;}
    break;

  case 564:
#line 4701 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ascending"); ;}
    break;

  case 565:
#line 4702 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("descending"); ;}
    break;

  case 566:
#line 4703 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("greatest"); ;}
    break;

  case 567:
#line 4704 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("least"); ;}
    break;

  case 568:
#line 4705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("collation"); ;}
    break;

  case 569:
#line 4706 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("some"); ;}
    break;

  case 570:
#line 4707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("every"); ;}
    break;

  case 571:
#line 4708 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("satisfies"); ;}
    break;

  case 572:
#line 4709 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("case"); ;}
    break;

  case 573:
#line 4710 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("as"); ;}
    break;

  case 574:
#line 4711 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("then"); ;}
    break;

  case 575:
#line 4712 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("else"); ;}
    break;

  case 576:
#line 4713 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("or"); ;}
    break;

  case 577:
#line 4714 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("and"); ;}
    break;

  case 578:
#line 4715 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("instance"); ;}
    break;

  case 579:
#line 4716 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("of"); ;}
    break;

  case 580:
#line 4717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("castable"); ;}
    break;

  case 581:
#line 4718 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("to"); ;}
    break;

  case 582:
#line 4719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("div"); ;}
    break;

  case 583:
#line 4720 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("mod"); ;}
    break;

  case 584:
#line 4721 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("union"); ;}
    break;

  case 585:
#line 4722 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("intersect"); ;}
    break;

  case 586:
#line 4723 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("except"); ;}
    break;

  case 587:
#line 4724 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("validate"); ;}
    break;

  case 588:
#line 4725 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cast"); ;}
    break;

  case 589:
#line 4726 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("treat"); ;}
    break;

  case 590:
#line 4727 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("is"); ;}
    break;

  case 591:
#line 4728 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("preserve"); ;}
    break;

  case 592:
#line 4729 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strip"); ;}
    break;

  case 593:
#line 4730 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("namespace"); ;}
    break;

  case 594:
#line 4731 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("external"); ;}
    break;

  case 595:
#line 4732 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("encoding"); ;}
    break;

  case 596:
#line 4733 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-preserve"); ;}
    break;

  case 597:
#line 4734 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("inherit"); ;}
    break;

  case 598:
#line 4735 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-inherit"); ;}
    break;

  case 599:
#line 4736 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("declare"); ;}
    break;

  case 600:
#line 4737 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("construction"); ;}
    break;

  case 601:
#line 4738 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordering"); ;}
    break;

  case 602:
#line 4739 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("default"); ;}
    break;

  case 603:
#line 4740 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy-namespaces"); ;}
    break;

  case 604:
#line 4741 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("option"); ;}
    break;

  case 605:
#line 4742 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("version"); ;}
    break;

  case 606:
#line 4743 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("import"); ;}
    break;

  case 607:
#line 4744 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema"); ;}
    break;

  case 608:
#line 4745 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("module"); ;}
    break;

  case 609:
#line 4746 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("function"); ;}
    break;

  case 610:
#line 4747 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("score"); ;}
    break;

  case 611:
#line 4748 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ftcontains"); ;}
    break;

  case 612:
#line 4749 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("weight"); ;}
    break;

  case 613:
#line 4750 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("window"); ;}
    break;

  case 614:
#line 4751 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("distance"); ;}
    break;

  case 615:
#line 4752 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("occurs"); ;}
    break;

  case 616:
#line 4753 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("times"); ;}
    break;

  case 617:
#line 4754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("same"); ;}
    break;

  case 618:
#line 4755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("different"); ;}
    break;

  case 619:
#line 4756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lowercase"); ;}
    break;

  case 620:
#line 4757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("uppercase"); ;}
    break;

  case 621:
#line 4758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("relationship"); ;}
    break;

  case 622:
#line 4759 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("levels"); ;}
    break;

  case 623:
#line 4760 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("language"); ;}
    break;

  case 624:
#line 4761 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("any"); ;}
    break;

  case 625:
#line 4762 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("all"); ;}
    break;

  case 626:
#line 4763 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("phrase"); ;}
    break;

  case 627:
#line 4764 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exactly"); ;}
    break;

  case 628:
#line 4765 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("from"); ;}
    break;

  case 629:
#line 4766 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("words"); ;}
    break;

  case 630:
#line 4767 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentences"); ;}
    break;

  case 631:
#line 4768 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentence"); ;}
    break;

  case 632:
#line 4769 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("paragraph"); ;}
    break;

  case 633:
#line 4770 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("replace"); ;}
    break;

  case 634:
#line 4771 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("modify"); ;}
    break;

  case 635:
#line 4772 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("first"); ;}
    break;

  case 636:
#line 4773 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insert"); ;}
    break;

  case 637:
#line 4774 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("bofer"); ;}
    break;

  case 638:
#line 4775 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("after"); ;}
    break;

  case 639:
#line 4776 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("revalidation"); ;}
    break;

  case 640:
#line 4777 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("with"); ;}
    break;

  case 641:
#line 4778 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("nodes"); ;}
    break;

  case 642:
#line 4779 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("rename"); ;}
    break;

  case 643:
#line 4780 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("last"); ;}
    break;

  case 644:
#line 4781 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("delete"); ;}
    break;

  case 645:
#line 4782 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("into"); ;}
    break;

  case 646:
#line 4783 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("updating"); ;}
    break;

  case 647:
#line 4784 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordered"); ;}
    break;

  case 648:
#line 4785 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("unordered"); ;}
    break;

  case 649:
#line 4786 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exit"); ;}
    break;

  case 650:
#line 4787 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("loop"); ;}
    break;

  case 651:
#line 4788 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("break"); ;}
    break;

  case 652:
#line 4789 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cont"); ;}
    break;

  case 653:
#line 4790 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("set"); ;}
    break;

  case 654:
#line 4802 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 655:
#line 4808 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 656:
#line 4825 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 657:
#line 4829 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 658:
#line 4833 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 659:
#line 4837 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 660:
#line 4847 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 661:
#line 4850 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 662:
#line 4853 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 663:
#line 4856 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 664:
#line 4865 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 665:
#line 4868 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 666:
#line 4877 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 667:
#line 4880 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 668:
#line 4889 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 669:
#line 4892 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 670:
#line 4901 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 671:
#line 4904 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 672:
#line 4913 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 673:
#line 4916 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 674:
#line 4919 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 675:
#line 4928 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 676:
#line 4931 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 677:
#line 4940 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 678:
#line 4944 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, static_cast<Expr *> ((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 679:
#line 4954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 680:
#line 4957 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 681:
#line 4960 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 682:
#line 4963 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 683:
#line 4966 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 684:
#line 4975 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 685:
#line 4984 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 686:
#line 4988 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 687:
#line 4992 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 688:
#line 4996 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 689:
#line 5000 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 690:
#line 5004 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 691:
#line 5008 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 692:
#line 5018 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 693:
#line 5021 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 694:
#line 5024 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 695:
#line 5027 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 696:
#line 5036 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 697:
#line 5039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 698:
#line 5042 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 699:
#line 5045 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 700:
#line 5054 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 701:
#line 5057 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 702:
#line 5066 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 703:
#line 5069 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 704:
#line 5072 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 705:
#line 5075 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 706:
#line 5078 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 707:
#line 5081 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 708:
#line 5084 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 709:
#line 5093 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 710:
#line 5096 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 711:
#line 5105 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 712:
#line 5108 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 713:
#line 5111 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 714:
#line 5114 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 715:
#line 5123 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 716:
#line 5126 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 717:
#line 5129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 718:
#line 5132 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 719:
#line 5135 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 720:
#line 5144 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 721:
#line 5147 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 722:
#line 5156 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 723:
#line 5159 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 724:
#line 5168 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 725:
#line 5171 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 726:
#line 5180 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 727:
#line 5183 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 728:
#line 5192 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 729:
#line 5201 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 730:
#line 5204 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 731:
#line 5213 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 732:
#line 5216 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 733:
#line 5219 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 734:
#line 5228 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 735:
#line 5231 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 736:
#line 5234 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 737:
#line 5237 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 738:
#line 5240 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 739:
#line 5249 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 740:
#line 5253 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 741:
#line 5257 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 742:
#line 5261 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 743:
#line 5271 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 744:
#line 5280 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 745:
#line 5290 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 746:
#line 5299 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 747:
#line 5302 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 748:
#line 5311 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 749:
#line 5314 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 750:
#line 5317 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 751:
#line 5326 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 752:
#line 5329 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 753:
#line 5338 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6530 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1129;
  const short int
  xquery_parser::yypact_[] =
  {
      1251, -1129, -1129, -1129, -1129,  -117,   109, -1129,   113,   346,
     132,  6218,   145,   430,   450,    82, -1129, -1129,   167,    32,
   -1129,   549,   228, -1129,   221, -1129, -1129, -1129,   247,   376,
   -1129,   324,   404,   490, -1129, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129,   554, -1129,   453,   473, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129, -1129, -1129, -1129,  6459, -1129,  5485, -1129,
   -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
   -1129,  7664, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
     514, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129,  4240,  1501,  7664, -1129, -1129, -1129, -1129, -1129,
   -1129,   489, -1129, -1129, -1129, -1129,   614, -1129,  5977, -1129,
   -1129, -1129, -1129, -1129,  7664, -1129, -1129,  5236, -1129, -1129,
   -1129, -1129, -1129, -1129,   501, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129,     9,   446, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129,   266,   518,   306, -1129,   452,   -78, -1129,
   -1129, -1129, -1129, -1129, -1129,   550, -1129,   528,   565, -1129,
   -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129, -1129, -1129,  1750,   667, -1129,  4489, -1129,
   -1129,   384,  4240,   500,   502, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
     580, -1129, -1129, -1129, -1129,   264,  7664, -1129, -1129, -1129,
   -1129, -1129,   526,   598, -1129,   715,   440,   289,   127,   -56,
     -28, -1129,   605,   498,   593,   594,  4738, -1129, -1129, -1129,
     -10, -1129, -1129,  5236, -1129,   426, -1129,   545,  5485, -1129,
     545,  5485, -1129, -1129, -1129, -1129,   545, -1129, -1129, -1129,
   -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129, -1129, -1129,   546, -1129,  4240, -1129,  4240,
    4240,   548,   555,   556,  4240, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,  4240,  6700,
   -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,   558,  4240,
    4240,   527,  4240,   529,  7664,   649,   654,  7664,   305,   -69,
     674,   315,   307,   595,    66,   679,   443,     1,  4240, -1129,
    4240,    41,   566,    48,    29,  7664,   679,  7664,  7664,  4240,
     448,   454, -1129,   597,   601, -1129,  7664,    30,  4240,  6941,
     571,   572,   573,   574,   575,   576, -1129, -1129, -1129,  7664,
    1999,   -16, -1129,    -5,   682,  4240,    36, -1129,   698,   552,
   -1129,  4240,   522, -1129,   701,  4240,  4240,   557,  4240,  4240,
    4240,  4240,   511,  7664,  4240,  7664, -1129, -1129, -1129, -1129,
      82,   549, -1129, -1129,   384,   687,  4240,   579,   376,   404,
     490,   624,   581,   582,  4240,  4240, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129,   638, -1129,   -43,  4987,  4987,  4987, -1129,
    4987,  4987, -1129,  4987, -1129,  4987, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129,  4987,  4987,    12,  4987,  4987,  4987,  4987,
    4987,  4987,  4987,  4987,  4987,  4987,  4987,   519,   655,   658,
     662, -1129, -1129, -1129,  2248, -1129, -1129,  5236,  5236,  4240,
     545, -1129, -1129,   545, -1129,   545,  2497, -1129,   577,    79,
    4240,  4240,  4240,    10,   172, -1129,    16,    51,  2746,   192,
     208, -1129,   231, -1129,   606,  7664,  7664,   721, -1129, -1129,
   -1129, -1129, -1129, -1129,   653,   660, -1129, -1129,  7664,   186,
     609,   612,   674,   637,   633, -1129, -1129, -1129,   394,    22,
     398,   733, -1129, -1129,   348, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129,    69,   242,   588, -1129,   590,  2995,   679,
     677,   725,   679,   674,   684,    14, -1129,     2,   646,   642,
     675, -1129,   -36,   604, -1129, -1129,  7664,   -18, -1129,   602,
     572,   453, -1129,   603,   607,   255, -1129,   120,   142,  3244,
      53, -1129,    44, -1129, -1129,  7664,   682, -1129,   161,   274,
   -1129, -1129, -1129, -1129,   278, -1129,   -20, -1129, -1129, -1129,
     -27,    60,   692,   560,   567,    -9, -1129,   648,   616,   201,
   -1129, -1129,   610, -1129,     0, -1129, -1129,   625,  7664,  4240,
     680, -1129, -1129,   681,  7423,   686,  4240,   688,   -57,   656,
     -46,   598, -1129, -1129, -1129, -1129, -1129,  4987, -1129, -1129,
   -1129,  4240,    12,   218, -1129,   532,   510,   559,   561, -1129,
   -1129,   551,   335,   127,   127,   181,   -56,   -56,   -56,   -56,
     -28,   -28, -1129, -1129,  7423,  7423,  7664,  7664, -1129,   282,
   -1129, -1129,    72, -1129, -1129, -1129,   149,   657, -1129,   296,
     302,   320,   707,   663,  7664, -1129,  7664, -1129, -1129,   321,
   -1129, -1129, -1129,   215,   418,   606,   606, -1129,   389,   413,
     717,   676,  4240,   674,   674, -1129,   521,   674, -1129, -1129,
     543, -1129, -1129,   544,   334, -1129, -1129, -1129, -1129, -1129,
   -1129,   547, -1129, -1129,   627,   668, -1129, -1129, -1129,   341,
     689,   674,   665,   693,   727,   674,   712,  4240,  4240,   690,
     674,  4240,   714,  4240,   695,   -71, -1129,   203,   591, -1129,
   -1129,   492,   -18, -1129, -1129, -1129,   691,  7664, -1129,  7664,
   -1129, -1129,   347,  4240, -1129,   795, -1129,   273, -1129,   158,
   -1129, -1129,   802, -1129,   330,  4240,  4240,  4240,   411,  4240,
    4240,  4240,  4240,  4240,  4240,   722,  4240,  4240,   611,   699,
     724,   687,  4240, -1129,   460,   735, -1129,  7664,   740, -1129,
    7664,   702,   704, -1129,   291, -1129, -1129, -1129,  7664, -1129,
    7664,  4240,   708,  4240,  4240,   -33,   716, -1129,   349,   678,
   -1129,   617, -1129,  -104, -1129,   371,   -39,   623,    12,   371,
    4987,  4987,   636, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
      12,   718,   -39, -1129,   585,   785, -1129, -1129, -1129, -1129,
   -1129,   730, -1129, -1129, -1129,  4240, -1129, -1129, -1129, -1129,
   -1129,  7182,   495, -1129,  3493,   694,   696,   731,   700,   703,
   -1129,  7664,   764,   174, -1129, -1129,  4240, -1129,   451,   657,
   -1129, -1129, -1129, -1129, -1129,  4240, -1129, -1129, -1129, -1129,
   -1129, -1129,   619,   190,   827, -1129,   150, -1129, -1129,  4240,
    3742, -1129,   674,   767, -1129, -1129, -1129,   674,   767,  7664,
   -1129, -1129,  4240,   697, -1129,  7664, -1129,  4240,  4240,   745,
    4240,   743, -1129,   776,   777,  4240,  7664,   578,   816, -1129,
   -1129, -1129,  3991,   719, -1129,   726, -1129, -1129, -1129,   769,
   -1129,   165, -1129, -1129,   877, -1129, -1129,  4240,  7664, -1129,
   -1129,   427, -1129, -1129, -1129,   723,   671,   683, -1129, -1129,
   -1129,   705,   706, -1129, -1129, -1129, -1129, -1129,   709,  7664,
     729, -1129,   755,   611, -1129,  4240,  7664,   735, -1129,   674,
   -1129,   538, -1129,   364,   813, -1129,  4240,   814,   680, -1129,
     739,   741, -1129, -1129, -1129, -1129, -1129, -1129, -1129,  4240,
   -1129, -1129,  4240,   779,  4240, -1129, -1129,  4987, -1129, -1129,
   -1129, -1129, -1129,    33,  4987,  4987,   233, -1129,   559, -1129,
   -1129,   116,  4987, -1129, -1129,   561,    12,   659, -1129, -1129,
   -1129, -1129,  7664,   744,   187, -1129, -1129,   356, -1129, -1129,
   -1129, -1129, -1129,   717,  7423,   809,   833,   357, -1129, -1129,
   -1129, -1129,   -21,   892,   893,   -21,    11,   176,   183,   807,
   -1129,   359,   835,   674,   767, -1129, -1129, -1129, -1129, -1129,
   -1129,  4240, -1129,  4240,  7664,  7664, -1129,   515, -1129,  4240,
   -1129,   360, -1129, -1129,   795,  7664,   434, -1129,   369,   795,
    7664, -1129, -1129,  4240,  4240,  4240,  4240,  4240, -1129,  4240,
    5734, -1129,   753, -1129, -1129, -1129, -1129,   813, -1129, -1129,
   -1129,   674, -1129, -1129, -1129, -1129, -1129, -1129,  4240, -1129,
     -56,  4987,  4987,   -56,   245, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129,   839,  4240,  7664,  4240, -1129, -1129, -1129,
   -1129,  7423, -1129,   190,   190,   -21, -1129, -1129, -1129,    26,
     -21,   900,   685,   841, -1129,   841, -1129,  4240, -1129,   674,
   -1129, -1129, -1129,   861, -1129, -1129, -1129, -1129,    -4,   795,
    7664, -1129,   747,   795, -1129, -1129, -1129, -1129, -1129, -1129,
     193, -1129, -1129, -1129, -1129,   -56,   -56,  4987,  7423, -1129,
     760, -1129, -1129, -1129, -1129, -1129, -1129, -1129,   -39, -1129,
     196, -1129,   202, -1129,   767,   828,   286,    47, -1129,   754,
     795, -1129,   757,   830,   803,   -56,   770,  4240,   710,   841,
   -1129, -1129,  7664, -1129, -1129,   860,   293, -1129, -1129, -1129,
   -1129,   778,   412, -1129, -1129, -1129,   762, -1129,  7664, -1129,
    4240, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129,   216, -1129,   838,   803,  7664, -1129,   223,   840,
     803,  7664, -1129,   780,   803, -1129
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   320,   321,   499,   467,   649,   651,   650,     0,   587,
     512,   504,   520,   511,   502,   599,   609,   646,   506,   508,
     535,   606,   569,   563,   608,   604,   532,   607,   653,   558,
     600,     0,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   601,   652,   516,   510,   503,   603,   578,   509,   514,
     311,   314,   577,   573,   564,   545,   501,   301,     0,   572,
     580,   588,   299,   568,   337,   546,   602,   300,   303,   565,
     582,     0,   343,   309,   339,   575,   500,   566,   567,   595,
     570,   586,   594,   305,   304,   519,   557,   597,   338,   585,
     590,   505,     0,     0,     0,   258,   583,   593,   598,   596,
     576,   647,   562,   560,   561,   310,     0,   257,     0,   313,
     312,   591,   547,   571,     0,   302,   287,     0,   319,   592,
     574,   581,   589,   584,   648,   539,   544,   543,   542,   541,
     540,   513,   559,     0,     0,   605,   533,   638,   637,   639,
     518,   517,   536,   644,   507,   636,   641,   642,   633,   538,
     579,   635,   645,   643,   634,   537,   640,     0,     0,   625,
     624,   522,   515,   524,   523,   618,   614,   530,   534,   531,
     627,   628,   611,   521,   623,   622,   619,   615,   632,   626,
     621,   617,   610,   631,   630,   616,   620,   612,   613,   525,
     526,   528,   629,   527,   529,     0,     0,     2,     0,     4,
       6,     0,     0,     0,     0,    17,    19,    21,    22,    23,
      29,    24,    27,    28,    33,    34,    35,    30,    31,    37,
      38,    25,    32,   117,   116,   113,   114,   115,    26,    11,
      98,    99,   101,   132,   138,     0,     0,   130,   131,   102,
     103,   104,   105,   214,   216,   218,   228,   231,   233,   236,
     241,   244,   247,   249,   251,   253,     0,   255,   261,   263,
       0,   279,   262,   283,   286,   288,   291,   293,     0,   298,
     295,     0,   306,   316,   318,   292,   322,   327,   335,   328,
     329,   330,   333,   334,   331,   332,   350,   352,   353,   354,
     351,   399,   400,   401,   402,   403,   404,   315,   441,   433,
     440,   439,   438,   435,   437,   434,   436,   336,    36,   106,
     107,   109,   108,   110,   111,   317,   112,     0,    85,     0,
       0,     0,     0,     0,     0,   649,   651,   587,   512,   504,
     520,   511,   502,   599,   506,   508,   606,   569,   608,   653,
     558,   548,   549,   652,   510,   503,   501,   570,     0,     0,
     647,   648,   644,   507,   636,   642,   633,   537,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   498,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,     0,     0,    86,     0,     0,     0,     0,
       0,   504,   511,   502,   508,   501,   307,   317,   340,     0,
       0,     0,   341,     0,   366,     0,     0,   282,     0,     0,
     285,     0,     0,   395,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     1,     5,     7,
       0,     0,    12,    10,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,   137,   133,   139,
     134,   136,   135,   142,   143,     0,     0,     0,     0,   272,
       0,     0,   270,     0,   223,     0,   271,   264,   269,   268,
     267,   266,   265,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,   259,   256,     0,   280,   284,     0,     0,     0,
     294,   324,   297,   296,   308,   323,     0,    83,     0,     0,
       0,     0,     0,     0,     0,   457,     0,     0,     0,     0,
       0,   446,     0,   447,     0,     0,     0,     0,    73,    74,
      46,    47,   497,    55,     0,     0,    40,    41,     0,     0,
       0,     0,     0,     0,     0,   468,   469,   470,     0,     0,
       0,     0,   692,   693,     0,    45,   685,   686,   687,   688,
     689,   690,   691,     0,     0,     0,   448,     0,     0,     0,
      64,     0,     0,     0,    56,     0,   203,     0,     0,     0,
     155,   156,     0,     0,   120,   121,     0,     0,   141,     0,
       0,     0,   443,     0,     0,     0,   451,     0,     0,     0,
       0,    79,     0,    80,   342,   367,   366,   363,     0,     0,
     397,   396,   281,   456,     0,   394,     0,   481,   482,   442,
       0,     0,     0,     0,     0,     0,   487,     0,     0,     0,
     158,   175,     0,    18,     0,    20,   100,     0,     0,     0,
       0,   119,   176,     0,     0,     0,     0,     0,     0,     0,
       0,   215,   217,   221,   227,   226,   225,     0,   222,   219,
     220,     0,     0,     0,   677,   229,   656,   664,   666,   668,
     670,   672,   675,   235,   234,   232,   238,   239,   240,   237,
     242,   243,   246,   245,     0,     0,     0,     0,   277,     0,
     289,   290,     0,   325,   346,   348,     0,     0,   273,     0,
       0,     0,     0,     0,     0,   461,     0,   458,   406,     0,
     405,   414,   415,     0,     0,     0,     0,    44,     0,     0,
      68,    71,     0,     0,     0,    54,     0,     0,   694,   695,
       0,   696,   700,     0,     0,   729,   698,   699,   728,   697,
     701,     0,   708,   730,     0,     0,   450,   449,   416,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   655,     0,     0,   122,
     123,     0,   128,   464,   444,   445,     0,     0,   454,     0,
     452,   410,     0,     0,    81,   366,   364,     0,   355,     0,
     344,   345,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,   129,   187,   183,   185,     0,   177,   178,
       0,   505,   513,   422,   423,   429,   430,   432,     0,   145,
       0,     0,     0,     0,     0,     0,     0,   224,     0,     0,
     671,     0,   230,     0,   684,     0,     0,     0,     0,     0,
       0,     0,   657,   661,   679,   660,   683,   681,   680,   682,
       0,     0,     0,   673,   736,   734,   738,   676,   248,   250,
     252,   420,   254,   278,   326,     0,   347,    84,   274,   275,
     276,     0,     0,   209,     0,     0,     0,   465,     0,     0,
     407,     0,    75,     0,    92,    87,     0,    88,     0,     0,
      52,    53,    50,    51,    69,     0,    70,    42,    43,    48,
      49,    39,     0,     0,     0,   703,     0,   702,   719,     0,
       0,   417,     0,    66,    60,    63,    62,     0,    58,     0,
     201,   205,     0,     0,    82,     0,   160,     0,     0,     0,
       0,     0,   124,     0,     0,     0,     0,   169,     0,   166,
     171,   127,     0,     0,   465,     0,   411,   202,   367,     0,
     356,     0,   390,   387,     0,   391,   392,     0,     0,   393,
     386,     0,   361,   389,   388,     0,     0,     0,   474,   475,
     471,     0,     0,   479,   480,   476,   485,   483,     0,     0,
       0,   489,     0,   490,   491,     0,     0,   184,   196,     0,
     197,     0,   188,   189,   190,   191,     0,   180,     0,   144,
       0,     0,   426,   428,   427,   424,   153,   154,   147,     0,
     149,   146,     0,     0,     0,   678,   674,     0,   731,   732,
     752,   751,   747,     0,     0,     0,     0,   733,   665,   746,
     658,     0,     0,   663,   662,   667,     0,     0,   737,   735,
     421,   349,     0,     0,     0,   210,   408,     0,   462,   463,
     466,   459,   460,    94,     0,     0,    76,     0,    89,    90,
      91,    72,   717,     0,     0,   715,   711,     0,     0,     0,
     418,     0,    65,     0,    59,   204,   206,    13,   157,   162,
     161,     0,   164,     0,     0,     0,   126,   167,   170,     0,
     412,     0,   455,   453,   366,     0,     0,   398,     0,   366,
       0,   362,     9,     0,     0,     0,     0,     0,   488,     0,
       0,   492,     0,   159,   200,   198,   199,   192,   193,   194,
     186,     0,   181,   179,   431,   425,   151,   148,     0,   150,
     753,     0,     0,   739,     0,   750,   749,   748,   743,   744,
     659,   669,   745,     0,     0,     0,     0,   409,    95,    77,
      93,     0,    97,     0,     0,   718,   720,   722,   724,     0,
     716,     0,     0,     0,   706,     0,   704,     0,   419,     0,
      61,   163,   165,   174,   173,   168,   125,   413,     0,   366,
       0,    96,     0,   366,   472,   473,   477,   478,   484,   486,
       0,   654,   195,   182,   152,   741,   740,     0,     0,   211,
       0,   207,    78,   727,   726,   721,   725,   723,   712,   713,
       0,   709,     0,   213,    67,     0,   376,   370,   365,     0,
     366,   357,     0,     0,     0,   742,     0,     0,     0,     0,
     707,   705,     0,   384,   378,     0,   377,   379,   385,   382,
     372,     0,   371,   373,   383,   359,     0,   358,     0,   493,
       0,   208,   714,   710,   172,   369,   380,   381,   368,   374,
     375,   360,     0,   212,     0,     0,     0,   494,     0,     0,
       0,     0,   495,     0,     0,   496
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1129, -1129,   748, -1129,   746,   749, -1129,   750, -1129,   504,
     506,  -425, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129, -1129, -1129,  -750, -1129, -1129, -1129, -1129,
   -1129,   -76,  -681, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
    -123, -1129,  -884,   751,   -35,  -315, -1129, -1129, -1129, -1129,
     175, -1129, -1129,   728, -1129, -1129, -1129, -1129, -1129,   124,
    -437,  -570, -1129, -1129, -1129,    13, -1129, -1129,  -151,     3,
     -47, -1129, -1129, -1129,   -54, -1129, -1129,   139,   -51, -1129,
   -1129,   -45,  -942, -1129,   553,    27, -1129, -1129,    77, -1129,
   -1129,   505,   503, -1129,  -406,  -831,   484,   166,  -483,   162,
     164, -1129, -1129, -1129, -1129, -1129,   720, -1129, -1129, -1129,
   -1129, -1129,   713, -1129, -1129,   -99, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129,   -37,  -156, -1129, -1129,   239,    97, -1129,
    -475, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
    -772, -1129,     4, -1129,   361,  -611, -1129, -1129, -1129, -1129,
   -1129,  -284,  -277,  -925, -1128, -1129, -1129, -1129, -1129, -1129,
   -1129, -1129, -1129, -1129, -1129,   283,  -573,  -683, -1129, -1129,
     -34,  -641, -1129, -1129, -1129, -1129, -1129, -1129, -1129,   584,
     586,  -385,   268, -1129, -1129, -1129, -1129, -1129, -1129, -1129,
   -1129,   -17, -1129, -1129,   -14,  -367,  -350,   -11, -1129,   313,
   -1129, -1129,   128,   117,   -66,   318, -1129, -1129,   130, -1129,
    -643, -1129, -1129, -1129, -1129,  -192,  -743, -1129,   -91,  -509,
   -1129,  -564, -1129, -1129, -1129, -1129,  -849, -1129, -1129, -1129,
   -1129,   -55,   138, -1129
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   933,   583,   220,   549,   221,
     222,   724,   223,   410,   224,   225,   226,   227,   228,   903,
     904,   979,   907,   229,   230,   231,   232,   456,   393,   781,
     782,   233,   457,   234,   459,   235,   236,   237,   463,   464,
     957,   659,   238,   590,   639,   591,   597,   958,   959,   960,
     640,   460,   461,   828,   829,  1142,   462,   825,   826,  1012,
    1013,  1014,  1015,   239,   585,   586,   240,   892,   893,   241,
     242,   243,   244,   667,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   483,   484,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   510,   511,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   706,   285,
     286,   287,   981,   616,   617,   618,  1238,  1261,  1262,  1255,
    1256,  1263,  1257,   982,   983,   288,   289,   984,   290,   291,
     292,   293,   294,   295,   296,   880,   660,   833,  1025,   834,
     835,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   895,   896,   307,   308,   309,   310,   311,   312,   313,
     635,   636,   314,  1003,  1004,   934,   382,   315,   316,   675,
     862,   676,   677,   678,   679,   680,   681,   682,   863,   864,
     565,   566,   567,   568,   569,  1230,  1231,   570,  1175,  1085,
    1179,  1176,   571,   572,   866,   877,  1046,   867,   868,   873,
     869,  1158,  1042,   852
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       358,   927,   517,   543,   518,   797,   686,   687,   688,   689,
     674,   878,   879,   836,   769,   938,   580,   584,   420,   775,
     645,   406,   774,  1057,  1079,   554,   887,   980,   658,  1050,
     422,   577,     4,   865,   655,   654,   588,   655,   364,   365,
     366,  1043,   654,   620,   778,   400,  1226,   407,   367,   542,
     379,   804,   948,   836,   836,   972,  1121,   411,   413,   379,
     408,   575,   663,   600,   664,   665,  1259,   666,   542,   668,
     841,  1138,  1139,  1236,   593,   446,  1151,   669,   670,   540,
     654,   844,   815,   414,   656,   558,   446,   773,   842,   495,
     846,  1043,   802,  1038,  1032,   373,  1173,   418,   601,   550,
     317,   446,   496,   419,   551,   766,    64,   714,  1258,  1264,
     627,   628,   541,   630,   631,   632,   633,    74,   740,   638,
     364,   365,   366,   504,   493,   581,  1039,   431,  1258,   768,
     367,   646,   432,   494,  1264,   446,   368,   318,   808,   651,
     652,    88,   716,  1152,   766,   671,   108,   369,   672,   370,
     803,   975,   371,   976,   613,   372,   552,   914,  1237,  1174,
     446,   614,  1260,   446,   506,   380,   972,   973,   381,   582,
     446,   805,   806,   972,   973,   657,   712,   373,   374,   779,
     977,   767,   715,  1088,   969,   735,   807,  1094,   579,   657,
     621,  1121,  1227,  1044,  1045,  1212,   602,   674,   674,   980,
     657,   705,   423,   657,   951,   949,   816,   576,  1063,   980,
     657,   787,   780,   657,   794,   553,   764,   717,   559,  1054,
     793,  1160,   375,   845,   377,   465,   560,   489,  1080,   760,
     924,   512,   763,   789,   514,   754,   884,  1182,     4,   561,
     885,   562,   708,  1044,  1045,   974,  1087,   741,   673,   319,
     836,   563,   974,   490,   564,  1181,   819,   407,   809,   810,
     407,   847,   975,   446,   976,  1075,   491,  1183,   324,   975,
    1083,   976,   798,   811,  1185,  1033,   742,   743,   359,   744,
     745,   654,   376,   446,  1243,   519,   788,  1249,  1165,   523,
    1253,   977,   820,  1249,   972,    94,   493,  1253,   977,   446,
     492,   972,    94,   378,   731,   494,   377,  1284,   790,   732,
     447,   106,    64,   524,  1289,   886,   901,   448,   106,   486,
     449,   450,   446,    74,   529,   530,  1084,   532,   451,   385,
     950,   898,   978,   446,   824,   713,   487,   799,   527,  1115,
    1076,   839,  1184,   573,   980,   574,   446,    88,   387,  1186,
     133,   671,  1166,   534,   672,   720,   537,   133,  1155,  1244,
    1269,   386,  1250,   605,  1156,   446,   917,   918,  1251,   446,
     921,   721,  1157,   446,   587,   612,   589,   592,  1051,  1248,
     619,   902,  1285,   674,   970,   599,   624,   446,   608,  1290,
     975,  1169,   976,   446,   722,   674,   645,   975,   587,   976,
    1254,  1287,   963,   943,   965,   755,  1292,  1276,   700,   701,
    1295,   446,   446,   452,   924,   453,  1022,   916,   786,   977,
     972,   440,   637,  1217,   641,   493,   977,   486,   441,   454,
     925,  1259,   446,   836,   494,   972,   973,   800,   446,  1234,
     446,   801,   972,   973,   487,   883,  1023,   446,   446,   971,
     446,   446,   940,   941,  1009,   455,   944,   389,   946,   888,
     446,   544,   390,   391,  1024,   889,   538,   488,   546,   699,
     926,   425,  1011,   426,   702,  1155,   545,   388,   967,   320,
     539,  1156,   547,   890,   900,   709,   710,   711,  1222,  1157,
     988,   989,   990,   719,   993,   994,   995,   996,   997,   998,
    1168,  1000,  1001,  1198,   931,   392,  1273,   824,  1202,   513,
     966,   428,  1035,   429,   974,   515,   975,   910,   976,  1167,
    1172,   974,  1188,  1197,   725,   726,  1028,  1279,  1030,  1031,
     836,   975,  1201,   976,   911,  1246,   905,   730,   975,  1008,
     976,   912,   986,   759,   987,   977,   394,   321,   322,   323,
    1009,   906,   953,   954,  1150,   955,   874,   875,   913,  1010,
     977,  1153,  1154,   360,    94,  1092,   361,   977,  1011,  1078,
    1061,    94,   655,   749,   792,   953,   954,   836,   876,   891,
     106,   674,   395,   362,   906,   777,   363,   106,  1239,   396,
     853,  1064,  1242,   956,   558,   655,   383,   507,   508,   384,
    1081,  1120,   750,   751,   795,   752,   753,   703,  1200,   397,
     703,  1225,   703,  1040,  1089,   409,  1225,   738,  1041,   133,
     739,   746,   415,   991,   747,   992,   133,  1096,   416,  1266,
     919,   920,  1099,  1100,   421,  1102,   848,   823,   953,   954,
    1106,   424,  1134,   837,   555,   556,   557,  1135,  1136,   908,
     909,   433,   683,   684,   427,   690,   691,   430,   854,   692,
     693,   434,   881,   881,  1223,  1224,   435,   437,  1215,  1216,
     444,   446,   445,   466,   467,   485,   497,   498,   499,   509,
     500,   520,   516,   837,   837,   837,   837,   535,   521,   522,
    1132,   528,   536,   531,   542,   533,   548,   379,   596,   578,
     594,   824,   598,   897,   609,   897,   595,   615,   349,   361,
     363,   381,   399,   622,  1146,   625,   853,  1147,   623,  1149,
     558,   626,   634,   629,   644,   648,  1190,   559,   647,   653,
     694,   649,   650,   695,  1245,   560,   696,   855,   856,   857,
     697,   727,   723,   707,   728,   736,   737,   858,   561,   733,
     562,   729,   734,   748,   756,   859,   757,   761,   762,   770,
     563,   860,   861,   564,   765,   771,   772,   776,   783,   784,
     812,   817,   814,   785,  1213,   822,   964,   813,   964,   818,
     821,   827,   830,   843,   854,   851,  1191,   838,  1192,   840,
      92,   891,   872,   870,  1196,   654,   894,   871,   922,   915,
     923,   930,   932,   928,   929,   935,   936,   937,  1204,  1205,
    1206,  1207,  1208,   939,  1209,   945,  1017,   942,   947,   465,
     968,   952,   985,   999,   962,  1006,  1016,  1026,   468,  1027,
    1002,  1018,  1005,  1214,  1059,  1029,   469,   470,  1020,   471,
    1021,  1058,  1074,  1034,  1036,  1056,   472,  1086,  1037,  1219,
     473,  1221,   474,   559,  1047,  1060,  1070,   475,  1093,  1067,
    1068,   560,  1069,   855,   856,   857,  1071,  1097,  1101,  1072,
    1103,  1077,  1233,   476,   561,  1082,   562,  1104,  1105,  1109,
     837,   859,  1114,  1117,  1123,  1112,   563,  1052,   861,   564,
    1073,  1130,  1113,  1122,  1129,  1091,  1124,   477,   478,   479,
     480,   481,   482,  1009,  1141,  1144,  1148,  1145,  1162,  1164,
     901,  1171,  1177,  1178,  1187,  1189,  1211,  1218,  1125,  1126,
    1228,   924,  1235,  1241,  1229,  1247,  1127,  1111,   587,  1252,
    1265,  1268,  1271,  1267,   592,  1270,   906,  1275,  1281,  1286,
    1278,  1291,  1118,   436,   438,  1107,  1294,   439,   642,  1272,
     643,   442,  1170,   443,  1019,  1283,  1195,   961,  1098,  1133,
    1108,  1007,   610,   458,  1143,  1140,  1095,  1119,  1137,  1065,
     662,   661,   685,   505,  1210,  1116,   503,   796,  1280,  1277,
     882,   603,  1128,   604,   899,   849,  1048,  1055,   637,  1131,
    1161,   850,  1053,  1232,  1180,   641,  1159,  1049,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   837,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1193,  1194,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1199,     0,     0,     0,     0,  1203,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   407,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1220,     0,     0,     0,     0,     0,
     837,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1240,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   837,     0,     0,
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
     111,     0,   611,     0,   112,     0,   113,   114,   115,     0,
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
       0,   698,     0,   112,     0,   113,   114,   115,     0,   116,
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
       0,     0,   112,   704,   113,   114,   115,     0,   116,   117,
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
       0,   107,   108,     0,     0,   109,   110,   111,     0,   718,
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
     107,   108,     0,     0,   109,   110,   111,     0,   758,     0,
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
     108,     0,     0,   109,   110,   111,     0,   791,     0,   112,
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
       0,     0,   109,   110,   111,     0,  1066,     0,   112,     0,
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
       0,   109,   110,   111,     0,  1090,     0,   112,     0,   113,
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
     109,   110,   111,     0,  1110,     0,   112,     0,   113,   114,
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
       0,     0,   111,     0,     0,     0,   112,   606,   113,     0,
       0,     0,     0,     0,   607,     0,   119,     0,   120,   121,
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
       0,    69,    70,  1062,     0,     0,     0,     0,     0,    75,
      76,    77,    78,     0,    79,     0,     0,     0,   347,    81,
      82,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,     0,    89,    90,   831,     0,     0,     0,     0,     0,
       0,    96,    97,     0,     0,     0,     0,    98,    99,   100,
     350,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,     0,     0,     0,   112,     0,   113,
     114,     0,     0,     0,     0,     0,     0,   119,     0,   120,
     121,   122,   123,   351,   125,   126,   127,   128,   129,   130,
       0,     0,   832,   132,     0,     0,     0,   135,     0,   136,
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
      86,    87,     0,    89,    90,   831,     0,     0,     0,     0,
       0,     0,    96,    97,     0,     0,     0,     0,    98,    99,
     100,   350,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,     0,     0,     0,   112,     0,
     113,   114,     0,     0,     0,     0,     0,     0,   119,     0,
     120,   121,   122,   123,   351,   125,   126,   127,   128,   129,
     130,     0,     0,   832,   132,     0,     0,     0,   135,     0,
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
        11,   744,   317,   370,   319,   616,   489,   490,   491,   492,
     485,   694,   695,   654,   587,   765,   383,   384,   117,   592,
     445,    58,   592,   872,   908,   375,   707,   799,   465,   860,
      21,   381,    20,   676,    80,    78,   386,    80,    38,    39,
      40,    80,    78,     7,    62,    56,    20,    58,    48,    20,
      18,    78,   123,   694,   695,     8,   981,    92,    93,    18,
      71,    20,   468,    33,   470,   471,    19,   473,    20,   475,
     127,  1013,  1014,    77,   389,    91,    43,   483,   484,   148,
      78,   127,    91,    94,   127,    84,    91,   123,   658,   117,
     660,    80,   112,   197,   127,    95,   117,   108,    68,    33,
     217,    91,   130,   114,    38,    91,    94,    91,  1236,  1237,
     425,   426,   181,   428,   429,   430,   431,   105,    96,   434,
      38,    39,    40,   133,   180,    96,   230,   205,  1256,   127,
      48,   446,   210,   189,  1262,    91,    54,    28,    78,   454,
     455,   129,    91,   110,    91,   133,   156,    65,   136,    67,
     170,   104,    70,   106,   170,    73,    90,   730,   162,   180,
      91,   166,   115,    91,   263,   133,     8,     9,   136,   140,
      91,   198,   199,     8,     9,   246,   166,    95,    96,   197,
     133,   167,   166,   926,   795,   552,   213,   937,   140,   246,
     154,  1116,   166,   232,   233,  1137,   166,   672,   673,   971,
     246,   516,   193,   246,   777,   775,   215,   166,   891,   981,
     246,    91,   230,   246,   170,   149,   583,   166,   217,   862,
     167,  1052,   140,   660,   224,   236,   225,   100,   909,   579,
      80,   268,   582,    91,   271,   166,   164,  1086,    20,   238,
      91,   240,   163,   232,   233,    87,    96,   225,   236,   136,
     891,   250,    87,   126,   253,   244,    55,   268,   198,   199,
     271,   667,   104,    91,   106,    91,   139,    91,   136,   104,
      80,   106,   111,   213,    91,   845,   254,   255,   133,   257,
     258,    78,   200,    91,    91,   320,   166,    91,   101,   324,
       4,   133,    91,    91,     8,   137,   180,     4,   133,    91,
     173,     8,   137,   136,   118,   189,   224,    91,   166,   123,
      46,   153,    94,   348,    91,   166,   101,    53,   153,   138,
      56,    57,    91,   105,   359,   360,   136,   362,    64,   101,
     127,   716,   174,    91,   649,   163,   155,   176,   349,   174,
     166,   656,   166,   378,  1116,   380,    91,   129,   101,   166,
     192,   133,   165,   364,   136,   163,   367,   192,   242,   166,
    1244,   140,   166,   398,   248,    91,   733,   734,   166,    91,
     737,   163,   256,    91,   385,   410,   387,   388,   861,  1228,
     415,   166,   166,   858,   111,   396,   421,    91,   399,   166,
     104,  1074,   106,    91,   163,   870,   821,   104,   409,   106,
     114,  1285,   787,   770,   789,   163,  1290,   114,   507,   508,
    1294,    91,    91,   149,    80,   151,   125,   732,   163,   133,
       8,    37,   433,   178,   435,   180,   133,   138,    44,   165,
      96,    19,    91,  1074,   189,     8,     9,   163,    91,  1189,
      91,   163,     8,     9,   155,   163,   155,    91,    91,   176,
      91,    91,   767,   768,    90,   191,   771,   133,   773,   163,
      91,   146,    58,    59,   173,   163,   161,   178,   161,   504,
     136,   205,   108,   207,   509,   242,   161,   101,   793,   133,
     175,   248,   175,   163,   163,   520,   521,   522,  1171,   256,
     805,   806,   807,   528,   809,   810,   811,   812,   813,   814,
    1073,   816,   817,  1114,   163,   101,  1249,   822,  1119,   270,
     163,   205,   163,   207,    87,   276,   104,   128,   106,   163,
     163,    87,   163,   163,   535,   536,   841,   115,   843,   844,
    1171,   104,   163,   106,   145,  1218,   118,   548,   104,    79,
     106,   128,   212,   578,   214,   133,    56,   201,   202,   203,
      90,   133,    60,    61,  1037,    63,   221,   222,   145,    99,
     133,  1044,  1045,   133,   137,   932,   136,   133,   108,   118,
     885,   137,    80,   225,   609,    60,    61,  1218,   243,    84,
     153,  1056,    28,   133,   133,   596,   136,   153,  1199,   136,
      80,    96,  1203,   101,    84,    80,    47,   171,   172,    50,
     915,   174,   254,   255,   615,   257,   258,   510,   174,   136,
     513,  1175,   515,   242,   929,   101,  1180,   223,   247,   192,
     226,   223,   133,   212,   226,   214,   192,   942,    14,  1240,
     109,   110,   947,   948,   133,   950,   671,   648,    60,    61,
     955,   195,  1009,   654,   201,   202,   203,   109,   110,   725,
     726,   101,   486,   487,   136,   493,   494,   205,   148,   495,
     496,   133,   696,   697,  1173,  1174,   101,     0,  1151,  1152,
     170,    91,   170,   147,    76,   235,    71,   179,    85,   134,
      86,   133,   136,   694,   695,   696,   697,    38,   133,   133,
    1005,   133,    38,   166,    20,   166,   101,    18,   101,   133,
     252,  1016,   101,   714,   133,   716,   252,    25,   136,   136,
     136,   136,   136,    15,  1029,   193,    80,  1032,   166,  1034,
      84,    20,   211,   166,    37,   101,  1093,   217,   149,    91,
     211,   150,   150,    78,  1217,   225,    78,   227,   228,   229,
      78,    20,   136,   166,    91,   108,   113,   237,   238,   140,
     240,    91,   140,    20,   166,   245,   166,    80,    33,   113,
     250,   251,   252,   253,    80,   123,    91,   163,   166,   166,
      78,   123,   205,   166,  1141,   150,   787,   217,   789,   163,
     170,   101,   101,   127,   148,   253,  1101,   101,  1103,   101,
     133,    84,   241,   234,  1109,    78,   133,   236,   255,   123,
     256,   133,   113,   256,   177,   140,   113,    80,  1123,  1124,
    1125,  1126,  1127,   101,  1129,   101,   827,   127,   123,   830,
      25,   230,    20,   101,   133,   101,    91,   838,   113,   840,
     219,    91,   133,  1148,    49,   127,   121,   122,   136,   124,
     136,   256,    78,   127,   166,   127,   131,    20,   231,  1164,
     135,  1166,   137,   217,   231,   125,   125,   142,    91,   894,
     166,   225,   166,   227,   228,   229,   166,   170,   123,   166,
     127,   906,  1187,   158,   238,   256,   240,   101,   101,    63,
     891,   245,   113,     6,   213,   166,   250,   251,   252,   253,
     901,   136,   166,   170,   165,   930,   213,   182,   183,   184,
     185,   186,   187,    90,    90,   166,   127,   166,   249,   165,
     101,    78,    20,    20,   107,    80,   163,    78,   213,   213,
      20,    80,    61,   176,   239,   165,   217,   962,   939,   101,
     176,   101,  1247,   176,   945,   165,   133,    77,   176,   101,
     162,   101,   977,   195,   198,   956,   166,   198,   444,   239,
     444,   201,  1075,   202,   830,  1270,  1107,   782,   945,  1006,
     957,   822,   409,   235,  1018,  1016,   939,   978,  1013,   892,
     467,   466,   488,   260,  1130,   971,   256,   616,  1262,  1256,
     697,   397,   999,   397,   716,   672,   858,   870,   999,  1003,
    1056,   673,   862,  1185,  1085,  1006,  1051,   859,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1062,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1074,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1104,  1105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1115,    -1,    -1,    -1,    -1,  1120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1165,    -1,    -1,    -1,    -1,    -1,
    1171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     301,   303,   304,   306,   308,   309,   310,   311,   312,   317,
     318,   319,   320,   325,   327,   329,   330,   331,   336,   357,
     360,   363,   364,   365,   366,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   413,   414,   415,   429,   430,
     432,   433,   434,   435,   436,   437,   438,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   457,   458,   459,
     460,   461,   462,   463,   466,   471,   472,   217,    28,   136,
     133,   201,   202,   203,   136,    26,    27,    31,    32,    33,
      34,    35,    36,    37,    41,    42,    44,    45,    47,    52,
      53,    56,    57,    66,    68,    69,    81,   116,   133,   136,
     148,   181,   204,   205,   206,   208,   209,   216,   471,   133,
     133,   136,   133,   136,    38,    39,    40,    48,    54,    65,
      67,    70,    73,    95,    96,   140,   200,   224,   136,    18,
     133,   136,   470,    47,    50,   101,   140,   101,   101,   133,
      58,    59,   101,   322,    56,    28,   136,   136,   133,   136,
     471,    33,    35,    36,    42,    81,   397,   471,   471,   101,
     307,   318,   166,   318,   471,   133,    14,    16,   471,   471,
     389,   133,    21,   193,   195,   205,   207,   136,   205,   207,
     205,   205,   210,   101,   133,   101,   276,     0,   278,   279,
      37,    44,   281,   317,   170,   170,    91,    46,    53,    56,
      57,    64,   149,   151,   165,   191,   321,   326,   327,   328,
     345,   346,   350,   332,   333,   471,   147,    76,   113,   121,
     122,   124,   131,   135,   137,   142,   158,   182,   183,   184,
     185,   186,   187,   381,   382,   235,   138,   155,   178,   100,
     126,   139,   173,   180,   189,   117,   130,    71,   179,    85,
      86,   138,   155,   380,   133,   386,   389,   171,   172,   134,
     401,   402,   397,   401,   397,   401,   136,   319,   319,   318,
     133,   133,   133,   318,   318,   166,   173,   471,   133,   318,
     318,   166,   318,   166,   471,    38,    38,   471,   161,   175,
     148,   181,    20,   469,   146,   161,   161,   175,   101,   302,
      33,    38,    90,   149,   470,   201,   202,   203,    84,   217,
     225,   238,   240,   250,   253,   484,   485,   486,   487,   488,
     491,   496,   497,   318,   318,    20,   166,   470,   133,   140,
     469,    96,   140,   300,   469,   358,   359,   471,   470,   471,
     337,   339,   471,   319,   252,   252,   101,   340,   101,   471,
      33,    68,   166,   453,   454,   318,   166,   173,   471,   133,
     358,   163,   318,   170,   166,    25,   417,   418,   419,   318,
       7,   154,    15,   166,   318,   193,    20,   319,   319,   166,
     319,   319,   319,   319,   211,   464,   465,   471,   319,   338,
     344,   471,   283,   284,    37,   285,   319,   149,   101,   150,
     150,   319,   319,    91,    78,    80,   127,   246,   334,   335,
     440,   365,   366,   368,   368,   368,   368,   367,   368,   368,
     368,   133,   136,   236,   404,   473,   475,   476,   477,   478,
     479,   480,   481,   371,   371,   370,   372,   372,   372,   372,
     373,   373,   374,   374,   211,    78,    78,    78,   163,   318,
     389,   389,   318,   402,   166,   319,   412,   166,   163,   318,
     318,   318,   166,   163,    91,   166,    91,   166,   163,   318,
     163,   163,   163,   136,   305,   471,   471,    20,    91,    91,
     471,   118,   123,   140,   140,   469,   108,   113,   223,   226,
      96,   225,   254,   255,   257,   258,   223,   226,    20,   225,
     254,   255,   257,   258,   166,   163,   166,   166,   163,   318,
     470,    80,    33,   470,   469,    80,    91,   167,   127,   440,
     113,   123,    91,   123,   335,   440,   163,   471,    62,   197,
     230,   323,   324,   166,   166,   166,   163,    91,   166,    91,
     166,   163,   318,   167,   170,   471,   418,   419,   111,   176,
     163,   163,   112,   170,    78,   198,   199,   213,    78,   198,
     199,   213,    78,   217,   205,    91,   215,   123,   163,    55,
      91,   170,   150,   471,   319,   351,   352,   101,   347,   348,
     101,   132,   190,   441,   443,   444,   445,   471,   101,   319,
     101,   127,   335,   127,   127,   334,   335,   368,   318,   473,
     479,   253,   507,    80,   148,   227,   228,   229,   237,   245,
     251,   252,   474,   482,   483,   484,   498,   501,   502,   504,
     234,   236,   241,   503,   221,   222,   243,   499,   441,   441,
     439,   444,   439,   163,   164,    91,   166,   306,   163,   163,
     163,    84,   361,   362,   133,   455,   456,   471,   455,   456,
     163,   101,   166,   313,   314,   118,   133,   316,   305,   305,
     128,   145,   128,   145,   440,   123,   319,   469,   469,   109,
     110,   469,   255,   256,    80,    96,   136,   490,   256,   177,
     133,   163,   113,   299,   469,   140,   113,    80,   299,   101,
     319,   319,   127,   469,   319,   101,   319,   123,   123,   335,
     127,   440,   230,    60,    61,    63,   101,   334,   341,   342,
     343,   324,   133,   455,   471,   455,   163,   319,    25,   419,
     111,   176,     8,     9,    87,   104,   106,   133,   174,   315,
     414,   416,   427,   428,   431,    20,   212,   214,   319,   319,
     319,   212,   214,   319,   319,   319,   319,   319,   319,   101,
     319,   319,   219,   467,   468,   133,   101,   351,    79,    90,
      99,   108,   353,   354,   355,   356,    91,   471,    91,   333,
     136,   136,   125,   155,   173,   442,   471,   471,   319,   127,
     319,   319,   127,   335,   127,   163,   166,   231,   197,   230,
     242,   247,   506,    80,   232,   233,   500,   231,   476,   506,
     369,   372,   251,   482,   484,   477,   127,   500,   256,    49,
     125,   319,   101,   441,    96,   362,   163,   318,   166,   166,
     125,   166,   166,   471,    78,    91,   166,   318,   118,   316,
     306,   319,   256,    80,   136,   493,    20,    96,   490,   319,
     163,   318,   469,    91,   299,   359,   319,   170,   339,   319,
     319,   123,   319,   127,   101,   101,   319,   471,   343,    63,
     163,   318,   166,   166,   113,   174,   416,     6,   318,   471,
     174,   427,   170,   213,   213,   213,   213,   217,   465,   165,
     136,   468,   319,   344,   469,   109,   110,   355,   356,   356,
     352,    90,   349,   348,   166,   166,   319,   319,   127,   319,
     372,    43,   110,   372,   372,   242,   248,   256,   505,   505,
     369,   478,   249,   471,   165,   101,   165,   163,   440,   441,
     314,    78,   163,   117,   180,   492,   495,    20,    20,   494,
     492,   244,   500,    91,   166,    91,   166,   107,   163,    80,
     469,   319,   319,   471,   471,   342,   319,   163,   419,   471,
     174,   163,   419,   471,   319,   319,   319,   319,   319,   319,
     398,   163,   356,   469,   319,   372,   372,   178,    78,   319,
     471,   319,   441,   493,   493,   495,    20,   166,    20,   239,
     489,   490,   489,   319,   299,    61,    77,   162,   420,   419,
     471,   176,   419,    91,   166,   372,   441,   165,   500,    91,
     166,   166,   101,     4,   114,   423,   424,   426,   428,    19,
     115,   421,   422,   425,   428,   176,   419,   176,   101,   316,
     165,   319,   239,   490,   471,    77,   114,   426,   162,   115,
     425,   176,   471,   319,    91,   166,   101,   316,   471,    91,
     166,   101,   316,   471,   166,   316
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
     303,   303,   303,   304,   304,   305,   305,   305,   305,   306,
     307,   307,   308,   309,   310,   311,   311,   312,   312,   312,
     312,   312,   313,   313,   314,   314,   315,   316,   317,   318,
     318,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   320,   321,
     322,   322,   323,   323,   323,   324,   324,   325,   325,   326,
     327,   327,   327,   328,   328,   328,   328,   328,   329,   329,
     330,   330,   331,   332,   332,   333,   333,   333,   333,   333,
     333,   333,   333,   334,   335,   336,   337,   337,   338,   338,
     339,   339,   339,   339,   340,   340,   341,   341,   341,   342,
     342,   342,   343,   343,   343,   344,   345,   346,   347,   347,
     348,   348,   349,   350,   350,   351,   351,   352,   352,   353,
     353,   353,   353,   353,   353,   353,   354,   354,   355,   355,
     356,   357,   357,   358,   358,   359,   359,   360,   360,   361,
     361,   362,   362,   363,   364,   364,   365,   365,   366,   366,
     366,   366,   366,   367,   366,   366,   366,   366,   368,   368,
     368,   369,   369,   370,   370,   370,   371,   371,   371,   371,
     371,   372,   372,   372,   373,   373,   373,   374,   374,   375,
     375,   376,   376,   377,   377,   378,   378,   379,   379,   379,
     379,   380,   380,   380,   381,   381,   381,   381,   381,   381,
     382,   382,   382,   383,   383,   383,   383,   384,   384,   385,
     385,   386,   386,   387,   387,   387,   387,   388,   389,   389,
     389,   390,   390,   391,   391,   391,   391,   392,   392,   393,
     393,   393,   393,   393,   393,   393,   394,   394,   395,   395,
     396,   396,   396,   396,   396,   397,   397,   398,   398,   399,
     399,   399,   400,   400,   401,   401,   402,   403,   403,   403,
     403,   403,   403,   403,   403,   404,   404,   405,   405,   405,
     406,   407,   407,   408,   409,   410,   411,   411,   412,   412,
     413,   413,   414,   414,   414,   415,   415,   415,   415,   415,
     415,   416,   416,   417,   417,   418,   419,   419,   420,   420,
     421,   421,   422,   422,   422,   422,   423,   423,   424,   424,
     424,   424,   425,   425,   426,   426,   427,   427,   427,   427,
     428,   428,   428,   428,   429,   429,   430,   430,   431,   432,
     432,   432,   432,   432,   432,   433,   434,   434,   434,   434,
     435,   435,   435,   435,   436,   437,   438,   438,   438,   438,
     439,   439,   440,   441,   441,   441,   442,   442,   442,   443,
     443,   443,   444,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   446,   447,   447,   447,   448,   449,   450,   450,
     450,   451,   451,   451,   451,   451,   452,   453,   453,   453,
     453,   453,   453,   453,   454,   455,   456,   457,   458,   458,
     458,   459,   459,   459,   459,   459,   459,   459,   459,   459,
     459,   460,   460,   461,   461,   462,   463,   464,   464,   465,
     466,   467,   467,   468,   468,   468,   468,   469,   470,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   472,   472,   473,   473,   473,   473,
     474,   474,   474,   474,   475,   475,   476,   476,   477,   477,
     478,   478,   479,   479,   479,   480,   480,   481,   481,   482,
     482,   482,   482,   482,   483,   484,   484,   484,   484,   484,
     484,   484,   485,   485,   485,   485,   486,   486,   486,   486,
     487,   487,   488,   488,   488,   488,   488,   488,   488,   489,
     489,   490,   490,   490,   490,   491,   491,   491,   491,   491,
     492,   492,   493,   493,   494,   494,   495,   495,   496,   497,
     497,   498,   498,   498,   499,   499,   499,   499,   499,   500,
     500,   500,   500,   501,   502,   503,   504,   504,   505,   505,
     505,   506,   506,   507
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
       1,     3,     3,     3,     3,     6,     5,     8,     2,     3,
       5,     4,     6,     3,     3,     2,     3,     4,     5,     3,
       2,     3,     5,     3,     5,     2,     2,     5,     5,     6,
       6,     6,     1,     3,     2,     3,     3,     3,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     2,     4,     3,     5,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     2,     1,     4,     3,     4,     4,     5,     4,
       5,     5,     6,     3,     3,     3,     1,     4,     1,     4,
       3,     4,     4,     5,     4,     5,     1,     2,     3,     1,
       2,     1,     6,     3,     3,     1,     2,     3,     1,     3,
       2,     3,     2,     3,     4,     1,     3,     1,     2,     1,
       1,     1,     2,     2,     2,     3,     1,     1,     2,     2,
       2,     5,     5,     1,     4,     3,     4,     8,    10,     1,
       2,     4,     7,     8,     1,     3,     1,     3,     1,     3,
       3,     3,     3,     0,     4,     3,     3,     3,     1,     3,
       4,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     4,     1,
       4,     1,     4,     1,     4,     1,     2,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     5,     5,     5,     3,     4,     1,
       2,     3,     2,     1,     2,     2,     1,     1,     1,     3,
       3,     1,     1,     1,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     4,     4,     3,     4,     1,     3,
       1,     1,     1,     1,     1,     4,     5,     8,     9,     9,
      10,     1,     2,     1,     2,     6,     0,     1,     3,     3,
       0,     1,     1,     1,     2,     2,     0,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     4,     4,     5,     6,     7,
       4,     5,     6,     7,     4,     4,     4,     5,     6,     7,
       1,     2,     2,     1,     2,     3,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     4,     3,     3,     3,     4,
       4,     3,     4,     6,     4,     6,     3,     3,     4,     6,
       6,     4,     6,     6,     4,     1,     2,     1,     3,     3,
       3,     5,     7,     7,     5,     5,     5,     7,     7,     5,
       5,     3,     3,     5,     7,     5,     7,     1,     4,     3,
       5,     1,     2,     5,     8,    11,    14,     1,     1,     1,
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
       1,     1,     1,     1,     7,     4,     1,     2,     3,     4,
       1,     1,     2,     2,     1,     3,     1,     3,     1,     4,
       1,     2,     1,     2,     3,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     3,     5,     7,     5,     7,     2,     1,
       3,     2,     4,     4,     6,     4,     5,     4,     5,     3,
       1,     2,     2,     3,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     1,     2,     1,     2,
       3,     3,     4,     3,     3,     3,     2,     2,     1,     1,
       1,     1,     1,     3
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
  "VarNameAndType", "VarDecl", "ConstructionDecl", "FunctionSig", "Block",
  "BlockBody", "AssignExpr", "ExitExpr", "WhileExpr", "FlowCtlStatement",
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
     281,   317,    -1,   317,    -1,   280,   281,    -1,    47,   140,
     470,   113,   469,   170,    -1,   282,   170,    -1,   283,   170,
      -1,   282,   170,   283,   170,    -1,   284,    -1,   282,   170,
     284,    -1,   285,    -1,   283,   170,   285,    -1,   286,    -1,
     287,    -1,   288,    -1,   290,    -1,   303,    -1,   312,    -1,
     291,    -1,   292,    -1,   289,    -1,   296,    -1,   297,    -1,
     304,    -1,   293,    -1,   294,    -1,   295,    -1,   458,    -1,
     298,    -1,   301,    -1,    37,   140,   470,   113,   469,    -1,
      37,    73,   161,    -1,    37,    73,   175,    -1,    37,    96,
      33,   140,   469,    -1,    37,    96,    38,   140,   469,    -1,
      37,    48,   471,    20,    -1,    37,   224,   484,    -1,    37,
      65,   148,    -1,    37,    65,   181,    -1,    37,    96,   149,
     108,   109,    -1,    37,    96,   149,   108,   110,    -1,    37,
      70,   161,    91,   128,    -1,    37,    70,   161,    91,   145,
      -1,    37,    70,   146,    91,   128,    -1,    37,    70,   146,
      91,   145,    -1,    37,    96,    90,   469,    -1,    37,    67,
     469,    -1,    44,    50,   469,    -1,    44,    50,   300,   469,
      -1,    44,    50,   469,    80,   299,    -1,    44,    50,   300,
     469,    80,   299,    -1,   469,    -1,   299,    91,   469,    -1,
     140,   470,   113,    -1,    96,    33,   140,    -1,    44,    47,
     469,    -1,    44,    47,   140,   470,   113,   469,    -1,    44,
      47,   469,    80,   299,    -1,    44,    47,   140,   470,   113,
     469,    80,   299,    -1,   101,   471,    -1,   101,   471,   440,
      -1,    37,    95,   302,   123,   319,    -1,    37,    95,   302,
     118,    -1,    37,    95,   302,   118,   123,   319,    -1,    37,
      54,   161,    -1,    37,    54,   175,    -1,   136,   166,    -1,
     136,   313,   166,    -1,   136,   166,    78,   441,    -1,   136,
     313,   166,    78,   441,    -1,   133,   307,   163,    -1,   318,
     170,    -1,   307,   318,   170,    -1,    52,   101,   471,   123,
     319,    -1,    26,   217,   319,    -1,    30,   136,   319,   166,
     306,    -1,    27,    28,    -1,    66,    28,    -1,    37,    38,
     471,   305,   118,    -1,    37,    38,   471,   305,   316,    -1,
      37,    39,    38,   471,   305,   118,    -1,    37,    39,    38,
     471,   305,   316,    -1,    37,    40,    38,   471,   305,   306,
      -1,   314,    -1,   313,    91,   314,    -1,   101,   471,    -1,
     101,   471,   440,    -1,   133,   318,   163,    -1,   133,   318,
     163,    -1,   318,    -1,   319,    -1,   318,    91,   319,    -1,
     320,    -1,   357,    -1,   360,    -1,   363,    -1,   364,    -1,
     459,    -1,   460,    -1,   462,    -1,   461,    -1,   463,    -1,
     466,    -1,   472,    -1,   309,    -1,   310,    -1,   311,    -1,
     308,    -1,   306,    -1,   329,   321,    -1,   165,   319,    -1,
      58,   252,    -1,    59,   252,    -1,   197,    -1,   230,    -1,
      62,   230,    -1,   323,   341,    63,   319,    -1,   323,    63,
     319,    -1,    56,   322,   340,   324,   324,    -1,    56,   322,
     340,   324,    -1,    64,   101,   471,    -1,   331,    -1,   336,
      -1,   325,    -1,   327,    -1,   345,    -1,   350,    -1,   346,
      -1,   326,    -1,   327,    -1,   329,   328,    -1,    56,   101,
      -1,    57,    56,   101,    -1,   330,   332,    -1,   333,    -1,
     332,    91,   101,   333,    -1,   471,   127,   319,    -1,   471,
     440,   127,   319,    -1,   471,   334,   127,   319,    -1,   471,
     440,   334,   127,   319,    -1,   471,   335,   127,   319,    -1,
     471,   440,   335,   127,   319,    -1,   471,   334,   335,   127,
     319,    -1,   471,   440,   334,   335,   127,   319,    -1,    80,
     101,   471,    -1,   246,   101,   471,    -1,    53,   101,   337,
      -1,   339,    -1,   337,    91,   101,   339,    -1,   344,    -1,
     338,    91,   101,   344,    -1,   471,   123,   319,    -1,   471,
     440,   123,   319,    -1,   471,   335,   123,   319,    -1,   471,
     440,   335,   123,   319,    -1,   101,   471,   127,   319,    -1,
     101,   471,   440,   127,   319,    -1,   342,    -1,   101,   471,
      -1,   101,   471,   342,    -1,   334,    -1,   334,   343,    -1,
     343,    -1,    60,   101,   471,    61,   101,   471,    -1,    61,
     101,   471,    -1,    60,   101,   471,    -1,   471,    -1,   191,
     319,    -1,   151,   150,   347,    -1,   348,    -1,   347,    91,
     348,    -1,   101,   471,    -1,   101,   471,   349,    -1,    90,
     469,    -1,   149,   150,   351,    -1,    46,   149,   150,   351,
      -1,   352,    -1,   351,    91,   352,    -1,   319,    -1,   319,
     353,    -1,   354,    -1,   355,    -1,   356,    -1,   354,   355,
      -1,   354,   356,    -1,   355,   356,    -1,   354,   355,   356,
      -1,    79,    -1,    99,    -1,   108,   109,    -1,   108,   110,
      -1,    90,   469,    -1,    45,   101,   358,   167,   319,    -1,
     116,   101,   358,   167,   319,    -1,   359,    -1,   358,    91,
     101,   359,    -1,   471,   127,   319,    -1,   471,   440,   127,
     319,    -1,    32,   136,   318,   166,   361,    96,   165,   319,
      -1,    32,   136,   318,   166,   361,    96,   101,   471,   165,
     319,    -1,   362,    -1,   361,   362,    -1,    84,   441,   165,
     319,    -1,    84,   101,   471,    78,   441,   165,   319,    -1,
      41,   136,   318,   166,   177,   319,   107,   319,    -1,   365,
      -1,   364,   147,   365,    -1,   366,    -1,   365,    76,   366,
      -1,   368,    -1,   368,   381,   368,    -1,   368,   382,   368,
      -1,   368,   113,   368,    -1,   368,   142,   368,    -1,    -1,
     368,   137,   367,   368,    -1,   368,   135,   368,    -1,   368,
     124,   368,    -1,   368,   122,   368,    -1,   369,    -1,   369,
     235,   473,    -1,   369,   235,   473,   507,    -1,   370,    -1,
     370,   178,   370,    -1,   371,    -1,   370,   155,   371,    -1,
     370,   138,   371,    -1,   372,    -1,   371,   173,   372,    -1,
     371,   100,   372,    -1,   371,   126,   372,    -1,   371,   139,
     372,    -1,   373,    -1,   372,   180,   373,    -1,   372,   189,
     373,    -1,   374,    -1,   373,   130,   374,    -1,   373,   117,
     374,    -1,   375,    -1,   375,    71,   211,   441,    -1,   376,
      -1,   376,   179,    78,   441,    -1,   377,    -1,   377,    85,
      78,   439,    -1,   378,    -1,   378,    86,    78,   439,    -1,
     380,    -1,   379,   380,    -1,   155,    -1,   138,    -1,   379,
     155,    -1,   379,   138,    -1,   383,    -1,   387,    -1,   384,
      -1,   182,    -1,   187,    -1,   186,    -1,   185,    -1,   184,
      -1,   183,    -1,   131,    -1,   158,    -1,   121,    -1,    31,
     133,   318,   163,    -1,    31,   201,   133,   318,   163,    -1,
      31,   202,   133,   318,   163,    -1,    31,   203,   133,   318,
     163,    -1,   385,   133,   163,    -1,   385,   133,   318,   163,
      -1,   386,    -1,   385,   386,    -1,   156,   471,    15,    -1,
     156,    16,    -1,   388,    -1,   388,   389,    -1,   172,   389,
      -1,   389,    -1,   171,    -1,   390,    -1,   390,   171,   389,
      -1,   390,   172,   389,    -1,   391,    -1,   400,    -1,   392,
      -1,   392,   401,    -1,   395,    -1,   395,   401,    -1,   393,
     397,    -1,   394,    -1,    89,    -1,    97,    -1,    82,    -1,
     169,    -1,    98,    -1,   120,    -1,   119,    -1,   397,    -1,
      83,   397,    -1,   396,   397,    -1,   103,    -1,   152,    -1,
      74,    -1,   160,    -1,   159,    -1,    75,    -1,   445,    -1,
     398,    -1,   471,    -1,   399,    -1,   173,    -1,    10,    -1,
      17,    -1,   403,    -1,   403,   401,    -1,   402,    -1,   401,
     402,    -1,   134,   318,   164,    -1,   404,    -1,   406,    -1,
     407,    -1,   408,    -1,   411,    -1,   413,    -1,   409,    -1,
     410,    -1,   405,    -1,   457,    -1,    94,    -1,   129,    -1,
     105,    -1,   101,   471,    -1,   136,   166,    -1,   136,   318,
     166,    -1,   102,    -1,   148,   133,   318,   163,    -1,   181,
     133,   318,   163,    -1,   471,   136,   166,    -1,   471,   136,
     412,   166,    -1,   319,    -1,   412,    91,   319,    -1,   414,
      -1,   432,    -1,   415,    -1,   429,    -1,   430,    -1,   137,
     471,   419,   111,    -1,   137,   471,   417,   419,   111,    -1,
     137,   471,   419,   176,   174,   471,   419,   176,    -1,   137,
     471,   419,   176,   416,   174,   471,   419,   176,    -1,   137,
     471,   417,   419,   176,   174,   471,   419,   176,    -1,   137,
     471,   417,   419,   176,   416,   174,   471,   419,   176,    -1,
     427,    -1,   416,   427,    -1,   418,    -1,   417,   418,    -1,
      25,   471,   419,   113,   419,   420,    -1,    -1,    25,    -1,
     162,   421,   162,    -1,    77,   423,    77,    -1,    -1,   422,
      -1,   115,    -1,   425,    -1,   422,   115,    -1,   422,   425,
      -1,    -1,   424,    -1,   114,    -1,   426,    -1,   424,   114,
      -1,   424,   426,    -1,    19,    -1,   428,    -1,     4,    -1,
     428,    -1,   414,    -1,     9,    -1,   431,    -1,   428,    -1,
       8,    -1,   104,    -1,   106,    -1,   315,    -1,   192,    21,
     193,    -1,   192,   193,    -1,   153,    14,   154,    -1,   153,
      14,     7,    -1,    87,     6,    -1,   433,    -1,   434,    -1,
     435,    -1,   436,    -1,   437,    -1,   438,    -1,    34,   133,
     318,   163,    -1,    33,   471,   133,   163,    -1,    33,   471,
     133,   318,   163,    -1,    33,   133,   318,   163,   133,   163,
      -1,    33,   133,   318,   163,   133,   318,   163,    -1,    81,
     471,   133,   163,    -1,    81,   471,   133,   318,   163,    -1,
      81,   133,   318,   163,   133,   163,    -1,    81,   133,   318,
     163,   133,   318,   163,    -1,    35,   133,   318,   163,    -1,
      36,   133,   318,   163,    -1,    42,   470,   133,   163,    -1,
      42,   470,   133,   318,   163,    -1,    42,   133,   318,   163,
     133,   163,    -1,    42,   133,   318,   163,   133,   318,   163,
      -1,   444,    -1,   444,   125,    -1,    78,   441,    -1,   443,
      -1,   443,   442,    -1,   190,   136,   166,    -1,   125,    -1,
     173,    -1,   155,    -1,   444,    -1,   445,    -1,   132,   136,
     166,    -1,   471,    -1,   447,    -1,   453,    -1,   451,    -1,
     454,    -1,   452,    -1,   450,    -1,   449,    -1,   448,    -1,
     446,    -1,   205,   136,   166,    -1,    69,   136,   166,    -1,
      69,   136,   453,   166,    -1,    69,   136,   454,   166,    -1,
      35,   136,   166,    -1,    36,   136,   166,    -1,    42,   136,
     166,    -1,    42,   136,   470,   166,    -1,    42,   136,    20,
     166,    -1,    81,   136,   166,    -1,    81,   136,   471,   166,
      -1,    81,   136,   471,    91,   455,   166,    -1,    81,   136,
     173,   166,    -1,    81,   136,   173,    91,   455,   166,    -1,
     168,   471,   166,    -1,    33,   136,   166,    -1,    33,   136,
     471,   166,    -1,    33,   136,   471,    91,   455,   166,    -1,
      33,   136,   471,    91,   456,   166,    -1,    33,   136,   173,
     166,    -1,    33,   136,   173,    91,   455,   166,    -1,    33,
     136,   173,    91,   456,   166,    -1,    68,   136,   471,   166,
      -1,   471,    -1,   471,   125,    -1,    20,    -1,    37,   200,
     201,    -1,    37,   200,   202,    -1,    37,   200,   203,    -1,
     206,   205,   319,   213,   319,    -1,   206,   205,   319,    78,
     212,   213,   319,    -1,   206,   205,   319,    78,   214,   213,
     319,    -1,   206,   205,   319,   198,   319,    -1,   206,   205,
     319,   199,   319,    -1,   206,   207,   319,   213,   319,    -1,
     206,   207,   319,    78,   212,   213,   319,    -1,   206,   207,
     319,    78,   214,   213,   319,    -1,   206,   207,   319,   198,
     319,    -1,   206,   207,   319,   199,   319,    -1,   204,   205,
     319,    -1,   204,   207,   319,    -1,   209,   205,   319,   217,
     319,    -1,   209,   210,   211,   205,   319,   217,   319,    -1,
     208,   205,   319,    78,   319,    -1,   216,   101,   464,   215,
     319,   165,   319,    -1,   465,    -1,   464,    91,   101,   465,
      -1,   471,   123,   319,    -1,   218,   133,   319,   163,   467,
      -1,   468,    -1,   467,   468,    -1,   219,   136,   398,   166,
     316,    -1,   219,   136,   398,    91,   101,   471,   166,   316,
      -1,   219,   136,   398,    91,   101,   471,    91,   101,   471,
     166,   316,    -1,   219,   136,   398,    91,   101,   471,    91,
     101,   471,    91,   101,   471,   166,   316,    -1,    20,    -1,
      18,    -1,    18,    -1,   108,    -1,    81,    -1,    36,    -1,
      69,    -1,    33,    -1,   132,    -1,    41,    -1,   205,    -1,
      42,    -1,    72,    -1,    68,    -1,    35,    -1,    32,    -1,
     190,    -1,    73,    -1,   224,    -1,    67,    -1,   202,    -1,
     201,    -1,   126,    -1,    34,    -1,   236,    -1,   223,    -1,
     226,    -1,   225,    -1,   253,    -1,   254,    -1,   257,    -1,
     255,    -1,   258,    -1,   229,    -1,   231,    -1,    49,    -1,
     197,    -1,   230,    -1,    43,    -1,   203,    -1,   216,    -1,
     210,    -1,   182,    -1,   187,    -1,   186,    -1,   185,    -1,
     184,    -1,   183,    -1,    80,    -1,    95,    -1,   165,    -1,
      56,    -1,    57,    -1,    58,    -1,    59,    -1,    60,    -1,
      61,    -1,    62,    -1,    63,    -1,    64,    -1,   127,    -1,
      53,    -1,   191,    -1,   150,    -1,   151,    -1,   149,    -1,
      46,    -1,    79,    -1,    99,    -1,   109,    -1,   110,    -1,
      90,    -1,    45,    -1,   116,    -1,   167,    -1,    84,    -1,
      78,    -1,   177,    -1,   107,    -1,   147,    -1,    76,    -1,
      71,    -1,   211,    -1,    85,    -1,   178,    -1,   100,    -1,
     139,    -1,   180,    -1,   130,    -1,   117,    -1,    31,    -1,
      86,    -1,   179,    -1,   131,    -1,   161,    -1,   175,    -1,
     140,    -1,   118,    -1,   112,    -1,   146,    -1,   128,    -1,
     145,    -1,    37,    -1,    54,    -1,    65,    -1,    96,    -1,
      70,    -1,    48,    -1,   195,    -1,    44,    -1,    50,    -1,
      47,    -1,    38,    -1,   246,    -1,   235,    -1,   251,    -1,
     252,    -1,   228,    -1,   241,    -1,   249,    -1,   245,    -1,
     227,    -1,   240,    -1,   250,    -1,   244,    -1,   239,    -1,
     238,    -1,   222,    -1,   221,    -1,   243,    -1,   232,    -1,
     233,    -1,   256,    -1,   248,    -1,   247,    -1,   242,    -1,
     209,    -1,   215,    -1,   212,    -1,   206,    -1,   199,    -1,
     198,    -1,   200,    -1,   217,    -1,   207,    -1,   208,    -1,
     214,    -1,   204,    -1,   213,    -1,    39,    -1,   148,    -1,
     181,    -1,    26,    -1,    28,    -1,    27,    -1,    66,    -1,
      52,    -1,   220,   101,   338,    55,   133,   319,   163,    -1,
      55,   133,   319,   163,    -1,   475,    -1,   475,   474,    -1,
     475,   251,   369,    -1,   475,   474,   251,   369,    -1,   484,
      -1,   482,    -1,   474,   484,    -1,   474,   482,    -1,   476,
      -1,   475,   237,   476,    -1,   477,    -1,   476,   234,   477,
      -1,   478,    -1,   477,   236,   127,   478,    -1,   479,    -1,
     236,   479,    -1,   480,    -1,   480,   503,    -1,   136,   473,
     166,    -1,   481,    -1,   481,   499,    -1,   404,    -1,   133,
     318,   163,    -1,   483,    -1,   502,    -1,   501,    -1,   504,
      -1,   498,    -1,   148,    -1,   485,    -1,   486,    -1,   487,
      -1,   488,    -1,   491,    -1,   496,    -1,   497,    -1,   240,
      -1,   250,    -1,    84,   223,    -1,    84,   226,    -1,   217,
     225,    -1,   253,   225,    -1,   225,   223,    -1,   225,   226,
      -1,   217,   254,    -1,   253,   254,    -1,   217,   257,   490,
      -1,   217,   257,    96,    -1,   217,   257,   136,   490,   166,
      -1,   217,   257,   136,   490,    91,   489,   166,    -1,   217,
     257,   136,    96,   166,    -1,   217,   257,   136,    96,    91,
     489,   166,    -1,   253,   257,    -1,   490,    -1,   489,    91,
     490,    -1,    80,    20,    -1,    80,    20,   244,    20,    -1,
      80,    20,   500,   239,    -1,    80,    20,   244,    20,   500,
     239,    -1,   217,   255,   256,   493,    -1,   217,   255,   256,
     493,   492,    -1,   217,    96,   255,   256,    -1,   217,    96,
     255,   256,   492,    -1,   253,   255,   256,    -1,   495,    -1,
     492,   495,    -1,    80,    20,    -1,   136,   494,   166,    -1,
      20,    -1,   494,    20,    -1,   180,   493,    -1,   117,   493,
      -1,   238,    20,    -1,   217,   258,    -1,   253,   258,    -1,
      80,   197,    -1,    80,   230,    -1,   229,   231,    -1,   222,
      -1,   222,    49,    -1,   221,    -1,   221,   256,    -1,   243,
      -1,   232,   372,    -1,    80,   110,   372,    -1,    80,    43,
     372,    -1,   233,   372,   178,   372,    -1,   228,   500,   505,
      -1,   252,   372,   505,    -1,   241,   500,   249,    -1,   245,
     506,    -1,   227,   506,    -1,   256,    -1,   248,    -1,   242,
      -1,   247,    -1,   242,    -1,   253,   231,   372,    -1
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
     214,   216,   220,   224,   228,   232,   239,   245,   254,   257,
     261,   267,   272,   279,   283,   287,   290,   294,   299,   305,
     309,   312,   316,   322,   326,   332,   335,   338,   344,   350,
     357,   364,   371,   373,   377,   380,   384,   388,   392,   394,
     396,   400,   402,   404,   406,   408,   410,   412,   414,   416,
     418,   420,   422,   424,   426,   428,   430,   432,   434,   437,
     440,   443,   446,   448,   450,   453,   458,   462,   468,   473,
     477,   479,   481,   483,   485,   487,   489,   491,   493,   495,
     498,   501,   505,   508,   510,   515,   519,   524,   529,   535,
     540,   546,   552,   559,   563,   567,   571,   573,   578,   580,
     585,   589,   594,   599,   605,   610,   616,   618,   621,   625,
     627,   630,   632,   639,   643,   647,   649,   652,   656,   658,
     662,   665,   669,   672,   676,   681,   683,   687,   689,   692,
     694,   696,   698,   701,   704,   707,   711,   713,   715,   718,
     721,   724,   730,   736,   738,   743,   747,   752,   761,   772,
     774,   777,   782,   790,   799,   801,   805,   807,   811,   813,
     817,   821,   825,   829,   830,   835,   839,   843,   847,   849,
     853,   858,   860,   864,   866,   870,   874,   876,   880,   884,
     888,   892,   894,   898,   902,   904,   908,   912,   914,   919,
     921,   926,   928,   933,   935,   940,   942,   945,   947,   949,
     952,   955,   957,   959,   961,   963,   965,   967,   969,   971,
     973,   975,   977,   979,   984,   990,   996,  1002,  1006,  1011,
    1013,  1016,  1020,  1023,  1025,  1028,  1031,  1033,  1035,  1037,
    1041,  1045,  1047,  1049,  1051,  1054,  1056,  1059,  1062,  1064,
    1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,  1083,  1086,
    1088,  1090,  1092,  1094,  1096,  1098,  1100,  1102,  1104,  1106,
    1108,  1110,  1112,  1114,  1117,  1119,  1122,  1126,  1128,  1130,
    1132,  1134,  1136,  1138,  1140,  1142,  1144,  1146,  1148,  1150,
    1152,  1155,  1158,  1162,  1164,  1169,  1174,  1178,  1183,  1185,
    1189,  1191,  1193,  1195,  1197,  1199,  1204,  1210,  1219,  1229,
    1239,  1250,  1252,  1255,  1257,  1260,  1267,  1268,  1270,  1274,
    1278,  1279,  1281,  1283,  1285,  1288,  1291,  1292,  1294,  1296,
    1298,  1301,  1304,  1306,  1308,  1310,  1312,  1314,  1316,  1318,
    1320,  1322,  1324,  1326,  1328,  1332,  1335,  1339,  1343,  1346,
    1348,  1350,  1352,  1354,  1356,  1358,  1363,  1368,  1374,  1381,
    1389,  1394,  1400,  1407,  1415,  1420,  1425,  1430,  1436,  1443,
    1451,  1453,  1456,  1459,  1461,  1464,  1468,  1470,  1472,  1474,
    1476,  1478,  1482,  1484,  1486,  1488,  1490,  1492,  1494,  1496,
    1498,  1500,  1502,  1506,  1510,  1515,  1520,  1524,  1528,  1532,
    1537,  1542,  1546,  1551,  1558,  1563,  1570,  1574,  1578,  1583,
    1590,  1597,  1602,  1609,  1616,  1621,  1623,  1626,  1628,  1632,
    1636,  1640,  1646,  1654,  1662,  1668,  1674,  1680,  1688,  1696,
    1702,  1708,  1712,  1716,  1722,  1730,  1736,  1744,  1746,  1751,
    1755,  1761,  1763,  1766,  1772,  1781,  1793,  1808,  1810,  1812,
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
    2094,  2096,  2098,  2100,  2102,  2104,  2106,  2108,  2110,  2112,
    2114,  2116,  2118,  2120,  2122,  2130,  2135,  2137,  2140,  2144,
    2149,  2151,  2153,  2156,  2159,  2161,  2165,  2167,  2171,  2173,
    2178,  2180,  2183,  2185,  2188,  2192,  2194,  2197,  2199,  2203,
    2205,  2207,  2209,  2211,  2213,  2215,  2217,  2219,  2221,  2223,
    2225,  2227,  2229,  2231,  2233,  2236,  2239,  2242,  2245,  2248,
    2251,  2254,  2257,  2261,  2265,  2271,  2279,  2285,  2293,  2296,
    2298,  2302,  2305,  2310,  2315,  2322,  2327,  2333,  2338,  2344,
    2348,  2350,  2353,  2356,  2360,  2362,  2365,  2368,  2371,  2374,
    2377,  2380,  2383,  2386,  2389,  2391,  2394,  2396,  2399,  2401,
    2404,  2408,  2412,  2417,  2421,  2425,  2429,  2432,  2435,  2437,
    2439,  2441,  2443,  2445
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   832,   832,   833,   843,   848,   854,   859,   871,   876,
     886,   893,   905,   917,   929,   935,   941,   953,   959,   973,
     979,   993,   994,   995,   996,  1002,  1003,  1004,  1007,  1014,
    1015,  1016,  1017,  1018,  1019,  1020,  1023,  1030,  1031,  1043,
    1055,  1060,  1071,  1077,  1089,  1102,  1113,  1118,  1130,  1135,
    1146,  1152,  1158,  1164,  1183,  1194,  1205,  1212,  1219,  1226,
    1239,  1245,  1260,  1264,  1274,  1280,  1287,  1293,  1304,  1308,
    1318,  1326,  1332,  1344,  1349,  1361,  1365,  1369,  1373,  1380,
    1387,  1393,  1402,  1409,  1416,  1423,  1427,  1434,  1442,  1451,
    1460,  1469,  1484,  1492,  1506,  1512,  1524,  1532,  1543,  1554,
    1560,  1572,  1573,  1574,  1575,  1576,  1579,  1580,  1581,  1582,
    1583,  1585,  1586,  1589,  1590,  1591,  1592,  1593,  1600,  1609,
    1616,  1620,  1628,  1632,  1636,  1643,  1647,  1654,  1659,  1668,
    1677,  1678,  1679,  1683,  1683,  1683,  1683,  1683,  1686,  1692,
    1701,  1705,  1715,  1726,  1732,  1746,  1753,  1761,  1770,  1780,
    1788,  1797,  1806,  1821,  1833,  1844,  1856,  1862,  1874,  1880,
    1894,  1902,  1911,  1919,  1931,  1937,  1947,  1948,  1952,  1960,
    1964,  1969,  1973,  1977,  1981,  1988,  2003,  2011,  2021,  2027,
    2038,  2044,  2053,  2063,  2068,  2080,  2086,  2100,  2106,  2118,
    2125,  2132,  2139,  2146,  2153,  2160,  2173,  2177,  2187,  2192,
    2203,  2214,  2221,  2234,  2241,  2253,  2259,  2272,  2279,  2293,
    2299,  2311,  2317,  2330,  2341,  2345,  2356,  2360,  2379,  2383,
    2391,  2399,  2407,  2415,  2415,  2423,  2431,  2439,  2453,  2457,
    2464,  2477,  2481,  2492,  2496,  2500,  2510,  2514,  2518,  2522,
    2526,  2536,  2540,  2545,  2556,  2560,  2564,  2574,  2578,  2590,
    2594,  2606,  2610,  2622,  2626,  2638,  2642,  2654,  2658,  2662,
    2666,  2678,  2682,  2686,  2696,  2700,  2704,  2708,  2712,  2716,
    2726,  2730,  2734,  2744,  2748,  2754,  2760,  2772,  2778,  2790,
    2796,  2810,  2817,  2858,  2862,  2866,  2870,  2882,  2892,  2903,
    2908,  2918,  2922,  2932,  2938,  2944,  2950,  2962,  2968,  2979,
    2983,  2987,  2991,  2995,  2999,  3003,  3013,  3017,  3027,  3033,
    3045,  3049,  3053,  3057,  3061,  3076,  3080,  3090,  3094,  3104,
    3111,  3118,  3131,  3135,  3147,  3153,  3167,  3178,  3182,  3186,
    3190,  3194,  3198,  3202,  3206,  3216,  3220,  3230,  3235,  3240,
    3251,  3261,  3265,  3276,  3286,  3297,  3353,  3359,  3371,  3377,
    3389,  3393,  3403,  3407,  3411,  3421,  3429,  3437,  3445,  3453,
    3461,  3476,  3482,  3494,  3500,  3513,  3522,  3524,  3530,  3535,
    3547,  3550,  3557,  3563,  3569,  3577,  3592,  3595,  3602,  3608,
    3614,  3622,  3636,  3641,  3652,  3657,  3668,  3673,  3678,  3684,
    3696,  3702,  3707,  3712,  3723,  3728,  3743,  3748,  3765,  3780,
    3784,  3788,  3792,  3796,  3800,  3810,  3821,  3827,  3833,  3838,
    3860,  3866,  3872,  3877,  3888,  3899,  3910,  3916,  3922,  3927,
    3938,  3944,  3956,  3968,  3974,  3980,  4017,  4022,  4027,  4038,
    4042,  4046,  4056,  4067,  4071,  4075,  4079,  4083,  4087,  4091,
    4095,  4099,  4109,  4119,  4123,  4128,  4139,  4149,  4159,  4163,
    4167,  4177,  4183,  4189,  4195,  4201,  4213,  4224,  4231,  4238,
    4245,  4252,  4259,  4266,  4279,  4300,  4307,  4327,  4367,  4372,
    4375,  4383,  4389,  4395,  4401,  4407,  4414,  4420,  4426,  4432,
    4438,  4450,  4455,  4465,  4471,  4483,  4509,  4520,  4526,  4539,
    4553,  4560,  4567,  4578,  4585,  4593,  4602,  4615,  4618,  4636,
    4637,  4638,  4639,  4640,  4641,  4642,  4643,  4644,  4645,  4646,
    4647,  4648,  4649,  4650,  4651,  4652,  4653,  4654,  4655,  4656,
    4657,  4658,  4659,  4660,  4661,  4662,  4663,  4664,  4665,  4666,
    4667,  4668,  4669,  4670,  4671,  4672,  4673,  4674,  4675,  4676,
    4677,  4678,  4679,  4680,  4681,  4682,  4683,  4684,  4685,  4686,
    4687,  4688,  4689,  4690,  4691,  4692,  4693,  4694,  4695,  4696,
    4697,  4698,  4699,  4700,  4701,  4702,  4703,  4704,  4705,  4706,
    4707,  4708,  4709,  4710,  4711,  4712,  4713,  4714,  4715,  4716,
    4717,  4718,  4719,  4720,  4721,  4722,  4723,  4724,  4725,  4726,
    4727,  4728,  4729,  4730,  4731,  4732,  4733,  4734,  4735,  4736,
    4737,  4738,  4739,  4740,  4741,  4742,  4743,  4744,  4745,  4746,
    4747,  4748,  4749,  4750,  4751,  4752,  4753,  4754,  4755,  4756,
    4757,  4758,  4759,  4760,  4761,  4762,  4763,  4764,  4765,  4766,
    4767,  4768,  4769,  4770,  4771,  4772,  4773,  4774,  4775,  4776,
    4777,  4778,  4779,  4780,  4781,  4782,  4783,  4784,  4785,  4786,
    4787,  4788,  4789,  4790,  4801,  4807,  4824,  4828,  4832,  4836,
    4846,  4849,  4852,  4855,  4864,  4867,  4876,  4879,  4888,  4891,
    4900,  4903,  4912,  4915,  4918,  4927,  4930,  4939,  4943,  4953,
    4956,  4959,  4962,  4965,  4974,  4983,  4987,  4991,  4995,  4999,
    5003,  5007,  5017,  5020,  5023,  5026,  5035,  5038,  5041,  5044,
    5053,  5056,  5065,  5068,  5071,  5074,  5077,  5080,  5083,  5092,
    5095,  5104,  5107,  5110,  5113,  5122,  5125,  5128,  5131,  5134,
    5143,  5146,  5155,  5158,  5167,  5170,  5179,  5182,  5191,  5200,
    5203,  5212,  5215,  5218,  5227,  5230,  5233,  5236,  5239,  5248,
    5252,  5256,  5260,  5270,  5279,  5289,  5298,  5301,  5310,  5313,
    5316,  5325,  5328,  5337
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
  const int xquery_parser::yynnts_ = 234;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 437;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 274;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 528;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5345 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"


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

