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
#line 839 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

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
        case 94: /* "\"'DECIMAL'\"" */
#line 732 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 105: /* "\"'DOUBLE'\"" */
#line 731 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 129: /* "\"'INTEGER'\"" */
#line 730 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 284: /* "VersionDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 285: /* "MainModule" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "LibraryModule" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "ModuleDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "Prolog" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "SIND_DeclList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "VFO_DeclList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "SIND_Decl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "VFO_Decl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "Setter" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "Import" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "NamespaceDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "BoundarySpaceDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "DefaultNamespaceDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "OptionDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "OrderingModeDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "EmptyOrderDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "CopyNamespacesDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "DefaultCollationDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "BaseURIDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "SchemaImport" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "URILiteralList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "SchemaPrefix" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "ModuleImport" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "VarNameAndType" */
#line 744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };
#line 346 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "VarDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "IndexDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 356 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "IndexDeclSuffix" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 361 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "IndexField" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 366 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "IndexField1" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 371 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "IndexFieldList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 376 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "ConstructionDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 381 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "FunctionSig" */
#line 744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 386 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "Block" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 391 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "BlockBody" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 396 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "AssignExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 401 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "ExitExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 406 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "WhileExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 411 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "FlowCtlStatement" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 416 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "IndexStatement" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 421 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "FunctionDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 426 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "ParamList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 431 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "Param" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 436 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "EnclosedExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 441 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "BracedExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 446 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "QueryBody" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 451 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "Expr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 456 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "ExprSingle" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 461 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "FLWORExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 466 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "ReturnExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 471 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "FLWORWinCond" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "WindowClause" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 481 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "CountClause" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 486 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "ForLetWinClause" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 491 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "FLWORClauseList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 496 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "ForClause" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 501 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "VarInDeclList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 506 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "VarInDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 511 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "PositionalVar" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 516 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "LetClause" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 521 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "VarGetsDeclList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "EvalVarDeclList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "VarGetsDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 536 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "WindowVarDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "WindowVars" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "WindowVars3" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 551 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "WindowVars2" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 556 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "EvalVarDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 561 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "WhereClause" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 566 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "GroupByClause" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 571 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "GroupSpecList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 576 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "GroupSpec" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 581 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "GroupCollationSpec" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 586 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "OrderByClause" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 591 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "OrderSpecList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 596 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "OrderSpec" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 601 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "OrderModifier" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 606 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "OrderDirSpec" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 611 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "OrderEmptySpec" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 616 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "OrderCollationSpec" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 621 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "QuantifiedExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 626 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "QVarInDeclList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 631 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "QVarInDecl" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 636 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "TypeswitchExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 641 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "CaseClauseList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 646 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "CaseClause" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 651 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "IfExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 656 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "OrExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 661 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "AndExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 666 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ComparisonExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 671 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "FTContainsExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 676 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "RangeExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 681 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "AdditiveExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 686 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "MultiplicativeExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 691 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "UnionExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 696 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "IntersectExceptExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 701 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "InstanceofExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 706 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "TreatExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 711 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "CastableExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 716 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "CastExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 721 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "UnaryExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 726 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "SignList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 731 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ValueExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 736 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ValueComp" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 741 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "NodeComp" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 746 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "ValidateExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 751 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "ExtensionExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 756 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "PragmaList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 761 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "Pragma" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 766 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "PathExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 771 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "RelativePathExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 776 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "StepExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 781 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "AxisStep" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 786 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ForwardStep" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 791 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "ForwardAxis" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 796 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "AbbrevForwardStep" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 801 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "ReverseStep" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 806 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ReverseAxis" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 811 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "NodeTest" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 816 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "NameTest" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 821 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "Wildcard" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 826 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "FilterExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 831 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "PredicateList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 836 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "Predicate" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 841 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "PrimaryExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 846 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "Literal" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 851 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "NumericLiteral" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 856 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "VarRef" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 861 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "ParenthesizedExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 866 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "ContextItemExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 871 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderedExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 876 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "UnorderedExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 881 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "FunctionCall" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 886 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "ArgList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 891 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "Constructor" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 896 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "DirectConstructor" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 901 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "DirElemConstructor" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 906 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "DirElemContentList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 911 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "DirAttributeList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 916 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "DirAttr" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 921 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "DirAttributeValue" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 926 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "Opt_QuoteAttrContentList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 931 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "QuoteAttrContentList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 936 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "Opt_AposAttrContentList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 941 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "AposAttrContentList" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 946 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "QuoteAttrValueContent" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 951 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "AposAttrValueContent" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 956 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "DirElemContent" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 961 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "CommonContent" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 966 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "DirCommentConstructor" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 971 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "DirPIConstructor" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 976 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "CDataSection" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 981 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "ComputedConstructor" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 986 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "CompDocConstructor" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 991 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "CompElemConstructor" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 996 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "CompAttrConstructor" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1001 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CompTextConstructor" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1006 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "CompCommentConstructor" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1011 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "CompPIConstructor" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1016 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SingleType" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1021 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "TypeDeclaration" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1026 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SequenceType" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1031 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "OccurrenceIndicator" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1036 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ItemType" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1041 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "AtomicType" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1046 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "KindTest" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1051 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "AnyKindTest" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1056 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "DocumentTest" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1061 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "TextTest" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1066 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "CommentTest" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1071 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "PITest" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1076 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "AttributeTest" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1081 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "SchemaAttributeTest" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1086 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "ElementTest" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1091 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "SchemaElementTest" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1096 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "TypeName" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1101 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "TypeName_WITH_HOOK" */
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1106 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "StringLiteral" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1111 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "InsertExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1116 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "DeleteExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1121 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ReplaceExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1126 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "RenameExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1131 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "TransformExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1136 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "VarNameList" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1141 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "VarNameDecl" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1146 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "TryExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1151 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "CatchListExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1156 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "CatchExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1161 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "EvalExpr" */
#line 742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1166 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 112 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}
  /* Line 547 of yacc.c.  */
#line 1247 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
#line 857 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 4:
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 878 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 7:
#line 883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 8:
#line 895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		;}
    break;

  case 9:
#line 900 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    ;}
    break;

  case 10:
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 11:
#line 917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		;}
    break;

  case 12:
#line 929 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 13:
#line 941 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval)));
		;}
    break;

  case 14:
#line 953 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 15:
#line 959 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 16:
#line 965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 17:
#line 977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 18:
#line 983 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 997 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 20:
#line 1003 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 40:
#line 1070 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 41:
#line 1082 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 42:
#line 1087 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 43:
#line 1098 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 44:
#line 1104 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 45:
#line 1116 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 46:
#line 1129 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		;}
    break;

  case 47:
#line 1140 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 48:
#line 1145 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 49:
#line 1157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 50:
#line 1162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 51:
#line 1173 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 52:
#line 1179 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 53:
#line 1185 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 54:
#line 1191 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 55:
#line 1210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 56:
#line 1221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 57:
#line 1232 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 58:
#line 1239 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		;}
    break;

  case 59:
#line 1246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 60:
#line 1253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 61:
#line 1266 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 62:
#line 1272 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 63:
#line 1287 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 64:
#line 1291 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 65:
#line 1301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 66:
#line 1307 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		;}
    break;

  case 67:
#line 1314 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 68:
#line 1320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		;}
    break;

  case 69:
#line 1331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (driver.symtab.get((off_t) (yysemantic_stack_[(2) - (2)].sval)), NULL);
    ;}
    break;

  case 70:
#line 1335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (driver.symtab.get((off_t) (yysemantic_stack_[(3) - (2)].sval)),
                               dynamic_cast<TypeDeclaration *> ((yysemantic_stack_[(3) - (3)].node)));
    ;}
    break;

  case 71:
#line 1345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(5) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								nt->name,
								nt->type,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 72:
#line 1353 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(4) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
		;}
    break;

  case 73:
#line 1359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(6) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
		;}
    break;

  case 74:
#line 1368 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = parser::the_declare; ;}
    break;

  case 75:
#line 1370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = parser::the_create; ;}
    break;

  case 76:
#line 1375 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "hash"; ;}
    break;

  case 77:
#line 1377 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "btree"; ;}
    break;

  case 78:
#line 1382 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->create = ((yysemantic_stack_[(2) - (1)].strval) == parser::the_create);
      (yyval.node) = d;
    ;}
    break;

  case 79:
#line 1388 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->create = ((yysemantic_stack_[(3) - (1)].strval) == parser::the_create);
      d->uniq = true;
      (yyval.node) = d;
    ;}
    break;

  case 80:
#line 1398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl (LOC ((yyloc)), SYMTAB (2), (yysemantic_stack_[(7) - (4)].expr), "",
                          dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(7) - (6)].node)));
    ;}
    break;

  case 81:
#line 1403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = new IndexDecl (LOC ((yyloc)), SYMTAB (2), (yysemantic_stack_[(8) - (4)].expr), SYMTAB (5),
                                    dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(8) - (7)].node)));
      d->method = (yysemantic_stack_[(8) - (5)].strval);
      (yyval.node) = d;
    ;}
    break;

  case 82:
#line 1413 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 83:
#line 1417 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (1)].node))->coll = driver.symtab.get ((off_t) (yysemantic_stack_[(3) - (3)].sval));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    ;}
    break;

  case 84:
#line 1425 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL);
    ;}
    break;

  case 85:
#line 1429 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<TypeDeclaration *> ((yysemantic_stack_[(2) - (2)].node)));
    ;}
    break;

  case 86:
#line 1436 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexFieldList *l = new IndexFieldList (LOC ((yyloc)));
      l->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
      
    ;}
    break;

  case 87:
#line 1443 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(3) - (1)].node))->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    ;}
    break;

  case 88:
#line 1453 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 89:
#line 1458 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 90:
#line 1470 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 91:
#line 1474 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 92:
#line 1478 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 93:
#line 1482 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 94:
#line 1489 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    ;}
    break;

  case 95:
#line 1496 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = new BlockBody (LOC ((yyloc)));
      blk->add ((yysemantic_stack_[(2) - (1)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 96:
#line 1502 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 97:
#line 1511 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), driver.symtab.get ((off_t)(yysemantic_stack_[(5) - (3)].sval)), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 98:
#line 1518 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 99:
#line 1525 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr)));
    ;}
    break;

  case 100:
#line 1532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 101:
#line 1536 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 102:
#line 1543 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB (3), true);
    ;}
    break;

  case 103:
#line 1547 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB (3), false);
    ;}
    break;

  case 104:
#line 1554 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval))),
                &* (yysemantic_stack_[(5) - (4)].fnsig)->param, &* (yysemantic_stack_[(5) - (4)].fnsig)->ret, NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
		;}
    break;

  case 105:
#line 1562 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval))),
                &* (yysemantic_stack_[(5) - (4)].fnsig)->param, &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
								(yysemantic_stack_[(5) - (5)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
		;}
    break;

  case 106:
#line 1571 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
								&* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern_update);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 107:
#line 1580 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
                &* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_update);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 108:
#line 1589 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval))),
                &* (yysemantic_stack_[(6) - (5)].fnsig)->param, &* (yysemantic_stack_[(6) - (5)].fnsig)->ret,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(6) - (5)].fnsig);
		;}
    break;

  case 109:
#line 1604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 110:
#line 1612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 111:
#line 1626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 112:
#line 1632 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 113:
#line 1644 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 114:
#line 1652 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 115:
#line 1663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 116:
#line 1674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = new Expr(LOC ((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 117:
#line 1680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 136:
#line 1723 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 137:
#line 1732 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 138:
#line 1739 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    ;}
    break;

  case 139:
#line 1743 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    ;}
    break;

  case 140:
#line 1751 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    ;}
    break;

  case 141:
#line 1755 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    ;}
    break;

  case 142:
#line 1759 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    ;}
    break;

  case 143:
#line 1766 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 144:
#line 1770 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 145:
#line 1777 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)), dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 146:
#line 1782 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    ;}
    break;

  case 147:
#line 1791 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 156:
#line 1809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 157:
#line 1815 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 158:
#line 1824 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    ;}
    break;

  case 159:
#line 1828 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    ;}
    break;

  case 160:
#line 1838 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		;}
    break;

  case 161:
#line 1849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 162:
#line 1855 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 163:
#line 1869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 164:
#line 1876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 165:
#line 1884 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 166:
#line 1893 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 167:
#line 1903 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 168:
#line 1911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 169:
#line 1920 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 170:
#line 1929 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 171:
#line 1944 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 172:
#line 1956 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 173:
#line 1967 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 174:
#line 1979 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 175:
#line 1985 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 176:
#line 1997 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 177:
#line 2003 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 178:
#line 2017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 179:
#line 2025 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 180:
#line 2034 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 181:
#line 2042 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 182:
#line 2054 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 183:
#line 2060 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 185:
#line 2071 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)), "", "");
    ;}
    break;

  case 186:
#line 2075 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
    ;}
    break;

  case 187:
#line 2083 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    ;}
    break;

  case 188:
#line 2087 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    ;}
    break;

  case 190:
#line 2096 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)));
    ;}
    break;

  case 191:
#line 2100 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 192:
#line 2104 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)), "");
    ;}
    break;

  case 193:
#line 2111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 194:
#line 2126 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 195:
#line 2134 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 196:
#line 2144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 197:
#line 2150 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 198:
#line 2161 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 199:
#line 2167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 200:
#line 2176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 201:
#line 2186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 202:
#line 2191 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 203:
#line 2203 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 204:
#line 2209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 205:
#line 2223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 206:
#line 2229 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 207:
#line 2241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 208:
#line 2248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 209:
#line 2255 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 210:
#line 2262 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 211:
#line 2269 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 212:
#line 2276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 213:
#line 2283 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 214:
#line 2296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 215:
#line 2300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 216:
#line 2310 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 217:
#line 2315 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 218:
#line 2326 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 219:
#line 2337 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 220:
#line 2344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 221:
#line 2357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 222:
#line 2364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 223:
#line 2376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 224:
#line 2382 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 225:
#line 2395 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 226:
#line 2402 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 227:
#line 2416 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 228:
#line 2422 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 229:
#line 2434 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 230:
#line 2440 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 231:
#line 2453 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 232:
#line 2464 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 233:
#line 2468 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 234:
#line 2479 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 235:
#line 2483 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 236:
#line 2502 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 237:
#line 2506 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 238:
#line 2514 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 239:
#line 2522 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 240:
#line 2530 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 241:
#line 2537 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 242:
#line 2538 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 243:
#line 2546 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 244:
#line 2554 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 245:
#line 2562 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 246:
#line 2576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 247:
#line 2580 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 248:
#line 2587 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 249:
#line 2600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 250:
#line 2604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 251:
#line 2615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 252:
#line 2619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 253:
#line 2623 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 254:
#line 2633 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 255:
#line 2637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 256:
#line 2641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 257:
#line 2645 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 258:
#line 2649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 259:
#line 2659 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 260:
#line 2663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 261:
#line 2668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 262:
#line 2679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 263:
#line 2683 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 264:
#line 2687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 265:
#line 2697 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 266:
#line 2701 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 267:
#line 2713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 268:
#line 2717 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 269:
#line 2729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 270:
#line 2733 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 271:
#line 2745 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 272:
#line 2749 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 273:
#line 2761 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 274:
#line 2765 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 275:
#line 2777 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 276:
#line 2781 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 277:
#line 2785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 278:
#line 2789 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 279:
#line 2801 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 280:
#line 2805 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 281:
#line 2809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 2819 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 283:
#line 2823 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 284:
#line 2827 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 285:
#line 2831 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 286:
#line 2835 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 287:
#line 2839 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 288:
#line 2849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 289:
#line 2853 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 290:
#line 2857 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 291:
#line 2867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 292:
#line 2871 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (2)].node))->get_name(),
                            (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 293:
#line 2883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 294:
#line 2889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 295:
#line 2901 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 296:
#line 2907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 297:
#line 2921 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 298:
#line 2927 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 299:
#line 2969 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 300:
#line 2973 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 301:
#line 2977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 302:
#line 2981 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 303:
#line 2993 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    ;}
    break;

  case 304:
#line 3003 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 305:
#line 3014 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 306:
#line 3019 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 307:
#line 3029 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 308:
#line 3033 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 309:
#line 3043 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 310:
#line 3049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 311:
#line 3055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 312:
#line 3061 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 313:
#line 3073 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 314:
#line 3079 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 315:
#line 3090 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 316:
#line 3094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 317:
#line 3098 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 318:
#line 3102 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 319:
#line 3106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 320:
#line 3110 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 321:
#line 3114 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 322:
#line 3124 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 323:
#line 3128 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 324:
#line 3138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 325:
#line 3144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 326:
#line 3156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 327:
#line 3160 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 328:
#line 3164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 329:
#line 3168 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 330:
#line 3172 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 331:
#line 3187 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 332:
#line 3191 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 333:
#line 3201 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 334:
#line 3205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 335:
#line 3215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 336:
#line 3222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 337:
#line 3229 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 338:
#line 3242 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 339:
#line 3246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 340:
#line 3258 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 341:
#line 3264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 342:
#line 3278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 343:
#line 3289 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 344:
#line 3293 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 345:
#line 3297 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 346:
#line 3301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 347:
#line 3305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 348:
#line 3309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 3313 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 3317 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 3327 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 352:
#line 3331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 353:
#line 3341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 354:
#line 3346 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 355:
#line 3351 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 356:
#line 3362 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 357:
#line 3372 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 358:
#line 3376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 359:
#line 3387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 360:
#line 3397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 361:
#line 3408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 362:
#line 3464 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 363:
#line 3470 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 364:
#line 3482 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 365:
#line 3488 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 366:
#line 3500 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 367:
#line 3504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 368:
#line 3514 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 369:
#line 3518 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 370:
#line 3522 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 371:
#line 3532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 372:
#line 3540 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 373:
#line 3548 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 374:
#line 3556 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 375:
#line 3564 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 376:
#line 3572 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 377:
#line 3587 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 378:
#line 3593 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 379:
#line 3605 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 380:
#line 3611 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 381:
#line 3624 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 384:
#line 3641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 385:
#line 3646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 386:
#line 3657 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 387:
#line 3661 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 388:
#line 3668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 389:
#line 3674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 390:
#line 3680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 391:
#line 3688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 392:
#line 3702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 393:
#line 3706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 394:
#line 3713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 395:
#line 3719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 396:
#line 3725 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 397:
#line 3733 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 398:
#line 3747 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 399:
#line 3752 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 400:
#line 3763 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 401:
#line 3768 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 402:
#line 3779 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 403:
#line 3784 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 404:
#line 3789 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 405:
#line 3795 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 406:
#line 3807 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 407:
#line 3813 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 408:
#line 3818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 409:
#line 3823 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 410:
#line 3834 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 411:
#line 3839 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 412:
#line 3854 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 413:
#line 3859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 414:
#line 3876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 415:
#line 3891 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 416:
#line 3895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 417:
#line 3899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 418:
#line 3903 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 419:
#line 3907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 420:
#line 3911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 421:
#line 3921 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 422:
#line 3932 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 423:
#line 3938 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 424:
#line 3944 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 425:
#line 3949 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 426:
#line 3971 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 427:
#line 3977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 428:
#line 3983 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 429:
#line 3988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 430:
#line 3999 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 431:
#line 4010 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(4) - (3)].expr)));
		;}
    break;

  case 432:
#line 4021 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 433:
#line 4027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 434:
#line 4033 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 435:
#line 4038 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 436:
#line 4049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 437:
#line 4055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 438:
#line 4067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 439:
#line 4079 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 440:
#line 4085 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 441:
#line 4091 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 442:
#line 4128 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 443:
#line 4133 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 444:
#line 4138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 445:
#line 4149 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 446:
#line 4153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 447:
#line 4157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 448:
#line 4167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 449:
#line 4178 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 450:
#line 4182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 451:
#line 4186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 452:
#line 4190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 453:
#line 4194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 454:
#line 4198 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 455:
#line 4202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 456:
#line 4206 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 457:
#line 4210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 458:
#line 4220 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 459:
#line 4230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 460:
#line 4234 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 461:
#line 4239 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 462:
#line 4250 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 463:
#line 4260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 464:
#line 4270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 465:
#line 4274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 466:
#line 4278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 467:
#line 4288 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 468:
#line 4294 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 469:
#line 4300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 470:
#line 4306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 471:
#line 4312 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 472:
#line 4324 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 473:
#line 4335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		;}
    break;

  case 474:
#line 4342 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
                           NULL,
                           true);
		;}
    break;

  case 475:
#line 4349 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		;}
    break;

  case 476:
#line 4356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		;}
    break;

  case 477:
#line 4363 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 478:
#line 4370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		;}
    break;

  case 479:
#line 4377 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 480:
#line 4390 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 481:
#line 4411 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 482:
#line 4418 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 483:
#line 4438 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 484:
#line 4478 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 485:
#line 4483 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 486:
#line 4486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 487:
#line 4494 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 488:
#line 4500 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 489:
#line 4506 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 490:
#line 4512 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 491:
#line 4518 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 492:
#line 4525 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 493:
#line 4531 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 494:
#line 4537 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 495:
#line 4543 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 496:
#line 4549 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 497:
#line 4561 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 498:
#line 4566 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 499:
#line 4576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 500:
#line 4582 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 501:
#line 4594 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 502:
#line 4620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 503:
#line 4631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 504:
#line 4637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 505:
#line 4650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 506:
#line 4664 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 507:
#line 4671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 508:
#line 4678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 509:
#line 4689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 510:
#line 4696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 511:
#line 4704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 512:
#line 4713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(14) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (9)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (12)].sval)),
                          (yysemantic_stack_[(14) - (14)].expr));
    ;}
    break;

  case 514:
#line 4729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 515:
#line 4746 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 516:
#line 4747 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty"); ;}
    break;

  case 517:
#line 4748 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("attribute"); ;}
    break;

  case 518:
#line 4749 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("comment"); ;}
    break;

  case 519:
#line 4750 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document-node"); ;}
    break;

  case 520:
#line 4751 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("element"); ;}
    break;

  case 521:
#line 4752 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("item"); ;}
    break;

  case 522:
#line 4753 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("if"); ;}
    break;

  case 523:
#line 4754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("node"); ;}
    break;

  case 524:
#line 4755 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("processing-instruction"); ;}
    break;

  case 525:
#line 4756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-attribute"); ;}
    break;

  case 526:
#line 4757 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-element"); ;}
    break;

  case 527:
#line 4758 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("text"); ;}
    break;

  case 528:
#line 4759 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("typeswitch"); ;}
    break;

  case 529:
#line 4760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty-sequence"); ;}
    break;

  case 530:
#line 4761 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("boundary-space"); ;}
    break;

  case 531:
#line 4762 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ft-option"); ;}
    break;

  case 532:
#line 4763 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("base-uri"); ;}
    break;

  case 533:
#line 4764 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lax"); ;}
    break;

  case 534:
#line 4765 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strict"); ;}
    break;

  case 535:
#line 4766 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("idiv"); ;}
    break;

  case 536:
#line 4767 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document"); ;}
    break;

  case 537:
#line 4768 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("not"); ;}
    break;

  case 538:
#line 4769 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sensitive"); ;}
    break;

  case 539:
#line 4770 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insensitive"); ;}
    break;

  case 540:
#line 4771 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("diacritics"); ;}
    break;

  case 541:
#line 4772 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("without"); ;}
    break;

  case 542:
#line 4773 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stemming"); ;}
    break;

  case 543:
#line 4774 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("thesaurus"); ;}
    break;

  case 544:
#line 4775 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stop"); ;}
    break;

  case 545:
#line 4776 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("wildcards"); ;}
    break;

  case 546:
#line 4777 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("entire"); ;}
    break;

  case 547:
#line 4778 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("content"); ;}
    break;

  case 548:
#line 4779 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("word"); ;}
    break;

  case 549:
#line 4780 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("start"); ;}
    break;

  case 550:
#line 4781 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("end"); ;}
    break;

  case 551:
#line 4782 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("most"); ;}
    break;

  case 552:
#line 4783 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("skip"); ;}
    break;

  case 553:
#line 4784 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy"); ;}
    break;

  case 554:
#line 4785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("value"); ;}
    break;

  case 555:
#line 4786 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("eq"); ;}
    break;

  case 556:
#line 4787 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ne"); ;}
    break;

  case 557:
#line 4788 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lt"); ;}
    break;

  case 558:
#line 4789 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("le"); ;}
    break;

  case 559:
#line 4790 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("gt"); ;}
    break;

  case 560:
#line 4791 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ge"); ;}
    break;

  case 561:
#line 4792 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("at"); ;}
    break;

  case 562:
#line 4793 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("variable"); ;}
    break;

  case 563:
#line 4794 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("return"); ;}
    break;

  case 564:
#line 4795 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("for"); ;}
    break;

  case 565:
#line 4796 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("outer"); ;}
    break;

  case 566:
#line 4797 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sliding"); ;}
    break;

  case 567:
#line 4798 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("tumbling"); ;}
    break;

  case 568:
#line 4799 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("previous"); ;}
    break;

  case 569:
#line 4800 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("next"); ;}
    break;

  case 570:
#line 4801 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("only"); ;}
    break;

  case 571:
#line 4802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("when"); ;}
    break;

  case 572:
#line 4803 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("count"); ;}
    break;

  case 573:
#line 4804 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("in"); ;}
    break;

  case 574:
#line 4805 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("let"); ;}
    break;

  case 575:
#line 4806 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("where"); ;}
    break;

  case 576:
#line 4807 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("by"); ;}
    break;

  case 577:
#line 4808 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("group"); ;}
    break;

  case 578:
#line 4809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("order"); ;}
    break;

  case 579:
#line 4810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stable"); ;}
    break;

  case 580:
#line 4811 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ascending"); ;}
    break;

  case 581:
#line 4812 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("descending"); ;}
    break;

  case 582:
#line 4813 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("greatest"); ;}
    break;

  case 583:
#line 4814 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("least"); ;}
    break;

  case 584:
#line 4815 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("collation"); ;}
    break;

  case 585:
#line 4816 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("some"); ;}
    break;

  case 586:
#line 4817 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("every"); ;}
    break;

  case 587:
#line 4818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("satisfies"); ;}
    break;

  case 588:
#line 4819 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("case"); ;}
    break;

  case 589:
#line 4820 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("as"); ;}
    break;

  case 590:
#line 4821 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("then"); ;}
    break;

  case 591:
#line 4822 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("else"); ;}
    break;

  case 592:
#line 4823 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("or"); ;}
    break;

  case 593:
#line 4824 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("and"); ;}
    break;

  case 594:
#line 4825 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("instance"); ;}
    break;

  case 595:
#line 4826 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("of"); ;}
    break;

  case 596:
#line 4827 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("castable"); ;}
    break;

  case 597:
#line 4828 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("to"); ;}
    break;

  case 598:
#line 4829 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("div"); ;}
    break;

  case 599:
#line 4830 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("mod"); ;}
    break;

  case 600:
#line 4831 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("union"); ;}
    break;

  case 601:
#line 4832 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("intersect"); ;}
    break;

  case 602:
#line 4833 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("except"); ;}
    break;

  case 603:
#line 4834 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("validate"); ;}
    break;

  case 604:
#line 4835 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cast"); ;}
    break;

  case 605:
#line 4836 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("treat"); ;}
    break;

  case 606:
#line 4837 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("is"); ;}
    break;

  case 607:
#line 4838 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("preserve"); ;}
    break;

  case 608:
#line 4839 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strip"); ;}
    break;

  case 609:
#line 4840 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("namespace"); ;}
    break;

  case 610:
#line 4841 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("external"); ;}
    break;

  case 611:
#line 4842 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("encoding"); ;}
    break;

  case 612:
#line 4843 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-preserve"); ;}
    break;

  case 613:
#line 4844 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("inherit"); ;}
    break;

  case 614:
#line 4845 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-inherit"); ;}
    break;

  case 615:
#line 4846 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("declare"); ;}
    break;

  case 616:
#line 4847 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("construction"); ;}
    break;

  case 617:
#line 4848 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordering"); ;}
    break;

  case 618:
#line 4849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("default"); ;}
    break;

  case 619:
#line 4850 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy-namespaces"); ;}
    break;

  case 620:
#line 4851 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("option"); ;}
    break;

  case 621:
#line 4852 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("version"); ;}
    break;

  case 622:
#line 4853 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("import"); ;}
    break;

  case 623:
#line 4854 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema"); ;}
    break;

  case 624:
#line 4855 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("module"); ;}
    break;

  case 625:
#line 4856 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("function"); ;}
    break;

  case 626:
#line 4857 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("score"); ;}
    break;

  case 627:
#line 4858 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ftcontains"); ;}
    break;

  case 628:
#line 4859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("weight"); ;}
    break;

  case 629:
#line 4860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("window"); ;}
    break;

  case 630:
#line 4861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("distance"); ;}
    break;

  case 631:
#line 4862 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("occurs"); ;}
    break;

  case 632:
#line 4863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("times"); ;}
    break;

  case 633:
#line 4864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("same"); ;}
    break;

  case 634:
#line 4865 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("different"); ;}
    break;

  case 635:
#line 4866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lowercase"); ;}
    break;

  case 636:
#line 4867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("uppercase"); ;}
    break;

  case 637:
#line 4868 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("relationship"); ;}
    break;

  case 638:
#line 4869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("levels"); ;}
    break;

  case 639:
#line 4870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("language"); ;}
    break;

  case 640:
#line 4871 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("any"); ;}
    break;

  case 641:
#line 4872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("all"); ;}
    break;

  case 642:
#line 4873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("phrase"); ;}
    break;

  case 643:
#line 4874 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exactly"); ;}
    break;

  case 644:
#line 4875 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("from"); ;}
    break;

  case 645:
#line 4876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("words"); ;}
    break;

  case 646:
#line 4877 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentences"); ;}
    break;

  case 647:
#line 4878 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentence"); ;}
    break;

  case 648:
#line 4879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("paragraph"); ;}
    break;

  case 649:
#line 4880 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("replace"); ;}
    break;

  case 650:
#line 4881 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("modify"); ;}
    break;

  case 651:
#line 4882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("first"); ;}
    break;

  case 652:
#line 4883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insert"); ;}
    break;

  case 653:
#line 4884 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("bofer"); ;}
    break;

  case 654:
#line 4885 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("after"); ;}
    break;

  case 655:
#line 4886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("revalidation"); ;}
    break;

  case 656:
#line 4887 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("with"); ;}
    break;

  case 657:
#line 4888 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("nodes"); ;}
    break;

  case 658:
#line 4889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("rename"); ;}
    break;

  case 659:
#line 4890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("last"); ;}
    break;

  case 660:
#line 4891 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("delete"); ;}
    break;

  case 661:
#line 4892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("into"); ;}
    break;

  case 662:
#line 4893 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("updating"); ;}
    break;

  case 663:
#line 4894 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordered"); ;}
    break;

  case 664:
#line 4895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("unordered"); ;}
    break;

  case 665:
#line 4896 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exit"); ;}
    break;

  case 666:
#line 4897 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("loop"); ;}
    break;

  case 667:
#line 4898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("break"); ;}
    break;

  case 668:
#line 4899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cont"); ;}
    break;

  case 669:
#line 4900 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("set"); ;}
    break;

  case 670:
#line 4901 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("index"); ;}
    break;

  case 671:
#line 4902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("create"); ;}
    break;

  case 672:
#line 4903 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("unique"); ;}
    break;

  case 673:
#line 4904 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("on"); ;}
    break;

  case 674:
#line 4905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("hash"); ;}
    break;

  case 675:
#line 4906 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("btree"); ;}
    break;

  case 676:
#line 4907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("DROP"); ;}
    break;

  case 677:
#line 4919 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 678:
#line 4925 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 679:
#line 4942 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 680:
#line 4946 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 681:
#line 4950 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 682:
#line 4954 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 683:
#line 4964 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 684:
#line 4967 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 685:
#line 4970 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 686:
#line 4973 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 687:
#line 4982 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 688:
#line 4985 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 689:
#line 4994 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 690:
#line 4997 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 691:
#line 5006 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 692:
#line 5009 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 693:
#line 5018 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 694:
#line 5021 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 695:
#line 5030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 696:
#line 5033 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 697:
#line 5036 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 698:
#line 5045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 699:
#line 5048 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 700:
#line 5057 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 701:
#line 5061 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, static_cast<Expr *> ((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 702:
#line 5071 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 703:
#line 5074 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 704:
#line 5077 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 705:
#line 5080 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 706:
#line 5083 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 707:
#line 5092 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 708:
#line 5101 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 709:
#line 5105 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 710:
#line 5109 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 711:
#line 5113 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 712:
#line 5117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 713:
#line 5121 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 714:
#line 5125 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 715:
#line 5135 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 716:
#line 5138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 717:
#line 5141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 718:
#line 5144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 719:
#line 5153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 726:
#line 5186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 727:
#line 5189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 728:
#line 5192 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 729:
#line 5195 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 730:
#line 5198 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 731:
#line 5201 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 732:
#line 5210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 733:
#line 5213 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 734:
#line 5222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 735:
#line 5225 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 736:
#line 5228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 737:
#line 5231 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 738:
#line 5240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 739:
#line 5243 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 740:
#line 5246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 741:
#line 5249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 742:
#line 5252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 743:
#line 5261 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 744:
#line 5264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 745:
#line 5273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 746:
#line 5276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 747:
#line 5285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 748:
#line 5288 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 749:
#line 5297 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 750:
#line 5300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 751:
#line 5309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 752:
#line 5318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 753:
#line 5321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 754:
#line 5330 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 755:
#line 5333 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 756:
#line 5336 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 757:
#line 5345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 758:
#line 5348 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 759:
#line 5351 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 760:
#line 5354 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 761:
#line 5357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 762:
#line 5366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 763:
#line 5370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 764:
#line 5374 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 765:
#line 5378 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 766:
#line 5388 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 767:
#line 5397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 768:
#line 5407 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 769:
#line 5416 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 770:
#line 5419 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 771:
#line 5428 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 772:
#line 5431 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 773:
#line 5434 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 774:
#line 5443 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 775:
#line 5446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 776:
#line 5455 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6695 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -944;
  const short int
  xquery_parser::yypact_[] =
  {
      1288,  -944,  -944,  -944,  -944,   -67,   375,  -944,   175,  7635,
     257,  6395,   299,   -21,   516,    52,  -944,  -944,   337,   120,
    -944,   608,   352,  -944,   351,  -944,  -944,  -944,   382,   410,
    -944,   464,   467,   521,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,   542,  -944,   515,   531,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  6643,  -944,  5641,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  8131,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
     488,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  4361,  1545,  8131,  -944,  -944,  -944,  -944,  -944,
    -944,   554,  -944,  -944,  -944,  -944,   677,  -944,  6147,  -944,
    -944,  -944,  -944,  -944,  8131,  -944,  -944,  5385,  -944,  -944,
    -944,  -944,  -944,  -944,   563,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,    24,   508,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,   413,   568,   435,  -944,   504,   390,  -944,
    -944,  -944,  -944,  -944,  -944,   611,  -944,   580,   613,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,   152,   458,  -944,  -944,  -944,
    -944,  -944,  1801,   715,  -944,  4617,  -944,  -944,    -8,  4361,
     547,   548,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,   417,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
     628,  -944,  -944,  -944,  -944,   211,  8131,  -944,  -944,  -944,
    -944,  -944,   574,   655,  -944,   634,   497,   420,   315,   437,
     498,  -944,   662,   555,   657,   659,  4873,  -944,  -944,  -944,
     404,  -944,  -944,  5385,  -944,   459,  -944,   609,  5641,  -944,
     609,  5641,  -944,  -944,  -944,  -944,   609,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,   610,  -944,  4361,  -944,  4361,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  4361,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,   615,  -944,  4361,  4361,  6891,   620,
    4361,  4361,   588,  4361,   591,  8131,   721,   722,  8131,   441,
     -41,   741,   163,   444,   661,    85,   745,   474,   -28,  4361,
    -944,  4361,    55,   631,    78,    58,  8131,   745,  8131,  8131,
    4361,   518,   520,  -944,   665,   666,  -944,  8131,    25,  4361,
    7139,   635,   637,   638,   639,   641,   642,  -944,  -944,  -944,
    8131,   517,  2057,   -15,  -944,    17,   755,  4361,    53,  -944,
     766,   617,  -944,  4361,   592,  -944,   764,  4361,  4361,   621,
    4361,  4361,  4361,  4361,   575,  8131,  4361,  8131,   741,   741,
    -944,  -944,  -944,  -944,   223,   608,  -944,  -944,  -944,    -8,
      -5,   526,   741,  -944,  4361,   640,   410,   467,   521,   689,
     643,   644,  4361,  4361,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,   700,  -944,   -32,  5129,  5129,  5129,  -944,  5129,  5129,
    -944,  5129,  -944,  5129,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  5129,  5129,     8,  5129,  5129,  5129,  5129,  5129,  5129,
    5129,  5129,  5129,  5129,  5129,   584,   719,   723,   724,  -944,
    -944,  -944,  2313,  -944,  -944,  5385,  5385,  4361,   609,  -944,
    -944,   609,  -944,   609,  2569,  -944,   633,    13,  4361,    43,
      23,  -944,    72,   133,  2825,   225,   270,  -944,   283,  -944,
     664,  8131,  8131,   783,  -944,  -944,  -944,  -944,  -944,  -944,
     713,   714,  -944,  -944,  8131,   514,   668,   670,   741,   698,
     699,  -944,  -944,  -944,   434,    40,   440,   791,  -944,  -944,
     353,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,   168,
     304,   647,  -944,   648,  3081,   745,   742,   790,   745,   741,
     746,    -7,  -944,    46,   712,   704,   737,  -944,   -26,   671,
    -944,  -944,  8131,    -3,  -944,   672,   637,   515,  -944,   673,
     675,   318,  -944,   187,   198,  3337,    61,  -944,   -11,  -944,
    -944,  8131,   755,  -944,   -25,   319,  -944,  -944,  -944,  -944,
     335,  -944,   235,  -944,  -944,  -944,    42,    93,   765,   625,
     646,   -19,  -944,   726,   681,   424,  -944,  -944,  -944,  -944,
     676,  -944,    15,  -944,  -944,   582,  -944,   695,  8131,  4361,
     751,  -944,  -944,   752,  7883,   753,  4361,   754,   -56,   729,
     -16,   655,  -944,  -944,  -944,  -944,  -944,  5129,  -944,  -944,
    -944,  4361,     8,   250,  -944,   604,   499,   627,   626,  -944,
    -944,   618,   344,   315,   315,     1,   437,   437,   437,   437,
     498,   498,  -944,  -944,  7883,  7883,  8131,  8131,  -944,   343,
    -944,  -944,     3,  -944,  -944,  -944,   212,   730,  -944,   346,
     780,   732,  8131,  -944,  8131,  -944,  -944,   364,  -944,  -944,
    -944,   228,   455,   664,   664,  -944,   377,   456,   788,   744,
    4361,   741,   741,  -944,   572,   741,  -944,  -944,   614,  -944,
    -944,   612,   414,  -944,  -944,  -944,  -944,  -944,  -944,   616,
    -944,  -944,   693,   738,  -944,  -944,  -944,   365,   760,   741,
     735,   767,   797,   741,   777,  4361,  4361,   756,   741,  4361,
     778,  4361,   758,   -62,  -944,   180,   652,  -944,  -944,   511,
      -3,  -944,  -944,  -944,   757,  8131,  -944,  8131,  -944,  -944,
     368,  4361,  -944,   859,  -944,     5,  -944,   312,  -944,  -944,
     865,  -944,   450,  4361,  4361,  4361,   457,  4361,  4361,  4361,
    4361,  4361,  4361,   785,  4361,  4361,   669,   761,   786,    -5,
    4361,  4361,  -944,   477,   798,  -944,  8131,   800,  -944,  8131,
     759,   762,  -944,   317,  -944,  -944,  -944,  8131,  -944,  8131,
    4361,   769,  4361,  4361,   -44,   773,  -944,   369,   727,  -944,
     674,  -944,   -64,  -944,   391,    16,   679,     8,   391,  5129,
    5129,    98,  -944,  -944,  -944,  -944,  -944,  -944,  -944,     8,
     774,    16,  -944,   651,   853,  -944,  -944,  -944,  -944,  -944,
     779,  -944,  -944,  -944,  4361,  -944,  -944,  -944,  7387,   216,
    -944,  3593,   747,   748,   787,   749,   750,  -944,  8131,   825,
     226,  -944,  -944,  4361,  -944,   481,   730,  -944,  -944,  -944,
    -944,  -944,  4361,  -944,  -944,  -944,  -944,  -944,  -944,   663,
      29,   888,  -944,    62,  -944,  -944,  4361,  3849,  -944,   741,
     820,  -944,  -944,  -944,   741,   820,  8131,  -944,  -944,  4361,
     763,  -944,  8131,  -944,  4361,  4361,   794,  4361,   796,  -944,
     817,   823,  4361,  8131,   623,   858,  -944,  -944,  -944,  4105,
     768,   770,  -944,  -944,  -944,   812,  -944,   453,  -944,  -944,
     920,  -944,  -944,  4361,  8131,  -944,  -944,   476,  -944,  -944,
    -944,   771,   716,   717,  -944,  -944,  -944,   718,   725,  -944,
    -944,  -944,  -944,  -944,   710,  8131,   772,  -944,   792,   669,
    -944,  4361,  8131,    18,   798,  -944,   741,  -944,   576,  -944,
      38,   842,  -944,  4361,   845,   751,  -944,   776,   782,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  4361,  -944,  -944,  4361,
     813,  4361,  -944,  -944,  5129,  -944,  -944,  -944,  -944,  -944,
     258,  5129,  5129,   245,  -944,   627,  -944,  -944,   202,  5129,
    -944,  -944,   626,     8,   690,  -944,  -944,  -944,  -944,  8131,
     781,   324,  -944,  -944,   372,  -944,  -944,  -944,  -944,  -944,
     788,  7883,   843,   867,   373,  -944,  -944,  -944,  -944,    28,
     923,   929,    28,    41,   241,   246,   844,  -944,   378,   870,
     741,   820,  -944,  -944,  -944,  -944,  -944,  -944,  4361,  -944,
    4361,  8131,  8131,  -944,   473,  -944,  4361,  -944,   385,  -944,
    -944,   859,  8131,   537,  -944,   401,   859,  8131,  -944,  -944,
    4361,  4361,  4361,  4361,  4361,  -944,  4361,  5897,  -944,   789,
    -944,   818,  -944,  -944,   805,  -944,  -944,  -944,   842,  -944,
    -944,  -944,   741,  -944,  -944,  -944,  -944,  -944,  -944,  4361,
    -944,   437,  5129,  5129,   437,   445,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,   878,  4361,  8131,  4361,  -944,  -944,
    -944,  -944,  7883,  -944,    29,    29,    28,  -944,  -944,  -944,
      45,    28,   937,   720,   880,  -944,   880,  -944,  4361,  -944,
     741,  -944,  -944,  -944,   897,  -944,  -944,  -944,  -944,     2,
     859,  8131,  -944,   793,   859,  -944,  -944,  -944,  -944,  -944,
    -944,   251,  -944,  4361,   254,   818,  -944,  -944,  -944,   437,
     437,  5129,  7883,  -944,   802,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,    16,  -944,   261,  -944,   263,  -944,   820,   861,
      66,   224,  -944,   795,   859,  -944,   799,   862,   832,  -944,
     882,   788,  4361,  -944,   265,   437,   803,  4361,   731,   880,
    -944,  -944,  8131,  -944,  -944,   896,    73,  -944,  -944,  -944,
    -944,   814,   362,  -944,  -944,  -944,   801,  -944,  8131,  -944,
     741,  -944,  -944,  -944,  4361,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,   282,  -944,  -944,   873,
     832,  8131,  -944,   286,   877,   832,  8131,  -944,   815,   832,
    -944
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   336,   337,   515,   483,   665,   667,   666,     0,   603,
     528,   520,   536,   527,   518,   615,   625,   662,   522,   524,
     551,   622,   585,   579,   624,   620,   548,   623,   669,   574,
     616,     0,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   617,   668,   532,   526,   519,   619,   594,   525,   530,
     327,   330,   593,   589,   580,   561,   517,   317,     0,   588,
     596,   604,   315,   584,   353,   562,   618,   316,   319,   581,
     598,     0,   359,   325,   355,   591,   516,   582,   583,   611,
     586,   602,   610,   321,   320,   535,   573,   613,   354,   601,
     606,   521,     0,     0,     0,   276,   599,   609,   614,   612,
     592,   663,   578,   576,   577,   326,     0,   275,     0,   329,
     328,   607,   563,   587,     0,   318,   303,     0,   335,   608,
     590,   597,   605,   600,   664,   555,   560,   559,   558,   557,
     556,   529,   575,     0,     0,   621,   549,   654,   653,   655,
     534,   533,   552,   660,   523,   652,   657,   658,   649,   554,
     595,   651,   661,   659,   650,   553,   656,     0,     0,   641,
     640,   538,   531,   540,   539,   634,   630,   546,   550,   547,
     643,   644,   627,   537,   639,   638,   635,   631,   648,   642,
     637,   633,   626,   647,   646,   632,   636,   628,   629,   541,
     542,   544,   645,   543,   545,   671,   676,   672,   670,   674,
     675,   673,     0,     0,     2,     0,     4,     6,     0,     0,
       0,     0,    17,    19,    21,    22,    23,    30,    24,    27,
      28,    34,    35,    36,    31,    32,    38,    39,    25,     0,
      29,    33,   134,   133,   130,   131,   132,   135,    26,    11,
     115,   116,   118,   150,   156,     0,     0,   148,   149,   119,
     120,   121,   122,   232,   234,   236,   246,   249,   251,   254,
     259,   262,   265,   267,   269,   271,     0,   273,   279,   281,
       0,   295,   280,   299,   302,   304,   307,   309,     0,   314,
     311,     0,   322,   332,   334,   308,   338,   343,   351,   344,
     345,   346,   349,   350,   347,   348,   366,   368,   369,   370,
     367,   415,   416,   417,   418,   419,   420,   331,   457,   449,
     456,   455,   454,   451,   453,   450,   452,   352,    37,   123,
     124,   126,   125,   127,   128,   333,   129,     0,   100,     0,
     665,   667,   603,   528,   520,   536,   527,   518,   615,   522,
     524,   622,   585,   624,   669,   574,   564,   565,   668,   526,
     519,   517,   586,     0,   663,   664,   660,   523,   652,   658,
     649,   553,   671,   676,     0,   481,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     514,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   158,     0,     0,   101,     0,     0,     0,
       0,     0,   520,   527,   518,   524,   517,   323,   333,   356,
       0,   671,     0,     0,   357,     0,   382,     0,     0,   298,
       0,     0,   301,     0,     0,   411,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     1,     5,     7,    74,     0,    75,    12,    10,    14,
      15,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,   155,   151,   157,   152,   154,
     153,   160,   161,     0,     0,     0,     0,   290,     0,     0,
     288,     0,   241,     0,   289,   282,   287,   286,   285,   284,
     283,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
     277,   274,     0,   296,   300,     0,     0,     0,   310,   340,
     313,   312,   324,   339,     0,    98,     0,     0,     0,     0,
       0,   473,     0,     0,     0,     0,     0,   462,     0,   463,
       0,     0,     0,     0,    88,    89,    47,    48,   513,    56,
       0,     0,    41,    42,     0,     0,     0,     0,     0,     0,
       0,   484,   485,   486,     0,     0,     0,     0,   715,   716,
       0,    46,   708,   709,   710,   711,   712,   713,   714,     0,
       0,     0,   464,     0,     0,     0,    65,     0,     0,     0,
      57,     0,   221,     0,     0,     0,   173,   174,     0,     0,
     138,   139,     0,     0,   159,     0,     0,     0,   459,     0,
       0,     0,   467,     0,     0,     0,     0,    94,     0,    95,
     358,   383,   382,   379,     0,     0,   413,   412,   297,   472,
       0,   410,     0,   497,   498,   458,     0,     0,     0,     0,
       0,     0,   503,     0,     0,     0,   176,   193,   102,   103,
       0,    18,    74,    20,    79,     0,   117,     0,     0,     0,
       0,   137,   194,     0,     0,     0,     0,     0,     0,     0,
       0,   233,   235,   239,   245,   244,   243,     0,   240,   237,
     238,     0,     0,     0,   700,   247,   679,   687,   689,   691,
     693,   695,   698,   253,   252,   250,   256,   257,   258,   255,
     260,   261,   264,   263,     0,     0,     0,     0,   293,     0,
     305,   306,     0,   341,   362,   364,     0,     0,   291,     0,
       0,     0,     0,   477,     0,   474,   422,     0,   421,   430,
     431,     0,     0,     0,     0,    45,     0,     0,    69,    72,
       0,     0,     0,    55,     0,     0,   717,   718,     0,   719,
     723,     0,     0,   752,   721,   722,   751,   720,   724,     0,
     731,   753,     0,     0,   466,   465,   432,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   678,     0,     0,   140,   141,     0,
     146,   480,   460,   461,     0,     0,   470,     0,   468,   426,
       0,     0,    96,   382,   380,     0,   371,     0,   360,   361,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     0,   147,   205,   201,   203,     0,   195,   196,     0,
     521,   529,   438,   439,   445,   446,   448,     0,   163,     0,
       0,     0,     0,     0,     0,     0,   242,     0,     0,   694,
       0,   248,     0,   707,     0,     0,     0,     0,     0,     0,
       0,   680,   684,   702,   683,   706,   704,   703,   705,     0,
       0,     0,   696,   759,   757,   761,   699,   266,   268,   270,
     436,   272,   294,   342,     0,   363,    99,   292,     0,     0,
     227,     0,     0,     0,   481,     0,     0,   423,     0,    90,
       0,   109,   104,     0,   105,     0,     0,    53,    54,    51,
      52,    70,     0,    71,    43,    44,    49,    50,    40,     0,
       0,     0,   726,     0,   725,   742,     0,     0,   433,     0,
      67,    61,    64,    63,     0,    59,     0,   219,   223,     0,
       0,    97,     0,   178,     0,     0,     0,     0,     0,   142,
       0,     0,     0,     0,   187,     0,   184,   189,   145,     0,
       0,     0,   427,   220,   383,     0,   372,     0,   406,   403,
       0,   407,   408,     0,     0,   409,   402,     0,   377,   405,
     404,     0,     0,     0,   490,   491,   487,     0,     0,   495,
     496,   492,   501,   499,     0,     0,     0,   505,     0,   506,
     507,     0,     0,     0,   202,   214,     0,   215,     0,   206,
     207,   208,   209,     0,   198,     0,   162,     0,     0,   442,
     444,   443,   440,   171,   172,   165,     0,   167,   164,     0,
       0,     0,   701,   697,     0,   754,   755,   775,   774,   770,
       0,     0,     0,     0,   756,   688,   769,   681,     0,     0,
     686,   685,   690,     0,     0,   760,   758,   437,   365,     0,
       0,     0,   228,   424,     0,   478,   479,   482,   475,   476,
     111,     0,     0,    91,     0,   106,   107,   108,    73,   740,
       0,     0,   738,   734,     0,     0,     0,   434,     0,    66,
       0,    60,   222,   224,    13,   175,   180,   179,     0,   182,
       0,     0,     0,   144,   185,   188,     0,   428,     0,   471,
     469,   382,     0,     0,   414,     0,   382,     0,   378,     9,
       0,     0,     0,     0,     0,   504,     0,     0,   508,     0,
     177,     0,    76,    77,     0,   218,   216,   217,   210,   211,
     212,   204,     0,   199,   197,   447,   441,   169,   166,     0,
     168,   776,     0,     0,   762,     0,   773,   772,   771,   766,
     767,   682,   692,   768,     0,     0,     0,     0,   425,   112,
      92,   110,     0,   114,     0,     0,   741,   743,   745,   747,
       0,   739,     0,     0,     0,   729,     0,   727,     0,   435,
       0,    62,   181,   183,   192,   191,   186,   143,   429,     0,
     382,     0,   113,     0,   382,   488,   489,   493,   494,   500,
     502,     0,   677,     0,     0,     0,   213,   200,   170,   764,
     763,     0,     0,   229,     0,   225,    93,   750,   749,   744,
     748,   746,   735,   736,     0,   732,     0,   231,    68,     0,
     392,   386,   381,     0,   382,   373,     0,     0,     0,    86,
      82,    84,     0,    80,     0,   765,     0,     0,     0,     0,
     730,   728,     0,   400,   394,     0,   393,   395,   401,   398,
     388,     0,   387,   389,   399,   375,     0,   374,     0,   509,
       0,    85,    87,    81,     0,   226,   737,   733,   190,   385,
     396,   397,   384,   390,   391,   376,     0,    83,   230,     0,
       0,     0,   510,     0,     0,     0,     0,   511,     0,     0,
     512
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -944,  -944,   784,  -944,   775,   804,  -944,   806,  -944,   523,
     524,  -439,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -780,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,   527,  -293,  -944,  -251,  -944,   -55,  -697,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -105,  -944,
    -901,   807,   -87,  -311,  -944,  -944,  -944,  -944,   189,  -944,
    -944,   808,  -944,  -944,  -944,  -944,  -944,   141,  -449,  -577,
    -944,  -944,  -944,    30,  -944,  -944,  -133,    20,   -27,  -944,
    -944,  -944,   -39,  -944,  -944,   156,   -35,  -944,  -944,   -30,
    -943,  -944,   579,    47,  -944,  -944,    92,  -944,  -944,   528,
     519,  -944,  -451,  -836,   496,   188,  -500,   183,   184,  -944,
    -944,  -944,  -944,  -944,   739,  -944,  -944,  -944,  -944,  -944,
     740,  -944,  -944,  -104,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,   -31,  -140,  -944,  -944,  -137,  -223,  -944,  -492,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -792,  -944,
      21,  -944,   379,  -628,  -944,  -944,  -944,  -944,  -944,  -277,
    -269,  -940,  -790,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,   301,  -591,  -695,  -944,  -944,   -17,  -648,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,   619,   622,  -401,
     285,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,     6,
    -944,  -944,     4,  -380,  -353,    -9,  -944,   328,  -944,  -944,
     145,   135,   -48,   333,  -944,  -944,   147,  -944,  -655,  -944,
    -944,  -944,  -944,  -177,  -740,  -944,   -71,  -493,  -944,  -557,
    -944,  -944,  -944,  -944,  -868,  -944,  -944,  -944,  -944,   -36,
     155,  -944
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   950,   599,   227,   565,   228,
     229,  1154,   230,   463,  1269,  1270,  1234,   231,   742,   232,
     422,   233,   234,   235,   236,   237,   238,   920,   921,   995,
     924,   239,   240,   241,   242,   474,   404,   799,   800,   243,
     475,   244,   477,   245,   246,   247,   481,   482,   974,   679,
     248,   606,   655,   607,   613,   975,   976,   977,   656,   478,
     479,   847,   848,  1163,   480,   844,   845,  1029,  1030,  1031,
    1032,   249,   601,   602,   250,   909,   910,   251,   252,   253,
     254,   687,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   501,   502,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   528,   529,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   726,   295,   296,   297,
     997,   632,   633,   634,  1262,  1291,  1292,  1285,  1286,  1293,
    1287,   998,   999,   298,   299,  1000,   300,   301,   302,   303,
     304,   305,   306,   899,   680,   852,  1042,   853,   854,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   364,
     913,   317,   318,   319,   320,   321,   322,   323,   651,   652,
     324,  1019,  1020,   951,   393,   325,   326,   695,   881,   696,
     697,   698,   699,   700,   701,   702,   882,   883,   581,   582,
     583,   584,   585,  1254,  1255,   586,  1196,  1102,  1200,  1197,
     587,   588,   885,   896,  1063,   886,   887,   892,   888,  1179,
    1059,   871
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -76;
  const short int
  xquery_parser::yytable_[] =
  {
       365,   559,   369,   955,   815,   423,   425,   706,   707,   708,
     709,   694,   787,   432,   596,   600,   535,   793,   536,   897,
     898,   663,   944,  1074,  1096,   996,   855,   417,     4,   454,
     906,   792,   662,   570,   678,   683,   455,   684,   685,   593,
     686,   884,   688,  1067,   604,   434,   674,   411,   675,   418,
     689,   690,   674,   375,   376,   377,   574,  1138,   616,   796,
     636,   965,   419,   378,   675,  1250,   855,   855,   658,   659,
    1283,   860,   833,   390,   988,   591,   464,  1283,   558,  1260,
     464,   988,   665,  1049,   784,   426,   816,  1159,  1160,   609,
     375,   376,   377,   617,   464,   676,  1060,   791,   558,   430,
     378,   861,    64,   865,   464,   431,   379,   556,   464,  1100,
     384,   863,   371,    74,   464,   372,   986,   380,   566,   381,
     822,  1060,   382,   567,   674,   383,   643,   644,  1026,   646,
     647,   648,   649,  1055,   464,   654,   758,    88,   390,   504,
     557,   691,   941,   531,   692,  1194,  1028,   384,   385,   533,
     327,   817,   784,   666,   597,   629,   505,   931,  1104,   812,
     785,   671,   672,   732,  1261,  1101,  1056,   903,  1151,   524,
     991,   826,   992,   786,  1111,   568,   728,   991,   872,   992,
    1284,   987,   574,   630,   677,   985,   731,  1310,   753,   575,
     677,   618,   386,  1138,   797,   996,   834,   576,   598,   993,
     694,   694,   677,  1105,   968,   996,   993,   637,  1195,   730,
     577,  1251,   578,  1080,   677,  1236,   966,   435,   595,   782,
     677,   592,   579,   725,   734,   580,  1071,   798,   811,  1097,
     677,   864,   988,  1181,   569,  1203,   866,   483,   733,   388,
     823,   824,   778,  1289,   693,   781,   873,   530,  1061,  1062,
     532,   456,   387,   391,   456,   825,   392,   465,   674,   464,
     855,   375,   376,   377,   466,   759,   537,   467,   468,   418,
       4,   378,   418,  1061,  1062,   469,   388,   379,   805,   539,
     540,  1152,  1153,   545,   546,  1202,   548,  1050,   380,   807,
     381,   827,   828,   382,   760,   761,   383,   762,   763,   735,
     908,  1172,   589,   904,   590,   723,   829,   967,   723,   560,
     723,   329,  1081,   -74,   -74,   575,   464,  1092,   384,   385,
     988,   989,   621,   576,   561,   874,   875,   876,   991,   918,
     992,   912,  1204,   915,   772,   628,   577,  1206,   578,  1290,
     635,   996,  1267,   878,    64,  1272,   640,   820,   579,  1069,
     880,   580,  1279,   806,  1279,    74,  1272,   993,   843,   543,
     470,   464,   471,   386,   808,   858,   550,  1299,  1173,   553,
     988,   934,   935,  1319,   464,   938,   472,  1324,   905,    88,
    1068,  1289,   511,   691,  1278,   694,   692,   603,   738,   605,
     608,   512,  1093,   366,   919,   464,  1190,   694,   615,   990,
     663,   624,   473,   328,   980,   821,   981,  1205,   960,   464,
     464,   603,  1207,   -75,   448,   507,   991,  1268,   992,  1322,
    1273,   720,   721,   387,  1327,  1186,   464,  1280,  1330,  1281,
    1258,  1303,   370,   739,   464,   719,   653,   464,   657,   933,
     722,   508,  1039,   855,  1176,   993,   740,   388,  1320,    94,
    1177,   729,  1325,   396,   509,   464,   464,   737,  1178,   464,
     464,   988,   989,   464,   464,   106,   991,   773,   992,   464,
    1288,  1294,  1040,   389,   957,   958,   464,  1313,   961,   837,
     963,   804,   818,   398,   988,   989,   994,  1176,   510,  1187,
    1041,   397,   464,  1177,   941,   993,  1288,  1246,   819,  1189,
     983,  1178,  1294,  1219,   133,   927,   902,   777,  1223,   907,
     942,   399,  1004,  1005,  1006,   838,  1009,  1010,  1011,  1012,
    1013,  1014,   928,  1016,  1017,   401,   402,   917,   948,  1023,
     843,   982,  1052,   970,   971,  1188,  1193,   522,   810,  1307,
     990,  1209,   743,   744,   855,   988,   989,  1276,  1218,  1045,
     943,  1047,  1048,   675,  1171,   748,  1025,   991,   504,   992,
     108,  1174,  1175,   990,  1222,   893,   894,  1026,   403,  1109,
     406,   970,   971,   922,   972,   505,  1027,   405,   767,   872,
     991,   694,   992,   574,   929,  1028,   993,   895,   923,   420,
      94,   675,  1263,  1078,   855,   443,  1266,   400,   506,  1095,
     444,   930,   554,   795,   867,   562,   106,   768,   769,   993,
     770,   771,   973,    94,   923,   513,   555,   511,   437,   563,
     438,  1098,   813,  1241,   990,   511,   512,  1132,   514,   106,
     525,   526,   749,  1057,   512,  1106,  1296,   750,  1058,  1249,
     440,   991,   441,   992,  1249,   133,  1155,   873,  1113,   373,
    1137,   407,   374,  1116,  1117,   394,  1119,   756,   395,   842,
     757,  1123,  1002,   764,  1003,   856,   765,   408,   133,  1007,
     993,  1008,  1239,  1240,    94,   571,   572,   573,   461,   462,
    1301,   936,   937,   970,   971,  1156,  1157,   427,   925,   926,
     106,   428,   703,   704,   710,   711,   433,   712,   713,   900,
     900,  1247,  1248,   436,   439,   856,   856,   856,   856,   442,
    1149,  1221,   445,   446,   447,   451,   575,   459,   460,   464,
     449,   484,   843,   914,   576,   914,   874,   875,   876,   133,
    1211,   485,   503,   515,   516,  1167,   877,   577,  1168,   578,
    1170,  1275,   517,   527,   878,   518,   534,   486,   538,   579,
     879,   880,   580,   544,   547,   487,   488,   549,   489,   551,
     552,   558,   564,   390,   594,   490,   612,   614,   625,   491,
     610,   492,   611,   368,   372,   374,   493,   392,   410,   448,
     631,   638,  1237,   639,   642,   641,   650,   645,   462,   667,
     668,   673,   494,   669,   670,   714,   365,   715,   365,   727,
     741,   716,   717,   745,   746,   747,   754,  1212,   751,  1213,
     752,   766,   755,   774,   775,  1217,   495,   496,   497,   498,
     499,   500,   779,   780,  1084,   788,   783,   789,   790,  1225,
    1226,  1227,  1228,  1229,   794,  1230,  1094,  1034,   801,   802,
     483,   803,   831,   830,   836,   841,   839,   840,  1043,   835,
    1044,   832,   846,   849,   857,   859,   862,   870,  1238,   891,
    1108,   889,   890,    92,   908,   911,   674,   932,   940,   939,
     946,   947,   945,   949,  1243,   952,  1245,   954,   956,   962,
     953,   964,   969,   959,   984,  1001,  1015,  1022,  1018,  1033,
     979,  1035,  1128,  1053,  1021,  1037,  1046,  1257,  1038,   856,
    1051,  1073,  1076,  1091,  1077,  1054,  1135,  1075,  1103,  1090,
    1064,  1110,  1087,  1085,  1086,  1088,  1089,  1118,  1121,  1099,
    1317,  1126,  1271,  1120,  1122,  1131,  1134,  1144,  1147,  1140,
    1141,  1142,  1026,  1114,  1129,  1162,  1130,  1146,  1143,  1183,
    1169,  1139,  1165,  1198,   918,  1192,  1185,   603,  1166,  1199,
    1210,  1208,  1232,   608,  1233,  1235,  1242,  1252,  1259,  1253,
     941,  1271,  1282,  1298,  1124,   923,  1305,  1277,  1304,  1265,
    1306,  1295,  1300,  1309,  1321,  1297,  1312,  1315,  1326,  1302,
     452,  1329,   660,   661,  1274,  1136,   450,  1191,   664,   978,
    1036,  1216,  1115,  1318,  1125,  1150,  1164,  1024,  1161,   626,
    1158,  1082,   705,  1112,   682,   521,   653,  1231,  1133,   453,
     523,   814,   681,   657,   457,  1314,   458,  1311,   901,   916,
     868,  1145,  1065,  1148,  1072,  1182,   869,   619,  1070,  1256,
     620,  1201,  1180,  1066,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   856,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1214,  1215,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1220,     0,     0,     0,     0,  1224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1244,     0,     0,
       0,     0,     0,   856,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   856,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1308,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1316,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,  1323,     0,     5,     6,     7,  1328,     8,     9,
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
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     7,     0,     8,     9,    10,    11,    12,
      13,    14,   338,    16,    17,     0,    18,    19,    20,   341,
      22,    23,   343,    25,    26,    27,     0,    28,    29,    30,
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
     112,   424,   113,   114,   115,     0,   116,   117,   118,     0,
     119,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,   131,   132,   133,     0,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
     172,   173,     0,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   421,   196,   197,   198,   199,   200,
     201,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     7,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
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
     195,   196,   197,   198,   199,   200,   201,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     0,     8,     9,    10,
      11,    12,    13,    14,   338,    16,    17,     0,    18,    19,
      20,   341,    22,    23,   343,    25,    26,    27,     0,    28,
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
     627,     0,   112,     0,   113,   114,   115,     0,   116,   117,
     118,     0,   119,     0,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,   131,   132,   133,
       0,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,     0,   172,   173,     0,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   421,   196,   197,   198,
     199,   200,   201,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     5,
       6,     7,     0,     8,     9,    10,    11,    12,    13,    14,
     338,    16,    17,     0,    18,    19,    20,   341,    22,    23,
     343,    25,    26,    27,     0,    28,    29,    30,    31,    32,
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
       0,     0,   109,   110,   111,     0,   718,     0,   112,     0,
     113,   114,   115,     0,   116,   117,   118,     0,   119,     0,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   131,   132,   133,     0,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,     0,   172,   173,
       0,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   421,   196,   197,   198,   199,   200,   201,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     8,
       9,    10,    11,    12,    13,    14,   338,    16,    17,     0,
      18,    19,    20,   341,    22,    23,   343,    25,    26,    27,
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
     111,     0,     0,     0,   112,   724,   113,   114,   115,     0,
     116,   117,   118,     0,   119,     0,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,   131,
     132,   133,     0,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,   172,   173,     0,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   421,   196,
     197,   198,   199,   200,   201,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     7,     0,     8,     9,    10,    11,    12,
      13,    14,   338,    16,    17,     0,    18,    19,    20,   341,
      22,    23,   343,    25,    26,    27,     0,    28,    29,    30,
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
     107,   108,     0,     0,   109,   110,   111,     0,   736,     0,
     112,     0,   113,   114,   115,     0,   116,   117,   118,     0,
     119,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,   131,   132,   133,     0,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
     172,   173,     0,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   421,   196,   197,   198,   199,   200,
     201,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     7,
       0,     8,     9,    10,    11,    12,    13,    14,   338,    16,
      17,     0,    18,    19,    20,   341,    22,    23,   343,    25,
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
     109,   110,   111,     0,   776,     0,   112,     0,   113,   114,
     115,     0,   116,   117,   118,     0,   119,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,   131,   132,   133,     0,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   172,   173,     0,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     421,   196,   197,   198,   199,   200,   201,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     0,     8,     9,    10,
      11,    12,    13,    14,   338,    16,    17,     0,    18,    19,
      20,   341,    22,    23,   343,    25,    26,    27,     0,    28,
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
     809,     0,   112,     0,   113,   114,   115,     0,   116,   117,
     118,     0,   119,     0,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,   131,   132,   133,
       0,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,     0,   172,   173,     0,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   421,   196,   197,   198,
     199,   200,   201,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     5,
       6,     7,     0,     8,     9,    10,    11,    12,    13,    14,
     338,    16,    17,     0,    18,    19,    20,   341,    22,    23,
     343,    25,    26,    27,     0,    28,    29,    30,    31,    32,
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
       0,     0,   109,   110,   111,     0,  1083,     0,   112,     0,
     113,   114,   115,     0,   116,   117,   118,     0,   119,     0,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   131,   132,   133,     0,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,     0,   172,   173,
       0,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   421,   196,   197,   198,   199,   200,   201,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     8,
       9,    10,    11,    12,    13,    14,   338,    16,    17,     0,
      18,    19,    20,   341,    22,    23,   343,    25,    26,    27,
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
     111,     0,  1107,     0,   112,     0,   113,   114,   115,     0,
     116,   117,   118,     0,   119,     0,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,   131,
     132,   133,     0,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,   172,   173,     0,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   421,   196,
     197,   198,   199,   200,   201,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     7,     0,     8,     9,    10,    11,    12,
      13,    14,   338,    16,    17,     0,    18,    19,    20,   341,
      22,    23,   343,    25,    26,    27,     0,    28,    29,    30,
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
     107,   108,     0,     0,   109,   110,   111,     0,  1127,     0,
     112,     0,   113,   114,   115,     0,   116,   117,   118,     0,
     119,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,   131,   132,   133,     0,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
     172,   173,     0,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   421,   196,   197,   198,   199,   200,
     201,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     7,
       0,     8,     9,    10,    11,    12,    13,    14,   338,    16,
      17,     0,    18,    19,    20,   341,    22,    23,   343,    25,
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
       0,   131,   132,   133,     0,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   172,   173,     0,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     421,   196,   197,   198,   199,   200,   201,     1,     0,     0,
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
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,   330,
     331,     7,     0,     0,     9,   333,    11,    12,    13,    14,
     338,    16,    17,     0,   339,    19,    20,   341,   342,    23,
     343,    25,    26,    27,     0,   344,   345,    30,     0,   346,
     347,    34,    35,    36,    37,    38,    39,    40,    41,   348,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,     0,    62,    63,     0,     0,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,    74,     0,
      75,    76,    77,    78,     0,    79,     0,     0,     0,   352,
      81,    82,    83,    84,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     0,    93,
      94,   519,    96,    97,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,   520,   108,
       0,     0,   109,   110,   111,     0,     0,     0,   112,     0,
     113,   114,   115,     0,   116,   117,   118,     0,   119,     0,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   131,   132,   133,     0,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   356,   144,   358,
     146,   359,   360,   149,   150,   151,   152,   153,   154,   361,
     156,     0,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,     0,   172,   173,
       0,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   362,   363,   197,   198,   199,   200,   201,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,   330,   331,     7,     0,     0,
       9,   333,    11,    12,    13,    14,   338,    16,    17,     0,
     339,    19,    20,   341,   342,    23,   343,    25,    26,    27,
       0,   344,   345,    30,     0,   346,   347,    34,    35,    36,
      37,    38,    39,    40,    41,   348,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,    62,    63,
       0,     0,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,    74,     0,    75,    76,    77,    78,
       0,    79,     0,     0,     0,   352,    81,    82,    83,    84,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,     0,     0,   109,   110,
     111,     0,     0,     0,   112,     0,   113,   114,   115,     0,
     116,   117,   118,     0,   119,     0,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,   131,
     132,   133,     0,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   356,   144,   358,   146,   359,   360,   149,
     150,   151,   152,   153,   154,   361,   156,     0,     0,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,   172,   173,     0,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   362,   363,
     197,   198,   199,   200,   201,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,   330,   331,     7,     0,     0,   332,   333,    11,    12,
      13,    14,   338,    16,    17,     0,   339,    19,    20,   341,
     342,    23,   343,    25,    26,    27,     0,   344,   345,    30,
       0,   346,   347,    34,    35,    36,    37,    38,    39,    40,
      41,   348,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,     0,     0,    62,    63,     0,     0,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
      74,     0,    75,    76,    77,    78,     0,    79,     0,     0,
       0,   352,    81,    82,    83,    84,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    90,    91,     0,     0,
       0,    93,    94,     0,    96,    97,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,     0,     0,   109,   110,   111,     0,     0,     0,
     112,     0,   113,   114,   115,     0,     0,     0,   118,     0,
     119,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,   131,   132,   133,     0,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   356,
     144,   358,   146,   359,   360,   149,   150,   151,   152,   153,
     154,   361,   156,     0,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
     172,   173,     0,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   362,   363,   197,   198,   199,   200,
     201,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     0,     0,   330,   331,     7,
       0,     0,   332,   333,   412,   335,   413,   414,   338,    16,
      17,     0,   339,   415,    20,   341,   342,    23,   343,    25,
      26,    27,     0,   344,   345,    30,     0,   346,   347,    34,
      35,    36,    37,    38,    39,    40,    41,   348,    43,    44,
      45,    46,    47,    48,    49,     0,     0,    52,     0,    53,
      54,    55,   416,     0,     0,    59,    60,    61,     0,     0,
       0,    63,     0,     0,     0,     0,    65,    66,     0,     0,
      69,    70,     0,     0,     0,     0,     0,     0,    75,    76,
      77,    78,     0,    79,     0,     0,     0,   352,    81,    82,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
       0,    89,    90,    91,     0,     0,     0,     0,     0,     0,
      96,    97,     0,     0,     0,     0,    98,    99,   100,   354,
     102,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,     0,     0,     0,   112,     0,   113,   114,
       0,     0,     0,     0,   118,     0,   119,     0,   120,   121,
     122,   123,   355,   125,   126,   127,   128,   129,   130,     0,
       0,   131,   132,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   356,   144,   358,   146,   359,
     360,   149,   150,   151,   152,   153,   154,   361,   156,     0,
       0,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   172,   173,     0,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     362,   363,   197,   198,   199,   200,   201,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     0,     0,     0,
       0,     0,     0,   330,   331,     7,     0,     0,   332,   333,
     334,   335,   336,   337,   338,    16,    17,     0,   339,   340,
      20,   341,   342,    23,   343,    25,    26,    27,     0,   344,
     345,    30,     0,   346,   347,    34,    35,    36,    37,    38,
      39,    40,    41,   348,    43,   349,   350,    46,    47,    48,
      49,     0,     0,    52,     0,    53,    54,    55,   351,     0,
       0,    59,    60,    61,     0,     0,     0,    63,     0,     0,
       0,     0,    65,    66,     0,     0,    69,    70,     0,     0,
       0,     0,     0,     0,    75,    76,    77,    78,     0,    79,
       0,     0,     0,   352,    81,    82,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,     0,    89,    90,    91,
       0,     0,     0,     0,     0,     0,    96,    97,     0,     0,
       0,     0,    98,    99,   100,   354,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,     0,
       0,     0,   112,     0,   113,     0,     0,     0,     0,     0,
     118,     0,   119,     0,   120,   121,   122,   123,   355,   125,
     126,   127,   128,   129,   130,     0,     0,   131,   132,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   356,   357,   358,   146,   359,   360,   149,   150,   151,
     152,   153,   154,   361,   156,     0,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,     0,   172,   173,     0,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   362,   363,   197,   198,
     199,   200,   201,   429,     0,     3,     0,     0,     0,     0,
       0,     0,     0,   330,   331,     7,     0,     0,   332,   333,
     334,   335,   336,   337,   338,    16,    17,     0,   339,   340,
      20,   341,   342,    23,   343,    25,    26,    27,     0,   344,
     345,    30,     0,   346,   347,    34,    35,    36,    37,    38,
      39,    40,    41,   348,    43,   349,   350,    46,    47,    48,
      49,     0,     0,    52,     0,    53,    54,    55,   351,     0,
       0,    59,    60,    61,     0,     0,     0,    63,     0,     0,
       0,     0,    65,    66,     0,     0,    69,    70,     0,     0,
       0,     0,     0,     0,    75,    76,    77,    78,     0,    79,
       0,     0,     0,   352,    81,    82,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,     0,    89,    90,    91,
       0,     0,     0,     0,     0,     0,    96,    97,     0,     0,
       0,     0,    98,    99,   100,   354,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,     0,
       0,     0,   112,     0,   113,     0,     0,     0,     0,     0,
       0,     0,   119,     0,   120,   121,   122,   123,   355,   125,
     126,   127,   128,   129,   130,     0,     0,   131,   132,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   356,   357,   358,   146,   359,   360,   149,   150,   151,
     152,   153,   154,   361,   156,     0,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,     0,   172,   173,     0,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   362,   363,   197,   198,
     199,   200,   201,     3,     0,     0,     0,     0,     0,     0,
       0,   330,   331,     7,     0,     0,   332,   333,   334,   335,
     336,   337,   338,    16,    17,     0,   339,   340,    20,   341,
     342,    23,   343,    25,    26,    27,     0,   344,   345,    30,
       0,   346,   347,    34,    35,    36,    37,    38,    39,    40,
      41,   348,    43,   349,   350,    46,    47,    48,    49,     0,
       0,    52,     0,    53,    54,    55,   351,     0,     0,    59,
      60,    61,     0,     0,     0,    63,     0,     0,     0,     0,
      65,    66,     0,     0,    69,    70,     0,     0,     0,     0,
       0,     0,    75,    76,    77,    78,     0,    79,     0,     0,
       0,   352,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,     0,    89,    90,    91,   367,     0,
       0,   368,     0,     0,    96,    97,     0,     0,     0,     0,
      98,    99,   100,   354,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
     112,     0,   113,     0,     0,     0,     0,     0,     0,     0,
     119,     0,   120,   121,   122,   123,   355,   125,   126,   127,
     128,   129,   130,     0,     0,   131,   132,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   356,
     357,   358,   146,   359,   360,   149,   150,   151,   152,   153,
     154,   361,   156,     0,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
     172,   173,     0,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   362,   363,   197,   198,   199,   200,
     201,     3,     0,     0,     0,     0,     0,     0,     0,   330,
     331,     7,     0,     0,   332,   333,   334,   335,   336,   337,
     338,    16,    17,     0,   339,   340,    20,   341,   342,    23,
     343,    25,    26,    27,     0,   344,   345,    30,     0,   346,
     347,    34,    35,    36,    37,    38,    39,    40,    41,   348,
      43,   349,   350,    46,    47,    48,    49,     0,     0,    52,
       0,    53,    54,    55,   351,     0,     0,    59,    60,    61,
       0,     0,     0,    63,     0,     0,     0,     0,    65,    66,
       0,     0,    69,    70,     0,     0,     0,     0,     0,     0,
      75,    76,    77,    78,     0,    79,     0,     0,     0,   352,
      81,    82,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,     0,    89,    90,    91,   409,     0,     0,   410,
       0,     0,    96,    97,     0,     0,     0,     0,    98,    99,
     100,   354,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,     0,     0,     0,   112,     0,
     113,     0,     0,     0,     0,     0,     0,     0,   119,     0,
     120,   121,   122,   123,   355,   125,   126,   127,   128,   129,
     130,     0,     0,   131,   132,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   356,   357,   358,
     146,   359,   360,   149,   150,   151,   152,   153,   154,   361,
     156,     0,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,     0,   172,   173,
       0,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   362,   363,   197,   198,   199,   200,   201,     3,
       0,     0,     0,     0,     0,     0,     0,   330,   331,     7,
       0,     0,   332,   333,   334,   335,   336,   337,   338,    16,
      17,     0,   339,   340,    20,   341,   342,    23,   343,    25,
      26,    27,     0,   344,   345,    30,     0,   346,   347,    34,
      35,    36,    37,    38,    39,    40,    41,   348,    43,   349,
     350,    46,    47,    48,    49,     0,     0,    52,     0,    53,
      54,    55,   351,     0,     0,    59,    60,    61,     0,     0,
       0,    63,     0,     0,     0,     0,    65,    66,     0,     0,
      69,    70,     0,     0,     0,     0,     0,     0,    75,    76,
      77,    78,     0,    79,     0,     0,     0,   352,    81,    82,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
       0,    89,    90,    91,     0,     0,     0,     0,     0,     0,
      96,    97,     0,     0,     0,     0,    98,    99,   100,   354,
     102,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,     0,     0,     0,   112,   541,   113,     0,
       0,     0,     0,     0,   542,     0,   119,     0,   120,   121,
     122,   123,   355,   125,   126,   127,   128,   129,   130,     0,
       0,   131,   132,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   356,   357,   358,   146,   359,
     360,   149,   150,   151,   152,   153,   154,   361,   156,     0,
       0,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   172,   173,     0,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     362,   363,   197,   198,   199,   200,   201,     3,     0,     0,
       0,     0,     0,     0,     0,   330,   331,     7,     0,     0,
     332,   333,   334,   335,   336,   337,   338,    16,    17,     0,
     339,   340,    20,   341,   342,    23,   343,    25,    26,    27,
       0,   344,   345,    30,     0,   346,   347,    34,    35,    36,
      37,    38,    39,    40,    41,   348,    43,   349,   350,    46,
      47,    48,    49,     0,     0,    52,     0,    53,    54,    55,
     351,     0,     0,    59,    60,    61,     0,     0,     0,    63,
       0,     0,     0,     0,    65,    66,     0,     0,    69,    70,
       0,     0,     0,     0,     0,     0,    75,    76,    77,    78,
       0,    79,     0,     0,     0,   352,    81,    82,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,     0,    89,
      90,    91,     0,     0,     0,     0,     0,     0,    96,    97,
       0,     0,     0,     0,    98,    99,   100,   354,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     0,     0,     0,   112,   622,   113,     0,     0,     0,
       0,     0,   623,     0,   119,     0,   120,   121,   122,   123,
     355,   125,   126,   127,   128,   129,   130,     0,     0,   131,
     132,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   356,   357,   358,   146,   359,   360,   149,
     150,   151,   152,   153,   154,   361,   156,     0,     0,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,   172,   173,     0,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   362,   363,
     197,   198,   199,   200,   201,     3,     0,     0,     0,     0,
       0,     0,     0,   330,   331,     7,     0,     0,   332,   333,
     412,   335,   413,   414,   338,    16,    17,     0,   339,   415,
      20,   341,   342,    23,   343,    25,    26,    27,     0,   344,
     345,    30,     0,   346,   347,    34,    35,    36,    37,    38,
      39,    40,    41,   348,    43,    44,    45,    46,    47,    48,
      49,     0,     0,    52,     0,    53,    54,    55,   416,     0,
       0,    59,    60,    61,     0,     0,     0,    63,     0,     0,
       0,     0,    65,    66,     0,     0,    69,    70,  1079,     0,
       0,     0,     0,     0,    75,    76,    77,    78,     0,    79,
       0,     0,     0,   352,    81,    82,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,     0,    89,    90,   850,
       0,     0,     0,     0,     0,     0,    96,    97,     0,     0,
       0,     0,    98,    99,   100,   354,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,     0,
       0,     0,   112,     0,   113,   114,     0,     0,     0,     0,
       0,     0,   119,     0,   120,   121,   122,   123,   355,   125,
     126,   127,   128,   129,   130,     0,     0,   851,   132,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   356,   144,   358,   146,   359,   360,   149,   150,   151,
     152,   153,   154,   361,   156,     0,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,     0,   172,   173,     0,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   362,   363,   197,   198,
     199,   200,   201,     3,     0,     0,     0,     0,     0,     0,
       0,   330,   331,     7,     0,     0,   332,   333,   334,   335,
     336,   337,   338,    16,    17,     0,   339,   340,    20,   341,
     342,    23,   343,    25,    26,    27,     0,   344,   345,    30,
       0,   346,   347,    34,    35,    36,    37,    38,    39,    40,
      41,   348,    43,   349,   350,    46,    47,    48,    49,     0,
       0,    52,     0,    53,    54,    55,   351,     0,     0,    59,
      60,    61,     0,     0,     0,    63,     0,     0,     0,     0,
      65,    66,     0,     0,    69,    70,     0,     0,     0,     0,
       0,     0,    75,    76,    77,    78,     0,    79,     0,     0,
       0,   352,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,     0,    89,    90,    91,   353,     0,
       0,     0,     0,     0,    96,    97,     0,     0,     0,     0,
      98,    99,   100,   354,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
     112,     0,   113,     0,     0,     0,     0,     0,     0,     0,
     119,     0,   120,   121,   122,   123,   355,   125,   126,   127,
     128,   129,   130,     0,     0,   131,   132,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   356,
     357,   358,   146,   359,   360,   149,   150,   151,   152,   153,
     154,   361,   156,     0,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
     172,   173,     0,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   362,   363,   197,   198,   199,   200,
     201,     3,     0,     0,     0,     0,     0,     0,     0,   330,
     331,     7,     0,     0,   332,   333,   412,   335,   413,   414,
     338,    16,    17,     0,   339,   415,    20,   341,   342,    23,
     343,    25,    26,    27,     0,   344,   345,    30,     0,   346,
     347,    34,    35,    36,    37,    38,    39,    40,    41,   348,
      43,    44,    45,    46,    47,    48,    49,     0,     0,    52,
       0,    53,    54,    55,   416,     0,     0,    59,    60,    61,
       0,     0,     0,    63,     0,     0,     0,     0,    65,    66,
       0,     0,    69,    70,     0,     0,     0,     0,     0,     0,
      75,    76,    77,    78,     0,    79,     0,     0,     0,   352,
      81,    82,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,     0,    89,    90,   850,     0,     0,     0,     0,
       0,     0,    96,    97,     0,     0,     0,     0,    98,    99,
     100,   354,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,     0,     0,     0,   112,     0,
     113,   114,     0,     0,     0,     0,     0,     0,   119,     0,
     120,   121,   122,   123,   355,   125,   126,   127,   128,   129,
     130,     0,     0,   851,   132,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   356,   144,   358,
     146,   359,   360,   149,   150,   151,   152,   153,   154,   361,
     156,     0,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,     0,   172,   173,
       0,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   362,   363,   197,   198,   199,   200,   201,     3,
       0,     0,     0,     0,     0,     0,     0,   330,   331,     7,
       0,     0,   332,   333,   334,   335,   336,   337,   338,    16,
      17,     0,   339,   340,    20,   341,   342,    23,   343,    25,
      26,    27,     0,   344,   345,    30,     0,   346,   347,    34,
      35,    36,    37,    38,    39,    40,    41,   348,    43,   349,
     350,    46,    47,    48,    49,     0,     0,    52,     0,    53,
      54,    55,   351,     0,     0,    59,    60,    61,     0,     0,
       0,    63,     0,     0,     0,     0,    65,    66,     0,     0,
      69,    70,     0,     0,     0,     0,     0,     0,    75,    76,
      77,    78,     0,    79,     0,     0,     0,   352,    81,    82,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
       0,    89,    90,    91,     0,     0,     0,     0,     0,     0,
      96,    97,     0,     0,     0,     0,    98,    99,   100,   354,
     102,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,     0,     0,     0,   112,     0,   113,     0,
       0,     0,     0,     0,     0,     0,   119,     0,   120,   121,
     122,   123,   355,   125,   126,   127,   128,   129,   130,     0,
       0,   131,   132,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   356,   357,   358,   146,   359,
     360,   149,   150,   151,   152,   153,   154,   361,   156,     0,
       0,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   172,   173,     0,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     362,   363,   197,   198,   199,   200,   201
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,   381,    11,   783,   632,    92,    93,   507,   508,   509,
     510,   503,   603,   117,   394,   395,   327,   608,   329,   714,
     715,   460,   762,   891,   925,   817,   674,    58,    20,    37,
     727,   608,    37,   386,   483,   486,    44,   488,   489,   392,
     491,   696,   493,   879,   397,    21,    78,    56,    80,    58,
     501,   502,    78,    38,    39,    40,    84,   997,    33,    62,
       7,   123,    71,    48,    80,    20,   714,   715,   448,   449,
       4,   127,    91,    18,     8,    20,    91,     4,    20,    77,
      91,     8,   462,   127,    91,    94,   111,  1030,  1031,   400,
      38,    39,    40,    68,    91,   127,    80,   123,    20,   108,
      48,   678,    94,   680,    91,   114,    54,   148,    91,    80,
      95,   127,   133,   105,    91,   136,   111,    65,    33,    67,
      78,    80,    70,    38,    78,    73,   437,   438,    90,   440,
     441,   442,   443,   197,    91,   446,    96,   129,    18,   138,
     181,   133,    80,   280,   136,   117,   108,    95,    96,   286,
     217,   176,    91,   464,    96,   170,   155,   748,    96,   170,
     167,   472,   473,    91,   162,   136,   230,   164,   150,   273,
     104,    78,   106,   127,   954,    90,   163,   104,    80,   106,
     114,   176,    84,   166,   246,   813,   163,   114,   568,   217,
     246,   166,   140,  1133,   197,   987,   215,   225,   140,   133,
     692,   693,   246,   943,   795,   997,   133,   154,   180,   166,
     238,   166,   240,   908,   246,  1158,   793,   193,   140,   599,
     246,   166,   250,   534,    91,   253,   881,   230,   167,   926,
     246,   680,     8,  1069,   149,  1103,   687,   246,   166,   224,
     198,   199,   595,    19,   236,   598,   148,   278,   232,   233,
     281,   259,   200,   133,   259,   213,   136,    46,    78,    91,
     908,    38,    39,    40,    53,   225,   353,    56,    57,   278,
      20,    48,   281,   232,   233,    64,   224,    54,    91,   366,
     367,   263,   264,   370,   371,   244,   373,   864,    65,    91,
      67,   198,   199,    70,   254,   255,    73,   257,   258,   166,
      84,    43,   389,    91,   391,   528,   213,   127,   531,   146,
     533,   136,    96,   261,   262,   217,    91,    91,    95,    96,
       8,     9,   409,   225,   161,   227,   228,   229,   104,   101,
     106,   732,    91,   734,   166,   422,   238,    91,   240,   115,
     427,  1133,    91,   245,    94,    91,   433,   112,   250,   251,
     252,   253,    91,   166,    91,   105,    91,   133,   669,   368,
     149,    91,   151,   140,   166,   676,   375,  1268,   110,   378,
       8,   751,   752,    91,    91,   755,   165,    91,   166,   129,
     880,    19,   180,   133,  1252,   877,   136,   396,   163,   398,
     399,   189,   166,   136,   166,    91,  1091,   889,   407,    87,
     839,   410,   191,    28,   805,   170,   807,   166,   788,    91,
      91,   420,   166,   261,   262,   100,   104,   166,   106,  1320,
     166,   525,   526,   200,  1325,   101,    91,   166,  1329,   166,
    1210,   166,   133,   163,    91,   522,   445,    91,   447,   750,
     527,   126,   125,  1091,   242,   133,   163,   224,   166,   137,
     248,   538,   166,   101,   139,    91,    91,   544,   256,    91,
      91,     8,     9,    91,    91,   153,   104,   163,   106,    91,
    1260,  1261,   155,   136,   785,   786,    91,   115,   789,    55,
     791,   163,   163,   101,     8,     9,   174,   242,   173,   165,
     173,   140,    91,   248,    80,   133,  1286,  1192,   163,  1090,
     811,   256,  1292,  1131,   192,   128,   163,   594,  1136,   163,
      96,   101,   823,   824,   825,    91,   827,   828,   829,   830,
     831,   832,   145,   834,   835,    58,    59,   163,   163,   840,
     841,   163,   163,    60,    61,   163,   163,   133,   625,  1279,
      87,   163,   551,   552,  1192,     8,     9,  1242,   163,   860,
     136,   862,   863,    80,  1054,   564,    79,   104,   138,   106,
     156,  1061,  1062,    87,   163,   221,   222,    90,   101,   949,
      28,    60,    61,   118,    63,   155,    99,    56,   225,    80,
     104,  1073,   106,    84,   128,   108,   133,   243,   133,   101,
     137,    80,  1220,   904,  1242,   205,  1224,   133,   178,   118,
     210,   145,   161,   612,   691,   161,   153,   254,   255,   133,
     257,   258,   101,   137,   133,   117,   175,   180,   205,   175,
     207,   932,   631,   178,    87,   180,   189,   174,   130,   153,
     171,   172,   118,   242,   189,   946,  1264,   123,   247,  1196,
     205,   104,   207,   106,  1201,   192,  1026,   148,   959,   133,
     174,   136,   136,   964,   965,    47,   967,   223,    50,   668,
     226,   972,   212,   223,   214,   674,   226,   136,   192,   212,
     133,   214,  1172,  1173,   137,   201,   202,   203,   261,   262,
    1271,   109,   110,    60,    61,   109,   110,   133,   743,   744,
     153,    14,   504,   505,   511,   512,   133,   513,   514,   716,
     717,  1194,  1195,   195,   136,   714,   715,   716,   717,   205,
    1021,   174,   101,   133,   101,     0,   217,   170,   170,    91,
     262,   147,  1033,   732,   225,   734,   227,   228,   229,   192,
    1110,    76,   235,    71,   179,  1046,   237,   238,  1049,   240,
    1051,  1241,    85,   134,   245,    86,   136,   113,   133,   250,
     251,   252,   253,   133,   166,   121,   122,   166,   124,    38,
      38,    20,   101,    18,   133,   131,   101,   101,   133,   135,
     252,   137,   252,   136,   136,   136,   142,   136,   136,   262,
      25,    15,  1162,   166,    20,   193,   211,   166,   262,   149,
     101,    91,   158,   150,   150,   211,   805,    78,   807,   166,
     136,    78,    78,    20,    91,    91,   108,  1118,   140,  1120,
     140,    20,   113,   166,   166,  1126,   182,   183,   184,   185,
     186,   187,    80,    33,   911,   113,    80,   123,    91,  1140,
    1141,  1142,  1143,  1144,   163,  1146,   923,   846,   166,   166,
     849,   166,   217,    78,   163,   150,   170,   265,   857,   123,
     859,   205,   101,   101,   101,   101,   127,   253,  1169,   241,
     947,   234,   236,   133,    84,   133,    78,   123,   256,   255,
     177,   133,   256,   113,  1185,   140,  1187,    80,   101,   101,
     113,   123,   230,   127,    25,    20,   101,   101,   219,    91,
     133,    91,   979,   166,   133,   136,   127,  1208,   136,   908,
     127,   127,    49,    78,   125,   231,   993,   256,    20,   918,
     231,    91,   125,   166,   166,   166,   166,   123,   101,   256,
    1300,    63,  1233,   127,   101,   113,     6,   217,   136,   213,
     213,   213,    90,   170,   166,    90,   166,   165,   213,   249,
     127,   170,   166,    20,   101,    78,   165,   956,   166,    20,
      80,   107,   163,   962,   136,   150,    78,    20,    61,   239,
      80,  1272,   101,   101,   973,   133,  1277,   165,   165,   176,
     239,   176,    90,    77,   101,   176,   162,   176,   101,  1272,
     205,   166,   459,   459,  1235,   994,   202,  1092,   461,   800,
     849,  1124,   962,  1304,   974,  1022,  1035,   841,  1033,   420,
    1030,   909,   506,   956,   485,   266,  1015,  1147,   987,   205,
     270,   632,   484,  1022,   208,  1292,   209,  1286,   717,   734,
     692,  1015,   877,  1019,   889,  1073,   693,   408,   881,  1206,
     408,  1102,  1068,   878,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1079,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1091,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1121,  1122,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1132,    -1,    -1,    -1,    -1,  1137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1186,    -1,    -1,
      -1,    -1,    -1,  1192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1282,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1298,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,  1321,    -1,    26,    27,    28,  1326,    30,    31,
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
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,    10,    -1,    -1,    -1,    -1,
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
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
     259,   260,   261,   262,   263,   264,   265,    10,    -1,    -1,
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
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     257,   258,   259,   260,   261,   262,   263,   264,   265,    10,
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
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,    10,    -1,    -1,    -1,    -1,
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
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
     259,   260,   261,   262,   263,   264,   265,    10,    -1,    -1,
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
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     257,   258,   259,   260,   261,   262,   263,   264,   265,    10,
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
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,    10,    -1,    -1,    -1,    -1,
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
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
     159,   160,   161,    -1,    -1,    -1,   165,    -1,   167,   168,
     169,    -1,   171,   172,   173,    -1,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,   190,   191,   192,    -1,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,   235,   236,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,    10,    -1,    -1,
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
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    -1,    89,    90,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,   105,    -1,
     107,   108,   109,   110,    -1,   112,    -1,    -1,    -1,   116,
     117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
      -1,    -1,   159,   160,   161,    -1,    -1,    -1,   165,    -1,
     167,   168,   169,    -1,   171,   172,   173,    -1,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,   190,   191,   192,    -1,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,   235,   236,
      -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    -1,    89,    90,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,   105,    -1,   107,   108,   109,   110,
      -1,   112,    -1,    -1,    -1,   116,   117,   118,   119,   120,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,    -1,    -1,   159,   160,
     161,    -1,    -1,    -1,   165,    -1,   167,   168,   169,    -1,
     171,   172,   173,    -1,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,   190,
     191,   192,    -1,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,   235,   236,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,    10,    -1,    -1,    -1,    -1,
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
      -1,   136,   137,    -1,   139,   140,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,    -1,    -1,    -1,
     165,    -1,   167,   168,   169,    -1,    -1,    -1,   173,    -1,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,   190,   191,   192,    -1,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
     235,   236,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,    -1,    -1,    -1,   173,    -1,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,   190,   191,    -1,    -1,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,   235,   236,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
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
     173,    -1,   175,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,   190,   191,    -1,
      -1,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,   235,   236,    -1,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,    16,    -1,    18,    -1,    -1,    -1,    -1,
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
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,    18,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   126,   127,   128,    -1,   130,   131,   132,   133,    -1,
      -1,   136,    -1,    -1,   139,   140,    -1,    -1,    -1,    -1,
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
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
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
     127,   128,    -1,   130,   131,   132,   133,    -1,    -1,   136,
      -1,    -1,   139,   140,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,   165,    -1,
     167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,   235,   236,
      -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,    18,
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
     259,   260,   261,   262,   263,   264,   265,    18,    -1,    -1,
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
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    76,    -1,    78,    79,    80,    81,    -1,
      -1,    84,    85,    86,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    -1,    95,    96,    -1,    -1,    99,   100,   101,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,   110,    -1,   112,
      -1,    -1,    -1,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,    -1,   130,   131,   132,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,
      -1,    -1,   165,    -1,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,   175,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,   190,   191,    -1,
      -1,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,   235,   236,    -1,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,    18,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   126,   127,   128,    -1,   130,   131,   132,   133,    -1,
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
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
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
     257,   258,   259,   260,   261,   262,   263,   264,   265,    18,
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
      -1,    -1,   161,    -1,    -1,    -1,   165,    -1,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,   190,   191,    -1,    -1,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,   235,   236,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265
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
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   308,   310,   311,
     313,   318,   320,   322,   323,   324,   325,   326,   327,   332,
     333,   334,   335,   340,   342,   344,   345,   346,   351,   372,
     375,   378,   379,   380,   381,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   428,   429,   430,   444,   445,
     447,   448,   449,   450,   451,   452,   453,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   472,   473,   474,
     475,   476,   477,   478,   481,   486,   487,   217,    28,   136,
      26,    27,    31,    32,    33,    34,    35,    36,    37,    41,
      42,    44,    45,    47,    52,    53,    56,    57,    66,    68,
      69,    81,   116,   133,   148,   181,   204,   205,   206,   208,
     209,   216,   259,   260,   470,   486,   136,   133,   136,   486,
     133,   133,   136,   133,   136,    38,    39,    40,    48,    54,
      65,    67,    70,    73,    95,    96,   140,   200,   224,   136,
      18,   133,   136,   485,    47,    50,   101,   140,   101,   101,
     133,    58,    59,   101,   337,    56,    28,   136,   136,   133,
     136,   486,    33,    35,    36,    42,    81,   412,   486,   486,
     101,   259,   321,   333,   166,   333,   486,   133,    14,    16,
     486,   486,   404,   133,    21,   193,   195,   205,   207,   136,
     205,   207,   205,   205,   210,   101,   133,   101,   262,   262,
     283,     0,   285,   286,    37,    44,   259,   288,   332,   170,
     170,   261,   262,   314,    91,    46,    53,    56,    57,    64,
     149,   151,   165,   191,   336,   341,   342,   343,   360,   361,
     365,   347,   348,   486,   147,    76,   113,   121,   122,   124,
     131,   135,   137,   142,   158,   182,   183,   184,   185,   186,
     187,   396,   397,   235,   138,   155,   178,   100,   126,   139,
     173,   180,   189,   117,   130,    71,   179,    85,    86,   138,
     155,   395,   133,   401,   404,   171,   172,   134,   416,   417,
     412,   416,   412,   416,   136,   334,   334,   333,   133,   333,
     333,   166,   173,   486,   133,   333,   333,   166,   333,   166,
     486,    38,    38,   486,   161,   175,   148,   181,    20,   484,
     146,   161,   161,   175,   101,   309,    33,    38,    90,   149,
     485,   201,   202,   203,    84,   217,   225,   238,   240,   250,
     253,   499,   500,   501,   502,   503,   506,   511,   512,   333,
     333,    20,   166,   485,   133,   140,   484,    96,   140,   307,
     484,   373,   374,   486,   485,   486,   352,   354,   486,   334,
     252,   252,   101,   355,   101,   486,    33,    68,   166,   468,
     469,   333,   166,   173,   486,   133,   373,   163,   333,   170,
     166,    25,   432,   433,   434,   333,     7,   154,    15,   166,
     333,   193,    20,   334,   334,   166,   334,   334,   334,   334,
     211,   479,   480,   486,   334,   353,   359,   486,   484,   484,
     290,   291,    37,   292,   314,   484,   334,   149,   101,   150,
     150,   334,   334,    91,    78,    80,   127,   246,   349,   350,
     455,   380,   381,   383,   383,   383,   383,   382,   383,   383,
     383,   133,   136,   236,   419,   488,   490,   491,   492,   493,
     494,   495,   496,   386,   386,   385,   387,   387,   387,   387,
     388,   388,   389,   389,   211,    78,    78,    78,   163,   333,
     404,   404,   333,   417,   166,   334,   427,   166,   163,   333,
     166,   163,    91,   166,    91,   166,   163,   333,   163,   163,
     163,   136,   319,   486,   486,    20,    91,    91,   486,   118,
     123,   140,   140,   484,   108,   113,   223,   226,    96,   225,
     254,   255,   257,   258,   223,   226,    20,   225,   254,   255,
     257,   258,   166,   163,   166,   166,   163,   333,   485,    80,
      33,   485,   484,    80,    91,   167,   127,   455,   113,   123,
      91,   123,   350,   455,   163,   486,    62,   197,   230,   338,
     339,   166,   166,   166,   163,    91,   166,    91,   166,   163,
     333,   167,   170,   486,   433,   434,   111,   176,   163,   163,
     112,   170,    78,   198,   199,   213,    78,   198,   199,   213,
      78,   217,   205,    91,   215,   123,   163,    55,    91,   170,
     265,   150,   486,   334,   366,   367,   101,   362,   363,   101,
     132,   190,   456,   458,   459,   460,   486,   101,   334,   101,
     127,   350,   127,   127,   349,   350,   383,   333,   488,   494,
     253,   522,    80,   148,   227,   228,   229,   237,   245,   251,
     252,   489,   497,   498,   499,   513,   516,   517,   519,   234,
     236,   241,   518,   221,   222,   243,   514,   456,   456,   454,
     459,   454,   163,   164,    91,   166,   320,   163,    84,   376,
     377,   133,   470,   471,   486,   470,   471,   163,   101,   166,
     328,   329,   118,   133,   331,   319,   319,   128,   145,   128,
     145,   455,   123,   334,   484,   484,   109,   110,   484,   255,
     256,    80,    96,   136,   505,   256,   177,   133,   163,   113,
     306,   484,   140,   113,    80,   306,   101,   334,   334,   127,
     484,   334,   101,   334,   123,   123,   350,   127,   455,   230,
      60,    61,    63,   101,   349,   356,   357,   358,   339,   133,
     470,   470,   163,   334,    25,   434,   111,   176,     8,     9,
      87,   104,   106,   133,   174,   330,   429,   431,   442,   443,
     446,    20,   212,   214,   334,   334,   334,   212,   214,   334,
     334,   334,   334,   334,   334,   101,   334,   334,   219,   482,
     483,   133,   101,   334,   366,    79,    90,    99,   108,   368,
     369,   370,   371,    91,   486,    91,   348,   136,   136,   125,
     155,   173,   457,   486,   486,   334,   127,   334,   334,   127,
     350,   127,   163,   166,   231,   197,   230,   242,   247,   521,
      80,   232,   233,   515,   231,   491,   521,   384,   387,   251,
     497,   499,   492,   127,   515,   256,    49,   125,   334,   101,
     456,    96,   377,   163,   333,   166,   166,   125,   166,   166,
     486,    78,    91,   166,   333,   118,   331,   320,   334,   256,
      80,   136,   508,    20,    96,   505,   334,   163,   333,   484,
      91,   306,   374,   334,   170,   354,   334,   334,   123,   334,
     127,   101,   101,   334,   486,   358,    63,   163,   333,   166,
     166,   113,   174,   431,     6,   333,   486,   174,   442,   170,
     213,   213,   213,   213,   217,   480,   165,   136,   483,   334,
     359,   150,   263,   264,   312,   484,   109,   110,   370,   371,
     371,   367,    90,   364,   363,   166,   166,   334,   334,   127,
     334,   387,    43,   110,   387,   387,   242,   248,   256,   520,
     520,   384,   493,   249,   486,   165,   101,   165,   163,   455,
     456,   329,    78,   163,   117,   180,   507,   510,    20,    20,
     509,   507,   244,   515,    91,   166,    91,   166,   107,   163,
      80,   484,   334,   334,   486,   486,   357,   334,   163,   434,
     486,   174,   163,   434,   486,   334,   334,   334,   334,   334,
     334,   413,   163,   136,   317,   150,   371,   484,   334,   387,
     387,   178,    78,   334,   486,   334,   456,   508,   508,   510,
      20,   166,    20,   239,   504,   505,   504,   334,   306,    61,
      77,   162,   435,   434,   486,   176,   434,    91,   166,   315,
     316,   334,    91,   166,   317,   387,   456,   165,   515,    91,
     166,   166,   101,     4,   114,   438,   439,   441,   443,    19,
     115,   436,   437,   440,   443,   176,   434,   176,   101,   331,
      90,   455,   315,   166,   165,   334,   239,   505,   486,    77,
     114,   441,   162,   115,   440,   176,   486,   484,   334,    91,
     166,   101,   331,   486,    91,   166,   101,   331,   486,   166,
     331
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
     535
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   281,   282,   282,   283,   283,   283,   283,   284,   284,
     285,   285,   286,   287,   288,   288,   288,   289,   289,   290,
     290,   291,   291,   291,   291,   292,   292,   292,   292,   292,
     293,   293,   293,   293,   293,   293,   293,   293,   294,   294,
     295,   296,   296,   297,   297,   298,   299,   300,   300,   301,
     301,   302,   302,   302,   302,   303,   304,   305,   305,   305,
     305,   306,   306,   307,   307,   308,   308,   308,   308,   309,
     309,   310,   310,   310,   311,   311,   312,   312,   313,   313,
     314,   314,   315,   315,   316,   316,   317,   317,   318,   318,
     319,   319,   319,   319,   320,   321,   321,   322,   323,   324,
     325,   325,   326,   326,   327,   327,   327,   327,   327,   328,
     328,   329,   329,   330,   331,   332,   333,   333,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   335,   336,   337,   337,
     338,   338,   338,   339,   339,   340,   340,   341,   342,   342,
     342,   343,   343,   343,   343,   343,   344,   344,   345,   345,
     346,   347,   347,   348,   348,   348,   348,   348,   348,   348,
     348,   349,   350,   351,   352,   352,   353,   353,   354,   354,
     354,   354,   355,   355,   356,   356,   356,   357,   357,   357,
     358,   358,   358,   359,   360,   361,   362,   362,   363,   363,
     364,   365,   365,   366,   366,   367,   367,   368,   368,   368,
     368,   368,   368,   368,   369,   369,   370,   370,   371,   372,
     372,   373,   373,   374,   374,   375,   375,   376,   376,   377,
     377,   378,   379,   379,   380,   380,   381,   381,   381,   381,
     381,   382,   381,   381,   381,   381,   383,   383,   383,   384,
     384,   385,   385,   385,   386,   386,   386,   386,   386,   387,
     387,   387,   388,   388,   388,   389,   389,   390,   390,   391,
     391,   392,   392,   393,   393,   394,   394,   394,   394,   395,
     395,   395,   396,   396,   396,   396,   396,   396,   397,   397,
     397,   398,   398,   399,   399,   400,   400,   401,   401,   402,
     402,   402,   402,   403,   404,   404,   404,   405,   405,   406,
     406,   406,   406,   407,   407,   408,   408,   408,   408,   408,
     408,   408,   409,   409,   410,   410,   411,   411,   411,   411,
     411,   412,   412,   413,   413,   414,   414,   414,   415,   415,
     416,   416,   417,   418,   418,   418,   418,   418,   418,   418,
     418,   419,   419,   420,   420,   420,   421,   422,   422,   423,
     424,   425,   426,   426,   427,   427,   428,   428,   429,   429,
     429,   430,   430,   430,   430,   430,   430,   431,   431,   432,
     432,   433,   434,   434,   435,   435,   436,   436,   437,   437,
     437,   437,   438,   438,   439,   439,   439,   439,   440,   440,
     441,   441,   442,   442,   442,   442,   443,   443,   443,   443,
     444,   444,   445,   445,   446,   447,   447,   447,   447,   447,
     447,   448,   449,   449,   449,   449,   450,   450,   450,   450,
     451,   452,   453,   453,   453,   453,   454,   454,   455,   456,
     456,   456,   457,   457,   457,   458,   458,   458,   459,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   461,   462,
     462,   462,   463,   464,   465,   465,   465,   466,   466,   466,
     466,   466,   467,   468,   468,   468,   468,   468,   468,   468,
     469,   470,   471,   472,   473,   473,   473,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   475,   475,   476,
     476,   477,   478,   479,   479,   480,   481,   482,   482,   483,
     483,   483,   483,   484,   485,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   487,   487,   488,
     488,   488,   488,   489,   489,   489,   489,   490,   490,   491,
     491,   492,   492,   493,   493,   494,   494,   494,   495,   495,
     496,   496,   497,   497,   497,   497,   497,   498,   499,   499,
     499,   499,   499,   499,   499,   500,   500,   500,   500,   501,
     501,   501,   501,   502,   502,   503,   503,   503,   503,   503,
     503,   503,   504,   504,   505,   505,   505,   505,   506,   506,
     506,   506,   506,   507,   507,   508,   508,   509,   509,   510,
     510,   511,   512,   512,   513,   513,   513,   514,   514,   514,
     514,   514,   515,   515,   515,   515,   516,   517,   518,   519,
     519,   520,   520,   520,   521,   521,   522
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     1,     2,     4,     6,
       2,     1,     2,     6,     2,     2,     4,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     3,     3,     5,     5,     4,     3,     3,     3,     5,
       5,     5,     5,     5,     5,     4,     3,     3,     4,     5,
       6,     1,     3,     3,     3,     3,     6,     5,     8,     2,
       3,     5,     4,     6,     1,     1,     1,     1,     2,     3,
       7,     8,     1,     3,     1,     2,     2,     3,     3,     3,
       2,     3,     4,     5,     3,     2,     3,     5,     3,     5,
       2,     2,     3,     3,     5,     5,     6,     6,     6,     1,
       3,     2,     3,     3,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     2,     4,     3,     5,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       2,     1,     4,     3,     4,     4,     5,     4,     5,     5,
       6,     3,     3,     3,     1,     4,     1,     4,     3,     4,
       4,     5,     4,     5,     1,     2,     3,     1,     2,     1,
       6,     3,     3,     1,     2,     3,     1,     3,     2,     3,
       2,     3,     4,     1,     3,     1,     2,     1,     1,     1,
       2,     2,     2,     3,     1,     1,     2,     2,     2,     5,
       5,     1,     4,     3,     4,     8,    10,     1,     2,     4,
       7,     8,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     0,     4,     3,     3,     3,     1,     3,     4,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     4,     1,     4,     1,
       4,     1,     4,     1,     2,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     3,     4,     1,     2,     3,     2,     1,
       2,     2,     1,     1,     1,     3,     3,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     7,     4,     1,
       2,     3,     4,     1,     1,     2,     2,     1,     3,     1,
       3,     1,     4,     1,     2,     1,     2,     3,     1,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     3,     5,     7,     5,
       7,     2,     1,     3,     2,     4,     4,     6,     4,     5,
       4,     5,     3,     1,     2,     2,     3,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     1,
       2,     1,     2,     3,     3,     4,     3,     3,     3,     2,
       2,     1,     1,     1,     1,     1,     3
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
  "\"'words'\"", "\"'thesaurus'\"", "\"'wildcards'\"", "\"'create'\"",
  "\"'drop'\"", "\"'unique'\"", "\"'index'\"", "\"'hash'\"", "\"'btree'\"",
  "\"'on'\"", "\"'BOM_UTF8'\"", "FTCONTAINS_REDUCE", "RANGE_REDUCE",
  "ADDITIVE_REDUCE", "MULTIPLICATIVE_REDUCE", "UNION_REDUCE",
  "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR",
  "UNARY_PREC", "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR", "OCCURS_PLUS",
  "OCCURS_HOOK", "STEP_REDUCE", "$accept", "Module", "ModuleWithoutBOM",
  "VersionDecl", "MainModule", "LibraryModule", "ModuleDecl", "Prolog",
  "SIND_DeclList", "VFO_DeclList", "SIND_Decl", "VFO_Decl", "Setter",
  "Import", "NamespaceDecl", "BoundarySpaceDecl", "DefaultNamespaceDecl",
  "OptionDecl", "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "DefaultCollationDecl", "BaseURIDecl",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "VarNameAndType", "VarDecl", "DeclareOrCreate", "IndexingMethod",
  "IndexDecl", "IndexDeclSuffix", "IndexField", "IndexField1",
  "IndexFieldList", "ConstructionDecl", "FunctionSig", "Block",
  "BlockBody", "AssignExpr", "ExitExpr", "WhileExpr", "FlowCtlStatement",
  "IndexStatement", "FunctionDecl", "ParamList", "Param", "EnclosedExpr",
  "BracedExpr", "QueryBody", "Expr", "ExprSingle", "FLWORExpr",
  "ReturnExpr", "WindowType", "FLWORWinCondType", "FLWORWinCond",
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
       282,     0,    -1,   283,    -1,   266,   283,    -1,   285,    -1,
     284,   285,    -1,   286,    -1,   284,   286,    -1,   194,   195,
      20,   170,    -1,   194,   195,    20,   112,    20,   170,    -1,
     288,   332,    -1,   332,    -1,   287,   288,    -1,    47,   140,
     485,   113,   484,   170,    -1,   289,   170,    -1,   290,   170,
      -1,   289,   170,   290,   170,    -1,   291,    -1,   289,   170,
     291,    -1,   292,    -1,   290,   170,   292,    -1,   293,    -1,
     294,    -1,   295,    -1,   297,    -1,   310,    -1,   327,    -1,
     298,    -1,   299,    -1,   313,    -1,   296,    -1,   303,    -1,
     304,    -1,   318,    -1,   300,    -1,   301,    -1,   302,    -1,
     473,    -1,   305,    -1,   308,    -1,    37,   140,   485,   113,
     484,    -1,    37,    73,   161,    -1,    37,    73,   175,    -1,
      37,    96,    33,   140,   484,    -1,    37,    96,    38,   140,
     484,    -1,    37,    48,   486,    20,    -1,    37,   224,   499,
      -1,    37,    65,   148,    -1,    37,    65,   181,    -1,    37,
      96,   149,   108,   109,    -1,    37,    96,   149,   108,   110,
      -1,    37,    70,   161,    91,   128,    -1,    37,    70,   161,
      91,   145,    -1,    37,    70,   146,    91,   128,    -1,    37,
      70,   146,    91,   145,    -1,    37,    96,    90,   484,    -1,
      37,    67,   484,    -1,    44,    50,   484,    -1,    44,    50,
     307,   484,    -1,    44,    50,   484,    80,   306,    -1,    44,
      50,   307,   484,    80,   306,    -1,   484,    -1,   306,    91,
     484,    -1,   140,   485,   113,    -1,    96,    33,   140,    -1,
      44,    47,   484,    -1,    44,    47,   140,   485,   113,   484,
      -1,    44,    47,   484,    80,   306,    -1,    44,    47,   140,
     485,   113,   484,    80,   306,    -1,   101,   486,    -1,   101,
     486,   455,    -1,    37,    95,   309,   123,   334,    -1,    37,
      95,   309,   118,    -1,    37,    95,   309,   118,   123,   334,
      -1,    37,    -1,   259,    -1,   263,    -1,   264,    -1,   311,
     314,    -1,   311,   261,   314,    -1,   262,   484,   265,   334,
     150,   317,   166,    -1,   262,   484,   265,   334,   312,   150,
     317,   166,    -1,   316,    -1,   316,    90,   484,    -1,   334,
      -1,   334,   455,    -1,   136,   315,    -1,   317,    91,   315,
      -1,    37,    54,   161,    -1,    37,    54,   175,    -1,   136,
     166,    -1,   136,   328,   166,    -1,   136,   166,    78,   456,
      -1,   136,   328,   166,    78,   456,    -1,   133,   321,   163,
      -1,   333,   170,    -1,   321,   333,   170,    -1,    52,   101,
     486,   123,   334,    -1,    26,   217,   334,    -1,    30,   136,
     334,   166,   320,    -1,    27,    28,    -1,    66,    28,    -1,
     259,   262,   484,    -1,   260,   262,   484,    -1,    37,    38,
     486,   319,   118,    -1,    37,    38,   486,   319,   331,    -1,
      37,    39,    38,   486,   319,   118,    -1,    37,    39,    38,
     486,   319,   331,    -1,    37,    40,    38,   486,   319,   320,
      -1,   329,    -1,   328,    91,   329,    -1,   101,   486,    -1,
     101,   486,   455,    -1,   133,   333,   163,    -1,   133,   333,
     163,    -1,   333,    -1,   334,    -1,   333,    91,   334,    -1,
     335,    -1,   372,    -1,   375,    -1,   378,    -1,   379,    -1,
     474,    -1,   475,    -1,   477,    -1,   476,    -1,   478,    -1,
     481,    -1,   487,    -1,   323,    -1,   324,    -1,   325,    -1,
     322,    -1,   320,    -1,   326,    -1,   344,   336,    -1,   165,
     334,    -1,    58,   252,    -1,    59,   252,    -1,   197,    -1,
     230,    -1,    62,   230,    -1,   338,   356,    63,   334,    -1,
     338,    63,   334,    -1,    56,   337,   355,   339,   339,    -1,
      56,   337,   355,   339,    -1,    64,   101,   486,    -1,   346,
      -1,   351,    -1,   340,    -1,   342,    -1,   360,    -1,   365,
      -1,   361,    -1,   341,    -1,   342,    -1,   344,   343,    -1,
      56,   101,    -1,    57,    56,   101,    -1,   345,   347,    -1,
     348,    -1,   347,    91,   101,   348,    -1,   486,   127,   334,
      -1,   486,   455,   127,   334,    -1,   486,   349,   127,   334,
      -1,   486,   455,   349,   127,   334,    -1,   486,   350,   127,
     334,    -1,   486,   455,   350,   127,   334,    -1,   486,   349,
     350,   127,   334,    -1,   486,   455,   349,   350,   127,   334,
      -1,    80,   101,   486,    -1,   246,   101,   486,    -1,    53,
     101,   352,    -1,   354,    -1,   352,    91,   101,   354,    -1,
     359,    -1,   353,    91,   101,   359,    -1,   486,   123,   334,
      -1,   486,   455,   123,   334,    -1,   486,   350,   123,   334,
      -1,   486,   455,   350,   123,   334,    -1,   101,   486,   127,
     334,    -1,   101,   486,   455,   127,   334,    -1,   357,    -1,
     101,   486,    -1,   101,   486,   357,    -1,   349,    -1,   349,
     358,    -1,   358,    -1,    60,   101,   486,    61,   101,   486,
      -1,    61,   101,   486,    -1,    60,   101,   486,    -1,   486,
      -1,   191,   334,    -1,   151,   150,   362,    -1,   363,    -1,
     362,    91,   363,    -1,   101,   486,    -1,   101,   486,   364,
      -1,    90,   484,    -1,   149,   150,   366,    -1,    46,   149,
     150,   366,    -1,   367,    -1,   366,    91,   367,    -1,   334,
      -1,   334,   368,    -1,   369,    -1,   370,    -1,   371,    -1,
     369,   370,    -1,   369,   371,    -1,   370,   371,    -1,   369,
     370,   371,    -1,    79,    -1,    99,    -1,   108,   109,    -1,
     108,   110,    -1,    90,   484,    -1,    45,   101,   373,   167,
     334,    -1,   116,   101,   373,   167,   334,    -1,   374,    -1,
     373,    91,   101,   374,    -1,   486,   127,   334,    -1,   486,
     455,   127,   334,    -1,    32,   136,   333,   166,   376,    96,
     165,   334,    -1,    32,   136,   333,   166,   376,    96,   101,
     486,   165,   334,    -1,   377,    -1,   376,   377,    -1,    84,
     456,   165,   334,    -1,    84,   101,   486,    78,   456,   165,
     334,    -1,    41,   136,   333,   166,   177,   334,   107,   334,
      -1,   380,    -1,   379,   147,   380,    -1,   381,    -1,   380,
      76,   381,    -1,   383,    -1,   383,   396,   383,    -1,   383,
     397,   383,    -1,   383,   113,   383,    -1,   383,   142,   383,
      -1,    -1,   383,   137,   382,   383,    -1,   383,   135,   383,
      -1,   383,   124,   383,    -1,   383,   122,   383,    -1,   384,
      -1,   384,   235,   488,    -1,   384,   235,   488,   522,    -1,
     385,    -1,   385,   178,   385,    -1,   386,    -1,   385,   155,
     386,    -1,   385,   138,   386,    -1,   387,    -1,   386,   173,
     387,    -1,   386,   100,   387,    -1,   386,   126,   387,    -1,
     386,   139,   387,    -1,   388,    -1,   387,   180,   388,    -1,
     387,   189,   388,    -1,   389,    -1,   388,   130,   389,    -1,
     388,   117,   389,    -1,   390,    -1,   390,    71,   211,   456,
      -1,   391,    -1,   391,   179,    78,   456,    -1,   392,    -1,
     392,    85,    78,   454,    -1,   393,    -1,   393,    86,    78,
     454,    -1,   395,    -1,   394,   395,    -1,   155,    -1,   138,
      -1,   394,   155,    -1,   394,   138,    -1,   398,    -1,   402,
      -1,   399,    -1,   182,    -1,   187,    -1,   186,    -1,   185,
      -1,   184,    -1,   183,    -1,   131,    -1,   158,    -1,   121,
      -1,    31,   133,   333,   163,    -1,    31,   470,   133,   333,
     163,    -1,   400,   133,   163,    -1,   400,   133,   333,   163,
      -1,   401,    -1,   400,   401,    -1,   156,   486,    15,    -1,
     156,    16,    -1,   403,    -1,   403,   404,    -1,   172,   404,
      -1,   404,    -1,   171,    -1,   405,    -1,   405,   171,   404,
      -1,   405,   172,   404,    -1,   406,    -1,   415,    -1,   407,
      -1,   407,   416,    -1,   410,    -1,   410,   416,    -1,   408,
     412,    -1,   409,    -1,    89,    -1,    97,    -1,    82,    -1,
     169,    -1,    98,    -1,   120,    -1,   119,    -1,   412,    -1,
      83,   412,    -1,   411,   412,    -1,   103,    -1,   152,    -1,
      74,    -1,   160,    -1,   159,    -1,    75,    -1,   460,    -1,
     413,    -1,   486,    -1,   414,    -1,   173,    -1,    10,    -1,
      17,    -1,   418,    -1,   418,   416,    -1,   417,    -1,   416,
     417,    -1,   134,   333,   164,    -1,   419,    -1,   421,    -1,
     422,    -1,   423,    -1,   426,    -1,   428,    -1,   424,    -1,
     425,    -1,   420,    -1,   472,    -1,    94,    -1,   129,    -1,
     105,    -1,   101,   486,    -1,   136,   166,    -1,   136,   333,
     166,    -1,   102,    -1,   148,   133,   333,   163,    -1,   181,
     133,   333,   163,    -1,   486,   136,   166,    -1,   486,   136,
     427,   166,    -1,   334,    -1,   427,    91,   334,    -1,   429,
      -1,   447,    -1,   430,    -1,   444,    -1,   445,    -1,   137,
     486,   434,   111,    -1,   137,   486,   432,   434,   111,    -1,
     137,   486,   434,   176,   174,   486,   434,   176,    -1,   137,
     486,   434,   176,   431,   174,   486,   434,   176,    -1,   137,
     486,   432,   434,   176,   174,   486,   434,   176,    -1,   137,
     486,   432,   434,   176,   431,   174,   486,   434,   176,    -1,
     442,    -1,   431,   442,    -1,   433,    -1,   432,   433,    -1,
      25,   486,   434,   113,   434,   435,    -1,    -1,    25,    -1,
     162,   436,   162,    -1,    77,   438,    77,    -1,    -1,   437,
      -1,   115,    -1,   440,    -1,   437,   115,    -1,   437,   440,
      -1,    -1,   439,    -1,   114,    -1,   441,    -1,   439,   114,
      -1,   439,   441,    -1,    19,    -1,   443,    -1,     4,    -1,
     443,    -1,   429,    -1,     9,    -1,   446,    -1,   443,    -1,
       8,    -1,   104,    -1,   106,    -1,   330,    -1,   192,    21,
     193,    -1,   192,   193,    -1,   153,    14,   154,    -1,   153,
      14,     7,    -1,    87,     6,    -1,   448,    -1,   449,    -1,
     450,    -1,   451,    -1,   452,    -1,   453,    -1,    34,   133,
     333,   163,    -1,    33,   486,   133,   163,    -1,    33,   486,
     133,   333,   163,    -1,    33,   133,   333,   163,   133,   163,
      -1,    33,   133,   333,   163,   133,   333,   163,    -1,    81,
     486,   133,   163,    -1,    81,   486,   133,   333,   163,    -1,
      81,   133,   333,   163,   133,   163,    -1,    81,   133,   333,
     163,   133,   333,   163,    -1,    35,   133,   333,   163,    -1,
      36,   133,   333,   163,    -1,    42,   485,   133,   163,    -1,
      42,   485,   133,   333,   163,    -1,    42,   133,   333,   163,
     133,   163,    -1,    42,   133,   333,   163,   133,   333,   163,
      -1,   459,    -1,   459,   125,    -1,    78,   456,    -1,   458,
      -1,   458,   457,    -1,   190,   136,   166,    -1,   125,    -1,
     173,    -1,   155,    -1,   459,    -1,   460,    -1,   132,   136,
     166,    -1,   486,    -1,   462,    -1,   468,    -1,   466,    -1,
     469,    -1,   467,    -1,   465,    -1,   464,    -1,   463,    -1,
     461,    -1,   205,   136,   166,    -1,    69,   136,   166,    -1,
      69,   136,   468,   166,    -1,    69,   136,   469,   166,    -1,
      35,   136,   166,    -1,    36,   136,   166,    -1,    42,   136,
     166,    -1,    42,   136,   485,   166,    -1,    42,   136,    20,
     166,    -1,    81,   136,   166,    -1,    81,   136,   486,   166,
      -1,    81,   136,   486,    91,   470,   166,    -1,    81,   136,
     173,   166,    -1,    81,   136,   173,    91,   470,   166,    -1,
     168,   486,   166,    -1,    33,   136,   166,    -1,    33,   136,
     486,   166,    -1,    33,   136,   486,    91,   470,   166,    -1,
      33,   136,   486,    91,   471,   166,    -1,    33,   136,   173,
     166,    -1,    33,   136,   173,    91,   470,   166,    -1,    33,
     136,   173,    91,   471,   166,    -1,    68,   136,   486,   166,
      -1,   486,    -1,   486,   125,    -1,    20,    -1,    37,   200,
     201,    -1,    37,   200,   202,    -1,    37,   200,   203,    -1,
     206,   205,   334,   213,   334,    -1,   206,   205,   334,    78,
     212,   213,   334,    -1,   206,   205,   334,    78,   214,   213,
     334,    -1,   206,   205,   334,   198,   334,    -1,   206,   205,
     334,   199,   334,    -1,   206,   207,   334,   213,   334,    -1,
     206,   207,   334,    78,   212,   213,   334,    -1,   206,   207,
     334,    78,   214,   213,   334,    -1,   206,   207,   334,   198,
     334,    -1,   206,   207,   334,   199,   334,    -1,   204,   205,
     334,    -1,   204,   207,   334,    -1,   209,   205,   334,   217,
     334,    -1,   209,   210,   211,   205,   334,   217,   334,    -1,
     208,   205,   334,    78,   334,    -1,   216,   101,   479,   215,
     334,   165,   334,    -1,   480,    -1,   479,    91,   101,   480,
      -1,   486,   123,   334,    -1,   218,   133,   334,   163,   482,
      -1,   483,    -1,   482,   483,    -1,   219,   136,   413,   166,
     331,    -1,   219,   136,   413,    91,   101,   486,   166,   331,
      -1,   219,   136,   413,    91,   101,   486,    91,   101,   486,
     166,   331,    -1,   219,   136,   413,    91,   101,   486,    91,
     101,   486,    91,   101,   486,   166,   331,    -1,    20,    -1,
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
      52,    -1,   262,    -1,   259,    -1,   261,    -1,   265,    -1,
     263,    -1,   264,    -1,   260,    -1,   220,   101,   353,    55,
     133,   334,   163,    -1,    55,   133,   334,   163,    -1,   490,
      -1,   490,   489,    -1,   490,   251,   384,    -1,   490,   489,
     251,   384,    -1,   499,    -1,   497,    -1,   489,   499,    -1,
     489,   497,    -1,   491,    -1,   490,   237,   491,    -1,   492,
      -1,   491,   234,   492,    -1,   493,    -1,   492,   236,   127,
     493,    -1,   494,    -1,   236,   494,    -1,   495,    -1,   495,
     518,    -1,   136,   488,   166,    -1,   496,    -1,   496,   514,
      -1,   419,    -1,   133,   333,   163,    -1,   498,    -1,   517,
      -1,   516,    -1,   519,    -1,   513,    -1,   148,    -1,   500,
      -1,   501,    -1,   502,    -1,   503,    -1,   506,    -1,   511,
      -1,   512,    -1,   240,    -1,   250,    -1,    84,   223,    -1,
      84,   226,    -1,   217,   225,    -1,   253,   225,    -1,   225,
     223,    -1,   225,   226,    -1,   217,   254,    -1,   253,   254,
      -1,   217,   257,   505,    -1,   217,   257,    96,    -1,   217,
     257,   136,   505,   166,    -1,   217,   257,   136,   505,    91,
     504,   166,    -1,   217,   257,   136,    96,   166,    -1,   217,
     257,   136,    96,    91,   504,   166,    -1,   253,   257,    -1,
     505,    -1,   504,    91,   505,    -1,    80,    20,    -1,    80,
      20,   244,    20,    -1,    80,    20,   515,   239,    -1,    80,
      20,   244,    20,   515,   239,    -1,   217,   255,   256,   508,
      -1,   217,   255,   256,   508,   507,    -1,   217,    96,   255,
     256,    -1,   217,    96,   255,   256,   507,    -1,   253,   255,
     256,    -1,   510,    -1,   507,   510,    -1,    80,    20,    -1,
     136,   509,   166,    -1,    20,    -1,   509,    20,    -1,   180,
     508,    -1,   117,   508,    -1,   238,    20,    -1,   217,   258,
      -1,   253,   258,    -1,    80,   197,    -1,    80,   230,    -1,
     229,   231,    -1,   222,    -1,   222,    49,    -1,   221,    -1,
     221,   256,    -1,   243,    -1,   232,   387,    -1,    80,   110,
     387,    -1,    80,    43,   387,    -1,   233,   387,   178,   387,
      -1,   228,   515,   520,    -1,   252,   387,   520,    -1,   241,
     515,   249,    -1,   245,   521,    -1,   227,   521,    -1,   256,
      -1,   248,    -1,   242,    -1,   247,    -1,   242,    -1,   253,
     231,   387,    -1
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
     106,   112,   116,   120,   126,   132,   137,   141,   145,   149,
     155,   161,   167,   173,   179,   185,   190,   194,   198,   203,
     209,   216,   218,   222,   226,   230,   234,   241,   247,   256,
     259,   263,   269,   274,   281,   283,   285,   287,   289,   292,
     296,   304,   313,   315,   319,   321,   324,   327,   331,   335,
     339,   342,   346,   351,   357,   361,   364,   368,   374,   378,
     384,   387,   390,   394,   398,   404,   410,   417,   424,   431,
     433,   437,   440,   444,   448,   452,   454,   456,   460,   462,
     464,   466,   468,   470,   472,   474,   476,   478,   480,   482,
     484,   486,   488,   490,   492,   494,   496,   499,   502,   505,
     508,   510,   512,   515,   520,   524,   530,   535,   539,   541,
     543,   545,   547,   549,   551,   553,   555,   557,   560,   563,
     567,   570,   572,   577,   581,   586,   591,   597,   602,   608,
     614,   621,   625,   629,   633,   635,   640,   642,   647,   651,
     656,   661,   667,   672,   678,   680,   683,   687,   689,   692,
     694,   701,   705,   709,   711,   714,   718,   720,   724,   727,
     731,   734,   738,   743,   745,   749,   751,   754,   756,   758,
     760,   763,   766,   769,   773,   775,   777,   780,   783,   786,
     792,   798,   800,   805,   809,   814,   823,   834,   836,   839,
     844,   852,   861,   863,   867,   869,   873,   875,   879,   883,
     887,   891,   892,   897,   901,   905,   909,   911,   915,   920,
     922,   926,   928,   932,   936,   938,   942,   946,   950,   954,
     956,   960,   964,   966,   970,   974,   976,   981,   983,   988,
     990,   995,   997,  1002,  1004,  1007,  1009,  1011,  1014,  1017,
    1019,  1021,  1023,  1025,  1027,  1029,  1031,  1033,  1035,  1037,
    1039,  1041,  1046,  1052,  1056,  1061,  1063,  1066,  1070,  1073,
    1075,  1078,  1081,  1083,  1085,  1087,  1091,  1095,  1097,  1099,
    1101,  1104,  1106,  1109,  1112,  1114,  1116,  1118,  1120,  1122,
    1124,  1126,  1128,  1130,  1133,  1136,  1138,  1140,  1142,  1144,
    1146,  1148,  1150,  1152,  1154,  1156,  1158,  1160,  1162,  1164,
    1167,  1169,  1172,  1176,  1178,  1180,  1182,  1184,  1186,  1188,
    1190,  1192,  1194,  1196,  1198,  1200,  1202,  1205,  1208,  1212,
    1214,  1219,  1224,  1228,  1233,  1235,  1239,  1241,  1243,  1245,
    1247,  1249,  1254,  1260,  1269,  1279,  1289,  1300,  1302,  1305,
    1307,  1310,  1317,  1318,  1320,  1324,  1328,  1329,  1331,  1333,
    1335,  1338,  1341,  1342,  1344,  1346,  1348,  1351,  1354,  1356,
    1358,  1360,  1362,  1364,  1366,  1368,  1370,  1372,  1374,  1376,
    1378,  1382,  1385,  1389,  1393,  1396,  1398,  1400,  1402,  1404,
    1406,  1408,  1413,  1418,  1424,  1431,  1439,  1444,  1450,  1457,
    1465,  1470,  1475,  1480,  1486,  1493,  1501,  1503,  1506,  1509,
    1511,  1514,  1518,  1520,  1522,  1524,  1526,  1528,  1532,  1534,
    1536,  1538,  1540,  1542,  1544,  1546,  1548,  1550,  1552,  1556,
    1560,  1565,  1570,  1574,  1578,  1582,  1587,  1592,  1596,  1601,
    1608,  1613,  1620,  1624,  1628,  1633,  1640,  1647,  1652,  1659,
    1666,  1671,  1673,  1676,  1678,  1682,  1686,  1690,  1696,  1704,
    1712,  1718,  1724,  1730,  1738,  1746,  1752,  1758,  1762,  1766,
    1772,  1780,  1786,  1794,  1796,  1801,  1805,  1811,  1813,  1816,
    1822,  1831,  1843,  1858,  1860,  1862,  1864,  1866,  1868,  1870,
    1872,  1874,  1876,  1878,  1880,  1882,  1884,  1886,  1888,  1890,
    1892,  1894,  1896,  1898,  1900,  1902,  1904,  1906,  1908,  1910,
    1912,  1914,  1916,  1918,  1920,  1922,  1924,  1926,  1928,  1930,
    1932,  1934,  1936,  1938,  1940,  1942,  1944,  1946,  1948,  1950,
    1952,  1954,  1956,  1958,  1960,  1962,  1964,  1966,  1968,  1970,
    1972,  1974,  1976,  1978,  1980,  1982,  1984,  1986,  1988,  1990,
    1992,  1994,  1996,  1998,  2000,  2002,  2004,  2006,  2008,  2010,
    2012,  2014,  2016,  2018,  2020,  2022,  2024,  2026,  2028,  2030,
    2032,  2034,  2036,  2038,  2040,  2042,  2044,  2046,  2048,  2050,
    2052,  2054,  2056,  2058,  2060,  2062,  2064,  2066,  2068,  2070,
    2072,  2074,  2076,  2078,  2080,  2082,  2084,  2086,  2088,  2090,
    2092,  2094,  2096,  2098,  2100,  2102,  2104,  2106,  2108,  2110,
    2112,  2114,  2116,  2118,  2120,  2122,  2124,  2126,  2128,  2130,
    2132,  2134,  2136,  2138,  2140,  2142,  2144,  2146,  2148,  2150,
    2152,  2154,  2156,  2158,  2160,  2162,  2164,  2166,  2168,  2170,
    2172,  2174,  2176,  2178,  2180,  2182,  2184,  2186,  2194,  2199,
    2201,  2204,  2208,  2213,  2215,  2217,  2220,  2223,  2225,  2229,
    2231,  2235,  2237,  2242,  2244,  2247,  2249,  2252,  2256,  2258,
    2261,  2263,  2267,  2269,  2271,  2273,  2275,  2277,  2279,  2281,
    2283,  2285,  2287,  2289,  2291,  2293,  2295,  2297,  2300,  2303,
    2306,  2309,  2312,  2315,  2318,  2321,  2325,  2329,  2335,  2343,
    2349,  2357,  2360,  2362,  2366,  2369,  2374,  2379,  2386,  2391,
    2397,  2402,  2408,  2412,  2414,  2417,  2420,  2424,  2426,  2429,
    2432,  2435,  2438,  2441,  2444,  2447,  2450,  2453,  2455,  2458,
    2460,  2463,  2465,  2468,  2472,  2476,  2481,  2485,  2489,  2493,
    2496,  2499,  2501,  2503,  2505,  2507,  2509
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   855,   855,   856,   866,   871,   877,   882,   894,   899,
     909,   916,   928,   940,   952,   958,   964,   976,   982,   996,
    1002,  1016,  1017,  1018,  1019,  1025,  1026,  1027,  1030,  1033,
    1040,  1041,  1042,  1043,  1044,  1045,  1046,  1049,  1056,  1057,
    1069,  1081,  1086,  1097,  1103,  1115,  1128,  1139,  1144,  1156,
    1161,  1172,  1178,  1184,  1190,  1209,  1220,  1231,  1238,  1245,
    1252,  1265,  1271,  1286,  1290,  1300,  1306,  1313,  1319,  1330,
    1334,  1344,  1352,  1358,  1367,  1369,  1374,  1376,  1381,  1387,
    1397,  1402,  1412,  1416,  1424,  1428,  1435,  1442,  1452,  1457,
    1469,  1473,  1477,  1481,  1488,  1495,  1501,  1510,  1517,  1524,
    1531,  1535,  1542,  1546,  1553,  1561,  1570,  1579,  1588,  1603,
    1611,  1625,  1631,  1643,  1651,  1662,  1673,  1679,  1691,  1692,
    1693,  1694,  1695,  1698,  1699,  1700,  1701,  1702,  1704,  1705,
    1708,  1709,  1710,  1711,  1712,  1715,  1722,  1731,  1738,  1742,
    1750,  1754,  1758,  1765,  1769,  1776,  1781,  1790,  1799,  1800,
    1801,  1805,  1805,  1805,  1805,  1805,  1808,  1814,  1823,  1827,
    1837,  1848,  1854,  1868,  1875,  1883,  1892,  1902,  1910,  1919,
    1928,  1943,  1955,  1966,  1978,  1984,  1996,  2002,  2016,  2024,
    2033,  2041,  2053,  2059,  2069,  2070,  2074,  2082,  2086,  2091,
    2095,  2099,  2103,  2110,  2125,  2133,  2143,  2149,  2160,  2166,
    2175,  2185,  2190,  2202,  2208,  2222,  2228,  2240,  2247,  2254,
    2261,  2268,  2275,  2282,  2295,  2299,  2309,  2314,  2325,  2336,
    2343,  2356,  2363,  2375,  2381,  2394,  2401,  2415,  2421,  2433,
    2439,  2452,  2463,  2467,  2478,  2482,  2501,  2505,  2513,  2521,
    2529,  2537,  2537,  2545,  2553,  2561,  2575,  2579,  2586,  2599,
    2603,  2614,  2618,  2622,  2632,  2636,  2640,  2644,  2648,  2658,
    2662,  2667,  2678,  2682,  2686,  2696,  2700,  2712,  2716,  2728,
    2732,  2744,  2748,  2760,  2764,  2776,  2780,  2784,  2788,  2800,
    2804,  2808,  2818,  2822,  2826,  2830,  2834,  2838,  2848,  2852,
    2856,  2866,  2870,  2882,  2888,  2900,  2906,  2920,  2927,  2968,
    2972,  2976,  2980,  2992,  3002,  3013,  3018,  3028,  3032,  3042,
    3048,  3054,  3060,  3072,  3078,  3089,  3093,  3097,  3101,  3105,
    3109,  3113,  3123,  3127,  3137,  3143,  3155,  3159,  3163,  3167,
    3171,  3186,  3190,  3200,  3204,  3214,  3221,  3228,  3241,  3245,
    3257,  3263,  3277,  3288,  3292,  3296,  3300,  3304,  3308,  3312,
    3316,  3326,  3330,  3340,  3345,  3350,  3361,  3371,  3375,  3386,
    3396,  3407,  3463,  3469,  3481,  3487,  3499,  3503,  3513,  3517,
    3521,  3531,  3539,  3547,  3555,  3563,  3571,  3586,  3592,  3604,
    3610,  3623,  3632,  3634,  3640,  3645,  3657,  3660,  3667,  3673,
    3679,  3687,  3702,  3705,  3712,  3718,  3724,  3732,  3746,  3751,
    3762,  3767,  3778,  3783,  3788,  3794,  3806,  3812,  3817,  3822,
    3833,  3838,  3853,  3858,  3875,  3890,  3894,  3898,  3902,  3906,
    3910,  3920,  3931,  3937,  3943,  3948,  3970,  3976,  3982,  3987,
    3998,  4009,  4020,  4026,  4032,  4037,  4048,  4054,  4066,  4078,
    4084,  4090,  4127,  4132,  4137,  4148,  4152,  4156,  4166,  4177,
    4181,  4185,  4189,  4193,  4197,  4201,  4205,  4209,  4219,  4229,
    4233,  4238,  4249,  4259,  4269,  4273,  4277,  4287,  4293,  4299,
    4305,  4311,  4323,  4334,  4341,  4348,  4355,  4362,  4369,  4376,
    4389,  4410,  4417,  4437,  4477,  4482,  4485,  4493,  4499,  4505,
    4511,  4517,  4524,  4530,  4536,  4542,  4548,  4560,  4565,  4575,
    4581,  4593,  4619,  4630,  4636,  4649,  4663,  4670,  4677,  4688,
    4695,  4703,  4712,  4725,  4728,  4746,  4747,  4748,  4749,  4750,
    4751,  4752,  4753,  4754,  4755,  4756,  4757,  4758,  4759,  4760,
    4761,  4762,  4763,  4764,  4765,  4766,  4767,  4768,  4769,  4770,
    4771,  4772,  4773,  4774,  4775,  4776,  4777,  4778,  4779,  4780,
    4781,  4782,  4783,  4784,  4785,  4786,  4787,  4788,  4789,  4790,
    4791,  4792,  4793,  4794,  4795,  4796,  4797,  4798,  4799,  4800,
    4801,  4802,  4803,  4804,  4805,  4806,  4807,  4808,  4809,  4810,
    4811,  4812,  4813,  4814,  4815,  4816,  4817,  4818,  4819,  4820,
    4821,  4822,  4823,  4824,  4825,  4826,  4827,  4828,  4829,  4830,
    4831,  4832,  4833,  4834,  4835,  4836,  4837,  4838,  4839,  4840,
    4841,  4842,  4843,  4844,  4845,  4846,  4847,  4848,  4849,  4850,
    4851,  4852,  4853,  4854,  4855,  4856,  4857,  4858,  4859,  4860,
    4861,  4862,  4863,  4864,  4865,  4866,  4867,  4868,  4869,  4870,
    4871,  4872,  4873,  4874,  4875,  4876,  4877,  4878,  4879,  4880,
    4881,  4882,  4883,  4884,  4885,  4886,  4887,  4888,  4889,  4890,
    4891,  4892,  4893,  4894,  4895,  4896,  4897,  4898,  4899,  4900,
    4901,  4902,  4903,  4904,  4905,  4906,  4907,  4918,  4924,  4941,
    4945,  4949,  4953,  4963,  4966,  4969,  4972,  4981,  4984,  4993,
    4996,  5005,  5008,  5017,  5020,  5029,  5032,  5035,  5044,  5047,
    5056,  5060,  5070,  5073,  5076,  5079,  5082,  5091,  5100,  5104,
    5108,  5112,  5116,  5120,  5124,  5134,  5137,  5140,  5143,  5152,
    5155,  5158,  5161,  5170,  5173,  5182,  5185,  5188,  5191,  5194,
    5197,  5200,  5209,  5212,  5221,  5224,  5227,  5230,  5239,  5242,
    5245,  5248,  5251,  5260,  5263,  5272,  5275,  5284,  5287,  5296,
    5299,  5308,  5317,  5320,  5329,  5332,  5335,  5344,  5347,  5350,
    5353,  5356,  5365,  5369,  5373,  5377,  5387,  5396,  5406,  5415,
    5418,  5427,  5430,  5433,  5442,  5445,  5454
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
     275,   276,   277,   278,   279,   280
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 8396;
  const int xquery_parser::yynnts_ = 242;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 451;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 281;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 535;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5462 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_ofor = "ofor", *the_declare = "declare", *the_create = "create";

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

