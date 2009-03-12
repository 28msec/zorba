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
#line 853 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"

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
        case 98: /* "\"'DECIMAL'\"" */
#line 746 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 110: /* "\"'DOUBLE'\"" */
#line 745 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 134: /* "\"'INTEGER'\"" */
#line 744 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "VersionDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "MainModule" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "LibraryModule" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "ModuleDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "Prolog" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "SIND_DeclList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "VFO_DeclList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "SIND_Decl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "VFO_Decl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "Setter" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "Import" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "NamespaceDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "BoundarySpaceDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "DefaultNamespaceDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "OptionDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "OrderingModeDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "EmptyOrderDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "CopyNamespacesDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "DefaultCollationDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "BaseURIDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "SchemaImport" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "URILiteralList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "SchemaPrefix" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "ModuleImport" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "CtxItemDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 346 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "CtxItemDecl2" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "CtxItemDecl3" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 356 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "CtxItemDecl4" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 361 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "VarNameAndType" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };
#line 366 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "VarDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 371 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "IndexDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 376 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "IndexDecl2" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 381 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "IndexDeclSuffix" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 386 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "IndexField" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 391 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "IndexField1" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 396 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "IndexFieldList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 401 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "ConstructionDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 406 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "FunctionSig" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 411 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "BlockExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 416 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "Block" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 421 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "AssignExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 426 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "ExitExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 431 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "WhileExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 436 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "FlowCtlStatement" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 441 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "IndexStatement" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 446 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "FunctionDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 451 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "FunctionDecl2" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 456 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "FunctionDecl3" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 461 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "FunctionDecl4" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 466 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "ParamList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 471 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "Param" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "EnclosedExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 481 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "BracedExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 486 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "QueryBody" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 491 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "Expr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 496 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "ApplyExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 501 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "ConcatExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 506 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ExprSingle" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 511 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "FLWORExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 516 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "ReturnExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 521 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "FLWORWinCond" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "WindowClause" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CountClause" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 536 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "ForLetWinClause" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "FLWORClauseList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "ForClause" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 551 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "VarInDeclList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 556 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "VarInDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 561 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "PositionalVar" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 566 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "LetClause" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 571 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "VarGetsDeclList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 576 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "EvalVarDeclList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 581 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "VarGetsDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 586 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "WindowVarDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 591 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "WindowVars" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 596 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "WindowVars3" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 601 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "WindowVars2" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 606 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "EvalVarDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 611 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "WhereClause" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 616 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "GroupByClause" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 621 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "GroupSpecList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 626 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "GroupSpec" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 631 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "GroupCollationSpec" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 636 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "OrderByClause" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 641 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "OrderSpecList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 646 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "OrderSpec" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 651 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "OrderModifier" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 656 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "OrderDirSpec" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 661 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "OrderEmptySpec" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 666 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "OrderCollationSpec" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 671 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "QuantifiedExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 676 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "QVarInDeclList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 681 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "QVarInDecl" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 686 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "TypeswitchExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 691 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "CaseClauseList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 696 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "CaseClause" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 701 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "IfExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 706 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "OrExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 711 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "AndExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 716 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ComparisonExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 721 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "FTContainsExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 726 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "RangeExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 731 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "AdditiveExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 736 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "MultiplicativeExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 741 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "UnionExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 746 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "IntersectExceptExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 751 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "InstanceofExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 756 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "TreatExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 761 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "CastableExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 766 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "CastExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 771 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "UnaryExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 776 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "SignList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 781 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "ValueExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 786 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "ValueComp" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 791 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "NodeComp" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 796 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "ValidateExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 801 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ExtensionExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 806 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "PragmaList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 811 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "Pragma" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 816 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "PathExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 821 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "RelativePathExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 826 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "StepExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 831 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "AxisStep" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 836 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "ForwardStep" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 841 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "ForwardAxis" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 846 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "AbbrevForwardStep" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 851 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "ReverseStep" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 856 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "ReverseAxis" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 861 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "NodeTest" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 866 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "NameTest" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 871 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "Wildcard" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 876 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "FilterExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 881 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "PredicateList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 886 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "Predicate" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 891 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "PrimaryExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 896 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "Literal" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 901 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "NumericLiteral" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 906 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "VarRef" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 911 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "ParenthesizedExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 916 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "ContextItemExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 921 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrderedExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 926 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "UnorderedExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 931 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "FunctionCall" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 936 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "ArgList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 941 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "Constructor" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 946 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "DirectConstructor" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 951 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "DirElemConstructor" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 956 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "DirElemContentList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 961 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "DirAttributeList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 966 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "DirAttr" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 971 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "DirAttributeValue" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 976 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "Opt_QuoteAttrContentList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 981 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "QuoteAttrContentList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 986 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "Opt_AposAttrContentList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 991 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "AposAttrContentList" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 996 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "QuoteAttrValueContent" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1001 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "AposAttrValueContent" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1006 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "DirElemContent" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1011 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "CommonContent" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1016 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "DirCommentConstructor" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1021 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "DirPIConstructor" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1026 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "CDataSection" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1031 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ComputedConstructor" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1036 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CompDocConstructor" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1041 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "CompElemConstructor" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1046 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "CompAttrConstructor" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1051 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "CompTextConstructor" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1056 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "CompCommentConstructor" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1061 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "CompPIConstructor" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1066 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "SingleType" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1071 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "TypeDeclaration" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1076 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "SequenceType" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1081 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "OccurrenceIndicator" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1086 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "ItemType" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1091 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "AtomicType" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1096 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "KindTest" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1101 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "AnyKindTest" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1106 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "DocumentTest" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1111 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "TextTest" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1116 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "CommentTest" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1121 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "PITest" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1126 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "AttributeTest" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1131 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "SchemaAttributeTest" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1136 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ElementTest" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1141 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "SchemaElementTest" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1146 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "TypeName" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1151 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "TypeName_WITH_HOOK" */
#line 754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1156 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "StringLiteral" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1161 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "InsertExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1166 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DeleteExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1171 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ReplaceExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1176 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "RenameExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1181 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "TransformExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1186 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "VarNameList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1191 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "VarNameDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1196 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "TryExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1201 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "CatchListExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1206 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "CatchExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1211 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "EvalExpr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1216 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
#line 1297 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
#line 871 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 4:
#line 881 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 886 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 892 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 7:
#line 897 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 8:
#line 909 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		;}
    break;

  case 9:
#line 914 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    ;}
    break;

  case 10:
#line 924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 11:
#line 931 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		;}
    break;

  case 12:
#line 943 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 13:
#line 955 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval)));
		;}
    break;

  case 14:
#line 967 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 15:
#line 973 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 16:
#line 979 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 17:
#line 991 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 18:
#line 997 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 1011 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 20:
#line 1017 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 41:
#line 1085 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 42:
#line 1097 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 43:
#line 1102 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 44:
#line 1113 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 45:
#line 1119 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 46:
#line 1131 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 47:
#line 1144 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		;}
    break;

  case 48:
#line 1155 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 49:
#line 1160 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 50:
#line 1172 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 51:
#line 1177 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 52:
#line 1188 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 53:
#line 1194 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 54:
#line 1200 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 55:
#line 1206 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 56:
#line 1225 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 57:
#line 1236 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 58:
#line 1247 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 59:
#line 1254 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		;}
    break;

  case 60:
#line 1261 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 61:
#line 1268 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 62:
#line 1281 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 63:
#line 1287 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 64:
#line 1302 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 65:
#line 1306 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 66:
#line 1316 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 67:
#line 1322 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		;}
    break;

  case 68:
#line 1329 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 69:
#line 1335 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (4)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		;}
    break;

  case 70:
#line 1347 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    ;}
    break;

  case 71:
#line 1354 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = dynamic_cast<ItemType *> ((yysemantic_stack_[(3) - (2)].node));
      (yyval.node) = d;
    ;}
    break;

  case 72:
#line 1360 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 73:
#line 1367 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 74:
#line 1371 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->ext = true;
      (yyval.node) = d;
    ;}
    break;

  case 75:
#line 1380 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 76:
#line 1391 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (driver.symtab.get((off_t) (yysemantic_stack_[(2) - (2)].sval)), NULL);
    ;}
    break;

  case 77:
#line 1395 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (driver.symtab.get((off_t) (yysemantic_stack_[(3) - (2)].sval)),
                               dynamic_cast<TypeDeclaration *> ((yysemantic_stack_[(3) - (3)].node)));
    ;}
    break;

  case 78:
#line 1403 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(5) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								nt->name,
								nt->type,
								(yysemantic_stack_[(5) - (5)].expr));
      delete nt;
		;}
    break;

  case 79:
#line 1412 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(4) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      delete nt;
		;}
    break;

  case 80:
#line 1419 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(6) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      delete nt;
		;}
    break;

  case 81:
#line 1429 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "hash"; ;}
    break;

  case 82:
#line 1431 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "btree"; ;}
    break;

  case 83:
#line 1438 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->create = false;
      (yyval.node) = d;
    ;}
    break;

  case 84:
#line 1444 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->create = true;
      (yyval.node) = d;
    ;}
    break;

  case 85:
#line 1453 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 86:
#line 1457 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->uniq = true;
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 87:
#line 1465 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl (LOC ((yyloc)), SYMTAB (2), (yysemantic_stack_[(7) - (4)].expr), "",
                          dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(7) - (6)].node)));
    ;}
    break;

  case 88:
#line 1470 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = new IndexDecl (LOC ((yyloc)), SYMTAB (2), (yysemantic_stack_[(8) - (4)].expr), SYMTAB (5),
                                    dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(8) - (7)].node)));
      d->method = (yysemantic_stack_[(8) - (5)].strval);
      (yyval.node) = d;
    ;}
    break;

  case 89:
#line 1480 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 90:
#line 1484 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (1)].node))->coll = driver.symtab.get ((off_t) (yysemantic_stack_[(3) - (3)].sval));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    ;}
    break;

  case 91:
#line 1492 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL);
    ;}
    break;

  case 92:
#line 1496 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<TypeDeclaration *> ((yysemantic_stack_[(2) - (2)].node)));
    ;}
    break;

  case 93:
#line 1503 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexFieldList *l = new IndexFieldList (LOC ((yyloc)));
      l->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
      
    ;}
    break;

  case 94:
#line 1510 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(3) - (1)].node))->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    ;}
    break;

  case 95:
#line 1520 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 96:
#line 1525 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 97:
#line 1537 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 98:
#line 1541 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 99:
#line 1545 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 100:
#line 1549 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 101:
#line 1556 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 102:
#line 1563 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    ;}
    break;

  case 103:
#line 1570 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), driver.symtab.get ((off_t)(yysemantic_stack_[(5) - (3)].sval)), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 104:
#line 1577 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 105:
#line 1584 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr)));
    ;}
    break;

  case 106:
#line 1591 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 107:
#line 1595 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 108:
#line 1602 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB (3), true);
    ;}
    break;

  case 109:
#line 1606 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB (3), false);
    ;}
    break;

  case 110:
#line 1613 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 111:
#line 1617 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    ;}
    break;

  case 112:
#line 1621 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      //
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    ;}
    break;

  case 113:
#line 1629 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 114:
#line 1633 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 115:
#line 1637 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    ;}
    break;

  case 116:
#line 1645 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 117:
#line 1652 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 118:
#line 1661 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 119:
#line 1673 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 120:
#line 1687 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 121:
#line 1695 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 122:
#line 1709 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 123:
#line 1715 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 124:
#line 1727 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 125:
#line 1735 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 126:
#line 1746 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 127:
#line 1758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 128:
#line 1762 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(2) - (2)].expr)),
        *blk2 = new BlockBody (LOC ((yyloc)));
      blk2->add ((yysemantic_stack_[(2) - (1)].expr));
      for (int i = 0; i < blk->size (); i++)
        blk2->add ((*blk) [i]);
      (yyval.expr) = blk2;
    ;}
    break;

  case 129:
#line 1774 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    ;}
    break;

  case 130:
#line 1778 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 131:
#line 1787 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 132:
#line 1791 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 151:
#line 1838 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 152:
#line 1847 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 153:
#line 1854 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    ;}
    break;

  case 154:
#line 1858 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    ;}
    break;

  case 155:
#line 1866 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    ;}
    break;

  case 156:
#line 1870 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    ;}
    break;

  case 157:
#line 1874 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    ;}
    break;

  case 158:
#line 1881 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 159:
#line 1885 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 160:
#line 1892 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)), dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 161:
#line 1897 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    ;}
    break;

  case 162:
#line 1906 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 171:
#line 1924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 172:
#line 1930 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 173:
#line 1939 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    ;}
    break;

  case 174:
#line 1943 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    ;}
    break;

  case 175:
#line 1953 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		;}
    break;

  case 176:
#line 1964 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 177:
#line 1970 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 178:
#line 1984 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 179:
#line 1991 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 180:
#line 1999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 181:
#line 2008 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 182:
#line 2018 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 183:
#line 2026 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 184:
#line 2035 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 185:
#line 2044 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 186:
#line 2059 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 187:
#line 2071 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 188:
#line 2082 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 189:
#line 2094 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 190:
#line 2100 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 191:
#line 2112 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 192:
#line 2118 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 193:
#line 2132 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 194:
#line 2140 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 195:
#line 2149 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 196:
#line 2157 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 197:
#line 2169 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 198:
#line 2175 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 200:
#line 2186 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)), "", "");
    ;}
    break;

  case 201:
#line 2190 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
    ;}
    break;

  case 202:
#line 2198 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    ;}
    break;

  case 203:
#line 2202 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    ;}
    break;

  case 205:
#line 2211 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (6)].sval)));
    ;}
    break;

  case 206:
#line 2215 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 207:
#line 2219 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)), "");
    ;}
    break;

  case 208:
#line 2226 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 209:
#line 2241 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 210:
#line 2249 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 211:
#line 2259 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 212:
#line 2265 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 213:
#line 2276 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 214:
#line 2282 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 215:
#line 2291 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 216:
#line 2301 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 217:
#line 2306 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 218:
#line 2318 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 219:
#line 2324 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 220:
#line 2338 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 221:
#line 2344 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 222:
#line 2356 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 223:
#line 2363 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 224:
#line 2370 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 225:
#line 2377 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 226:
#line 2384 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 227:
#line 2391 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 228:
#line 2398 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 229:
#line 2411 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 230:
#line 2415 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 231:
#line 2425 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 232:
#line 2430 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 233:
#line 2441 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 234:
#line 2452 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 235:
#line 2459 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 236:
#line 2472 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 237:
#line 2479 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 238:
#line 2491 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 239:
#line 2497 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 240:
#line 2510 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 241:
#line 2517 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 242:
#line 2531 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 243:
#line 2537 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 244:
#line 2549 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 245:
#line 2555 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 246:
#line 2568 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 247:
#line 2579 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 248:
#line 2583 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 249:
#line 2594 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 250:
#line 2598 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 251:
#line 2617 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 252:
#line 2621 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 253:
#line 2629 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 254:
#line 2637 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 255:
#line 2645 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 256:
#line 2652 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 257:
#line 2653 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 258:
#line 2661 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 259:
#line 2669 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 260:
#line 2677 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 261:
#line 2691 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 262:
#line 2695 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 263:
#line 2702 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 264:
#line 2715 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 265:
#line 2719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 266:
#line 2730 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 267:
#line 2734 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 268:
#line 2738 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 269:
#line 2748 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 270:
#line 2752 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 271:
#line 2756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 272:
#line 2760 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 273:
#line 2764 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 274:
#line 2774 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 275:
#line 2778 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 276:
#line 2783 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 277:
#line 2794 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 278:
#line 2798 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 279:
#line 2802 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 280:
#line 2812 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 281:
#line 2816 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 282:
#line 2828 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 283:
#line 2832 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 284:
#line 2844 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 285:
#line 2848 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 286:
#line 2860 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 287:
#line 2864 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 288:
#line 2876 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 289:
#line 2880 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 290:
#line 2892 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 291:
#line 2896 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 292:
#line 2900 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 293:
#line 2904 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 294:
#line 2916 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 295:
#line 2920 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 296:
#line 2924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 297:
#line 2934 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 298:
#line 2938 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 299:
#line 2942 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 300:
#line 2946 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 301:
#line 2950 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 302:
#line 2954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 303:
#line 2964 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 304:
#line 2968 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 305:
#line 2972 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 306:
#line 2982 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 307:
#line 2986 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (2)].node))->get_name(),
                            (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 308:
#line 2998 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 309:
#line 3004 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 310:
#line 3016 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 311:
#line 3022 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 312:
#line 3036 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 313:
#line 3042 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 314:
#line 3084 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 315:
#line 3088 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 316:
#line 3092 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 317:
#line 3096 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 318:
#line 3108 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    ;}
    break;

  case 319:
#line 3118 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 320:
#line 3129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 321:
#line 3134 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 322:
#line 3144 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 323:
#line 3148 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 324:
#line 3158 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 325:
#line 3164 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 326:
#line 3170 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 327:
#line 3176 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 328:
#line 3188 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 329:
#line 3194 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 330:
#line 3205 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 331:
#line 3209 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 332:
#line 3213 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 333:
#line 3217 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 334:
#line 3221 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 335:
#line 3225 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 336:
#line 3229 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 337:
#line 3239 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 338:
#line 3243 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 339:
#line 3253 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 340:
#line 3259 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 341:
#line 3271 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 342:
#line 3275 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 343:
#line 3279 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 344:
#line 3283 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 345:
#line 3287 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 346:
#line 3302 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 347:
#line 3306 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 348:
#line 3316 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 349:
#line 3320 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 350:
#line 3330 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 351:
#line 3337 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 352:
#line 3344 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 353:
#line 3357 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 354:
#line 3361 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 355:
#line 3373 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 356:
#line 3379 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 357:
#line 3393 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 358:
#line 3404 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 359:
#line 3408 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 360:
#line 3412 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 361:
#line 3416 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 362:
#line 3420 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 363:
#line 3424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 364:
#line 3428 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 365:
#line 3432 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 366:
#line 3442 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 367:
#line 3446 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 368:
#line 3456 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 369:
#line 3461 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 370:
#line 3466 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 371:
#line 3477 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 372:
#line 3487 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 373:
#line 3491 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 374:
#line 3502 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 375:
#line 3512 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 376:
#line 3523 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 377:
#line 3579 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 378:
#line 3585 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 379:
#line 3597 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 380:
#line 3603 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 381:
#line 3615 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 382:
#line 3619 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 383:
#line 3629 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 384:
#line 3633 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 385:
#line 3637 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 386:
#line 3647 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 387:
#line 3655 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 388:
#line 3663 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 389:
#line 3671 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 390:
#line 3679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 391:
#line 3687 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 392:
#line 3702 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 393:
#line 3708 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 394:
#line 3720 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 395:
#line 3726 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 396:
#line 3739 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 399:
#line 3756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 400:
#line 3761 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 401:
#line 3772 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 402:
#line 3776 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 403:
#line 3783 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 404:
#line 3789 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 405:
#line 3795 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 406:
#line 3803 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 407:
#line 3817 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 408:
#line 3821 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 409:
#line 3828 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 410:
#line 3834 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 411:
#line 3840 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 412:
#line 3848 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 413:
#line 3862 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 414:
#line 3867 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 415:
#line 3878 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 416:
#line 3883 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 417:
#line 3894 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 418:
#line 3899 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 419:
#line 3904 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 420:
#line 3910 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 421:
#line 3922 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 422:
#line 3928 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 423:
#line 3933 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 424:
#line 3938 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 425:
#line 3949 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 426:
#line 3954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 427:
#line 3969 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 428:
#line 3974 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 429:
#line 3991 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 430:
#line 4006 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 431:
#line 4010 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 432:
#line 4014 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 433:
#line 4018 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 434:
#line 4022 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 435:
#line 4026 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 436:
#line 4036 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 437:
#line 4047 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 438:
#line 4053 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 439:
#line 4059 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 440:
#line 4064 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 441:
#line 4086 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 442:
#line 4092 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 443:
#line 4098 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 444:
#line 4103 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 445:
#line 4114 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 446:
#line 4124 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 447:
#line 4134 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 448:
#line 4140 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 449:
#line 4146 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 450:
#line 4151 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 451:
#line 4162 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 452:
#line 4168 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 453:
#line 4180 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 454:
#line 4192 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 455:
#line 4198 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 456:
#line 4204 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 457:
#line 4241 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 458:
#line 4246 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 459:
#line 4251 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 460:
#line 4262 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 461:
#line 4266 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 462:
#line 4270 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 463:
#line 4280 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 464:
#line 4291 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 465:
#line 4295 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 466:
#line 4299 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 467:
#line 4303 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 468:
#line 4307 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 469:
#line 4311 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 470:
#line 4315 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 471:
#line 4319 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 472:
#line 4323 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 473:
#line 4333 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 474:
#line 4343 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 475:
#line 4347 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 476:
#line 4352 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 477:
#line 4363 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 478:
#line 4373 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 479:
#line 4383 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 480:
#line 4387 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 481:
#line 4391 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 482:
#line 4401 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 483:
#line 4407 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 484:
#line 4413 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 485:
#line 4419 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 486:
#line 4425 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 487:
#line 4437 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 488:
#line 4448 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		;}
    break;

  case 489:
#line 4455 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))),
                           NULL,
                           true);
		;}
    break;

  case 490:
#line 4462 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		;}
    break;

  case 491:
#line 4469 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		;}
    break;

  case 492:
#line 4476 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 493:
#line 4483 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		;}
    break;

  case 494:
#line 4490 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 495:
#line 4503 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 496:
#line 4524 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 497:
#line 4531 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 498:
#line 4551 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 499:
#line 4591 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 500:
#line 4596 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 501:
#line 4599 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 502:
#line 4607 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 503:
#line 4613 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 504:
#line 4619 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 505:
#line 4625 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 506:
#line 4631 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 507:
#line 4638 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 508:
#line 4644 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 509:
#line 4650 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 510:
#line 4656 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 511:
#line 4662 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 512:
#line 4674 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 513:
#line 4679 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 514:
#line 4689 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 515:
#line 4695 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 516:
#line 4707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 517:
#line 4733 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 518:
#line 4744 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 519:
#line 4750 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 520:
#line 4763 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 521:
#line 4777 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 522:
#line 4784 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 523:
#line 4791 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 524:
#line 4802 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 525:
#line 4809 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 526:
#line 4817 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 527:
#line 4826 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(14) - (3)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (6)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (9)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(14) - (12)].sval)),
                          (yysemantic_stack_[(14) - (14)].expr));
    ;}
    break;

  case 529:
#line 4842 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 530:
#line 4859 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 531:
#line 4860 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty"); ;}
    break;

  case 532:
#line 4861 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("attribute"); ;}
    break;

  case 533:
#line 4862 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("comment"); ;}
    break;

  case 534:
#line 4863 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document-node"); ;}
    break;

  case 535:
#line 4864 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("element"); ;}
    break;

  case 536:
#line 4865 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("item"); ;}
    break;

  case 537:
#line 4866 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("if"); ;}
    break;

  case 538:
#line 4867 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("node"); ;}
    break;

  case 539:
#line 4868 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("processing-instruction"); ;}
    break;

  case 540:
#line 4869 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-attribute"); ;}
    break;

  case 541:
#line 4870 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema-element"); ;}
    break;

  case 542:
#line 4871 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("text"); ;}
    break;

  case 543:
#line 4872 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("typeswitch"); ;}
    break;

  case 544:
#line 4873 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("empty-sequence"); ;}
    break;

  case 545:
#line 4874 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("boundary-space"); ;}
    break;

  case 546:
#line 4875 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ft-option"); ;}
    break;

  case 547:
#line 4876 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("base-uri"); ;}
    break;

  case 548:
#line 4877 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lax"); ;}
    break;

  case 549:
#line 4878 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strict"); ;}
    break;

  case 550:
#line 4879 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("idiv"); ;}
    break;

  case 551:
#line 4880 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("document"); ;}
    break;

  case 552:
#line 4881 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("not"); ;}
    break;

  case 553:
#line 4882 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sensitive"); ;}
    break;

  case 554:
#line 4883 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insensitive"); ;}
    break;

  case 555:
#line 4884 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("diacritics"); ;}
    break;

  case 556:
#line 4885 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("without"); ;}
    break;

  case 557:
#line 4886 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stemming"); ;}
    break;

  case 558:
#line 4887 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("thesaurus"); ;}
    break;

  case 559:
#line 4888 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stop"); ;}
    break;

  case 560:
#line 4889 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("wildcards"); ;}
    break;

  case 561:
#line 4890 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("entire"); ;}
    break;

  case 562:
#line 4891 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("content"); ;}
    break;

  case 563:
#line 4892 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("word"); ;}
    break;

  case 564:
#line 4893 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("start"); ;}
    break;

  case 565:
#line 4894 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("end"); ;}
    break;

  case 566:
#line 4895 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("most"); ;}
    break;

  case 567:
#line 4896 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("skip"); ;}
    break;

  case 568:
#line 4897 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy"); ;}
    break;

  case 569:
#line 4898 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("value"); ;}
    break;

  case 570:
#line 4899 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("eq"); ;}
    break;

  case 571:
#line 4900 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ne"); ;}
    break;

  case 572:
#line 4901 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lt"); ;}
    break;

  case 573:
#line 4902 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("le"); ;}
    break;

  case 574:
#line 4903 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("gt"); ;}
    break;

  case 575:
#line 4904 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ge"); ;}
    break;

  case 576:
#line 4905 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("at"); ;}
    break;

  case 577:
#line 4906 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("context"); ;}
    break;

  case 578:
#line 4907 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("variable"); ;}
    break;

  case 579:
#line 4908 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("return"); ;}
    break;

  case 580:
#line 4909 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("for"); ;}
    break;

  case 581:
#line 4910 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("outer"); ;}
    break;

  case 582:
#line 4911 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sliding"); ;}
    break;

  case 583:
#line 4912 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("tumbling"); ;}
    break;

  case 584:
#line 4913 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("previous"); ;}
    break;

  case 585:
#line 4914 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("next"); ;}
    break;

  case 586:
#line 4915 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("only"); ;}
    break;

  case 587:
#line 4916 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("when"); ;}
    break;

  case 588:
#line 4917 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("count"); ;}
    break;

  case 589:
#line 4918 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("in"); ;}
    break;

  case 590:
#line 4919 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("let"); ;}
    break;

  case 591:
#line 4920 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("where"); ;}
    break;

  case 592:
#line 4921 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("by"); ;}
    break;

  case 593:
#line 4922 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("group"); ;}
    break;

  case 594:
#line 4923 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("order"); ;}
    break;

  case 595:
#line 4924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("stable"); ;}
    break;

  case 596:
#line 4925 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ascending"); ;}
    break;

  case 597:
#line 4926 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("descending"); ;}
    break;

  case 598:
#line 4927 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("greatest"); ;}
    break;

  case 599:
#line 4928 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("least"); ;}
    break;

  case 600:
#line 4929 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("collation"); ;}
    break;

  case 601:
#line 4930 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("some"); ;}
    break;

  case 602:
#line 4931 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("every"); ;}
    break;

  case 603:
#line 4932 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("satisfies"); ;}
    break;

  case 604:
#line 4933 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("case"); ;}
    break;

  case 605:
#line 4934 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("as"); ;}
    break;

  case 606:
#line 4935 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("then"); ;}
    break;

  case 607:
#line 4936 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("else"); ;}
    break;

  case 608:
#line 4937 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("or"); ;}
    break;

  case 609:
#line 4938 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("and"); ;}
    break;

  case 610:
#line 4939 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("instance"); ;}
    break;

  case 611:
#line 4940 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("of"); ;}
    break;

  case 612:
#line 4941 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("castable"); ;}
    break;

  case 613:
#line 4942 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("to"); ;}
    break;

  case 614:
#line 4943 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("div"); ;}
    break;

  case 615:
#line 4944 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("mod"); ;}
    break;

  case 616:
#line 4945 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("union"); ;}
    break;

  case 617:
#line 4946 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("intersect"); ;}
    break;

  case 618:
#line 4947 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("except"); ;}
    break;

  case 619:
#line 4948 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("validate"); ;}
    break;

  case 620:
#line 4949 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cast"); ;}
    break;

  case 621:
#line 4950 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("treat"); ;}
    break;

  case 622:
#line 4951 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("is"); ;}
    break;

  case 623:
#line 4952 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("preserve"); ;}
    break;

  case 624:
#line 4953 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("strip"); ;}
    break;

  case 625:
#line 4954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("namespace"); ;}
    break;

  case 626:
#line 4955 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("external"); ;}
    break;

  case 627:
#line 4956 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("encoding"); ;}
    break;

  case 628:
#line 4957 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-preserve"); ;}
    break;

  case 629:
#line 4958 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("inherit"); ;}
    break;

  case 630:
#line 4959 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("no-inherit"); ;}
    break;

  case 631:
#line 4960 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("declare"); ;}
    break;

  case 632:
#line 4961 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("construction"); ;}
    break;

  case 633:
#line 4962 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordering"); ;}
    break;

  case 634:
#line 4963 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("default"); ;}
    break;

  case 635:
#line 4964 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("copy-namespaces"); ;}
    break;

  case 636:
#line 4965 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("option"); ;}
    break;

  case 637:
#line 4966 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("version"); ;}
    break;

  case 638:
#line 4967 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("import"); ;}
    break;

  case 639:
#line 4968 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("schema"); ;}
    break;

  case 640:
#line 4969 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("module"); ;}
    break;

  case 641:
#line 4970 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("function"); ;}
    break;

  case 642:
#line 4971 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("score"); ;}
    break;

  case 643:
#line 4972 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ftcontains"); ;}
    break;

  case 644:
#line 4973 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("weight"); ;}
    break;

  case 645:
#line 4974 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("window"); ;}
    break;

  case 646:
#line 4975 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("distance"); ;}
    break;

  case 647:
#line 4976 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("occurs"); ;}
    break;

  case 648:
#line 4977 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("times"); ;}
    break;

  case 649:
#line 4978 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("same"); ;}
    break;

  case 650:
#line 4979 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("different"); ;}
    break;

  case 651:
#line 4980 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("lowercase"); ;}
    break;

  case 652:
#line 4981 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("uppercase"); ;}
    break;

  case 653:
#line 4982 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("relationship"); ;}
    break;

  case 654:
#line 4983 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("levels"); ;}
    break;

  case 655:
#line 4984 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("language"); ;}
    break;

  case 656:
#line 4985 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("any"); ;}
    break;

  case 657:
#line 4986 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("all"); ;}
    break;

  case 658:
#line 4987 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("phrase"); ;}
    break;

  case 659:
#line 4988 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exactly"); ;}
    break;

  case 660:
#line 4989 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("from"); ;}
    break;

  case 661:
#line 4990 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("words"); ;}
    break;

  case 662:
#line 4991 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentences"); ;}
    break;

  case 663:
#line 4992 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("sentence"); ;}
    break;

  case 664:
#line 4993 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("paragraph"); ;}
    break;

  case 665:
#line 4994 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("replace"); ;}
    break;

  case 666:
#line 4995 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("modify"); ;}
    break;

  case 667:
#line 4996 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("first"); ;}
    break;

  case 668:
#line 4997 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("insert"); ;}
    break;

  case 669:
#line 4998 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("bofer"); ;}
    break;

  case 670:
#line 4999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("after"); ;}
    break;

  case 671:
#line 5000 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("revalidation"); ;}
    break;

  case 672:
#line 5001 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("with"); ;}
    break;

  case 673:
#line 5002 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("nodes"); ;}
    break;

  case 674:
#line 5003 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("rename"); ;}
    break;

  case 675:
#line 5004 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("last"); ;}
    break;

  case 676:
#line 5005 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("delete"); ;}
    break;

  case 677:
#line 5006 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("into"); ;}
    break;

  case 678:
#line 5007 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("updating"); ;}
    break;

  case 679:
#line 5008 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("ordered"); ;}
    break;

  case 680:
#line 5009 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("unordered"); ;}
    break;

  case 681:
#line 5010 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("block"); ;}
    break;

  case 682:
#line 5011 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("exit"); ;}
    break;

  case 683:
#line 5012 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("loop"); ;}
    break;

  case 684:
#line 5013 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("break"); ;}
    break;

  case 685:
#line 5014 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("cont"); ;}
    break;

  case 686:
#line 5015 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("set"); ;}
    break;

  case 687:
#line 5016 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("index"); ;}
    break;

  case 688:
#line 5017 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("create"); ;}
    break;

  case 689:
#line 5018 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("unique"); ;}
    break;

  case 690:
#line 5019 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("on"); ;}
    break;

  case 691:
#line 5020 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("hash"); ;}
    break;

  case 692:
#line 5021 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("btree"); ;}
    break;

  case 693:
#line 5022 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = driver.symtab.put("DROP"); ;}
    break;

  case 694:
#line 5034 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 695:
#line 5040 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 696:
#line 5057 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 697:
#line 5061 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 698:
#line 5065 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 699:
#line 5069 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 700:
#line 5079 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 701:
#line 5082 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 702:
#line 5085 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 703:
#line 5088 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 704:
#line 5097 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 705:
#line 5100 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 706:
#line 5109 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 707:
#line 5112 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 708:
#line 5121 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 709:
#line 5124 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 710:
#line 5133 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 711:
#line 5136 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 712:
#line 5145 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 713:
#line 5148 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 714:
#line 5151 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 715:
#line 5160 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 716:
#line 5163 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 717:
#line 5172 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 718:
#line 5176 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 719:
#line 5186 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 720:
#line 5189 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 721:
#line 5192 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 722:
#line 5195 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 723:
#line 5198 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 724:
#line 5207 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 725:
#line 5216 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 726:
#line 5220 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 727:
#line 5224 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 728:
#line 5228 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 729:
#line 5232 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 730:
#line 5236 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 731:
#line 5240 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 732:
#line 5250 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 733:
#line 5253 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 734:
#line 5256 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 735:
#line 5259 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 736:
#line 5268 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 737:
#line 5271 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 738:
#line 5274 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 739:
#line 5277 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 740:
#line 5286 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 741:
#line 5289 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 742:
#line 5298 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 743:
#line 5301 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 744:
#line 5304 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 745:
#line 5307 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 746:
#line 5310 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 747:
#line 5313 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 748:
#line 5316 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 749:
#line 5325 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 750:
#line 5328 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 751:
#line 5337 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 752:
#line 5340 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 753:
#line 5343 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 754:
#line 5346 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 755:
#line 5355 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 756:
#line 5358 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 757:
#line 5361 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 758:
#line 5364 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 759:
#line 5367 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 760:
#line 5376 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 761:
#line 5379 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 762:
#line 5388 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 763:
#line 5391 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 764:
#line 5400 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 765:
#line 5403 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 766:
#line 5412 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 767:
#line 5415 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 768:
#line 5424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 769:
#line 5433 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 770:
#line 5436 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 771:
#line 5445 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 772:
#line 5448 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 773:
#line 5451 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 774:
#line 5460 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 775:
#line 5463 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 776:
#line 5466 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 777:
#line 5469 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 778:
#line 5472 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 779:
#line 5481 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 780:
#line 5485 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 781:
#line 5489 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 782:
#line 5493 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 783:
#line 5503 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 784:
#line 5512 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 785:
#line 5522 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 786:
#line 5531 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 787:
#line 5534 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 788:
#line 5543 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 789:
#line 5546 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 790:
#line 5549 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 791:
#line 5558 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 792:
#line 5561 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 793:
#line 5570 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6863 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -988;
  const short int
  xquery_parser::yypact_[] =
  {
      1312,  -988,  -988,  -988,  -988,     6,   -94,   235,  -988,   152,
    7523,   192,  6258,   295,   273,   454,    17,  -988,  -988,   302,
     136,  -988,   507,   367,  -988,   364,  -988,  -988,  -988,   415,
     427,  -988,   445,   396,   527,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,   562,  -988,   463,   480,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  6511,  -988,  5489,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  8282,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,   530,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,  1574,  8282,  -988,  -988,  -988,  -988,
    -988,  -988,   505,  -988,  -988,  -988,  -988,   627,  -988,  6005,
    -988,  -988,  -988,  -988,  -988,  8282,  -988,  -988,  5228,  -988,
    -988,  -988,  -988,  -988,  -988,   513,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,    12,   453,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,   -31,   514,   174,  -988,   444,   276,
    -988,  -988,  -988,  -988,  -988,  -988,   550,  -988,   520,   553,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,   293,   393,  -988,  -988,
    -988,  -988,  -988,  1835,   661,  -988,  4184,  -988,  -988,    -9,
    4445,   487,   488,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,    -3,  -988,  -988,  -988,  -988,   275,  8282,  -988,
    -988,  -988,  -988,  -988,   519,   586,  -988,   591,   432,   212,
     266,   -51,   347,  -988,   598,   491,   588,   589,  4706,  -988,
    -988,  -988,   -11,  -988,  -988,  5228,  -988,   401,  -988,   542,
    5489,  -988,   542,  5489,  -988,  -988,  -988,  -988,   542,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,   543,  -988,  4445,
    -988,  4445,  -988,  4445,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  4445,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,   545,
    -988,  4445,  4445,  6764,   548,  4445,  4445,   516,  4445,   517,
    8282,   655,   656,   502,   502,   655,  8282,   149,   -13,   676,
     348,   313,   560,   592,    59,   683,   400,   124,   436,   676,
    -988,  -988,  -988,  -988,  4445,  -988,  4445,    77,   566,    70,
      62,  8282,   683,  8282,  8282,  4445,   449,   455,  -988,   599,
     605,  -988,  8282,    40,  4445,  7017,   575,   573,   578,   580,
     585,   587,  -988,  -988,  -988,  8282,  -988,   462,   559,   691,
    4445,    57,  -988,   717,   563,  -988,  4445,   537,  -988,   716,
    4445,  4445,   568,  4445,  4445,  4445,  4445,   521,  8282,  4445,
    8282,   676,  -988,   676,  -988,  -988,  -988,  -988,    17,   507,
     344,  -988,  -988,    -9,   -21,  4445,  -988,  4445,   590,   427,
     396,   527,   634,   593,   594,  4445,  4445,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,   647,  -988,   -30,  4967,  4967,  4967,
    -988,  4967,  4967,  -988,  4967,  -988,  4967,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,  4967,  4967,    11,  4967,  4967,  4967,
    4967,  4967,  4967,  4967,  4967,  4967,  4967,  4967,   529,   664,
     665,   668,  -988,  -988,  -988,  2096,  -988,  -988,  5228,  5228,
    4445,   542,  -988,  -988,   542,  -988,   542,  2357,   583,  -988,
     581,   595,  4445,   582,   597,  -988,    43,    83,  2618,   601,
     602,  -988,   603,  -988,   614,  -988,  8282,  -988,  -988,  -988,
    -988,   738,  -988,  -988,  -988,  -988,  -988,  -988,   666,   667,
    -988,  -988,   340,  8282,   425,   615,   621,   676,   646,   649,
    -988,  -988,  -988,   365,    45,   370,   752,  -988,  -988,   202,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,   504,
     606,   608,   613,  -988,   616,  2879,   683,   689,   751,   683,
     676,   702,   -24,  -988,   165,   671,   662,   697,  -988,   -45,
     626,  -988,  -988,  8282,    -4,  -988,   624,   573,   463,  -988,
     625,   628,   629,  -988,    87,   171,  3140,    36,   676,  -988,
    8282,   691,  -988,   169,   630,  -988,  -988,  -988,  -988,   632,
    -988,     5,  -988,  -988,  -988,    85,   135,   719,   584,   600,
      25,  -988,   674,   635,    47,  -988,  -988,   504,  -988,   633,
    -988,     1,  -988,  -988,     8,   652,  8282,  4445,   698,  -988,
    -988,   703,  7776,   705,  4445,   706,   -67,   681,   -18,   586,
    -988,  -988,  -988,  -988,  -988,  4967,  -988,  -988,  -988,  4445,
      11,   336,  -988,   556,   392,   576,   577,  -988,  -988,   570,
    -101,   266,   266,   280,   -51,   -51,   -51,   -51,   347,   347,
    -988,  -988,  7776,  7776,  8282,  8282,  -988,   651,  -988,  -988,
     648,  -988,  -988,  -988,   176,  -988,     6,  -988,   653,   735,
     686,  8282,  -988,  8282,  -988,  -988,   657,  -988,  -988,  -988,
      26,   382,   614,  -988,   316,   342,  8029,   699,  4445,  -988,
    -988,  -988,   744,   700,  4445,   676,   676,  -988,   498,   676,
    -988,  -988,   569,  -988,  -988,   571,   353,  -988,  -988,  -988,
    -988,  -988,  -988,   572,  -988,  -988,  4445,   654,   692,  -988,
    -988,  -988,   663,   720,   676,   690,   721,   750,   676,   731,
    4445,  4445,   708,   676,  4445,   736,  4445,   713,   -60,  -988,
     199,   609,  -988,  -988,   448,    -4,  -988,  -988,  -988,   707,
    8282,  -988,  8282,  -988,  -988,   675,  4445,  -988,   821,  -988,
     178,  -988,   148,  -988,  -988,   827,  -988,   330,  4445,  4445,
    4445,   380,  4445,  4445,  4445,  4445,  4445,  4445,   742,  4445,
    4445,   631,   711,   745,   -21,  -988,  4445,  -988,   414,   755,
    -988,  8282,   757,  -988,  8282,   712,   718,  -988,   -23,  -988,
    -988,  -988,  8282,  -988,  8282,  4445,   722,  4445,  4445,     9,
     725,  -988,   694,   687,  -988,   637,  -988,   114,  -988,   303,
     -49,   639,    11,   303,  4967,  4967,   435,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,    11,   728,   -49,  -988,   617,   813,
    -988,  -988,  -988,  -988,  -988,   737,  -988,  -988,  -988,  4445,
    -988,  -988,  -988,  7270,   320,  -988,  3401,   709,   710,   739,
     723,   726,  -988,  8282,   788,   187,  -988,  -988,  4445,  -988,
       6,  -988,  -988,  -988,  -988,   434,  -988,  -988,  -988,  4445,
    -988,  -988,  -988,  -988,  -988,  -988,   618,    20,   856,  -988,
      35,  -988,  -988,    31,  4445,  3662,  -988,   676,   782,  -988,
    -988,  -988,   676,   782,  8282,  -988,  -988,  4445,   715,  -988,
    8282,  -988,  4445,  4445,   754,  4445,   760,  -988,   777,   778,
    4445,  8282,   551,   826,  -988,  -988,  -988,  3923,   727,   729,
    -988,  -988,  -988,   781,  -988,   210,  -988,  -988,   890,  -988,
    -988,  4445,  8282,  -988,  -988,   219,  -988,  -988,  -988,   730,
     684,   685,  -988,  -988,  -988,   688,   693,  -988,  -988,  -988,
    -988,  -988,   679,  8282,   734,  -988,   766,   631,  -988,  4445,
    8282,   755,  -988,   676,  -988,   503,  -988,   281,   814,  -988,
    4445,   815,   698,  -988,   741,   743,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  4445,  -988,  -988,  4445,   783,  4445,  -988,
    -988,  4967,  -988,  -988,  -988,  -988,  -988,    49,  4967,  4967,
     291,  -988,   576,  -988,  -988,   234,  4967,  -988,  -988,   577,
      11,   659,  -988,  -988,  -988,  -988,  8282,   746,    71,  -988,
    -988,   749,  -988,  -988,  -988,  -988,  -988,   744,  7776,   812,
     837,   753,  -988,  -988,  -988,   198,   900,   902,   198,   -14,
     207,   214,   789,  -988,  -988,   769,   817,  -988,   763,   848,
     676,   782,  -988,  -988,  -988,  -988,  -988,  -988,  4445,  -988,
    4445,  8282,  8282,  -988,   420,  -988,  4445,  -988,   767,  -988,
    -988,   821,  8282,   309,  -988,   768,   821,  8282,  -988,  -988,
    4445,  4445,  4445,  4445,  4445,  -988,  4445,  5750,  -988,   770,
    -988,  -988,  -988,  -988,   814,  -988,  -988,  -988,   676,  -988,
    -988,  -988,  -988,  -988,  -988,  4445,  -988,   -51,  4967,  4967,
     -51,   128,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
     852,  4445,  8282,  4445,  -988,  -988,  -988,  -988,  7776,  -988,
      20,    20,   198,  -988,  -988,  -988,    16,   198,   917,   695,
     858,  -988,   858,  -988,  4445,   217,   789,  4445,  -988,   676,
    -988,  -988,  -988,   875,  -988,  -988,  -988,  -988,    -8,   821,
    8282,  -988,   762,   821,  -988,  -988,  -988,  -988,  -988,  -988,
     242,  -988,  -988,  -988,  -988,   -51,   -51,  4967,  7776,  -988,
     774,  -988,  -988,  -988,  -988,  -988,  -988,  -988,   -49,  -988,
     246,  -988,   256,  -988,   851,   744,  4445,  -988,   270,  -988,
     782,   840,   125,   253,  -988,   772,   821,  -988,   773,   841,
     810,   -51,   780,  4445,   714,   858,  -988,  -988,   676,  -988,
    -988,  -988,  8282,  -988,  -988,   870,   131,  -988,  -988,  -988,
    -988,   790,   315,  -988,  -988,  -988,   775,  -988,  8282,  -988,
    4445,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,   285,  -988,   849,   810,  8282,  -988,   286,
     853,   810,  8282,  -988,   791,   810,  -988
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   351,   352,   530,   498,   681,   682,   684,   683,     0,
     619,   543,   535,   551,   542,   533,   631,   641,   678,   537,
     539,   566,   638,   601,   595,   640,   636,   563,   639,   686,
     590,   632,     0,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   633,   685,   547,   541,   534,   635,   610,   540,
     545,   342,   345,   609,   605,   596,   576,   532,   332,     0,
     604,   612,   620,   330,   600,   368,   577,   578,   634,   331,
     334,   597,   614,     0,   374,   340,   370,   607,   531,   598,
     599,   627,   602,   618,   626,   336,   335,   550,   589,   629,
     369,   617,   622,   536,     0,     0,   291,   615,   625,   630,
     628,   608,   679,   594,   592,   593,   341,     0,   290,     0,
     344,   343,   623,   579,   603,     0,   333,   318,     0,   350,
     624,   606,   613,   621,   616,   680,   570,   575,   574,   573,
     572,   571,   544,   591,     0,     0,   637,   564,   670,   669,
     671,   549,   548,   567,   676,   538,   668,   673,   674,   665,
     569,   611,   667,   677,   675,   666,   568,   672,     0,     0,
     657,   656,   553,   546,   555,   554,   650,   646,   561,   565,
     562,   659,   660,   643,   552,   655,   654,   651,   647,   664,
     658,   653,   649,   642,   663,   662,   648,   652,   644,   645,
     556,   557,   559,   661,   558,   560,   688,   693,   689,   687,
     691,   692,   690,     0,     0,     2,     0,     4,     6,     0,
       0,     0,     0,    17,    19,    21,    22,    23,    31,    24,
      28,    29,    35,    36,    37,    32,    33,    39,    40,    26,
      25,    30,    34,   149,   148,   145,   146,   147,   150,    27,
      11,   126,   127,   131,   133,   165,   171,     0,     0,   163,
     164,   134,   135,   136,   137,   247,   249,   251,   261,   264,
     266,   269,   274,   277,   280,   282,   284,   286,     0,   288,
     294,   296,     0,   310,   295,   314,   317,   319,   322,   324,
       0,   329,   326,     0,   337,   347,   349,   323,   353,   358,
     366,   359,   360,   361,   364,   365,   362,   363,   381,   383,
     384,   385,   382,   430,   431,   432,   433,   434,   435,   346,
     472,   464,   471,   470,   469,   466,   468,   465,   467,   367,
      38,   138,   139,   141,   140,   142,   143,   348,   144,     0,
     101,     0,   106,     0,   681,   682,   684,   619,   543,   535,
     551,   542,   533,   631,   537,   539,   638,   601,   640,   686,
     590,   580,   581,   685,   541,   534,   532,   602,     0,   679,
     680,   676,   538,   668,   674,   665,   568,   688,   693,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    85,   110,   113,     0,   529,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   173,     0,
       0,   107,     0,     0,     0,     0,     0,   535,   542,   533,
     539,   532,   338,   348,   371,     0,   372,   688,     0,   397,
       0,     0,   313,     0,     0,   316,     0,     0,   426,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     3,     1,     5,     7,     0,     0,
       0,    12,    10,    14,    15,     0,   129,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   151,   170,   166,
     172,   167,   169,   168,   175,   176,     0,     0,     0,     0,
     305,     0,     0,   303,     0,   256,     0,   304,   297,   302,
     301,   300,   299,   298,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,   292,   289,     0,   311,   315,     0,     0,
       0,   325,   355,   328,   327,   339,   354,     0,     0,   104,
       0,     0,     0,     0,     0,   488,     0,     0,     0,     0,
       0,   477,     0,   478,     0,   115,     0,   116,   112,   111,
     114,     0,    95,    96,    48,    49,   528,    57,     0,     0,
      42,    43,     0,     0,     0,     0,     0,     0,     0,     0,
     499,   500,   501,     0,     0,     0,     0,   732,   733,     0,
      47,   725,   726,   727,   728,   729,   730,   731,    86,     0,
       0,     0,     0,   479,     0,     0,     0,    66,     0,     0,
       0,    58,     0,   236,     0,     0,     0,   188,   189,     0,
       0,   153,   154,     0,     0,   174,     0,     0,     0,   474,
       0,     0,     0,   482,     0,     0,     0,     0,     0,   373,
     398,   397,   394,     0,     0,   428,   427,   312,   487,     0,
     425,     0,   512,   513,   473,     0,     0,     0,     0,     0,
       0,   518,     0,     0,     0,   191,   208,   108,   109,     0,
      18,     0,    20,   132,     0,     0,     0,     0,     0,   152,
     209,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     250,   254,   260,   259,   258,     0,   255,   252,   253,     0,
       0,     0,   717,   262,   696,   704,   706,   708,   710,   712,
     715,   268,   267,   265,   271,   272,   273,   270,   275,   276,
     279,   278,     0,     0,     0,     0,   308,     0,   320,   321,
       0,   356,   377,   379,     0,   102,     0,   306,     0,     0,
       0,     0,   492,     0,   489,   437,     0,   436,   445,   446,
       0,     0,     0,    46,     0,     0,     0,     0,     0,    70,
      72,    73,    76,    79,     0,     0,     0,    56,     0,     0,
     734,   735,     0,   736,   740,     0,     0,   769,   738,   739,
     768,   737,   741,     0,   748,   770,     0,     0,     0,   481,
     480,   447,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   695,
       0,     0,   155,   156,     0,   161,   495,   475,   476,     0,
       0,   485,     0,   483,   441,     0,     0,   108,   397,   395,
       0,   386,     0,   375,   376,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,   130,     0,   162,   220,   216,
     218,     0,   210,   211,     0,   536,   544,   453,   454,   460,
     461,   463,     0,   178,     0,     0,     0,     0,     0,     0,
       0,   257,     0,     0,   711,     0,   263,     0,   724,     0,
       0,     0,     0,     0,     0,     0,   697,   701,   719,   700,
     723,   721,   720,   722,     0,     0,     0,   713,   776,   774,
     778,   716,   281,   283,   285,   451,   287,   309,   357,     0,
     378,   105,   307,     0,     0,   242,     0,     0,     0,   496,
       0,     0,   438,     0,    97,     0,   120,   118,     0,   117,
       0,    54,    55,    52,    53,     0,    74,    75,    77,     0,
      78,    44,    45,    50,    51,    41,     0,     0,     0,   743,
       0,   742,   759,     0,     0,     0,   448,     0,    68,    62,
      65,    64,     0,    60,     0,   234,   238,     0,     0,   103,
       0,   193,     0,     0,     0,     0,     0,   157,     0,     0,
       0,     0,   202,     0,   199,   204,   160,     0,     0,     0,
     442,   235,   398,     0,   387,     0,   421,   418,     0,   422,
     423,     0,     0,   424,   417,     0,   392,   420,   419,     0,
       0,     0,   505,   506,   502,     0,     0,   510,   511,   507,
     516,   514,     0,     0,     0,   520,     0,   521,   522,     0,
       0,   217,   229,     0,   230,     0,   221,   222,   223,   224,
       0,   213,     0,   177,     0,     0,   457,   459,   458,   455,
     186,   187,   180,     0,   182,   179,     0,     0,     0,   718,
     714,     0,   771,   772,   792,   791,   787,     0,     0,     0,
       0,   773,   705,   786,   698,     0,     0,   703,   702,   707,
       0,     0,   777,   775,   452,   380,     0,     0,     0,   243,
     439,     0,   493,   494,   497,   490,   491,   122,     0,     0,
      98,     0,   119,    71,    80,   757,     0,     0,   755,   751,
       0,     0,     0,    81,    82,     0,     0,   449,     0,    67,
       0,    61,   237,   239,    13,   190,   195,   194,     0,   197,
       0,     0,     0,   159,   200,   203,     0,   443,     0,   486,
     484,   397,     0,     0,   429,     0,   397,     0,   393,     9,
       0,     0,     0,     0,     0,   519,     0,     0,   523,     0,
     192,   233,   231,   232,   225,   226,   227,   219,     0,   214,
     212,   462,   456,   184,   181,     0,   183,   793,     0,     0,
     779,     0,   790,   789,   788,   783,   784,   699,   709,   785,
       0,     0,     0,     0,   440,   123,    99,   121,     0,   125,
       0,     0,   758,   760,   762,   764,     0,   756,     0,     0,
       0,   746,     0,   744,     0,     0,     0,     0,   450,     0,
      63,   196,   198,   207,   206,   201,   158,   444,     0,   397,
       0,   124,     0,   397,   503,   504,   508,   509,   515,   517,
       0,   694,   228,   215,   185,   781,   780,     0,     0,   244,
       0,   240,   100,   767,   766,   761,   765,   763,   752,   753,
       0,   749,     0,    93,    89,    91,     0,    87,     0,   246,
      69,     0,   407,   401,   396,     0,   397,   388,     0,     0,
       0,   782,     0,     0,     0,     0,   747,   745,     0,    92,
      94,    88,     0,   415,   409,     0,   408,   410,   416,   413,
     403,     0,   402,   404,   414,   390,     0,   389,     0,   524,
       0,   241,   754,   750,    90,   205,   400,   411,   412,   399,
     405,   406,   391,     0,   245,     0,     0,     0,   525,     0,
       0,     0,     0,   526,     0,     0,   527
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -988,  -988,   758,  -988,   759,   761,  -988,   764,  -988,   490,
     493,  -459,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,  -988,  -988,  -988,  -797,  -988,  -988,  -988,  -988,
      13,   193,  -988,  -988,  -988,  -988,  -183,   574,  -322,  -988,
    -267,  -988,   208,  -988,  -721,  -988,  -988,  -988,  -988,  -988,
    -988,   236,   195,  -988,  -988,  -148,  -988,  -848,   765,   -80,
    -988,   499,  -285,  -988,  -988,  -988,  -988,   153,  -988,  -988,
     732,  -988,  -988,  -988,  -988,  -988,   103,  -466,  -609,  -988,
    -988,  -988,    -6,  -988,  -988,  -173,   -20,   -65,  -988,  -988,
    -988,   -79,  -988,  -988,   120,   -73,  -988,  -988,   -69,  -981,
    -988,   554,    10,  -988,  -988,    56,  -988,  -988,   495,   497,
    -988,  -391,  -876,   474,   110,  -499,   106,   112,  -988,  -988,
    -988,  -988,  -988,   740,  -988,  -988,  -988,  -988,  -988,   724,
    -988,  -988,  -100,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
     -27,  -180,  -988,  -988,   228,    -7,  -988,  -515,  -988,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -823,  -988,   -17,
    -988,   349,  -644,  -988,  -988,  -988,  -988,  -988,  -323,  -314,
    -987,  -792,  -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,
    -988,  -988,   268,  -621,  -728,  -988,   238,  -102,  -682,  -988,
    -988,  -988,  -988,  -988,  -988,  -988,   596,   604,  -672,   252,
    -988,  -988,  -988,  -988,  -988,  -988,  -988,  -988,   -37,  -988,
    -988,   -40,  -383,  -340,   -10,  -988,   299,  -988,  -988,   108,
      97,   -87,   304,  -988,  -988,   111,  -988,  -680,  -988,  -988,
    -988,  -988,  -218,  -777,  -988,  -112,  -575,  -988,  -643,  -988,
    -988,  -988,  -988,  -904,  -988,  -988,  -988,  -988,   -75,   118,
    -988
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   978,   620,   228,   229,   769,
     770,   771,   584,   230,  1135,   231,   400,   401,  1283,  1284,
    1235,   232,   761,   233,   330,   234,   235,   236,   237,   238,
     239,   402,   403,   567,   945,   946,  1023,   949,   240,   241,
     477,   242,   243,   244,   487,   419,   824,   825,   245,   488,
     246,   490,   247,   248,   249,   494,   495,  1002,   697,   250,
     627,   674,   628,   634,  1003,  1004,  1005,   675,   491,   492,
     872,   873,  1189,   493,   869,   870,  1056,  1057,  1058,  1059,
     251,   622,   623,   252,   934,   935,   253,   254,   255,   256,
     705,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   514,   515,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   541,   542,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   744,   297,   298,   299,  1025,
     651,   652,   653,  1294,  1321,  1322,  1315,  1316,  1323,  1317,
    1026,  1027,   300,   301,  1028,   302,   303,   304,   305,   306,
     307,   308,   924,   698,   877,  1069,   878,   879,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   369,   938,
     319,   320,   321,   322,   323,   324,   325,   670,   671,   326,
    1047,  1048,   979,   408,   327,   328,   713,   906,   714,   715,
     716,   717,   718,   719,   720,   907,   908,   600,   601,   602,
     603,   604,  1280,  1281,   605,  1222,  1128,  1226,  1223,   606,
     607,   910,   921,  1090,   911,   912,   917,   913,  1205,  1086,
     896
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       370,   712,   374,   812,   922,   923,   577,   840,   818,   971,
     880,   983,  1101,   462,   438,   682,   609,   681,   445,  1024,
     817,   724,   725,   726,   727,   931,   617,   621,  1094,   468,
     696,     4,   432,   447,   909,  1087,  1276,   692,  1168,   469,
     380,   381,   382,   383,   384,   385,   549,   426,   550,   433,
     880,   880,   692,   386,   693,   589,   380,   381,   382,   383,
     384,   385,   821,   434,   655,   885,   693,   614,   993,   386,
    1087,   809,   625,  1292,   637,   387,  1185,  1186,   677,   937,
     678,   940,   576,   816,   880,   439,   388,   886,   389,   890,
     576,   390,   475,   585,   391,   405,  1198,   612,   586,   443,
     392,   393,   694,   475,  1126,   444,   862,  1066,   701,    65,
     702,   703,   638,   704,   888,   706,   392,   393,   394,   968,
     858,    76,   845,   707,   708,   918,   919,   535,   331,  1313,
     630,   809,   943,  1016,   524,  1313,  1130,  1067,   751,  1016,
     574,  1076,   863,   525,   329,    90,   782,   920,   810,   709,
     109,   958,   710,   587,   405,  1068,  1016,  1017,  1008,  1293,
    1009,  1127,   395,   618,  1199,   662,   663,   847,   665,   666,
     667,   668,   476,   575,   673,   537,  1168,  1212,   753,   450,
     846,   451,   830,   865,   695,  1141,  1132,  1277,  1088,  1089,
     683,   695,  1024,  1131,  1013,   712,   712,   944,   822,   996,
     689,   690,  1024,  1262,   777,  1107,   695,   619,   836,   994,
     448,   639,   593,   588,   752,   616,   656,   851,  1016,  1017,
    1207,   695,   396,  1088,  1089,  1229,  1098,  1016,  1017,  1122,
     397,   823,   889,   695,  1019,  1228,  1020,   807,   496,  1018,
    1019,  1213,  1020,   470,  1314,   859,   397,   692,   613,   548,
    1337,   880,   711,   543,   754,   470,   545,  1019,   831,  1020,
     695,  1016,   743,  1021,   332,   837,   832,   398,   399,  1021,
     433,   929,  1319,   433,   406,   783,   803,   407,   551,   806,
    1077,   692,  1119,   398,   399,   841,  1021,   462,   848,   849,
      95,   553,   554,   333,  1014,   559,   560,   811,   562,  1133,
    1134,  1018,  1230,   850,   784,   785,   107,   786,   787,  1232,
    1018,  1267,  1286,   524,   891,   572,  1082,  1016,  1017,  1019,
    1220,  1020,   525,  1016,   610,   478,   611,  1022,  1019,   573,
    1020,   995,   479,   371,  1319,   480,   481,  1299,   852,   853,
    1024,  1305,   833,   482,   642,   134,   594,   930,  1021,  1083,
     842,  1305,    95,   854,   595,   517,     4,  1021,  1120,  1015,
     654,    95,  1019,   557,  1020,  1286,   659,   596,   107,   597,
     564,   520,   518,  1320,  1304,  1053,   571,   107,  1231,   598,
    1345,  1350,   599,  1221,   453,  1233,   454,   712,  1287,  1162,
    1216,  1021,   961,   962,  1055,   519,   965,   521,  1167,   712,
    1018,   624,   868,   626,   629,   682,  1095,   134,   933,   883,
     522,   376,   636,  1300,   377,   645,   134,  1306,  1019,   524,
    1020,  1108,   766,   517,  1019,   624,  1020,  1307,   525,   483,
     988,   484,   791,   375,    65,  1340,   880,   968,   738,   739,
     518,  1311,  1290,   404,   523,   485,    76,  1021,   672,   951,
     676,    95,  1329,  1021,   969,   737,  1346,  1351,   416,   417,
     740,   792,   793,   767,   794,   795,   952,   107,   768,   526,
      90,   486,   748,   411,   709,   953,   897,   710,   756,   580,
     593,  1202,   527,   957,   998,   999,   456,  1203,  1250,   960,
    1272,   457,   954,   581,   970,  1204,  1215,  1052,  1348,   578,
    1318,  1324,   418,  1353,   693,   947,   134,  1356,  1053,   412,
     544,   973,   998,   999,   579,  1000,   546,  1248,  1054,   897,
     948,   413,  1252,   593,  1318,   985,   986,  1055,  1333,   989,
    1324,   991,   693,   414,   741,   802,   880,   741,  1202,   741,
    1302,   380,   381,   382,  1203,   898,   385,  1030,   773,  1031,
    1084,  1011,  1204,   774,  1001,  1085,   762,   767,   409,   398,
     461,   410,   768,  1032,  1033,  1034,   835,  1037,  1038,  1039,
    1040,  1041,  1042,   772,  1044,  1045,   565,   538,   539,  1275,
     570,   868,  1197,   415,  1275,   712,   880,   420,   898,  1200,
    1201,   421,   378,   780,  1139,   379,   781,  1035,   788,  1036,
    1072,   789,  1074,  1075,   422,  1295,   590,   591,   592,  1298,
     398,   399,   963,   964,   594,   998,   999,  1182,  1183,   568,
     569,   423,   595,   820,   899,   900,   901,   721,   722,   892,
     728,   729,   925,   925,   902,   596,   435,   597,   730,   731,
     838,   441,   903,   440,  1105,  1273,  1274,   598,   904,   905,
     599,   446,  1326,   449,   455,   452,   458,   594,   459,   460,
     463,   465,   473,   474,  1309,   595,   498,   899,   900,   901,
    1181,   497,   516,   528,  1124,   529,   867,   530,   596,   531,
     597,   540,   881,   552,   547,   903,   558,   561,   563,  1136,
     598,  1096,   905,   599,   380,   566,   576,   582,   583,  1265,
    1266,   405,  1143,   399,   615,   633,   631,  1146,  1147,   499,
    1149,   635,   632,   646,   373,  1153,   650,   500,   501,   377,
     502,   379,   881,   881,   881,   881,   407,   503,   425,   648,
     649,   504,   657,   505,   658,   660,   661,   669,   506,   664,
     686,   939,   691,   939,   685,   732,   733,   734,   687,   688,
     735,   745,   746,   749,   507,   760,   881,  1240,   763,   778,
     775,   764,   765,   747,  1179,   750,   776,   779,  1301,   757,
     758,   759,   790,   804,   796,   868,   798,   797,   508,   509,
     510,   511,   512,   513,   799,   805,   808,   800,  1193,   813,
     814,  1194,   815,  1196,   819,   826,   827,   829,   843,   828,
     844,   855,   860,   861,   871,  1263,   856,   866,   864,   874,
     857,   882,   884,   887,   895,   914,   916,   928,   915,   927,
     370,   932,   370,   933,   936,   942,   692,   768,   959,   966,
     975,   976,   967,   972,   982,   980,   974,   984,   977,   981,
     987,   992,   990,  1010,   997,  1007,  1012,  1029,  1043,  1049,
    1060,  1050,  1062,  1064,  1073,  1046,  1111,  1078,  1080,  1065,
    1100,  1061,  1079,  1241,   496,  1242,  1103,  1104,  1121,  1114,
    1118,  1246,  1070,  1081,  1071,  1091,  1129,  1140,  1102,  1125,
    1112,  1113,  1148,  1151,  1152,  1254,  1255,  1256,  1257,  1258,
    1144,  1259,  1150,  1156,  1115,  1138,  1164,  1116,  1159,  1161,
    1160,  1174,  1170,  1171,  1176,  1169,  1172,  1177,  1053,  1188,
    1264,  1173,  1191,  1209,  1192,  1195,  1211,  1214,   943,  1218,
    1224,  1219,  1225,   881,  1236,  1334,  1269,  1158,  1271,  1237,
    1234,  1238,  1239,  1117,  1268,  1247,  1251,  1278,  1261,  1279,
    1291,  1165,   968,  1297,  1303,  1308,  1312,  1328,   948,  1285,
    1330,  1336,  1289,  1325,  1327,  1347,  1342,  1339,  1332,  1352,
     956,   464,  1355,   679,  1310,   466,   680,   467,  1123,  1288,
     950,  1217,   608,   471,   624,   472,   684,  1063,  1006,   489,
     629,  1245,  1155,  1190,  1145,  1180,  1051,  1187,  1184,   647,
    1109,  1154,   699,   723,  1142,   700,   536,  1260,  1163,  1341,
     839,  1285,  1338,   926,   955,   941,  1175,  1178,   534,   893,
    1092,  1099,  1166,  1208,  1282,   894,  1227,  1097,  1331,   640,
    1206,  1093,     0,     0,     0,     0,     0,   641,     0,     0,
       0,     0,     0,   672,     0,     0,     0,     0,     0,     0,
     676,     0,     0,     0,     0,  1344,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   881,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1243,  1244,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1249,     0,     0,     0,     0,  1253,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   433,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1270,     0,     0,     0,     0,     0,   881,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   881,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1335,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1343,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,  1349,     5,     6,
       7,     8,  1354,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     0,     0,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,    63,    64,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,     0,    77,    78,    79,    80,     0,    81,
       0,     0,     0,    82,    83,    84,    85,    86,     0,     0,
       0,     0,     0,    87,    88,    89,    90,    91,    92,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,   108,   109,     0,     0,   110,   111,   112,     0,
       0,     0,   113,     0,   114,   115,   116,     0,   117,   118,
     119,     0,   120,     0,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,     0,   132,   133,   134,
       0,   135,   136,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,   173,   174,     0,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     0,     9,    10,    11,    12,    13,
      14,    15,   343,    17,    18,     0,     0,     0,     0,    19,
      20,    21,   346,    23,    24,   348,    26,    27,    28,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,    63,    64,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,    77,    78,    79,    80,
       0,    81,     0,     0,     0,    82,    83,    84,    85,    86,
       0,     0,     0,     0,     0,    87,    88,    89,    90,    91,
      92,    93,     0,     0,     0,    94,    95,    96,    97,    98,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,   108,   109,     0,     0,   110,   111,
     112,     0,     0,     0,   113,   436,   114,   115,   116,     0,
     117,   118,   119,     0,   120,     0,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,     0,   132,
     133,   134,     0,     0,   136,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,   173,   174,     0,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   437,   197,
     198,   199,   200,   201,   202,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     0,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,    63,    64,
       0,     0,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,    76,     0,    77,    78,    79,
      80,     0,    81,     0,     0,     0,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,    87,    88,    89,    90,
      91,    92,    93,     0,     0,     0,    94,    95,    96,    97,
      98,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,   109,     0,     0,   110,
     111,   112,     0,     0,     0,   113,     0,   114,   115,   116,
       0,   117,   118,   119,     0,   120,     0,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,     0,     0,
     132,   133,   134,     0,   135,   136,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,     0,   173,   174,     0,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     0,     9,    10,    11,
      12,    13,    14,    15,   343,    17,    18,     0,     0,     0,
       0,    19,    20,    21,   346,    23,    24,   348,    26,    27,
      28,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,    63,
      64,     0,     0,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,     0,    77,    78,
      79,    80,     0,    81,     0,     0,     0,    82,    83,    84,
      85,    86,     0,     0,     0,     0,     0,    87,    88,    89,
      90,    91,    92,    93,     0,     0,     0,    94,    95,    96,
      97,    98,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,   108,   109,     0,     0,
     110,   111,   112,     0,   736,     0,   113,     0,   114,   115,
     116,     0,   117,   118,   119,     0,   120,     0,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,   132,   133,   134,     0,     0,   136,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,   173,   174,     0,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     437,   197,   198,   199,   200,   201,   202,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     0,     9,    10,
      11,    12,    13,    14,    15,   343,    17,    18,     0,     0,
       0,     0,    19,    20,    21,   346,    23,    24,   348,    26,
      27,    28,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,     0,
      63,    64,     0,     0,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     0,    76,     0,    77,
      78,    79,    80,     0,    81,     0,     0,     0,    82,    83,
      84,    85,    86,     0,     0,     0,     0,     0,    87,    88,
      89,    90,    91,    92,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,   108,   109,     0,
       0,   110,   111,   112,     0,     0,     0,   113,   742,   114,
     115,   116,     0,   117,   118,   119,     0,   120,     0,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
       0,     0,   132,   133,   134,     0,     0,   136,     0,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,   173,   174,     0,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   437,   197,   198,   199,   200,   201,   202,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     0,     9,
      10,    11,    12,    13,    14,    15,   343,    17,    18,     0,
       0,     0,     0,    19,    20,    21,   346,    23,    24,   348,
      26,    27,    28,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,    63,    64,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
      77,    78,    79,    80,     0,    81,     0,     0,     0,    82,
      83,    84,    85,    86,     0,     0,     0,     0,     0,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,    94,
      95,    96,    97,    98,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,   108,   109,
       0,     0,   110,   111,   112,     0,   755,     0,   113,     0,
     114,   115,   116,     0,   117,   118,   119,     0,   120,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,     0,   132,   133,   134,     0,     0,   136,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,   173,   174,
       0,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   437,   197,   198,   199,   200,   201,   202,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     0,
       9,    10,    11,    12,    13,    14,    15,   343,    17,    18,
       0,     0,     0,     0,    19,    20,    21,   346,    23,    24,
     348,    26,    27,    28,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,    63,    64,     0,     0,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,     0,    76,
       0,    77,    78,    79,    80,     0,    81,     0,     0,     0,
      82,    83,    84,    85,    86,     0,     0,     0,     0,     0,
      87,    88,    89,    90,    91,    92,    93,     0,     0,     0,
      94,    95,    96,    97,    98,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,   108,
     109,     0,     0,   110,   111,   112,     0,   801,     0,   113,
       0,   114,   115,   116,     0,   117,   118,   119,     0,   120,
       0,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,     0,     0,   132,   133,   134,     0,     0,   136,
       0,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,     0,   173,
     174,     0,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   437,   197,   198,   199,   200,   201,   202,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       0,     9,    10,    11,    12,    13,    14,    15,   343,    17,
      18,     0,     0,     0,     0,    19,    20,    21,   346,    23,
      24,   348,    26,    27,    28,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,     0,    63,    64,     0,     0,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
      76,     0,    77,    78,    79,    80,     0,    81,     0,     0,
       0,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,    94,    95,    96,    97,    98,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
     108,   109,     0,     0,   110,   111,   112,     0,   834,     0,
     113,     0,   114,   115,   116,     0,   117,   118,   119,     0,
     120,     0,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,     0,     0,   132,   133,   134,     0,     0,
     136,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
     173,   174,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   437,   197,   198,   199,   200,   201,
     202,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     0,     9,    10,    11,    12,    13,    14,    15,   343,
      17,    18,     0,     0,     0,     0,    19,    20,    21,   346,
      23,    24,   348,    26,    27,    28,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,    63,    64,     0,     0,     0,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       0,    76,     0,    77,    78,    79,    80,     0,    81,     0,
       0,     0,    82,    83,    84,    85,    86,     0,     0,     0,
       0,     0,    87,    88,    89,    90,    91,    92,    93,     0,
       0,     0,    94,    95,    96,    97,    98,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,   108,   109,     0,     0,   110,   111,   112,     0,  1110,
       0,   113,     0,   114,   115,   116,     0,   117,   118,   119,
       0,   120,     0,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,   132,   133,   134,     0,
       0,   136,     0,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
       0,   173,   174,     0,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   437,   197,   198,   199,   200,
     201,   202,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     0,     9,    10,    11,    12,    13,    14,    15,
     343,    17,    18,     0,     0,     0,     0,    19,    20,    21,
     346,    23,    24,   348,    26,    27,    28,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,    63,    64,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,     0,    77,    78,    79,    80,     0,    81,
       0,     0,     0,    82,    83,    84,    85,    86,     0,     0,
       0,     0,     0,    87,    88,    89,    90,    91,    92,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,   108,   109,     0,     0,   110,   111,   112,     0,
    1137,     0,   113,     0,   114,   115,   116,     0,   117,   118,
     119,     0,   120,     0,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,     0,   132,   133,   134,
       0,     0,   136,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,   173,   174,     0,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   437,   197,   198,   199,
     200,   201,   202,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     0,     9,    10,    11,    12,    13,    14,
      15,   343,    17,    18,     0,     0,     0,     0,    19,    20,
      21,   346,    23,    24,   348,    26,    27,    28,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,     0,    63,    64,     0,     0,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,     0,    76,     0,    77,    78,    79,    80,     0,
      81,     0,     0,     0,    82,    83,    84,    85,    86,     0,
       0,     0,     0,     0,    87,    88,    89,    90,    91,    92,
      93,     0,     0,     0,    94,    95,    96,    97,    98,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   108,   109,     0,     0,   110,   111,   112,
       0,  1157,     0,   113,     0,   114,   115,   116,     0,   117,
     118,   119,     0,   120,     0,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,     0,   132,   133,
     134,     0,     0,   136,     0,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,     0,   173,   174,     0,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   437,   197,   198,
     199,   200,   201,   202,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     0,     0,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,    63,    64,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,    77,    78,    79,    80,
       0,    81,     0,     0,     0,    82,    83,    84,    85,    86,
       0,     0,     0,     0,     0,    87,    88,    89,    90,    91,
      92,    93,     0,     0,     0,    94,    95,    96,    97,    98,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,   108,   109,     0,     0,   110,   111,
     112,     0,     0,     0,   113,     0,   114,   115,   116,     0,
     117,   118,   119,     0,   120,     0,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,     0,   132,
     133,   134,     0,     0,   136,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,   173,   174,     0,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     0,     9,    10,    11,    12,
      13,    14,    15,   343,    17,    18,     0,     0,     0,     0,
      19,    20,    21,   346,    23,    24,   348,    26,    27,    28,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,    63,    64,
       0,     0,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,    76,     0,    77,    78,    79,
      80,     0,    81,     0,     0,     0,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,    87,    88,    89,    90,
      91,    92,    93,     0,     0,     0,    94,    95,    96,    97,
      98,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,   109,     0,     0,   110,
     111,   112,     0,     0,     0,   113,     0,   114,   115,   116,
       0,   117,   118,   119,     0,   120,     0,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,     0,     0,
     132,   133,   134,     0,     0,   136,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,     0,   173,   174,     0,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   437,
     197,   198,   199,   200,   201,   202,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,   334,   335,   336,     8,     0,     0,    10,   338,
      12,    13,    14,    15,   343,    17,    18,     0,     0,     0,
       0,   344,    20,    21,   346,   347,    24,   348,    26,    27,
      28,     0,   349,   350,    31,     0,   351,   352,    35,    36,
      37,    38,    39,    40,    41,    42,   353,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,    63,
      64,     0,     0,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,     0,    77,    78,
      79,    80,     0,    81,     0,     0,     0,   357,    83,    84,
      85,    86,     0,     0,     0,     0,     0,    87,    88,    89,
      90,    91,    92,    93,     0,     0,     0,    94,    95,   532,
      97,    98,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,   533,   109,     0,     0,
     110,   111,   112,     0,     0,     0,   113,     0,   114,   115,
     116,     0,   117,   118,   119,     0,   120,     0,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,   132,   133,   134,     0,     0,   136,     0,   137,   138,
     139,   140,   141,   142,   143,   361,   145,   363,   147,   364,
     365,   150,   151,   152,   153,   154,   155,   366,   157,     0,
       0,     0,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,   173,   174,     0,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     367,   368,   198,   199,   200,   201,   202,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,   334,   335,   336,     8,     0,     0,    10,
     338,    12,    13,    14,    15,   343,    17,    18,     0,     0,
       0,     0,   344,    20,    21,   346,   347,    24,   348,    26,
      27,    28,     0,   349,   350,    31,     0,   351,   352,    35,
      36,    37,    38,    39,    40,    41,    42,   353,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,     0,
      63,    64,     0,     0,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     0,    76,     0,    77,
      78,    79,    80,     0,    81,     0,     0,     0,   357,    83,
      84,    85,    86,     0,     0,     0,     0,     0,    87,    88,
      89,    90,    91,    92,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,   108,   109,     0,
       0,   110,   111,   112,     0,     0,     0,   113,     0,   114,
     115,   116,     0,   117,   118,   119,     0,   120,     0,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
       0,     0,   132,   133,   134,     0,     0,   136,     0,   137,
     138,   139,   140,   141,   142,   143,   361,   145,   363,   147,
     364,   365,   150,   151,   152,   153,   154,   155,   366,   157,
       0,     0,     0,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,   173,   174,     0,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   367,   368,   198,   199,   200,   201,   202,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     0,   334,   335,   336,     8,     0,     0,
     337,   338,    12,    13,    14,    15,   343,    17,    18,     0,
       0,     0,     0,   344,    20,    21,   346,   347,    24,   348,
      26,    27,    28,     0,   349,   350,    31,     0,   351,   352,
      35,    36,    37,    38,    39,    40,    41,    42,   353,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,    63,    64,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
      77,    78,    79,    80,     0,    81,     0,     0,     0,   357,
      83,    84,    85,    86,     0,     0,     0,     0,     0,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,    94,
      95,     0,    97,    98,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,     0,     0,
       0,     0,   110,   111,   112,     0,     0,     0,   113,     0,
     114,   115,   116,     0,     0,     0,   119,     0,   120,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,     0,   132,   133,   134,     0,     0,   136,     0,
     137,   138,   139,   140,   141,   142,   143,   361,   145,   363,
     147,   364,   365,   150,   151,   152,   153,   154,   155,   366,
     157,     0,     0,     0,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,   173,   174,
       0,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   367,   368,   198,   199,   200,   201,   202,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     0,
       0,     0,     0,     0,     0,   334,   335,   336,     8,     0,
       0,   337,   338,   427,   340,   428,   429,   343,    17,    18,
       0,     0,     0,     0,   344,   430,    21,   346,   347,    24,
     348,    26,    27,    28,     0,   349,   350,    31,     0,   351,
     352,    35,    36,    37,    38,    39,    40,    41,    42,   353,
      44,    45,    46,    47,    48,    49,    50,     0,     0,    53,
       0,    54,    55,    56,   431,     0,     0,    60,    61,    62,
       0,     0,     0,    64,     0,     0,     0,     0,    66,    67,
      68,     0,     0,    71,    72,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,     0,    81,     0,     0,     0,
     357,    83,    84,     0,     0,     0,     0,     0,     0,     0,
      87,    88,    89,     0,    91,    92,    93,     0,     0,     0,
       0,     0,     0,    97,    98,     0,     0,     0,     0,    99,
     100,   101,   359,   103,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   112,     0,     0,     0,   113,
       0,   114,   115,     0,     0,     0,     0,   119,     0,   120,
       0,   121,   122,   123,   124,   360,   126,   127,   128,   129,
     130,   131,     0,     0,   132,   133,     0,     0,     0,   136,
       0,   137,   138,   139,   140,   141,   142,   143,   361,   145,
     363,   147,   364,   365,   150,   151,   152,   153,   154,   155,
     366,   157,     0,     0,     0,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,     0,   173,
     174,     0,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   367,   368,   198,   199,   200,   201,   202,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       0,     0,     0,     0,     0,     0,   334,   335,   336,     8,
       0,     0,   337,   338,   339,   340,   341,   342,   343,    17,
      18,     0,     0,     0,     0,   344,   345,    21,   346,   347,
      24,   348,    26,    27,    28,     0,   349,   350,    31,     0,
     351,   352,    35,    36,    37,    38,    39,    40,    41,    42,
     353,    44,   354,   355,    47,    48,    49,    50,     0,     0,
      53,     0,    54,    55,    56,   356,     0,     0,    60,    61,
      62,     0,     0,     0,    64,     0,     0,     0,     0,    66,
      67,    68,     0,     0,    71,    72,     0,     0,     0,     0,
       0,     0,    77,    78,    79,    80,     0,    81,     0,     0,
       0,   357,    83,    84,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,     0,    91,    92,    93,     0,     0,
       0,     0,     0,     0,    97,    98,     0,     0,     0,     0,
      99,   100,   101,   359,   103,   104,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,     0,     0,     0,
     113,     0,   114,     0,     0,     0,     0,     0,   119,     0,
     120,     0,   121,   122,   123,   124,   360,   126,   127,   128,
     129,   130,   131,     0,     0,   132,   133,     0,     0,     0,
     136,     0,   137,   138,   139,   140,   141,   142,   143,   361,
     362,   363,   147,   364,   365,   150,   151,   152,   153,   154,
     155,   366,   157,     0,     0,     0,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
     173,   174,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   367,   368,   198,   199,   200,   201,
     202,   442,     0,     3,     0,     0,     0,     0,     0,     0,
       0,   334,   335,   336,     8,     0,     0,   337,   338,   339,
     340,   341,   342,   343,    17,    18,     0,     0,     0,     0,
     344,   345,    21,   346,   347,    24,   348,    26,    27,    28,
       0,   349,   350,    31,     0,   351,   352,    35,    36,    37,
      38,    39,    40,    41,    42,   353,    44,   354,   355,    47,
      48,    49,    50,     0,     0,    53,     0,    54,    55,    56,
     356,     0,     0,    60,    61,    62,     0,     0,     0,    64,
       0,     0,     0,     0,    66,    67,    68,     0,     0,    71,
      72,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,     0,    81,     0,     0,     0,   357,    83,    84,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,     0,
      91,    92,    93,     0,     0,     0,     0,     0,     0,    97,
      98,     0,     0,     0,     0,    99,   100,   101,   359,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,     0,     0,   113,     0,   114,     0,     0,
       0,     0,     0,     0,     0,   120,     0,   121,   122,   123,
     124,   360,   126,   127,   128,   129,   130,   131,     0,     0,
     132,   133,     0,     0,     0,   136,     0,   137,   138,   139,
     140,   141,   142,   143,   361,   362,   363,   147,   364,   365,
     150,   151,   152,   153,   154,   155,   366,   157,     0,     0,
       0,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,     0,   173,   174,     0,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   367,
     368,   198,   199,   200,   201,   202,     3,     0,     0,     0,
       0,     0,     0,     0,   334,   335,   336,     8,     0,     0,
     337,   338,   339,   340,   341,   342,   343,    17,    18,     0,
       0,     0,     0,   344,   345,    21,   346,   347,    24,   348,
      26,    27,    28,     0,   349,   350,    31,     0,   351,   352,
      35,    36,    37,    38,    39,    40,    41,    42,   353,    44,
     354,   355,    47,    48,    49,    50,     0,     0,    53,     0,
      54,    55,    56,   356,     0,     0,    60,    61,    62,     0,
       0,     0,    64,     0,     0,     0,     0,    66,    67,    68,
       0,     0,    71,    72,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,     0,    81,     0,     0,     0,   357,
      83,    84,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,     0,    91,    92,    93,   372,     0,     0,   373,
       0,     0,    97,    98,     0,     0,     0,     0,    99,   100,
     101,   359,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,     0,     0,     0,   113,     0,
     114,     0,     0,     0,     0,     0,     0,     0,   120,     0,
     121,   122,   123,   124,   360,   126,   127,   128,   129,   130,
     131,     0,     0,   132,   133,     0,     0,     0,   136,     0,
     137,   138,   139,   140,   141,   142,   143,   361,   362,   363,
     147,   364,   365,   150,   151,   152,   153,   154,   155,   366,
     157,     0,     0,     0,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,   173,   174,
       0,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   367,   368,   198,   199,   200,   201,   202,     3,
       0,     0,     0,     0,     0,     0,     0,   334,   335,   336,
       8,     0,     0,   337,   338,   339,   340,   341,   342,   343,
      17,    18,     0,     0,     0,     0,   344,   345,    21,   346,
     347,    24,   348,    26,    27,    28,     0,   349,   350,    31,
       0,   351,   352,    35,    36,    37,    38,    39,    40,    41,
      42,   353,    44,   354,   355,    47,    48,    49,    50,     0,
       0,    53,     0,    54,    55,    56,   356,     0,     0,    60,
      61,    62,     0,     0,     0,    64,     0,     0,     0,     0,
      66,    67,    68,     0,     0,    71,    72,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,     0,    81,     0,
       0,     0,   357,    83,    84,     0,     0,     0,     0,     0,
       0,     0,    87,    88,    89,     0,    91,    92,    93,   424,
       0,     0,   425,     0,     0,    97,    98,     0,     0,     0,
       0,    99,   100,   101,   359,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,     0,     0,
       0,   113,     0,   114,     0,     0,     0,     0,     0,     0,
       0,   120,     0,   121,   122,   123,   124,   360,   126,   127,
     128,   129,   130,   131,     0,     0,   132,   133,     0,     0,
       0,   136,     0,   137,   138,   139,   140,   141,   142,   143,
     361,   362,   363,   147,   364,   365,   150,   151,   152,   153,
     154,   155,   366,   157,     0,     0,     0,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
       0,   173,   174,     0,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   367,   368,   198,   199,   200,
     201,   202,     3,     0,     0,     0,     0,     0,     0,     0,
     334,   335,   336,     8,     0,     0,   337,   338,   339,   340,
     341,   342,   343,    17,    18,     0,     0,     0,     0,   344,
     345,    21,   346,   347,    24,   348,    26,    27,    28,     0,
     349,   350,    31,     0,   351,   352,    35,    36,    37,    38,
      39,    40,    41,    42,   353,    44,   354,   355,    47,    48,
      49,    50,     0,     0,    53,     0,    54,    55,    56,   356,
       0,     0,    60,    61,    62,     0,     0,     0,    64,     0,
       0,     0,     0,    66,    67,    68,     0,     0,    71,    72,
       0,     0,     0,     0,     0,     0,    77,    78,    79,    80,
       0,    81,     0,     0,     0,   357,    83,    84,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,     0,    91,
      92,    93,     0,     0,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,    99,   100,   101,   359,   103,   104,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,     0,     0,     0,   113,   555,   114,     0,     0,     0,
       0,     0,   556,     0,   120,     0,   121,   122,   123,   124,
     360,   126,   127,   128,   129,   130,   131,     0,     0,   132,
     133,     0,     0,     0,   136,     0,   137,   138,   139,   140,
     141,   142,   143,   361,   362,   363,   147,   364,   365,   150,
     151,   152,   153,   154,   155,   366,   157,     0,     0,     0,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,   173,   174,     0,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   367,   368,
     198,   199,   200,   201,   202,     3,     0,     0,     0,     0,
       0,     0,     0,   334,   335,   336,     8,     0,     0,   337,
     338,   339,   340,   341,   342,   343,    17,    18,     0,     0,
       0,     0,   344,   345,    21,   346,   347,    24,   348,    26,
      27,    28,     0,   349,   350,    31,     0,   351,   352,    35,
      36,    37,    38,    39,    40,    41,    42,   353,    44,   354,
     355,    47,    48,    49,    50,     0,     0,    53,     0,    54,
      55,    56,   356,     0,     0,    60,    61,    62,     0,     0,
       0,    64,     0,     0,     0,     0,    66,    67,    68,     0,
       0,    71,    72,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,     0,    81,     0,     0,     0,   357,    83,
      84,     0,     0,     0,     0,     0,     0,     0,    87,    88,
      89,     0,    91,    92,    93,     0,     0,     0,     0,     0,
       0,    97,    98,     0,     0,     0,     0,    99,   100,   101,
     359,   103,   104,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,     0,     0,     0,   113,   643,   114,
       0,     0,     0,     0,     0,   644,     0,   120,     0,   121,
     122,   123,   124,   360,   126,   127,   128,   129,   130,   131,
       0,     0,   132,   133,     0,     0,     0,   136,     0,   137,
     138,   139,   140,   141,   142,   143,   361,   362,   363,   147,
     364,   365,   150,   151,   152,   153,   154,   155,   366,   157,
       0,     0,     0,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,   173,   174,     0,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   367,   368,   198,   199,   200,   201,   202,     3,     0,
       0,     0,     0,     0,     0,     0,   334,   335,   336,     8,
       0,     0,   337,   338,   427,   340,   428,   429,   343,    17,
      18,     0,     0,     0,     0,   344,   430,    21,   346,   347,
      24,   348,    26,    27,    28,     0,   349,   350,    31,     0,
     351,   352,    35,    36,    37,    38,    39,    40,    41,    42,
     353,    44,    45,    46,    47,    48,    49,    50,     0,     0,
      53,     0,    54,    55,    56,   431,     0,     0,    60,    61,
      62,     0,     0,     0,    64,     0,     0,     0,     0,    66,
      67,    68,     0,     0,    71,    72,  1106,     0,     0,     0,
       0,     0,    77,    78,    79,    80,     0,    81,     0,     0,
       0,   357,    83,    84,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,     0,    91,    92,   875,     0,     0,
       0,     0,     0,     0,    97,    98,     0,     0,     0,     0,
      99,   100,   101,   359,   103,   104,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,     0,     0,     0,
     113,     0,   114,   115,     0,     0,     0,     0,     0,     0,
     120,     0,   121,   122,   123,   124,   360,   126,   127,   128,
     129,   130,   131,     0,     0,   876,   133,     0,     0,     0,
     136,     0,   137,   138,   139,   140,   141,   142,   143,   361,
     145,   363,   147,   364,   365,   150,   151,   152,   153,   154,
     155,   366,   157,     0,     0,     0,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
     173,   174,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   367,   368,   198,   199,   200,   201,
     202,     3,     0,     0,     0,     0,     0,     0,     0,   334,
     335,   336,     8,     0,     0,   337,   338,   339,   340,   341,
     342,   343,    17,    18,     0,     0,     0,     0,   344,   345,
      21,   346,   347,    24,   348,    26,    27,    28,     0,   349,
     350,    31,     0,   351,   352,    35,    36,    37,    38,    39,
      40,    41,    42,   353,    44,   354,   355,    47,    48,    49,
      50,     0,     0,    53,     0,    54,    55,    56,   356,     0,
       0,    60,    61,    62,     0,     0,     0,    64,     0,     0,
       0,     0,    66,    67,    68,     0,     0,    71,    72,     0,
       0,     0,     0,     0,     0,    77,    78,    79,    80,     0,
      81,     0,     0,     0,   357,    83,    84,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    89,     0,    91,    92,
      93,   358,     0,     0,     0,     0,     0,    97,    98,     0,
       0,     0,     0,    99,   100,   101,   359,   103,   104,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
       0,     0,     0,   113,     0,   114,     0,     0,     0,     0,
       0,     0,     0,   120,     0,   121,   122,   123,   124,   360,
     126,   127,   128,   129,   130,   131,     0,     0,   132,   133,
       0,     0,     0,   136,     0,   137,   138,   139,   140,   141,
     142,   143,   361,   362,   363,   147,   364,   365,   150,   151,
     152,   153,   154,   155,   366,   157,     0,     0,     0,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,     0,   173,   174,     0,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   367,   368,   198,
     199,   200,   201,   202,     3,     0,     0,     0,     0,     0,
       0,     0,   334,   335,   336,     8,     0,     0,   337,   338,
     427,   340,   428,   429,   343,    17,    18,     0,     0,     0,
       0,   344,   430,    21,   346,   347,    24,   348,    26,    27,
      28,     0,   349,   350,    31,     0,   351,   352,    35,    36,
      37,    38,    39,    40,    41,    42,   353,    44,    45,    46,
      47,    48,    49,    50,     0,     0,    53,     0,    54,    55,
      56,   431,     0,     0,    60,    61,    62,     0,     0,     0,
      64,     0,     0,     0,     0,    66,    67,    68,     0,     0,
      71,    72,     0,     0,     0,     0,     0,     0,    77,    78,
      79,    80,     0,    81,     0,     0,     0,   357,    83,    84,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
       0,    91,    92,   875,     0,     0,     0,     0,     0,     0,
      97,    98,     0,     0,     0,     0,    99,   100,   101,   359,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,     0,     0,     0,   113,     0,   114,   115,
       0,     0,     0,     0,     0,     0,   120,     0,   121,   122,
     123,   124,   360,   126,   127,   128,   129,   130,   131,     0,
       0,   876,   133,     0,     0,     0,   136,     0,   137,   138,
     139,   140,   141,   142,   143,   361,   145,   363,   147,   364,
     365,   150,   151,   152,   153,   154,   155,   366,   157,     0,
       0,     0,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,   173,   174,     0,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     367,   368,   198,   199,   200,   201,   202,     3,     0,     0,
       0,     0,     0,     0,     0,   334,   335,   336,     8,     0,
       0,   337,   338,   427,   340,   428,   429,   343,    17,    18,
       0,     0,     0,     0,   344,   430,    21,   346,   347,    24,
     348,    26,    27,    28,     0,   349,   350,    31,     0,   351,
     352,    35,    36,    37,    38,    39,    40,    41,    42,   353,
      44,    45,    46,    47,    48,    49,    50,     0,     0,    53,
       0,    54,    55,    56,   431,     0,     0,    60,    61,    62,
       0,     0,     0,    64,     0,     0,     0,     0,    66,    67,
      68,     0,     0,    71,    72,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,     0,    81,     0,     0,     0,
     357,    83,    84,     0,     0,     0,     0,     0,     0,     0,
      87,    88,    89,     0,    91,    92,   875,     0,     0,     0,
       0,     0,     0,    97,    98,     0,     0,     0,     0,    99,
     100,   101,   359,   103,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   112,     0,     0,     0,   113,
       0,   114,   115,     0,     0,     0,     0,     0,     0,   120,
       0,   121,   122,   123,   124,   360,   126,   127,   128,   129,
     130,   131,     0,     0,   132,   133,     0,     0,     0,   136,
       0,   137,   138,   139,   140,   141,   142,   143,   361,   145,
     363,   147,   364,   365,   150,   151,   152,   153,   154,   155,
     366,   157,     0,     0,     0,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,     0,   173,
     174,     0,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   367,   368,   198,   199,   200,   201,   202,
       3,     0,     0,     0,     0,     0,     0,     0,   334,   335,
     336,     8,     0,     0,   337,   338,   339,   340,   341,   342,
     343,    17,    18,     0,     0,     0,     0,   344,   345,    21,
     346,   347,    24,   348,    26,    27,    28,     0,   349,   350,
      31,     0,   351,   352,    35,    36,    37,    38,    39,    40,
      41,    42,   353,    44,   354,   355,    47,    48,    49,    50,
       0,     0,    53,     0,    54,    55,    56,   356,     0,     0,
      60,    61,    62,     0,     0,     0,    64,     0,     0,     0,
       0,    66,    67,    68,     0,     0,    71,    72,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,     0,    81,
       0,     0,     0,   357,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,     0,    91,    92,    93,
       0,     0,     0,     0,     0,     0,    97,    98,     0,     0,
       0,     0,    99,   100,   101,   359,   103,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,     0,
       0,     0,   113,     0,   114,     0,     0,     0,     0,     0,
       0,     0,   120,     0,   121,   122,   123,   124,   360,   126,
     127,   128,   129,   130,   131,     0,     0,   132,   133,     0,
       0,     0,   136,     0,   137,   138,   139,   140,   141,   142,
     143,   361,   362,   363,   147,   364,   365,   150,   151,   152,
     153,   154,   155,   366,   157,     0,     0,     0,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,   173,   174,     0,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   367,   368,   198,   199,
     200,   201,   202
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        10,   516,    12,   624,   732,   733,   389,   651,   629,   786,
     692,   808,   916,   196,    94,   474,   399,    38,   118,   842,
     629,   520,   521,   522,   523,   746,   409,   410,   904,    38,
     496,    20,    59,    21,   714,    84,    20,    82,  1025,    48,
      39,    40,    41,    42,    43,    44,   331,    57,   333,    59,
     732,   733,    82,    52,    84,   395,    39,    40,    41,    42,
      43,    44,    66,    73,     7,   132,    84,   407,   128,    52,
      84,    95,   412,    81,    34,    58,  1057,  1058,   461,   751,
     463,   753,    20,   128,   766,    95,    69,   696,    71,   698,
      20,    74,    95,    34,    77,    18,    47,    20,    39,   109,
      99,   100,   132,    95,    84,   115,    59,   130,   499,    98,
     501,   502,    72,   504,   132,   506,    99,   100,   101,    84,
      95,   110,   117,   514,   515,   226,   227,   138,   222,     4,
     415,    95,   106,     8,   185,     4,   101,   160,    95,     8,
     153,   132,    95,   194,   138,   134,   101,   248,   172,   138,
     161,   772,   141,    94,    18,   178,     8,     9,   830,   167,
     832,   141,   145,   101,   115,   450,   451,    82,   453,   454,
     455,   456,   175,   186,   459,   275,  1163,   106,    95,   210,
     175,   212,    95,   175,   251,   982,   155,   171,   237,   238,
     475,   251,  1015,   970,   838,   710,   711,   171,   202,   820,
     485,   486,  1025,  1184,   587,   933,   251,   145,   172,   818,
     198,   171,    88,   154,   171,   145,   159,    82,     8,     9,
    1096,   251,   205,   237,   238,  1129,   906,     8,     9,   950,
     229,   235,   698,   251,   109,   249,   111,   620,   248,    91,
     109,   170,   111,   264,   119,   220,   229,    82,   171,   329,
     119,   933,   241,   280,   171,   264,   283,   109,   171,   111,
     251,     8,   547,   138,    29,   648,    95,   266,   267,   138,
     280,    95,    19,   283,   138,   230,   616,   141,   358,   619,
     889,    82,    95,   266,   267,   116,   138,   470,   203,   204,
     142,   371,   372,   141,   116,   375,   376,   132,   378,   268,
     269,    91,    95,   218,   259,   260,   158,   262,   263,    95,
      91,   183,    95,   185,   705,   166,   202,     8,     9,   109,
     122,   111,   194,     8,   404,    50,   406,   179,   109,   180,
     111,   132,    57,   141,    19,    60,    61,    95,   203,   204,
    1163,    95,   171,    68,   424,   197,   222,   171,   138,   235,
     181,    95,   142,   218,   230,   143,    20,   138,   171,   181,
     440,   142,   109,   373,   111,    95,   446,   243,   158,   245,
     380,   105,   160,   120,  1278,    94,   386,   158,   171,   255,
      95,    95,   258,   185,   210,   171,   212,   902,   171,   179,
    1118,   138,   775,   776,   113,   183,   779,   131,   179,   914,
      91,   411,   687,   413,   414,   864,   905,   197,    88,   694,
     144,   138,   422,   171,   141,   425,   197,   171,   109,   185,
     111,   101,    82,   143,   109,   435,   111,   171,   194,   154,
     813,   156,   230,   138,    98,   120,  1118,    84,   538,   539,
     160,   171,  1239,   141,   178,   170,   110,   138,   458,   133,
     460,   142,  1300,   138,   101,   535,   171,   171,    62,    63,
     540,   259,   260,   123,   262,   263,   150,   158,   128,   122,
     134,   196,   552,   106,   138,   133,    84,   141,   558,   166,
      88,   247,   135,   768,    64,    65,   210,   253,   179,   774,
    1218,   215,   150,   180,   141,   261,  1117,    83,  1346,   151,
    1292,  1293,   106,  1351,    84,   123,   197,  1355,    94,   145,
     282,   796,    64,    65,   166,    67,   288,  1161,   104,    84,
     138,   106,  1166,    88,  1316,   810,   811,   113,  1305,   814,
    1322,   816,    84,   106,   541,   615,  1218,   544,   247,   546,
    1268,    39,    40,    41,   253,   153,    44,   217,   123,   219,
     247,   836,   261,   128,   106,   252,   566,   123,    51,   266,
     267,    54,   128,   848,   849,   850,   646,   852,   853,   854,
     855,   856,   857,   583,   859,   860,   381,   176,   177,  1222,
     385,   866,  1081,   138,  1227,  1100,  1268,    60,   153,  1088,
    1089,    29,   138,   228,   977,   141,   231,   217,   228,   219,
     885,   231,   887,   888,   141,  1249,   206,   207,   208,  1253,
     266,   267,   114,   115,   222,    64,    65,   114,   115,   383,
     384,   141,   230,   633,   232,   233,   234,   517,   518,   709,
     524,   525,   734,   735,   242,   243,   106,   245,   526,   527,
     650,    14,   250,   138,   929,  1220,  1221,   255,   256,   257,
     258,   138,  1296,   200,   210,   141,   106,   222,   138,   106,
     267,     0,   175,   175,  1285,   230,    80,   232,   233,   234,
    1053,   152,   240,    75,   959,   184,   686,    89,   243,    90,
     245,   139,   692,   138,   141,   250,   138,   171,   171,   974,
     255,   256,   257,   258,    39,    39,    20,   137,   106,  1198,
    1199,    18,   987,   267,   138,   106,   257,   992,   993,   118,
     995,   106,   257,   138,   141,  1000,    25,   126,   127,   141,
     129,   141,   732,   733,   734,   735,   141,   136,   141,   267,
     171,   140,    15,   142,   171,   198,    20,   216,   147,   171,
     106,   751,    95,   753,   154,   216,    82,    82,   155,   155,
      82,   168,   171,   171,   163,   141,   766,  1140,    20,   113,
     145,    95,    95,   168,  1049,   168,   145,   118,  1267,   168,
     168,   168,    20,    84,   270,  1060,   168,   171,   187,   188,
     189,   190,   191,   192,   171,    34,    84,   171,  1073,   118,
     128,  1076,    95,  1078,   168,   171,   171,   168,   168,   171,
     168,    82,   128,   168,   106,  1188,   222,   155,   175,   106,
     210,   106,   106,   132,   258,   239,   246,   169,   241,   168,
     830,   168,   832,    88,   138,   168,    82,   128,   128,   260,
     138,   168,   261,   261,    84,   145,   182,   106,   118,   118,
     132,   128,   106,   168,   235,   138,    25,    20,   106,   138,
      95,   106,    95,   141,   132,   224,   936,   132,   171,   141,
     132,   871,   168,  1148,   874,  1150,    53,   130,   948,   130,
      82,  1156,   882,   236,   884,   236,    20,    95,   261,   261,
     171,   171,   128,   106,   106,  1170,  1171,  1172,  1173,  1174,
     175,  1176,   132,    67,   171,   975,     6,   171,   171,   118,
     171,   222,   218,   218,   170,   175,   218,   141,    94,    94,
    1195,   218,   171,   254,   171,   132,   170,   168,   106,    82,
      20,   168,    20,   933,   155,  1308,  1211,  1007,  1213,   112,
     141,   168,    84,   943,    82,   168,   168,    20,   168,   244,
      65,  1021,    84,   181,   170,    94,   106,   106,   138,  1234,
     170,    81,  1237,   181,   181,   106,   181,   167,   244,   106,
     767,   203,   171,   473,  1286,   206,   473,   206,   955,  1236,
     762,  1119,   398,   209,   984,   210,   477,   874,   825,   247,
     990,  1154,  1002,  1062,   990,  1050,   866,  1060,  1057,   435,
     934,  1001,   497,   519,   984,   498,   272,  1177,  1015,  1322,
     651,  1286,  1316,   735,   766,   753,  1043,  1047,   268,   710,
     902,   914,  1022,  1100,  1232,   711,  1128,   906,  1303,   423,
    1095,   903,    -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,
      -1,    -1,    -1,  1043,    -1,    -1,    -1,    -1,    -1,    -1,
    1050,    -1,    -1,    -1,    -1,  1330,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1151,  1152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1162,    -1,    -1,    -1,    -1,  1167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1212,    -1,    -1,    -1,    -1,    -1,  1218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1268,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1328,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,  1347,    26,    27,
      28,    29,  1352,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    -1,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    -1,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,   110,    -1,   112,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,   160,   161,    -1,    -1,   164,   165,   166,    -1,
      -1,    -1,   170,    -1,   172,   173,   174,    -1,   176,   177,
     178,    -1,   180,    -1,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,   195,   196,   197,
      -1,   199,   200,    -1,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,   240,   241,    -1,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    -1,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    -1,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    -1,   110,    -1,   112,   113,   114,   115,
      -1,   117,    -1,    -1,    -1,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,   160,   161,    -1,    -1,   164,   165,
     166,    -1,    -1,    -1,   170,   171,   172,   173,   174,    -1,
     176,   177,   178,    -1,   180,    -1,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,   195,
     196,   197,    -1,    -1,   200,    -1,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,   240,   241,    -1,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    -1,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,   110,    -1,   112,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,
     135,   136,   137,    -1,    -1,    -1,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,   160,   161,    -1,    -1,   164,
     165,   166,    -1,    -1,    -1,   170,    -1,   172,   173,   174,
      -1,   176,   177,   178,    -1,   180,    -1,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
     195,   196,   197,    -1,   199,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,   240,   241,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    -1,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    -1,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,    -1,   112,   113,
     114,   115,    -1,   117,    -1,    -1,    -1,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,   160,   161,    -1,    -1,
     164,   165,   166,    -1,   168,    -1,   170,    -1,   172,   173,
     174,    -1,   176,   177,   178,    -1,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,   195,   196,   197,    -1,    -1,   200,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,   240,   241,    -1,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    -1,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,   110,    -1,   112,
     113,   114,   115,    -1,   117,    -1,    -1,    -1,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,   136,   137,    -1,    -1,    -1,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,   160,   161,    -1,
      -1,   164,   165,   166,    -1,    -1,    -1,   170,   171,   172,
     173,   174,    -1,   176,   177,   178,    -1,   180,    -1,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,   195,   196,   197,    -1,    -1,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,   240,   241,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      -1,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,    -1,
     112,   113,   114,   115,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,   160,   161,
      -1,    -1,   164,   165,   166,    -1,   168,    -1,   170,    -1,
     172,   173,   174,    -1,   176,   177,   178,    -1,   180,    -1,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,   195,   196,   197,    -1,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,   240,   241,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    -1,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,   110,
      -1,   112,   113,   114,   115,    -1,   117,    -1,    -1,    -1,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,   136,   137,    -1,    -1,    -1,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,   160,
     161,    -1,    -1,   164,   165,   166,    -1,   168,    -1,   170,
      -1,   172,   173,   174,    -1,   176,   177,   178,    -1,   180,
      -1,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,   195,   196,   197,    -1,    -1,   200,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,   240,
     241,    -1,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    -1,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
     110,    -1,   112,   113,   114,   115,    -1,   117,    -1,    -1,
      -1,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
     160,   161,    -1,    -1,   164,   165,   166,    -1,   168,    -1,
     170,    -1,   172,   173,   174,    -1,   176,   177,   178,    -1,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,   195,   196,   197,    -1,    -1,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
     240,   241,    -1,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    -1,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,    -1,   112,   113,   114,   115,    -1,   117,    -1,
      -1,    -1,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,   134,   135,   136,   137,    -1,
      -1,    -1,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,   160,   161,    -1,    -1,   164,   165,   166,    -1,   168,
      -1,   170,    -1,   172,   173,   174,    -1,   176,   177,   178,
      -1,   180,    -1,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,   195,   196,   197,    -1,
      -1,   200,    -1,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,   240,   241,    -1,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    -1,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    -1,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,   110,    -1,   112,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,   160,   161,    -1,    -1,   164,   165,   166,    -1,
     168,    -1,   170,    -1,   172,   173,   174,    -1,   176,   177,
     178,    -1,   180,    -1,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,   195,   196,   197,
      -1,    -1,   200,    -1,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,   240,   241,    -1,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    -1,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,   110,    -1,   112,   113,   114,   115,    -1,
     117,    -1,    -1,    -1,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,   136,
     137,    -1,    -1,    -1,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,   160,   161,    -1,    -1,   164,   165,   166,
      -1,   168,    -1,   170,    -1,   172,   173,   174,    -1,   176,
     177,   178,    -1,   180,    -1,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,    -1,   195,   196,
     197,    -1,    -1,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,   240,   241,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    -1,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    -1,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    -1,   110,    -1,   112,   113,   114,   115,
      -1,   117,    -1,    -1,    -1,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,   160,   161,    -1,    -1,   164,   165,
     166,    -1,    -1,    -1,   170,    -1,   172,   173,   174,    -1,
     176,   177,   178,    -1,   180,    -1,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,   195,
     196,   197,    -1,    -1,   200,    -1,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,   240,   241,    -1,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    -1,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,   110,    -1,   112,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,
     135,   136,   137,    -1,    -1,    -1,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,   160,   161,    -1,    -1,   164,
     165,   166,    -1,    -1,    -1,   170,    -1,   172,   173,   174,
      -1,   176,   177,   178,    -1,   180,    -1,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
     195,   196,   197,    -1,    -1,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,   240,   241,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    -1,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    -1,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,    -1,   112,   113,
     114,   115,    -1,   117,    -1,    -1,    -1,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,   160,   161,    -1,    -1,
     164,   165,   166,    -1,    -1,    -1,   170,    -1,   172,   173,
     174,    -1,   176,   177,   178,    -1,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,   195,   196,   197,    -1,    -1,   200,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,   240,   241,    -1,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    -1,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,   110,    -1,   112,
     113,   114,   115,    -1,   117,    -1,    -1,    -1,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,   136,   137,    -1,    -1,    -1,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,   160,   161,    -1,
      -1,   164,   165,   166,    -1,    -1,    -1,   170,    -1,   172,
     173,   174,    -1,   176,   177,   178,    -1,   180,    -1,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,   195,   196,   197,    -1,    -1,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,   240,   241,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      -1,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,    -1,
     112,   113,   114,   115,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,   141,
     142,    -1,   144,   145,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,    -1,   164,   165,   166,    -1,    -1,    -1,   170,    -1,
     172,   173,   174,    -1,    -1,    -1,   178,    -1,   180,    -1,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,   195,   196,   197,    -1,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,   240,   241,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    80,
      -1,    82,    83,    84,    85,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,    -1,   117,    -1,    -1,    -1,
     121,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,    -1,    -1,    -1,    -1,   150,
     151,   152,   153,   154,   155,   156,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,   170,
      -1,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,   180,
      -1,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,   195,   196,    -1,    -1,    -1,   200,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,   240,
     241,    -1,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    -1,    82,    83,    84,    85,    -1,    -1,    88,    89,
      90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,    -1,   117,    -1,    -1,
      -1,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,   154,   155,   156,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,    -1,   172,    -1,    -1,    -1,    -1,    -1,   178,    -1,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,   195,   196,    -1,    -1,    -1,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
     240,   241,    -1,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    -1,    82,    83,    84,
      85,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    -1,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,   121,   122,   123,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,    -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,
     155,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,   170,    -1,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,    -1,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
     195,   196,    -1,    -1,    -1,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,   240,   241,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    -1,
      82,    83,    84,    85,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    -1,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,   135,   136,   137,   138,    -1,    -1,   141,
      -1,    -1,   144,   145,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,   155,   156,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,   170,    -1,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,    -1,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,   195,   196,    -1,    -1,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,   240,   241,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    -1,    82,    83,    84,    85,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,    -1,   117,    -1,
      -1,    -1,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,    -1,   135,   136,   137,   138,
      -1,    -1,   141,    -1,    -1,   144,   145,    -1,    -1,    -1,
      -1,   150,   151,   152,   153,   154,   155,   156,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,
      -1,   170,    -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,    -1,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,   195,   196,    -1,    -1,
      -1,   200,    -1,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,   240,   241,    -1,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    -1,    82,    83,    84,    85,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    -1,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
      -1,   117,    -1,    -1,    -1,   121,   122,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,   135,
     136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
      -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,   155,
     156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,   178,    -1,   180,    -1,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,   195,
     196,    -1,    -1,    -1,   200,    -1,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,   240,   241,    -1,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    -1,    82,
      83,    84,    85,    -1,    -1,    88,    89,    90,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    99,   100,   101,    -1,
      -1,   104,   105,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,    -1,   117,    -1,    -1,    -1,   121,   122,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,   178,    -1,   180,    -1,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,   195,   196,    -1,    -1,    -1,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,   240,   241,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    -1,    82,    83,    84,    85,    -1,    -1,    88,    89,
      90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    99,
     100,   101,    -1,    -1,   104,   105,   106,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,    -1,   117,    -1,    -1,
      -1,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,   154,   155,   156,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,    -1,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,   195,   196,    -1,    -1,    -1,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
     240,   241,    -1,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    -1,    82,    83,    84,    85,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,    -1,
     117,    -1,    -1,    -1,   121,   122,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,   144,   145,    -1,
      -1,    -1,    -1,   150,   151,   152,   153,   154,   155,   156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
      -1,    -1,    -1,   170,    -1,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,    -1,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,    -1,   195,   196,
      -1,    -1,    -1,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,   240,   241,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    -1,    82,    83,
      84,    85,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,    -1,   117,    -1,    -1,    -1,   121,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
      -1,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,   153,
     154,   155,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,   170,    -1,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,   195,   196,    -1,    -1,    -1,   200,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,   240,   241,    -1,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    80,
      -1,    82,    83,    84,    85,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,    -1,   117,    -1,    -1,    -1,
     121,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,    -1,    -1,    -1,    -1,   150,
     151,   152,   153,   154,   155,   156,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,   170,
      -1,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,   180,
      -1,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,   195,   196,    -1,    -1,    -1,   200,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,   240,
     241,    -1,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    -1,    82,    83,    84,    85,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,   121,   122,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,    -1,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,
      -1,    -1,   150,   151,   152,   153,   154,   155,   156,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,   170,    -1,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,    -1,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,   195,   196,    -1,
      -1,    -1,   200,    -1,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,   240,   241,    -1,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    10,    17,    18,    20,    26,    27,    28,    29,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    93,    94,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   110,   112,   113,   114,
     115,   117,   121,   122,   123,   124,   125,   131,   132,   133,
     134,   135,   136,   137,   141,   142,   143,   144,   145,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   160,   161,
     164,   165,   166,   170,   172,   173,   174,   176,   177,   178,
     180,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   195,   196,   197,   199,   200,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   240,   241,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   313,   314,
     319,   321,   327,   329,   331,   332,   333,   334,   335,   336,
     344,   345,   347,   348,   349,   354,   356,   358,   359,   360,
     365,   386,   389,   392,   393,   394,   395,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   442,   443,   444,
     458,   459,   461,   462,   463,   464,   465,   466,   467,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   486,
     487,   488,   489,   490,   491,   492,   495,   500,   501,   138,
     330,   222,    29,   141,    26,    27,    28,    32,    33,    34,
      35,    36,    37,    38,    45,    46,    48,    49,    51,    56,
      57,    60,    61,    70,    72,    73,    85,   121,   138,   153,
     186,   209,   210,   211,   213,   214,   221,   264,   265,   484,
     500,   141,   138,   141,   500,   138,   138,   141,   138,   141,
      39,    40,    41,    42,    43,    44,    52,    58,    69,    71,
      74,    77,    99,   100,   101,   145,   205,   229,   266,   267,
     322,   323,   337,   338,   141,    18,   138,   141,   499,    51,
      54,   106,   145,   106,   106,   138,    62,    63,   106,   351,
      60,    29,   141,   141,   138,   141,   500,    34,    36,    37,
      46,    85,   426,   500,   500,   106,   171,   264,   345,   500,
     138,    14,    16,   500,   500,   418,   138,    21,   198,   200,
     210,   212,   141,   210,   212,   210,   210,   215,   106,   138,
     106,   267,   322,   267,   288,     0,   290,   291,    38,    48,
     264,   293,   344,   175,   175,    95,   175,   346,    50,    57,
      60,    61,    68,   154,   156,   170,   196,   350,   355,   356,
     357,   374,   375,   379,   361,   362,   500,   152,    80,   118,
     126,   127,   129,   136,   140,   142,   147,   163,   187,   188,
     189,   190,   191,   192,   410,   411,   240,   143,   160,   183,
     105,   131,   144,   178,   185,   194,   122,   135,    75,   184,
      89,    90,   143,   160,   409,   138,   415,   418,   176,   177,
     139,   430,   431,   426,   430,   426,   430,   141,   345,   348,
     348,   345,   138,   345,   345,   171,   178,   500,   138,   345,
     345,   171,   345,   171,   500,   338,    39,   339,   337,   337,
     338,   500,   166,   180,   153,   186,    20,   498,   151,   166,
     166,   180,   137,   106,   318,    34,    39,    94,   154,   499,
     206,   207,   208,    88,   222,   230,   243,   245,   255,   258,
     513,   514,   515,   516,   517,   520,   525,   526,   323,   498,
     345,   345,    20,   171,   499,   138,   145,   498,   101,   145,
     312,   498,   387,   388,   500,   499,   500,   366,   368,   500,
     348,   257,   257,   106,   369,   106,   500,    34,    72,   171,
     482,   483,   345,   171,   178,   500,   138,   387,   267,   171,
      25,   446,   447,   448,   345,     7,   159,    15,   171,   345,
     198,    20,   348,   348,   171,   348,   348,   348,   348,   216,
     493,   494,   500,   348,   367,   373,   500,   498,   498,   295,
     296,    38,   297,   348,   347,   154,   106,   155,   155,   348,
     348,    95,    82,    84,   132,   251,   363,   364,   469,   394,
     395,   397,   397,   397,   397,   396,   397,   397,   397,   138,
     141,   241,   433,   502,   504,   505,   506,   507,   508,   509,
     510,   400,   400,   399,   401,   401,   401,   401,   402,   402,
     403,   403,   216,    82,    82,    82,   168,   345,   418,   418,
     345,   431,   171,   348,   441,   168,   171,   168,   345,   171,
     168,    95,   171,    95,   171,   168,   345,   168,   168,   168,
     141,   328,   500,    20,    95,    95,    82,   123,   128,   315,
     316,   317,   500,   123,   128,   145,   145,   498,   113,   118,
     228,   231,   101,   230,   259,   260,   262,   263,   228,   231,
      20,   230,   259,   260,   262,   263,   270,   171,   168,   171,
     171,   168,   345,   499,    84,    34,   499,   498,    84,    95,
     172,   132,   469,   118,   128,    95,   128,   364,   469,   168,
     500,    66,   202,   235,   352,   353,   171,   171,   171,   168,
      95,   171,    95,   171,   168,   345,   172,   498,   500,   447,
     448,   116,   181,   168,   168,   117,   175,    82,   203,   204,
     218,    82,   203,   204,   218,    82,   222,   210,    95,   220,
     128,   168,    59,    95,   175,   175,   155,   500,   348,   380,
     381,   106,   376,   377,   106,   137,   195,   470,   472,   473,
     474,   500,   106,   348,   106,   132,   364,   132,   132,   363,
     364,   397,   345,   502,   508,   258,   536,    84,   153,   232,
     233,   234,   242,   250,   256,   257,   503,   511,   512,   513,
     527,   530,   531,   533,   239,   241,   246,   532,   226,   227,
     248,   528,   470,   470,   468,   473,   468,   168,   169,    95,
     171,   330,   168,    88,   390,   391,   138,   484,   485,   500,
     484,   485,   168,   106,   171,   340,   341,   123,   138,   343,
     328,   133,   150,   133,   150,   472,   317,   348,   469,   128,
     348,   498,   498,   114,   115,   498,   260,   261,    84,   101,
     141,   519,   261,   348,   182,   138,   168,   118,   311,   498,
     145,   118,    84,   311,   106,   348,   348,   132,   498,   348,
     106,   348,   128,   128,   364,   132,   469,   235,    64,    65,
      67,   106,   363,   370,   371,   372,   353,   138,   484,   484,
     168,   348,    25,   448,   116,   181,     8,     9,    91,   109,
     111,   138,   179,   342,   443,   445,   456,   457,   460,    20,
     217,   219,   348,   348,   348,   217,   219,   348,   348,   348,
     348,   348,   348,   106,   348,   348,   224,   496,   497,   138,
     106,   380,    83,    94,   104,   113,   382,   383,   384,   385,
      95,   500,    95,   362,   141,   141,   130,   160,   178,   471,
     500,   500,   348,   132,   348,   348,   132,   364,   132,   168,
     171,   236,   202,   235,   247,   252,   535,    84,   237,   238,
     529,   236,   505,   535,   398,   401,   256,   511,   513,   506,
     132,   529,   261,    53,   130,   348,   106,   470,   101,   391,
     168,   345,   171,   171,   130,   171,   171,   500,    82,    95,
     171,   345,   330,   316,   348,   261,    84,   141,   522,    20,
     101,   519,   155,   268,   269,   320,   348,   168,   345,   498,
      95,   311,   388,   348,   175,   368,   348,   348,   128,   348,
     132,   106,   106,   348,   500,   372,    67,   168,   345,   171,
     171,   118,   179,   445,     6,   345,   500,   179,   456,   175,
     218,   218,   218,   218,   222,   494,   170,   141,   497,   348,
     373,   498,   114,   115,   384,   385,   385,   381,    94,   378,
     377,   171,   171,   348,   348,   132,   348,   401,    47,   115,
     401,   401,   247,   253,   261,   534,   534,   398,   507,   254,
     500,   170,   106,   170,   168,   469,   470,   341,    82,   168,
     122,   185,   521,   524,    20,    20,   523,   521,   249,   529,
      95,   171,    95,   171,   141,   326,   155,   112,   168,    84,
     498,   348,   348,   500,   500,   371,   348,   168,   448,   500,
     179,   168,   448,   500,   348,   348,   348,   348,   348,   348,
     427,   168,   385,   498,   348,   401,   401,   183,    82,   348,
     500,   348,   470,   522,   522,   524,    20,   171,    20,   244,
     518,   519,   518,   324,   325,   348,    95,   171,   326,   348,
     311,    65,    81,   167,   449,   448,   500,   181,   448,    95,
     171,   401,   470,   170,   529,    95,   171,   171,    94,   469,
     324,   171,   106,     4,   119,   452,   453,   455,   457,    19,
     120,   450,   451,   454,   457,   181,   448,   181,   106,   343,
     170,   348,   244,   519,   498,   500,    81,   119,   455,   167,
     120,   454,   181,   500,   348,    95,   171,   106,   343,   500,
      95,   171,   106,   343,   500,   171,   343
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
     535,   536,   537,   538,   539,   540
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   286,   287,   287,   288,   288,   288,   288,   289,   289,
     290,   290,   291,   292,   293,   293,   293,   294,   294,   295,
     295,   296,   296,   296,   296,   297,   297,   297,   297,   297,
     297,   298,   298,   298,   298,   298,   298,   298,   298,   299,
     299,   300,   301,   301,   302,   302,   303,   304,   305,   305,
     306,   306,   307,   307,   307,   307,   308,   309,   310,   310,
     310,   310,   311,   311,   312,   312,   313,   313,   313,   313,
     314,   315,   315,   316,   316,   317,   318,   318,   319,   319,
     319,   320,   320,   321,   321,   322,   322,   323,   323,   324,
     324,   325,   325,   326,   326,   327,   327,   328,   328,   328,
     328,   329,   330,   331,   332,   333,   334,   334,   335,   335,
     336,   336,   336,   337,   337,   337,   337,   338,   338,   339,
     340,   340,   341,   341,   342,   343,   344,   345,   345,   346,
     346,   347,   347,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   349,   350,   351,   351,   352,   352,   352,   353,   353,
     354,   354,   355,   356,   356,   356,   357,   357,   357,   357,
     357,   358,   358,   359,   359,   360,   361,   361,   362,   362,
     362,   362,   362,   362,   362,   362,   363,   364,   365,   366,
     366,   367,   367,   368,   368,   368,   368,   369,   369,   370,
     370,   370,   371,   371,   371,   372,   372,   372,   373,   374,
     375,   376,   376,   377,   377,   378,   379,   379,   380,   380,
     381,   381,   382,   382,   382,   382,   382,   382,   382,   383,
     383,   384,   384,   385,   386,   386,   387,   387,   388,   388,
     389,   389,   390,   390,   391,   391,   392,   393,   393,   394,
     394,   395,   395,   395,   395,   395,   396,   395,   395,   395,
     395,   397,   397,   397,   398,   398,   399,   399,   399,   400,
     400,   400,   400,   400,   401,   401,   401,   402,   402,   402,
     403,   403,   404,   404,   405,   405,   406,   406,   407,   407,
     408,   408,   408,   408,   409,   409,   409,   410,   410,   410,
     410,   410,   410,   411,   411,   411,   412,   412,   413,   413,
     414,   414,   415,   415,   416,   416,   416,   416,   417,   418,
     418,   418,   419,   419,   420,   420,   420,   420,   421,   421,
     422,   422,   422,   422,   422,   422,   422,   423,   423,   424,
     424,   425,   425,   425,   425,   425,   426,   426,   427,   427,
     428,   428,   428,   429,   429,   430,   430,   431,   432,   432,
     432,   432,   432,   432,   432,   432,   433,   433,   434,   434,
     434,   435,   436,   436,   437,   438,   439,   440,   440,   441,
     441,   442,   442,   443,   443,   443,   444,   444,   444,   444,
     444,   444,   445,   445,   446,   446,   447,   448,   448,   449,
     449,   450,   450,   451,   451,   451,   451,   452,   452,   453,
     453,   453,   453,   454,   454,   455,   455,   456,   456,   456,
     456,   457,   457,   457,   457,   458,   458,   459,   459,   460,
     461,   461,   461,   461,   461,   461,   462,   463,   463,   463,
     463,   464,   464,   464,   464,   465,   466,   467,   467,   467,
     467,   468,   468,   469,   470,   470,   470,   471,   471,   471,
     472,   472,   472,   473,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   475,   476,   476,   476,   477,   478,   479,
     479,   479,   480,   480,   480,   480,   480,   481,   482,   482,
     482,   482,   482,   482,   482,   483,   484,   485,   486,   487,
     487,   487,   488,   488,   488,   488,   488,   488,   488,   488,
     488,   488,   489,   489,   490,   490,   491,   492,   493,   493,
     494,   495,   496,   496,   497,   497,   497,   497,   498,   499,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   501,   501,   502,   502,   502,   502,
     503,   503,   503,   503,   504,   504,   505,   505,   506,   506,
     507,   507,   508,   508,   508,   509,   509,   510,   510,   511,
     511,   511,   511,   511,   512,   513,   513,   513,   513,   513,
     513,   513,   514,   514,   514,   514,   515,   515,   515,   515,
     516,   516,   517,   517,   517,   517,   517,   517,   517,   518,
     518,   519,   519,   519,   519,   520,   520,   520,   520,   520,
     521,   521,   522,   522,   523,   523,   524,   524,   525,   526,
     526,   527,   527,   527,   528,   528,   528,   528,   528,   529,
     529,   529,   529,   530,   531,   532,   533,   533,   534,   534,
     534,   535,   535,   536
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
       4,     3,     1,     1,     2,     2,     2,     3,     5,     4,
       6,     1,     1,     2,     2,     1,     2,     7,     8,     1,
       3,     1,     2,     2,     3,     3,     3,     2,     3,     4,
       5,     2,     3,     5,     3,     5,     2,     2,     3,     3,
       2,     3,     3,     1,     2,     2,     2,     4,     4,     4,
       1,     3,     2,     3,     3,     3,     1,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     2,     4,     3,
       5,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     2,     1,     4,     3,     4,
       4,     5,     4,     5,     5,     6,     3,     3,     3,     1,
       4,     1,     4,     3,     4,     4,     5,     4,     5,     1,
       2,     3,     1,     2,     1,     6,     3,     3,     1,     2,
       3,     1,     3,     2,     3,     2,     3,     4,     1,     3,
       1,     2,     1,     1,     1,     2,     2,     2,     3,     1,
       1,     2,     2,     2,     5,     5,     1,     4,     3,     4,
       8,    10,     1,     2,     4,     7,     8,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     0,     4,     3,     3,
       3,     1,     3,     4,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     4,     1,     4,     1,     4,     1,     4,     1,     2,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     3,     4,
       1,     2,     3,     2,     1,     2,     2,     1,     1,     1,
       3,     3,     1,     1,     1,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     4,     4,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     4,     5,     8,     9,
       9,    10,     1,     2,     1,     2,     6,     0,     1,     3,
       3,     0,     1,     1,     1,     2,     2,     0,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     4,     4,     5,     6,
       7,     4,     5,     6,     7,     4,     4,     4,     5,     6,
       7,     1,     2,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     4,     4,     3,     3,     3,
       4,     4,     3,     4,     6,     4,     6,     3,     3,     4,
       6,     6,     4,     6,     6,     4,     1,     2,     1,     3,
       3,     3,     5,     7,     7,     5,     5,     5,     7,     7,
       5,     5,     3,     3,     5,     7,     5,     7,     1,     4,
       3,     5,     1,     2,     5,     8,    11,    14,     1,     1,
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
  "\"'cont'\"", "\"'base-uri'\"", "\"'schema-element'\"",
  "\"'document-node'\"", "\"'copy-namespaces'\"", "\"'instance'\"",
  "\"'schema-attribute'\"", "\"'boundary-space'\"", "\"'ancestor::'\"",
  "\"'ancestor-or-self::'\"", "\"'and'\"", "\"'''\"", "\"'as'\"",
  "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'attribute::'\"",
  "\"'@'\"", "\"'case'\"", "\"'castable'\"", "\"'cast'\"", "\"'CDATA[['\"",
  "\"']]'\"", "\"'child::'\"", "\"'collation'\"", "\"','\"", "\"'(:'\"",
  "\"':)'\"", "\"'DECIMAL'\"", "\"'context'\"", "\"'variable'\"",
  "\"'default'\"", "\"'descendant::'\"", "\"'descendant-or-self::'\"",
  "\"'descending'\"", "\"'div'\"", "\"'$'\"", "\"'.'\"", "\"'..'\"",
  "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"", "\"'else'\"",
  "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
  "\"'encoding'\"", "\"'='\"", "\"''''\"", "\"'\\\"\\\"'\"", "\"'every'\"",
  "\"'except'\"", "\"'external'\"", "\"'following::'\"",
  "\"'following-sibling::'\"", "\"'follows'\"", "\"'>='\"", "\"':='\"",
  "\"'>'\"", "\"'?'\"", "\"'idiv'\"", "\"'in'\"", "\"'inherit'\"",
  "\"'INTEGER'\"", "\"'intersect'\"", "\"'is'\"", "\"'item'\"", "\"'{'\"",
  "\"'['\"", "\"'<='\"", "\"'('\"", "\"'<'\"", "\"'-'\"", "\"'mod'\"",
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
       287,     0,    -1,   288,    -1,   271,   288,    -1,   290,    -1,
     289,   290,    -1,   291,    -1,   289,   291,    -1,   199,   200,
      20,   175,    -1,   199,   200,    20,   117,    20,   175,    -1,
     293,   344,    -1,   344,    -1,   292,   293,    -1,    51,   145,
     499,   118,   498,   175,    -1,   294,   175,    -1,   295,   175,
      -1,   294,   175,   295,   175,    -1,   296,    -1,   294,   175,
     296,    -1,   297,    -1,   295,   175,   297,    -1,   298,    -1,
     299,    -1,   300,    -1,   302,    -1,   319,    -1,   314,    -1,
     336,    -1,   303,    -1,   304,    -1,   321,    -1,   301,    -1,
     308,    -1,   309,    -1,   327,    -1,   305,    -1,   306,    -1,
     307,    -1,   487,    -1,   310,    -1,   313,    -1,    38,   145,
     499,   118,   498,    -1,    38,    77,   166,    -1,    38,    77,
     180,    -1,    38,   101,    34,   145,   498,    -1,    38,   101,
      39,   145,   498,    -1,    38,    52,   500,    20,    -1,    38,
     229,   513,    -1,    38,    69,   153,    -1,    38,    69,   186,
      -1,    38,   101,   154,   113,   114,    -1,    38,   101,   154,
     113,   115,    -1,    38,    74,   166,    95,   133,    -1,    38,
      74,   166,    95,   150,    -1,    38,    74,   151,    95,   133,
      -1,    38,    74,   151,    95,   150,    -1,    38,   101,    94,
     498,    -1,    38,    71,   498,    -1,    48,    54,   498,    -1,
      48,    54,   312,   498,    -1,    48,    54,   498,    84,   311,
      -1,    48,    54,   312,   498,    84,   311,    -1,   498,    -1,
     311,    95,   498,    -1,   145,   499,   118,    -1,   101,    34,
     145,    -1,    48,    51,   498,    -1,    48,    51,   145,   499,
     118,   498,    -1,    48,    51,   498,    84,   311,    -1,    48,
      51,   145,   499,   118,   498,    84,   311,    -1,    38,    99,
     137,   315,    -1,    82,   472,   316,    -1,   316,    -1,   317,
      -1,   123,   317,    -1,   128,   348,    -1,   106,   500,    -1,
     106,   500,   469,    -1,    38,   100,   318,   128,   348,    -1,
      38,   100,   318,   123,    -1,    38,   100,   318,   123,   128,
     348,    -1,   268,    -1,   269,    -1,    38,   322,    -1,   264,
     322,    -1,   323,    -1,   266,   323,    -1,   267,   498,   270,
     348,   155,   326,   171,    -1,   267,   498,   270,   348,   320,
     155,   326,   171,    -1,   325,    -1,   325,    94,   498,    -1,
     348,    -1,   348,   469,    -1,   141,   324,    -1,   326,    95,
     324,    -1,    38,    58,   166,    -1,    38,    58,   180,    -1,
     141,   171,    -1,   141,   340,   171,    -1,   141,   171,    82,
     470,    -1,   141,   340,   171,    82,   470,    -1,    26,   330,
      -1,   138,   345,   168,    -1,    56,   106,   500,   128,   348,
      -1,    27,   222,   348,    -1,    31,   141,   348,   171,   330,
      -1,    28,    29,    -1,    70,    29,    -1,   264,   267,   498,
      -1,   265,   267,   498,    -1,    38,   337,    -1,    38,    43,
     337,    -1,    38,    42,   337,    -1,   338,    -1,    44,   338,
      -1,    40,   338,    -1,    41,   339,    -1,    39,   500,   328,
     343,    -1,    39,   500,   328,   123,    -1,    39,   500,   328,
     330,    -1,   341,    -1,   340,    95,   341,    -1,   106,   500,
      -1,   106,   500,   469,    -1,   138,   345,   168,    -1,   138,
     345,   168,    -1,   345,    -1,   347,    -1,   347,   346,    -1,
     175,    -1,   346,   347,   175,    -1,   348,    -1,   347,    95,
     348,    -1,   349,    -1,   386,    -1,   389,    -1,   392,    -1,
     393,    -1,   488,    -1,   489,    -1,   491,    -1,   490,    -1,
     492,    -1,   495,    -1,   501,    -1,   332,    -1,   333,    -1,
     334,    -1,   331,    -1,   329,    -1,   335,    -1,   358,   350,
      -1,   170,   348,    -1,    62,   257,    -1,    63,   257,    -1,
     202,    -1,   235,    -1,    66,   235,    -1,   352,   370,    67,
     348,    -1,   352,    67,   348,    -1,    60,   351,   369,   353,
     353,    -1,    60,   351,   369,   353,    -1,    68,   106,   500,
      -1,   360,    -1,   365,    -1,   354,    -1,   356,    -1,   374,
      -1,   379,    -1,   375,    -1,   355,    -1,   356,    -1,   358,
     357,    -1,    60,   106,    -1,    61,    60,   106,    -1,   359,
     361,    -1,   362,    -1,   361,    95,   106,   362,    -1,   500,
     132,   348,    -1,   500,   469,   132,   348,    -1,   500,   363,
     132,   348,    -1,   500,   469,   363,   132,   348,    -1,   500,
     364,   132,   348,    -1,   500,   469,   364,   132,   348,    -1,
     500,   363,   364,   132,   348,    -1,   500,   469,   363,   364,
     132,   348,    -1,    84,   106,   500,    -1,   251,   106,   500,
      -1,    57,   106,   366,    -1,   368,    -1,   366,    95,   106,
     368,    -1,   373,    -1,   367,    95,   106,   373,    -1,   500,
     128,   348,    -1,   500,   469,   128,   348,    -1,   500,   364,
     128,   348,    -1,   500,   469,   364,   128,   348,    -1,   106,
     500,   132,   348,    -1,   106,   500,   469,   132,   348,    -1,
     371,    -1,   106,   500,    -1,   106,   500,   371,    -1,   363,
      -1,   363,   372,    -1,   372,    -1,    64,   106,   500,    65,
     106,   500,    -1,    65,   106,   500,    -1,    64,   106,   500,
      -1,   500,    -1,   196,   348,    -1,   156,   155,   376,    -1,
     377,    -1,   376,    95,   377,    -1,   106,   500,    -1,   106,
     500,   378,    -1,    94,   498,    -1,   154,   155,   380,    -1,
      50,   154,   155,   380,    -1,   381,    -1,   380,    95,   381,
      -1,   348,    -1,   348,   382,    -1,   383,    -1,   384,    -1,
     385,    -1,   383,   384,    -1,   383,   385,    -1,   384,   385,
      -1,   383,   384,   385,    -1,    83,    -1,   104,    -1,   113,
     114,    -1,   113,   115,    -1,    94,   498,    -1,    49,   106,
     387,   172,   348,    -1,   121,   106,   387,   172,   348,    -1,
     388,    -1,   387,    95,   106,   388,    -1,   500,   132,   348,
      -1,   500,   469,   132,   348,    -1,    33,   141,   345,   171,
     390,   101,   170,   348,    -1,    33,   141,   345,   171,   390,
     101,   106,   500,   170,   348,    -1,   391,    -1,   390,   391,
      -1,    88,   470,   170,   348,    -1,    88,   106,   500,    82,
     470,   170,   348,    -1,    45,   141,   345,   171,   182,   348,
     112,   348,    -1,   394,    -1,   393,   152,   394,    -1,   395,
      -1,   394,    80,   395,    -1,   397,    -1,   397,   410,   397,
      -1,   397,   411,   397,    -1,   397,   118,   397,    -1,   397,
     147,   397,    -1,    -1,   397,   142,   396,   397,    -1,   397,
     140,   397,    -1,   397,   129,   397,    -1,   397,   127,   397,
      -1,   398,    -1,   398,   240,   502,    -1,   398,   240,   502,
     536,    -1,   399,    -1,   399,   183,   399,    -1,   400,    -1,
     399,   160,   400,    -1,   399,   143,   400,    -1,   401,    -1,
     400,   178,   401,    -1,   400,   105,   401,    -1,   400,   131,
     401,    -1,   400,   144,   401,    -1,   402,    -1,   401,   185,
     402,    -1,   401,   194,   402,    -1,   403,    -1,   402,   135,
     403,    -1,   402,   122,   403,    -1,   404,    -1,   404,    75,
     216,   470,    -1,   405,    -1,   405,   184,    82,   470,    -1,
     406,    -1,   406,    89,    82,   468,    -1,   407,    -1,   407,
      90,    82,   468,    -1,   409,    -1,   408,   409,    -1,   160,
      -1,   143,    -1,   408,   160,    -1,   408,   143,    -1,   412,
      -1,   416,    -1,   413,    -1,   187,    -1,   192,    -1,   191,
      -1,   190,    -1,   189,    -1,   188,    -1,   136,    -1,   163,
      -1,   126,    -1,    32,   138,   345,   168,    -1,    32,   484,
     138,   345,   168,    -1,   414,   138,   168,    -1,   414,   138,
     345,   168,    -1,   415,    -1,   414,   415,    -1,   161,   500,
      15,    -1,   161,    16,    -1,   417,    -1,   417,   418,    -1,
     177,   418,    -1,   418,    -1,   176,    -1,   419,    -1,   419,
     176,   418,    -1,   419,   177,   418,    -1,   420,    -1,   429,
      -1,   421,    -1,   421,   430,    -1,   424,    -1,   424,   430,
      -1,   422,   426,    -1,   423,    -1,    93,    -1,   102,    -1,
      86,    -1,   174,    -1,   103,    -1,   125,    -1,   124,    -1,
     426,    -1,    87,   426,    -1,   425,   426,    -1,   108,    -1,
     157,    -1,    78,    -1,   165,    -1,   164,    -1,    79,    -1,
     474,    -1,   427,    -1,   500,    -1,   428,    -1,   178,    -1,
      10,    -1,    17,    -1,   432,    -1,   432,   430,    -1,   431,
      -1,   430,   431,    -1,   139,   345,   169,    -1,   433,    -1,
     435,    -1,   436,    -1,   437,    -1,   440,    -1,   442,    -1,
     438,    -1,   439,    -1,   434,    -1,   486,    -1,    98,    -1,
     134,    -1,   110,    -1,   106,   500,    -1,   141,   171,    -1,
     141,   345,   171,    -1,   107,    -1,   153,   138,   345,   168,
      -1,   186,   138,   345,   168,    -1,   500,   141,   171,    -1,
     500,   141,   441,   171,    -1,   348,    -1,   441,    95,   348,
      -1,   443,    -1,   461,    -1,   444,    -1,   458,    -1,   459,
      -1,   142,   500,   448,   116,    -1,   142,   500,   446,   448,
     116,    -1,   142,   500,   448,   181,   179,   500,   448,   181,
      -1,   142,   500,   448,   181,   445,   179,   500,   448,   181,
      -1,   142,   500,   446,   448,   181,   179,   500,   448,   181,
      -1,   142,   500,   446,   448,   181,   445,   179,   500,   448,
     181,    -1,   456,    -1,   445,   456,    -1,   447,    -1,   446,
     447,    -1,    25,   500,   448,   118,   448,   449,    -1,    -1,
      25,    -1,   167,   450,   167,    -1,    81,   452,    81,    -1,
      -1,   451,    -1,   120,    -1,   454,    -1,   451,   120,    -1,
     451,   454,    -1,    -1,   453,    -1,   119,    -1,   455,    -1,
     453,   119,    -1,   453,   455,    -1,    19,    -1,   457,    -1,
       4,    -1,   457,    -1,   443,    -1,     9,    -1,   460,    -1,
     457,    -1,     8,    -1,   109,    -1,   111,    -1,   342,    -1,
     197,    21,   198,    -1,   197,   198,    -1,   158,    14,   159,
      -1,   158,    14,     7,    -1,    91,     6,    -1,   462,    -1,
     463,    -1,   464,    -1,   465,    -1,   466,    -1,   467,    -1,
      35,   138,   345,   168,    -1,    34,   500,   138,   168,    -1,
      34,   500,   138,   345,   168,    -1,    34,   138,   345,   168,
     138,   168,    -1,    34,   138,   345,   168,   138,   345,   168,
      -1,    85,   500,   138,   168,    -1,    85,   500,   138,   345,
     168,    -1,    85,   138,   345,   168,   138,   168,    -1,    85,
     138,   345,   168,   138,   345,   168,    -1,    36,   138,   345,
     168,    -1,    37,   138,   345,   168,    -1,    46,   499,   138,
     168,    -1,    46,   499,   138,   345,   168,    -1,    46,   138,
     345,   168,   138,   168,    -1,    46,   138,   345,   168,   138,
     345,   168,    -1,   473,    -1,   473,   130,    -1,    82,   470,
      -1,   472,    -1,   472,   471,    -1,   195,   141,   171,    -1,
     130,    -1,   178,    -1,   160,    -1,   473,    -1,   474,    -1,
     137,   141,   171,    -1,   500,    -1,   476,    -1,   482,    -1,
     480,    -1,   483,    -1,   481,    -1,   479,    -1,   478,    -1,
     477,    -1,   475,    -1,   210,   141,   171,    -1,    73,   141,
     171,    -1,    73,   141,   482,   171,    -1,    73,   141,   483,
     171,    -1,    36,   141,   171,    -1,    37,   141,   171,    -1,
      46,   141,   171,    -1,    46,   141,   499,   171,    -1,    46,
     141,    20,   171,    -1,    85,   141,   171,    -1,    85,   141,
     500,   171,    -1,    85,   141,   500,    95,   484,   171,    -1,
      85,   141,   178,   171,    -1,    85,   141,   178,    95,   484,
     171,    -1,   173,   500,   171,    -1,    34,   141,   171,    -1,
      34,   141,   500,   171,    -1,    34,   141,   500,    95,   484,
     171,    -1,    34,   141,   500,    95,   485,   171,    -1,    34,
     141,   178,   171,    -1,    34,   141,   178,    95,   484,   171,
      -1,    34,   141,   178,    95,   485,   171,    -1,    72,   141,
     500,   171,    -1,   500,    -1,   500,   130,    -1,    20,    -1,
      38,   205,   206,    -1,    38,   205,   207,    -1,    38,   205,
     208,    -1,   211,   210,   348,   218,   348,    -1,   211,   210,
     348,    82,   217,   218,   348,    -1,   211,   210,   348,    82,
     219,   218,   348,    -1,   211,   210,   348,   203,   348,    -1,
     211,   210,   348,   204,   348,    -1,   211,   212,   348,   218,
     348,    -1,   211,   212,   348,    82,   217,   218,   348,    -1,
     211,   212,   348,    82,   219,   218,   348,    -1,   211,   212,
     348,   203,   348,    -1,   211,   212,   348,   204,   348,    -1,
     209,   210,   348,    -1,   209,   212,   348,    -1,   214,   210,
     348,   222,   348,    -1,   214,   215,   216,   210,   348,   222,
     348,    -1,   213,   210,   348,    82,   348,    -1,   221,   106,
     493,   220,   348,   170,   348,    -1,   494,    -1,   493,    95,
     106,   494,    -1,   500,   128,   348,    -1,   223,   138,   348,
     168,   496,    -1,   497,    -1,   496,   497,    -1,   224,   141,
     427,   171,   343,    -1,   224,   141,   427,    95,   106,   500,
     171,   343,    -1,   224,   141,   427,    95,   106,   500,    95,
     106,   500,   171,   343,    -1,   224,   141,   427,    95,   106,
     500,    95,   106,   500,    95,   106,   500,   171,   343,    -1,
      20,    -1,    18,    -1,    18,    -1,   113,    -1,    85,    -1,
      37,    -1,    73,    -1,    34,    -1,   137,    -1,    45,    -1,
     210,    -1,    46,    -1,    76,    -1,    72,    -1,    36,    -1,
      33,    -1,   195,    -1,    77,    -1,   229,    -1,    71,    -1,
     207,    -1,   206,    -1,   131,    -1,    35,    -1,   241,    -1,
     228,    -1,   231,    -1,   230,    -1,   258,    -1,   259,    -1,
     262,    -1,   260,    -1,   263,    -1,   234,    -1,   236,    -1,
      53,    -1,   202,    -1,   235,    -1,    47,    -1,   208,    -1,
     221,    -1,   215,    -1,   187,    -1,   192,    -1,   191,    -1,
     190,    -1,   189,    -1,   188,    -1,    84,    -1,    99,    -1,
     100,    -1,   170,    -1,    60,    -1,    61,    -1,    62,    -1,
      63,    -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,
      68,    -1,   132,    -1,    57,    -1,   196,    -1,   155,    -1,
     156,    -1,   154,    -1,    50,    -1,    83,    -1,   104,    -1,
     114,    -1,   115,    -1,    94,    -1,    49,    -1,   121,    -1,
     172,    -1,    88,    -1,    82,    -1,   182,    -1,   112,    -1,
     152,    -1,    80,    -1,    75,    -1,   216,    -1,    89,    -1,
     183,    -1,   105,    -1,   144,    -1,   185,    -1,   135,    -1,
     122,    -1,    32,    -1,    90,    -1,   184,    -1,   136,    -1,
     166,    -1,   180,    -1,   145,    -1,   123,    -1,   117,    -1,
     151,    -1,   133,    -1,   150,    -1,    38,    -1,    58,    -1,
      69,    -1,   101,    -1,    74,    -1,    52,    -1,   200,    -1,
      48,    -1,    54,    -1,    51,    -1,    39,    -1,   251,    -1,
     240,    -1,   256,    -1,   257,    -1,   233,    -1,   246,    -1,
     254,    -1,   250,    -1,   232,    -1,   245,    -1,   255,    -1,
     249,    -1,   244,    -1,   243,    -1,   227,    -1,   226,    -1,
     248,    -1,   237,    -1,   238,    -1,   261,    -1,   253,    -1,
     252,    -1,   247,    -1,   214,    -1,   220,    -1,   217,    -1,
     211,    -1,   204,    -1,   203,    -1,   205,    -1,   222,    -1,
     212,    -1,   213,    -1,   219,    -1,   209,    -1,   218,    -1,
      40,    -1,   153,    -1,   186,    -1,    26,    -1,    27,    -1,
      29,    -1,    28,    -1,    70,    -1,    56,    -1,   267,    -1,
     264,    -1,   266,    -1,   270,    -1,   268,    -1,   269,    -1,
     265,    -1,   225,   106,   367,    59,   138,   348,   168,    -1,
      59,   138,   348,   168,    -1,   504,    -1,   504,   503,    -1,
     504,   256,   398,    -1,   504,   503,   256,   398,    -1,   513,
      -1,   511,    -1,   503,   513,    -1,   503,   511,    -1,   505,
      -1,   504,   242,   505,    -1,   506,    -1,   505,   239,   506,
      -1,   507,    -1,   506,   241,   132,   507,    -1,   508,    -1,
     241,   508,    -1,   509,    -1,   509,   532,    -1,   141,   502,
     171,    -1,   510,    -1,   510,   528,    -1,   433,    -1,   138,
     345,   168,    -1,   512,    -1,   531,    -1,   530,    -1,   533,
      -1,   527,    -1,   153,    -1,   514,    -1,   515,    -1,   516,
      -1,   517,    -1,   520,    -1,   525,    -1,   526,    -1,   245,
      -1,   255,    -1,    88,   228,    -1,    88,   231,    -1,   222,
     230,    -1,   258,   230,    -1,   230,   228,    -1,   230,   231,
      -1,   222,   259,    -1,   258,   259,    -1,   222,   262,   519,
      -1,   222,   262,   101,    -1,   222,   262,   141,   519,   171,
      -1,   222,   262,   141,   519,    95,   518,   171,    -1,   222,
     262,   141,   101,   171,    -1,   222,   262,   141,   101,    95,
     518,   171,    -1,   258,   262,    -1,   519,    -1,   518,    95,
     519,    -1,    84,    20,    -1,    84,    20,   249,    20,    -1,
      84,    20,   529,   244,    -1,    84,    20,   249,    20,   529,
     244,    -1,   222,   260,   261,   522,    -1,   222,   260,   261,
     522,   521,    -1,   222,   101,   260,   261,    -1,   222,   101,
     260,   261,   521,    -1,   258,   260,   261,    -1,   524,    -1,
     521,   524,    -1,    84,    20,    -1,   141,   523,   171,    -1,
      20,    -1,   523,    20,    -1,   185,   522,    -1,   122,   522,
      -1,   243,    20,    -1,   222,   263,    -1,   258,   263,    -1,
      84,   202,    -1,    84,   235,    -1,   234,   236,    -1,   227,
      -1,   227,    53,    -1,   226,    -1,   226,   261,    -1,   248,
      -1,   237,   401,    -1,    84,   115,   401,    -1,    84,    47,
     401,    -1,   238,   401,   183,   401,    -1,   233,   529,   534,
      -1,   257,   401,   534,    -1,   246,   529,   254,    -1,   250,
     535,    -1,   232,   535,    -1,   261,    -1,   253,    -1,   247,
      -1,   252,    -1,   247,    -1,   258,   236,   401,    -1
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
     258,   263,   267,   269,   271,   274,   277,   280,   284,   290,
     295,   302,   304,   306,   309,   312,   314,   317,   325,   334,
     336,   340,   342,   345,   348,   352,   356,   360,   363,   367,
     372,   378,   381,   385,   391,   395,   401,   404,   407,   411,
     415,   418,   422,   426,   428,   431,   434,   437,   442,   447,
     452,   454,   458,   461,   465,   469,   473,   475,   477,   480,
     482,   486,   488,   492,   494,   496,   498,   500,   502,   504,
     506,   508,   510,   512,   514,   516,   518,   520,   522,   524,
     526,   528,   531,   534,   537,   540,   542,   544,   547,   552,
     556,   562,   567,   571,   573,   575,   577,   579,   581,   583,
     585,   587,   589,   592,   595,   599,   602,   604,   609,   613,
     618,   623,   629,   634,   640,   646,   653,   657,   661,   665,
     667,   672,   674,   679,   683,   688,   693,   699,   704,   710,
     712,   715,   719,   721,   724,   726,   733,   737,   741,   743,
     746,   750,   752,   756,   759,   763,   766,   770,   775,   777,
     781,   783,   786,   788,   790,   792,   795,   798,   801,   805,
     807,   809,   812,   815,   818,   824,   830,   832,   837,   841,
     846,   855,   866,   868,   871,   876,   884,   893,   895,   899,
     901,   905,   907,   911,   915,   919,   923,   924,   929,   933,
     937,   941,   943,   947,   952,   954,   958,   960,   964,   968,
     970,   974,   978,   982,   986,   988,   992,   996,   998,  1002,
    1006,  1008,  1013,  1015,  1020,  1022,  1027,  1029,  1034,  1036,
    1039,  1041,  1043,  1046,  1049,  1051,  1053,  1055,  1057,  1059,
    1061,  1063,  1065,  1067,  1069,  1071,  1073,  1078,  1084,  1088,
    1093,  1095,  1098,  1102,  1105,  1107,  1110,  1113,  1115,  1117,
    1119,  1123,  1127,  1129,  1131,  1133,  1136,  1138,  1141,  1144,
    1146,  1148,  1150,  1152,  1154,  1156,  1158,  1160,  1162,  1165,
    1168,  1170,  1172,  1174,  1176,  1178,  1180,  1182,  1184,  1186,
    1188,  1190,  1192,  1194,  1196,  1199,  1201,  1204,  1208,  1210,
    1212,  1214,  1216,  1218,  1220,  1222,  1224,  1226,  1228,  1230,
    1232,  1234,  1237,  1240,  1244,  1246,  1251,  1256,  1260,  1265,
    1267,  1271,  1273,  1275,  1277,  1279,  1281,  1286,  1292,  1301,
    1311,  1321,  1332,  1334,  1337,  1339,  1342,  1349,  1350,  1352,
    1356,  1360,  1361,  1363,  1365,  1367,  1370,  1373,  1374,  1376,
    1378,  1380,  1383,  1386,  1388,  1390,  1392,  1394,  1396,  1398,
    1400,  1402,  1404,  1406,  1408,  1410,  1414,  1417,  1421,  1425,
    1428,  1430,  1432,  1434,  1436,  1438,  1440,  1445,  1450,  1456,
    1463,  1471,  1476,  1482,  1489,  1497,  1502,  1507,  1512,  1518,
    1525,  1533,  1535,  1538,  1541,  1543,  1546,  1550,  1552,  1554,
    1556,  1558,  1560,  1564,  1566,  1568,  1570,  1572,  1574,  1576,
    1578,  1580,  1582,  1584,  1588,  1592,  1597,  1602,  1606,  1610,
    1614,  1619,  1624,  1628,  1633,  1640,  1645,  1652,  1656,  1660,
    1665,  1672,  1679,  1684,  1691,  1698,  1703,  1705,  1708,  1710,
    1714,  1718,  1722,  1728,  1736,  1744,  1750,  1756,  1762,  1770,
    1778,  1784,  1790,  1794,  1798,  1804,  1812,  1818,  1826,  1828,
    1833,  1837,  1843,  1845,  1848,  1854,  1863,  1875,  1890,  1892,
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
    2114,  2116,  2118,  2120,  2122,  2124,  2126,  2128,  2130,  2132,
    2134,  2136,  2138,  2140,  2142,  2144,  2146,  2148,  2150,  2152,
    2154,  2156,  2158,  2160,  2162,  2164,  2166,  2168,  2170,  2172,
    2174,  2176,  2178,  2180,  2182,  2184,  2186,  2188,  2190,  2192,
    2194,  2196,  2198,  2200,  2202,  2204,  2206,  2208,  2210,  2212,
    2214,  2216,  2218,  2220,  2222,  2230,  2235,  2237,  2240,  2244,
    2249,  2251,  2253,  2256,  2259,  2261,  2265,  2267,  2271,  2273,
    2278,  2280,  2283,  2285,  2288,  2292,  2294,  2297,  2299,  2303,
    2305,  2307,  2309,  2311,  2313,  2315,  2317,  2319,  2321,  2323,
    2325,  2327,  2329,  2331,  2333,  2336,  2339,  2342,  2345,  2348,
    2351,  2354,  2357,  2361,  2365,  2371,  2379,  2385,  2393,  2396,
    2398,  2402,  2405,  2410,  2415,  2422,  2427,  2433,  2438,  2444,
    2448,  2450,  2453,  2456,  2460,  2462,  2465,  2468,  2471,  2474,
    2477,  2480,  2483,  2486,  2489,  2491,  2494,  2496,  2499,  2501,
    2504,  2508,  2512,  2517,  2521,  2525,  2529,  2532,  2535,  2537,
    2539,  2541,  2543,  2545
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   869,   869,   870,   880,   885,   891,   896,   908,   913,
     923,   930,   942,   954,   966,   972,   978,   990,   996,  1010,
    1016,  1030,  1031,  1032,  1033,  1039,  1040,  1041,  1042,  1045,
    1048,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1064,  1071,
    1072,  1084,  1096,  1101,  1112,  1118,  1130,  1143,  1154,  1159,
    1171,  1176,  1187,  1193,  1199,  1205,  1224,  1235,  1246,  1253,
    1260,  1267,  1280,  1286,  1301,  1305,  1315,  1321,  1328,  1334,
    1346,  1353,  1359,  1366,  1370,  1379,  1390,  1394,  1402,  1411,
    1418,  1428,  1430,  1437,  1443,  1452,  1456,  1464,  1469,  1479,
    1483,  1491,  1495,  1502,  1509,  1519,  1524,  1536,  1540,  1544,
    1548,  1555,  1562,  1569,  1576,  1583,  1590,  1594,  1601,  1605,
    1612,  1616,  1620,  1628,  1632,  1636,  1644,  1651,  1660,  1672,
    1686,  1694,  1708,  1714,  1726,  1734,  1745,  1757,  1761,  1773,
    1777,  1786,  1790,  1806,  1807,  1808,  1809,  1810,  1813,  1814,
    1815,  1816,  1817,  1819,  1820,  1823,  1824,  1825,  1826,  1827,
    1830,  1837,  1846,  1853,  1857,  1865,  1869,  1873,  1880,  1884,
    1891,  1896,  1905,  1914,  1915,  1916,  1920,  1920,  1920,  1920,
    1920,  1923,  1929,  1938,  1942,  1952,  1963,  1969,  1983,  1990,
    1998,  2007,  2017,  2025,  2034,  2043,  2058,  2070,  2081,  2093,
    2099,  2111,  2117,  2131,  2139,  2148,  2156,  2168,  2174,  2184,
    2185,  2189,  2197,  2201,  2206,  2210,  2214,  2218,  2225,  2240,
    2248,  2258,  2264,  2275,  2281,  2290,  2300,  2305,  2317,  2323,
    2337,  2343,  2355,  2362,  2369,  2376,  2383,  2390,  2397,  2410,
    2414,  2424,  2429,  2440,  2451,  2458,  2471,  2478,  2490,  2496,
    2509,  2516,  2530,  2536,  2548,  2554,  2567,  2578,  2582,  2593,
    2597,  2616,  2620,  2628,  2636,  2644,  2652,  2652,  2660,  2668,
    2676,  2690,  2694,  2701,  2714,  2718,  2729,  2733,  2737,  2747,
    2751,  2755,  2759,  2763,  2773,  2777,  2782,  2793,  2797,  2801,
    2811,  2815,  2827,  2831,  2843,  2847,  2859,  2863,  2875,  2879,
    2891,  2895,  2899,  2903,  2915,  2919,  2923,  2933,  2937,  2941,
    2945,  2949,  2953,  2963,  2967,  2971,  2981,  2985,  2997,  3003,
    3015,  3021,  3035,  3042,  3083,  3087,  3091,  3095,  3107,  3117,
    3128,  3133,  3143,  3147,  3157,  3163,  3169,  3175,  3187,  3193,
    3204,  3208,  3212,  3216,  3220,  3224,  3228,  3238,  3242,  3252,
    3258,  3270,  3274,  3278,  3282,  3286,  3301,  3305,  3315,  3319,
    3329,  3336,  3343,  3356,  3360,  3372,  3378,  3392,  3403,  3407,
    3411,  3415,  3419,  3423,  3427,  3431,  3441,  3445,  3455,  3460,
    3465,  3476,  3486,  3490,  3501,  3511,  3522,  3578,  3584,  3596,
    3602,  3614,  3618,  3628,  3632,  3636,  3646,  3654,  3662,  3670,
    3678,  3686,  3701,  3707,  3719,  3725,  3738,  3747,  3749,  3755,
    3760,  3772,  3775,  3782,  3788,  3794,  3802,  3817,  3820,  3827,
    3833,  3839,  3847,  3861,  3866,  3877,  3882,  3893,  3898,  3903,
    3909,  3921,  3927,  3932,  3937,  3948,  3953,  3968,  3973,  3990,
    4005,  4009,  4013,  4017,  4021,  4025,  4035,  4046,  4052,  4058,
    4063,  4085,  4091,  4097,  4102,  4113,  4123,  4133,  4139,  4145,
    4150,  4161,  4167,  4179,  4191,  4197,  4203,  4240,  4245,  4250,
    4261,  4265,  4269,  4279,  4290,  4294,  4298,  4302,  4306,  4310,
    4314,  4318,  4322,  4332,  4342,  4346,  4351,  4362,  4372,  4382,
    4386,  4390,  4400,  4406,  4412,  4418,  4424,  4436,  4447,  4454,
    4461,  4468,  4475,  4482,  4489,  4502,  4523,  4530,  4550,  4590,
    4595,  4598,  4606,  4612,  4618,  4624,  4630,  4637,  4643,  4649,
    4655,  4661,  4673,  4678,  4688,  4694,  4706,  4732,  4743,  4749,
    4762,  4776,  4783,  4790,  4801,  4808,  4816,  4825,  4838,  4841,
    4859,  4860,  4861,  4862,  4863,  4864,  4865,  4866,  4867,  4868,
    4869,  4870,  4871,  4872,  4873,  4874,  4875,  4876,  4877,  4878,
    4879,  4880,  4881,  4882,  4883,  4884,  4885,  4886,  4887,  4888,
    4889,  4890,  4891,  4892,  4893,  4894,  4895,  4896,  4897,  4898,
    4899,  4900,  4901,  4902,  4903,  4904,  4905,  4906,  4907,  4908,
    4909,  4910,  4911,  4912,  4913,  4914,  4915,  4916,  4917,  4918,
    4919,  4920,  4921,  4922,  4923,  4924,  4925,  4926,  4927,  4928,
    4929,  4930,  4931,  4932,  4933,  4934,  4935,  4936,  4937,  4938,
    4939,  4940,  4941,  4942,  4943,  4944,  4945,  4946,  4947,  4948,
    4949,  4950,  4951,  4952,  4953,  4954,  4955,  4956,  4957,  4958,
    4959,  4960,  4961,  4962,  4963,  4964,  4965,  4966,  4967,  4968,
    4969,  4970,  4971,  4972,  4973,  4974,  4975,  4976,  4977,  4978,
    4979,  4980,  4981,  4982,  4983,  4984,  4985,  4986,  4987,  4988,
    4989,  4990,  4991,  4992,  4993,  4994,  4995,  4996,  4997,  4998,
    4999,  5000,  5001,  5002,  5003,  5004,  5005,  5006,  5007,  5008,
    5009,  5010,  5011,  5012,  5013,  5014,  5015,  5016,  5017,  5018,
    5019,  5020,  5021,  5022,  5033,  5039,  5056,  5060,  5064,  5068,
    5078,  5081,  5084,  5087,  5096,  5099,  5108,  5111,  5120,  5123,
    5132,  5135,  5144,  5147,  5150,  5159,  5162,  5171,  5175,  5185,
    5188,  5191,  5194,  5197,  5206,  5215,  5219,  5223,  5227,  5231,
    5235,  5239,  5249,  5252,  5255,  5258,  5267,  5270,  5273,  5276,
    5285,  5288,  5297,  5300,  5303,  5306,  5309,  5312,  5315,  5324,
    5327,  5336,  5339,  5342,  5345,  5354,  5357,  5360,  5363,  5366,
    5375,  5378,  5387,  5390,  5399,  5402,  5411,  5414,  5423,  5432,
    5435,  5444,  5447,  5450,  5459,  5462,  5465,  5468,  5471,  5480,
    5484,  5488,  5492,  5502,  5511,  5521,  5530,  5533,  5542,  5545,
    5548,  5557,  5560,  5569
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
     285
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 8552;
  const int xquery_parser::yynnts_ = 251;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 465;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 286;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 540;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5577 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"


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

