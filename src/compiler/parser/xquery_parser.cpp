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
#line 862 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

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
        case 97: /* "\"'DECIMAL'\"" */
#line 746 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 109: /* "\"'DOUBLE'\"" */
#line 745 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 133: /* "\"'INTEGER'\"" */
#line 744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "VersionDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "MainModule" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "LibraryModule" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "ModuleDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "Prolog" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "SIND_DeclList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "VFO_DeclList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "SIND_Decl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "VFO_Decl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "Setter" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "Import" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "NamespaceDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "BoundarySpaceDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "DefaultNamespaceDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "OptionDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "OrderingModeDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "EmptyOrderDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "CopyNamespacesDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "DefaultCollationDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "BaseURIDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "SchemaImport" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "URILiteralList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "SchemaPrefix" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "ModuleImport" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "CtxItemDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 346 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "CtxItemDecl2" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "CtxItemDecl3" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 356 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "CtxItemDecl4" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 361 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "VarNameAndType" */
#line 758 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };
#line 366 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "VarDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 371 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "IndexDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 376 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "IndexDecl2" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 381 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "IndexDeclSuffix" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 386 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "IndexField" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 391 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "IndexField1" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 396 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "IndexFieldList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 401 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "ConstructionDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 406 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "FunctionSig" */
#line 758 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 411 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "BlockExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 416 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "Block" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 421 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "AssignExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 426 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "ExitExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 431 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "WhileExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 436 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "FlowCtlStatement" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 441 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "IndexStatement" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 446 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "FunctionDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 451 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "FunctionDecl2" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 456 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "FunctionDecl3" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 461 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "FunctionDecl4" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 466 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "ParamList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 471 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "Param" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "EnclosedExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 481 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "BracedExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 486 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "QueryBody" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 491 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "Expr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 496 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ApplyExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 501 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "ConcatExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 506 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "ExprSingle" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 511 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "FLWORExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 516 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "ReturnExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 521 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "FLWORWinCond" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "WindowClause" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CountClause" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 536 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "ForLetWinClause" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "FLWORClauseList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "ForClause" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 551 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VarInDeclList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 556 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "VarInDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 561 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "PositionalVar" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 566 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "LetClause" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 571 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "VarGetsDeclList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 576 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "EvalVarDeclList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 581 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "VarGetsDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 586 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "WindowVarDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 591 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "WindowVars" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 596 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "WindowVars3" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 601 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "WindowVars2" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 606 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "EvalVarDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 611 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "WhereClause" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 616 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "GroupByClause" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 621 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "GroupSpecList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 626 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "GroupSpec" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 631 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "GroupCollationSpec" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 636 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "OrderByClause" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 641 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "OrderSpecList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 646 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "OrderSpec" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 651 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "OrderModifier" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 656 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "OrderDirSpec" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 661 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "OrderEmptySpec" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 666 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "OrderCollationSpec" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 671 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "QuantifiedExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 676 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "QVarInDeclList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 681 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "QVarInDecl" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 686 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "TypeswitchExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 691 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "CaseClauseList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 696 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "CaseClause" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 701 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "IfExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 706 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "OrExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 711 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "AndExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 716 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "ComparisonExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 721 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "FTContainsExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 726 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "RangeExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 731 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "AdditiveExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 736 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "MultiplicativeExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 741 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "UnionExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 746 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "IntersectExceptExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 751 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "InstanceofExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 756 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "TreatExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 761 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "CastableExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 766 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "CastExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 771 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "UnaryExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 776 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "SignList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 781 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "ValueExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 786 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "ValueComp" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 791 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "NodeComp" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 796 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ValidateExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 801 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "ExtensionExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 806 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "PragmaList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 811 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "Pragma" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 816 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "PathExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 821 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "RelativePathExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 826 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "StepExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 831 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "AxisStep" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 836 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "ForwardStep" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 841 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "ForwardAxis" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 846 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "AbbrevForwardStep" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 851 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "ReverseStep" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 856 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "ReverseAxis" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 861 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "NodeTest" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 866 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "NameTest" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 871 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "Wildcard" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 876 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "FilterExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 881 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "PredicateList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 886 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "Predicate" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 891 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "PrimaryExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 896 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "Literal" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 901 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "NumericLiteral" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 906 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "VarRef" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 911 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "ParenthesizedExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 916 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "ContextItemExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 921 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderedExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 926 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "UnorderedExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 931 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "FunctionCall" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 936 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "ArgList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 941 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "Constructor" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 946 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "DirectConstructor" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 951 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "DirElemConstructor" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 956 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "DirElemContentList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 961 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "DirAttributeList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 966 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "DirAttr" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 971 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "DirAttributeValue" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 976 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "Opt_QuoteAttrContentList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 981 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "QuoteAttrContentList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 986 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "Opt_AposAttrContentList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 991 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "AposAttrContentList" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 996 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "QuoteAttrValueContent" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1001 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "AposAttrValueContent" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1006 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "DirElemContent" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1011 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "CommonContent" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1016 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "DirCommentConstructor" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1021 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "DirPIConstructor" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1026 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "CDataSection" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1031 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ComputedConstructor" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1036 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "CompDocConstructor" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1041 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CompElemConstructor" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1046 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "CompAttrConstructor" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1051 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "CompTextConstructor" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1056 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "CompCommentConstructor" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1061 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "CompPIConstructor" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1066 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "SingleType" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1071 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "TypeDeclaration" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1076 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "SequenceType" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1081 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "OccurrenceIndicator" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1086 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ItemType" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1091 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "AtomicType" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1096 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "KindTest" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1101 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "AnyKindTest" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1106 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "DocumentTest" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1111 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "TextTest" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1116 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "CommentTest" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1121 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "PITest" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1126 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "AttributeTest" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1131 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "SchemaAttributeTest" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1136 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ElementTest" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1141 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "SchemaElementTest" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1146 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "TypeName" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1151 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "TypeName_WITH_HOOK" */
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1156 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "StringLiteral" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1161 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "InsertExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1166 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DeleteExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1171 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ReplaceExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1176 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "RenameExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1181 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "TransformExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1186 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "VarNameList" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1191 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "VarNameDecl" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1196 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "TryExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1201 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "CatchListExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1206 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "CatchExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1211 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "EvalExpr" */
#line 756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1216 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 113 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}
  /* Line 547 of yacc.c.  */
#line 1297 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
#line 880 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 4:
#line 890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 901 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 7:
#line 906 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 8:
#line 918 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		;}
    break;

  case 9:
#line 923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    ;}
    break;

  case 10:
#line 933 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 11:
#line 940 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		;}
    break;

  case 12:
#line 952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 13:
#line 964 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), 
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
		;}
    break;

  case 14:
#line 976 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 15:
#line 982 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 16:
#line 988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 17:
#line 1000 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 18:
#line 1006 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 1020 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 20:
#line 1026 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 41:
#line 1094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 42:
#line 1106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 43:
#line 1111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 44:
#line 1122 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 45:
#line 1128 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 46:
#line 1140 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 47:
#line 1153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		;}
    break;

  case 48:
#line 1164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 49:
#line 1169 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 50:
#line 1181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 51:
#line 1186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 52:
#line 1197 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 53:
#line 1203 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 54:
#line 1209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 55:
#line 1215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 56:
#line 1234 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 57:
#line 1245 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 58:
#line 1256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 59:
#line 1263 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		;}
    break;

  case 60:
#line 1270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 61:
#line 1277 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 62:
#line 1290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 63:
#line 1296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 64:
#line 1311 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 65:
#line 1315 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 66:
#line 1325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 67:
#line 1331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		;}
    break;

  case 68:
#line 1338 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 69:
#line 1344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		;}
    break;

  case 70:
#line 1356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    ;}
    break;

  case 71:
#line 1363 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    ;}
    break;

  case 72:
#line 1369 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 73:
#line 1376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    ;}
    break;

  case 74:
#line 1382 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    ;}
    break;

  case 75:
#line 1386 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 76:
#line 1393 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 77:
#line 1404 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (SYMTAB ((yysemantic_stack_[(2) - (2)].sval)), NULL);
    ;}
    break;

  case 78:
#line 1408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
                               dynamic_cast<TypeDeclaration *> ((yysemantic_stack_[(3) - (3)].node)));
    ;}
    break;

  case 79:
#line 1416 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(5) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								nt->name,
								nt->type,
								(yysemantic_stack_[(5) - (5)].expr));
      delete nt;
		;}
    break;

  case 80:
#line 1425 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(4) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      delete nt;
		;}
    break;

  case 81:
#line 1432 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(6) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      delete nt;
		;}
    break;

  case 82:
#line 1442 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "hash"; ;}
    break;

  case 83:
#line 1444 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "btree"; ;}
    break;

  case 84:
#line 1451 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->create = false;
      (yyval.node) = d;
    ;}
    break;

  case 85:
#line 1457 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->create = true;
      (yyval.node) = d;
    ;}
    break;

  case 86:
#line 1466 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 87:
#line 1470 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->uniq = true;
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 88:
#line 1478 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(7) - (2)].sval)), (yysemantic_stack_[(7) - (4)].expr), "",
                          dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(7) - (6)].node)));
    ;}
    break;

  case 89:
#line 1483 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = new IndexDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(8) - (2)].sval)), (yysemantic_stack_[(8) - (4)].expr), SYMTAB ((yysemantic_stack_[(8) - (5)].strval)),
                                    dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(8) - (7)].node)));
      d->method = (yysemantic_stack_[(8) - (5)].strval);
      (yyval.node) = d;
    ;}
    break;

  case 90:
#line 1493 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 91:
#line 1497 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (1)].node))->coll = SYMTAB ((yysemantic_stack_[(3) - (3)].sval));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    ;}
    break;

  case 92:
#line 1505 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL);
    ;}
    break;

  case 93:
#line 1509 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<TypeDeclaration *> ((yysemantic_stack_[(2) - (2)].node)));
    ;}
    break;

  case 94:
#line 1516 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexFieldList *l = new IndexFieldList (LOC ((yyloc)));
      l->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
      
    ;}
    break;

  case 95:
#line 1523 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(3) - (1)].node))->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    ;}
    break;

  case 96:
#line 1533 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 97:
#line 1538 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 98:
#line 1550 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 99:
#line 1554 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 100:
#line 1558 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 101:
#line 1562 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 102:
#line 1569 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 103:
#line 1576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    ;}
    break;

  case 104:
#line 1583 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (3)].sval)), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 105:
#line 1590 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 106:
#line 1597 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *b = dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr));
      if (b == NULL) {
        b = new BlockBody ((yysemantic_stack_[(5) - (5)].expr)->get_location ()); 
        b->add ((yysemantic_stack_[(5) - (5)].expr));
      }
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), b);
    ;}
    break;

  case 107:
#line 1609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 108:
#line 1613 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 109:
#line 1620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), true);
    ;}
    break;

  case 110:
#line 1624 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), false);
    ;}
    break;

  case 111:
#line 1631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 112:
#line 1635 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->deterministic = false;
      (yyval.node) = d;
    ;}
    break;

  case 113:
#line 1641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    ;}
    break;

  case 114:
#line 1648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 115:
#line 1652 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 116:
#line 1656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    ;}
    break;

  case 117:
#line 1664 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 118:
#line 1671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 119:
#line 1680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 120:
#line 1692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 121:
#line 1706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 122:
#line 1714 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 123:
#line 1728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 124:
#line 1734 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 125:
#line 1746 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 126:
#line 1754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 127:
#line 1765 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 128:
#line 1777 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 129:
#line 1781 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(2) - (2)].expr)),
        *blk2 = new BlockBody (LOC ((yyloc)));
      blk2->add ((yysemantic_stack_[(2) - (1)].expr));
      for (int i = 0; i < blk->size (); i++)
        blk2->add ((*blk) [i]);
      (yyval.expr) = blk2;
    ;}
    break;

  case 130:
#line 1793 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    ;}
    break;

  case 131:
#line 1797 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 132:
#line 1806 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 133:
#line 1810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p == NULL) {
        expr_p = new Expr (LOC ((yyloc)));
        expr_p->push_back ((yysemantic_stack_[(3) - (1)].expr));
      }
      expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 152:
#line 1857 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 153:
#line 1866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 154:
#line 1873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    ;}
    break;

  case 155:
#line 1877 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    ;}
    break;

  case 156:
#line 1885 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    ;}
    break;

  case 157:
#line 1889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    ;}
    break;

  case 158:
#line 1893 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    ;}
    break;

  case 159:
#line 1900 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 160:
#line 1904 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 161:
#line 1911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)), dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 162:
#line 1916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    ;}
    break;

  case 163:
#line 1925 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 172:
#line 1943 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 173:
#line 1949 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 174:
#line 1958 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    ;}
    break;

  case 175:
#line 1962 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    ;}
    break;

  case 176:
#line 1972 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		;}
    break;

  case 177:
#line 1983 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 178:
#line 1989 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 179:
#line 2003 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 180:
#line 2010 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 181:
#line 2018 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 182:
#line 2027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 183:
#line 2037 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 184:
#line 2045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 185:
#line 2054 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 186:
#line 2063 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 187:
#line 2078 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 188:
#line 2090 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 189:
#line 2101 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 190:
#line 2113 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 191:
#line 2119 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 192:
#line 2131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 193:
#line 2137 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 194:
#line 2151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 195:
#line 2159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 196:
#line 2168 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 197:
#line 2176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 198:
#line 2188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 199:
#line 2194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 201:
#line 2205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, SYMTAB ((yysemantic_stack_[(2) - (2)].sval)), "", "");
    ;}
    break;

  case 202:
#line 2209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
    ;}
    break;

  case 203:
#line 2217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    ;}
    break;

  case 204:
#line 2221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    ;}
    break;

  case 206:
#line 2230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (6)].sval)));
    ;}
    break;

  case 207:
#line 2234 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 208:
#line 2238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), "");
    ;}
    break;

  case 209:
#line 2245 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::string name = SYMTAB ((yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 210:
#line 2260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 211:
#line 2268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 212:
#line 2278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 213:
#line 2284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 214:
#line 2295 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 SYMTAB ((yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 215:
#line 2301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 216:
#line 2310 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 217:
#line 2320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 218:
#line 2325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 219:
#line 2337 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 220:
#line 2343 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 221:
#line 2357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 222:
#line 2363 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 223:
#line 2375 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 224:
#line 2382 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 225:
#line 2389 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 226:
#line 2396 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 227:
#line 2403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 228:
#line 2410 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 229:
#line 2417 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 230:
#line 2430 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 231:
#line 2434 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 232:
#line 2444 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 233:
#line 2449 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 234:
#line 2460 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 235:
#line 2471 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 236:
#line 2478 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 237:
#line 2491 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 238:
#line 2498 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 239:
#line 2510 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 240:
#line 2516 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 241:
#line 2529 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 242:
#line 2536 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								SYMTAB ((yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 243:
#line 2550 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 244:
#line 2556 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 245:
#line 2568 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 246:
#line 2574 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 247:
#line 2587 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 248:
#line 2598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 249:
#line 2602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 250:
#line 2613 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 251:
#line 2617 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 252:
#line 2636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 253:
#line 2640 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 254:
#line 2648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 255:
#line 2656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 256:
#line 2664 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 257:
#line 2671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 258:
#line 2672 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 259:
#line 2680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 260:
#line 2688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 261:
#line 2696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 262:
#line 2710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 263:
#line 2714 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 264:
#line 2721 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 265:
#line 2734 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 266:
#line 2738 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 267:
#line 2749 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 268:
#line 2753 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 269:
#line 2757 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 270:
#line 2767 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 271:
#line 2771 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 272:
#line 2775 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 273:
#line 2779 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 274:
#line 2783 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 275:
#line 2793 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 276:
#line 2797 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 277:
#line 2802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 278:
#line 2813 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 279:
#line 2817 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 280:
#line 2821 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 281:
#line 2831 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 2835 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 283:
#line 2847 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 284:
#line 2851 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 285:
#line 2863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 286:
#line 2867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 287:
#line 2879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 288:
#line 2883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 289:
#line 2895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 290:
#line 2899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 291:
#line 2911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 292:
#line 2915 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 293:
#line 2919 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 294:
#line 2923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 295:
#line 2935 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 296:
#line 2939 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 297:
#line 2943 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 298:
#line 2953 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 299:
#line 2957 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 300:
#line 2961 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 301:
#line 2965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 302:
#line 2969 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 303:
#line 2973 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 304:
#line 2983 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 305:
#line 2987 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 306:
#line 2991 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 307:
#line 3001 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 308:
#line 3005 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    ;}
    break;

  case 309:
#line 3017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 310:
#line 3023 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 311:
#line 3035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 312:
#line 3041 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 313:
#line 3055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(3) - (2)].sval))),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 314:
#line 3061 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 315:
#line 3103 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 316:
#line 3107 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 317:
#line 3111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 318:
#line 3115 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 319:
#line 3127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    ;}
    break;

  case 320:
#line 3137 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 321:
#line 3148 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 322:
#line 3153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 323:
#line 3163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 324:
#line 3167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 325:
#line 3177 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 326:
#line 3183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 327:
#line 3189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 328:
#line 3195 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 329:
#line 3207 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 330:
#line 3213 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 331:
#line 3224 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 332:
#line 3228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 333:
#line 3232 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 334:
#line 3236 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 335:
#line 3240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 336:
#line 3244 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 337:
#line 3248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 338:
#line 3258 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 339:
#line 3262 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 340:
#line 3272 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 341:
#line 3278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 342:
#line 3290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 343:
#line 3294 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 344:
#line 3298 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 345:
#line 3302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 346:
#line 3306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 347:
#line 3321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 348:
#line 3325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 349:
#line 3335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 350:
#line 3339 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 351:
#line 3349 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 352:
#line 3356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 353:
#line 3363 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 354:
#line 3376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 355:
#line 3380 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 356:
#line 3392 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 357:
#line 3398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 358:
#line 3412 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 359:
#line 3423 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 360:
#line 3427 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 361:
#line 3431 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 362:
#line 3435 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 363:
#line 3439 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 364:
#line 3443 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 365:
#line 3447 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 366:
#line 3451 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 367:
#line 3461 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 368:
#line 3465 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 369:
#line 3475 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 370:
#line 3480 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 371:
#line 3485 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 372:
#line 3496 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 373:
#line 3506 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 374:
#line 3510 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 375:
#line 3521 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 376:
#line 3531 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 377:
#line 3542 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 378:
#line 3598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 379:
#line 3604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 380:
#line 3616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 381:
#line 3622 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 382:
#line 3634 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 383:
#line 3638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 384:
#line 3648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 385:
#line 3652 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 386:
#line 3656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 387:
#line 3666 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 388:
#line 3674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 389:
#line 3682 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 390:
#line 3690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 391:
#line 3698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 392:
#line 3706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 393:
#line 3721 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 394:
#line 3727 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 395:
#line 3739 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 396:
#line 3745 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 397:
#line 3758 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 400:
#line 3775 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 401:
#line 3780 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 402:
#line 3791 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 403:
#line 3795 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 404:
#line 3802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 405:
#line 3808 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 406:
#line 3814 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 407:
#line 3822 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 408:
#line 3836 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 409:
#line 3840 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 410:
#line 3847 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 411:
#line 3853 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 412:
#line 3859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 413:
#line 3867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 414:
#line 3881 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 415:
#line 3886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 416:
#line 3897 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 417:
#line 3902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 418:
#line 3913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 419:
#line 3918 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 420:
#line 3923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 421:
#line 3929 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 422:
#line 3941 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 423:
#line 3947 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 424:
#line 3952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 425:
#line 3957 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 426:
#line 3968 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 427:
#line 3973 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 428:
#line 3988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 429:
#line 3993 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 430:
#line 4010 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 431:
#line 4025 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 432:
#line 4029 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 433:
#line 4033 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 434:
#line 4037 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 435:
#line 4041 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 436:
#line 4045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 437:
#line 4055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 438:
#line 4066 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 439:
#line 4072 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 440:
#line 4078 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 441:
#line 4083 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 442:
#line 4105 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 443:
#line 4111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 444:
#line 4117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 445:
#line 4122 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 446:
#line 4133 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 447:
#line 4143 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 448:
#line 4153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 449:
#line 4159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 450:
#line 4165 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 451:
#line 4170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 452:
#line 4181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 453:
#line 4187 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 454:
#line 4199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 455:
#line 4211 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 456:
#line 4217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 457:
#line 4223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 458:
#line 4260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 459:
#line 4265 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 460:
#line 4270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 461:
#line 4281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 462:
#line 4285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 463:
#line 4289 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 464:
#line 4299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 465:
#line 4310 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 466:
#line 4314 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 467:
#line 4318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 468:
#line 4322 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 469:
#line 4326 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 470:
#line 4330 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 471:
#line 4334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 472:
#line 4338 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 473:
#line 4342 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 474:
#line 4352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 475:
#line 4362 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 476:
#line 4366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 477:
#line 4371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 478:
#line 4382 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 479:
#line 4392 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 480:
#line 4402 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 481:
#line 4406 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 482:
#line 4410 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 483:
#line 4420 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 484:
#line 4426 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 485:
#line 4432 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 486:
#line 4438 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 487:
#line 4444 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 488:
#line 4456 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 489:
#line 4467 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		;}
    break;

  case 490:
#line 4474 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
                           NULL,
                           true);
		;}
    break;

  case 491:
#line 4481 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		;}
    break;

  case 492:
#line 4488 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		;}
    break;

  case 493:
#line 4495 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 494:
#line 4502 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		;}
    break;

  case 495:
#line 4509 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 496:
#line 4522 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 497:
#line 4543 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 498:
#line 4550 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 499:
#line 4570 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 500:
#line 4610 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 501:
#line 4615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 502:
#line 4618 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 503:
#line 4626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 504:
#line 4632 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 505:
#line 4638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 506:
#line 4644 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 507:
#line 4650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 508:
#line 4657 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 509:
#line 4663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 510:
#line 4669 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 511:
#line 4675 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 512:
#line 4681 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 513:
#line 4693 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 514:
#line 4698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 515:
#line 4708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 516:
#line 4714 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 517:
#line 4726 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 518:
#line 4752 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 519:
#line 4763 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 520:
#line 4769 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 521:
#line 4782 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 522:
#line 4796 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 523:
#line 4803 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 524:
#line 4810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 525:
#line 4821 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 526:
#line 4828 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 527:
#line 4836 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(11) - (6)].sval)),
                          SYMTAB ((yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 528:
#line 4845 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(14) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(14) - (6)].sval)),
                          SYMTAB ((yysemantic_stack_[(14) - (9)].sval)),
                          SYMTAB ((yysemantic_stack_[(14) - (12)].sval)),
                          (yysemantic_stack_[(14) - (14)].expr));
    ;}
    break;

  case 530:
#line 4861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    std::string tmp = SYMTAB ((yysemantic_stack_[(1) - (1)].sval));
    for (unsigned int i = 0; i<tmp.size(); i++)
      if (tmp[i] == ':')
      {
        error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
        YYERROR;
      }
    (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval);
  ;}
    break;

  case 531:
#line 4878 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 532:
#line 4879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); ;}
    break;

  case 533:
#line 4880 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); ;}
    break;

  case 534:
#line 4881 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); ;}
    break;

  case 535:
#line 4882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); ;}
    break;

  case 536:
#line 4883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); ;}
    break;

  case 537:
#line 4884 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); ;}
    break;

  case 538:
#line 4885 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); ;}
    break;

  case 539:
#line 4886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); ;}
    break;

  case 540:
#line 4887 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); ;}
    break;

  case 541:
#line 4888 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); ;}
    break;

  case 542:
#line 4889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); ;}
    break;

  case 543:
#line 4890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); ;}
    break;

  case 544:
#line 4891 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); ;}
    break;

  case 545:
#line 4892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); ;}
    break;

  case 546:
#line 4893 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); ;}
    break;

  case 547:
#line 4894 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); ;}
    break;

  case 548:
#line 4895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); ;}
    break;

  case 549:
#line 4896 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); ;}
    break;

  case 550:
#line 4897 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); ;}
    break;

  case 551:
#line 4898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); ;}
    break;

  case 552:
#line 4899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); ;}
    break;

  case 553:
#line 4900 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); ;}
    break;

  case 554:
#line 4901 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); ;}
    break;

  case 555:
#line 4902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); ;}
    break;

  case 556:
#line 4903 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); ;}
    break;

  case 557:
#line 4904 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); ;}
    break;

  case 558:
#line 4905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); ;}
    break;

  case 559:
#line 4906 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); ;}
    break;

  case 560:
#line 4907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); ;}
    break;

  case 561:
#line 4908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); ;}
    break;

  case 562:
#line 4909 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); ;}
    break;

  case 563:
#line 4910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); ;}
    break;

  case 564:
#line 4911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); ;}
    break;

  case 565:
#line 4912 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); ;}
    break;

  case 566:
#line 4913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); ;}
    break;

  case 567:
#line 4914 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); ;}
    break;

  case 568:
#line 4915 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); ;}
    break;

  case 569:
#line 4916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); ;}
    break;

  case 570:
#line 4917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); ;}
    break;

  case 571:
#line 4918 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); ;}
    break;

  case 572:
#line 4919 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); ;}
    break;

  case 573:
#line 4920 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); ;}
    break;

  case 574:
#line 4921 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); ;}
    break;

  case 575:
#line 4922 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); ;}
    break;

  case 576:
#line 4923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); ;}
    break;

  case 577:
#line 4924 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); ;}
    break;

  case 578:
#line 4925 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); ;}
    break;

  case 579:
#line 4926 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); ;}
    break;

  case 580:
#line 4927 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); ;}
    break;

  case 581:
#line 4928 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); ;}
    break;

  case 582:
#line 4929 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); ;}
    break;

  case 583:
#line 4930 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); ;}
    break;

  case 584:
#line 4931 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); ;}
    break;

  case 585:
#line 4932 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); ;}
    break;

  case 586:
#line 4933 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); ;}
    break;

  case 587:
#line 4934 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); ;}
    break;

  case 588:
#line 4935 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); ;}
    break;

  case 589:
#line 4936 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); ;}
    break;

  case 590:
#line 4937 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); ;}
    break;

  case 591:
#line 4938 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); ;}
    break;

  case 592:
#line 4939 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); ;}
    break;

  case 593:
#line 4940 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); ;}
    break;

  case 594:
#line 4941 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); ;}
    break;

  case 595:
#line 4942 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); ;}
    break;

  case 596:
#line 4943 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); ;}
    break;

  case 597:
#line 4944 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); ;}
    break;

  case 598:
#line 4945 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); ;}
    break;

  case 599:
#line 4946 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); ;}
    break;

  case 600:
#line 4947 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); ;}
    break;

  case 601:
#line 4948 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); ;}
    break;

  case 602:
#line 4949 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); ;}
    break;

  case 603:
#line 4950 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); ;}
    break;

  case 604:
#line 4951 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); ;}
    break;

  case 605:
#line 4952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); ;}
    break;

  case 606:
#line 4953 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); ;}
    break;

  case 607:
#line 4954 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); ;}
    break;

  case 608:
#line 4955 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); ;}
    break;

  case 609:
#line 4956 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); ;}
    break;

  case 610:
#line 4957 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); ;}
    break;

  case 611:
#line 4958 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); ;}
    break;

  case 612:
#line 4959 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); ;}
    break;

  case 613:
#line 4960 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); ;}
    break;

  case 614:
#line 4961 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); ;}
    break;

  case 615:
#line 4962 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); ;}
    break;

  case 616:
#line 4963 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); ;}
    break;

  case 617:
#line 4964 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); ;}
    break;

  case 618:
#line 4965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); ;}
    break;

  case 619:
#line 4966 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); ;}
    break;

  case 620:
#line 4967 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); ;}
    break;

  case 621:
#line 4968 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); ;}
    break;

  case 622:
#line 4969 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); ;}
    break;

  case 623:
#line 4970 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); ;}
    break;

  case 624:
#line 4971 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); ;}
    break;

  case 625:
#line 4972 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); ;}
    break;

  case 626:
#line 4973 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); ;}
    break;

  case 627:
#line 4974 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); ;}
    break;

  case 628:
#line 4975 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); ;}
    break;

  case 629:
#line 4976 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); ;}
    break;

  case 630:
#line 4977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); ;}
    break;

  case 631:
#line 4978 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); ;}
    break;

  case 632:
#line 4979 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); ;}
    break;

  case 633:
#line 4980 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); ;}
    break;

  case 634:
#line 4981 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); ;}
    break;

  case 635:
#line 4982 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); ;}
    break;

  case 636:
#line 4983 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); ;}
    break;

  case 637:
#line 4984 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); ;}
    break;

  case 638:
#line 4985 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); ;}
    break;

  case 639:
#line 4986 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); ;}
    break;

  case 640:
#line 4987 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); ;}
    break;

  case 641:
#line 4988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); ;}
    break;

  case 642:
#line 4989 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); ;}
    break;

  case 643:
#line 4990 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); ;}
    break;

  case 644:
#line 4991 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); ;}
    break;

  case 645:
#line 4992 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); ;}
    break;

  case 646:
#line 4993 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); ;}
    break;

  case 647:
#line 4994 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); ;}
    break;

  case 648:
#line 4995 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); ;}
    break;

  case 649:
#line 4996 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); ;}
    break;

  case 650:
#line 4997 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); ;}
    break;

  case 651:
#line 4998 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); ;}
    break;

  case 652:
#line 4999 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); ;}
    break;

  case 653:
#line 5000 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); ;}
    break;

  case 654:
#line 5001 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); ;}
    break;

  case 655:
#line 5002 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); ;}
    break;

  case 656:
#line 5003 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); ;}
    break;

  case 657:
#line 5004 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); ;}
    break;

  case 658:
#line 5005 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); ;}
    break;

  case 659:
#line 5006 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); ;}
    break;

  case 660:
#line 5007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); ;}
    break;

  case 661:
#line 5008 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); ;}
    break;

  case 662:
#line 5009 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); ;}
    break;

  case 663:
#line 5010 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); ;}
    break;

  case 664:
#line 5011 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); ;}
    break;

  case 665:
#line 5012 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); ;}
    break;

  case 666:
#line 5013 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); ;}
    break;

  case 667:
#line 5014 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); ;}
    break;

  case 668:
#line 5015 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); ;}
    break;

  case 669:
#line 5016 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); ;}
    break;

  case 670:
#line 5017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); ;}
    break;

  case 671:
#line 5018 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); ;}
    break;

  case 672:
#line 5019 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); ;}
    break;

  case 673:
#line 5020 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); ;}
    break;

  case 674:
#line 5021 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); ;}
    break;

  case 675:
#line 5022 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); ;}
    break;

  case 676:
#line 5023 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); ;}
    break;

  case 677:
#line 5024 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); ;}
    break;

  case 678:
#line 5025 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); ;}
    break;

  case 679:
#line 5026 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); ;}
    break;

  case 680:
#line 5027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); ;}
    break;

  case 681:
#line 5028 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); ;}
    break;

  case 682:
#line 5029 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); ;}
    break;

  case 683:
#line 5030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); ;}
    break;

  case 684:
#line 5031 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); ;}
    break;

  case 685:
#line 5032 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); ;}
    break;

  case 686:
#line 5033 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); ;}
    break;

  case 687:
#line 5034 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); ;}
    break;

  case 688:
#line 5035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); ;}
    break;

  case 689:
#line 5036 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); ;}
    break;

  case 690:
#line 5037 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); ;}
    break;

  case 691:
#line 5038 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); ;}
    break;

  case 692:
#line 5039 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); ;}
    break;

  case 693:
#line 5040 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); ;}
    break;

  case 694:
#line 5041 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); ;}
    break;

  case 695:
#line 5042 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); ;}
    break;

  case 696:
#line 5043 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); ;}
    break;

  case 697:
#line 5044 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); ;}
    break;

  case 698:
#line 5045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); ;}
    break;

  case 699:
#line 5046 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("create"); ;}
    break;

  case 700:
#line 5047 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); ;}
    break;

  case 701:
#line 5048 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); ;}
    break;

  case 702:
#line 5049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("hash"); ;}
    break;

  case 703:
#line 5050 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("btree"); ;}
    break;

  case 704:
#line 5051 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("drop"); ;}
    break;

  case 705:
#line 5063 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 706:
#line 5069 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 707:
#line 5086 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 708:
#line 5090 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 709:
#line 5094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 710:
#line 5098 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 711:
#line 5108 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 712:
#line 5111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 713:
#line 5114 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 714:
#line 5117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 715:
#line 5126 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 716:
#line 5129 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 717:
#line 5138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 718:
#line 5141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 719:
#line 5150 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 720:
#line 5153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 721:
#line 5162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 722:
#line 5165 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 723:
#line 5174 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 724:
#line 5177 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 725:
#line 5180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 726:
#line 5189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 727:
#line 5192 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 728:
#line 5201 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 729:
#line 5205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 730:
#line 5215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 731:
#line 5218 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 732:
#line 5221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 733:
#line 5224 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 734:
#line 5227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 735:
#line 5236 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 736:
#line 5245 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 737:
#line 5249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 738:
#line 5253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 739:
#line 5257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 740:
#line 5261 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 741:
#line 5265 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 742:
#line 5269 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 743:
#line 5279 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 744:
#line 5282 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 745:
#line 5285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 746:
#line 5288 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 747:
#line 5297 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 748:
#line 5300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 749:
#line 5303 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 750:
#line 5306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 751:
#line 5315 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 752:
#line 5318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 753:
#line 5327 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5339 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 758:
#line 5342 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 759:
#line 5345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
		;}
    break;

  case 763:
#line 5369 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 764:
#line 5372 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 765:
#line 5375 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 766:
#line 5384 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 767:
#line 5387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 768:
#line 5390 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 769:
#line 5393 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 770:
#line 5396 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 771:
#line 5405 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 772:
#line 5408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 773:
#line 5417 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 774:
#line 5420 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 775:
#line 5429 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 776:
#line 5432 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 777:
#line 5441 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 778:
#line 5444 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 779:
#line 5453 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 780:
#line 5462 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 781:
#line 5465 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 782:
#line 5474 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 783:
#line 5477 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 784:
#line 5480 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 785:
#line 5489 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 786:
#line 5492 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 787:
#line 5495 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 788:
#line 5498 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 789:
#line 5501 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 790:
#line 5510 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 791:
#line 5514 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 792:
#line 5518 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 793:
#line 5522 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 794:
#line 5532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 795:
#line 5541 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 796:
#line 5551 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 797:
#line 5560 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 798:
#line 5563 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 799:
#line 5572 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 800:
#line 5575 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 801:
#line 5578 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 802:
#line 5587 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 803:
#line 5590 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 804:
#line 5599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6926 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -967;
  const short int
  xquery_parser::yypact_[] =
  {
      1326,  -967,  -967,  -967,  -967,   144,   201,   454,  -967,   463,
     264,   178,   371,  6253,   407,    14,   464,    40,  -967,  -967,
    -967,  -967,  -967,  -967,   397,   101,  -967,   545,   470,  -967,
     437,  -967,  -967,  -967,   482,   538,  -967,   507,    60,   585,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,   506,
     508,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  6505,  -967,  5487,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  8017,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,   546,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  1587,  8017,
    -967,  -967,  -967,  -967,  -967,  -967,   515,  -967,  -967,  -967,
    -967,   636,  -967,  6001,  -967,  -967,  -967,  -967,  -967,  8017,
    -967,  -967,  5227,  -967,  -967,  -967,  -967,  -967,  -967,   517,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,    22,   456,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,   239,   516,
     359,  -967,   448,  -102,  -967,  -967,  -967,  -967,  -967,  -967,
     553,  -967,   522,  -967,   555,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,   235,   395,  -967,  -967,  -967,  -967,  -967,  3927,   662,
    -967,  4187,  -967,  -967,   -11,  4447,   489,   493,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,   -18,  -967,  -967,
    -967,  -967,   352,  8017,  -967,  -967,  -967,  -967,  -967,   518,
     589,  -967,   608,   431,   320,   373,   -38,   383,  -967,   601,
     494,   588,   592,  4707,  -967,  -967,  -967,    12,  -967,  -967,
    5227,  -967,   385,  -967,   540,  5487,  -967,   540,  5487,  -967,
    -967,  -967,  -967,   540,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,   542,  -967,  4447,  -967,  4447,  -967,  -967,  4447,
    8017,  4447,  4447,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  4447,
    6757,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,   547,  4447,  4447,   523,  4447,   524,
    8017,   646,   647,   554,   554,   646,  8017,   180,   122,   667,
     269,   301,   561,   593,    96,   681,   408,   118,   436,   667,
    -967,  -967,  -967,  -967,  4447,  -967,  4447,    47,   567,    32,
     127,  8017,   681,  8017,  8017,  4447,   449,   450,  -967,   602,
     604,  8017,    65,  4447,  7009,   573,   571,   572,   577,   578,
     579,  -967,  -967,  -967,  8017,  -967,   455,   550,   697,  4447,
      63,  -967,   708,   556,  -967,  4447,   527,  -967,   707,  4447,
    4447,   565,  4447,  4447,  4447,  4447,   525,  8017,  4447,  8017,
     667,  -967,   667,  -967,  -967,  -967,  -967,    40,   545,   355,
    -967,  -967,   -11,     0,  4447,  -967,  4447,   584,   538,    60,
     585,   633,   587,   590,  4447,  4447,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,   648,  -967,   -20,  4967,  4967,  4967,  -967,
    4967,  4967,  -967,  4967,  -967,  4967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  4967,  4967,     8,  4967,  4967,  4967,  4967,
    4967,  4967,  4967,  4967,  4967,  4967,  4967,   530,   665,   670,
     675,  -967,  -967,  -967,  1847,  -967,  -967,  5227,  5227,  4447,
     540,  -967,  -967,   540,  -967,   540,  2107,   591,  -967,   595,
     622,  -967,   594,   596,   600,  -967,    64,   193,  2367,   605,
     606,  -967,   607,  -967,   620,  -967,  8017,  -967,  -967,  -967,
    -967,   742,  -967,  -967,  -967,  -967,  -967,  -967,   674,   677,
    -967,  -967,   386,  8017,   170,   625,   631,   667,   664,   660,
    -967,  -967,  -967,   380,    93,   382,   758,  -967,  -967,   296,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,   510,
     610,   614,   612,  -967,   613,  2627,   681,   701,   751,   681,
     667,   703,     3,  -967,   283,   671,   663,   693,  -967,   -26,
     624,  -967,  -967,  8017,     2,  -967,   619,   571,   506,  -967,
     623,   630,   635,  -967,   220,   225,  2887,    58,   667,  -967,
    8017,   697,  -967,    -7,   637,  -967,  -967,  -967,  -967,   638,
    -967,     4,  -967,  -967,  -967,    -8,   141,   711,   582,   597,
     -19,  -967,   680,   641,   321,  -967,  -967,   510,  -967,   639,
    -967,   -10,  -967,  -967,    -3,   655,  8017,  4447,   705,  -967,
    -967,   706,  7513,   709,  4447,   710,    -5,   685,   -27,   589,
    -967,  -967,  -967,  -967,  -967,  4967,  -967,  -967,  -967,  4447,
       8,   354,  -967,   562,   459,   574,   580,  -967,  -967,   576,
     273,   373,   373,     1,   -38,   -38,   -38,   -38,   383,   383,
    -967,  -967,  7513,  7513,  8017,  8017,  -967,   650,  -967,  -967,
     654,  -967,  -967,  -967,   237,  -967,   144,  4447,  -967,   731,
     686,  8017,  -967,  8017,  -967,  -967,   657,  -967,  -967,  -967,
     148,   375,   620,  -967,   147,   267,  7765,   698,  4447,  -967,
    -967,  -967,   745,   704,  4447,   667,   667,  -967,   509,   667,
    -967,  -967,   575,  -967,  -967,   581,    42,  -967,  -967,  -967,
    -967,  -967,  -967,   583,  -967,  -967,  4447,   651,   696,  -967,
    -967,  -967,   668,   720,   667,   694,   722,   757,   667,   737,
    4447,  4447,   713,   667,  4447,   740,  4447,   719,   -37,  -967,
     308,   615,  -967,  -967,   405,     2,  -967,  -967,  -967,   718,
    8017,  -967,  8017,  -967,  -967,   690,  4447,  -967,   822,  -967,
       6,  -967,    69,  -967,  -967,   828,  -967,   400,  4447,  4447,
    4447,   401,  4447,  4447,  4447,  4447,  4447,  4447,   753,  4447,
    4447,   640,   723,   754,     0,  -967,  4447,  -967,   480,   767,
    -967,  8017,   770,  -967,  8017,   725,   726,  -967,   309,  -967,
    -967,  -967,  8017,  -967,  8017,  4447,   736,  4447,  4447,    -4,
     738,  -967,   715,   700,  -967,   642,  -967,   199,  -967,   272,
     -25,   643,     8,   272,  4967,  4967,    79,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,     8,   741,   -25,  -967,   616,   820,
    -967,  -967,  -967,  -967,  -967,   755,  -967,  -967,  -967,  4447,
    -967,  -967,   716,  7261,   422,  -967,  3147,   717,   724,   756,
     727,   728,  -967,  8017,   799,   247,  -967,  -967,  4447,  -967,
     144,  -967,  -967,  -967,  -967,   421,  -967,  -967,  -967,  4447,
    -967,  -967,  -967,  -967,  -967,  -967,   626,    35,   868,  -967,
      61,  -967,  -967,    16,  4447,  3407,  -967,   667,   795,  -967,
    -967,  -967,   667,   795,  8017,  -967,  -967,  4447,   721,  -967,
    8017,  -967,  4447,  4447,   763,  4447,   761,  -967,   791,   794,
    4447,  8017,   560,   833,  -967,  -967,  -967,  3667,   732,   733,
    -967,  -967,  -967,   787,  -967,   172,  -967,  -967,   899,  -967,
    -967,  4447,  8017,  -967,  -967,   183,  -967,  -967,  -967,   734,
     689,   692,  -967,  -967,  -967,   695,   699,  -967,  -967,  -967,
    -967,  -967,   702,  8017,   744,  -967,   771,   640,  -967,  4447,
    8017,   767,  -967,   667,  -967,   513,  -967,   366,   814,  -967,
    4447,   817,   705,  -967,   748,   749,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  4447,  -967,  -967,  4447,   784,  4447,  -967,
    -967,  4967,  -967,  -967,  -967,  -967,  -967,    55,  4967,  4967,
     319,  -967,   574,  -967,  -967,   132,  4967,  -967,  -967,   580,
       8,   669,  -967,  -967,  -967,  -967,  -967,  8017,   759,    -2,
    -967,  -967,   760,  -967,  -967,  -967,  -967,  -967,   745,  7513,
     815,   843,   762,  -967,  -967,  -967,    83,   905,   906,    83,
      41,   254,   259,   792,  -967,  -967,   777,   823,  -967,   768,
     853,   667,   795,  -967,  -967,  -967,  -967,  -967,  -967,  4447,
    -967,  4447,  8017,  8017,  -967,   234,  -967,  4447,  -967,   772,
    -967,  -967,   822,  8017,   286,  -967,   774,   822,  8017,  -967,
    -967,  4447,  4447,  4447,  4447,  4447,  -967,  4447,  5747,  -967,
     775,  -967,  -967,  -967,  -967,   814,  -967,  -967,  -967,   667,
    -967,  -967,  -967,  -967,  -967,  -967,  4447,  -967,   -38,  4967,
    4967,   -38,   404,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,   856,  4447,  8017,  4447,  -967,  -967,  -967,  -967,  7513,
    -967,    35,    35,    83,  -967,  -967,  -967,    46,    83,   918,
     712,   860,  -967,   860,  -967,  4447,   262,   792,  4447,  -967,
     667,  -967,  -967,  -967,   879,  -967,  -967,  -967,  -967,    -9,
     822,  8017,  -967,   765,   822,  -967,  -967,  -967,  -967,  -967,
    -967,   276,  -967,  -967,  -967,  -967,   -38,   -38,  4967,  7513,
    -967,   779,  -967,  -967,  -967,  -967,  -967,  -967,  -967,   -25,
    -967,   287,  -967,   288,  -967,   857,   745,  4447,  -967,   291,
    -967,   795,   841,   334,    77,  -967,   769,   822,  -967,   773,
     846,   819,   -38,   783,  4447,   714,   860,  -967,  -967,   667,
    -967,  -967,  -967,  8017,  -967,  -967,   874,   441,  -967,  -967,
    -967,  -967,   793,   318,  -967,  -967,  -967,   778,  -967,  8017,
    -967,  4447,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,   303,  -967,   855,   819,  8017,  -967,
     304,   858,   819,  8017,  -967,   797,   819,  -967
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   352,   353,   531,   499,   687,   688,   691,   689,   692,
     690,   621,   545,   537,   553,   544,   535,   633,   643,   682,
     681,   683,   684,   680,   539,   541,   568,   640,   603,   597,
     642,   638,   565,   641,   697,   592,   634,   695,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   635,   549,   543,
     536,   637,   612,   542,   547,   343,   346,   611,   607,   598,
     578,   534,   333,     0,   606,   614,   622,   331,   602,   369,
     579,   580,   636,   332,   335,   599,   616,     0,   375,   341,
     371,   609,   533,   600,   601,   629,   604,   620,   628,   337,
     336,   552,   591,   631,   370,   619,   624,   538,     0,     0,
     292,   617,   627,   632,   630,   610,   685,   596,   594,   595,
     342,     0,   291,     0,   345,   344,   625,   581,   605,     0,
     334,   319,     0,   351,   626,   608,   615,   623,   618,   686,
     572,   577,   576,   575,   574,   573,   546,   593,     0,   532,
     639,   566,   672,   671,   673,   551,   550,   569,   678,   540,
     670,   675,   676,   667,   571,   613,   669,   679,   677,   668,
     570,   674,   693,   694,   696,   659,   658,   555,   548,   557,
     556,   652,   648,   563,   567,   564,   661,   662,   645,   554,
     657,   656,   653,   649,   666,   660,   655,   651,   644,   665,
     664,   650,   654,   646,   647,   558,   559,   561,   663,   560,
     562,   699,   704,   700,   698,   702,   703,   701,     0,     0,
       2,     0,     4,     6,     0,     0,     0,     0,    17,    19,
      21,    22,    23,    31,    24,    28,    29,    35,    36,    37,
      32,    33,    39,    40,    26,    25,    30,    34,   150,   149,
     146,   147,   148,   151,    27,    11,   127,   128,   132,   134,
     166,   172,     0,     0,   164,   165,   135,   136,   137,   138,
     248,   250,   252,   262,   265,   267,   270,   275,   278,   281,
     283,   285,   287,     0,   289,   295,   297,     0,   311,   296,
     315,   318,   320,   323,   325,     0,   330,   327,     0,   338,
     348,   350,   324,   354,   359,   367,   360,   361,   362,   365,
     366,   363,   364,   382,   384,   385,   386,   383,   431,   432,
     433,   434,   435,   436,   347,   473,   465,   472,   471,   470,
     467,   469,   466,   468,   368,    38,   139,   140,   142,   141,
     143,   144,   349,   145,     0,   102,     0,   107,   108,     0,
       0,     0,     0,   687,   688,   691,   692,   690,   621,   545,
     537,   553,   544,   535,   633,   539,   541,   640,   603,   642,
     697,   592,   695,   582,   583,   543,   536,   534,   604,     0,
       0,   685,   686,   532,   678,   540,   670,   676,   667,   570,
     693,   696,   699,   704,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    86,   111,   114,     0,   530,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   174,     0,
       0,     0,     0,     0,     0,     0,   537,   544,   535,   541,
     534,   339,   349,   372,     0,   373,   699,     0,   398,     0,
       0,   314,     0,     0,   317,     0,     0,   427,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     3,     1,     5,     7,     0,     0,     0,
      12,    10,    14,    15,     0,   130,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,   171,   167,   173,
     168,   170,   169,   176,   177,     0,     0,     0,     0,   306,
       0,     0,   304,     0,   257,     0,   305,   298,   303,   302,
     301,   300,   299,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   294,   293,   290,     0,   312,   316,     0,     0,     0,
     326,   356,   329,   328,   340,   355,     0,     0,   105,     0,
       0,   497,     0,     0,     0,   489,     0,     0,     0,     0,
       0,   478,     0,   479,     0,   116,     0,   117,   113,   112,
     115,     0,    96,    97,    48,    49,   529,    57,     0,     0,
      42,    43,     0,     0,     0,     0,     0,     0,     0,     0,
     500,   501,   502,     0,     0,     0,     0,   743,   744,     0,
      47,   736,   737,   738,   739,   740,   741,   742,    87,     0,
       0,     0,     0,   480,     0,     0,     0,    66,     0,     0,
       0,    58,     0,   237,     0,     0,     0,   189,   190,     0,
       0,   154,   155,     0,     0,   175,     0,     0,     0,   475,
       0,     0,     0,   483,     0,     0,     0,     0,     0,   374,
     399,   398,   395,     0,     0,   429,   428,   313,   488,     0,
     426,     0,   513,   514,   474,     0,     0,     0,     0,     0,
       0,   519,     0,     0,     0,   192,   209,   109,   110,     0,
      18,     0,    20,   133,     0,     0,     0,     0,     0,   153,
     210,     0,     0,     0,     0,     0,     0,     0,     0,   249,
     251,   255,   261,   260,   259,     0,   256,   253,   254,     0,
       0,     0,   728,   263,   707,   715,   717,   719,   721,   723,
     726,   269,   268,   266,   272,   273,   274,   271,   276,   277,
     280,   279,     0,     0,     0,     0,   309,     0,   321,   322,
       0,   357,   378,   380,     0,   103,     0,     0,   307,     0,
       0,     0,   493,     0,   490,   438,     0,   437,   446,   447,
       0,     0,     0,    46,     0,     0,     0,    74,     0,    70,
      72,    73,    77,    80,     0,     0,     0,    56,     0,     0,
     745,   746,     0,   747,   751,     0,     0,   780,   749,   750,
     779,   748,   752,     0,   759,   781,     0,     0,     0,   482,
     481,   448,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   706,
       0,     0,   156,   157,     0,   162,   496,   476,   477,     0,
       0,   486,     0,   484,   442,     0,     0,   109,   398,   396,
       0,   387,     0,   376,   377,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,   131,     0,   163,   221,   217,
     219,     0,   211,   212,     0,   538,   546,   454,   455,   461,
     462,   464,     0,   179,     0,     0,     0,     0,     0,     0,
       0,   258,     0,     0,   722,     0,   264,     0,   735,     0,
       0,     0,     0,     0,     0,     0,   708,   712,   730,   711,
     734,   732,   731,   733,     0,     0,     0,   724,   787,   785,
     789,   727,   282,   284,   286,   452,   288,   310,   358,     0,
     379,   106,     0,     0,     0,   243,     0,     0,     0,   497,
       0,     0,   439,     0,    98,     0,   121,   119,     0,   118,
       0,    54,    55,    52,    53,     0,    75,    76,    78,     0,
      79,    44,    45,    50,    51,    41,     0,     0,     0,   754,
       0,   753,   770,     0,     0,     0,   449,     0,    68,    62,
      65,    64,     0,    60,     0,   235,   239,     0,     0,   104,
       0,   194,     0,     0,     0,     0,     0,   158,     0,     0,
       0,     0,   203,     0,   200,   205,   161,     0,     0,     0,
     443,   236,   399,     0,   388,     0,   422,   419,     0,   423,
     424,     0,     0,   425,   418,     0,   393,   421,   420,     0,
       0,     0,   506,   507,   503,     0,     0,   511,   512,   508,
     517,   515,     0,     0,     0,   521,     0,   522,   523,     0,
       0,   218,   230,     0,   231,     0,   222,   223,   224,   225,
       0,   214,     0,   178,     0,     0,   458,   460,   459,   456,
     187,   188,   181,     0,   183,   180,     0,     0,     0,   729,
     725,     0,   782,   783,   803,   802,   798,     0,     0,     0,
       0,   784,   716,   797,   709,     0,     0,   714,   713,   718,
       0,     0,   788,   786,   453,   381,   308,     0,     0,     0,
     244,   440,     0,   494,   495,   498,   491,   492,   123,     0,
       0,    99,     0,   120,    71,    81,   768,     0,     0,   766,
     762,     0,     0,     0,    82,    83,     0,     0,   450,     0,
      67,     0,    61,   238,   240,    13,   191,   196,   195,     0,
     198,     0,     0,     0,   160,   201,   204,     0,   444,     0,
     487,   485,   398,     0,     0,   430,     0,   398,     0,   394,
       9,     0,     0,     0,     0,     0,   520,     0,     0,   524,
       0,   193,   234,   232,   233,   226,   227,   228,   220,     0,
     215,   213,   463,   457,   185,   182,     0,   184,   804,     0,
       0,   790,     0,   801,   800,   799,   794,   795,   710,   720,
     796,     0,     0,     0,     0,   441,   124,   100,   122,     0,
     126,     0,     0,   769,   771,   773,   775,     0,   767,     0,
       0,     0,   757,     0,   755,     0,     0,     0,     0,   451,
       0,    63,   197,   199,   208,   207,   202,   159,   445,     0,
     398,     0,   125,     0,   398,   504,   505,   509,   510,   516,
     518,     0,   705,   229,   216,   186,   792,   791,     0,     0,
     245,     0,   241,   101,   778,   777,   772,   776,   774,   763,
     764,     0,   760,     0,    94,    90,    92,     0,    88,     0,
     247,    69,     0,   408,   402,   397,     0,   398,   389,     0,
       0,     0,   793,     0,     0,     0,     0,   758,   756,     0,
      93,    95,    89,     0,   416,   410,     0,   409,   411,   417,
     414,   404,     0,   403,   405,   415,   391,     0,   390,     0,
     525,     0,   242,   765,   761,    91,   206,   401,   412,   413,
     400,   406,   407,   392,     0,   246,     0,     0,     0,   526,
       0,     0,     0,     0,   527,     0,     0,   528
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -967,  -967,   764,  -967,   750,   766,  -967,   776,  -967,   483,
     486,  -471,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -809,  -967,  -967,  -967,  -967,
      -1,   185,  -967,  -967,  -967,  -967,  -176,   563,  -328,  -967,
    -277,  -967,   202,  -967,  -721,  -967,  -967,  -967,  -967,  -967,
    -967,   238,   135,  -967,  -967,  -157,  -967,  -881,   780,   -84,
    -967,   490,  -331,  -967,  -967,  -967,  -967,   140,  -967,  -967,
     730,  -967,  -967,  -967,  -967,  -967,    94,  -465,  -613,  -967,
    -967,  -967,   -21,  -967,  -967,  -185,   -28,   -75,  -967,  -967,
    -967,   -86,  -967,  -967,   112,   -81,  -967,  -967,   -76,  -953,
    -967,   548,     5,  -967,  -967,    49,  -967,  -967,   488,   495,
    -967,  -464,  -878,   468,   102,  -514,   100,   104,  -967,  -967,
    -967,  -967,  -967,   735,  -967,  -967,  -967,  -967,  -967,   729,
    -967,  -967,  -112,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
     -24,  -191,  -967,  -967,   -17,    50,  -967,  -519,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -828,  -967,   -22,
    -967,   339,  -658,  -967,  -967,  -967,  -967,  -967,  -332,  -323,
    -966,  -751,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,   260,  -632,  -723,  -967,   231,  -108,  -689,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,   586,   598,  -473,   246,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,   -42,  -967,
    -967,   -45,  -398,  -360,   -13,  -967,   293,  -967,  -967,   103,
      90,   -94,   299,  -967,  -967,   105,  -967,  -683,  -967,  -967,
    -967,  -967,  -226,  -792,  -967,  -117,  -590,  -967,  -664,  -967,
    -967,  -967,  -967,  -903,  -967,  -967,  -967,  -967,   -82,   111,
    -967
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   988,   630,   233,   234,   779,
     780,   781,   594,   235,  1146,   236,   410,   411,  1294,  1295,
    1246,   237,   771,   238,   335,   239,   240,   241,   242,   243,
     244,   412,   413,   577,   955,   956,  1033,   959,   245,   246,
     486,   247,   248,   249,   496,   429,   834,   835,   250,   497,
     251,   499,   252,   253,   254,   503,   504,  1012,   707,   255,
     637,   684,   638,   644,  1013,  1014,  1015,   685,   500,   501,
     882,   883,  1200,   502,   879,   880,  1066,  1067,  1068,  1069,
     256,   632,   633,   257,   944,   945,   258,   259,   260,   261,
     715,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   523,   524,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   550,   551,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   754,   302,   303,   304,  1035,
     661,   662,   663,  1305,  1332,  1333,  1326,  1327,  1334,  1328,
    1036,  1037,   305,   306,  1038,   307,   308,   309,   310,   311,
     312,   313,   934,   708,   887,  1079,   888,   889,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   560,   948,
     324,   325,   326,   327,   328,   329,   330,   680,   681,   331,
    1057,  1058,   989,   418,   332,   333,   723,   916,   724,   725,
     726,   727,   728,   729,   730,   917,   918,   610,   611,   612,
     613,   614,  1291,  1292,   615,  1233,  1139,  1237,  1234,   616,
     617,   920,   931,  1100,   921,   922,   927,   923,  1216,  1096,
     906
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       384,   587,   822,   850,   981,   558,   722,   828,   559,   993,
     454,   619,   692,   890,   447,   734,   735,   736,   737,   932,
     933,   627,   631,  1111,  1034,   471,   827,   477,     4,   390,
     391,   392,   393,   394,   395,   941,  1104,   478,   691,   441,
     706,   919,   396,   456,   711,   599,   712,   713,   435,   714,
     442,   716,   586,   890,   890,   702,   703,   624,  1097,   717,
     718,   702,   635,   703,   443,   415,  1287,   622,   831,  1179,
     665,  1303,   687,   857,   688,   868,   484,  1026,  1027,   390,
     391,   392,   393,   394,   395,  1026,   448,   890,   402,   403,
    1003,   484,   396,   896,   640,   900,  1330,   819,   397,   647,
     452,   826,  1209,  1223,   898,    69,   453,   465,   851,   398,
     399,   704,   466,   400,  1196,  1197,   401,    80,  1137,   415,
     855,  1024,   426,   427,  1097,   978,   895,  1086,   672,   673,
     595,   675,   676,   677,   678,   596,   648,   683,   402,   403,
     404,    94,   979,   526,   978,   719,   533,   586,   720,   544,
     968,   386,   819,   693,   387,   534,   485,  1304,   761,  1028,
     527,  1141,   907,   699,   700,   428,   603,  1224,   546,  1210,
    1143,   875,   113,   852,   820,  1138,   626,  1029,   856,  1030,
    1026,  1027,   980,  1152,   405,  1029,  1025,  1030,  1142,   597,
    1023,  1026,  1027,   792,   858,   859,  1331,  1034,  1006,   787,
     869,   722,   722,   832,  1231,   603,  1031,  1034,  1179,   860,
      99,  1098,  1099,   705,  1031,  1004,  1288,   623,   407,   457,
    1118,   666,   861,   705,   705,   753,   111,   628,  1218,   846,
     705,   908,   817,  1108,   762,   649,   833,  1240,   416,  1133,
     505,   417,  1273,   899,   406,   705,   705,  1032,   721,   598,
     557,   901,   479,   953,   890,   408,   409,   562,   563,   340,
     847,   552,  1028,   479,   554,   138,   813,  1232,   407,   816,
     553,   629,   442,  1028,   584,   442,   555,  1098,  1099,   961,
    1029,   334,  1030,  1144,  1145,   564,  1087,   763,   947,  1239,
     950,  1029,   783,  1030,  1026,  1027,   962,   784,  1008,  1009,
     604,   569,   570,   471,   572,   408,   409,   585,   605,  1031,
     909,   910,   911,    99,   840,   341,   533,   703,   954,   842,
    1031,   606,   793,   607,    99,   534,  1026,   561,   913,   111,
     620,   939,   621,   608,  1106,   915,   609,  1330,  1324,   604,
     111,  1130,  1026,   862,   863,   582,  1034,   605,  1241,   652,
    1173,   794,   795,  1243,   796,   797,  1297,   567,   864,   583,
     606,  1178,   607,   764,   702,   664,   878,  1018,   138,  1019,
    1310,   669,   608,   893,     4,   609,  1028,   574,  1213,   138,
     872,  1316,  1316,   581,  1214,  1297,  1315,   971,   972,   702,
     841,   975,  1215,   722,  1029,   843,  1030,  1356,  1361,   963,
    1092,  1105,   487,   692,   339,   722,  1227,   940,   634,   488,
     636,   639,   489,   490,   821,   873,   964,  1131,   646,   588,
     491,   655,   336,  1031,  1242,   998,  1029,    99,  1030,  1244,
    1340,   634,  1298,  1093,   589,   748,   749,  1351,  1076,  1005,
     890,  1301,  1029,   111,  1030,  1324,  1311,   967,   459,  1026,
     460,    69,  1325,   970,   682,  1031,   686,  1317,  1318,  1063,
     747,  1322,   526,    80,  1261,   750,   590,   776,  1077,  1008,
    1009,  1031,  1010,  1357,  1362,   983,  1359,   529,  1065,   527,
     591,  1364,   138,   337,   766,  1367,  1078,    94,   703,   995,
     996,   719,   338,   999,   720,  1001,  1226,   957,   928,   929,
     408,   470,   528,   530,   535,   492,  1283,   493,   777,   943,
    1011,   342,   958,   778,  1259,  1021,   531,   536,  1094,  1263,
     930,   494,  1119,  1095,  1344,   801,   575,  1042,  1043,  1044,
     580,  1047,  1048,  1049,  1050,  1051,  1052,   414,  1054,  1055,
     890,   812,   907,   777,   385,   878,   603,   495,   778,  1029,
     532,  1030,  1329,  1335,   802,   803,  1313,   804,   805,  1348,
     547,   548,  1062,   772,  1082,  1213,  1084,  1085,   462,  1286,
     463,  1214,   845,  1063,  1286,   421,  1329,  1208,  1031,  1215,
     782,   422,  1335,  1064,  1211,  1212,  1278,   423,   533,  1150,
     890,   722,  1065,   390,   391,   392,   419,   534,   395,   420,
     751,   388,  1306,   751,   389,   751,  1309,   790,  1115,   798,
     791,   908,   799,   600,   601,   602,  1040,  1045,  1041,  1046,
     408,   409,   973,   974,  1008,  1009,  1193,  1194,   731,   732,
     830,   578,   579,   738,   739,   902,   935,   935,  1135,   740,
     741,  1284,  1285,   424,   425,   430,   431,   848,   432,  1337,
     450,   444,   449,  1147,   455,   458,   461,   464,   467,   468,
     469,   472,   474,   482,  1320,  1192,  1154,   483,   507,   506,
     525,  1157,  1158,   942,  1160,   537,   539,   538,   549,  1164,
     604,   540,   556,   877,   568,   390,   576,   586,   605,   891,
     909,   910,   911,   571,   573,  1276,  1277,   592,   593,   415,
     912,   606,   409,   607,   625,   641,   642,   643,   913,   645,
     656,   370,   387,   608,   914,   915,   609,   389,   417,   434,
     659,   658,   660,   667,   670,   508,   668,   671,  1190,   891,
     891,   891,   891,   509,   510,   674,   511,   695,   696,   878,
     679,   697,   701,   512,   698,   742,   743,   513,   949,   514,
     949,   744,  1204,  1251,   515,  1205,   745,  1207,   755,   757,
     770,   758,   773,   891,  1312,   756,   759,   760,   774,   785,
     516,   775,   767,   768,   769,   786,   788,   789,   800,   806,
     807,   808,   809,   810,   814,   815,   818,   825,   823,   836,
     824,   829,   865,   837,   517,   518,   519,   520,   521,   522,
     838,  1274,   839,   866,   853,   854,   867,   870,   871,   876,
     881,   884,   924,   874,   892,   894,   897,   937,   943,   905,
     925,   926,   938,   946,   952,   778,   702,   561,  1252,   561,
    1253,   969,   984,   985,   976,   986,  1257,   987,   990,   991,
     992,   977,   994,   982,   997,  1000,  1002,  1022,  1039,  1007,
    1265,  1266,  1267,  1268,  1269,  1017,  1270,  1020,  1053,  1060,
    1059,  1070,  1122,  1056,  1072,  1074,  1075,  1083,  1071,  1088,
    1090,   505,  1110,  1113,  1132,  1275,  1112,  1091,  1101,  1080,
    1129,  1081,  1089,  1116,  1114,  1125,  1136,  1123,  1140,  1151,
    1159,  1280,  1161,  1282,  1124,  1155,  1162,  1126,  1127,  1163,
    1167,  1149,  1170,  1171,  1172,  1175,  1181,  1063,  1180,  1182,
    1199,  1188,  1183,  1187,  1296,  1206,  1184,  1300,  1202,  1203,
     953,  1345,  1220,  1185,  1229,  1235,  1236,  1225,  1222,  1230,
     891,  1247,  1245,  1169,  1248,  1249,  1250,  1279,  1289,  1258,
    1128,  1262,  1272,   978,  1302,  1308,  1323,  1176,  1314,  1336,
    1319,  1339,  1341,  1338,  1347,  1290,   958,  1343,  1353,  1350,
    1358,   475,   966,  1363,  1134,   689,  1296,  1366,   690,  1321,
    1299,   618,   473,  1228,   960,  1016,   694,   476,  1073,  1156,
    1256,   634,   498,  1342,  1166,  1191,  1201,   639,  1061,  1198,
     480,  1195,   657,  1120,   709,   481,   733,  1271,  1165,  1153,
     849,  1352,   710,  1174,  1349,   936,   545,   965,   543,   951,
    1355,  1186,  1189,   903,  1109,  1102,  1219,  1293,   650,  1177,
     904,  1107,  1238,  1217,  1103,     0,     0,     0,     0,     0,
     651,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     682,     0,     0,     0,     0,     0,     0,   686,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   891,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1254,
    1255,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1260,     0,     0,     0,     0,  1264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   442,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1281,     0,     0,     0,     0,     0,   891,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1307,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   891,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1346,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1354,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     2,     3,  1360,     4,     0,     0,     0,
    1365,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,     0,    67,    68,
       0,     0,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,    80,     0,    81,    82,    83,
      84,     0,    85,     0,     0,     0,    86,    87,    88,    89,
      90,     0,     0,     0,     0,     0,    91,    92,    93,    94,
      95,    96,    97,     0,     0,     0,    98,    99,   100,   101,
     102,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,     0,   112,   113,     0,     0,   114,
     115,   116,     0,     0,     0,   117,     0,   118,   119,   120,
       0,   121,   122,   123,     0,   124,     0,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     0,     0,
     136,   137,   138,     0,   139,   140,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   178,   179,     0,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   354,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   357,    28,    29,   359,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,     0,     0,
     114,   115,   116,     0,     0,     0,   117,   445,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     446,   202,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   354,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   357,    28,    29,   359,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,     0,     0,
     114,   115,   116,     0,   746,     0,   117,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     446,   202,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   354,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   357,    28,    29,   359,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,     0,     0,
     114,   115,   116,     0,     0,     0,   117,   752,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     446,   202,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   354,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   357,    28,    29,   359,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,     0,     0,
     114,   115,   116,     0,   765,     0,   117,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     446,   202,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   354,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   357,    28,    29,   359,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,     0,     0,
     114,   115,   116,     0,   811,     0,   117,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     446,   202,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   354,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   357,    28,    29,   359,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,     0,     0,
     114,   115,   116,     0,   844,     0,   117,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     446,   202,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   354,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   357,    28,    29,   359,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,     0,     0,
     114,   115,   116,     0,  1121,     0,   117,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     446,   202,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   354,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   357,    28,    29,   359,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,     0,     0,
     114,   115,   116,     0,  1148,     0,   117,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     446,   202,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   354,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   357,    28,    29,   359,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,     0,     0,
     114,   115,   116,     0,  1168,     0,   117,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     446,   202,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,     0,     0,
     114,   115,   116,     0,     0,     0,   117,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   139,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,     0,     0,
     114,   115,   116,     0,     0,     0,   117,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   354,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   357,    28,    29,   359,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,     0,     0,
     114,   115,   116,     0,     0,     0,   117,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     446,   202,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,   343,   344,   345,     8,   346,   347,    11,
     349,    13,    14,    15,    16,   354,    18,    19,    20,    21,
      22,    23,   355,    25,    26,   357,   358,    29,   359,    31,
      32,    33,     0,   360,   361,    36,   362,   363,   364,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,   368,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   541,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   542,   113,     0,     0,
     114,   115,   116,     0,     0,     0,   117,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   374,   149,   376,   151,   377,
     378,   154,   155,   156,   157,   158,   159,   379,   161,   380,
     163,   381,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     382,   383,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,   343,   344,   345,     8,   346,   347,    11,
     349,    13,    14,    15,    16,   354,    18,    19,    20,    21,
      22,    23,   355,    25,    26,   357,   358,    29,   359,    31,
      32,    33,     0,   360,   361,    36,   362,   363,   364,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,   368,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,     0,     0,
     114,   115,   116,     0,     0,     0,   117,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   374,   149,   376,   151,   377,
     378,   154,   155,   156,   157,   158,   159,   379,   161,   380,
     163,   381,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     382,   383,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,   343,   344,   345,     8,   346,   347,   348,
     349,    13,    14,    15,    16,   354,    18,    19,    20,    21,
      22,    23,   355,    25,    26,   357,   358,    29,   359,    31,
      32,    33,     0,   360,   361,    36,   362,   363,   364,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,   368,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,     0,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,     0,     0,     0,     0,
     114,   115,   116,     0,     0,     0,   117,     0,   118,   119,
     120,     0,     0,     0,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   374,   149,   376,   151,   377,
     378,   154,   155,   156,   157,   158,   159,   379,   161,   380,
     163,   381,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     382,   383,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     0,     0,     0,
       0,     0,     0,   343,   344,   345,     8,   346,   347,   348,
     349,   436,   351,   437,   438,   354,    18,    19,    20,    21,
      22,    23,   355,   439,    26,   357,   358,    29,   359,    31,
      32,    33,     0,   360,   361,    36,   362,   363,   364,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,     0,     0,    57,     0,    58,    59,
      60,   440,     0,     0,    64,    65,    66,     0,     0,     0,
      68,     0,     0,     0,     0,    70,    71,    72,     0,     0,
      75,    76,     0,     0,     0,     0,     0,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,   368,    87,    88,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
       0,    95,    96,    97,     0,     0,     0,     0,     0,     0,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   371,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,   117,     0,   118,   119,
       0,     0,     0,     0,   123,     0,   124,     0,   125,   126,
     127,   128,   372,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,     0,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   374,   149,   376,   151,   377,
     378,   154,   155,   156,   157,   158,   159,   379,   161,   380,
     163,   381,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     382,   383,   203,   204,   205,   206,   207,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     0,     0,     0,
       0,     0,     0,   343,   344,   345,     8,   346,   347,   348,
     349,   350,   351,   352,   353,   354,    18,    19,    20,    21,
      22,    23,   355,   356,    26,   357,   358,    29,   359,    31,
      32,    33,     0,   360,   361,    36,   362,   363,   364,    40,
      41,    42,    43,    44,    45,    46,    47,    48,   365,   366,
      51,    52,    53,    54,     0,     0,    57,     0,    58,    59,
      60,   367,     0,     0,    64,    65,    66,     0,     0,     0,
      68,     0,     0,     0,     0,    70,    71,    72,     0,     0,
      75,    76,     0,     0,     0,     0,     0,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,   368,    87,    88,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
       0,    95,    96,    97,     0,     0,     0,     0,     0,     0,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   371,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,   117,     0,   118,     0,
       0,     0,     0,     0,   123,     0,   124,     0,   125,   126,
     127,   128,   372,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,     0,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   374,   375,   376,   151,   377,
     378,   154,   155,   156,   157,   158,   159,   379,   161,   380,
     163,   381,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     382,   383,   203,   204,   205,   206,   207,   451,     0,     3,
       0,     0,     0,     0,     0,     0,     0,   343,   344,   345,
       8,   346,   347,   348,   349,   350,   351,   352,   353,   354,
      18,    19,    20,    21,    22,    23,   355,   356,    26,   357,
     358,    29,   359,    31,    32,    33,     0,   360,   361,    36,
     362,   363,   364,    40,    41,    42,    43,    44,    45,    46,
      47,    48,   365,   366,    51,    52,    53,    54,     0,     0,
      57,     0,    58,    59,    60,   367,     0,     0,    64,    65,
      66,     0,     0,     0,    68,     0,     0,     0,     0,    70,
      71,    72,     0,     0,    75,    76,     0,     0,     0,     0,
       0,     0,    81,    82,    83,    84,     0,    85,     0,     0,
       0,   368,    87,    88,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,     0,    95,    96,    97,     0,     0,
       0,     0,     0,     0,   101,   102,     0,     0,     0,     0,
     103,   104,   105,   371,   107,   108,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,     0,     0,
     117,     0,   118,     0,     0,     0,     0,     0,     0,     0,
     124,     0,   125,   126,   127,   128,   372,   130,   131,   132,
     133,   134,   135,     0,     0,   136,   137,     0,     0,   373,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   374,
     375,   376,   151,   377,   378,   154,   155,   156,   157,   158,
     159,   379,   161,   380,   163,   381,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,     0,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   382,   383,   203,   204,   205,   206,
     207,     3,     0,     0,     0,     0,     0,     0,     0,   343,
     344,   345,     8,   346,   347,   348,   349,   350,   351,   352,
     353,   354,    18,    19,    20,    21,    22,    23,   355,   356,
      26,   357,   358,    29,   359,    31,    32,    33,     0,   360,
     361,    36,   362,   363,   364,    40,    41,    42,    43,    44,
      45,    46,    47,    48,   365,   366,    51,    52,    53,    54,
       0,     0,    57,     0,    58,    59,    60,   367,     0,     0,
      64,    65,    66,     0,     0,     0,    68,     0,     0,     0,
       0,    70,    71,    72,     0,     0,    75,    76,     0,     0,
       0,     0,     0,     0,    81,    82,    83,    84,     0,    85,
       0,     0,     0,   368,    87,    88,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,     0,    95,    96,    97,
     369,     0,     0,   370,     0,     0,   101,   102,     0,     0,
       0,     0,   103,   104,   105,   371,   107,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116,     0,
       0,     0,   117,     0,   118,     0,     0,     0,     0,     0,
       0,     0,   124,     0,   125,   126,   127,   128,   372,   130,
     131,   132,   133,   134,   135,     0,     0,   136,   137,     0,
       0,   373,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   374,   375,   376,   151,   377,   378,   154,   155,   156,
     157,   158,   159,   379,   161,   380,   163,   381,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,   179,     0,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   382,   383,   203,   204,
     205,   206,   207,     3,     0,     0,     0,     0,     0,     0,
       0,   343,   344,   345,     8,   346,   347,   348,   349,   350,
     351,   352,   353,   354,    18,    19,    20,    21,    22,    23,
     355,   356,    26,   357,   358,    29,   359,    31,    32,    33,
       0,   360,   361,    36,   362,   363,   364,    40,    41,    42,
      43,    44,    45,    46,    47,    48,   365,   366,    51,    52,
      53,    54,     0,     0,    57,     0,    58,    59,    60,   367,
       0,     0,    64,    65,    66,     0,     0,     0,    68,     0,
       0,     0,     0,    70,    71,    72,     0,     0,    75,    76,
       0,     0,     0,     0,     0,     0,    81,    82,    83,    84,
       0,    85,     0,     0,     0,   368,    87,    88,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,     0,    95,
      96,    97,   433,     0,     0,   434,     0,     0,   101,   102,
       0,     0,     0,     0,   103,   104,   105,   371,   107,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,     0,     0,     0,   117,     0,   118,     0,     0,     0,
       0,     0,     0,     0,   124,     0,   125,   126,   127,   128,
     372,   130,   131,   132,   133,   134,   135,     0,     0,   136,
     137,     0,     0,   373,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   374,   375,   376,   151,   377,   378,   154,
     155,   156,   157,   158,   159,   379,   161,   380,   163,   381,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,     0,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   382,   383,
     203,   204,   205,   206,   207,     3,     0,     0,     0,     0,
       0,     0,     0,   343,   344,   345,     8,   346,   347,   348,
     349,   350,   351,   352,   353,   354,    18,    19,    20,    21,
      22,    23,   355,   356,    26,   357,   358,    29,   359,    31,
      32,    33,     0,   360,   361,    36,   362,   363,   364,    40,
      41,    42,    43,    44,    45,    46,    47,    48,   365,   366,
      51,    52,    53,    54,     0,     0,    57,     0,    58,    59,
      60,   367,     0,     0,    64,    65,    66,     0,     0,     0,
      68,     0,     0,     0,     0,    70,    71,    72,     0,     0,
      75,    76,     0,     0,     0,     0,     0,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,   368,    87,    88,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
       0,    95,    96,    97,     0,     0,     0,     0,     0,     0,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   371,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,   117,   565,   118,     0,
       0,     0,     0,     0,   566,     0,   124,     0,   125,   126,
     127,   128,   372,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,     0,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   374,   375,   376,   151,   377,
     378,   154,   155,   156,   157,   158,   159,   379,   161,   380,
     163,   381,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     382,   383,   203,   204,   205,   206,   207,     3,     0,     0,
       0,     0,     0,     0,     0,   343,   344,   345,     8,   346,
     347,   348,   349,   350,   351,   352,   353,   354,    18,    19,
      20,    21,    22,    23,   355,   356,    26,   357,   358,    29,
     359,    31,    32,    33,     0,   360,   361,    36,   362,   363,
     364,    40,    41,    42,    43,    44,    45,    46,    47,    48,
     365,   366,    51,    52,    53,    54,     0,     0,    57,     0,
      58,    59,    60,   367,     0,     0,    64,    65,    66,     0,
       0,     0,    68,     0,     0,     0,     0,    70,    71,    72,
       0,     0,    75,    76,     0,     0,     0,     0,     0,     0,
      81,    82,    83,    84,     0,    85,     0,     0,     0,   368,
      87,    88,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,     0,    95,    96,    97,     0,     0,     0,     0,
       0,     0,   101,   102,     0,     0,     0,     0,   103,   104,
     105,   371,   107,   108,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,   117,   653,
     118,     0,     0,     0,     0,     0,   654,     0,   124,     0,
     125,   126,   127,   128,   372,   130,   131,   132,   133,   134,
     135,     0,     0,   136,   137,     0,     0,   373,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   374,   375,   376,
     151,   377,   378,   154,   155,   156,   157,   158,   159,   379,
     161,   380,   163,   381,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,   178,   179,
       0,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   382,   383,   203,   204,   205,   206,   207,     3,
       0,     0,     0,     0,     0,     0,     0,   343,   344,   345,
       8,   346,   347,   348,   349,   436,   351,   437,   438,   354,
      18,    19,    20,    21,    22,    23,   355,   439,    26,   357,
     358,    29,   359,    31,    32,    33,     0,   360,   361,    36,
     362,   363,   364,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     0,     0,
      57,     0,    58,    59,    60,   440,     0,     0,    64,    65,
      66,     0,     0,     0,    68,     0,     0,     0,     0,    70,
      71,    72,     0,     0,    75,    76,  1117,     0,     0,     0,
       0,     0,    81,    82,    83,    84,     0,    85,     0,     0,
       0,   368,    87,    88,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,     0,    95,    96,   885,     0,     0,
       0,     0,     0,     0,   101,   102,     0,     0,     0,     0,
     103,   104,   105,   371,   107,   108,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,     0,     0,
     117,     0,   118,   119,     0,     0,     0,     0,     0,     0,
     124,     0,   125,   126,   127,   128,   372,   130,   131,   132,
     133,   134,   135,     0,     0,   886,   137,     0,     0,   373,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   374,
     149,   376,   151,   377,   378,   154,   155,   156,   157,   158,
     159,   379,   161,   380,   163,   381,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,     0,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   382,   383,   203,   204,   205,   206,
     207,     3,     0,     0,     0,     0,     0,     0,     0,   343,
     344,   345,     8,   346,   347,   348,   349,   436,   351,   437,
     438,   354,    18,    19,    20,    21,    22,    23,   355,   439,
      26,   357,   358,    29,   359,    31,    32,    33,     0,   360,
     361,    36,   362,   363,   364,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
       0,     0,    57,     0,    58,    59,    60,   440,     0,     0,
      64,    65,    66,     0,     0,     0,    68,     0,     0,     0,
       0,    70,    71,    72,     0,     0,    75,    76,     0,     0,
       0,     0,     0,     0,    81,    82,    83,    84,     0,    85,
       0,     0,     0,   368,    87,    88,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,     0,    95,    96,   885,
       0,     0,     0,     0,     0,     0,   101,   102,     0,     0,
       0,     0,   103,   104,   105,   371,   107,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116,     0,
       0,     0,   117,     0,   118,   119,     0,     0,     0,     0,
       0,     0,   124,     0,   125,   126,   127,   128,   372,   130,
     131,   132,   133,   134,   135,     0,     0,   886,   137,     0,
       0,   373,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   374,   149,   376,   151,   377,   378,   154,   155,   156,
     157,   158,   159,   379,   161,   380,   163,   381,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,   179,     0,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   382,   383,   203,   204,
     205,   206,   207,     3,     0,     0,     0,     0,     0,     0,
       0,   343,   344,   345,     8,   346,   347,   348,   349,   436,
     351,   437,   438,   354,    18,    19,    20,    21,    22,    23,
     355,   439,    26,   357,   358,    29,   359,    31,    32,    33,
       0,   360,   361,    36,   362,   363,   364,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,     0,     0,    57,     0,    58,    59,    60,   440,
       0,     0,    64,    65,    66,     0,     0,     0,    68,     0,
       0,     0,     0,    70,    71,    72,     0,     0,    75,    76,
       0,     0,     0,     0,     0,     0,    81,    82,    83,    84,
       0,    85,     0,     0,     0,   368,    87,    88,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,     0,    95,
      96,   885,     0,     0,     0,     0,     0,     0,   101,   102,
       0,     0,     0,     0,   103,   104,   105,   371,   107,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,     0,     0,     0,   117,     0,   118,   119,     0,     0,
       0,     0,     0,     0,   124,     0,   125,   126,   127,   128,
     372,   130,   131,   132,   133,   134,   135,     0,     0,   136,
     137,     0,     0,   373,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   374,   149,   376,   151,   377,   378,   154,
     155,   156,   157,   158,   159,   379,   161,   380,   163,   381,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,     0,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   382,   383,
     203,   204,   205,   206,   207,     3,     0,     0,     0,     0,
       0,     0,     0,   343,   344,   345,     8,   346,   347,   348,
     349,   350,   351,   352,   353,   354,    18,    19,    20,    21,
      22,    23,   355,   356,    26,   357,   358,    29,   359,    31,
      32,    33,     0,   360,   361,    36,   362,   363,   364,    40,
      41,    42,    43,    44,    45,    46,    47,    48,   365,   366,
      51,    52,    53,    54,     0,     0,    57,     0,    58,    59,
      60,   367,     0,     0,    64,    65,    66,     0,     0,     0,
      68,     0,     0,     0,     0,    70,    71,    72,     0,     0,
      75,    76,     0,     0,     0,     0,     0,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,   368,    87,    88,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
       0,    95,    96,    97,     0,     0,     0,     0,     0,     0,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   371,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,   117,     0,   118,     0,
       0,     0,     0,     0,     0,     0,   124,     0,   125,   126,
     127,   128,   372,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,     0,     0,   373,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   374,   375,   376,   151,   377,
     378,   154,   155,   156,   157,   158,   159,   379,   161,   380,
     163,   381,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     382,   383,   203,   204,   205,   206,   207
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        13,   399,   634,   661,   796,   336,   525,   639,   339,   818,
     122,   409,   483,   702,    98,   529,   530,   531,   532,   742,
     743,   419,   420,   926,   852,   201,   639,    38,    20,    39,
      40,    41,    42,    43,    44,   756,   914,    48,    38,    63,
     505,   724,    52,    21,   508,   405,   510,   511,    61,   513,
      63,   515,    20,   742,   743,    81,    83,   417,    83,   523,
     524,    81,   422,    83,    77,    18,    20,    20,    66,  1035,
       7,    80,   470,    81,   472,    94,    94,     8,     9,    39,
      40,    41,    42,    43,    44,     8,    99,   776,    98,    99,
     127,    94,    52,   706,   425,   708,    19,    94,    58,    34,
     113,   127,    47,   105,   131,    97,   119,   209,   115,    69,
      70,   131,   214,    73,  1067,  1068,    76,   109,    83,    18,
     116,   115,    62,    63,    83,    83,   131,   131,   459,   460,
      34,   462,   463,   464,   465,    39,    71,   468,    98,    99,
     100,   133,   100,   142,    83,   137,   184,    20,   140,   137,
     782,   137,    94,   484,   140,   193,   174,   166,    94,    90,
     159,   100,    83,   494,   495,   105,    87,   169,   280,   114,
     154,   174,   160,   180,   171,   140,   144,   108,   174,   110,
       8,     9,   140,   992,   144,   108,   180,   110,   980,    93,
     848,     8,     9,   100,   202,   203,   119,  1025,   830,   597,
     219,   720,   721,   201,   121,    87,   137,  1035,  1174,   217,
     141,   236,   237,   250,   137,   828,   170,   170,   228,   197,
     943,   158,    81,   250,   250,   556,   157,   100,  1106,   171,
     250,   152,   630,   916,   170,   170,   234,  1140,   137,   960,
     253,   140,  1195,   708,   204,   250,   250,   178,   240,   153,
     334,   715,   263,   105,   943,   265,   266,   341,   342,    81,
     658,   285,    90,   263,   288,   196,   626,   184,   228,   629,
     287,   144,   285,    90,   152,   288,   293,   236,   237,   132,
     108,   137,   110,   267,   268,   369,   899,    94,   761,   248,
     763,   108,   122,   110,     8,     9,   149,   127,    64,    65,
     221,   385,   386,   479,   388,   265,   266,   185,   229,   137,
     231,   232,   233,   141,    94,   137,   184,    83,   170,    94,
     137,   242,   229,   244,   141,   193,     8,   340,   249,   157,
     414,    94,   416,   254,   255,   256,   257,    19,     4,   221,
     157,    94,     8,   202,   203,   165,  1174,   229,    94,   433,
     178,   258,   259,    94,   261,   262,    94,   370,   217,   179,
     242,   178,   244,   170,    81,   449,   697,   840,   196,   842,
      94,   455,   254,   704,    20,   257,    90,   390,   246,   196,
      59,    94,    94,   396,   252,    94,  1289,   785,   786,    81,
     170,   789,   260,   912,   108,   170,   110,    94,    94,   132,
     201,   915,    50,   874,   140,   924,  1129,   170,   421,    57,
     423,   424,    60,    61,   131,    94,   149,   170,   431,   150,
      68,   434,   221,   137,   170,   823,   108,   141,   110,   170,
    1311,   444,   170,   234,   165,   547,   548,   119,   129,   131,
    1129,  1250,   108,   157,   110,     4,   170,   778,   209,     8,
     211,    97,   118,   784,   467,   137,   469,   170,   170,    93,
     544,   170,   142,   109,   178,   549,   165,    81,   159,    64,
      65,   137,    67,   170,   170,   806,  1357,   104,   112,   159,
     179,  1362,   196,    29,   568,  1366,   177,   133,    83,   820,
     821,   137,    29,   824,   140,   826,  1128,   122,   225,   226,
     265,   266,   182,   130,   121,   153,  1229,   155,   122,    87,
     105,   140,   137,   127,  1172,   846,   143,   134,   246,  1177,
     247,   169,   100,   251,  1316,   229,   391,   858,   859,   860,
     395,   862,   863,   864,   865,   866,   867,   140,   869,   870,
    1229,   625,    83,   122,   137,   876,    87,   195,   127,   108,
     177,   110,  1303,  1304,   258,   259,  1279,   261,   262,   118,
     175,   176,    82,   576,   895,   246,   897,   898,   209,  1233,
     211,   252,   656,    93,  1238,   105,  1327,  1091,   137,   260,
     593,   144,  1333,   103,  1098,  1099,   182,   105,   184,   987,
    1279,  1110,   112,    39,    40,    41,    51,   193,    44,    54,
     550,   137,  1260,   553,   140,   555,  1264,   227,   939,   227,
     230,   152,   230,   205,   206,   207,   216,   216,   218,   218,
     265,   266,   113,   114,    64,    65,   113,   114,   526,   527,
     643,   393,   394,   533,   534,   719,   744,   745,   969,   535,
     536,  1231,  1232,   105,   137,    60,   140,   660,   140,  1307,
      14,   105,   137,   984,   137,   199,   140,   209,   105,   137,
     105,   266,     0,   174,  1296,  1063,   997,   174,    79,   151,
     239,  1002,  1003,   757,  1005,    74,    88,   183,   138,  1010,
     221,    89,   140,   696,   137,    39,    39,    20,   229,   702,
     231,   232,   233,   170,   170,  1209,  1210,   136,   105,    18,
     241,   242,   266,   244,   137,   256,   256,   105,   249,   105,
     137,   140,   140,   254,   255,   256,   257,   140,   140,   140,
     170,   266,    25,    15,   197,   117,   170,    20,  1059,   742,
     743,   744,   745,   125,   126,   170,   128,   153,   105,  1070,
     215,   154,    94,   135,   154,   215,    81,   139,   761,   141,
     763,    81,  1083,  1151,   146,  1086,    81,  1088,   167,   137,
     140,   167,    20,   776,  1278,   170,   170,   167,    94,   144,
     162,    94,   167,   167,   167,   144,   112,   117,    20,   269,
     170,   167,   170,   170,    83,    34,    83,    94,   117,   170,
     127,   167,    81,   170,   186,   187,   188,   189,   190,   191,
     170,  1199,   167,   221,   167,   167,   209,   127,   167,   154,
     105,   105,   238,   174,   105,   105,   131,   167,    87,   257,
     240,   245,   168,   137,   167,   127,    81,   840,  1159,   842,
    1161,   127,   181,   137,   259,   167,  1167,   117,   144,   117,
      83,   260,   105,   260,   131,   105,   127,    25,    20,   234,
    1181,  1182,  1183,  1184,  1185,   137,  1187,   167,   105,   105,
     137,    94,   946,   223,    94,   140,   140,   131,   881,   131,
     170,   884,   131,    53,   958,  1206,   260,   235,   235,   892,
      81,   894,   167,   167,   129,   129,   260,   170,    20,    94,
     127,  1222,   131,  1224,   170,   174,   105,   170,   170,   105,
      67,   985,   170,   170,   117,     6,   217,    93,   174,   217,
      93,   140,   217,   169,  1245,   131,   217,  1248,   170,   170,
     105,  1319,   253,   221,    81,    20,    20,   167,   169,   167,
     943,   154,   140,  1017,   111,   167,    83,    81,    20,   167,
     953,   167,   167,    83,    65,   180,   105,  1031,   169,   180,
      93,   105,   169,   180,    80,   243,   137,   243,   180,   166,
     105,   211,   777,   105,   965,   482,  1297,   170,   482,  1297,
    1247,   408,   208,  1130,   772,   835,   486,   211,   884,  1000,
    1165,   994,   252,  1314,  1012,  1060,  1072,  1000,   876,  1070,
     214,  1067,   444,   944,   506,   215,   528,  1188,  1011,   994,
     661,  1333,   507,  1025,  1327,   745,   277,   776,   273,   763,
    1341,  1053,  1057,   720,   924,   912,  1110,  1243,   432,  1032,
     721,   916,  1139,  1105,   913,    -1,    -1,    -1,    -1,    -1,
     432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1053,    -1,    -1,    -1,    -1,    -1,    -1,  1060,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1162,
    1163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1173,    -1,    -1,    -1,    -1,  1178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1223,    -1,    -1,    -1,    -1,    -1,  1229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1261,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1279,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1339,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,  1358,    20,    -1,    -1,    -1,
    1363,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    93,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    -1,   109,    -1,   111,   112,   113,
     114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,    -1,    -1,    -1,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    -1,   159,   160,    -1,    -1,   163,
     164,   165,    -1,    -1,    -1,   169,    -1,   171,   172,   173,
      -1,   175,   176,   177,    -1,   179,    -1,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
     194,   195,   196,    -1,   198,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,    -1,   239,   240,    -1,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,   164,   165,    -1,    -1,    -1,   169,   170,   171,   172,
     173,    -1,   175,   176,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,   164,   165,    -1,   167,    -1,   169,    -1,   171,   172,
     173,    -1,   175,   176,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,   164,   165,    -1,    -1,    -1,   169,   170,   171,   172,
     173,    -1,   175,   176,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,   164,   165,    -1,   167,    -1,   169,    -1,   171,   172,
     173,    -1,   175,   176,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,   164,   165,    -1,   167,    -1,   169,    -1,   171,   172,
     173,    -1,   175,   176,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,   164,   165,    -1,   167,    -1,   169,    -1,   171,   172,
     173,    -1,   175,   176,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,   164,   165,    -1,   167,    -1,   169,    -1,   171,   172,
     173,    -1,   175,   176,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,   164,   165,    -1,   167,    -1,   169,    -1,   171,   172,
     173,    -1,   175,   176,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,   164,   165,    -1,   167,    -1,   169,    -1,   171,   172,
     173,    -1,   175,   176,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,   164,   165,    -1,    -1,    -1,   169,    -1,   171,   172,
     173,    -1,   175,   176,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,   164,   165,    -1,    -1,    -1,   169,    -1,   171,   172,
     173,    -1,   175,   176,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,   164,   165,    -1,    -1,    -1,   169,    -1,   171,   172,
     173,    -1,   175,   176,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,   164,   165,    -1,    -1,    -1,   169,    -1,   171,   172,
     173,    -1,   175,   176,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,   164,   165,    -1,    -1,    -1,   169,    -1,   171,   172,
     173,    -1,   175,   176,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,   141,    -1,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,   164,   165,    -1,    -1,    -1,   169,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    79,    -1,    81,    82,
      83,    84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
      -1,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,    -1,    -1,    -1,   169,    -1,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,    -1,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    79,    -1,    81,    82,
      83,    84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
      -1,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,    -1,    -1,    -1,   169,    -1,   171,    -1,
      -1,    -1,    -1,    -1,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,    -1,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    16,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    -1,    81,    82,    83,    84,    -1,    -1,    87,    88,
      89,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,
      -1,   120,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,    -1,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,
     169,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,    -1,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,   194,   195,    -1,    -1,   198,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,    -1,
     239,   240,    -1,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,
      87,    88,    89,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,    -1,   116,
      -1,    -1,    -1,   120,   121,   122,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,    -1,   134,   135,   136,
     137,    -1,    -1,   140,    -1,    -1,   143,   144,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,
      -1,    -1,   169,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,    -1,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,   194,   195,    -1,
      -1,   198,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,    -1,   239,   240,    -1,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    79,    -1,    81,    82,    83,    84,
      -1,    -1,    87,    88,    89,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
      -1,   116,    -1,    -1,    -1,   120,   121,   122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,    -1,   134,
     135,   136,   137,    -1,    -1,   140,    -1,    -1,   143,   144,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,    -1,    -1,    -1,   169,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,    -1,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,   194,
     195,    -1,    -1,   198,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,    -1,   239,   240,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    79,    -1,    81,    82,
      83,    84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
      -1,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,    -1,    -1,    -1,   169,   170,   171,    -1,
      -1,    -1,    -1,    -1,   177,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,    -1,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    79,    -1,
      81,    82,    83,    84,    -1,    -1,    87,    88,    89,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    -1,    98,    99,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,    -1,   116,    -1,    -1,    -1,   120,
     121,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,   169,   170,
     171,    -1,    -1,    -1,    -1,    -1,   177,    -1,   179,    -1,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,   194,   195,    -1,    -1,   198,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,    -1,   239,   240,
      -1,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    -1,    81,    82,    83,    84,    -1,    -1,    87,    88,
      89,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    98,
      99,   100,    -1,    -1,   103,   104,   105,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,
      -1,   120,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,    -1,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,
     169,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
     179,    -1,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,   194,   195,    -1,    -1,   198,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,    -1,
     239,   240,    -1,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,
      87,    88,    89,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,    -1,   116,
      -1,    -1,    -1,   120,   121,   122,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,    -1,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,
      -1,    -1,   169,    -1,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,   179,    -1,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,   194,   195,    -1,
      -1,   198,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,    -1,   239,   240,    -1,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    79,    -1,    81,    82,    83,    84,
      -1,    -1,    87,    88,    89,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
      -1,   116,    -1,    -1,    -1,   120,   121,   122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,    -1,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,    -1,    -1,    -1,   169,    -1,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,   179,    -1,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,   194,
     195,    -1,    -1,   198,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,    -1,   239,   240,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    79,    -1,    81,    82,
      83,    84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
      -1,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,    -1,    -1,    -1,   169,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,    -1,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    10,    17,    18,    20,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    92,    93,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     109,   111,   112,   113,   114,   116,   120,   121,   122,   123,
     124,   130,   131,   132,   133,   134,   135,   136,   140,   141,
     142,   143,   144,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   159,   160,   163,   164,   165,   169,   171,   172,
     173,   175,   176,   177,   179,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   194,   195,   196,   198,
     199,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   239,   240,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   312,   313,   318,   320,   326,   328,   330,
     331,   332,   333,   334,   335,   343,   344,   346,   347,   348,
     353,   355,   357,   358,   359,   364,   385,   388,   391,   392,
     393,   394,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   441,   442,   443,   457,   458,   460,   461,   462,
     463,   464,   465,   466,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   485,   486,   487,   488,   489,   490,
     491,   494,   499,   500,   137,   329,   221,    29,    29,   140,
      81,   137,   140,    26,    27,    28,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    45,    46,    48,    49,    51,
      56,    57,    59,    60,    61,    71,    72,    84,   120,   137,
     140,   152,   185,   198,   208,   209,   210,   212,   213,   220,
     222,   224,   263,   264,   499,   137,   137,   140,   137,   140,
      39,    40,    41,    42,    43,    44,    52,    58,    69,    70,
      73,    76,    98,    99,   100,   144,   204,   228,   265,   266,
     321,   322,   336,   337,   140,    18,   137,   140,   498,    51,
      54,   105,   144,   105,   105,   137,    62,    63,   105,   350,
      60,   140,   140,   137,   140,   499,    34,    36,    37,    46,
      84,   425,   499,   499,   105,   170,   263,   344,   499,   137,
      14,    16,   499,   499,   417,   137,    21,   197,   199,   209,
     211,   140,   209,   211,   209,   209,   214,   105,   137,   105,
     266,   321,   266,   287,     0,   289,   290,    38,    48,   263,
     292,   343,   174,   174,    94,   174,   345,    50,    57,    60,
      61,    68,   153,   155,   169,   195,   349,   354,   355,   356,
     373,   374,   378,   360,   361,   499,   151,    79,   117,   125,
     126,   128,   135,   139,   141,   146,   162,   186,   187,   188,
     189,   190,   191,   409,   410,   239,   142,   159,   182,   104,
     130,   143,   177,   184,   193,   121,   134,    74,   183,    88,
      89,   142,   159,   408,   137,   414,   417,   175,   176,   138,
     429,   430,   425,   429,   425,   429,   140,   344,   347,   347,
     483,   499,   344,   344,   344,   170,   177,   499,   137,   344,
     344,   170,   344,   170,   499,   337,    39,   338,   336,   336,
     337,   499,   165,   179,   152,   185,    20,   497,   150,   165,
     165,   179,   136,   105,   317,    34,    39,    93,   153,   498,
     205,   206,   207,    87,   221,   229,   242,   244,   254,   257,
     512,   513,   514,   515,   516,   519,   524,   525,   322,   497,
     344,   344,    20,   170,   498,   137,   144,   497,   100,   144,
     311,   497,   386,   387,   499,   498,   499,   365,   367,   499,
     347,   256,   256,   105,   368,   105,   499,    34,    71,   170,
     481,   482,   344,   170,   177,   499,   137,   386,   266,   170,
      25,   445,   446,   447,   344,     7,   158,    15,   170,   344,
     197,    20,   347,   347,   170,   347,   347,   347,   347,   215,
     492,   493,   499,   347,   366,   372,   499,   497,   497,   294,
     295,    38,   296,   347,   346,   153,   105,   154,   154,   347,
     347,    94,    81,    83,   131,   250,   362,   363,   468,   393,
     394,   396,   396,   396,   396,   395,   396,   396,   396,   137,
     140,   240,   432,   501,   503,   504,   505,   506,   507,   508,
     509,   399,   399,   398,   400,   400,   400,   400,   401,   401,
     402,   402,   215,    81,    81,    81,   167,   344,   417,   417,
     344,   430,   170,   347,   440,   167,   170,   137,   167,   170,
     167,    94,   170,    94,   170,   167,   344,   167,   167,   167,
     140,   327,   499,    20,    94,    94,    81,   122,   127,   314,
     315,   316,   499,   122,   127,   144,   144,   497,   112,   117,
     227,   230,   100,   229,   258,   259,   261,   262,   227,   230,
      20,   229,   258,   259,   261,   262,   269,   170,   167,   170,
     170,   167,   344,   498,    83,    34,   498,   497,    83,    94,
     171,   131,   468,   117,   127,    94,   127,   363,   468,   167,
     499,    66,   201,   234,   351,   352,   170,   170,   170,   167,
      94,   170,    94,   170,   167,   344,   171,   497,   499,   446,
     447,   115,   180,   167,   167,   116,   174,    81,   202,   203,
     217,    81,   202,   203,   217,    81,   221,   209,    94,   219,
     127,   167,    59,    94,   174,   174,   154,   499,   347,   379,
     380,   105,   375,   376,   105,   136,   194,   469,   471,   472,
     473,   499,   105,   347,   105,   131,   363,   131,   131,   362,
     363,   396,   344,   501,   507,   257,   535,    83,   152,   231,
     232,   233,   241,   249,   255,   256,   502,   510,   511,   512,
     526,   529,   530,   532,   238,   240,   245,   531,   225,   226,
     247,   527,   469,   469,   467,   472,   467,   167,   168,    94,
     170,   329,   344,    87,   389,   390,   137,   483,   484,   499,
     483,   484,   167,   105,   170,   339,   340,   122,   137,   342,
     327,   132,   149,   132,   149,   471,   316,   347,   468,   127,
     347,   497,   497,   113,   114,   497,   259,   260,    83,   100,
     140,   518,   260,   347,   181,   137,   167,   117,   310,   497,
     144,   117,    83,   310,   105,   347,   347,   131,   497,   347,
     105,   347,   127,   127,   363,   131,   468,   234,    64,    65,
      67,   105,   362,   369,   370,   371,   352,   137,   483,   483,
     167,   347,    25,   447,   115,   180,     8,     9,    90,   108,
     110,   137,   178,   341,   442,   444,   455,   456,   459,    20,
     216,   218,   347,   347,   347,   216,   218,   347,   347,   347,
     347,   347,   347,   105,   347,   347,   223,   495,   496,   137,
     105,   379,    82,    93,   103,   112,   381,   382,   383,   384,
      94,   499,    94,   361,   140,   140,   129,   159,   177,   470,
     499,   499,   347,   131,   347,   347,   131,   363,   131,   167,
     170,   235,   201,   234,   246,   251,   534,    83,   236,   237,
     528,   235,   504,   534,   397,   400,   255,   510,   512,   505,
     131,   528,   260,    53,   129,   347,   167,   105,   469,   100,
     390,   167,   344,   170,   170,   129,   170,   170,   499,    81,
      94,   170,   344,   329,   315,   347,   260,    83,   140,   521,
      20,   100,   518,   154,   267,   268,   319,   347,   167,   344,
     497,    94,   310,   387,   347,   174,   367,   347,   347,   127,
     347,   131,   105,   105,   347,   499,   371,    67,   167,   344,
     170,   170,   117,   178,   444,     6,   344,   499,   178,   455,
     174,   217,   217,   217,   217,   221,   493,   169,   140,   496,
     347,   372,   497,   113,   114,   383,   384,   384,   380,    93,
     377,   376,   170,   170,   347,   347,   131,   347,   400,    47,
     114,   400,   400,   246,   252,   260,   533,   533,   397,   506,
     253,   499,   169,   105,   169,   167,   468,   469,   340,    81,
     167,   121,   184,   520,   523,    20,    20,   522,   520,   248,
     528,    94,   170,    94,   170,   140,   325,   154,   111,   167,
      83,   497,   347,   347,   499,   499,   370,   347,   167,   447,
     499,   178,   167,   447,   499,   347,   347,   347,   347,   347,
     347,   426,   167,   384,   497,   347,   400,   400,   182,    81,
     347,   499,   347,   469,   521,   521,   523,    20,   170,    20,
     243,   517,   518,   517,   323,   324,   347,    94,   170,   325,
     347,   310,    65,    80,   166,   448,   447,   499,   180,   447,
      94,   170,   400,   469,   169,   528,    94,   170,   170,    93,
     468,   323,   170,   105,     4,   118,   451,   452,   454,   456,
      19,   119,   449,   450,   453,   456,   180,   447,   180,   105,
     342,   169,   347,   243,   518,   497,   499,    80,   118,   454,
     166,   119,   453,   180,   499,   347,    94,   170,   105,   342,
     499,    94,   170,   105,   342,   499,   170,   342
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
     535,   536,   537,   538,   539
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   285,   286,   286,   287,   287,   287,   287,   288,   288,
     289,   289,   290,   291,   292,   292,   292,   293,   293,   294,
     294,   295,   295,   295,   295,   296,   296,   296,   296,   296,
     296,   297,   297,   297,   297,   297,   297,   297,   297,   298,
     298,   299,   300,   300,   301,   301,   302,   303,   304,   304,
     305,   305,   306,   306,   306,   306,   307,   308,   309,   309,
     309,   309,   310,   310,   311,   311,   312,   312,   312,   312,
     313,   314,   314,   315,   315,   315,   316,   317,   317,   318,
     318,   318,   319,   319,   320,   320,   321,   321,   322,   322,
     323,   323,   324,   324,   325,   325,   326,   326,   327,   327,
     327,   327,   328,   329,   330,   331,   332,   333,   333,   334,
     334,   335,   335,   335,   336,   336,   336,   336,   337,   337,
     338,   339,   339,   340,   340,   341,   342,   343,   344,   344,
     345,   345,   346,   346,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   348,   349,   350,   350,   351,   351,   351,   352,
     352,   353,   353,   354,   355,   355,   355,   356,   356,   356,
     356,   356,   357,   357,   358,   358,   359,   360,   360,   361,
     361,   361,   361,   361,   361,   361,   361,   362,   363,   364,
     365,   365,   366,   366,   367,   367,   367,   367,   368,   368,
     369,   369,   369,   370,   370,   370,   371,   371,   371,   372,
     373,   374,   375,   375,   376,   376,   377,   378,   378,   379,
     379,   380,   380,   381,   381,   381,   381,   381,   381,   381,
     382,   382,   383,   383,   384,   385,   385,   386,   386,   387,
     387,   388,   388,   389,   389,   390,   390,   391,   392,   392,
     393,   393,   394,   394,   394,   394,   394,   395,   394,   394,
     394,   394,   396,   396,   396,   397,   397,   398,   398,   398,
     399,   399,   399,   399,   399,   400,   400,   400,   401,   401,
     401,   402,   402,   403,   403,   404,   404,   405,   405,   406,
     406,   407,   407,   407,   407,   408,   408,   408,   409,   409,
     409,   409,   409,   409,   410,   410,   410,   411,   411,   412,
     412,   413,   413,   414,   414,   415,   415,   415,   415,   416,
     417,   417,   417,   418,   418,   419,   419,   419,   419,   420,
     420,   421,   421,   421,   421,   421,   421,   421,   422,   422,
     423,   423,   424,   424,   424,   424,   424,   425,   425,   426,
     426,   427,   427,   427,   428,   428,   429,   429,   430,   431,
     431,   431,   431,   431,   431,   431,   431,   432,   432,   433,
     433,   433,   434,   435,   435,   436,   437,   438,   439,   439,
     440,   440,   441,   441,   442,   442,   442,   443,   443,   443,
     443,   443,   443,   444,   444,   445,   445,   446,   447,   447,
     448,   448,   449,   449,   450,   450,   450,   450,   451,   451,
     452,   452,   452,   452,   453,   453,   454,   454,   455,   455,
     455,   455,   456,   456,   456,   456,   457,   457,   458,   458,
     459,   460,   460,   460,   460,   460,   460,   461,   462,   462,
     462,   462,   463,   463,   463,   463,   464,   465,   466,   466,
     466,   466,   467,   467,   468,   469,   469,   469,   470,   470,
     470,   471,   471,   471,   472,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   474,   475,   475,   475,   476,   477,
     478,   478,   478,   479,   479,   479,   479,   479,   480,   481,
     481,   481,   481,   481,   481,   481,   482,   483,   484,   485,
     486,   486,   486,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   488,   488,   489,   489,   490,   491,   492,
     492,   493,   494,   495,   495,   496,   496,   496,   496,   497,
     498,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   500,   500,   501,   501,   501,
     501,   502,   502,   502,   502,   503,   503,   504,   504,   505,
     505,   506,   506,   507,   507,   507,   508,   508,   509,   509,
     510,   510,   510,   510,   510,   511,   512,   512,   512,   512,
     512,   512,   512,   513,   513,   513,   513,   514,   514,   514,
     514,   515,   515,   516,   516,   516,   516,   516,   516,   516,
     517,   517,   518,   518,   518,   518,   519,   519,   519,   519,
     519,   520,   520,   521,   521,   522,   522,   523,   523,   524,
     525,   525,   526,   526,   526,   527,   527,   527,   527,   527,
     528,   528,   528,   528,   529,   530,   531,   532,   532,   533,
     533,   533,   534,   534,   535
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     1,     2,     4,     6,
       2,     1,     2,     6,     2,     2,     4,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     3,     3,     5,     5,     4,     3,     3,     3,
       5,     5,     5,     5,     5,     5,     4,     3,     3,     4,
       5,     6,     1,     3,     3,     3,     3,     6,     5,     8,
       4,     3,     1,     1,     1,     2,     2,     2,     3,     5,
       4,     6,     1,     1,     2,     2,     1,     2,     7,     8,
       1,     3,     1,     2,     2,     3,     3,     3,     2,     3,
       4,     5,     2,     3,     5,     3,     5,     2,     2,     3,
       3,     2,     3,     3,     1,     2,     2,     2,     4,     4,
       4,     1,     3,     2,     3,     3,     3,     1,     1,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     2,     4,
       3,     5,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     2,     1,     4,     3,
       4,     4,     5,     4,     5,     5,     6,     3,     3,     3,
       1,     4,     1,     4,     3,     4,     4,     5,     4,     5,
       1,     2,     3,     1,     2,     1,     6,     3,     3,     1,
       2,     3,     1,     3,     2,     3,     2,     3,     4,     1,
       3,     1,     2,     1,     1,     1,     2,     2,     2,     3,
       1,     1,     2,     2,     2,     5,     5,     1,     4,     3,
       4,     8,    10,     1,     2,     4,     7,     8,     1,     3,
       1,     3,     1,     3,     3,     3,     3,     0,     4,     3,
       3,     3,     1,     3,     4,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     4,     1,     4,     1,     4,     1,     4,     1,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     6,     3,
       4,     1,     2,     3,     2,     1,     2,     2,     1,     1,
       1,     3,     3,     1,     1,     1,     2,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     1,     4,     4,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     4,     5,     8,
       9,     9,    10,     1,     2,     1,     2,     6,     0,     1,
       3,     3,     0,     1,     1,     1,     2,     2,     0,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     4,     4,     5,
       6,     7,     4,     5,     6,     7,     4,     4,     4,     5,
       6,     7,     1,     2,     2,     1,     2,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     4,     3,     3,
       3,     4,     4,     3,     4,     6,     4,     6,     3,     3,
       4,     6,     6,     4,     6,     6,     4,     1,     2,     1,
       3,     3,     3,     5,     7,     7,     5,     5,     5,     7,
       7,     5,     5,     3,     3,     5,     7,     5,     7,     1,
       4,     3,     5,     1,     2,     5,     8,    11,    14,     1,
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
    "\"end of file\"", "error", "$undefined", "\"'unrecognized'\"",
  "\"'apos attribute content'\"", "\"'char literal'\"",
  "\"'char literal]]>'\"", "\"'char literal and pi end'\"",
  "\"'#charref;'\"", "\"'element content'\"", "\"'pref:*'\"",
  "\"'&entity;'\"", "\"'comment literal'\"", "\"'pi <NCName {>'\"",
  "\"'pi target'\"", "\"'pragma literal'\"", "\"'QName #)'\"",
  "\"'*:QName'\"", "\"'QName_sval'\"", "\"'quote attribute content'\"",
  "\"'STRING'\"", "\"'XML comment'\"", "\"'QName'\"", "\"'URI'\"",
  "\"'NCName'\"", "\"<blank>\"", "\"'block'\"", "\"'exit'\"",
  "\"'break'\"", "\"'loop'\"", "\"'continue'\"", "\"'while'\"",
  "\"'validate'\"", "\"'typeswitch'\"", "\"'element'\"", "\"'document'\"",
  "\"'text'\"", "\"'comment'\"", "\"'declare'\"", "\"'function'\"",
  "\"'updating'\"", "\"'sequential'\"", "\"'deterministic'\"",
  "\"'nondeterministic'\"", "\"'simple'\"", "\"'if'\"",
  "\"'processing-instruction'\"", "\"'most'\"", "\"'import'\"",
  "\"'some'\"", "\"'stable'\"", "\"'module'\"", "\"'option'\"",
  "\"'word'\"", "\"'schema'\"", "\"'space'\"", "\"'set'\"", "\"'let'\"",
  "\"'construction'\"", "\"'eval'\"", "\"'for'\"", "\"'outer'\"",
  "\"'sliding'\"", "\"'tumbling'\"", "\"'previous'\"", "\"'next'\"",
  "\"'only'\"", "\"'when'\"", "\"'count'\"", "\"'ordering'\"",
  "\"'base-uri'\"", "\"'schema-element'\"", "\"'document-node'\"",
  "\"'copy-namespaces'\"", "\"'instance'\"", "\"'schema-attribute'\"",
  "\"'boundary-space'\"", "\"'ancestor::'\"", "\"'ancestor-or-self::'\"",
  "\"'and'\"", "\"'''\"", "\"'as'\"", "\"'ascending'\"", "\"'at'\"",
  "\"'attribute'\"", "\"'attribute::'\"", "\"'@'\"", "\"'case'\"",
  "\"'castable'\"", "\"'cast'\"", "\"'CDATA[['\"", "\"']]'\"",
  "\"'child::'\"", "\"'collation'\"", "\"','\"", "\"'(:'\"", "\"':)'\"",
  "\"'DECIMAL'\"", "\"'context'\"", "\"'variable'\"", "\"'default'\"",
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
  "CtxItemDecl", "CtxItemDecl2", "CtxItemDecl3", "CtxItemDecl4",
  "VarNameAndType", "VarDecl", "IndexingMethod", "IndexDecl", "IndexDecl2",
  "IndexDeclSuffix", "IndexField", "IndexField1", "IndexFieldList",
  "ConstructionDecl", "FunctionSig", "BlockExpr", "Block", "AssignExpr",
  "ExitExpr", "WhileExpr", "FlowCtlStatement", "IndexStatement",
  "FunctionDecl", "FunctionDecl2", "FunctionDecl3", "FunctionDecl4",
  "ParamList", "Param", "EnclosedExpr", "BracedExpr", "QueryBody", "Expr",
  "ApplyExpr", "ConcatExpr", "ExprSingle", "FLWORExpr", "ReturnExpr",
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
       286,     0,    -1,   287,    -1,   270,   287,    -1,   289,    -1,
     288,   289,    -1,   290,    -1,   288,   290,    -1,   198,   199,
      20,   174,    -1,   198,   199,    20,   116,    20,   174,    -1,
     292,   343,    -1,   343,    -1,   291,   292,    -1,    51,   144,
     498,   117,   497,   174,    -1,   293,   174,    -1,   294,   174,
      -1,   293,   174,   294,   174,    -1,   295,    -1,   293,   174,
     295,    -1,   296,    -1,   294,   174,   296,    -1,   297,    -1,
     298,    -1,   299,    -1,   301,    -1,   318,    -1,   313,    -1,
     335,    -1,   302,    -1,   303,    -1,   320,    -1,   300,    -1,
     307,    -1,   308,    -1,   326,    -1,   304,    -1,   305,    -1,
     306,    -1,   486,    -1,   309,    -1,   312,    -1,    38,   144,
     498,   117,   497,    -1,    38,    76,   165,    -1,    38,    76,
     179,    -1,    38,   100,    34,   144,   497,    -1,    38,   100,
      39,   144,   497,    -1,    38,    52,   499,    20,    -1,    38,
     228,   512,    -1,    38,    69,   152,    -1,    38,    69,   185,
      -1,    38,   100,   153,   112,   113,    -1,    38,   100,   153,
     112,   114,    -1,    38,    73,   165,    94,   132,    -1,    38,
      73,   165,    94,   149,    -1,    38,    73,   150,    94,   132,
      -1,    38,    73,   150,    94,   149,    -1,    38,   100,    93,
     497,    -1,    38,    70,   497,    -1,    48,    54,   497,    -1,
      48,    54,   311,   497,    -1,    48,    54,   497,    83,   310,
      -1,    48,    54,   311,   497,    83,   310,    -1,   497,    -1,
     310,    94,   497,    -1,   144,   498,   117,    -1,   100,    34,
     144,    -1,    48,    51,   497,    -1,    48,    51,   144,   498,
     117,   497,    -1,    48,    51,   497,    83,   310,    -1,    48,
      51,   144,   498,   117,   497,    83,   310,    -1,    38,    98,
     136,   314,    -1,    81,   471,   315,    -1,   315,    -1,   316,
      -1,   122,    -1,   122,   316,    -1,   127,   347,    -1,   105,
     499,    -1,   105,   499,   468,    -1,    38,    99,   317,   127,
     347,    -1,    38,    99,   317,   122,    -1,    38,    99,   317,
     122,   127,   347,    -1,   267,    -1,   268,    -1,    38,   321,
      -1,   263,   321,    -1,   322,    -1,   265,   322,    -1,   266,
     497,   269,   347,   154,   325,   170,    -1,   266,   497,   269,
     347,   319,   154,   325,   170,    -1,   324,    -1,   324,    93,
     497,    -1,   347,    -1,   347,   468,    -1,   140,   323,    -1,
     325,    94,   323,    -1,    38,    58,   165,    -1,    38,    58,
     179,    -1,   140,   170,    -1,   140,   339,   170,    -1,   140,
     170,    81,   469,    -1,   140,   339,   170,    81,   469,    -1,
      26,   329,    -1,   137,   344,   167,    -1,    56,   105,   499,
     127,   347,    -1,    27,   221,   347,    -1,    31,   140,   347,
     170,   329,    -1,    28,    29,    -1,    30,    29,    -1,   263,
     266,   497,    -1,   264,   266,   497,    -1,    38,   336,    -1,
      38,    43,   336,    -1,    38,    42,   336,    -1,   337,    -1,
      44,   337,    -1,    40,   337,    -1,    41,   338,    -1,    39,
     499,   327,   342,    -1,    39,   499,   327,   122,    -1,    39,
     499,   327,   329,    -1,   340,    -1,   339,    94,   340,    -1,
     105,   499,    -1,   105,   499,   468,    -1,   137,   344,   167,
      -1,   137,   344,   167,    -1,   344,    -1,   346,    -1,   346,
     345,    -1,   174,    -1,   345,   346,   174,    -1,   347,    -1,
     346,    94,   347,    -1,   348,    -1,   385,    -1,   388,    -1,
     391,    -1,   392,    -1,   487,    -1,   488,    -1,   490,    -1,
     489,    -1,   491,    -1,   494,    -1,   500,    -1,   331,    -1,
     332,    -1,   333,    -1,   330,    -1,   328,    -1,   334,    -1,
     357,   349,    -1,   169,   347,    -1,    62,   256,    -1,    63,
     256,    -1,   201,    -1,   234,    -1,    66,   234,    -1,   351,
     369,    67,   347,    -1,   351,    67,   347,    -1,    60,   350,
     368,   352,   352,    -1,    60,   350,   368,   352,    -1,    68,
     105,   499,    -1,   359,    -1,   364,    -1,   353,    -1,   355,
      -1,   373,    -1,   378,    -1,   374,    -1,   354,    -1,   355,
      -1,   357,   356,    -1,    60,   105,    -1,    61,    60,   105,
      -1,   358,   360,    -1,   361,    -1,   360,    94,   105,   361,
      -1,   499,   131,   347,    -1,   499,   468,   131,   347,    -1,
     499,   362,   131,   347,    -1,   499,   468,   362,   131,   347,
      -1,   499,   363,   131,   347,    -1,   499,   468,   363,   131,
     347,    -1,   499,   362,   363,   131,   347,    -1,   499,   468,
     362,   363,   131,   347,    -1,    83,   105,   499,    -1,   250,
     105,   499,    -1,    57,   105,   365,    -1,   367,    -1,   365,
      94,   105,   367,    -1,   372,    -1,   366,    94,   105,   372,
      -1,   499,   127,   347,    -1,   499,   468,   127,   347,    -1,
     499,   363,   127,   347,    -1,   499,   468,   363,   127,   347,
      -1,   105,   499,   131,   347,    -1,   105,   499,   468,   131,
     347,    -1,   370,    -1,   105,   499,    -1,   105,   499,   370,
      -1,   362,    -1,   362,   371,    -1,   371,    -1,    64,   105,
     499,    65,   105,   499,    -1,    65,   105,   499,    -1,    64,
     105,   499,    -1,   499,    -1,   195,   347,    -1,   155,   154,
     375,    -1,   376,    -1,   375,    94,   376,    -1,   105,   499,
      -1,   105,   499,   377,    -1,    93,   497,    -1,   153,   154,
     379,    -1,    50,   153,   154,   379,    -1,   380,    -1,   379,
      94,   380,    -1,   347,    -1,   347,   381,    -1,   382,    -1,
     383,    -1,   384,    -1,   382,   383,    -1,   382,   384,    -1,
     383,   384,    -1,   382,   383,   384,    -1,    82,    -1,   103,
      -1,   112,   113,    -1,   112,   114,    -1,    93,   497,    -1,
      49,   105,   386,   171,   347,    -1,   120,   105,   386,   171,
     347,    -1,   387,    -1,   386,    94,   105,   387,    -1,   499,
     131,   347,    -1,   499,   468,   131,   347,    -1,    33,   140,
     344,   170,   389,   100,   169,   347,    -1,    33,   140,   344,
     170,   389,   100,   105,   499,   169,   347,    -1,   390,    -1,
     389,   390,    -1,    87,   469,   169,   347,    -1,    87,   105,
     499,    81,   469,   169,   347,    -1,    45,   140,   344,   170,
     181,   347,   111,   347,    -1,   393,    -1,   392,   151,   393,
      -1,   394,    -1,   393,    79,   394,    -1,   396,    -1,   396,
     409,   396,    -1,   396,   410,   396,    -1,   396,   117,   396,
      -1,   396,   146,   396,    -1,    -1,   396,   141,   395,   396,
      -1,   396,   139,   396,    -1,   396,   128,   396,    -1,   396,
     126,   396,    -1,   397,    -1,   397,   239,   501,    -1,   397,
     239,   501,   535,    -1,   398,    -1,   398,   182,   398,    -1,
     399,    -1,   398,   159,   399,    -1,   398,   142,   399,    -1,
     400,    -1,   399,   177,   400,    -1,   399,   104,   400,    -1,
     399,   130,   400,    -1,   399,   143,   400,    -1,   401,    -1,
     400,   184,   401,    -1,   400,   193,   401,    -1,   402,    -1,
     401,   134,   402,    -1,   401,   121,   402,    -1,   403,    -1,
     403,    74,   215,   469,    -1,   404,    -1,   404,   183,    81,
     469,    -1,   405,    -1,   405,    88,    81,   467,    -1,   406,
      -1,   406,    89,    81,   467,    -1,   408,    -1,   407,   408,
      -1,   159,    -1,   142,    -1,   407,   159,    -1,   407,   142,
      -1,   411,    -1,   415,    -1,   412,    -1,   186,    -1,   191,
      -1,   190,    -1,   189,    -1,   188,    -1,   187,    -1,   135,
      -1,   162,    -1,   125,    -1,    32,   137,   344,   167,    -1,
      32,    81,   483,   137,   344,   167,    -1,   413,   137,   167,
      -1,   413,   137,   344,   167,    -1,   414,    -1,   413,   414,
      -1,   160,   499,    15,    -1,   160,    16,    -1,   416,    -1,
     416,   417,    -1,   176,   417,    -1,   417,    -1,   175,    -1,
     418,    -1,   418,   175,   417,    -1,   418,   176,   417,    -1,
     419,    -1,   428,    -1,   420,    -1,   420,   429,    -1,   423,
      -1,   423,   429,    -1,   421,   425,    -1,   422,    -1,    92,
      -1,   101,    -1,    85,    -1,   173,    -1,   102,    -1,   124,
      -1,   123,    -1,   425,    -1,    86,   425,    -1,   424,   425,
      -1,   107,    -1,   156,    -1,    77,    -1,   164,    -1,   163,
      -1,    78,    -1,   473,    -1,   426,    -1,   499,    -1,   427,
      -1,   177,    -1,    10,    -1,    17,    -1,   431,    -1,   431,
     429,    -1,   430,    -1,   429,   430,    -1,   138,   344,   168,
      -1,   432,    -1,   434,    -1,   435,    -1,   436,    -1,   439,
      -1,   441,    -1,   437,    -1,   438,    -1,   433,    -1,   485,
      -1,    97,    -1,   133,    -1,   109,    -1,   105,   499,    -1,
     140,   170,    -1,   140,   344,   170,    -1,   106,    -1,   152,
     137,   344,   167,    -1,   185,   137,   344,   167,    -1,   499,
     140,   170,    -1,   499,   140,   440,   170,    -1,   347,    -1,
     440,    94,   347,    -1,   442,    -1,   460,    -1,   443,    -1,
     457,    -1,   458,    -1,   141,   499,   447,   115,    -1,   141,
     499,   445,   447,   115,    -1,   141,   499,   447,   180,   178,
     499,   447,   180,    -1,   141,   499,   447,   180,   444,   178,
     499,   447,   180,    -1,   141,   499,   445,   447,   180,   178,
     499,   447,   180,    -1,   141,   499,   445,   447,   180,   444,
     178,   499,   447,   180,    -1,   455,    -1,   444,   455,    -1,
     446,    -1,   445,   446,    -1,    25,   499,   447,   117,   447,
     448,    -1,    -1,    25,    -1,   166,   449,   166,    -1,    80,
     451,    80,    -1,    -1,   450,    -1,   119,    -1,   453,    -1,
     450,   119,    -1,   450,   453,    -1,    -1,   452,    -1,   118,
      -1,   454,    -1,   452,   118,    -1,   452,   454,    -1,    19,
      -1,   456,    -1,     4,    -1,   456,    -1,   442,    -1,     9,
      -1,   459,    -1,   456,    -1,     8,    -1,   108,    -1,   110,
      -1,   341,    -1,   196,    21,   197,    -1,   196,   197,    -1,
     157,    14,   158,    -1,   157,    14,     7,    -1,    90,     6,
      -1,   461,    -1,   462,    -1,   463,    -1,   464,    -1,   465,
      -1,   466,    -1,    35,   137,   344,   167,    -1,    34,   499,
     137,   167,    -1,    34,   499,   137,   344,   167,    -1,    34,
     137,   344,   167,   137,   167,    -1,    34,   137,   344,   167,
     137,   344,   167,    -1,    84,   499,   137,   167,    -1,    84,
     499,   137,   344,   167,    -1,    84,   137,   344,   167,   137,
     167,    -1,    84,   137,   344,   167,   137,   344,   167,    -1,
      36,   137,   344,   167,    -1,    37,   137,   344,   167,    -1,
      46,   498,   137,   167,    -1,    46,   498,   137,   344,   167,
      -1,    46,   137,   344,   167,   137,   167,    -1,    46,   137,
     344,   167,   137,   344,   167,    -1,   472,    -1,   472,   129,
      -1,    81,   469,    -1,   471,    -1,   471,   470,    -1,   194,
     140,   170,    -1,   129,    -1,   177,    -1,   159,    -1,   472,
      -1,   473,    -1,   136,   140,   170,    -1,   499,    -1,   475,
      -1,   481,    -1,   479,    -1,   482,    -1,   480,    -1,   478,
      -1,   477,    -1,   476,    -1,   474,    -1,   209,   140,   170,
      -1,    72,   140,   170,    -1,    72,   140,   481,   170,    -1,
      72,   140,   482,   170,    -1,    36,   140,   170,    -1,    37,
     140,   170,    -1,    46,   140,   170,    -1,    46,   140,   498,
     170,    -1,    46,   140,    20,   170,    -1,    84,   140,   170,
      -1,    84,   140,   499,   170,    -1,    84,   140,   499,    94,
     483,   170,    -1,    84,   140,   177,   170,    -1,    84,   140,
     177,    94,   483,   170,    -1,   172,   499,   170,    -1,    34,
     140,   170,    -1,    34,   140,   499,   170,    -1,    34,   140,
     499,    94,   483,   170,    -1,    34,   140,   499,    94,   484,
     170,    -1,    34,   140,   177,   170,    -1,    34,   140,   177,
      94,   483,   170,    -1,    34,   140,   177,    94,   484,   170,
      -1,    71,   140,   499,   170,    -1,   499,    -1,   499,   129,
      -1,    20,    -1,    38,   204,   205,    -1,    38,   204,   206,
      -1,    38,   204,   207,    -1,   210,   209,   347,   217,   347,
      -1,   210,   209,   347,    81,   216,   217,   347,    -1,   210,
     209,   347,    81,   218,   217,   347,    -1,   210,   209,   347,
     202,   347,    -1,   210,   209,   347,   203,   347,    -1,   210,
     211,   347,   217,   347,    -1,   210,   211,   347,    81,   216,
     217,   347,    -1,   210,   211,   347,    81,   218,   217,   347,
      -1,   210,   211,   347,   202,   347,    -1,   210,   211,   347,
     203,   347,    -1,   208,   209,   347,    -1,   208,   211,   347,
      -1,   213,   209,   347,   221,   347,    -1,   213,   214,   215,
     209,   347,   221,   347,    -1,   212,   209,   347,    81,   347,
      -1,   220,   105,   492,   219,   347,   169,   347,    -1,   493,
      -1,   492,    94,   105,   493,    -1,   499,   127,   347,    -1,
     222,   137,   347,   167,   495,    -1,   496,    -1,   495,   496,
      -1,   223,   140,   426,   170,   342,    -1,   223,   140,   426,
      94,   105,   499,   170,   342,    -1,   223,   140,   426,    94,
     105,   499,    94,   105,   499,   170,   342,    -1,   223,   140,
     426,    94,   105,   499,    94,   105,   499,    94,   105,   499,
     170,   342,    -1,    20,    -1,    18,    -1,    18,    -1,   198,
      -1,   112,    -1,    84,    -1,    37,    -1,    72,    -1,    34,
      -1,   136,    -1,    45,    -1,   209,    -1,    46,    -1,    75,
      -1,    71,    -1,    36,    -1,    33,    -1,   194,    -1,    76,
      -1,   228,    -1,    70,    -1,   206,    -1,   205,    -1,   130,
      -1,    35,    -1,   240,    -1,   227,    -1,   230,    -1,   229,
      -1,   257,    -1,   258,    -1,   261,    -1,   259,    -1,   262,
      -1,   233,    -1,   235,    -1,    53,    -1,   201,    -1,   234,
      -1,    47,    -1,   207,    -1,   220,    -1,   214,    -1,   186,
      -1,   191,    -1,   190,    -1,   189,    -1,   188,    -1,   187,
      -1,    83,    -1,    98,    -1,    99,    -1,   169,    -1,    60,
      -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,    65,
      -1,    66,    -1,    67,    -1,    68,    -1,   131,    -1,    57,
      -1,   195,    -1,   154,    -1,   155,    -1,   153,    -1,    50,
      -1,    82,    -1,   103,    -1,   113,    -1,   114,    -1,    93,
      -1,    49,    -1,   120,    -1,   171,    -1,    87,    -1,    81,
      -1,   181,    -1,   111,    -1,   151,    -1,    79,    -1,    74,
      -1,   215,    -1,    88,    -1,   182,    -1,   104,    -1,   143,
      -1,   184,    -1,   134,    -1,   121,    -1,    32,    -1,    89,
      -1,   183,    -1,   135,    -1,   165,    -1,   179,    -1,   144,
      -1,   122,    -1,   116,    -1,   150,    -1,   132,    -1,   149,
      -1,    38,    -1,    58,    -1,    69,    -1,   100,    -1,    73,
      -1,    52,    -1,   199,    -1,    48,    -1,    54,    -1,    51,
      -1,    39,    -1,   250,    -1,   239,    -1,   255,    -1,   256,
      -1,   232,    -1,   245,    -1,   253,    -1,   249,    -1,   231,
      -1,   244,    -1,   254,    -1,   248,    -1,   243,    -1,   242,
      -1,   226,    -1,   225,    -1,   247,    -1,   236,    -1,   237,
      -1,   260,    -1,   252,    -1,   251,    -1,   246,    -1,   213,
      -1,   219,    -1,   216,    -1,   210,    -1,   203,    -1,   202,
      -1,   204,    -1,   221,    -1,   211,    -1,   212,    -1,   218,
      -1,   208,    -1,   217,    -1,    44,    -1,    41,    -1,    40,
      -1,    42,    -1,    43,    -1,   152,    -1,   185,    -1,    26,
      -1,    27,    -1,    29,    -1,    31,    -1,    28,    -1,    30,
      -1,   222,    -1,   223,    -1,    59,    -1,   224,    -1,    56,
      -1,   266,    -1,   263,    -1,   265,    -1,   269,    -1,   267,
      -1,   268,    -1,   264,    -1,   224,   105,   366,    59,   137,
     347,   167,    -1,    59,   137,   347,   167,    -1,   503,    -1,
     503,   502,    -1,   503,   255,   397,    -1,   503,   502,   255,
     397,    -1,   512,    -1,   510,    -1,   502,   512,    -1,   502,
     510,    -1,   504,    -1,   503,   241,   504,    -1,   505,    -1,
     504,   238,   505,    -1,   506,    -1,   505,   240,   131,   506,
      -1,   507,    -1,   240,   507,    -1,   508,    -1,   508,   531,
      -1,   140,   501,   170,    -1,   509,    -1,   509,   527,    -1,
     432,    -1,   137,   344,   167,    -1,   511,    -1,   530,    -1,
     529,    -1,   532,    -1,   526,    -1,   152,    -1,   513,    -1,
     514,    -1,   515,    -1,   516,    -1,   519,    -1,   524,    -1,
     525,    -1,   244,    -1,   254,    -1,    87,   227,    -1,    87,
     230,    -1,   221,   229,    -1,   257,   229,    -1,   229,   227,
      -1,   229,   230,    -1,   221,   258,    -1,   257,   258,    -1,
     221,   261,   518,    -1,   221,   261,   100,    -1,   221,   261,
     140,   518,   170,    -1,   221,   261,   140,   518,    94,   517,
     170,    -1,   221,   261,   140,   100,   170,    -1,   221,   261,
     140,   100,    94,   517,   170,    -1,   257,   261,    -1,   518,
      -1,   517,    94,   518,    -1,    83,    20,    -1,    83,    20,
     248,    20,    -1,    83,    20,   528,   243,    -1,    83,    20,
     248,    20,   528,   243,    -1,   221,   259,   260,   521,    -1,
     221,   259,   260,   521,   520,    -1,   221,   100,   259,   260,
      -1,   221,   100,   259,   260,   520,    -1,   257,   259,   260,
      -1,   523,    -1,   520,   523,    -1,    83,    20,    -1,   140,
     522,   170,    -1,    20,    -1,   522,    20,    -1,   184,   521,
      -1,   121,   521,    -1,   242,    20,    -1,   221,   262,    -1,
     257,   262,    -1,    83,   201,    -1,    83,   234,    -1,   233,
     235,    -1,   226,    -1,   226,    53,    -1,   225,    -1,   225,
     260,    -1,   247,    -1,   236,   400,    -1,    83,   114,   400,
      -1,    83,    47,   400,    -1,   237,   400,   182,   400,    -1,
     232,   528,   533,    -1,   256,   400,   533,    -1,   245,   528,
     253,    -1,   249,   534,    -1,   231,   534,    -1,   260,    -1,
     252,    -1,   246,    -1,   251,    -1,   246,    -1,   257,   235,
     400,    -1
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
     106,   108,   114,   118,   122,   128,   134,   139,   143,   147,
     151,   157,   163,   169,   175,   181,   187,   192,   196,   200,
     205,   211,   218,   220,   224,   228,   232,   236,   243,   249,
     258,   263,   267,   269,   271,   273,   276,   279,   282,   286,
     292,   297,   304,   306,   308,   311,   314,   316,   319,   327,
     336,   338,   342,   344,   347,   350,   354,   358,   362,   365,
     369,   374,   380,   383,   387,   393,   397,   403,   406,   409,
     413,   417,   420,   424,   428,   430,   433,   436,   439,   444,
     449,   454,   456,   460,   463,   467,   471,   475,   477,   479,
     482,   484,   488,   490,   494,   496,   498,   500,   502,   504,
     506,   508,   510,   512,   514,   516,   518,   520,   522,   524,
     526,   528,   530,   533,   536,   539,   542,   544,   546,   549,
     554,   558,   564,   569,   573,   575,   577,   579,   581,   583,
     585,   587,   589,   591,   594,   597,   601,   604,   606,   611,
     615,   620,   625,   631,   636,   642,   648,   655,   659,   663,
     667,   669,   674,   676,   681,   685,   690,   695,   701,   706,
     712,   714,   717,   721,   723,   726,   728,   735,   739,   743,
     745,   748,   752,   754,   758,   761,   765,   768,   772,   777,
     779,   783,   785,   788,   790,   792,   794,   797,   800,   803,
     807,   809,   811,   814,   817,   820,   826,   832,   834,   839,
     843,   848,   857,   868,   870,   873,   878,   886,   895,   897,
     901,   903,   907,   909,   913,   917,   921,   925,   926,   931,
     935,   939,   943,   945,   949,   954,   956,   960,   962,   966,
     970,   972,   976,   980,   984,   988,   990,   994,   998,  1000,
    1004,  1008,  1010,  1015,  1017,  1022,  1024,  1029,  1031,  1036,
    1038,  1041,  1043,  1045,  1048,  1051,  1053,  1055,  1057,  1059,
    1061,  1063,  1065,  1067,  1069,  1071,  1073,  1075,  1080,  1087,
    1091,  1096,  1098,  1101,  1105,  1108,  1110,  1113,  1116,  1118,
    1120,  1122,  1126,  1130,  1132,  1134,  1136,  1139,  1141,  1144,
    1147,  1149,  1151,  1153,  1155,  1157,  1159,  1161,  1163,  1165,
    1168,  1171,  1173,  1175,  1177,  1179,  1181,  1183,  1185,  1187,
    1189,  1191,  1193,  1195,  1197,  1199,  1202,  1204,  1207,  1211,
    1213,  1215,  1217,  1219,  1221,  1223,  1225,  1227,  1229,  1231,
    1233,  1235,  1237,  1240,  1243,  1247,  1249,  1254,  1259,  1263,
    1268,  1270,  1274,  1276,  1278,  1280,  1282,  1284,  1289,  1295,
    1304,  1314,  1324,  1335,  1337,  1340,  1342,  1345,  1352,  1353,
    1355,  1359,  1363,  1364,  1366,  1368,  1370,  1373,  1376,  1377,
    1379,  1381,  1383,  1386,  1389,  1391,  1393,  1395,  1397,  1399,
    1401,  1403,  1405,  1407,  1409,  1411,  1413,  1417,  1420,  1424,
    1428,  1431,  1433,  1435,  1437,  1439,  1441,  1443,  1448,  1453,
    1459,  1466,  1474,  1479,  1485,  1492,  1500,  1505,  1510,  1515,
    1521,  1528,  1536,  1538,  1541,  1544,  1546,  1549,  1553,  1555,
    1557,  1559,  1561,  1563,  1567,  1569,  1571,  1573,  1575,  1577,
    1579,  1581,  1583,  1585,  1587,  1591,  1595,  1600,  1605,  1609,
    1613,  1617,  1622,  1627,  1631,  1636,  1643,  1648,  1655,  1659,
    1663,  1668,  1675,  1682,  1687,  1694,  1701,  1706,  1708,  1711,
    1713,  1717,  1721,  1725,  1731,  1739,  1747,  1753,  1759,  1765,
    1773,  1781,  1787,  1793,  1797,  1801,  1807,  1815,  1821,  1829,
    1831,  1836,  1840,  1846,  1848,  1851,  1857,  1866,  1878,  1893,
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
    2095,  2097,  2099,  2101,  2103,  2105,  2107,  2109,  2111,  2113,
    2115,  2117,  2119,  2121,  2123,  2125,  2127,  2129,  2131,  2133,
    2135,  2137,  2139,  2141,  2143,  2145,  2147,  2149,  2151,  2153,
    2155,  2157,  2159,  2161,  2163,  2165,  2167,  2169,  2171,  2173,
    2175,  2177,  2179,  2181,  2183,  2185,  2187,  2189,  2191,  2193,
    2195,  2197,  2199,  2201,  2203,  2205,  2207,  2209,  2211,  2213,
    2215,  2217,  2219,  2221,  2223,  2225,  2227,  2229,  2231,  2233,
    2235,  2237,  2239,  2241,  2243,  2245,  2253,  2258,  2260,  2263,
    2267,  2272,  2274,  2276,  2279,  2282,  2284,  2288,  2290,  2294,
    2296,  2301,  2303,  2306,  2308,  2311,  2315,  2317,  2320,  2322,
    2326,  2328,  2330,  2332,  2334,  2336,  2338,  2340,  2342,  2344,
    2346,  2348,  2350,  2352,  2354,  2356,  2359,  2362,  2365,  2368,
    2371,  2374,  2377,  2380,  2384,  2388,  2394,  2402,  2408,  2416,
    2419,  2421,  2425,  2428,  2433,  2438,  2445,  2450,  2456,  2461,
    2467,  2471,  2473,  2476,  2479,  2483,  2485,  2488,  2491,  2494,
    2497,  2500,  2503,  2506,  2509,  2512,  2514,  2517,  2519,  2522,
    2524,  2527,  2531,  2535,  2540,  2544,  2548,  2552,  2555,  2558,
    2560,  2562,  2564,  2566,  2568
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   878,   878,   879,   889,   894,   900,   905,   917,   922,
     932,   939,   951,   963,   975,   981,   987,   999,  1005,  1019,
    1025,  1039,  1040,  1041,  1042,  1048,  1049,  1050,  1051,  1054,
    1057,  1064,  1065,  1066,  1067,  1068,  1069,  1070,  1073,  1080,
    1081,  1093,  1105,  1110,  1121,  1127,  1139,  1152,  1163,  1168,
    1180,  1185,  1196,  1202,  1208,  1214,  1233,  1244,  1255,  1262,
    1269,  1276,  1289,  1295,  1310,  1314,  1324,  1330,  1337,  1343,
    1355,  1362,  1368,  1375,  1381,  1385,  1392,  1403,  1407,  1415,
    1424,  1431,  1441,  1443,  1450,  1456,  1465,  1469,  1477,  1482,
    1492,  1496,  1504,  1508,  1515,  1522,  1532,  1537,  1549,  1553,
    1557,  1561,  1568,  1575,  1582,  1589,  1596,  1608,  1612,  1619,
    1623,  1630,  1634,  1640,  1647,  1651,  1655,  1663,  1670,  1679,
    1691,  1705,  1713,  1727,  1733,  1745,  1753,  1764,  1776,  1780,
    1792,  1796,  1805,  1809,  1825,  1826,  1827,  1828,  1829,  1832,
    1833,  1834,  1835,  1836,  1838,  1839,  1842,  1843,  1844,  1845,
    1846,  1849,  1856,  1865,  1872,  1876,  1884,  1888,  1892,  1899,
    1903,  1910,  1915,  1924,  1933,  1934,  1935,  1939,  1939,  1939,
    1939,  1939,  1942,  1948,  1957,  1961,  1971,  1982,  1988,  2002,
    2009,  2017,  2026,  2036,  2044,  2053,  2062,  2077,  2089,  2100,
    2112,  2118,  2130,  2136,  2150,  2158,  2167,  2175,  2187,  2193,
    2203,  2204,  2208,  2216,  2220,  2225,  2229,  2233,  2237,  2244,
    2259,  2267,  2277,  2283,  2294,  2300,  2309,  2319,  2324,  2336,
    2342,  2356,  2362,  2374,  2381,  2388,  2395,  2402,  2409,  2416,
    2429,  2433,  2443,  2448,  2459,  2470,  2477,  2490,  2497,  2509,
    2515,  2528,  2535,  2549,  2555,  2567,  2573,  2586,  2597,  2601,
    2612,  2616,  2635,  2639,  2647,  2655,  2663,  2671,  2671,  2679,
    2687,  2695,  2709,  2713,  2720,  2733,  2737,  2748,  2752,  2756,
    2766,  2770,  2774,  2778,  2782,  2792,  2796,  2801,  2812,  2816,
    2820,  2830,  2834,  2846,  2850,  2862,  2866,  2878,  2882,  2894,
    2898,  2910,  2914,  2918,  2922,  2934,  2938,  2942,  2952,  2956,
    2960,  2964,  2968,  2972,  2982,  2986,  2990,  3000,  3004,  3016,
    3022,  3034,  3040,  3054,  3061,  3102,  3106,  3110,  3114,  3126,
    3136,  3147,  3152,  3162,  3166,  3176,  3182,  3188,  3194,  3206,
    3212,  3223,  3227,  3231,  3235,  3239,  3243,  3247,  3257,  3261,
    3271,  3277,  3289,  3293,  3297,  3301,  3305,  3320,  3324,  3334,
    3338,  3348,  3355,  3362,  3375,  3379,  3391,  3397,  3411,  3422,
    3426,  3430,  3434,  3438,  3442,  3446,  3450,  3460,  3464,  3474,
    3479,  3484,  3495,  3505,  3509,  3520,  3530,  3541,  3597,  3603,
    3615,  3621,  3633,  3637,  3647,  3651,  3655,  3665,  3673,  3681,
    3689,  3697,  3705,  3720,  3726,  3738,  3744,  3757,  3766,  3768,
    3774,  3779,  3791,  3794,  3801,  3807,  3813,  3821,  3836,  3839,
    3846,  3852,  3858,  3866,  3880,  3885,  3896,  3901,  3912,  3917,
    3922,  3928,  3940,  3946,  3951,  3956,  3967,  3972,  3987,  3992,
    4009,  4024,  4028,  4032,  4036,  4040,  4044,  4054,  4065,  4071,
    4077,  4082,  4104,  4110,  4116,  4121,  4132,  4142,  4152,  4158,
    4164,  4169,  4180,  4186,  4198,  4210,  4216,  4222,  4259,  4264,
    4269,  4280,  4284,  4288,  4298,  4309,  4313,  4317,  4321,  4325,
    4329,  4333,  4337,  4341,  4351,  4361,  4365,  4370,  4381,  4391,
    4401,  4405,  4409,  4419,  4425,  4431,  4437,  4443,  4455,  4466,
    4473,  4480,  4487,  4494,  4501,  4508,  4521,  4542,  4549,  4569,
    4609,  4614,  4617,  4625,  4631,  4637,  4643,  4649,  4656,  4662,
    4668,  4674,  4680,  4692,  4697,  4707,  4713,  4725,  4751,  4762,
    4768,  4781,  4795,  4802,  4809,  4820,  4827,  4835,  4844,  4857,
    4860,  4878,  4879,  4880,  4881,  4882,  4883,  4884,  4885,  4886,
    4887,  4888,  4889,  4890,  4891,  4892,  4893,  4894,  4895,  4896,
    4897,  4898,  4899,  4900,  4901,  4902,  4903,  4904,  4905,  4906,
    4907,  4908,  4909,  4910,  4911,  4912,  4913,  4914,  4915,  4916,
    4917,  4918,  4919,  4920,  4921,  4922,  4923,  4924,  4925,  4926,
    4927,  4928,  4929,  4930,  4931,  4932,  4933,  4934,  4935,  4936,
    4937,  4938,  4939,  4940,  4941,  4942,  4943,  4944,  4945,  4946,
    4947,  4948,  4949,  4950,  4951,  4952,  4953,  4954,  4955,  4956,
    4957,  4958,  4959,  4960,  4961,  4962,  4963,  4964,  4965,  4966,
    4967,  4968,  4969,  4970,  4971,  4972,  4973,  4974,  4975,  4976,
    4977,  4978,  4979,  4980,  4981,  4982,  4983,  4984,  4985,  4986,
    4987,  4988,  4989,  4990,  4991,  4992,  4993,  4994,  4995,  4996,
    4997,  4998,  4999,  5000,  5001,  5002,  5003,  5004,  5005,  5006,
    5007,  5008,  5009,  5010,  5011,  5012,  5013,  5014,  5015,  5016,
    5017,  5018,  5019,  5020,  5021,  5022,  5023,  5024,  5025,  5026,
    5027,  5028,  5029,  5030,  5031,  5032,  5033,  5034,  5035,  5036,
    5037,  5038,  5039,  5040,  5041,  5042,  5043,  5044,  5045,  5046,
    5047,  5048,  5049,  5050,  5051,  5062,  5068,  5085,  5089,  5093,
    5097,  5107,  5110,  5113,  5116,  5125,  5128,  5137,  5140,  5149,
    5152,  5161,  5164,  5173,  5176,  5179,  5188,  5191,  5200,  5204,
    5214,  5217,  5220,  5223,  5226,  5235,  5244,  5248,  5252,  5256,
    5260,  5264,  5268,  5278,  5281,  5284,  5287,  5296,  5299,  5302,
    5305,  5314,  5317,  5326,  5329,  5332,  5335,  5338,  5341,  5344,
    5353,  5356,  5365,  5368,  5371,  5374,  5383,  5386,  5389,  5392,
    5395,  5404,  5407,  5416,  5419,  5428,  5431,  5440,  5443,  5452,
    5461,  5464,  5473,  5476,  5479,  5488,  5491,  5494,  5497,  5500,
    5509,  5513,  5517,  5521,  5531,  5540,  5550,  5559,  5562,  5571,
    5574,  5577,  5586,  5589,  5598
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
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 8286;
  const int xquery_parser::yynnts_ = 251;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 474;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 285;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 539;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


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

