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
                                  new ContextItemExpr(LOC((yyloc)), true),
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
                           NULL,
                           true);
		;}
    break;

  case 453:
#line 4181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
                           NULL,
                           true);
		;}
    break;

  case 454:
#line 4188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		;}
    break;

  case 455:
#line 4195 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		;}
    break;

  case 456:
#line 4202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 457:
#line 4209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		;}
    break;

  case 458:
#line 4216 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 459:
#line 4229 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 460:
#line 4250 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 461:
#line 4257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 462:
#line 4277 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 463:
#line 4317 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 464:
#line 4322 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 465:
#line 4325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 466:
#line 4333 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 467:
#line 4339 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 468:
#line 4345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 469:
#line 4351 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 470:
#line 4357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 471:
#line 4364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 472:
#line 4370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 473:
#line 4376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 474:
#line 4382 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 475:
#line 4388 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 476:
#line 4400 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 477:
#line 4405 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 478:
#line 4415 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 479:
#line 4421 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 480:
#line 4433 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 481:
#line 4459 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 482:
#line 4470 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 483:
#line 4476 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 484:
#line 4489 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 485:
#line 4503 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 486:
#line 4510 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 487:
#line 4517 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 488:
#line 4528 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 489:
#line 4535 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 490:
#line 4543 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 491:
#line 4552 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4568 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4585 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 495:
#line 4586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty"); ;}
    break;

  case 496:
#line 4587 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("attribute"); ;}
    break;

  case 497:
#line 4588 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("comment"); ;}
    break;

  case 498:
#line 4589 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document-node"); ;}
    break;

  case 499:
#line 4590 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("element"); ;}
    break;

  case 500:
#line 4591 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("item"); ;}
    break;

  case 501:
#line 4592 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("if"); ;}
    break;

  case 502:
#line 4593 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("node"); ;}
    break;

  case 503:
#line 4594 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("processing-instruction"); ;}
    break;

  case 504:
#line 4595 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-attribute"); ;}
    break;

  case 505:
#line 4596 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-element"); ;}
    break;

  case 506:
#line 4597 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("text"); ;}
    break;

  case 507:
#line 4598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("typeswitch"); ;}
    break;

  case 508:
#line 4599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty-sequence"); ;}
    break;

  case 509:
#line 4600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("boundary-space"); ;}
    break;

  case 510:
#line 4601 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ft-option"); ;}
    break;

  case 511:
#line 4602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("base-uri"); ;}
    break;

  case 512:
#line 4603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lax"); ;}
    break;

  case 513:
#line 4604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strict"); ;}
    break;

  case 514:
#line 4605 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("idiv"); ;}
    break;

  case 515:
#line 4606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document"); ;}
    break;

  case 516:
#line 4607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("not"); ;}
    break;

  case 517:
#line 4608 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sensitive"); ;}
    break;

  case 518:
#line 4609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insensitive"); ;}
    break;

  case 519:
#line 4610 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("diacritics"); ;}
    break;

  case 520:
#line 4611 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("without"); ;}
    break;

  case 521:
#line 4612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stemming"); ;}
    break;

  case 522:
#line 4613 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("thesaurus"); ;}
    break;

  case 523:
#line 4614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stop"); ;}
    break;

  case 524:
#line 4615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("wildcards"); ;}
    break;

  case 525:
#line 4616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("entire"); ;}
    break;

  case 526:
#line 4617 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("content"); ;}
    break;

  case 527:
#line 4618 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("word"); ;}
    break;

  case 528:
#line 4619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("start"); ;}
    break;

  case 529:
#line 4620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("end"); ;}
    break;

  case 530:
#line 4621 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("most"); ;}
    break;

  case 531:
#line 4622 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("skip"); ;}
    break;

  case 532:
#line 4623 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy"); ;}
    break;

  case 533:
#line 4624 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("value"); ;}
    break;

  case 534:
#line 4625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("eq"); ;}
    break;

  case 535:
#line 4626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ne"); ;}
    break;

  case 536:
#line 4627 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lt"); ;}
    break;

  case 537:
#line 4628 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("le"); ;}
    break;

  case 538:
#line 4629 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("gt"); ;}
    break;

  case 539:
#line 4630 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ge"); ;}
    break;

  case 540:
#line 4631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("at"); ;}
    break;

  case 541:
#line 4632 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("variable"); ;}
    break;

  case 542:
#line 4633 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("return"); ;}
    break;

  case 543:
#line 4634 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("for"); ;}
    break;

  case 544:
#line 4635 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("outer"); ;}
    break;

  case 545:
#line 4636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sliding"); ;}
    break;

  case 546:
#line 4637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("tumbling"); ;}
    break;

  case 547:
#line 4638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("previous"); ;}
    break;

  case 548:
#line 4639 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("next"); ;}
    break;

  case 549:
#line 4640 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("only"); ;}
    break;

  case 550:
#line 4641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("when"); ;}
    break;

  case 551:
#line 4642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("count"); ;}
    break;

  case 552:
#line 4643 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("in"); ;}
    break;

  case 553:
#line 4644 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("let"); ;}
    break;

  case 554:
#line 4645 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("where"); ;}
    break;

  case 555:
#line 4646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("by"); ;}
    break;

  case 556:
#line 4647 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("group"); ;}
    break;

  case 557:
#line 4648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("order"); ;}
    break;

  case 558:
#line 4649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stable"); ;}
    break;

  case 559:
#line 4650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ascending"); ;}
    break;

  case 560:
#line 4651 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("descending"); ;}
    break;

  case 561:
#line 4652 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("greatest"); ;}
    break;

  case 562:
#line 4653 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("least"); ;}
    break;

  case 563:
#line 4654 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("collation"); ;}
    break;

  case 564:
#line 4655 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("some"); ;}
    break;

  case 565:
#line 4656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("every"); ;}
    break;

  case 566:
#line 4657 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("satisfies"); ;}
    break;

  case 567:
#line 4658 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("case"); ;}
    break;

  case 568:
#line 4659 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("as"); ;}
    break;

  case 569:
#line 4660 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("then"); ;}
    break;

  case 570:
#line 4661 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("else"); ;}
    break;

  case 571:
#line 4662 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("or"); ;}
    break;

  case 572:
#line 4663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("and"); ;}
    break;

  case 573:
#line 4664 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("instance"); ;}
    break;

  case 574:
#line 4665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("of"); ;}
    break;

  case 575:
#line 4666 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("castable"); ;}
    break;

  case 576:
#line 4667 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("to"); ;}
    break;

  case 577:
#line 4668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("div"); ;}
    break;

  case 578:
#line 4669 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("mod"); ;}
    break;

  case 579:
#line 4670 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("union"); ;}
    break;

  case 580:
#line 4671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("intersect"); ;}
    break;

  case 581:
#line 4672 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("except"); ;}
    break;

  case 582:
#line 4673 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("validate"); ;}
    break;

  case 583:
#line 4674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cast"); ;}
    break;

  case 584:
#line 4675 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("treat"); ;}
    break;

  case 585:
#line 4676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("is"); ;}
    break;

  case 586:
#line 4677 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("preserve"); ;}
    break;

  case 587:
#line 4678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strip"); ;}
    break;

  case 588:
#line 4679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("namespace"); ;}
    break;

  case 589:
#line 4680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("external"); ;}
    break;

  case 590:
#line 4681 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("encoding"); ;}
    break;

  case 591:
#line 4682 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-preserve"); ;}
    break;

  case 592:
#line 4683 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("inherit"); ;}
    break;

  case 593:
#line 4684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-inherit"); ;}
    break;

  case 594:
#line 4685 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("declare"); ;}
    break;

  case 595:
#line 4686 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("construction"); ;}
    break;

  case 596:
#line 4687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordering"); ;}
    break;

  case 597:
#line 4688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("default"); ;}
    break;

  case 598:
#line 4689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy-namespaces"); ;}
    break;

  case 599:
#line 4690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("option"); ;}
    break;

  case 600:
#line 4691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("version"); ;}
    break;

  case 601:
#line 4692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("import"); ;}
    break;

  case 602:
#line 4693 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema"); ;}
    break;

  case 603:
#line 4694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("function"); ;}
    break;

  case 604:
#line 4695 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("score"); ;}
    break;

  case 605:
#line 4696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ftcontains"); ;}
    break;

  case 606:
#line 4697 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("weight"); ;}
    break;

  case 607:
#line 4698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("window"); ;}
    break;

  case 608:
#line 4699 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("distance"); ;}
    break;

  case 609:
#line 4700 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("occurs"); ;}
    break;

  case 610:
#line 4701 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("times"); ;}
    break;

  case 611:
#line 4702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("same"); ;}
    break;

  case 612:
#line 4703 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("different"); ;}
    break;

  case 613:
#line 4704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lowercase"); ;}
    break;

  case 614:
#line 4705 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("uppercase"); ;}
    break;

  case 615:
#line 4706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("relationship"); ;}
    break;

  case 616:
#line 4707 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("levels"); ;}
    break;

  case 617:
#line 4708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("language"); ;}
    break;

  case 618:
#line 4709 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("any"); ;}
    break;

  case 619:
#line 4710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("all"); ;}
    break;

  case 620:
#line 4711 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("phrase"); ;}
    break;

  case 621:
#line 4712 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exactly"); ;}
    break;

  case 622:
#line 4713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("from"); ;}
    break;

  case 623:
#line 4714 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("words"); ;}
    break;

  case 624:
#line 4715 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentences"); ;}
    break;

  case 625:
#line 4716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentence"); ;}
    break;

  case 626:
#line 4717 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("paragraph"); ;}
    break;

  case 627:
#line 4718 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("replace"); ;}
    break;

  case 628:
#line 4719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("modify"); ;}
    break;

  case 629:
#line 4720 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("first"); ;}
    break;

  case 630:
#line 4721 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insert"); ;}
    break;

  case 631:
#line 4722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("bofer"); ;}
    break;

  case 632:
#line 4723 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("after"); ;}
    break;

  case 633:
#line 4724 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("revalidation"); ;}
    break;

  case 634:
#line 4725 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("with"); ;}
    break;

  case 635:
#line 4726 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("nodes"); ;}
    break;

  case 636:
#line 4727 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("rename"); ;}
    break;

  case 637:
#line 4728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("last"); ;}
    break;

  case 638:
#line 4729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("delete"); ;}
    break;

  case 639:
#line 4730 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("into"); ;}
    break;

  case 640:
#line 4731 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("updating"); ;}
    break;

  case 641:
#line 4732 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordered"); ;}
    break;

  case 642:
#line 4733 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("unordered"); ;}
    break;

  case 643:
#line 4745 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 644:
#line 4751 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 645:
#line 4768 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 646:
#line 4772 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 647:
#line 4776 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 648:
#line 4780 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 649:
#line 4790 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 650:
#line 4793 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 651:
#line 4796 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 652:
#line 4799 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 653:
#line 4808 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 654:
#line 4811 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 655:
#line 4820 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 656:
#line 4823 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 657:
#line 4832 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 658:
#line 4835 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 659:
#line 4844 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 660:
#line 4847 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 661:
#line 4856 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 662:
#line 4859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 663:
#line 4862 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 664:
#line 4871 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 665:
#line 4874 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 666:
#line 4883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 667:
#line 4887 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, static_cast<Expr *> ((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 668:
#line 4897 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 669:
#line 4900 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 670:
#line 4903 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 671:
#line 4906 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 672:
#line 4909 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 673:
#line 4918 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 674:
#line 4927 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 675:
#line 4931 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 676:
#line 4935 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 677:
#line 4939 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 678:
#line 4943 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 679:
#line 4947 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 680:
#line 4951 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 681:
#line 4961 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 682:
#line 4964 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 683:
#line 4967 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 684:
#line 4970 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 685:
#line 4979 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 686:
#line 4982 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 687:
#line 4985 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 688:
#line 4988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 689:
#line 4997 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 690:
#line 5000 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 691:
#line 5009 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 692:
#line 5012 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 693:
#line 5015 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 694:
#line 5018 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 695:
#line 5021 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 696:
#line 5024 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 697:
#line 5027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 698:
#line 5036 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 699:
#line 5039 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 700:
#line 5048 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 701:
#line 5051 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 702:
#line 5054 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 703:
#line 5057 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 704:
#line 5066 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 705:
#line 5069 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 706:
#line 5072 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 707:
#line 5075 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 708:
#line 5078 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 709:
#line 5087 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 710:
#line 5090 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 711:
#line 5099 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 712:
#line 5102 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 713:
#line 5111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 714:
#line 5114 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 715:
#line 5123 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 716:
#line 5126 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 717:
#line 5135 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 718:
#line 5144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 719:
#line 5147 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 720:
#line 5156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 721:
#line 5159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 722:
#line 5162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 723:
#line 5171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 724:
#line 5174 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 725:
#line 5177 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 726:
#line 5180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 727:
#line 5183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 728:
#line 5192 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 729:
#line 5196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 730:
#line 5200 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 731:
#line 5204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 732:
#line 5214 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 733:
#line 5223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 734:
#line 5233 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 735:
#line 5242 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 736:
#line 5245 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 737:
#line 5254 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 738:
#line 5257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 739:
#line 5260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 740:
#line 5269 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 741:
#line 5272 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 742:
#line 5281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6472 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -926;
  const short int
  xquery_parser::yypact_[] =
  {
      1238,  -926,  -926,  -926,  -926,   -99,   339,   134,   365,   350,
    5955,   183,   265,   500,    27,  -926,  -926,   387,   101,  -926,
     407,   431,  -926,   283,  -926,  -926,  -926,   460,  -926,   437,
     416,   523,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
     573,  -926,   491,   504,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  6196,  -926,  5222,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  7401,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,   505,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    4226,  1487,  7401,  -926,  -926,  -926,  -926,  -926,  -926,   515,
    -926,  -926,  -926,  -926,   646,  -926,  5714,  -926,  -926,  -926,
    -926,  -926,  7401,  -926,  -926,  4973,  -926,  -926,  -926,  -926,
    -926,  -926,   544,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,    22,   494,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,   -69,   551,   415,  -926,   487,   409,  -926,  -926,  -926,
    -926,  -926,  -926,   594,  -926,   566,   613,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,   717,  1736,  -926,  -926,   312,  4226,   553,
     555,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,   635,  -926,  -926,  -926,  -926,
     329,  7401,  -926,  -926,  -926,  -926,  -926,   581,   655,  -926,
     470,   496,   411,   310,   406,   180,  -926,   662,   556,   649,
     650,  4475,  -926,  -926,  -926,   371,  -926,  -926,  4973,  -926,
     495,  -926,   603,  5222,  -926,   603,  5222,  -926,  -926,  -926,
    -926,   603,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
     602,  -926,  4226,  -926,  4226,  4226,   606,   607,   608,  4226,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  4226,  6437,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,   609,  4226,
    4226,   577,  4226,   578,  7401,   706,   707,  7401,   287,   -52,
     726,   143,   424,   647,   253,   730,   467,    67,  4226,  -926,
    4226,    56,   617,    41,    38,  7401,   730,  7401,  4226,   498,
     499,  -926,   652,   653,  -926,  7401,    49,  4226,  6678,   622,
     620,   621,   623,   624,   625,  -926,  -926,  -926,  7401,  1985,
     -21,  -926,    -5,   732,  4226,    29,  -926,   747,   599,  -926,
    4226,   572,  -926,   746,  4226,  4226,   604,  4226,  4226,  4226,
    4226,   557,  7401,  4226,  7401,  -926,  -926,  -926,    27,   407,
    -926,  -926,   312,   733,  4226,   626,   460,   416,   523,   671,
     627,   629,  4226,  4226,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,   682,  -926,   -20,  4724,  4724,  4724,  -926,  4724,  4724,
    -926,  4724,  -926,  4724,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  4724,  4724,     9,  4724,  4724,  4724,  4724,  4724,  4724,
    4724,  4724,  4724,  4724,  4724,   562,   698,   702,   703,  -926,
    -926,  -926,  2234,  -926,  -926,  4973,  4973,  4226,   603,  -926,
    -926,   603,  -926,   603,  2483,  -926,   616,    79,  4226,  4226,
    4226,    11,   174,  -926,    81,    98,  2732,   190,   208,  -926,
     220,  -926,   648,  7401,  7401,   762,  -926,  -926,  -926,  -926,
    -926,  -926,   694,   695,  -926,  -926,  7401,   651,   654,   726,
     679,   675,  -926,  -926,  -926,   420,   198,   435,   768,  -926,
    -926,   358,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
     112,   263,   630,  -926,   631,  2981,   730,   710,   758,   730,
     726,   713,    -2,  -926,    32,   686,   704,  -926,   -36,   638,
    -926,  -926,  7401,   -11,  -926,   642,   620,   491,  -926,   643,
     644,   313,  -926,   172,   175,  3230,     4,  -926,   -12,  -926,
    -926,  7401,   732,  -926,   137,   314,  -926,  -926,  -926,  -926,
     322,  -926,   142,  -926,  -926,  -926,   -26,   -14,   725,   586,
     605,   -17,  -926,   689,   664,    61,  -926,  -926,   658,  -926,
      16,  -926,  -926,   666,  7401,  4226,   716,  -926,  -926,   724,
    7160,   728,  4226,   729,   -42,   687,    -9,   655,  -926,  -926,
    -926,  -926,  -926,  4724,  -926,  -926,  -926,  4226,     9,   197,
    -926,   564,   450,   597,   598,  -926,  -926,   589,   408,   310,
     310,   167,   406,   406,   406,   406,   180,   180,  -926,  -926,
    7160,  7160,  7401,  7401,  -926,   337,  -926,  -926,     2,  -926,
    -926,  -926,   176,   700,  -926,   359,   368,   370,   750,   705,
    7401,  -926,  7401,  -926,  -926,   375,  -926,  -926,  -926,   200,
     278,   648,   648,  -926,   354,   443,   472,   726,   726,  -926,
     576,   726,  -926,  -926,   580,  -926,  -926,   582,   446,  -926,
    -926,  -926,  -926,  -926,  -926,   583,  -926,  -926,   660,   708,
    -926,  -926,  -926,   380,   731,   726,   709,   734,   766,   726,
     741,  4226,  4226,   721,   726,   749,  4226,   735,   -54,  -926,
     357,   628,  -926,  -926,   517,   -11,  -926,  -926,  -926,   718,
    7401,  -926,  7401,  -926,  -926,   381,  4226,  -926,   826,  -926,
     216,  -926,   103,  -926,  -926,   832,  -926,   468,  4226,  4226,
    4226,   469,  4226,  4226,  4226,  4226,  4226,  4226,   753,  4226,
    4226,   636,   722,   756,   733,  4226,  -926,    45,   769,  -926,
    7401,   771,  -926,  7401,   736,   737,  -926,   338,  -926,  -926,
    -926,  7401,  -926,  7401,  4226,   738,  4226,  4226,   -22,   740,
    -926,   382,   711,  -926,   632,  -926,   -77,  -926,   360,    26,
     639,     9,   360,  4724,  4724,   191,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,     9,   742,    26,  -926,   611,   820,  -926,
    -926,  -926,  -926,  -926,   754,  -926,  -926,  -926,  4226,  -926,
    -926,  -926,  -926,  -926,  6919,   445,  -926,  3479,   712,   714,
     757,   715,   720,  -926,  7401,   797,   192,  -926,  -926,  4226,
    -926,   334,   700,  -926,  -926,  -926,  -926,  -926,  4226,   528,
    -926,  -926,  -926,  -926,  -926,   633,   173,   862,  -926,   456,
    -926,  -926,  4226,  3728,  -926,   726,   793,  -926,  -926,  -926,
     726,   793,  7401,  -926,  -926,  4226,   723,  7401,  -926,  4226,
    4226,   764,  4226,   761,  -926,   790,   791,  4226,  7401,   637,
     831,  -926,  -926,  -926,  3977,   739,  -926,   743,  -926,  -926,
    -926,   782,  -926,   170,  -926,  -926,   889,  -926,  -926,  4226,
    7401,  -926,  -926,   182,  -926,  -926,  -926,   727,   684,   685,
    -926,  -926,  -926,   688,   690,  -926,  -926,  -926,  -926,  -926,
     683,  7401,   745,  -926,   767,   636,  -926,  4226,  7401,   769,
    -926,   726,  -926,   596,  -926,    35,   810,  -926,  4226,   816,
     716,  -926,   751,   752,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  4226,  -926,  -926,  4226,   780,  4226,  -926,  -926,  4724,
    -926,  -926,  -926,  -926,  -926,   308,  4724,  4724,   316,  -926,
     597,  -926,  -926,   -81,  4724,  -926,  -926,   598,     9,   661,
    -926,  -926,  -926,  -926,  7401,   748,   -19,  -926,  -926,   390,
    -926,  -926,  -926,  -926,  -926,   830,  7160,   811,   837,   397,
    -926,  -926,  -926,  -926,  -926,  4226,   -16,   895,   899,   -16,
      28,   193,   199,   814,  -926,   399,   842,   726,   793,  -926,
    -926,  -926,  -926,  -926,  -926,  4226,  -926,  4226,  7401,  7401,
    -926,    80,  -926,  4226,  -926,   400,  -926,  -926,   826,  7401,
     241,  -926,   401,   826,  7401,  -926,  -926,  4226,  4226,  4226,
    4226,  4226,  -926,  4226,  5471,  -926,   760,  -926,  -926,  -926,
    -926,   810,  -926,  -926,  -926,   726,  -926,  -926,  -926,  -926,
    -926,  -926,  4226,  -926,   406,  4724,  4724,   406,   459,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,   846,  4226,  7401,
    4226,  -926,  -926,  -926,  -926,  7160,  -926,  -926,   173,   173,
     -16,  -926,  -926,  -926,    42,   -16,   904,   691,   847,  -926,
     847,  -926,  4226,  -926,   726,  -926,  -926,  -926,   865,  -926,
    -926,  -926,  -926,     1,   826,  7401,  -926,   759,   826,  -926,
    -926,  -926,  -926,  -926,  -926,   204,  -926,  -926,  -926,  -926,
     406,   406,  4724,  7160,  -926,   763,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,    26,  -926,   223,  -926,   229,  -926,   793,
     828,   327,   106,  -926,   765,   826,  -926,   770,   833,   799,
     406,   772,  4226,   693,   847,  -926,  -926,  7401,  -926,  -926,
     859,   442,  -926,  -926,  -926,  -926,   776,   364,  -926,  -926,
    -926,   773,  -926,  7401,  -926,  4226,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,   233,  -926,   838,
     799,  7401,  -926,   234,   839,   799,  7401,  -926,   777,   799,
    -926
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   315,   316,   494,   462,     0,     0,     0,   582,   507,
     499,   515,   506,   497,   594,   603,   640,   501,   503,   530,
     601,   564,   558,     0,   599,   527,   602,   553,   595,     0,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   596,
       0,   511,   505,   498,   598,   573,   504,   509,   306,   309,
     572,   568,   559,   540,   496,   296,     0,   567,   575,   583,
     294,   563,   332,   541,   597,   295,   298,   560,   577,     0,
     338,   304,   334,   570,   495,   561,   562,   590,   565,   581,
     589,   300,   299,   514,   552,   592,   333,   580,   585,   500,
       0,     0,     0,   253,   578,   588,   593,   591,   571,   641,
     557,   555,   556,   305,     0,   252,     0,   308,   307,   586,
     542,   566,     0,   297,   282,     0,   314,   587,   569,   576,
     584,   579,   642,   534,   539,   538,   537,   536,   535,   508,
     554,     0,     0,   600,   528,   632,   631,   633,   513,   512,
     531,   638,   502,   630,   635,   636,   627,   533,   574,   629,
     639,   637,   628,   532,   634,     0,     0,   619,   618,   517,
     510,   519,   518,   612,   608,   525,   529,   526,   621,   622,
     605,   516,   617,   616,   613,   609,   626,   620,   615,   611,
     604,   625,   624,   610,   614,   606,   607,   520,   521,   523,
     623,   522,   524,     0,     0,     2,     4,     0,     0,     0,
       0,    15,    17,    19,    20,    21,    27,    22,    25,    26,
      31,    32,    33,    28,    29,    35,    36,    23,    30,   112,
     109,   110,   111,    24,     9,    94,    95,    97,   127,   133,
       0,     0,   125,   126,    98,    99,   100,   101,   209,   211,
     213,   223,   226,   228,   231,   236,   239,   242,   244,   246,
     248,     0,   250,   256,   258,     0,   274,   257,   278,   281,
     283,   286,   288,     0,   293,   290,     0,   301,   311,   313,
     287,   317,   322,   330,   323,   324,   325,   328,   329,   326,
     327,   345,   347,   348,   349,   346,   394,   395,   396,   397,
     398,   399,   310,   436,   428,   435,   434,   433,   430,   432,
     429,   431,   331,    34,   102,   103,   105,   104,   106,   107,
     312,   108,     0,    81,     0,     0,     0,     0,     0,     0,
     582,   507,   499,   515,   506,   497,   594,   501,   503,   601,
     564,   553,   543,   544,   505,   498,   496,   565,     0,     0,
     641,   642,   638,   502,   630,   636,   627,   532,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   493,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,     0,     0,    82,     0,     0,     0,     0,     0,
     499,   506,   497,   503,   496,   302,   312,   335,     0,     0,
       0,   336,     0,   361,     0,     0,   277,     0,     0,   280,
       0,     0,   390,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     3,     5,     0,     0,
      10,     8,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,   132,   128,   134,   129,   131,
     130,   137,   138,     0,     0,     0,     0,   267,     0,     0,
     265,     0,   218,     0,   266,   259,   264,   263,   262,   261,
     260,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     254,   251,     0,   275,   279,     0,     0,     0,   289,   319,
     292,   291,   303,   318,     0,    79,     0,     0,     0,     0,
       0,     0,     0,   452,     0,     0,     0,     0,     0,   441,
       0,   442,     0,     0,     0,     0,    70,    71,    44,    45,
     492,    53,     0,     0,    38,    39,     0,     0,     0,     0,
       0,     0,   463,   464,   465,     0,     0,     0,     0,   681,
     682,     0,    43,   674,   675,   676,   677,   678,   679,   680,
       0,     0,     0,   443,     0,     0,     0,    62,     0,     0,
       0,    54,     0,   198,     0,     0,   150,   151,     0,     0,
     115,   116,     0,     0,   136,     0,     0,     0,   438,     0,
       0,     0,   446,     0,     0,     0,     0,    76,     0,    77,
     337,   362,   361,   358,     0,     0,   392,   391,   276,   451,
       0,   389,     0,   476,   477,   437,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,   153,   170,     0,    16,
       0,    18,    96,     0,     0,     0,     0,   114,   171,     0,
       0,     0,     0,     0,     0,     0,     0,   210,   212,   216,
     222,   221,   220,     0,   217,   214,   215,     0,     0,     0,
     666,   224,   645,   653,   655,   657,   659,   661,   664,   230,
     229,   227,   233,   234,   235,   232,   237,   238,   241,   240,
       0,     0,     0,     0,   272,     0,   284,   285,     0,   320,
     341,   343,     0,     0,   268,     0,     0,     0,     0,     0,
       0,   456,     0,   453,   401,     0,   400,   409,   410,     0,
       0,     0,     0,    42,     0,     0,     0,     0,     0,    52,
       0,     0,   683,   684,     0,   685,   689,     0,     0,   718,
     687,   688,   717,   686,   690,     0,   697,   719,     0,     0,
     445,   444,   411,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   644,
       0,     0,   117,   118,     0,   123,   459,   439,   440,     0,
       0,   449,     0,   447,   405,     0,     0,    78,   361,   359,
       0,   350,     0,   339,   340,     0,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,   124,   182,   178,   180,
       0,   172,   173,     0,   500,   508,   417,   418,   424,   425,
     427,     0,   140,     0,     0,     0,     0,     0,     0,     0,
     219,     0,     0,   660,     0,   225,     0,   673,     0,     0,
       0,     0,     0,     0,     0,   646,   650,   668,   649,   672,
     670,   669,   671,     0,     0,     0,   662,   725,   723,   727,
     665,   243,   245,   247,   415,   249,   273,   321,     0,   342,
      80,   269,   270,   271,     0,     0,   204,     0,     0,     0,
     460,     0,     0,   402,     0,    72,     0,    88,    83,     0,
      84,     0,     0,    50,    51,    48,    49,    67,     0,     0,
      40,    41,    46,    47,    37,     0,     0,     0,   692,     0,
     691,   708,     0,     0,   412,     0,    64,    58,    61,    60,
       0,    56,     0,   196,   200,     0,     0,     0,   155,     0,
       0,     0,     0,     0,   119,     0,     0,     0,     0,   164,
       0,   161,   166,   122,     0,     0,   460,     0,   406,   197,
     362,     0,   351,     0,   385,   382,     0,   386,   387,     0,
       0,   388,   381,     0,   356,   384,   383,     0,     0,     0,
     469,   470,   466,     0,     0,   474,   475,   471,   480,   478,
       0,     0,     0,   484,     0,   485,   486,     0,     0,   179,
     191,     0,   192,     0,   183,   184,   185,   186,     0,   175,
       0,   139,     0,     0,   421,   423,   422,   419,   148,   149,
     142,     0,   144,   141,     0,     0,     0,   667,   663,     0,
     720,   721,   741,   740,   736,     0,     0,     0,     0,   722,
     654,   735,   647,     0,     0,   652,   651,   656,     0,     0,
     726,   724,   416,   344,     0,     0,     0,   205,   403,     0,
     457,   458,   461,   454,   455,    90,     0,     0,    73,     0,
      85,    86,    87,    66,    69,     0,   706,     0,     0,   704,
     700,     0,     0,     0,   413,     0,    63,     0,    57,   199,
     201,    11,   152,   157,   156,     0,   159,     0,     0,     0,
     121,   162,   165,     0,   407,     0,   450,   448,   361,     0,
       0,   393,     0,   361,     0,   357,     7,     0,     0,     0,
       0,     0,   483,     0,     0,   487,     0,   154,   195,   193,
     194,   187,   188,   189,   181,     0,   176,   174,   426,   420,
     146,   143,     0,   145,   742,     0,     0,   728,     0,   739,
     738,   737,   732,   733,   648,   658,   734,     0,     0,     0,
       0,   404,    91,    74,    89,     0,    93,    68,     0,     0,
     707,   709,   711,   713,     0,   705,     0,     0,     0,   695,
       0,   693,     0,   414,     0,    59,   158,   160,   169,   168,
     163,   120,   408,     0,   361,     0,    92,     0,   361,   467,
     468,   472,   473,   479,   481,     0,   643,   190,   177,   147,
     730,   729,     0,     0,   206,     0,   202,    75,   716,   715,
     710,   714,   712,   701,   702,     0,   698,     0,   208,    65,
       0,   371,   365,   360,     0,   361,   352,     0,     0,     0,
     731,     0,     0,     0,     0,   696,   694,     0,   379,   373,
       0,   372,   374,   380,   377,   367,     0,   366,   368,   378,
     354,     0,   353,     0,   488,     0,   203,   703,   699,   167,
     364,   375,   376,   363,   369,   370,   355,     0,   207,     0,
       0,     0,   489,     0,     0,     0,     0,   490,     0,     0,
     491
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -926,  -926,  -926,   755,   774,  -926,   775,  -926,   508,   510,
    -425,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -747,  -926,  -926,  -926,  -926,    -6,
    -663,  -926,  -926,  -926,  -926,  -926,  -926,  -112,  -926,  -869,
     778,   -72,  -289,  -926,  -926,  -926,  -926,   181,  -926,  -926,
     744,  -926,  -926,  -926,  -926,  -926,   135,  -424,  -558,  -926,
    -926,  -926,    24,  -926,  -926,  -139,    14,   -34,  -926,  -926,
    -926,   -45,  -926,  -926,   151,   -41,  -926,  -926,   -37,  -925,
    -926,   561,    39,  -926,  -926,    85,  -926,  -926,   509,   507,
    -926,  -420,  -810,   488,   236,  -474,   226,   230,  -926,  -926,
    -926,  -926,  -926,   719,  -926,  -926,  -926,  -926,  -926,   781,
    -926,  -926,   -91,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
     -35,  -149,  -926,  -926,   284,   119,  -926,  -464,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -751,  -926,    20,
    -926,   367,  -586,  -926,  -926,  -926,  -926,  -926,  -280,  -266,
    -918,  -614,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,   294,  -561,  -670,  -926,  -926,    33,  -633,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,   593,   595,  -624,   280,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,    -1,  -926,
    -926,     0,  -359,  -339,   -10,  -926,   325,  -926,  -926,   145,
     131,   -51,   330,  -926,  -926,   146,  -926,  -628,  -926,  -926,
    -926,  -926,  -182,  -716,  -926,   -79,  -439,  -926,  -502,  -926,
    -926,  -926,  -926,  -828,  -926,  -926,  -926,  -926,   -40,   150,
    -926
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   916,   570,   216,   217,   218,   710,
     219,   399,   220,   221,   222,   223,   886,   887,   961,   890,
     224,   225,   226,   227,   444,   382,   764,   765,   228,   445,
     229,   447,   230,   231,   232,   451,   452,   939,   645,   233,
     576,   625,   577,   583,   940,   941,   942,   626,   448,   449,
     811,   812,  1126,   450,   808,   809,   994,   995,   996,   997,
     234,   572,   573,   235,   875,   876,   236,   237,   238,   239,
     653,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   471,   472,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   498,   499,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   692,   280,   281,   282,   963,
     602,   603,   604,  1223,  1246,  1247,  1240,  1241,  1248,  1242,
     964,   965,   283,   284,   966,   285,   286,   287,   288,   289,
     290,   291,   863,   646,   816,  1007,   817,   818,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   878,   879,
     302,   303,   304,   305,   306,   307,   308,   621,   622,   309,
     985,   986,   917,   372,   310,   311,   661,   845,   662,   663,
     664,   665,   666,   667,   668,   846,   847,   552,   553,   554,
     555,   556,  1215,  1216,   557,  1160,  1069,  1164,  1161,   558,
     559,   849,   860,  1028,   850,   851,   856,   852,  1142,  1024,
     835
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       348,   531,   921,   672,   673,   674,   675,   819,   631,   660,
     861,   862,   910,   753,   567,   571,   780,   758,   400,   402,
     757,   395,  1061,   505,   409,   506,   541,  1039,     4,   644,
     870,   962,   564,  1032,   848,   606,   649,   575,   650,   651,
     640,   652,   411,   654,   389,  1105,   396,   819,   819,   761,
     787,   655,   656,   354,   355,   356,   640,   530,   641,   397,
     530,  1211,   791,   357,   354,   355,   356,   930,   434,   641,
    1122,  1123,   798,   369,   357,   562,  1221,   434,   881,   358,
    1149,   586,   403,   824,   434,   756,   825,   750,   829,   579,
     359,   434,   360,   750,   528,   361,   407,   481,   362,  1158,
     434,    62,   408,  1014,  1025,   642,  1025,   482,   640,   363,
     954,   955,    72,   954,   802,   587,   827,   312,   369,  1020,
     363,   364,   990,   991,  1244,   613,   614,   529,   616,   617,
     618,   619,   568,   991,   624,   414,    86,   415,   935,   936,
     657,   993,   992,   658,  1150,   632,   945,   599,   947,   545,
     803,   993,  1021,   637,   638,   899,   777,   752,   641,   600,
    1139,  1222,  1159,   751,   867,   365,  1140,   494,   434,   776,
     700,   788,   789,  1078,  1141,   698,   569,   954,   955,   566,
     719,   607,  1105,   792,   793,   762,   790,   702,   956,   954,
     955,   643,   951,  1072,   660,   660,  1197,   799,   794,   933,
     931,   434,   962,   643,  1045,   957,  1212,   958,   957,   643,
     958,   748,   962,   588,   412,   691,     4,  1036,   763,  1245,
     563,   453,   828,   643,  1144,   643,   366,   744,   500,  1062,
     747,   502,   370,   830,   959,   371,   643,   959,    92,   367,
     694,   819,  1167,   507,   659,   701,   781,   511,   954,   955,
     367,  1067,   785,   396,   104,   956,   396,  1026,  1027,  1026,
    1027,   770,   703,   434,   772,   868,   512,   956,   314,   836,
    1015,  1166,   957,   545,   958,   960,   738,   517,   518,   434,
     520,  1057,  1168,   546,   957,   537,   958,   532,  1170,    62,
     538,   547,   724,  1228,   131,   483,   560,   434,   561,   884,
      72,   959,   533,   474,   548,    92,   549,  1068,   484,   434,
     786,   782,  1234,   959,   349,   591,   550,    92,  1234,   551,
     475,   104,  1269,  1274,    86,   952,   956,   598,   657,   515,
    1238,   658,   605,   104,   954,   699,   771,   837,   610,   773,
     869,   539,  1099,   957,   522,   958,   807,   525,   428,   962,
    1135,   706,   434,   822,  1104,   429,  1058,  1169,   900,   901,
    1254,   131,   904,  1171,   885,   574,   313,   578,  1229,   707,
    1033,   954,   959,   131,   435,   585,    92,   660,   594,   631,
     436,   708,  1244,   437,   438,  1233,  1153,  1235,   574,   660,
     953,   439,   104,  1236,   888,   926,   350,  1270,  1275,   351,
     540,  1272,   434,   434,   686,   687,  1277,   546,   477,   889,
    1280,   434,   623,  1185,   627,   547,  1136,   838,   839,   840,
     685,   376,   725,   819,   739,   688,   434,  1219,   548,   957,
     549,   958,   131,   640,   478,   842,   695,   696,   697,  1239,
     550,  1034,   844,   551,   705,  1238,   526,   479,   434,   954,
    1060,   726,   727,   373,   728,   729,   374,   434,   959,   434,
     527,  1004,   923,   924,   434,   889,   957,   928,   958,   434,
     434,   434,   379,   380,   769,   783,   440,  1264,   441,   434,
     893,   480,   932,   784,   319,  1207,   434,   949,   434,   434,
     434,  1005,   442,   743,  1152,   959,   315,   894,   866,   970,
     971,   972,   492,   975,   976,   977,   978,   979,   980,  1006,
     982,   983,  1183,   711,   712,   381,   807,  1187,  1258,   443,
     871,   368,   819,   775,   907,   106,   716,   874,   836,   872,
     375,   873,   545,  1231,   907,  1010,   883,  1012,  1013,  1046,
     908,   914,   948,  1017,   957,  1134,   958,   474,   640,   501,
    1071,  1151,  1137,  1138,  1261,   503,  1076,  1139,  1156,   377,
    1173,  1182,  1186,  1140,   475,   316,   317,   318,   378,   895,
     819,  1141,   760,   959,   660,   935,   936,   383,   937,  1043,
     909,   456,   733,   534,   481,   831,   896,   476,   897,   457,
     458,   778,   459,   898,   482,   641,   837,   535,  1224,   460,
     384,  1022,  1227,   461,   398,   462,  1023,  1243,  1249,  1063,
     463,   734,   735,   420,   736,   737,   938,   689,   421,   417,
     689,   418,   689,  1073,   806,   385,   464,  1243,   857,   858,
     820,   352,  1118,  1249,   353,  1202,  1080,   481,   386,  1251,
    1083,  1084,   722,  1086,  1064,   723,   404,   482,  1090,  1065,
     859,   465,   466,   467,   468,   469,   470,   730,  1210,   405,
     731,  1200,  1201,  1210,   495,   496,   546,   542,   543,   544,
     820,   820,   820,   820,   547,   410,   838,   839,   840,   968,
     973,   969,   974,   902,   903,   416,   841,   548,   413,   549,
     880,   419,   880,   422,   842,   935,   936,   423,  1116,   550,
     843,   844,   551,  1119,  1120,   891,   892,   676,   677,   807,
     669,   670,   424,   678,   679,   864,   864,   425,  1175,  1208,
    1209,   432,  1130,   433,   434,  1131,   454,  1133,  1230,   455,
     473,   485,   487,   486,   488,   497,   504,   508,   509,   510,
     516,   519,   521,   523,   524,   530,   536,   369,   565,   580,
     581,   582,   584,   595,   339,   351,   601,   353,   371,   388,
     946,   608,   946,   609,   611,   612,  1198,   620,   615,   630,
     634,   639,   680,   633,   681,   635,  1157,   636,   682,   683,
     693,   713,   709,   714,   715,   720,   721,   732,   745,   717,
     746,   749,   718,   755,   740,   741,  1176,   754,  1177,   759,
     999,   795,   796,   453,  1181,  1049,   766,   767,   768,   797,
     800,  1008,   826,  1009,   805,   810,   834,  1059,  1189,  1190,
    1191,  1192,  1193,   813,  1194,   801,   804,   821,   823,   855,
     853,    90,   874,   854,   905,   912,   877,   906,   911,   913,
     922,  1075,   915,  1199,   920,   919,   925,   918,   927,   944,
     950,   967,   981,   987,   984,   988,   929,   934,   998,  1204,
    1000,  1206,  1019,  1011,   820,  1016,  1040,  1038,  1041,  1029,
    1002,  1003,  1095,  1056,  1055,  1018,  1050,  1042,  1051,  1053,
    1052,  1070,  1077,  1218,  1054,  1085,  1087,  1102,  1066,  1088,
    1089,  1081,  1093,  1098,  1101,  1106,  1107,  1108,   991,  1111,
    1109,  1114,  1110,  1096,  1125,  1132,   640,  1097,  1113,  1146,
     884,  1148,   574,  1155,  1162,  1128,  1129,   578,  1163,  1172,
    1174,  1196,  1203,  1213,  1220,   907,  1232,  1237,  1091,  1214,
     889,  1257,  1253,  1226,  1260,  1255,  1263,  1271,  1276,  1250,
     628,  1279,   629,  1256,  1252,  1154,   943,  1266,  1001,   426,
    1103,  1082,  1180,  1092,  1117,  1127,   989,  1124,  1121,   596,
    1047,  1079,   648,   647,   671,  1195,  1268,  1265,   427,   779,
     491,   623,   430,  1100,   446,  1262,   431,   865,   627,   589,
    1112,   590,   882,   832,  1037,  1115,  1030,  1145,  1217,   833,
    1165,  1035,  1031,  1143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1147,     0,   493,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   820,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1178,  1179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1184,
       0,     0,     0,     0,  1188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1205,
       0,     0,     0,     0,     0,   820,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   820,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1267,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,  1273,     0,     5,     6,     0,  1278,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,    27,
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
       0,   105,   106,     0,     0,   107,   108,   109,     0,     0,
       0,   110,     0,   111,   112,   113,     0,   114,   115,   116,
       0,   117,     0,   118,   119,   120,   121,   122,     0,   123,
     124,   125,   126,   127,   128,     0,     0,   129,   130,   131,
       0,   132,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,     0,   170,   171,     0,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,     5,     6,     0,     0,     7,     8,     9,    10,
      11,    12,    13,   326,    15,    16,     0,    17,    18,    19,
     329,    21,    22,     0,    24,    25,    26,     0,    27,    28,
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
     105,   106,     0,     0,   107,   108,   109,     0,     0,     0,
     110,   401,   111,   112,   113,     0,   114,   115,   116,     0,
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
      97,    98,    99,   100,   101,   102,   103,   104,     0,   105,
     106,     0,     0,   107,   108,   109,     0,     0,     0,   110,
       0,   111,   112,   113,     0,   114,   115,   116,     0,   117,
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
      13,   326,    15,    16,     0,    17,    18,    19,   329,    21,
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
       0,     0,   107,   108,   109,     0,   597,     0,   110,     0,
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
     326,    15,    16,     0,    17,    18,    19,   329,    21,    22,
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
       0,   107,   108,   109,     0,   684,     0,   110,     0,   111,
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
       0,     0,     7,     8,     9,    10,    11,    12,    13,   326,
      15,    16,     0,    17,    18,    19,   329,    21,    22,     0,
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
     107,   108,   109,     0,     0,     0,   110,   690,   111,   112,
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
       0,     7,     8,     9,    10,    11,    12,    13,   326,    15,
      16,     0,    17,    18,    19,   329,    21,    22,     0,    24,
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
     108,   109,     0,   704,     0,   110,     0,   111,   112,   113,
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
       7,     8,     9,    10,    11,    12,    13,   326,    15,    16,
       0,    17,    18,    19,   329,    21,    22,     0,    24,    25,
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
     109,     0,   742,     0,   110,     0,   111,   112,   113,     0,
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
       8,     9,    10,    11,    12,    13,   326,    15,    16,     0,
      17,    18,    19,   329,    21,    22,     0,    24,    25,    26,
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
       0,   774,     0,   110,     0,   111,   112,   113,     0,   114,
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
       9,    10,    11,    12,    13,   326,    15,    16,     0,    17,
      18,    19,   329,    21,    22,     0,    24,    25,    26,     0,
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
    1048,     0,   110,     0,   111,   112,   113,     0,   114,   115,
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
      10,    11,    12,    13,   326,    15,    16,     0,    17,    18,
      19,   329,    21,    22,     0,    24,    25,    26,     0,    27,
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
       0,   105,   106,     0,     0,   107,   108,   109,     0,  1074,
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
      11,    12,    13,   326,    15,    16,     0,    17,    18,    19,
     329,    21,    22,     0,    24,    25,    26,     0,    27,    28,
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
     105,   106,     0,     0,   107,   108,   109,     0,  1094,     0,
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
      12,    13,   326,    15,    16,     0,    17,    18,    19,   329,
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
       0,   111,   112,   113,     0,   114,   115,   116,     0,   117,
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
       0,     0,     0,     0,     0,     8,   321,    10,    11,    12,
      13,   326,    15,    16,     0,   327,    18,    19,   329,   330,
      22,     0,    24,    25,    26,     0,   331,    28,     0,   332,
     333,    32,    33,    34,    35,    36,    37,    38,    39,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
       0,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    60,    61,     0,     0,     0,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,     0,
      73,    74,    75,    76,     0,    77,     0,     0,     0,   337,
      79,    80,    81,    82,     0,     0,     0,     0,     0,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    91,
      92,   489,    94,    95,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,   490,   106,
       0,     0,   107,   108,   109,     0,     0,     0,   110,     0,
     111,   112,   113,     0,   114,   115,   116,     0,   117,     0,
     118,   119,   120,   121,   122,     0,   123,   124,   125,   126,
     127,   128,     0,     0,   129,   130,   131,     0,     0,   133,
       0,   134,   135,   136,   137,   138,   139,   140,   342,   142,
     344,   144,   345,   346,   147,   148,   149,   150,   151,   152,
     347,   154,     0,     0,     0,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,     0,   170,
     171,     0,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,   321,    10,    11,    12,    13,
     326,    15,    16,     0,   327,    18,    19,   329,   330,    22,
       0,    24,    25,    26,     0,   331,    28,     0,   332,   333,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,     0,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    60,    61,     0,     0,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,     0,    73,
      74,    75,    76,     0,    77,     0,     0,     0,   337,    79,
      80,    81,    82,     0,     0,     0,     0,     0,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,   106,     0,
       0,   107,   108,   109,     0,     0,     0,   110,     0,   111,
     112,   113,     0,   114,   115,   116,     0,   117,     0,   118,
     119,   120,   121,   122,     0,   123,   124,   125,   126,   127,
     128,     0,     0,   129,   130,   131,     0,     0,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   342,   142,   344,
     144,   345,   346,   147,   148,   149,   150,   151,   152,   347,
     154,     0,     0,     0,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,     0,   170,   171,
       0,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   320,   321,    10,    11,    12,    13,   326,
      15,    16,     0,   327,    18,    19,   329,   330,    22,     0,
      24,    25,    26,     0,   331,    28,     0,   332,   333,    32,
      33,    34,    35,    36,    37,    38,    39,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,     0,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      60,    61,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,     0,    73,    74,
      75,    76,     0,    77,     0,     0,     0,   337,    79,    80,
      81,    82,     0,     0,     0,     0,     0,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    91,    92,     0,
      94,    95,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
     107,   108,   109,     0,     0,     0,   110,     0,   111,   112,
     113,     0,     0,     0,   116,     0,   117,     0,   118,   119,
     120,   121,   122,     0,   123,   124,   125,   126,   127,   128,
       0,     0,   129,   130,   131,     0,     0,   133,     0,   134,
     135,   136,   137,   138,   139,   140,   342,   142,   344,   144,
     345,   346,   147,   148,   149,   150,   151,   152,   347,   154,
       0,     0,     0,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,     0,   170,   171,     0,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   320,   321,   390,   323,   391,   392,   326,    15,
      16,     0,   327,   393,    19,   329,   330,    22,     0,    24,
      25,    26,     0,   331,    28,     0,   332,   333,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    41,    42,    43,
      44,    45,    46,    47,     0,     0,    50,     0,    51,    52,
      53,   394,     0,     0,    57,    58,    59,     0,     0,     0,
      61,     0,     0,     0,     0,    63,    64,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,    73,    74,    75,
      76,     0,    77,     0,     0,     0,   337,    79,    80,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,     0,
      87,    88,    89,     0,     0,     0,     0,     0,     0,    94,
      95,     0,     0,     0,     0,    96,    97,    98,   340,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,     0,     0,     0,   110,     0,   111,   112,     0,
       0,     0,     0,   116,     0,   117,     0,   118,   119,   120,
     121,   341,     0,   123,   124,   125,   126,   127,   128,     0,
       0,   129,   130,     0,     0,     0,   133,     0,   134,   135,
     136,   137,   138,   139,   140,   342,   142,   344,   144,   345,
     346,   147,   148,   149,   150,   151,   152,   347,   154,     0,
       0,     0,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,     0,   170,   171,     0,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   320,   321,   322,   323,   324,   325,   326,    15,    16,
       0,   327,   328,    19,   329,   330,    22,     0,    24,    25,
      26,     0,   331,    28,     0,   332,   333,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    41,   334,   335,    44,
      45,    46,    47,     0,     0,    50,     0,    51,    52,    53,
     336,     0,     0,    57,    58,    59,     0,     0,     0,    61,
       0,     0,     0,     0,    63,    64,     0,     0,    67,    68,
       0,     0,     0,     0,     0,     0,    73,    74,    75,    76,
       0,    77,     0,     0,     0,   337,    79,    80,     0,     0,
       0,     0,     0,     0,     0,    83,    84,    85,     0,    87,
      88,    89,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,    96,    97,    98,   340,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,     0,     0,   110,     0,   111,     0,     0,     0,
       0,     0,   116,     0,   117,     0,   118,   119,   120,   121,
     341,     0,   123,   124,   125,   126,   127,   128,     0,     0,
     129,   130,     0,     0,     0,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   342,   343,   344,   144,   345,   346,
     147,   148,   149,   150,   151,   152,   347,   154,     0,     0,
       0,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,     0,   170,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   406,
       0,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   320,   321,   322,   323,   324,   325,
     326,    15,    16,     0,   327,   328,    19,   329,   330,    22,
       0,    24,    25,    26,     0,   331,    28,     0,   332,   333,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    41,
     334,   335,    44,    45,    46,    47,     0,     0,    50,     0,
      51,    52,    53,   336,     0,     0,    57,    58,    59,     0,
       0,     0,    61,     0,     0,     0,     0,    63,    64,     0,
       0,    67,    68,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,     0,    77,     0,     0,     0,   337,    79,
      80,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,     0,    87,    88,    89,     0,     0,     0,     0,     0,
       0,    94,    95,     0,     0,     0,     0,    96,    97,    98,
     340,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,     0,     0,     0,   110,     0,   111,
       0,     0,     0,     0,     0,     0,     0,   117,     0,   118,
     119,   120,   121,   341,     0,   123,   124,   125,   126,   127,
     128,     0,     0,   129,   130,     0,     0,     0,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   342,   343,   344,
     144,   345,   346,   147,   148,   149,   150,   151,   152,   347,
     154,     0,     0,     0,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,     0,   170,   171,
       0,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   320,   321,   322,   323,   324,
     325,   326,    15,    16,     0,   327,   328,    19,   329,   330,
      22,     0,    24,    25,    26,     0,   331,    28,     0,   332,
     333,    32,    33,    34,    35,    36,    37,    38,    39,     0,
      41,   334,   335,    44,    45,    46,    47,     0,     0,    50,
       0,    51,    52,    53,   336,     0,     0,    57,    58,    59,
       0,     0,     0,    61,     0,     0,     0,     0,    63,    64,
       0,     0,    67,    68,     0,     0,     0,     0,     0,     0,
      73,    74,    75,    76,     0,    77,     0,     0,     0,   337,
      79,    80,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,     0,    87,    88,    89,   338,     0,     0,   339,
       0,     0,    94,    95,     0,     0,     0,     0,    96,    97,
      98,   340,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,     0,     0,     0,   110,     0,
     111,     0,     0,     0,     0,     0,     0,     0,   117,     0,
     118,   119,   120,   121,   341,     0,   123,   124,   125,   126,
     127,   128,     0,     0,   129,   130,     0,     0,     0,   133,
       0,   134,   135,   136,   137,   138,   139,   140,   342,   343,
     344,   144,   345,   346,   147,   148,   149,   150,   151,   152,
     347,   154,     0,     0,     0,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,     0,   170,
     171,     0,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   320,   321,   322,   323,
     324,   325,   326,    15,    16,     0,   327,   328,    19,   329,
     330,    22,     0,    24,    25,    26,     0,   331,    28,     0,
     332,   333,    32,    33,    34,    35,    36,    37,    38,    39,
       0,    41,   334,   335,    44,    45,    46,    47,     0,     0,
      50,     0,    51,    52,    53,   336,     0,     0,    57,    58,
      59,     0,     0,     0,    61,     0,     0,     0,     0,    63,
      64,     0,     0,    67,    68,     0,     0,     0,     0,     0,
       0,    73,    74,    75,    76,     0,    77,     0,     0,     0,
     337,    79,    80,     0,     0,     0,     0,     0,     0,     0,
      83,    84,    85,     0,    87,    88,    89,   387,     0,     0,
     388,     0,     0,    94,    95,     0,     0,     0,     0,    96,
      97,    98,   340,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,     0,     0,     0,   110,
       0,   111,     0,     0,     0,     0,     0,     0,     0,   117,
       0,   118,   119,   120,   121,   341,     0,   123,   124,   125,
     126,   127,   128,     0,     0,   129,   130,     0,     0,     0,
     133,     0,   134,   135,   136,   137,   138,   139,   140,   342,
     343,   344,   144,   345,   346,   147,   148,   149,   150,   151,
     152,   347,   154,     0,     0,     0,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,     0,
     170,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   320,   321,   322,
     323,   324,   325,   326,    15,    16,     0,   327,   328,    19,
     329,   330,    22,     0,    24,    25,    26,     0,   331,    28,
       0,   332,   333,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    41,   334,   335,    44,    45,    46,    47,     0,
       0,    50,     0,    51,    52,    53,   336,     0,     0,    57,
      58,    59,     0,     0,     0,    61,     0,     0,     0,     0,
      63,    64,     0,     0,    67,    68,     0,     0,     0,     0,
       0,     0,    73,    74,    75,    76,     0,    77,     0,     0,
       0,   337,    79,    80,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    85,     0,    87,    88,    89,     0,     0,
       0,     0,     0,     0,    94,    95,     0,     0,     0,     0,
      96,    97,    98,   340,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,     0,     0,     0,
     110,   513,   111,     0,     0,     0,     0,     0,   514,     0,
     117,     0,   118,   119,   120,   121,   341,     0,   123,   124,
     125,   126,   127,   128,     0,     0,   129,   130,     0,     0,
       0,   133,     0,   134,   135,   136,   137,   138,   139,   140,
     342,   343,   344,   144,   345,   346,   147,   148,   149,   150,
     151,   152,   347,   154,     0,     0,     0,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
       0,   170,   171,     0,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   320,   321,
     322,   323,   324,   325,   326,    15,    16,     0,   327,   328,
      19,   329,   330,    22,     0,    24,    25,    26,     0,   331,
      28,     0,   332,   333,    32,    33,    34,    35,    36,    37,
      38,    39,     0,    41,   334,   335,    44,    45,    46,    47,
       0,     0,    50,     0,    51,    52,    53,   336,     0,     0,
      57,    58,    59,     0,     0,     0,    61,     0,     0,     0,
       0,    63,    64,     0,     0,    67,    68,     0,     0,     0,
       0,     0,     0,    73,    74,    75,    76,     0,    77,     0,
       0,     0,   337,    79,    80,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,     0,    87,    88,    89,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,    96,    97,    98,   340,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,     0,     0,
       0,   110,   592,   111,     0,     0,     0,     0,     0,   593,
       0,   117,     0,   118,   119,   120,   121,   341,     0,   123,
     124,   125,   126,   127,   128,     0,     0,   129,   130,     0,
       0,     0,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   342,   343,   344,   144,   345,   346,   147,   148,   149,
     150,   151,   152,   347,   154,     0,     0,     0,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,     0,   170,   171,     0,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   320,
     321,   390,   323,   391,   392,   326,    15,    16,     0,   327,
     393,    19,   329,   330,    22,     0,    24,    25,    26,     0,
     331,    28,     0,   332,   333,    32,    33,    34,    35,    36,
      37,    38,    39,     0,    41,    42,    43,    44,    45,    46,
      47,     0,     0,    50,     0,    51,    52,    53,   394,     0,
       0,    57,    58,    59,     0,     0,     0,    61,     0,     0,
       0,     0,    63,    64,     0,     0,    67,    68,  1044,     0,
       0,     0,     0,     0,    73,    74,    75,    76,     0,    77,
       0,     0,     0,   337,    79,    80,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,     0,    87,    88,   814,
       0,     0,     0,     0,     0,     0,    94,    95,     0,     0,
       0,     0,    96,    97,    98,   340,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,     0,
       0,     0,   110,     0,   111,   112,     0,     0,     0,     0,
       0,     0,   117,     0,   118,   119,   120,   121,   341,     0,
     123,   124,   125,   126,   127,   128,     0,     0,   815,   130,
       0,     0,     0,   133,     0,   134,   135,   136,   137,   138,
     139,   140,   342,   142,   344,   144,   345,   346,   147,   148,
     149,   150,   151,   152,   347,   154,     0,     0,     0,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,     0,   170,   171,     0,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     320,   321,   390,   323,   391,   392,   326,    15,    16,     0,
     327,   393,    19,   329,   330,    22,     0,    24,    25,    26,
       0,   331,    28,     0,   332,   333,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    41,    42,    43,    44,    45,
      46,    47,     0,     0,    50,     0,    51,    52,    53,   394,
       0,     0,    57,    58,    59,     0,     0,     0,    61,     0,
       0,     0,     0,    63,    64,     0,     0,    67,    68,     0,
       0,     0,     0,     0,     0,    73,    74,    75,    76,     0,
      77,     0,     0,     0,   337,    79,    80,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,     0,    87,    88,
     814,     0,     0,     0,     0,     0,     0,    94,    95,     0,
       0,     0,     0,    96,    97,    98,   340,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
       0,     0,     0,   110,     0,   111,   112,     0,     0,     0,
       0,     0,     0,   117,     0,   118,   119,   120,   121,   341,
       0,   123,   124,   125,   126,   127,   128,     0,     0,   815,
     130,     0,     0,     0,   133,     0,   134,   135,   136,   137,
     138,   139,   140,   342,   142,   344,   144,   345,   346,   147,
     148,   149,   150,   151,   152,   347,   154,     0,     0,     0,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,     0,   170,   171,     0,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   320,   321,   322,   323,   324,   325,   326,    15,    16,
       0,   327,   328,    19,   329,   330,    22,     0,    24,    25,
      26,     0,   331,    28,     0,   332,   333,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    41,   334,   335,    44,
      45,    46,    47,     0,     0,    50,     0,    51,    52,    53,
     336,     0,     0,    57,    58,    59,     0,     0,     0,    61,
       0,     0,     0,     0,    63,    64,     0,     0,    67,    68,
       0,     0,     0,     0,     0,     0,    73,    74,    75,    76,
       0,    77,     0,     0,     0,   337,    79,    80,     0,     0,
       0,     0,     0,     0,     0,    83,    84,    85,     0,    87,
      88,    89,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,    96,    97,    98,   340,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,     0,     0,   110,     0,   111,     0,     0,     0,
       0,     0,     0,     0,   117,     0,   118,   119,   120,   121,
     341,     0,   123,   124,   125,   126,   127,   128,     0,     0,
     129,   130,     0,     0,     0,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   342,   343,   344,   144,   345,   346,
     147,   148,   149,   150,   151,   152,   347,   154,     0,     0,
       0,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,     0,   170,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        10,   360,   749,   477,   478,   479,   480,   640,   433,   473,
     680,   681,   728,   574,   373,   374,   602,   578,    90,    91,
     578,    56,   891,   312,   115,   314,   365,   855,    19,   453,
     693,   782,   371,   843,   662,     6,   456,   376,   458,   459,
      76,   461,    20,   463,    54,   963,    56,   680,   681,    60,
      76,   471,   472,    37,    38,    39,    76,    19,    78,    69,
      19,    19,    76,    47,    37,    38,    39,   121,    89,    78,
     995,   996,    89,    17,    47,    19,    75,    89,   702,    52,
      99,    32,    92,   125,    89,   121,   644,    89,   646,   378,
      63,    89,    65,    89,   146,    68,   106,   178,    71,   115,
      89,    92,   112,   125,    78,   125,    78,   188,    76,    93,
       7,     8,   103,     7,    53,    66,   125,   216,    17,   196,
      93,    94,    77,    88,    18,   414,   415,   179,   417,   418,
     419,   420,    94,    88,   423,   204,   127,   206,    58,    59,
     131,   106,    97,   134,   163,   434,   770,   168,   772,    82,
      89,   106,   229,   442,   443,   716,   168,   125,    78,   164,
     241,   160,   178,   165,   162,   138,   247,   258,    89,   165,
      89,   197,   198,   920,   255,   164,   138,     7,     8,   138,
     539,   152,  1100,   197,   198,   196,   212,    89,    85,     7,
       8,   245,   778,   909,   658,   659,  1121,   214,   212,   760,
     758,    89,   953,   245,   874,   102,   164,   104,   102,   245,
     104,   570,   963,   164,   192,   504,    19,   845,   229,   113,
     164,   231,   646,   245,  1034,   245,   199,   566,   263,   892,
     569,   266,   131,   653,   131,   134,   245,   131,   135,   223,
     161,   874,  1070,   315,   235,   164,   109,   319,     7,     8,
     223,    78,   110,   263,   151,    85,   266,   231,   232,   231,
     232,    89,   164,    89,    89,    89,   338,    85,   134,    78,
     828,   243,   102,    82,   104,   172,   164,   349,   350,    89,
     352,    89,    89,   216,   102,    32,   104,   144,    89,    92,
      37,   224,    94,    89,   191,   115,   368,    89,   370,    99,
     103,   131,   159,   136,   237,   135,   239,   134,   128,    89,
     168,   174,    89,   131,   131,   387,   249,   135,    89,   252,
     153,   151,    89,    89,   127,   109,    85,   399,   131,   339,
       3,   134,   404,   151,     7,   161,   164,   146,   410,   164,
     164,    88,   172,   102,   354,   104,   635,   357,    36,  1100,
      42,   161,    89,   642,   172,    43,   164,   164,   717,   718,
    1229,   191,   721,   164,   164,   375,    27,   377,   164,   161,
     844,     7,   131,   191,    45,   385,   135,   841,   388,   804,
      51,   161,    18,    54,    55,  1213,  1056,   164,   398,   853,
     174,    62,   151,   164,   116,   754,   131,   164,   164,   134,
     147,  1270,    89,    89,   495,   496,  1275,   216,    98,   131,
    1279,    89,   422,   172,   424,   224,   108,   226,   227,   228,
     492,   138,   224,  1056,   161,   497,    89,  1174,   237,   102,
     239,   104,   191,    76,   124,   244,   508,   509,   510,   112,
     249,   250,   251,   252,   516,     3,   159,   137,    89,     7,
     116,   253,   254,    46,   256,   257,    49,    89,   131,    89,
     173,   123,   751,   752,    89,   131,   102,   756,   104,    89,
      89,    89,    56,    57,   161,   161,   147,   113,   149,    89,
     126,   171,   125,   161,   134,  1155,    89,   776,    89,    89,
      89,   153,   163,   565,  1055,   131,   131,   143,   161,   788,
     789,   790,   131,   792,   793,   794,   795,   796,   797,   171,
     799,   800,  1098,   523,   524,    99,   805,  1103,  1234,   190,
     161,   134,  1155,   595,    78,   154,   536,    82,    78,   161,
      99,   161,    82,  1203,    78,   824,   161,   826,   827,    94,
      94,   161,   161,   161,   102,  1019,   104,   136,    76,   265,
      94,   161,  1026,  1027,   112,   271,   915,   241,   161,    99,
     161,   161,   161,   247,   153,   200,   201,   202,   131,   126,
    1203,   255,   582,   131,  1038,    58,    59,    54,    61,   868,
     134,   111,   224,   159,   178,   657,   143,   176,   116,   119,
     120,   601,   122,   121,   188,    78,   146,   173,  1184,   129,
      27,   241,  1188,   133,    99,   135,   246,  1221,  1222,   898,
     140,   253,   254,   204,   256,   257,    99,   498,   209,   204,
     501,   206,   503,   912,   634,   134,   156,  1241,   220,   221,
     640,   131,   991,  1247,   134,   176,   925,   178,   134,  1225,
     929,   930,   222,   932,   116,   225,   131,   188,   937,   121,
     242,   181,   182,   183,   184,   185,   186,   222,  1160,    13,
     225,  1135,  1136,  1165,   169,   170,   216,   200,   201,   202,
     680,   681,   682,   683,   224,   131,   226,   227,   228,   211,
     211,   213,   213,   107,   108,   134,   236,   237,   194,   239,
     700,   204,   702,    99,   244,    58,    59,   131,   987,   249,
     250,   251,   252,   107,   108,   711,   712,   481,   482,   998,
     474,   475,    99,   483,   484,   682,   683,     0,  1077,  1158,
    1159,   168,  1011,   168,    89,  1014,   145,  1016,  1202,    74,
     234,    69,    83,   177,    84,   132,   134,   131,   131,   131,
     131,   164,   164,    37,    37,    19,    99,    17,   131,   251,
     251,    99,    99,   131,   134,   134,    24,   134,   134,   134,
     770,    14,   772,   164,   192,    19,  1125,   210,   164,    36,
      99,    89,   210,   147,    76,   148,  1065,   148,    76,    76,
     164,    19,   134,    89,    89,   106,   111,    19,    78,   138,
      32,    78,   138,    89,   164,   164,  1085,   111,  1087,   161,
     810,    76,   216,   813,  1093,   877,   164,   164,   164,   204,
     121,   821,   125,   823,   148,    99,   252,   889,  1107,  1108,
    1109,  1110,  1111,    99,  1113,   161,   168,    99,    99,   240,
     233,   131,    82,   235,   254,   175,   131,   255,   255,   131,
      99,   913,   111,  1132,    78,   111,   125,   138,    99,   131,
      24,    19,    99,   131,   218,    99,   121,   229,    89,  1148,
      89,  1150,   230,   125,   874,   125,   255,   125,    48,   230,
     134,   134,   944,    76,   884,   164,   164,   123,   164,   164,
     123,    19,    89,  1172,   164,   121,   125,   959,   255,    99,
      99,   168,    61,   111,     5,   168,   212,   212,    88,   216,
     212,   134,   212,   164,    88,   125,    76,   164,   163,   248,
      99,   163,   922,    76,    19,   164,   164,   927,    19,   105,
      78,   161,    76,    19,    59,    78,   163,    99,   938,   238,
     131,   238,    99,   174,    75,   163,   160,    99,    99,   174,
     432,   164,   432,  1232,   174,  1057,   765,   174,   813,   194,
     960,   927,  1091,   939,   988,  1000,   805,   998,   995,   398,
     875,   922,   455,   454,   476,  1114,  1255,  1247,   194,   602,
     251,   981,   197,   953,   230,  1241,   198,   683,   988,   386,
     981,   386,   702,   658,   853,   985,   841,  1038,  1170,   659,
    1069,   845,   842,  1033,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1044,    -1,   255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1056,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1088,  1089,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1099,
      -1,    -1,    -1,    -1,  1104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1149,
      -1,    -1,    -1,    -1,    -1,  1155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1253,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    -1,    19,    -1,    -1,
      -1,  1271,    -1,    25,    26,    -1,  1276,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
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
      -1,   153,   154,    -1,    -1,   157,   158,   159,    -1,    -1,
      -1,   163,    -1,   165,   166,   167,    -1,   169,   170,   171,
      -1,   173,    -1,   175,   176,   177,   178,   179,    -1,   181,
     182,   183,   184,   185,   186,    -1,    -1,   189,   190,   191,
      -1,   193,   194,    -1,   196,   197,   198,   199,   200,   201,
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
     153,   154,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,
     163,   164,   165,   166,   167,    -1,   169,   170,   171,    -1,
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
     144,   145,   146,   147,   148,   149,   150,   151,    -1,   153,
     154,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,   163,
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
     157,   158,   159,    -1,    -1,    -1,   163,   164,   165,   166,
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
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,    -1,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    -1,    87,    88,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,    -1,
     105,   106,   107,   108,    -1,   110,    -1,    -1,    -1,   114,
     115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,   153,   154,
      -1,    -1,   157,   158,   159,    -1,    -1,    -1,   163,    -1,
     165,   166,   167,    -1,   169,   170,   171,    -1,   173,    -1,
     175,   176,   177,   178,   179,    -1,   181,   182,   183,   184,
     185,   186,    -1,    -1,   189,   190,   191,    -1,    -1,   194,
      -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,   220,   221,   222,   223,   224,
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
     146,   147,   148,   149,   150,   151,    -1,   153,   154,    -1,
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
     127,   128,   129,   130,    -1,    -1,    -1,   134,   135,    -1,
     137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,    -1,    -1,    -1,   163,    -1,   165,   166,
     167,    -1,    -1,    -1,   171,    -1,   173,    -1,   175,   176,
     177,   178,   179,    -1,   181,   182,   183,   184,   185,   186,
      -1,    -1,   189,   190,   191,    -1,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,   234,   235,    -1,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
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
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,   163,    -1,   165,   166,    -1,
      -1,    -1,    -1,   171,    -1,   173,    -1,   175,   176,   177,
     178,   179,    -1,   181,   182,   183,   184,   185,   186,    -1,
      -1,   189,   190,    -1,    -1,    -1,   194,    -1,   196,   197,
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
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,   163,    -1,   165,    -1,    -1,    -1,
      -1,    -1,   171,    -1,   173,    -1,   175,   176,   177,   178,
     179,    -1,   181,   182,   183,   184,   185,   186,    -1,    -1,
     189,   190,    -1,    -1,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,   234,   235,    -1,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    15,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
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
     124,   125,   126,    -1,   128,   129,   130,   131,    -1,    -1,
     134,    -1,    -1,   137,   138,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,
      -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,
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
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
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
      -1,    93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,    -1,   110,    -1,
      -1,    -1,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,    -1,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,
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
      -1,    -1,    93,    94,    -1,    -1,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,    -1,   110,
      -1,    -1,    -1,   114,   115,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,    -1,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,    -1,
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
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,   163,    -1,   165,   166,    -1,    -1,    -1,
      -1,    -1,    -1,   173,    -1,   175,   176,   177,   178,   179,
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
     159,    -1,    -1,    -1,   163,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   173,    -1,   175,   176,   177,   178,
     179,    -1,   181,   182,   183,   184,   185,   186,    -1,    -1,
     189,   190,    -1,    -1,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,   234,   235,    -1,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257
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
     255,   256,   257,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   298,   299,   300,   302,
     304,   305,   306,   307,   312,   313,   314,   315,   320,   322,
     324,   325,   326,   331,   352,   355,   358,   359,   360,   361,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     408,   409,   410,   424,   425,   427,   428,   429,   430,   431,
     432,   433,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   452,   453,   454,   455,   456,   457,   458,   461,
     466,   467,   216,    27,   134,   131,   200,   201,   202,   134,
      30,    31,    32,    33,    34,    35,    36,    40,    41,    43,
      44,    51,    54,    55,    66,    67,    79,   114,   131,   134,
     146,   179,   203,   204,   205,   207,   208,   215,   466,   131,
     131,   134,   131,   134,    37,    38,    39,    47,    52,    63,
      65,    68,    71,    93,    94,   138,   199,   223,   134,    17,
     131,   134,   465,    46,    49,    99,   138,    99,   131,    56,
      57,    99,   317,    54,    27,   134,   134,   131,   134,   466,
      32,    34,    35,    41,    79,   392,   466,   466,    99,   303,
     313,   164,   313,   466,   131,    13,    15,   466,   466,   384,
     131,    20,   192,   194,   204,   206,   134,   204,   206,   204,
     204,   209,    99,   131,    99,     0,   275,   276,    36,    43,
     278,   312,   168,   168,    89,    45,    51,    54,    55,    62,
     147,   149,   163,   190,   316,   321,   322,   323,   340,   341,
     345,   327,   328,   466,   145,    74,   111,   119,   120,   122,
     129,   133,   135,   140,   156,   181,   182,   183,   184,   185,
     186,   376,   377,   234,   136,   153,   176,    98,   124,   137,
     171,   178,   188,   115,   128,    69,   177,    83,    84,   136,
     153,   375,   131,   381,   384,   169,   170,   132,   396,   397,
     392,   396,   392,   396,   134,   314,   314,   313,   131,   131,
     131,   313,   313,   164,   171,   466,   131,   313,   313,   164,
     313,   164,   466,    37,    37,   466,   159,   173,   146,   179,
      19,   464,   144,   159,   159,   173,    99,    32,    37,    88,
     147,   465,   200,   201,   202,    82,   216,   224,   237,   239,
     249,   252,   479,   480,   481,   482,   483,   486,   491,   492,
     313,   313,    19,   164,   465,   131,   138,   464,    94,   138,
     297,   464,   353,   354,   466,   465,   332,   334,   466,   314,
     251,   251,    99,   335,    99,   466,    32,    66,   164,   448,
     449,   313,   164,   171,   466,   131,   353,   161,   313,   168,
     164,    24,   412,   413,   414,   313,     6,   152,    14,   164,
     313,   192,    19,   314,   314,   164,   314,   314,   314,   314,
     210,   459,   460,   466,   314,   333,   339,   466,   280,   281,
      36,   282,   314,   147,    99,   148,   148,   314,   314,    89,
      76,    78,   125,   245,   329,   330,   435,   360,   361,   363,
     363,   363,   363,   362,   363,   363,   363,   131,   134,   235,
     399,   468,   470,   471,   472,   473,   474,   475,   476,   366,
     366,   365,   367,   367,   367,   367,   368,   368,   369,   369,
     210,    76,    76,    76,   161,   313,   384,   384,   313,   397,
     164,   314,   407,   164,   161,   313,   313,   313,   164,   161,
      89,   164,    89,   164,   161,   313,   161,   161,   161,   134,
     301,   466,   466,    19,    89,    89,   466,   138,   138,   464,
     106,   111,   222,   225,    94,   224,   253,   254,   256,   257,
     222,   225,    19,   224,   253,   254,   256,   257,   164,   161,
     164,   164,   161,   313,   465,    78,    32,   465,   464,    78,
      89,   165,   125,   435,   111,    89,   121,   330,   435,   161,
     466,    60,   196,   229,   318,   319,   164,   164,   164,   161,
      89,   164,    89,   164,   161,   313,   165,   168,   466,   413,
     414,   109,   174,   161,   161,   110,   168,    76,   197,   198,
     212,    76,   197,   198,   212,    76,   216,   204,    89,   214,
     121,   161,    53,    89,   168,   148,   466,   314,   346,   347,
      99,   342,   343,    99,   130,   189,   436,   438,   439,   440,
     466,    99,   314,    99,   125,   330,   125,   125,   329,   330,
     363,   313,   468,   474,   252,   502,    78,   146,   226,   227,
     228,   236,   244,   250,   251,   469,   477,   478,   479,   493,
     496,   497,   499,   233,   235,   240,   498,   220,   221,   242,
     494,   436,   436,   434,   439,   434,   161,   162,    89,   164,
     302,   161,   161,   161,    82,   356,   357,   131,   450,   451,
     466,   450,   451,   161,    99,   164,   308,   309,   116,   131,
     311,   301,   301,   126,   143,   126,   143,   116,   121,   435,
     464,   464,   107,   108,   464,   254,   255,    78,    94,   134,
     485,   255,   175,   131,   161,   111,   296,   464,   138,   111,
      78,   296,    99,   314,   314,   125,   464,    99,   314,   121,
     121,   330,   125,   435,   229,    58,    59,    61,    99,   329,
     336,   337,   338,   319,   131,   450,   466,   450,   161,   314,
      24,   414,   109,   174,     7,     8,    85,   102,   104,   131,
     172,   310,   409,   411,   422,   423,   426,    19,   211,   213,
     314,   314,   314,   211,   213,   314,   314,   314,   314,   314,
     314,    99,   314,   314,   218,   462,   463,   131,    99,   346,
      77,    88,    97,   106,   348,   349,   350,   351,    89,   466,
      89,   328,   134,   134,   123,   153,   171,   437,   466,   466,
     314,   125,   314,   314,   125,   330,   125,   161,   164,   230,
     196,   229,   241,   246,   501,    78,   231,   232,   495,   230,
     471,   501,   364,   367,   250,   477,   479,   472,   125,   495,
     255,    48,   123,   314,    99,   436,    94,   357,   161,   313,
     164,   164,   123,   164,   164,   466,    76,    89,   164,   313,
     116,   311,   302,   314,   116,   121,   255,    78,   134,   488,
      19,    94,   485,   314,   161,   313,   464,    89,   296,   354,
     314,   168,   334,   314,   314,   121,   314,   125,    99,    99,
     314,   466,   338,    61,   161,   313,   164,   164,   111,   172,
     411,     5,   313,   466,   172,   422,   168,   212,   212,   212,
     212,   216,   460,   163,   134,   463,   314,   339,   464,   107,
     108,   350,   351,   351,   347,    88,   344,   343,   164,   164,
     314,   314,   125,   314,   367,    42,   108,   367,   367,   241,
     247,   255,   500,   500,   364,   473,   248,   466,   163,    99,
     163,   161,   435,   436,   309,    76,   161,   314,   115,   178,
     487,   490,    19,    19,   489,   487,   243,   495,    89,   164,
      89,   164,   105,   161,    78,   464,   314,   314,   466,   466,
     337,   314,   161,   414,   466,   172,   161,   414,   466,   314,
     314,   314,   314,   314,   314,   393,   161,   351,   464,   314,
     367,   367,   176,    76,   314,   466,   314,   436,   488,   488,
     490,    19,   164,    19,   238,   484,   485,   484,   314,   296,
      59,    75,   160,   415,   414,   466,   174,   414,    89,   164,
     367,   436,   163,   495,    89,   164,   164,    99,     3,   112,
     418,   419,   421,   423,    18,   113,   416,   417,   420,   423,
     174,   414,   174,    99,   311,   163,   314,   238,   485,   466,
      75,   112,   421,   160,   113,   420,   174,   466,   314,    89,
     164,    99,   311,   466,    89,   164,    99,   311,   466,   164,
     311
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
     466,   466,   466,   467,   467,   468,   468,   468,   468,   469,
     469,   469,   469,   470,   470,   471,   471,   472,   472,   473,
     473,   474,   474,   474,   475,   475,   476,   476,   477,   477,
     477,   477,   477,   478,   479,   479,   479,   479,   479,   479,
     479,   480,   480,   480,   480,   481,   481,   481,   481,   482,
     482,   483,   483,   483,   483,   483,   483,   483,   484,   484,
     485,   485,   485,   485,   486,   486,   486,   486,   486,   487,
     487,   488,   488,   489,   489,   490,   490,   491,   492,   492,
     493,   493,   493,   494,   494,   494,   494,   494,   495,   495,
     495,   495,   496,   497,   498,   499,   499,   500,   500,   500,
     501,   501,   502
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
      51,    -1,   190,    -1,   148,    -1,   149,    -1,   147,    -1,
      45,    -1,    77,    -1,    97,    -1,   107,    -1,   108,    -1,
      88,    -1,    44,    -1,   114,    -1,   165,    -1,    82,    -1,
      76,    -1,   175,    -1,   105,    -1,   145,    -1,    74,    -1,
      69,    -1,   210,    -1,    83,    -1,   176,    -1,    98,    -1,
     137,    -1,   178,    -1,   128,    -1,   115,    -1,    30,    -1,
      84,    -1,   177,    -1,   129,    -1,   159,    -1,   173,    -1,
     138,    -1,   116,    -1,   110,    -1,   144,    -1,   126,    -1,
     143,    -1,    36,    -1,    52,    -1,    63,    -1,    94,    -1,
      68,    -1,    47,    -1,   194,    -1,    43,    -1,    49,    -1,
      37,    -1,   245,    -1,   234,    -1,   250,    -1,   251,    -1,
     227,    -1,   240,    -1,   248,    -1,   244,    -1,   226,    -1,
     239,    -1,   249,    -1,   243,    -1,   238,    -1,   237,    -1,
     221,    -1,   220,    -1,   242,    -1,   231,    -1,   232,    -1,
     255,    -1,   247,    -1,   246,    -1,   241,    -1,   208,    -1,
     214,    -1,   211,    -1,   205,    -1,   198,    -1,   197,    -1,
     199,    -1,   216,    -1,   206,    -1,   207,    -1,   213,    -1,
     203,    -1,   212,    -1,    38,    -1,   146,    -1,   179,    -1,
     219,    99,   333,    53,   131,   314,   161,    -1,    53,   131,
     314,   161,    -1,   470,    -1,   470,   469,    -1,   470,   250,
     364,    -1,   470,   469,   250,   364,    -1,   479,    -1,   477,
      -1,   469,   479,    -1,   469,   477,    -1,   471,    -1,   470,
     236,   471,    -1,   472,    -1,   471,   233,   472,    -1,   473,
      -1,   472,   235,   125,   473,    -1,   474,    -1,   235,   474,
      -1,   475,    -1,   475,   498,    -1,   134,   468,   164,    -1,
     476,    -1,   476,   494,    -1,   399,    -1,   131,   313,   161,
      -1,   478,    -1,   497,    -1,   496,    -1,   499,    -1,   493,
      -1,   146,    -1,   480,    -1,   481,    -1,   482,    -1,   483,
      -1,   486,    -1,   491,    -1,   492,    -1,   239,    -1,   249,
      -1,    82,   222,    -1,    82,   225,    -1,   216,   224,    -1,
     252,   224,    -1,   224,   222,    -1,   224,   225,    -1,   216,
     253,    -1,   252,   253,    -1,   216,   256,   485,    -1,   216,
     256,    94,    -1,   216,   256,   134,   485,   164,    -1,   216,
     256,   134,   485,    89,   484,   164,    -1,   216,   256,   134,
      94,   164,    -1,   216,   256,   134,    94,    89,   484,   164,
      -1,   252,   256,    -1,   485,    -1,   484,    89,   485,    -1,
      78,    19,    -1,    78,    19,   243,    19,    -1,    78,    19,
     495,   238,    -1,    78,    19,   243,    19,   495,   238,    -1,
     216,   254,   255,   488,    -1,   216,   254,   255,   488,   487,
      -1,   216,    94,   254,   255,    -1,   216,    94,   254,   255,
     487,    -1,   252,   254,   255,    -1,   490,    -1,   487,   490,
      -1,    78,    19,    -1,   134,   489,   164,    -1,    19,    -1,
     489,    19,    -1,   178,   488,    -1,   115,   488,    -1,   237,
      19,    -1,   216,   257,    -1,   252,   257,    -1,    78,   196,
      -1,    78,   229,    -1,   228,   230,    -1,   221,    -1,   221,
      48,    -1,   220,    -1,   220,   255,    -1,   242,    -1,   231,
     367,    -1,    78,   108,   367,    -1,    78,    42,   367,    -1,
     232,   367,   176,   367,    -1,   227,   495,   500,    -1,   251,
     367,   500,    -1,   240,   495,   248,    -1,   244,   501,    -1,
     226,   501,    -1,   255,    -1,   247,    -1,   241,    -1,   246,
      -1,   241,    -1,   252,   230,   367,    -1
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
    2094,  2096,  2098,  2100,  2108,  2113,  2115,  2118,  2122,  2127,
    2129,  2131,  2134,  2137,  2139,  2143,  2145,  2149,  2151,  2156,
    2158,  2161,  2163,  2166,  2170,  2172,  2175,  2177,  2181,  2183,
    2185,  2187,  2189,  2191,  2193,  2195,  2197,  2199,  2201,  2203,
    2205,  2207,  2209,  2211,  2214,  2217,  2220,  2223,  2226,  2229,
    2232,  2235,  2239,  2243,  2249,  2257,  2263,  2271,  2274,  2276,
    2280,  2283,  2288,  2293,  2300,  2305,  2311,  2316,  2322,  2326,
    2328,  2331,  2334,  2338,  2340,  2343,  2346,  2349,  2352,  2355,
    2358,  2361,  2364,  2367,  2369,  2372,  2374,  2377,  2379,  2382,
    2386,  2390,  2395,  2399,  2403,  2407,  2410,  2413,  2415,  2417,
    2419,  2421,  2423
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
    4150,  4162,  4173,  4180,  4187,  4194,  4201,  4208,  4215,  4228,
    4249,  4256,  4276,  4316,  4321,  4324,  4332,  4338,  4344,  4350,
    4356,  4363,  4369,  4375,  4381,  4387,  4399,  4404,  4414,  4420,
    4432,  4458,  4469,  4475,  4488,  4502,  4509,  4516,  4527,  4534,
    4542,  4551,  4564,  4567,  4585,  4586,  4587,  4588,  4589,  4590,
    4591,  4592,  4593,  4594,  4595,  4596,  4597,  4598,  4599,  4600,
    4601,  4602,  4603,  4604,  4605,  4606,  4607,  4608,  4609,  4610,
    4611,  4612,  4613,  4614,  4615,  4616,  4617,  4618,  4619,  4620,
    4621,  4622,  4623,  4624,  4625,  4626,  4627,  4628,  4629,  4630,
    4631,  4632,  4633,  4634,  4635,  4636,  4637,  4638,  4639,  4640,
    4641,  4642,  4643,  4644,  4645,  4646,  4647,  4648,  4649,  4650,
    4651,  4652,  4653,  4654,  4655,  4656,  4657,  4658,  4659,  4660,
    4661,  4662,  4663,  4664,  4665,  4666,  4667,  4668,  4669,  4670,
    4671,  4672,  4673,  4674,  4675,  4676,  4677,  4678,  4679,  4680,
    4681,  4682,  4683,  4684,  4685,  4686,  4687,  4688,  4689,  4690,
    4691,  4692,  4693,  4694,  4695,  4696,  4697,  4698,  4699,  4700,
    4701,  4702,  4703,  4704,  4705,  4706,  4707,  4708,  4709,  4710,
    4711,  4712,  4713,  4714,  4715,  4716,  4717,  4718,  4719,  4720,
    4721,  4722,  4723,  4724,  4725,  4726,  4727,  4728,  4729,  4730,
    4731,  4732,  4733,  4744,  4750,  4767,  4771,  4775,  4779,  4789,
    4792,  4795,  4798,  4807,  4810,  4819,  4822,  4831,  4834,  4843,
    4846,  4855,  4858,  4861,  4870,  4873,  4882,  4886,  4896,  4899,
    4902,  4905,  4908,  4917,  4926,  4930,  4934,  4938,  4942,  4946,
    4950,  4960,  4963,  4966,  4969,  4978,  4981,  4984,  4987,  4996,
    4999,  5008,  5011,  5014,  5017,  5020,  5023,  5026,  5035,  5038,
    5047,  5050,  5053,  5056,  5065,  5068,  5071,  5074,  5077,  5086,
    5089,  5098,  5101,  5110,  5113,  5122,  5125,  5134,  5143,  5146,
    5155,  5158,  5161,  5170,  5173,  5176,  5179,  5182,  5191,  5195,
    5199,  5203,  5213,  5222,  5232,  5241,  5244,  5253,  5256,  5259,
    5268,  5271,  5280
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
  const int xquery_parser::yylast_ = 7658;
  const int xquery_parser::yynnts_ = 231;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 425;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 272;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 526;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5288 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


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

