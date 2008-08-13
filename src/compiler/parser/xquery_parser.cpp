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
#line 762 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"

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
        case 84: /* "\"'DECIMAL'\"" */
#line 659 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 95: /* "\"'DOUBLE'\"" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 119: /* "\"'INTEGER'\"" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 267: /* "VersionDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 268: /* "MainModule" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 269: /* "LibraryModule" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 270: /* "ModuleDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 271: /* "Prolog" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 272: /* "SIND_DeclList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 273: /* "VFO_DeclList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 274: /* "SIND_Decl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 275: /* "VFO_Decl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 276: /* "Setter" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 277: /* "Import" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 278: /* "NamespaceDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 279: /* "BoundarySpaceDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 280: /* "DefaultNamespaceDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 281: /* "OptionDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 283: /* "OrderingModeDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 284: /* "EmptyOrderDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 285: /* "CopyNamespacesDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "DefaultCollationDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "BaseURIDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "SchemaImport" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "URILiteralList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "SchemaPrefix" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "ModuleImport" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "VarDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 346 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "ConstructionDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "FunctionSig" */
#line 667 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 356 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "Block" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 361 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "BlockBody" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 366 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "ExitExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 371 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "WhileExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 376 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "FlowCtlStatement" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 381 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "FunctionDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 386 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "ParamList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 391 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "Param" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 396 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "EnclosedExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 401 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "BracedExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 406 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "QueryBody" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 411 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "Expr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 416 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "ExprSingle" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 421 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "FLWORExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 426 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "ForLetClauseList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 431 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "ForLetClause" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 436 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "ForClause" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 441 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "VarInDeclList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 446 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "VarInDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 451 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "PositionalVar" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 456 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "LetClause" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 461 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "VarGetsDeclList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 466 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "EvalVarDeclList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 471 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "VarGetsDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "EvalVarDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 481 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "WhereClause" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 486 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "GroupByClause" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 491 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "GroupSpecList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 496 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "GroupSpec" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 501 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "GroupCollationSpec" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 506 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "LetClauseList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 511 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "OrderByClause" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 516 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "OrderSpecList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 521 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "OrderSpec" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "OrderModifier" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "OrderDirSpec" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 536 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "OrderEmptySpec" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "OrderCollationSpec" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "QuantifiedExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 551 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "QVarInDeclList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 556 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "QVarInDecl" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 561 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "TypeswitchExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 566 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "CaseClauseList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 571 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "CaseClause" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 576 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "IfExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 581 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "OrExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 586 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "AndExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 591 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "ComparisonExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 596 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "FTContainsExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 601 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "RangeExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 606 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "AdditiveExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 611 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "MultiplicativeExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 616 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "UnionExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 621 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "IntersectExceptExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 626 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "InstanceofExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 631 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "TreatExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 636 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CastableExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 641 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CastExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 646 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "UnaryExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 651 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "SignList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 656 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "ValueExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 661 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "ValueComp" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 666 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "NodeComp" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 671 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "ValidateExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 676 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "ExtensionExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 681 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "PragmaList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 686 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "Pragma" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 691 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "PathExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 696 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "RelativePathExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 701 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "StepExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 706 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "AxisStep" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 711 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "ForwardStep" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 716 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ForwardAxis" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 721 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "AbbrevForwardStep" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 726 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "ReverseStep" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 731 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "ReverseAxis" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 736 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "NodeTest" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 741 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "NameTest" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 746 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "Wildcard" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 751 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FilterExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 756 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "PredicateList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 761 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "Predicate" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 766 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "PrimaryExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 771 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "Literal" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 776 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "NumericLiteral" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 781 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "VarRef" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 786 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "ParenthesizedExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 791 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ContextItemExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 796 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "OrderedExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 801 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "UnorderedExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 806 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "FunctionCall" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 811 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ArgList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 816 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "Constructor" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 821 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "DirectConstructor" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 826 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "DirElemConstructor" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 831 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "DirElemContentList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 836 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "DirAttributeList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 841 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "DirAttr" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 846 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "DirAttributeValue" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 851 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "Opt_QuoteAttrContentList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 856 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "QuoteAttrContentList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 861 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "Opt_AposAttrContentList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 866 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "AposAttrContentList" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 871 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "QuoteAttrValueContent" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 876 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "AposAttrValueContent" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 881 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "DirElemContent" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 886 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "CommonContent" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 891 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "DirCommentConstructor" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 896 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "DirPIConstructor" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 901 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "CDataSection" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 906 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "ComputedConstructor" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 911 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "CompDocConstructor" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 916 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CompElemConstructor" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 921 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CompAttrConstructor" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 926 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "CompTextConstructor" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 931 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "CompCommentConstructor" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 936 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "CompPIConstructor" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 941 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "SingleType" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 946 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "TypeDeclaration" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 951 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "SequenceType" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 956 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "OccurrenceIndicator" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 961 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "ItemType" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 966 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "AtomicType" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 971 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "KindTest" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 976 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "AnyKindTest" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 981 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "DocumentTest" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 986 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "TextTest" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 991 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "CommentTest" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 996 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "PITest" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1001 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "AttributeTest" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1006 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "SchemaAttributeTest" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1011 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "ElementTest" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1016 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "SchemaElementTest" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1021 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "TypeName" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1026 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "TypeName_WITH_HOOK" */
#line 665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1031 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "StringLiteral" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1036 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "InsertExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1041 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "DeleteExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1046 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "ReplaceExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1051 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "RenameExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1056 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "TransformExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1061 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "VarNameList" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1066 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "VarNameDecl" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1071 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "TryExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1076 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "CatchListExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1081 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "CatchExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1086 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "EvalExpr" */
#line 666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1091 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
#line 1172 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
#line 783 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 3:
#line 788 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 4:
#line 794 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 799 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 811 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		;}
    break;

  case 7:
#line 816 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    ;}
    break;

  case 8:
#line 826 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)));
		;}
    break;

  case 9:
#line 833 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								NULL,
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 10:
#line 845 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 11:
#line 857 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval)));
		;}
    break;

  case 12:
#line 869 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 13:
#line 875 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 14:
#line 881 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 15:
#line 893 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 16:
#line 899 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 17:
#line 913 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 18:
#line 919 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 933 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 937 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 941 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 945 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 958 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 962 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 968 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 978 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 982 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 986 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 990 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 994 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 998 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1002 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1008 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1018 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1022 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1037 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 38:
#line 1049 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1054 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1065 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 41:
#line 1071 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 42:
#line 1083 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 43:
#line 1096 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		;}
    break;

  case 44:
#line 1107 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1112 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1124 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1140 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 49:
#line 1146 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 50:
#line 1152 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 51:
#line 1158 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 52:
#line 1177 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 53:
#line 1188 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 54:
#line 1199 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 55:
#line 1206 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		;}
    break;

  case 56:
#line 1213 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 57:
#line 1220 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 58:
#line 1233 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 59:
#line 1239 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 60:
#line 1254 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1258 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 62:
#line 1268 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 63:
#line 1274 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		;}
    break;

  case 64:
#line 1281 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 65:
#line 1287 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		;}
    break;

  case 66:
#line 1301 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								NULL,
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 67:
#line 1308 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (4)].sval)),
								NULL,
								NULL);
		;}
    break;

  case 68:
#line 1315 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (4)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 69:
#line 1322 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (5)].node)),
								NULL);
		;}
    break;

  case 70:
#line 1335 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1340 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1352 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 73:
#line 1356 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 74:
#line 1360 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 75:
#line 1364 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 76:
#line 1371 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    ;}
    break;

  case 77:
#line 1378 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = new BlockBody (LOC ((yyloc)));
      blk->add ((yysemantic_stack_[(2) - (1)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 78:
#line 1384 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 79:
#line 1393 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 80:
#line 1400 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr)));
    ;}
    break;

  case 81:
#line 1407 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 82:
#line 1411 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 83:
#line 1418 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval))),
                &* (yysemantic_stack_[(5) - (4)].fnsig)->param, &* (yysemantic_stack_[(5) - (4)].fnsig)->ret, NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
		;}
    break;

  case 84:
#line 1426 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1435 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1444 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1453 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1468 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 89:
#line 1476 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 90:
#line 1490 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 91:
#line 1496 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 92:
#line 1508 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1516 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 94:
#line 1527 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 95:
#line 1538 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = new Expr(LOC ((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 96:
#line 1544 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 97:
#line 1556 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1560 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1564 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1568 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1572 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1578 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1582 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1586 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1590 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1594 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 107:
#line 1598 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 108:
#line 1602 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 109:
#line 1606 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 110:
#line 1610 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 111:
#line 1614 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 112:
#line 1618 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 113:
#line 1628 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 114:
#line 1635 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 115:
#line 1643 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								NULL,NULL,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 116:
#line 1651 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1660 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1672 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1684 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1696 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1714 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ForLetClauseList* flc_list_p = new ForLetClauseList(LOC ((yyloc)));
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = flc_list_p;
		;}
    break;

  case 122:
#line 1720 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(2) - (1)].node));
			if (flc_list_p) flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 123:
#line 1732 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 124:
#line 1736 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 125:
#line 1746 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 126:
#line 1757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 127:
#line 1763 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 128:
#line 1777 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 129:
#line 1784 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 130:
#line 1792 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1801 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1811 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 133:
#line 1819 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1828 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1837 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1852 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 137:
#line 1864 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 138:
#line 1875 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 139:
#line 1887 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 140:
#line 1893 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 141:
#line 1905 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 142:
#line 1911 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 143:
#line 1925 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 144:
#line 1933 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 145:
#line 1942 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 146:
#line 1950 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 147:
#line 1962 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 148:
#line 1977 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 149:
#line 1985 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 150:
#line 1992 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(4) - (3)].node)),
                 dynamic_cast<LetClauseList*>((yysemantic_stack_[(4) - (4)].node)),
                 NULL);
    ;}
    break;

  case 151:
#line 1999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(4) - (3)].node)),
                 NULL,
                 dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 152:
#line 2006 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(5) - (3)].node)),
                 dynamic_cast<LetClauseList*>((yysemantic_stack_[(5) - (4)].node)),
                 dynamic_cast<WhereClause*>((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 153:
#line 2016 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 154:
#line 2022 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 155:
#line 2033 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 156:
#line 2039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 157:
#line 2048 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 158:
#line 2055 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      LetClauseList* lc_list_p = new LetClauseList(LOC((yyloc)));
      lc_list_p->push_back(dynamic_cast<LetClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = lc_list_p;
    ;}
    break;

  case 159:
#line 2062 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      LetClauseList* lc_list_p = dynamic_cast<LetClauseList*>((yysemantic_stack_[(2) - (1)].node));
      if (lc_list_p) lc_list_p->push_back(dynamic_cast<LetClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    ;}
    break;

  case 160:
#line 2074 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 161:
#line 2079 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 162:
#line 2091 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 163:
#line 2097 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 164:
#line 2111 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 165:
#line 2117 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 166:
#line 2129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 167:
#line 2136 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 168:
#line 2143 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 169:
#line 2150 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 170:
#line 2157 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 171:
#line 2164 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 172:
#line 2171 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 173:
#line 2184 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 174:
#line 2188 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 175:
#line 2198 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 176:
#line 2203 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 177:
#line 2214 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 178:
#line 2225 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 179:
#line 2232 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 180:
#line 2245 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 181:
#line 2252 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 182:
#line 2264 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 183:
#line 2270 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 184:
#line 2283 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 185:
#line 2290 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 186:
#line 2304 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 187:
#line 2310 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 188:
#line 2322 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 189:
#line 2328 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 190:
#line 2341 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 191:
#line 2352 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 192:
#line 2356 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 193:
#line 2367 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 194:
#line 2371 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 195:
#line 2390 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 196:
#line 2394 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 197:
#line 2402 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 198:
#line 2410 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 199:
#line 2418 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 200:
#line 2425 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 201:
#line 2426 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 202:
#line 2434 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 203:
#line 2442 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 204:
#line 2450 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 205:
#line 2464 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 206:
#line 2468 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 207:
#line 2475 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 208:
#line 2488 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 2492 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 210:
#line 2503 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 211:
#line 2507 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 212:
#line 2511 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 213:
#line 2521 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 214:
#line 2525 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 215:
#line 2529 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 216:
#line 2533 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 217:
#line 2537 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 218:
#line 2547 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 219:
#line 2551 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 220:
#line 2556 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 221:
#line 2567 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 222:
#line 2571 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 223:
#line 2575 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 224:
#line 2585 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 225:
#line 2589 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 226:
#line 2601 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 227:
#line 2605 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 228:
#line 2617 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 229:
#line 2621 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 230:
#line 2633 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 231:
#line 2637 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 232:
#line 2649 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 233:
#line 2653 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 234:
#line 2665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 235:
#line 2669 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 236:
#line 2673 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 237:
#line 2677 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 238:
#line 2689 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 239:
#line 2693 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 240:
#line 2697 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 241:
#line 2707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 242:
#line 2711 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 243:
#line 2715 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 244:
#line 2719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 245:
#line 2723 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 246:
#line 2727 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 247:
#line 2737 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 248:
#line 2741 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 249:
#line 2745 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 250:
#line 2755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 251:
#line 2759 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "strict",
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 252:
#line 2765 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "lax",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 253:
#line 2771 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "skip",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 254:
#line 2783 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 255:
#line 2789 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 256:
#line 2801 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 257:
#line 2807 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 258:
#line 2821 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 259:
#line 2827 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 260:
#line 2870 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 261:
#line 2874 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 262:
#line 2878 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 263:
#line 2882 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 264:
#line 2895 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 265:
#line 2906 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 266:
#line 2911 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 267:
#line 2921 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 268:
#line 2925 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 269:
#line 2935 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 270:
#line 2941 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 271:
#line 2947 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 272:
#line 2953 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 273:
#line 2965 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 274:
#line 2971 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 275:
#line 2982 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 276:
#line 2986 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 277:
#line 2990 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 278:
#line 2994 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 279:
#line 2998 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 280:
#line 3002 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 281:
#line 3006 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 282:
#line 3016 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 283:
#line 3020 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 284:
#line 3030 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 285:
#line 3036 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 286:
#line 3048 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 287:
#line 3052 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 288:
#line 3056 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 289:
#line 3060 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 290:
#line 3064 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 291:
#line 3079 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 292:
#line 3083 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 293:
#line 3093 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 294:
#line 3097 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 295:
#line 3107 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 296:
#line 3114 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 297:
#line 3121 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 298:
#line 3134 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 3138 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 300:
#line 3150 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 301:
#line 3156 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 302:
#line 3170 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
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
#line 3205 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 310:
#line 3209 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 311:
#line 3219 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 312:
#line 3223 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 313:
#line 3233 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 314:
#line 3238 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 315:
#line 3243 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 316:
#line 3254 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 317:
#line 3264 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 318:
#line 3268 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 319:
#line 3279 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 320:
#line 3289 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 321:
#line 3300 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 322:
#line 3356 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 323:
#line 3362 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 324:
#line 3374 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 325:
#line 3380 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 326:
#line 3392 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 327:
#line 3396 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3410 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 330:
#line 3414 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 331:
#line 3424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 332:
#line 3432 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 333:
#line 3440 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 334:
#line 3448 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 335:
#line 3456 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 336:
#line 3464 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 337:
#line 3479 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 338:
#line 3485 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 339:
#line 3497 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 340:
#line 3503 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 341:
#line 3516 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 344:
#line 3533 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 345:
#line 3538 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 346:
#line 3549 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 347:
#line 3553 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 348:
#line 3560 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 349:
#line 3566 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 350:
#line 3572 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 351:
#line 3580 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 352:
#line 3594 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 353:
#line 3598 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 354:
#line 3605 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 355:
#line 3611 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 356:
#line 3617 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 357:
#line 3625 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 358:
#line 3639 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 359:
#line 3644 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 360:
#line 3655 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 361:
#line 3660 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 362:
#line 3671 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 363:
#line 3676 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 364:
#line 3681 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 365:
#line 3687 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 366:
#line 3699 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 367:
#line 3705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 368:
#line 3710 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 369:
#line 3715 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 370:
#line 3726 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 371:
#line 3731 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 372:
#line 3746 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 373:
#line 3751 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 374:
#line 3768 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 375:
#line 3783 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 376:
#line 3787 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 377:
#line 3791 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 378:
#line 3795 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 379:
#line 3799 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 380:
#line 3803 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 381:
#line 3813 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 382:
#line 3824 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 383:
#line 3830 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 384:
#line 3836 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 385:
#line 3841 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 386:
#line 3863 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 387:
#line 3869 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 388:
#line 3875 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 389:
#line 3880 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 390:
#line 3891 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 391:
#line 3902 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 392:
#line 3913 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 393:
#line 3919 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 394:
#line 3925 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 395:
#line 3930 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 396:
#line 3941 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 397:
#line 3947 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 398:
#line 3959 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 399:
#line 3971 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 400:
#line 3977 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 401:
#line 3983 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 402:
#line 4020 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 403:
#line 4025 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 404:
#line 4030 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 405:
#line 4041 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 406:
#line 4045 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 407:
#line 4049 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 408:
#line 4059 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 409:
#line 4070 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 410:
#line 4074 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 411:
#line 4078 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 412:
#line 4082 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 413:
#line 4086 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 414:
#line 4090 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 415:
#line 4094 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 416:
#line 4098 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 417:
#line 4102 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 418:
#line 4112 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 419:
#line 4122 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 420:
#line 4126 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 421:
#line 4131 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 422:
#line 4142 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 423:
#line 4152 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 424:
#line 4162 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 425:
#line 4166 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 426:
#line 4170 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 427:
#line 4180 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 428:
#line 4186 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 429:
#line 4192 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 430:
#line 4198 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 431:
#line 4204 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 432:
#line 4216 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 433:
#line 4227 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL);
		;}
    break;

  case 434:
#line 4233 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
									NULL);
		;}
    break;

  case 435:
#line 4239 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 436:
#line 4245 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 437:
#line 4251 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 438:
#line 4258 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 439:
#line 4265 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 440:
#line 4278 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 441:
#line 4299 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 442:
#line 4306 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 443:
#line 4326 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 444:
#line 4366 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 445:
#line 4371 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 446:
#line 4374 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 447:
#line 4382 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 448:
#line 4388 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 449:
#line 4394 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 450:
#line 4400 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 451:
#line 4406 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 452:
#line 4413 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 453:
#line 4419 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 454:
#line 4425 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 455:
#line 4431 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 456:
#line 4437 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 457:
#line 4449 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 458:
#line 4454 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 459:
#line 4464 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 460:
#line 4470 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 461:
#line 4482 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 462:
#line 4508 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 463:
#line 4519 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 464:
#line 4525 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 465:
#line 4538 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 466:
#line 4552 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 467:
#line 4559 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 468:
#line 4566 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 469:
#line 4577 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 470:
#line 4584 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 471:
#line 4592 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 472:
#line 4601 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(14) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (9)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (12)].sval)),
                          (yysemantic_stack_[(14) - (14)].expr));
    ;}
    break;

  case 474:
#line 4617 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 475:
#line 4634 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 476:
#line 4635 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty"); ;}
    break;

  case 477:
#line 4636 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("attribute"); ;}
    break;

  case 478:
#line 4637 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("comment"); ;}
    break;

  case 479:
#line 4638 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document-node"); ;}
    break;

  case 480:
#line 4639 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("element"); ;}
    break;

  case 481:
#line 4640 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("item"); ;}
    break;

  case 482:
#line 4641 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("if"); ;}
    break;

  case 483:
#line 4642 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("node"); ;}
    break;

  case 484:
#line 4643 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("processing-instruction"); ;}
    break;

  case 485:
#line 4644 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-attribute"); ;}
    break;

  case 486:
#line 4645 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-element"); ;}
    break;

  case 487:
#line 4646 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("text"); ;}
    break;

  case 488:
#line 4647 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("typeswitch"); ;}
    break;

  case 489:
#line 4648 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty-sequence"); ;}
    break;

  case 490:
#line 4649 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("boundary-space"); ;}
    break;

  case 491:
#line 4650 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ft-option"); ;}
    break;

  case 492:
#line 4651 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("base-uri"); ;}
    break;

  case 493:
#line 4652 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lax"); ;}
    break;

  case 494:
#line 4653 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strict"); ;}
    break;

  case 495:
#line 4654 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("idiv"); ;}
    break;

  case 496:
#line 4655 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document"); ;}
    break;

  case 497:
#line 4656 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("not"); ;}
    break;

  case 498:
#line 4657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sensitive"); ;}
    break;

  case 499:
#line 4658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insensitive"); ;}
    break;

  case 500:
#line 4659 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("diacritics"); ;}
    break;

  case 501:
#line 4660 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("without"); ;}
    break;

  case 502:
#line 4661 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stemming"); ;}
    break;

  case 503:
#line 4662 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("thesaurus"); ;}
    break;

  case 504:
#line 4663 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stop"); ;}
    break;

  case 505:
#line 4664 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("wildcards"); ;}
    break;

  case 506:
#line 4665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("entire"); ;}
    break;

  case 507:
#line 4666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("content"); ;}
    break;

  case 508:
#line 4667 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("word"); ;}
    break;

  case 509:
#line 4668 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("start"); ;}
    break;

  case 510:
#line 4669 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("end"); ;}
    break;

  case 511:
#line 4670 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("most"); ;}
    break;

  case 512:
#line 4671 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("skip"); ;}
    break;

  case 513:
#line 4672 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy"); ;}
    break;

  case 514:
#line 4673 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("value"); ;}
    break;

  case 515:
#line 4674 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("eq"); ;}
    break;

  case 516:
#line 4675 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ne"); ;}
    break;

  case 517:
#line 4676 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lt"); ;}
    break;

  case 518:
#line 4677 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("le"); ;}
    break;

  case 519:
#line 4678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("gt"); ;}
    break;

  case 520:
#line 4679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ge"); ;}
    break;

  case 521:
#line 4680 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("at"); ;}
    break;

  case 522:
#line 4681 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("variable"); ;}
    break;

  case 523:
#line 4682 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("return"); ;}
    break;

  case 524:
#line 4683 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("for"); ;}
    break;

  case 525:
#line 4684 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("in"); ;}
    break;

  case 526:
#line 4685 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("let"); ;}
    break;

  case 527:
#line 4686 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("where"); ;}
    break;

  case 528:
#line 4687 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("by"); ;}
    break;

  case 529:
#line 4688 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("order"); ;}
    break;

  case 530:
#line 4689 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stable"); ;}
    break;

  case 531:
#line 4690 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ascending"); ;}
    break;

  case 532:
#line 4691 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("descending"); ;}
    break;

  case 533:
#line 4692 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("greatest"); ;}
    break;

  case 534:
#line 4693 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("least"); ;}
    break;

  case 535:
#line 4694 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("collation"); ;}
    break;

  case 536:
#line 4695 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("some"); ;}
    break;

  case 537:
#line 4696 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("every"); ;}
    break;

  case 538:
#line 4697 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("satisfies"); ;}
    break;

  case 539:
#line 4698 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("case"); ;}
    break;

  case 540:
#line 4699 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("as"); ;}
    break;

  case 541:
#line 4700 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("then"); ;}
    break;

  case 542:
#line 4701 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("else"); ;}
    break;

  case 543:
#line 4702 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("or"); ;}
    break;

  case 544:
#line 4703 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("and"); ;}
    break;

  case 545:
#line 4704 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("instance"); ;}
    break;

  case 546:
#line 4705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("of"); ;}
    break;

  case 547:
#line 4706 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("castable"); ;}
    break;

  case 548:
#line 4707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("to"); ;}
    break;

  case 549:
#line 4708 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("div"); ;}
    break;

  case 550:
#line 4709 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("mod"); ;}
    break;

  case 551:
#line 4710 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("union"); ;}
    break;

  case 552:
#line 4711 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("intersect"); ;}
    break;

  case 553:
#line 4712 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("except"); ;}
    break;

  case 554:
#line 4713 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("validate"); ;}
    break;

  case 555:
#line 4714 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cast"); ;}
    break;

  case 556:
#line 4715 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("treat"); ;}
    break;

  case 557:
#line 4716 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("is"); ;}
    break;

  case 558:
#line 4717 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("preserve"); ;}
    break;

  case 559:
#line 4718 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strip"); ;}
    break;

  case 560:
#line 4719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("namespace"); ;}
    break;

  case 561:
#line 4720 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("external"); ;}
    break;

  case 562:
#line 4721 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("encoding"); ;}
    break;

  case 563:
#line 4722 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-preserve"); ;}
    break;

  case 564:
#line 4723 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("inherit"); ;}
    break;

  case 565:
#line 4724 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-inherit"); ;}
    break;

  case 566:
#line 4725 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("declare"); ;}
    break;

  case 567:
#line 4726 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("construction"); ;}
    break;

  case 568:
#line 4727 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordering"); ;}
    break;

  case 569:
#line 4728 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("default"); ;}
    break;

  case 570:
#line 4729 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy-namespaces"); ;}
    break;

  case 571:
#line 4730 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("option"); ;}
    break;

  case 572:
#line 4731 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("version"); ;}
    break;

  case 573:
#line 4732 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("import"); ;}
    break;

  case 574:
#line 4733 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema"); ;}
    break;

  case 575:
#line 4734 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("function"); ;}
    break;

  case 576:
#line 4735 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("score"); ;}
    break;

  case 577:
#line 4736 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ftcontains"); ;}
    break;

  case 578:
#line 4737 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("weight"); ;}
    break;

  case 579:
#line 4738 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("window"); ;}
    break;

  case 580:
#line 4739 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("distance"); ;}
    break;

  case 581:
#line 4740 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("occurs"); ;}
    break;

  case 582:
#line 4741 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("times"); ;}
    break;

  case 583:
#line 4742 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("same"); ;}
    break;

  case 584:
#line 4743 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("different"); ;}
    break;

  case 585:
#line 4744 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lowercase"); ;}
    break;

  case 586:
#line 4745 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("uppercase"); ;}
    break;

  case 587:
#line 4746 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("relationship"); ;}
    break;

  case 588:
#line 4747 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("levels"); ;}
    break;

  case 589:
#line 4748 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("language"); ;}
    break;

  case 590:
#line 4749 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("any"); ;}
    break;

  case 591:
#line 4750 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("all"); ;}
    break;

  case 592:
#line 4751 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("phrase"); ;}
    break;

  case 593:
#line 4752 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exactly"); ;}
    break;

  case 594:
#line 4753 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("from"); ;}
    break;

  case 595:
#line 4754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("words"); ;}
    break;

  case 596:
#line 4755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentences"); ;}
    break;

  case 597:
#line 4756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentence"); ;}
    break;

  case 598:
#line 4757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("paragraph"); ;}
    break;

  case 599:
#line 4758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("replace"); ;}
    break;

  case 600:
#line 4759 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("modify"); ;}
    break;

  case 601:
#line 4760 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("first"); ;}
    break;

  case 602:
#line 4761 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insert"); ;}
    break;

  case 603:
#line 4762 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("bofer"); ;}
    break;

  case 604:
#line 4763 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("after"); ;}
    break;

  case 605:
#line 4764 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("revalidation"); ;}
    break;

  case 606:
#line 4765 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("with"); ;}
    break;

  case 607:
#line 4766 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("nodes"); ;}
    break;

  case 608:
#line 4767 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("rename"); ;}
    break;

  case 609:
#line 4768 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("last"); ;}
    break;

  case 610:
#line 4769 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("delete"); ;}
    break;

  case 611:
#line 4770 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("into"); ;}
    break;

  case 612:
#line 4771 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("updating"); ;}
    break;

  case 613:
#line 4772 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordered"); ;}
    break;

  case 614:
#line 4773 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("unordered"); ;}
    break;

  case 615:
#line 4785 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 616:
#line 4791 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 617:
#line 4808 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 618:
#line 4812 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 619:
#line 4816 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 620:
#line 4820 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 621:
#line 4830 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 622:
#line 4833 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 623:
#line 4836 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 624:
#line 4839 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 625:
#line 4848 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 626:
#line 4851 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 627:
#line 4860 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 628:
#line 4863 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 629:
#line 4872 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 630:
#line 4875 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 631:
#line 4884 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 632:
#line 4887 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 633:
#line 4896 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 634:
#line 4899 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 635:
#line 4902 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 636:
#line 4911 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 637:
#line 4914 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 638:
#line 4923 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 639:
#line 4927 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, static_cast<Expr *> ((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 640:
#line 4937 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 641:
#line 4940 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 642:
#line 4943 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 643:
#line 4946 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 644:
#line 4949 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 645:
#line 4958 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 646:
#line 4967 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 647:
#line 4971 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 648:
#line 4975 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 649:
#line 4979 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 650:
#line 4983 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 651:
#line 4987 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 652:
#line 4991 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 653:
#line 5001 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 654:
#line 5004 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 655:
#line 5007 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 656:
#line 5010 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 657:
#line 5019 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 658:
#line 5022 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 659:
#line 5025 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 660:
#line 5028 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 661:
#line 5037 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 662:
#line 5040 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 663:
#line 5049 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 664:
#line 5052 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 665:
#line 5055 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 666:
#line 5058 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 667:
#line 5061 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 668:
#line 5064 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 669:
#line 5067 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 670:
#line 5076 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 671:
#line 5079 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 672:
#line 5088 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 673:
#line 5091 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 674:
#line 5094 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 675:
#line 5097 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 676:
#line 5106 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 677:
#line 5109 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 678:
#line 5112 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 679:
#line 5115 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 680:
#line 5118 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 681:
#line 5127 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 682:
#line 5130 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 683:
#line 5139 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 684:
#line 5142 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 685:
#line 5151 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 686:
#line 5154 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 687:
#line 5163 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 688:
#line 5166 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 689:
#line 5175 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 690:
#line 5184 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 691:
#line 5187 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 692:
#line 5196 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 693:
#line 5199 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 694:
#line 5202 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 695:
#line 5211 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 696:
#line 5214 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 697:
#line 5217 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 698:
#line 5220 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 699:
#line 5223 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 700:
#line 5232 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 701:
#line 5236 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 702:
#line 5240 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 703:
#line 5244 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 704:
#line 5254 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 705:
#line 5263 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 706:
#line 5273 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 707:
#line 5282 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 708:
#line 5285 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 709:
#line 5294 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 710:
#line 5297 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 711:
#line 5300 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 712:
#line 5309 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 713:
#line 5312 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 714:
#line 5321 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6613 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -877;
  const short int
  xquery_parser::yypact_[] =
  {
      1198,  -877,  -877,  -877,  -877,  -117,   285,   140,   385,   211,
    6024,    16,   493,   494,    31,  -877,  -877,   230,   220,  -877,
     556,   274,  -877,   242,  -877,  -877,  -877,   483,  -877,   388,
     499,  -877,   570,  -877,   491,   505,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  6258,  -877,  5312,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  7428,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
     519,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  4102,  1440,  7428,  -877,  -877,  -877,  -877,  -877,
    -877,   503,  -877,  -877,  -877,   622,  -877,  5790,  -877,  -877,
    -877,  -877,  -877,  7428,  -877,  5070,  4828,  -877,  -877,  -877,
    -877,  -877,  -877,   531,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,    21,   472,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,   447,   543,   448,  -877,   481,   -59,  -877,  -877,
    -877,  -877,  -877,  -877,   591,  -877,   562,   596,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,   688,  1682,  -877,  -877,   467,  4102,
     528,   529,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,   611,  -877,  -877,   121,
    -877,  -877,  -877,  -877,  -877,  -877,   557,   634,  -877,   685,
     475,   420,   328,   428,   455,  -877,   645,   537,   633,   635,
    4344,  -877,  -877,  -877,     6,  -877,  -877,  -877,   476,  -877,
     585,  5312,  -877,   585,  5312,  -877,  -877,  -877,  -877,   585,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,   583,  -877,
    4102,  -877,  4102,  4102,   590,   592,   594,  4102,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  4102,  6492,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,   595,  4102,  4102,   563,  4102,
     565,  7428,   682,   686,  7428,   354,    -8,   705,   171,   374,
     639,   270,   708,   436,    34,  4102,  -877,  4102,    81,   608,
      46,   109,  7428,   708,  7428,  4102,  7428,  -877,  7428,    39,
    4102,  6726,   612,   610,   613,   614,   615,   616,  -877,  -877,
    -877,  7428,  1924,   -21,  -877,     1,   714,  4102,    56,  -877,
     725,   588,  -877,  -877,  4102,   561,  -877,   728,  4102,  4102,
     593,  4102,  4102,  4102,  4102,   545,  7428,  4102,  7428,  -877,
    -877,  -877,    31,   556,  -877,  -877,   467,   713,  4102,   618,
     483,   499,   619,   621,  4102,  4102,  -877,   112,   115,   597,
    4586,  4586,  4586,  -877,  4586,  4586,  -877,  4586,  -877,  4586,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  4586,  4586,    18,
    4586,  4586,  4586,  4586,  4586,  4586,  4586,  4586,  4586,  4586,
    4586,   548,   684,   687,   691,  -877,  -877,  -877,  2166,  -877,
    4828,  4828,  4102,   585,  -877,  -877,   585,  -877,   585,  2408,
    -877,   599,   228,  4102,  4102,  4102,     4,   239,  -877,   161,
     176,  2650,   278,   283,  -877,   299,  -877,   627,  7428,  7428,
     744,  -877,  -877,  -877,  -877,  -877,  -877,   689,   692,  -877,
    -877,  7428,   637,   638,   705,   667,   669,  -877,  -877,  -877,
     407,    48,   409,   755,  -877,  -877,   387,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,   191,   313,   620,  -877,   628,
    2892,   708,   706,   743,   708,   705,   717,    -2,  -877,    57,
     675,   709,  -877,     7,   640,   710,  -877,   -18,   632,   610,
     491,  -877,   636,   641,   353,  -877,   205,   218,  3134,   208,
    -877,   131,  -877,  -877,  7428,   714,  -877,     0,   358,  -877,
    -877,  -877,  -877,   362,  -877,   167,  -877,  -877,  -877,    83,
      91,   724,   586,   603,   -17,  -877,   694,   647,   347,  -877,
    -877,   643,  -877,    20,  -877,  -877,   661,  4102,   718,  -877,
    -877,  4102,   135,   649,  4102,   652,  4102,   634,  -877,  -877,
    -877,  -877,  -877,  4586,  -877,  -877,  -877,  4102,    18,   371,
    -877,   566,   454,   589,   584,  -877,  -877,   581,   -91,   328,
     328,   141,   428,   428,   428,   428,   455,   455,  -877,  -877,
    7194,  7194,  7428,  7428,  -877,   367,  -877,  -877,    -1,  -877,
    -877,  -877,   219,   693,  -877,   368,   369,   376,   745,   698,
    7428,  -877,  7428,  -877,  -877,   380,  -877,  -877,  -877,   260,
      19,   627,   627,  -877,   449,   450,   457,   705,   705,  -877,
     439,   705,  -877,  -877,   576,  -877,  -877,   569,   432,  -877,
    -877,  -877,  -877,  -877,  -877,   577,  -877,  -877,   656,   703,
    -877,  -877,  -877,   381,   726,   705,   696,   727,   758,   705,
     741,  4102,  7194,  4102,   719,   705,   746,  4102,   747,   722,
     -50,  -877,   748,   749,  4102,   -45,   729,   -36,  -877,  -877,
    -877,   720,  7428,  -877,  7428,  -877,  -877,   383,  4102,  -877,
     818,  -877,   350,  -877,    69,  -877,  -877,   826,  -877,   444,
    4102,  4102,  4102,   445,  4102,  4102,  4102,  4102,  4102,  4102,
     756,  4102,  4102,   642,   731,   759,   713,  4102,   502,   768,
    -877,  7428,    15,  -877,  -877,  4102,   699,  4102,  -877,  4102,
    -877,  -877,   390,   695,  -877,   644,  -877,   311,  -877,   280,
      25,   646,    18,   280,  4586,  4586,   484,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,    18,   739,    25,  -877,   609,   810,
    -877,  -877,   738,   750,  -877,     9,  -877,  -877,  -877,  -877,
    -877,   751,  -877,  -877,  -877,  4102,  -877,  -877,  -877,  -877,
    -877,  6960,    61,  -877,  3376,   711,   715,   760,   716,   721,
    -877,  7428,   802,   232,  -877,  -877,  4102,  -877,   301,   693,
    -877,  -877,  -877,  -877,  -877,  4102,   433,  -877,  -877,  -877,
    -877,  -877,   623,    51,   855,  -877,    66,  -877,  -877,  4102,
    3618,  -877,   705,   795,  -877,  -877,  -877,   705,   795,  7428,
    -877,  -877,  -877,  4102,   723,  7428,  -877,  7428,  4102,  4102,
     767,  7428,  7428,  -877,  4102,   764,  4102,  4102,   -27,   765,
    3860,   732,  -877,   733,  -877,  -877,  -877,   780,  -877,   162,
    -877,  -877,   881,  -877,  -877,  4102,  7428,  -877,  -877,   276,
    -877,  -877,  -877,   734,   683,   700,  -877,  -877,  -877,   701,
     702,  -877,  -877,  -877,  -877,  -877,   690,  7428,   737,  -877,
     769,   642,  -877,  4102,  7428,   768,  -877,   705,  -877,   553,
    -877,    50,   814,  -877,  4102,   817,   718,  -877,  -877,     3,
    -877,  4102,  -877,  -877,  -877,  -877,  4586,  -877,  -877,  -877,
    -877,  -877,    76,  4586,  4586,   321,  -877,   589,  -877,  -877,
     206,  4586,  -877,  -877,   584,    18,   657,  -877,  -877,   752,
     753,  -877,  -877,  -877,  -877,  -877,  -877,  7428,   757,    23,
    -877,  -877,   397,  -877,  -877,  -877,  -877,  -877,   832,  7194,
     812,   833,   402,  -877,  -877,  -877,  -877,  -877,  4102,    12,
     885,   889,    12,    -9,   240,   245,   815,  -877,   403,   841,
     705,   795,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  4102,
    -877,  -877,  -877,  4102,  -877,  -877,  4102,   797,  4102,  -877,
     406,  -877,  -877,   818,  7428,   419,  -877,   418,   818,  7428,
    -877,  -877,  4102,  4102,  4102,  4102,  4102,  -877,  4102,  5554,
    -877,   761,  -877,  -877,  -877,  -877,   814,  -877,  -877,  -877,
     705,  -877,  -877,  -877,  -877,  -877,   428,  4586,  4586,   428,
     427,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,   849,  4102,  7428,  4102,  -877,  -877,  -877,  -877,  7194,
    -877,  -877,    51,    51,    12,  -877,  -877,  -877,    27,    12,
     899,   697,   850,  -877,   850,  -877,  4102,  -877,   705,  -877,
    -877,  -877,  -877,  4102,  -877,  -877,    82,   818,  7428,  -877,
     754,   818,  -877,  -877,  -877,  -877,  -877,  -877,   248,  -877,
    -877,  -877,   428,   428,  4586,  7194,  -877,   763,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,    25,  -877,   254,  -877,   256,
    -877,   795,  -877,   207,   307,  -877,   762,   818,  -877,   766,
     831,   800,   428,   770,  4102,   704,   850,  -877,  -877,  -877,
    -877,   858,   329,  -877,  -877,  -877,  -877,   774,   342,  -877,
    -877,  -877,   771,  -877,  7428,  -877,  4102,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,   258,  -877,   839,
     800,  7428,  -877,   288,   840,   800,  7428,  -877,   775,   800,
    -877
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   296,   297,   475,   443,     0,     0,     0,   554,   488,
     480,   496,   487,   478,   566,   575,   612,   482,   484,   511,
     573,   536,   530,     0,   571,   508,   574,   526,   567,     0,
     524,   568,     0,   492,   486,   479,   570,   545,   485,   490,
     287,   290,   544,   540,   531,   521,   477,   277,     0,   539,
     547,   555,   275,   535,   313,   522,   569,   276,   279,   532,
     549,     0,   319,   285,   315,   542,   476,   533,   534,   562,
     537,   553,   561,   281,   280,   495,   525,   564,   314,   552,
     557,   481,     0,     0,     0,   235,   550,   560,   565,   563,
     543,   613,   529,   528,   286,     0,   234,     0,   289,   288,
     558,   523,   538,     0,   278,   260,     0,   295,   559,   541,
     548,   556,   551,   614,   515,   520,   519,   518,   517,   516,
     489,   527,     0,     0,   572,   509,   604,   603,   605,   494,
     493,   512,   610,   483,   602,   607,   608,   599,   514,   546,
     601,   611,   609,   600,   513,   606,     0,     0,   591,   590,
     498,   491,   500,   499,   584,   580,   506,   510,   507,   593,
     594,   577,   497,   589,   588,   585,   581,   598,   592,   587,
     583,   576,   597,   596,   582,   586,   578,   579,   501,   502,
     504,   595,   503,   505,     0,     0,     2,     4,     0,     0,
       0,     0,    15,    17,    19,    20,    21,    27,    22,    25,
      26,    31,    32,    33,    28,    29,    35,    36,    23,    30,
     112,   109,   110,   111,    24,     9,    94,    95,    97,     0,
     121,   123,   124,    98,    99,   100,   101,   191,   193,   195,
     205,   208,   210,   213,   218,   221,   224,   226,   228,   230,
       0,   232,   238,   240,     0,   256,   239,   263,   264,   267,
     269,     0,   274,   271,     0,   282,   292,   294,   268,   298,
     303,   311,   304,   305,   306,   309,   310,   307,   308,   326,
     328,   329,   330,   327,   375,   376,   377,   378,   379,   380,
     291,   417,   409,   416,   415,   414,   411,   413,   410,   412,
     312,    34,   102,   103,   105,   104,   106,   107,   293,   108,
       0,    81,     0,     0,     0,     0,     0,     0,   554,   488,
     480,   496,   487,   478,   566,   482,   484,   573,   536,   526,
     524,   486,   479,   477,   537,     0,     0,   613,   614,   610,
     483,   602,   608,   599,   513,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,     0,
       0,     0,     0,   480,   487,   478,   484,   477,   283,   293,
     316,     0,     0,     0,   317,     0,   342,     0,     0,   259,
       0,     0,   261,   262,     0,     0,   371,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       3,     5,     0,     0,    10,     8,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,   122,     0,     0,     0,
       0,     0,     0,   249,     0,     0,   247,     0,   200,     0,
     248,   241,   246,   245,   244,   243,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,   236,   233,     0,   257,
       0,     0,     0,   270,   300,   273,   272,   284,   299,     0,
      79,     0,     0,     0,     0,     0,     0,     0,   433,     0,
       0,     0,     0,     0,   422,     0,   423,     0,     0,     0,
       0,    70,    71,    44,    45,   473,    53,     0,     0,    38,
      39,     0,     0,     0,     0,     0,     0,   444,   445,   446,
       0,     0,     0,     0,   653,   654,     0,    43,   646,   647,
     648,   649,   650,   651,   652,     0,     0,     0,   424,     0,
       0,     0,    62,     0,     0,     0,    54,     0,   180,     0,
       0,   138,   139,     0,     0,   125,   126,     0,     0,     0,
       0,   419,     0,     0,     0,   427,     0,     0,     0,     0,
      76,     0,    77,   318,   343,   342,   339,     0,     0,   373,
     372,   258,   432,     0,   370,     0,   457,   458,   418,     0,
       0,     0,     0,     0,     0,   463,     0,     0,     0,   141,
     147,     0,    16,     0,    18,    96,     0,     0,     0,   113,
     148,     0,     0,     0,     0,     0,     0,   192,   194,   198,
     204,   203,   202,     0,   199,   196,   197,     0,     0,     0,
     638,   206,   617,   625,   627,   629,   631,   633,   636,   212,
     211,   209,   215,   216,   217,   214,   219,   220,   223,   222,
       0,     0,     0,     0,   254,     0,   265,   266,     0,   301,
     322,   324,     0,     0,   250,     0,     0,     0,     0,     0,
       0,   437,     0,   434,   382,     0,   381,   390,   391,     0,
       0,     0,     0,    42,     0,     0,     0,     0,     0,    52,
       0,     0,   655,   656,     0,   657,   661,     0,     0,   690,
     659,   660,   689,   658,   662,     0,   669,   691,     0,     0,
     426,   425,   392,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   616,     0,     0,     0,     0,     0,     0,   440,   420,
     421,     0,     0,   430,     0,   428,   386,     0,     0,    78,
     342,   340,     0,   331,     0,   320,   321,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,   164,   160,
     162,     0,   149,   153,   114,     0,     0,     0,   117,     0,
     115,   201,     0,     0,   632,     0,   207,     0,   645,     0,
       0,     0,     0,     0,     0,     0,   618,   622,   640,   621,
     644,   642,   641,   643,     0,     0,     0,   634,   697,   695,
     699,   637,   481,   489,   225,   399,   405,   406,   408,   227,
     229,   396,   231,   255,   302,     0,   323,    80,   251,   252,
     253,     0,     0,   186,     0,     0,     0,   441,     0,     0,
     383,     0,    72,     0,    88,    83,     0,    84,     0,     0,
      50,    51,    48,    49,    67,     0,     0,    40,    41,    46,
      47,    37,     0,     0,     0,   664,     0,   663,   680,     0,
       0,   393,     0,    64,    58,    61,    60,     0,    56,     0,
     178,   398,   182,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
       0,     0,   441,     0,   387,   179,   343,     0,   332,     0,
     366,   363,     0,   367,   368,     0,     0,   369,   362,     0,
     337,   365,   364,     0,     0,     0,   450,   451,   447,     0,
       0,   455,   456,   452,   461,   459,     0,     0,     0,   465,
       0,   466,   467,     0,     0,   161,   173,     0,   174,     0,
     165,   166,   167,   168,     0,   155,     0,   158,   151,   150,
     118,     0,   116,   119,   639,   635,     0,   692,   693,   713,
     712,   708,     0,     0,     0,     0,   694,   626,   707,   619,
       0,     0,   624,   623,   628,     0,     0,   698,   696,     0,
       0,   402,   404,   403,   400,   397,   325,     0,     0,     0,
     187,   384,     0,   438,   439,   442,   435,   436,    90,     0,
       0,    73,     0,    85,    86,    87,    66,    69,     0,   678,
       0,     0,   676,   672,     0,     0,     0,   394,     0,    63,
       0,    57,   181,   183,    11,   140,   137,   145,   144,     0,
     127,   136,   130,     0,   132,   129,     0,     0,     0,   388,
       0,   431,   429,   342,     0,     0,   374,     0,   342,     0,
     338,     7,     0,     0,     0,     0,     0,   464,     0,     0,
     468,     0,   142,   177,   175,   176,   169,   170,   171,   163,
       0,   156,   154,   159,   152,   120,   714,     0,     0,   700,
       0,   711,   710,   709,   704,   705,   620,   630,   706,   407,
     401,     0,     0,     0,     0,   385,    91,    74,    89,     0,
      93,    68,     0,     0,   679,   681,   683,   685,     0,   677,
       0,     0,     0,   667,     0,   665,     0,   395,     0,    59,
     146,   134,   131,     0,   133,   389,     0,   342,     0,    92,
       0,   342,   448,   449,   453,   454,   460,   462,     0,   615,
     172,   157,   702,   701,     0,     0,   188,     0,   184,    75,
     688,   687,   682,   686,   684,   673,   674,     0,   670,     0,
     190,    65,   135,   352,   346,   341,     0,   342,   333,     0,
       0,     0,   703,     0,     0,     0,     0,   668,   666,   360,
     354,     0,   353,   355,   361,   358,   348,     0,   347,   349,
     359,   335,     0,   334,     0,   469,     0,   185,   675,   671,
     345,   356,   357,   344,   350,   351,   336,     0,   189,     0,
       0,     0,   470,     0,     0,     0,     0,   471,     0,     0,
     472
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -877,  -877,  -877,   772,   773,  -877,   776,  -877,   518,   520,
    -408,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -716,  -877,  -877,  -877,  -877,   -26,
    -635,  -877,  -877,  -877,  -877,  -877,  -877,   -81,  -877,  -847,
     777,   -77,  -292,  -877,  -877,   730,  -877,  -877,    40,   203,
    -530,  -752,  -877,  -877,    47,   -11,  -751,   521,  -877,   -20,
    -877,  -877,  -379,   168,   -14,  -877,  -877,    -7,  -858,  -877,
     571,    58,  -877,  -877,   111,  -877,  -877,   525,   530,  -877,
    -392,  -772,   504,   214,  -431,   200,   209,  -877,  -877,  -877,
    -877,  -877,   735,  -877,  -877,  -877,  -877,  -877,   707,  -877,
     -86,  -877,  -877,  -877,  -877,  -877,  -877,  -877,   -22,  -120,
    -877,  -877,   324,   -57,  -877,  -447,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -725,  -877,    41,  -877,   392,
    -559,  -877,  -877,  -877,  -877,  -877,  -246,  -239,  -876,  -589,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
     312,  -536,  -633,  -877,  -877,    24,  -638,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,   600,   601,  -213,   296,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,    26,  -877,  -877,    28,
    -346,  -319,   -10,  -877,   343,  -877,  -877,   170,   160,   -19,
     348,  -877,  -877,   172,  -877,  -597,  -877,  -877,  -877,  -877,
    -154,  -691,  -877,   -51,  -442,  -877,  -548,  -877,  -877,  -877,
    -877,  -812,  -877,  -877,  -877,  -877,    -6,   179,  -877
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   883,   545,   207,   208,   209,   680,
     210,   382,   211,   212,   213,   214,   853,   854,   927,   857,
     215,   216,   217,   218,   219,   220,   221,   555,   556,   735,
     729,   222,   551,   598,   552,   599,   427,   428,   782,   783,
    1091,   969,   429,   779,   780,   960,   961,   962,   963,   223,
     547,   548,   224,   842,   843,   225,   226,   227,   228,   623,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   447,   448,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   473,   474,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   662,   268,   269,   270,   929,   575,   576,
     577,  1185,  1207,  1208,  1201,  1202,  1209,  1203,   930,   931,
     271,   272,   932,   273,   274,   275,   276,   277,   278,   279,
     830,   724,   824,  1004,   825,   826,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   845,   846,   290,   291,
     292,   293,   294,   295,   296,   594,   595,   297,   951,   952,
     884,   359,   298,   299,   631,   806,   632,   633,   634,   635,
     636,   637,   638,   807,   808,   527,   528,   529,   530,   531,
    1177,  1178,   532,  1124,  1032,  1128,  1125,   533,   534,   810,
     821,   985,   811,   812,   817,   813,  1104,   981,   796
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       335,   506,   630,   888,   996,   383,   385,   877,   480,   604,
     481,  1024,   827,   827,   542,   546,   752,   730,   829,   392,
     393,   737,   642,   643,   644,   645,   378,   736,   837,   928,
     967,   968,   989,   516,   733,   809,   372,     4,   379,   539,
     619,   395,   620,   621,   550,   622,  1173,   624,   613,   615,
     722,   380,   733,  1070,   420,   625,   626,   341,   342,   343,
     418,   982,   579,   899,   770,   505,   420,   344,   341,   342,
     343,   559,   904,   554,   386,   722,   920,   921,   344,   720,
     418,   907,   418,   345,   827,   418,   346,   390,   347,   891,
    1056,   348,   300,   391,   349,   982,   966,   560,   356,   734,
     537,   753,    54,  1087,  1088,   350,   586,   587,   520,   589,
     590,   591,   592,    64,  1113,   597,   350,   351,  1097,  1122,
     727,  1030,   818,   819,  1001,   722,   605,   855,   505,   468,
     957,   503,   609,   610,   694,   841,   874,    78,   404,   336,
     572,   627,   856,   405,   820,   628,   922,  1009,   959,  1183,
     866,   759,  1034,    97,   834,  1002,   721,   419,   573,   763,
     419,   668,   352,   923,   504,   924,   419,   754,   689,   920,
     921,  1041,   420,  1003,   723,   421,  1098,   541,  1031,  1114,
     419,   630,   630,  1123,  1174,  1035,   425,   661,   728,  1070,
     771,   917,   925,   728,   928,   543,   561,    84,   425,   718,
     900,   580,   728,   827,   928,   905,   396,   909,  1008,   993,
    1199,   728,   418,    95,   920,   983,   984,  1093,  1094,  1106,
     728,  1131,   714,   353,  1025,   717,   482,  1130,  1160,   475,
     486,   791,   477,   786,   926,  1184,   354,   356,   538,   922,
     544,   379,   670,   521,   379,   728,   629,   354,   487,   983,
     984,   522,   422,   122,   423,   422,   923,   672,   924,   492,
     493,   422,   495,   423,   523,   695,   524,   302,   611,   757,
     450,   614,   418,   760,   761,   422,   525,   424,   535,   526,
     536,   764,   765,   920,   921,   925,   742,   451,   762,   720,
      84,   785,   749,   564,   696,   697,   766,   698,   699,   744,
     835,   923,   512,   924,   425,   571,    95,   513,   507,   418,
     578,  1200,   301,  1020,   920,   778,   490,   583,   671,   784,
     418,  1132,   788,   508,   790,  1205,  1134,  1064,   758,  1190,
     925,   497,  1199,   673,   500,  1196,   920,  1196,   307,  1229,
     928,   867,   868,   357,  1215,   871,   122,   358,   708,   920,
     514,   851,   549,   922,   553,   630,   557,   355,   558,   418,
    1205,   567,   743,  1195,   418,   362,   748,   630,   604,  1234,
     923,   549,   924,   363,   990,   745,   836,   457,  1057,   894,
     418,   827,   664,  1232,   656,   657,  1117,   458,  1237,  1021,
       4,   655,  1240,   669,   418,   658,   596,  1133,   600,   925,
     774,   923,  1135,   924,    84,  1191,   665,   666,   667,  1023,
     515,  1197,  1206,  1198,   675,  1230,   659,   852,   453,   659,
      95,   659,  1181,   923,   856,   924,   920,   921,   775,   890,
     925,   892,   676,  1221,   418,   896,   923,   677,   924,   418,
    1101,  1069,   903,   418,   454,  1235,  1102,  1224,   418,   418,
     418,   918,   925,   678,  1103,    54,   915,   418,   455,   848,
     122,   418,   418,   713,   418,   925,    64,   709,   936,   937,
     938,   418,   941,   942,   943,   944,   945,   946,   418,   948,
     949,   827,  1116,   418,   418,   778,  1169,   418,   681,   682,
      78,   747,   456,   970,   627,   972,   922,   973,   628,   418,
     977,   686,   874,   412,  1146,  1219,   501,   741,   303,  1150,
     413,   365,   755,   923,   979,   924,   756,   919,   875,   980,
     502,   833,   838,   839,   797,   722,   509,   827,   520,   911,
     840,   913,  1193,   978,   850,   881,  1039,   914,   869,   870,
     510,  1027,   925,  1006,   974,  1096,  1028,    84,   630,   450,
     792,  1115,  1099,  1100,   797,  1101,  1120,  1137,   520,   876,
    1145,  1102,   459,    95,   750,   864,   451,   860,   862,  1103,
     865,   956,  1149,  1026,   364,   460,  1172,   476,   304,   305,
     306,  1172,   957,   478,  1148,   861,   863,  1036,  1186,   452,
     366,   958,  1189,   798,  1204,  1210,  1164,   367,   457,   457,
     959,  1043,   360,   122,   703,   361,  1047,  1048,   458,   458,
     381,  1083,  1052,  1204,  1054,  1055,   337,   339,   368,  1210,
     338,   340,   692,   798,   700,   693,   387,   701,  1212,   517,
     518,   519,   369,   704,   705,   388,   706,   707,   470,   471,
     828,   828,   828,   828,   398,   401,   399,   402,   934,   939,
     935,   940,  1084,  1085,   394,   858,   859,   646,   647,   397,
     847,  1081,   847,   521,   639,   640,  1162,  1163,   648,   649,
     400,   522,   778,   799,   800,   801,   831,   831,   403,  1095,
    1170,  1171,   406,   802,   523,   407,   524,   408,   409,   416,
     417,   803,   418,   521,  1139,   430,   525,   804,   805,   526,
     431,   522,   449,   799,   800,   801,   461,   462,   463,   472,
     479,   464,   828,   483,   523,   484,   524,   485,   491,   498,
     494,   803,   496,   499,   505,   356,   525,   991,   805,   526,
     511,   540,   912,  1192,   912,   568,  1121,   326,   574,   581,
     338,   340,   358,   371,  1161,   582,   584,   585,   593,   603,
     588,   650,   651,   616,   679,   652,   663,  1140,   606,   653,
     607,  1141,   608,   683,  1142,   690,  1144,  1012,   687,   688,
     684,   965,   691,   685,   702,   716,   715,   710,   725,  1022,
    1152,  1153,  1154,  1155,  1156,   711,  1157,   719,   432,   738,
     726,   732,   767,   739,   731,   768,   433,   434,   740,   435,
     769,   773,   777,  1038,   776,   787,   436,   772,   789,   781,
     437,   795,   815,   438,   816,   814,    82,   873,   439,   841,
    1166,   844,  1168,   872,   879,   878,   880,   885,   887,   882,
     886,   828,   889,  1060,   440,   898,   893,   895,   897,   901,
     902,  1018,   916,   910,  1180,   933,   906,   947,  1067,   964,
     954,  1182,   975,   950,   953,   971,   995,   997,   998,   441,
     442,   443,   444,   445,   446,   999,  1005,   976,  1013,   986,
    1019,  1029,  1014,  1016,  1033,  1015,  1040,  1000,  1017,   549,
    1049,  1053,  1058,  1063,  1044,   553,  1066,  1046,  1072,  1061,
    1062,   557,  1051,  1078,   957,  1071,  1079,  1090,  1108,  1076,
     722,  1119,  1217,   851,  1126,  1073,  1074,  1075,  1127,  1109,
    1110,  1138,  1136,  1112,  1143,  1159,  1068,  1165,  1175,  1194,
     874,  1188,  1214,   856,  1228,  1220,  1216,  1223,  1176,  1211,
    1231,  1236,  1239,  1213,   601,  1218,   602,   596,  1226,  1118,
     908,  1050,  1045,  1082,   600,   955,  1092,  1042,   612,   426,
    1089,   469,   569,  1010,  1086,   617,   641,   410,   411,  1158,
    1065,   618,  1225,  1222,   414,   832,   415,   751,   849,   562,
     563,   793,   987,  1077,   994,   467,  1107,   794,   992,  1080,
    1179,  1129,   988,     0,  1105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   828,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1147,     0,     0,     0,     0,  1151,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1167,     0,     0,     0,     0,     0,   828,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   828,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1227,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,  1233,     0,     5,     6,     0,  1238,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     0,    43,    44,    45,    46,
      47,    48,    49,    50,    51,     0,     0,    52,    53,     0,
       0,     0,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,     0,    65,    66,    67,    68,     0,
      69,     0,     0,     0,    70,    71,    72,    73,    74,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,     0,     0,     0,    83,    84,    85,    86,    87,
       0,     0,     0,     0,    88,    89,    90,    91,    92,    93,
       0,    94,    95,     0,    96,    97,     0,     0,    98,    99,
     100,     0,     0,     0,   101,     0,   102,   103,   104,     0,
     105,   106,   107,     0,   108,     0,   109,   110,   111,   112,
     113,     0,   114,   115,   116,   117,   118,   119,     0,     0,
     120,   121,   122,     0,   123,   124,     0,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,   161,   162,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     0,     0,     7,
       8,     9,    10,    11,    12,    13,   314,    15,    16,     0,
      17,    18,    19,   317,    21,    22,     0,    24,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     0,    43,    44,
      45,    46,    47,    48,    49,    50,    51,     0,     0,    52,
      53,     0,     0,     0,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,    64,     0,    65,    66,    67,
      68,     0,    69,     0,     0,     0,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     0,    83,    84,    85,
      86,    87,     0,     0,     0,     0,    88,    89,    90,    91,
      92,    93,     0,    94,    95,     0,    96,    97,     0,     0,
      98,    99,   100,     0,     0,     0,   101,   384,   102,   103,
     104,     0,   105,   106,   107,     0,   108,     0,   109,   110,
     111,   112,   113,     0,   114,   115,   116,   117,   118,   119,
       0,     0,   120,   121,   122,     0,     0,   124,     0,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,   161,   162,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     0,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     0,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     0,
      43,    44,    45,    46,    47,    48,    49,    50,    51,     0,
       0,    52,    53,     0,     0,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,    64,     0,    65,
      66,    67,    68,     0,    69,     0,     0,     0,    70,    71,
      72,    73,    74,     0,     0,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,     0,    83,
      84,    85,    86,    87,     0,     0,     0,     0,    88,    89,
      90,    91,    92,    93,     0,    94,    95,     0,    96,    97,
       0,     0,    98,    99,   100,     0,     0,     0,   101,     0,
     102,   103,   104,     0,   105,   106,   107,     0,   108,     0,
     109,   110,   111,   112,   113,     0,   114,   115,   116,   117,
     118,   119,     0,     0,   120,   121,   122,     0,     0,   124,
       0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,   161,
     162,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     5,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
     314,    15,    16,     0,    17,    18,    19,   317,    21,    22,
       0,    24,    25,    26,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     0,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     0,     0,    52,    53,     0,     0,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,    64,
       0,    65,    66,    67,    68,     0,    69,     0,     0,     0,
      70,    71,    72,    73,    74,     0,     0,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
       0,    83,    84,    85,    86,    87,     0,     0,     0,     0,
      88,    89,    90,    91,    92,    93,     0,    94,    95,     0,
      96,    97,     0,     0,    98,    99,   100,     0,   570,     0,
     101,     0,   102,   103,   104,     0,   105,   106,   107,     0,
     108,     0,   109,   110,   111,   112,   113,     0,   114,   115,
     116,   117,   118,   119,     0,     0,   120,   121,   122,     0,
       0,   124,     0,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,   161,   162,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     0,     0,     7,     8,     9,    10,    11,
      12,    13,   314,    15,    16,     0,    17,    18,    19,   317,
      21,    22,     0,    24,    25,    26,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,    51,     0,     0,    52,    53,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       0,    64,     0,    65,    66,    67,    68,     0,    69,     0,
       0,     0,    70,    71,    72,    73,    74,     0,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
       0,     0,     0,    83,    84,    85,    86,    87,     0,     0,
       0,     0,    88,    89,    90,    91,    92,    93,     0,    94,
      95,     0,    96,    97,     0,     0,    98,    99,   100,     0,
     654,     0,   101,     0,   102,   103,   104,     0,   105,   106,
     107,     0,   108,     0,   109,   110,   111,   112,   113,     0,
     114,   115,   116,   117,   118,   119,     0,     0,   120,   121,
     122,     0,     0,   124,     0,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,     0,   161,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     0,     0,     7,     8,     9,
      10,    11,    12,    13,   314,    15,    16,     0,    17,    18,
      19,   317,    21,    22,     0,    24,    25,    26,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     0,    43,    44,    45,    46,
      47,    48,    49,    50,    51,     0,     0,    52,    53,     0,
       0,     0,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,     0,    65,    66,    67,    68,     0,
      69,     0,     0,     0,    70,    71,    72,    73,    74,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,     0,     0,     0,    83,    84,    85,    86,    87,
       0,     0,     0,     0,    88,    89,    90,    91,    92,    93,
       0,    94,    95,     0,    96,    97,     0,     0,    98,    99,
     100,     0,     0,     0,   101,   660,   102,   103,   104,     0,
     105,   106,   107,     0,   108,     0,   109,   110,   111,   112,
     113,     0,   114,   115,   116,   117,   118,   119,     0,     0,
     120,   121,   122,     0,     0,   124,     0,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,   161,   162,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     0,     0,     7,
       8,     9,    10,    11,    12,    13,   314,    15,    16,     0,
      17,    18,    19,   317,    21,    22,     0,    24,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     0,    43,    44,
      45,    46,    47,    48,    49,    50,    51,     0,     0,    52,
      53,     0,     0,     0,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,    64,     0,    65,    66,    67,
      68,     0,    69,     0,     0,     0,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     0,    83,    84,    85,
      86,    87,     0,     0,     0,     0,    88,    89,    90,    91,
      92,    93,     0,    94,    95,     0,    96,    97,     0,     0,
      98,    99,   100,     0,   674,     0,   101,     0,   102,   103,
     104,     0,   105,   106,   107,     0,   108,     0,   109,   110,
     111,   112,   113,     0,   114,   115,   116,   117,   118,   119,
       0,     0,   120,   121,   122,     0,     0,   124,     0,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,   161,   162,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     0,
       0,     7,     8,     9,    10,    11,    12,    13,   314,    15,
      16,     0,    17,    18,    19,   317,    21,    22,     0,    24,
      25,    26,     0,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     0,
      43,    44,    45,    46,    47,    48,    49,    50,    51,     0,
       0,    52,    53,     0,     0,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,    64,     0,    65,
      66,    67,    68,     0,    69,     0,     0,     0,    70,    71,
      72,    73,    74,     0,     0,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,     0,    83,
      84,    85,    86,    87,     0,     0,     0,     0,    88,    89,
      90,    91,    92,    93,     0,    94,    95,     0,    96,    97,
       0,     0,    98,    99,   100,     0,   712,     0,   101,     0,
     102,   103,   104,     0,   105,   106,   107,     0,   108,     0,
     109,   110,   111,   112,   113,     0,   114,   115,   116,   117,
     118,   119,     0,     0,   120,   121,   122,     0,     0,   124,
       0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,   161,
     162,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     5,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
     314,    15,    16,     0,    17,    18,    19,   317,    21,    22,
       0,    24,    25,    26,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     0,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     0,     0,    52,    53,     0,     0,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,    64,
       0,    65,    66,    67,    68,     0,    69,     0,     0,     0,
      70,    71,    72,    73,    74,     0,     0,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
       0,    83,    84,    85,    86,    87,     0,     0,     0,     0,
      88,    89,    90,    91,    92,    93,     0,    94,    95,     0,
      96,    97,     0,     0,    98,    99,   100,     0,   746,     0,
     101,     0,   102,   103,   104,     0,   105,   106,   107,     0,
     108,     0,   109,   110,   111,   112,   113,     0,   114,   115,
     116,   117,   118,   119,     0,     0,   120,   121,   122,     0,
       0,   124,     0,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,   161,   162,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     0,     0,     7,     8,     9,    10,    11,
      12,    13,   314,    15,    16,     0,    17,    18,    19,   317,
      21,    22,     0,    24,    25,    26,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,    51,     0,     0,    52,    53,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       0,    64,     0,    65,    66,    67,    68,     0,    69,     0,
       0,     0,    70,    71,    72,    73,    74,     0,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
       0,     0,     0,    83,    84,    85,    86,    87,     0,     0,
       0,     0,    88,    89,    90,    91,    92,    93,     0,    94,
      95,     0,    96,    97,     0,     0,    98,    99,   100,     0,
    1011,     0,   101,     0,   102,   103,   104,     0,   105,   106,
     107,     0,   108,     0,   109,   110,   111,   112,   113,     0,
     114,   115,   116,   117,   118,   119,     0,     0,   120,   121,
     122,     0,     0,   124,     0,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,     0,   161,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     0,     0,     7,     8,     9,
      10,    11,    12,    13,   314,    15,    16,     0,    17,    18,
      19,   317,    21,    22,     0,    24,    25,    26,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     0,    43,    44,    45,    46,
      47,    48,    49,    50,    51,     0,     0,    52,    53,     0,
       0,     0,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,     0,    65,    66,    67,    68,     0,
      69,     0,     0,     0,    70,    71,    72,    73,    74,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,     0,     0,     0,    83,    84,    85,    86,    87,
       0,     0,     0,     0,    88,    89,    90,    91,    92,    93,
       0,    94,    95,     0,    96,    97,     0,     0,    98,    99,
     100,     0,  1037,     0,   101,     0,   102,   103,   104,     0,
     105,   106,   107,     0,   108,     0,   109,   110,   111,   112,
     113,     0,   114,   115,   116,   117,   118,   119,     0,     0,
     120,   121,   122,     0,     0,   124,     0,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,   161,   162,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     0,     0,     7,
       8,     9,    10,    11,    12,    13,   314,    15,    16,     0,
      17,    18,    19,   317,    21,    22,     0,    24,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     0,    43,    44,
      45,    46,    47,    48,    49,    50,    51,     0,     0,    52,
      53,     0,     0,     0,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,    64,     0,    65,    66,    67,
      68,     0,    69,     0,     0,     0,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     0,    83,    84,    85,
      86,    87,     0,     0,     0,     0,    88,    89,    90,    91,
      92,    93,     0,    94,    95,     0,    96,    97,     0,     0,
      98,    99,   100,     0,  1059,     0,   101,     0,   102,   103,
     104,     0,   105,   106,   107,     0,   108,     0,   109,   110,
     111,   112,   113,     0,   114,   115,   116,   117,   118,   119,
       0,     0,   120,   121,   122,     0,     0,   124,     0,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,   161,   162,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     0,
       0,     7,     8,     9,    10,    11,    12,    13,   314,    15,
      16,     0,    17,    18,    19,   317,    21,    22,     0,    24,
      25,    26,     0,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     0,
      43,    44,    45,    46,    47,    48,    49,    50,    51,     0,
       0,    52,    53,     0,     0,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,    64,     0,    65,
      66,    67,    68,     0,    69,     0,     0,     0,    70,    71,
      72,    73,    74,     0,     0,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,     0,    83,
      84,    85,    86,    87,     0,     0,     0,     0,    88,    89,
      90,    91,    92,    93,     0,    94,    95,     0,    96,    97,
       0,     0,    98,    99,   100,     0,     0,     0,   101,     0,
     102,   103,   104,     0,   105,   106,   107,     0,   108,     0,
     109,   110,   111,   112,   113,     0,   114,   115,   116,   117,
     118,   119,     0,     0,   120,   121,   122,     0,     0,   124,
       0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,   161,
     162,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,   309,    10,    11,    12,    13,
     314,    15,    16,     0,   315,    18,    19,   317,   318,    22,
       0,    24,    25,    26,     0,   319,    28,     0,   320,    31,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     0,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     0,     0,    52,    53,     0,     0,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,    64,
       0,    65,    66,    67,    68,     0,    69,     0,     0,     0,
     324,    71,    72,    73,    74,     0,     0,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
       0,    83,    84,   465,    86,    87,     0,     0,     0,     0,
      88,    89,    90,    91,    92,    93,     0,    94,    95,     0,
     466,    97,     0,     0,    98,    99,   100,     0,     0,     0,
     101,     0,   102,   103,   104,     0,   105,   106,   107,     0,
     108,     0,   109,   110,   111,   112,   113,     0,   114,   115,
     116,   117,   118,   119,     0,     0,   120,   121,   122,     0,
       0,   124,     0,   125,   126,   127,   128,   129,   130,   131,
     329,   133,   331,   135,   332,   333,   138,   139,   140,   141,
     142,   143,   334,   145,     0,     0,     0,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,   161,   162,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,   309,    10,    11,
      12,    13,   314,    15,    16,     0,   315,    18,    19,   317,
     318,    22,     0,    24,    25,    26,     0,   319,    28,     0,
     320,    31,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,    51,     0,     0,    52,    53,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       0,    64,     0,    65,    66,    67,    68,     0,    69,     0,
       0,     0,   324,    71,    72,    73,    74,     0,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,     0,    83,    84,    85,    86,    87,     0,     0,
       0,     0,    88,    89,    90,    91,    92,    93,     0,    94,
      95,     0,    96,    97,     0,     0,    98,    99,   100,     0,
       0,     0,   101,     0,   102,   103,   104,     0,   105,   106,
     107,     0,   108,     0,   109,   110,   111,   112,   113,     0,
     114,   115,   116,   117,   118,   119,     0,     0,   120,   121,
     122,     0,     0,   124,     0,   125,   126,   127,   128,   129,
     130,   131,   329,   133,   331,   135,   332,   333,   138,   139,
     140,   141,   142,   143,   334,   145,     0,     0,     0,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,     0,   161,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   308,   309,
      10,    11,    12,    13,   314,    15,    16,     0,   315,    18,
      19,   317,   318,    22,     0,    24,    25,    26,     0,   319,
      28,     0,   320,    31,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     0,    43,    44,    45,    46,
      47,    48,    49,    50,    51,     0,     0,    52,    53,     0,
       0,     0,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,     0,    65,    66,    67,    68,     0,
      69,     0,     0,     0,   324,    71,    72,    73,    74,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,     0,    83,    84,     0,    86,    87,
       0,     0,     0,     0,    88,    89,    90,    91,    92,    93,
       0,    94,    95,     0,     0,     0,     0,     0,    98,    99,
     100,     0,     0,     0,   101,     0,   102,   103,   104,     0,
       0,     0,   107,     0,   108,     0,   109,   110,   111,   112,
     113,     0,   114,   115,   116,   117,   118,   119,     0,     0,
     120,   121,   122,     0,     0,   124,     0,   125,   126,   127,
     128,   129,   130,   131,   329,   133,   331,   135,   332,   333,
     138,   139,   140,   141,   142,   143,   334,   145,     0,     0,
       0,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,   161,   162,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     308,   309,    10,    11,    12,    13,   314,    15,    16,     0,
     315,    18,    19,   317,   318,    22,     0,    24,    25,    26,
       0,   319,    28,     0,   320,    31,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     0,    43,    44,
      45,    46,    47,    48,    49,    50,    51,     0,     0,    52,
      53,     0,     0,     0,    54,    55,    56,    57,    58,    59,
       0,    61,    62,    63,     0,    64,     0,    65,    66,    67,
      68,     0,    69,     0,     0,     0,   324,     0,    72,    73,
      74,     0,     0,     0,     0,     0,     0,    76,    77,    78,
       0,    80,    81,     0,     0,     0,     0,    83,    84,     0,
       0,    87,     0,     0,     0,     0,    88,    89,    90,    91,
      92,    93,     0,    94,    95,     0,     0,     0,     0,     0,
      98,    99,   100,     0,     0,     0,   101,     0,   102,   103,
     104,     0,     0,     0,     0,     0,   108,     0,   109,     0,
     111,     0,   113,     0,   114,   115,   116,   117,   118,   119,
       0,     0,   120,   121,   122,     0,     0,   124,     0,   125,
     126,   127,   128,   129,   130,   131,   329,   133,   331,   135,
     332,   333,   138,   139,   140,   141,   142,   143,   334,   145,
       0,     0,     0,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,   162,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   308,   309,   373,   311,   374,   375,   314,    15,
      16,     0,   315,   376,    19,   317,   318,    22,     0,    24,
      25,    26,     0,   319,    28,     0,   320,    31,     0,    33,
      34,    35,    36,    37,    38,    39,     0,     0,    42,     0,
      43,    44,    45,   377,     0,     0,    49,    50,    51,     0,
       0,     0,    53,     0,     0,     0,     0,    55,    56,     0,
       0,    59,    60,     0,     0,     0,     0,     0,     0,    65,
      66,    67,    68,     0,    69,     0,     0,     0,   324,    71,
      72,     0,     0,     0,     0,     0,     0,     0,    75,    76,
      77,     0,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,    86,    87,     0,     0,     0,     0,    88,    89,
      90,   327,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,     0,   101,     0,
     102,   103,     0,     0,     0,     0,   107,     0,   108,     0,
     109,   110,   111,   112,   328,     0,   114,   115,   116,   117,
     118,   119,     0,     0,   120,   121,     0,     0,     0,   124,
       0,   125,   126,   127,   128,   129,   130,   131,   329,   133,
     331,   135,   332,   333,   138,   139,   140,   141,   142,   143,
     334,   145,     0,     0,     0,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,   161,
     162,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   308,   309,   310,   311,   312,   313,
     314,    15,    16,     0,   315,   316,    19,   317,   318,    22,
       0,    24,    25,    26,     0,   319,    28,     0,   320,    31,
       0,    33,   321,   322,    36,    37,    38,    39,     0,     0,
      42,     0,    43,    44,    45,   323,     0,     0,    49,    50,
      51,     0,     0,     0,    53,     0,     0,     0,     0,    55,
      56,     0,     0,    59,    60,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,     0,    69,     0,     0,     0,
     324,    71,    72,     0,     0,     0,     0,     0,     0,     0,
      75,    76,    77,     0,    79,    80,    81,     0,     0,     0,
       0,     0,     0,     0,    86,    87,     0,     0,     0,     0,
      88,    89,    90,   327,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
     101,     0,   102,     0,     0,     0,     0,     0,   107,     0,
     108,     0,   109,   110,   111,   112,   328,     0,   114,   115,
     116,   117,   118,   119,     0,     0,   120,   121,     0,     0,
       0,   124,     0,   125,   126,   127,   128,   129,   130,   131,
     329,   330,   331,   135,   332,   333,   138,   139,   140,   141,
     142,   143,   334,   145,     0,     0,     0,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,   161,   162,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   389,     0,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     308,   309,   310,   311,   312,   313,   314,    15,    16,     0,
     315,   316,    19,   317,   318,    22,     0,    24,    25,    26,
       0,   319,    28,     0,   320,    31,     0,    33,   321,   322,
      36,    37,    38,    39,     0,     0,    42,     0,    43,    44,
      45,   323,     0,     0,    49,    50,    51,     0,     0,     0,
      53,     0,     0,     0,     0,    55,    56,     0,     0,    59,
      60,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,     0,    69,     0,     0,     0,   324,    71,    72,     0,
       0,     0,     0,     0,     0,     0,    75,    76,    77,     0,
      79,    80,    81,     0,     0,     0,     0,     0,     0,     0,
      86,    87,     0,     0,     0,     0,    88,    89,    90,   327,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,     0,     0,   101,     0,   102,     0,
       0,     0,     0,     0,     0,     0,   108,     0,   109,   110,
     111,   112,   328,     0,   114,   115,   116,   117,   118,   119,
       0,     0,   120,   121,     0,     0,     0,   124,     0,   125,
     126,   127,   128,   129,   130,   131,   329,   330,   331,   135,
     332,   333,   138,   139,   140,   141,   142,   143,   334,   145,
       0,     0,     0,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,   161,   162,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   308,   309,   310,   311,   312,   313,
     314,    15,    16,     0,   315,   316,    19,   317,   318,    22,
       0,    24,    25,    26,     0,   319,    28,     0,   320,    31,
       0,    33,   321,   322,    36,    37,    38,    39,     0,     0,
      42,     0,    43,    44,    45,   323,     0,     0,    49,    50,
      51,     0,     0,     0,    53,     0,     0,     0,     0,    55,
      56,     0,     0,    59,    60,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,     0,    69,     0,     0,     0,
     324,    71,    72,     0,     0,     0,     0,     0,     0,     0,
      75,    76,    77,     0,    79,    80,    81,   325,     0,     0,
       0,   326,     0,     0,    86,    87,     0,     0,     0,     0,
      88,    89,    90,   327,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
     101,     0,   102,     0,     0,     0,     0,     0,     0,     0,
     108,     0,   109,   110,   111,   112,   328,     0,   114,   115,
     116,   117,   118,   119,     0,     0,   120,   121,     0,     0,
       0,   124,     0,   125,   126,   127,   128,   129,   130,   131,
     329,   330,   331,   135,   332,   333,   138,   139,   140,   141,
     142,   143,   334,   145,     0,     0,     0,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,   161,   162,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   308,   309,
     310,   311,   312,   313,   314,    15,    16,     0,   315,   316,
      19,   317,   318,    22,     0,    24,    25,    26,     0,   319,
      28,     0,   320,    31,     0,    33,   321,   322,    36,    37,
      38,    39,     0,     0,    42,     0,    43,    44,    45,   323,
       0,     0,    49,    50,    51,     0,     0,     0,    53,     0,
       0,     0,     0,    55,    56,     0,     0,    59,    60,     0,
       0,     0,     0,     0,     0,    65,    66,    67,    68,     0,
      69,     0,     0,     0,   324,    71,    72,     0,     0,     0,
       0,     0,     0,     0,    75,    76,    77,     0,    79,    80,
      81,   370,     0,     0,     0,   371,     0,     0,    86,    87,
       0,     0,     0,     0,    88,    89,    90,   327,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,     0,     0,     0,   101,     0,   102,     0,     0,     0,
       0,     0,     0,     0,   108,     0,   109,   110,   111,   112,
     328,     0,   114,   115,   116,   117,   118,   119,     0,     0,
     120,   121,     0,     0,     0,   124,     0,   125,   126,   127,
     128,   129,   130,   131,   329,   330,   331,   135,   332,   333,
     138,   139,   140,   141,   142,   143,   334,   145,     0,     0,
       0,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,   161,   162,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   308,   309,   310,   311,   312,   313,   314,    15,
      16,     0,   315,   316,    19,   317,   318,    22,     0,    24,
      25,    26,     0,   319,    28,     0,   320,    31,     0,    33,
     321,   322,    36,    37,    38,    39,     0,     0,    42,     0,
      43,    44,    45,   323,     0,     0,    49,    50,    51,     0,
       0,     0,    53,     0,     0,     0,     0,    55,    56,     0,
       0,    59,    60,     0,     0,     0,     0,     0,     0,    65,
      66,    67,    68,     0,    69,     0,     0,     0,   324,    71,
      72,     0,     0,     0,     0,     0,     0,     0,    75,    76,
      77,     0,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,    86,    87,     0,     0,     0,     0,    88,    89,
      90,   327,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,     0,   101,   488,
     102,     0,     0,     0,     0,     0,   489,     0,   108,     0,
     109,   110,   111,   112,   328,     0,   114,   115,   116,   117,
     118,   119,     0,     0,   120,   121,     0,     0,     0,   124,
       0,   125,   126,   127,   128,   129,   130,   131,   329,   330,
     331,   135,   332,   333,   138,   139,   140,   141,   142,   143,
     334,   145,     0,     0,     0,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,   161,
     162,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   308,   309,   310,   311,
     312,   313,   314,    15,    16,     0,   315,   316,    19,   317,
     318,    22,     0,    24,    25,    26,     0,   319,    28,     0,
     320,    31,     0,    33,   321,   322,    36,    37,    38,    39,
       0,     0,    42,     0,    43,    44,    45,   323,     0,     0,
      49,    50,    51,     0,     0,     0,    53,     0,     0,     0,
       0,    55,    56,     0,     0,    59,    60,     0,     0,     0,
       0,     0,     0,    65,    66,    67,    68,     0,    69,     0,
       0,     0,   324,    71,    72,     0,     0,     0,     0,     0,
       0,     0,    75,    76,    77,     0,    79,    80,    81,     0,
       0,     0,     0,     0,     0,     0,    86,    87,     0,     0,
       0,     0,    88,    89,    90,   327,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
       0,     0,   101,   565,   102,     0,     0,     0,     0,     0,
     566,     0,   108,     0,   109,   110,   111,   112,   328,     0,
     114,   115,   116,   117,   118,   119,     0,     0,   120,   121,
       0,     0,     0,   124,     0,   125,   126,   127,   128,   129,
     130,   131,   329,   330,   331,   135,   332,   333,   138,   139,
     140,   141,   142,   143,   334,   145,     0,     0,     0,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,     0,   161,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     308,   309,   373,   311,   374,   375,   314,    15,    16,     0,
     315,   376,    19,   317,   318,    22,     0,    24,    25,    26,
       0,   319,    28,     0,   320,    31,     0,    33,    34,    35,
      36,    37,    38,    39,     0,     0,    42,     0,    43,    44,
      45,   377,     0,     0,    49,    50,    51,     0,     0,     0,
      53,     0,     0,     0,     0,    55,    56,     0,     0,    59,
      60,  1007,     0,     0,     0,     0,     0,    65,    66,    67,
      68,     0,    69,     0,     0,     0,   324,    71,    72,     0,
       0,     0,     0,     0,     0,     0,    75,    76,    77,     0,
      79,    80,   822,     0,     0,     0,     0,     0,     0,     0,
      86,    87,     0,     0,     0,     0,    88,    89,    90,   327,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,     0,     0,   101,     0,   102,   103,
       0,     0,     0,     0,     0,     0,   108,     0,   109,   110,
     111,   112,   328,     0,   114,   115,   116,   117,   118,   119,
       0,     0,   823,   121,     0,     0,     0,   124,     0,   125,
     126,   127,   128,   129,   130,   131,   329,   133,   331,   135,
     332,   333,   138,   139,   140,   141,   142,   143,   334,   145,
       0,     0,     0,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,   161,   162,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   308,   309,   373,   311,   374,   375,
     314,    15,    16,     0,   315,   376,    19,   317,   318,    22,
       0,    24,    25,    26,     0,   319,    28,     0,   320,    31,
       0,    33,    34,    35,    36,    37,    38,    39,     0,     0,
      42,     0,    43,    44,    45,   377,     0,     0,    49,    50,
      51,     0,     0,     0,    53,     0,     0,     0,     0,    55,
      56,     0,     0,    59,    60,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,     0,    69,     0,     0,     0,
     324,    71,    72,     0,     0,     0,     0,     0,     0,     0,
      75,    76,    77,     0,    79,    80,   822,     0,     0,     0,
       0,     0,     0,     0,    86,    87,     0,     0,     0,     0,
      88,    89,    90,   327,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
     101,     0,   102,   103,     0,     0,     0,     0,     0,     0,
     108,     0,   109,   110,   111,   112,   328,     0,   114,   115,
     116,   117,   118,   119,     0,     0,   823,   121,     0,     0,
       0,   124,     0,   125,   126,   127,   128,   129,   130,   131,
     329,   133,   331,   135,   332,   333,   138,   139,   140,   141,
     142,   143,   334,   145,     0,     0,     0,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,   161,   162,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   308,   309,
     310,   311,   312,   313,   314,    15,    16,     0,   315,   316,
      19,   317,   318,    22,     0,    24,    25,    26,     0,   319,
      28,     0,   320,    31,     0,    33,   321,   322,    36,    37,
      38,    39,     0,     0,    42,     0,    43,    44,    45,   323,
       0,     0,    49,    50,    51,     0,     0,     0,    53,     0,
       0,     0,     0,    55,    56,     0,     0,    59,    60,     0,
       0,     0,     0,     0,     0,    65,    66,    67,    68,     0,
      69,     0,     0,     0,   324,    71,    72,     0,     0,     0,
       0,     0,     0,     0,    75,    76,    77,     0,    79,    80,
      81,     0,     0,     0,     0,     0,     0,     0,    86,    87,
       0,     0,     0,     0,    88,    89,    90,   327,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,     0,     0,     0,   101,     0,   102,     0,     0,     0,
       0,     0,     0,     0,   108,     0,   109,   110,   111,   112,
     328,     0,   114,   115,   116,   117,   118,   119,     0,     0,
     120,   121,     0,     0,     0,   124,     0,   125,   126,   127,
     128,   129,   130,   131,   329,   330,   331,   135,   332,   333,
     138,   139,   140,   141,   142,   143,   334,   145,     0,     0,
       0,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,   161,   162,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        10,   347,   449,   719,   816,    82,    83,   698,   300,   417,
     302,   858,   650,   651,   360,   361,   575,   553,   651,   105,
     106,   557,   453,   454,   455,   456,    48,   557,   663,   754,
     782,   782,   804,   352,    70,   632,    46,    19,    48,   358,
     432,    20,   434,   435,   363,   437,    19,   439,   427,   428,
      68,    61,    70,   929,    51,   447,   448,    37,    38,    39,
      81,    70,     6,   113,    81,    19,    51,    47,    37,    38,
      39,    32,   117,   365,    84,    68,     7,     8,    47,    81,
      81,   117,    81,    52,   722,    81,    55,    97,    57,   722,
     117,    60,   209,   103,    63,    70,    81,    58,    17,   117,
      19,   101,    84,   961,   962,    85,   398,   399,    74,   401,
     402,   403,   404,    95,    91,   407,    85,    86,    42,   107,
     113,    70,   213,   214,   115,    68,   418,   108,    19,   123,
      80,   139,   424,   425,    86,    74,    70,   119,   197,   123,
     161,   123,   123,   202,   235,   127,    77,    86,    98,    67,
     686,    68,    86,   147,   155,   146,   158,    45,   157,    68,
      45,   157,   131,    94,   172,    96,    45,   167,   514,     7,
       8,   887,    51,   164,   117,    54,   100,   131,   127,   156,
      45,   628,   629,   171,   157,   876,   183,   479,   238,  1065,
     207,   750,   123,   238,   919,    86,   157,   128,   183,   545,
     730,   145,   238,   841,   929,   735,   185,   737,   841,   806,
       3,   238,    81,   144,     7,   224,   225,   969,   969,   991,
     238,  1033,   541,   192,   859,   544,   303,   236,  1086,   251,
     307,   623,   254,   612,   165,   153,   216,    17,   157,    77,
     131,   251,    81,   209,   254,   238,   228,   216,   325,   224,
     225,   217,   140,   184,   142,   140,    94,    81,    96,   336,
     337,   140,   339,   142,   230,   217,   232,   127,   156,   102,
     129,   156,    81,   190,   191,   140,   242,   156,   355,   245,
     357,   190,   191,     7,     8,   123,    81,   146,   205,    81,
     128,   156,   161,   370,   246,   247,   205,   249,   250,    81,
      81,    94,    32,    96,   183,   382,   144,    37,   137,    81,
     387,   104,    27,    81,     7,   607,   326,   394,   157,   611,
      81,    81,   614,   152,   616,    18,    81,   165,   161,    81,
     123,   341,     3,   157,   344,    81,     7,    81,   127,    81,
    1065,   687,   688,   123,  1191,   691,   184,   127,   157,     7,
      80,    91,   362,    77,   364,   802,   366,   127,   368,    81,
      18,   371,   157,  1175,    81,    91,   158,   814,   776,    81,
      94,   381,    96,   131,   805,   157,   157,   171,   908,   725,
      81,  1019,   154,  1230,   470,   471,  1019,   181,  1235,   157,
      19,   468,  1239,   154,    81,   472,   406,   157,   408,   123,
      53,    94,   157,    96,   128,   157,   483,   484,   485,   108,
     140,   157,   105,   157,   491,   157,   473,   157,    90,   476,
     144,   478,  1138,    94,   123,    96,     7,     8,    81,   721,
     123,   723,   154,   104,    81,   727,    94,   154,    96,    81,
     234,   165,   734,    81,   116,   157,   240,   105,    81,    81,
      81,   101,   123,   154,   248,    84,   748,    81,   130,   672,
     184,    81,    81,   540,    81,   123,    95,   154,   760,   761,
     762,    81,   764,   765,   766,   767,   768,   769,    81,   771,
     772,  1119,  1018,    81,    81,   777,  1119,    81,   498,   499,
     119,   568,   164,   785,   123,   787,    77,   789,   127,    81,
     189,   511,    70,    36,  1063,  1196,   152,   154,   123,  1068,
      43,   123,   154,    94,   234,    96,   154,   167,    86,   239,
     166,   154,   154,   154,    70,    68,   152,  1165,    74,   742,
     154,   744,  1165,   222,   154,   154,   882,   154,    99,   100,
     166,   108,   123,   835,   154,   976,   113,   128,   995,   129,
     627,   154,   983,   984,    70,   234,   154,   154,    74,   127,
     154,   240,   107,   144,   574,   108,   146,   118,   118,   248,
     113,    69,   154,   865,    91,   120,  1124,   253,   193,   194,
     195,  1129,    80,   259,   165,   136,   136,   879,  1147,   169,
      91,    89,  1151,   139,  1183,  1184,   169,    27,   171,   171,
      98,   893,    46,   184,   217,    49,   898,   899,   181,   181,
      91,   957,   904,  1202,   906,   907,   123,   123,   127,  1208,
     127,   127,   215,   139,   215,   218,   123,   218,  1187,   193,
     194,   195,   127,   246,   247,    13,   249,   250,   162,   163,
     650,   651,   652,   653,   197,   197,   199,   199,   204,   204,
     206,   206,    99,   100,   123,   681,   682,   457,   458,   187,
     670,   953,   672,   209,   450,   451,  1097,  1098,   459,   460,
     127,   217,   964,   219,   220,   221,   652,   653,   197,   971,
    1122,  1123,    91,   229,   230,   123,   232,    91,     0,   161,
     161,   237,    81,   209,  1040,   138,   242,   243,   244,   245,
      66,   217,   227,   219,   220,   221,    61,   170,    75,   124,
     127,    76,   722,   123,   230,   123,   232,   123,   123,    37,
     157,   237,   157,    37,    19,    17,   242,   243,   244,   245,
      91,   123,   742,  1164,   744,   123,  1028,   127,    24,    14,
     127,   127,   127,   127,  1090,   157,   185,    19,   203,    36,
     157,   203,    68,   156,   127,    68,   157,  1049,   140,    68,
     141,  1053,   141,    19,  1056,    98,  1058,   844,   131,   131,
      81,   781,   103,    81,    19,    32,    70,   157,   103,   856,
    1072,  1073,  1074,  1075,  1076,   157,  1078,    70,   103,   157,
      81,    81,    68,   157,   154,   209,   111,   112,   157,   114,
     197,   154,   141,   880,   161,   156,   121,   113,   156,    91,
     125,   245,   228,   128,   233,   226,   123,   248,   133,    74,
    1112,   123,  1114,   247,   168,   248,   123,   131,    70,   103,
     103,   841,    91,   910,   149,   113,   117,    91,    91,    91,
      91,   851,    24,   123,  1136,    19,   117,    91,   925,    81,
      91,  1143,   157,   211,   123,   156,   117,   248,    48,   174,
     175,   176,   177,   178,   179,   127,   115,   223,   157,   223,
      68,   248,   157,   157,    19,   115,    81,   127,   157,   889,
     113,   117,   117,   103,   161,   895,     5,   897,   205,   157,
     157,   901,   902,   156,    80,   161,   127,    80,   241,   209,
      68,    68,  1194,    91,    19,   205,   205,   205,    19,   157,
     157,    70,    97,   156,   117,   154,   926,    68,    19,   156,
      70,   167,    91,   123,  1216,    67,   156,   153,   231,   167,
      91,    91,   157,   167,   416,   231,   416,   947,   167,  1020,
     737,   901,   895,   954,   954,   777,   966,   889,   427,   219,
     964,   244,   381,   842,   961,   430,   452,   185,   185,  1079,
     919,   431,  1208,  1202,   188,   653,   189,   575,   672,   369,
     369,   628,   802,   947,   814,   240,   995,   629,   806,   951,
    1134,  1032,   803,    -1,   990,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1007,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1019,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1064,    -1,    -1,    -1,    -1,  1069,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1079,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1113,    -1,    -1,    -1,    -1,    -1,  1119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1165,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1214,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    -1,    19,    -1,    -1,
      -1,  1231,    -1,    25,    26,    -1,  1236,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    79,    80,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,    -1,
     102,    -1,    -1,    -1,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,   137,   138,   139,   140,   141,
      -1,   143,   144,    -1,   146,   147,    -1,    -1,   150,   151,
     152,    -1,    -1,    -1,   156,    -1,   158,   159,   160,    -1,
     162,   163,   164,    -1,   166,    -1,   168,   169,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,    -1,    -1,
     182,   183,   184,    -1,   186,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,    -1,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    79,
      80,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    -1,    97,    98,    99,
     100,    -1,   102,    -1,    -1,    -1,   106,   107,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,    -1,    -1,    -1,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,   137,   138,   139,
     140,   141,    -1,   143,   144,    -1,   146,   147,    -1,    -1,
     150,   151,   152,    -1,    -1,    -1,   156,   157,   158,   159,
     160,    -1,   162,   163,   164,    -1,   166,    -1,   168,   169,
     170,   171,   172,    -1,   174,   175,   176,   177,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,   227,   228,    -1,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    79,    80,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    -1,    97,
      98,    99,   100,    -1,   102,    -1,    -1,    -1,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,   137,
     138,   139,   140,   141,    -1,   143,   144,    -1,   146,   147,
      -1,    -1,   150,   151,   152,    -1,    -1,    -1,   156,    -1,
     158,   159,   160,    -1,   162,   163,   164,    -1,   166,    -1,
     168,   169,   170,   171,   172,    -1,   174,   175,   176,   177,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,   227,
     228,    -1,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    79,    80,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      -1,    97,    98,    99,   100,    -1,   102,    -1,    -1,    -1,
     106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,   122,   123,    -1,    -1,
      -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,   137,   138,   139,   140,   141,    -1,   143,   144,    -1,
     146,   147,    -1,    -1,   150,   151,   152,    -1,   154,    -1,
     156,    -1,   158,   159,   160,    -1,   162,   163,   164,    -1,
     166,    -1,   168,   169,   170,   171,   172,    -1,   174,   175,
     176,   177,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,   227,   228,    -1,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    -1,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    79,    80,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    -1,    97,    98,    99,   100,    -1,   102,    -1,
      -1,    -1,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,   137,   138,   139,   140,   141,    -1,   143,
     144,    -1,   146,   147,    -1,    -1,   150,   151,   152,    -1,
     154,    -1,   156,    -1,   158,   159,   160,    -1,   162,   163,
     164,    -1,   166,    -1,   168,   169,   170,   171,   172,    -1,
     174,   175,   176,   177,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,   227,   228,    -1,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    79,    80,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,    -1,
     102,    -1,    -1,    -1,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,   137,   138,   139,   140,   141,
      -1,   143,   144,    -1,   146,   147,    -1,    -1,   150,   151,
     152,    -1,    -1,    -1,   156,   157,   158,   159,   160,    -1,
     162,   163,   164,    -1,   166,    -1,   168,   169,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,    -1,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    79,
      80,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    -1,    97,    98,    99,
     100,    -1,   102,    -1,    -1,    -1,   106,   107,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,    -1,    -1,    -1,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,   137,   138,   139,
     140,   141,    -1,   143,   144,    -1,   146,   147,    -1,    -1,
     150,   151,   152,    -1,   154,    -1,   156,    -1,   158,   159,
     160,    -1,   162,   163,   164,    -1,   166,    -1,   168,   169,
     170,   171,   172,    -1,   174,   175,   176,   177,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,   227,   228,    -1,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    79,    80,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    -1,    97,
      98,    99,   100,    -1,   102,    -1,    -1,    -1,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,   137,
     138,   139,   140,   141,    -1,   143,   144,    -1,   146,   147,
      -1,    -1,   150,   151,   152,    -1,   154,    -1,   156,    -1,
     158,   159,   160,    -1,   162,   163,   164,    -1,   166,    -1,
     168,   169,   170,   171,   172,    -1,   174,   175,   176,   177,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,   227,
     228,    -1,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    79,    80,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      -1,    97,    98,    99,   100,    -1,   102,    -1,    -1,    -1,
     106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,   122,   123,    -1,    -1,
      -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,   137,   138,   139,   140,   141,    -1,   143,   144,    -1,
     146,   147,    -1,    -1,   150,   151,   152,    -1,   154,    -1,
     156,    -1,   158,   159,   160,    -1,   162,   163,   164,    -1,
     166,    -1,   168,   169,   170,   171,   172,    -1,   174,   175,
     176,   177,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,   227,   228,    -1,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    -1,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    79,    80,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    -1,    97,    98,    99,   100,    -1,   102,    -1,
      -1,    -1,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,   137,   138,   139,   140,   141,    -1,   143,
     144,    -1,   146,   147,    -1,    -1,   150,   151,   152,    -1,
     154,    -1,   156,    -1,   158,   159,   160,    -1,   162,   163,
     164,    -1,   166,    -1,   168,   169,   170,   171,   172,    -1,
     174,   175,   176,   177,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,   227,   228,    -1,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    79,    80,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,    -1,
     102,    -1,    -1,    -1,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,   137,   138,   139,   140,   141,
      -1,   143,   144,    -1,   146,   147,    -1,    -1,   150,   151,
     152,    -1,   154,    -1,   156,    -1,   158,   159,   160,    -1,
     162,   163,   164,    -1,   166,    -1,   168,   169,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,    -1,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    79,
      80,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    -1,    97,    98,    99,
     100,    -1,   102,    -1,    -1,    -1,   106,   107,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,    -1,    -1,    -1,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,   137,   138,   139,
     140,   141,    -1,   143,   144,    -1,   146,   147,    -1,    -1,
     150,   151,   152,    -1,   154,    -1,   156,    -1,   158,   159,
     160,    -1,   162,   163,   164,    -1,   166,    -1,   168,   169,
     170,   171,   172,    -1,   174,   175,   176,   177,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,   227,   228,    -1,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    79,    80,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    -1,    97,
      98,    99,   100,    -1,   102,    -1,    -1,    -1,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,   137,
     138,   139,   140,   141,    -1,   143,   144,    -1,   146,   147,
      -1,    -1,   150,   151,   152,    -1,    -1,    -1,   156,    -1,
     158,   159,   160,    -1,   162,   163,   164,    -1,   166,    -1,
     168,   169,   170,   171,   172,    -1,   174,   175,   176,   177,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,   227,
     228,    -1,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    -1,    51,    52,    -1,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    79,    80,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      -1,    97,    98,    99,   100,    -1,   102,    -1,    -1,    -1,
     106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,   137,   138,   139,   140,   141,    -1,   143,   144,    -1,
     146,   147,    -1,    -1,   150,   151,   152,    -1,    -1,    -1,
     156,    -1,   158,   159,   160,    -1,   162,   163,   164,    -1,
     166,    -1,   168,   169,   170,   171,   172,    -1,   174,   175,
     176,   177,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,   227,   228,    -1,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    -1,    47,    48,    49,    -1,    51,    52,    -1,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    79,    80,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    -1,    97,    98,    99,   100,    -1,   102,    -1,
      -1,    -1,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,   137,   138,   139,   140,   141,    -1,   143,
     144,    -1,   146,   147,    -1,    -1,   150,   151,   152,    -1,
      -1,    -1,   156,    -1,   158,   159,   160,    -1,   162,   163,
     164,    -1,   166,    -1,   168,   169,   170,   171,   172,    -1,
     174,   175,   176,   177,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,   227,   228,    -1,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    -1,    51,
      52,    -1,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    79,    80,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,    -1,
     102,    -1,    -1,    -1,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,   128,    -1,   130,   131,
      -1,    -1,    -1,    -1,   136,   137,   138,   139,   140,   141,
      -1,   143,   144,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,    -1,    -1,    -1,   156,    -1,   158,   159,   160,    -1,
      -1,    -1,   164,    -1,   166,    -1,   168,   169,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,    -1,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      -1,    51,    52,    -1,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    79,
      80,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      -1,    91,    92,    93,    -1,    95,    -1,    97,    98,    99,
     100,    -1,   102,    -1,    -1,    -1,   106,    -1,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
      -1,   121,   122,    -1,    -1,    -1,    -1,   127,   128,    -1,
      -1,   131,    -1,    -1,    -1,    -1,   136,   137,   138,   139,
     140,   141,    -1,   143,   144,    -1,    -1,    -1,    -1,    -1,
     150,   151,   152,    -1,    -1,    -1,   156,    -1,   158,   159,
     160,    -1,    -1,    -1,    -1,    -1,   166,    -1,   168,    -1,
     170,    -1,   172,    -1,   174,   175,   176,   177,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,   228,    -1,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    49,    -1,    51,    52,    -1,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    66,    -1,
      68,    69,    70,    71,    -1,    -1,    74,    75,    76,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,    -1,   102,    -1,    -1,    -1,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,
     118,    -1,   120,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,    -1,    -1,    -1,    -1,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,   156,    -1,
     158,   159,    -1,    -1,    -1,    -1,   164,    -1,   166,    -1,
     168,   169,   170,   171,   172,    -1,   174,   175,   176,   177,
     178,   179,    -1,    -1,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,   227,
     228,    -1,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    -1,    51,    52,    -1,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      66,    -1,    68,    69,    70,    71,    -1,    -1,    74,    75,
      76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    85,
      86,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,    -1,   102,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,    -1,   120,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    -1,    -1,    -1,    -1,
     136,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
     156,    -1,   158,    -1,    -1,    -1,    -1,    -1,   164,    -1,
     166,    -1,   168,   169,   170,   171,   172,    -1,   174,   175,
     176,   177,   178,   179,    -1,    -1,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,   227,   228,    -1,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    15,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      -1,    51,    52,    -1,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    66,    -1,    68,    69,
      70,    71,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,    -1,   102,    -1,    -1,    -1,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,    -1,
     120,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,    -1,    -1,    -1,    -1,   136,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,   156,    -1,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,   168,   169,
     170,   171,   172,    -1,   174,   175,   176,   177,   178,   179,
      -1,    -1,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,   227,   228,    -1,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    -1,    51,    52,    -1,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      66,    -1,    68,    69,    70,    71,    -1,    -1,    74,    75,
      76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    85,
      86,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,    -1,   102,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,    -1,   120,   121,   122,   123,    -1,    -1,
      -1,   127,    -1,    -1,   130,   131,    -1,    -1,    -1,    -1,
     136,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
     156,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,    -1,   168,   169,   170,   171,   172,    -1,   174,   175,
     176,   177,   178,   179,    -1,    -1,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,   227,   228,    -1,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    -1,    51,
      52,    -1,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    66,    -1,    68,    69,    70,    71,
      -1,    -1,    74,    75,    76,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    -1,    85,    86,    -1,    -1,    89,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,    -1,
     102,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,   117,   118,    -1,   120,   121,
     122,   123,    -1,    -1,    -1,   127,    -1,    -1,   130,   131,
      -1,    -1,    -1,    -1,   136,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,   156,    -1,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,    -1,   168,   169,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,    -1,    -1,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,    -1,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    49,    -1,    51,    52,    -1,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    66,    -1,
      68,    69,    70,    71,    -1,    -1,    74,    75,    76,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,    -1,   102,    -1,    -1,    -1,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,
     118,    -1,   120,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,    -1,    -1,    -1,    -1,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,   156,   157,
     158,    -1,    -1,    -1,    -1,    -1,   164,    -1,   166,    -1,
     168,   169,   170,   171,   172,    -1,   174,   175,   176,   177,
     178,   179,    -1,    -1,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,   227,
     228,    -1,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    -1,    47,    48,    49,    -1,    51,    52,    -1,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    66,    -1,    68,    69,    70,    71,    -1,    -1,
      74,    75,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      -1,    85,    86,    -1,    -1,    89,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,    -1,   102,    -1,
      -1,    -1,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,    -1,   120,   121,   122,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,    -1,
      -1,    -1,   136,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,
     164,    -1,   166,    -1,   168,   169,   170,   171,   172,    -1,
     174,   175,   176,   177,   178,   179,    -1,    -1,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,   227,   228,    -1,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      -1,    51,    52,    -1,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    66,    -1,    68,    69,
      70,    71,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    89,
      90,    91,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,    -1,   102,    -1,    -1,    -1,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,    -1,
     120,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,    -1,    -1,    -1,    -1,   136,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,   156,    -1,   158,   159,
      -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,   168,   169,
     170,   171,   172,    -1,   174,   175,   176,   177,   178,   179,
      -1,    -1,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,   227,   228,    -1,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    -1,    51,    52,    -1,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      66,    -1,    68,    69,    70,    71,    -1,    -1,    74,    75,
      76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    85,
      86,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,    -1,   102,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,    -1,   120,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    -1,    -1,    -1,    -1,
     136,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
     156,    -1,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,
     166,    -1,   168,   169,   170,   171,   172,    -1,   174,   175,
     176,   177,   178,   179,    -1,    -1,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,   227,   228,    -1,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    -1,    51,
      52,    -1,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    66,    -1,    68,    69,    70,    71,
      -1,    -1,    74,    75,    76,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    -1,    85,    86,    -1,    -1,    89,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,    -1,
     102,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,   117,   118,    -1,   120,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
      -1,    -1,    -1,    -1,   136,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,   156,    -1,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,    -1,   168,   169,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,    -1,    -1,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,    -1,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250
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
      64,    65,    66,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    79,    80,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    95,    97,    98,    99,   100,   102,
     106,   107,   108,   109,   110,   116,   117,   118,   119,   120,
     121,   122,   123,   127,   128,   129,   130,   131,   136,   137,
     138,   139,   140,   141,   143,   144,   146,   147,   150,   151,
     152,   156,   158,   159,   160,   162,   163,   164,   166,   168,
     169,   170,   171,   172,   174,   175,   176,   177,   178,   179,
     182,   183,   184,   186,   187,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   227,   228,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   291,   292,   293,
     295,   297,   298,   299,   300,   305,   306,   307,   308,   309,
     310,   311,   316,   334,   337,   340,   341,   342,   343,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   389,   390,
     391,   405,   406,   408,   409,   410,   411,   412,   413,   414,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     433,   434,   435,   436,   437,   438,   439,   442,   447,   448,
     209,    27,   127,   123,   193,   194,   195,   127,    30,    31,
      32,    33,    34,    35,    36,    40,    41,    43,    44,    51,
      54,    58,    59,    71,   106,   123,   127,   139,   172,   196,
     197,   198,   200,   201,   208,   447,   123,   123,   127,   123,
     127,    37,    38,    39,    47,    52,    55,    57,    60,    63,
      85,    86,   131,   192,   216,   127,    17,   123,   127,   446,
      46,    49,    91,   131,    91,   123,    91,    27,   127,   127,
     123,   127,   447,    32,    34,    35,    41,    71,   373,   447,
     447,    91,   296,   306,   157,   306,   447,   123,    13,    15,
     447,   447,   365,   365,   123,    20,   185,   187,   197,   199,
     127,   197,   199,   197,   197,   202,    91,   123,    91,     0,
     268,   269,    36,    43,   271,   305,   161,   161,    81,    45,
      51,    54,   140,   142,   156,   183,   310,   321,   322,   327,
     138,    66,   103,   111,   112,   114,   121,   125,   128,   133,
     149,   174,   175,   176,   177,   178,   179,   358,   359,   227,
     129,   146,   169,    90,   116,   130,   164,   171,   181,   107,
     120,    61,   170,    75,    76,   129,   146,   357,   123,   363,
     162,   163,   124,   377,   378,   373,   377,   373,   377,   127,
     307,   307,   306,   123,   123,   123,   306,   306,   157,   164,
     447,   123,   306,   306,   157,   306,   157,   447,    37,    37,
     447,   152,   166,   139,   172,    19,   445,   137,   152,   152,
     166,    91,    32,    37,    80,   140,   446,   193,   194,   195,
      74,   209,   217,   230,   232,   242,   245,   460,   461,   462,
     463,   464,   467,   472,   473,   306,   306,    19,   157,   446,
     123,   131,   445,    86,   131,   290,   445,   335,   336,   447,
     446,   317,   319,   447,   307,   312,   313,   447,   447,    32,
      58,   157,   429,   430,   306,   157,   164,   447,   123,   335,
     154,   306,   161,   157,    24,   393,   394,   395,   306,     6,
     145,    14,   157,   306,   185,    19,   307,   307,   157,   307,
     307,   307,   307,   203,   440,   441,   447,   307,   318,   320,
     447,   273,   274,    36,   275,   307,   140,   141,   141,   307,
     307,   156,   322,   327,   156,   327,   156,   342,   343,   345,
     345,   345,   345,   344,   345,   345,   345,   123,   127,   228,
     380,   449,   451,   452,   453,   454,   455,   456,   457,   348,
     348,   347,   349,   349,   349,   349,   350,   350,   351,   351,
     203,    68,    68,    68,   154,   306,   365,   365,   306,   378,
     157,   307,   388,   157,   154,   306,   306,   306,   157,   154,
      81,   157,    81,   157,   154,   306,   154,   154,   154,   127,
     294,   447,   447,    19,    81,    81,   447,   131,   131,   445,
      98,   103,   215,   218,    86,   217,   246,   247,   249,   250,
     215,   218,    19,   217,   246,   247,   249,   250,   157,   154,
     157,   157,   154,   306,   446,    70,    32,   446,   445,    70,
      81,   158,    68,   117,   416,   103,    81,   113,   238,   315,
     416,   154,    81,    70,   117,   314,   315,   416,   157,   157,
     157,   154,    81,   157,    81,   157,   154,   306,   158,   161,
     447,   394,   395,   101,   167,   154,   154,   102,   161,    68,
     190,   191,   205,    68,   190,   191,   205,    68,   209,   197,
      81,   207,   113,   154,    53,    81,   161,   141,   307,   328,
     329,    91,   323,   324,   307,   156,   327,   156,   307,   156,
     307,   345,   306,   449,   455,   245,   483,    70,   139,   219,
     220,   221,   229,   237,   243,   244,   450,   458,   459,   460,
     474,   477,   478,   480,   226,   228,   233,   479,   213,   214,
     235,   475,   122,   182,   417,   419,   420,   421,   447,   417,
     415,   420,   415,   154,   155,    81,   157,   295,   154,   154,
     154,    74,   338,   339,   123,   431,   432,   447,   431,   432,
     154,    91,   157,   301,   302,   108,   123,   304,   294,   294,
     118,   136,   118,   136,   108,   113,   416,   445,   445,    99,
     100,   445,   247,   248,    70,    86,   127,   466,   248,   168,
     123,   154,   103,   289,   445,   131,   103,    70,   289,    91,
     307,   417,   307,   117,   445,    91,   307,    91,   113,   113,
     315,    91,    91,   307,   117,   315,   117,   117,   314,   315,
     123,   431,   447,   431,   154,   307,    24,   395,   101,   167,
       7,     8,    77,    94,    96,   123,   165,   303,   390,   392,
     403,   404,   407,    19,   204,   206,   307,   307,   307,   204,
     206,   307,   307,   307,   307,   307,   307,    91,   307,   307,
     211,   443,   444,   123,    91,   328,    69,    80,    89,    98,
     330,   331,   332,   333,    81,   447,    81,   316,   321,   326,
     307,   156,   307,   307,   154,   157,   223,   189,   222,   234,
     239,   482,    70,   224,   225,   476,   223,   452,   482,   346,
     349,   243,   458,   460,   453,   117,   476,   248,    48,   127,
     127,   115,   146,   164,   418,   115,   307,    91,   417,    86,
     339,   154,   306,   157,   157,   115,   157,   157,   447,    68,
      81,   157,   306,   108,   304,   295,   307,   108,   113,   248,
      70,   127,   469,    19,    86,   466,   307,   154,   306,   445,
      81,   289,   336,   307,   161,   319,   447,   307,   307,   113,
     313,   447,   307,   117,   307,   307,   117,   315,   117,   154,
     306,   157,   157,   103,   165,   392,     5,   306,   447,   165,
     403,   161,   205,   205,   205,   205,   209,   441,   156,   127,
     444,   307,   320,   445,    99,   100,   332,   333,   333,   329,
      80,   325,   324,   316,   321,   307,   349,    42,   100,   349,
     349,   234,   240,   248,   481,   481,   346,   454,   241,   157,
     157,   447,   156,    91,   156,   154,   416,   417,   302,    68,
     154,   307,   107,   171,   468,   471,    19,    19,   470,   468,
     236,   476,    81,   157,    81,   157,    97,   154,    70,   445,
     307,   307,   307,   117,   307,   154,   395,   447,   165,   154,
     395,   447,   307,   307,   307,   307,   307,   307,   374,   154,
     333,   445,   349,   349,   169,    68,   307,   447,   307,   417,
     469,   469,   471,    19,   157,    19,   231,   465,   466,   465,
     307,   289,   307,    67,   153,   396,   395,   447,   167,   395,
      81,   157,   349,   417,   156,   476,    81,   157,   157,     3,
     104,   399,   400,   402,   404,    18,   105,   397,   398,   401,
     404,   167,   395,   167,    91,   304,   156,   307,   231,   466,
      67,   104,   402,   153,   105,   401,   167,   447,   307,    81,
     157,    91,   304,   447,    81,   157,    91,   304,   447,   157,
     304
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
     515,   516,   517,   518,   519
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   265,   266,   266,   266,   266,   267,   267,   268,   268,
     269,   270,   271,   271,   271,   272,   272,   273,   273,   274,
     274,   274,   274,   275,   275,   275,   275,   276,   276,   276,
     276,   276,   276,   276,   276,   277,   277,   278,   279,   279,
     280,   280,   281,   282,   283,   283,   284,   284,   285,   285,
     285,   285,   286,   287,   288,   288,   288,   288,   289,   289,
     290,   290,   291,   291,   291,   291,   292,   292,   292,   292,
     293,   293,   294,   294,   294,   294,   295,   296,   296,   297,
     298,   299,   299,   300,   300,   300,   300,   300,   301,   301,
     302,   302,   303,   304,   305,   306,   306,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   308,   308,   308,   308,   308,   308,   308,
     308,   309,   309,   310,   310,   311,   312,   312,   313,   313,
     313,   313,   313,   313,   313,   313,   314,   315,   316,   317,
     317,   318,   318,   319,   319,   319,   319,   320,   321,   322,
     322,   322,   322,   323,   323,   324,   324,   325,   326,   326,
     327,   327,   328,   328,   329,   329,   330,   330,   330,   330,
     330,   330,   330,   331,   331,   332,   332,   333,   334,   334,
     335,   335,   336,   336,   337,   337,   338,   338,   339,   339,
     340,   341,   341,   342,   342,   343,   343,   343,   343,   343,
     344,   343,   343,   343,   343,   345,   345,   345,   346,   346,
     347,   347,   347,   348,   348,   348,   348,   348,   349,   349,
     349,   350,   350,   350,   351,   351,   352,   352,   353,   353,
     354,   354,   355,   355,   356,   356,   356,   356,   357,   357,
     357,   358,   358,   358,   358,   358,   358,   359,   359,   359,
     360,   360,   360,   360,   361,   361,   362,   362,   363,   363,
     364,   364,   364,   364,   365,   365,   365,   366,   366,   367,
     367,   367,   367,   368,   368,   369,   369,   369,   369,   369,
     369,   369,   370,   370,   371,   371,   372,   372,   372,   372,
     372,   373,   373,   374,   374,   375,   375,   375,   376,   376,
     377,   377,   378,   379,   379,   379,   379,   379,   379,   379,
     379,   380,   380,   381,   381,   381,   382,   383,   383,   384,
     385,   386,   387,   387,   388,   388,   389,   389,   390,   390,
     390,   391,   391,   391,   391,   391,   391,   392,   392,   393,
     393,   394,   395,   395,   396,   396,   397,   397,   398,   398,
     398,   398,   399,   399,   400,   400,   400,   400,   401,   401,
     402,   402,   403,   403,   403,   403,   404,   404,   404,   404,
     405,   405,   406,   406,   407,   408,   408,   408,   408,   408,
     408,   409,   410,   410,   410,   410,   411,   411,   411,   411,
     412,   413,   414,   414,   414,   414,   415,   415,   416,   417,
     417,   417,   418,   418,   418,   419,   419,   419,   420,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   422,   423,
     423,   423,   424,   425,   426,   426,   426,   427,   427,   427,
     427,   427,   428,   429,   429,   429,   429,   429,   429,   429,
     430,   431,   432,   433,   434,   434,   434,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   435,   436,   436,   437,
     437,   438,   439,   440,   440,   441,   442,   443,   443,   444,
     444,   444,   444,   445,   446,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   448,   448,   449,   449,   449,
     449,   450,   450,   450,   450,   451,   451,   452,   452,   453,
     453,   454,   454,   455,   455,   455,   456,   456,   457,   457,
     458,   458,   458,   458,   458,   459,   460,   460,   460,   460,
     460,   460,   460,   461,   461,   461,   461,   462,   462,   462,
     462,   463,   463,   464,   464,   464,   464,   464,   464,   464,
     465,   465,   466,   466,   466,   466,   467,   467,   467,   467,
     467,   468,   468,   469,   469,   470,   470,   471,   471,   472,
     473,   473,   474,   474,   474,   475,   475,   475,   475,   475,
     476,   476,   476,   476,   477,   478,   479,   480,   480,   481,
     481,   481,   482,   482,   483
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
       1,     1,     1,     3,     4,     4,     5,     4,     5,     5,
       6,     1,     2,     1,     1,     3,     1,     4,     3,     4,
       4,     5,     4,     5,     5,     6,     3,     3,     3,     1,
       4,     1,     4,     3,     4,     4,     5,     1,     2,     3,
       4,     4,     5,     1,     3,     2,     3,     2,     1,     2,
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
       1,     2,     2,     1,     1,     3,     3,     1,     1,     1,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     1,
       4,     4,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     4,     5,     8,     9,     9,    10,     1,     2,     1,
       2,     6,     0,     1,     3,     3,     0,     1,     1,     1,
       2,     2,     0,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     4,     4,     5,     6,     7,     4,     5,     6,     7,
       4,     4,     4,     5,     6,     7,     1,     2,     2,     1,
       2,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       4,     4,     3,     3,     3,     4,     4,     3,     4,     6,
       4,     6,     3,     3,     4,     6,     6,     4,     6,     6,
       4,     1,     2,     1,     3,     3,     3,     5,     7,     7,
       5,     5,     5,     7,     7,     5,     5,     3,     3,     5,
       7,     5,     7,     1,     4,     3,     5,     1,     2,     5,
       8,    11,    14,     1,     1,     1,     1,     1,     1,     1,
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
  "\"'construction'\"", "\"'eval'\"", "\"'for'\"", "\"'ordering'\"",
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
  "\"'<='\"", "\"'[ / ]'\"", "\"'('\"", "\"'<'\"", "\"'-'\"", "\"'mod'\"",
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
  "FLWORExpr", "ForLetClauseList", "ForLetClause", "ForClause",
  "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
  "VarGetsDeclList", "EvalVarDeclList", "VarGetsDecl", "EvalVarDecl",
  "WhereClause", "GroupByClause", "GroupSpecList", "GroupSpec",
  "GroupCollationSpec", "LetClauseList", "OrderByClause", "OrderSpecList",
  "OrderSpec", "OrderModifier", "OrderDirSpec", "OrderEmptySpec",
  "OrderCollationSpec", "QuantifiedExpr", "QVarInDeclList", "QVarInDecl",
  "TypeswitchExpr", "CaseClauseList", "CaseClause", "IfExpr", "OrExpr",
  "AndExpr", "ComparisonExpr", "@1", "FTContainsExpr", "RangeExpr",
  "AdditiveExpr", "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "UnaryExpr",
  "SignList", "ValueExpr", "ValueComp", "NodeComp", "ValidateExpr",
  "ExtensionExpr", "PragmaList", "Pragma", "PathExpr", "RelativePathExpr",
  "StepExpr", "AxisStep", "ForwardStep", "ForwardAxis",
  "AbbrevForwardStep", "ReverseStep", "ReverseAxis", "NodeTest",
  "NameTest", "Wildcard", "FilterExpr", "PredicateList", "Predicate",
  "PrimaryExpr", "Literal", "NumericLiteral", "VarRef",
  "ParenthesizedExpr", "ContextItemExpr", "OrderedExpr", "UnorderedExpr",
  "FunctionCall", "ArgList", "Constructor", "DirectConstructor",
  "DirElemConstructor", "DirElemContentList", "DirAttributeList",
  "DirAttr", "OptionalBlank", "DirAttributeValue",
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
       266,     0,    -1,   268,    -1,   267,   268,    -1,   269,    -1,
     267,   269,    -1,   186,   187,    19,   161,    -1,   186,   187,
      19,   102,    19,   161,    -1,   271,   305,    -1,   305,    -1,
     270,   271,    -1,    46,   131,   446,   103,   445,   161,    -1,
     272,   161,    -1,   273,   161,    -1,   272,   161,   273,   161,
      -1,   274,    -1,   272,   161,   274,    -1,   275,    -1,   273,
     161,   275,    -1,   276,    -1,   277,    -1,   278,    -1,   280,
      -1,   292,    -1,   300,    -1,   281,    -1,   282,    -1,   279,
      -1,   286,    -1,   287,    -1,   293,    -1,   283,    -1,   284,
      -1,   285,    -1,   434,    -1,   288,    -1,   291,    -1,    36,
     131,   446,   103,   445,    -1,    36,    63,   152,    -1,    36,
      63,   166,    -1,    36,    86,    32,   131,   445,    -1,    36,
      86,    37,   131,   445,    -1,    36,    47,   447,    19,    -1,
      36,   216,   460,    -1,    36,    55,   139,    -1,    36,    55,
     172,    -1,    36,    86,   140,    98,    99,    -1,    36,    86,
     140,    98,   100,    -1,    36,    60,   152,    81,   118,    -1,
      36,    60,   152,    81,   136,    -1,    36,    60,   137,    81,
     118,    -1,    36,    60,   137,    81,   136,    -1,    36,    86,
      80,   445,    -1,    36,    57,   445,    -1,    43,    49,   445,
      -1,    43,    49,   290,   445,    -1,    43,    49,   445,    70,
     289,    -1,    43,    49,   290,   445,    70,   289,    -1,   445,
      -1,   289,    81,   445,    -1,   131,   446,   103,    -1,    86,
      32,   131,    -1,    43,    46,   445,    -1,    43,    46,   131,
     446,   103,   445,    -1,    43,    46,   445,    70,   289,    -1,
      43,    46,   131,   446,   103,   445,    70,   289,    -1,    36,
      85,    91,   447,   113,   307,    -1,    36,    85,    91,   447,
     108,    -1,    36,    85,    91,   447,   416,   113,   307,    -1,
      36,    85,    91,   447,   416,   108,    -1,    36,    52,   152,
      -1,    36,    52,   166,    -1,   127,   157,    -1,   127,   301,
     157,    -1,   127,   157,    68,   417,    -1,   127,   301,   157,
      68,   417,    -1,   123,   296,   154,    -1,   306,   161,    -1,
     296,   306,   161,    -1,    25,   209,   307,    -1,    29,   127,
     307,   157,   295,    -1,    26,    27,    -1,    56,    27,    -1,
      36,    37,   447,   294,   108,    -1,    36,    37,   447,   294,
     304,    -1,    36,    38,    37,   447,   294,   108,    -1,    36,
      38,    37,   447,   294,   304,    -1,    36,    39,    37,   447,
     294,   295,    -1,   302,    -1,   301,    81,   302,    -1,    91,
     447,    -1,    91,   447,   416,    -1,   123,   306,   154,    -1,
     123,   306,   154,    -1,   306,    -1,   307,    -1,   306,    81,
     307,    -1,   308,    -1,   334,    -1,   337,    -1,   340,    -1,
     341,    -1,   435,    -1,   436,    -1,   438,    -1,   437,    -1,
     439,    -1,   442,    -1,   448,    -1,   297,    -1,   298,    -1,
     299,    -1,   295,    -1,   309,   156,   307,    -1,   309,   321,
     156,   307,    -1,   309,   327,   156,   307,    -1,   309,   321,
     327,   156,   307,    -1,   309,   322,   156,   307,    -1,   309,
     321,   322,   156,   307,    -1,   309,   322,   327,   156,   307,
      -1,   309,   321,   322,   327,   156,   307,    -1,   310,    -1,
     309,   310,    -1,   311,    -1,   316,    -1,    54,    91,   312,
      -1,   313,    -1,   312,    81,    91,   313,    -1,   447,   117,
     307,    -1,   447,   416,   117,   307,    -1,   447,   314,   117,
     307,    -1,   447,   416,   314,   117,   307,    -1,   447,   315,
     117,   307,    -1,   447,   416,   315,   117,   307,    -1,   447,
     314,   315,   117,   307,    -1,   447,   416,   314,   315,   117,
     307,    -1,    70,    91,   447,    -1,   238,    91,   447,    -1,
      51,    91,   317,    -1,   319,    -1,   317,    81,    91,   319,
      -1,   320,    -1,   318,    81,    91,   320,    -1,   447,   113,
     307,    -1,   447,   416,   113,   307,    -1,   447,   315,   113,
     307,    -1,   447,   416,   315,   113,   307,    -1,   447,    -1,
     183,   307,    -1,   142,   141,   323,    -1,   142,   141,   323,
     326,    -1,   142,   141,   323,   321,    -1,   142,   141,   323,
     326,   321,    -1,   324,    -1,   323,    81,   324,    -1,    91,
     447,    -1,    91,   447,   325,    -1,    80,   445,    -1,   316,
      -1,   326,   316,    -1,   140,   141,   328,    -1,    45,   140,
     141,   328,    -1,   329,    -1,   328,    81,   329,    -1,   307,
      -1,   307,   330,    -1,   331,    -1,   332,    -1,   333,    -1,
     331,   332,    -1,   331,   333,    -1,   332,   333,    -1,   331,
     332,   333,    -1,    69,    -1,    89,    -1,    98,    99,    -1,
      98,   100,    -1,    80,   445,    -1,    44,    91,   335,   158,
     307,    -1,   106,    91,   335,   158,   307,    -1,   336,    -1,
     335,    81,    91,   336,    -1,   447,   117,   307,    -1,   447,
     416,   117,   307,    -1,    31,   127,   306,   157,   338,    86,
     156,   307,    -1,    31,   127,   306,   157,   338,    86,    91,
     447,   156,   307,    -1,   339,    -1,   338,   339,    -1,    74,
     417,   156,   307,    -1,    74,    91,   447,    68,   417,   156,
     307,    -1,    40,   127,   306,   157,   168,   307,    97,   307,
      -1,   342,    -1,   341,   138,   342,    -1,   343,    -1,   342,
      66,   343,    -1,   345,    -1,   345,   358,   345,    -1,   345,
     359,   345,    -1,   345,   103,   345,    -1,   345,   133,   345,
      -1,    -1,   345,   128,   344,   345,    -1,   345,   125,   345,
      -1,   345,   114,   345,    -1,   345,   112,   345,    -1,   346,
      -1,   346,   227,   449,    -1,   346,   227,   449,   483,    -1,
     347,    -1,   347,   169,   347,    -1,   348,    -1,   347,   146,
     348,    -1,   347,   129,   348,    -1,   349,    -1,   348,   164,
     349,    -1,   348,    90,   349,    -1,   348,   116,   349,    -1,
     348,   130,   349,    -1,   350,    -1,   349,   171,   350,    -1,
     349,   181,   350,    -1,   351,    -1,   350,   120,   351,    -1,
     350,   107,   351,    -1,   352,    -1,   352,    61,   203,   417,
      -1,   353,    -1,   353,   170,    68,   417,    -1,   354,    -1,
     354,    75,    68,   415,    -1,   355,    -1,   355,    76,    68,
     415,    -1,   357,    -1,   356,   357,    -1,   146,    -1,   129,
      -1,   356,   146,    -1,   356,   129,    -1,   360,    -1,   364,
      -1,   361,    -1,   174,    -1,   179,    -1,   178,    -1,   177,
      -1,   176,    -1,   175,    -1,   121,    -1,   149,    -1,   111,
      -1,    30,   123,   306,   154,    -1,    30,   193,   123,   306,
     154,    -1,    30,   194,   123,   306,   154,    -1,    30,   195,
     123,   306,   154,    -1,   362,   123,   154,    -1,   362,   123,
     306,   154,    -1,   363,    -1,   362,   363,    -1,   147,   447,
      14,    -1,   147,    15,    -1,   162,    -1,   162,   365,    -1,
     163,   365,    -1,   365,    -1,   366,    -1,   366,   162,   365,
      -1,   366,   163,   365,    -1,   367,    -1,   376,    -1,   368,
      -1,   368,   377,    -1,   371,    -1,   371,   377,    -1,   369,
     373,    -1,   370,    -1,    79,    -1,    87,    -1,    72,    -1,
     160,    -1,    88,    -1,   110,    -1,   109,    -1,   373,    -1,
      73,   373,    -1,   372,   373,    -1,    93,    -1,   143,    -1,
      64,    -1,   151,    -1,   150,    -1,    65,    -1,   421,    -1,
     374,    -1,   447,    -1,   375,    -1,   164,    -1,     9,    -1,
      16,    -1,   379,    -1,   379,   377,    -1,   378,    -1,   377,
     378,    -1,   124,   306,   155,    -1,   380,    -1,   382,    -1,
     383,    -1,   384,    -1,   387,    -1,   389,    -1,   385,    -1,
     386,    -1,   381,    -1,   433,    -1,    84,    -1,   119,    -1,
      95,    -1,    91,   447,    -1,   127,   157,    -1,   127,   306,
     157,    -1,    92,    -1,   139,   123,   306,   154,    -1,   172,
     123,   306,   154,    -1,   447,   127,   157,    -1,   447,   127,
     388,   157,    -1,   307,    -1,   388,    81,   307,    -1,   390,
      -1,   408,    -1,   391,    -1,   405,    -1,   406,    -1,   128,
     447,   395,   101,    -1,   128,   447,   393,   395,   101,    -1,
     128,   447,   395,   167,   165,   447,   395,   167,    -1,   128,
     447,   395,   167,   392,   165,   447,   395,   167,    -1,   128,
     447,   393,   395,   167,   165,   447,   395,   167,    -1,   128,
     447,   393,   395,   167,   392,   165,   447,   395,   167,    -1,
     403,    -1,   392,   403,    -1,   394,    -1,   393,   394,    -1,
      24,   447,   395,   103,   395,   396,    -1,    -1,    24,    -1,
     153,   397,   153,    -1,    67,   399,    67,    -1,    -1,   398,
      -1,   105,    -1,   401,    -1,   398,   105,    -1,   398,   401,
      -1,    -1,   400,    -1,   104,    -1,   402,    -1,   400,   104,
      -1,   400,   402,    -1,    18,    -1,   404,    -1,     3,    -1,
     404,    -1,   390,    -1,     8,    -1,   407,    -1,   404,    -1,
       7,    -1,    94,    -1,    96,    -1,   303,    -1,   184,    20,
     185,    -1,   184,   185,    -1,   144,    13,   145,    -1,   144,
      13,     6,    -1,    77,     5,    -1,   409,    -1,   410,    -1,
     411,    -1,   412,    -1,   413,    -1,   414,    -1,    33,   123,
     306,   154,    -1,    32,   447,   123,   154,    -1,    32,   447,
     123,   306,   154,    -1,    32,   123,   306,   154,   123,   154,
      -1,    32,   123,   306,   154,   123,   306,   154,    -1,    71,
     447,   123,   154,    -1,    71,   447,   123,   306,   154,    -1,
      71,   123,   306,   154,   123,   154,    -1,    71,   123,   306,
     154,   123,   306,   154,    -1,    34,   123,   306,   154,    -1,
      35,   123,   306,   154,    -1,    41,   446,   123,   154,    -1,
      41,   446,   123,   306,   154,    -1,    41,   123,   306,   154,
     123,   154,    -1,    41,   123,   306,   154,   123,   306,   154,
      -1,   420,    -1,   420,   115,    -1,    68,   417,    -1,   419,
      -1,   419,   418,    -1,   182,   127,   157,    -1,   115,    -1,
     164,    -1,   146,    -1,   420,    -1,   421,    -1,   122,   127,
     157,    -1,   447,    -1,   423,    -1,   429,    -1,   427,    -1,
     430,    -1,   428,    -1,   426,    -1,   425,    -1,   424,    -1,
     422,    -1,   197,   127,   157,    -1,    59,   127,   157,    -1,
      59,   127,   429,   157,    -1,    59,   127,   430,   157,    -1,
      34,   127,   157,    -1,    35,   127,   157,    -1,    41,   127,
     157,    -1,    41,   127,   446,   157,    -1,    41,   127,    19,
     157,    -1,    71,   127,   157,    -1,    71,   127,   447,   157,
      -1,    71,   127,   447,    81,   431,   157,    -1,    71,   127,
     164,   157,    -1,    71,   127,   164,    81,   431,   157,    -1,
     159,   447,   157,    -1,    32,   127,   157,    -1,    32,   127,
     447,   157,    -1,    32,   127,   447,    81,   431,   157,    -1,
      32,   127,   447,    81,   432,   157,    -1,    32,   127,   164,
     157,    -1,    32,   127,   164,    81,   431,   157,    -1,    32,
     127,   164,    81,   432,   157,    -1,    58,   127,   447,   157,
      -1,   447,    -1,   447,   115,    -1,    19,    -1,    36,   192,
     193,    -1,    36,   192,   194,    -1,    36,   192,   195,    -1,
     198,   197,   307,   205,   307,    -1,   198,   197,   307,    68,
     204,   205,   307,    -1,   198,   197,   307,    68,   206,   205,
     307,    -1,   198,   197,   307,   190,   307,    -1,   198,   197,
     307,   191,   307,    -1,   198,   199,   307,   205,   307,    -1,
     198,   199,   307,    68,   204,   205,   307,    -1,   198,   199,
     307,    68,   206,   205,   307,    -1,   198,   199,   307,   190,
     307,    -1,   198,   199,   307,   191,   307,    -1,   196,   197,
     307,    -1,   196,   199,   307,    -1,   201,   197,   307,   209,
     307,    -1,   201,   202,   203,   197,   307,   209,   307,    -1,
     200,   197,   307,    68,   307,    -1,   208,    91,   440,   207,
     307,   156,   307,    -1,   441,    -1,   440,    81,    91,   441,
      -1,   447,   113,   307,    -1,   210,   123,   307,   154,   443,
      -1,   444,    -1,   443,   444,    -1,   211,   127,   374,   157,
     304,    -1,   211,   127,   374,    81,    91,   447,   157,   304,
      -1,   211,   127,   374,    81,    91,   447,    81,    91,   447,
     157,   304,    -1,   211,   127,   374,    81,    91,   447,    81,
      91,   447,    81,    91,   447,   157,   304,    -1,    19,    -1,
      17,    -1,    17,    -1,    98,    -1,    71,    -1,    35,    -1,
      59,    -1,    32,    -1,   122,    -1,    40,    -1,   197,    -1,
      41,    -1,    62,    -1,    58,    -1,    34,    -1,    31,    -1,
     182,    -1,    63,    -1,   216,    -1,    57,    -1,   194,    -1,
     193,    -1,   116,    -1,    33,    -1,   228,    -1,   215,    -1,
     218,    -1,   217,    -1,   245,    -1,   246,    -1,   249,    -1,
     247,    -1,   250,    -1,   221,    -1,   223,    -1,    48,    -1,
     189,    -1,   222,    -1,    42,    -1,   195,    -1,   208,    -1,
     202,    -1,   174,    -1,   179,    -1,   178,    -1,   177,    -1,
     176,    -1,   175,    -1,    70,    -1,    85,    -1,   156,    -1,
      54,    -1,   117,    -1,    51,    -1,   183,    -1,   141,    -1,
     140,    -1,    45,    -1,    69,    -1,    89,    -1,    99,    -1,
     100,    -1,    80,    -1,    44,    -1,   106,    -1,   158,    -1,
      74,    -1,    68,    -1,   168,    -1,    97,    -1,   138,    -1,
      66,    -1,    61,    -1,   203,    -1,    75,    -1,   169,    -1,
      90,    -1,   130,    -1,   171,    -1,   120,    -1,   107,    -1,
      30,    -1,    76,    -1,   170,    -1,   121,    -1,   152,    -1,
     166,    -1,   131,    -1,   108,    -1,   102,    -1,   137,    -1,
     118,    -1,   136,    -1,    36,    -1,    52,    -1,    55,    -1,
      86,    -1,    60,    -1,    47,    -1,   187,    -1,    43,    -1,
      49,    -1,    37,    -1,   238,    -1,   227,    -1,   243,    -1,
     244,    -1,   220,    -1,   233,    -1,   241,    -1,   237,    -1,
     219,    -1,   232,    -1,   242,    -1,   236,    -1,   231,    -1,
     230,    -1,   214,    -1,   213,    -1,   235,    -1,   224,    -1,
     225,    -1,   248,    -1,   240,    -1,   239,    -1,   234,    -1,
     201,    -1,   207,    -1,   204,    -1,   198,    -1,   191,    -1,
     190,    -1,   192,    -1,   209,    -1,   199,    -1,   200,    -1,
     206,    -1,   196,    -1,   205,    -1,    38,    -1,   139,    -1,
     172,    -1,   212,    91,   318,    53,   123,   307,   154,    -1,
      53,   123,   307,   154,    -1,   451,    -1,   451,   450,    -1,
     451,   243,   346,    -1,   451,   450,   243,   346,    -1,   460,
      -1,   458,    -1,   450,   460,    -1,   450,   458,    -1,   452,
      -1,   451,   229,   452,    -1,   453,    -1,   452,   226,   453,
      -1,   454,    -1,   453,   228,   117,   454,    -1,   455,    -1,
     228,   455,    -1,   456,    -1,   456,   479,    -1,   127,   449,
     157,    -1,   457,    -1,   457,   475,    -1,   380,    -1,   123,
     306,   154,    -1,   459,    -1,   478,    -1,   477,    -1,   480,
      -1,   474,    -1,   139,    -1,   461,    -1,   462,    -1,   463,
      -1,   464,    -1,   467,    -1,   472,    -1,   473,    -1,   232,
      -1,   242,    -1,    74,   215,    -1,    74,   218,    -1,   209,
     217,    -1,   245,   217,    -1,   217,   215,    -1,   217,   218,
      -1,   209,   246,    -1,   245,   246,    -1,   209,   249,   466,
      -1,   209,   249,    86,    -1,   209,   249,   127,   466,   157,
      -1,   209,   249,   127,   466,    81,   465,   157,    -1,   209,
     249,   127,    86,   157,    -1,   209,   249,   127,    86,    81,
     465,   157,    -1,   245,   249,    -1,   466,    -1,   465,    81,
     466,    -1,    70,    19,    -1,    70,    19,   236,    19,    -1,
      70,    19,   476,   231,    -1,    70,    19,   236,    19,   476,
     231,    -1,   209,   247,   248,   469,    -1,   209,   247,   248,
     469,   468,    -1,   209,    86,   247,   248,    -1,   209,    86,
     247,   248,   468,    -1,   245,   247,   248,    -1,   471,    -1,
     468,   471,    -1,    70,    19,    -1,   127,   470,   157,    -1,
      19,    -1,   470,    19,    -1,   171,   469,    -1,   107,   469,
      -1,   230,    19,    -1,   209,   250,    -1,   245,   250,    -1,
      70,   189,    -1,    70,   222,    -1,   221,   223,    -1,   214,
      -1,   214,    48,    -1,   213,    -1,   213,   248,    -1,   235,
      -1,   224,   349,    -1,    70,   100,   349,    -1,    70,    42,
     349,    -1,   225,   349,   169,   349,    -1,   220,   476,   481,
      -1,   244,   349,   481,    -1,   233,   476,   241,    -1,   237,
     482,    -1,   219,   482,    -1,   248,    -1,   240,    -1,   234,
      -1,   239,    -1,   234,    -1,   245,   223,   349,    -1
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
     418,   420,   422,   424,   428,   433,   438,   444,   449,   455,
     461,   468,   470,   473,   475,   477,   481,   483,   488,   492,
     497,   502,   508,   513,   519,   525,   532,   536,   540,   544,
     546,   551,   553,   558,   562,   567,   572,   578,   580,   583,
     587,   592,   597,   603,   605,   609,   612,   616,   619,   621,
     624,   628,   633,   635,   639,   641,   644,   646,   648,   650,
     653,   656,   659,   663,   665,   667,   670,   673,   676,   682,
     688,   690,   695,   699,   704,   713,   724,   726,   729,   734,
     742,   751,   753,   757,   759,   763,   765,   769,   773,   777,
     781,   782,   787,   791,   795,   799,   801,   805,   810,   812,
     816,   818,   822,   826,   828,   832,   836,   840,   844,   846,
     850,   854,   856,   860,   864,   866,   871,   873,   878,   880,
     885,   887,   892,   894,   897,   899,   901,   904,   907,   909,
     911,   913,   915,   917,   919,   921,   923,   925,   927,   929,
     931,   936,   942,   948,   954,   958,   963,   965,   968,   972,
     975,   977,   980,   983,   985,   987,   991,   995,   997,   999,
    1001,  1004,  1006,  1009,  1012,  1014,  1016,  1018,  1020,  1022,
    1024,  1026,  1028,  1030,  1033,  1036,  1038,  1040,  1042,  1044,
    1046,  1048,  1050,  1052,  1054,  1056,  1058,  1060,  1062,  1064,
    1067,  1069,  1072,  1076,  1078,  1080,  1082,  1084,  1086,  1088,
    1090,  1092,  1094,  1096,  1098,  1100,  1102,  1105,  1108,  1112,
    1114,  1119,  1124,  1128,  1133,  1135,  1139,  1141,  1143,  1145,
    1147,  1149,  1154,  1160,  1169,  1179,  1189,  1200,  1202,  1205,
    1207,  1210,  1217,  1218,  1220,  1224,  1228,  1229,  1231,  1233,
    1235,  1238,  1241,  1242,  1244,  1246,  1248,  1251,  1254,  1256,
    1258,  1260,  1262,  1264,  1266,  1268,  1270,  1272,  1274,  1276,
    1278,  1282,  1285,  1289,  1293,  1296,  1298,  1300,  1302,  1304,
    1306,  1308,  1313,  1318,  1324,  1331,  1339,  1344,  1350,  1357,
    1365,  1370,  1375,  1380,  1386,  1393,  1401,  1403,  1406,  1409,
    1411,  1414,  1418,  1420,  1422,  1424,  1426,  1428,  1432,  1434,
    1436,  1438,  1440,  1442,  1444,  1446,  1448,  1450,  1452,  1456,
    1460,  1465,  1470,  1474,  1478,  1482,  1487,  1492,  1496,  1501,
    1508,  1513,  1520,  1524,  1528,  1533,  1540,  1547,  1552,  1559,
    1566,  1571,  1573,  1576,  1578,  1582,  1586,  1590,  1596,  1604,
    1612,  1618,  1624,  1630,  1638,  1646,  1652,  1658,  1662,  1666,
    1672,  1680,  1686,  1694,  1696,  1701,  1705,  1711,  1713,  1716,
    1722,  1731,  1743,  1758,  1760,  1762,  1764,  1766,  1768,  1770,
    1772,  1774,  1776,  1778,  1780,  1782,  1784,  1786,  1788,  1790,
    1792,  1794,  1796,  1798,  1800,  1802,  1804,  1806,  1808,  1810,
    1812,  1814,  1816,  1818,  1820,  1822,  1824,  1826,  1828,  1830,
    1832,  1834,  1836,  1838,  1840,  1842,  1844,  1846,  1848,  1850,
    1852,  1854,  1856,  1858,  1860,  1862,  1864,  1866,  1868,  1870,
    1872,  1874,  1876,  1878,  1880,  1882,  1884,  1886,  1888,  1890,
    1892,  1894,  1896,  1898,  1900,  1902,  1904,  1906,  1908,  1910,
    1912,  1914,  1916,  1918,  1920,  1922,  1924,  1926,  1928,  1930,
    1932,  1934,  1936,  1938,  1940,  1942,  1944,  1946,  1948,  1950,
    1952,  1954,  1956,  1958,  1960,  1962,  1964,  1966,  1968,  1970,
    1972,  1974,  1976,  1978,  1980,  1982,  1984,  1986,  1988,  1990,
    1992,  1994,  1996,  1998,  2000,  2002,  2004,  2006,  2008,  2010,
    2012,  2014,  2016,  2018,  2020,  2022,  2024,  2026,  2028,  2030,
    2032,  2034,  2036,  2038,  2040,  2042,  2050,  2055,  2057,  2060,
    2064,  2069,  2071,  2073,  2076,  2079,  2081,  2085,  2087,  2091,
    2093,  2098,  2100,  2103,  2105,  2108,  2112,  2114,  2117,  2119,
    2123,  2125,  2127,  2129,  2131,  2133,  2135,  2137,  2139,  2141,
    2143,  2145,  2147,  2149,  2151,  2153,  2156,  2159,  2162,  2165,
    2168,  2171,  2174,  2177,  2181,  2185,  2191,  2199,  2205,  2213,
    2216,  2218,  2222,  2225,  2230,  2235,  2242,  2247,  2253,  2258,
    2264,  2268,  2270,  2273,  2276,  2280,  2282,  2285,  2288,  2291,
    2294,  2297,  2300,  2303,  2306,  2309,  2311,  2314,  2316,  2319,
    2321,  2324,  2328,  2332,  2337,  2341,  2345,  2349,  2352,  2355,
    2357,  2359,  2361,  2363,  2365
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   782,   782,   787,   793,   798,   810,   815,   825,   832,
     844,   856,   868,   874,   880,   892,   898,   912,   918,   932,
     936,   940,   944,   953,   957,   961,   967,   977,   981,   985,
     989,   993,   997,  1001,  1007,  1017,  1021,  1036,  1048,  1053,
    1064,  1070,  1082,  1095,  1106,  1111,  1123,  1128,  1139,  1145,
    1151,  1157,  1176,  1187,  1198,  1205,  1212,  1219,  1232,  1238,
    1253,  1257,  1267,  1273,  1280,  1286,  1300,  1307,  1314,  1321,
    1334,  1339,  1351,  1355,  1359,  1363,  1370,  1377,  1383,  1392,
    1399,  1406,  1410,  1417,  1425,  1434,  1443,  1452,  1467,  1475,
    1489,  1495,  1507,  1515,  1526,  1537,  1543,  1555,  1559,  1563,
    1567,  1571,  1577,  1581,  1585,  1589,  1593,  1597,  1601,  1605,
    1609,  1613,  1617,  1627,  1634,  1642,  1650,  1659,  1671,  1683,
    1695,  1713,  1719,  1731,  1735,  1745,  1756,  1762,  1776,  1783,
    1791,  1800,  1810,  1818,  1827,  1836,  1851,  1863,  1874,  1886,
    1892,  1904,  1910,  1924,  1932,  1941,  1949,  1961,  1976,  1984,
    1991,  1998,  2005,  2015,  2021,  2032,  2038,  2047,  2054,  2061,
    2073,  2078,  2090,  2096,  2110,  2116,  2128,  2135,  2142,  2149,
    2156,  2163,  2170,  2183,  2187,  2197,  2202,  2213,  2224,  2231,
    2244,  2251,  2263,  2269,  2282,  2289,  2303,  2309,  2321,  2327,
    2340,  2351,  2355,  2366,  2370,  2389,  2393,  2401,  2409,  2417,
    2425,  2425,  2433,  2441,  2449,  2463,  2467,  2474,  2487,  2491,
    2502,  2506,  2510,  2520,  2524,  2528,  2532,  2536,  2546,  2550,
    2555,  2566,  2570,  2574,  2584,  2588,  2600,  2604,  2616,  2620,
    2632,  2636,  2648,  2652,  2664,  2668,  2672,  2676,  2688,  2692,
    2696,  2706,  2710,  2714,  2718,  2722,  2726,  2736,  2740,  2744,
    2754,  2758,  2764,  2770,  2782,  2788,  2800,  2806,  2820,  2827,
    2869,  2873,  2877,  2881,  2894,  2905,  2910,  2920,  2924,  2934,
    2940,  2946,  2952,  2964,  2970,  2981,  2985,  2989,  2993,  2997,
    3001,  3005,  3015,  3019,  3029,  3035,  3047,  3051,  3055,  3059,
    3063,  3078,  3082,  3092,  3096,  3106,  3113,  3120,  3133,  3137,
    3149,  3155,  3169,  3180,  3184,  3188,  3192,  3196,  3200,  3204,
    3208,  3218,  3222,  3232,  3237,  3242,  3253,  3263,  3267,  3278,
    3288,  3299,  3355,  3361,  3373,  3379,  3391,  3395,  3405,  3409,
    3413,  3423,  3431,  3439,  3447,  3455,  3463,  3478,  3484,  3496,
    3502,  3515,  3524,  3526,  3532,  3537,  3549,  3552,  3559,  3565,
    3571,  3579,  3594,  3597,  3604,  3610,  3616,  3624,  3638,  3643,
    3654,  3659,  3670,  3675,  3680,  3686,  3698,  3704,  3709,  3714,
    3725,  3730,  3745,  3750,  3767,  3782,  3786,  3790,  3794,  3798,
    3802,  3812,  3823,  3829,  3835,  3840,  3862,  3868,  3874,  3879,
    3890,  3901,  3912,  3918,  3924,  3929,  3940,  3946,  3958,  3970,
    3976,  3982,  4019,  4024,  4029,  4040,  4044,  4048,  4058,  4069,
    4073,  4077,  4081,  4085,  4089,  4093,  4097,  4101,  4111,  4121,
    4125,  4130,  4141,  4151,  4161,  4165,  4169,  4179,  4185,  4191,
    4197,  4203,  4215,  4226,  4232,  4238,  4244,  4250,  4257,  4264,
    4277,  4298,  4305,  4325,  4365,  4370,  4373,  4381,  4387,  4393,
    4399,  4405,  4412,  4418,  4424,  4430,  4436,  4448,  4453,  4463,
    4469,  4481,  4507,  4518,  4524,  4537,  4551,  4558,  4565,  4576,
    4583,  4591,  4600,  4613,  4616,  4634,  4635,  4636,  4637,  4638,
    4639,  4640,  4641,  4642,  4643,  4644,  4645,  4646,  4647,  4648,
    4649,  4650,  4651,  4652,  4653,  4654,  4655,  4656,  4657,  4658,
    4659,  4660,  4661,  4662,  4663,  4664,  4665,  4666,  4667,  4668,
    4669,  4670,  4671,  4672,  4673,  4674,  4675,  4676,  4677,  4678,
    4679,  4680,  4681,  4682,  4683,  4684,  4685,  4686,  4687,  4688,
    4689,  4690,  4691,  4692,  4693,  4694,  4695,  4696,  4697,  4698,
    4699,  4700,  4701,  4702,  4703,  4704,  4705,  4706,  4707,  4708,
    4709,  4710,  4711,  4712,  4713,  4714,  4715,  4716,  4717,  4718,
    4719,  4720,  4721,  4722,  4723,  4724,  4725,  4726,  4727,  4728,
    4729,  4730,  4731,  4732,  4733,  4734,  4735,  4736,  4737,  4738,
    4739,  4740,  4741,  4742,  4743,  4744,  4745,  4746,  4747,  4748,
    4749,  4750,  4751,  4752,  4753,  4754,  4755,  4756,  4757,  4758,
    4759,  4760,  4761,  4762,  4763,  4764,  4765,  4766,  4767,  4768,
    4769,  4770,  4771,  4772,  4773,  4784,  4790,  4807,  4811,  4815,
    4819,  4829,  4832,  4835,  4838,  4847,  4850,  4859,  4862,  4871,
    4874,  4883,  4886,  4895,  4898,  4901,  4910,  4913,  4922,  4926,
    4936,  4939,  4942,  4945,  4948,  4957,  4966,  4970,  4974,  4978,
    4982,  4986,  4990,  5000,  5003,  5006,  5009,  5018,  5021,  5024,
    5027,  5036,  5039,  5048,  5051,  5054,  5057,  5060,  5063,  5066,
    5075,  5078,  5087,  5090,  5093,  5096,  5105,  5108,  5111,  5114,
    5117,  5126,  5129,  5138,  5141,  5150,  5153,  5162,  5165,  5174,
    5183,  5186,  5195,  5198,  5201,  5210,  5213,  5216,  5219,  5222,
    5231,  5235,  5239,  5243,  5253,  5262,  5272,  5281,  5284,  5293,
    5296,  5299,  5308,  5311,  5320
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
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 7678;
  const int xquery_parser::yynnts_ = 219;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 409;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 265;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 519;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5328 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"



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

