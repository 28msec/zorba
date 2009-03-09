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
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								nt->name,
								nt->type,
								NULL);
		;}
    break;

  case 72:
#line 1341 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 73:
#line 1346 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 74:
#line 1358 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 75:
#line 1362 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 76:
#line 1366 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 77:
#line 1370 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 78:
#line 1377 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    ;}
    break;

  case 79:
#line 1384 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = new BlockBody (LOC ((yyloc)));
      blk->add ((yysemantic_stack_[(2) - (1)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 80:
#line 1390 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 81:
#line 1399 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), driver.symtab.get ((off_t)(yysemantic_stack_[(5) - (3)].sval)), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 82:
#line 1406 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 83:
#line 1413 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr)));
    ;}
    break;

  case 84:
#line 1420 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 85:
#line 1424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 86:
#line 1431 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval))),
                &* (yysemantic_stack_[(5) - (4)].fnsig)->param, &* (yysemantic_stack_[(5) - (4)].fnsig)->ret, NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
		;}
    break;

  case 87:
#line 1439 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1448 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1457 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1466 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1481 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 92:
#line 1489 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 93:
#line 1503 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 94:
#line 1509 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 95:
#line 1521 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 96:
#line 1529 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 97:
#line 1540 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 98:
#line 1551 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = new Expr(LOC ((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 99:
#line 1557 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 117:
#line 1597 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 118:
#line 1606 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 119:
#line 1613 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    ;}
    break;

  case 120:
#line 1617 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    ;}
    break;

  case 121:
#line 1625 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    ;}
    break;

  case 122:
#line 1629 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    ;}
    break;

  case 123:
#line 1633 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    ;}
    break;

  case 124:
#line 1640 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 125:
#line 1644 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 126:
#line 1651 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)), dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 127:
#line 1656 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    ;}
    break;

  case 128:
#line 1665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 137:
#line 1683 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 138:
#line 1689 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 139:
#line 1698 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    ;}
    break;

  case 140:
#line 1702 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    ;}
    break;

  case 141:
#line 1712 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		;}
    break;

  case 142:
#line 1723 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 143:
#line 1729 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 144:
#line 1743 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 145:
#line 1750 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 146:
#line 1758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1767 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1777 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 149:
#line 1785 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1794 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1803 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1818 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 153:
#line 1830 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 154:
#line 1841 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 155:
#line 1853 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 156:
#line 1859 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 157:
#line 1871 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 158:
#line 1877 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 159:
#line 1891 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 160:
#line 1899 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 161:
#line 1908 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 162:
#line 1916 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 163:
#line 1928 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 164:
#line 1934 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 166:
#line 1945 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)), "", "");
    ;}
    break;

  case 167:
#line 1949 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
    ;}
    break;

  case 168:
#line 1957 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    ;}
    break;

  case 169:
#line 1961 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    ;}
    break;

  case 171:
#line 1970 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)));
    ;}
    break;

  case 172:
#line 1974 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 173:
#line 1978 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)), "");
    ;}
    break;

  case 174:
#line 1985 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 175:
#line 2000 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 176:
#line 2008 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 177:
#line 2018 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 178:
#line 2024 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 179:
#line 2035 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 180:
#line 2041 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 181:
#line 2050 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 182:
#line 2060 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 183:
#line 2065 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 184:
#line 2077 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 185:
#line 2083 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 186:
#line 2097 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 187:
#line 2103 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 188:
#line 2115 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 189:
#line 2122 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 190:
#line 2129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 191:
#line 2136 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 192:
#line 2143 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 193:
#line 2150 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 194:
#line 2157 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 195:
#line 2170 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 196:
#line 2174 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 197:
#line 2184 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 198:
#line 2189 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 199:
#line 2200 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 200:
#line 2211 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 201:
#line 2218 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 202:
#line 2231 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 203:
#line 2238 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 204:
#line 2250 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 205:
#line 2256 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 206:
#line 2269 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 207:
#line 2276 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 208:
#line 2290 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 209:
#line 2296 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 210:
#line 2308 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 211:
#line 2314 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 212:
#line 2327 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 213:
#line 2338 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 214:
#line 2342 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 215:
#line 2353 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 216:
#line 2357 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 217:
#line 2376 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 218:
#line 2380 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 219:
#line 2388 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 220:
#line 2396 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 221:
#line 2404 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 222:
#line 2411 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 223:
#line 2412 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 224:
#line 2420 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 225:
#line 2428 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 226:
#line 2436 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 227:
#line 2450 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 228:
#line 2454 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 229:
#line 2461 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 230:
#line 2474 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 231:
#line 2478 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 232:
#line 2489 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 233:
#line 2493 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 234:
#line 2497 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 235:
#line 2507 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 236:
#line 2511 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 237:
#line 2515 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 238:
#line 2519 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 239:
#line 2523 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 240:
#line 2533 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 241:
#line 2537 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 242:
#line 2542 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 243:
#line 2553 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 244:
#line 2557 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 245:
#line 2561 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 246:
#line 2571 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 247:
#line 2575 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 248:
#line 2587 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 249:
#line 2591 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 250:
#line 2603 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 251:
#line 2607 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 252:
#line 2619 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 253:
#line 2623 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 254:
#line 2635 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 255:
#line 2639 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 256:
#line 2651 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 257:
#line 2655 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 258:
#line 2659 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 259:
#line 2663 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 260:
#line 2675 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
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
#line 2693 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 264:
#line 2697 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 265:
#line 2701 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 266:
#line 2705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 267:
#line 2709 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 268:
#line 2713 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 269:
#line 2723 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 270:
#line 2727 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 271:
#line 2731 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 272:
#line 2741 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 273:
#line 2745 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "strict",
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 274:
#line 2751 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "lax",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 275:
#line 2757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "skip",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 276:
#line 2769 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 277:
#line 2775 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 278:
#line 2787 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 279:
#line 2793 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 280:
#line 2807 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 281:
#line 2813 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 282:
#line 2855 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 283:
#line 2859 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 284:
#line 2863 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 285:
#line 2867 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 286:
#line 2879 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    ;}
    break;

  case 287:
#line 2889 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2900 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 289:
#line 2905 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 290:
#line 2915 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 291:
#line 2919 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 292:
#line 2929 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 293:
#line 2935 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 294:
#line 2941 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 295:
#line 2947 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 296:
#line 2959 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 297:
#line 2965 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 298:
#line 2976 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 299:
#line 2980 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 300:
#line 2984 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 301:
#line 2988 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 302:
#line 2992 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 303:
#line 2996 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 304:
#line 3000 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 305:
#line 3010 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 306:
#line 3014 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 307:
#line 3024 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 308:
#line 3030 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 309:
#line 3042 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 310:
#line 3046 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 311:
#line 3050 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 312:
#line 3054 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 313:
#line 3058 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 314:
#line 3073 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 315:
#line 3077 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 316:
#line 3087 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 317:
#line 3091 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 318:
#line 3101 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 319:
#line 3108 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 320:
#line 3115 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 321:
#line 3128 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 322:
#line 3132 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 323:
#line 3144 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 324:
#line 3150 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 325:
#line 3164 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 326:
#line 3175 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
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
#line 3213 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3227 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 337:
#line 3232 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 338:
#line 3237 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 339:
#line 3248 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 340:
#line 3258 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 341:
#line 3262 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 342:
#line 3273 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 343:
#line 3283 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 344:
#line 3294 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 345:
#line 3350 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 346:
#line 3356 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 347:
#line 3368 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 348:
#line 3374 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 349:
#line 3386 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 3390 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 3400 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3418 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 355:
#line 3426 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 356:
#line 3434 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 357:
#line 3442 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 358:
#line 3450 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 359:
#line 3458 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 360:
#line 3473 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 361:
#line 3479 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 362:
#line 3491 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 363:
#line 3497 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 364:
#line 3510 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 367:
#line 3527 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 368:
#line 3532 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 369:
#line 3543 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 370:
#line 3547 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 371:
#line 3554 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 372:
#line 3560 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 373:
#line 3566 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 374:
#line 3574 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 375:
#line 3588 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 376:
#line 3592 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 377:
#line 3599 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 378:
#line 3605 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 379:
#line 3611 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 380:
#line 3619 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 381:
#line 3633 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 382:
#line 3638 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 383:
#line 3649 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 384:
#line 3654 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 385:
#line 3665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 386:
#line 3670 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 387:
#line 3675 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 388:
#line 3681 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 389:
#line 3693 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 390:
#line 3699 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 391:
#line 3704 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 392:
#line 3709 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 393:
#line 3720 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 394:
#line 3725 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 395:
#line 3740 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 396:
#line 3745 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 397:
#line 3762 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 398:
#line 3777 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
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
#line 3807 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 405:
#line 3818 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 406:
#line 3824 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 407:
#line 3830 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 408:
#line 3835 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 409:
#line 3857 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 410:
#line 3863 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 411:
#line 3869 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 412:
#line 3874 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 413:
#line 3885 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 414:
#line 3896 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 415:
#line 3907 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 416:
#line 3913 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 417:
#line 3919 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 418:
#line 3924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 419:
#line 3935 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 420:
#line 3941 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 421:
#line 3953 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 422:
#line 3965 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 423:
#line 3971 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 424:
#line 3977 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 425:
#line 4014 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 426:
#line 4019 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 427:
#line 4024 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 428:
#line 4035 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
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
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 431:
#line 4053 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 432:
#line 4064 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
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
#line 4106 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 442:
#line 4116 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 443:
#line 4120 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 444:
#line 4125 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 445:
#line 4136 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 446:
#line 4146 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 447:
#line 4156 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 448:
#line 4160 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 449:
#line 4164 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 450:
#line 4174 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 451:
#line 4180 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 452:
#line 4186 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 453:
#line 4192 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 454:
#line 4198 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 455:
#line 4210 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 456:
#line 4221 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		;}
    break;

  case 457:
#line 4228 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
                           NULL,
                           true);
		;}
    break;

  case 458:
#line 4235 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		;}
    break;

  case 459:
#line 4242 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		;}
    break;

  case 460:
#line 4249 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 461:
#line 4256 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		;}
    break;

  case 462:
#line 4263 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 463:
#line 4276 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 464:
#line 4297 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 465:
#line 4304 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 466:
#line 4324 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 467:
#line 4364 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 468:
#line 4369 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 469:
#line 4372 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 470:
#line 4380 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 471:
#line 4386 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 472:
#line 4392 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 473:
#line 4398 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 474:
#line 4404 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 475:
#line 4411 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 476:
#line 4417 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 477:
#line 4423 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 478:
#line 4429 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 479:
#line 4435 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 480:
#line 4447 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 481:
#line 4452 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 482:
#line 4462 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 483:
#line 4468 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 484:
#line 4480 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 485:
#line 4506 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 486:
#line 4517 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 487:
#line 4523 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 488:
#line 4536 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 489:
#line 4550 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 490:
#line 4557 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 491:
#line 4564 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 492:
#line 4575 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 493:
#line 4582 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 494:
#line 4590 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 495:
#line 4599 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4615 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4632 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 499:
#line 4633 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty"); ;}
    break;

  case 500:
#line 4634 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("attribute"); ;}
    break;

  case 501:
#line 4635 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("comment"); ;}
    break;

  case 502:
#line 4636 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document-node"); ;}
    break;

  case 503:
#line 4637 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("element"); ;}
    break;

  case 504:
#line 4638 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("item"); ;}
    break;

  case 505:
#line 4639 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("if"); ;}
    break;

  case 506:
#line 4640 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("node"); ;}
    break;

  case 507:
#line 4641 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("processing-instruction"); ;}
    break;

  case 508:
#line 4642 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-attribute"); ;}
    break;

  case 509:
#line 4643 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-element"); ;}
    break;

  case 510:
#line 4644 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("text"); ;}
    break;

  case 511:
#line 4645 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("typeswitch"); ;}
    break;

  case 512:
#line 4646 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty-sequence"); ;}
    break;

  case 513:
#line 4647 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("boundary-space"); ;}
    break;

  case 514:
#line 4648 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ft-option"); ;}
    break;

  case 515:
#line 4649 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("base-uri"); ;}
    break;

  case 516:
#line 4650 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lax"); ;}
    break;

  case 517:
#line 4651 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strict"); ;}
    break;

  case 518:
#line 4652 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("idiv"); ;}
    break;

  case 519:
#line 4653 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document"); ;}
    break;

  case 520:
#line 4654 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("not"); ;}
    break;

  case 521:
#line 4655 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sensitive"); ;}
    break;

  case 522:
#line 4656 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insensitive"); ;}
    break;

  case 523:
#line 4657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("diacritics"); ;}
    break;

  case 524:
#line 4658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("without"); ;}
    break;

  case 525:
#line 4659 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stemming"); ;}
    break;

  case 526:
#line 4660 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("thesaurus"); ;}
    break;

  case 527:
#line 4661 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stop"); ;}
    break;

  case 528:
#line 4662 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("wildcards"); ;}
    break;

  case 529:
#line 4663 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("entire"); ;}
    break;

  case 530:
#line 4664 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("content"); ;}
    break;

  case 531:
#line 4665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("word"); ;}
    break;

  case 532:
#line 4666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("start"); ;}
    break;

  case 533:
#line 4667 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("end"); ;}
    break;

  case 534:
#line 4668 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("most"); ;}
    break;

  case 535:
#line 4669 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("skip"); ;}
    break;

  case 536:
#line 4670 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy"); ;}
    break;

  case 537:
#line 4671 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("value"); ;}
    break;

  case 538:
#line 4672 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("eq"); ;}
    break;

  case 539:
#line 4673 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ne"); ;}
    break;

  case 540:
#line 4674 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lt"); ;}
    break;

  case 541:
#line 4675 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("le"); ;}
    break;

  case 542:
#line 4676 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("gt"); ;}
    break;

  case 543:
#line 4677 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ge"); ;}
    break;

  case 544:
#line 4678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("at"); ;}
    break;

  case 545:
#line 4679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("variable"); ;}
    break;

  case 546:
#line 4680 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("return"); ;}
    break;

  case 547:
#line 4681 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("for"); ;}
    break;

  case 548:
#line 4682 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("outer"); ;}
    break;

  case 549:
#line 4683 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sliding"); ;}
    break;

  case 550:
#line 4684 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("tumbling"); ;}
    break;

  case 551:
#line 4685 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("previous"); ;}
    break;

  case 552:
#line 4686 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("next"); ;}
    break;

  case 553:
#line 4687 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("only"); ;}
    break;

  case 554:
#line 4688 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("when"); ;}
    break;

  case 555:
#line 4689 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("count"); ;}
    break;

  case 556:
#line 4690 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("in"); ;}
    break;

  case 557:
#line 4691 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("let"); ;}
    break;

  case 558:
#line 4692 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("where"); ;}
    break;

  case 559:
#line 4693 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("by"); ;}
    break;

  case 560:
#line 4694 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("group"); ;}
    break;

  case 561:
#line 4695 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("order"); ;}
    break;

  case 562:
#line 4696 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stable"); ;}
    break;

  case 563:
#line 4697 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ascending"); ;}
    break;

  case 564:
#line 4698 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("descending"); ;}
    break;

  case 565:
#line 4699 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("greatest"); ;}
    break;

  case 566:
#line 4700 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("least"); ;}
    break;

  case 567:
#line 4701 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("collation"); ;}
    break;

  case 568:
#line 4702 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("some"); ;}
    break;

  case 569:
#line 4703 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("every"); ;}
    break;

  case 570:
#line 4704 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("satisfies"); ;}
    break;

  case 571:
#line 4705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("case"); ;}
    break;

  case 572:
#line 4706 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("as"); ;}
    break;

  case 573:
#line 4707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("then"); ;}
    break;

  case 574:
#line 4708 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("else"); ;}
    break;

  case 575:
#line 4709 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("or"); ;}
    break;

  case 576:
#line 4710 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("and"); ;}
    break;

  case 577:
#line 4711 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("instance"); ;}
    break;

  case 578:
#line 4712 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("of"); ;}
    break;

  case 579:
#line 4713 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("castable"); ;}
    break;

  case 580:
#line 4714 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("to"); ;}
    break;

  case 581:
#line 4715 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("div"); ;}
    break;

  case 582:
#line 4716 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("mod"); ;}
    break;

  case 583:
#line 4717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("union"); ;}
    break;

  case 584:
#line 4718 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("intersect"); ;}
    break;

  case 585:
#line 4719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("except"); ;}
    break;

  case 586:
#line 4720 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("validate"); ;}
    break;

  case 587:
#line 4721 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cast"); ;}
    break;

  case 588:
#line 4722 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("treat"); ;}
    break;

  case 589:
#line 4723 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("is"); ;}
    break;

  case 590:
#line 4724 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("preserve"); ;}
    break;

  case 591:
#line 4725 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strip"); ;}
    break;

  case 592:
#line 4726 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("namespace"); ;}
    break;

  case 593:
#line 4727 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("external"); ;}
    break;

  case 594:
#line 4728 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("encoding"); ;}
    break;

  case 595:
#line 4729 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-preserve"); ;}
    break;

  case 596:
#line 4730 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("inherit"); ;}
    break;

  case 597:
#line 4731 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-inherit"); ;}
    break;

  case 598:
#line 4732 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("declare"); ;}
    break;

  case 599:
#line 4733 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("construction"); ;}
    break;

  case 600:
#line 4734 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordering"); ;}
    break;

  case 601:
#line 4735 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("default"); ;}
    break;

  case 602:
#line 4736 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy-namespaces"); ;}
    break;

  case 603:
#line 4737 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("option"); ;}
    break;

  case 604:
#line 4738 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("version"); ;}
    break;

  case 605:
#line 4739 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("import"); ;}
    break;

  case 606:
#line 4740 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema"); ;}
    break;

  case 607:
#line 4741 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("module"); ;}
    break;

  case 608:
#line 4742 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("function"); ;}
    break;

  case 609:
#line 4743 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("score"); ;}
    break;

  case 610:
#line 4744 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ftcontains"); ;}
    break;

  case 611:
#line 4745 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("weight"); ;}
    break;

  case 612:
#line 4746 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("window"); ;}
    break;

  case 613:
#line 4747 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("distance"); ;}
    break;

  case 614:
#line 4748 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("occurs"); ;}
    break;

  case 615:
#line 4749 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("times"); ;}
    break;

  case 616:
#line 4750 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("same"); ;}
    break;

  case 617:
#line 4751 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("different"); ;}
    break;

  case 618:
#line 4752 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lowercase"); ;}
    break;

  case 619:
#line 4753 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("uppercase"); ;}
    break;

  case 620:
#line 4754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("relationship"); ;}
    break;

  case 621:
#line 4755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("levels"); ;}
    break;

  case 622:
#line 4756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("language"); ;}
    break;

  case 623:
#line 4757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("any"); ;}
    break;

  case 624:
#line 4758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("all"); ;}
    break;

  case 625:
#line 4759 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("phrase"); ;}
    break;

  case 626:
#line 4760 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exactly"); ;}
    break;

  case 627:
#line 4761 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("from"); ;}
    break;

  case 628:
#line 4762 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("words"); ;}
    break;

  case 629:
#line 4763 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentences"); ;}
    break;

  case 630:
#line 4764 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentence"); ;}
    break;

  case 631:
#line 4765 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("paragraph"); ;}
    break;

  case 632:
#line 4766 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("replace"); ;}
    break;

  case 633:
#line 4767 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("modify"); ;}
    break;

  case 634:
#line 4768 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("first"); ;}
    break;

  case 635:
#line 4769 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insert"); ;}
    break;

  case 636:
#line 4770 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("bofer"); ;}
    break;

  case 637:
#line 4771 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("after"); ;}
    break;

  case 638:
#line 4772 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("revalidation"); ;}
    break;

  case 639:
#line 4773 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("with"); ;}
    break;

  case 640:
#line 4774 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("nodes"); ;}
    break;

  case 641:
#line 4775 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("rename"); ;}
    break;

  case 642:
#line 4776 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("last"); ;}
    break;

  case 643:
#line 4777 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("delete"); ;}
    break;

  case 644:
#line 4778 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("into"); ;}
    break;

  case 645:
#line 4779 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("updating"); ;}
    break;

  case 646:
#line 4780 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordered"); ;}
    break;

  case 647:
#line 4781 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("unordered"); ;}
    break;

  case 648:
#line 4782 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exit"); ;}
    break;

  case 649:
#line 4783 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("loop"); ;}
    break;

  case 650:
#line 4784 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("break"); ;}
    break;

  case 651:
#line 4785 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cont"); ;}
    break;

  case 652:
#line 4786 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("set"); ;}
    break;

  case 653:
#line 4798 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 654:
#line 4804 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 655:
#line 4821 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 656:
#line 4825 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 657:
#line 4829 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 658:
#line 4833 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 659:
#line 4843 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 660:
#line 4846 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 661:
#line 4849 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 662:
#line 4852 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 663:
#line 4861 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 664:
#line 4864 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 665:
#line 4873 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 666:
#line 4876 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 667:
#line 4885 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 668:
#line 4888 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 669:
#line 4897 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 670:
#line 4900 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 671:
#line 4909 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 672:
#line 4912 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 673:
#line 4915 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 674:
#line 4924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 675:
#line 4927 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 676:
#line 4936 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 677:
#line 4940 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, static_cast<Expr *> ((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 678:
#line 4950 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 679:
#line 4953 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 680:
#line 4956 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 681:
#line 4959 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 682:
#line 4962 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 683:
#line 4971 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 684:
#line 4980 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
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
#line 5014 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 692:
#line 5017 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 693:
#line 5020 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 694:
#line 5023 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 695:
#line 5032 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 696:
#line 5035 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 697:
#line 5038 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 698:
#line 5041 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 699:
#line 5050 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 700:
#line 5053 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 701:
#line 5062 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 702:
#line 5065 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 703:
#line 5068 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 704:
#line 5071 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 705:
#line 5074 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 706:
#line 5077 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 707:
#line 5080 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 708:
#line 5089 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 709:
#line 5092 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 710:
#line 5101 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 711:
#line 5104 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 712:
#line 5107 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 713:
#line 5110 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 714:
#line 5119 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 715:
#line 5122 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 716:
#line 5125 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 717:
#line 5128 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 718:
#line 5131 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 719:
#line 5140 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 720:
#line 5143 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 721:
#line 5152 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 722:
#line 5155 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 723:
#line 5164 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 724:
#line 5167 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 725:
#line 5176 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 726:
#line 5179 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 727:
#line 5188 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 728:
#line 5197 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 729:
#line 5200 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 730:
#line 5209 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 731:
#line 5212 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 732:
#line 5215 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 733:
#line 5224 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 734:
#line 5227 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 735:
#line 5230 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 736:
#line 5233 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 737:
#line 5236 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 738:
#line 5245 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 739:
#line 5249 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 740:
#line 5253 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 741:
#line 5257 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 742:
#line 5267 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 743:
#line 5276 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 744:
#line 5286 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 745:
#line 5295 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 746:
#line 5298 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 747:
#line 5307 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 748:
#line 5310 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 749:
#line 5313 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 750:
#line 5322 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 751:
#line 5325 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 752:
#line 5334 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6523 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
      1249,  -942,  -942,  -942,  -942,   -87,   218,  -942,   134,   224,
     145,  6216,   190,   442,   492,    28,  -942,  -942,   223,    46,
    -942,   427,   250,  -942,   290,  -942,  -942,  -942,   333,   421,
    -942,   343,   426,   520,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,   556,  -942,   450,   472,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  6457,  -942,  5483,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  7662,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
     489,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  4238,  1499,  7662,  -942,  -942,  -942,  -942,  -942,
    -942,   496,  -942,  -942,  -942,  -942,   624,  -942,  5975,  -942,
    -942,  -942,  -942,  -942,  7662,  -942,  -942,  5234,  -942,  -942,
    -942,  -942,  -942,  -942,   516,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,    19,   458,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,   410,   536,   414,  -942,   475,   383,  -942,
    -942,  -942,  -942,  -942,  -942,   576,  -942,   548,   581,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  1748,   688,  -942,  4487,  -942,
    -942,    90,  4238,   521,   522,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
     599,  -942,  -942,  -942,  -942,   263,  7662,  -942,  -942,  -942,
    -942,  -942,   546,   618,  -942,   612,   461,   -29,   229,   393,
     161,  -942,   630,   523,   619,   620,  4736,  -942,  -942,  -942,
     144,  -942,  -942,  5234,  -942,   431,  -942,   575,  5483,  -942,
     575,  5483,  -942,  -942,  -942,  -942,   575,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,   578,  -942,  4238,  -942,  4238,
    4238,   579,   584,   586,  4238,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  4238,  6698,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,   593,  4238,
    4238,   545,  4238,   561,  7662,   690,   691,  7662,   153,   -46,
     710,   394,   359,   634,   270,   713,   454,   -48,  4238,  -942,
    4238,    51,   604,    43,    60,  7662,   713,  7662,  7662,  4238,
     487,   488,  -942,   637,   640,  -942,  7662,    74,  4238,  6939,
     609,   608,   610,   614,   615,   616,  -942,  -942,  -942,  7662,
    1997,    -5,  -942,    47,   720,  4238,    37,  -942,   733,   587,
    -942,  4238,   562,  -942,   736,  4238,  4238,   591,  4238,  4238,
    4238,  4238,   547,  7662,  4238,  7662,  -942,  -942,  -942,  -942,
      28,   427,  -942,  -942,    90,   722,  4238,   611,   421,   426,
     520,   660,   613,   617,  4238,  4238,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,   671,  -942,   -28,  4985,  4985,  4985,  -942,
    4985,  4985,  -942,  4985,  -942,  4985,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  4985,  4985,    12,  4985,  4985,  4985,  4985,
    4985,  4985,  4985,  4985,  4985,  4985,  4985,   554,   686,   693,
     695,  -942,  -942,  -942,  2246,  -942,  -942,  5234,  5234,  4238,
     575,  -942,  -942,   575,  -942,   575,  2495,  -942,   602,   176,
    4238,  4238,  4238,    64,   199,  -942,   135,   165,  2744,   233,
     244,  -942,   253,  -942,   633,  7662,  7662,   746,  -942,  -942,
    -942,  -942,  -942,  -942,   683,   684,  -942,  -942,  7662,   471,
     639,   641,   710,   669,   667,  -942,  -942,  -942,   404,    25,
     428,   762,  -942,  -942,   352,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,   167,   319,   621,  -942,   622,  2993,   713,
     703,   752,   713,   710,   709,   -14,  -942,   175,   677,   668,
     702,  -942,   -19,   638,  -942,  -942,  7662,    -8,  -942,   636,
     608,   450,  -942,   645,   647,   320,  -942,   180,   181,  3242,
      14,  -942,     5,  -942,  -942,  7662,   720,  -942,   -39,   324,
    -942,  -942,  -942,  -942,   341,  -942,   -20,  -942,  -942,  -942,
      -3,    16,   725,   583,   623,   -21,  -942,   681,   642,    63,
    -942,  -942,   644,  -942,    17,  -942,  -942,   665,  7662,  4238,
     716,  -942,  -942,   717,  7421,   719,  4238,   721,   -84,   696,
      -7,   618,  -942,  -942,  -942,  -942,  -942,  4985,  -942,  -942,
    -942,  4238,    12,   216,  -942,   571,   470,   592,   589,  -942,
    -942,   594,   336,   229,   229,    -9,   393,   393,   393,   393,
     161,   161,  -942,  -942,  7421,  7421,  7662,  7662,  -942,   348,
    -942,  -942,    -6,  -942,  -942,  -942,   203,   697,  -942,   349,
     350,   351,   748,   701,  7662,  -942,  7662,  -942,  -942,   354,
    -942,  -942,  -942,   195,   347,   633,   633,  -942,   185,   316,
     758,  -942,  4238,   710,   710,  -942,   549,   710,  -942,  -942,
     582,  -942,  -942,   585,   423,  -942,  -942,  -942,  -942,  -942,
    -942,   588,  -942,  -942,   661,   706,  -942,  -942,  -942,   355,
     727,   710,   705,   729,   763,   710,   745,  4238,  4238,   723,
     710,  4238,   747,  4238,   728,   -86,  -942,   306,   625,  -942,
    -942,   486,    -8,  -942,  -942,  -942,   724,  7662,  -942,  7662,
    -942,  -942,   360,  4238,  -942,   827,  -942,   -24,  -942,    70,
    -942,  -942,   833,  -942,   430,  4238,  4238,  4238,   438,  4238,
    4238,  4238,  4238,  4238,  4238,   753,  4238,  4238,   643,   726,
     757,   722,  4238,  -942,   466,   769,  -942,  7662,   770,  -942,
    7662,   730,   731,  -942,   396,  -942,  -942,  -942,  7662,  -942,
    7662,  4238,   737,  4238,  4238,   -27,   738,  -942,   368,   707,
    -942,   632,  -942,   -50,  -942,   358,   -45,   646,    12,   358,
    4985,  4985,   395,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
      12,   741,   -45,  -942,   626,   820,  -942,  -942,  -942,  -942,
    -942,   749,  -942,  -942,  -942,  4238,  -942,  -942,  -942,  -942,
    -942,  7180,   448,  -942,  3491,   712,   715,   750,   718,   732,
    -942,  7662,   793,   206,  -942,  -942,  4238,  -942,   434,   697,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,   627,     8,   852,  -942,   392,  -942,  -942,  4238,  3740,
    -942,   710,   785,  -942,  -942,  -942,   710,   785,  7662,  -942,
    -942,  4238,   734,  -942,  7662,  -942,  4238,  4238,   756,  4238,
     759,  -942,   784,   786,  4238,  7662,   600,   826,  -942,  -942,
    -942,  3989,   735,  -942,   739,  -942,  -942,  -942,   778,  -942,
     162,  -942,  -942,   886,  -942,  -942,  4238,  7662,  -942,  -942,
     276,  -942,  -942,  -942,   740,   680,   682,  -942,  -942,  -942,
     687,   689,  -942,  -942,  -942,  -942,  -942,   679,  7662,   742,
    -942,   761,   643,  -942,  4238,  7662,   769,  -942,   710,  -942,
     553,  -942,    35,   804,  -942,  4238,   809,   716,  -942,   743,
     751,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  4238,  -942,
    -942,  4238,   779,  4238,  -942,  -942,  4985,  -942,  -942,  -942,
    -942,  -942,    41,  4985,  4985,  -120,  -942,   592,  -942,  -942,
      84,  4985,  -942,  -942,   589,    12,   659,  -942,  -942,  -942,
    -942,  7662,   754,     7,  -942,  -942,   372,  -942,  -942,  -942,
    -942,  -942,   758,  7421,   810,   834,   375,  -942,  -942,  -942,
     284,   893,   894,   284,    10,   207,   215,   808,  -942,   376,
     836,   710,   785,  -942,  -942,  -942,  -942,  -942,  -942,  4238,
    -942,  4238,  7662,  7662,  -942,   377,  -942,  4238,  -942,   378,
    -942,  -942,   827,  7662,   356,  -942,   379,   827,  7662,  -942,
    -942,  4238,  4238,  4238,  4238,  4238,  -942,  4238,  5732,  -942,
     755,  -942,  -942,  -942,  -942,   804,  -942,  -942,  -942,   710,
    -942,  -942,  -942,  -942,  -942,  -942,  4238,  -942,   393,  4985,
    4985,   393,   403,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,   842,  4238,  7662,  4238,  -942,  -942,  -942,  -942,  7421,
    -942,     8,     8,   284,  -942,  -942,  -942,    38,   284,   901,
     685,   843,  -942,   843,  -942,  4238,  -942,   710,  -942,  -942,
    -942,   861,  -942,  -942,  -942,  -942,     4,   827,  7662,  -942,
     760,   827,  -942,  -942,  -942,  -942,  -942,  -942,   220,  -942,
    -942,  -942,  -942,   393,   393,  4985,  7421,  -942,   764,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,   -45,  -942,   221,  -942,
     226,  -942,   785,   824,   155,   159,  -942,   765,   827,  -942,
     766,   825,   795,   393,   767,  4238,   692,   843,  -942,  -942,
    7662,  -942,  -942,   857,   367,  -942,  -942,  -942,  -942,   773,
     285,  -942,  -942,  -942,   771,  -942,  7662,  -942,  4238,  -942,
    -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
     227,  -942,   837,   795,  7662,  -942,   231,   838,   795,  7662,
    -942,   774,   795,  -942
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
       0,     0,     0,     0,     0,   467,   468,   469,     0,     0,
       0,     0,   691,   692,     0,    45,   684,   685,   686,   687,
     688,   689,   690,     0,     0,     0,   447,     0,     0,     0,
      64,     0,     0,     0,    56,     0,   202,     0,     0,     0,
     154,   155,     0,     0,   119,   120,     0,     0,   140,     0,
       0,     0,   442,     0,     0,     0,   450,     0,     0,     0,
       0,    78,     0,    79,   341,   366,   365,   362,     0,     0,
     396,   395,   280,   455,     0,   393,     0,   480,   481,   441,
       0,     0,     0,     0,     0,     0,   486,     0,     0,     0,
     157,   174,     0,    18,     0,    20,    99,     0,     0,     0,
       0,   118,   175,     0,     0,     0,     0,     0,     0,     0,
       0,   214,   216,   220,   226,   225,   224,     0,   221,   218,
     219,     0,     0,     0,   676,   228,   655,   663,   665,   667,
     669,   671,   674,   234,   233,   231,   237,   238,   239,   236,
     241,   242,   245,   244,     0,     0,     0,     0,   276,     0,
     288,   289,     0,   324,   345,   347,     0,     0,   272,     0,
       0,     0,     0,     0,     0,   460,     0,   457,   405,     0,
     404,   413,   414,     0,     0,     0,     0,    44,     0,     0,
      68,    71,     0,     0,     0,    54,     0,     0,   693,   694,
       0,   695,   699,     0,     0,   728,   697,   698,   727,   696,
     700,     0,   707,   729,     0,     0,   449,   448,   415,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   654,     0,     0,   121,
     122,     0,   127,   463,   443,   444,     0,     0,   453,     0,
     451,   409,     0,     0,    80,   365,   363,     0,   354,     0,
     343,   344,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,   128,   186,   182,   184,     0,   176,   177,
       0,   504,   512,   421,   422,   428,   429,   431,     0,   144,
       0,     0,     0,     0,     0,     0,     0,   223,     0,     0,
     670,     0,   229,     0,   683,     0,     0,     0,     0,     0,
       0,     0,   656,   660,   678,   659,   682,   680,   679,   681,
       0,     0,     0,   672,   735,   733,   737,   675,   247,   249,
     251,   419,   253,   277,   325,     0,   346,    83,   273,   274,
     275,     0,     0,   208,     0,     0,     0,   464,     0,     0,
     406,     0,    74,     0,    91,    86,     0,    87,     0,     0,
      52,    53,    50,    51,    69,    70,    42,    43,    48,    49,
      39,     0,     0,     0,   702,     0,   701,   718,     0,     0,
     416,     0,    66,    60,    63,    62,     0,    58,     0,   200,
     204,     0,     0,    81,     0,   159,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,   168,     0,   165,   170,
     126,     0,     0,   464,     0,   410,   201,   366,     0,   355,
       0,   389,   386,     0,   390,   391,     0,     0,   392,   385,
       0,   360,   388,   387,     0,     0,     0,   473,   474,   470,
       0,     0,   478,   479,   475,   484,   482,     0,     0,     0,
     488,     0,   489,   490,     0,     0,   183,   195,     0,   196,
       0,   187,   188,   189,   190,     0,   179,     0,   143,     0,
       0,   425,   427,   426,   423,   152,   153,   146,     0,   148,
     145,     0,     0,     0,   677,   673,     0,   730,   731,   751,
     750,   746,     0,     0,     0,     0,   732,   664,   745,   657,
       0,     0,   662,   661,   666,     0,     0,   736,   734,   420,
     348,     0,     0,     0,   209,   407,     0,   461,   462,   465,
     458,   459,    93,     0,     0,    75,     0,    88,    89,    90,
     716,     0,     0,   714,   710,     0,     0,     0,   417,     0,
      65,     0,    59,   203,   205,    13,   156,   161,   160,     0,
     163,     0,     0,     0,   125,   166,   169,     0,   411,     0,
     454,   452,   365,     0,     0,   397,     0,   365,     0,   361,
       9,     0,     0,     0,     0,     0,   487,     0,     0,   491,
       0,   158,   199,   197,   198,   191,   192,   193,   185,     0,
     180,   178,   430,   424,   150,   147,     0,   149,   752,     0,
       0,   738,     0,   749,   748,   747,   742,   743,   658,   668,
     744,     0,     0,     0,     0,   408,    94,    76,    92,     0,
      96,     0,     0,   717,   719,   721,   723,     0,   715,     0,
       0,     0,   705,     0,   703,     0,   418,     0,    61,   162,
     164,   173,   172,   167,   124,   412,     0,   365,     0,    95,
       0,   365,   471,   472,   476,   477,   483,   485,     0,   653,
     194,   181,   151,   740,   739,     0,     0,   210,     0,   206,
      77,   726,   725,   720,   724,   722,   711,   712,     0,   708,
       0,   212,    67,     0,   375,   369,   364,     0,   365,   356,
       0,     0,     0,   741,     0,     0,     0,     0,   706,   704,
       0,   383,   377,     0,   376,   378,   384,   381,   371,     0,
     370,   372,   382,   358,     0,   357,     0,   492,     0,   207,
     713,   709,   171,   368,   379,   380,   367,   373,   374,   359,
       0,   211,     0,     0,     0,   493,     0,     0,     0,     0,
     494,     0,     0,   495
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -942,  -942,   768,  -942,   772,   775,  -942,   744,  -942,   493,
     499,  -427,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,  -752,  -942,  -942,  -942,  -942,
    -942,   -61,  -676,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -128,  -942,  -884,   776,   -73,  -315,  -942,  -942,  -942,  -942,
     166,  -942,  -942,   714,  -942,  -942,  -942,  -942,  -942,   120,
    -436,  -569,  -942,  -942,  -942,    11,  -942,  -942,  -154,    -4,
     -51,  -942,  -942,  -942,   -60,  -942,  -942,   136,   -59,  -942,
    -942,   -53,  -880,  -942,   551,    23,  -942,  -942,    72,  -942,
    -942,   501,   495,  -942,  -422,  -830,   477,   182,  -483,   177,
     178,  -942,  -942,  -942,  -942,  -942,   777,  -942,  -942,  -942,
    -942,  -942,   708,  -942,  -942,  -102,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,   -36,  -159,  -942,  -942,   292,   101,  -942,
    -475,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -771,  -942,     1,  -942,   361,  -602,  -942,  -942,  -942,  -942,
    -942,  -288,  -280,  -941,  -663,  -942,  -942,  -942,  -942,  -942,
    -942,  -942,  -942,  -942,  -942,   278,  -566,  -683,  -942,  -942,
     -18,  -653,  -942,  -942,  -942,  -942,  -942,  -942,  -942,   595,
     596,  -366,   260,  -942,  -942,  -942,  -942,  -942,  -942,  -942,
    -942,   -17,  -942,  -942,   -23,  -367,  -348,   -11,  -942,   308,
    -942,  -942,   124,   113,   -71,   312,  -942,  -942,   126,  -942,
    -642,  -942,  -942,  -942,  -942,  -197,  -739,  -942,   -94,  -496,
    -942,  -577,  -942,  -942,  -942,  -942,  -847,  -942,  -942,  -942,
    -942,   -55,   131,  -942
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   932,   583,   220,   549,   221,
     222,   724,   223,   410,   224,   225,   226,   227,   228,   903,
     904,   978,   907,   229,   230,   231,   232,   456,   393,   781,
     782,   233,   457,   234,   459,   235,   236,   237,   463,   464,
     956,   659,   238,   590,   639,   591,   597,   957,   958,   959,
     640,   460,   461,   828,   829,  1140,   462,   825,   826,  1011,
    1012,  1013,  1014,   239,   585,   586,   240,   892,   893,   241,
     242,   243,   244,   667,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   483,   484,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   510,   511,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   706,   285,
     286,   287,   980,   616,   617,   618,  1236,  1259,  1260,  1253,
    1254,  1261,  1255,   981,   982,   288,   289,   983,   290,   291,
     292,   293,   294,   295,   296,   880,   660,   833,  1024,   834,
     835,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   895,   896,   307,   308,   309,   310,   311,   312,   313,
     635,   636,   314,  1002,  1003,   933,   382,   315,   316,   675,
     862,   676,   677,   678,   679,   680,   681,   682,   863,   864,
     565,   566,   567,   568,   569,  1228,  1229,   570,  1173,  1083,
    1177,  1174,   571,   572,   866,   877,  1045,   867,   868,   873,
     869,  1156,  1041,   852
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       358,   836,   517,   543,   518,   926,   686,   687,   688,   689,
     674,   878,   879,   937,   797,   420,   580,   584,   645,   411,
     413,   769,   406,   774,  1078,  1056,   775,   554,   979,   658,
    1049,   887,     4,   577,   865,  1042,   558,   947,   588,  1119,
     422,   836,   836,   841,   620,   400,   663,   407,   664,   665,
     654,   666,   655,   668,   778,   364,   365,   366,  1224,   654,
     408,   669,   670,   542,   379,   367,   364,   365,   366,   379,
     815,   575,   798,   655,   593,   804,   367,   766,   971,   972,
     542,  1234,   368,   414,  1149,   446,   446,   969,  1081,   842,
    1042,   846,   802,   369,   808,   370,   446,   418,   371,   656,
    1031,   372,   540,   419,   773,   766,    64,   600,  1163,   486,
     627,   628,   373,   630,   631,   632,   633,    74,   819,   638,
     844,   740,  1153,   373,   374,  1008,   487,   440,  1154,   486,
     317,   646,  1136,  1137,   441,   541,  1155,   799,   446,   651,
     652,    88,   601,  1010,  1082,   671,   487,  1037,   672,   488,
     803,  1150,   970,   767,   820,   446,   581,   973,   884,  1251,
     657,   506,   657,   971,   914,   613,  1235,   971,   375,   559,
     971,   972,  1164,  1119,   974,   794,   975,   560,  1257,   380,
    1038,   793,   381,   579,  1092,   735,  1086,  1043,  1044,   779,
     561,   621,   562,   968,   816,   805,   806,   674,   674,   979,
     582,   705,   563,   976,  1225,   564,   948,    94,  1062,   979,
     807,   950,   423,   614,   809,   810,   764,   576,   657,   657,
    1053,  1158,   780,   106,   845,   465,   714,   657,   376,   811,
     712,   760,   512,  1079,   763,   514,     4,  1180,   836,   657,
     602,   377,  1043,  1044,   977,   847,   318,   519,   673,   973,
     741,   523,   377,   654,  1179,  1210,   716,   407,   446,   974,
     407,   975,   133,   974,   493,   975,   974,   446,   975,  1252,
     319,   787,   789,   494,  1258,   524,  1032,   504,   495,   742,
     743,   324,   744,   745,   971,   972,   529,   530,   976,   532,
     446,   496,   976,   971,   885,   976,   901,  1074,  1181,    94,
     108,   715,   768,   550,  1257,   573,  1183,   574,   551,   447,
      64,  1241,  1247,   910,   538,   106,   448,  1247,  1282,   449,
     450,    74,  1287,   359,   446,   605,  1153,   451,   539,   489,
     911,   717,  1154,   754,   824,   446,  1113,   612,   527,   708,
    1155,   839,   619,   979,   446,    88,   788,   790,   624,   671,
     898,   385,   672,   534,   133,   490,   537,   320,  1267,   378,
     552,   902,   713,   973,   971,   972,   916,   917,   491,   886,
     920,  1251,  1075,  1182,   587,   971,   589,   592,  1050,  1246,
     974,  1184,   975,   674,   654,   599,  1242,  1248,   608,   974,
    1167,   975,  1249,  1283,   645,   674,   720,  1288,   587,  1285,
    1277,  1171,   492,   942,  1290,   700,   701,   721,  1293,   976,
     446,   446,   452,    94,   453,   446,   722,   915,   976,   553,
     836,   962,   637,   964,   641,   321,   322,   323,   454,   106,
     386,   699,   446,   949,   387,  1232,   702,   952,   953,   446,
     446,   446,   446,   973,   912,   446,   446,   709,   710,   711,
    1118,   446,   939,   940,   455,   719,   943,   655,   945,   446,
     974,   913,   975,   446,  1172,   905,   446,   446,   133,   446,
     446,   974,   923,   975,   383,   853,   389,   384,   966,   558,
     906,  1274,   755,   786,   390,   391,  1220,   800,  1085,   976,
     987,   988,   989,    94,   992,   993,   994,   995,   996,   997,
     976,   999,  1000,   923,   801,   759,  1166,   824,  1271,   106,
    1196,   883,   888,   889,   890,  1200,   836,   900,   930,   924,
     546,  1021,   388,   965,   725,   726,  1027,   392,  1029,  1030,
    1198,  1034,   891,  1244,   547,  1165,   792,   730,  1170,  1186,
     544,  1195,  1199,   854,  1063,  1007,   952,   953,   133,   954,
     853,  1022,  1077,  1148,   558,   545,  1008,   874,   875,   925,
    1151,  1152,   513,   836,  1090,  1009,   655,   906,   515,  1023,
    1060,  1256,  1262,   493,  1010,   360,   394,   749,   361,   876,
     674,  1215,   494,   493,   395,   777,   396,   955,   431,   731,
     409,  1256,   494,   432,   732,  1237,  1223,  1262,   848,  1240,
    1039,  1223,   507,   508,   795,  1040,   750,   751,   397,   752,
     753,   703,   559,  1087,   703,   425,   703,   426,   854,   428,
     560,   429,   855,   856,   857,   362,  1094,   738,   363,   415,
     739,  1097,  1098,   561,  1100,   562,  1264,   823,   416,  1104,
     859,  1132,   985,   837,   986,   563,  1051,   861,   564,   421,
     990,   746,   991,   424,   747,   555,   556,   557,   918,   919,
     952,   953,  1133,  1134,   908,   909,  1213,  1214,   683,   684,
     690,   691,   427,   692,   693,  1221,  1222,   433,   881,   881,
     430,   434,   435,   837,   837,   837,   837,   559,   437,  1130,
     446,   444,   445,   466,   467,   560,   485,   855,   856,   857,
     824,   497,   498,   897,   499,   897,   500,   858,   561,   509,
     562,   531,   520,  1144,   516,   859,  1145,   521,  1147,   522,
     563,   860,   861,   564,  1188,   468,   528,   533,   535,   536,
     542,   379,  1243,   469,   470,   548,   471,   578,   596,   594,
     595,   598,   609,   472,   349,   615,   361,   473,   622,   474,
     363,   381,   399,   623,   475,   625,   626,   629,   634,   644,
     647,   648,   653,   649,   695,   694,   727,   650,   707,   723,
     476,   696,  1211,   697,   728,   729,   963,   736,   963,   733,
     737,   734,   748,   761,  1189,   762,  1190,   756,   757,   765,
     770,   771,  1194,   772,   477,   478,   479,   480,   481,   482,
     813,   776,   783,   812,   817,   818,  1202,  1203,  1204,  1205,
    1206,   784,  1207,   785,   821,   822,  1016,   827,   830,   465,
     838,  1066,   840,   843,   851,   871,   870,  1025,   814,  1026,
      92,  1212,   891,  1076,   894,   872,   654,   921,   928,   929,
     931,   922,   935,   936,   927,   934,   938,  1217,   944,  1219,
     941,   946,   967,   984,   998,   951,  1089,   961,  1005,  1004,
    1015,  1017,  1001,  1036,  1028,  1033,  1019,  1020,  1055,  1058,
    1231,  1073,  1084,  1035,  1059,  1069,  1091,  1046,  1067,  1099,
     837,  1068,  1057,  1080,  1070,  1102,  1101,  1103,  1109,  1107,
    1072,  1112,  1115,  1121,  1008,  1122,  1125,  1128,  1071,  1139,
    1123,  1110,  1124,  1116,  1095,  1111,  1146,  1127,  1160,  1142,
    1120,   901,  1169,  1175,  1176,  1185,  1187,  1143,  1209,  1162,
    1216,  1226,  1233,   923,  1227,  1250,  1266,   587,   906,  1245,
    1269,  1270,  1268,   592,  1273,  1276,  1239,   642,  1284,  1289,
    1292,  1263,  1265,   643,  1105,   442,  1168,  1279,   960,   458,
    1018,  1193,  1106,  1281,  1131,  1096,  1138,  1141,  1006,  1135,
     610,  1093,   662,   436,  1064,   685,  1117,   661,   505,  1208,
     438,  1114,  1278,   439,  1275,   882,   899,   796,   443,  1129,
     849,  1126,  1047,  1054,  1159,   850,  1230,   637,  1052,  1178,
    1048,     0,   603,   604,   641,  1157,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   503,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   837,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1191,  1192,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1197,     0,     0,     0,     0,  1201,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   407,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1218,     0,     0,     0,     0,     0,   837,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   837,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1272,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1280,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,  1286,     0,     5,     6,     7,  1291,     8,
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
     132,   133,     0,   134,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,   172,   173,     0,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     1,
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
     111,     0,     0,     0,   112,   412,   113,   114,   115,     0,
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
      10,    11,    12,    13,    14,    15,    16,    17,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
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
       0,     0,     0,   112,     0,   113,   114,   115,     0,   116,
     117,   118,     0,   119,     0,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,   131,   132,
     133,     0,   134,   135,     0,   136,   137,   138,   139,   140,
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
     611,     0,   112,     0,   113,   114,   115,     0,   116,   117,
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
       0,   107,   108,     0,     0,   109,   110,   111,     0,   698,
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
     107,   108,     0,     0,   109,   110,   111,     0,     0,     0,
     112,   704,   113,   114,   115,     0,   116,   117,   118,     0,
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
     108,     0,     0,   109,   110,   111,     0,   718,     0,   112,
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
       0,     0,   109,   110,   111,     0,   758,     0,   112,     0,
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
       0,   109,   110,   111,     0,   791,     0,   112,     0,   113,
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
     109,   110,   111,     0,  1065,     0,   112,     0,   113,   114,
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
     110,   111,     0,  1088,     0,   112,     0,   113,   114,   115,
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
     111,     0,  1108,     0,   112,     0,   113,   114,   115,     0,
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
       0,     0,     0,   112,     0,   113,   114,   115,     0,   116,
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
      11,    12,    13,    14,    15,    16,    17,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
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
       0,     0,   112,     0,   113,   114,   115,     0,   116,   117,
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
       0,     0,   325,   326,     7,     0,     0,     9,   328,    11,
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
       0,     0,    93,    94,   501,    96,    97,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,   502,   108,     0,     0,   109,   110,   111,     0,     0,
       0,   112,     0,   113,   114,   115,     0,   116,   117,   118,
       0,   119,     0,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,   131,   132,   133,     0,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     352,   144,   354,   146,   355,   356,   149,   150,   151,   152,
     153,   154,   357,   156,     0,     0,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
       0,   172,   173,     0,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,   325,   326,     7,     0,     0,     9,   328,    11,    12,
      13,    14,   333,    16,    17,     0,   334,    19,    20,   336,
     337,    23,   338,    25,    26,    27,     0,   339,   340,    30,
       0,   341,   342,    34,    35,    36,    37,    38,    39,    40,
      41,   343,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,     0,     0,    62,    63,     0,     0,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
      74,     0,    75,    76,    77,    78,     0,    79,     0,     0,
       0,   347,    81,    82,    83,    84,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    90,    91,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,     0,     0,   109,   110,   111,     0,     0,     0,
     112,     0,   113,   114,   115,     0,   116,   117,   118,     0,
     119,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,   131,   132,   133,     0,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   352,
     144,   354,   146,   355,   356,   149,   150,   151,   152,   153,
     154,   357,   156,     0,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
     172,   173,     0,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,     0,
     325,   326,     7,     0,     0,   327,   328,    11,    12,    13,
      14,   333,    16,    17,     0,   334,    19,    20,   336,   337,
      23,   338,    25,    26,    27,     0,   339,   340,    30,     0,
     341,   342,    34,    35,    36,    37,    38,    39,    40,    41,
     343,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     0,     0,    62,    63,     0,     0,     0,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,    74,
       0,    75,    76,    77,    78,     0,    79,     0,     0,     0,
     347,    81,    82,    83,    84,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
      93,    94,     0,    96,    97,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,     0,     0,   109,   110,   111,     0,     0,     0,   112,
       0,   113,   114,   115,     0,     0,     0,   118,     0,   119,
       0,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,   131,   132,   133,     0,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   352,   144,
     354,   146,   355,   356,   149,   150,   151,   152,   153,   154,
     357,   156,     0,     0,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,     0,   172,
     173,     0,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     0,     0,     0,     0,     0,     0,   325,
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
      86,    87,     0,    89,    90,    91,     0,     0,     0,     0,
       0,     0,    96,    97,     0,     0,     0,     0,    98,    99,
     100,   350,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,     0,     0,     0,   112,     0,
     113,   114,     0,     0,     0,     0,   118,     0,   119,     0,
     120,   121,   122,   123,   351,   125,   126,   127,   128,   129,
     130,     0,     0,   131,   132,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   352,   144,   354,
     146,   355,   356,   149,   150,   151,   152,   153,   154,   357,
     156,     0,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,     0,   172,   173,
       0,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,     0,   325,   326,
       7,     0,     0,   327,   328,   329,   330,   331,   332,   333,
      16,    17,     0,   334,   335,    20,   336,   337,    23,   338,
      25,    26,    27,     0,   339,   340,    30,     0,   341,   342,
      34,    35,    36,    37,    38,    39,    40,    41,   343,    43,
     344,   345,    46,    47,    48,    49,     0,     0,    52,     0,
      53,    54,    55,   346,     0,     0,    59,    60,    61,     0,
       0,     0,    63,     0,     0,     0,     0,    65,    66,     0,
       0,    69,    70,     0,     0,     0,     0,     0,     0,    75,
      76,    77,    78,     0,    79,     0,     0,     0,   347,    81,
      82,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,     0,    89,    90,    91,     0,     0,     0,     0,     0,
       0,    96,    97,     0,     0,     0,     0,    98,    99,   100,
     350,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,     0,     0,     0,   112,     0,   113,
       0,     0,     0,     0,     0,   118,     0,   119,     0,   120,
     121,   122,   123,   351,   125,   126,   127,   128,   129,   130,
       0,     0,   131,   132,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   352,   353,   354,   146,
     355,   356,   149,   150,   151,   152,   153,   154,   357,   156,
       0,     0,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,     0,   172,   173,     0,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   417,     0,     3,     0,     0,     0,     0,     0,     0,
       0,   325,   326,     7,     0,     0,   327,   328,   329,   330,
     331,   332,   333,    16,    17,     0,   334,   335,    20,   336,
     337,    23,   338,    25,    26,    27,     0,   339,   340,    30,
       0,   341,   342,    34,    35,    36,    37,    38,    39,    40,
      41,   343,    43,   344,   345,    46,    47,    48,    49,     0,
       0,    52,     0,    53,    54,    55,   346,     0,     0,    59,
      60,    61,     0,     0,     0,    63,     0,     0,     0,     0,
      65,    66,     0,     0,    69,    70,     0,     0,     0,     0,
       0,     0,    75,    76,    77,    78,     0,    79,     0,     0,
       0,   347,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,     0,    89,    90,    91,     0,     0,
       0,     0,     0,     0,    96,    97,     0,     0,     0,     0,
      98,    99,   100,   350,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
     112,     0,   113,     0,     0,     0,     0,     0,     0,     0,
     119,     0,   120,   121,   122,   123,   351,   125,   126,   127,
     128,   129,   130,     0,     0,   131,   132,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   352,
     353,   354,   146,   355,   356,   149,   150,   151,   152,   153,
     154,   357,   156,     0,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
     172,   173,     0,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     3,     0,     0,     0,     0,     0,
       0,     0,   325,   326,     7,     0,     0,   327,   328,   329,
     330,   331,   332,   333,    16,    17,     0,   334,   335,    20,
     336,   337,    23,   338,    25,    26,    27,     0,   339,   340,
      30,     0,   341,   342,    34,    35,    36,    37,    38,    39,
      40,    41,   343,    43,   344,   345,    46,    47,    48,    49,
       0,     0,    52,     0,    53,    54,    55,   346,     0,     0,
      59,    60,    61,     0,     0,     0,    63,     0,     0,     0,
       0,    65,    66,     0,     0,    69,    70,     0,     0,     0,
       0,     0,     0,    75,    76,    77,    78,     0,    79,     0,
       0,     0,   347,    81,    82,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,     0,    89,    90,    91,   348,
       0,     0,   349,     0,     0,    96,    97,     0,     0,     0,
       0,    98,    99,   100,   350,   102,   103,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   111,     0,     0,
       0,   112,     0,   113,     0,     0,     0,     0,     0,     0,
       0,   119,     0,   120,   121,   122,   123,   351,   125,   126,
     127,   128,   129,   130,     0,     0,   131,   132,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     352,   353,   354,   146,   355,   356,   149,   150,   151,   152,
     153,   154,   357,   156,     0,     0,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
       0,   172,   173,     0,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     3,     0,     0,     0,     0,
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
     398,     0,     0,   399,     0,     0,    96,    97,     0,     0,
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
      91,     0,     0,     0,     0,     0,     0,    96,    97,     0,
       0,     0,     0,    98,    99,   100,   350,   102,   103,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
       0,     0,     0,   112,   525,   113,     0,     0,     0,     0,
       0,   526,     0,   119,     0,   120,   121,   122,   123,   351,
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
      90,    91,     0,     0,     0,     0,     0,     0,    96,    97,
       0,     0,     0,     0,    98,    99,   100,   350,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     0,     0,     0,   112,   606,   113,     0,     0,     0,
       0,     0,   607,     0,   119,     0,   120,   121,   122,   123,
     351,   125,   126,   127,   128,   129,   130,     0,     0,   131,
     132,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   352,   353,   354,   146,   355,   356,   149,
     150,   151,   152,   153,   154,   357,   156,     0,     0,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,   172,   173,     0,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,     3,     0,
       0,     0,     0,     0,     0,     0,   325,   326,     7,     0,
       0,   327,   328,   401,   330,   402,   403,   333,    16,    17,
       0,   334,   404,    20,   336,   337,    23,   338,    25,    26,
      27,     0,   339,   340,    30,     0,   341,   342,    34,    35,
      36,    37,    38,    39,    40,    41,   343,    43,    44,    45,
      46,    47,    48,    49,     0,     0,    52,     0,    53,    54,
      55,   405,     0,     0,    59,    60,    61,     0,     0,     0,
      63,     0,     0,     0,     0,    65,    66,     0,     0,    69,
      70,  1061,     0,     0,     0,     0,     0,    75,    76,    77,
      78,     0,    79,     0,     0,     0,   347,    81,    82,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,     0,
      89,    90,   831,     0,     0,     0,     0,     0,     0,    96,
      97,     0,     0,     0,     0,    98,    99,   100,   350,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,     0,     0,   112,     0,   113,   114,     0,
       0,     0,     0,     0,     0,   119,     0,   120,   121,   122,
     123,   351,   125,   126,   127,   128,   129,   130,     0,     0,
     832,   132,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   352,   144,   354,   146,   355,   356,
     149,   150,   151,   152,   153,   154,   357,   156,     0,     0,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,     0,   172,   173,     0,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     3,
       0,     0,     0,     0,     0,     0,     0,   325,   326,     7,
       0,     0,   327,   328,   401,   330,   402,   403,   333,    16,
      17,     0,   334,   404,    20,   336,   337,    23,   338,    25,
      26,    27,     0,   339,   340,    30,     0,   341,   342,    34,
      35,    36,    37,    38,    39,    40,    41,   343,    43,    44,
      45,    46,    47,    48,    49,     0,     0,    52,     0,    53,
      54,    55,   405,     0,     0,    59,    60,    61,     0,     0,
       0,    63,     0,     0,     0,     0,    65,    66,     0,     0,
      69,    70,     0,     0,     0,     0,     0,     0,    75,    76,
      77,    78,     0,    79,     0,     0,     0,   347,    81,    82,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
       0,    89,    90,   831,     0,     0,     0,     0,     0,     0,
      96,    97,     0,     0,     0,     0,    98,    99,   100,   350,
     102,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,     0,     0,     0,   112,     0,   113,   114,
       0,     0,     0,     0,     0,     0,   119,     0,   120,   121,
     122,   123,   351,   125,   126,   127,   128,   129,   130,     0,
       0,   832,   132,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   352,   144,   354,   146,   355,
     356,   149,   150,   151,   152,   153,   154,   357,   156,     0,
       0,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   172,   173,     0,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       3,     0,     0,     0,     0,     0,     0,     0,   325,   326,
       7,     0,     0,   327,   328,   329,   330,   331,   332,   333,
      16,    17,     0,   334,   335,    20,   336,   337,    23,   338,
      25,    26,    27,     0,   339,   340,    30,     0,   341,   342,
      34,    35,    36,    37,    38,    39,    40,    41,   343,    43,
     344,   345,    46,    47,    48,    49,     0,     0,    52,     0,
      53,    54,    55,   346,     0,     0,    59,    60,    61,     0,
       0,     0,    63,     0,     0,     0,     0,    65,    66,     0,
       0,    69,    70,     0,     0,     0,     0,     0,     0,    75,
      76,    77,    78,     0,    79,     0,     0,     0,   347,    81,
      82,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,     0,    89,    90,    91,     0,     0,     0,     0,     0,
       0,    96,    97,     0,     0,     0,     0,    98,    99,   100,
     350,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,     0,     0,     0,   112,     0,   113,
       0,     0,     0,     0,     0,     0,     0,   119,     0,   120,
     121,   122,   123,   351,   125,   126,   127,   128,   129,   130,
       0,     0,   131,   132,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   352,   353,   354,   146,
     355,   356,   149,   150,   151,   152,   153,   154,   357,   156,
       0,     0,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,     0,   172,   173,     0,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        11,   654,   317,   370,   319,   744,   489,   490,   491,   492,
     485,   694,   695,   765,   616,   117,   383,   384,   445,    92,
      93,   587,    58,   592,   908,   872,   592,   375,   799,   465,
     860,   707,    20,   381,   676,    80,    84,   123,   386,   980,
      21,   694,   695,   127,     7,    56,   468,    58,   470,   471,
      78,   473,    80,   475,    62,    38,    39,    40,    20,    78,
      71,   483,   484,    20,    18,    48,    38,    39,    40,    18,
      91,    20,   111,    80,   389,    78,    48,    91,     8,     9,
      20,    77,    54,    94,    43,    91,    91,   111,    80,   658,
      80,   660,   112,    65,    78,    67,    91,   108,    70,   127,
     127,    73,   148,   114,   123,    91,    94,    33,   101,   138,
     425,   426,    95,   428,   429,   430,   431,   105,    55,   434,
     127,    96,   242,    95,    96,    90,   155,    37,   248,   138,
     217,   446,  1012,  1013,    44,   181,   256,   176,    91,   454,
     455,   129,    68,   108,   136,   133,   155,   197,   136,   178,
     170,   110,   176,   167,    91,    91,    96,    87,   164,     4,
     246,   263,   246,     8,   730,   170,   162,     8,   140,   217,
       8,     9,   165,  1114,   104,   170,   106,   225,    19,   133,
     230,   167,   136,   140,   936,   552,   925,   232,   233,   197,
     238,   154,   240,   795,   215,   198,   199,   672,   673,   970,
     140,   516,   250,   133,   166,   253,   775,   137,   891,   980,
     213,   777,   193,   166,   198,   199,   583,   166,   246,   246,
     862,  1051,   230,   153,   660,   236,    91,   246,   200,   213,
     166,   579,   268,   909,   582,   271,    20,  1084,   891,   246,
     166,   224,   232,   233,   174,   667,    28,   320,   236,    87,
     225,   324,   224,    78,   244,  1135,    91,   268,    91,   104,
     271,   106,   192,   104,   180,   106,   104,    91,   106,   114,
     136,    91,    91,   189,   115,   348,   845,   133,   117,   254,
     255,   136,   257,   258,     8,     9,   359,   360,   133,   362,
      91,   130,   133,     8,    91,   133,   101,    91,    91,   137,
     156,   166,   127,    33,    19,   378,    91,   380,    38,    46,
      94,    91,    91,   128,   161,   153,    53,    91,    91,    56,
      57,   105,    91,   133,    91,   398,   242,    64,   175,   100,
     145,   166,   248,   166,   649,    91,   174,   410,   349,   163,
     256,   656,   415,  1114,    91,   129,   166,   166,   421,   133,
     716,   101,   136,   364,   192,   126,   367,   133,  1242,   136,
      90,   166,   163,    87,     8,     9,   733,   734,   139,   166,
     737,     4,   166,   166,   385,     8,   387,   388,   861,  1226,
     104,   166,   106,   858,    78,   396,   166,   166,   399,   104,
    1073,   106,   166,   166,   821,   870,   163,   166,   409,  1283,
     115,   117,   173,   770,  1288,   507,   508,   163,  1292,   133,
      91,    91,   149,   137,   151,    91,   163,   732,   133,   149,
    1073,   787,   433,   789,   435,   201,   202,   203,   165,   153,
     140,   504,    91,   127,   101,  1187,   509,    60,    61,    91,
      91,    91,    91,    87,   128,    91,    91,   520,   521,   522,
     174,    91,   767,   768,   191,   528,   771,    80,   773,    91,
     104,   145,   106,    91,   180,   118,    91,    91,   192,    91,
      91,   104,    80,   106,    47,    80,   133,    50,   793,    84,
     133,   114,   163,   163,    58,    59,  1169,   163,    96,   133,
     805,   806,   807,   137,   809,   810,   811,   812,   813,   814,
     133,   816,   817,    80,   163,   578,  1072,   822,  1247,   153,
    1112,   163,   163,   163,   163,  1117,  1169,   163,   163,    96,
     161,   125,   101,   163,   535,   536,   841,   101,   843,   844,
     174,   163,    84,  1216,   175,   163,   609,   548,   163,   163,
     146,   163,   163,   148,    96,    79,    60,    61,   192,    63,
      80,   155,   118,  1036,    84,   161,    90,   221,   222,   136,
    1043,  1044,   270,  1216,   931,    99,    80,   133,   276,   173,
     885,  1234,  1235,   180,   108,   133,    56,   225,   136,   243,
    1055,   178,   189,   180,    28,   596,   136,   101,   205,   118,
     101,  1254,   189,   210,   123,  1197,  1173,  1260,   671,  1201,
     242,  1178,   171,   172,   615,   247,   254,   255,   136,   257,
     258,   510,   217,   928,   513,   205,   515,   207,   148,   205,
     225,   207,   227,   228,   229,   133,   941,   223,   136,   133,
     226,   946,   947,   238,   949,   240,  1238,   648,    14,   954,
     245,  1008,   212,   654,   214,   250,   251,   252,   253,   133,
     212,   223,   214,   195,   226,   201,   202,   203,   109,   110,
      60,    61,   109,   110,   725,   726,  1149,  1150,   486,   487,
     493,   494,   136,   495,   496,  1171,  1172,   101,   696,   697,
     205,   133,   101,   694,   695,   696,   697,   217,     0,  1004,
      91,   170,   170,   147,    76,   225,   235,   227,   228,   229,
    1015,    71,   179,   714,    85,   716,    86,   237,   238,   134,
     240,   166,   133,  1028,   136,   245,  1031,   133,  1033,   133,
     250,   251,   252,   253,  1091,   113,   133,   166,    38,    38,
      20,    18,  1215,   121,   122,   101,   124,   133,   101,   252,
     252,   101,   133,   131,   136,    25,   136,   135,    15,   137,
     136,   136,   136,   166,   142,   193,    20,   166,   211,    37,
     149,   101,    91,   150,    78,   211,    20,   150,   166,   136,
     158,    78,  1139,    78,    91,    91,   787,   108,   789,   140,
     113,   140,    20,    80,  1099,    33,  1101,   166,   166,    80,
     113,   123,  1107,    91,   182,   183,   184,   185,   186,   187,
     217,   163,   166,    78,   123,   163,  1121,  1122,  1123,  1124,
    1125,   166,  1127,   166,   170,   150,   827,   101,   101,   830,
     101,   894,   101,   127,   253,   236,   234,   838,   205,   840,
     133,  1146,    84,   906,   133,   241,    78,   255,   177,   133,
     113,   256,   113,    80,   256,   140,   101,  1162,   101,  1164,
     127,   123,    25,    20,   101,   230,   929,   133,   101,   133,
      91,    91,   219,   231,   127,   127,   136,   136,   127,    49,
    1185,    78,    20,   166,   125,   125,    91,   231,   166,   123,
     891,   166,   256,   256,   166,   101,   127,   101,   961,    63,
     901,   113,     6,   213,    90,   213,   217,   136,   166,    90,
     213,   166,   213,   976,   170,   166,   127,   165,   249,   166,
     170,   101,    78,    20,    20,   107,    80,   166,   163,   165,
      78,    20,    61,    80,   239,   101,   101,   938,   133,   165,
    1245,   239,   165,   944,    77,   162,   176,   444,   101,   101,
     166,   176,   176,   444,   955,   201,  1074,   176,   782,   235,
     830,  1105,   956,  1268,  1005,   944,  1015,  1017,   822,  1012,
     409,   938,   467,   195,   892,   488,   977,   466,   260,  1128,
     198,   970,  1260,   198,  1254,   697,   716,   616,   202,  1002,
     672,   998,   858,   870,  1055,   673,  1183,   998,   862,  1083,
     859,    -1,   397,   397,  1005,  1050,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1061,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1073,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1102,  1103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1113,    -1,    -1,    -1,    -1,  1118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1163,    -1,    -1,    -1,    -1,    -1,  1169,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1250,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1266,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,  1284,    -1,    26,    27,    28,  1289,    30,
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
     191,   192,    -1,   194,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,   235,   236,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    10,
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
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,    -1,
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
      -1,    -1,    -1,   165,    -1,   167,   168,   169,    -1,   171,
     172,   173,    -1,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,   190,   191,
     192,    -1,   194,   195,    -1,   197,   198,   199,   200,   201,
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
     163,    -1,   165,    -1,   167,   168,   169,    -1,   171,   172,
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
     155,   156,    -1,    -1,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,    -1,   171,   172,   173,    -1,
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
     160,   161,    -1,   163,    -1,   165,    -1,   167,   168,   169,
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
      -1,    -1,    -1,   165,    -1,   167,   168,   169,    -1,   171,
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
      -1,    -1,   165,    -1,   167,   168,   169,    -1,   171,   172,
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
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,    -1,    -1,   159,   160,   161,    -1,    -1,
      -1,   165,    -1,   167,   168,   169,    -1,   171,   172,   173,
      -1,   175,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,   190,   191,   192,    -1,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,   235,   236,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
     105,    -1,   107,   108,   109,   110,    -1,   112,    -1,    -1,
      -1,   116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
     155,   156,    -1,    -1,   159,   160,   161,    -1,    -1,    -1,
     165,    -1,   167,   168,   169,    -1,   171,   172,   173,    -1,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,   190,   191,   192,    -1,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
     235,   236,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    -1,    89,    90,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,   105,
      -1,   107,   108,   109,   110,    -1,   112,    -1,    -1,    -1,
     116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
     136,   137,    -1,   139,   140,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,   159,   160,   161,    -1,    -1,    -1,   165,
      -1,   167,   168,   169,    -1,    -1,    -1,   173,    -1,   175,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,   190,   191,   192,    -1,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,   235,
     236,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
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
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,   235,   236,
      -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    -1,    76,    -1,
      78,    79,    80,    81,    -1,    -1,    84,    85,    86,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    -1,    95,    96,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,   112,    -1,    -1,    -1,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,    -1,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,    -1,    -1,    -1,   165,    -1,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,   175,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,   190,   191,    -1,    -1,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,   235,   236,    -1,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
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
     165,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,   190,   191,    -1,    -1,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
     235,   236,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      -1,    -1,    76,    -1,    78,    79,    80,    81,    -1,    -1,
      84,    85,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    95,    96,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,   112,    -1,
      -1,    -1,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,    -1,   130,   131,   132,   133,
      -1,    -1,   136,    -1,    -1,   139,   140,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,
      -1,   165,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,   190,   191,    -1,    -1,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,   235,   236,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    18,    -1,    -1,    -1,    -1,
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
     133,    -1,    -1,   136,    -1,    -1,   139,   140,    -1,    -1,
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
     132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
      -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,   175,    -1,   177,   178,   179,   180,   181,
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
     131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,   175,    -1,   177,   178,   179,   180,
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
     100,   101,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,   112,    -1,    -1,    -1,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,
     130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,    -1,    -1,    -1,   165,    -1,   167,   168,    -1,
      -1,    -1,    -1,    -1,    -1,   175,    -1,   177,   178,   179,
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
      -1,    -1,   161,    -1,    -1,    -1,   165,    -1,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,   177,   178,
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
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,   112,    -1,    -1,    -1,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,    -1,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,    -1,    -1,    -1,   165,    -1,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,   190,   191,    -1,    -1,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,   235,   236,    -1,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258
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
     128,   145,   128,   145,   440,   319,   469,   469,   109,   110,
     469,   255,   256,    80,    96,   136,   490,   256,   177,   133,
     163,   113,   299,   469,   140,   113,    80,   299,   101,   319,
     319,   127,   469,   319,   101,   319,   123,   123,   335,   127,
     440,   230,    60,    61,    63,   101,   334,   341,   342,   343,
     324,   133,   455,   471,   455,   163,   319,    25,   419,   111,
     176,     8,     9,    87,   104,   106,   133,   174,   315,   414,
     416,   427,   428,   431,    20,   212,   214,   319,   319,   319,
     212,   214,   319,   319,   319,   319,   319,   319,   101,   319,
     319,   219,   467,   468,   133,   101,   351,    79,    90,    99,
     108,   353,   354,   355,   356,    91,   471,    91,   333,   136,
     136,   125,   155,   173,   442,   471,   471,   319,   127,   319,
     319,   127,   335,   127,   163,   166,   231,   197,   230,   242,
     247,   506,    80,   232,   233,   500,   231,   476,   506,   369,
     372,   251,   482,   484,   477,   127,   500,   256,    49,   125,
     319,   101,   441,    96,   362,   163,   318,   166,   166,   125,
     166,   166,   471,    78,    91,   166,   318,   118,   316,   306,
     256,    80,   136,   493,    20,    96,   490,   319,   163,   318,
     469,    91,   299,   359,   319,   170,   339,   319,   319,   123,
     319,   127,   101,   101,   319,   471,   343,    63,   163,   318,
     166,   166,   113,   174,   416,     6,   318,   471,   174,   427,
     170,   213,   213,   213,   213,   217,   465,   165,   136,   468,
     319,   344,   469,   109,   110,   355,   356,   356,   352,    90,
     349,   348,   166,   166,   319,   319,   127,   319,   372,    43,
     110,   372,   372,   242,   248,   256,   505,   505,   369,   478,
     249,   471,   165,   101,   165,   163,   440,   441,   314,    78,
     163,   117,   180,   492,   495,    20,    20,   494,   492,   244,
     500,    91,   166,    91,   166,   107,   163,    80,   469,   319,
     319,   471,   471,   342,   319,   163,   419,   471,   174,   163,
     419,   471,   319,   319,   319,   319,   319,   319,   398,   163,
     356,   469,   319,   372,   372,   178,    78,   319,   471,   319,
     441,   493,   493,   495,    20,   166,    20,   239,   489,   490,
     489,   319,   299,    61,    77,   162,   420,   419,   471,   176,
     419,    91,   166,   372,   441,   165,   500,    91,   166,   166,
     101,     4,   114,   423,   424,   426,   428,    19,   115,   421,
     422,   425,   428,   176,   419,   176,   101,   316,   165,   319,
     239,   490,   471,    77,   114,   426,   162,   115,   425,   176,
     471,   319,    91,   166,   101,   316,   471,    91,   166,   101,
     316,   471,   166,   316
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
     303,   303,   304,   304,   305,   305,   305,   305,   306,   307,
     307,   308,   309,   310,   311,   311,   312,   312,   312,   312,
     312,   313,   313,   314,   314,   315,   316,   317,   318,   318,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   320,   321,   322,
     322,   323,   323,   323,   324,   324,   325,   325,   326,   327,
     327,   327,   328,   328,   328,   328,   328,   329,   329,   330,
     330,   331,   332,   332,   333,   333,   333,   333,   333,   333,
     333,   333,   334,   335,   336,   337,   337,   338,   338,   339,
     339,   339,   339,   340,   340,   341,   341,   341,   342,   342,
     342,   343,   343,   343,   344,   345,   346,   347,   347,   348,
     348,   349,   350,   350,   351,   351,   352,   352,   353,   353,
     353,   353,   353,   353,   353,   354,   354,   355,   355,   356,
     357,   357,   358,   358,   359,   359,   360,   360,   361,   361,
     362,   362,   363,   364,   364,   365,   365,   366,   366,   366,
     366,   366,   367,   366,   366,   366,   366,   368,   368,   368,
     369,   369,   370,   370,   370,   371,   371,   371,   371,   371,
     372,   372,   372,   373,   373,   373,   374,   374,   375,   375,
     376,   376,   377,   377,   378,   378,   379,   379,   379,   379,
     380,   380,   380,   381,   381,   381,   381,   381,   381,   382,
     382,   382,   383,   383,   383,   383,   384,   384,   385,   385,
     386,   386,   387,   387,   387,   387,   388,   389,   389,   389,
     390,   390,   391,   391,   391,   391,   392,   392,   393,   393,
     393,   393,   393,   393,   393,   394,   394,   395,   395,   396,
     396,   396,   396,   396,   397,   397,   398,   398,   399,   399,
     399,   400,   400,   401,   401,   402,   403,   403,   403,   403,
     403,   403,   403,   403,   404,   404,   405,   405,   405,   406,
     407,   407,   408,   409,   410,   411,   411,   412,   412,   413,
     413,   414,   414,   414,   415,   415,   415,   415,   415,   415,
     416,   416,   417,   417,   418,   419,   419,   420,   420,   421,
     421,   422,   422,   422,   422,   423,   423,   424,   424,   424,
     424,   425,   425,   426,   426,   427,   427,   427,   427,   428,
     428,   428,   428,   429,   429,   430,   430,   431,   432,   432,
     432,   432,   432,   432,   433,   434,   434,   434,   434,   435,
     435,   435,   435,   436,   437,   438,   438,   438,   438,   439,
     439,   440,   441,   441,   441,   442,   442,   442,   443,   443,
     443,   444,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   446,   447,   447,   447,   448,   449,   450,   450,   450,
     451,   451,   451,   451,   451,   452,   453,   453,   453,   453,
     453,   453,   453,   454,   455,   456,   457,   458,   458,   458,
     459,   459,   459,   459,   459,   459,   459,   459,   459,   459,
     460,   460,   461,   461,   462,   463,   464,   464,   465,   466,
     467,   467,   468,   468,   468,   468,   469,   470,   471,   471,
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
     471,   471,   471,   472,   472,   473,   473,   473,   473,   474,
     474,   474,   474,   475,   475,   476,   476,   477,   477,   478,
     478,   479,   479,   479,   480,   480,   481,   481,   482,   482,
     482,   482,   482,   483,   484,   484,   484,   484,   484,   484,
     484,   485,   485,   485,   485,   486,   486,   486,   486,   487,
     487,   488,   488,   488,   488,   488,   488,   488,   489,   489,
     490,   490,   490,   490,   491,   491,   491,   491,   491,   492,
     492,   493,   493,   494,   494,   495,   495,   496,   497,   497,
     498,   498,   498,   499,   499,   499,   499,   499,   500,   500,
     500,   500,   501,   502,   503,   504,   504,   505,   505,   505,
     506,   506,   507
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
       5,     4,     3,     3,     2,     3,     4,     5,     3,     2,
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
     118,    -1,    37,    54,   161,    -1,    37,    54,   175,    -1,
     136,   166,    -1,   136,   313,   166,    -1,   136,   166,    78,
     441,    -1,   136,   313,   166,    78,   441,    -1,   133,   307,
     163,    -1,   318,   170,    -1,   307,   318,   170,    -1,    52,
     101,   471,   123,   319,    -1,    26,   217,   319,    -1,    30,
     136,   319,   166,   306,    -1,    27,    28,    -1,    66,    28,
      -1,    37,    38,   471,   305,   118,    -1,    37,    38,   471,
     305,   316,    -1,    37,    39,    38,   471,   305,   118,    -1,
      37,    39,    38,   471,   305,   316,    -1,    37,    40,    38,
     471,   305,   306,    -1,   314,    -1,   313,    91,   314,    -1,
     101,   471,    -1,   101,   471,   440,    -1,   133,   318,   163,
      -1,   133,   318,   163,    -1,   318,    -1,   319,    -1,   318,
      91,   319,    -1,   320,    -1,   357,    -1,   360,    -1,   363,
      -1,   364,    -1,   459,    -1,   460,    -1,   462,    -1,   461,
      -1,   463,    -1,   466,    -1,   472,    -1,   309,    -1,   310,
      -1,   311,    -1,   308,    -1,   306,    -1,   329,   321,    -1,
     165,   319,    -1,    58,   252,    -1,    59,   252,    -1,   197,
      -1,   230,    -1,    62,   230,    -1,   323,   341,    63,   319,
      -1,   323,    63,   319,    -1,    56,   322,   340,   324,   324,
      -1,    56,   322,   340,   324,    -1,    64,   101,   471,    -1,
     331,    -1,   336,    -1,   325,    -1,   327,    -1,   345,    -1,
     350,    -1,   346,    -1,   326,    -1,   327,    -1,   329,   328,
      -1,    56,   101,    -1,    57,    56,   101,    -1,   330,   332,
      -1,   333,    -1,   332,    91,   101,   333,    -1,   471,   127,
     319,    -1,   471,   440,   127,   319,    -1,   471,   334,   127,
     319,    -1,   471,   440,   334,   127,   319,    -1,   471,   335,
     127,   319,    -1,   471,   440,   335,   127,   319,    -1,   471,
     334,   335,   127,   319,    -1,   471,   440,   334,   335,   127,
     319,    -1,    80,   101,   471,    -1,   246,   101,   471,    -1,
      53,   101,   337,    -1,   339,    -1,   337,    91,   101,   339,
      -1,   344,    -1,   338,    91,   101,   344,    -1,   471,   123,
     319,    -1,   471,   440,   123,   319,    -1,   471,   335,   123,
     319,    -1,   471,   440,   335,   123,   319,    -1,   101,   471,
     127,   319,    -1,   101,   471,   440,   127,   319,    -1,   342,
      -1,   101,   471,    -1,   101,   471,   342,    -1,   334,    -1,
     334,   343,    -1,   343,    -1,    60,   101,   471,    61,   101,
     471,    -1,    61,   101,   471,    -1,    60,   101,   471,    -1,
     471,    -1,   191,   319,    -1,   151,   150,   347,    -1,   348,
      -1,   347,    91,   348,    -1,   101,   471,    -1,   101,   471,
     349,    -1,    90,   469,    -1,   149,   150,   351,    -1,    46,
     149,   150,   351,    -1,   352,    -1,   351,    91,   352,    -1,
     319,    -1,   319,   353,    -1,   354,    -1,   355,    -1,   356,
      -1,   354,   355,    -1,   354,   356,    -1,   355,   356,    -1,
     354,   355,   356,    -1,    79,    -1,    99,    -1,   108,   109,
      -1,   108,   110,    -1,    90,   469,    -1,    45,   101,   358,
     167,   319,    -1,   116,   101,   358,   167,   319,    -1,   359,
      -1,   358,    91,   101,   359,    -1,   471,   127,   319,    -1,
     471,   440,   127,   319,    -1,    32,   136,   318,   166,   361,
      96,   165,   319,    -1,    32,   136,   318,   166,   361,    96,
     101,   471,   165,   319,    -1,   362,    -1,   361,   362,    -1,
      84,   441,   165,   319,    -1,    84,   101,   471,    78,   441,
     165,   319,    -1,    41,   136,   318,   166,   177,   319,   107,
     319,    -1,   365,    -1,   364,   147,   365,    -1,   366,    -1,
     365,    76,   366,    -1,   368,    -1,   368,   381,   368,    -1,
     368,   382,   368,    -1,   368,   113,   368,    -1,   368,   142,
     368,    -1,    -1,   368,   137,   367,   368,    -1,   368,   135,
     368,    -1,   368,   124,   368,    -1,   368,   122,   368,    -1,
     369,    -1,   369,   235,   473,    -1,   369,   235,   473,   507,
      -1,   370,    -1,   370,   178,   370,    -1,   371,    -1,   370,
     155,   371,    -1,   370,   138,   371,    -1,   372,    -1,   371,
     173,   372,    -1,   371,   100,   372,    -1,   371,   126,   372,
      -1,   371,   139,   372,    -1,   373,    -1,   372,   180,   373,
      -1,   372,   189,   373,    -1,   374,    -1,   373,   130,   374,
      -1,   373,   117,   374,    -1,   375,    -1,   375,    71,   211,
     441,    -1,   376,    -1,   376,   179,    78,   441,    -1,   377,
      -1,   377,    85,    78,   439,    -1,   378,    -1,   378,    86,
      78,   439,    -1,   380,    -1,   379,   380,    -1,   155,    -1,
     138,    -1,   379,   155,    -1,   379,   138,    -1,   383,    -1,
     387,    -1,   384,    -1,   182,    -1,   187,    -1,   186,    -1,
     185,    -1,   184,    -1,   183,    -1,   131,    -1,   158,    -1,
     121,    -1,    31,   133,   318,   163,    -1,    31,   201,   133,
     318,   163,    -1,    31,   202,   133,   318,   163,    -1,    31,
     203,   133,   318,   163,    -1,   385,   133,   163,    -1,   385,
     133,   318,   163,    -1,   386,    -1,   385,   386,    -1,   156,
     471,    15,    -1,   156,    16,    -1,   388,    -1,   388,   389,
      -1,   172,   389,    -1,   389,    -1,   171,    -1,   390,    -1,
     390,   171,   389,    -1,   390,   172,   389,    -1,   391,    -1,
     400,    -1,   392,    -1,   392,   401,    -1,   395,    -1,   395,
     401,    -1,   393,   397,    -1,   394,    -1,    89,    -1,    97,
      -1,    82,    -1,   169,    -1,    98,    -1,   120,    -1,   119,
      -1,   397,    -1,    83,   397,    -1,   396,   397,    -1,   103,
      -1,   152,    -1,    74,    -1,   160,    -1,   159,    -1,    75,
      -1,   445,    -1,   398,    -1,   471,    -1,   399,    -1,   173,
      -1,    10,    -1,    17,    -1,   403,    -1,   403,   401,    -1,
     402,    -1,   401,   402,    -1,   134,   318,   164,    -1,   404,
      -1,   406,    -1,   407,    -1,   408,    -1,   411,    -1,   413,
      -1,   409,    -1,   410,    -1,   405,    -1,   457,    -1,    94,
      -1,   129,    -1,   105,    -1,   101,   471,    -1,   136,   166,
      -1,   136,   318,   166,    -1,   102,    -1,   148,   133,   318,
     163,    -1,   181,   133,   318,   163,    -1,   471,   136,   166,
      -1,   471,   136,   412,   166,    -1,   319,    -1,   412,    91,
     319,    -1,   414,    -1,   432,    -1,   415,    -1,   429,    -1,
     430,    -1,   137,   471,   419,   111,    -1,   137,   471,   417,
     419,   111,    -1,   137,   471,   419,   176,   174,   471,   419,
     176,    -1,   137,   471,   419,   176,   416,   174,   471,   419,
     176,    -1,   137,   471,   417,   419,   176,   174,   471,   419,
     176,    -1,   137,   471,   417,   419,   176,   416,   174,   471,
     419,   176,    -1,   427,    -1,   416,   427,    -1,   418,    -1,
     417,   418,    -1,    25,   471,   419,   113,   419,   420,    -1,
      -1,    25,    -1,   162,   421,   162,    -1,    77,   423,    77,
      -1,    -1,   422,    -1,   115,    -1,   425,    -1,   422,   115,
      -1,   422,   425,    -1,    -1,   424,    -1,   114,    -1,   426,
      -1,   424,   114,    -1,   424,   426,    -1,    19,    -1,   428,
      -1,     4,    -1,   428,    -1,   414,    -1,     9,    -1,   431,
      -1,   428,    -1,     8,    -1,   104,    -1,   106,    -1,   315,
      -1,   192,    21,   193,    -1,   192,   193,    -1,   153,    14,
     154,    -1,   153,    14,     7,    -1,    87,     6,    -1,   433,
      -1,   434,    -1,   435,    -1,   436,    -1,   437,    -1,   438,
      -1,    34,   133,   318,   163,    -1,    33,   471,   133,   163,
      -1,    33,   471,   133,   318,   163,    -1,    33,   133,   318,
     163,   133,   163,    -1,    33,   133,   318,   163,   133,   318,
     163,    -1,    81,   471,   133,   163,    -1,    81,   471,   133,
     318,   163,    -1,    81,   133,   318,   163,   133,   163,    -1,
      81,   133,   318,   163,   133,   318,   163,    -1,    35,   133,
     318,   163,    -1,    36,   133,   318,   163,    -1,    42,   470,
     133,   163,    -1,    42,   470,   133,   318,   163,    -1,    42,
     133,   318,   163,   133,   163,    -1,    42,   133,   318,   163,
     133,   318,   163,    -1,   444,    -1,   444,   125,    -1,    78,
     441,    -1,   443,    -1,   443,   442,    -1,   190,   136,   166,
      -1,   125,    -1,   173,    -1,   155,    -1,   444,    -1,   445,
      -1,   132,   136,   166,    -1,   471,    -1,   447,    -1,   453,
      -1,   451,    -1,   454,    -1,   452,    -1,   450,    -1,   449,
      -1,   448,    -1,   446,    -1,   205,   136,   166,    -1,    69,
     136,   166,    -1,    69,   136,   453,   166,    -1,    69,   136,
     454,   166,    -1,    35,   136,   166,    -1,    36,   136,   166,
      -1,    42,   136,   166,    -1,    42,   136,   470,   166,    -1,
      42,   136,    20,   166,    -1,    81,   136,   166,    -1,    81,
     136,   471,   166,    -1,    81,   136,   471,    91,   455,   166,
      -1,    81,   136,   173,   166,    -1,    81,   136,   173,    91,
     455,   166,    -1,   168,   471,   166,    -1,    33,   136,   166,
      -1,    33,   136,   471,   166,    -1,    33,   136,   471,    91,
     455,   166,    -1,    33,   136,   471,    91,   456,   166,    -1,
      33,   136,   173,   166,    -1,    33,   136,   173,    91,   455,
     166,    -1,    33,   136,   173,    91,   456,   166,    -1,    68,
     136,   471,   166,    -1,   471,    -1,   471,   125,    -1,    20,
      -1,    37,   200,   201,    -1,    37,   200,   202,    -1,    37,
     200,   203,    -1,   206,   205,   319,   213,   319,    -1,   206,
     205,   319,    78,   212,   213,   319,    -1,   206,   205,   319,
      78,   214,   213,   319,    -1,   206,   205,   319,   198,   319,
      -1,   206,   205,   319,   199,   319,    -1,   206,   207,   319,
     213,   319,    -1,   206,   207,   319,    78,   212,   213,   319,
      -1,   206,   207,   319,    78,   214,   213,   319,    -1,   206,
     207,   319,   198,   319,    -1,   206,   207,   319,   199,   319,
      -1,   204,   205,   319,    -1,   204,   207,   319,    -1,   209,
     205,   319,   217,   319,    -1,   209,   210,   211,   205,   319,
     217,   319,    -1,   208,   205,   319,    78,   319,    -1,   216,
     101,   464,   215,   319,   165,   319,    -1,   465,    -1,   464,
      91,   101,   465,    -1,   471,   123,   319,    -1,   218,   133,
     319,   163,   467,    -1,   468,    -1,   467,   468,    -1,   219,
     136,   398,   166,   316,    -1,   219,   136,   398,    91,   101,
     471,   166,   316,    -1,   219,   136,   398,    91,   101,   471,
      91,   101,   471,   166,   316,    -1,   219,   136,   398,    91,
     101,   471,    91,   101,   471,    91,   101,   471,   166,   316,
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
      -1,    66,    -1,    52,    -1,   220,   101,   338,    55,   133,
     319,   163,    -1,    55,   133,   319,   163,    -1,   475,    -1,
     475,   474,    -1,   475,   251,   369,    -1,   475,   474,   251,
     369,    -1,   484,    -1,   482,    -1,   474,   484,    -1,   474,
     482,    -1,   476,    -1,   475,   237,   476,    -1,   477,    -1,
     476,   234,   477,    -1,   478,    -1,   477,   236,   127,   478,
      -1,   479,    -1,   236,   479,    -1,   480,    -1,   480,   503,
      -1,   136,   473,   166,    -1,   481,    -1,   481,   499,    -1,
     404,    -1,   133,   318,   163,    -1,   483,    -1,   502,    -1,
     501,    -1,   504,    -1,   498,    -1,   148,    -1,   485,    -1,
     486,    -1,   487,    -1,   488,    -1,   491,    -1,   496,    -1,
     497,    -1,   240,    -1,   250,    -1,    84,   223,    -1,    84,
     226,    -1,   217,   225,    -1,   253,   225,    -1,   225,   223,
      -1,   225,   226,    -1,   217,   254,    -1,   253,   254,    -1,
     217,   257,   490,    -1,   217,   257,    96,    -1,   217,   257,
     136,   490,   166,    -1,   217,   257,   136,   490,    91,   489,
     166,    -1,   217,   257,   136,    96,   166,    -1,   217,   257,
     136,    96,    91,   489,   166,    -1,   253,   257,    -1,   490,
      -1,   489,    91,   490,    -1,    80,    20,    -1,    80,    20,
     244,    20,    -1,    80,    20,   500,   239,    -1,    80,    20,
     244,    20,   500,   239,    -1,   217,   255,   256,   493,    -1,
     217,   255,   256,   493,   492,    -1,   217,    96,   255,   256,
      -1,   217,    96,   255,   256,   492,    -1,   253,   255,   256,
      -1,   495,    -1,   492,   495,    -1,    80,    20,    -1,   136,
     494,   166,    -1,    20,    -1,   494,    20,    -1,   180,   493,
      -1,   117,   493,    -1,   238,    20,    -1,   217,   258,    -1,
     253,   258,    -1,    80,   197,    -1,    80,   230,    -1,   229,
     231,    -1,   222,    -1,   222,    49,    -1,   221,    -1,   221,
     256,    -1,   243,    -1,   232,   372,    -1,    80,   110,   372,
      -1,    80,    43,   372,    -1,   233,   372,   178,   372,    -1,
     228,   500,   505,    -1,   252,   372,   505,    -1,   241,   500,
     249,    -1,   245,   506,    -1,   227,   506,    -1,   256,    -1,
     248,    -1,   242,    -1,   247,    -1,   242,    -1,   253,   231,
     372,    -1
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
     261,   267,   272,   276,   280,   283,   287,   292,   298,   302,
     305,   309,   315,   319,   325,   328,   331,   337,   343,   350,
     357,   364,   366,   370,   373,   377,   381,   385,   387,   389,
     393,   395,   397,   399,   401,   403,   405,   407,   409,   411,
     413,   415,   417,   419,   421,   423,   425,   427,   430,   433,
     436,   439,   441,   443,   446,   451,   455,   461,   466,   470,
     472,   474,   476,   478,   480,   482,   484,   486,   488,   491,
     494,   498,   501,   503,   508,   512,   517,   522,   528,   533,
     539,   545,   552,   556,   560,   564,   566,   571,   573,   578,
     582,   587,   592,   598,   603,   609,   611,   614,   618,   620,
     623,   625,   632,   636,   640,   642,   645,   649,   651,   655,
     658,   662,   665,   669,   674,   676,   680,   682,   685,   687,
     689,   691,   694,   697,   700,   704,   706,   708,   711,   714,
     717,   723,   729,   731,   736,   740,   745,   754,   765,   767,
     770,   775,   783,   792,   794,   798,   800,   804,   806,   810,
     814,   818,   822,   823,   828,   832,   836,   840,   842,   846,
     851,   853,   857,   859,   863,   867,   869,   873,   877,   881,
     885,   887,   891,   895,   897,   901,   905,   907,   912,   914,
     919,   921,   926,   928,   933,   935,   938,   940,   942,   945,
     948,   950,   952,   954,   956,   958,   960,   962,   964,   966,
     968,   970,   972,   977,   983,   989,   995,   999,  1004,  1006,
    1009,  1013,  1016,  1018,  1021,  1024,  1026,  1028,  1030,  1034,
    1038,  1040,  1042,  1044,  1047,  1049,  1052,  1055,  1057,  1059,
    1061,  1063,  1065,  1067,  1069,  1071,  1073,  1076,  1079,  1081,
    1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,  1099,  1101,
    1103,  1105,  1107,  1110,  1112,  1115,  1119,  1121,  1123,  1125,
    1127,  1129,  1131,  1133,  1135,  1137,  1139,  1141,  1143,  1145,
    1148,  1151,  1155,  1157,  1162,  1167,  1171,  1176,  1178,  1182,
    1184,  1186,  1188,  1190,  1192,  1197,  1203,  1212,  1222,  1232,
    1243,  1245,  1248,  1250,  1253,  1260,  1261,  1263,  1267,  1271,
    1272,  1274,  1276,  1278,  1281,  1284,  1285,  1287,  1289,  1291,
    1294,  1297,  1299,  1301,  1303,  1305,  1307,  1309,  1311,  1313,
    1315,  1317,  1319,  1321,  1325,  1328,  1332,  1336,  1339,  1341,
    1343,  1345,  1347,  1349,  1351,  1356,  1361,  1367,  1374,  1382,
    1387,  1393,  1400,  1408,  1413,  1418,  1423,  1429,  1436,  1444,
    1446,  1449,  1452,  1454,  1457,  1461,  1463,  1465,  1467,  1469,
    1471,  1475,  1477,  1479,  1481,  1483,  1485,  1487,  1489,  1491,
    1493,  1495,  1499,  1503,  1508,  1513,  1517,  1521,  1525,  1530,
    1535,  1539,  1544,  1551,  1556,  1563,  1567,  1571,  1576,  1583,
    1590,  1595,  1602,  1609,  1614,  1616,  1619,  1621,  1625,  1629,
    1633,  1639,  1647,  1655,  1661,  1667,  1673,  1681,  1689,  1695,
    1701,  1705,  1709,  1715,  1723,  1729,  1737,  1739,  1744,  1748,
    1754,  1756,  1759,  1765,  1774,  1786,  1801,  1803,  1805,  1807,
    1809,  1811,  1813,  1815,  1817,  1819,  1821,  1823,  1825,  1827,
    1829,  1831,  1833,  1835,  1837,  1839,  1841,  1843,  1845,  1847,
    1849,  1851,  1853,  1855,  1857,  1859,  1861,  1863,  1865,  1867,
    1869,  1871,  1873,  1875,  1877,  1879,  1881,  1883,  1885,  1887,
    1889,  1891,  1893,  1895,  1897,  1899,  1901,  1903,  1905,  1907,
    1909,  1911,  1913,  1915,  1917,  1919,  1921,  1923,  1925,  1927,
    1929,  1931,  1933,  1935,  1937,  1939,  1941,  1943,  1945,  1947,
    1949,  1951,  1953,  1955,  1957,  1959,  1961,  1963,  1965,  1967,
    1969,  1971,  1973,  1975,  1977,  1979,  1981,  1983,  1985,  1987,
    1989,  1991,  1993,  1995,  1997,  1999,  2001,  2003,  2005,  2007,
    2009,  2011,  2013,  2015,  2017,  2019,  2021,  2023,  2025,  2027,
    2029,  2031,  2033,  2035,  2037,  2039,  2041,  2043,  2045,  2047,
    2049,  2051,  2053,  2055,  2057,  2059,  2061,  2063,  2065,  2067,
    2069,  2071,  2073,  2075,  2077,  2079,  2081,  2083,  2085,  2087,
    2089,  2091,  2093,  2095,  2097,  2099,  2101,  2103,  2105,  2107,
    2109,  2111,  2113,  2115,  2123,  2128,  2130,  2133,  2137,  2142,
    2144,  2146,  2149,  2152,  2154,  2158,  2160,  2164,  2166,  2171,
    2173,  2176,  2178,  2181,  2185,  2187,  2190,  2192,  2196,  2198,
    2200,  2202,  2204,  2206,  2208,  2210,  2212,  2214,  2216,  2218,
    2220,  2222,  2224,  2226,  2229,  2232,  2235,  2238,  2241,  2244,
    2247,  2250,  2254,  2258,  2264,  2272,  2278,  2286,  2289,  2291,
    2295,  2298,  2303,  2308,  2315,  2320,  2326,  2331,  2337,  2341,
    2343,  2346,  2349,  2353,  2355,  2358,  2361,  2364,  2367,  2370,
    2373,  2376,  2379,  2382,  2384,  2387,  2389,  2392,  2394,  2397,
    2401,  2405,  2410,  2414,  2418,  2422,  2425,  2428,  2430,  2432,
    2434,  2436,  2438
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
    1318,  1326,  1340,  1345,  1357,  1361,  1365,  1369,  1376,  1383,
    1389,  1398,  1405,  1412,  1419,  1423,  1430,  1438,  1447,  1456,
    1465,  1480,  1488,  1502,  1508,  1520,  1528,  1539,  1550,  1556,
    1568,  1569,  1570,  1571,  1572,  1575,  1576,  1577,  1578,  1579,
    1581,  1582,  1585,  1586,  1587,  1588,  1589,  1596,  1605,  1612,
    1616,  1624,  1628,  1632,  1639,  1643,  1650,  1655,  1664,  1673,
    1674,  1675,  1679,  1679,  1679,  1679,  1679,  1682,  1688,  1697,
    1701,  1711,  1722,  1728,  1742,  1749,  1757,  1766,  1776,  1784,
    1793,  1802,  1817,  1829,  1840,  1852,  1858,  1870,  1876,  1890,
    1898,  1907,  1915,  1927,  1933,  1943,  1944,  1948,  1956,  1960,
    1965,  1969,  1973,  1977,  1984,  1999,  2007,  2017,  2023,  2034,
    2040,  2049,  2059,  2064,  2076,  2082,  2096,  2102,  2114,  2121,
    2128,  2135,  2142,  2149,  2156,  2169,  2173,  2183,  2188,  2199,
    2210,  2217,  2230,  2237,  2249,  2255,  2268,  2275,  2289,  2295,
    2307,  2313,  2326,  2337,  2341,  2352,  2356,  2375,  2379,  2387,
    2395,  2403,  2411,  2411,  2419,  2427,  2435,  2449,  2453,  2460,
    2473,  2477,  2488,  2492,  2496,  2506,  2510,  2514,  2518,  2522,
    2532,  2536,  2541,  2552,  2556,  2560,  2570,  2574,  2586,  2590,
    2602,  2606,  2618,  2622,  2634,  2638,  2650,  2654,  2658,  2662,
    2674,  2678,  2682,  2692,  2696,  2700,  2704,  2708,  2712,  2722,
    2726,  2730,  2740,  2744,  2750,  2756,  2768,  2774,  2786,  2792,
    2806,  2813,  2854,  2858,  2862,  2866,  2878,  2888,  2899,  2904,
    2914,  2918,  2928,  2934,  2940,  2946,  2958,  2964,  2975,  2979,
    2983,  2987,  2991,  2995,  2999,  3009,  3013,  3023,  3029,  3041,
    3045,  3049,  3053,  3057,  3072,  3076,  3086,  3090,  3100,  3107,
    3114,  3127,  3131,  3143,  3149,  3163,  3174,  3178,  3182,  3186,
    3190,  3194,  3198,  3202,  3212,  3216,  3226,  3231,  3236,  3247,
    3257,  3261,  3272,  3282,  3293,  3349,  3355,  3367,  3373,  3385,
    3389,  3399,  3403,  3407,  3417,  3425,  3433,  3441,  3449,  3457,
    3472,  3478,  3490,  3496,  3509,  3518,  3520,  3526,  3531,  3543,
    3546,  3553,  3559,  3565,  3573,  3588,  3591,  3598,  3604,  3610,
    3618,  3632,  3637,  3648,  3653,  3664,  3669,  3674,  3680,  3692,
    3698,  3703,  3708,  3719,  3724,  3739,  3744,  3761,  3776,  3780,
    3784,  3788,  3792,  3796,  3806,  3817,  3823,  3829,  3834,  3856,
    3862,  3868,  3873,  3884,  3895,  3906,  3912,  3918,  3923,  3934,
    3940,  3952,  3964,  3970,  3976,  4013,  4018,  4023,  4034,  4038,
    4042,  4052,  4063,  4067,  4071,  4075,  4079,  4083,  4087,  4091,
    4095,  4105,  4115,  4119,  4124,  4135,  4145,  4155,  4159,  4163,
    4173,  4179,  4185,  4191,  4197,  4209,  4220,  4227,  4234,  4241,
    4248,  4255,  4262,  4275,  4296,  4303,  4323,  4363,  4368,  4371,
    4379,  4385,  4391,  4397,  4403,  4410,  4416,  4422,  4428,  4434,
    4446,  4451,  4461,  4467,  4479,  4505,  4516,  4522,  4535,  4549,
    4556,  4563,  4574,  4581,  4589,  4598,  4611,  4614,  4632,  4633,
    4634,  4635,  4636,  4637,  4638,  4639,  4640,  4641,  4642,  4643,
    4644,  4645,  4646,  4647,  4648,  4649,  4650,  4651,  4652,  4653,
    4654,  4655,  4656,  4657,  4658,  4659,  4660,  4661,  4662,  4663,
    4664,  4665,  4666,  4667,  4668,  4669,  4670,  4671,  4672,  4673,
    4674,  4675,  4676,  4677,  4678,  4679,  4680,  4681,  4682,  4683,
    4684,  4685,  4686,  4687,  4688,  4689,  4690,  4691,  4692,  4693,
    4694,  4695,  4696,  4697,  4698,  4699,  4700,  4701,  4702,  4703,
    4704,  4705,  4706,  4707,  4708,  4709,  4710,  4711,  4712,  4713,
    4714,  4715,  4716,  4717,  4718,  4719,  4720,  4721,  4722,  4723,
    4724,  4725,  4726,  4727,  4728,  4729,  4730,  4731,  4732,  4733,
    4734,  4735,  4736,  4737,  4738,  4739,  4740,  4741,  4742,  4743,
    4744,  4745,  4746,  4747,  4748,  4749,  4750,  4751,  4752,  4753,
    4754,  4755,  4756,  4757,  4758,  4759,  4760,  4761,  4762,  4763,
    4764,  4765,  4766,  4767,  4768,  4769,  4770,  4771,  4772,  4773,
    4774,  4775,  4776,  4777,  4778,  4779,  4780,  4781,  4782,  4783,
    4784,  4785,  4786,  4797,  4803,  4820,  4824,  4828,  4832,  4842,
    4845,  4848,  4851,  4860,  4863,  4872,  4875,  4884,  4887,  4896,
    4899,  4908,  4911,  4914,  4923,  4926,  4935,  4939,  4949,  4952,
    4955,  4958,  4961,  4970,  4979,  4983,  4987,  4991,  4995,  4999,
    5003,  5013,  5016,  5019,  5022,  5031,  5034,  5037,  5040,  5049,
    5052,  5061,  5064,  5067,  5070,  5073,  5076,  5079,  5088,  5091,
    5100,  5103,  5106,  5109,  5118,  5121,  5124,  5127,  5130,  5139,
    5142,  5151,  5154,  5163,  5166,  5175,  5178,  5187,  5196,  5199,
    5208,  5211,  5214,  5223,  5226,  5229,  5232,  5235,  5244,  5248,
    5252,  5256,  5266,  5275,  5285,  5294,  5297,  5306,  5309,  5312,
    5321,  5324,  5333
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
  const int xquery_parser::yylast_ = 7920;
  const int xquery_parser::yynnts_ = 234;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 437;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 274;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 528;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5341 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"


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

