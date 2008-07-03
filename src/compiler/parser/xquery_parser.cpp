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
#line 775 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"

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
        case 54: /* "\"'DECIMAL'\"" */
#line 672 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 85: /* "\"'DOUBLE'\"" */
#line 671 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 116: /* "\"'INTEGER'\"" */
#line 670 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "VersionDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "MainModule" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "LibraryModule" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "ModuleDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "Prolog" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "SIND_DeclList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "VFO_DeclList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "SIND_Decl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "VFO_Decl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "Setter" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "Import" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "NamespaceDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "BoundarySpaceDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "DefaultNamespaceDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "OptionDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "OrderingModeDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "EmptyOrderDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "CopyNamespacesDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "DefaultCollationDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "BaseURIDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "SchemaImport" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "URILiteralList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "SchemaPrefix" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "ModuleImport" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "VarDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 346 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "ConstructionDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "FunctionSig" */
#line 680 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 356 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "Block" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 361 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "BlockBody" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 366 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "ExitExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 371 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "WhileExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 376 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "FlowCtlStatement" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 381 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "FunctionDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 386 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "ParamList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 391 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "Param" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 396 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "EnclosedExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 401 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "BracedExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 406 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "QueryBody" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 411 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "Expr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 416 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "ExprSingle" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 421 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "FLWORExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 426 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "ForLetClauseList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 431 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "ForLetClause" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 436 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "ForClause" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 441 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "VarInDeclList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 446 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "VarInDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 451 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "PositionalVar" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 456 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "LetClause" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 461 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "VarGetsDeclList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 466 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "EvalVarDeclList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 471 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "VarGetsDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "EvalVarDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 481 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "WhereClause" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 486 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "GroupByClause" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 491 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "GroupSpecList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 496 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "GroupSpec" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 501 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "GroupCollationSpec" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 506 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "LetClauseList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 511 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "OrderByClause" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 516 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "OrderSpecList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 521 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "OrderSpec" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "OrderModifier" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "OrderDirSpec" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 536 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "OrderEmptySpec" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "OrderCollationSpec" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "QuantifiedExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 551 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "QVarInDeclList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 556 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "QVarInDecl" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 561 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "TypeswitchExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 566 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "CaseClauseList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 571 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "CaseClause" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 576 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "IfExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 581 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "OrExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 586 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "AndExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 591 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "ComparisonExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 596 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FTContainsExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 601 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "RangeExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 606 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "AdditiveExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 611 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "MultiplicativeExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 616 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "UnionExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 621 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "IntersectExceptExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 626 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "InstanceofExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 631 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "TreatExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 636 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "CastableExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 641 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "CastExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 646 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "UnaryExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 651 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "SignList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 656 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ValueExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 661 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "GeneralComp" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 666 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "ValueComp" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 671 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "NodeComp" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 676 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ValidateExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 681 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "ExtensionExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 686 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "PragmaList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 691 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "Pragma" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 696 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "PathExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 701 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "RelativePathExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 706 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "StepExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 711 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "AxisStep" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 716 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ForwardStep" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 721 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ForwardAxis" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 726 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "AbbrevForwardStep" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 731 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ReverseStep" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 736 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ReverseAxis" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 741 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "NodeTest" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 746 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "NameTest" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 751 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "Wildcard" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 756 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "FilterExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 761 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "PredicateList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 766 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "Predicate" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 771 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "PrimaryExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 776 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "Literal" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 781 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "NumericLiteral" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 786 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarRef" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 791 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ParenthesizedExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 796 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "ContextItemExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 801 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "OrderedExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 806 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "UnorderedExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 811 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "FunctionCall" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 816 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "ArgList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 821 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "Constructor" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 826 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "DirectConstructor" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 831 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "DirElemConstructor" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 836 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "DirElemContentList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 841 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "DirAttributeList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 846 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "DirAttr" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 851 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "DirAttributeValue" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 856 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "Opt_QuoteAttrContentList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 861 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "QuoteAttrContentList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 866 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "Opt_AposAttrContentList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 871 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "AposAttrContentList" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 876 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "QuoteAttrValueContent" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 881 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "AposAttrValueContent" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 886 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "DirElemContent" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 891 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "CommonContent" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 896 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "DirCommentConstructor" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 901 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "DirPIConstructor" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 906 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "CDataSection" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 911 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "ComputedConstructor" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 916 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "CompDocConstructor" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 921 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "CompElemConstructor" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 926 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "CompAttrConstructor" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 931 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CompTextConstructor" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 936 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "CompCommentConstructor" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 941 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "CompPIConstructor" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 946 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "SingleType" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 951 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "TypeDeclaration" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 956 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "SequenceType" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 961 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OccurrenceIndicator" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 966 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "ItemType" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 971 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "AtomicType" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 976 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "KindTest" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 981 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "AnyKindTest" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 986 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "DocumentTest" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 991 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "TextTest" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 996 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "CommentTest" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1001 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "PITest" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1006 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "AttributeTest" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1011 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "SchemaAttributeTest" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1016 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "ElementTest" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1021 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SchemaElementTest" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1026 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "TypeName" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1031 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "TypeName_WITH_HOOK" */
#line 678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1036 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "StringLiteral" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1041 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "InsertExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1046 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "DeleteExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1051 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ReplaceExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1056 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "RenameExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1061 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "TransformExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1066 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "VarNameList" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1071 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "VarNameDecl" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1076 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "TryExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1081 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "CatchListExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1086 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "CatchExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1091 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "EvalExpr" */
#line 679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1096 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 91 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}
  /* Line 547 of yacc.c.  */
#line 1177 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
#line 796 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 3:
#line 801 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 4:
#line 807 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 812 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 824 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), encoding);
		;}
    break;

  case 7:
#line 829 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (2)].sval)), SYMTAB ((yysemantic_stack_[(5) - (4)].sval)));
    ;}
    break;

  case 8:
#line 839 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)));
		;}
    break;

  case 9:
#line 846 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								NULL,
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 10:
#line 858 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 11:
#line 870 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (4)].sval)));
		;}
    break;

  case 12:
#line 882 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 13:
#line 888 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 14:
#line 894 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 15:
#line 906 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 16:
#line 912 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 17:
#line 926 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 18:
#line 932 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 946 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 950 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 958 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 967 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 971 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 975 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 981 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 991 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 995 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1003 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1007 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1011 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1015 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1021 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1031 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1035 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1050 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 38:
#line 1062 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1067 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1078 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 41:
#line 1084 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 42:
#line 1096 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 43:
#line 1109 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1120 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1125 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1137 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1142 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1153 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 49:
#line 1159 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 50:
#line 1165 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 51:
#line 1171 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 52:
#line 1190 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1201 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1212 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 55:
#line 1219 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(3) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 56:
#line 1226 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 57:
#line 1233 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(5) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 58:
#line 1246 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 59:
#line 1252 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 60:
#line 1267 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1271 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 62:
#line 1281 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 63:
#line 1287 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)),
								NULL);
		;}
    break;

  case 64:
#line 1294 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 65:
#line 1300 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(7) - (7)].node)));
		;}
    break;

  case 66:
#line 1314 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 67:
#line 1321 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								NULL,
								NULL);
		;}
    break;

  case 68:
#line 1328 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 69:
#line 1335 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (3)].node)),
								NULL);
		;}
    break;

  case 70:
#line 1348 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1353 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1365 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 73:
#line 1369 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 74:
#line 1373 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 75:
#line 1377 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 76:
#line 1384 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    ;}
    break;

  case 77:
#line 1391 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = new BlockBody (LOC ((yyloc)));
      blk->add ((yysemantic_stack_[(2) - (1)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 78:
#line 1397 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 79:
#line 1406 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 80:
#line 1413 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(4) - (2)].expr), dynamic_cast<BlockBody *> ((yysemantic_stack_[(4) - (4)].expr)));
    ;}
    break;

  case 81:
#line 1420 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 82:
#line 1424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 83:
#line 1431 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret, NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
		;}
    break;

  case 84:
#line 1439 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret, 
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
		;}
    break;

  case 85:
#line 1448 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								&* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret, 
								NULL,
								ParseConstants::fn_extern_update);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
		;}
    break;

  case 86:
#line 1457 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret, 
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_update);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
		;}
    break;

  case 87:
#line 1466 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret, 
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
		;}
    break;

  case 88:
#line 1481 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 89:
#line 1489 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 90:
#line 1503 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 91:
#line 1509 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 92:
#line 1521 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1529 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 94:
#line 1540 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 95:
#line 1551 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = new Expr(LOC ((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 96:
#line 1557 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 97:
#line 1569 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1573 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1577 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1581 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1585 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1591 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1595 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1599 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1603 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1607 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 107:
#line 1611 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 108:
#line 1615 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 109:
#line 1619 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 110:
#line 1623 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 111:
#line 1627 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 112:
#line 1631 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 113:
#line 1641 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 114:
#line 1648 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 115:
#line 1656 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								NULL,NULL,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 116:
#line 1664 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(5) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(5) - (2)].node)),
                NULL,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 117:
#line 1673 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 118:
#line 1685 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 119:
#line 1697 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 120:
#line 1709 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 121:
#line 1727 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ForLetClauseList* flc_list_p = new ForLetClauseList(LOC ((yyloc)));
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = flc_list_p;
		;}
    break;

  case 122:
#line 1733 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(2) - (1)].node));
			if (flc_list_p) flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 123:
#line 1745 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 124:
#line 1749 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 125:
#line 1759 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 126:
#line 1770 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 127:
#line 1776 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 128:
#line 1790 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 129:
#line 1797 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 130:
#line 1805 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 131:
#line 1814 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 132:
#line 1824 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 133:
#line 1832 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 134:
#line 1841 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 135:
#line 1850 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 136:
#line 1865 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 137:
#line 1877 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 138:
#line 1888 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 139:
#line 1900 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 140:
#line 1906 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 141:
#line 1918 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 142:
#line 1924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 143:
#line 1938 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 144:
#line 1946 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 145:
#line 1955 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 146:
#line 1963 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 147:
#line 1975 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 148:
#line 1990 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 149:
#line 1998 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(2) - (2)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 150:
#line 2005 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (2)].node)),
                 dynamic_cast<LetClauseList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL);
    ;}
    break;

  case 151:
#line 2012 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (2)].node)),
                 NULL,
                 dynamic_cast<WhereClause*>((yysemantic_stack_[(3) - (3)].node)));
    ;}
    break;

  case 152:
#line 2019 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(4) - (2)].node)),
                 dynamic_cast<LetClauseList*>((yysemantic_stack_[(4) - (3)].node)),
                 dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 153:
#line 2029 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 154:
#line 2035 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 155:
#line 2046 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 156:
#line 2052 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 157:
#line 2061 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 158:
#line 2068 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      LetClauseList* lc_list_p = new LetClauseList(LOC((yyloc)));
      lc_list_p->push_back(dynamic_cast<LetClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = lc_list_p;
    ;}
    break;

  case 159:
#line 2075 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      LetClauseList* lc_list_p = dynamic_cast<LetClauseList*>((yysemantic_stack_[(2) - (1)].node));
      if (lc_list_p) lc_list_p->push_back(dynamic_cast<LetClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    ;}
    break;

  case 160:
#line 2087 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 161:
#line 2092 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)),
								true);
		;}
    break;

  case 162:
#line 2104 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 163:
#line 2110 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 164:
#line 2124 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 165:
#line 2130 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 166:
#line 2142 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 167:
#line 2149 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 168:
#line 2156 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 169:
#line 2163 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 170:
#line 2170 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 171:
#line 2177 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 172:
#line 2184 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 173:
#line 2197 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 174:
#line 2201 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 175:
#line 2211 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 176:
#line 2216 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 177:
#line 2227 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 178:
#line 2238 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 179:
#line 2245 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 180:
#line 2258 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 181:
#line 2265 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 182:
#line 2277 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 183:
#line 2283 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 184:
#line 2296 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(7) - (4)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 185:
#line 2303 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(9) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(9) - (4)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval)),
								(yysemantic_stack_[(9) - (9)].expr));
		;}
    break;

  case 186:
#line 2317 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 187:
#line 2323 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 188:
#line 2335 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 189:
#line 2341 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 190:
#line 2354 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 191:
#line 2365 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 192:
#line 2369 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 193:
#line 2380 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 194:
#line 2384 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 195:
#line 2403 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 196:
#line 2407 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 197:
#line 2415 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<GeneralComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 198:
#line 2423 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "is" | "<<" | ">>" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 199:
#line 2437 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 200:
#line 2441 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 201:
#line 2448 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 202:
#line 2461 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 203:
#line 2465 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 204:
#line 2476 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 205:
#line 2480 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 206:
#line 2484 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 207:
#line 2494 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 208:
#line 2498 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 209:
#line 2502 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 210:
#line 2506 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 211:
#line 2510 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 212:
#line 2520 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 213:
#line 2524 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 214:
#line 2529 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 215:
#line 2540 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 216:
#line 2544 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 217:
#line 2548 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 218:
#line 2558 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 219:
#line 2562 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 220:
#line 2574 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 221:
#line 2578 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 222:
#line 2590 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 223:
#line 2594 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 224:
#line 2606 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 225:
#line 2610 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 226:
#line 2622 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 227:
#line 2626 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 228:
#line 2638 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 229:
#line 2642 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 230:
#line 2646 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 231:
#line 2650 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 232:
#line 2662 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 233:
#line 2666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 234:
#line 2670 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 235:
#line 2681 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq);
		;}
    break;

  case 236:
#line 2685 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne);
		;}
    break;

  case 237:
#line 2689 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt);
		;}
    break;

  case 238:
#line 2693 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_le);
		;}
    break;

  case 239:
#line 2697 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt);
		;}
    break;

  case 240:
#line 2701 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge);
		;}
    break;

  case 241:
#line 2711 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 242:
#line 2715 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 243:
#line 2719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 244:
#line 2723 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 245:
#line 2727 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 246:
#line 2731 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 247:
#line 2741 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 248:
#line 2745 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 249:
#line 2749 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 250:
#line 2760 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 251:
#line 2764 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 252:
#line 2776 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 253:
#line 2782 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 254:
#line 2794 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 255:
#line 2800 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 256:
#line 2814 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 257:
#line 2819 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 258:
#line 2862 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 259:
#line 2866 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 260:
#line 2870 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 261:
#line 2874 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 262:
#line 2887 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 263:
#line 2898 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 264:
#line 2903 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 265:
#line 2913 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 266:
#line 2917 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 267:
#line 2927 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 268:
#line 2933 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 269:
#line 2939 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 270:
#line 2945 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 271:
#line 2957 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 272:
#line 2963 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 273:
#line 2974 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 274:
#line 2978 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 275:
#line 2982 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 276:
#line 2986 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 277:
#line 2990 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 278:
#line 2994 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 279:
#line 2998 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 280:
#line 3008 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 281:
#line 3012 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 282:
#line 3022 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 283:
#line 3028 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 284:
#line 3040 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 285:
#line 3044 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 286:
#line 3048 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 287:
#line 3052 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 288:
#line 3056 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 289:
#line 3071 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 290:
#line 3075 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 291:
#line 3085 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 292:
#line 3089 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 293:
#line 3099 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 294:
#line 3106 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 295:
#line 3113 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 296:
#line 3126 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 297:
#line 3130 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 298:
#line 3142 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 299:
#line 3148 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 300:
#line 3162 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 301:
#line 3173 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 3177 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 3181 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 304:
#line 3185 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 305:
#line 3189 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 306:
#line 3193 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 307:
#line 3197 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 308:
#line 3201 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 309:
#line 3211 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 310:
#line 3215 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 311:
#line 3225 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 312:
#line 3230 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 313:
#line 3235 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 314:
#line 3246 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 315:
#line 3256 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 316:
#line 3260 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 317:
#line 3271 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 318:
#line 3281 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 319:
#line 3292 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 320:
#line 3348 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 321:
#line 3354 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 322:
#line 3366 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 323:
#line 3372 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 324:
#line 3384 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 325:
#line 3388 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 326:
#line 3398 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 327:
#line 3402 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 328:
#line 3406 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 329:
#line 3416 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 330:
#line 3424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(4) - (3)].node)), 
								NULL);
		;}
    break;

  case 331:
#line 3432 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 332:
#line 3440 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (6)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(7) - (4)].node)));
		;}
    break;

  case 333:
#line 3448 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (6)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(7) - (3)].node)),
								NULL);
		;}
    break;

  case 334:
#line 3456 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(8) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(8) - (5)].node)));
		;}
    break;

  case 335:
#line 3471 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 336:
#line 3477 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 337:
#line 3489 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 338:
#line 3495 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 339:
#line 3509 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 340:
#line 3521 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 341:
#line 3526 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 342:
#line 3537 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 343:
#line 3541 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 344:
#line 3548 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 345:
#line 3554 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 346:
#line 3560 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 347:
#line 3568 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 348:
#line 3582 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 349:
#line 3586 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 350:
#line 3593 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 351:
#line 3599 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 352:
#line 3605 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 353:
#line 3613 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 354:
#line 3627 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 355:
#line 3632 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 356:
#line 3643 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 357:
#line 3648 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 358:
#line 3659 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 359:
#line 3664 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 360:
#line 3669 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 361:
#line 3675 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 362:
#line 3687 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 363:
#line 3693 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 364:
#line 3698 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 365:
#line 3703 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 366:
#line 3714 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 367:
#line 3719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 368:
#line 3734 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 369:
#line 3739 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 370:
#line 3756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 371:
#line 3771 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 372:
#line 3775 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 373:
#line 3779 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 374:
#line 3783 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 375:
#line 3787 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 376:
#line 3791 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 377:
#line 3801 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 378:
#line 3812 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 379:
#line 3818 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 380:
#line 3824 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 381:
#line 3829 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 382:
#line 3851 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 383:
#line 3857 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 384:
#line 3863 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 385:
#line 3868 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 386:
#line 3879 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 387:
#line 3890 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 388:
#line 3901 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 389:
#line 3907 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 390:
#line 3913 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 391:
#line 3918 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 392:
#line 3929 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 393:
#line 3935 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 394:
#line 3947 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 395:
#line 3958 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 396:
#line 3964 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 397:
#line 3970 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 398:
#line 4007 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 399:
#line 4012 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 400:
#line 4017 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 401:
#line 4028 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 402:
#line 4032 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 403:
#line 4036 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 404:
#line 4046 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 405:
#line 4057 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 406:
#line 4061 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 407:
#line 4065 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 408:
#line 4069 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 409:
#line 4073 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 410:
#line 4077 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 411:
#line 4081 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 412:
#line 4085 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 413:
#line 4089 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 414:
#line 4099 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 415:
#line 4109 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 416:
#line 4113 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 417:
#line 4118 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 418:
#line 4129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 419:
#line 4139 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 420:
#line 4149 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 421:
#line 4153 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 422:
#line 4157 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 423:
#line 4167 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 424:
#line 4173 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL);
		;}
    break;

  case 425:
#line 4179 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 426:
#line 4185 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 427:
#line 4191 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 428:
#line 4203 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 429:
#line 4214 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL);
		;}
    break;

  case 430:
#line 4220 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
									NULL);
		;}
    break;

  case 431:
#line 4226 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 432:
#line 4232 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 433:
#line 4238 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 434:
#line 4245 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 435:
#line 4252 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 436:
#line 4265 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 437:
#line 4286 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 438:
#line 4293 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 439:
#line 4313 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 440:
#line 4353 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 441:
#line 4358 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 442:
#line 4361 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 443:
#line 4369 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 444:
#line 4375 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 445:
#line 4381 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 446:
#line 4387 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 447:
#line 4393 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 448:
#line 4400 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 449:
#line 4406 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 450:
#line 4412 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 451:
#line 4418 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 452:
#line 4424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 453:
#line 4436 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 454:
#line 4441 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 455:
#line 4451 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 456:
#line 4457 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 457:
#line 4469 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 458:
#line 4495 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(6) - (2)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(6) - (4)].expr), (yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 459:
#line 4506 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 460:
#line 4512 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 461:
#line 4525 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 462:
#line 4539 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 463:
#line 4546 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 464:
#line 4553 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 465:
#line 4564 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 466:
#line 4571 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(7) - (2)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval)),
                          (yysemantic_stack_[(7) - (7)].expr));
    ;}
    break;

  case 467:
#line 4579 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(10) - (2)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(10) - (5)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval)),
                          (yysemantic_stack_[(10) - (10)].expr));
    ;}
    break;

  case 468:
#line 4588 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(13) - (2)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(13) - (5)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(13) - (8)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(13) - (11)].sval)),
                          (yysemantic_stack_[(13) - (13)].expr));
    ;}
    break;

  case 469:
#line 4607 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(5) - (2)].node)),
                          (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 470:
#line 4613 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(3) - (2)].expr));
    ;}
    break;

  case 471:
#line 4630 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 472:
#line 4634 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 473:
#line 4638 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 474:
#line 4642 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 475:
#line 4652 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 476:
#line 4655 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 477:
#line 4658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 478:
#line 4661 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 479:
#line 4670 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 480:
#line 4673 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 481:
#line 4682 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 482:
#line 4685 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 483:
#line 4694 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 484:
#line 4697 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 485:
#line 4706 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 486:
#line 4709 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 487:
#line 4718 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 488:
#line 4721 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 489:
#line 4724 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 490:
#line 4733 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 491:
#line 4736 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 492:
#line 4745 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 493:
#line 4749 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, static_cast<Expr *> ((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 494:
#line 4759 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 495:
#line 4762 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 496:
#line 4765 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 497:
#line 4768 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 498:
#line 4771 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 499:
#line 4780 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 500:
#line 4789 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 501:
#line 4793 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 502:
#line 4797 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 503:
#line 4801 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 504:
#line 4805 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 505:
#line 4809 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 506:
#line 4813 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 507:
#line 4823 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 508:
#line 4826 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 509:
#line 4829 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 510:
#line 4832 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 511:
#line 4841 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 512:
#line 4844 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 513:
#line 4847 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 514:
#line 4850 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 515:
#line 4859 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 516:
#line 4862 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 517:
#line 4871 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 518:
#line 4874 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 519:
#line 4877 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 520:
#line 4880 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 521:
#line 4883 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 522:
#line 4886 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 523:
#line 4889 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 524:
#line 4898 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 525:
#line 4901 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 526:
#line 4910 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 527:
#line 4913 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 528:
#line 4916 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 529:
#line 4919 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 530:
#line 4928 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 531:
#line 4931 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 532:
#line 4934 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 533:
#line 4937 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 534:
#line 4940 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 535:
#line 4949 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 536:
#line 4952 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 537:
#line 4961 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 538:
#line 4964 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 539:
#line 4973 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 540:
#line 4976 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 541:
#line 4985 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 542:
#line 4988 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 543:
#line 4997 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 544:
#line 5006 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 545:
#line 5009 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 546:
#line 5018 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 547:
#line 5021 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 548:
#line 5024 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 549:
#line 5033 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 550:
#line 5036 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 551:
#line 5039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 552:
#line 5042 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 553:
#line 5045 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 554:
#line 5054 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 555:
#line 5058 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 556:
#line 5062 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 557:
#line 5066 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 558:
#line 5076 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 559:
#line 5085 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 560:
#line 5095 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 561:
#line 5104 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 562:
#line 5107 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 563:
#line 5116 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 564:
#line 5119 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 565:
#line 5122 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 566:
#line 5131 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 567:
#line 5134 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 568:
#line 5143 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(2) - (2)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 5868 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -704;
  const short int
  xquery_parser::yypact_[] =
  {
       874,  1306,  1522,  -704,  -704,   -37,  3466,  -704,     4,  -704,
    -704,  -704,  3466,    59,   430,  -704,  3466,   -23,  -704,   245,
     -13,   180,     9,   312,    21,    24,   298,   308,   363,   316,
     -38,   352,   403,  3466,  -704,  -704,   411,  -704,  -704,  3466,
     271,   442,  -704,  -704,  -704,  3466,    72,   449,  -704,  -704,
     459,  3466,   209,   290,  -704,  3466,   489,  1738,  -704,   507,
     365,  3466,  -704,   519,   107,  -704,   399,  -704,  -704,   128,
     522,   526,  -704,  4013,  3854,   449,  -704,   533,  3466,   392,
    3466,  3466,  3466,     7,   544,   368,  3466,  3466,  3466,  3466,
    3466,  3466,  3466,   546,   451,   555,  3466,  3479,   618,  1090,
    -704,  -704,   197,  3466,   454,   456,  -704,  -704,  -704,  -704,
    -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,
    -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,
     573,  -704,  -704,   416,  -704,  -704,  -704,  -704,  -704,  -704,
     488,   603,  -704,   461,   394,   -12,    -8,   276,   356,  -704,
     527,   453,   598,   599,   654,  -704,  -704,  -704,    -9,  -704,
    -704,  -704,   378,  -704,   523,   430,  -704,   523,   430,  -704,
    -704,  -704,  -704,   523,  -704,  -704,  -704,  -704,  -704,  -704,
    -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,
    -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,
    -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,
    -704,  -704,  -704,  -704,    88,  -704,   170,  1954,   482,  3466,
     200,    23,  -704,   105,  -704,  -704,   237,  -704,  -704,  -704,
    -704,  -704,  -704,   600,   601,  -704,   631,   633,  -704,  -704,
     534,   568,   638,  -704,  -704,   534,   534,  -704,   433,   243,
    -704,   499,   502,  -704,   246,   108,  -704,   109,   287,    20,
    -704,   -17,   619,  -704,   110,   634,   657,   639,   538,   661,
     651,  2170,    53,   -19,   629,  -704,  -704,   111,   586,  -704,
     248,    38,   516,   518,  -704,   668,  -704,   567,  3466,   524,
     525,  -704,  -704,    79,    15,   249,  -704,   113,   250,   251,
     486,  -704,   232,  -704,  -704,  -704,  -704,  -704,   391,   402,
     662,   469,   475,   592,     0,  -704,  3466,  -704,   -16,  -704,
     537,  -704,  -704,  -704,  -704,   675,  -704,  -704,  -704,  -704,
    -704,  -704,  -704,   -42,  -704,  -704,    55,   359,  -704,  -704,
    -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,
    -704,  -704,   197,    -1,  3466,  3466,   621,  3466,  3466,  3466,
    -704,   380,   384,   539,  3682,  3682,  -704,  -704,  -704,  -704,
    -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,
    -704,  3682,  3682,  3682,    -7,  3682,  3682,  3682,  3682,  3682,
    3682,  3682,  3682,  3682,  3682,  3682,   310,   310,   684,   684,
    -704,  -704,  -704,  2386,  -704,  3854,  3854,  3466,   523,  -704,
    -704,   523,  -704,   523,  -704,  -704,  -704,  -704,   115,   585,
     252,   589,   690,  -704,   690,  -704,  -704,   205,   370,  -704,
    -704,   231,   223,   685,  -704,   302,   585,   310,  -704,  3466,
     369,  -704,  -704,  -704,   593,   692,  -704,   692,  -704,  3466,
     604,   635,  3466,   637,  3466,   641,   -56,   606,   -15,   643,
     545,   694,   632,   694,  -704,   644,   695,  -704,    74,  -704,
    3466,   622,   -58,   659,  -704,   706,  -704,  -704,  -704,  -704,
    -704,  -704,  2602,   253,  -704,  -704,  3466,   649,  -704,    13,
      43,  -704,  -704,   702,  -704,  -704,  -704,   720,  -704,  3466,
    3466,  3466,  3466,  3466,  3466,  3466,  3466,  3466,  3466,  3466,
    3466,  3466,  3466,   665,  3466,   587,   666,  3466,  -704,  -704,
      55,    55,   -42,  -704,   723,   725,   -42,   726,  -704,   104,
    -704,   582,  -704,  -704,  -704,   444,   704,  -704,   729,    -4,
    -704,  -704,   704,  -704,  3466,   400,   594,  3466,   595,  3466,
     603,  -704,  -704,  -704,  -704,  3466,    -7,   321,  -704,   492,
    3964,   515,   509,  -704,  -704,   510,   357,    -8,    -8,    10,
     276,   276,   276,   276,   356,   356,  -704,  -704,  -704,  -704,
    -704,  -704,   452,  -704,  -704,  -704,  -704,   656,  -704,  -704,
     254,  -704,  -704,    19,  -704,  3466,  -704,  -704,  -704,  2818,
    -704,   597,   602,  -704,  -704,  -704,  -704,   738,   732,   117,
    -704,  -704,  3466,  -704,  -704,  -704,  -704,  -704,  -704,  -704,
    -704,  3466,  3034,   660,   607,   608,   609,   610,  -704,  3466,
     449,  -704,   742,  -704,   744,  3466,   663,  3466,  3466,   -20,
     664,   459,  3466,  -704,   730,   752,   730,  -704,   694,  -704,
    -704,  3466,  3466,   677,   489,   611,  -704,   255,   667,  -704,
      42,  -704,  -704,   777,  -704,  -704,  3466,   765,  -704,  -704,
      28,  -704,  -704,  -704,  -704,    31,  -704,   226,    66,  -704,
     616,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,
    -704,  -704,  -704,  -704,  -704,   546,   624,   570,   555,   630,
    -704,  -704,  -704,  -704,  -704,    27,   -42,    91,   120,   123,
      -1,  -704,   770,  -704,  -704,  -704,  -704,   283,   743,  -704,
    3466,   749,   621,  -704,  -704,   -47,  -704,  3466,   636,  3466,
    -704,  3466,  -704,   256,   645,  -704,  3682,  -704,  -704,  -704,
    -704,   133,   280,  -704,    -7,   133,  3682,  3682,  4010,  -704,
    -704,  -704,  -704,  -704,  -704,  -704,    -7,    -7,   280,  -704,
    -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,
    -704,  -704,  -704,  -704,  -704,   262,  -704,  -704,   772,   310,
     718,   775,   264,  -704,  -704,   266,  -704,  -704,  -704,  -704,
    -704,  -704,  -704,  -704,  -704,  -704,  3466,  -704,  -704,  3466,
     691,  3466,  -704,   724,   789,   780,   730,  -704,  -704,  3466,
    -704,  -704,  -704,  3250,   147,   367,  -704,  -704,   268,   640,
     797,  -704,   798,    50,   793,   669,   196,  -704,  -704,  -704,
    3466,   106,   570,  -704,  -704,  -704,  -704,  -704,  3682,  3682,
    3682,  3682,   802,   578,   794,  -704,   794,  -704,  -704,   743,
    -704,  -704,  -704,   806,  -704,  -704,  -704,  -704,  -704,  3466,
    -704,  -704,  -704,  -704,   276,  -704,  -704,  -704,   260,   515,
    -704,  -704,   211,  3682,  -704,  -704,   509,  -704,   575,  -704,
    -704,  -704,  -704,   310,  -704,  -704,  -704,  -704,  3466,  -704,
    3466,  -704,   694,  -704,  -704,   269,  -704,  -704,   804,   284,
    -704,  -704,  -704,  -704,   678,   431,  -704,  -704,  -704,  -704,
     670,   672,   818,   807,  3466,   813,  3466,  -704,   124,  -704,
     276,   276,   276,   143,   280,  -704,   125,  -704,   126,  -704,
    -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,
    -704,  -704,   730,  -704,  -704,  -704,  -704,  -704,  -704,  -704,
    -704,  -704,   673,   310,  -704,   679,  -704,   763,   727,  3682,
     596,   794,  -704,  -704,  -704,   681,  3466,   821,  -704,   276,
    -704,  -704,  3466,  -704,   129,  -704,   773,   727,   829,  -704,
     131,   776,   727,   831,  -704,   696,   727,  -704
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     0,     0,   294,   295,   291,     0,   439,     0,   285,
     288,   275,     0,     0,     0,   273,     0,     0,   311,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    82,     0,   274,   277,     0,
       0,     0,   317,   283,   313,     0,     0,     0,   279,   278,
       0,     0,     0,     0,   312,     0,     0,     0,   229,     0,
       0,     0,   284,     0,     0,   228,     0,   287,   286,     0,
       0,     0,   276,   258,     0,     0,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     4,     0,     0,     0,     0,    15,    17,    19,    20,
      21,    27,    22,    25,    26,    31,    32,    33,    28,    29,
      35,    36,    23,    30,   112,   109,   110,   111,    24,     9,
      94,    95,    97,     0,   121,   123,   124,    98,    99,   100,
     101,   191,   193,   195,   199,   202,   204,   207,   212,   215,
     218,   220,   222,   224,     0,   226,   232,   234,     0,   254,
     233,   261,   262,   265,   267,     0,   272,   269,     0,   280,
     290,   292,   266,   296,   301,   309,   302,   303,   304,   307,
     308,   305,   306,   324,   326,   327,   328,   325,   371,   372,
     373,   374,   375,   376,   289,   413,   405,   412,   411,   410,
     407,   409,   406,   408,   310,    34,   102,   103,   105,   104,
     106,   107,   108,   382,     0,   378,     0,     0,     0,     0,
       0,     0,   423,     0,   291,   281,     0,   419,    53,    38,
      39,    70,    71,     0,     0,    52,     0,     0,    46,    47,
       0,     0,     0,    44,    45,     0,     0,    79,     0,     0,
     415,     0,     0,   314,     0,     0,   429,     0,     0,     0,
     180,     0,   125,   126,     0,    62,     0,    54,     0,     0,
       0,     0,     0,     0,   138,   139,   315,     0,     0,   414,
       0,     0,     0,     0,   420,     0,   257,     0,     0,     0,
       0,   259,   260,     0,     0,     0,   418,     0,     0,     0,
       0,   367,     0,   440,   441,   442,   453,   454,     0,     0,
       0,     0,     0,     0,     0,   459,     0,   147,     0,   141,
       0,   510,   509,   514,   513,     0,   507,   508,   512,   516,
     534,   523,   545,   532,   511,   515,     0,     0,   544,    43,
     500,   501,   502,   503,   504,   505,   506,     1,     3,     5,
      10,     8,    12,    13,     0,     0,     0,     0,     0,     0,
     122,     0,     0,     0,     0,     0,   235,   249,   240,   239,
     247,   238,   237,   236,   248,   241,   246,   245,   244,   243,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     231,   230,   227,     0,   255,     0,     0,     0,   268,   298,
     271,   270,   282,   297,   383,   379,   320,   322,     0,     0,
       0,     0,     0,   424,     0,   426,   387,     0,     0,    40,
      41,     0,     0,     0,    42,     0,     0,     0,    67,     0,
       0,   377,   416,   417,     0,     0,   430,     0,   433,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     0,    55,    76,     0,    77,
       0,     0,     0,     0,   316,     0,   318,   369,   368,   421,
     422,   256,     0,     0,   428,   436,     0,     0,   329,     0,
       0,   337,   386,     0,   319,   250,   366,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   470,   543,
       0,     0,   533,   535,     0,     0,   530,     0,   518,     0,
     517,     0,    16,    18,    96,   164,   160,   162,     0,   149,
     153,   113,   161,   148,     0,     0,     0,     0,     0,     0,
     192,   194,   197,   196,   198,     0,     0,     0,   492,   200,
     471,   479,   481,   483,   485,   487,   490,   206,   205,   203,
     209,   210,   211,   208,   213,   214,   217,   216,   404,   403,
     397,   219,   395,   401,   402,   221,   223,   392,   225,   252,
       0,   263,   264,     0,   299,     0,   321,    80,   251,     0,
     437,     0,     0,    50,    51,    48,    49,     0,    72,     0,
      88,    83,     0,    84,    37,    85,    86,    87,   394,    66,
      69,     0,     0,   437,     0,     0,     0,     0,   182,     0,
       0,   179,     0,   128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    64,     0,    56,    60,     0,    78,
     143,     0,     0,     0,     0,     0,   388,     0,     0,   178,
       0,   362,   359,     0,   363,   364,     0,     0,   365,   358,
       0,   335,   361,   360,   330,     0,   338,     0,     0,   186,
       0,   446,   447,   444,   443,   445,   451,   452,   449,   448,
     450,   457,   455,   456,   461,     0,     0,     0,     0,     0,
     542,   541,   536,   537,   539,     0,   531,   526,     0,     0,
      14,   173,     0,   174,   175,   176,   165,   166,   167,   168,
       0,   155,     0,   158,   151,   150,   114,     0,     0,     0,
     117,     0,   115,     0,     0,   486,     0,   201,   499,   547,
     546,     0,     0,   548,     0,     0,     0,     0,   472,   476,
     494,   475,   498,   496,   495,   497,     0,     0,     0,   488,
     551,   552,   549,   550,   553,   491,   398,   400,   399,   396,
     393,   253,   300,   323,   384,     0,   425,   427,    90,     0,
       0,    73,     0,    68,   380,     0,   438,   431,   432,   434,
     435,   183,   181,   136,   137,   130,     0,   132,   129,     0,
       0,     0,   127,     0,     0,    63,    57,   145,   144,     0,
     140,    11,   389,     0,   348,   342,   339,   370,     0,     0,
       0,   336,     0,     0,     0,     0,     0,   187,     7,   460,
       0,     0,   462,   463,   142,   469,   540,   538,     0,     0,
       0,     0,     0,     0,     0,   521,     0,   519,   177,   169,
     170,   171,   163,     0,   156,   154,   159,   152,   118,     0,
     116,   119,   493,   489,   568,   567,   566,   562,     0,   480,
     561,   473,     0,     0,   478,   477,   482,   484,     0,   385,
      91,    74,    89,     0,    93,   381,   134,   131,     0,   133,
       0,    59,     0,   146,   390,     0,   356,   350,     0,   349,
     351,   357,   354,   344,     0,   343,   345,   355,    92,   331,
       0,     0,     0,     0,     0,     0,     0,   458,     0,   464,
     555,   556,   554,     0,   527,   528,     0,   524,     0,   172,
     157,   120,   565,   564,   563,   558,   559,   474,   560,    75,
     135,   190,    65,   391,   341,   352,   353,   340,   346,   347,
     332,   333,     0,     0,   188,     0,   184,     0,     0,     0,
       0,     0,   522,   520,   334,     0,     0,     0,   465,   557,
     529,   525,     0,   185,     0,   189,     0,     0,     0,   466,
       0,     0,     0,     0,   467,     0,     0,   468
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -704,  -704,  -704,   760,   761,  -704,   762,  -704,   511,   513,
    -341,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,
    -704,  -704,  -704,  -704,  -457,  -704,  -704,  -704,  -704,   236,
       8,  -704,  -704,  -704,  -704,  -704,  -704,    86,  -704,  -430,
     764,    49,    -6,  -704,  -704,   735,  -704,  -704,   228,   412,
    -259,  -513,  -704,  -704,   219,   173,  -509,   514,  -704,   150,
    -704,  -704,  -330,   521,   154,  -704,  -704,   163,  -664,  -704,
     801,   247,  -704,  -704,   203,  -704,  -704,   528,   530,   218,
    -643,   496,   217,  -381,   221,   233,  -704,  -704,  -704,  -704,
    -704,   733,  -704,  -704,  -704,  -704,  -704,  -704,   731,  -704,
     -49,  -704,  -704,  -704,  -704,  -704,  -704,  -704,    60,    57,
    -704,  -704,   160,   159,  -704,  -373,  -704,  -704,  -704,  -704,
    -704,  -704,  -704,  -704,  -704,  -469,  -704,   215,  -704,   401,
    -704,  -704,  -704,  -704,  -704,    -5,    -3,  -628,  -433,  -704,
    -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,   504,
    -245,  -393,  -704,  -704,   235,  -394,  -704,  -704,  -704,  -704,
    -704,  -704,  -704,   858,   861,   -80,   460,  -704,  -704,  -704,
    -704,  -704,  -704,  -704,  -704,   214,  -704,  -704,    84,  -704,
     350,  -704,  -704,   167,   161,   162,   361,  -704,  -704,   172,
    -704,  -531,  -704,  -704,  -704,  -704,    76,  -336,  -704,   397,
     118,  -704,  -488,  -704,  -704,  -704,  -704,  -703,  -704,  -704,
    -704,  -704,    52,   202,  -704
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   644,   270,   121,   122,   123,   432,
     124,   271,   125,   126,   127,   128,   609,   610,   668,   613,
     129,   130,   131,   132,   133,   134,   135,   262,   263,   456,
     457,   136,   274,   318,   275,   319,   361,   362,   539,   540,
     854,   725,   363,   536,   537,   716,   717,   718,   719,   137,
     259,   260,   138,   678,   679,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   381,   382,   383,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   408,   409,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   418,   182,   183,   184,   670,   490,   491,
     816,   904,   905,   898,   899,   906,   900,   671,   672,   185,
     186,   673,   187,   188,   189,   190,   191,   192,   193,   586,
     440,   581,   769,   582,   583,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   601,   625,   204,   205,   206,
     207,   208,   209,   210,   314,   315,   211,   832,   833,   212,
     559,   748,   560,   561,   562,   563,   564,   565,   566,   749,
     750,   339,   340,   341,   342,   343,   926,   927,   344,   522,
     526,   705,   523,   345,   346,   752,   765,   843,   753,   754,
     759,   755,   935,   867,   737
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       218,   530,   584,   584,   585,   616,   646,   570,   571,   572,
     573,   558,   533,   450,   471,   437,   458,   437,     7,   453,
     669,   453,   661,   662,   291,   292,   723,   247,   472,   751,
     724,   546,   548,   516,   702,   487,   300,   661,   662,   868,
     661,   662,   821,   584,   618,   722,   477,    18,   652,   513,
     214,   216,   836,   850,   851,   878,   520,   635,   663,   661,
     662,   220,    27,   487,    29,   226,    31,    32,   354,   451,
     388,    36,   422,   663,   225,   814,   663,    56,    44,   221,
     306,   307,   308,   309,   310,   311,   312,   470,   249,   217,
     320,   524,   255,   799,   254,   663,   454,   664,   638,   665,
     264,   389,   354,   871,   272,   243,   277,   488,   677,    54,
     280,   403,   664,   555,   665,   664,   385,   665,     3,   556,
      56,   390,   282,   354,   219,     4,   224,   295,   451,   297,
     298,   299,   283,   666,   664,   674,   665,   354,   385,   826,
     527,   386,   227,   287,   521,    66,   229,   233,   666,   244,
     896,   666,   236,   359,   424,   237,   661,   445,   447,   354,
     354,    63,   354,   386,   595,   230,   780,   391,   234,   844,
     666,   387,   846,   957,   961,   961,    63,   708,   976,    63,
     981,   525,   772,   558,   558,   929,   452,   478,   423,   667,
      77,   806,   837,   709,   489,   821,   359,   636,    63,   640,
     455,   669,   455,   815,   820,    77,   669,   822,    77,   301,
     517,   417,   856,   653,    83,   728,   857,   875,   702,   354,
     514,   960,   675,   469,   222,   410,   912,    77,   412,    83,
     937,   664,    83,   665,   223,   265,    97,   256,   455,   455,
     557,   455,   897,   455,   649,   486,   578,   257,   288,   354,
     414,    83,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    13,   666,   420,    36,
     425,   228,   284,   446,   448,   460,   474,   915,   493,    17,
     596,    76,   781,   584,   825,   845,   354,   896,   847,   958,
     962,   963,   354,   661,   977,   354,   982,   354,   354,   354,
     354,   354,   354,   354,   354,   354,    40,   824,    52,    53,
     515,   354,   607,   354,    46,   354,   267,   354,   354,   603,
     468,   437,   611,   838,   839,   497,   959,   411,   240,   392,
     578,   712,   415,   413,   840,   841,   242,   483,   235,   231,
     266,   393,   604,   612,   602,   579,     7,   842,   534,   535,
      13,   541,   535,   543,   669,   864,   591,   592,   232,    46,
     916,    60,   421,    17,   268,   624,   872,   626,   664,   533,
     665,   558,   245,   714,   715,    18,   661,    64,   241,   945,
     800,   901,   907,   558,   558,   584,   881,   865,   238,   239,
      40,   902,   866,    70,    71,   527,   608,   392,    46,   426,
     449,   615,   498,    85,   666,   441,    44,    79,   444,   393,
     476,   492,   494,   495,   598,   658,   771,   812,   862,   285,
     286,   269,   612,   246,   879,   580,   884,   597,   885,   579,
     908,   943,   528,   619,    97,   942,   250,    54,   248,    71,
     661,   555,     3,   628,   617,    60,   631,   556,   633,     4,
     224,   664,   590,   665,   394,   902,   593,   920,   921,   922,
     923,    64,   392,   903,   650,   932,   901,   437,   620,   253,
      13,   933,   907,   395,   393,   621,   258,    70,    71,   711,
     659,   435,   436,    17,   605,   529,   261,   666,   934,   584,
     939,    79,   712,   681,   682,   683,   684,   685,   686,   687,
     688,   689,   690,   691,   692,   693,   694,   606,   696,   580,
      40,   699,   838,   839,   932,   664,   273,   665,    46,    50,
     933,   713,   278,   840,   841,   355,   356,   948,   968,   355,
     279,   657,   438,   880,   714,   715,   281,   934,   726,   439,
      56,   730,   289,   732,   544,   355,   290,   979,   547,   405,
     406,   666,   984,   294,   358,   366,   987,   296,   358,   584,
     965,   355,   356,   367,   727,    60,   368,   594,   369,   302,
     594,   316,   594,   313,   358,   303,   304,   305,   969,   370,
     357,    64,   317,   371,   760,   761,   762,   763,   372,   773,
     358,   766,   767,   768,   373,   499,   500,    70,    71,   552,
     553,   554,   567,   568,   733,    76,   504,   505,   501,   502,
     503,    79,   764,   574,   575,   783,   359,   374,   347,   506,
     507,   508,   354,   791,   352,   971,   353,   576,   577,   795,
     364,   797,   798,   587,   587,   365,   803,   397,   700,   701,
     384,   398,   396,   399,   407,   807,   808,   419,   775,   427,
     428,   375,   376,   377,   378,   379,   380,   429,     1,   430,
     431,   782,   433,   434,   442,     2,     3,   443,   459,   464,
     461,   785,   462,     4,     5,   463,   465,   466,   473,     7,
     475,   479,     8,   480,     9,    10,   481,   482,   496,   484,
     485,   510,    11,    12,    13,    14,   509,   511,   512,   518,
     519,    15,   538,   549,   578,    55,    16,    17,    18,   599,
     600,   614,   623,   622,   535,   818,   630,   629,   632,   637,
     643,   858,   634,   860,   641,   861,   645,   642,   651,    37,
      38,   648,   655,    39,    40,    41,    42,    43,   647,    44,
     654,    45,    46,   660,   677,   680,   695,   698,   703,   697,
     704,   707,   710,   720,    48,    49,   721,   736,   729,   731,
     756,   757,   776,   758,   770,   778,   779,   777,   786,   793,
      54,   794,   787,   788,   789,   790,   796,   801,   805,   804,
      57,   811,   400,   809,   817,   819,   828,   813,   830,    60,
     886,   712,   835,   887,   831,   889,   848,   853,    61,   607,
     859,    62,    63,   893,   888,    64,   437,   401,    66,   883,
     863,    67,    68,   890,    69,   891,   892,   910,   911,   909,
     913,    70,    71,    72,   917,    73,    74,   924,   925,    76,
     527,    77,   930,   914,    78,    79,   938,   944,   952,   947,
     955,   953,    81,   966,   967,   972,   970,   612,   974,   950,
      82,   951,   964,   931,   978,    83,   980,   983,   985,   348,
     349,   986,   895,   531,   350,   532,   882,   351,   360,   802,
     639,   834,   855,   810,   852,   545,   293,   792,     1,   542,
     849,   827,   940,   569,   941,     2,     3,   402,   918,   404,
     823,   676,   550,     4,     5,   551,   946,     6,   251,     7,
     949,   252,     8,   588,     9,    10,   734,   627,   954,   829,
     956,   869,    11,    12,    13,    14,   919,   876,   735,   877,
     874,    15,   928,   706,   936,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,   870,     0,    37,
      38,     0,     0,    39,    40,    41,    42,    43,     0,    44,
     973,    45,    46,     0,     0,     0,   975,     0,     0,     0,
       0,    47,     0,     0,    48,    49,     0,    50,     0,     0,
       0,     0,     0,     0,    51,    52,    53,     0,     0,     0,
      54,     0,     0,     0,    55,     0,     0,     0,    56,     0,
      57,     0,    58,     0,    59,     0,     0,     0,     0,    60,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
       0,    62,    63,     0,     0,    64,     0,    65,    66,     0,
       0,    67,    68,     0,    69,     0,     0,     0,     0,     0,
       0,    70,    71,    72,     0,    73,    74,    75,     0,    76,
       0,    77,     0,     0,    78,    79,     0,     0,     0,    80,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,    83,     0,    84,     0,     0,
      85,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,     1,    93,     0,    94,     0,    95,
      96,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,    97,     0,     6,     0,     7,     0,     0,     8,     0,
       9,    10,     0,     0,     0,     0,     0,     0,    11,    12,
      13,    14,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,    37,    38,     0,     0,    39,
      40,    41,    42,    43,     0,    44,     0,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
      48,    49,     0,    50,     0,     0,     0,     0,     0,     0,
      51,    52,    53,     0,     0,     0,    54,     0,     0,     0,
      55,     0,     0,     0,    56,     0,    57,     0,    58,     0,
      59,     0,     0,     0,     0,    60,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     0,     0,    62,    63,     0,
       0,    64,     0,    65,    66,     0,     0,    67,    68,     0,
      69,     0,     0,     0,     0,     0,     0,    70,    71,    72,
       0,    73,    74,    75,     0,    76,     0,    77,     0,     0,
      78,    79,     0,     0,     0,    80,     0,     0,    81,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,    83,     0,     0,     0,     0,    85,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
       1,    93,     0,    94,     0,    95,    96,     2,     3,     0,
       0,     0,     0,     0,     0,     4,     5,    97,     0,     6,
       0,     7,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,     0,     0,    11,    12,    13,    14,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,    16,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,     0,     0,
       0,    37,    38,     0,     0,    39,    40,    41,    42,    43,
       0,    44,     0,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,    48,    49,     0,    50,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,    54,     0,     0,     0,    55,     0,     0,     0,
      56,     0,    57,     0,    58,     0,     0,     0,     0,     0,
       0,    60,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,    62,    63,     0,     0,    64,     0,    65,
      66,     0,     0,    67,    68,     0,    69,     0,   213,     0,
       0,     0,     0,    70,    71,    72,     0,    73,    74,    75,
       0,    76,     0,    77,     0,     0,    78,    79,     0,     0,
       0,    80,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,     1,    93,     0,    94,
       0,    95,    96,     2,     3,     0,     0,     0,     0,     0,
       0,     4,     5,     0,     0,     6,     0,     7,     0,     0,
       8,     0,     9,    10,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,    16,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,     0,     0,     0,    37,    38,     0,
       0,    39,    40,    41,    42,    43,     0,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,    48,    49,     0,    50,     0,     0,     0,     0,
       0,     0,    51,     0,     0,     0,     0,     0,    54,     0,
       0,     0,    55,     0,     0,     0,    56,     0,    57,     0,
      58,     0,     0,     0,     0,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     0,     0,    61,     0,     0,    62,
      63,     0,     0,    64,     0,    65,    66,     0,     0,    67,
      68,     0,    69,     0,   215,     0,     0,     0,     0,    70,
      71,    72,     0,    73,    74,    75,     0,    76,     0,    77,
       0,     0,    78,    79,     0,     0,     0,    80,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,     1,    93,     0,    94,     0,    95,    96,     2,
       3,     0,     0,     0,     0,     0,     0,     4,     5,     0,
       0,     6,     0,     7,     0,     0,     8,     0,     9,    10,
       0,     0,     0,     0,     0,     0,    11,    12,    13,    14,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
      16,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
       0,     0,     0,    37,    38,     0,     0,    39,    40,    41,
      42,    43,     0,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,    48,    49,
       0,    50,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,    54,     0,     0,     0,    55,     0,
       0,     0,    56,     0,    57,     0,    58,     0,     0,     0,
       0,     0,     0,    60,     0,     0,     0,     0,     0,     0,
       0,     0,    61,     0,     0,    62,    63,     0,     0,    64,
       0,    65,    66,     0,     0,    67,    68,     0,    69,     0,
       0,     0,     0,   276,     0,    70,    71,    72,     0,    73,
      74,    75,     0,    76,     0,    77,     0,     0,    78,    79,
       0,     0,     0,    80,     0,     0,    81,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,     1,    93,
       0,    94,     0,    95,    96,     2,     3,     0,     0,     0,
       0,     0,     0,     4,     5,     0,     0,     6,     0,     7,
       0,     0,     8,     0,     9,    10,     0,     0,     0,     0,
       0,     0,    11,    12,    13,    14,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,     0,     0,     0,    37,
      38,     0,     0,    39,    40,    41,    42,    43,     0,    44,
       0,    45,    46,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,    48,    49,     0,    50,     0,     0,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
      54,     0,     0,     0,    55,     0,     0,     0,    56,     0,
      57,     0,    58,     0,     0,     0,     0,     0,     0,    60,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
       0,    62,    63,     0,     0,    64,     0,    65,    66,     0,
       0,    67,    68,     0,    69,     0,     0,     0,     0,   416,
       0,    70,    71,    72,     0,    73,    74,    75,     0,    76,
       0,    77,     0,     0,    78,    79,     0,     0,     0,    80,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,     1,    93,     0,    94,     0,    95,
      96,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     6,     0,     7,     0,     0,     8,     0,
       9,    10,     0,     0,     0,     0,     0,     0,    11,    12,
      13,    14,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,    16,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,     0,     0,     0,    37,    38,     0,     0,    39,
      40,    41,    42,    43,     0,    44,     0,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
      48,    49,     0,    50,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,    54,     0,     0,     0,
      55,     0,     0,     0,    56,     0,    57,     0,    58,     0,
       0,     0,     0,     0,     0,    60,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     0,     0,    62,    63,     0,
       0,    64,     0,    65,    66,     0,     0,    67,    68,     0,
      69,     0,   467,     0,     0,     0,     0,    70,    71,    72,
       0,    73,    74,    75,     0,    76,     0,    77,     0,     0,
      78,    79,     0,     0,     0,    80,     0,     0,    81,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
       1,    93,     0,    94,     0,    95,    96,     2,     3,     0,
       0,     0,     0,     0,     0,     4,     5,     0,     0,     6,
       0,     7,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,     0,     0,    11,    12,    13,    14,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,    16,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,     0,     0,
       0,    37,    38,     0,     0,    39,    40,    41,    42,    43,
       0,    44,     0,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,    48,    49,     0,    50,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,    54,     0,     0,     0,    55,     0,     0,     0,
      56,     0,    57,     0,    58,     0,     0,     0,     0,     0,
       0,    60,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,    62,    63,     0,     0,    64,     0,    65,
      66,     0,     0,    67,    68,     0,    69,     0,   589,     0,
       0,     0,     0,    70,    71,    72,     0,    73,    74,    75,
       0,    76,     0,    77,     0,     0,    78,    79,     0,     0,
       0,    80,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,     1,    93,     0,    94,
       0,    95,    96,     2,     3,     0,     0,     0,     0,     0,
       0,     4,     5,     0,     0,     6,     0,     7,     0,     0,
       8,     0,     9,    10,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,    16,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,     0,     0,     0,    37,    38,     0,
       0,    39,    40,    41,    42,    43,     0,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,    48,    49,     0,    50,     0,     0,     0,     0,
       0,     0,    51,     0,     0,     0,     0,     0,    54,     0,
       0,     0,    55,     0,     0,     0,    56,     0,    57,     0,
      58,     0,     0,     0,     0,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     0,     0,    61,     0,     0,    62,
      63,     0,     0,    64,     0,    65,    66,     0,     0,    67,
      68,     0,    69,     0,   656,     0,     0,     0,     0,    70,
      71,    72,     0,    73,    74,    75,     0,    76,     0,    77,
       0,     0,    78,    79,     0,     0,     0,    80,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,     1,    93,     0,    94,     0,    95,    96,     2,
       3,     0,     0,     0,     0,     0,     0,     4,     5,     0,
       0,     6,     0,     7,     0,     0,     8,     0,     9,    10,
       0,     0,     0,     0,     0,     0,    11,    12,    13,    14,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
      16,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
       0,     0,     0,    37,    38,     0,     0,    39,    40,    41,
      42,    43,     0,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,    48,    49,
       0,    50,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,    54,     0,     0,     0,    55,     0,
       0,     0,    56,     0,    57,     0,    58,     0,     0,     0,
       0,     0,     0,    60,     0,     0,     0,     0,     0,     0,
       0,     0,    61,     0,     0,    62,    63,     0,     0,    64,
       0,    65,    66,     0,     0,    67,    68,     0,    69,     0,
     774,     0,     0,     0,     0,    70,    71,    72,     0,    73,
      74,    75,     0,    76,     0,    77,     0,     0,    78,    79,
       0,     0,     0,    80,     0,     0,    81,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,     1,    93,
       0,    94,     0,    95,    96,     2,     3,     0,     0,     0,
       0,     0,     0,     4,     5,     0,     0,     6,     0,     7,
       0,     0,     8,     0,     9,    10,     0,     0,     0,     0,
       0,     0,    11,    12,    13,    14,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,     0,     0,     0,    37,
      38,     0,     0,    39,    40,    41,    42,    43,     0,    44,
       0,    45,    46,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,    48,    49,     0,    50,     0,     0,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
      54,     0,     0,     0,    55,     0,     0,     0,    56,     0,
      57,     0,    58,     0,     0,     0,     0,     0,     0,    60,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
       0,    62,    63,     0,     0,    64,     0,    65,    66,     0,
       0,    67,    68,     0,    69,     0,   784,     0,     0,     0,
       0,    70,    71,    72,     0,    73,    74,    75,     0,    76,
       0,    77,     0,     0,    78,    79,     0,     0,     0,    80,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,     1,    93,     0,    94,     0,    95,
      96,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     6,     0,     7,     0,     0,     8,     0,
       9,    10,     0,     0,     0,     0,     0,     0,    11,    12,
      13,    14,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,    16,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,     0,     0,     0,    37,    38,     0,     0,    39,
      40,    41,    42,    43,     0,    44,     0,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
      48,    49,     0,    50,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,    54,     0,     0,     0,
      55,     0,     0,     0,    56,     0,    57,     0,    58,     0,
       0,     0,     0,     0,     0,    60,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     0,     0,    62,    63,     0,
       0,    64,     0,    65,    66,     0,     0,    67,    68,     0,
      69,     0,   894,     0,     0,     0,     0,    70,    71,    72,
       0,    73,    74,    75,     0,    76,     0,    77,     0,     0,
      78,    79,     0,     0,     0,    80,     0,     0,    81,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
       1,    93,     0,    94,     0,    95,    96,     2,     3,     0,
       0,     0,     0,     0,     0,     4,     5,     0,     0,     6,
       0,     7,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,     0,     0,    11,    12,    13,    14,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,    16,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,     0,     0,
       0,    37,    38,     0,     0,    39,    40,    41,    42,    43,
       0,    44,     0,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,    48,    49,     0,    50,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,    54,     0,     0,     0,    55,     0,     0,     0,
      56,     0,    57,     0,    58,     0,     0,     0,     0,     0,
       0,    60,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,    62,    63,     0,     0,    64,     0,    65,
      66,     0,     0,    67,    68,     0,    69,     0,     0,     0,
       0,     0,     0,    70,    71,    72,     0,    73,    74,    75,
       0,    76,     0,    77,     0,     0,    78,    79,     0,     0,
       0,    80,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,     1,    93,     0,    94,
       0,    95,    96,     2,     3,     0,     0,     0,     0,     0,
       0,     4,     5,     0,     0,     0,     0,     7,     0,     0,
       8,     0,     9,    10,   321,   322,     0,   323,   324,     0,
      11,    12,    13,    14,     0,     0,     0,     0,   325,    15,
     326,     0,     0,     0,    16,    17,    18,     0,     0,     0,
       0,   327,     0,     0,     0,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,     0,    37,    38,     0,
       0,    39,    40,    41,    42,    43,     0,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
      58,     0,     0,     0,     0,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     0,     0,    61,     0,     0,    62,
      63,     0,     0,    64,     0,    65,    66,     0,     0,    67,
      68,     0,    69,     0,     0,     0,     0,     0,     0,    70,
      71,    72,     0,    73,    74,     0,     0,    76,     1,    77,
       0,     0,    78,    79,     0,     2,     3,     0,     0,     0,
      81,     0,     0,     4,     5,     0,     0,     0,    82,     7,
       0,     0,     0,    83,     9,    10,     0,     0,     0,     0,
       0,     0,    11,    12,    13,    14,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      38,     0,     0,    39,    40,    41,    42,    43,     0,    44,
       0,    45,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    60,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
       0,    62,    63,     0,     0,    64,     0,     0,     0,     0,
       0,    67,    68,     0,    69,     0,     0,     1,     0,     0,
       0,    70,    71,    72,     2,     3,     0,     0,     0,    76,
       0,    77,     4,     5,    78,    79,     0,     0,     7,     0,
       0,     0,    81,     9,    10,     0,     0,     0,     0,     0,
       0,    11,    12,    13,    14,    83,     0,     0,     0,     0,
      15,     0,     0,     0,     0,    16,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,    38,
       0,     0,    39,    40,    41,    42,    43,     0,    44,     0,
      45,    46,     0,     0,     0,     0,     0,   738,     0,     0,
       0,     0,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,     0,   738,     0,     0,     0,    61,     0,     0,
      62,    63,     0,     0,    64,     0,     0,     0,     0,     0,
      67,    68,     0,    69,     0,     0,     0,     0,     0,     0,
      70,    71,    72,     0,     0,     0,     0,     0,     0,     0,
      77,     0,     0,    78,    79,   739,     0,     0,   740,   321,
     322,    81,   323,   324,   741,   742,   743,     0,     0,     0,
       0,     0,   744,   325,    83,   326,     0,     0,     0,     0,
       0,   745,     0,     0,     0,     0,   327,   746,   747,     0,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   739,     0,     0,   740,   321,   322,     0,   323,   324,
     741,   742,   743,     0,     0,     0,     0,     0,     0,   325,
       0,   326,     0,     0,     0,     0,     0,   745,     0,     0,
       0,     0,   327,   873,   747,     0,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         6,   337,   396,   397,   397,   435,   463,   388,   389,   390,
     391,   384,   353,   258,   273,    34,   261,    34,    25,    36,
     489,    36,     9,    10,    73,    74,   539,    33,   273,   560,
     539,   361,   362,    49,   522,    20,    29,     9,    10,   742,
       9,    10,   670,   437,   437,    49,     8,    54,   106,    49,
       1,     2,    25,   717,   718,   758,    98,   113,    45,     9,
      10,    12,    63,    20,    65,    16,    67,    68,    49,    49,
      78,    72,    49,    45,    14,    33,    45,   124,    85,    20,
      86,    87,    88,    89,    90,    91,    92,   106,    39,   126,
      96,    36,    20,   113,    45,    45,   113,    84,   113,    86,
      51,   109,    49,   746,    55,   143,    57,    92,    42,   116,
      61,   120,    84,   120,    86,    84,   128,    86,    12,   126,
     124,   129,    15,    49,   120,    19,    20,    78,    49,    80,
      81,    82,    25,   120,    84,    92,    86,    49,   128,    73,
      36,   153,   165,    15,   186,   154,   159,   138,   120,   187,
       3,   120,   131,   200,    49,   131,     9,    49,    49,    49,
      49,   148,    49,   153,    49,   178,    49,   175,   159,    49,
     120,   183,    49,    49,    49,    49,   148,    73,    49,   148,
      49,   126,   163,   556,   557,   849,   166,   149,   165,   176,
     177,   648,   165,   529,   179,   823,   200,   456,   148,   458,
     258,   670,   258,   161,   176,   177,   675,   176,   177,   202,
     226,   217,   725,   472,   201,   545,   725,   748,   706,    49,
     220,   924,   179,   170,   165,   165,   176,   177,   168,   201,
     873,    84,   201,    86,   175,    26,   237,   165,   258,   258,
     247,   258,    95,   258,   170,   166,    20,   175,   120,    49,
     162,   201,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    40,   120,   219,    72,
     165,    26,   165,   165,   165,   165,   165,    81,   165,    53,
     165,   175,   165,   677,   677,   165,    49,     3,   165,   165,
     165,   165,    49,     9,   165,    49,   165,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    80,    81,   111,   112,
     316,    49,    81,    49,    88,    49,    26,    49,    49,   114,
     271,    34,    99,   232,   233,    93,   183,   167,    20,   186,
      20,    48,   162,   173,   243,   244,    20,   288,    26,   159,
     131,   198,   137,   120,   424,   119,    25,   256,   354,   355,
      40,   357,   358,   359,   823,   736,   405,   406,   178,    88,
     164,   135,   162,    53,    74,   445,   747,   447,    84,   710,
      86,   744,    20,    90,    91,    54,     9,   151,    15,    95,
     639,   814,   815,   756,   757,   779,   779,   254,    90,    91,
      80,    24,   259,   167,   168,    36,   165,   186,    88,   162,
     113,    99,   170,   206,   120,   162,    85,   181,   162,   198,
     162,   162,   162,   162,   162,   162,   162,   162,   162,    20,
      21,   131,   120,    20,   162,   199,   162,   419,   162,   119,
     162,   162,    73,   439,   237,   892,   165,   116,    27,   168,
       9,   120,    12,   449,   436,   135,   452,   126,   454,    19,
      20,    84,   403,    86,    98,    24,   407,   838,   839,   840,
     841,   151,   186,    96,   470,   254,   899,    34,    99,    27,
      40,   260,   905,   117,   198,   106,    27,   167,   168,    35,
     486,   245,   246,    53,   114,   126,    27,   120,   277,   883,
     883,   181,    48,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   137,   514,   199,
      80,   517,   232,   233,   254,    84,    27,    86,    88,   103,
     260,    77,    15,   243,   244,   145,   146,    96,   958,   145,
     165,   482,    99,   778,    90,    91,    17,   277,   544,   106,
     124,   547,    20,   549,   164,   145,    20,   977,   164,   171,
     172,   120,   982,    20,   174,    94,   986,   165,   174,   953,
     953,   145,   146,   102,   164,   135,   105,   408,   107,    25,
     411,   120,   413,    27,   174,   207,   208,   209,   959,   118,
     164,   151,    27,   122,   227,   228,   229,   230,   127,   595,
     174,   139,   140,   141,   133,   204,   205,   167,   168,   381,
     382,   383,   385,   386,   555,   175,   204,   205,   217,   218,
     219,   181,   255,   392,   393,   621,   200,   156,     0,   217,
     218,   219,    49,   629,   170,   961,   170,   394,   395,   635,
     142,   637,   638,   398,   399,    32,   642,   184,   520,   521,
     246,    43,   115,    44,   121,   651,   652,   165,   599,    49,
      49,   190,   191,   192,   193,   194,   195,    26,     4,    26,
     126,   612,    94,    25,   165,    11,    12,   165,    49,   131,
      36,   622,    15,    19,    20,    36,    15,    26,    49,    25,
      94,   165,    28,   165,    30,    31,    18,   120,   202,   165,
     165,   222,    38,    39,    40,    41,    34,   222,   106,   162,
      25,    47,    81,   164,    20,   120,    52,    53,    54,   120,
      20,    26,    20,   120,   720,   666,    81,   113,    81,   113,
      26,   727,    81,   729,    81,   731,    94,   182,   106,    75,
      76,    36,    26,    79,    80,    81,    82,    83,    94,    85,
      81,    87,    88,    94,    42,    25,    81,    81,    25,   162,
      25,    25,   170,    49,   100,   101,    27,   265,   164,   164,
     245,   252,   165,   253,   108,    27,    34,   165,   108,    27,
     116,    27,   165,   165,   165,   165,   113,   113,    26,    49,
     126,   170,   128,   106,     7,    20,   170,   120,   164,   135,
     796,    48,   162,   799,   224,   801,    26,    48,   144,    81,
     164,   147,   148,   809,   113,   151,    34,   153,   154,    34,
     165,   157,   158,    89,   160,    26,    36,    20,    20,   179,
      27,   167,   168,   169,   830,   171,   172,    25,   250,   175,
      36,   177,    26,   164,   180,   181,   261,    33,    20,   161,
      27,    34,   188,   164,    81,   164,   250,   120,    27,   179,
     196,   179,   179,   859,    81,   201,    27,    81,    27,    99,
      99,   165,   813,   352,   102,   352,   780,   103,   133,   641,
     458,   698,   722,   654,   720,   361,    75,   630,     4,   358,
     717,   678,   888,   387,   890,    11,    12,   154,   831,   158,
     675,   490,   364,    19,    20,   365,   899,    23,    40,    25,
     905,    40,    28,   399,    30,    31,   556,   447,   914,   695,
     916,   744,    38,    39,    40,    41,   832,   756,   557,   757,
     748,    47,   846,   526,   872,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,   745,    -1,    75,
      76,    -1,    -1,    79,    80,    81,    82,    83,    -1,    85,
     966,    87,    88,    -1,    -1,    -1,   972,    -1,    -1,    -1,
      -1,    97,    -1,    -1,   100,   101,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,    -1,    -1,    -1,
     116,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,    -1,
     126,    -1,   128,    -1,   130,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
      -1,   147,   148,    -1,    -1,   151,    -1,   153,   154,    -1,
      -1,   157,   158,    -1,   160,    -1,    -1,    -1,    -1,    -1,
      -1,   167,   168,   169,    -1,   171,   172,   173,    -1,   175,
      -1,   177,    -1,    -1,   180,   181,    -1,    -1,    -1,   185,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,   201,    -1,   203,    -1,    -1,
     206,    -1,    -1,    -1,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,     4,   221,    -1,   223,    -1,   225,
     226,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,   237,    -1,    23,    -1,    25,    -1,    -1,    28,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    75,    76,    -1,    -1,    79,
      80,    81,    82,    83,    -1,    85,    -1,    87,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,
     100,   101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,    -1,    -1,    -1,   116,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   124,    -1,   126,    -1,   128,    -1,
     130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    -1,    -1,   147,   148,    -1,
      -1,   151,    -1,   153,   154,    -1,    -1,   157,   158,    -1,
     160,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,   169,
      -1,   171,   172,   173,    -1,   175,    -1,   177,    -1,    -1,
     180,   181,    -1,    -1,    -1,   185,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
       4,   221,    -1,   223,    -1,   225,   226,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,   237,    -1,    23,
      -1,    25,    -1,    -1,    28,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    -1,    -1,
      -1,    75,    76,    -1,    -1,    79,    80,    81,    82,    83,
      -1,    85,    -1,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    -1,   100,   101,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,
     124,    -1,   126,    -1,   128,    -1,    -1,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,    -1,    -1,   147,   148,    -1,    -1,   151,    -1,   153,
     154,    -1,    -1,   157,   158,    -1,   160,    -1,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,    -1,   171,   172,   173,
      -1,   175,    -1,   177,    -1,    -1,   180,   181,    -1,    -1,
      -1,   185,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,     4,   221,    -1,   223,
      -1,   225,   226,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    -1,    -1,    23,    -1,    25,    -1,    -1,
      28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    52,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    -1,    -1,    -1,    75,    76,    -1,
      -1,    79,    80,    81,    82,    83,    -1,    85,    -1,    87,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,   100,   101,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,   120,    -1,    -1,    -1,   124,    -1,   126,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,   147,
     148,    -1,    -1,   151,    -1,   153,   154,    -1,    -1,   157,
     158,    -1,   160,    -1,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,    -1,   171,   172,   173,    -1,   175,    -1,   177,
      -1,    -1,   180,   181,    -1,    -1,    -1,   185,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,     4,   221,    -1,   223,    -1,   225,   226,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,
      -1,    23,    -1,    25,    -1,    -1,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      -1,    -1,    -1,    75,    76,    -1,    -1,    79,    80,    81,
      82,    83,    -1,    85,    -1,    87,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,   101,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,
      -1,    -1,   124,    -1,   126,    -1,   128,    -1,    -1,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,    -1,    -1,   147,   148,    -1,    -1,   151,
      -1,   153,   154,    -1,    -1,   157,   158,    -1,   160,    -1,
      -1,    -1,    -1,   165,    -1,   167,   168,   169,    -1,   171,
     172,   173,    -1,   175,    -1,   177,    -1,    -1,   180,   181,
      -1,    -1,    -1,   185,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,     4,   221,
      -1,   223,    -1,   225,   226,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    -1,    -1,    23,    -1,    25,
      -1,    -1,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    52,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,    75,
      76,    -1,    -1,    79,    80,    81,    82,    83,    -1,    85,
      -1,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    -1,    -1,   100,   101,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
     116,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,    -1,
     126,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
      -1,   147,   148,    -1,    -1,   151,    -1,   153,   154,    -1,
      -1,   157,   158,    -1,   160,    -1,    -1,    -1,    -1,   165,
      -1,   167,   168,   169,    -1,   171,   172,   173,    -1,   175,
      -1,   177,    -1,    -1,   180,   181,    -1,    -1,    -1,   185,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,     4,   221,    -1,   223,    -1,   225,
     226,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    23,    -1,    25,    -1,    -1,    28,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    -1,    -1,    -1,    75,    76,    -1,    -1,    79,
      80,    81,    82,    83,    -1,    85,    -1,    87,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,
     100,   101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   124,    -1,   126,    -1,   128,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    -1,    -1,   147,   148,    -1,
      -1,   151,    -1,   153,   154,    -1,    -1,   157,   158,    -1,
     160,    -1,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
      -1,   171,   172,   173,    -1,   175,    -1,   177,    -1,    -1,
     180,   181,    -1,    -1,    -1,   185,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
       4,   221,    -1,   223,    -1,   225,   226,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,
      -1,    25,    -1,    -1,    28,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    -1,    -1,
      -1,    75,    76,    -1,    -1,    79,    80,    81,    82,    83,
      -1,    85,    -1,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    -1,   100,   101,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,
     124,    -1,   126,    -1,   128,    -1,    -1,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,    -1,    -1,   147,   148,    -1,    -1,   151,    -1,   153,
     154,    -1,    -1,   157,   158,    -1,   160,    -1,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,    -1,   171,   172,   173,
      -1,   175,    -1,   177,    -1,    -1,   180,   181,    -1,    -1,
      -1,   185,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,     4,   221,    -1,   223,
      -1,   225,   226,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    -1,    -1,    23,    -1,    25,    -1,    -1,
      28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    52,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    -1,    -1,    -1,    75,    76,    -1,
      -1,    79,    80,    81,    82,    83,    -1,    85,    -1,    87,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,   100,   101,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,   120,    -1,    -1,    -1,   124,    -1,   126,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,   147,
     148,    -1,    -1,   151,    -1,   153,   154,    -1,    -1,   157,
     158,    -1,   160,    -1,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,    -1,   171,   172,   173,    -1,   175,    -1,   177,
      -1,    -1,   180,   181,    -1,    -1,    -1,   185,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,     4,   221,    -1,   223,    -1,   225,   226,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,
      -1,    23,    -1,    25,    -1,    -1,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      -1,    -1,    -1,    75,    76,    -1,    -1,    79,    80,    81,
      82,    83,    -1,    85,    -1,    87,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,   101,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,
      -1,    -1,   124,    -1,   126,    -1,   128,    -1,    -1,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,    -1,    -1,   147,   148,    -1,    -1,   151,
      -1,   153,   154,    -1,    -1,   157,   158,    -1,   160,    -1,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,    -1,   171,
     172,   173,    -1,   175,    -1,   177,    -1,    -1,   180,   181,
      -1,    -1,    -1,   185,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,     4,   221,
      -1,   223,    -1,   225,   226,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    -1,    -1,    23,    -1,    25,
      -1,    -1,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    52,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,    75,
      76,    -1,    -1,    79,    80,    81,    82,    83,    -1,    85,
      -1,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    -1,    -1,   100,   101,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
     116,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,    -1,
     126,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
      -1,   147,   148,    -1,    -1,   151,    -1,   153,   154,    -1,
      -1,   157,   158,    -1,   160,    -1,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,    -1,   171,   172,   173,    -1,   175,
      -1,   177,    -1,    -1,   180,   181,    -1,    -1,    -1,   185,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,     4,   221,    -1,   223,    -1,   225,
     226,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    23,    -1,    25,    -1,    -1,    28,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    -1,    -1,    -1,    75,    76,    -1,    -1,    79,
      80,    81,    82,    83,    -1,    85,    -1,    87,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,
     100,   101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   124,    -1,   126,    -1,   128,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    -1,    -1,   147,   148,    -1,
      -1,   151,    -1,   153,   154,    -1,    -1,   157,   158,    -1,
     160,    -1,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
      -1,   171,   172,   173,    -1,   175,    -1,   177,    -1,    -1,
     180,   181,    -1,    -1,    -1,   185,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
       4,   221,    -1,   223,    -1,   225,   226,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,
      -1,    25,    -1,    -1,    28,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    -1,    -1,
      -1,    75,    76,    -1,    -1,    79,    80,    81,    82,    83,
      -1,    85,    -1,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    -1,   100,   101,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,
     124,    -1,   126,    -1,   128,    -1,    -1,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,    -1,    -1,   147,   148,    -1,    -1,   151,    -1,   153,
     154,    -1,    -1,   157,   158,    -1,   160,    -1,    -1,    -1,
      -1,    -1,    -1,   167,   168,   169,    -1,   171,   172,   173,
      -1,   175,    -1,   177,    -1,    -1,   180,   181,    -1,    -1,
      -1,   185,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,     4,   221,    -1,   223,
      -1,   225,   226,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    31,   235,   236,    -1,   238,   239,    -1,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,   249,    47,
     251,    -1,    -1,    -1,    52,    53,    54,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,    -1,    75,    76,    -1,
      -1,    79,    80,    81,    82,    83,    -1,    85,    -1,    87,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,   147,
     148,    -1,    -1,   151,    -1,   153,   154,    -1,    -1,   157,
     158,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,   167,
     168,   169,    -1,   171,   172,    -1,    -1,   175,     4,   177,
      -1,    -1,   180,   181,    -1,    11,    12,    -1,    -1,    -1,
     188,    -1,    -1,    19,    20,    -1,    -1,    -1,   196,    25,
      -1,    -1,    -1,   201,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    52,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    -1,    -1,    79,    80,    81,    82,    83,    -1,    85,
      -1,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
      -1,   147,   148,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,   157,   158,    -1,   160,    -1,    -1,     4,    -1,    -1,
      -1,   167,   168,   169,    11,    12,    -1,    -1,    -1,   175,
      -1,   177,    19,    20,   180,   181,    -1,    -1,    25,    -1,
      -1,    -1,   188,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,   201,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    52,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      -1,    -1,    79,    80,    81,    82,    83,    -1,    85,    -1,
      87,    88,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,   143,    -1,    -1,    -1,   144,    -1,    -1,
     147,   148,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,
     157,   158,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,    -1,    -1,   180,   181,   231,    -1,    -1,   234,   235,
     236,   188,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,    -1,   248,   249,   201,   251,    -1,    -1,    -1,    -1,
      -1,   257,    -1,    -1,    -1,    -1,   262,   263,   264,    -1,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   231,    -1,    -1,   234,   235,   236,    -1,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,    -1,    -1,   249,
      -1,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   262,   263,   264,    -1,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,     4,    11,    12,    19,    20,    23,    25,    28,    30,
      31,    38,    39,    40,    41,    47,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    75,    76,    79,
      80,    81,    82,    83,    85,    87,    88,    97,   100,   101,
     103,   110,   111,   112,   116,   120,   124,   126,   128,   130,
     135,   144,   147,   148,   151,   153,   154,   157,   158,   160,
     167,   168,   169,   171,   172,   173,   175,   177,   180,   181,
     185,   188,   196,   201,   203,   206,   210,   211,   212,   213,
     214,   215,   216,   221,   223,   225,   226,   237,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   315,   316,   317,   319,   321,   322,   323,   324,   329,
     330,   331,   332,   333,   334,   335,   340,   358,   361,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   413,   414,   415,   428,   429,   431,   432,   433,
     434,   435,   436,   437,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   456,   457,   458,   459,   460,   461,
     462,   465,   468,   162,   330,   162,   330,   126,   331,   120,
     330,    20,   165,   175,    20,   397,   330,   165,    26,   159,
     178,   159,   178,   138,   159,    26,   131,   131,    90,    91,
      20,    15,    20,   143,   187,    20,    20,   331,    27,   330,
     165,   452,   453,    27,   330,    20,   165,   175,    27,   359,
     360,    27,   336,   337,   330,    26,   131,    26,    74,   131,
     314,   320,   330,    27,   341,   343,   165,   330,    15,   165,
     330,    17,    15,    25,   165,    20,    21,    15,   120,    20,
      20,   389,   389,   359,    20,   330,   165,   330,   330,   330,
      29,   202,    25,   207,   208,   209,   331,   331,   331,   331,
     331,   331,   331,    27,   463,   464,   120,    27,   342,   344,
     331,   235,   236,   238,   239,   249,   251,   262,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   480,
     481,   482,   483,   484,   487,   492,   493,     0,   292,   293,
     295,   329,   170,   170,    49,   145,   146,   164,   174,   200,
     334,   345,   346,   351,   142,    32,    94,   102,   105,   107,
     118,   122,   127,   133,   156,   190,   191,   192,   193,   194,
     195,   381,   382,   383,   246,   128,   153,   183,    78,   109,
     129,   175,   186,   198,    98,   117,   115,   184,    43,    44,
     128,   153,   380,   120,   387,   171,   172,   121,   401,   402,
     397,   401,   397,   401,   162,   162,   165,   331,   412,   165,
     330,   162,    49,   165,    49,   165,   162,    49,    49,    26,
      26,   126,   318,    94,    25,   318,   318,    34,    99,   106,
     439,   162,   165,   165,   162,    49,   165,    49,   165,   113,
     439,    49,   166,    36,   113,   258,   338,   339,   439,    49,
     165,    36,    15,    36,   131,    15,    26,   162,   330,   170,
     106,   339,   439,    49,   165,    94,   162,     8,   149,   165,
     165,    18,   120,   330,   165,   165,   166,    20,    92,   179,
     417,   418,   162,   165,   162,   162,   202,    93,   170,   204,
     205,   217,   218,   219,   204,   205,   217,   218,   219,    34,
     222,   222,   106,    49,   220,   331,    49,   226,   162,    25,
      98,   186,   488,   491,    36,   126,   489,    36,    73,   126,
     486,   297,   298,   299,   331,   331,   352,   353,    81,   347,
     348,   331,   352,   331,   164,   346,   351,   164,   351,   164,
     366,   367,   368,   368,   368,   120,   126,   247,   404,   469,
     471,   472,   473,   474,   475,   476,   477,   371,   371,   370,
     372,   372,   372,   372,   373,   373,   374,   374,    20,   119,
     199,   440,   442,   443,   444,   440,   438,   443,   438,   162,
     330,   389,   389,   330,   402,    49,   165,   319,   162,   120,
      20,   454,   454,   114,   137,   114,   137,    81,   165,   325,
     326,    99,   120,   328,    26,    99,   328,   319,   440,   331,
      99,   106,   120,    20,   454,   455,   454,   455,   331,   113,
      81,   331,    81,   331,    81,   113,   339,   113,   113,   338,
     339,    81,   182,    26,   313,    94,   313,    94,    36,   170,
     331,   106,   106,   339,    81,    26,   162,   330,   162,   331,
      94,     9,    10,    45,    84,    86,   120,   176,   327,   414,
     416,   426,   427,   430,    92,   179,   418,    42,   362,   363,
      25,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,    81,   331,   162,    81,   331,
     489,   489,   491,    25,    25,   490,   488,    25,    73,   486,
     170,    35,    48,    77,    90,    91,   354,   355,   356,   357,
      49,    27,    49,   340,   345,   350,   331,   164,   351,   164,
     331,   164,   331,   330,   469,   475,   265,   503,   143,   231,
     234,   240,   241,   242,   248,   257,   263,   264,   470,   478,
     479,   480,   494,   497,   498,   500,   245,   252,   253,   499,
     227,   228,   229,   230,   255,   495,   139,   140,   141,   441,
     108,   162,   163,   331,   162,   330,   165,   165,    27,    34,
      49,   165,   330,   331,   162,   330,   108,   165,   165,   165,
     165,   331,   360,    27,    27,   331,   113,   331,   331,   113,
     339,   113,   337,   331,    49,    26,   313,   331,   331,   106,
     343,   170,   162,   120,    33,   161,   419,     7,   330,    20,
     176,   426,   176,   416,    81,   440,    73,   363,   170,   464,
     164,   224,   466,   467,   344,   162,    25,   165,   232,   233,
     243,   244,   256,   496,    49,   165,    49,   165,    26,   356,
     357,   357,   353,    48,   349,   348,   340,   345,   331,   164,
     331,   331,   162,   165,   372,   254,   259,   502,   496,   472,
     502,   369,   372,   263,   478,   480,   473,   474,   496,   162,
     439,   440,   326,    34,   162,   162,   331,   331,   113,   331,
      89,    26,    36,   331,   162,   330,     3,    95,   422,   423,
     425,   427,    24,    96,   420,   421,   424,   427,   162,   179,
      20,    20,   176,    27,   164,    81,   164,   331,   398,   467,
     372,   372,   372,   372,    25,   250,   485,   486,   485,   357,
      26,   331,   254,   260,   277,   501,   501,   369,   261,   440,
     331,   331,   313,   162,    33,    95,   425,   161,    96,   424,
     179,   179,    20,    34,   331,    27,   331,    49,   165,   183,
     496,    49,   165,   165,   179,   440,   164,    81,   328,   372,
     250,   486,   164,   331,    27,   331,    49,   165,    81,   328,
      27,    49,   165,    81,   328,    27,   165,   328
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
     535,   536,   537,   538,   539,   540,   541,   542,   543
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   289,   290,   290,   290,   290,   291,   291,   292,   292,
     293,   294,   295,   295,   295,   296,   296,   297,   297,   298,
     298,   298,   298,   299,   299,   299,   299,   300,   300,   300,
     300,   300,   300,   300,   300,   301,   301,   302,   303,   303,
     304,   304,   305,   306,   307,   307,   308,   308,   309,   309,
     309,   309,   310,   311,   312,   312,   312,   312,   313,   313,
     314,   314,   315,   315,   315,   315,   316,   316,   316,   316,
     317,   317,   318,   318,   318,   318,   319,   320,   320,   321,
     322,   323,   323,   324,   324,   324,   324,   324,   325,   325,
     326,   326,   327,   328,   329,   330,   330,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   332,   332,   332,   332,   332,   332,   332,
     332,   333,   333,   334,   334,   335,   336,   336,   337,   337,
     337,   337,   337,   337,   337,   337,   338,   339,   340,   341,
     341,   342,   342,   343,   343,   343,   343,   344,   345,   346,
     346,   346,   346,   347,   347,   348,   348,   349,   350,   350,
     351,   351,   352,   352,   353,   353,   354,   354,   354,   354,
     354,   354,   354,   355,   355,   356,   356,   357,   358,   358,
     359,   359,   360,   360,   361,   361,   362,   362,   363,   363,
     364,   365,   365,   366,   366,   367,   367,   367,   367,   368,
     368,   368,   369,   369,   370,   370,   370,   371,   371,   371,
     371,   371,   372,   372,   372,   373,   373,   373,   374,   374,
     375,   375,   376,   376,   377,   377,   378,   378,   379,   379,
     379,   379,   380,   380,   380,   381,   381,   381,   381,   381,
     381,   382,   382,   382,   382,   382,   382,   383,   383,   383,
     384,   384,   385,   385,   386,   386,   387,   387,   388,   388,
     388,   388,   389,   389,   389,   390,   390,   391,   391,   391,
     391,   392,   392,   393,   393,   393,   393,   393,   393,   393,
     394,   394,   395,   395,   396,   396,   396,   396,   396,   397,
     397,   398,   398,   399,   399,   399,   400,   400,   401,   401,
     402,   403,   403,   403,   403,   403,   403,   403,   403,   404,
     404,   405,   405,   405,   406,   407,   407,   408,   409,   410,
     411,   411,   412,   412,   413,   413,   414,   414,   414,   415,
     415,   415,   415,   415,   415,   416,   416,   417,   417,   418,
     419,   419,   420,   420,   421,   421,   421,   421,   422,   422,
     423,   423,   423,   423,   424,   424,   425,   425,   426,   426,
     426,   426,   427,   427,   427,   427,   428,   428,   429,   429,
     430,   431,   431,   431,   431,   431,   431,   432,   433,   433,
     433,   433,   434,   434,   434,   434,   435,   436,   437,   437,
     437,   437,   438,   438,   439,   440,   440,   440,   441,   441,
     441,   442,   442,   442,   443,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   445,   446,   446,   446,   447,   448,
     449,   449,   449,   450,   450,   450,   450,   450,   451,   452,
     452,   452,   452,   452,   452,   452,   453,   454,   455,   456,
     457,   457,   457,   458,   458,   458,   458,   458,   458,   458,
     458,   458,   458,   459,   459,   460,   460,   461,   462,   463,
     463,   464,   465,   466,   466,   467,   467,   467,   467,   468,
     468,   469,   469,   469,   469,   470,   470,   470,   470,   471,
     471,   472,   472,   473,   473,   474,   474,   475,   475,   475,
     476,   476,   477,   477,   478,   478,   478,   478,   478,   479,
     480,   480,   480,   480,   480,   480,   480,   481,   481,   481,
     481,   482,   482,   482,   482,   483,   483,   484,   484,   484,
     484,   484,   484,   484,   485,   485,   486,   486,   486,   486,
     487,   487,   487,   487,   487,   488,   488,   489,   489,   490,
     490,   491,   491,   492,   493,   493,   494,   494,   494,   495,
     495,   495,   495,   495,   496,   496,   496,   496,   497,   498,
     499,   500,   500,   501,   501,   501,   502,   502,   503
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
       2,     2,     2,     3,     4,     5,     3,     2,     3,     2,
       4,     1,     1,     4,     4,     4,     4,     4,     1,     3,
       2,     3,     3,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     4,     5,     4,     5,     5,
       6,     1,     2,     1,     1,     2,     1,     4,     3,     4,
       4,     5,     4,     5,     5,     6,     3,     3,     2,     1,
       4,     1,     4,     3,     4,     4,     5,     1,     2,     2,
       3,     3,     4,     1,     3,     2,     3,     2,     1,     2,
       2,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       2,     2,     3,     1,     1,     1,     1,     2,     4,     4,
       1,     4,     3,     4,     7,     9,     1,     2,     4,     7,
       7,     1,     3,     1,     3,     1,     3,     3,     3,     1,
       3,     4,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     2,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     4,     1,     2,     3,     2,     1,     2,
       2,     1,     1,     3,     3,     1,     1,     1,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     1,     3,     3,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     3,
       4,     6,     7,     7,     8,     1,     2,     1,     2,     3,
       3,     3,     0,     1,     1,     1,     2,     2,     0,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       5,     6,     2,     3,     5,     6,     3,     3,     4,     5,
       6,     7,     1,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     3,     2,     2,
       2,     3,     3,     2,     3,     5,     3,     5,     3,     2,
       3,     5,     5,     3,     5,     5,     3,     1,     2,     1,
       2,     2,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     2,     2,     4,     4,     4,     6,     1,
       4,     3,     5,     1,     2,     4,     7,    10,    13,     5,
       3,     1,     2,     3,     4,     1,     1,     2,     2,     1,
       3,     1,     3,     1,     3,     1,     2,     1,     2,     3,
       1,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     4,
       6,     4,     6,     1,     1,     3,     2,     4,     4,     6,
       2,     3,     1,     2,     1,     1,     2,     2,     3,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     4,     3,     3,
       3,     2,     2,     1,     1,     1,     1,     1,     2
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
  "\"'<while (>'\"", "\"'quote attribute content'\"", "\"'STRING'\"",
  "\"'URI'\"", "\"'variable name'\"", "\"'validate mode'\"",
  "\"'XML comment'\"", "\"'ancestor::'\"", "\"'ancestor-or-self::'\"",
  "\"'and'\"", "\"'''\"", "\"'as'\"", "\"'ascending'\"", "\"'at'\"",
  "\"'attribute'\"", "\"'attribute::'\"", "\"'<attribute {>'\"",
  "\"'<attribute (>'\"", "\"'@'\"", "\"'case'\"", "\"'<castable as>'\"",
  "\"'<cast as>'\"", "\"'CDATA[['\"", "\"']]'\"", "\"'child::'\"",
  "\"'collation'\"", "\"','\"", "\"'(:'\"", "\"':)'\"",
  "\"'<comment {>'\"", "\"'<comment (>'\"", "\"'DECIMAL'\"",
  "\"'<declare base URI>'\"", "\"'<declare boundary space>'\"",
  "\"'<declare construction>'\"", "\"'<declare copy namespaces>'\"",
  "\"'<declare default collation>'\"", "\"'<declare default element>'\"",
  "\"'<declare default function>'\"", "\"'<declare default order>'\"",
  "\"'<declare function>'\"", "\"'<declare namespace>'\"",
  "\"'<declare option>'\"", "\"'<declare ordering>'\"",
  "\"'<declare updating function>'\"",
  "\"'<declare sequential function>'\"", "\"'<exit with>'\"",
  "\"'<break loop>'\"", "\"'<continue loop>'\"", "\"'<declare var $>'\"",
  "\"'default'\"", "\"'<default element>'\"", "\"'descendant::'\"",
  "\"'descendant-or-self::'\"", "\"'descending'\"", "\"'div'\"",
  "\"'<document {>'\"", "\"'<document node (>'\"", "\"'$'\"", "\"'.'\"",
  "\"'..'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
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
  "VarDecl", "ConstructionDecl", "FunctionSig", "Block", "BlockBody",
  "ExitExpr", "WhileExpr", "FlowCtlStatement", "FunctionDecl", "ParamList",
  "Param", "EnclosedExpr", "BracedExpr", "QueryBody", "Expr", "ExprSingle",
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
       290,     0,    -1,   292,    -1,   291,   292,    -1,   293,    -1,
     291,   293,    -1,   203,    25,   170,    -1,   203,    25,    93,
      25,   170,    -1,   295,   329,    -1,   329,    -1,   294,   295,
      -1,   130,    15,    94,    26,   170,    -1,   296,   170,    -1,
     297,   170,    -1,   296,   170,   297,   170,    -1,   298,    -1,
     296,   170,   298,    -1,   299,    -1,   297,   170,   299,    -1,
     300,    -1,   301,    -1,   302,    -1,   304,    -1,   316,    -1,
     324,    -1,   305,    -1,   306,    -1,   303,    -1,   310,    -1,
     311,    -1,   317,    -1,   307,    -1,   308,    -1,   309,    -1,
     457,    -1,   312,    -1,   315,    -1,    64,    15,    94,    26,
      -1,    56,   159,    -1,    56,   178,    -1,    60,   131,    26,
      -1,    61,   131,    26,    -1,    65,    20,    25,    -1,   237,
     480,    -1,    66,   143,    -1,    66,   187,    -1,    62,    90,
      -1,    62,    91,    -1,    58,   159,    49,   114,    -1,    58,
     159,    49,   137,    -1,    58,   138,    49,   114,    -1,    58,
     138,    49,   137,    -1,    59,    26,    -1,    55,    26,    -1,
     112,    26,    -1,   112,   314,    26,    -1,   112,    26,    36,
     313,    -1,   112,   314,    26,    36,   313,    -1,    26,    -1,
     313,    49,    26,    -1,   131,    15,    94,    -1,    74,   131,
      -1,   111,    26,    -1,   111,   131,    15,    94,    26,    -1,
     111,    26,    36,   313,    -1,   111,   131,    15,    94,    26,
      36,   313,    -1,    72,    27,   106,   331,    -1,    72,    27,
      99,    -1,    72,    27,   439,   106,   331,    -1,    72,    27,
     439,    99,    -1,    57,   159,    -1,    57,   178,    -1,   126,
     165,    -1,   126,   325,   165,    -1,   126,   165,    34,   440,
      -1,   126,   325,   165,    34,   440,    -1,   120,   320,   162,
      -1,   330,   170,    -1,   320,   330,   170,    -1,    69,   331,
      -1,    23,   331,   165,   319,    -1,    70,    -1,    71,    -1,
      63,    20,   318,    99,    -1,    63,    20,   318,   328,    -1,
      67,    20,   318,    99,    -1,    67,    20,   318,   328,    -1,
      68,    20,   318,   319,    -1,   326,    -1,   325,    49,   326,
      -1,    81,    27,    -1,    81,    27,   439,    -1,   120,   330,
     162,    -1,   120,   330,   162,    -1,   330,    -1,   331,    -1,
     330,    49,   331,    -1,   332,    -1,   358,    -1,   361,    -1,
     364,    -1,   365,    -1,   458,    -1,   459,    -1,   461,    -1,
     460,    -1,   462,    -1,   465,    -1,   468,    -1,   321,    -1,
     322,    -1,   323,    -1,   319,    -1,   333,   164,   331,    -1,
     333,   345,   164,   331,    -1,   333,   351,   164,   331,    -1,
     333,   345,   351,   164,   331,    -1,   333,   346,   164,   331,
      -1,   333,   345,   346,   164,   331,    -1,   333,   346,   351,
     164,   331,    -1,   333,   345,   346,   351,   164,   331,    -1,
     334,    -1,   333,   334,    -1,   335,    -1,   340,    -1,   103,
     336,    -1,   337,    -1,   336,    49,    81,   337,    -1,    27,
     113,   331,    -1,    27,   439,   113,   331,    -1,    27,   338,
     113,   331,    -1,    27,   439,   338,   113,   331,    -1,    27,
     339,   113,   331,    -1,    27,   439,   339,   113,   331,    -1,
      27,   338,   339,   113,   331,    -1,    27,   439,   338,   339,
     113,   331,    -1,    36,    81,    27,    -1,   258,    81,    27,
      -1,   124,   341,    -1,   343,    -1,   341,    49,    81,   343,
      -1,   344,    -1,   342,    49,    81,   344,    -1,    27,   106,
     331,    -1,    27,   439,   106,   331,    -1,    27,   339,   106,
     331,    -1,    27,   439,   339,   106,   331,    -1,    27,    -1,
     200,   331,    -1,   146,   347,    -1,   146,   347,   350,    -1,
     146,   347,   345,    -1,   146,   347,   350,   345,    -1,   348,
      -1,   347,    49,   348,    -1,    81,    27,    -1,    81,    27,
     349,    -1,    48,    26,    -1,   340,    -1,   350,   340,    -1,
     145,   352,    -1,   174,   352,    -1,   353,    -1,   352,    49,
     353,    -1,   331,    -1,   331,   354,    -1,   355,    -1,   356,
      -1,   357,    -1,   355,   356,    -1,   355,   357,    -1,   356,
     357,    -1,   355,   356,   357,    -1,    35,    -1,    77,    -1,
      90,    -1,    91,    -1,    48,    26,    -1,   173,   359,   166,
     331,    -1,    97,   359,   166,   331,    -1,   360,    -1,   359,
      49,    81,   360,    -1,    27,   113,   331,    -1,    27,   439,
     113,   331,    -1,   185,   330,   165,   362,    73,   164,   331,
      -1,   185,   330,   165,   362,    73,    81,    27,   164,   331,
      -1,   363,    -1,   362,   363,    -1,    42,   440,   164,   331,
      -1,    42,    81,    27,    34,   440,   164,   331,    -1,   110,
     330,   165,   182,   331,    89,   331,    -1,   366,    -1,   365,
     142,   366,    -1,   367,    -1,   366,    32,   367,    -1,   368,
      -1,   368,   382,   368,    -1,   368,   381,   368,    -1,   368,
     383,   368,    -1,   369,    -1,   369,   246,   469,    -1,   369,
     246,   469,   503,    -1,   370,    -1,   370,   183,   370,    -1,
     371,    -1,   370,   153,   371,    -1,   370,   128,   371,    -1,
     372,    -1,   371,   175,   372,    -1,   371,    78,   372,    -1,
     371,   109,   372,    -1,   371,   129,   372,    -1,   373,    -1,
     372,   186,   373,    -1,   372,   198,   373,    -1,   374,    -1,
     373,   117,   374,    -1,   373,    98,   374,    -1,   375,    -1,
     375,   115,   440,    -1,   376,    -1,   376,   184,   440,    -1,
     377,    -1,   377,    43,   438,    -1,   378,    -1,   378,    44,
     438,    -1,   380,    -1,   379,   380,    -1,   153,    -1,   128,
      -1,   379,   153,    -1,   379,   128,    -1,   384,    -1,   388,
      -1,   385,    -1,    94,    -1,   133,    -1,   127,    -1,   122,
      -1,   107,    -1,   105,    -1,   190,    -1,   195,    -1,   194,
      -1,   193,    -1,   192,    -1,   191,    -1,   118,    -1,   156,
      -1,   102,    -1,   196,   330,   162,    -1,    28,   120,   330,
     162,    -1,   386,   120,   162,    -1,   386,   120,   330,   162,
      -1,   387,    -1,   386,   387,    -1,   154,    20,    18,    -1,
     154,    21,    -1,   171,    -1,   171,   389,    -1,   172,   389,
      -1,   389,    -1,   390,    -1,   390,   171,   389,    -1,   390,
     172,   389,    -1,   391,    -1,   400,    -1,   392,    -1,   392,
     401,    -1,   395,    -1,   395,   401,    -1,   393,   397,    -1,
     394,    -1,    47,    -1,    75,    -1,    38,    -1,   169,    -1,
      76,    -1,   101,    -1,   100,    -1,   397,    -1,    41,   397,
      -1,   396,   397,    -1,    83,    -1,   147,    -1,    30,    -1,
     158,    -1,   157,    -1,    31,    -1,   444,    -1,   398,    -1,
      20,    -1,   399,    -1,   175,    -1,    12,    -1,    19,    -1,
     403,    -1,   403,   401,    -1,   402,    -1,   401,   402,    -1,
     121,   330,   163,    -1,   404,    -1,   406,    -1,   407,    -1,
     408,    -1,   411,    -1,   413,    -1,   409,    -1,   410,    -1,
     405,    -1,   456,    -1,    54,    -1,   116,    -1,    85,    -1,
      81,    27,    -1,   126,   165,    -1,   126,   330,   165,    -1,
      82,    -1,   144,   330,   162,    -1,   188,   330,   162,    -1,
      20,   126,   165,    -1,    20,   126,   412,   165,    -1,   331,
      -1,   412,    49,   331,    -1,   414,    -1,   431,    -1,   415,
      -1,   428,    -1,   429,    -1,   177,    20,    92,    -1,   177,
      20,   417,    92,    -1,   177,    20,   179,   176,    20,   179,
      -1,   177,    20,   179,   416,   176,    20,   179,    -1,   177,
      20,   417,   179,   176,    20,   179,    -1,   177,    20,   417,
     179,   416,   176,    20,   179,    -1,   426,    -1,   416,   426,
      -1,   418,    -1,   417,   418,    -1,    20,    94,   419,    -1,
     161,   420,   161,    -1,    33,   422,    33,    -1,    -1,   421,
      -1,    96,    -1,   424,    -1,   421,    96,    -1,   421,   424,
      -1,    -1,   423,    -1,    95,    -1,   425,    -1,   423,    95,
      -1,   423,   425,    -1,    24,    -1,   427,    -1,     3,    -1,
     427,    -1,   414,    -1,    10,    -1,   430,    -1,   427,    -1,
       9,    -1,    84,    -1,    86,    -1,   327,    -1,   201,    29,
     202,    -1,   201,   202,    -1,   148,    17,   149,    -1,   148,
      17,     8,    -1,    45,     7,    -1,   432,    -1,   433,    -1,
     434,    -1,   435,    -1,   436,    -1,   437,    -1,    79,   330,
     162,    -1,    11,   162,    -1,    11,   330,   162,    -1,    87,
     330,   162,   120,   162,    -1,    87,   330,   162,   120,   330,
     162,    -1,     4,   162,    -1,     4,   330,   162,    -1,    39,
     330,   162,   120,   162,    -1,    39,   330,   162,   120,   330,
     162,    -1,   180,   330,   162,    -1,    52,   330,   162,    -1,
     160,    15,   120,   162,    -1,   160,    15,   120,   330,   162,
      -1,   160,   120,   330,   162,   120,   162,    -1,   160,   120,
     330,   162,   120,   330,   162,    -1,   443,    -1,   443,   108,
      -1,    34,   440,    -1,   442,    -1,   442,   441,    -1,   199,
      -1,   139,    -1,   141,    -1,   140,    -1,   443,    -1,   444,
      -1,   119,    -1,    20,    -1,   446,    -1,   452,    -1,   450,
      -1,   453,    -1,   451,    -1,   449,    -1,   448,    -1,   447,
      -1,   445,    -1,   135,   165,    -1,    80,   165,    -1,    80,
     452,   165,    -1,    80,   453,   165,    -1,   181,   165,    -1,
      53,   165,    -1,   151,   165,    -1,   151,    15,   165,    -1,
     151,    25,   165,    -1,    40,   165,    -1,    40,    20,   165,
      -1,    40,    20,    49,   454,   165,    -1,    40,   175,   165,
      -1,    40,   175,    49,   454,   165,    -1,   167,    20,   165,
      -1,    88,   165,    -1,    88,    20,   165,    -1,    88,    20,
      49,   454,   165,    -1,    88,    20,    49,   455,   165,    -1,
      88,   175,   165,    -1,    88,   175,    49,   454,   165,    -1,
      88,   175,    49,   455,   165,    -1,   168,    20,   165,    -1,
      20,    -1,    20,   108,    -1,    25,    -1,   206,   207,    -1,
     206,   208,    -1,   206,   209,    -1,   212,   331,   218,   331,
      -1,   212,   331,   217,   331,    -1,   212,   331,   219,   331,
      -1,   212,   331,   204,   331,    -1,   212,   331,   205,   331,
      -1,   213,   331,   218,   331,    -1,   213,   331,   217,   331,
      -1,   213,   331,   219,   331,    -1,   213,   331,   204,   331,
      -1,   213,   331,   205,   331,    -1,   210,   331,    -1,   211,
     331,    -1,   215,   331,   222,   331,    -1,   216,   331,   222,
     331,    -1,   214,   331,    34,   331,    -1,   221,   463,   220,
     331,   164,   331,    -1,   464,    -1,   463,    49,    81,   464,
      -1,    27,   106,   331,    -1,   223,   120,   331,   162,   466,
      -1,   467,    -1,   466,   467,    -1,   224,   398,   165,   328,
      -1,   224,   398,    49,    81,    27,   165,   328,    -1,   224,
     398,    49,    81,    27,    49,    81,    27,   165,   328,    -1,
     224,   398,    49,    81,    27,    49,    81,    27,    49,    81,
      27,   165,   328,    -1,   225,   342,   226,   331,   162,    -1,
     226,   331,   162,    -1,   471,    -1,   471,   470,    -1,   471,
     263,   369,    -1,   471,   470,   263,   369,    -1,   480,    -1,
     478,    -1,   470,   480,    -1,   470,   478,    -1,   472,    -1,
     471,   248,   472,    -1,   473,    -1,   472,   245,   473,    -1,
     474,    -1,   473,   252,   474,    -1,   475,    -1,   247,   475,
      -1,   476,    -1,   476,   499,    -1,   126,   469,   165,    -1,
     477,    -1,   477,   495,    -1,   404,    -1,   120,   330,   162,
      -1,   479,    -1,   498,    -1,   497,    -1,   500,    -1,   494,
      -1,   143,    -1,   481,    -1,   482,    -1,   483,    -1,   484,
      -1,   487,    -1,   492,    -1,   493,    -1,   251,    -1,   262,
      -1,   236,    -1,   235,    -1,   272,    -1,   266,    -1,   239,
      -1,   238,    -1,   273,    -1,   267,    -1,   275,   486,    -1,
     275,    73,    -1,   275,   126,   486,   165,    -1,   275,   126,
     486,    49,   485,   165,    -1,   275,   126,    73,   165,    -1,
     275,   126,    73,    49,   485,   165,    -1,   269,    -1,   486,
      -1,   485,    49,   486,    -1,    36,    25,    -1,    36,    25,
     256,    25,    -1,    36,    25,   496,   250,    -1,    36,    25,
     256,    25,   496,   250,    -1,   274,   489,    -1,   274,   489,
     488,    -1,   271,    -1,   271,   488,    -1,   268,    -1,   491,
      -1,   488,   491,    -1,    36,    25,    -1,   126,   490,   165,
      -1,    25,    -1,   490,    25,    -1,   186,   489,    -1,    98,
     489,    -1,   249,    25,    -1,   276,    -1,   270,    -1,   234,
      -1,   231,    -1,   242,    -1,   229,    -1,   230,    -1,   227,
      -1,   228,    -1,   255,    -1,   243,   372,    -1,   232,   372,
      -1,   233,   372,    -1,   244,   372,   183,   372,    -1,   241,
     496,   501,    -1,   264,   372,   501,    -1,   253,   496,   261,
      -1,   257,   502,    -1,   240,   502,    -1,   277,    -1,   260,
      -1,   254,    -1,   259,    -1,   254,    -1,   265,   372,    -1
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
     233,   236,   239,   242,   246,   251,   257,   261,   264,   268,
     271,   276,   278,   280,   285,   290,   295,   300,   305,   307,
     311,   314,   318,   322,   326,   328,   330,   334,   336,   338,
     340,   342,   344,   346,   348,   350,   352,   354,   356,   358,
     360,   362,   364,   366,   370,   375,   380,   386,   391,   397,
     403,   410,   412,   415,   417,   419,   422,   424,   429,   433,
     438,   443,   449,   454,   460,   466,   473,   477,   481,   484,
     486,   491,   493,   498,   502,   507,   512,   518,   520,   523,
     526,   530,   534,   539,   541,   545,   548,   552,   555,   557,
     560,   563,   566,   568,   572,   574,   577,   579,   581,   583,
     586,   589,   592,   596,   598,   600,   602,   604,   607,   612,
     617,   619,   624,   628,   633,   641,   651,   653,   656,   661,
     669,   677,   679,   683,   685,   689,   691,   695,   699,   703,
     705,   709,   714,   716,   720,   722,   726,   730,   732,   736,
     740,   744,   748,   750,   754,   758,   760,   764,   768,   770,
     774,   776,   780,   782,   786,   788,   792,   794,   797,   799,
     801,   804,   807,   809,   811,   813,   815,   817,   819,   821,
     823,   825,   827,   829,   831,   833,   835,   837,   839,   841,
     843,   847,   852,   856,   861,   863,   866,   870,   873,   875,
     878,   881,   883,   885,   889,   893,   895,   897,   899,   902,
     904,   907,   910,   912,   914,   916,   918,   920,   922,   924,
     926,   928,   931,   934,   936,   938,   940,   942,   944,   946,
     948,   950,   952,   954,   956,   958,   960,   962,   965,   967,
     970,   974,   976,   978,   980,   982,   984,   986,   988,   990,
     992,   994,   996,   998,  1000,  1003,  1006,  1010,  1012,  1016,
    1020,  1024,  1029,  1031,  1035,  1037,  1039,  1041,  1043,  1045,
    1049,  1054,  1061,  1069,  1077,  1086,  1088,  1091,  1093,  1096,
    1100,  1104,  1108,  1109,  1111,  1113,  1115,  1118,  1121,  1122,
    1124,  1126,  1128,  1131,  1134,  1136,  1138,  1140,  1142,  1144,
    1146,  1148,  1150,  1152,  1154,  1156,  1158,  1162,  1165,  1169,
    1173,  1176,  1178,  1180,  1182,  1184,  1186,  1188,  1192,  1195,
    1199,  1205,  1212,  1215,  1219,  1225,  1232,  1236,  1240,  1245,
    1251,  1258,  1266,  1268,  1271,  1274,  1276,  1279,  1281,  1283,
    1285,  1287,  1289,  1291,  1293,  1295,  1297,  1299,  1301,  1303,
    1305,  1307,  1309,  1311,  1313,  1316,  1319,  1323,  1327,  1330,
    1333,  1336,  1340,  1344,  1347,  1351,  1357,  1361,  1367,  1371,
    1374,  1378,  1384,  1390,  1394,  1400,  1406,  1410,  1412,  1415,
    1417,  1420,  1423,  1426,  1431,  1436,  1441,  1446,  1451,  1456,
    1461,  1466,  1471,  1476,  1479,  1482,  1487,  1492,  1497,  1504,
    1506,  1511,  1515,  1521,  1523,  1526,  1531,  1539,  1550,  1564,
    1570,  1574,  1576,  1579,  1583,  1588,  1590,  1592,  1595,  1598,
    1600,  1604,  1606,  1610,  1612,  1616,  1618,  1621,  1623,  1626,
    1630,  1632,  1635,  1637,  1641,  1643,  1645,  1647,  1649,  1651,
    1653,  1655,  1657,  1659,  1661,  1663,  1665,  1667,  1669,  1671,
    1673,  1675,  1677,  1679,  1681,  1683,  1685,  1687,  1690,  1693,
    1698,  1705,  1710,  1717,  1719,  1721,  1725,  1728,  1733,  1738,
    1745,  1748,  1752,  1754,  1757,  1759,  1761,  1764,  1767,  1771,
    1773,  1776,  1779,  1782,  1785,  1787,  1789,  1791,  1793,  1795,
    1797,  1799,  1801,  1803,  1805,  1808,  1811,  1814,  1819,  1823,
    1827,  1831,  1834,  1837,  1839,  1841,  1843,  1845,  1847
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   795,   795,   800,   806,   811,   823,   828,   838,   845,
     857,   869,   881,   887,   893,   905,   911,   925,   931,   945,
     949,   953,   957,   966,   970,   974,   980,   990,   994,   998,
    1002,  1006,  1010,  1014,  1020,  1030,  1034,  1049,  1061,  1066,
    1077,  1083,  1095,  1108,  1119,  1124,  1136,  1141,  1152,  1158,
    1164,  1170,  1189,  1200,  1211,  1218,  1225,  1232,  1245,  1251,
    1266,  1270,  1280,  1286,  1293,  1299,  1313,  1320,  1327,  1334,
    1347,  1352,  1364,  1368,  1372,  1376,  1383,  1390,  1396,  1405,
    1412,  1419,  1423,  1430,  1438,  1447,  1456,  1465,  1480,  1488,
    1502,  1508,  1520,  1528,  1539,  1550,  1556,  1568,  1572,  1576,
    1580,  1584,  1590,  1594,  1598,  1602,  1606,  1610,  1614,  1618,
    1622,  1626,  1630,  1640,  1647,  1655,  1663,  1672,  1684,  1696,
    1708,  1726,  1732,  1744,  1748,  1758,  1769,  1775,  1789,  1796,
    1804,  1813,  1823,  1831,  1840,  1849,  1864,  1876,  1887,  1899,
    1905,  1917,  1923,  1937,  1945,  1954,  1962,  1974,  1989,  1997,
    2004,  2011,  2018,  2028,  2034,  2045,  2051,  2060,  2067,  2074,
    2086,  2091,  2103,  2109,  2123,  2129,  2141,  2148,  2155,  2162,
    2169,  2176,  2183,  2196,  2200,  2210,  2215,  2226,  2237,  2244,
    2257,  2264,  2276,  2282,  2295,  2302,  2316,  2322,  2334,  2340,
    2353,  2364,  2368,  2379,  2383,  2402,  2406,  2414,  2422,  2436,
    2440,  2447,  2460,  2464,  2475,  2479,  2483,  2493,  2497,  2501,
    2505,  2509,  2519,  2523,  2528,  2539,  2543,  2547,  2557,  2561,
    2573,  2577,  2589,  2593,  2605,  2609,  2621,  2625,  2637,  2641,
    2645,  2649,  2661,  2665,  2669,  2680,  2684,  2688,  2692,  2696,
    2700,  2710,  2714,  2718,  2722,  2726,  2730,  2740,  2744,  2748,
    2759,  2763,  2775,  2781,  2793,  2799,  2813,  2819,  2861,  2865,
    2869,  2873,  2886,  2897,  2902,  2912,  2916,  2926,  2932,  2938,
    2944,  2956,  2962,  2973,  2977,  2981,  2985,  2989,  2993,  2997,
    3007,  3011,  3021,  3027,  3039,  3043,  3047,  3051,  3055,  3070,
    3074,  3084,  3088,  3098,  3105,  3112,  3125,  3129,  3141,  3147,
    3161,  3172,  3176,  3180,  3184,  3188,  3192,  3196,  3200,  3210,
    3214,  3224,  3229,  3234,  3245,  3255,  3259,  3270,  3280,  3291,
    3347,  3353,  3365,  3371,  3383,  3387,  3397,  3401,  3405,  3415,
    3423,  3431,  3439,  3447,  3455,  3470,  3476,  3488,  3494,  3508,
    3520,  3525,  3537,  3540,  3547,  3553,  3559,  3567,  3582,  3585,
    3592,  3598,  3604,  3612,  3626,  3631,  3642,  3647,  3658,  3663,
    3668,  3674,  3686,  3692,  3697,  3702,  3713,  3718,  3733,  3738,
    3755,  3770,  3774,  3778,  3782,  3786,  3790,  3800,  3811,  3817,
    3823,  3828,  3850,  3856,  3862,  3867,  3878,  3889,  3900,  3906,
    3912,  3917,  3928,  3934,  3946,  3957,  3963,  3969,  4006,  4011,
    4016,  4027,  4031,  4035,  4045,  4056,  4060,  4064,  4068,  4072,
    4076,  4080,  4084,  4088,  4098,  4108,  4112,  4117,  4128,  4138,
    4148,  4152,  4156,  4166,  4172,  4178,  4184,  4190,  4202,  4213,
    4219,  4225,  4231,  4237,  4244,  4251,  4264,  4285,  4292,  4312,
    4352,  4357,  4360,  4368,  4374,  4380,  4386,  4392,  4399,  4405,
    4411,  4417,  4423,  4435,  4440,  4450,  4456,  4468,  4494,  4505,
    4511,  4524,  4538,  4545,  4552,  4563,  4570,  4578,  4587,  4606,
    4612,  4629,  4633,  4637,  4641,  4651,  4654,  4657,  4660,  4669,
    4672,  4681,  4684,  4693,  4696,  4705,  4708,  4717,  4720,  4723,
    4732,  4735,  4744,  4748,  4758,  4761,  4764,  4767,  4770,  4779,
    4788,  4792,  4796,  4800,  4804,  4808,  4812,  4822,  4825,  4828,
    4831,  4840,  4843,  4846,  4849,  4858,  4861,  4870,  4873,  4876,
    4879,  4882,  4885,  4888,  4897,  4900,  4909,  4912,  4915,  4918,
    4927,  4930,  4933,  4936,  4939,  4948,  4951,  4960,  4963,  4972,
    4975,  4984,  4987,  4996,  5005,  5008,  5017,  5020,  5023,  5032,
    5035,  5038,  5041,  5044,  5053,  5057,  5061,  5065,  5075,  5084,
    5094,  5103,  5106,  5115,  5118,  5121,  5130,  5133,  5142
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
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 4286;
  const int xquery_parser::yynnts_ = 215;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 347;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 289;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 543;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5150 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"



/*
	The error member function registers the errors to the driver.
*/

void zorba::xquery_parser::error(
	zorba::xquery_parser::location_type const& loc,
	std::string const& msg)
{
  driver.set_expr (new ParseErrorNode (driver.createQueryLoc (loc), msg));
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

