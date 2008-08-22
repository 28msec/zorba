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
#line 788 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 51 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"

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
        case 91: /* "\"'DECIMAL'\"" */
#line 681 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 102: /* "\"'DOUBLE'\"" */
#line 680 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 126: /* "\"'INTEGER'\"" */
#line 679 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 274: /* "VersionDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 275: /* "MainModule" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 276: /* "LibraryModule" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 277: /* "ModuleDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 278: /* "Prolog" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 279: /* "SIND_DeclList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 280: /* "VFO_DeclList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 281: /* "SIND_Decl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 282: /* "VFO_Decl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 283: /* "Setter" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 284: /* "Import" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 285: /* "NamespaceDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "BoundarySpaceDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "DefaultNamespaceDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "OptionDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "OrderingModeDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "EmptyOrderDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "CopyNamespacesDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "DefaultCollationDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "BaseURIDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "SchemaImport" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "URILiteralList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "SchemaPrefix" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "ModuleImport" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "VarDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 346 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "ConstructionDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "FunctionSig" */
#line 693 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 356 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "Block" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 361 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "BlockBody" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 366 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "ExitExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 371 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "WhileExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 376 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "FlowCtlStatement" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 381 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "FunctionDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 386 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "ParamList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 391 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "Param" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 396 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "EnclosedExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 401 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "BracedExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 406 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "QueryBody" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 411 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "Expr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 416 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "ExprSingle" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 421 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "FLWORExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 426 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "FLWORWinCond" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 431 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "WindowClause" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 436 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "CountClause" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 441 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "ForLetWinClause" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 446 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "FLWORClauseList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 451 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "ForClause" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 456 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "VarInDeclList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 461 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VarInDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 466 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "PositionalVar" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 471 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "LetClause" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "VarGetsDeclList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 481 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "EvalVarDeclList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 486 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "VarGetsDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 491 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "WindowVarDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 496 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "WindowVars" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 501 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "WindowVars2" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 506 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "EvalVarDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 511 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "WhereClause" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 516 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "GroupByClause" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 521 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "GroupSpecList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "GroupSpec" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "GroupCollationSpec" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 536 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "LetClauseList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "OrderByClause" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "OrderSpecList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 551 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "OrderSpec" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 556 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "OrderModifier" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 561 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "OrderDirSpec" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 566 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "OrderEmptySpec" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 571 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "OrderCollationSpec" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 576 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "QuantifiedExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 581 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "QVarInDeclList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 586 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "QVarInDecl" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 591 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "TypeswitchExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 596 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CaseClauseList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 601 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CaseClause" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 606 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "IfExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 611 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "OrExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 616 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "AndExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 621 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "ComparisonExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 626 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "FTContainsExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 631 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "RangeExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 636 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "AdditiveExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 641 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "MultiplicativeExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 646 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "UnionExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 651 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "IntersectExceptExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 656 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "InstanceofExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 661 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "TreatExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 666 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CastableExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 671 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CastExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 676 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "UnaryExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 681 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "SignList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 686 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "ValueExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 691 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "ValueComp" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 696 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "NodeComp" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 701 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "ValidateExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 706 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "ExtensionExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 711 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "PragmaList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 716 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "Pragma" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 721 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "PathExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 726 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "RelativePathExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 731 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "StepExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 736 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "AxisStep" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 741 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ForwardStep" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 746 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "ForwardAxis" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 751 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "AbbrevForwardStep" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 756 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ReverseStep" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 761 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ReverseAxis" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 766 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "NodeTest" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 771 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "NameTest" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 776 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Wildcard" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 781 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "FilterExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 786 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "PredicateList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 791 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Predicate" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 796 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "PrimaryExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 801 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "Literal" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 806 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "NumericLiteral" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 811 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarRef" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 816 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "ParenthesizedExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 821 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ContextItemExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 826 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "OrderedExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 831 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "UnorderedExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 836 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "FunctionCall" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 841 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ArgList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 846 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "Constructor" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 851 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "DirectConstructor" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 856 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "DirElemConstructor" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 861 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "DirElemContentList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 866 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "DirAttributeList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 871 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "DirAttr" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 876 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "DirAttributeValue" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 881 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "Opt_QuoteAttrContentList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 886 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "QuoteAttrContentList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 891 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "Opt_AposAttrContentList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 896 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "AposAttrContentList" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 901 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "QuoteAttrValueContent" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 906 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "AposAttrValueContent" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 911 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "DirElemContent" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 916 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "CommonContent" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 921 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "DirCommentConstructor" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 926 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "DirPIConstructor" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 931 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "CDataSection" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 936 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "ComputedConstructor" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 941 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "CompDocConstructor" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 946 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "CompElemConstructor" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 951 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "CompAttrConstructor" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 956 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "CompTextConstructor" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 961 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "CompCommentConstructor" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 966 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "CompPIConstructor" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 971 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "SingleType" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 976 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "TypeDeclaration" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 981 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "SequenceType" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 986 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OccurrenceIndicator" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 991 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "ItemType" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 996 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "AtomicType" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1001 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "KindTest" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1006 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "AnyKindTest" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1011 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "DocumentTest" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1016 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "TextTest" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1021 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "CommentTest" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1026 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "PITest" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1031 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "AttributeTest" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1036 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SchemaAttributeTest" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1041 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "ElementTest" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1046 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "SchemaElementTest" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1051 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "TypeName" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1056 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "TypeName_WITH_HOOK" */
#line 689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1061 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "StringLiteral" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1066 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "InsertExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1071 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "DeleteExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1076 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "ReplaceExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1081 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "RenameExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1086 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "TransformExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1091 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "VarNameList" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1096 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "VarNameDecl" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1101 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "TryExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1106 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "CatchListExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1111 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "CatchExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1116 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "EvalExpr" */
#line 691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1121 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 94 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}
  /* Line 547 of yacc.c.  */
#line 1202 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
#line 808 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 3:
#line 813 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 4:
#line 819 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 824 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 836 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		;}
    break;

  case 7:
#line 841 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    ;}
    break;

  case 8:
#line 851 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 9:
#line 858 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		;}
    break;

  case 10:
#line 870 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 11:
#line 882 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval)));
		;}
    break;

  case 12:
#line 894 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 13:
#line 900 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 14:
#line 906 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 15:
#line 918 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 16:
#line 924 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 17:
#line 938 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 18:
#line 944 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 37:
#line 1008 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 38:
#line 1020 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1025 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1036 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 41:
#line 1042 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 42:
#line 1054 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 43:
#line 1067 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		;}
    break;

  case 44:
#line 1078 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1083 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1095 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1100 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1111 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 49:
#line 1117 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 50:
#line 1123 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 51:
#line 1129 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 52:
#line 1148 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 53:
#line 1159 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 54:
#line 1170 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 55:
#line 1177 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		;}
    break;

  case 56:
#line 1184 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 57:
#line 1191 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 58:
#line 1204 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 59:
#line 1210 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 60:
#line 1225 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1229 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 62:
#line 1239 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 63:
#line 1245 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		;}
    break;

  case 64:
#line 1252 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 65:
#line 1258 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		;}
    break;

  case 66:
#line 1272 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								NULL,
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 67:
#line 1279 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (4)].sval)),
								NULL,
								NULL);
		;}
    break;

  case 68:
#line 1286 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (4)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 69:
#line 1293 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (5)].node)),
								NULL);
		;}
    break;

  case 70:
#line 1306 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1311 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1323 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 73:
#line 1327 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 74:
#line 1331 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 75:
#line 1335 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 76:
#line 1342 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    ;}
    break;

  case 77:
#line 1349 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = new BlockBody (LOC ((yyloc)));
      blk->add ((yysemantic_stack_[(2) - (1)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 78:
#line 1355 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 79:
#line 1364 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 80:
#line 1371 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr)));
    ;}
    break;

  case 81:
#line 1378 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 82:
#line 1382 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 83:
#line 1389 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval))),
                &* (yysemantic_stack_[(5) - (4)].fnsig)->param, &* (yysemantic_stack_[(5) - (4)].fnsig)->ret, NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
		;}
    break;

  case 84:
#line 1397 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
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
#line 1406 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
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
#line 1415 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
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
#line 1424 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
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
#line 1439 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 89:
#line 1447 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 90:
#line 1461 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 91:
#line 1467 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 92:
#line 1479 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1487 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 94:
#line 1498 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 95:
#line 1509 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = new Expr(LOC ((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 96:
#line 1515 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 113:
#line 1551 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 114:
#line 1559 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    ;}
    break;

  case 115:
#line 1563 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    ;}
    break;

  case 116:
#line 1571 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    ;}
    break;

  case 117:
#line 1575 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    ;}
    break;

  case 118:
#line 1579 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    ;}
    break;

  case 119:
#line 1586 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 120:
#line 1590 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 121:
#line 1597 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)), dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 122:
#line 1602 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    ;}
    break;

  case 123:
#line 1611 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 132:
#line 1629 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 133:
#line 1635 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 134:
#line 1646 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 135:
#line 1657 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 136:
#line 1663 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 137:
#line 1677 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 138:
#line 1684 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 139:
#line 1692 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 140:
#line 1701 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 141:
#line 1711 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 142:
#line 1719 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 143:
#line 1728 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 144:
#line 1737 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 145:
#line 1752 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 146:
#line 1764 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 147:
#line 1775 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 148:
#line 1787 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 149:
#line 1793 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 150:
#line 1805 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 151:
#line 1811 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 152:
#line 1825 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 153:
#line 1833 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 154:
#line 1842 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 155:
#line 1850 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 156:
#line 1862 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 157:
#line 1868 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 159:
#line 1879 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
    ;}
    break;

  case 160:
#line 1887 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(7) - (1)].node)), "", driver.symtab.get((off_t)(yysemantic_stack_[(7) - (4)].sval)), driver.symtab.get((off_t)(yysemantic_stack_[(7) - (7)].sval)));
    ;}
    break;

  case 161:
#line 1891 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(4) - (1)].node)), "", "", driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
    ;}
    break;

  case 162:
#line 1895 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(4) - (1)].node)), "", driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)), "");
    ;}
    break;

  case 163:
#line 1899 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    ;}
    break;

  case 164:
#line 1906 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 165:
#line 1921 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 166:
#line 1929 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 167:
#line 1936 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(4) - (3)].node)),
                 dynamic_cast<LetClauseList*>((yysemantic_stack_[(4) - (4)].node)),
                 NULL);
    ;}
    break;

  case 168:
#line 1943 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(4) - (3)].node)),
                 NULL,
                 dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 169:
#line 1950 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(5) - (3)].node)),
                 dynamic_cast<LetClauseList*>((yysemantic_stack_[(5) - (4)].node)),
                 dynamic_cast<WhereClause*>((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 170:
#line 1960 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 171:
#line 1966 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 172:
#line 1977 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 173:
#line 1983 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 174:
#line 1992 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 175:
#line 1999 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      LetClauseList* lc_list_p = new LetClauseList(LOC((yyloc)));
      lc_list_p->push_back(dynamic_cast<LetClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = lc_list_p;
    ;}
    break;

  case 176:
#line 2006 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      LetClauseList* lc_list_p = dynamic_cast<LetClauseList*>((yysemantic_stack_[(2) - (1)].node));
      if (lc_list_p) lc_list_p->push_back(dynamic_cast<LetClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    ;}
    break;

  case 177:
#line 2018 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 178:
#line 2023 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 179:
#line 2035 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 180:
#line 2041 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 181:
#line 2055 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 182:
#line 2061 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 183:
#line 2073 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 184:
#line 2080 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 185:
#line 2087 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 186:
#line 2094 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 187:
#line 2101 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 188:
#line 2108 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 189:
#line 2115 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 190:
#line 2128 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 191:
#line 2132 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 192:
#line 2142 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 193:
#line 2147 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 194:
#line 2158 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 195:
#line 2169 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 196:
#line 2176 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 197:
#line 2189 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 198:
#line 2196 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 199:
#line 2208 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 200:
#line 2214 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 201:
#line 2227 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 202:
#line 2234 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 203:
#line 2248 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 204:
#line 2254 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 205:
#line 2266 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 206:
#line 2272 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 207:
#line 2285 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 208:
#line 2296 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 2300 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 210:
#line 2311 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 211:
#line 2315 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 212:
#line 2334 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 213:
#line 2338 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 214:
#line 2346 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 215:
#line 2354 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 216:
#line 2362 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 217:
#line 2369 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 218:
#line 2370 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 219:
#line 2378 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 220:
#line 2386 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 221:
#line 2394 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 222:
#line 2408 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 223:
#line 2412 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 224:
#line 2419 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 225:
#line 2432 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 226:
#line 2436 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 227:
#line 2447 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 228:
#line 2451 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 229:
#line 2455 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 230:
#line 2465 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 231:
#line 2469 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 232:
#line 2473 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 233:
#line 2477 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 234:
#line 2481 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 235:
#line 2491 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 236:
#line 2495 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 237:
#line 2500 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 238:
#line 2511 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 239:
#line 2515 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 240:
#line 2519 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 241:
#line 2529 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 242:
#line 2533 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 243:
#line 2545 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 244:
#line 2549 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 245:
#line 2561 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 246:
#line 2565 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 247:
#line 2577 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 248:
#line 2581 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 249:
#line 2593 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 250:
#line 2597 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 251:
#line 2609 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 252:
#line 2613 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 253:
#line 2617 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 254:
#line 2621 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 255:
#line 2633 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 256:
#line 2637 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 257:
#line 2641 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 258:
#line 2651 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 259:
#line 2655 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 260:
#line 2659 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 261:
#line 2663 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 262:
#line 2667 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 263:
#line 2671 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 264:
#line 2681 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 265:
#line 2685 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 266:
#line 2689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 267:
#line 2699 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 268:
#line 2703 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "strict",
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 269:
#line 2709 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "lax",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 270:
#line 2715 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "skip",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 271:
#line 2727 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 272:
#line 2733 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 273:
#line 2745 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 274:
#line 2751 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 275:
#line 2765 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 276:
#line 2771 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 277:
#line 2814 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 278:
#line 2818 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 279:
#line 2822 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 280:
#line 2826 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 281:
#line 2839 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
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

  case 282:
#line 2850 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 283:
#line 2855 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 284:
#line 2865 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 285:
#line 2869 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 286:
#line 2879 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 287:
#line 2885 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 288:
#line 2891 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 289:
#line 2897 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 290:
#line 2909 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 291:
#line 2915 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 292:
#line 2926 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 293:
#line 2930 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 294:
#line 2934 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 295:
#line 2938 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 296:
#line 2942 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 297:
#line 2946 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 298:
#line 2950 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 299:
#line 2960 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 300:
#line 2964 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 301:
#line 2974 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 302:
#line 2980 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 303:
#line 2992 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 304:
#line 2996 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 305:
#line 3000 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 306:
#line 3004 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 307:
#line 3008 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 308:
#line 3023 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 309:
#line 3027 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 310:
#line 3037 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 311:
#line 3041 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 312:
#line 3051 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 313:
#line 3058 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 314:
#line 3065 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 315:
#line 3078 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 316:
#line 3082 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 317:
#line 3094 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 318:
#line 3100 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 319:
#line 3114 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 320:
#line 3125 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 321:
#line 3129 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 322:
#line 3133 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 323:
#line 3137 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 324:
#line 3141 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 325:
#line 3145 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 326:
#line 3149 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 327:
#line 3153 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 328:
#line 3163 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 329:
#line 3167 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 330:
#line 3177 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 331:
#line 3182 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 332:
#line 3187 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 333:
#line 3198 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 334:
#line 3208 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 335:
#line 3212 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 336:
#line 3223 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 337:
#line 3233 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 338:
#line 3244 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 339:
#line 3300 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 340:
#line 3306 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 341:
#line 3318 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 342:
#line 3324 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 343:
#line 3336 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 344:
#line 3340 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 345:
#line 3350 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 346:
#line 3354 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 347:
#line 3358 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 348:
#line 3368 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 349:
#line 3376 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 350:
#line 3384 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 351:
#line 3392 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 352:
#line 3400 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 353:
#line 3408 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 354:
#line 3423 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 355:
#line 3429 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 356:
#line 3441 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 357:
#line 3447 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 358:
#line 3460 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 361:
#line 3477 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 362:
#line 3482 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 363:
#line 3493 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 364:
#line 3497 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 365:
#line 3504 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 366:
#line 3510 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 367:
#line 3516 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 368:
#line 3524 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 369:
#line 3538 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 370:
#line 3542 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 371:
#line 3549 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 372:
#line 3555 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 373:
#line 3561 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 374:
#line 3569 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 375:
#line 3583 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 376:
#line 3588 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 377:
#line 3599 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 378:
#line 3604 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 379:
#line 3615 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 380:
#line 3620 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 381:
#line 3625 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 382:
#line 3631 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 383:
#line 3643 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 384:
#line 3649 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 385:
#line 3654 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 386:
#line 3659 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 387:
#line 3670 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 388:
#line 3675 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 389:
#line 3690 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 390:
#line 3695 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 391:
#line 3712 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 392:
#line 3727 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 393:
#line 3731 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 394:
#line 3735 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 395:
#line 3739 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 396:
#line 3743 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 397:
#line 3747 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 398:
#line 3757 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 399:
#line 3768 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 400:
#line 3774 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 401:
#line 3780 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 402:
#line 3785 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 403:
#line 3807 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 404:
#line 3813 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 405:
#line 3819 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 406:
#line 3824 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 407:
#line 3835 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 408:
#line 3846 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 409:
#line 3857 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 410:
#line 3863 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 411:
#line 3869 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 412:
#line 3874 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 413:
#line 3885 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 414:
#line 3891 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 415:
#line 3903 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 416:
#line 3915 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 417:
#line 3921 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 418:
#line 3927 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 419:
#line 3964 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 420:
#line 3969 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 421:
#line 3974 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 422:
#line 3985 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 423:
#line 3989 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 424:
#line 3993 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 425:
#line 4003 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 426:
#line 4014 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 427:
#line 4018 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 428:
#line 4022 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 429:
#line 4026 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 430:
#line 4030 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 431:
#line 4034 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 432:
#line 4038 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 433:
#line 4042 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 434:
#line 4046 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 435:
#line 4056 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 436:
#line 4066 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 437:
#line 4070 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 438:
#line 4075 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 439:
#line 4086 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 440:
#line 4096 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 441:
#line 4106 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 442:
#line 4110 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 443:
#line 4114 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 444:
#line 4124 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 445:
#line 4130 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 446:
#line 4136 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 447:
#line 4142 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 448:
#line 4148 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 449:
#line 4160 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 450:
#line 4171 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL);
		;}
    break;

  case 451:
#line 4177 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
									NULL);
		;}
    break;

  case 452:
#line 4183 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 453:
#line 4189 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 454:
#line 4195 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 455:
#line 4202 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 456:
#line 4209 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 457:
#line 4222 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 458:
#line 4243 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 459:
#line 4250 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 460:
#line 4270 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 461:
#line 4310 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 462:
#line 4315 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 463:
#line 4318 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 464:
#line 4326 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 465:
#line 4332 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 466:
#line 4338 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 467:
#line 4344 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 468:
#line 4350 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 469:
#line 4357 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 470:
#line 4363 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 471:
#line 4369 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 472:
#line 4375 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 473:
#line 4381 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 474:
#line 4393 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 475:
#line 4398 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 476:
#line 4408 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 477:
#line 4414 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 478:
#line 4426 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 479:
#line 4452 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 480:
#line 4463 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 481:
#line 4469 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 482:
#line 4482 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 483:
#line 4496 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 484:
#line 4503 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 485:
#line 4510 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 486:
#line 4521 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 487:
#line 4528 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 488:
#line 4536 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 489:
#line 4545 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(14) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (9)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (12)].sval)),
                          (yysemantic_stack_[(14) - (14)].expr));
    ;}
    break;

  case 491:
#line 4561 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
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

  case 492:
#line 4578 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 493:
#line 4579 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty"); ;}
    break;

  case 494:
#line 4580 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("attribute"); ;}
    break;

  case 495:
#line 4581 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("comment"); ;}
    break;

  case 496:
#line 4582 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document-node"); ;}
    break;

  case 497:
#line 4583 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("element"); ;}
    break;

  case 498:
#line 4584 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("item"); ;}
    break;

  case 499:
#line 4585 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("if"); ;}
    break;

  case 500:
#line 4586 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("node"); ;}
    break;

  case 501:
#line 4587 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("processing-instruction"); ;}
    break;

  case 502:
#line 4588 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-attribute"); ;}
    break;

  case 503:
#line 4589 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-element"); ;}
    break;

  case 504:
#line 4590 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("text"); ;}
    break;

  case 505:
#line 4591 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("typeswitch"); ;}
    break;

  case 506:
#line 4592 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty-sequence"); ;}
    break;

  case 507:
#line 4593 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("boundary-space"); ;}
    break;

  case 508:
#line 4594 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ft-option"); ;}
    break;

  case 509:
#line 4595 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("base-uri"); ;}
    break;

  case 510:
#line 4596 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lax"); ;}
    break;

  case 511:
#line 4597 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strict"); ;}
    break;

  case 512:
#line 4598 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("idiv"); ;}
    break;

  case 513:
#line 4599 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document"); ;}
    break;

  case 514:
#line 4600 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("not"); ;}
    break;

  case 515:
#line 4601 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sensitive"); ;}
    break;

  case 516:
#line 4602 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insensitive"); ;}
    break;

  case 517:
#line 4603 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("diacritics"); ;}
    break;

  case 518:
#line 4604 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("without"); ;}
    break;

  case 519:
#line 4605 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stemming"); ;}
    break;

  case 520:
#line 4606 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("thesaurus"); ;}
    break;

  case 521:
#line 4607 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stop"); ;}
    break;

  case 522:
#line 4608 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("wildcards"); ;}
    break;

  case 523:
#line 4609 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("entire"); ;}
    break;

  case 524:
#line 4610 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("content"); ;}
    break;

  case 525:
#line 4611 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("word"); ;}
    break;

  case 526:
#line 4612 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("start"); ;}
    break;

  case 527:
#line 4613 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("end"); ;}
    break;

  case 528:
#line 4614 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("most"); ;}
    break;

  case 529:
#line 4615 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("skip"); ;}
    break;

  case 530:
#line 4616 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy"); ;}
    break;

  case 531:
#line 4617 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("value"); ;}
    break;

  case 532:
#line 4618 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("eq"); ;}
    break;

  case 533:
#line 4619 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ne"); ;}
    break;

  case 534:
#line 4620 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lt"); ;}
    break;

  case 535:
#line 4621 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("le"); ;}
    break;

  case 536:
#line 4622 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("gt"); ;}
    break;

  case 537:
#line 4623 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ge"); ;}
    break;

  case 538:
#line 4624 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("at"); ;}
    break;

  case 539:
#line 4625 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("variable"); ;}
    break;

  case 540:
#line 4626 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("return"); ;}
    break;

  case 541:
#line 4627 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("for"); ;}
    break;

  case 542:
#line 4628 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sliding"); ;}
    break;

  case 543:
#line 4629 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("tumbling"); ;}
    break;

  case 544:
#line 4630 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("previous"); ;}
    break;

  case 545:
#line 4631 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("next"); ;}
    break;

  case 546:
#line 4632 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("only"); ;}
    break;

  case 547:
#line 4633 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("when"); ;}
    break;

  case 548:
#line 4634 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("count"); ;}
    break;

  case 549:
#line 4635 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("in"); ;}
    break;

  case 550:
#line 4636 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("let"); ;}
    break;

  case 551:
#line 4637 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("where"); ;}
    break;

  case 552:
#line 4638 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("by"); ;}
    break;

  case 553:
#line 4639 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("order"); ;}
    break;

  case 554:
#line 4640 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stable"); ;}
    break;

  case 555:
#line 4641 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ascending"); ;}
    break;

  case 556:
#line 4642 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("descending"); ;}
    break;

  case 557:
#line 4643 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("greatest"); ;}
    break;

  case 558:
#line 4644 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("least"); ;}
    break;

  case 559:
#line 4645 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("collation"); ;}
    break;

  case 560:
#line 4646 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("some"); ;}
    break;

  case 561:
#line 4647 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("every"); ;}
    break;

  case 562:
#line 4648 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("satisfies"); ;}
    break;

  case 563:
#line 4649 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("case"); ;}
    break;

  case 564:
#line 4650 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("as"); ;}
    break;

  case 565:
#line 4651 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("then"); ;}
    break;

  case 566:
#line 4652 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("else"); ;}
    break;

  case 567:
#line 4653 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("or"); ;}
    break;

  case 568:
#line 4654 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("and"); ;}
    break;

  case 569:
#line 4655 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("instance"); ;}
    break;

  case 570:
#line 4656 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("of"); ;}
    break;

  case 571:
#line 4657 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("castable"); ;}
    break;

  case 572:
#line 4658 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("to"); ;}
    break;

  case 573:
#line 4659 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("div"); ;}
    break;

  case 574:
#line 4660 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("mod"); ;}
    break;

  case 575:
#line 4661 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("union"); ;}
    break;

  case 576:
#line 4662 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("intersect"); ;}
    break;

  case 577:
#line 4663 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("except"); ;}
    break;

  case 578:
#line 4664 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("validate"); ;}
    break;

  case 579:
#line 4665 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cast"); ;}
    break;

  case 580:
#line 4666 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("treat"); ;}
    break;

  case 581:
#line 4667 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("is"); ;}
    break;

  case 582:
#line 4668 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("preserve"); ;}
    break;

  case 583:
#line 4669 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strip"); ;}
    break;

  case 584:
#line 4670 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("namespace"); ;}
    break;

  case 585:
#line 4671 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("external"); ;}
    break;

  case 586:
#line 4672 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("encoding"); ;}
    break;

  case 587:
#line 4673 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-preserve"); ;}
    break;

  case 588:
#line 4674 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("inherit"); ;}
    break;

  case 589:
#line 4675 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-inherit"); ;}
    break;

  case 590:
#line 4676 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("declare"); ;}
    break;

  case 591:
#line 4677 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("construction"); ;}
    break;

  case 592:
#line 4678 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordering"); ;}
    break;

  case 593:
#line 4679 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("default"); ;}
    break;

  case 594:
#line 4680 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy-namespaces"); ;}
    break;

  case 595:
#line 4681 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("option"); ;}
    break;

  case 596:
#line 4682 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("version"); ;}
    break;

  case 597:
#line 4683 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("import"); ;}
    break;

  case 598:
#line 4684 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema"); ;}
    break;

  case 599:
#line 4685 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("function"); ;}
    break;

  case 600:
#line 4686 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("score"); ;}
    break;

  case 601:
#line 4687 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ftcontains"); ;}
    break;

  case 602:
#line 4688 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("weight"); ;}
    break;

  case 603:
#line 4689 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("window"); ;}
    break;

  case 604:
#line 4690 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("distance"); ;}
    break;

  case 605:
#line 4691 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("occurs"); ;}
    break;

  case 606:
#line 4692 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("times"); ;}
    break;

  case 607:
#line 4693 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("same"); ;}
    break;

  case 608:
#line 4694 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("different"); ;}
    break;

  case 609:
#line 4695 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lowercase"); ;}
    break;

  case 610:
#line 4696 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("uppercase"); ;}
    break;

  case 611:
#line 4697 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("relationship"); ;}
    break;

  case 612:
#line 4698 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("levels"); ;}
    break;

  case 613:
#line 4699 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("language"); ;}
    break;

  case 614:
#line 4700 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("any"); ;}
    break;

  case 615:
#line 4701 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("all"); ;}
    break;

  case 616:
#line 4702 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("phrase"); ;}
    break;

  case 617:
#line 4703 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exactly"); ;}
    break;

  case 618:
#line 4704 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("from"); ;}
    break;

  case 619:
#line 4705 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("words"); ;}
    break;

  case 620:
#line 4706 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentences"); ;}
    break;

  case 621:
#line 4707 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentence"); ;}
    break;

  case 622:
#line 4708 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("paragraph"); ;}
    break;

  case 623:
#line 4709 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("replace"); ;}
    break;

  case 624:
#line 4710 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("modify"); ;}
    break;

  case 625:
#line 4711 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("first"); ;}
    break;

  case 626:
#line 4712 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insert"); ;}
    break;

  case 627:
#line 4713 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("bofer"); ;}
    break;

  case 628:
#line 4714 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("after"); ;}
    break;

  case 629:
#line 4715 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("revalidation"); ;}
    break;

  case 630:
#line 4716 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("with"); ;}
    break;

  case 631:
#line 4717 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("nodes"); ;}
    break;

  case 632:
#line 4718 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("rename"); ;}
    break;

  case 633:
#line 4719 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("last"); ;}
    break;

  case 634:
#line 4720 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("delete"); ;}
    break;

  case 635:
#line 4721 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("into"); ;}
    break;

  case 636:
#line 4722 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("updating"); ;}
    break;

  case 637:
#line 4723 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordered"); ;}
    break;

  case 638:
#line 4724 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("unordered"); ;}
    break;

  case 639:
#line 4736 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 640:
#line 4742 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 641:
#line 4759 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 642:
#line 4763 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 643:
#line 4767 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 644:
#line 4771 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 645:
#line 4781 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 646:
#line 4784 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 647:
#line 4787 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 648:
#line 4790 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 649:
#line 4799 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 650:
#line 4802 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 651:
#line 4811 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 652:
#line 4814 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 653:
#line 4823 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 654:
#line 4826 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 655:
#line 4835 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 656:
#line 4838 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 657:
#line 4847 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 658:
#line 4850 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 659:
#line 4853 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 660:
#line 4862 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 661:
#line 4865 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 662:
#line 4874 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 663:
#line 4878 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, static_cast<Expr *> ((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 664:
#line 4888 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 665:
#line 4891 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 666:
#line 4894 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 667:
#line 4897 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 668:
#line 4900 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 669:
#line 4909 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 670:
#line 4918 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 671:
#line 4922 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 672:
#line 4926 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 673:
#line 4930 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 674:
#line 4934 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 675:
#line 4938 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 676:
#line 4942 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 677:
#line 4952 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 678:
#line 4955 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 679:
#line 4958 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 680:
#line 4961 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 681:
#line 4970 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 682:
#line 4973 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 683:
#line 4976 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 684:
#line 4979 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 685:
#line 4988 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 686:
#line 4991 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 687:
#line 5000 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 688:
#line 5003 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 689:
#line 5006 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 690:
#line 5009 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 691:
#line 5012 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 692:
#line 5015 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 693:
#line 5018 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 694:
#line 5027 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 695:
#line 5030 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 696:
#line 5039 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 697:
#line 5042 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 698:
#line 5045 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 699:
#line 5048 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 700:
#line 5057 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 701:
#line 5060 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 702:
#line 5063 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 703:
#line 5066 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 704:
#line 5069 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 705:
#line 5078 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 706:
#line 5081 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 707:
#line 5090 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 708:
#line 5093 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 709:
#line 5102 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 710:
#line 5105 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 711:
#line 5114 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 712:
#line 5117 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 713:
#line 5126 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 714:
#line 5135 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 715:
#line 5138 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 716:
#line 5147 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 717:
#line 5150 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 718:
#line 5153 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 719:
#line 5162 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 720:
#line 5165 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 721:
#line 5168 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 722:
#line 5171 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 723:
#line 5174 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 724:
#line 5183 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 725:
#line 5187 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 726:
#line 5191 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 727:
#line 5195 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 728:
#line 5205 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 729:
#line 5214 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 730:
#line 5224 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 731:
#line 5233 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 732:
#line 5236 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 733:
#line 5245 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 734:
#line 5248 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 735:
#line 5251 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 736:
#line 5260 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 737:
#line 5263 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 738:
#line 5272 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6456 "/usr/local/src/zorba_gflwor/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -919;
  const short int
  xquery_parser::yypact_[] =
  {
      1236,  -919,  -919,  -919,  -919,   -92,   135,   141,   320,   176,
    6202,    42,   474,   480,    66,  -919,  -919,   209,   120,  -919,
     495,   310,   134,   301,  -919,  -919,  -919,   390,  -919,   235,
     400,  -919,  -919,  -919,  -919,  -919,  -919,   454,  -919,   442,
    -919,   439,   475,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,  6443,  -919,  5469,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  7648,  -919,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,   500,  -919,  -919,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  4224,
    1485,  7648,  -919,  -919,  -919,  -919,  -919,  -919,   486,   479,
    -919,   481,  -919,   483,  -919,  5961,  -919,  -919,  -919,  -919,
    -919,  7648,  -919,  5220,  4971,  -919,  -919,  -919,  -919,  -919,
    -919,   510,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  4224,
      11,   485,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
     450,   516,   451,  -919,   482,   -77,  -919,  -919,  -919,  -919,
    -919,  -919,   585,  -919,   558,   586,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,  -919,   689,  1734,  -919,  -919,   546,  4224,   525,   532,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,  -919,   616,  -919,  -919,  -919,  -919,  -919,
    -919,   110,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
     560,   633,  -919,   593,   473,   -34,   277,   331,   192,  -919,
     640,   533,   627,   630,  4473,  -919,  -919,  -919,   188,  -919,
    -919,  -919,   464,  -919,   587,  5469,  -919,   587,  5469,  -919,
    -919,  -919,  -919,   587,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,  -919,   582,  -919,  4224,  -919,  4224,  4224,   589,   590,
     594,  4224,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,  4224,  6684,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,   596,  4224,  4224,   553,  4224,   559,  7648,
     690,   692,  7648,   418,   -54,   711,   410,   429,   634,   350,
     714,   446,    27,  4224,  -919,  4224,    69,   604,    38,    48,
    7648,   588,   714,  7648,  4224,   484,   487,  7648,   641,  7648,
    -919,  7648,    80,  4224,  6925,   610,   607,   608,   609,   611,
     612,  -919,  -919,  -919,  7648,  1983,   -16,  -919,     6,   720,
    4224,  4224,   649,    44,  -919,   734,   591,  -919,  -919,  4224,
    -919,   561,  -919,   731,  4224,  4224,   592,  4224,  4224,  4224,
    4224,   542,  7648,  4224,  7648,  -919,  -919,  -919,    66,   495,
    -919,  -919,   546,   718,  4224,   134,   390,   400,   454,   479,
    4224,  4224,  -919,  4722,  4722,  4722,  -919,  4722,  4722,  -919,
    4722,  -919,  4722,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    4722,  4722,     5,  4722,  4722,  4722,  4722,  4722,  4722,  4722,
    4722,  4722,  4722,  4722,   547,   683,   684,   685,  -919,  -919,
    -919,  2232,  -919,  4971,  4971,  4224,   587,  -919,  -919,   587,
    -919,   587,  2481,  -919,   597,   -13,  4224,  4224,  4224,    23,
      12,  -919,   106,   158,  2730,   183,   198,  -919,   205,  -919,
     628,  7648,  7648,   744,  -919,  -919,  -919,  -919,  -919,  -919,
     677,   679,  -919,  -919,  7648,   631,   632,   711,   663,   661,
    -919,  -919,  -919,   406,    73,   420,   753,  -919,  -919,   382,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,   159,   206,
     618,  -919,   619,  2979,   714,   696,   748,   714,   711,   707,
     -22,  -919,   150,  4224,   675,   698,  -919,    -4,   626,  -919,
    -919,   700,  -919,   -14,  7648,     3,  -919,   625,   607,   439,
    -919,   629,   635,   290,  -919,   199,   204,  3228,    10,  -919,
     -15,  -919,  -919,  7648,   720,  -919,   -30,   309,   471,   702,
    -919,  7648,    26,  -919,  -919,  -919,  -919,  -919,   321,  -919,
     147,  -919,  -919,  -919,    65,    93,   716,   576,   598,   -32,
    -919,   674,   636,    34,  -919,  -919,   637,  -919,     1,  -919,
    -919,  -919,   633,  -919,  -919,  -919,  -919,  -919,  4722,  -919,
    -919,  -919,  4224,     5,   341,  -919,   544,   312,   565,   566,
    -919,  -919,   563,   358,   277,   277,   -19,   331,   331,   331,
     331,   192,   192,  -919,  -919,  7407,  7407,  7648,  7648,  -919,
     322,  -919,  -919,   196,  -919,  -919,  -919,   208,   670,  -919,
     340,   345,   352,   725,   678,  7648,  -919,  7648,  -919,  -919,
     365,  -919,  -919,  -919,    -7,   416,   628,   628,  -919,   221,
     374,   387,   711,   711,  -919,   552,   711,  -919,  -919,   556,
    -919,  -919,   557,   227,  -919,  -919,  -919,  -919,  -919,  -919,
     562,  -919,  -919,   638,   681,  -919,  -919,  -919,   366,   697,
     711,   680,   709,   747,   711,   723,  4224,  7407,  4224,   701,
     702,   711,   729,  4224,   730,   710,   -52,  -919,   733,   735,
    4224,   -71,   708,   -44,   336,   606,  -919,  -919,    49,     3,
    -919,  -919,  -919,   704,  7648,  -919,  7648,  -919,  -919,   371,
    4224,  -919,   812,  -919,     7,  -919,    62,  -919,  -919,   711,
    -919,   554,  -919,   470,   750,  -919,  4224,   751,   649,  -919,
    -919,    25,  -919,   820,  -919,   430,  4224,  4224,  4224,   438,
    4224,  4224,  4224,  4224,  4224,  4224,   743,  4224,  4224,   624,
     713,   746,   718,  -919,   376,   682,  -919,   615,  -919,   -75,
    -919,   220,    -3,   617,     5,   220,  4722,  4722,   368,  -919,
    -919,  -919,  -919,  -919,  -919,  -919,     5,   724,    -3,  -919,
     595,   801,  -919,  -919,   717,   719,  -919,   -33,  -919,  -919,
    -919,  -919,  -919,   732,  -919,  -919,  -919,  4224,  -919,  -919,
    -919,  -919,  -919,  7166,   348,  -919,  3477,   688,   691,   736,
     693,   695,  -919,  7648,   781,   211,  -919,  -919,  4224,  -919,
     456,   670,  -919,  -919,  -919,  -919,  -919,  4224,   445,  -919,
    -919,  -919,  -919,  -919,   613,    22,   841,  -919,   423,  -919,
    -919,  4224,  3726,  -919,   711,   773,  -919,  -919,  -919,   711,
     773,  7648,  -919,  -919,  -919,  4224,   694,  7648,  -919,  7648,
    4224,  4224,   745,  7648,  7648,  -919,  4224,   740,  4224,  4224,
     -60,   742,  4224,   752,  -919,  4224,  7648,   605,   807,  -919,
    -919,  3975,   705,  -919,   706,  -919,  -919,  -919,   761,  -919,
      76,  -919,  -919,   867,  -919,  -919,  4224,  7648,  -919,  -919,
     317,  -919,  -919,  -919,  -919,  -919,  -919,   750,  -919,  -919,
    -919,   711,  -919,  -919,  -919,  -919,   712,   662,   665,  -919,
    -919,  -919,   666,   669,  -919,  -919,  -919,  -919,  -919,   659,
    7648,   721,  -919,   749,   624,  -919,  4224,  7648,  -919,  -919,
    4722,  -919,  -919,  -919,  -919,  -919,    43,  4722,  4722,   356,
    -919,   565,  -919,  -919,   238,  4722,  -919,  -919,   566,     5,
     639,  -919,  -919,   722,   727,  -919,  -919,  -919,  -919,  -919,
    -919,  7648,   726,   242,  -919,  -919,   384,  -919,  -919,  -919,
    -919,  -919,   810,  7407,   784,   813,   389,  -919,  -919,  -919,
    -919,  -919,  4224,   138,   873,   874,   138,    29,   243,   248,
     791,  -919,   392,   819,   711,   773,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,  4224,  -919,  -919,  -919,  4224,  -919,  -919,
    4224,   774,  4224,  -919,  4224,  -919,   822,   799,   802,  4224,
    -919,   398,  -919,  -919,   812,  7648,   343,  -919,   407,   812,
    7648,  -919,  -919,  -919,  -919,  4224,  4224,  4224,  4224,  4224,
    -919,  4224,  5718,  -919,   741,  -919,   331,  4722,  4722,   331,
     437,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,   826,  4224,  7648,  4224,  -919,  -919,  -919,  -919,  7407,
    -919,  -919,    22,    22,   138,  -919,  -919,  -919,    78,   138,
     884,   667,   827,  -919,   827,  -919,  4224,  -919,   711,  -919,
    -919,  -919,  -919,  4224,  -919,  -919,  -919,  7648,  7648,  -919,
    -919,    -9,   812,  7648,  -919,   738,   812,  -919,  -919,  -919,
    -919,  -919,  -919,   249,  -919,   331,   331,  4722,  7407,  -919,
     755,  -919,  -919,  -919,  -919,  -919,  -919,  -919,    -3,  -919,
     251,  -919,   253,  -919,   773,  -919,   848,  -919,   177,   362,
    -919,   739,   812,  -919,   754,   809,   778,   331,   757,  4224,
     671,   827,  -919,  -919,   816,  -919,  -919,   836,   295,  -919,
    -919,  -919,  -919,   756,   469,  -919,  -919,  -919,   758,  -919,
    7648,  -919,  4224,  -919,  -919,  -919,  7648,  -919,  -919,  -919,
    -919,  -919,  -919,  -919,   257,  -919,  -919,   817,   778,  7648,
    -919,   267,   823,   778,  7648,  -919,   762,   778,  -919
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   313,   314,   492,   460,     0,     0,     0,   578,   505,
     497,   513,   504,   495,   590,   599,   636,   499,   501,   528,
     597,   560,   554,     0,   595,   525,   598,   550,   591,     0,
     541,   542,   543,   544,   545,   546,   547,   548,   592,     0,
     509,   503,   496,   594,   569,   502,   507,   304,   307,   568,
     564,   555,   538,   494,   294,     0,   563,   571,   579,   292,
     559,   330,   539,   593,   293,   296,   556,   573,     0,   336,
     302,   332,   566,   493,   557,   558,   586,   561,   577,   585,
     298,   297,   512,   549,   588,   331,   576,   581,   498,     0,
       0,     0,   252,   574,   584,   589,   587,   567,   637,   553,
     552,     0,   303,     0,   251,     0,   306,   305,   582,   540,
     562,     0,   295,   277,     0,   312,   583,   565,   572,   580,
     575,   638,   532,   537,   536,   535,   534,   533,   506,   551,
       0,     0,   596,   526,   628,   627,   629,   511,   510,   529,
     634,   500,   626,   631,   632,   623,   531,   570,   625,   635,
     633,   624,   530,   630,     0,     0,   615,   614,   515,   508,
     517,   516,   608,   604,   523,   527,   524,   617,   618,   601,
     514,   613,   612,   609,   605,   622,   616,   611,   607,   600,
     621,   620,   606,   610,   602,   603,   518,   519,   521,   619,
     520,   522,     0,     0,     2,     4,     0,     0,     0,     0,
      15,    17,    19,    20,    21,    27,    22,    25,    26,    31,
      32,    33,    28,    29,    35,    36,    23,    30,   112,   109,
     110,   111,    24,     9,    94,    95,    97,   126,   131,   127,
     132,     0,   124,   125,   128,   130,   129,    98,    99,   100,
     101,   208,   210,   212,   222,   225,   227,   230,   235,   238,
     241,   243,   245,   247,     0,   249,   255,   257,     0,   273,
     256,   280,   281,   284,   286,     0,   291,   288,     0,   299,
     309,   311,   285,   315,   320,   328,   321,   322,   323,   326,
     327,   324,   325,   343,   345,   346,   347,   344,   392,   393,
     394,   395,   396,   397,   308,   434,   426,   433,   432,   431,
     428,   430,   427,   429,   329,    34,   102,   103,   105,   104,
     106,   107,   310,   108,     0,    81,     0,     0,     0,     0,
       0,     0,   578,   505,   497,   513,   504,   495,   590,   499,
     501,   597,   560,   554,   550,   541,   548,   503,   496,   494,
     561,     0,     0,   637,   553,   638,   551,   634,   500,   626,
     632,   623,   530,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,   497,   504,   495,   501,
     494,   300,   310,   333,     0,     0,     0,   334,     0,   359,
       0,     0,     0,     0,   276,     0,     0,   278,   279,     0,
     165,     0,   388,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     3,     5,     0,     0,
      10,     8,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,   133,     0,     0,     0,   266,     0,     0,   264,
       0,   217,     0,   265,   258,   263,   262,   261,   260,   259,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   253,
     250,     0,   274,     0,     0,     0,   287,   317,   290,   289,
     301,   316,     0,    79,     0,     0,     0,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,   439,     0,   440,
       0,     0,     0,     0,    70,    71,    44,    45,   490,    53,
       0,     0,    38,    39,     0,     0,     0,     0,     0,     0,
     461,   462,   463,     0,     0,     0,     0,   677,   678,     0,
      43,   670,   671,   672,   673,   674,   675,   676,     0,     0,
       0,   441,     0,     0,     0,    62,     0,     0,     0,    54,
       0,   197,     0,     0,     0,   147,   148,     0,     0,   114,
     115,   134,   135,     0,     0,     0,   123,     0,     0,     0,
     436,     0,     0,     0,   444,     0,     0,     0,     0,    76,
       0,    77,   335,   360,   359,   356,     0,     0,   181,   177,
     179,     0,   166,   170,   390,   389,   275,   449,     0,   387,
       0,   474,   475,   435,     0,     0,     0,     0,     0,     0,
     480,     0,     0,     0,   150,   164,     0,    16,     0,    18,
      96,   113,   209,   211,   215,   221,   220,   219,     0,   216,
     213,   214,     0,     0,     0,   662,   223,   641,   649,   651,
     653,   655,   657,   660,   229,   228,   226,   232,   233,   234,
     231,   236,   237,   240,   239,     0,     0,     0,     0,   271,
       0,   282,   283,     0,   318,   339,   341,     0,     0,   267,
       0,     0,     0,     0,     0,     0,   454,     0,   451,   399,
       0,   398,   407,   408,     0,     0,     0,     0,    42,     0,
       0,     0,     0,     0,    52,     0,     0,   679,   680,     0,
     681,   685,     0,     0,   714,   683,   684,   713,   682,   686,
       0,   693,   715,     0,     0,   443,   442,   409,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
     178,     0,     0,     0,     0,     0,     0,   640,     0,     0,
       0,     0,     0,     0,     0,     0,   116,   117,     0,   122,
     457,   437,   438,     0,     0,   447,     0,   445,   403,     0,
       0,    78,   359,   357,     0,   348,     0,   337,   190,     0,
     191,     0,   182,   183,   184,   185,     0,   172,     0,   175,
     168,   167,   338,     0,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,   218,     0,     0,   656,     0,   224,     0,
     669,     0,     0,     0,     0,     0,     0,     0,   642,   646,
     664,   645,   668,   666,   665,   667,     0,     0,     0,   658,
     721,   719,   723,   661,   498,   506,   242,   416,   422,   423,
     425,   244,   246,   413,   248,   272,   319,     0,   340,    80,
     268,   269,   270,     0,     0,   203,     0,     0,     0,   458,
       0,     0,   400,     0,    72,     0,    88,    83,     0,    84,
       0,     0,    50,    51,    48,    49,    67,     0,     0,    40,
      41,    46,    47,    37,     0,     0,     0,   688,     0,   687,
     704,     0,     0,   410,     0,    64,    58,    61,    60,     0,
      56,     0,   195,   415,   199,     0,     0,     0,   152,     0,
       0,     0,     0,     0,     0,   137,     0,     0,     0,     0,
       0,     0,     0,     0,   118,     0,     0,   163,     0,   158,
     121,     0,     0,   458,     0,   404,   196,   360,     0,   349,
       0,   383,   380,     0,   384,   385,     0,     0,   386,   379,
       0,   354,   382,   381,   194,   192,   193,   186,   187,   188,
     180,     0,   173,   171,   176,   169,     0,     0,     0,   467,
     468,   464,     0,     0,   472,   473,   469,   478,   476,     0,
       0,     0,   482,     0,   483,   484,     0,     0,   663,   659,
       0,   716,   717,   737,   736,   732,     0,     0,     0,     0,
     718,   650,   731,   643,     0,     0,   648,   647,   652,     0,
       0,   722,   720,     0,     0,   419,   421,   420,   417,   414,
     342,     0,     0,     0,   204,   401,     0,   455,   456,   459,
     452,   453,    90,     0,     0,    73,     0,    85,    86,    87,
      66,    69,     0,   702,     0,     0,   700,   696,     0,     0,
       0,   411,     0,    63,     0,    57,   198,   200,    11,   149,
     146,   154,   153,     0,   136,   145,   139,     0,   141,   138,
       0,     0,     0,   156,     0,   120,     0,     0,     0,     0,
     405,     0,   448,   446,   359,     0,     0,   391,     0,   359,
       0,   355,   189,   174,     7,     0,     0,     0,     0,     0,
     481,     0,     0,   485,     0,   151,   738,     0,     0,   724,
       0,   735,   734,   733,   728,   729,   644,   654,   730,   424,
     418,     0,     0,     0,     0,   402,    91,    74,    89,     0,
      93,    68,     0,     0,   703,   705,   707,   709,     0,   701,
       0,     0,     0,   691,     0,   689,     0,   412,     0,    59,
     155,   143,   140,     0,   142,   157,   159,     0,     0,   119,
     406,     0,   359,     0,    92,     0,   359,   465,   466,   470,
     471,   477,   479,     0,   639,   726,   725,     0,     0,   205,
       0,   201,    75,   712,   711,   706,   710,   708,   697,   698,
       0,   694,     0,   207,    65,   144,   162,   161,   369,   363,
     358,     0,   359,   350,     0,     0,     0,   727,     0,     0,
       0,     0,   692,   690,     0,   377,   371,     0,   370,   372,
     378,   375,   365,     0,   364,   366,   376,   352,     0,   351,
       0,   486,     0,   202,   699,   695,     0,   362,   373,   374,
     361,   367,   368,   353,     0,   206,   160,     0,     0,     0,
     487,     0,     0,     0,     0,   488,     0,     0,   489
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -919,  -919,  -919,   737,   759,  -919,   760,  -919,   489,   491,
    -418,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,  -919,  -730,  -919,  -919,  -919,  -919,   -37,
    -661,  -919,  -919,  -919,  -919,  -919,  -919,  -132,  -919,  -878,
     728,   -72,  -116,  -919,  -919,  -919,   160,  -919,  -919,  -919,
     703,  -919,  -919,  -919,    -6,  -541,  -549,  -584,  -919,  -919,
       8,  -919,  -919,  -159,   -69,  -582,  -919,  -919,   142,  -919,
    -919,  -919,   369,   143,  -919,  -919,   148,  -739,  -919,   539,
      24,  -919,  -919,    70,  -919,  -919,   494,   496,  -919,  -411,
    -804,   476,   200,  -475,   191,   193,  -919,  -919,  -919,  -919,
    -919,   699,  -919,  -919,  -919,  -919,  -919,   715,  -919,   -91,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,   -29,  -174,  -919,
    -919,  -144,   125,  -919,  -463,  -919,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,  -919,  -750,  -919,   -11,  -919,   351,  -599,
    -919,  -919,  -919,  -919,  -919,  -290,  -280,  -918,  -715,  -919,
    -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,  -919,   281,
    -562,  -665,  -919,  -919,     0,  -668,  -919,  -919,  -919,  -919,
    -919,  -919,  -919,   568,   569,  -607,   265,  -919,  -919,  -919,
    -919,  -919,  -919,  -919,  -919,   -36,  -919,  -919,   -41,  -359,
    -341,   -10,  -919,   313,  -919,  -919,   131,   122,   -59,   315,
    -919,  -919,   137,  -919,  -620,  -919,  -919,  -919,  -919,  -192,
    -713,  -919,   -89,  -471,  -919,  -569,  -919,  -919,  -919,  -919,
    -832,  -919,  -919,  -919,  -919,   -45,   145,  -919
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   915,   568,   215,   216,   217,   705,
     218,   405,   219,   220,   221,   222,   885,   886,   968,   889,
     223,   224,   225,   226,   388,   768,   769,   227,   228,   229,
     230,   231,   232,   581,   582,   947,   755,   233,   575,   633,
     576,   585,   948,   949,   634,   234,   235,   612,   613,   982,
     801,   236,   609,   610,   792,   793,   794,   795,   237,   570,
     571,   238,   874,   875,   239,   240,   241,   242,   648,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   470,   471,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   496,   497,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   687,   282,   283,   284,   970,   604,   605,   606,
    1220,  1243,  1244,  1237,  1238,  1245,  1239,   971,   972,   285,
     286,   973,   287,   288,   289,   290,   291,   292,   293,   862,
     749,   856,  1038,   857,   858,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   877,   878,   304,   305,   306,
     307,   308,   309,   310,   629,   630,   311,  1004,  1005,   916,
     377,   312,   313,   656,   838,   657,   658,   659,   660,   661,
     662,   663,   839,   840,   550,   551,   552,   553,   554,  1210,
    1211,   555,  1154,  1066,  1158,  1155,   556,   557,   842,   853,
    1019,   843,   844,   849,   845,  1134,  1015,   828
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       353,   667,   668,   669,   670,   784,   529,   859,   859,   655,
     909,   861,  1058,   420,   920,   756,  1030,   406,   408,   565,
     569,   763,   417,   418,     4,   639,   401,   869,   799,   539,
     800,   421,  1023,   759,   762,   562,   969,   841,   359,   360,
     361,   574,   761,   395,   644,   402,   645,   646,   362,   647,
     614,   649,  1111,   936,   978,   979,   816,   528,   403,   650,
     651,   747,   765,   759,  1090,  1218,   745,   528,   931,   961,
     962,   747,   444,   444,  1016,   444,   446,   446,   785,   859,
     939,   409,   923,   961,   962,  1127,   374,   820,   560,  1035,
     880,   883,   526,   368,   444,   415,    61,  1206,   745,  1064,
     444,   416,   473,   359,   360,   361,  1016,    71,   543,   945,
     760,   444,   588,   362,   798,   959,   753,   473,   363,   474,
    1036,  1011,   821,   499,   314,   527,   759,   430,   364,   501,
     365,    85,   431,   366,   474,   652,   367,   374,  1037,   653,
     805,   566,   475,   746,   786,   589,   963,   946,   689,   898,
    1128,  1219,   601,   781,  1012,   445,  1065,   884,   368,   369,
     963,   446,   315,   964,   447,   965,   719,   952,   809,   954,
     602,   448,   354,   694,   754,   780,   564,   964,   714,   965,
    1235,   960,   817,   958,   961,   754,   567,   693,  1111,  1075,
     655,   655,   966,   754,   695,  1069,   615,    91,   503,   766,
     504,   754,   943,   422,   370,   859,   966,   932,  1042,   743,
     969,    91,   937,   103,   941,   451,   451,   984,  1027,   985,
     969,  1136,   940,   739,   372,   747,   742,   103,  1017,  1018,
    1059,   754,   767,   561,   967,  1161,   498,   823,  1112,   500,
     654,   754,  1207,   544,   590,   505,   697,   444,  1105,   509,
     375,   545,  1152,   130,   376,   402,   803,   449,   402,   101,
    1017,  1018,   806,   807,   546,   371,   547,   130,   578,   510,
     696,   444,  1160,   450,   748,   316,   548,   808,   964,   549,
     965,   381,   515,   516,   444,   518,   444,   774,  1236,   372,
     810,   811,   776,   444,   444,   608,   867,   720,  1235,  1054,
     451,   558,   961,   559,   906,   812,   482,   966,   621,   622,
     321,   624,   625,   626,   627,   804,  1153,   632,   491,   483,
     907,   593,   698,   733,   961,   962,   721,   722,   640,   723,
     724,  1162,   513,   600,   641,   420,  1164,  1225,   607,  1231,
    1143,  1231,   105,   373,   701,  1267,   892,   618,  1251,   520,
     961,   962,   523,   899,   900,  1272,   969,   903,   866,   702,
       4,   908,  1024,   775,   893,   384,   703,   734,   777,   961,
     572,   655,   868,   577,   476,  1055,  1230,   583,   444,   586,
    1241,   587,   535,   655,   596,   859,   686,   536,  1147,   829,
    1270,  1091,   926,   543,   572,  1275,   964,   444,   965,  1278,
     477,   963,   681,   682,   639,  1144,  1258,  1163,   380,   444,
     444,   747,  1165,  1226,   478,  1232,   480,  1233,   964,   680,
     965,  1268,   631,   683,   635,   966,   481,   963,   444,   873,
     974,  1273,    61,   444,   690,   691,   692,   537,  1214,   382,
     444,  1043,   700,    71,   964,   829,   965,   966,   479,   543,
     317,   773,    91,   444,   444,   385,   386,   608,   830,   444,
     942,  1013,   747,   964,   444,   965,  1014,    85,   103,   390,
     787,   652,   444,   966,  1242,   653,   961,   444,    91,  1131,
     444,   859,   802,   865,  1202,  1132,   444,  1241,   383,  1110,
    1146,   738,   966,  1133,   103,   444,   413,   538,   387,   894,
     906,   870,   896,  1240,  1246,  1181,   871,   897,   130,   480,
    1185,   706,   707,   872,   830,  1183,  1068,   895,  1255,   481,
     318,   319,   320,  1240,   711,   779,   882,   913,   544,  1246,
     859,   887,   955,  1228,   130,  1126,   545,  1008,   831,   832,
     833,   378,  1129,  1130,   379,  1145,   888,   788,   834,   546,
    1150,   547,   389,  1167,   530,  1073,   835,   789,   789,  1180,
    1061,   548,   836,   837,   549,  1062,   655,   790,  1184,   531,
     964,  1057,   965,   391,   764,   791,   791,   524,   850,   851,
     824,  1261,   438,  1221,   544,  1205,   888,  1224,   532,   439,
    1205,   525,   545,   782,   831,   832,   833,  1131,   404,   966,
     852,   797,   533,  1132,   355,   546,   728,   547,   356,   392,
     357,  1133,   835,  1197,   358,   480,   410,   548,  1025,   837,
     549,   684,  1113,  1248,   684,   481,   684,   411,   717,   412,
     922,   718,   924,   493,   494,   729,   730,   928,   731,   732,
     419,   987,   725,   988,   935,   726,   540,   541,   542,   992,
     426,   993,  1195,  1196,   424,   427,   425,   428,   901,   902,
     975,   976,  1097,  1098,   956,   860,   860,   860,   860,   890,
     891,   671,   672,   664,   665,   673,   674,   863,   863,   423,
     608,  1203,  1204,   432,   434,   879,   429,   879,   433,   435,
     989,   990,   991,   442,   994,   995,   996,   997,   998,   999,
     443,  1001,  1002,   455,   444,   453,   454,   472,   484,   486,
     485,   456,   457,   487,   458,  1169,   502,   517,   495,   506,
     507,   459,  1227,   519,   508,   460,   514,   521,   461,   522,
     528,   374,   534,   462,   563,   579,   573,   860,   580,   584,
     597,   342,   356,   358,   603,   376,   394,   611,   616,   463,
     620,  1040,   628,   619,   638,   617,   623,   675,   676,   677,
     678,   688,   704,   708,   953,   709,   953,   710,   715,   712,
     713,   716,   727,   740,   464,   465,   466,   467,   468,   469,
     741,  1060,   735,   736,   744,   751,   752,   757,   758,   770,
     796,   813,   814,   771,   818,  1070,   827,   819,   846,   772,
      89,   847,   815,   848,  1046,   822,   873,   914,   876,  1077,
     904,   912,   905,   911,  1081,  1082,  1056,   910,   917,   918,
    1086,   921,  1088,  1089,   919,   925,  1093,   927,   929,  1095,
     930,   933,   938,   934,   951,   944,   957,   789,   981,   986,
    1072,  1000,  1003,  1006,  1007,  1010,  1009,  1020,  1029,  1032,
    1031,  1033,  1047,  1034,  1039,  1048,  1053,  1050,  1049,  1051,
    1067,  1074,  1078,   860,  1087,  1083,  1092,  1099,  1063,  1102,
    1103,  1104,  1107,  1052,  1115,  1119,  1094,  1116,  1117,  1101,
    1114,  1118,   883,  1122,  1121,   747,  1139,  1138,  1149,  1142,
    1124,  1140,  1156,  1157,  1108,  1166,  1168,  1177,  1173,   759,
    1178,  1198,  1194,  1208,   906,  1209,  1234,  1250,   888,  1254,
    1257,   572,  1223,  1247,  1256,  1269,  1260,   577,  1229,  1080,
    1252,  1274,  1148,   583,  1085,   441,  1277,  1084,  1249,   950,
     436,   636,  1263,   637,   452,  1079,  1096,  1176,  1125,   980,
     983,   977,   750,   598,  1044,  1076,  1151,   642,  1193,  1106,
     643,   666,   437,   490,  1262,   783,   440,  1109,  1259,   864,
     591,   592,   881,  1123,  1120,  1021,   825,  1170,  1028,   826,
    1137,  1171,  1212,   492,  1172,  1026,  1174,  1159,  1175,  1135,
    1022,     0,     0,  1179,     0,     0,     0,     0,     0,     0,
     631,     0,     0,     0,     0,     0,     0,   635,     0,  1187,
    1188,  1189,  1190,  1191,     0,  1192,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1199,     0,  1201,     0,
       0,  1141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   860,     0,     0,     0,     0,     0,     0,
    1213,     0,     0,     0,     0,     0,     0,  1215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1182,     0,     0,     0,     0,
    1186,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   402,  1253,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1200,     0,     0,  1265,     0,     0,   860,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1216,  1217,     0,
       0,     0,     0,  1222,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   860,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1264,     0,     0,     0,     0,     1,  1266,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,  1271,
       0,     5,     6,     0,  1276,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
       0,     0,    59,    60,     0,     0,     0,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    71,     0,
      72,    73,    74,    75,     0,    76,     0,     0,     0,    77,
      78,    79,    80,    81,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      90,    91,    92,    93,    94,     0,     0,     0,     0,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   104,
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
      13,   328,    15,    16,     0,    17,    18,    19,   331,    21,
      22,     0,    24,    25,    26,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     0,
       0,    59,    60,     0,     0,     0,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,     0,    72,
      73,    74,    75,     0,    76,     0,     0,     0,    77,    78,
      79,    80,    81,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    90,
      91,    92,    93,    94,     0,     0,     0,     0,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,   104,   105,
       0,     0,   106,   107,   108,     0,     0,     0,   109,   407,
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
      42,    43,    44,    45,    46,    47,    48,    49,     0,    50,
      51,    52,    53,    54,    55,    56,    57,    58,     0,     0,
      59,    60,     0,     0,     0,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,     0,    72,    73,
      74,    75,     0,    76,     0,     0,     0,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,    91,
      92,    93,    94,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   104,   105,     0,
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
       0,     0,     7,     8,     9,    10,    11,    12,    13,   328,
      15,    16,     0,    17,    18,    19,   331,    21,    22,     0,
      24,    25,    26,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     0,     0,    59,
      60,     0,     0,     0,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    71,     0,    72,    73,    74,
      75,     0,    76,     0,     0,     0,    77,    78,    79,    80,
      81,     0,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    90,    91,    92,
      93,    94,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   104,   105,     0,     0,
     106,   107,   108,     0,   599,     0,   109,     0,   110,   111,
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
       0,     7,     8,     9,    10,    11,    12,    13,   328,    15,
      16,     0,    17,    18,    19,   331,    21,    22,     0,    24,
      25,    26,     0,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,     0,     0,    59,    60,
       0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,    71,     0,    72,    73,    74,    75,
       0,    76,     0,     0,     0,    77,    78,    79,    80,    81,
       0,     0,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    90,    91,    92,    93,
      94,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,   104,   105,     0,     0,   106,
     107,   108,     0,   679,     0,   109,     0,   110,   111,   112,
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
       7,     8,     9,    10,    11,    12,    13,   328,    15,    16,
       0,    17,    18,    19,   331,    21,    22,     0,    24,    25,
      26,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     0,     0,    59,    60,     0,
       0,     0,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,     0,    72,    73,    74,    75,     0,
      76,     0,     0,     0,    77,    78,    79,    80,    81,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,    90,    91,    92,    93,    94,
       0,     0,     0,     0,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,   104,   105,     0,     0,   106,   107,
     108,     0,     0,     0,   109,   685,   110,   111,   112,     0,
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
       8,     9,    10,    11,    12,    13,   328,    15,    16,     0,
      17,    18,    19,   331,    21,    22,     0,    24,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,     0,    50,    51,    52,    53,    54,
      55,    56,    57,    58,     0,     0,    59,    60,     0,     0,
       0,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,    71,     0,    72,    73,    74,    75,     0,    76,
       0,     0,     0,    77,    78,    79,    80,    81,     0,     0,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,    90,    91,    92,    93,    94,     0,
       0,     0,     0,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,   104,   105,     0,     0,   106,   107,   108,
       0,   699,     0,   109,     0,   110,   111,   112,     0,   113,
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
       9,    10,    11,    12,    13,   328,    15,    16,     0,    17,
      18,    19,   331,    21,    22,     0,    24,    25,    26,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,     0,     0,    59,    60,     0,     0,     0,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,     0,    72,    73,    74,    75,     0,    76,     0,
       0,     0,    77,    78,    79,    80,    81,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,    90,    91,    92,    93,    94,     0,     0,
       0,     0,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,     0,     0,   106,   107,   108,     0,
     737,     0,   109,     0,   110,   111,   112,     0,   113,   114,
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
      10,    11,    12,    13,   328,    15,    16,     0,    17,    18,
      19,   331,    21,    22,     0,    24,    25,    26,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     0,    50,    51,    52,    53,    54,    55,    56,
      57,    58,     0,     0,    59,    60,     0,     0,     0,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,     0,    72,    73,    74,    75,     0,    76,     0,     0,
       0,    77,    78,    79,    80,    81,     0,     0,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,    91,    92,    93,    94,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,   104,   105,     0,     0,   106,   107,   108,     0,   778,
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
      11,    12,    13,   328,    15,    16,     0,    17,    18,    19,
     331,    21,    22,     0,    24,    25,    26,     0,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     0,     0,    59,    60,     0,     0,     0,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
       0,    72,    73,    74,    75,     0,    76,     0,     0,     0,
      77,    78,    79,    80,    81,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,    90,    91,    92,    93,    94,     0,     0,     0,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     104,   105,     0,     0,   106,   107,   108,     0,  1045,     0,
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
      12,    13,   328,    15,    16,     0,    17,    18,    19,   331,
      21,    22,     0,    24,    25,    26,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
       0,     0,    59,    60,     0,     0,     0,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    71,     0,
      72,    73,    74,    75,     0,    76,     0,     0,     0,    77,
      78,    79,    80,    81,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      90,    91,    92,    93,    94,     0,     0,     0,     0,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   104,
     105,     0,     0,   106,   107,   108,     0,  1071,     0,   109,
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
      13,   328,    15,    16,     0,    17,    18,    19,   331,    21,
      22,     0,    24,    25,    26,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     0,
       0,    59,    60,     0,     0,     0,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,     0,    72,
      73,    74,    75,     0,    76,     0,     0,     0,    77,    78,
      79,    80,    81,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    90,
      91,    92,    93,    94,     0,     0,     0,     0,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,   104,   105,
       0,     0,   106,   107,   108,     0,  1100,     0,   109,     0,
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
     328,    15,    16,     0,    17,    18,    19,   331,    21,    22,
       0,    24,    25,    26,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,     0,    50,
      51,    52,    53,    54,    55,    56,    57,    58,     0,     0,
      59,    60,     0,     0,     0,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,     0,    72,    73,
      74,    75,     0,    76,     0,     0,     0,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,    91,
      92,    93,    94,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   104,   105,     0,
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
       0,     0,     0,     8,   323,    10,    11,    12,    13,   328,
      15,    16,     0,   329,    18,    19,   331,   332,   333,     0,
      24,    25,    26,     0,   334,    28,     0,   335,    31,    32,
      33,    34,    35,    36,   336,    38,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     0,     0,    59,
      60,     0,     0,     0,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    71,     0,    72,    73,    74,
      75,     0,    76,     0,     0,     0,   340,    78,    79,    80,
      81,     0,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,    90,    91,   488,
      93,    94,     0,     0,     0,     0,    95,    96,    97,    98,
     344,   100,     0,   102,   103,     0,   489,   105,     0,     0,
     106,   107,   108,     0,     0,     0,   109,     0,   110,   111,
     112,     0,   113,   114,   115,     0,   116,     0,   117,   118,
     119,   120,   121,     0,   122,   123,   124,   125,   126,   127,
       0,     0,   128,   346,   130,     0,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   347,   141,   349,   143,
     350,   351,   146,   147,   148,   149,   150,   151,   352,   153,
       0,     0,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,   169,   170,     0,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,   323,    10,    11,    12,    13,   328,    15,
      16,     0,   329,    18,    19,   331,   332,   333,     0,    24,
      25,    26,     0,   334,    28,     0,   335,    31,    32,    33,
      34,    35,    36,   336,    38,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,     0,     0,    59,    60,
       0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,    71,     0,    72,    73,    74,    75,
       0,    76,     0,     0,     0,   340,    78,    79,    80,    81,
       0,     0,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,    90,    91,    92,    93,
      94,     0,     0,     0,     0,    95,    96,    97,    98,   344,
     100,     0,   102,   103,     0,   104,   105,     0,     0,   106,
     107,   108,     0,     0,     0,   109,     0,   110,   111,   112,
       0,   113,   114,   115,     0,   116,     0,   117,   118,   119,
     120,   121,     0,   122,   123,   124,   125,   126,   127,     0,
       0,   128,   346,   130,     0,     0,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   347,   141,   349,   143,   350,
     351,   146,   147,   148,   149,   150,   151,   352,   153,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,     0,   169,   170,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   322,   323,    10,    11,    12,    13,   328,    15,    16,
       0,   329,    18,    19,   331,   332,   333,     0,    24,    25,
      26,     0,   334,    28,     0,   335,    31,    32,    33,    34,
      35,    36,   336,    38,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     0,     0,    59,    60,     0,
       0,     0,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,     0,    72,    73,    74,    75,     0,
      76,     0,     0,     0,   340,    78,    79,    80,    81,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,     0,    90,    91,     0,    93,    94,
       0,     0,     0,     0,    95,    96,    97,    98,   344,   100,
       0,   102,   103,     0,     0,     0,     0,     0,   106,   107,
     108,     0,     0,     0,   109,     0,   110,   111,   112,     0,
       0,     0,   115,     0,   116,     0,   117,   118,   119,   120,
     121,     0,   122,   123,   124,   125,   126,   127,     0,     0,
     128,   346,   130,     0,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   347,   141,   349,   143,   350,   351,
     146,   147,   148,   149,   150,   151,   352,   153,     0,     0,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,     0,   169,   170,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     322,   323,    10,    11,    12,    13,   328,    15,    16,     0,
     329,    18,    19,   331,   332,   333,     0,    24,    25,    26,
       0,   334,    28,     0,   335,    31,    32,    33,    34,    35,
      36,   336,    38,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,     0,    50,    51,    52,    53,    54,
      55,    56,    57,    58,     0,     0,    59,    60,     0,     0,
       0,    61,    62,    63,    64,    65,    66,     0,    68,    69,
      70,     0,    71,     0,    72,    73,    74,    75,     0,    76,
       0,     0,     0,   340,     0,    79,    80,    81,     0,     0,
       0,     0,     0,     0,    83,    84,    85,     0,    87,    88,
       0,     0,     0,     0,    90,    91,     0,     0,    94,     0,
       0,     0,     0,    95,    96,    97,    98,   344,   100,     0,
     102,   103,     0,     0,     0,     0,     0,   106,   107,   108,
       0,     0,     0,   109,     0,   110,   111,   112,     0,     0,
       0,     0,     0,   116,     0,   117,     0,   119,     0,   121,
       0,   122,   123,   124,   125,   126,   127,     0,     0,   128,
     346,   130,     0,     0,   132,     0,   133,   134,   135,   136,
     137,   138,   139,   347,   141,   349,   143,   350,   351,   146,
     147,   148,   149,   150,   151,   352,   153,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,     0,     0,   170,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   322,
     323,   396,   325,   397,   398,   328,    15,    16,     0,   329,
     399,    19,   331,   332,   333,     0,    24,    25,    26,     0,
     334,    28,     0,   335,    31,    32,    33,    34,    35,    36,
     336,    38,     0,    40,    41,    42,    43,    44,    45,    46,
       0,     0,    49,     0,    50,    51,    52,   400,     0,     0,
      56,    57,    58,     0,     0,     0,    60,     0,     0,     0,
       0,    62,    63,     0,     0,    66,    67,     0,     0,     0,
       0,     0,     0,    72,    73,    74,    75,     0,    76,     0,
       0,     0,   340,    78,    79,     0,     0,     0,     0,     0,
       0,     0,    82,    83,    84,     0,    86,    87,    88,     0,
       0,     0,     0,     0,     0,     0,    93,    94,     0,     0,
       0,     0,    95,    96,    97,   343,   344,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,   109,     0,   110,   111,     0,     0,     0,     0,
     115,     0,   116,     0,   117,   118,   119,   120,   345,     0,
     122,   123,   124,   125,   126,   127,     0,     0,   128,   346,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   347,   141,   349,   143,   350,   351,   146,   147,
     148,   149,   150,   151,   352,   153,     0,     0,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,     0,   169,   170,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   322,   323,
     324,   325,   326,   327,   328,    15,    16,     0,   329,   330,
      19,   331,   332,   333,     0,    24,    25,    26,     0,   334,
      28,     0,   335,    31,    32,    33,    34,    35,    36,   336,
      38,     0,    40,   337,   338,    43,    44,    45,    46,     0,
       0,    49,     0,    50,    51,    52,   339,     0,     0,    56,
      57,    58,     0,     0,     0,    60,     0,     0,     0,     0,
      62,    63,     0,     0,    66,    67,     0,     0,     0,     0,
       0,     0,    72,    73,    74,    75,     0,    76,     0,     0,
       0,   340,    78,    79,     0,     0,     0,     0,     0,     0,
       0,    82,    83,    84,     0,    86,    87,    88,     0,     0,
       0,     0,     0,     0,     0,    93,    94,     0,     0,     0,
       0,    95,    96,    97,   343,   344,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,   109,     0,   110,     0,     0,     0,     0,     0,   115,
       0,   116,     0,   117,   118,   119,   120,   345,     0,   122,
     123,   124,   125,   126,   127,     0,     0,   128,   346,     0,
       0,     0,   132,     0,   133,   134,   135,   136,   137,   138,
     139,   347,   348,   349,   143,   350,   351,   146,   147,   148,
     149,   150,   151,   352,   153,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,     0,   169,   170,     0,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   414,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   322,   323,   324,   325,   326,   327,   328,    15,    16,
       0,   329,   330,    19,   331,   332,   333,     0,    24,    25,
      26,     0,   334,    28,     0,   335,    31,    32,    33,    34,
      35,    36,   336,    38,     0,    40,   337,   338,    43,    44,
      45,    46,     0,     0,    49,     0,    50,    51,    52,   339,
       0,     0,    56,    57,    58,     0,     0,     0,    60,     0,
       0,     0,     0,    62,    63,     0,     0,    66,    67,     0,
       0,     0,     0,     0,     0,    72,    73,    74,    75,     0,
      76,     0,     0,     0,   340,    78,    79,     0,     0,     0,
       0,     0,     0,     0,    82,    83,    84,     0,    86,    87,
      88,     0,     0,     0,     0,     0,     0,     0,    93,    94,
       0,     0,     0,     0,    95,    96,    97,   343,   344,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,   109,     0,   110,     0,     0,     0,
       0,     0,     0,     0,   116,     0,   117,   118,   119,   120,
     345,     0,   122,   123,   124,   125,   126,   127,     0,     0,
     128,   346,     0,     0,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   347,   348,   349,   143,   350,   351,
     146,   147,   148,   149,   150,   151,   352,   153,     0,     0,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,     0,   169,   170,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   322,   323,   324,   325,   326,   327,   328,    15,
      16,     0,   329,   330,    19,   331,   332,   333,     0,    24,
      25,    26,     0,   334,    28,     0,   335,    31,    32,    33,
      34,    35,    36,   336,    38,     0,    40,   337,   338,    43,
      44,    45,    46,     0,     0,    49,     0,    50,    51,    52,
     339,     0,     0,    56,    57,    58,     0,     0,     0,    60,
       0,     0,     0,     0,    62,    63,     0,     0,    66,    67,
       0,     0,     0,     0,     0,     0,    72,    73,    74,    75,
       0,    76,     0,     0,     0,   340,    78,    79,     0,     0,
       0,     0,     0,     0,     0,    82,    83,    84,     0,    86,
      87,    88,   341,     0,     0,     0,   342,     0,     0,    93,
      94,     0,     0,     0,     0,    95,    96,    97,   343,   344,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,     0,   109,     0,   110,     0,     0,
       0,     0,     0,     0,     0,   116,     0,   117,   118,   119,
     120,   345,     0,   122,   123,   124,   125,   126,   127,     0,
       0,   128,   346,     0,     0,     0,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   347,   348,   349,   143,   350,
     351,   146,   147,   148,   149,   150,   151,   352,   153,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,     0,   169,   170,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,   323,   324,   325,   326,   327,   328,
      15,    16,     0,   329,   330,    19,   331,   332,   333,     0,
      24,    25,    26,     0,   334,    28,     0,   335,    31,    32,
      33,    34,    35,    36,   336,    38,     0,    40,   337,   338,
      43,    44,    45,    46,     0,     0,    49,     0,    50,    51,
      52,   339,     0,     0,    56,    57,    58,     0,     0,     0,
      60,     0,     0,     0,     0,    62,    63,     0,     0,    66,
      67,     0,     0,     0,     0,     0,     0,    72,    73,    74,
      75,     0,    76,     0,     0,     0,   340,    78,    79,     0,
       0,     0,     0,     0,     0,     0,    82,    83,    84,     0,
      86,    87,    88,   393,     0,     0,     0,   394,     0,     0,
      93,    94,     0,     0,     0,     0,    95,    96,    97,   343,
     344,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,     0,   109,     0,   110,     0,
       0,     0,     0,     0,     0,     0,   116,     0,   117,   118,
     119,   120,   345,     0,   122,   123,   124,   125,   126,   127,
       0,     0,   128,   346,     0,     0,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   347,   348,   349,   143,
     350,   351,   146,   147,   148,   149,   150,   151,   352,   153,
       0,     0,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,   169,   170,     0,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   322,   323,   324,   325,   326,   327,
     328,    15,    16,     0,   329,   330,    19,   331,   332,   333,
       0,    24,    25,    26,     0,   334,    28,     0,   335,    31,
      32,    33,    34,    35,    36,   336,    38,     0,    40,   337,
     338,    43,    44,    45,    46,     0,     0,    49,     0,    50,
      51,    52,   339,     0,     0,    56,    57,    58,     0,     0,
       0,    60,     0,     0,     0,     0,    62,    63,     0,     0,
      66,    67,     0,     0,     0,     0,     0,     0,    72,    73,
      74,    75,     0,    76,     0,     0,     0,   340,    78,    79,
       0,     0,     0,     0,     0,     0,     0,    82,    83,    84,
       0,    86,    87,    88,     0,     0,     0,     0,     0,     0,
       0,    93,    94,     0,     0,     0,     0,    95,    96,    97,
     343,   344,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,     0,   109,   511,   110,
       0,     0,     0,     0,     0,   512,     0,   116,     0,   117,
     118,   119,   120,   345,     0,   122,   123,   124,   125,   126,
     127,     0,     0,   128,   346,     0,     0,     0,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   347,   348,   349,
     143,   350,   351,   146,   147,   148,   149,   150,   151,   352,
     153,     0,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,     0,   169,   170,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   322,   323,   324,   325,   326,
     327,   328,    15,    16,     0,   329,   330,    19,   331,   332,
     333,     0,    24,    25,    26,     0,   334,    28,     0,   335,
      31,    32,    33,    34,    35,    36,   336,    38,     0,    40,
     337,   338,    43,    44,    45,    46,     0,     0,    49,     0,
      50,    51,    52,   339,     0,     0,    56,    57,    58,     0,
       0,     0,    60,     0,     0,     0,     0,    62,    63,     0,
       0,    66,    67,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,     0,    76,     0,     0,     0,   340,    78,
      79,     0,     0,     0,     0,     0,     0,     0,    82,    83,
      84,     0,    86,    87,    88,     0,     0,     0,     0,     0,
       0,     0,    93,    94,     0,     0,     0,     0,    95,    96,
      97,   343,   344,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,   109,   594,
     110,     0,     0,     0,     0,     0,   595,     0,   116,     0,
     117,   118,   119,   120,   345,     0,   122,   123,   124,   125,
     126,   127,     0,     0,   128,   346,     0,     0,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   347,   348,
     349,   143,   350,   351,   146,   147,   148,   149,   150,   151,
     352,   153,     0,     0,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,     0,   169,
     170,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   322,   323,   396,   325,
     397,   398,   328,    15,    16,     0,   329,   399,    19,   331,
     332,   333,     0,    24,    25,    26,     0,   334,    28,     0,
     335,    31,    32,    33,    34,    35,    36,   336,    38,     0,
      40,    41,    42,    43,    44,    45,    46,     0,     0,    49,
       0,    50,    51,    52,   400,     0,     0,    56,    57,    58,
       0,     0,     0,    60,     0,     0,     0,     0,    62,    63,
       0,     0,    66,    67,  1041,     0,     0,     0,     0,     0,
      72,    73,    74,    75,     0,    76,     0,     0,     0,   340,
      78,    79,     0,     0,     0,     0,     0,     0,     0,    82,
      83,    84,     0,    86,    87,   854,     0,     0,     0,     0,
       0,     0,     0,    93,    94,     0,     0,     0,     0,    95,
      96,    97,   343,   344,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,   109,
       0,   110,   111,     0,     0,     0,     0,     0,     0,   116,
       0,   117,   118,   119,   120,   345,     0,   122,   123,   124,
     125,   126,   127,     0,     0,   855,   346,     0,     0,     0,
     132,     0,   133,   134,   135,   136,   137,   138,   139,   347,
     141,   349,   143,   350,   351,   146,   147,   148,   149,   150,
     151,   352,   153,     0,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,     0,
     169,   170,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   322,   323,   396,
     325,   397,   398,   328,    15,    16,     0,   329,   399,    19,
     331,   332,   333,     0,    24,    25,    26,     0,   334,    28,
       0,   335,    31,    32,    33,    34,    35,    36,   336,    38,
       0,    40,    41,    42,    43,    44,    45,    46,     0,     0,
      49,     0,    50,    51,    52,   400,     0,     0,    56,    57,
      58,     0,     0,     0,    60,     0,     0,     0,     0,    62,
      63,     0,     0,    66,    67,     0,     0,     0,     0,     0,
       0,    72,    73,    74,    75,     0,    76,     0,     0,     0,
     340,    78,    79,     0,     0,     0,     0,     0,     0,     0,
      82,    83,    84,     0,    86,    87,   854,     0,     0,     0,
       0,     0,     0,     0,    93,    94,     0,     0,     0,     0,
      95,    96,    97,   343,   344,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
     109,     0,   110,   111,     0,     0,     0,     0,     0,     0,
     116,     0,   117,   118,   119,   120,   345,     0,   122,   123,
     124,   125,   126,   127,     0,     0,   855,   346,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     347,   141,   349,   143,   350,   351,   146,   147,   148,   149,
     150,   151,   352,   153,     0,     0,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
       0,   169,   170,     0,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   322,   323,
     324,   325,   326,   327,   328,    15,    16,     0,   329,   330,
      19,   331,   332,   333,     0,    24,    25,    26,     0,   334,
      28,     0,   335,    31,    32,    33,    34,    35,    36,   336,
      38,     0,    40,   337,   338,    43,    44,    45,    46,     0,
       0,    49,     0,    50,    51,    52,   339,     0,     0,    56,
      57,    58,     0,     0,     0,    60,     0,     0,     0,     0,
      62,    63,     0,     0,    66,    67,     0,     0,     0,     0,
       0,     0,    72,    73,    74,    75,     0,    76,     0,     0,
       0,   340,    78,    79,     0,     0,     0,     0,     0,     0,
       0,    82,    83,    84,     0,    86,    87,    88,     0,     0,
       0,     0,     0,     0,     0,    93,    94,     0,     0,     0,
       0,    95,    96,    97,   343,   344,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,   109,     0,   110,     0,     0,     0,     0,     0,     0,
       0,   116,     0,   117,   118,   119,   120,   345,     0,   122,
     123,   124,   125,   126,   127,     0,     0,   128,   346,     0,
       0,     0,   132,     0,   133,   134,   135,   136,   137,   138,
     139,   347,   348,   349,   143,   350,   351,   146,   147,   148,
     149,   150,   151,   352,   153,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,     0,   169,   170,     0,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        10,   476,   477,   478,   479,   604,   365,   675,   676,   472,
     723,   676,   890,   129,   744,   577,   848,    89,    90,   378,
     379,   583,   113,   114,    19,   443,    55,   688,   612,   370,
     612,    20,   836,    77,   583,   376,   786,   657,    37,    38,
      39,   382,   583,    53,   455,    55,   457,   458,    47,   460,
       6,   462,   970,   124,   793,   794,    88,    19,    68,   470,
     471,    75,    59,    77,   124,    74,    88,    19,   120,     7,
       8,    75,    88,    88,    77,    88,    51,    51,   108,   747,
     124,    91,   747,     7,     8,    42,    17,    53,    19,   122,
     697,    98,   146,    92,    88,   105,    91,    19,    88,    77,
      88,   111,   136,    37,    38,    39,    77,   102,    81,    60,
     124,    88,    32,    47,    88,   108,   120,   136,    52,   153,
     153,   196,    88,   267,   216,   179,    77,   204,    62,   273,
      64,   126,   209,    67,   153,   130,    70,    17,   171,   134,
      75,    93,   176,   165,   174,    65,    84,    98,   161,   711,
     107,   160,   168,   168,   229,    45,   134,   164,    92,    93,
      84,    51,    27,   101,    54,   103,    93,   774,    75,   776,
     164,    61,   130,   161,   245,   165,   138,   101,   537,   103,
       3,   174,   214,   782,     7,   245,   138,   164,  1106,   919,
     653,   654,   130,   245,    88,   908,   152,   135,   314,   196,
     316,   245,   764,   192,   138,   873,   130,   756,   873,   568,
     960,   135,   761,   151,   763,   190,   190,   801,   838,   801,
     970,  1025,   763,   564,   223,    75,   567,   151,   231,   232,
     891,   245,   229,   164,   172,  1067,   265,   648,   977,   268,
     235,   245,   164,   216,   164,   317,    88,    88,   172,   321,
     130,   224,   114,   191,   134,   265,   109,   147,   268,   149,
     231,   232,   197,   198,   237,   199,   239,   191,   384,   341,
     164,    88,   243,   163,   124,   134,   249,   212,   101,   252,
     103,   147,   354,   355,    88,   357,    88,    88,   111,   223,
     197,   198,    88,    88,    88,   411,    88,   224,     3,    88,
     190,   373,     7,   375,    77,   212,   114,   130,   424,   425,
     134,   427,   428,   429,   430,   168,   178,   433,   130,   127,
      93,   393,   164,   164,     7,     8,   253,   254,   444,   256,
     257,    88,   342,   405,   450,   451,    88,    88,   410,    88,
      98,    88,   154,   134,   161,    88,   125,   419,  1226,   359,
       7,     8,   362,   712,   713,    88,  1106,   716,   162,   161,
      19,   134,   837,   164,   143,   130,   161,   161,   164,     7,
     380,   834,   164,   383,    97,   164,  1208,   387,    88,   389,
      18,   391,    32,   846,   394,  1053,   502,    37,  1053,    77,
    1268,   940,   751,    81,   404,  1273,   101,    88,   103,  1277,
     123,    84,   493,   494,   822,   163,   111,   164,    98,    88,
      88,    75,   164,   164,   137,   164,   178,   164,   101,   491,
     103,   164,   432,   495,   434,   130,   188,    84,    88,    81,
     789,   164,    91,    88,   506,   507,   508,    87,  1168,   138,
      88,    93,   514,   102,   101,    77,   103,   130,   171,    81,
     130,   161,   135,    88,    88,    55,    56,   573,   146,    88,
     124,   241,    75,   101,    88,   103,   246,   126,   151,    27,
     161,   130,    88,   130,   112,   134,     7,    88,   135,   241,
      88,  1149,   161,   161,  1149,   247,    88,    18,    98,   172,
    1052,   563,   130,   255,   151,    88,    13,   147,    98,   125,
      77,   161,   115,  1218,  1219,  1104,   161,   120,   191,   178,
    1109,   521,   522,   161,   146,   172,    93,   143,  1231,   188,
     200,   201,   202,  1238,   534,   597,   161,   161,   216,  1244,
    1198,   115,   161,  1198,   191,  1010,   224,   161,   226,   227,
     228,    46,  1017,  1018,    49,   161,   130,    76,   236,   237,
     161,   239,    98,   161,   144,   914,   244,    87,    87,   161,
     115,   249,   250,   251,   252,   120,  1029,    96,   161,   159,
     101,   115,   103,   134,   584,   105,   105,   159,   220,   221,
     652,   112,    36,  1182,   216,  1154,   130,  1186,   159,    43,
    1159,   173,   224,   603,   226,   227,   228,   241,    98,   130,
     242,   611,   173,   247,   130,   237,   224,   239,   134,   134,
     130,   255,   244,   176,   134,   178,   130,   249,   250,   251,
     252,   496,   981,  1222,   499,   188,   501,   148,   222,   148,
     746,   225,   748,   169,   170,   253,   254,   753,   256,   257,
     130,   211,   222,   213,   760,   225,   200,   201,   202,   211,
     134,   213,  1127,  1128,   204,   204,   206,   206,   106,   107,
     106,   107,    57,    58,   780,   675,   676,   677,   678,   706,
     707,   480,   481,   473,   474,   482,   483,   677,   678,   194,
     796,  1152,  1153,    98,    98,   695,   204,   697,   130,     0,
     806,   807,   808,   168,   810,   811,   812,   813,   814,   815,
     168,   817,   818,   110,    88,   145,    73,   234,    68,    82,
     177,   118,   119,    83,   121,  1074,   134,   164,   131,   130,
     130,   128,  1197,   164,   130,   132,   130,    37,   135,    37,
      19,    17,    98,   140,   130,   251,   148,   747,   251,    98,
     130,   134,   134,   134,    24,   134,   134,    98,    14,   156,
      19,   867,   210,   192,    36,   164,   164,   210,    75,    75,
      75,   164,   134,    19,   774,    88,   776,    88,   105,   138,
     138,   110,    19,    77,   181,   182,   183,   184,   185,   186,
      32,   897,   164,   164,    77,   110,    88,   161,    88,   164,
      88,    75,   216,   164,   120,   911,   252,   161,   233,   164,
     130,   235,   204,   240,   876,   168,    81,   110,   130,   925,
     254,   130,   255,   175,   930,   931,   888,   255,   138,   110,
     936,    98,   938,   939,    77,   124,   942,    98,    98,   945,
     120,    98,   124,    98,   130,   229,    24,    87,    87,    19,
     912,    98,   218,   130,    98,   230,   164,   230,   124,    48,
     255,   134,   164,   134,   122,   164,    75,   164,   122,   164,
      19,    88,   168,   873,   124,   120,   124,    60,   255,   164,
     164,   110,     5,   883,   212,   216,   124,   212,   212,   951,
     168,   212,    98,   134,   163,    75,   164,   248,    75,   163,
    1006,   164,    19,    19,   966,   104,    77,    98,   124,    77,
      98,    75,   161,    19,    77,   238,    58,    98,   130,   238,
      74,   921,   174,   174,    98,    98,   160,   927,   163,   929,
     163,    98,  1054,   933,   934,   197,   164,   933,   174,   769,
     193,   442,   174,   442,   231,   927,   946,  1096,  1007,   796,
     798,   793,   573,   404,   874,   921,  1062,   453,  1122,   960,
     454,   475,   193,   254,  1244,   604,   196,   967,  1238,   678,
     392,   392,   697,  1004,  1000,   834,   653,  1083,   846,   654,
    1029,  1087,  1164,   258,  1090,   838,  1092,  1066,  1094,  1024,
     835,    -1,    -1,  1099,    -1,    -1,    -1,    -1,    -1,    -1,
    1000,    -1,    -1,    -1,    -1,    -1,    -1,  1007,    -1,  1115,
    1116,  1117,  1118,  1119,    -1,  1121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1142,    -1,  1144,    -1,
      -1,  1041,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1053,    -1,    -1,    -1,    -1,    -1,    -1,
    1166,    -1,    -1,    -1,    -1,    -1,    -1,  1173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1105,    -1,    -1,    -1,    -1,
    1110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1122,  1229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1143,    -1,    -1,  1252,    -1,    -1,  1149,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1177,  1178,    -1,
      -1,    -1,    -1,  1183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1250,    -1,    -1,    -1,    -1,     9,  1256,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    19,    -1,    -1,    -1,  1269,
      -1,    25,    26,    -1,  1274,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    86,    87,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,   102,    -1,
     104,   105,   106,   107,    -1,   109,    -1,    -1,    -1,   113,
     114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,   153,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    86,    87,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,   102,    -1,   104,
     105,   106,   107,    -1,   109,    -1,    -1,    -1,   113,   114,
     115,   116,   117,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,   153,   154,
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
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,   102,    -1,   104,   105,
     106,   107,    -1,   109,    -1,    -1,    -1,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,   153,   154,    -1,
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
      67,    68,    69,    70,    71,    72,    73,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    86,
      87,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,   102,    -1,   104,   105,   106,
     107,    -1,   109,    -1,    -1,    -1,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,   134,   135,   136,
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
      68,    69,    70,    71,    72,    73,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    86,    87,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,   102,    -1,   104,   105,   106,   107,
      -1,   109,    -1,    -1,    -1,   113,   114,   115,   116,   117,
      -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,   134,   135,   136,   137,
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
      69,    70,    71,    72,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    -1,    86,    87,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,   102,    -1,   104,   105,   106,   107,    -1,
     109,    -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,   153,   154,    -1,    -1,   157,   158,
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
      70,    71,    72,    73,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    86,    87,    -1,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,    -1,   104,   105,   106,   107,    -1,   109,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
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
      71,    72,    73,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    86,    87,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,   102,    -1,   104,   105,   106,   107,    -1,   109,    -1,
      -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
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
      72,    73,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    86,    87,    -1,    -1,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
     102,    -1,   104,   105,   106,   107,    -1,   109,    -1,    -1,
      -1,   113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
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
      73,    -1,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,   102,
      -1,   104,   105,   106,   107,    -1,   109,    -1,    -1,    -1,
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
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
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    86,    87,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,   102,    -1,
     104,   105,   106,   107,    -1,   109,    -1,    -1,    -1,   113,
     114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,   153,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    86,    87,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,   102,    -1,   104,
     105,   106,   107,    -1,   109,    -1,    -1,    -1,   113,   114,
     115,   116,   117,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,   134,
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
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,   102,    -1,   104,   105,
     106,   107,    -1,   109,    -1,    -1,    -1,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,   153,   154,    -1,
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
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    86,
      87,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,   102,    -1,   104,   105,   106,
     107,    -1,   109,    -1,    -1,    -1,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,   134,   135,   136,
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
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    86,    87,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,   102,    -1,   104,   105,   106,   107,
      -1,   109,    -1,    -1,    -1,   113,   114,   115,   116,   117,
      -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
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
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    -1,    86,    87,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,   102,    -1,   104,   105,   106,   107,    -1,
     109,    -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,   127,   128,
     129,    -1,    -1,    -1,    -1,   134,   135,    -1,   137,   138,
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
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      -1,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    86,    87,    -1,    -1,
      -1,    91,    92,    93,    94,    95,    96,    -1,    98,    99,
     100,    -1,   102,    -1,   104,   105,   106,   107,    -1,   109,
      -1,    -1,    -1,   113,    -1,   115,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,    -1,   128,   129,
      -1,    -1,    -1,    -1,   134,   135,    -1,    -1,   138,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,    -1,
     150,   151,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
      -1,    -1,    -1,   163,    -1,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,   175,    -1,   177,    -1,   179,
      -1,   181,   182,   183,   184,   185,   186,    -1,    -1,   189,
     190,   191,    -1,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,   235,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    -1,    47,    48,    49,    -1,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    73,    -1,    75,    76,    77,    78,    -1,    -1,
      81,    82,    83,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    92,    93,    -1,    -1,    96,    97,    -1,    -1,    -1,
      -1,    -1,    -1,   104,   105,   106,   107,    -1,   109,    -1,
      -1,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,    -1,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,   163,    -1,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,   173,    -1,   175,   176,   177,   178,   179,    -1,
     181,   182,   183,   184,   185,   186,    -1,    -1,   189,   190,
      -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,   234,   235,    -1,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    -1,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    73,    -1,    75,    76,    77,    78,    -1,    -1,    81,
      82,    83,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      92,    93,    -1,    -1,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,    -1,   109,    -1,    -1,
      -1,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,    -1,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   163,    -1,   165,    -1,    -1,    -1,    -1,    -1,   171,
      -1,   173,    -1,   175,   176,   177,   178,   179,    -1,   181,
     182,   183,   184,   185,   186,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,   234,   235,    -1,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    15,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    -1,    47,    48,
      49,    -1,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    73,    -1,    75,    76,    77,    78,
      -1,    -1,    81,    82,    83,    -1,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    92,    93,    -1,    -1,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,    -1,
     109,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,    -1,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,   163,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   173,    -1,   175,   176,   177,   178,
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
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    73,    -1,    75,    76,    77,
      78,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    96,    97,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
      -1,   109,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,   125,    -1,   127,
     128,   129,   130,    -1,    -1,    -1,   134,    -1,    -1,   137,
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
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    73,    -1,    75,    76,
      77,    78,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    96,
      97,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,
     107,    -1,   109,    -1,    -1,    -1,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,    -1,
     127,   128,   129,   130,    -1,    -1,    -1,   134,    -1,    -1,
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
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    73,    -1,    75,
      76,    77,    78,    -1,    -1,    81,    82,    83,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,
     106,   107,    -1,   109,    -1,    -1,    -1,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
      -1,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,   163,   164,   165,
      -1,    -1,    -1,    -1,    -1,   171,    -1,   173,    -1,   175,
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
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    73,    -1,
      75,    76,    77,    78,    -1,    -1,    81,    82,    83,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,
      -1,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,    -1,   109,    -1,    -1,    -1,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,    -1,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
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
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    73,
      -1,    75,    76,    77,    78,    -1,    -1,    81,    82,    83,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    92,    93,
      -1,    -1,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,    -1,   109,    -1,    -1,    -1,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,    -1,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,
      -1,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,   173,
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
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      73,    -1,    75,    76,    77,    78,    -1,    -1,    81,    82,
      83,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,    -1,   109,    -1,    -1,    -1,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,    -1,   127,   128,   129,    -1,    -1,    -1,
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
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    73,    -1,    75,    76,    77,    78,    -1,    -1,    81,
      82,    83,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      92,    93,    -1,    -1,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,    -1,   109,    -1,    -1,
      -1,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,    -1,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
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
     252,   253,   254,   255,   256,   257
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    86,
      87,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   102,   104,   105,   106,   107,   109,   113,   114,   115,
     116,   117,   123,   124,   125,   126,   127,   128,   129,   130,
     134,   135,   136,   137,   138,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   153,   154,   157,   158,   159,   163,
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
     305,   306,   307,   312,   313,   314,   315,   319,   320,   321,
     322,   323,   324,   329,   337,   338,   343,   350,   353,   356,
     357,   358,   359,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   405,   406,   407,   421,   422,   424,   425,   426,
     427,   428,   429,   430,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   449,   450,   451,   452,   453,   454,
     455,   458,   463,   464,   216,    27,   134,   130,   200,   201,
     202,   134,    30,    31,    32,    33,    34,    35,    36,    40,
      41,    43,    44,    45,    51,    54,    61,    65,    66,    78,
     113,   130,   134,   146,   147,   179,   190,   203,   204,   205,
     207,   208,   215,   463,   130,   130,   134,   130,   134,    37,
      38,    39,    47,    52,    62,    64,    67,    70,    92,    93,
     138,   199,   223,   134,    17,   130,   134,   462,    46,    49,
      98,   147,   138,    98,   130,    55,    56,    98,   316,    98,
      27,   134,   134,   130,   134,   463,    32,    34,    35,    41,
      78,   389,   463,   463,    98,   303,   313,   164,   313,   463,
     130,   148,   148,    13,    15,   463,   463,   381,   381,   130,
     314,    20,   192,   194,   204,   206,   134,   204,   206,   204,
     204,   209,    98,   130,    98,     0,   275,   276,    36,    43,
     278,   312,   168,   168,    88,    45,    51,    54,    61,   147,
     163,   190,   322,   145,    73,   110,   118,   119,   121,   128,
     132,   135,   140,   156,   181,   182,   183,   184,   185,   186,
     374,   375,   234,   136,   153,   176,    97,   123,   137,   171,
     178,   188,   114,   127,    68,   177,    82,    83,   136,   153,
     373,   130,   379,   169,   170,   131,   393,   394,   389,   393,
     389,   393,   134,   314,   314,   313,   130,   130,   130,   313,
     313,   164,   171,   463,   130,   313,   313,   164,   313,   164,
     463,    37,    37,   463,   159,   173,   146,   179,    19,   461,
     144,   159,   159,   173,    98,    32,    37,    87,   147,   462,
     200,   201,   202,    81,   216,   224,   237,   239,   249,   252,
     476,   477,   478,   479,   480,   483,   488,   489,   313,   313,
      19,   164,   462,   130,   138,   461,    93,   138,   297,   461,
     351,   352,   463,   148,   462,   330,   332,   463,   314,   251,
     251,   325,   326,   463,    98,   333,   463,   463,    32,    65,
     164,   445,   446,   313,   164,   171,   463,   130,   351,   161,
     313,   168,   164,    24,   409,   410,   411,   313,   314,   344,
     345,    98,   339,   340,     6,   152,    14,   164,   313,   192,
      19,   314,   314,   164,   314,   314,   314,   314,   210,   456,
     457,   463,   314,   331,   336,   463,   280,   281,    36,   282,
     314,   314,   358,   359,   361,   361,   361,   361,   360,   361,
     361,   361,   130,   134,   235,   396,   465,   467,   468,   469,
     470,   471,   472,   473,   364,   364,   363,   365,   365,   365,
     365,   366,   366,   367,   367,   210,    75,    75,    75,   161,
     313,   381,   381,   313,   394,   164,   314,   404,   164,   161,
     313,   313,   313,   164,   161,    88,   164,    88,   164,   161,
     313,   161,   161,   161,   134,   301,   463,   463,    19,    88,
      88,   463,   138,   138,   461,   105,   110,   222,   225,    93,
     224,   253,   254,   256,   257,   222,   225,    19,   224,   253,
     254,   256,   257,   164,   161,   164,   164,   161,   313,   462,
      77,    32,   462,   461,    77,    88,   165,    75,   124,   432,
     344,   110,    88,   120,   245,   328,   432,   161,    88,    77,
     124,   327,   328,   432,   463,    59,   196,   229,   317,   318,
     164,   164,   164,   161,    88,   164,    88,   164,   161,   313,
     165,   168,   463,   410,   411,   108,   174,   161,    76,    87,
      96,   105,   346,   347,   348,   349,    88,   463,    88,   329,
     337,   342,   161,   109,   168,    75,   197,   198,   212,    75,
     197,   198,   212,    75,   216,   204,    88,   214,   120,   161,
      53,    88,   168,   361,   313,   465,   471,   252,   499,    77,
     146,   226,   227,   228,   236,   244,   250,   251,   466,   474,
     475,   476,   490,   493,   494,   496,   233,   235,   240,   495,
     220,   221,   242,   491,   129,   189,   433,   435,   436,   437,
     463,   433,   431,   436,   431,   161,   162,    88,   164,   302,
     161,   161,   161,    81,   354,   355,   130,   447,   448,   463,
     447,   448,   161,    98,   164,   308,   309,   115,   130,   311,
     301,   301,   125,   143,   125,   143,   115,   120,   432,   461,
     461,   106,   107,   461,   254,   255,    77,    93,   134,   482,
     255,   175,   130,   161,   110,   296,   461,   138,   110,    77,
     296,    98,   314,   433,   314,   124,   461,    98,   314,    98,
     120,   120,   328,    98,    98,   314,   124,   328,   124,   124,
     327,   328,   124,   432,   229,    60,    98,   327,   334,   335,
     318,   130,   447,   463,   447,   161,   314,    24,   411,   108,
     174,     7,     8,    84,   101,   103,   130,   172,   310,   406,
     408,   419,   420,   423,   461,   106,   107,   348,   349,   349,
     345,    87,   341,   340,   329,   337,    19,   211,   213,   314,
     314,   314,   211,   213,   314,   314,   314,   314,   314,   314,
      98,   314,   314,   218,   459,   460,   130,    98,   161,   164,
     230,   196,   229,   241,   246,   498,    77,   231,   232,   492,
     230,   468,   498,   362,   365,   250,   474,   476,   469,   124,
     492,   255,    48,   134,   134,   122,   153,   171,   434,   122,
     314,    98,   433,    93,   355,   161,   313,   164,   164,   122,
     164,   164,   463,    75,    88,   164,   313,   115,   311,   302,
     314,   115,   120,   255,    77,   134,   485,    19,    93,   482,
     314,   161,   313,   461,    88,   296,   352,   314,   168,   332,
     463,   314,   314,   120,   326,   463,   314,   124,   314,   314,
     124,   328,   124,   314,   124,   314,   463,    57,    58,    60,
     161,   313,   164,   164,   110,   172,   408,     5,   313,   463,
     172,   419,   349,   461,   168,   212,   212,   212,   212,   216,
     457,   163,   134,   460,   314,   336,   365,    42,   107,   365,
     365,   241,   247,   255,   497,   497,   362,   470,   248,   164,
     164,   463,   163,    98,   163,   161,   432,   433,   309,    75,
     161,   314,   114,   178,   484,   487,    19,    19,   486,   484,
     243,   492,    88,   164,    88,   164,   104,   161,    77,   461,
     314,   314,   314,   124,   314,   314,   335,    98,    98,   314,
     161,   411,   463,   172,   161,   411,   463,   314,   314,   314,
     314,   314,   314,   390,   161,   365,   365,   176,    75,   314,
     463,   314,   433,   485,   485,   487,    19,   164,    19,   238,
     481,   482,   481,   314,   296,   314,   463,   463,    74,   160,
     412,   411,   463,   174,   411,    88,   164,   365,   433,   163,
     492,    88,   164,   164,    58,     3,   111,   415,   416,   418,
     420,    18,   112,   413,   414,   417,   420,   174,   411,   174,
      98,   311,   163,   314,   238,   482,    98,    74,   111,   418,
     160,   112,   417,   174,   463,   314,   463,    88,   164,    98,
     311,   463,    88,   164,    98,   311,   463,   164,   311
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
     322,   322,   323,   323,   324,   325,   325,   326,   326,   326,
     326,   326,   326,   326,   326,   327,   328,   329,   330,   330,
     331,   331,   332,   332,   332,   332,   333,   333,   334,   334,
     335,   335,   335,   335,   336,   337,   338,   338,   338,   338,
     339,   339,   340,   340,   341,   342,   342,   343,   343,   344,
     344,   345,   345,   346,   346,   346,   346,   346,   346,   346,
     347,   347,   348,   348,   349,   350,   350,   351,   351,   352,
     352,   353,   353,   354,   354,   355,   355,   356,   357,   357,
     358,   358,   359,   359,   359,   359,   359,   360,   359,   359,
     359,   359,   361,   361,   361,   362,   362,   363,   363,   363,
     364,   364,   364,   364,   364,   365,   365,   365,   366,   366,
     366,   367,   367,   368,   368,   369,   369,   370,   370,   371,
     371,   372,   372,   372,   372,   373,   373,   373,   374,   374,
     374,   374,   374,   374,   375,   375,   375,   376,   376,   376,
     376,   377,   377,   378,   378,   379,   379,   380,   380,   380,
     380,   381,   381,   381,   382,   382,   383,   383,   383,   383,
     384,   384,   385,   385,   385,   385,   385,   385,   385,   386,
     386,   387,   387,   388,   388,   388,   388,   388,   389,   389,
     390,   390,   391,   391,   391,   392,   392,   393,   393,   394,
     395,   395,   395,   395,   395,   395,   395,   395,   396,   396,
     397,   397,   397,   398,   399,   399,   400,   401,   402,   403,
     403,   404,   404,   405,   405,   406,   406,   406,   407,   407,
     407,   407,   407,   407,   408,   408,   409,   409,   410,   411,
     411,   412,   412,   413,   413,   414,   414,   414,   414,   415,
     415,   416,   416,   416,   416,   417,   417,   418,   418,   419,
     419,   419,   419,   420,   420,   420,   420,   421,   421,   422,
     422,   423,   424,   424,   424,   424,   424,   424,   425,   426,
     426,   426,   426,   427,   427,   427,   427,   428,   429,   430,
     430,   430,   430,   431,   431,   432,   433,   433,   433,   434,
     434,   434,   435,   435,   435,   436,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   438,   439,   439,   439,   440,
     441,   442,   442,   442,   443,   443,   443,   443,   443,   444,
     445,   445,   445,   445,   445,   445,   445,   446,   447,   448,
     449,   450,   450,   450,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   452,   452,   453,   453,   454,   455,
     456,   456,   457,   458,   459,   459,   460,   460,   460,   460,
     461,   462,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   464,
     464,   465,   465,   465,   465,   466,   466,   466,   466,   467,
     467,   468,   468,   469,   469,   470,   470,   471,   471,   471,
     472,   472,   473,   473,   474,   474,   474,   474,   474,   475,
     476,   476,   476,   476,   476,   476,   476,   477,   477,   477,
     477,   478,   478,   478,   478,   479,   479,   480,   480,   480,
     480,   480,   480,   480,   481,   481,   482,   482,   482,   482,
     483,   483,   483,   483,   483,   484,   484,   485,   485,   486,
     486,   487,   487,   488,   489,   489,   490,   490,   490,   491,
     491,   491,   491,   491,   492,   492,   492,   492,   493,   494,
     495,   496,   496,   497,   497,   497,   498,   498,   499
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
       1,     1,     1,     2,     3,     1,     4,     3,     4,     4,
       5,     4,     5,     5,     6,     3,     3,     3,     1,     4,
       1,     4,     3,     4,     4,     5,     4,     5,     1,     3,
       7,     4,     4,     1,     1,     2,     3,     4,     4,     5,
       1,     3,     2,     3,     2,     1,     2,     3,     4,     1,
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
       1,     1,     3,     3,     1,     1,     1,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     1,     4,     4,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     4,     5,
       8,     9,     9,    10,     1,     2,     1,     2,     6,     0,
       1,     3,     3,     0,     1,     1,     1,     2,     2,     0,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     4,     4,
       5,     6,     7,     4,     5,     6,     7,     4,     4,     4,
       5,     6,     7,     1,     2,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     4,     4,     3,
       3,     3,     4,     4,     3,     4,     6,     4,     6,     3,
       3,     4,     6,     6,     4,     6,     6,     4,     1,     2,
       1,     3,     3,     3,     5,     7,     7,     5,     5,     5,
       7,     7,     5,     5,     3,     3,     5,     7,     5,     7,
       1,     4,     3,     5,     1,     2,     5,     8,    11,    14,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       4,     1,     2,     3,     4,     1,     1,     2,     2,     1,
       3,     1,     3,     1,     4,     1,     2,     1,     2,     3,
       1,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     3,     5,
       7,     5,     7,     2,     1,     3,     2,     4,     4,     6,
       4,     5,     4,     5,     3,     1,     2,     2,     3,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     1,     2,     1,     2,     3,     3,     4,     3,     3,
       3,     2,     2,     1,     1,     1,     1,     1,     3
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
  "\"'construction'\"", "\"'eval'\"", "\"'for'\"", "\"'sliding'\"",
  "\"'tumbling'\"", "\"'previous'\"", "\"'next'\"", "\"'only'\"",
  "\"'when'\"", "\"'count'\"", "\"'ordering'\"", "\"'cont'\"",
  "\"'base-uri'\"", "\"'schema-element'\"", "\"'document-node'\"",
  "\"'copy-namespaces'\"", "\"'instance'\"", "\"'schema-attribute'\"",
  "\"'boundary-space'\"", "\"'ancestor::'\"", "\"'ancestor-or-self::'\"",
  "\"'and'\"", "\"'''\"", "\"'as'\"", "\"'ascending'\"", "\"'at'\"",
  "\"'attribute'\"", "\"'attribute::'\"", "\"'@'\"", "\"'case'\"",
  "\"'castable'\"", "\"'cast'\"", "\"'CDATA[['\"", "\"']]'\"",
  "\"'child::'\"", "\"'collation'\"", "\"','\"", "\"'(:'\"", "\"':)'\"",
  "\"'DECIMAL'\"", "\"'variable'\"", "\"'default'\"", "\"'descendant::'\"",
  "\"'descendant-or-self::'\"", "\"'descending'\"", "\"'div'\"", "\"'$'\"",
  "\"'.'\"", "\"'..'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
  "\"'else'\"", "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
  "\"'encoding'\"", "\"'='\"", "\"''''\"", "\"'\\\"\\\"'\"", "\"'every'\"",
  "\"'except'\"", "\"'external'\"", "\"'following::'\"",
  "\"'following-sibling::'\"", "\"'follows'\"", "\"'>='\"", "\"':='\"",
  "\"'>'\"", "\"'?'\"", "\"'idiv'\"", "\"'in'\"", "\"'inherit'\"",
  "\"'INTEGER'\"", "\"'intersect'\"", "\"'is'\"", "\"'item'\"", "\"'{'\"",
  "\"'['\"", "\"'<='\"", "\"'[ / ]'\"", "\"'('\"", "\"'<'\"", "\"'-'\"",
  "\"'mod'\"", "\"'namespace'\"", "\"'nan'\"", "\"'!='\"",
  "\"'nodecomp'\"", "\"'?\\?'\"", "\"'<no inherit>'\"",
  "\"'<no preserve>'\"", "\"'or'\"", "\"'ordered'\"", "\"'order'\"",
  "\"'by'\"", "\"'group'\"", "\"'parent::'\"", "\"'<?'\"", "\"'?>'\"",
  "\"'+'\"", "\"'PRAGMA BEGIN'\"", "\"'PRAGMA END'\"", "\"'<<'\"",
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
  "FLWORClauseList", "ForClause", "VarInDeclList", "VarInDecl",
  "PositionalVar", "FTScoreVar", "LetClause", "VarGetsDeclList",
  "EvalVarDeclList", "VarGetsDecl", "WindowVarDecl", "WindowVars",
  "WindowVars2", "EvalVarDecl", "WhereClause", "GroupByClause",
  "GroupSpecList", "GroupSpec", "GroupCollationSpec", "LetClauseList",
  "OrderByClause", "OrderSpecList", "OrderSpec", "OrderModifier",
  "OrderDirSpec", "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
  "QVarInDeclList", "QVarInDecl", "TypeswitchExpr", "CaseClauseList",
  "CaseClause", "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr", "@1",
  "FTContainsExpr", "RangeExpr", "AdditiveExpr", "MultiplicativeExpr",
  "UnionExpr", "IntersectExceptExpr", "InstanceofExpr", "TreatExpr",
  "CastableExpr", "CastExpr", "UnaryExpr", "SignList", "ValueExpr",
  "ValueComp", "NodeComp", "ValidateExpr", "ExtensionExpr", "PragmaList",
  "Pragma", "PathExpr", "RelativePathExpr", "StepExpr", "AxisStep",
  "ForwardStep", "ForwardAxis", "AbbrevForwardStep", "ReverseStep",
  "ReverseAxis", "NodeTest", "NameTest", "Wildcard", "FilterExpr",
  "PredicateList", "Predicate", "PrimaryExpr", "Literal", "NumericLiteral",
  "VarRef", "ParenthesizedExpr", "ContextItemExpr", "OrderedExpr",
  "UnorderedExpr", "FunctionCall", "ArgList", "Constructor",
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
      19,   109,    19,   168,    -1,   278,   312,    -1,   312,    -1,
     277,   278,    -1,    46,   138,   462,   110,   461,   168,    -1,
     279,   168,    -1,   280,   168,    -1,   279,   168,   280,   168,
      -1,   281,    -1,   279,   168,   281,    -1,   282,    -1,   280,
     168,   282,    -1,   283,    -1,   284,    -1,   285,    -1,   287,
      -1,   299,    -1,   307,    -1,   288,    -1,   289,    -1,   286,
      -1,   293,    -1,   294,    -1,   300,    -1,   290,    -1,   291,
      -1,   292,    -1,   450,    -1,   295,    -1,   298,    -1,    36,
     138,   462,   110,   461,    -1,    36,    70,   159,    -1,    36,
      70,   173,    -1,    36,    93,    32,   138,   461,    -1,    36,
      93,    37,   138,   461,    -1,    36,    47,   463,    19,    -1,
      36,   223,   476,    -1,    36,    62,   146,    -1,    36,    62,
     179,    -1,    36,    93,   147,   105,   106,    -1,    36,    93,
     147,   105,   107,    -1,    36,    67,   159,    88,   125,    -1,
      36,    67,   159,    88,   143,    -1,    36,    67,   144,    88,
     125,    -1,    36,    67,   144,    88,   143,    -1,    36,    93,
      87,   461,    -1,    36,    64,   461,    -1,    43,    49,   461,
      -1,    43,    49,   297,   461,    -1,    43,    49,   461,    77,
     296,    -1,    43,    49,   297,   461,    77,   296,    -1,   461,
      -1,   296,    88,   461,    -1,   138,   462,   110,    -1,    93,
      32,   138,    -1,    43,    46,   461,    -1,    43,    46,   138,
     462,   110,   461,    -1,    43,    46,   461,    77,   296,    -1,
      43,    46,   138,   462,   110,   461,    77,   296,    -1,    36,
      92,    98,   463,   120,   314,    -1,    36,    92,    98,   463,
     115,    -1,    36,    92,    98,   463,   432,   120,   314,    -1,
      36,    92,    98,   463,   432,   115,    -1,    36,    52,   159,
      -1,    36,    52,   173,    -1,   134,   164,    -1,   134,   308,
     164,    -1,   134,   164,    75,   433,    -1,   134,   308,   164,
      75,   433,    -1,   130,   303,   161,    -1,   313,   168,    -1,
     303,   313,   168,    -1,    25,   216,   314,    -1,    29,   134,
     314,   164,   302,    -1,    26,    27,    -1,    63,    27,    -1,
      36,    37,   463,   301,   115,    -1,    36,    37,   463,   301,
     311,    -1,    36,    38,    37,   463,   301,   115,    -1,    36,
      38,    37,   463,   301,   311,    -1,    36,    39,    37,   463,
     301,   302,    -1,   309,    -1,   308,    88,   309,    -1,    98,
     463,    -1,    98,   463,   432,    -1,   130,   313,   161,    -1,
     130,   313,   161,    -1,   313,    -1,   314,    -1,   313,    88,
     314,    -1,   315,    -1,   350,    -1,   353,    -1,   356,    -1,
     357,    -1,   451,    -1,   452,    -1,   454,    -1,   453,    -1,
     455,    -1,   458,    -1,   464,    -1,   304,    -1,   305,    -1,
     306,    -1,   302,    -1,   323,   163,   314,    -1,    55,   251,
      -1,    56,   251,    -1,   196,    -1,   229,    -1,    59,   229,
      -1,   317,   334,    60,   314,    -1,   317,    60,   314,    -1,
      54,   316,   333,   318,   318,    -1,    54,   316,   333,   318,
      -1,    61,    98,   463,    -1,   324,    -1,   329,    -1,   319,
      -1,   321,    -1,   337,    -1,   343,    -1,   338,    -1,   320,
      -1,   322,    -1,   323,   322,    -1,    54,    98,   325,    -1,
     326,    -1,   325,    88,    98,   326,    -1,   463,   124,   314,
      -1,   463,   432,   124,   314,    -1,   463,   327,   124,   314,
      -1,   463,   432,   327,   124,   314,    -1,   463,   328,   124,
     314,    -1,   463,   432,   328,   124,   314,    -1,   463,   327,
     328,   124,   314,    -1,   463,   432,   327,   328,   124,   314,
      -1,    77,    98,   463,    -1,   245,    98,   463,    -1,    51,
      98,   330,    -1,   332,    -1,   330,    88,    98,   332,    -1,
     336,    -1,   331,    88,    98,   336,    -1,   463,   120,   314,
      -1,   463,   432,   120,   314,    -1,   463,   328,   120,   314,
      -1,   463,   432,   328,   120,   314,    -1,    98,   463,   124,
     314,    -1,    98,   463,   432,   124,   314,    -1,   335,    -1,
      98,   463,   335,    -1,   327,    57,    98,   463,    58,    98,
     463,    -1,   327,    58,    98,   463,    -1,   327,    57,    98,
     463,    -1,   327,    -1,   463,    -1,   190,   314,    -1,   149,
     148,   339,    -1,   149,   148,   339,   342,    -1,   149,   148,
     339,   337,    -1,   149,   148,   339,   342,   337,    -1,   340,
      -1,   339,    88,   340,    -1,    98,   463,    -1,    98,   463,
     341,    -1,    87,   461,    -1,   329,    -1,   342,   329,    -1,
     147,   148,   344,    -1,    45,   147,   148,   344,    -1,   345,
      -1,   344,    88,   345,    -1,   314,    -1,   314,   346,    -1,
     347,    -1,   348,    -1,   349,    -1,   347,   348,    -1,   347,
     349,    -1,   348,   349,    -1,   347,   348,   349,    -1,    76,
      -1,    96,    -1,   105,   106,    -1,   105,   107,    -1,    87,
     461,    -1,    44,    98,   351,   165,   314,    -1,   113,    98,
     351,   165,   314,    -1,   352,    -1,   351,    88,    98,   352,
      -1,   463,   124,   314,    -1,   463,   432,   124,   314,    -1,
      31,   134,   313,   164,   354,    93,   163,   314,    -1,    31,
     134,   313,   164,   354,    93,    98,   463,   163,   314,    -1,
     355,    -1,   354,   355,    -1,    81,   433,   163,   314,    -1,
      81,    98,   463,    75,   433,   163,   314,    -1,    40,   134,
     313,   164,   175,   314,   104,   314,    -1,   358,    -1,   357,
     145,   358,    -1,   359,    -1,   358,    73,   359,    -1,   361,
      -1,   361,   374,   361,    -1,   361,   375,   361,    -1,   361,
     110,   361,    -1,   361,   140,   361,    -1,    -1,   361,   135,
     360,   361,    -1,   361,   132,   361,    -1,   361,   121,   361,
      -1,   361,   119,   361,    -1,   362,    -1,   362,   234,   465,
      -1,   362,   234,   465,   499,    -1,   363,    -1,   363,   176,
     363,    -1,   364,    -1,   363,   153,   364,    -1,   363,   136,
     364,    -1,   365,    -1,   364,   171,   365,    -1,   364,    97,
     365,    -1,   364,   123,   365,    -1,   364,   137,   365,    -1,
     366,    -1,   365,   178,   366,    -1,   365,   188,   366,    -1,
     367,    -1,   366,   127,   367,    -1,   366,   114,   367,    -1,
     368,    -1,   368,    68,   210,   433,    -1,   369,    -1,   369,
     177,    75,   433,    -1,   370,    -1,   370,    82,    75,   431,
      -1,   371,    -1,   371,    83,    75,   431,    -1,   373,    -1,
     372,   373,    -1,   153,    -1,   136,    -1,   372,   153,    -1,
     372,   136,    -1,   376,    -1,   380,    -1,   377,    -1,   181,
      -1,   186,    -1,   185,    -1,   184,    -1,   183,    -1,   182,
      -1,   128,    -1,   156,    -1,   118,    -1,    30,   130,   313,
     161,    -1,    30,   200,   130,   313,   161,    -1,    30,   201,
     130,   313,   161,    -1,    30,   202,   130,   313,   161,    -1,
     378,   130,   161,    -1,   378,   130,   313,   161,    -1,   379,
      -1,   378,   379,    -1,   154,   463,    14,    -1,   154,    15,
      -1,   169,    -1,   169,   381,    -1,   170,   381,    -1,   381,
      -1,   382,    -1,   382,   169,   381,    -1,   382,   170,   381,
      -1,   383,    -1,   392,    -1,   384,    -1,   384,   393,    -1,
     387,    -1,   387,   393,    -1,   385,   389,    -1,   386,    -1,
      86,    -1,    94,    -1,    79,    -1,   167,    -1,    95,    -1,
     117,    -1,   116,    -1,   389,    -1,    80,   389,    -1,   388,
     389,    -1,   100,    -1,   150,    -1,    71,    -1,   158,    -1,
     157,    -1,    72,    -1,   437,    -1,   390,    -1,   463,    -1,
     391,    -1,   171,    -1,     9,    -1,    16,    -1,   395,    -1,
     395,   393,    -1,   394,    -1,   393,   394,    -1,   131,   313,
     162,    -1,   396,    -1,   398,    -1,   399,    -1,   400,    -1,
     403,    -1,   405,    -1,   401,    -1,   402,    -1,   397,    -1,
     449,    -1,    91,    -1,   126,    -1,   102,    -1,    98,   463,
      -1,   134,   164,    -1,   134,   313,   164,    -1,    99,    -1,
     146,   130,   313,   161,    -1,   179,   130,   313,   161,    -1,
     463,   134,   164,    -1,   463,   134,   404,   164,    -1,   314,
      -1,   404,    88,   314,    -1,   406,    -1,   424,    -1,   407,
      -1,   421,    -1,   422,    -1,   135,   463,   411,   108,    -1,
     135,   463,   409,   411,   108,    -1,   135,   463,   411,   174,
     172,   463,   411,   174,    -1,   135,   463,   411,   174,   408,
     172,   463,   411,   174,    -1,   135,   463,   409,   411,   174,
     172,   463,   411,   174,    -1,   135,   463,   409,   411,   174,
     408,   172,   463,   411,   174,    -1,   419,    -1,   408,   419,
      -1,   410,    -1,   409,   410,    -1,    24,   463,   411,   110,
     411,   412,    -1,    -1,    24,    -1,   160,   413,   160,    -1,
      74,   415,    74,    -1,    -1,   414,    -1,   112,    -1,   417,
      -1,   414,   112,    -1,   414,   417,    -1,    -1,   416,    -1,
     111,    -1,   418,    -1,   416,   111,    -1,   416,   418,    -1,
      18,    -1,   420,    -1,     3,    -1,   420,    -1,   406,    -1,
       8,    -1,   423,    -1,   420,    -1,     7,    -1,   101,    -1,
     103,    -1,   310,    -1,   191,    20,   192,    -1,   191,   192,
      -1,   151,    13,   152,    -1,   151,    13,     6,    -1,    84,
       5,    -1,   425,    -1,   426,    -1,   427,    -1,   428,    -1,
     429,    -1,   430,    -1,    33,   130,   313,   161,    -1,    32,
     463,   130,   161,    -1,    32,   463,   130,   313,   161,    -1,
      32,   130,   313,   161,   130,   161,    -1,    32,   130,   313,
     161,   130,   313,   161,    -1,    78,   463,   130,   161,    -1,
      78,   463,   130,   313,   161,    -1,    78,   130,   313,   161,
     130,   161,    -1,    78,   130,   313,   161,   130,   313,   161,
      -1,    34,   130,   313,   161,    -1,    35,   130,   313,   161,
      -1,    41,   462,   130,   161,    -1,    41,   462,   130,   313,
     161,    -1,    41,   130,   313,   161,   130,   161,    -1,    41,
     130,   313,   161,   130,   313,   161,    -1,   436,    -1,   436,
     122,    -1,    75,   433,    -1,   435,    -1,   435,   434,    -1,
     189,   134,   164,    -1,   122,    -1,   171,    -1,   153,    -1,
     436,    -1,   437,    -1,   129,   134,   164,    -1,   463,    -1,
     439,    -1,   445,    -1,   443,    -1,   446,    -1,   444,    -1,
     442,    -1,   441,    -1,   440,    -1,   438,    -1,   204,   134,
     164,    -1,    66,   134,   164,    -1,    66,   134,   445,   164,
      -1,    66,   134,   446,   164,    -1,    34,   134,   164,    -1,
      35,   134,   164,    -1,    41,   134,   164,    -1,    41,   134,
     462,   164,    -1,    41,   134,    19,   164,    -1,    78,   134,
     164,    -1,    78,   134,   463,   164,    -1,    78,   134,   463,
      88,   447,   164,    -1,    78,   134,   171,   164,    -1,    78,
     134,   171,    88,   447,   164,    -1,   166,   463,   164,    -1,
      32,   134,   164,    -1,    32,   134,   463,   164,    -1,    32,
     134,   463,    88,   447,   164,    -1,    32,   134,   463,    88,
     448,   164,    -1,    32,   134,   171,   164,    -1,    32,   134,
     171,    88,   447,   164,    -1,    32,   134,   171,    88,   448,
     164,    -1,    65,   134,   463,   164,    -1,   463,    -1,   463,
     122,    -1,    19,    -1,    36,   199,   200,    -1,    36,   199,
     201,    -1,    36,   199,   202,    -1,   205,   204,   314,   212,
     314,    -1,   205,   204,   314,    75,   211,   212,   314,    -1,
     205,   204,   314,    75,   213,   212,   314,    -1,   205,   204,
     314,   197,   314,    -1,   205,   204,   314,   198,   314,    -1,
     205,   206,   314,   212,   314,    -1,   205,   206,   314,    75,
     211,   212,   314,    -1,   205,   206,   314,    75,   213,   212,
     314,    -1,   205,   206,   314,   197,   314,    -1,   205,   206,
     314,   198,   314,    -1,   203,   204,   314,    -1,   203,   206,
     314,    -1,   208,   204,   314,   216,   314,    -1,   208,   209,
     210,   204,   314,   216,   314,    -1,   207,   204,   314,    75,
     314,    -1,   215,    98,   456,   214,   314,   163,   314,    -1,
     457,    -1,   456,    88,    98,   457,    -1,   463,   120,   314,
      -1,   217,   130,   314,   161,   459,    -1,   460,    -1,   459,
     460,    -1,   218,   134,   390,   164,   311,    -1,   218,   134,
     390,    88,    98,   463,   164,   311,    -1,   218,   134,   390,
      88,    98,   463,    88,    98,   463,   164,   311,    -1,   218,
     134,   390,    88,    98,   463,    88,    98,   463,    88,    98,
     463,   164,   311,    -1,    19,    -1,    17,    -1,    17,    -1,
     105,    -1,    78,    -1,    35,    -1,    66,    -1,    32,    -1,
     129,    -1,    40,    -1,   204,    -1,    41,    -1,    69,    -1,
      65,    -1,    34,    -1,    31,    -1,   189,    -1,    70,    -1,
     223,    -1,    64,    -1,   201,    -1,   200,    -1,   123,    -1,
      33,    -1,   235,    -1,   222,    -1,   225,    -1,   224,    -1,
     252,    -1,   253,    -1,   256,    -1,   254,    -1,   257,    -1,
     228,    -1,   230,    -1,    48,    -1,   196,    -1,   229,    -1,
      42,    -1,   202,    -1,   215,    -1,   209,    -1,   181,    -1,
     186,    -1,   185,    -1,   184,    -1,   183,    -1,   182,    -1,
      77,    -1,    92,    -1,   163,    -1,    54,    -1,    55,    -1,
      56,    -1,    57,    -1,    58,    -1,    59,    -1,    60,    -1,
      61,    -1,   124,    -1,    51,    -1,   190,    -1,   148,    -1,
     147,    -1,    45,    -1,    76,    -1,    96,    -1,   106,    -1,
     107,    -1,    87,    -1,    44,    -1,   113,    -1,   165,    -1,
      81,    -1,    75,    -1,   175,    -1,   104,    -1,   145,    -1,
      73,    -1,    68,    -1,   210,    -1,    82,    -1,   176,    -1,
      97,    -1,   137,    -1,   178,    -1,   127,    -1,   114,    -1,
      30,    -1,    83,    -1,   177,    -1,   128,    -1,   159,    -1,
     173,    -1,   138,    -1,   115,    -1,   109,    -1,   144,    -1,
     125,    -1,   143,    -1,    36,    -1,    52,    -1,    62,    -1,
      93,    -1,    67,    -1,    47,    -1,   194,    -1,    43,    -1,
      49,    -1,    37,    -1,   245,    -1,   234,    -1,   250,    -1,
     251,    -1,   227,    -1,   240,    -1,   248,    -1,   244,    -1,
     226,    -1,   239,    -1,   249,    -1,   243,    -1,   238,    -1,
     237,    -1,   221,    -1,   220,    -1,   242,    -1,   231,    -1,
     232,    -1,   255,    -1,   247,    -1,   246,    -1,   241,    -1,
     208,    -1,   214,    -1,   211,    -1,   205,    -1,   198,    -1,
     197,    -1,   199,    -1,   216,    -1,   206,    -1,   207,    -1,
     213,    -1,   203,    -1,   212,    -1,    38,    -1,   146,    -1,
     179,    -1,   219,    98,   331,    53,   130,   314,   161,    -1,
      53,   130,   314,   161,    -1,   467,    -1,   467,   466,    -1,
     467,   250,   362,    -1,   467,   466,   250,   362,    -1,   476,
      -1,   474,    -1,   466,   476,    -1,   466,   474,    -1,   468,
      -1,   467,   236,   468,    -1,   469,    -1,   468,   233,   469,
      -1,   470,    -1,   469,   235,   124,   470,    -1,   471,    -1,
     235,   471,    -1,   472,    -1,   472,   495,    -1,   134,   465,
     164,    -1,   473,    -1,   473,   491,    -1,   396,    -1,   130,
     313,   161,    -1,   475,    -1,   494,    -1,   493,    -1,   496,
      -1,   490,    -1,   146,    -1,   477,    -1,   478,    -1,   479,
      -1,   480,    -1,   483,    -1,   488,    -1,   489,    -1,   239,
      -1,   249,    -1,    81,   222,    -1,    81,   225,    -1,   216,
     224,    -1,   252,   224,    -1,   224,   222,    -1,   224,   225,
      -1,   216,   253,    -1,   252,   253,    -1,   216,   256,   482,
      -1,   216,   256,    93,    -1,   216,   256,   134,   482,   164,
      -1,   216,   256,   134,   482,    88,   481,   164,    -1,   216,
     256,   134,    93,   164,    -1,   216,   256,   134,    93,    88,
     481,   164,    -1,   252,   256,    -1,   482,    -1,   481,    88,
     482,    -1,    77,    19,    -1,    77,    19,   243,    19,    -1,
      77,    19,   492,   238,    -1,    77,    19,   243,    19,   492,
     238,    -1,   216,   254,   255,   485,    -1,   216,   254,   255,
     485,   484,    -1,   216,    93,   254,   255,    -1,   216,    93,
     254,   255,   484,    -1,   252,   254,   255,    -1,   487,    -1,
     484,   487,    -1,    77,    19,    -1,   134,   486,   164,    -1,
      19,    -1,   486,    19,    -1,   178,   485,    -1,   114,   485,
      -1,   237,    19,    -1,   216,   257,    -1,   252,   257,    -1,
      77,   196,    -1,    77,   229,    -1,   228,   230,    -1,   221,
      -1,   221,    48,    -1,   220,    -1,   220,   255,    -1,   242,
      -1,   231,   365,    -1,    77,   107,   365,    -1,    77,    42,
     365,    -1,   232,   365,   176,   365,    -1,   227,   492,   497,
      -1,   251,   365,   497,    -1,   240,   492,   248,    -1,   244,
     498,    -1,   226,   498,    -1,   255,    -1,   247,    -1,   241,
      -1,   246,    -1,   241,    -1,   252,   230,   365,    -1
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
     477,   479,   481,   483,   486,   490,   492,   497,   501,   506,
     511,   517,   522,   528,   534,   541,   545,   549,   553,   555,
     560,   562,   567,   571,   576,   581,   587,   592,   598,   600,
     604,   612,   617,   622,   624,   626,   629,   633,   638,   643,
     649,   651,   655,   658,   662,   665,   667,   670,   674,   679,
     681,   685,   687,   690,   692,   694,   696,   699,   702,   705,
     709,   711,   713,   716,   719,   722,   728,   734,   736,   741,
     745,   750,   759,   770,   772,   775,   780,   788,   797,   799,
     803,   805,   809,   811,   815,   819,   823,   827,   828,   833,
     837,   841,   845,   847,   851,   856,   858,   862,   864,   868,
     872,   874,   878,   882,   886,   890,   892,   896,   900,   902,
     906,   910,   912,   917,   919,   924,   926,   931,   933,   938,
     940,   943,   945,   947,   950,   953,   955,   957,   959,   961,
     963,   965,   967,   969,   971,   973,   975,   977,   982,   988,
     994,  1000,  1004,  1009,  1011,  1014,  1018,  1021,  1023,  1026,
    1029,  1031,  1033,  1037,  1041,  1043,  1045,  1047,  1050,  1052,
    1055,  1058,  1060,  1062,  1064,  1066,  1068,  1070,  1072,  1074,
    1076,  1079,  1082,  1084,  1086,  1088,  1090,  1092,  1094,  1096,
    1098,  1100,  1102,  1104,  1106,  1108,  1110,  1113,  1115,  1118,
    1122,  1124,  1126,  1128,  1130,  1132,  1134,  1136,  1138,  1140,
    1142,  1144,  1146,  1148,  1151,  1154,  1158,  1160,  1165,  1170,
    1174,  1179,  1181,  1185,  1187,  1189,  1191,  1193,  1195,  1200,
    1206,  1215,  1225,  1235,  1246,  1248,  1251,  1253,  1256,  1263,
    1264,  1266,  1270,  1274,  1275,  1277,  1279,  1281,  1284,  1287,
    1288,  1290,  1292,  1294,  1297,  1300,  1302,  1304,  1306,  1308,
    1310,  1312,  1314,  1316,  1318,  1320,  1322,  1324,  1328,  1331,
    1335,  1339,  1342,  1344,  1346,  1348,  1350,  1352,  1354,  1359,
    1364,  1370,  1377,  1385,  1390,  1396,  1403,  1411,  1416,  1421,
    1426,  1432,  1439,  1447,  1449,  1452,  1455,  1457,  1460,  1464,
    1466,  1468,  1470,  1472,  1474,  1478,  1480,  1482,  1484,  1486,
    1488,  1490,  1492,  1494,  1496,  1498,  1502,  1506,  1511,  1516,
    1520,  1524,  1528,  1533,  1538,  1542,  1547,  1554,  1559,  1566,
    1570,  1574,  1579,  1586,  1593,  1598,  1605,  1612,  1617,  1619,
    1622,  1624,  1628,  1632,  1636,  1642,  1650,  1658,  1664,  1670,
    1676,  1684,  1692,  1698,  1704,  1708,  1712,  1718,  1726,  1732,
    1740,  1742,  1747,  1751,  1757,  1759,  1762,  1768,  1777,  1789,
    1804,  1806,  1808,  1810,  1812,  1814,  1816,  1818,  1820,  1822,
    1824,  1826,  1828,  1830,  1832,  1834,  1836,  1838,  1840,  1842,
    1844,  1846,  1848,  1850,  1852,  1854,  1856,  1858,  1860,  1862,
    1864,  1866,  1868,  1870,  1872,  1874,  1876,  1878,  1880,  1882,
    1884,  1886,  1888,  1890,  1892,  1894,  1896,  1898,  1900,  1902,
    1904,  1906,  1908,  1910,  1912,  1914,  1916,  1918,  1920,  1922,
    1924,  1926,  1928,  1930,  1932,  1934,  1936,  1938,  1940,  1942,
    1944,  1946,  1948,  1950,  1952,  1954,  1956,  1958,  1960,  1962,
    1964,  1966,  1968,  1970,  1972,  1974,  1976,  1978,  1980,  1982,
    1984,  1986,  1988,  1990,  1992,  1994,  1996,  1998,  2000,  2002,
    2004,  2006,  2008,  2010,  2012,  2014,  2016,  2018,  2020,  2022,
    2024,  2026,  2028,  2030,  2032,  2034,  2036,  2038,  2040,  2042,
    2044,  2046,  2048,  2050,  2052,  2054,  2056,  2058,  2060,  2062,
    2064,  2066,  2068,  2070,  2072,  2074,  2076,  2078,  2080,  2082,
    2084,  2086,  2088,  2090,  2092,  2094,  2096,  2098,  2100,  2102,
    2110,  2115,  2117,  2120,  2124,  2129,  2131,  2133,  2136,  2139,
    2141,  2145,  2147,  2151,  2153,  2158,  2160,  2163,  2165,  2168,
    2172,  2174,  2177,  2179,  2183,  2185,  2187,  2189,  2191,  2193,
    2195,  2197,  2199,  2201,  2203,  2205,  2207,  2209,  2211,  2213,
    2216,  2219,  2222,  2225,  2228,  2231,  2234,  2237,  2241,  2245,
    2251,  2259,  2265,  2273,  2276,  2278,  2282,  2285,  2290,  2295,
    2302,  2307,  2313,  2318,  2324,  2328,  2330,  2333,  2336,  2340,
    2342,  2345,  2348,  2351,  2354,  2357,  2360,  2363,  2366,  2369,
    2371,  2374,  2376,  2379,  2381,  2384,  2388,  2392,  2397,  2401,
    2405,  2409,  2412,  2415,  2417,  2419,  2421,  2423,  2425
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   807,   807,   812,   818,   823,   835,   840,   850,   857,
     869,   881,   893,   899,   905,   917,   923,   937,   943,   957,
     958,   959,   960,   966,   967,   968,   971,   978,   979,   980,
     981,   982,   983,   984,   987,   994,   995,  1007,  1019,  1024,
    1035,  1041,  1053,  1066,  1077,  1082,  1094,  1099,  1110,  1116,
    1122,  1128,  1147,  1158,  1169,  1176,  1183,  1190,  1203,  1209,
    1224,  1228,  1238,  1244,  1251,  1257,  1271,  1278,  1285,  1292,
    1305,  1310,  1322,  1326,  1330,  1334,  1341,  1348,  1354,  1363,
    1370,  1377,  1381,  1388,  1396,  1405,  1414,  1423,  1438,  1446,
    1460,  1466,  1478,  1486,  1497,  1508,  1514,  1526,  1527,  1528,
    1529,  1530,  1533,  1534,  1535,  1536,  1537,  1538,  1539,  1540,
    1541,  1542,  1543,  1550,  1558,  1562,  1570,  1574,  1578,  1585,
    1589,  1596,  1601,  1610,  1619,  1620,  1621,  1625,  1625,  1625,
    1625,  1625,  1628,  1634,  1645,  1656,  1662,  1676,  1683,  1691,
    1700,  1710,  1718,  1727,  1736,  1751,  1763,  1774,  1786,  1792,
    1804,  1810,  1824,  1832,  1841,  1849,  1861,  1867,  1877,  1878,
    1886,  1890,  1894,  1898,  1905,  1920,  1928,  1935,  1942,  1949,
    1959,  1965,  1976,  1982,  1991,  1998,  2005,  2017,  2022,  2034,
    2040,  2054,  2060,  2072,  2079,  2086,  2093,  2100,  2107,  2114,
    2127,  2131,  2141,  2146,  2157,  2168,  2175,  2188,  2195,  2207,
    2213,  2226,  2233,  2247,  2253,  2265,  2271,  2284,  2295,  2299,
    2310,  2314,  2333,  2337,  2345,  2353,  2361,  2369,  2369,  2377,
    2385,  2393,  2407,  2411,  2418,  2431,  2435,  2446,  2450,  2454,
    2464,  2468,  2472,  2476,  2480,  2490,  2494,  2499,  2510,  2514,
    2518,  2528,  2532,  2544,  2548,  2560,  2564,  2576,  2580,  2592,
    2596,  2608,  2612,  2616,  2620,  2632,  2636,  2640,  2650,  2654,
    2658,  2662,  2666,  2670,  2680,  2684,  2688,  2698,  2702,  2708,
    2714,  2726,  2732,  2744,  2750,  2764,  2771,  2813,  2817,  2821,
    2825,  2838,  2849,  2854,  2864,  2868,  2878,  2884,  2890,  2896,
    2908,  2914,  2925,  2929,  2933,  2937,  2941,  2945,  2949,  2959,
    2963,  2973,  2979,  2991,  2995,  2999,  3003,  3007,  3022,  3026,
    3036,  3040,  3050,  3057,  3064,  3077,  3081,  3093,  3099,  3113,
    3124,  3128,  3132,  3136,  3140,  3144,  3148,  3152,  3162,  3166,
    3176,  3181,  3186,  3197,  3207,  3211,  3222,  3232,  3243,  3299,
    3305,  3317,  3323,  3335,  3339,  3349,  3353,  3357,  3367,  3375,
    3383,  3391,  3399,  3407,  3422,  3428,  3440,  3446,  3459,  3468,
    3470,  3476,  3481,  3493,  3496,  3503,  3509,  3515,  3523,  3538,
    3541,  3548,  3554,  3560,  3568,  3582,  3587,  3598,  3603,  3614,
    3619,  3624,  3630,  3642,  3648,  3653,  3658,  3669,  3674,  3689,
    3694,  3711,  3726,  3730,  3734,  3738,  3742,  3746,  3756,  3767,
    3773,  3779,  3784,  3806,  3812,  3818,  3823,  3834,  3845,  3856,
    3862,  3868,  3873,  3884,  3890,  3902,  3914,  3920,  3926,  3963,
    3968,  3973,  3984,  3988,  3992,  4002,  4013,  4017,  4021,  4025,
    4029,  4033,  4037,  4041,  4045,  4055,  4065,  4069,  4074,  4085,
    4095,  4105,  4109,  4113,  4123,  4129,  4135,  4141,  4147,  4159,
    4170,  4176,  4182,  4188,  4194,  4201,  4208,  4221,  4242,  4249,
    4269,  4309,  4314,  4317,  4325,  4331,  4337,  4343,  4349,  4356,
    4362,  4368,  4374,  4380,  4392,  4397,  4407,  4413,  4425,  4451,
    4462,  4468,  4481,  4495,  4502,  4509,  4520,  4527,  4535,  4544,
    4557,  4560,  4578,  4579,  4580,  4581,  4582,  4583,  4584,  4585,
    4586,  4587,  4588,  4589,  4590,  4591,  4592,  4593,  4594,  4595,
    4596,  4597,  4598,  4599,  4600,  4601,  4602,  4603,  4604,  4605,
    4606,  4607,  4608,  4609,  4610,  4611,  4612,  4613,  4614,  4615,
    4616,  4617,  4618,  4619,  4620,  4621,  4622,  4623,  4624,  4625,
    4626,  4627,  4628,  4629,  4630,  4631,  4632,  4633,  4634,  4635,
    4636,  4637,  4638,  4639,  4640,  4641,  4642,  4643,  4644,  4645,
    4646,  4647,  4648,  4649,  4650,  4651,  4652,  4653,  4654,  4655,
    4656,  4657,  4658,  4659,  4660,  4661,  4662,  4663,  4664,  4665,
    4666,  4667,  4668,  4669,  4670,  4671,  4672,  4673,  4674,  4675,
    4676,  4677,  4678,  4679,  4680,  4681,  4682,  4683,  4684,  4685,
    4686,  4687,  4688,  4689,  4690,  4691,  4692,  4693,  4694,  4695,
    4696,  4697,  4698,  4699,  4700,  4701,  4702,  4703,  4704,  4705,
    4706,  4707,  4708,  4709,  4710,  4711,  4712,  4713,  4714,  4715,
    4716,  4717,  4718,  4719,  4720,  4721,  4722,  4723,  4724,  4735,
    4741,  4758,  4762,  4766,  4770,  4780,  4783,  4786,  4789,  4798,
    4801,  4810,  4813,  4822,  4825,  4834,  4837,  4846,  4849,  4852,
    4861,  4864,  4873,  4877,  4887,  4890,  4893,  4896,  4899,  4908,
    4917,  4921,  4925,  4929,  4933,  4937,  4941,  4951,  4954,  4957,
    4960,  4969,  4972,  4975,  4978,  4987,  4990,  4999,  5002,  5005,
    5008,  5011,  5014,  5017,  5026,  5029,  5038,  5041,  5044,  5047,
    5056,  5059,  5062,  5065,  5068,  5077,  5080,  5089,  5092,  5101,
    5104,  5113,  5116,  5125,  5134,  5137,  5146,  5149,  5152,  5161,
    5164,  5167,  5170,  5173,  5182,  5186,  5190,  5194,  5204,  5213,
    5223,  5232,  5235,  5244,  5247,  5250,  5259,  5262,  5271
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
  const int xquery_parser::yylast_ = 7905;
  const int xquery_parser::yynnts_ = 228;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 435;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 272;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 526;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5279 "/usr/local/src/zorba_gflwor/src/compiler/parser/xquery_parser.y"


namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
                  *the_start = "start", *the_end = "end", *the_only_end = "only end";

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

