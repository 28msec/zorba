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
#line 787 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

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
#line 680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 103: /* "\"'DOUBLE'\"" */
#line 679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 127: /* "\"'INTEGER'\"" */
#line 678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 274: /* "VersionDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 275: /* "MainModule" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 276: /* "LibraryModule" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 277: /* "ModuleDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 278: /* "Prolog" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 279: /* "SIND_DeclList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 280: /* "VFO_DeclList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 281: /* "SIND_Decl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 282: /* "VFO_Decl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 283: /* "Setter" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 284: /* "Import" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 285: /* "NamespaceDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "BoundarySpaceDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "DefaultNamespaceDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "OptionDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "OrderingModeDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "EmptyOrderDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "CopyNamespacesDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "DefaultCollationDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "BaseURIDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "SchemaImport" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "URILiteralList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "SchemaPrefix" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "ModuleImport" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "VarDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 346 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "ConstructionDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "FunctionSig" */
#line 692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 356 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "Block" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 361 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "BlockBody" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 366 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "ExitExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 371 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "WhileExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 376 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "FlowCtlStatement" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 381 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "FunctionDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 386 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "ParamList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 391 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "Param" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 396 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "EnclosedExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 401 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "BracedExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 406 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "QueryBody" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 411 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "Expr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 416 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "ExprSingle" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 421 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "FLWORExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 426 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "ReturnExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 431 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "FLWORWinCond" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 436 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "WindowClause" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 441 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "CountClause" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 446 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "ForLetWinClause" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 451 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "FLWORClauseList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 456 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "ForClause" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 461 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VarInDeclList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 466 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "VarInDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 471 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "PositionalVar" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "LetClause" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 481 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "VarGetsDeclList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 486 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "EvalVarDeclList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 491 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "VarGetsDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 496 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "WindowVarDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 501 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "WindowVars" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 506 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "WindowVars3" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 511 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "WindowVars2" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 516 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "EvalVarDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 521 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "WhereClause" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "GroupByClause" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "GroupSpecList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 536 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "GroupSpec" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "GroupCollationSpec" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "OrderByClause" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 551 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "OrderSpecList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 556 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "OrderSpec" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 561 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "OrderModifier" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 566 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "OrderDirSpec" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 571 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "OrderEmptySpec" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 576 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "OrderCollationSpec" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 581 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "QuantifiedExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 586 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "QVarInDeclList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 591 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "QVarInDecl" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 596 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "TypeswitchExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 601 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CaseClauseList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 606 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CaseClause" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 611 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "IfExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 616 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "OrExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 621 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "AndExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 626 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "ComparisonExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 631 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "FTContainsExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 636 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "RangeExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 641 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "AdditiveExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 646 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "MultiplicativeExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 651 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "UnionExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 656 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "IntersectExceptExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 661 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "InstanceofExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 666 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "TreatExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 671 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "CastableExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 676 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "CastExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 681 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "UnaryExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 686 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "SignList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 691 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "ValueExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 696 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "ValueComp" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 701 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "NodeComp" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 706 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ValidateExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 711 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "ExtensionExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 716 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "PragmaList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 721 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "Pragma" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 726 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "PathExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 731 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "RelativePathExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 736 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "StepExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 741 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "AxisStep" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 746 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ForwardStep" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 751 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ForwardAxis" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 756 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "AbbrevForwardStep" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 761 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "ReverseStep" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 766 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ReverseAxis" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 771 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "NodeTest" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 776 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "NameTest" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 781 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Wildcard" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 786 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "FilterExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 791 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "PredicateList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 796 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "Predicate" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 801 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "PrimaryExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 806 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "Literal" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 811 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "NumericLiteral" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 816 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "VarRef" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 821 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ParenthesizedExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 826 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ContextItemExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 831 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "OrderedExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 836 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "UnorderedExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 841 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "FunctionCall" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 846 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ArgList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 851 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "Constructor" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 856 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "DirectConstructor" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 861 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "DirElemConstructor" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 866 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "DirElemContentList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 871 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "DirAttributeList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 876 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "DirAttr" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 881 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "DirAttributeValue" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 886 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "Opt_QuoteAttrContentList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 891 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "QuoteAttrContentList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 896 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "Opt_AposAttrContentList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 901 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "AposAttrContentList" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 906 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "QuoteAttrValueContent" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 911 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "AposAttrValueContent" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 916 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "DirElemContent" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 921 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "CommonContent" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 926 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "DirCommentConstructor" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 931 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "DirPIConstructor" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 936 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "CDataSection" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 941 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "ComputedConstructor" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 946 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "CompDocConstructor" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 951 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "CompElemConstructor" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 956 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "CompAttrConstructor" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 961 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "CompTextConstructor" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 966 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "CompCommentConstructor" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 971 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "CompPIConstructor" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 976 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "SingleType" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 981 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "TypeDeclaration" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 986 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "SequenceType" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 991 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OccurrenceIndicator" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 996 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "ItemType" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1001 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "AtomicType" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1006 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "KindTest" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1011 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "AnyKindTest" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1016 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "DocumentTest" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1021 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "TextTest" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1026 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "CommentTest" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1031 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "PITest" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1036 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "AttributeTest" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1041 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "SchemaAttributeTest" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1046 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "ElementTest" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1051 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "SchemaElementTest" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1056 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "TypeName" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1061 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "TypeName_WITH_HOOK" */
#line 688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1066 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "StringLiteral" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1071 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "InsertExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1076 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "DeleteExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1081 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ReplaceExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1086 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "RenameExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1091 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "TransformExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1096 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "VarNameList" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1101 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "VarNameDecl" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1106 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "TryExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1111 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CatchListExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1116 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "CatchExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1121 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "EvalExpr" */
#line 690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
	  case 2:
#line 807 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 3:
#line 812 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 4:
#line 818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 823 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 835 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		;}
    break;

  case 7:
#line 840 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    ;}
    break;

  case 8:
#line 850 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 9:
#line 857 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		;}
    break;

  case 10:
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 11:
#line 881 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval)));
		;}
    break;

  case 12:
#line 893 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 13:
#line 899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 14:
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 15:
#line 917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 16:
#line 923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 17:
#line 937 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 18:
#line 943 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 37:
#line 1007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 38:
#line 1019 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1024 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 41:
#line 1041 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 42:
#line 1053 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 43:
#line 1066 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		;}
    break;

  case 44:
#line 1077 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1082 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1099 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1110 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 49:
#line 1116 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 50:
#line 1122 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 51:
#line 1128 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 52:
#line 1147 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 53:
#line 1158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 54:
#line 1169 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 55:
#line 1176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		;}
    break;

  case 56:
#line 1183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 57:
#line 1190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 58:
#line 1203 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 59:
#line 1209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 60:
#line 1224 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 62:
#line 1238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 63:
#line 1244 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		;}
    break;

  case 64:
#line 1251 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 65:
#line 1257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		;}
    break;

  case 66:
#line 1271 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								NULL,
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 67:
#line 1278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (4)].sval)),
								NULL,
								NULL);
		;}
    break;

  case 68:
#line 1285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (4)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 69:
#line 1292 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (5)].node)),
								NULL);
		;}
    break;

  case 70:
#line 1305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1310 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1322 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 73:
#line 1326 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 74:
#line 1330 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 75:
#line 1334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 76:
#line 1341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    ;}
    break;

  case 77:
#line 1348 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = new BlockBody (LOC ((yyloc)));
      blk->add ((yysemantic_stack_[(2) - (1)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 78:
#line 1354 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 79:
#line 1363 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 80:
#line 1370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr)));
    ;}
    break;

  case 81:
#line 1377 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 82:
#line 1381 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 83:
#line 1388 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval))),
                &* (yysemantic_stack_[(5) - (4)].fnsig)->param, &* (yysemantic_stack_[(5) - (4)].fnsig)->ret, NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
		;}
    break;

  case 84:
#line 1396 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1405 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1414 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1423 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1438 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 89:
#line 1446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 90:
#line 1460 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 91:
#line 1466 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 92:
#line 1478 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 94:
#line 1497 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 95:
#line 1508 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = new Expr(LOC ((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 96:
#line 1514 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 113:
#line 1550 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 114:
#line 1559 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 115:
#line 1566 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    ;}
    break;

  case 116:
#line 1570 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    ;}
    break;

  case 117:
#line 1578 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    ;}
    break;

  case 118:
#line 1582 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    ;}
    break;

  case 119:
#line 1586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    ;}
    break;

  case 120:
#line 1593 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 121:
#line 1597 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 122:
#line 1604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)), dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 123:
#line 1609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    ;}
    break;

  case 124:
#line 1618 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 133:
#line 1636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 134:
#line 1642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 135:
#line 1651 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    ;}
    break;

  case 136:
#line 1655 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    ;}
    break;

  case 137:
#line 1665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		;}
    break;

  case 138:
#line 1676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 139:
#line 1682 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 140:
#line 1696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 141:
#line 1703 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 142:
#line 1711 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 143:
#line 1720 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 144:
#line 1730 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 145:
#line 1738 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 146:
#line 1747 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 147:
#line 1756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 148:
#line 1771 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 149:
#line 1783 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 150:
#line 1794 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 151:
#line 1806 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 152:
#line 1812 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 153:
#line 1824 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 154:
#line 1830 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 155:
#line 1844 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 156:
#line 1852 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 157:
#line 1861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 158:
#line 1869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 159:
#line 1881 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 160:
#line 1887 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 162:
#line 1898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)), "", "");
    ;}
    break;

  case 163:
#line 1902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
    ;}
    break;

  case 164:
#line 1910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    ;}
    break;

  case 165:
#line 1914 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    ;}
    break;

  case 167:
#line 1923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)));
    ;}
    break;

  case 168:
#line 1927 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 169:
#line 1931 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)), "");
    ;}
    break;

  case 170:
#line 1938 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 171:
#line 1953 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 172:
#line 1961 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 173:
#line 1971 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 174:
#line 1977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 175:
#line 1988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 176:
#line 1994 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 177:
#line 2003 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 178:
#line 2013 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 179:
#line 2018 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 180:
#line 2030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 181:
#line 2036 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 182:
#line 2050 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 183:
#line 2056 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 184:
#line 2068 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 185:
#line 2075 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 186:
#line 2082 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 187:
#line 2089 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 188:
#line 2096 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 189:
#line 2103 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 190:
#line 2110 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 191:
#line 2123 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 192:
#line 2127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 193:
#line 2137 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 194:
#line 2142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 195:
#line 2153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 196:
#line 2164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 197:
#line 2171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 198:
#line 2184 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 199:
#line 2191 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 200:
#line 2203 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 201:
#line 2209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 202:
#line 2222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 203:
#line 2229 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 204:
#line 2243 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 205:
#line 2249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 206:
#line 2261 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 207:
#line 2267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 208:
#line 2280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 209:
#line 2291 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 2295 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 211:
#line 2306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 212:
#line 2310 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 213:
#line 2329 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 214:
#line 2333 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 215:
#line 2341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 216:
#line 2349 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 217:
#line 2357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 218:
#line 2364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 219:
#line 2365 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 220:
#line 2373 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 221:
#line 2381 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 222:
#line 2389 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 223:
#line 2403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 224:
#line 2407 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 225:
#line 2414 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 226:
#line 2427 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 227:
#line 2431 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 228:
#line 2442 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 229:
#line 2446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 230:
#line 2450 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 231:
#line 2460 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 232:
#line 2464 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 233:
#line 2468 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 234:
#line 2472 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 235:
#line 2476 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 236:
#line 2486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 237:
#line 2490 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 238:
#line 2495 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 239:
#line 2506 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 240:
#line 2510 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 241:
#line 2514 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 242:
#line 2524 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 243:
#line 2528 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 244:
#line 2540 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 245:
#line 2544 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 246:
#line 2556 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 247:
#line 2560 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 248:
#line 2572 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 249:
#line 2576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 250:
#line 2588 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 251:
#line 2592 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 252:
#line 2604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 253:
#line 2608 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 254:
#line 2612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 255:
#line 2616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 256:
#line 2628 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 257:
#line 2632 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 258:
#line 2636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 259:
#line 2646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 260:
#line 2650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 261:
#line 2654 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 262:
#line 2658 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 263:
#line 2662 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 264:
#line 2666 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 265:
#line 2676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 266:
#line 2680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 267:
#line 2684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 268:
#line 2694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 269:
#line 2698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "strict",
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 270:
#line 2704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "lax",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 271:
#line 2710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                "skip",
                (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 272:
#line 2722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 273:
#line 2728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 274:
#line 2740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 275:
#line 2746 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 276:
#line 2760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 277:
#line 2766 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 278:
#line 2808 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 279:
#line 2812 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 280:
#line 2816 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 281:
#line 2820 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 282:
#line 2832 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    ;}
    break;

  case 283:
#line 2842 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 284:
#line 2853 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 285:
#line 2858 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 286:
#line 2868 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 287:
#line 2872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 288:
#line 2882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 289:
#line 2888 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 290:
#line 2894 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 291:
#line 2900 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 292:
#line 2912 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 293:
#line 2918 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 294:
#line 2929 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 295:
#line 2933 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 296:
#line 2937 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 297:
#line 2941 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 298:
#line 2945 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 299:
#line 2949 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 300:
#line 2953 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 301:
#line 2963 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 302:
#line 2967 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 303:
#line 2977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 304:
#line 2983 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 305:
#line 2995 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 306:
#line 2999 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 307:
#line 3003 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 308:
#line 3007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 309:
#line 3011 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 310:
#line 3026 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 311:
#line 3030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 312:
#line 3040 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 313:
#line 3044 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 314:
#line 3054 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 315:
#line 3061 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 316:
#line 3068 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 317:
#line 3081 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 318:
#line 3085 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 319:
#line 3097 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 320:
#line 3103 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 321:
#line 3117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 322:
#line 3128 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 323:
#line 3132 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 324:
#line 3136 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 325:
#line 3140 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 326:
#line 3144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 327:
#line 3148 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 328:
#line 3152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 329:
#line 3156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 333:
#line 3185 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 334:
#line 3190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 335:
#line 3201 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 336:
#line 3211 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 337:
#line 3215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 338:
#line 3226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 339:
#line 3236 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 340:
#line 3247 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 341:
#line 3303 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 342:
#line 3309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 343:
#line 3321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 344:
#line 3327 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 345:
#line 3339 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 346:
#line 3343 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
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
#line 3361 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 3371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 351:
#line 3379 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 352:
#line 3387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 353:
#line 3395 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 354:
#line 3403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 355:
#line 3411 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 356:
#line 3426 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 357:
#line 3432 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 358:
#line 3444 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 359:
#line 3450 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 360:
#line 3463 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 363:
#line 3480 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 364:
#line 3485 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 365:
#line 3496 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 366:
#line 3500 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 367:
#line 3507 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 368:
#line 3513 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 369:
#line 3519 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 370:
#line 3527 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 371:
#line 3541 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 372:
#line 3545 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 373:
#line 3552 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 374:
#line 3558 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 375:
#line 3564 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 376:
#line 3572 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 377:
#line 3586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 378:
#line 3591 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 379:
#line 3602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 380:
#line 3607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 381:
#line 3618 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 382:
#line 3623 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 383:
#line 3628 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 384:
#line 3634 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 385:
#line 3646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 386:
#line 3652 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 387:
#line 3657 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 388:
#line 3662 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 389:
#line 3673 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 390:
#line 3678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 391:
#line 3693 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 392:
#line 3698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 393:
#line 3715 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 394:
#line 3730 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 395:
#line 3734 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 396:
#line 3738 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 397:
#line 3742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 398:
#line 3746 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 399:
#line 3750 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 400:
#line 3760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 401:
#line 3771 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 402:
#line 3777 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 403:
#line 3783 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 404:
#line 3788 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 405:
#line 3810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 406:
#line 3816 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 407:
#line 3822 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 408:
#line 3827 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 409:
#line 3838 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 410:
#line 3849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 411:
#line 3860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 412:
#line 3866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 413:
#line 3872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 414:
#line 3877 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 415:
#line 3888 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 416:
#line 3894 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 417:
#line 3906 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 418:
#line 3918 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 419:
#line 3924 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 420:
#line 3930 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 421:
#line 3967 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 422:
#line 3972 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 423:
#line 3977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 424:
#line 3988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 425:
#line 3992 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 426:
#line 3996 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 427:
#line 4006 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 428:
#line 4017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 429:
#line 4021 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 430:
#line 4025 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 431:
#line 4029 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 432:
#line 4033 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 433:
#line 4037 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 434:
#line 4041 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 435:
#line 4045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 436:
#line 4049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 437:
#line 4059 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 438:
#line 4069 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 439:
#line 4073 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 440:
#line 4078 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 441:
#line 4089 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 442:
#line 4099 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 443:
#line 4109 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 444:
#line 4113 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 445:
#line 4117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 446:
#line 4127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 447:
#line 4133 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 448:
#line 4139 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 449:
#line 4145 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 450:
#line 4151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 451:
#line 4163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 452:
#line 4174 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL);
		;}
    break;

  case 453:
#line 4180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
									NULL);
		;}
    break;

  case 454:
#line 4186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 455:
#line 4192 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 456:
#line 4198 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 457:
#line 4205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 458:
#line 4212 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 459:
#line 4225 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 460:
#line 4246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 461:
#line 4253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 462:
#line 4273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 463:
#line 4313 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 464:
#line 4318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 465:
#line 4321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 466:
#line 4329 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 467:
#line 4335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 468:
#line 4341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 469:
#line 4347 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 470:
#line 4353 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 471:
#line 4360 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 472:
#line 4366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 473:
#line 4372 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 474:
#line 4378 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 475:
#line 4384 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 476:
#line 4396 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 477:
#line 4401 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 478:
#line 4411 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 479:
#line 4417 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 480:
#line 4429 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 481:
#line 4455 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 482:
#line 4466 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 483:
#line 4472 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 484:
#line 4485 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 485:
#line 4499 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 486:
#line 4506 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 487:
#line 4513 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 488:
#line 4524 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 489:
#line 4531 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 490:
#line 4539 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 491:
#line 4548 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(14) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (9)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (12)].sval)),
                          (yysemantic_stack_[(14) - (14)].expr));
    ;}
    break;

  case 493:
#line 4564 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 494:
#line 4581 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 495:
#line 4582 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty"); ;}
    break;

  case 496:
#line 4583 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("attribute"); ;}
    break;

  case 497:
#line 4584 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("comment"); ;}
    break;

  case 498:
#line 4585 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document-node"); ;}
    break;

  case 499:
#line 4586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("element"); ;}
    break;

  case 500:
#line 4587 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("item"); ;}
    break;

  case 501:
#line 4588 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("if"); ;}
    break;

  case 502:
#line 4589 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("node"); ;}
    break;

  case 503:
#line 4590 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("processing-instruction"); ;}
    break;

  case 504:
#line 4591 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-attribute"); ;}
    break;

  case 505:
#line 4592 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-element"); ;}
    break;

  case 506:
#line 4593 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("text"); ;}
    break;

  case 507:
#line 4594 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("typeswitch"); ;}
    break;

  case 508:
#line 4595 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty-sequence"); ;}
    break;

  case 509:
#line 4596 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("boundary-space"); ;}
    break;

  case 510:
#line 4597 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ft-option"); ;}
    break;

  case 511:
#line 4598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("base-uri"); ;}
    break;

  case 512:
#line 4599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lax"); ;}
    break;

  case 513:
#line 4600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strict"); ;}
    break;

  case 514:
#line 4601 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("idiv"); ;}
    break;

  case 515:
#line 4602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document"); ;}
    break;

  case 516:
#line 4603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("not"); ;}
    break;

  case 517:
#line 4604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sensitive"); ;}
    break;

  case 518:
#line 4605 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insensitive"); ;}
    break;

  case 519:
#line 4606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("diacritics"); ;}
    break;

  case 520:
#line 4607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("without"); ;}
    break;

  case 521:
#line 4608 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stemming"); ;}
    break;

  case 522:
#line 4609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("thesaurus"); ;}
    break;

  case 523:
#line 4610 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stop"); ;}
    break;

  case 524:
#line 4611 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("wildcards"); ;}
    break;

  case 525:
#line 4612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("entire"); ;}
    break;

  case 526:
#line 4613 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("content"); ;}
    break;

  case 527:
#line 4614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("word"); ;}
    break;

  case 528:
#line 4615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("start"); ;}
    break;

  case 529:
#line 4616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("end"); ;}
    break;

  case 530:
#line 4617 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("most"); ;}
    break;

  case 531:
#line 4618 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("skip"); ;}
    break;

  case 532:
#line 4619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy"); ;}
    break;

  case 533:
#line 4620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("value"); ;}
    break;

  case 534:
#line 4621 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("eq"); ;}
    break;

  case 535:
#line 4622 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ne"); ;}
    break;

  case 536:
#line 4623 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lt"); ;}
    break;

  case 537:
#line 4624 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("le"); ;}
    break;

  case 538:
#line 4625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("gt"); ;}
    break;

  case 539:
#line 4626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ge"); ;}
    break;

  case 540:
#line 4627 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("at"); ;}
    break;

  case 541:
#line 4628 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("variable"); ;}
    break;

  case 542:
#line 4629 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("return"); ;}
    break;

  case 543:
#line 4630 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("for"); ;}
    break;

  case 544:
#line 4631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("outer"); ;}
    break;

  case 545:
#line 4632 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sliding"); ;}
    break;

  case 546:
#line 4633 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("tumbling"); ;}
    break;

  case 547:
#line 4634 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("previous"); ;}
    break;

  case 548:
#line 4635 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("next"); ;}
    break;

  case 549:
#line 4636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("only"); ;}
    break;

  case 550:
#line 4637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("when"); ;}
    break;

  case 551:
#line 4638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("count"); ;}
    break;

  case 552:
#line 4639 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("in"); ;}
    break;

  case 553:
#line 4640 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("let"); ;}
    break;

  case 554:
#line 4641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("where"); ;}
    break;

  case 555:
#line 4642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("by"); ;}
    break;

  case 556:
#line 4643 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("order"); ;}
    break;

  case 557:
#line 4644 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stable"); ;}
    break;

  case 558:
#line 4645 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ascending"); ;}
    break;

  case 559:
#line 4646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("descending"); ;}
    break;

  case 560:
#line 4647 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("greatest"); ;}
    break;

  case 561:
#line 4648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("least"); ;}
    break;

  case 562:
#line 4649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("collation"); ;}
    break;

  case 563:
#line 4650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("some"); ;}
    break;

  case 564:
#line 4651 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("every"); ;}
    break;

  case 565:
#line 4652 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("satisfies"); ;}
    break;

  case 566:
#line 4653 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("case"); ;}
    break;

  case 567:
#line 4654 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("as"); ;}
    break;

  case 568:
#line 4655 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("then"); ;}
    break;

  case 569:
#line 4656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("else"); ;}
    break;

  case 570:
#line 4657 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("or"); ;}
    break;

  case 571:
#line 4658 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("and"); ;}
    break;

  case 572:
#line 4659 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("instance"); ;}
    break;

  case 573:
#line 4660 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("of"); ;}
    break;

  case 574:
#line 4661 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("castable"); ;}
    break;

  case 575:
#line 4662 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("to"); ;}
    break;

  case 576:
#line 4663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("div"); ;}
    break;

  case 577:
#line 4664 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("mod"); ;}
    break;

  case 578:
#line 4665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("union"); ;}
    break;

  case 579:
#line 4666 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("intersect"); ;}
    break;

  case 580:
#line 4667 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("except"); ;}
    break;

  case 581:
#line 4668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("validate"); ;}
    break;

  case 582:
#line 4669 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cast"); ;}
    break;

  case 583:
#line 4670 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("treat"); ;}
    break;

  case 584:
#line 4671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("is"); ;}
    break;

  case 585:
#line 4672 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("preserve"); ;}
    break;

  case 586:
#line 4673 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strip"); ;}
    break;

  case 587:
#line 4674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("namespace"); ;}
    break;

  case 588:
#line 4675 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("external"); ;}
    break;

  case 589:
#line 4676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("encoding"); ;}
    break;

  case 590:
#line 4677 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-preserve"); ;}
    break;

  case 591:
#line 4678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("inherit"); ;}
    break;

  case 592:
#line 4679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-inherit"); ;}
    break;

  case 593:
#line 4680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("declare"); ;}
    break;

  case 594:
#line 4681 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("construction"); ;}
    break;

  case 595:
#line 4682 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordering"); ;}
    break;

  case 596:
#line 4683 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("default"); ;}
    break;

  case 597:
#line 4684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy-namespaces"); ;}
    break;

  case 598:
#line 4685 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("option"); ;}
    break;

  case 599:
#line 4686 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("version"); ;}
    break;

  case 600:
#line 4687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("import"); ;}
    break;

  case 601:
#line 4688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema"); ;}
    break;

  case 602:
#line 4689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("function"); ;}
    break;

  case 603:
#line 4690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("score"); ;}
    break;

  case 604:
#line 4691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ftcontains"); ;}
    break;

  case 605:
#line 4692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("weight"); ;}
    break;

  case 606:
#line 4693 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("window"); ;}
    break;

  case 607:
#line 4694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("distance"); ;}
    break;

  case 608:
#line 4695 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("occurs"); ;}
    break;

  case 609:
#line 4696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("times"); ;}
    break;

  case 610:
#line 4697 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("same"); ;}
    break;

  case 611:
#line 4698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("different"); ;}
    break;

  case 612:
#line 4699 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lowercase"); ;}
    break;

  case 613:
#line 4700 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("uppercase"); ;}
    break;

  case 614:
#line 4701 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("relationship"); ;}
    break;

  case 615:
#line 4702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("levels"); ;}
    break;

  case 616:
#line 4703 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("language"); ;}
    break;

  case 617:
#line 4704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("any"); ;}
    break;

  case 618:
#line 4705 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("all"); ;}
    break;

  case 619:
#line 4706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("phrase"); ;}
    break;

  case 620:
#line 4707 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exactly"); ;}
    break;

  case 621:
#line 4708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("from"); ;}
    break;

  case 622:
#line 4709 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("words"); ;}
    break;

  case 623:
#line 4710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentences"); ;}
    break;

  case 624:
#line 4711 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentence"); ;}
    break;

  case 625:
#line 4712 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("paragraph"); ;}
    break;

  case 626:
#line 4713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("replace"); ;}
    break;

  case 627:
#line 4714 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("modify"); ;}
    break;

  case 628:
#line 4715 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("first"); ;}
    break;

  case 629:
#line 4716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insert"); ;}
    break;

  case 630:
#line 4717 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("bofer"); ;}
    break;

  case 631:
#line 4718 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("after"); ;}
    break;

  case 632:
#line 4719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("revalidation"); ;}
    break;

  case 633:
#line 4720 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("with"); ;}
    break;

  case 634:
#line 4721 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("nodes"); ;}
    break;

  case 635:
#line 4722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("rename"); ;}
    break;

  case 636:
#line 4723 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("last"); ;}
    break;

  case 637:
#line 4724 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("delete"); ;}
    break;

  case 638:
#line 4725 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("into"); ;}
    break;

  case 639:
#line 4726 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("updating"); ;}
    break;

  case 640:
#line 4727 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordered"); ;}
    break;

  case 641:
#line 4728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("unordered"); ;}
    break;

  case 642:
#line 4740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 643:
#line 4746 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 644:
#line 4763 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 645:
#line 4767 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 646:
#line 4771 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 647:
#line 4775 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 648:
#line 4785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 649:
#line 4788 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 650:
#line 4791 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 651:
#line 4794 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 652:
#line 4803 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 653:
#line 4806 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 654:
#line 4815 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 655:
#line 4818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 656:
#line 4827 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 657:
#line 4830 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 658:
#line 4839 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 659:
#line 4842 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 660:
#line 4851 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 661:
#line 4854 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 662:
#line 4857 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 663:
#line 4866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 664:
#line 4869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 665:
#line 4878 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 666:
#line 4882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, static_cast<Expr *> ((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 667:
#line 4892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 668:
#line 4895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 669:
#line 4898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 670:
#line 4901 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
		;}
    break;

  case 673:
#line 4922 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 674:
#line 4926 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 675:
#line 4930 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 676:
#line 4934 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 677:
#line 4938 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 678:
#line 4942 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 679:
#line 4946 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 680:
#line 4956 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 681:
#line 4959 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 682:
#line 4962 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 683:
#line 4965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 684:
#line 4974 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 685:
#line 4977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 686:
#line 4980 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 687:
#line 4983 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 688:
#line 4992 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 689:
#line 4995 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 690:
#line 5004 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 691:
#line 5007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 692:
#line 5010 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 693:
#line 5013 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 694:
#line 5016 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 695:
#line 5019 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 696:
#line 5022 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 697:
#line 5031 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 698:
#line 5034 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 699:
#line 5043 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 700:
#line 5046 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 701:
#line 5049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 702:
#line 5052 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 703:
#line 5061 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 704:
#line 5064 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 705:
#line 5067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 706:
#line 5070 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 707:
#line 5073 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 708:
#line 5082 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 709:
#line 5085 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 710:
#line 5094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 711:
#line 5097 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 712:
#line 5106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 713:
#line 5109 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 714:
#line 5118 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5139 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 718:
#line 5142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 719:
#line 5151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 720:
#line 5154 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 721:
#line 5157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 722:
#line 5166 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 723:
#line 5169 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 724:
#line 5172 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 725:
#line 5175 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 726:
#line 5178 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 727:
#line 5187 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 728:
#line 5191 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 729:
#line 5195 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 730:
#line 5199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 731:
#line 5209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 732:
#line 5218 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 733:
#line 5228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 734:
#line 5237 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 735:
#line 5240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 736:
#line 5249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 737:
#line 5252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 738:
#line 5255 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 739:
#line 5264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 740:
#line 5267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 741:
#line 5276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6463 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -935;
  const short int
  xquery_parser::yypact_[] =
  {
      1237,  -935,  -935,  -935,  -935,  -109,   221,   374,   247,   425,
    5954,   -20,   493,   494,   111,  -935,  -935,   436,    91,  -935,
      85,   230,  -935,   179,  -935,  -935,  -935,   264,  -935,   354,
     388,   551,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
     560,  -935,   485,   492,  -935,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,  -935,  -935,  6195,  -935,  5221,  -935,  -935,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  7400,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,   542,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
    4225,  1486,  7400,  -935,  -935,  -935,  -935,  -935,  -935,   514,
    -935,  -935,  -935,   635,  -935,  5713,  -935,  -935,  -935,  -935,
    -935,  7400,  -935,  -935,  4972,  -935,  -935,  -935,  -935,  -935,
    -935,   521,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
      18,   460,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
     432,   534,   440,  -935,   478,   384,  -935,  -935,  -935,  -935,
    -935,  -935,   578,  -935,   554,   587,  -935,  -935,  -935,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,   687,  1735,  -935,  -935,   533,  4225,   520,   522,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,  -935,  -935,   603,  -935,  -935,  -935,  -935,   268,
    7400,  -935,  -935,  -935,  -935,  -935,   548,   620,  -935,   481,
     462,   315,    -2,   295,     4,  -935,   629,   523,   618,   619,
    4474,  -935,  -935,  -935,   -38,  -935,  -935,  4972,  -935,   290,
    -935,   570,  5221,  -935,   570,  5221,  -935,  -935,  -935,  -935,
     570,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,   571,
    -935,  4225,  -935,  4225,  4225,   573,   575,   576,  4225,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  4225,  6436,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,   579,  4225,  4225,
     545,  4225,   547,  7400,   675,   676,  7400,   -59,   -67,   695,
     -39,   148,   616,   262,   699,   395,    54,  4225,  -935,  4225,
      26,   586,    83,   204,  7400,   699,  7400,  4225,   468,   471,
    -935,   624,   626,  -935,  7400,    51,  4225,  6677,   598,   599,
     600,   601,   602,   604,  -935,  -935,  -935,  7400,  1984,   -21,
    -935,   -22,   713,  4225,    56,  -935,   725,   580,  -935,  4225,
     550,  -935,   726,  4225,  4225,   582,  4225,  4225,  4225,  4225,
     537,  7400,  4225,  7400,  -935,  -935,  -935,   111,    85,  -935,
    -935,   533,   714,  4225,   605,   264,   388,   551,   650,   609,
     610,  4225,  4225,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
     662,  -935,    -7,  4723,  4723,  4723,  -935,  4723,  4723,  -935,
    4723,  -935,  4723,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
    4723,  4723,    12,  4723,  4723,  4723,  4723,  4723,  4723,  4723,
    4723,  4723,  4723,  4723,   552,   684,   688,   689,  -935,  -935,
    -935,  2233,  -935,  -935,  4972,  4972,  4225,   570,  -935,  -935,
     570,  -935,   570,  2482,  -935,   606,   -24,  4225,  4225,  4225,
      -5,   -16,  -935,     1,    14,  2731,    24,   178,  -935,   212,
    -935,   633,  7400,  7400,   749,  -935,  -935,  -935,  -935,  -935,
    -935,   680,   682,  -935,  -935,  7400,   634,   636,   695,   667,
     665,  -935,  -935,  -935,   408,     0,   409,   758,  -935,  -935,
     309,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,   124,
     251,   614,  -935,   615,  2980,   699,   702,   750,   699,   695,
     703,    -9,  -935,   213,   672,   696,  -935,   -36,   623,  -935,
    -935,  7400,    10,  -935,   622,   599,   485,  -935,   625,   627,
     260,  -935,   156,   169,  3229,     3,  -935,   -13,  -935,  -935,
    7400,   713,  -935,   248,   267,  -935,  -935,  -935,  -935,   271,
    -935,    -1,  -935,  -935,  -935,    62,    84,   711,   572,   588,
     -23,  -935,   669,   632,   400,  -935,  -935,   628,  -935,    17,
    -935,  -935,   646,  7400,  4225,   701,  -935,  -935,   706,  7159,
     707,  4225,   708,   -74,   673,   -26,   620,  -935,  -935,  -935,
    -935,  -935,  4723,  -935,  -935,  -935,  4225,    12,   289,  -935,
     556,   504,   568,   574,  -935,  -935,   584,   325,    -2,    -2,
     -30,   295,   295,   295,   295,     4,     4,  -935,  -935,  7159,
    7159,  7400,  7400,  -935,   279,  -935,  -935,   173,  -935,  -935,
    -935,   183,   683,  -935,   281,   291,   294,   729,   691,  7400,
    -935,  7400,  -935,  -935,   296,  -935,  -935,  -935,   201,   416,
     633,   633,  -935,   324,   371,     5,   695,   695,  -935,   473,
     695,  -935,  -935,   559,  -935,  -935,   577,   441,  -935,  -935,
    -935,  -935,  -935,  -935,   581,  -935,  -935,   640,   694,  -935,
    -935,  -935,   302,   715,   695,   690,   716,   751,   695,   731,
    4225,  4225,   709,   695,   732,  4225,   717,   -44,  -935,   351,
     608,  -935,  -935,   480,    10,  -935,  -935,  -935,   704,  7400,
    -935,  7400,  -935,  -935,   308,  4225,  -935,   815,  -935,   321,
    -935,   133,  -935,  -935,   827,  -935,   438,  4225,  4225,  4225,
     442,  4225,  4225,  4225,  4225,  4225,  4225,   748,  4225,  4225,
     630,   718,   752,   714,  4225,  -935,   443,   761,  -935,  7400,
     763,  -935,  7400,   719,   721,  -935,   303,  -935,  -935,  -935,
    7400,  -935,  7400,  4225,   734,  4225,  4225,   -68,   737,  -935,
     314,   693,  -935,   642,  -935,    73,  -935,   348,    19,   644,
      12,   348,  4723,  4723,   617,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,    12,   739,    19,  -935,   621,   817,  -935,  -935,
    -935,  -935,  -935,   747,  -935,  -935,  -935,  4225,  -935,  -935,
    -935,  -935,  -935,  6918,   193,  -935,  3478,   720,   723,   754,
     724,   727,  -935,  7400,   799,   191,  -935,  -935,  4225,  -935,
     437,   683,  -935,  -935,  -935,  -935,  -935,  4225,   497,  -935,
    -935,  -935,  -935,  -935,   637,   336,   859,  -935,   448,  -935,
    -935,  4225,  3727,  -935,   695,   790,  -935,  -935,  -935,   695,
     790,  7400,  -935,  -935,  4225,   712,  7400,  -935,  4225,  4225,
     760,  4225,   764,  -935,   784,   786,  4225,  7400,   553,   829,
    -935,  -935,  -935,  3976,   730,  -935,   733,  -935,  -935,  -935,
     782,  -935,   181,  -935,  -935,   890,  -935,  -935,  4225,  7400,
    -935,  -935,   392,  -935,  -935,  -935,   728,   686,   692,  -935,
    -935,  -935,   697,   698,  -935,  -935,  -935,  -935,  -935,   685,
    7400,   736,  -935,   766,   630,  -935,  4225,  7400,   761,  -935,
     695,  -935,   549,  -935,   366,   814,  -935,  4225,   818,   701,
    -935,   741,   743,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
    4225,  -935,  -935,  4225,   778,  4225,  -935,  -935,  4723,  -935,
    -935,  -935,  -935,  -935,   363,  4723,  4723,   344,  -935,   568,
    -935,  -935,   163,  4723,  -935,  -935,   574,    12,   660,  -935,
    -935,  -935,  -935,  7400,   755,   -12,  -935,  -935,   317,  -935,
    -935,  -935,  -935,  -935,   836,  7159,   816,   837,   318,  -935,
    -935,  -935,  -935,  -935,  4225,   -17,   895,   898,   -17,   -15,
     197,   203,   819,  -935,   319,   841,   695,   790,  -935,  -935,
    -935,  -935,  -935,  -935,  4225,  -935,  4225,  7400,  7400,  -935,
     496,  -935,  4225,  -935,   340,  -935,  -935,   815,  7400,   426,
    -935,   357,   815,  7400,  -935,  -935,  4225,  4225,  4225,  4225,
    4225,  -935,  4225,  5470,  -935,   759,  -935,  -935,  -935,  -935,
     814,  -935,  -935,  -935,   695,  -935,  -935,  -935,  -935,  -935,
    -935,  4225,  -935,   295,  4723,  4723,   295,   372,  -935,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,   845,  4225,  7400,  4225,
    -935,  -935,  -935,  -935,  7159,  -935,  -935,   336,   336,   -17,
    -935,  -935,  -935,    23,   -17,   903,   700,   847,  -935,   847,
    -935,  4225,  -935,   695,  -935,  -935,  -935,   864,  -935,  -935,
    -935,  -935,    -3,   815,  7400,  -935,   756,   815,  -935,  -935,
    -935,  -935,  -935,  -935,   215,  -935,  -935,  -935,  -935,   295,
     295,  4723,  7159,  -935,   765,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,    19,  -935,   220,  -935,   222,  -935,   790,   830,
      71,    68,  -935,   757,   815,  -935,   762,   833,   795,   295,
     770,  4225,   705,   847,  -935,  -935,  7400,  -935,  -935,   860,
     159,  -935,  -935,  -935,  -935,   774,   223,  -935,  -935,  -935,
     767,  -935,  7400,  -935,  4225,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,   226,  -935,   838,   795,
    7400,  -935,   229,   840,   795,  7400,  -935,   776,   795,  -935
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   315,   316,   494,   462,     0,     0,     0,   581,   507,
     499,   515,   506,   497,   593,   602,   639,   501,   503,   530,
     600,   563,   557,     0,   598,   527,   601,   553,   594,     0,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   595,
       0,   511,   505,   498,   597,   572,   504,   509,   306,   309,
     571,   567,   558,   540,   496,   296,     0,   566,   574,   582,
     294,   562,   332,   541,   596,   295,   298,   559,   576,     0,
     338,   304,   334,   569,   495,   560,   561,   589,   564,   580,
     588,   300,   299,   514,   552,   591,   333,   579,   584,   500,
       0,     0,     0,   253,   577,   587,   592,   590,   570,   640,
     556,   555,   305,     0,   252,     0,   308,   307,   585,   542,
     565,     0,   297,   282,     0,   314,   586,   568,   575,   583,
     578,   641,   534,   539,   538,   537,   536,   535,   508,   554,
       0,     0,   599,   528,   631,   630,   632,   513,   512,   531,
     637,   502,   629,   634,   635,   626,   533,   573,   628,   638,
     636,   627,   532,   633,     0,     0,   618,   617,   517,   510,
     519,   518,   611,   607,   525,   529,   526,   620,   621,   604,
     516,   616,   615,   612,   608,   625,   619,   614,   610,   603,
     624,   623,   609,   613,   605,   606,   520,   521,   523,   622,
     522,   524,     0,     0,     2,     4,     0,     0,     0,     0,
      15,    17,    19,    20,    21,    27,    22,    25,    26,    31,
      32,    33,    28,    29,    35,    36,    23,    30,   112,   109,
     110,   111,    24,     9,    94,    95,    97,   127,   133,     0,
       0,   125,   126,    98,    99,   100,   101,   209,   211,   213,
     223,   226,   228,   231,   236,   239,   242,   244,   246,   248,
       0,   250,   256,   258,     0,   274,   257,   278,   281,   283,
     286,   288,     0,   293,   290,     0,   301,   311,   313,   287,
     317,   322,   330,   323,   324,   325,   328,   329,   326,   327,
     345,   347,   348,   349,   346,   394,   395,   396,   397,   398,
     399,   310,   436,   428,   435,   434,   433,   430,   432,   429,
     431,   331,    34,   102,   103,   105,   104,   106,   107,   312,
     108,     0,    81,     0,     0,     0,     0,     0,     0,   581,
     507,   499,   515,   506,   497,   593,   501,   503,   600,   563,
     553,   543,   544,   505,   498,   496,   564,     0,     0,   640,
     641,   637,   502,   629,   635,   626,   532,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   493,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,     0,     0,    82,     0,     0,     0,     0,     0,   499,
     506,   497,   503,   496,   302,   312,   335,     0,     0,     0,
     336,     0,   361,     0,     0,   277,     0,     0,   280,     0,
       0,   390,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     3,     5,     0,     0,    10,
       8,    12,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,   132,   128,   134,   129,   131,   130,
     137,   138,     0,     0,     0,     0,   267,     0,     0,   265,
       0,   218,     0,   266,   259,   264,   263,   262,   261,   260,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   254,
     251,     0,   275,   279,     0,     0,     0,   289,   319,   292,
     291,   303,   318,     0,    79,     0,     0,     0,     0,     0,
       0,     0,   452,     0,     0,     0,     0,     0,   441,     0,
     442,     0,     0,     0,     0,    70,    71,    44,    45,   492,
      53,     0,     0,    38,    39,     0,     0,     0,     0,     0,
       0,   463,   464,   465,     0,     0,     0,     0,   680,   681,
       0,    43,   673,   674,   675,   676,   677,   678,   679,     0,
       0,     0,   443,     0,     0,     0,    62,     0,     0,     0,
      54,     0,   198,     0,     0,   150,   151,     0,     0,   115,
     116,     0,     0,   136,     0,     0,     0,   438,     0,     0,
       0,   446,     0,     0,     0,     0,    76,     0,    77,   337,
     362,   361,   358,     0,     0,   392,   391,   276,   451,     0,
     389,     0,   476,   477,   437,     0,     0,     0,     0,     0,
       0,   482,     0,     0,     0,   153,   170,     0,    16,     0,
      18,    96,     0,     0,     0,     0,   114,   171,     0,     0,
       0,     0,     0,     0,     0,     0,   210,   212,   216,   222,
     221,   220,     0,   217,   214,   215,     0,     0,     0,   665,
     224,   644,   652,   654,   656,   658,   660,   663,   230,   229,
     227,   233,   234,   235,   232,   237,   238,   241,   240,     0,
       0,     0,     0,   272,     0,   284,   285,     0,   320,   341,
     343,     0,     0,   268,     0,     0,     0,     0,     0,     0,
     456,     0,   453,   401,     0,   400,   409,   410,     0,     0,
       0,     0,    42,     0,     0,     0,     0,     0,    52,     0,
       0,   682,   683,     0,   684,   688,     0,     0,   717,   686,
     687,   716,   685,   689,     0,   696,   718,     0,     0,   445,
     444,   411,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   643,     0,
       0,   117,   118,     0,   123,   459,   439,   440,     0,     0,
     449,     0,   447,   405,     0,     0,    78,   361,   359,     0,
     350,     0,   339,   340,     0,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,   124,   182,   178,   180,     0,
     172,   173,     0,   500,   508,   417,   418,   424,   425,   427,
       0,   140,     0,     0,     0,     0,     0,     0,     0,   219,
       0,     0,   659,     0,   225,     0,   672,     0,     0,     0,
       0,     0,     0,     0,   645,   649,   667,   648,   671,   669,
     668,   670,     0,     0,     0,   661,   724,   722,   726,   664,
     243,   245,   247,   415,   249,   273,   321,     0,   342,    80,
     269,   270,   271,     0,     0,   204,     0,     0,     0,   460,
       0,     0,   402,     0,    72,     0,    88,    83,     0,    84,
       0,     0,    50,    51,    48,    49,    67,     0,     0,    40,
      41,    46,    47,    37,     0,     0,     0,   691,     0,   690,
     707,     0,     0,   412,     0,    64,    58,    61,    60,     0,
      56,     0,   196,   200,     0,     0,     0,   155,     0,     0,
       0,     0,     0,   119,     0,     0,     0,     0,   164,     0,
     161,   166,   122,     0,     0,   460,     0,   406,   197,   362,
       0,   351,     0,   385,   382,     0,   386,   387,     0,     0,
     388,   381,     0,   356,   384,   383,     0,     0,     0,   469,
     470,   466,     0,     0,   474,   475,   471,   480,   478,     0,
       0,     0,   484,     0,   485,   486,     0,     0,   179,   191,
       0,   192,     0,   183,   184,   185,   186,     0,   175,     0,
     139,     0,     0,   421,   423,   422,   419,   148,   149,   142,
       0,   144,   141,     0,     0,     0,   666,   662,     0,   719,
     720,   740,   739,   735,     0,     0,     0,     0,   721,   653,
     734,   646,     0,     0,   651,   650,   655,     0,     0,   725,
     723,   416,   344,     0,     0,     0,   205,   403,     0,   457,
     458,   461,   454,   455,    90,     0,     0,    73,     0,    85,
      86,    87,    66,    69,     0,   705,     0,     0,   703,   699,
       0,     0,     0,   413,     0,    63,     0,    57,   199,   201,
      11,   152,   157,   156,     0,   159,     0,     0,     0,   121,
     162,   165,     0,   407,     0,   450,   448,   361,     0,     0,
     393,     0,   361,     0,   357,     7,     0,     0,     0,     0,
       0,   483,     0,     0,   487,     0,   154,   195,   193,   194,
     187,   188,   189,   181,     0,   176,   174,   426,   420,   146,
     143,     0,   145,   741,     0,     0,   727,     0,   738,   737,
     736,   731,   732,   647,   657,   733,     0,     0,     0,     0,
     404,    91,    74,    89,     0,    93,    68,     0,     0,   706,
     708,   710,   712,     0,   704,     0,     0,     0,   694,     0,
     692,     0,   414,     0,    59,   158,   160,   169,   168,   163,
     120,   408,     0,   361,     0,    92,     0,   361,   467,   468,
     472,   473,   479,   481,     0,   642,   190,   177,   147,   729,
     728,     0,     0,   206,     0,   202,    75,   715,   714,   709,
     713,   711,   700,   701,     0,   697,     0,   208,    65,     0,
     371,   365,   360,     0,   361,   352,     0,     0,     0,   730,
       0,     0,     0,     0,   695,   693,     0,   379,   373,     0,
     372,   374,   380,   377,   367,     0,   366,   368,   378,   354,
       0,   353,     0,   488,     0,   203,   702,   698,   167,   364,
     375,   376,   363,   369,   370,   355,     0,   207,     0,     0,
       0,   489,     0,     0,     0,     0,   490,     0,     0,   491
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -935,  -935,  -935,   753,   768,  -935,   771,  -935,   513,   516,
    -407,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,  -935,  -935,  -735,  -935,  -935,  -935,  -935,   -52,
    -664,  -935,  -935,  -935,  -935,  -935,  -935,  -111,  -935,  -880,
     769,   -72,  -289,  -935,  -935,  -935,  -935,   184,  -935,  -935,
     722,  -935,  -935,  -935,  -935,  -935,   138,  -419,  -554,  -935,
    -935,  -935,    27,  -935,  -935,  -138,    16,   -32,  -935,  -935,
    -935,   -43,  -935,  -935,   153,   -37,  -935,  -935,   -35,  -934,
    -935,   561,    41,  -935,  -935,    89,  -935,  -935,   511,   515,
    -935,  -423,  -789,   498,   200,  -474,   195,   196,  -935,  -935,
    -935,  -935,  -935,   735,  -935,  -935,  -935,  -935,  -935,   738,
    -935,  -935,   -93,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
     -29,  -145,  -935,  -935,   218,   107,  -935,  -464,  -935,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  -755,  -935,    20,
    -935,   370,  -581,  -935,  -935,  -935,  -935,  -935,  -272,  -265,
    -904,  -756,  -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,
    -935,  -935,   297,  -561,  -673,  -935,  -935,     2,  -630,  -935,
    -935,  -935,  -935,  -935,  -935,  -935,   591,   593,  -330,   280,
    -935,  -935,  -935,  -935,  -935,  -935,  -935,  -935,     6,  -935,
    -935,    -4,  -358,  -334,   -10,  -935,   326,  -935,  -935,   142,
     132,   -50,   330,  -935,  -935,   145,  -935,  -632,  -935,  -935,
    -935,  -935,  -179,  -716,  -935,   -77,  -477,  -935,  -544,  -935,
    -935,  -935,  -935,  -837,  -935,  -935,  -935,  -935,   -34,   152,
    -935
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   915,   569,   215,   216,   217,   709,
     218,   398,   219,   220,   221,   222,   885,   886,   960,   889,
     223,   224,   225,   226,   443,   381,   763,   764,   227,   444,
     228,   446,   229,   230,   231,   450,   451,   938,   644,   232,
     575,   624,   576,   582,   939,   940,   941,   625,   447,   448,
     810,   811,  1125,   449,   807,   808,   993,   994,   995,   996,
     233,   571,   572,   234,   874,   875,   235,   236,   237,   238,
     652,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   470,   471,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   497,   498,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   691,   279,   280,   281,   962,
     601,   602,   603,  1222,  1245,  1246,  1239,  1240,  1247,  1241,
     963,   964,   282,   283,   965,   284,   285,   286,   287,   288,
     289,   290,   862,   645,   815,  1006,   816,   817,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   877,   878,
     301,   302,   303,   304,   305,   306,   307,   620,   621,   308,
     984,   985,   916,   371,   309,   310,   660,   844,   661,   662,
     663,   664,   665,   666,   667,   845,   846,   551,   552,   553,
     554,   555,  1214,  1215,   556,  1159,  1068,  1163,  1160,   557,
     558,   848,   859,  1027,   849,   850,   855,   851,  1141,  1023,
     834
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       347,   530,   671,   672,   673,   674,   860,   861,   659,   818,
    1060,   909,   752,   920,   566,   570,   757,  1038,   399,   401,
     779,   408,   504,   756,   505,   630,   961,   394,   869,   847,
     540,     4,   648,   643,   649,   650,   563,   651,   410,   653,
     639,   574,  1210,   368,   388,   561,   395,   654,   655,   818,
     818,   823,   640,  1031,   353,   354,   355,  1013,  1104,   396,
    1121,  1122,   605,  1024,   356,   433,   797,   433,   433,   639,
     760,   640,  1220,   433,  1237,   953,   433,   929,   953,   527,
     749,   639,   402,   585,   433,   755,  1243,  1148,   578,   824,
     699,   828,   749,   491,   723,   406,   476,  1024,  1157,   826,
     525,   407,   529,   701,    62,   531,   473,   311,   368,   784,
     362,   348,   528,   433,   526,    72,   105,   586,   641,   482,
     532,   896,   477,   474,   612,   613,   897,   615,   616,   617,
     618,   372,   483,   623,   373,   478,   544,   693,   786,    86,
     953,   954,   599,   656,   631,   698,   657,   598,   353,   354,
     355,  1149,   636,   637,   898,   776,   750,  1221,   356,   697,
     790,  1158,  1237,   357,   493,   700,   953,   785,   775,   479,
     956,   642,   957,   956,   358,   957,   359,   642,   702,   360,
     718,  1244,   361,  1238,  1077,   705,  1196,  1211,   953,   954,
     562,   798,  1071,   659,   659,  1104,   950,   961,   932,   958,
    1044,   642,   958,   930,   362,   363,   761,   961,   606,   642,
     411,   747,  1035,   433,   690,   587,  1025,  1026,   955,   642,
     452,   565,   369,   529,   724,   370,   827,  1061,  1165,   829,
     953,   743,  1166,   499,   746,   956,   501,   957,   642,   762,
     366,  1243,   506,   818,  1143,   769,   510,   658,   312,   364,
    1025,  1026,   395,   725,   726,   395,   727,   728,   771,   787,
     788,   956,   433,   957,   958,   511,   955,   433,    92,  1019,
     545,  1260,   867,  1014,   789,   873,   516,   517,   546,   519,
    1056,   791,   792,   956,   103,   957,  1167,  1045,   737,   639,
     958,   547,  1169,   548,   536,   559,   793,   560,   567,   537,
     883,   433,  1020,   549,  1227,   959,   550,   533,     4,  1233,
     365,  1233,   958,   434,   590,  1268,    92,   375,  1273,   435,
     770,   534,   436,   437,   130,   956,   597,   957,   514,   374,
     438,   604,   103,   772,   366,   866,  1263,   609,   751,   706,
     433,   480,   568,   521,   961,   806,   524,   868,  1253,   433,
     538,   481,   821,  1098,   958,  1057,   433,   780,   899,   900,
     433,  1168,   903,   376,   573,   884,   577,  1170,   433,  1032,
     433,   880,   130,   707,   584,  1232,   659,   593,   314,  1228,
     433,    62,  1152,   433,  1234,   433,  1235,   573,   659,  1271,
    1269,   433,    72,  1274,  1276,   925,   630,   433,  1279,   953,
     954,   685,   686,   433,  1138,  1134,   433,   433,   433,   539,
    1139,   622,   738,   626,  1066,   439,    86,   440,  1140,   684,
     656,   768,   781,   657,   687,   818,  1003,   639,   782,   433,
     951,   441,   783,   953,   954,   694,   695,   696,  1218,   944,
     865,   946,   870,   704,   378,   379,   433,   315,   316,   317,
     892,   473,   871,   801,   990,   872,  1004,   882,   442,   494,
     495,   922,   923,   913,  1242,  1248,   927,   893,   474,   947,
    1067,  1135,   992,   480,  1005,  1016,   931,   955,  1150,  1155,
    1172,  1206,   500,   481,  1242,   377,   948,   380,   502,   802,
    1248,   475,   742,  1151,   956,   952,   957,   894,   969,   970,
     971,  1181,   974,   975,   976,   977,   978,   979,   313,   981,
     982,   955,   710,   711,   895,   806,  1182,  1257,  1185,   906,
     989,  1186,   774,   958,   818,   715,   906,    92,   956,  1230,
     957,   990,   887,   732,  1009,   907,  1011,  1012,   934,   935,
     991,   936,  1070,   103,  1133,   856,   857,   888,  1201,   992,
     480,  1136,  1137,  1059,   934,   935,  1075,   958,   640,   318,
     481,    92,   733,   734,  1103,   735,   736,   858,   888,   427,
     367,   759,   818,   659,   640,   908,   428,   103,  1042,   937,
     901,   902,   835,   130,   830,  1138,   544,   383,   419,  1021,
     777,  1139,   455,   420,  1022,   541,   542,   543,  1184,  1140,
     456,   457,  1223,   458,   688,   382,  1226,   688,  1062,   688,
     459,   934,   935,  1063,   460,  1209,   461,   130,  1064,   384,
    1209,   462,  1072,   805,   349,   351,   385,   350,   352,   819,
     721,   729,  1117,   722,   730,  1079,   413,   463,   414,  1082,
    1083,   397,  1085,  1250,   416,   403,   417,  1089,   404,   967,
     836,   968,   409,   972,   412,   973,  1118,  1119,   890,   891,
    1199,  1200,   464,   465,   466,   467,   468,   469,   415,   819,
     819,   819,   819,   668,   669,   675,   676,   421,   677,   678,
    1207,  1208,   418,   863,   863,   422,   423,   424,   431,   879,
     432,   879,   433,   453,   454,   835,   472,  1115,   484,   544,
     485,   486,   496,   487,   507,   503,   508,   509,   806,   518,
     515,   520,   522,   523,   529,   535,   368,   564,  1174,   579,
     545,  1129,   580,   581,  1130,   583,  1132,  1229,   546,   594,
     837,   838,   839,   338,   350,   352,   370,   600,   387,   607,
     840,   547,   610,   548,   608,   611,   614,   619,   841,   633,
     629,   638,   632,   549,   842,   843,   550,   634,   635,   945,
     680,   945,   679,   836,   681,   682,  1197,   708,   712,   713,
     692,   714,   716,   719,   717,  1156,   720,   731,   739,   740,
     744,   748,   745,   753,   758,   754,   765,   794,   795,   766,
     799,   767,   796,   800,   804,  1175,   803,  1176,   825,   998,
     809,   852,   452,  1180,  1048,   812,   820,   822,   833,   853,
    1007,   873,  1008,   904,    90,   911,  1058,  1188,  1189,  1190,
    1191,  1192,   876,  1193,   854,   912,   914,   918,   917,   919,
     921,   926,   905,   545,   924,   943,   910,   933,   928,   949,
    1074,   546,  1198,   837,   838,   839,   966,   980,   983,   986,
     997,   987,   999,  1001,   547,  1002,   548,  1017,  1203,  1010,
    1205,   841,  1015,   819,  1037,  1040,   549,  1033,   843,   550,
    1041,  1094,  1018,  1054,  1028,  1055,  1039,  1051,  1069,  1076,
    1080,  1084,  1217,  1087,  1049,  1088,  1101,  1050,  1052,  1086,
    1092,  1053,  1065,  1097,  1095,  1100,  1105,  1096,  1106,  1112,
    1113,  1110,   990,  1131,  1107,  1127,  1124,  1128,  1145,  1108,
    1109,   573,   639,  1154,  1161,   883,   577,  1162,  1147,  1173,
    1195,  1202,  1212,  1219,  1171,   906,   888,  1090,  1231,  1236,
    1225,  1249,  1252,  1254,  1262,  1259,  1251,  1270,  1213,  1275,
    1278,  1265,  1255,  1256,   627,  1153,   425,   628,   942,  1102,
    1000,   445,  1179,  1081,  1091,  1116,  1126,   988,   595,  1120,
    1123,   426,  1078,  1046,   646,  1267,   430,   429,  1194,   647,
     622,   778,  1099,   670,  1264,  1261,   588,   626,   589,   864,
    1114,   881,  1029,   831,  1036,   490,  1111,  1144,   832,  1034,
    1216,  1164,   492,  1030,     0,     0,     0,     0,  1142,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   819,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1177,  1178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1183,     0,
       0,     0,     0,  1187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   395,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1204,     0,
       0,     0,     0,     0,   819,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   819,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1266,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
    1272,     0,     5,     6,     0,  1277,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,    27,    28,
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
     104,   105,     0,     0,   106,   107,   108,     0,     0,     0,
     109,     0,   110,   111,   112,     0,   113,   114,   115,     0,
     116,     0,   117,   118,   119,   120,   121,     0,   122,   123,
     124,   125,   126,   127,     0,     0,   128,   129,   130,     0,
     131,   132,     0,   133,   134,   135,   136,   137,   138,   139,
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
     105,     0,     0,   106,   107,   108,     0,     0,     0,   109,
     400,   110,   111,   112,     0,   113,   114,   115,     0,   116,
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
      13,    14,    15,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     0,    27,    28,    29,    30,
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
       0,     0,   106,   107,   108,     0,     0,     0,   109,     0,
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
       0,   106,   107,   108,     0,   596,     0,   109,     0,   110,
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
     106,   107,   108,     0,   683,     0,   109,     0,   110,   111,
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
     107,   108,     0,     0,     0,   109,   689,   110,   111,   112,
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
     108,     0,   703,     0,   109,     0,   110,   111,   112,     0,
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
       0,   741,     0,   109,     0,   110,   111,   112,     0,   113,
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
     773,     0,   109,     0,   110,   111,   112,     0,   113,   114,
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
       0,   104,   105,     0,     0,   106,   107,   108,     0,  1047,
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
     104,   105,     0,     0,   106,   107,   108,     0,  1073,     0,
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
     105,     0,     0,   106,   107,   108,     0,  1093,     0,   109,
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
       0,     0,   106,   107,   108,     0,     0,     0,   109,     0,
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
       2,     3,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,   320,    10,    11,    12,    13,
     325,    15,    16,     0,   326,    18,    19,   328,   329,    22,
       0,    24,    25,    26,     0,   330,    28,     0,   331,   332,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,     0,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    60,    61,     0,     0,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,     0,    73,
      74,    75,    76,     0,    77,     0,     0,     0,   336,    79,
      80,    81,    82,     0,     0,     0,     0,     0,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    91,    92,
     488,    94,    95,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,     0,   102,   103,     0,   489,   105,     0,
       0,   106,   107,   108,     0,     0,     0,   109,     0,   110,
     111,   112,     0,   113,   114,   115,     0,   116,     0,   117,
     118,   119,   120,   121,     0,   122,   123,   124,   125,   126,
     127,     0,     0,   128,   129,   130,     0,     0,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   341,   141,   343,
     143,   344,   345,   146,   147,   148,   149,   150,   151,   346,
     153,     0,     0,     0,   156,   157,   158,   159,   160,   161,
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
      86,    87,    88,    89,     0,     0,     0,    91,    92,    93,
      94,    95,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,     0,   102,   103,     0,   104,   105,     0,     0,
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
       0,     0,   319,   320,    10,    11,    12,    13,   325,    15,
      16,     0,   326,    18,    19,   328,   329,    22,     0,    24,
      25,    26,     0,   330,    28,     0,   331,   332,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,     0,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
      61,     0,     0,     0,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,     0,    73,    74,    75,
      76,     0,    77,     0,     0,     0,   336,    79,    80,    81,
      82,     0,     0,     0,     0,     0,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    91,    92,     0,    94,
      95,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,     0,   102,   103,     0,     0,     0,     0,     0,   106,
     107,   108,     0,     0,     0,   109,     0,   110,   111,   112,
       0,     0,     0,   115,     0,   116,     0,   117,   118,   119,
     120,   121,     0,   122,   123,   124,   125,   126,   127,     0,
       0,   128,   129,   130,     0,     0,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   341,   141,   343,   143,   344,
     345,   146,   147,   148,   149,   150,   151,   346,   153,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,     0,   169,   170,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   319,   320,   389,   322,   390,   391,   325,    15,    16,
       0,   326,   392,    19,   328,   329,    22,     0,    24,    25,
      26,     0,   330,    28,     0,   331,   332,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    41,    42,    43,    44,
      45,    46,    47,     0,     0,    50,     0,    51,    52,    53,
     393,     0,     0,    57,    58,    59,     0,     0,     0,    61,
       0,     0,     0,     0,    63,    64,     0,     0,    67,    68,
       0,     0,     0,     0,     0,     0,    73,    74,    75,    76,
       0,    77,     0,     0,     0,   336,    79,    80,     0,     0,
       0,     0,     0,     0,     0,    83,    84,    85,     0,    87,
      88,    89,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,    96,    97,    98,   339,   100,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,   109,     0,   110,   111,     0,     0,
       0,     0,   115,     0,   116,     0,   117,   118,   119,   120,
     340,     0,   122,   123,   124,   125,   126,   127,     0,     0,
     128,   129,     0,     0,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   341,   141,   343,   143,   344,   345,
     146,   147,   148,   149,   150,   151,   346,   153,     0,     0,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,     0,   169,   170,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     319,   320,   321,   322,   323,   324,   325,    15,    16,     0,
     326,   327,    19,   328,   329,    22,     0,    24,    25,    26,
       0,   330,    28,     0,   331,   332,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    41,   333,   334,    44,    45,
      46,    47,     0,     0,    50,     0,    51,    52,    53,   335,
       0,     0,    57,    58,    59,     0,     0,     0,    61,     0,
       0,     0,     0,    63,    64,     0,     0,    67,    68,     0,
       0,     0,     0,     0,     0,    73,    74,    75,    76,     0,
      77,     0,     0,     0,   336,    79,    80,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,     0,    87,    88,
      89,     0,     0,     0,     0,     0,     0,    94,    95,     0,
       0,     0,     0,    96,    97,    98,   339,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,   109,     0,   110,     0,     0,     0,     0,
       0,   115,     0,   116,     0,   117,   118,   119,   120,   340,
       0,   122,   123,   124,   125,   126,   127,     0,     0,   128,
     129,     0,     0,     0,   132,     0,   133,   134,   135,   136,
     137,   138,   139,   341,   342,   343,   143,   344,   345,   146,
     147,   148,   149,   150,   151,   346,   153,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,     0,   169,   170,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   405,     0,
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
       0,    87,    88,    89,     0,     0,     0,     0,     0,     0,
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
      85,     0,    87,    88,    89,   337,     0,     0,   338,     0,
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
      84,    85,     0,    87,    88,    89,   386,     0,     0,   387,
       0,     0,    94,    95,     0,     0,     0,     0,    96,    97,
      98,   339,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,   109,     0,
     110,     0,     0,     0,     0,     0,     0,     0,   116,     0,
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
     512,   110,     0,     0,     0,     0,     0,   513,     0,   116,
       0,   117,   118,   119,   120,   340,     0,   122,   123,   124,
     125,   126,   127,     0,     0,   128,   129,     0,     0,     0,
     132,     0,   133,   134,   135,   136,   137,   138,   139,   341,
     342,   343,   143,   344,   345,   146,   147,   148,   149,   150,
     151,   346,   153,     0,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,     0,
     169,   170,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   319,   320,   321,
     322,   323,   324,   325,    15,    16,     0,   326,   327,    19,
     328,   329,    22,     0,    24,    25,    26,     0,   330,    28,
       0,   331,   332,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    41,   333,   334,    44,    45,    46,    47,     0,
       0,    50,     0,    51,    52,    53,   335,     0,     0,    57,
      58,    59,     0,     0,     0,    61,     0,     0,     0,     0,
      63,    64,     0,     0,    67,    68,     0,     0,     0,     0,
       0,     0,    73,    74,    75,    76,     0,    77,     0,     0,
       0,   336,    79,    80,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    85,     0,    87,    88,    89,     0,     0,
       0,     0,     0,     0,    94,    95,     0,     0,     0,     0,
      96,    97,    98,   339,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
     109,   591,   110,     0,     0,     0,     0,     0,   592,     0,
     116,     0,   117,   118,   119,   120,   340,     0,   122,   123,
     124,   125,   126,   127,     0,     0,   128,   129,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     341,   342,   343,   143,   344,   345,   146,   147,   148,   149,
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
       0,    63,    64,     0,     0,    67,    68,  1043,     0,     0,
       0,     0,     0,    73,    74,    75,    76,     0,    77,     0,
       0,     0,   336,    79,    80,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,     0,    87,    88,   813,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,    96,    97,    98,   339,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,   109,     0,   110,   111,     0,     0,     0,     0,     0,
       0,   116,     0,   117,   118,   119,   120,   340,     0,   122,
     123,   124,   125,   126,   127,     0,     0,   814,   129,     0,
       0,     0,   132,     0,   133,   134,   135,   136,   137,   138,
     139,   341,   141,   343,   143,   344,   345,   146,   147,   148,
     149,   150,   151,   346,   153,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,     0,   169,   170,     0,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
     320,   389,   322,   390,   391,   325,    15,    16,     0,   326,
     392,    19,   328,   329,    22,     0,    24,    25,    26,     0,
     330,    28,     0,   331,   332,    32,    33,    34,    35,    36,
      37,    38,    39,     0,    41,    42,    43,    44,    45,    46,
      47,     0,     0,    50,     0,    51,    52,    53,   393,     0,
       0,    57,    58,    59,     0,     0,     0,    61,     0,     0,
       0,     0,    63,    64,     0,     0,    67,    68,     0,     0,
       0,     0,     0,     0,    73,    74,    75,    76,     0,    77,
       0,     0,     0,   336,    79,    80,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,     0,    87,    88,   813,
       0,     0,     0,     0,     0,     0,    94,    95,     0,     0,
       0,     0,    96,    97,    98,   339,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,   109,     0,   110,   111,     0,     0,     0,     0,
       0,     0,   116,     0,   117,   118,   119,   120,   340,     0,
     122,   123,   124,   125,   126,   127,     0,     0,   814,   129,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   341,   141,   343,   143,   344,   345,   146,   147,
     148,   149,   150,   151,   346,   153,     0,     0,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,     0,   169,   170,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     319,   320,   321,   322,   323,   324,   325,    15,    16,     0,
     326,   327,    19,   328,   329,    22,     0,    24,    25,    26,
       0,   330,    28,     0,   331,   332,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    41,   333,   334,    44,    45,
      46,    47,     0,     0,    50,     0,    51,    52,    53,   335,
       0,     0,    57,    58,    59,     0,     0,     0,    61,     0,
       0,     0,     0,    63,    64,     0,     0,    67,    68,     0,
       0,     0,     0,     0,     0,    73,    74,    75,    76,     0,
      77,     0,     0,     0,   336,    79,    80,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,     0,    87,    88,
      89,     0,     0,     0,     0,     0,     0,    94,    95,     0,
       0,     0,     0,    96,    97,    98,   339,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,   109,     0,   110,     0,     0,     0,     0,
       0,     0,     0,   116,     0,   117,   118,   119,   120,   340,
       0,   122,   123,   124,   125,   126,   127,     0,     0,   128,
     129,     0,     0,     0,   132,     0,   133,   134,   135,   136,
     137,   138,   139,   341,   342,   343,   143,   344,   345,   146,
     147,   148,   149,   150,   151,   346,   153,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,     0,   169,   170,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        10,   359,   476,   477,   478,   479,   679,   680,   472,   639,
     890,   727,   573,   748,   372,   373,   577,   854,    90,    91,
     601,   114,   311,   577,   313,   432,   781,    56,   692,   661,
     364,    19,   455,   452,   457,   458,   370,   460,    20,   462,
      76,   375,    19,    17,    54,    19,    56,   470,   471,   679,
     680,   125,    78,   842,    37,    38,    39,   125,   962,    69,
     994,   995,     6,    78,    47,    89,    89,    89,    89,    76,
      60,    78,    75,    89,     3,     7,    89,   121,     7,   146,
      89,    76,    92,    32,    89,   121,    18,    99,   377,   643,
      89,   645,    89,   131,    94,   105,    98,    78,   115,   125,
     159,   111,    19,    89,    92,   144,   136,   216,    17,   110,
      93,   131,   179,    89,   173,   103,   154,    66,   125,   115,
     159,   116,   124,   153,   413,   414,   121,   416,   417,   418,
     419,    46,   128,   422,    49,   137,    82,   161,    76,   127,
       7,     8,   164,   131,   433,   161,   134,   168,    37,    38,
      39,   163,   441,   442,   715,   168,   165,   160,    47,   164,
      76,   178,     3,    52,   257,   164,     7,   168,   165,   171,
     102,   245,   104,   102,    63,   104,    65,   245,   164,    68,
     538,   113,    71,   112,   919,   161,  1120,   164,     7,     8,
     164,   214,   908,   657,   658,  1099,   777,   952,   759,   131,
     873,   245,   131,   757,    93,    94,   196,   962,   152,   245,
     192,   569,   844,    89,   503,   164,   231,   232,    85,   245,
     230,   138,   131,    19,   224,   134,   645,   891,   243,   652,
       7,   565,  1069,   262,   568,   102,   265,   104,   245,   229,
     223,    18,   314,   873,  1033,    89,   318,   235,    27,   138,
     231,   232,   262,   253,   254,   265,   256,   257,    89,   197,
     198,   102,    89,   104,   131,   337,    85,    89,   135,   196,
     216,   112,    89,   827,   212,    82,   348,   349,   224,   351,
      89,   197,   198,   102,   151,   104,    89,    94,   164,    76,
     131,   237,    89,   239,    32,   367,   212,   369,    94,    37,
      99,    89,   229,   249,    89,   172,   252,   159,    19,    89,
     199,    89,   131,    45,   386,    89,   135,   138,    89,    51,
     164,   173,    54,    55,   191,   102,   398,   104,   338,    99,
      62,   403,   151,   164,   223,   162,   113,   409,   125,   161,
      89,   178,   138,   353,  1099,   634,   356,   164,  1228,    89,
      88,   188,   641,   172,   131,   164,    89,   109,   716,   717,
      89,   164,   720,    99,   374,   164,   376,   164,    89,   843,
      89,   701,   191,   161,   384,  1212,   840,   387,   131,   164,
      89,    92,  1055,    89,   164,    89,   164,   397,   852,  1269,
     164,    89,   103,   164,  1274,   753,   803,    89,  1278,     7,
       8,   494,   495,    89,   241,    42,    89,    89,    89,   147,
     247,   421,   161,   423,    78,   147,   127,   149,   255,   491,
     131,   161,   174,   134,   496,  1055,   123,    76,   161,    89,
     109,   163,   161,     7,     8,   507,   508,   509,  1173,   769,
     161,   771,   161,   515,    56,    57,    89,   200,   201,   202,
     126,   136,   161,    53,    88,   161,   153,   161,   190,   169,
     170,   750,   751,   161,  1220,  1221,   755,   143,   153,   161,
     134,   108,   106,   178,   171,   161,   125,    85,   161,   161,
     161,  1154,   264,   188,  1240,   131,   775,    99,   270,    89,
    1246,   176,   564,  1054,   102,   174,   104,   126,   787,   788,
     789,   161,   791,   792,   793,   794,   795,   796,   134,   798,
     799,    85,   522,   523,   143,   804,  1097,  1233,   161,    78,
      77,  1102,   594,   131,  1154,   535,    78,   135,   102,  1202,
     104,    88,   116,   224,   823,    94,   825,   826,    58,    59,
      97,    61,    94,   151,  1018,   220,   221,   131,   176,   106,
     178,  1025,  1026,   116,    58,    59,   914,   131,    78,   134,
     188,   135,   253,   254,   172,   256,   257,   242,   131,    36,
     134,   581,  1202,  1037,    78,   134,    43,   151,   867,    99,
     107,   108,    78,   191,   656,   241,    82,    27,   204,   241,
     600,   247,   111,   209,   246,   200,   201,   202,   172,   255,
     119,   120,  1183,   122,   497,    54,  1187,   500,   897,   502,
     129,    58,    59,   116,   133,  1159,   135,   191,   121,   134,
    1164,   140,   911,   633,   131,   131,   134,   134,   134,   639,
     222,   222,   990,   225,   225,   924,   204,   156,   206,   928,
     929,    99,   931,  1224,   204,   131,   206,   936,    13,   211,
     146,   213,   131,   211,   194,   213,   107,   108,   710,   711,
    1134,  1135,   181,   182,   183,   184,   185,   186,   134,   679,
     680,   681,   682,   473,   474,   480,   481,    99,   482,   483,
    1157,  1158,   204,   681,   682,   131,    99,     0,   168,   699,
     168,   701,    89,   145,    74,    78,   234,   986,    69,    82,
     177,    83,   132,    84,   131,   134,   131,   131,   997,   164,
     131,   164,    37,    37,    19,    99,    17,   131,  1076,   251,
     216,  1010,   251,    99,  1013,    99,  1015,  1201,   224,   131,
     226,   227,   228,   134,   134,   134,   134,    24,   134,    14,
     236,   237,   192,   239,   164,    19,   164,   210,   244,    99,
      36,    89,   147,   249,   250,   251,   252,   148,   148,   769,
      76,   771,   210,   146,    76,    76,  1124,   134,    19,    89,
     164,    89,   138,   106,   138,  1064,   111,    19,   164,   164,
      78,    78,    32,   111,   161,    89,   164,    76,   216,   164,
     121,   164,   204,   161,   148,  1084,   168,  1086,   125,   809,
      99,   233,   812,  1092,   876,    99,    99,    99,   252,   235,
     820,    82,   822,   254,   131,   175,   888,  1106,  1107,  1108,
    1109,  1110,   131,  1112,   240,   131,   111,   111,   138,    78,
      99,    99,   255,   216,   125,   131,   255,   229,   121,    24,
     912,   224,  1131,   226,   227,   228,    19,    99,   218,   131,
      89,    99,    89,   134,   237,   134,   239,   164,  1147,   125,
    1149,   244,   125,   873,   125,    48,   249,   250,   251,   252,
     123,   943,   230,   883,   230,    76,   255,   123,    19,    89,
     168,   121,  1171,    99,   164,    99,   958,   164,   164,   125,
      61,   164,   255,   111,   164,     5,   168,   164,   212,   163,
     134,   216,    88,   125,   212,   164,    88,   164,   248,   212,
     212,   921,    76,    76,    19,    99,   926,    19,   163,    78,
     161,    76,    19,    59,   105,    78,   131,   937,   163,    99,
     174,   174,    99,   163,   160,    75,   174,    99,   238,    99,
     164,   174,  1231,   238,   431,  1056,   193,   431,   764,   959,
     812,   229,  1090,   926,   938,   987,   999,   804,   397,   994,
     997,   193,   921,   874,   453,  1254,   197,   196,  1113,   454,
     980,   601,   952,   475,  1246,  1240,   385,   987,   385,   682,
     984,   701,   840,   657,   852,   250,   980,  1037,   658,   844,
    1169,  1068,   254,   841,    -1,    -1,    -1,    -1,  1032,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1043,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1055,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1087,  1088,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1098,    -1,
      -1,    -1,    -1,  1103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1148,    -1,
      -1,    -1,    -1,    -1,  1154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1184,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1252,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    -1,    19,    -1,    -1,    -1,
    1270,    -1,    25,    26,    -1,  1275,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,    52,
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
     153,   154,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,
     163,    -1,   165,   166,   167,    -1,   169,   170,   171,    -1,
     173,    -1,   175,   176,   177,   178,   179,    -1,   181,   182,
     183,   184,   185,   186,    -1,    -1,   189,   190,   191,    -1,
     193,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
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
      45,    46,    47,    48,    49,    -1,    51,    52,    53,    54,
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
      -1,    -1,   157,   158,   159,    -1,    -1,    -1,   163,    -1,
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
     158,   159,    -1,    -1,    -1,   163,   164,   165,   166,   167,
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
      -1,    -1,   157,   158,   159,    -1,    -1,    -1,   163,    -1,
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
      16,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    -1,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    87,    88,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,   103,    -1,   105,
     106,   107,   108,    -1,   110,    -1,    -1,    -1,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,    -1,   150,   151,    -1,   153,   154,    -1,
      -1,   157,   158,   159,    -1,    -1,    -1,   163,    -1,   165,
     166,   167,    -1,   169,   170,   171,    -1,   173,    -1,   175,
     176,   177,   178,   179,    -1,   181,   182,   183,   184,   185,
     186,    -1,    -1,   189,   190,   191,    -1,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,   220,   221,   222,   223,   224,   225,
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
     128,   129,   130,    -1,    -1,    -1,   134,   135,    -1,   137,
     138,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,    -1,   150,   151,    -1,    -1,    -1,    -1,    -1,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,   165,   166,   167,
      -1,    -1,    -1,   171,    -1,   173,    -1,   175,   176,   177,
     178,   179,    -1,   181,   182,   183,   184,   185,   186,    -1,
      -1,   189,   190,   191,    -1,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,   234,   235,    -1,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,   163,    -1,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,   173,    -1,   175,   176,   177,   178,
     179,    -1,   181,   182,   183,   184,   185,   186,    -1,    -1,
     189,   190,    -1,    -1,    -1,   194,    -1,   196,   197,   198,
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
      -1,    -1,    -1,   163,    -1,   165,    -1,    -1,    -1,    -1,
      -1,   171,    -1,   173,    -1,   175,   176,   177,   178,   179,
      -1,   181,   182,   183,   184,   185,   186,    -1,    -1,   189,
     190,    -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,   235,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    15,    -1,
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
     125,   126,    -1,   128,   129,   130,   131,    -1,    -1,   134,
      -1,    -1,   137,   138,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,
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
      93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,    -1,   110,    -1,    -1,
      -1,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,    -1,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
     163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,    -1,
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
      -1,    93,    94,    -1,    -1,    97,    98,    99,    -1,    -1,
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
      -1,    -1,   163,    -1,   165,   166,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,   163,    -1,   165,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   173,    -1,   175,   176,   177,   178,   179,
      -1,   181,   182,   183,   184,   185,   186,    -1,    -1,   189,
     190,    -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,   235,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257
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
     305,   306,   307,   312,   313,   314,   315,   320,   322,   324,
     325,   326,   331,   352,   355,   358,   359,   360,   361,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   408,
     409,   410,   424,   425,   427,   428,   429,   430,   431,   432,
     433,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   452,   453,   454,   455,   456,   457,   458,   461,   466,
     467,   216,    27,   134,   131,   200,   201,   202,   134,    30,
      31,    32,    33,    34,    35,    36,    40,    41,    43,    44,
      51,    54,    55,    66,    67,    79,   114,   131,   134,   146,
     179,   203,   204,   205,   207,   208,   215,   466,   131,   131,
     134,   131,   134,    37,    38,    39,    47,    52,    63,    65,
      68,    71,    93,    94,   138,   199,   223,   134,    17,   131,
     134,   465,    46,    49,    99,   138,    99,   131,    56,    57,
      99,   317,    54,    27,   134,   134,   131,   134,   466,    32,
      34,    35,    41,    79,   392,   466,   466,    99,   303,   313,
     164,   313,   466,   131,    13,    15,   466,   466,   384,   131,
      20,   192,   194,   204,   206,   134,   204,   206,   204,   204,
     209,    99,   131,    99,     0,   275,   276,    36,    43,   278,
     312,   168,   168,    89,    45,    51,    54,    55,    62,   147,
     149,   163,   190,   316,   321,   322,   323,   340,   341,   345,
     327,   328,   466,   145,    74,   111,   119,   120,   122,   129,
     133,   135,   140,   156,   181,   182,   183,   184,   185,   186,
     376,   377,   234,   136,   153,   176,    98,   124,   137,   171,
     178,   188,   115,   128,    69,   177,    83,    84,   136,   153,
     375,   131,   381,   384,   169,   170,   132,   396,   397,   392,
     396,   392,   396,   134,   314,   314,   313,   131,   131,   131,
     313,   313,   164,   171,   466,   131,   313,   313,   164,   313,
     164,   466,    37,    37,   466,   159,   173,   146,   179,    19,
     464,   144,   159,   159,   173,    99,    32,    37,    88,   147,
     465,   200,   201,   202,    82,   216,   224,   237,   239,   249,
     252,   479,   480,   481,   482,   483,   486,   491,   492,   313,
     313,    19,   164,   465,   131,   138,   464,    94,   138,   297,
     464,   353,   354,   466,   465,   332,   334,   466,   314,   251,
     251,    99,   335,    99,   466,    32,    66,   164,   448,   449,
     313,   164,   171,   466,   131,   353,   161,   313,   168,   164,
      24,   412,   413,   414,   313,     6,   152,    14,   164,   313,
     192,    19,   314,   314,   164,   314,   314,   314,   314,   210,
     459,   460,   466,   314,   333,   339,   466,   280,   281,    36,
     282,   314,   147,    99,   148,   148,   314,   314,    89,    76,
      78,   125,   245,   329,   330,   435,   360,   361,   363,   363,
     363,   363,   362,   363,   363,   363,   131,   134,   235,   399,
     468,   470,   471,   472,   473,   474,   475,   476,   366,   366,
     365,   367,   367,   367,   367,   368,   368,   369,   369,   210,
      76,    76,    76,   161,   313,   384,   384,   313,   397,   164,
     314,   407,   164,   161,   313,   313,   313,   164,   161,    89,
     164,    89,   164,   161,   313,   161,   161,   161,   134,   301,
     466,   466,    19,    89,    89,   466,   138,   138,   464,   106,
     111,   222,   225,    94,   224,   253,   254,   256,   257,   222,
     225,    19,   224,   253,   254,   256,   257,   164,   161,   164,
     164,   161,   313,   465,    78,    32,   465,   464,    78,    89,
     165,   125,   435,   111,    89,   121,   330,   435,   161,   466,
      60,   196,   229,   318,   319,   164,   164,   164,   161,    89,
     164,    89,   164,   161,   313,   165,   168,   466,   413,   414,
     109,   174,   161,   161,   110,   168,    76,   197,   198,   212,
      76,   197,   198,   212,    76,   216,   204,    89,   214,   121,
     161,    53,    89,   168,   148,   466,   314,   346,   347,    99,
     342,   343,    99,   130,   189,   436,   438,   439,   440,   466,
      99,   314,    99,   125,   330,   125,   125,   329,   330,   363,
     313,   468,   474,   252,   502,    78,   146,   226,   227,   228,
     236,   244,   250,   251,   469,   477,   478,   479,   493,   496,
     497,   499,   233,   235,   240,   498,   220,   221,   242,   494,
     436,   436,   434,   439,   434,   161,   162,    89,   164,   302,
     161,   161,   161,    82,   356,   357,   131,   450,   451,   466,
     450,   451,   161,    99,   164,   308,   309,   116,   131,   311,
     301,   301,   126,   143,   126,   143,   116,   121,   435,   464,
     464,   107,   108,   464,   254,   255,    78,    94,   134,   485,
     255,   175,   131,   161,   111,   296,   464,   138,   111,    78,
     296,    99,   314,   314,   125,   464,    99,   314,   121,   121,
     330,   125,   435,   229,    58,    59,    61,    99,   329,   336,
     337,   338,   319,   131,   450,   466,   450,   161,   314,    24,
     414,   109,   174,     7,     8,    85,   102,   104,   131,   172,
     310,   409,   411,   422,   423,   426,    19,   211,   213,   314,
     314,   314,   211,   213,   314,   314,   314,   314,   314,   314,
      99,   314,   314,   218,   462,   463,   131,    99,   346,    77,
      88,    97,   106,   348,   349,   350,   351,    89,   466,    89,
     328,   134,   134,   123,   153,   171,   437,   466,   466,   314,
     125,   314,   314,   125,   330,   125,   161,   164,   230,   196,
     229,   241,   246,   501,    78,   231,   232,   495,   230,   471,
     501,   364,   367,   250,   477,   479,   472,   125,   495,   255,
      48,   123,   314,    99,   436,    94,   357,   161,   313,   164,
     164,   123,   164,   164,   466,    76,    89,   164,   313,   116,
     311,   302,   314,   116,   121,   255,    78,   134,   488,    19,
      94,   485,   314,   161,   313,   464,    89,   296,   354,   314,
     168,   334,   314,   314,   121,   314,   125,    99,    99,   314,
     466,   338,    61,   161,   313,   164,   164,   111,   172,   411,
       5,   313,   466,   172,   422,   168,   212,   212,   212,   212,
     216,   460,   163,   134,   463,   314,   339,   464,   107,   108,
     350,   351,   351,   347,    88,   344,   343,   164,   164,   314,
     314,   125,   314,   367,    42,   108,   367,   367,   241,   247,
     255,   500,   500,   364,   473,   248,   466,   163,    99,   163,
     161,   435,   436,   309,    76,   161,   314,   115,   178,   487,
     490,    19,    19,   489,   487,   243,   495,    89,   164,    89,
     164,   105,   161,    78,   464,   314,   314,   466,   466,   337,
     314,   161,   414,   466,   172,   161,   414,   466,   314,   314,
     314,   314,   314,   314,   393,   161,   351,   464,   314,   367,
     367,   176,    76,   314,   466,   314,   436,   488,   488,   490,
      19,   164,    19,   238,   484,   485,   484,   314,   296,    59,
      75,   160,   415,   414,   466,   174,   414,    89,   164,   367,
     436,   163,   495,    89,   164,   164,    99,     3,   112,   418,
     419,   421,   423,    18,   113,   416,   417,   420,   423,   174,
     414,   174,    99,   311,   163,   314,   238,   485,   466,    75,
     112,   421,   160,   113,   420,   174,   466,   314,    89,   164,
      99,   311,   466,    89,   164,    99,   311,   466,   164,   311
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
     314,   314,   314,   315,   316,   317,   317,   318,   318,   318,
     319,   319,   320,   320,   321,   322,   322,   322,   323,   323,
     323,   323,   323,   324,   324,   325,   325,   326,   327,   327,
     328,   328,   328,   328,   328,   328,   328,   328,   329,   330,
     331,   332,   332,   333,   333,   334,   334,   334,   334,   335,
     335,   336,   336,   336,   337,   337,   337,   338,   338,   338,
     339,   340,   341,   342,   342,   343,   343,   344,   345,   345,
     346,   346,   347,   347,   348,   348,   348,   348,   348,   348,
     348,   349,   349,   350,   350,   351,   352,   352,   353,   353,
     354,   354,   355,   355,   356,   356,   357,   357,   358,   359,
     359,   360,   360,   361,   361,   361,   361,   361,   362,   361,
     361,   361,   361,   363,   363,   363,   364,   364,   365,   365,
     365,   366,   366,   366,   366,   366,   367,   367,   367,   368,
     368,   368,   369,   369,   370,   370,   371,   371,   372,   372,
     373,   373,   374,   374,   374,   374,   375,   375,   375,   376,
     376,   376,   376,   376,   376,   377,   377,   377,   378,   378,
     378,   378,   379,   379,   380,   380,   381,   381,   382,   382,
     382,   382,   383,   384,   384,   384,   385,   385,   386,   386,
     386,   386,   387,   387,   388,   388,   388,   388,   388,   388,
     388,   389,   389,   390,   390,   391,   391,   391,   391,   391,
     392,   392,   393,   393,   394,   394,   394,   395,   395,   396,
     396,   397,   398,   398,   398,   398,   398,   398,   398,   398,
     399,   399,   400,   400,   400,   401,   402,   402,   403,   404,
     405,   406,   406,   407,   407,   408,   408,   409,   409,   409,
     410,   410,   410,   410,   410,   410,   411,   411,   412,   412,
     413,   414,   414,   415,   415,   416,   416,   417,   417,   417,
     417,   418,   418,   419,   419,   419,   419,   420,   420,   421,
     421,   422,   422,   422,   422,   423,   423,   423,   423,   424,
     424,   425,   425,   426,   427,   427,   427,   427,   427,   427,
     428,   429,   429,   429,   429,   430,   430,   430,   430,   431,
     432,   433,   433,   433,   433,   434,   434,   435,   436,   436,
     436,   437,   437,   437,   438,   438,   438,   439,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   441,   442,   442,
     442,   443,   444,   445,   445,   445,   446,   446,   446,   446,
     446,   447,   448,   448,   448,   448,   448,   448,   448,   449,
     450,   451,   452,   453,   453,   453,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   455,   455,   456,   456,
     457,   458,   459,   459,   460,   461,   462,   462,   463,   463,
     463,   463,   464,   465,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   467,   467,   468,   468,   468,   468,   469,   469,
     469,   469,   470,   470,   471,   471,   472,   472,   473,   473,
     474,   474,   474,   475,   475,   476,   476,   477,   477,   477,
     477,   477,   478,   479,   479,   479,   479,   479,   479,   479,
     480,   480,   480,   480,   481,   481,   481,   481,   482,   482,
     483,   483,   483,   483,   483,   483,   483,   484,   484,   485,
     485,   485,   485,   486,   486,   486,   486,   486,   487,   487,
     488,   488,   489,   489,   490,   490,   491,   492,   492,   493,
     493,   493,   494,   494,   494,   494,   494,   495,   495,   495,
     495,   496,   497,   498,   499,   499,   500,   500,   500,   501,
     501,   502
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
       1,     1,     1,     2,     2,     2,     2,     1,     1,     2,
       4,     3,     5,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     2,     1,     4,
       3,     4,     4,     5,     4,     5,     5,     6,     3,     3,
       3,     1,     4,     1,     4,     3,     4,     4,     5,     4,
       5,     1,     2,     3,     1,     2,     1,     6,     3,     3,
       1,     2,     3,     1,     3,     2,     3,     2,     3,     4,
       1,     3,     1,     2,     1,     1,     1,     2,     2,     2,
       3,     1,     1,     2,     2,     2,     5,     5,     1,     4,
       3,     4,     8,    10,     1,     2,     4,     7,     8,     1,
       3,     1,     3,     1,     3,     3,     3,     3,     0,     4,
       3,     3,     3,     1,     3,     4,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     4,     1,     4,     1,     4,     1,     4,
       1,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     5,
       5,     5,     3,     4,     1,     2,     3,     2,     1,     2,
       2,     1,     1,     1,     3,     3,     1,     1,     1,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     1,     4,
       4,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       4,     5,     8,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     4,     5,     6,     7,     4,     5,     6,     7,     4,
       4,     4,     5,     6,     7,     1,     2,     2,     1,     2,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     4,
       4,     3,     3,     3,     4,     4,     3,     4,     6,     4,
       6,     3,     3,     4,     6,     6,     4,     6,     6,     4,
       1,     2,     1,     3,     3,     3,     5,     7,     7,     5,
       5,     5,     7,     7,     5,     5,     3,     3,     5,     7,
       5,     7,     1,     4,     3,     5,     1,     2,     5,     8,
      11,    14,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     7,     4,     1,     2,     3,     4,     1,     1,
       2,     2,     1,     3,     1,     3,     1,     4,     1,     2,
       1,     2,     3,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     3,     5,     7,     5,     7,     2,     1,     3,     2,
       4,     4,     6,     4,     5,     4,     5,     3,     1,     2,
       2,     3,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     1,     2,     1,     2,     3,     3,
       4,     3,     3,     3,     2,     2,     1,     1,     1,     1,
       1,     3
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
       273,     0,    -1,   275,    -1,   274,   275,    -1,   276,    -1,
     274,   276,    -1,   193,   194,    19,   168,    -1,   193,   194,
      19,   110,    19,   168,    -1,   278,   312,    -1,   312,    -1,
     277,   278,    -1,    46,   138,   465,   111,   464,   168,    -1,
     279,   168,    -1,   280,   168,    -1,   279,   168,   280,   168,
      -1,   281,    -1,   279,   168,   281,    -1,   282,    -1,   280,
     168,   282,    -1,   283,    -1,   284,    -1,   285,    -1,   287,
      -1,   299,    -1,   307,    -1,   288,    -1,   289,    -1,   286,
      -1,   293,    -1,   294,    -1,   300,    -1,   290,    -1,   291,
      -1,   292,    -1,   453,    -1,   295,    -1,   298,    -1,    36,
     138,   465,   111,   464,    -1,    36,    71,   159,    -1,    36,
      71,   173,    -1,    36,    94,    32,   138,   464,    -1,    36,
      94,    37,   138,   464,    -1,    36,    47,   466,    19,    -1,
      36,   223,   479,    -1,    36,    63,   146,    -1,    36,    63,
     179,    -1,    36,    94,   147,   106,   107,    -1,    36,    94,
     147,   106,   108,    -1,    36,    68,   159,    89,   126,    -1,
      36,    68,   159,    89,   143,    -1,    36,    68,   144,    89,
     126,    -1,    36,    68,   144,    89,   143,    -1,    36,    94,
      88,   464,    -1,    36,    65,   464,    -1,    43,    49,   464,
      -1,    43,    49,   297,   464,    -1,    43,    49,   464,    78,
     296,    -1,    43,    49,   297,   464,    78,   296,    -1,   464,
      -1,   296,    89,   464,    -1,   138,   465,   111,    -1,    94,
      32,   138,    -1,    43,    46,   464,    -1,    43,    46,   138,
     465,   111,   464,    -1,    43,    46,   464,    78,   296,    -1,
      43,    46,   138,   465,   111,   464,    78,   296,    -1,    36,
      93,    99,   466,   121,   314,    -1,    36,    93,    99,   466,
     116,    -1,    36,    93,    99,   466,   435,   121,   314,    -1,
      36,    93,    99,   466,   435,   116,    -1,    36,    52,   159,
      -1,    36,    52,   173,    -1,   134,   164,    -1,   134,   308,
     164,    -1,   134,   164,    76,   436,    -1,   134,   308,   164,
      76,   436,    -1,   131,   303,   161,    -1,   313,   168,    -1,
     303,   313,   168,    -1,    25,   216,   314,    -1,    29,   134,
     314,   164,   302,    -1,    26,    27,    -1,    64,    27,    -1,
      36,    37,   466,   301,   116,    -1,    36,    37,   466,   301,
     311,    -1,    36,    38,    37,   466,   301,   116,    -1,    36,
      38,    37,   466,   301,   311,    -1,    36,    39,    37,   466,
     301,   302,    -1,   309,    -1,   308,    89,   309,    -1,    99,
     466,    -1,    99,   466,   435,    -1,   131,   313,   161,    -1,
     131,   313,   161,    -1,   313,    -1,   314,    -1,   313,    89,
     314,    -1,   315,    -1,   352,    -1,   355,    -1,   358,    -1,
     359,    -1,   454,    -1,   455,    -1,   457,    -1,   456,    -1,
     458,    -1,   461,    -1,   467,    -1,   304,    -1,   305,    -1,
     306,    -1,   302,    -1,   324,   316,    -1,   163,   314,    -1,
      56,   251,    -1,    57,   251,    -1,   196,    -1,   229,    -1,
      60,   229,    -1,   318,   336,    61,   314,    -1,   318,    61,
     314,    -1,    54,   317,   335,   319,   319,    -1,    54,   317,
     335,   319,    -1,    62,    99,   466,    -1,   326,    -1,   331,
      -1,   320,    -1,   322,    -1,   340,    -1,   345,    -1,   341,
      -1,   321,    -1,   322,    -1,   324,   323,    -1,    54,    99,
      -1,    55,    54,    99,    -1,   325,   327,    -1,   328,    -1,
     327,    89,    99,   328,    -1,   466,   125,   314,    -1,   466,
     435,   125,   314,    -1,   466,   329,   125,   314,    -1,   466,
     435,   329,   125,   314,    -1,   466,   330,   125,   314,    -1,
     466,   435,   330,   125,   314,    -1,   466,   329,   330,   125,
     314,    -1,   466,   435,   329,   330,   125,   314,    -1,    78,
      99,   466,    -1,   245,    99,   466,    -1,    51,    99,   332,
      -1,   334,    -1,   332,    89,    99,   334,    -1,   339,    -1,
     333,    89,    99,   339,    -1,   466,   121,   314,    -1,   466,
     435,   121,   314,    -1,   466,   330,   121,   314,    -1,   466,
     435,   330,   121,   314,    -1,    99,   466,   125,   314,    -1,
      99,   466,   435,   125,   314,    -1,   337,    -1,    99,   466,
      -1,    99,   466,   337,    -1,   329,    -1,   329,   338,    -1,
     338,    -1,    58,    99,   466,    59,    99,   466,    -1,    59,
      99,   466,    -1,    58,    99,   466,    -1,   466,    -1,   190,
     314,    -1,   149,   148,   342,    -1,   343,    -1,   342,    89,
     343,    -1,    99,   466,    -1,    99,   466,   344,    -1,    88,
     464,    -1,   147,   148,   346,    -1,    45,   147,   148,   346,
      -1,   347,    -1,   346,    89,   347,    -1,   314,    -1,   314,
     348,    -1,   349,    -1,   350,    -1,   351,    -1,   349,   350,
      -1,   349,   351,    -1,   350,   351,    -1,   349,   350,   351,
      -1,    77,    -1,    97,    -1,   106,   107,    -1,   106,   108,
      -1,    88,   464,    -1,    44,    99,   353,   165,   314,    -1,
     114,    99,   353,   165,   314,    -1,   354,    -1,   353,    89,
      99,   354,    -1,   466,   125,   314,    -1,   466,   435,   125,
     314,    -1,    31,   134,   313,   164,   356,    94,   163,   314,
      -1,    31,   134,   313,   164,   356,    94,    99,   466,   163,
     314,    -1,   357,    -1,   356,   357,    -1,    82,   436,   163,
     314,    -1,    82,    99,   466,    76,   436,   163,   314,    -1,
      40,   134,   313,   164,   175,   314,   105,   314,    -1,   360,
      -1,   359,   145,   360,    -1,   361,    -1,   360,    74,   361,
      -1,   363,    -1,   363,   376,   363,    -1,   363,   377,   363,
      -1,   363,   111,   363,    -1,   363,   140,   363,    -1,    -1,
     363,   135,   362,   363,    -1,   363,   133,   363,    -1,   363,
     122,   363,    -1,   363,   120,   363,    -1,   364,    -1,   364,
     234,   468,    -1,   364,   234,   468,   502,    -1,   365,    -1,
     365,   176,   365,    -1,   366,    -1,   365,   153,   366,    -1,
     365,   136,   366,    -1,   367,    -1,   366,   171,   367,    -1,
     366,    98,   367,    -1,   366,   124,   367,    -1,   366,   137,
     367,    -1,   368,    -1,   367,   178,   368,    -1,   367,   188,
     368,    -1,   369,    -1,   368,   128,   369,    -1,   368,   115,
     369,    -1,   370,    -1,   370,    69,   210,   436,    -1,   371,
      -1,   371,   177,    76,   436,    -1,   372,    -1,   372,    83,
      76,   434,    -1,   373,    -1,   373,    84,    76,   434,    -1,
     375,    -1,   374,   375,    -1,   153,    -1,   136,    -1,   374,
     153,    -1,   374,   136,    -1,   378,    -1,   382,    -1,   379,
      -1,   181,    -1,   186,    -1,   185,    -1,   184,    -1,   183,
      -1,   182,    -1,   129,    -1,   156,    -1,   119,    -1,    30,
     131,   313,   161,    -1,    30,   200,   131,   313,   161,    -1,
      30,   201,   131,   313,   161,    -1,    30,   202,   131,   313,
     161,    -1,   380,   131,   161,    -1,   380,   131,   313,   161,
      -1,   381,    -1,   380,   381,    -1,   154,   466,    14,    -1,
     154,    15,    -1,   383,    -1,   383,   384,    -1,   170,   384,
      -1,   384,    -1,   169,    -1,   385,    -1,   385,   169,   384,
      -1,   385,   170,   384,    -1,   386,    -1,   395,    -1,   387,
      -1,   387,   396,    -1,   390,    -1,   390,   396,    -1,   388,
     392,    -1,   389,    -1,    87,    -1,    95,    -1,    80,    -1,
     167,    -1,    96,    -1,   118,    -1,   117,    -1,   392,    -1,
      81,   392,    -1,   391,   392,    -1,   101,    -1,   150,    -1,
      72,    -1,   158,    -1,   157,    -1,    73,    -1,   440,    -1,
     393,    -1,   466,    -1,   394,    -1,   171,    -1,     9,    -1,
      16,    -1,   398,    -1,   398,   396,    -1,   397,    -1,   396,
     397,    -1,   132,   313,   162,    -1,   399,    -1,   401,    -1,
     402,    -1,   403,    -1,   406,    -1,   408,    -1,   404,    -1,
     405,    -1,   400,    -1,   452,    -1,    92,    -1,   127,    -1,
     103,    -1,    99,   466,    -1,   134,   164,    -1,   134,   313,
     164,    -1,   100,    -1,   146,   131,   313,   161,    -1,   179,
     131,   313,   161,    -1,   466,   134,   164,    -1,   466,   134,
     407,   164,    -1,   314,    -1,   407,    89,   314,    -1,   409,
      -1,   427,    -1,   410,    -1,   424,    -1,   425,    -1,   135,
     466,   414,   109,    -1,   135,   466,   412,   414,   109,    -1,
     135,   466,   414,   174,   172,   466,   414,   174,    -1,   135,
     466,   414,   174,   411,   172,   466,   414,   174,    -1,   135,
     466,   412,   414,   174,   172,   466,   414,   174,    -1,   135,
     466,   412,   414,   174,   411,   172,   466,   414,   174,    -1,
     422,    -1,   411,   422,    -1,   413,    -1,   412,   413,    -1,
      24,   466,   414,   111,   414,   415,    -1,    -1,    24,    -1,
     160,   416,   160,    -1,    75,   418,    75,    -1,    -1,   417,
      -1,   113,    -1,   420,    -1,   417,   113,    -1,   417,   420,
      -1,    -1,   419,    -1,   112,    -1,   421,    -1,   419,   112,
      -1,   419,   421,    -1,    18,    -1,   423,    -1,     3,    -1,
     423,    -1,   409,    -1,     8,    -1,   426,    -1,   423,    -1,
       7,    -1,   102,    -1,   104,    -1,   310,    -1,   191,    20,
     192,    -1,   191,   192,    -1,   151,    13,   152,    -1,   151,
      13,     6,    -1,    85,     5,    -1,   428,    -1,   429,    -1,
     430,    -1,   431,    -1,   432,    -1,   433,    -1,    33,   131,
     313,   161,    -1,    32,   466,   131,   161,    -1,    32,   466,
     131,   313,   161,    -1,    32,   131,   313,   161,   131,   161,
      -1,    32,   131,   313,   161,   131,   313,   161,    -1,    79,
     466,   131,   161,    -1,    79,   466,   131,   313,   161,    -1,
      79,   131,   313,   161,   131,   161,    -1,    79,   131,   313,
     161,   131,   313,   161,    -1,    34,   131,   313,   161,    -1,
      35,   131,   313,   161,    -1,    41,   465,   131,   161,    -1,
      41,   465,   131,   313,   161,    -1,    41,   131,   313,   161,
     131,   161,    -1,    41,   131,   313,   161,   131,   313,   161,
      -1,   439,    -1,   439,   123,    -1,    76,   436,    -1,   438,
      -1,   438,   437,    -1,   189,   134,   164,    -1,   123,    -1,
     171,    -1,   153,    -1,   439,    -1,   440,    -1,   130,   134,
     164,    -1,   466,    -1,   442,    -1,   448,    -1,   446,    -1,
     449,    -1,   447,    -1,   445,    -1,   444,    -1,   443,    -1,
     441,    -1,   204,   134,   164,    -1,    67,   134,   164,    -1,
      67,   134,   448,   164,    -1,    67,   134,   449,   164,    -1,
      34,   134,   164,    -1,    35,   134,   164,    -1,    41,   134,
     164,    -1,    41,   134,   465,   164,    -1,    41,   134,    19,
     164,    -1,    79,   134,   164,    -1,    79,   134,   466,   164,
      -1,    79,   134,   466,    89,   450,   164,    -1,    79,   134,
     171,   164,    -1,    79,   134,   171,    89,   450,   164,    -1,
     166,   466,   164,    -1,    32,   134,   164,    -1,    32,   134,
     466,   164,    -1,    32,   134,   466,    89,   450,   164,    -1,
      32,   134,   466,    89,   451,   164,    -1,    32,   134,   171,
     164,    -1,    32,   134,   171,    89,   450,   164,    -1,    32,
     134,   171,    89,   451,   164,    -1,    66,   134,   466,   164,
      -1,   466,    -1,   466,   123,    -1,    19,    -1,    36,   199,
     200,    -1,    36,   199,   201,    -1,    36,   199,   202,    -1,
     205,   204,   314,   212,   314,    -1,   205,   204,   314,    76,
     211,   212,   314,    -1,   205,   204,   314,    76,   213,   212,
     314,    -1,   205,   204,   314,   197,   314,    -1,   205,   204,
     314,   198,   314,    -1,   205,   206,   314,   212,   314,    -1,
     205,   206,   314,    76,   211,   212,   314,    -1,   205,   206,
     314,    76,   213,   212,   314,    -1,   205,   206,   314,   197,
     314,    -1,   205,   206,   314,   198,   314,    -1,   203,   204,
     314,    -1,   203,   206,   314,    -1,   208,   204,   314,   216,
     314,    -1,   208,   209,   210,   204,   314,   216,   314,    -1,
     207,   204,   314,    76,   314,    -1,   215,    99,   459,   214,
     314,   163,   314,    -1,   460,    -1,   459,    89,    99,   460,
      -1,   466,   121,   314,    -1,   217,   131,   314,   161,   462,
      -1,   463,    -1,   462,   463,    -1,   218,   134,   393,   164,
     311,    -1,   218,   134,   393,    89,    99,   466,   164,   311,
      -1,   218,   134,   393,    89,    99,   466,    89,    99,   466,
     164,   311,    -1,   218,   134,   393,    89,    99,   466,    89,
      99,   466,    89,    99,   466,   164,   311,    -1,    19,    -1,
      17,    -1,    17,    -1,   106,    -1,    79,    -1,    35,    -1,
      67,    -1,    32,    -1,   130,    -1,    40,    -1,   204,    -1,
      41,    -1,    70,    -1,    66,    -1,    34,    -1,    31,    -1,
     189,    -1,    71,    -1,   223,    -1,    65,    -1,   201,    -1,
     200,    -1,   124,    -1,    33,    -1,   235,    -1,   222,    -1,
     225,    -1,   224,    -1,   252,    -1,   253,    -1,   256,    -1,
     254,    -1,   257,    -1,   228,    -1,   230,    -1,    48,    -1,
     196,    -1,   229,    -1,    42,    -1,   202,    -1,   215,    -1,
     209,    -1,   181,    -1,   186,    -1,   185,    -1,   184,    -1,
     183,    -1,   182,    -1,    78,    -1,    93,    -1,   163,    -1,
      54,    -1,    55,    -1,    56,    -1,    57,    -1,    58,    -1,
      59,    -1,    60,    -1,    61,    -1,    62,    -1,   125,    -1,
      51,    -1,   190,    -1,   148,    -1,   147,    -1,    45,    -1,
      77,    -1,    97,    -1,   107,    -1,   108,    -1,    88,    -1,
      44,    -1,   114,    -1,   165,    -1,    82,    -1,    76,    -1,
     175,    -1,   105,    -1,   145,    -1,    74,    -1,    69,    -1,
     210,    -1,    83,    -1,   176,    -1,    98,    -1,   137,    -1,
     178,    -1,   128,    -1,   115,    -1,    30,    -1,    84,    -1,
     177,    -1,   129,    -1,   159,    -1,   173,    -1,   138,    -1,
     116,    -1,   110,    -1,   144,    -1,   126,    -1,   143,    -1,
      36,    -1,    52,    -1,    63,    -1,    94,    -1,    68,    -1,
      47,    -1,   194,    -1,    43,    -1,    49,    -1,    37,    -1,
     245,    -1,   234,    -1,   250,    -1,   251,    -1,   227,    -1,
     240,    -1,   248,    -1,   244,    -1,   226,    -1,   239,    -1,
     249,    -1,   243,    -1,   238,    -1,   237,    -1,   221,    -1,
     220,    -1,   242,    -1,   231,    -1,   232,    -1,   255,    -1,
     247,    -1,   246,    -1,   241,    -1,   208,    -1,   214,    -1,
     211,    -1,   205,    -1,   198,    -1,   197,    -1,   199,    -1,
     216,    -1,   206,    -1,   207,    -1,   213,    -1,   203,    -1,
     212,    -1,    38,    -1,   146,    -1,   179,    -1,   219,    99,
     333,    53,   131,   314,   161,    -1,    53,   131,   314,   161,
      -1,   470,    -1,   470,   469,    -1,   470,   250,   364,    -1,
     470,   469,   250,   364,    -1,   479,    -1,   477,    -1,   469,
     479,    -1,   469,   477,    -1,   471,    -1,   470,   236,   471,
      -1,   472,    -1,   471,   233,   472,    -1,   473,    -1,   472,
     235,   125,   473,    -1,   474,    -1,   235,   474,    -1,   475,
      -1,   475,   498,    -1,   134,   468,   164,    -1,   476,    -1,
     476,   494,    -1,   399,    -1,   131,   313,   161,    -1,   478,
      -1,   497,    -1,   496,    -1,   499,    -1,   493,    -1,   146,
      -1,   480,    -1,   481,    -1,   482,    -1,   483,    -1,   486,
      -1,   491,    -1,   492,    -1,   239,    -1,   249,    -1,    82,
     222,    -1,    82,   225,    -1,   216,   224,    -1,   252,   224,
      -1,   224,   222,    -1,   224,   225,    -1,   216,   253,    -1,
     252,   253,    -1,   216,   256,   485,    -1,   216,   256,    94,
      -1,   216,   256,   134,   485,   164,    -1,   216,   256,   134,
     485,    89,   484,   164,    -1,   216,   256,   134,    94,   164,
      -1,   216,   256,   134,    94,    89,   484,   164,    -1,   252,
     256,    -1,   485,    -1,   484,    89,   485,    -1,    78,    19,
      -1,    78,    19,   243,    19,    -1,    78,    19,   495,   238,
      -1,    78,    19,   243,    19,   495,   238,    -1,   216,   254,
     255,   488,    -1,   216,   254,   255,   488,   487,    -1,   216,
      94,   254,   255,    -1,   216,    94,   254,   255,   487,    -1,
     252,   254,   255,    -1,   490,    -1,   487,   490,    -1,    78,
      19,    -1,   134,   489,   164,    -1,    19,    -1,   489,    19,
      -1,   178,   488,    -1,   115,   488,    -1,   237,    19,    -1,
     216,   257,    -1,   252,   257,    -1,    78,   196,    -1,    78,
     229,    -1,   228,   230,    -1,   221,    -1,   221,    48,    -1,
     220,    -1,   220,   255,    -1,   242,    -1,   231,   367,    -1,
      78,   108,   367,    -1,    78,    42,   367,    -1,   232,   367,
     176,   367,    -1,   227,   495,   500,    -1,   251,   367,   500,
      -1,   240,   495,   248,    -1,   244,   501,    -1,   226,   501,
      -1,   255,    -1,   247,    -1,   241,    -1,   246,    -1,   241,
      -1,   252,   230,   367,    -1
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
     418,   420,   422,   424,   427,   430,   433,   436,   438,   440,
     443,   448,   452,   458,   463,   467,   469,   471,   473,   475,
     477,   479,   481,   483,   485,   488,   491,   495,   498,   500,
     505,   509,   514,   519,   525,   530,   536,   542,   549,   553,
     557,   561,   563,   568,   570,   575,   579,   584,   589,   595,
     600,   606,   608,   611,   615,   617,   620,   622,   629,   633,
     637,   639,   642,   646,   648,   652,   655,   659,   662,   666,
     671,   673,   677,   679,   682,   684,   686,   688,   691,   694,
     697,   701,   703,   705,   708,   711,   714,   720,   726,   728,
     733,   737,   742,   751,   762,   764,   767,   772,   780,   789,
     791,   795,   797,   801,   803,   807,   811,   815,   819,   820,
     825,   829,   833,   837,   839,   843,   848,   850,   854,   856,
     860,   864,   866,   870,   874,   878,   882,   884,   888,   892,
     894,   898,   902,   904,   909,   911,   916,   918,   923,   925,
     930,   932,   935,   937,   939,   942,   945,   947,   949,   951,
     953,   955,   957,   959,   961,   963,   965,   967,   969,   974,
     980,   986,   992,   996,  1001,  1003,  1006,  1010,  1013,  1015,
    1018,  1021,  1023,  1025,  1027,  1031,  1035,  1037,  1039,  1041,
    1044,  1046,  1049,  1052,  1054,  1056,  1058,  1060,  1062,  1064,
    1066,  1068,  1070,  1073,  1076,  1078,  1080,  1082,  1084,  1086,
    1088,  1090,  1092,  1094,  1096,  1098,  1100,  1102,  1104,  1107,
    1109,  1112,  1116,  1118,  1120,  1122,  1124,  1126,  1128,  1130,
    1132,  1134,  1136,  1138,  1140,  1142,  1145,  1148,  1152,  1154,
    1159,  1164,  1168,  1173,  1175,  1179,  1181,  1183,  1185,  1187,
    1189,  1194,  1200,  1209,  1219,  1229,  1240,  1242,  1245,  1247,
    1250,  1257,  1258,  1260,  1264,  1268,  1269,  1271,  1273,  1275,
    1278,  1281,  1282,  1284,  1286,  1288,  1291,  1294,  1296,  1298,
    1300,  1302,  1304,  1306,  1308,  1310,  1312,  1314,  1316,  1318,
    1322,  1325,  1329,  1333,  1336,  1338,  1340,  1342,  1344,  1346,
    1348,  1353,  1358,  1364,  1371,  1379,  1384,  1390,  1397,  1405,
    1410,  1415,  1420,  1426,  1433,  1441,  1443,  1446,  1449,  1451,
    1454,  1458,  1460,  1462,  1464,  1466,  1468,  1472,  1474,  1476,
    1478,  1480,  1482,  1484,  1486,  1488,  1490,  1492,  1496,  1500,
    1505,  1510,  1514,  1518,  1522,  1527,  1532,  1536,  1541,  1548,
    1553,  1560,  1564,  1568,  1573,  1580,  1587,  1592,  1599,  1606,
    1611,  1613,  1616,  1618,  1622,  1626,  1630,  1636,  1644,  1652,
    1658,  1664,  1670,  1678,  1686,  1692,  1698,  1702,  1706,  1712,
    1720,  1726,  1734,  1736,  1741,  1745,  1751,  1753,  1756,  1762,
    1771,  1783,  1798,  1800,  1802,  1804,  1806,  1808,  1810,  1812,
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
    2094,  2096,  2098,  2106,  2111,  2113,  2116,  2120,  2125,  2127,
    2129,  2132,  2135,  2137,  2141,  2143,  2147,  2149,  2154,  2156,
    2159,  2161,  2164,  2168,  2170,  2173,  2175,  2179,  2181,  2183,
    2185,  2187,  2189,  2191,  2193,  2195,  2197,  2199,  2201,  2203,
    2205,  2207,  2209,  2212,  2215,  2218,  2221,  2224,  2227,  2230,
    2233,  2237,  2241,  2247,  2255,  2261,  2269,  2272,  2274,  2278,
    2281,  2286,  2291,  2298,  2303,  2309,  2314,  2320,  2324,  2326,
    2329,  2332,  2336,  2338,  2341,  2344,  2347,  2350,  2353,  2356,
    2359,  2362,  2365,  2367,  2370,  2372,  2375,  2377,  2380,  2384,
    2388,  2393,  2397,  2401,  2405,  2408,  2411,  2413,  2415,  2417,
    2419,  2421
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   806,   806,   811,   817,   822,   834,   839,   849,   856,
     868,   880,   892,   898,   904,   916,   922,   936,   942,   956,
     957,   958,   959,   965,   966,   967,   970,   977,   978,   979,
     980,   981,   982,   983,   986,   993,   994,  1006,  1018,  1023,
    1034,  1040,  1052,  1065,  1076,  1081,  1093,  1098,  1109,  1115,
    1121,  1127,  1146,  1157,  1168,  1175,  1182,  1189,  1202,  1208,
    1223,  1227,  1237,  1243,  1250,  1256,  1270,  1277,  1284,  1291,
    1304,  1309,  1321,  1325,  1329,  1333,  1340,  1347,  1353,  1362,
    1369,  1376,  1380,  1387,  1395,  1404,  1413,  1422,  1437,  1445,
    1459,  1465,  1477,  1485,  1496,  1507,  1513,  1525,  1526,  1527,
    1528,  1529,  1532,  1533,  1534,  1535,  1536,  1537,  1538,  1539,
    1540,  1541,  1542,  1549,  1558,  1565,  1569,  1577,  1581,  1585,
    1592,  1596,  1603,  1608,  1617,  1626,  1627,  1628,  1632,  1632,
    1632,  1632,  1632,  1635,  1641,  1650,  1654,  1664,  1675,  1681,
    1695,  1702,  1710,  1719,  1729,  1737,  1746,  1755,  1770,  1782,
    1793,  1805,  1811,  1823,  1829,  1843,  1851,  1860,  1868,  1880,
    1886,  1896,  1897,  1901,  1909,  1913,  1918,  1922,  1926,  1930,
    1937,  1952,  1960,  1970,  1976,  1987,  1993,  2002,  2012,  2017,
    2029,  2035,  2049,  2055,  2067,  2074,  2081,  2088,  2095,  2102,
    2109,  2122,  2126,  2136,  2141,  2152,  2163,  2170,  2183,  2190,
    2202,  2208,  2221,  2228,  2242,  2248,  2260,  2266,  2279,  2290,
    2294,  2305,  2309,  2328,  2332,  2340,  2348,  2356,  2364,  2364,
    2372,  2380,  2388,  2402,  2406,  2413,  2426,  2430,  2441,  2445,
    2449,  2459,  2463,  2467,  2471,  2475,  2485,  2489,  2494,  2505,
    2509,  2513,  2523,  2527,  2539,  2543,  2555,  2559,  2571,  2575,
    2587,  2591,  2603,  2607,  2611,  2615,  2627,  2631,  2635,  2645,
    2649,  2653,  2657,  2661,  2665,  2675,  2679,  2683,  2693,  2697,
    2703,  2709,  2721,  2727,  2739,  2745,  2759,  2766,  2807,  2811,
    2815,  2819,  2831,  2841,  2852,  2857,  2867,  2871,  2881,  2887,
    2893,  2899,  2911,  2917,  2928,  2932,  2936,  2940,  2944,  2948,
    2952,  2962,  2966,  2976,  2982,  2994,  2998,  3002,  3006,  3010,
    3025,  3029,  3039,  3043,  3053,  3060,  3067,  3080,  3084,  3096,
    3102,  3116,  3127,  3131,  3135,  3139,  3143,  3147,  3151,  3155,
    3165,  3169,  3179,  3184,  3189,  3200,  3210,  3214,  3225,  3235,
    3246,  3302,  3308,  3320,  3326,  3338,  3342,  3352,  3356,  3360,
    3370,  3378,  3386,  3394,  3402,  3410,  3425,  3431,  3443,  3449,
    3462,  3471,  3473,  3479,  3484,  3496,  3499,  3506,  3512,  3518,
    3526,  3541,  3544,  3551,  3557,  3563,  3571,  3585,  3590,  3601,
    3606,  3617,  3622,  3627,  3633,  3645,  3651,  3656,  3661,  3672,
    3677,  3692,  3697,  3714,  3729,  3733,  3737,  3741,  3745,  3749,
    3759,  3770,  3776,  3782,  3787,  3809,  3815,  3821,  3826,  3837,
    3848,  3859,  3865,  3871,  3876,  3887,  3893,  3905,  3917,  3923,
    3929,  3966,  3971,  3976,  3987,  3991,  3995,  4005,  4016,  4020,
    4024,  4028,  4032,  4036,  4040,  4044,  4048,  4058,  4068,  4072,
    4077,  4088,  4098,  4108,  4112,  4116,  4126,  4132,  4138,  4144,
    4150,  4162,  4173,  4179,  4185,  4191,  4197,  4204,  4211,  4224,
    4245,  4252,  4272,  4312,  4317,  4320,  4328,  4334,  4340,  4346,
    4352,  4359,  4365,  4371,  4377,  4383,  4395,  4400,  4410,  4416,
    4428,  4454,  4465,  4471,  4484,  4498,  4505,  4512,  4523,  4530,
    4538,  4547,  4560,  4563,  4581,  4582,  4583,  4584,  4585,  4586,
    4587,  4588,  4589,  4590,  4591,  4592,  4593,  4594,  4595,  4596,
    4597,  4598,  4599,  4600,  4601,  4602,  4603,  4604,  4605,  4606,
    4607,  4608,  4609,  4610,  4611,  4612,  4613,  4614,  4615,  4616,
    4617,  4618,  4619,  4620,  4621,  4622,  4623,  4624,  4625,  4626,
    4627,  4628,  4629,  4630,  4631,  4632,  4633,  4634,  4635,  4636,
    4637,  4638,  4639,  4640,  4641,  4642,  4643,  4644,  4645,  4646,
    4647,  4648,  4649,  4650,  4651,  4652,  4653,  4654,  4655,  4656,
    4657,  4658,  4659,  4660,  4661,  4662,  4663,  4664,  4665,  4666,
    4667,  4668,  4669,  4670,  4671,  4672,  4673,  4674,  4675,  4676,
    4677,  4678,  4679,  4680,  4681,  4682,  4683,  4684,  4685,  4686,
    4687,  4688,  4689,  4690,  4691,  4692,  4693,  4694,  4695,  4696,
    4697,  4698,  4699,  4700,  4701,  4702,  4703,  4704,  4705,  4706,
    4707,  4708,  4709,  4710,  4711,  4712,  4713,  4714,  4715,  4716,
    4717,  4718,  4719,  4720,  4721,  4722,  4723,  4724,  4725,  4726,
    4727,  4728,  4739,  4745,  4762,  4766,  4770,  4774,  4784,  4787,
    4790,  4793,  4802,  4805,  4814,  4817,  4826,  4829,  4838,  4841,
    4850,  4853,  4856,  4865,  4868,  4877,  4881,  4891,  4894,  4897,
    4900,  4903,  4912,  4921,  4925,  4929,  4933,  4937,  4941,  4945,
    4955,  4958,  4961,  4964,  4973,  4976,  4979,  4982,  4991,  4994,
    5003,  5006,  5009,  5012,  5015,  5018,  5021,  5030,  5033,  5042,
    5045,  5048,  5051,  5060,  5063,  5066,  5069,  5072,  5081,  5084,
    5093,  5096,  5105,  5108,  5117,  5120,  5129,  5138,  5141,  5150,
    5153,  5156,  5165,  5168,  5171,  5174,  5177,  5186,  5190,  5194,
    5198,  5208,  5217,  5227,  5236,  5239,  5248,  5251,  5254,  5263,
    5266,  5275
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
  const int xquery_parser::yylast_ = 7657;
  const int xquery_parser::yynnts_ = 231;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 424;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 272;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 526;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5283 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


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

