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
#line 863 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"

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
        case 97: /* "\"'DECIMAL'\"" */
#line 747 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 109: /* "\"'DOUBLE'\"" */
#line 746 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 133: /* "\"'INTEGER'\"" */
#line 745 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "VersionDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "MainModule" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "LibraryModule" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "ModuleDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "Prolog" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "SIND_DeclList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "VFO_DeclList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "SIND_Decl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "VFO_Decl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "Setter" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "Import" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "NamespaceDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "BoundarySpaceDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "DefaultNamespaceDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "OptionDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "OrderingModeDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "EmptyOrderDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "CopyNamespacesDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "DefaultCollationDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "BaseURIDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "SchemaImport" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "URILiteralList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "SchemaPrefix" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "ModuleImport" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "CtxItemDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 346 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "CtxItemDecl2" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "CtxItemDecl3" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 356 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "CtxItemDecl4" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 361 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "VarNameAndType" */
#line 759 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };
#line 366 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "VarDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 371 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "IndexDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 376 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "IndexDecl2" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 381 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "IndexDeclSuffix" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 386 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "IndexField" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 391 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "IndexField1" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 396 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "IndexFieldList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 401 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "ConstructionDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 406 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "FunctionSig" */
#line 759 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 411 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "BlockExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 416 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "Block" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 421 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "AssignExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 426 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "ExitExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 431 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "WhileExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 436 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "FlowCtlStatement" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 441 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "IndexStatement" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 446 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "FunctionDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 451 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "FunctionDecl2" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 456 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "FunctionDecl3" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 461 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "FunctionDecl4" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 466 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "ParamList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 471 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "Param" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "EnclosedExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 481 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "BracedExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 486 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "QueryBody" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 491 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "Expr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 496 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "ApplyExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 501 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "ConcatExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 506 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ExprSingle" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 511 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "FLWORExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 516 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "ReturnExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 521 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "FLWORWinCond" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "WindowClause" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CountClause" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 536 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "ForLetWinClause" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "FLWORClauseList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "ForClause" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 551 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "VarInDeclList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 556 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "VarInDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 561 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "PositionalVar" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 566 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "LetClause" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 571 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "VarGetsDeclList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 576 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "EvalVarDeclList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 581 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "VarGetsDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 586 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "WindowVarDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 591 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "WindowVars" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 596 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "WindowVars3" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 601 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "WindowVars2" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 606 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "EvalVarDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 611 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "WhereClause" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 616 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "GroupByClause" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 621 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "GroupSpecList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 626 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "GroupSpec" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 631 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "GroupCollationSpec" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 636 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "OrderByClause" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 641 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "OrderSpecList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 646 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "OrderSpec" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 651 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "OrderModifier" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 656 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "OrderDirSpec" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 661 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "OrderEmptySpec" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 666 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "OrderCollationSpec" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 671 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "QuantifiedExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 676 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "QVarInDeclList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 681 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "QVarInDecl" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 686 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "TypeswitchExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 691 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "CaseClauseList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 696 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "CaseClause" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 701 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "IfExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 706 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "OrExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 711 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "AndExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 716 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ComparisonExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 721 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "FTContainsExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 726 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "RangeExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 731 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "AdditiveExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 736 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "MultiplicativeExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 741 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "UnionExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 746 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "IntersectExceptExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 751 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "InstanceofExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 756 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "TreatExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 761 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "CastableExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 766 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "CastExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 771 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "UnaryExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 776 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "SignList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 781 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "ValueExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 786 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "ValueComp" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 791 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "NodeComp" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 796 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "ValidateExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 801 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ExtensionExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 806 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "PragmaList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 811 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "Pragma" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 816 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "PathExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 821 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "RelativePathExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 826 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "StepExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 831 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "AxisStep" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 836 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "ForwardStep" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 841 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "ForwardAxis" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 846 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "AbbrevForwardStep" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 851 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "ReverseStep" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 856 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "ReverseAxis" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 861 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "NodeTest" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 866 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "NameTest" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 871 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "Wildcard" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 876 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "FilterExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 881 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "PredicateList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 886 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "Predicate" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 891 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "PrimaryExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 896 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "Literal" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 901 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "NumericLiteral" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 906 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "VarRef" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 911 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "ParenthesizedExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 916 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "ContextItemExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 921 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrderedExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 926 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "UnorderedExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 931 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "FunctionCall" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 936 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "ArgList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 941 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "Constructor" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 946 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "DirectConstructor" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 951 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "DirElemConstructor" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 956 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "DirElemContentList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 961 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "DirAttributeList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 966 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "DirAttr" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 971 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "DirAttributeValue" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 976 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "Opt_QuoteAttrContentList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 981 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "QuoteAttrContentList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 986 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "Opt_AposAttrContentList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 991 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "AposAttrContentList" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 996 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "QuoteAttrValueContent" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1001 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "AposAttrValueContent" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1006 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "DirElemContent" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1011 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "CommonContent" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1016 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "DirCommentConstructor" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1021 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "DirPIConstructor" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1026 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "CDataSection" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1031 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ComputedConstructor" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1036 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CompDocConstructor" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1041 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "CompElemConstructor" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1046 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "CompAttrConstructor" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1051 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "CompTextConstructor" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1056 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "CompCommentConstructor" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1061 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "CompPIConstructor" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1066 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "SingleType" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1071 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "TypeDeclaration" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1076 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "SequenceType" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1081 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "OccurrenceIndicator" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1086 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "ItemType" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1091 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "AtomicType" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1096 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "KindTest" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1101 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "AnyKindTest" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1106 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "DocumentTest" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1111 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "TextTest" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1116 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "CommentTest" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1121 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "PITest" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1126 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "AttributeTest" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1131 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "SchemaAttributeTest" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1136 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ElementTest" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1141 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "SchemaElementTest" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1146 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "TypeName" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1151 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "TypeName_WITH_HOOK" */
#line 755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); };
#line 1156 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "StringLiteral" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1161 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "InsertExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1166 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DeleteExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1171 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ReplaceExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1176 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "RenameExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1181 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "TransformExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1186 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "VarNameList" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1191 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "VarNameDecl" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1196 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "TryExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1201 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "CatchListExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1206 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "CatchExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); };
#line 1211 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "EvalExpr" */
#line 757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
    #line 113 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 881 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 4:
#line 891 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 896 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 902 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 7:
#line 907 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 8:
#line 919 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		;}
    break;

  case 9:
#line 924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    ;}
    break;

  case 10:
#line 934 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 11:
#line 941 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		;}
    break;

  case 12:
#line 953 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 13:
#line 965 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), 
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
		;}
    break;

  case 14:
#line 977 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 15:
#line 983 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 16:
#line 989 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 17:
#line 1001 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 18:
#line 1007 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 1021 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 20:
#line 1027 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 41:
#line 1095 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 42:
#line 1107 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 43:
#line 1112 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 44:
#line 1123 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 45:
#line 1129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 46:
#line 1141 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 47:
#line 1154 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		;}
    break;

  case 48:
#line 1165 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 49:
#line 1170 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 50:
#line 1182 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 51:
#line 1187 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 52:
#line 1198 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 53:
#line 1204 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 54:
#line 1210 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 55:
#line 1216 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 56:
#line 1235 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 57:
#line 1246 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 58:
#line 1257 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 59:
#line 1264 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		;}
    break;

  case 60:
#line 1271 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 61:
#line 1278 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 62:
#line 1291 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 63:
#line 1297 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 64:
#line 1312 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 65:
#line 1316 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 66:
#line 1326 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 67:
#line 1332 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		;}
    break;

  case 68:
#line 1339 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 69:
#line 1345 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		;}
    break;

  case 70:
#line 1357 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    ;}
    break;

  case 71:
#line 1364 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    ;}
    break;

  case 72:
#line 1370 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 73:
#line 1377 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    ;}
    break;

  case 74:
#line 1383 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    ;}
    break;

  case 75:
#line 1387 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 76:
#line 1394 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 77:
#line 1405 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (SYMTAB ((yysemantic_stack_[(2) - (2)].sval)), NULL);
    ;}
    break;

  case 78:
#line 1409 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
                               dynamic_cast<TypeDeclaration *> ((yysemantic_stack_[(3) - (3)].node)));
    ;}
    break;

  case 79:
#line 1417 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1426 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(4) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      delete nt;
		;}
    break;

  case 81:
#line 1433 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(6) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      delete nt;
		;}
    break;

  case 82:
#line 1443 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "hash"; ;}
    break;

  case 83:
#line 1445 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "btree"; ;}
    break;

  case 84:
#line 1452 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->create = false;
      (yyval.node) = d;
    ;}
    break;

  case 85:
#line 1460 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 86:
#line 1464 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->uniq = true;
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 87:
#line 1472 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(7) - (2)].sval)), (yysemantic_stack_[(7) - (4)].expr), "",
                          dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(7) - (6)].node)));
    ;}
    break;

  case 88:
#line 1477 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = new IndexDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(8) - (2)].sval)), (yysemantic_stack_[(8) - (4)].expr), SYMTAB ((yysemantic_stack_[(8) - (5)].strval)),
                                    dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(8) - (7)].node)));
      d->method = (yysemantic_stack_[(8) - (5)].strval);
      (yyval.node) = d;
    ;}
    break;

  case 89:
#line 1487 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 90:
#line 1491 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (1)].node))->coll = SYMTAB ((yysemantic_stack_[(3) - (3)].sval));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    ;}
    break;

  case 91:
#line 1499 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL);
    ;}
    break;

  case 92:
#line 1503 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<TypeDeclaration *> ((yysemantic_stack_[(2) - (2)].node)));
    ;}
    break;

  case 93:
#line 1510 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexFieldList *l = new IndexFieldList (LOC ((yyloc)));
      l->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
      
    ;}
    break;

  case 94:
#line 1517 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(3) - (1)].node))->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    ;}
    break;

  case 95:
#line 1527 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 96:
#line 1532 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 97:
#line 1544 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 98:
#line 1548 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 99:
#line 1552 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 100:
#line 1556 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 101:
#line 1563 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 102:
#line 1570 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    ;}
    break;

  case 103:
#line 1577 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (3)].sval)), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 104:
#line 1584 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 105:
#line 1591 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *b = dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr));
      if (b == NULL) {
        b = new BlockBody ((yysemantic_stack_[(5) - (5)].expr)->get_location ()); 
        b->add ((yysemantic_stack_[(5) - (5)].expr));
      }
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), b);
    ;}
    break;

  case 106:
#line 1603 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 107:
#line 1607 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 108:
#line 1614 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::create_stmt);
    ;}
    break;

  case 109:
#line 1618 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::drop_stmt);
    ;}
    break;

  case 110:
#line 1622 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::build_stmt);
    ;}
    break;

  case 111:
#line 1629 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 112:
#line 1633 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->deterministic = false;
      (yyval.node) = d;
    ;}
    break;

  case 113:
#line 1639 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    ;}
    break;

  case 114:
#line 1646 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 115:
#line 1650 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 116:
#line 1654 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    ;}
    break;

  case 117:
#line 1662 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 118:
#line 1669 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1690 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1704 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 122:
#line 1712 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 123:
#line 1726 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 124:
#line 1732 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 125:
#line 1744 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 126:
#line 1752 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 127:
#line 1763 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 128:
#line 1775 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 129:
#line 1779 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1791 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    ;}
    break;

  case 131:
#line 1795 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 132:
#line 1804 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 133:
#line 1808 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1855 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 153:
#line 1864 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 154:
#line 1871 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    ;}
    break;

  case 155:
#line 1875 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    ;}
    break;

  case 156:
#line 1883 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    ;}
    break;

  case 157:
#line 1887 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    ;}
    break;

  case 158:
#line 1891 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    ;}
    break;

  case 159:
#line 1898 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 160:
#line 1902 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 161:
#line 1909 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)), dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 162:
#line 1914 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    ;}
    break;

  case 163:
#line 1923 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 172:
#line 1941 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 173:
#line 1947 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 174:
#line 1956 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    ;}
    break;

  case 175:
#line 1960 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    ;}
    break;

  case 176:
#line 1970 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		;}
    break;

  case 177:
#line 1981 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 178:
#line 1987 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 179:
#line 2001 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 180:
#line 2008 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 181:
#line 2016 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2025 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2035 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 184:
#line 2043 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2052 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2061 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2076 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 188:
#line 2088 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 189:
#line 2099 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 190:
#line 2111 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 191:
#line 2117 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 192:
#line 2129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 193:
#line 2135 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 194:
#line 2149 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 195:
#line 2157 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 196:
#line 2166 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 197:
#line 2174 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 198:
#line 2186 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 199:
#line 2192 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 201:
#line 2203 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, SYMTAB ((yysemantic_stack_[(2) - (2)].sval)), "", "");
    ;}
    break;

  case 202:
#line 2207 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
    ;}
    break;

  case 203:
#line 2215 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    ;}
    break;

  case 204:
#line 2219 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    ;}
    break;

  case 206:
#line 2228 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (6)].sval)));
    ;}
    break;

  case 207:
#line 2232 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 208:
#line 2236 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), "");
    ;}
    break;

  case 209:
#line 2243 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = SYMTAB ((yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 210:
#line 2258 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 211:
#line 2266 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 212:
#line 2276 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 213:
#line 2282 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 214:
#line 2293 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 SYMTAB ((yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 215:
#line 2299 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 216:
#line 2308 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 217:
#line 2318 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 218:
#line 2323 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 219:
#line 2335 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 220:
#line 2341 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 221:
#line 2355 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 222:
#line 2361 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 223:
#line 2373 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 224:
#line 2380 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 225:
#line 2387 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 226:
#line 2394 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 227:
#line 2401 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 228:
#line 2408 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 229:
#line 2415 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 230:
#line 2428 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 231:
#line 2432 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 232:
#line 2442 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 233:
#line 2447 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 234:
#line 2458 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 235:
#line 2469 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 236:
#line 2476 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 237:
#line 2489 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 238:
#line 2496 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 239:
#line 2508 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 240:
#line 2514 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 241:
#line 2527 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 242:
#line 2534 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								SYMTAB ((yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 243:
#line 2548 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 244:
#line 2554 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 245:
#line 2566 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 246:
#line 2572 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 247:
#line 2585 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 248:
#line 2596 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 249:
#line 2600 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 250:
#line 2611 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 251:
#line 2615 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 252:
#line 2634 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 253:
#line 2638 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 254:
#line 2646 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 255:
#line 2654 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 256:
#line 2662 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 257:
#line 2669 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 258:
#line 2670 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 259:
#line 2678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 260:
#line 2686 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 261:
#line 2694 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 262:
#line 2708 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 263:
#line 2712 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 264:
#line 2719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 265:
#line 2732 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 266:
#line 2736 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 267:
#line 2747 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 268:
#line 2751 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 269:
#line 2755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 270:
#line 2765 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 271:
#line 2769 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 272:
#line 2773 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 273:
#line 2777 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 274:
#line 2781 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 275:
#line 2791 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 276:
#line 2795 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 277:
#line 2800 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 278:
#line 2811 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 279:
#line 2815 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 280:
#line 2819 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 281:
#line 2829 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 2833 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 283:
#line 2845 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 284:
#line 2849 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 285:
#line 2861 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 286:
#line 2865 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 287:
#line 2877 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 288:
#line 2881 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 289:
#line 2893 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 290:
#line 2897 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 291:
#line 2909 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 292:
#line 2913 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 293:
#line 2917 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 294:
#line 2921 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 295:
#line 2933 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 296:
#line 2937 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 297:
#line 2941 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 298:
#line 2951 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 299:
#line 2955 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 300:
#line 2959 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 301:
#line 2963 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 302:
#line 2967 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 303:
#line 2971 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 304:
#line 2981 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 305:
#line 2985 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 306:
#line 2989 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 307:
#line 2999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 308:
#line 3003 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 309:
#line 3007 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 310:
#line 3011 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    ;}
    break;

  case 311:
#line 3023 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 312:
#line 3029 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 313:
#line 3041 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 314:
#line 3047 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 315:
#line 3061 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(3) - (2)].sval))),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 316:
#line 3067 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 317:
#line 3109 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 318:
#line 3113 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 319:
#line 3117 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 320:
#line 3121 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 321:
#line 3133 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    ;}
    break;

  case 322:
#line 3143 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 323:
#line 3154 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 324:
#line 3159 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 325:
#line 3169 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 326:
#line 3173 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 327:
#line 3183 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 328:
#line 3189 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 329:
#line 3195 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 330:
#line 3201 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 331:
#line 3213 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 332:
#line 3219 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 333:
#line 3230 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 334:
#line 3234 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 335:
#line 3238 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 336:
#line 3242 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 337:
#line 3246 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 338:
#line 3250 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 339:
#line 3254 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 340:
#line 3264 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 341:
#line 3268 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 342:
#line 3278 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 343:
#line 3284 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 344:
#line 3296 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 345:
#line 3300 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 346:
#line 3304 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 347:
#line 3308 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 348:
#line 3312 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 349:
#line 3327 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 350:
#line 3331 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 351:
#line 3341 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 352:
#line 3345 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 353:
#line 3355 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 354:
#line 3362 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 355:
#line 3369 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 356:
#line 3382 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 357:
#line 3386 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 358:
#line 3398 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 359:
#line 3404 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 360:
#line 3418 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 361:
#line 3429 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 362:
#line 3433 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 363:
#line 3437 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 364:
#line 3441 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 365:
#line 3445 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 366:
#line 3449 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 367:
#line 3453 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 368:
#line 3457 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 369:
#line 3467 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 370:
#line 3471 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 371:
#line 3481 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 372:
#line 3486 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 373:
#line 3491 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 374:
#line 3502 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 375:
#line 3512 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 376:
#line 3516 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 377:
#line 3527 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 378:
#line 3537 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 379:
#line 3548 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 380:
#line 3604 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 381:
#line 3610 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 382:
#line 3622 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 383:
#line 3628 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 384:
#line 3640 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 385:
#line 3644 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 386:
#line 3654 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 387:
#line 3658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 388:
#line 3662 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 389:
#line 3672 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 390:
#line 3680 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 391:
#line 3688 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 392:
#line 3696 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 393:
#line 3704 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 394:
#line 3712 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 395:
#line 3727 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 396:
#line 3733 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 397:
#line 3745 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 398:
#line 3751 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 399:
#line 3764 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 402:
#line 3781 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 403:
#line 3786 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 404:
#line 3797 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 405:
#line 3801 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 406:
#line 3808 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 407:
#line 3814 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 408:
#line 3820 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 409:
#line 3828 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 410:
#line 3842 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 411:
#line 3846 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 412:
#line 3853 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 413:
#line 3859 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 414:
#line 3865 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 415:
#line 3873 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 416:
#line 3887 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 417:
#line 3892 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 418:
#line 3903 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 419:
#line 3908 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 420:
#line 3919 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 421:
#line 3924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 422:
#line 3929 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 423:
#line 3935 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 424:
#line 3947 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 425:
#line 3953 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 426:
#line 3958 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 427:
#line 3963 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 428:
#line 3974 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 429:
#line 3979 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 430:
#line 3994 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 431:
#line 3999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 432:
#line 4016 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 433:
#line 4031 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 434:
#line 4035 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 435:
#line 4039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 436:
#line 4043 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 437:
#line 4047 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 438:
#line 4051 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 439:
#line 4061 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 440:
#line 4072 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 441:
#line 4078 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 442:
#line 4084 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 443:
#line 4089 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 444:
#line 4111 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 445:
#line 4117 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 446:
#line 4123 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 447:
#line 4128 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 448:
#line 4139 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 449:
#line 4149 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 450:
#line 4159 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 451:
#line 4165 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 452:
#line 4171 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 453:
#line 4176 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 454:
#line 4187 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 455:
#line 4193 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 456:
#line 4205 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 457:
#line 4217 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 458:
#line 4223 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 459:
#line 4229 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 460:
#line 4266 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 461:
#line 4271 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 462:
#line 4276 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 463:
#line 4287 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
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
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 466:
#line 4305 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 467:
#line 4316 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 468:
#line 4320 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 469:
#line 4324 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 470:
#line 4328 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 471:
#line 4332 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 472:
#line 4336 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 473:
#line 4340 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 474:
#line 4344 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 475:
#line 4348 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 476:
#line 4358 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 477:
#line 4368 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 478:
#line 4372 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 479:
#line 4377 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 480:
#line 4388 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 481:
#line 4398 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 482:
#line 4408 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 483:
#line 4412 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 484:
#line 4416 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 485:
#line 4426 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 486:
#line 4432 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 487:
#line 4438 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 488:
#line 4444 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 489:
#line 4450 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 490:
#line 4462 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 491:
#line 4473 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		;}
    break;

  case 492:
#line 4480 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
                           NULL,
                           true);
		;}
    break;

  case 493:
#line 4487 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		;}
    break;

  case 494:
#line 4494 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		;}
    break;

  case 495:
#line 4501 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 496:
#line 4508 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		;}
    break;

  case 497:
#line 4515 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 498:
#line 4528 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 499:
#line 4549 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 500:
#line 4556 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 501:
#line 4576 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 502:
#line 4616 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 503:
#line 4621 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 504:
#line 4624 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 505:
#line 4632 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 506:
#line 4638 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 507:
#line 4644 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 508:
#line 4650 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 509:
#line 4656 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 510:
#line 4663 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 511:
#line 4669 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 512:
#line 4675 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 513:
#line 4681 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 514:
#line 4687 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 515:
#line 4699 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 516:
#line 4704 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 517:
#line 4714 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 518:
#line 4720 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 519:
#line 4732 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 520:
#line 4758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 521:
#line 4769 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 522:
#line 4775 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 523:
#line 4788 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 524:
#line 4802 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 525:
#line 4809 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 526:
#line 4816 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 527:
#line 4827 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 528:
#line 4834 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 529:
#line 4842 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(11) - (6)].sval)),
                          SYMTAB ((yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 530:
#line 4851 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(14) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(14) - (6)].sval)),
                          SYMTAB ((yysemantic_stack_[(14) - (9)].sval)),
                          SYMTAB ((yysemantic_stack_[(14) - (12)].sval)),
                          (yysemantic_stack_[(14) - (14)].expr));
    ;}
    break;

  case 532:
#line 4867 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 533:
#line 4884 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 534:
#line 4885 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); ;}
    break;

  case 535:
#line 4886 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); ;}
    break;

  case 536:
#line 4887 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); ;}
    break;

  case 537:
#line 4888 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); ;}
    break;

  case 538:
#line 4889 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); ;}
    break;

  case 539:
#line 4890 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); ;}
    break;

  case 540:
#line 4891 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); ;}
    break;

  case 541:
#line 4892 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); ;}
    break;

  case 542:
#line 4893 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); ;}
    break;

  case 543:
#line 4894 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); ;}
    break;

  case 544:
#line 4895 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); ;}
    break;

  case 545:
#line 4896 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); ;}
    break;

  case 546:
#line 4897 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); ;}
    break;

  case 547:
#line 4898 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); ;}
    break;

  case 548:
#line 4899 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); ;}
    break;

  case 549:
#line 4900 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); ;}
    break;

  case 550:
#line 4901 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); ;}
    break;

  case 551:
#line 4902 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); ;}
    break;

  case 552:
#line 4903 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); ;}
    break;

  case 553:
#line 4904 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); ;}
    break;

  case 554:
#line 4905 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); ;}
    break;

  case 555:
#line 4906 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); ;}
    break;

  case 556:
#line 4907 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); ;}
    break;

  case 557:
#line 4908 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); ;}
    break;

  case 558:
#line 4909 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); ;}
    break;

  case 559:
#line 4910 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); ;}
    break;

  case 560:
#line 4911 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); ;}
    break;

  case 561:
#line 4912 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); ;}
    break;

  case 562:
#line 4913 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); ;}
    break;

  case 563:
#line 4914 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); ;}
    break;

  case 564:
#line 4915 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); ;}
    break;

  case 565:
#line 4916 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); ;}
    break;

  case 566:
#line 4917 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); ;}
    break;

  case 567:
#line 4918 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); ;}
    break;

  case 568:
#line 4919 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); ;}
    break;

  case 569:
#line 4920 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); ;}
    break;

  case 570:
#line 4921 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); ;}
    break;

  case 571:
#line 4922 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); ;}
    break;

  case 572:
#line 4923 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); ;}
    break;

  case 573:
#line 4924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); ;}
    break;

  case 574:
#line 4925 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); ;}
    break;

  case 575:
#line 4926 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); ;}
    break;

  case 576:
#line 4927 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); ;}
    break;

  case 577:
#line 4928 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); ;}
    break;

  case 578:
#line 4929 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); ;}
    break;

  case 579:
#line 4930 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); ;}
    break;

  case 580:
#line 4931 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); ;}
    break;

  case 581:
#line 4932 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); ;}
    break;

  case 582:
#line 4933 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); ;}
    break;

  case 583:
#line 4934 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); ;}
    break;

  case 584:
#line 4935 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); ;}
    break;

  case 585:
#line 4936 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); ;}
    break;

  case 586:
#line 4937 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); ;}
    break;

  case 587:
#line 4938 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); ;}
    break;

  case 588:
#line 4939 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); ;}
    break;

  case 589:
#line 4940 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); ;}
    break;

  case 590:
#line 4941 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); ;}
    break;

  case 591:
#line 4942 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); ;}
    break;

  case 592:
#line 4943 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); ;}
    break;

  case 593:
#line 4944 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); ;}
    break;

  case 594:
#line 4945 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); ;}
    break;

  case 595:
#line 4946 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); ;}
    break;

  case 596:
#line 4947 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); ;}
    break;

  case 597:
#line 4948 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); ;}
    break;

  case 598:
#line 4949 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); ;}
    break;

  case 599:
#line 4950 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); ;}
    break;

  case 600:
#line 4951 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); ;}
    break;

  case 601:
#line 4952 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); ;}
    break;

  case 602:
#line 4953 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); ;}
    break;

  case 603:
#line 4954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); ;}
    break;

  case 604:
#line 4955 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); ;}
    break;

  case 605:
#line 4956 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); ;}
    break;

  case 606:
#line 4957 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); ;}
    break;

  case 607:
#line 4958 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); ;}
    break;

  case 608:
#line 4959 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); ;}
    break;

  case 609:
#line 4960 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); ;}
    break;

  case 610:
#line 4961 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); ;}
    break;

  case 611:
#line 4962 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); ;}
    break;

  case 612:
#line 4963 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); ;}
    break;

  case 613:
#line 4964 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); ;}
    break;

  case 614:
#line 4965 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); ;}
    break;

  case 615:
#line 4966 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); ;}
    break;

  case 616:
#line 4967 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); ;}
    break;

  case 617:
#line 4968 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); ;}
    break;

  case 618:
#line 4969 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); ;}
    break;

  case 619:
#line 4970 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); ;}
    break;

  case 620:
#line 4971 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); ;}
    break;

  case 621:
#line 4972 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); ;}
    break;

  case 622:
#line 4973 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); ;}
    break;

  case 623:
#line 4974 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); ;}
    break;

  case 624:
#line 4975 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); ;}
    break;

  case 625:
#line 4976 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); ;}
    break;

  case 626:
#line 4977 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); ;}
    break;

  case 627:
#line 4978 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); ;}
    break;

  case 628:
#line 4979 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); ;}
    break;

  case 629:
#line 4980 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); ;}
    break;

  case 630:
#line 4981 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); ;}
    break;

  case 631:
#line 4982 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); ;}
    break;

  case 632:
#line 4983 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); ;}
    break;

  case 633:
#line 4984 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); ;}
    break;

  case 634:
#line 4985 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); ;}
    break;

  case 635:
#line 4986 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); ;}
    break;

  case 636:
#line 4987 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); ;}
    break;

  case 637:
#line 4988 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); ;}
    break;

  case 638:
#line 4989 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); ;}
    break;

  case 639:
#line 4990 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); ;}
    break;

  case 640:
#line 4991 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); ;}
    break;

  case 641:
#line 4992 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); ;}
    break;

  case 642:
#line 4993 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); ;}
    break;

  case 643:
#line 4994 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); ;}
    break;

  case 644:
#line 4995 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); ;}
    break;

  case 645:
#line 4996 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); ;}
    break;

  case 646:
#line 4997 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); ;}
    break;

  case 647:
#line 4998 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); ;}
    break;

  case 648:
#line 4999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); ;}
    break;

  case 649:
#line 5000 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); ;}
    break;

  case 650:
#line 5001 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); ;}
    break;

  case 651:
#line 5002 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); ;}
    break;

  case 652:
#line 5003 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); ;}
    break;

  case 653:
#line 5004 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); ;}
    break;

  case 654:
#line 5005 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); ;}
    break;

  case 655:
#line 5006 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); ;}
    break;

  case 656:
#line 5007 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); ;}
    break;

  case 657:
#line 5008 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); ;}
    break;

  case 658:
#line 5009 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); ;}
    break;

  case 659:
#line 5010 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); ;}
    break;

  case 660:
#line 5011 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); ;}
    break;

  case 661:
#line 5012 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); ;}
    break;

  case 662:
#line 5013 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); ;}
    break;

  case 663:
#line 5014 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); ;}
    break;

  case 664:
#line 5015 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); ;}
    break;

  case 665:
#line 5016 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); ;}
    break;

  case 666:
#line 5017 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); ;}
    break;

  case 667:
#line 5018 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); ;}
    break;

  case 668:
#line 5019 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); ;}
    break;

  case 669:
#line 5020 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); ;}
    break;

  case 670:
#line 5021 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); ;}
    break;

  case 671:
#line 5022 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); ;}
    break;

  case 672:
#line 5023 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); ;}
    break;

  case 673:
#line 5024 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); ;}
    break;

  case 674:
#line 5025 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); ;}
    break;

  case 675:
#line 5026 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); ;}
    break;

  case 676:
#line 5027 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); ;}
    break;

  case 677:
#line 5028 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); ;}
    break;

  case 678:
#line 5029 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); ;}
    break;

  case 679:
#line 5030 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); ;}
    break;

  case 680:
#line 5031 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); ;}
    break;

  case 681:
#line 5032 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); ;}
    break;

  case 682:
#line 5033 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); ;}
    break;

  case 683:
#line 5034 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); ;}
    break;

  case 684:
#line 5035 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); ;}
    break;

  case 685:
#line 5036 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); ;}
    break;

  case 686:
#line 5037 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); ;}
    break;

  case 687:
#line 5038 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); ;}
    break;

  case 688:
#line 5039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); ;}
    break;

  case 689:
#line 5040 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); ;}
    break;

  case 690:
#line 5041 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); ;}
    break;

  case 691:
#line 5042 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); ;}
    break;

  case 692:
#line 5043 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); ;}
    break;

  case 693:
#line 5044 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); ;}
    break;

  case 694:
#line 5045 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); ;}
    break;

  case 695:
#line 5046 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); ;}
    break;

  case 696:
#line 5047 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); ;}
    break;

  case 697:
#line 5048 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); ;}
    break;

  case 698:
#line 5049 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); ;}
    break;

  case 699:
#line 5050 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); ;}
    break;

  case 700:
#line 5051 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); ;}
    break;

  case 701:
#line 5052 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("create"); ;}
    break;

  case 702:
#line 5053 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("build"); ;}
    break;

  case 703:
#line 5054 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); ;}
    break;

  case 704:
#line 5055 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); ;}
    break;

  case 705:
#line 5056 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("hash"); ;}
    break;

  case 706:
#line 5057 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("btree"); ;}
    break;

  case 707:
#line 5058 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("drop"); ;}
    break;

  case 708:
#line 5070 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 709:
#line 5076 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 710:
#line 5093 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 711:
#line 5097 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 712:
#line 5101 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 713:
#line 5105 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 714:
#line 5115 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 715:
#line 5118 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 716:
#line 5121 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 717:
#line 5124 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 718:
#line 5133 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 719:
#line 5136 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 720:
#line 5145 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 721:
#line 5148 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 722:
#line 5157 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 723:
#line 5160 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 724:
#line 5169 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 725:
#line 5172 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 726:
#line 5181 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 727:
#line 5184 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 728:
#line 5187 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 729:
#line 5196 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 730:
#line 5199 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 731:
#line 5208 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 732:
#line 5212 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 733:
#line 5222 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 734:
#line 5225 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 735:
#line 5228 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 736:
#line 5231 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 737:
#line 5234 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 738:
#line 5243 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 739:
#line 5252 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 740:
#line 5256 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 741:
#line 5260 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 742:
#line 5264 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 743:
#line 5268 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 744:
#line 5272 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 745:
#line 5276 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 746:
#line 5286 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 747:
#line 5289 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 748:
#line 5292 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 749:
#line 5295 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 750:
#line 5304 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 751:
#line 5307 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 752:
#line 5310 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 753:
#line 5313 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 754:
#line 5322 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 755:
#line 5325 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 756:
#line 5334 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 757:
#line 5337 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 758:
#line 5340 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 759:
#line 5343 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 760:
#line 5346 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 761:
#line 5349 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 762:
#line 5352 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 763:
#line 5361 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 764:
#line 5364 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 765:
#line 5373 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 766:
#line 5376 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 767:
#line 5379 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 768:
#line 5382 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 769:
#line 5391 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 770:
#line 5394 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 771:
#line 5397 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 772:
#line 5400 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 773:
#line 5403 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 774:
#line 5412 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 775:
#line 5415 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 776:
#line 5424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 777:
#line 5427 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 778:
#line 5436 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 779:
#line 5439 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 780:
#line 5448 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 781:
#line 5451 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 782:
#line 5460 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 783:
#line 5469 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 784:
#line 5472 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 785:
#line 5481 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 786:
#line 5484 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 787:
#line 5487 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 788:
#line 5496 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 789:
#line 5499 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 790:
#line 5502 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 791:
#line 5505 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 792:
#line 5508 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 793:
#line 5517 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 794:
#line 5521 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 795:
#line 5525 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 796:
#line 5529 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 797:
#line 5539 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 798:
#line 5548 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 799:
#line 5558 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 800:
#line 5567 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 801:
#line 5570 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 802:
#line 5579 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 803:
#line 5582 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 804:
#line 5585 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 805:
#line 5594 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 806:
#line 5597 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 807:
#line 5606 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6943 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -995;
  const short int
  xquery_parser::yypact_[] =
  {
      1333,  -995,  -995,  -995,  -995,    80,   -49,   305,  -995,   384,
     284,   -22,   304,  6279,   323,   356,   433,    51,  -995,  -995,
    -995,  -995,  -995,  -995,   367,   134,  -995,   566,   466,  -995,
     385,  -995,  -995,  -995,   472,   478,  -995,   401,   412,   541,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,   479,
     482,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  6532,  -995,  5510,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  8050,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,   525,  -995,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  1595,  8050,
    -995,  -995,  -995,  -995,  -995,  -995,   504,  -995,  -995,  -995,
    -995,   631,  -995,  6026,  -995,  -995,  -995,  -995,  -995,  8050,
    -995,  -995,  5249,  -995,  -995,  -995,  -995,  -995,  -995,   510,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,    15,   450,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,   166,   514,
     414,  -995,   447,   136,  -995,  -995,  -995,  -995,  -995,  -995,
     553,  -995,   528,  -995,   557,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,   416,   421,   423,  -995,  -995,  -995,  -995,  -995,  3944,
     675,  -995,  4205,  -995,  -995,   453,  4466,   505,   517,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,   -12,  -995,
    -995,  -995,  -995,   328,  8050,  -995,  -995,  -995,  -995,  -995,
     543,   613,  -995,   518,   456,   330,   223,   225,   249,  -995,
     622,   515,   609,   612,  4727,  -995,  -995,  -995,   224,  -995,
    -995,  5249,  -995,   430,  -995,   564,  5510,  -995,   564,  5510,
    -995,  -995,  -995,  -995,   564,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,   563,  -995,  4466,  -995,  4466,  -995,  -995,
    4466,  8050,  4466,   574,   575,  4466,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  4466,  6785,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,   576,  4466,
    4466,   544,  4466,   545,  8050,   677,   678,   556,   556,   677,
    8050,   386,   -53,   698,   -34,   389,   583,   615,   210,   703,
     422,    72,   455,   698,  -995,  -995,  -995,  -995,  4466,  -995,
    4466,    26,   586,    47,    41,  8050,   703,  8050,  8050,  4466,
     468,   469,  -995,   621,   623,  8050,    73,  4466,  7038,   590,
     589,   591,   592,   597,   599,  -995,  -995,  -995,  8050,  -995,
     560,   715,  4466,    44,  -995,   726,   572,  -995,  4466,   546,
    -995,   724,  4466,  4466,   577,  4466,  4466,  4466,  4466,   530,
    8050,  4466,  8050,   698,   698,   698,  -995,  -995,  -995,  -995,
      51,   566,  -995,  -995,   453,   708,  4466,  -995,  4466,   595,
     478,   412,   541,   645,   598,   601,  4466,  4466,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,   657,  -995,   -18,  4988,  4988,
    4988,  -995,  4988,  4988,  -995,  4988,  -995,  4988,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  4988,  4988,    20,  4988,  4988,
    4988,  4988,  4988,  4988,  4988,  4988,  4988,  4988,  4988,   542,
     672,   679,   680,  -995,  -995,  -995,  1856,  -995,  -995,  5249,
    5249,  4466,   564,  -995,  -995,   564,  -995,   564,  2117,   596,
    -995,   594,   629,  -995,   603,  4466,  4466,   602,   604,  -995,
       8,    17,  2378,   606,   607,  -995,   608,  -995,   619,  -995,
    8050,  -995,  -995,  -995,  -995,   756,  -995,  -995,  -995,  -995,
    -995,  -995,   683,   684,  -995,  -995,   325,  8050,   404,   635,
     636,   698,   669,   665,  -995,  -995,  -995,   380,    61,   391,
     763,  -995,  -995,   301,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,   516,   614,   618,   617,  -995,   620,  2639,
     703,   705,   755,   703,   698,   709,   -24,  -995,    -9,   674,
     666,   700,  -995,   -29,   628,  -995,  -995,  8050,   -25,  -995,
     626,   589,   479,  -995,   627,   630,   632,  -995,    18,   137,
    2900,   -17,  -995,  8050,   715,  -995,    -7,   634,  -995,  -995,
    -995,  -995,   637,  -995,   113,  -995,  -995,  -995,    33,   108,
     717,   581,   600,    -6,  -995,   676,   638,   288,  -995,  -995,
    -995,  -995,  -995,   633,  -995,   -14,  -995,  -995,     3,   654,
    8050,  4466,   706,  -995,  -995,   707,  7544,   710,  4466,   711,
     -69,   682,   -26,   613,  -995,  -995,  -995,  -995,  -995,  4988,
    -995,  -995,  -995,  4466,    20,   373,  -995,   561,   222,   579,
     570,  -995,  -995,   569,   262,   223,   223,   260,   225,   225,
     225,   225,   249,   249,  -995,  -995,  7544,  7544,  8050,  8050,
    -995,   652,  -995,  -995,   653,  -995,  -995,  -995,   143,  -995,
      80,  4466,  -995,   655,   656,   733,   687,  8050,  -995,  8050,
    -995,  -995,   658,  -995,  -995,  -995,   173,   283,   619,  -995,
      -4,   279,  7797,   699,  4466,  -995,  -995,  -995,   746,   701,
    4466,   698,   698,  -995,   435,   698,  -995,  -995,   571,  -995,
    -995,   582,    42,  -995,  -995,  -995,  -995,  -995,  -995,   584,
    -995,  -995,  4466,   648,   694,  -995,  -995,  -995,   667,   719,
     698,   688,   720,   758,   698,   734,  4466,  4466,   712,   698,
    4466,   740,  4466,   721,   -31,  -995,     2,   616,  -995,  -995,
     375,   -25,  -995,  -995,  -995,   714,  8050,  -995,  8050,  -995,
    -995,   685,  4466,   822,  -995,   253,  -995,   110,  -995,  -995,
     829,  -995,   276,  4466,  4466,  4466,   424,  4466,  4466,  4466,
    4466,  4466,  4466,   748,  4466,  4466,   642,   718,   749,   708,
    -995,  4466,  -995,   473,   762,  -995,  8050,   764,  -995,  8050,
     727,   728,  -995,   309,  -995,  -995,  -995,  8050,  -995,  8050,
    4466,   738,  4466,  4466,   -60,   739,  -995,   690,   689,  -995,
     639,  -995,   123,  -995,   282,   -44,   640,    20,   282,  4988,
    4988,   382,  -995,  -995,  -995,  -995,  -995,  -995,  -995,    20,
     741,   -44,  -995,   611,   824,  -995,  -995,  -995,  -995,  -995,
     750,  -995,  -995,  -995,  4466,  -995,  -995,   713,  -995,  -995,
    7291,   334,  -995,  3161,   722,   723,   752,   725,   729,  -995,
    8050,   797,   162,  -995,  -995,  4466,  -995,    80,  -995,  -995,
    -995,  -995,   477,  -995,  -995,  -995,  4466,  -995,  -995,  -995,
    -995,  -995,  -995,   644,   254,   862,  -995,   390,  -995,  -995,
       1,  4466,  3422,  -995,   698,   789,  -995,  -995,  -995,   698,
     789,  8050,  -995,  -995,  4466,   716,  -995,  8050,  -995,  4466,
    4466,   760,  4466,   757,  -995,   784,   786,  4466,  8050,   568,
     827,  -995,  -995,  -995,  3683,   730,   735,  -995,  -995,  -995,
     779,  -995,   155,  -995,  -995,   891,  -995,  -995,  4466,  8050,
    -995,  -995,   158,  -995,  -995,  -995,   732,   681,   691,  -995,
    -995,  -995,   692,   693,  -995,  -995,  -995,  -995,  -995,   686,
    8050,   742,  -995,   772,   642,  -995,  4466,  8050,   762,  -995,
     698,  -995,   538,  -995,    11,   820,  -995,  4466,   823,   706,
    -995,   745,   747,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    4466,  -995,  -995,  4466,   787,  4466,  -995,  -995,  4988,  -995,
    -995,  -995,  -995,  -995,    89,  4988,  4988,   259,  -995,   579,
    -995,  -995,   171,  4988,  -995,  -995,   570,    20,   668,  -995,
    -995,  -995,  -995,  -995,  8050,   751,     5,  -995,  -995,   761,
    -995,  -995,  -995,  -995,  -995,   746,  7544,   814,   841,   765,
    -995,  -995,  -995,    49,   903,   905,    49,   -38,   165,   170,
     790,  -995,  -995,   775,   825,  -995,   766,   848,   698,   789,
    -995,  -995,  -995,  -995,  -995,  -995,  4466,  -995,  4466,  8050,
    8050,  -995,   266,  -995,  4466,  -995,   767,  -995,  -995,   822,
    8050,   289,  -995,   768,   822,  8050,  -995,  -995,  4466,  4466,
    4466,  4466,  4466,  -995,  4466,  5771,  -995,   771,  -995,  -995,
    -995,  -995,   820,  -995,  -995,  -995,   698,  -995,  -995,  -995,
    -995,  -995,  -995,  4466,  -995,   225,  4988,  4988,   225,   409,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,   858,  4466,
    8050,  4466,  -995,  -995,  -995,  -995,  7544,  -995,   254,   254,
      49,  -995,  -995,  -995,    46,    49,   920,   702,   859,  -995,
     859,  -995,  4466,   178,   790,  4466,  -995,   698,  -995,  -995,
    -995,   878,  -995,  -995,  -995,  -995,    -1,   822,  8050,  -995,
     769,   822,  -995,  -995,  -995,  -995,  -995,  -995,   186,  -995,
    -995,  -995,  -995,   225,   225,  4988,  7544,  -995,   777,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,   -44,  -995,   188,  -995,
     189,  -995,   851,   746,  4466,  -995,   192,  -995,   789,   843,
     167,   408,  -995,   770,   822,  -995,   773,   846,   815,   225,
     785,  4466,   731,   859,  -995,  -995,   698,  -995,  -995,  -995,
    8050,  -995,  -995,   875,   234,  -995,  -995,  -995,  -995,   791,
     442,  -995,  -995,  -995,   776,  -995,  8050,  -995,  4466,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,   195,  -995,   853,   815,  8050,  -995,   206,   854,   815,
    8050,  -995,   792,   815,  -995
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   354,   355,   533,   501,   689,   690,   693,   691,   694,
     692,   623,   547,   539,   555,   546,   537,   635,   645,   684,
     683,   685,   686,   682,   541,   543,   570,   642,   605,   599,
     644,   640,   567,   643,   699,   594,   636,   697,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   637,   551,   545,
     538,   639,   614,   544,   549,   345,   348,   613,   609,   600,
     580,   536,   335,     0,   608,   616,   624,   333,   604,   371,
     581,   582,   638,   334,   337,   601,   618,     0,   377,   343,
     373,   611,   535,   602,   603,   631,   606,   622,   630,   339,
     338,   554,   593,   633,   372,   621,   626,   540,     0,     0,
     292,   619,   629,   634,   632,   612,   687,   598,   596,   597,
     344,     0,   291,     0,   347,   346,   627,   583,   607,     0,
     336,   321,     0,   353,   628,   610,   617,   625,   620,   688,
     574,   579,   578,   577,   576,   575,   548,   595,     0,   534,
     641,   568,   674,   673,   675,   553,   552,   571,   680,   542,
     672,   677,   678,   669,   573,   615,   671,   681,   679,   670,
     572,   676,   695,   696,   698,   661,   660,   557,   550,   559,
     558,   654,   650,   565,   569,   566,   663,   664,   647,   556,
     659,   658,   655,   651,   668,   662,   657,   653,   646,   667,
     666,   652,   656,   648,   649,   560,   561,   563,   665,   562,
     564,   701,   702,   707,   703,   700,   705,   706,   704,     0,
       0,     2,     0,     4,     6,     0,     0,     0,     0,    17,
      19,    21,    22,    23,    31,    24,    28,    29,    35,    36,
      37,    32,    33,    39,    40,    26,    25,    30,    34,   150,
     149,   146,   147,   148,   151,    27,    11,   127,   128,   132,
     134,   166,   172,     0,     0,   164,   165,   135,   136,   137,
     138,   248,   250,   252,   262,   265,   267,   270,   275,   278,
     281,   283,   285,   287,     0,   289,   295,   297,     0,   313,
     296,   317,   320,   322,   325,   327,     0,   332,   329,     0,
     340,   350,   352,   326,   356,   361,   369,   362,   363,   364,
     367,   368,   365,   366,   384,   386,   387,   388,   385,   433,
     434,   435,   436,   437,   438,   349,   475,   467,   474,   473,
     472,   469,   471,   468,   470,   370,    38,   139,   140,   142,
     141,   143,   144,   351,   145,     0,   101,     0,   106,   107,
       0,     0,     0,     0,     0,     0,   689,   690,   693,   694,
     692,   623,   547,   539,   555,   546,   537,   635,   541,   543,
     642,   605,   644,   699,   594,   697,   584,   585,   545,   538,
     536,   606,     0,     0,   687,   688,   534,   680,   542,   672,
     678,   669,   572,   695,   698,   701,   702,   707,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,   111,   114,     0,   532,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   174,     0,     0,     0,     0,     0,     0,     0,
     539,   546,   537,   543,   536,   341,   351,   374,     0,   375,
       0,   400,     0,     0,   316,     0,     0,   319,     0,     0,
     429,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     1,     5,     7,
       0,     0,    12,    10,    14,    15,     0,   130,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   171,
     167,   173,   168,   170,   169,   176,   177,     0,     0,     0,
       0,   306,     0,     0,   304,     0,   257,     0,   305,   298,
     303,   302,   301,   300,   299,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,   293,   290,     0,   314,   318,     0,
       0,     0,   328,   358,   331,   330,   342,   357,     0,     0,
     104,     0,     0,   499,     0,     0,     0,     0,     0,   491,
       0,     0,     0,     0,     0,   480,     0,   481,     0,   116,
       0,   117,   113,   112,   115,     0,    95,    96,    48,    49,
     531,    57,     0,     0,    42,    43,     0,     0,     0,     0,
       0,     0,     0,     0,   502,   503,   504,     0,     0,     0,
       0,   746,   747,     0,    47,   739,   740,   741,   742,   743,
     744,   745,    86,     0,     0,     0,     0,   482,     0,     0,
       0,    66,     0,     0,     0,    58,     0,   237,     0,     0,
       0,   189,   190,     0,     0,   154,   155,     0,     0,   175,
       0,     0,     0,   477,     0,     0,     0,   485,     0,     0,
       0,     0,   376,   401,   400,   397,     0,     0,   431,   430,
     315,   490,     0,   428,     0,   515,   516,   476,     0,     0,
       0,     0,     0,     0,   521,     0,     0,     0,   192,   209,
     108,   110,   109,     0,    18,     0,    20,   133,     0,     0,
       0,     0,     0,   153,   210,     0,     0,     0,     0,     0,
       0,     0,     0,   249,   251,   255,   261,   260,   259,     0,
     256,   253,   254,     0,     0,     0,   731,   263,   710,   718,
     720,   722,   724,   726,   729,   269,   268,   266,   272,   273,
     274,   271,   276,   277,   280,   279,     0,     0,     0,     0,
     311,     0,   323,   324,     0,   359,   380,   382,     0,   102,
       0,     0,   307,     0,     0,     0,     0,     0,   495,     0,
     492,   440,     0,   439,   448,   449,     0,     0,     0,    46,
       0,     0,     0,    74,     0,    70,    72,    73,    77,    80,
       0,     0,     0,    56,     0,     0,   748,   749,     0,   750,
     754,     0,     0,   783,   752,   753,   782,   751,   755,     0,
     762,   784,     0,     0,     0,   484,   483,   450,     0,     0,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   709,     0,     0,   156,   157,
       0,   162,   498,   478,   479,     0,     0,   488,     0,   486,
     444,     0,     0,   400,   398,     0,   389,     0,   378,   379,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
     131,     0,   163,   221,   217,   219,     0,   211,   212,     0,
     540,   548,   456,   457,   463,   464,   466,     0,   179,     0,
       0,     0,     0,     0,     0,     0,   258,     0,     0,   725,
       0,   264,     0,   738,     0,     0,     0,     0,     0,     0,
       0,   711,   715,   733,   714,   737,   735,   734,   736,     0,
       0,     0,   727,   790,   788,   792,   730,   282,   284,   286,
     454,   288,   312,   360,     0,   381,   105,     0,   309,   308,
       0,     0,   243,     0,     0,     0,   499,     0,     0,   441,
       0,    97,     0,   121,   119,     0,   118,     0,    54,    55,
      52,    53,     0,    75,    76,    78,     0,    79,    44,    45,
      50,    51,    41,     0,     0,     0,   757,     0,   756,   773,
       0,     0,     0,   451,     0,    68,    62,    65,    64,     0,
      60,     0,   235,   239,     0,     0,   103,     0,   194,     0,
       0,     0,     0,     0,   158,     0,     0,     0,     0,   203,
       0,   200,   205,   161,     0,     0,     0,   445,   236,   401,
       0,   390,     0,   424,   421,     0,   425,   426,     0,     0,
     427,   420,     0,   395,   423,   422,     0,     0,     0,   508,
     509,   505,     0,     0,   513,   514,   510,   519,   517,     0,
       0,     0,   523,     0,   524,   525,     0,     0,   218,   230,
       0,   231,     0,   222,   223,   224,   225,     0,   214,     0,
     178,     0,     0,   460,   462,   461,   458,   187,   188,   181,
       0,   183,   180,     0,     0,     0,   732,   728,     0,   785,
     786,   806,   805,   801,     0,     0,     0,     0,   787,   719,
     800,   712,     0,     0,   717,   716,   721,     0,     0,   791,
     789,   455,   383,   310,     0,     0,     0,   244,   442,     0,
     496,   497,   500,   493,   494,   123,     0,     0,    98,     0,
     120,    71,    81,   771,     0,     0,   769,   765,     0,     0,
       0,    82,    83,     0,     0,   452,     0,    67,     0,    61,
     238,   240,    13,   191,   196,   195,     0,   198,     0,     0,
       0,   160,   201,   204,     0,   446,     0,   489,   487,   400,
       0,     0,   432,     0,   400,     0,   396,     9,     0,     0,
       0,     0,     0,   522,     0,     0,   526,     0,   193,   234,
     232,   233,   226,   227,   228,   220,     0,   215,   213,   465,
     459,   185,   182,     0,   184,   807,     0,     0,   793,     0,
     804,   803,   802,   797,   798,   713,   723,   799,     0,     0,
       0,     0,   443,   124,    99,   122,     0,   126,     0,     0,
     772,   774,   776,   778,     0,   770,     0,     0,     0,   760,
       0,   758,     0,     0,     0,     0,   453,     0,    63,   197,
     199,   208,   207,   202,   159,   447,     0,   400,     0,   125,
       0,   400,   506,   507,   511,   512,   518,   520,     0,   708,
     229,   216,   186,   795,   794,     0,     0,   245,     0,   241,
     100,   781,   780,   775,   779,   777,   766,   767,     0,   763,
       0,    93,    89,    91,     0,    87,     0,   247,    69,     0,
     410,   404,   399,     0,   400,   391,     0,     0,     0,   796,
       0,     0,     0,     0,   761,   759,     0,    92,    94,    88,
       0,   418,   412,     0,   411,   413,   419,   416,   406,     0,
     405,   407,   417,   393,     0,   392,     0,   527,     0,   242,
     768,   764,    90,   206,   403,   414,   415,   402,   408,   409,
     394,     0,   246,     0,     0,     0,   528,     0,     0,     0,
       0,   529,     0,     0,   530
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -995,  -995,   754,  -995,   753,   759,  -995,   774,  -995,   476,
     480,  -475,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -820,  -995,  -995,  -995,  -995,
     -11,   183,  -995,  -995,  -995,  -995,  -995,   555,  -336,  -995,
    -285,  -995,   194,  -995,  -727,  -995,  -995,  -995,  -995,  -995,
    -995,   263,  -269,  -995,  -995,  -167,  -995,  -928,   780,   -51,
    -995,   487,  -328,  -995,  -995,  -995,  -995,   139,  -995,  -995,
     737,  -995,  -995,  -995,  -995,  -995,    88,  -473,  -623,  -995,
    -995,  -995,   -28,  -995,  -995,  -194,   -37,   -86,  -995,  -995,
    -995,   -96,  -995,  -995,   103,   -92,  -995,  -995,   -88,  -994,
    -995,   547,   -10,  -995,  -995,    48,  -995,  -995,   484,   488,
    -995,  -457,  -887,   470,   138,  -517,   133,   140,  -995,  -995,
    -995,  -995,  -995,   736,  -995,  -995,  -995,  -995,  -995,   743,
    -995,  -995,  -101,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
     -32,  -197,  -995,  -995,    14,    35,  -995,  -519,  -995,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -835,  -995,   -30,
    -995,   337,  -659,  -995,  -995,  -995,  -995,  -995,  -337,  -330,
    -966,  -754,  -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,
    -995,  -995,   257,  -632,  -728,  -995,   226,   -75,  -704,  -995,
    -995,  -995,  -995,  -995,  -995,  -995,   573,   578,  -621,   238,
    -995,  -995,  -995,  -995,  -995,  -995,  -995,  -995,   -48,  -995,
    -995,   -47,  -400,  -372,   -13,  -995,   287,  -995,  -995,    96,
      86,   -99,   291,  -995,  -995,    98,  -995,  -693,  -995,  -995,
    -995,  -995,  -228,  -801,  -995,  -123,  -553,  -995,  -676,  -995,
    -995,  -995,  -995,  -924,  -995,  -995,  -995,  -995,   -87,   106,
    -995
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   995,   634,   234,   235,   785,
     786,   787,   598,   236,  1153,   237,   414,   415,  1301,  1302,
    1253,   238,   777,   239,   336,   240,   241,   242,   243,   244,
     245,   416,   417,   581,   962,   963,  1040,   966,   246,   247,
     488,   248,   249,   250,   498,   433,   840,   841,   251,   499,
     252,   501,   253,   254,   255,   505,   506,  1019,   711,   256,
     641,   687,   642,   648,  1020,  1021,  1022,   688,   502,   503,
     887,   888,  1207,   504,   884,   885,  1073,  1074,  1075,  1076,
     257,   636,   637,   258,   951,   952,   259,   260,   261,   262,
     719,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   525,   526,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   552,   553,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   758,   303,   304,   305,  1042,
     664,   665,   666,  1312,  1339,  1340,  1333,  1334,  1341,  1335,
    1043,  1044,   306,   307,  1045,   308,   309,   310,   311,   312,
     313,   314,   939,   712,   892,  1086,   893,   894,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   562,   955,
     325,   326,   327,   328,   329,   330,   331,   683,   684,   332,
    1064,  1065,   996,   422,   333,   334,   727,   921,   728,   729,
     730,   731,   732,   733,   734,   922,   923,   614,   615,   616,
     617,   618,  1298,  1299,   619,  1240,  1146,  1244,  1241,   620,
     621,   925,   936,  1107,   926,   927,   932,   928,  1223,  1103,
     911
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       388,   988,   895,   591,  1000,   855,   828,  1118,   726,   560,
     696,   834,   561,   623,   738,   739,   740,   741,   937,   938,
     833,   457,  1041,   631,   635,   394,   395,   396,   397,   398,
     399,   445,  1111,   946,   710,   924,   459,   603,   400,  1104,
       4,   837,   895,   895,   419,  1104,   626,   450,   439,   628,
     446,   668,   706,   715,   639,   716,   717,   707,   718,   341,
     720,   590,   900,   706,   447,   707,  1294,   590,   721,   722,
     825,  1093,   706,   690,   691,   692,  1186,   825,   895,  1310,
    1203,  1204,   486,   706,   406,   407,   451,   901,   873,   905,
     394,   395,   396,   397,   398,   399,  1010,   486,   832,   588,
     455,   644,   767,   400,  1070,   903,   456,   651,   856,   401,
    1230,   769,   846,   708,   862,   342,   592,    69,  1033,  1034,
     402,   403,   827,  1072,   404,   985,   579,   405,   968,    80,
     584,   593,   589,  1012,   675,   676,  1216,   678,   679,   680,
     681,   632,   986,   686,   652,   969,   954,   826,   957,   406,
     407,   408,   419,    94,   852,  1150,   975,   723,   697,   607,
     724,   798,   487,  1033,  1034,  1311,  1033,  1034,   703,   704,
    1238,  1331,   337,   857,  1231,  1033,   838,   880,   768,  1159,
     548,   709,   987,   343,   344,   633,  1149,   770,   847,   866,
     709,   630,  1105,  1106,  1030,   409,   627,  1041,  1105,  1106,
    1035,   793,   669,  1217,  1013,   726,   726,  1041,  1280,   839,
    1246,  1011,   460,   874,   411,  1186,  1295,   335,  1036,   709,
    1037,   709,  1125,  1247,   709,  1025,  1225,  1026,  1115,   860,
     757,   848,   709,  1239,   823,   863,   864,   944,  1331,   904,
    1140,   507,  1033,   653,   599,  1035,   895,  1038,  1035,   600,
     865,    99,   412,   413,   554,   410,  1137,   556,   819,  1248,
     725,   822,   906,  1036,  1250,  1037,  1036,   111,  1037,  1151,
    1152,   420,  1304,   446,   421,  1036,   446,  1037,   960,   411,
    1317,  1094,  1323,  1323,   559,  1332,  1304,   861,  1039,  1363,
     799,   564,  1038,   608,   567,  1038,    99,  1033,  1034,    99,
    1368,   609,   555,   601,  1038,   912,   138,   849,   557,   607,
     867,   868,   111,   945,   610,   111,   611,   412,   413,   800,
     801,   568,   802,   803,  1099,   869,   612,   531,   563,   613,
    1015,  1016,  1138,  1180,   338,  1249,  1185,  1144,   573,   574,
    1251,   576,  1036,   961,  1037,   468,  1041,   877,  1305,   707,
     469,   138,  1355,   532,   138,   535,  1318,  1100,  1324,  1325,
     571,   546,  1329,   602,   536,  1364,   533,   624,  1031,   625,
     537,  1038,  1322,   883,   913,   462,  1369,   463,   489,  1035,
     898,   578,   878,   538,   113,   490,   656,   585,   491,   492,
    1347,   978,   979,     4,  1145,   982,   493,  1036,   726,  1037,
     534,   667,   528,  1112,   696,   964,   782,   672,  1234,   535,
     726,   970,   638,   339,   640,   643,  1033,  1220,   536,   529,
     965,   950,   650,  1221,   340,   659,  1038,  1337,   971,  1005,
      99,  1222,   895,  1032,  1126,   638,  1366,  1308,  1083,  1015,
    1016,  1371,  1017,   608,   345,  1374,   111,   783,   752,   753,
    1033,   609,   784,   914,   915,   916,   974,   685,   707,   689,
     389,  1337,   977,   917,   610,   912,   611,  1268,  1084,   607,
      69,   918,   528,   985,   430,   431,   612,   919,   920,   613,
    1018,   494,    80,   495,   990,   138,  1085,   933,   934,   529,
    1148,   480,  1047,   390,  1048,   751,   391,   496,  1002,  1003,
     754,   481,  1006,  1233,  1008,  1220,    94,   418,  1290,   935,
     723,  1221,   530,   724,   763,   764,  1036,   432,  1037,  1222,
    1266,   772,  1351,   497,  1028,  1270,   789,  1338,  1101,   426,
     807,   790,   895,  1102,   913,  1049,  1050,  1051,   429,  1054,
    1055,  1056,  1057,  1058,  1059,  1038,  1061,  1062,   980,   981,
    1036,   586,  1037,   883,   594,  1069,  1336,  1342,  1320,   808,
     809,  1358,   810,   811,  1293,   587,  1070,   778,   595,  1293,
     392,   425,  1089,   393,  1091,  1092,  1071,   427,   818,  1038,
    1336,  1215,   895,   428,   788,  1072,  1342,   755,  1218,  1219,
     755,  1285,   755,   535,  1157,   394,   395,   396,   726,   783,
     399,   434,   536,   608,   784,   549,   550,   796,  1313,   851,
     797,   609,  1316,   914,   915,   916,  1122,   423,   804,   435,
     424,   805,   436,   465,   610,   466,   611,   604,   605,   606,
     448,   918,  1015,  1016,   836,   510,   612,  1113,   920,   613,
    1052,   452,  1053,   511,   512,   453,   513,   458,  1142,   461,
     853,  1200,  1201,   514,   464,  1344,   467,   515,   470,   516,
     582,   583,   472,  1154,   517,   471,   735,   736,   742,   743,
    1199,  1327,   907,   940,   940,   477,  1161,   744,   745,   484,
     518,  1164,  1165,   473,  1167,  1291,  1292,   882,   474,  1171,
     475,   485,   509,   896,   508,   527,   539,   541,   540,  1283,
    1284,   542,   551,   558,   519,   520,   521,   522,   523,   524,
     947,   565,   566,   572,   575,   577,   394,   580,   590,   596,
     597,   419,   413,   629,   645,   646,   647,   660,   649,   373,
     662,   391,   393,   896,   896,   896,   896,   421,  1197,   438,
     663,   670,   671,   673,   674,   682,   695,   677,   699,   883,
     700,   705,   701,   747,   956,   702,   956,   746,  1258,   776,
     748,   749,  1211,   759,   760,  1212,   761,  1214,  1319,   896,
     762,   766,   765,   773,   774,   775,   779,   780,   781,   791,
     792,   794,   795,   806,   813,   814,   812,   815,   820,   821,
     816,   829,   824,   830,   831,   835,   842,   843,   870,   845,
     844,   858,   871,   875,   859,   876,  1281,   879,   881,   872,
     930,   886,   889,   902,   931,   897,   899,   929,   910,   942,
     950,   943,   948,   949,   953,   959,   784,   706,   976,   991,
     983,   992,   997,   563,   993,   563,   994,   998,  1259,  1001,
    1260,   999,   984,  1004,   989,  1007,  1264,  1029,  1009,  1046,
    1014,  1024,  1027,  1060,  1067,  1066,  1077,  1096,  1079,  1097,
    1272,  1273,  1274,  1275,  1276,  1063,  1277,  1081,  1082,  1090,
    1095,  1119,  1117,  1078,  1098,  1108,   507,  1120,  1136,  1121,
    1123,  1132,  1147,  1158,  1087,  1282,  1088,  1166,  1168,  1169,
    1162,  1170,  1130,  1131,  1174,  1133,  1179,  1182,  1188,  1134,
    1177,  1287,  1129,  1289,  1143,  1178,  1187,  1192,  1189,  1190,
    1191,  1194,  1195,  1070,  1139,  1209,  1206,  1210,  1213,   960,
    1229,  1227,  1236,  1242,  1303,  1243,  1352,  1307,  1232,  1254,
    1252,  1257,  1237,  1256,  1265,  1269,  1255,   896,  1279,  1286,
    1296,  1156,   985,  1309,  1326,  1297,  1321,  1135,  1330,  1315,
    1343,  1346,   965,  1345,  1348,  1354,  1360,  1357,  1365,  1370,
     693,  1141,  1373,   476,   694,   478,   973,   622,  1328,  1306,
    1235,   479,   967,  1176,  1350,   698,  1303,  1080,  1263,  1163,
    1023,  1198,  1173,  1208,  1068,  1205,  1202,  1183,   638,   482,
     500,  1160,   713,  1349,   643,   661,   483,   714,  1278,  1127,
     737,   854,  1181,  1359,  1356,  1172,   941,   958,   972,   654,
     545,   908,  1193,  1109,   655,  1116,   909,  1196,  1226,  1114,
    1362,   547,  1300,  1245,  1110,  1224,  1184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   685,     0,     0,
       0,     0,     0,     0,   689,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1228,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   896,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1261,  1262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1267,     0,     0,
       0,     0,  1271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1288,     0,     0,
       0,     0,     0,   896,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1314,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   896,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1353,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1361,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       2,     3,  1367,     4,     0,     0,     0,  1372,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     0,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,     0,    67,    68,     0,     0,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,    80,     0,    81,    82,    83,    84,     0,    85,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,     0,    91,    92,    93,    94,    95,    96,    97,
       0,     0,     0,    98,    99,   100,   101,   102,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     0,   112,   113,     0,     0,   114,   115,   116,     0,
       0,     0,   117,     0,   118,   119,   120,     0,   121,   122,
     123,     0,   124,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,   136,   137,   138,
       0,   139,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,   179,     0,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   357,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   360,    28,    29,   362,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,    67,    68,     0,
       0,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,    80,     0,    81,    82,    83,    84,
       0,    85,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,     0,    91,    92,    93,    94,    95,
      96,    97,     0,     0,     0,    98,    99,   100,   101,   102,
       0,     0,     0,     0,   103,   104,   105,   106,   107,   108,
     109,   110,   111,     0,   112,   113,     0,     0,   114,   115,
     116,     0,     0,     0,   117,   449,   118,   119,   120,     0,
     121,   122,   123,     0,   124,     0,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,   136,
     137,   138,     0,   376,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,     0,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   357,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   360,    28,    29,   362,    31,    32,
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
     115,   116,     0,   750,     0,   117,     0,   118,   119,   120,
       0,   121,   122,   123,     0,   124,     0,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     0,     0,
     136,   137,   138,     0,   376,   140,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   178,   179,     0,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   357,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   360,    28,    29,   362,    31,
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
     114,   115,   116,     0,     0,     0,   117,   756,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   376,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   357,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   360,    28,    29,   362,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     0,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,     0,
      67,    68,     0,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,    80,     0,    81,
      82,    83,    84,     0,    85,     0,     0,     0,    86,    87,
      88,    89,    90,     0,     0,     0,     0,     0,    91,    92,
      93,    94,    95,    96,    97,     0,     0,     0,    98,    99,
     100,   101,   102,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     0,   112,   113,     0,
       0,   114,   115,   116,     0,   771,     0,   117,     0,   118,
     119,   120,     0,   121,   122,   123,     0,   124,     0,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,   136,   137,   138,     0,   376,   140,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,   178,   179,     0,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   357,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   360,    28,    29,
     362,    31,    32,    33,     0,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     0,
       0,    67,    68,     0,     0,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,     0,    80,     0,
      81,    82,    83,    84,     0,    85,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,     0,    91,
      92,    93,    94,    95,    96,    97,     0,     0,     0,    98,
      99,   100,   101,   102,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,   112,   113,
       0,     0,   114,   115,   116,     0,   817,     0,   117,     0,
     118,   119,   120,     0,   121,   122,   123,     0,   124,     0,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,     0,     0,   136,   137,   138,     0,   376,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,   178,   179,
       0,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   357,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   360,    28,
      29,   362,    31,    32,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,     0,    67,    68,     0,     0,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,    80,
       0,    81,    82,    83,    84,     0,    85,     0,     0,     0,
      86,    87,    88,    89,    90,     0,     0,     0,     0,     0,
      91,    92,    93,    94,    95,    96,    97,     0,     0,     0,
      98,    99,   100,   101,   102,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   112,
     113,     0,     0,   114,   115,   116,     0,   850,     0,   117,
       0,   118,   119,   120,     0,   121,   122,   123,     0,   124,
       0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,   136,   137,   138,     0,   376,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,   178,
     179,     0,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   357,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   360,
      28,    29,   362,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,     0,    67,    68,     0,     0,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
      80,     0,    81,    82,    83,    84,     0,    85,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
       0,    91,    92,    93,    94,    95,    96,    97,     0,     0,
       0,    98,    99,   100,   101,   102,     0,     0,     0,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,     0,
     112,   113,     0,     0,   114,   115,   116,     0,  1128,     0,
     117,     0,   118,   119,   120,     0,   121,   122,   123,     0,
     124,     0,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,     0,     0,   136,   137,   138,     0,   376,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,     0,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     357,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     360,    28,    29,   362,    31,    32,    33,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,     0,    67,    68,     0,     0,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,    80,     0,    81,    82,    83,    84,     0,    85,     0,
       0,     0,    86,    87,    88,    89,    90,     0,     0,     0,
       0,     0,    91,    92,    93,    94,    95,    96,    97,     0,
       0,     0,    98,    99,   100,   101,   102,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
       0,   112,   113,     0,     0,   114,   115,   116,     0,  1155,
       0,   117,     0,   118,   119,   120,     0,   121,   122,   123,
       0,   124,     0,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,   136,   137,   138,     0,
     376,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
       0,   178,   179,     0,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   357,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   360,    28,    29,   362,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     0,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,     0,    67,    68,     0,     0,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,    80,     0,    81,    82,    83,    84,     0,    85,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,     0,    91,    92,    93,    94,    95,    96,    97,
       0,     0,     0,    98,    99,   100,   101,   102,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     0,   112,   113,     0,     0,   114,   115,   116,     0,
    1175,     0,   117,     0,   118,   119,   120,     0,   121,   122,
     123,     0,   124,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,   136,   137,   138,
       0,   376,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,   179,     0,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     0,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,     0,    67,    68,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,    80,     0,    81,    82,    83,    84,     0,
      85,     0,     0,     0,    86,    87,    88,    89,    90,     0,
       0,     0,     0,     0,    91,    92,    93,    94,    95,    96,
      97,     0,     0,     0,    98,    99,   100,   101,   102,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,     0,   112,   113,     0,     0,   114,   115,   116,
       0,     0,     0,   117,     0,   118,   119,   120,     0,   121,
     122,   123,     0,   124,     0,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,   136,   137,
     138,     0,   139,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,   178,   179,     0,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,    67,    68,     0,
       0,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,    80,     0,    81,    82,    83,    84,
       0,    85,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,     0,    91,    92,    93,    94,    95,
      96,    97,     0,     0,     0,    98,    99,   100,   101,   102,
       0,     0,     0,     0,   103,   104,   105,   106,   107,   108,
     109,   110,   111,     0,   112,   113,     0,     0,   114,   115,
     116,     0,     0,     0,   117,     0,   118,   119,   120,     0,
     121,   122,   123,     0,   124,     0,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,   136,
     137,   138,     0,   376,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,     0,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   357,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   360,    28,    29,   362,    31,    32,
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
     136,   137,   138,     0,   376,   140,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   178,   179,     0,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,   346,   347,   348,     8,   349,   350,    11,
     352,    13,    14,    15,    16,   357,    18,    19,    20,    21,
      22,    23,   358,    25,    26,   360,   361,    29,   362,    31,
      32,    33,     0,   363,   364,    36,   365,   366,   367,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,   371,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   543,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   544,   113,     0,     0,
     114,   115,   116,     0,     0,     0,   117,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,   138,     0,   376,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   377,   149,   379,   151,   380,
     381,   154,   155,   156,   157,   158,   159,   382,   161,   383,
     163,   384,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     385,   386,   387,   204,   205,   206,   207,   208,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     0,   346,   347,   348,     8,   349,   350,
      11,   352,    13,    14,    15,    16,   357,    18,    19,    20,
      21,    22,    23,   358,    25,    26,   360,   361,    29,   362,
      31,    32,    33,     0,   363,   364,    36,   365,   366,   367,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     0,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,     0,
      67,    68,     0,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,    80,     0,    81,
      82,    83,    84,     0,    85,     0,     0,     0,   371,    87,
      88,    89,    90,     0,     0,     0,     0,     0,    91,    92,
      93,    94,    95,    96,    97,     0,     0,     0,    98,    99,
     100,   101,   102,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     0,   112,   113,     0,
       0,   114,   115,   116,     0,     0,     0,   117,     0,   118,
     119,   120,     0,   121,   122,   123,     0,   124,     0,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,   136,   137,   138,     0,   376,   140,     0,   141,
     142,   143,   144,   145,   146,   147,   377,   149,   379,   151,
     380,   381,   154,   155,   156,   157,   158,   159,   382,   161,
     383,   163,   384,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,   178,   179,     0,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   385,   386,   387,   204,   205,   206,   207,   208,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,   346,   347,   348,     8,   349,
     350,   351,   352,    13,    14,    15,    16,   357,    18,    19,
      20,    21,    22,    23,   358,    25,    26,   360,   361,    29,
     362,    31,    32,    33,     0,   363,   364,    36,   365,   366,
     367,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     0,
       0,    67,    68,     0,     0,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,     0,    80,     0,
      81,    82,    83,    84,     0,    85,     0,     0,     0,   371,
      87,    88,    89,    90,     0,     0,     0,     0,     0,    91,
      92,    93,    94,    95,    96,    97,     0,     0,     0,    98,
      99,     0,   101,   102,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,     0,     0,
       0,     0,   114,   115,   116,     0,     0,     0,   117,     0,
     118,   119,   120,     0,     0,     0,   123,     0,   124,     0,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,     0,     0,   136,   137,   138,     0,   376,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   377,   149,   379,
     151,   380,   381,   154,   155,   156,   157,   158,   159,   382,
     161,   383,   163,   384,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,   178,   179,
       0,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   385,   386,   387,   204,   205,   206,   207,   208,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       0,     0,     0,     0,     0,     0,   346,   347,   348,     8,
     349,   350,   351,   352,   440,   354,   441,   442,   357,    18,
      19,    20,    21,    22,    23,   358,   443,    26,   360,   361,
      29,   362,    31,    32,    33,     0,   363,   364,    36,   365,
     366,   367,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,     0,     0,    57,
       0,    58,    59,    60,   444,     0,     0,    64,    65,    66,
       0,     0,     0,    68,     0,     0,     0,     0,    70,    71,
      72,     0,     0,    75,    76,     0,     0,     0,     0,     0,
       0,    81,    82,    83,    84,     0,    85,     0,     0,     0,
     371,    87,    88,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,     0,    95,    96,    97,     0,     0,     0,
       0,     0,     0,   101,   102,     0,     0,     0,     0,   103,
     104,   105,   374,   107,   108,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   116,     0,     0,     0,   117,
       0,   118,   119,     0,     0,     0,     0,   123,     0,   124,
       0,   125,   126,   127,   128,   375,   130,   131,   132,   133,
     134,   135,     0,     0,   136,   137,     0,     0,   376,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   377,   149,
     379,   151,   380,   381,   154,   155,   156,   157,   158,   159,
     382,   161,   383,   163,   384,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,   178,
     179,     0,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   385,   386,   387,   204,   205,   206,   207,
     208,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     0,     0,   346,   347,   348,
       8,   349,   350,   351,   352,   353,   354,   355,   356,   357,
      18,    19,    20,    21,    22,    23,   358,   359,    26,   360,
     361,    29,   362,    31,    32,    33,     0,   363,   364,    36,
     365,   366,   367,    40,    41,    42,    43,    44,    45,    46,
      47,    48,   368,   369,    51,    52,    53,    54,     0,     0,
      57,     0,    58,    59,    60,   370,     0,     0,    64,    65,
      66,     0,     0,     0,    68,     0,     0,     0,     0,    70,
      71,    72,     0,     0,    75,    76,     0,     0,     0,     0,
       0,     0,    81,    82,    83,    84,     0,    85,     0,     0,
       0,   371,    87,    88,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,     0,    95,    96,    97,     0,     0,
       0,     0,     0,     0,   101,   102,     0,     0,     0,     0,
     103,   104,   105,   374,   107,   108,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,     0,     0,
     117,     0,   118,     0,     0,     0,     0,     0,   123,     0,
     124,     0,   125,   126,   127,   128,   375,   130,   131,   132,
     133,   134,   135,     0,     0,   136,   137,     0,     0,   376,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   377,
     378,   379,   151,   380,   381,   154,   155,   156,   157,   158,
     159,   382,   161,   383,   163,   384,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,     0,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   385,   386,   387,   204,   205,   206,
     207,   208,   454,     0,     3,     0,     0,     0,     0,     0,
       0,     0,   346,   347,   348,     8,   349,   350,   351,   352,
     353,   354,   355,   356,   357,    18,    19,    20,    21,    22,
      23,   358,   359,    26,   360,   361,    29,   362,    31,    32,
      33,     0,   363,   364,    36,   365,   366,   367,    40,    41,
      42,    43,    44,    45,    46,    47,    48,   368,   369,    51,
      52,    53,    54,     0,     0,    57,     0,    58,    59,    60,
     370,     0,     0,    64,    65,    66,     0,     0,     0,    68,
       0,     0,     0,     0,    70,    71,    72,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,    81,    82,    83,
      84,     0,    85,     0,     0,     0,   371,    87,    88,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,     0,
      95,    96,    97,     0,     0,     0,     0,     0,     0,   101,
     102,     0,     0,     0,     0,   103,   104,   105,   374,   107,
     108,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,     0,     0,     0,   117,     0,   118,     0,     0,
       0,     0,     0,     0,     0,   124,     0,   125,   126,   127,
     128,   375,   130,   131,   132,   133,   134,   135,     0,     0,
     136,   137,     0,     0,   376,   140,     0,   141,   142,   143,
     144,   145,   146,   147,   377,   378,   379,   151,   380,   381,
     154,   155,   156,   157,   158,   159,   382,   161,   383,   163,
     384,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   178,   179,     0,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   385,
     386,   387,   204,   205,   206,   207,   208,     3,     0,     0,
       0,     0,     0,     0,     0,   346,   347,   348,     8,   349,
     350,   351,   352,   353,   354,   355,   356,   357,    18,    19,
      20,    21,    22,    23,   358,   359,    26,   360,   361,    29,
     362,    31,    32,    33,     0,   363,   364,    36,   365,   366,
     367,    40,    41,    42,    43,    44,    45,    46,    47,    48,
     368,   369,    51,    52,    53,    54,     0,     0,    57,     0,
      58,    59,    60,   370,     0,     0,    64,    65,    66,     0,
       0,     0,    68,     0,     0,     0,     0,    70,    71,    72,
       0,     0,    75,    76,     0,     0,     0,     0,     0,     0,
      81,    82,    83,    84,     0,    85,     0,     0,     0,   371,
      87,    88,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,     0,    95,    96,    97,   372,     0,     0,   373,
       0,     0,   101,   102,     0,     0,     0,     0,   103,   104,
     105,   374,   107,   108,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,   117,     0,
     118,     0,     0,     0,     0,     0,     0,     0,   124,     0,
     125,   126,   127,   128,   375,   130,   131,   132,   133,   134,
     135,     0,     0,   136,   137,     0,     0,   376,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   377,   378,   379,
     151,   380,   381,   154,   155,   156,   157,   158,   159,   382,
     161,   383,   163,   384,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,   178,   179,
       0,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   385,   386,   387,   204,   205,   206,   207,   208,
       3,     0,     0,     0,     0,     0,     0,     0,   346,   347,
     348,     8,   349,   350,   351,   352,   353,   354,   355,   356,
     357,    18,    19,    20,    21,    22,    23,   358,   359,    26,
     360,   361,    29,   362,    31,    32,    33,     0,   363,   364,
      36,   365,   366,   367,    40,    41,    42,    43,    44,    45,
      46,    47,    48,   368,   369,    51,    52,    53,    54,     0,
       0,    57,     0,    58,    59,    60,   370,     0,     0,    64,
      65,    66,     0,     0,     0,    68,     0,     0,     0,     0,
      70,    71,    72,     0,     0,    75,    76,     0,     0,     0,
       0,     0,     0,    81,    82,    83,    84,     0,    85,     0,
       0,     0,   371,    87,    88,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,     0,    95,    96,    97,   437,
       0,     0,   438,     0,     0,   101,   102,     0,     0,     0,
       0,   103,   104,   105,   374,   107,   108,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,     0,     0,
       0,   117,     0,   118,     0,     0,     0,     0,     0,     0,
       0,   124,     0,   125,   126,   127,   128,   375,   130,   131,
     132,   133,   134,   135,     0,     0,   136,   137,     0,     0,
     376,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     377,   378,   379,   151,   380,   381,   154,   155,   156,   157,
     158,   159,   382,   161,   383,   163,   384,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
       0,   178,   179,     0,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   385,   386,   387,   204,   205,
     206,   207,   208,     3,     0,     0,     0,     0,     0,     0,
       0,   346,   347,   348,     8,   349,   350,   351,   352,   353,
     354,   355,   356,   357,    18,    19,    20,    21,    22,    23,
     358,   359,    26,   360,   361,    29,   362,    31,    32,    33,
       0,   363,   364,    36,   365,   366,   367,    40,    41,    42,
      43,    44,    45,    46,    47,    48,   368,   369,    51,    52,
      53,    54,     0,     0,    57,     0,    58,    59,    60,   370,
       0,     0,    64,    65,    66,     0,     0,     0,    68,     0,
       0,     0,     0,    70,    71,    72,     0,     0,    75,    76,
       0,     0,     0,     0,     0,     0,    81,    82,    83,    84,
       0,    85,     0,     0,     0,   371,    87,    88,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,     0,    95,
      96,    97,     0,     0,     0,     0,     0,     0,   101,   102,
       0,     0,     0,     0,   103,   104,   105,   374,   107,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,     0,     0,     0,   117,   569,   118,     0,     0,     0,
       0,     0,   570,     0,   124,     0,   125,   126,   127,   128,
     375,   130,   131,   132,   133,   134,   135,     0,     0,   136,
     137,     0,     0,   376,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   377,   378,   379,   151,   380,   381,   154,
     155,   156,   157,   158,   159,   382,   161,   383,   163,   384,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,     0,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   385,   386,
     387,   204,   205,   206,   207,   208,     3,     0,     0,     0,
       0,     0,     0,     0,   346,   347,   348,     8,   349,   350,
     351,   352,   353,   354,   355,   356,   357,    18,    19,    20,
      21,    22,    23,   358,   359,    26,   360,   361,    29,   362,
      31,    32,    33,     0,   363,   364,    36,   365,   366,   367,
      40,    41,    42,    43,    44,    45,    46,    47,    48,   368,
     369,    51,    52,    53,    54,     0,     0,    57,     0,    58,
      59,    60,   370,     0,     0,    64,    65,    66,     0,     0,
       0,    68,     0,     0,     0,     0,    70,    71,    72,     0,
       0,    75,    76,     0,     0,     0,     0,     0,     0,    81,
      82,    83,    84,     0,    85,     0,     0,     0,   371,    87,
      88,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,     0,    95,    96,    97,     0,     0,     0,     0,     0,
       0,   101,   102,     0,     0,     0,     0,   103,   104,   105,
     374,   107,   108,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,     0,     0,     0,   117,   657,   118,
       0,     0,     0,     0,     0,   658,     0,   124,     0,   125,
     126,   127,   128,   375,   130,   131,   132,   133,   134,   135,
       0,     0,   136,   137,     0,     0,   376,   140,     0,   141,
     142,   143,   144,   145,   146,   147,   377,   378,   379,   151,
     380,   381,   154,   155,   156,   157,   158,   159,   382,   161,
     383,   163,   384,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,   178,   179,     0,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   385,   386,   387,   204,   205,   206,   207,   208,     3,
       0,     0,     0,     0,     0,     0,     0,   346,   347,   348,
       8,   349,   350,   351,   352,   440,   354,   441,   442,   357,
      18,    19,    20,    21,    22,    23,   358,   443,    26,   360,
     361,    29,   362,    31,    32,    33,     0,   363,   364,    36,
     365,   366,   367,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     0,     0,
      57,     0,    58,    59,    60,   444,     0,     0,    64,    65,
      66,     0,     0,     0,    68,     0,     0,     0,     0,    70,
      71,    72,     0,     0,    75,    76,  1124,     0,     0,     0,
       0,     0,    81,    82,    83,    84,     0,    85,     0,     0,
       0,   371,    87,    88,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,     0,    95,    96,   890,     0,     0,
       0,     0,     0,     0,   101,   102,     0,     0,     0,     0,
     103,   104,   105,   374,   107,   108,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,     0,     0,
     117,     0,   118,   119,     0,     0,     0,     0,     0,     0,
     124,     0,   125,   126,   127,   128,   375,   130,   131,   132,
     133,   134,   135,     0,     0,   891,   137,     0,     0,   376,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   377,
     149,   379,   151,   380,   381,   154,   155,   156,   157,   158,
     159,   382,   161,   383,   163,   384,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,     0,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   385,   386,   387,   204,   205,   206,
     207,   208,     3,     0,     0,     0,     0,     0,     0,     0,
     346,   347,   348,     8,   349,   350,   351,   352,   440,   354,
     441,   442,   357,    18,    19,    20,    21,    22,    23,   358,
     443,    26,   360,   361,    29,   362,    31,    32,    33,     0,
     363,   364,    36,   365,   366,   367,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     0,     0,    57,     0,    58,    59,    60,   444,     0,
       0,    64,    65,    66,     0,     0,     0,    68,     0,     0,
       0,     0,    70,    71,    72,     0,     0,    75,    76,     0,
       0,     0,     0,     0,     0,    81,    82,    83,    84,     0,
      85,     0,     0,     0,   371,    87,    88,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,     0,    95,    96,
     890,     0,     0,     0,     0,     0,     0,   101,   102,     0,
       0,     0,     0,   103,   104,   105,   374,   107,   108,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,   117,     0,   118,   119,     0,     0,     0,
       0,     0,     0,   124,     0,   125,   126,   127,   128,   375,
     130,   131,   132,   133,   134,   135,     0,     0,   891,   137,
       0,     0,   376,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   377,   149,   379,   151,   380,   381,   154,   155,
     156,   157,   158,   159,   382,   161,   383,   163,   384,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,   178,   179,     0,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   385,   386,   387,
     204,   205,   206,   207,   208,     3,     0,     0,     0,     0,
       0,     0,     0,   346,   347,   348,     8,   349,   350,   351,
     352,   440,   354,   441,   442,   357,    18,    19,    20,    21,
      22,    23,   358,   443,    26,   360,   361,    29,   362,    31,
      32,    33,     0,   363,   364,    36,   365,   366,   367,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,     0,     0,    57,     0,    58,    59,
      60,   444,     0,     0,    64,    65,    66,     0,     0,     0,
      68,     0,     0,     0,     0,    70,    71,    72,     0,     0,
      75,    76,     0,     0,     0,     0,     0,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,   371,    87,    88,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
       0,    95,    96,   890,     0,     0,     0,     0,     0,     0,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   374,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,   117,     0,   118,   119,
       0,     0,     0,     0,     0,     0,   124,     0,   125,   126,
     127,   128,   375,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,     0,     0,   376,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   377,   149,   379,   151,   380,
     381,   154,   155,   156,   157,   158,   159,   382,   161,   383,
     163,   384,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     385,   386,   387,   204,   205,   206,   207,   208,     3,     0,
       0,     0,     0,     0,     0,     0,   346,   347,   348,     8,
     349,   350,   351,   352,   353,   354,   355,   356,   357,    18,
      19,    20,    21,    22,    23,   358,   359,    26,   360,   361,
      29,   362,    31,    32,    33,     0,   363,   364,    36,   365,
     366,   367,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   368,   369,    51,    52,    53,    54,     0,     0,    57,
       0,    58,    59,    60,   370,     0,     0,    64,    65,    66,
       0,     0,     0,    68,     0,     0,     0,     0,    70,    71,
      72,     0,     0,    75,    76,     0,     0,     0,     0,     0,
       0,    81,    82,    83,    84,     0,    85,     0,     0,     0,
     371,    87,    88,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,     0,    95,    96,    97,     0,     0,     0,
       0,     0,     0,   101,   102,     0,     0,     0,     0,   103,
     104,   105,   374,   107,   108,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   116,     0,     0,     0,   117,
       0,   118,     0,     0,     0,     0,     0,     0,     0,   124,
       0,   125,   126,   127,   128,   375,   130,   131,   132,   133,
     134,   135,     0,     0,   136,   137,     0,     0,   376,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   377,   378,
     379,   151,   380,   381,   154,   155,   156,   157,   158,   159,
     382,   161,   383,   163,   384,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,   178,
     179,     0,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   385,   386,   387,   204,   205,   206,   207,
     208
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        13,   802,   706,   403,   824,   664,   638,   931,   527,   337,
     485,   643,   340,   413,   531,   532,   533,   534,   746,   747,
     643,   122,   857,   423,   424,    39,    40,    41,    42,    43,
      44,    63,   919,   760,   507,   728,    21,   409,    52,    83,
      20,    66,   746,   747,    18,    83,    20,    98,    61,   421,
      63,     7,    81,   510,   426,   512,   513,    83,   515,    81,
     517,    20,   131,    81,    77,    83,    20,    20,   525,   526,
      94,   131,    81,   473,   474,   475,  1042,    94,   782,    80,
    1074,  1075,    94,    81,    98,    99,    99,   710,    94,   712,
      39,    40,    41,    42,    43,    44,   127,    94,   127,   152,
     113,   429,    94,    52,    93,   131,   119,    34,   115,    58,
     105,    94,    94,   131,    81,   137,   150,    97,     8,     9,
      69,    70,   131,   112,    73,    83,   395,    76,   132,   109,
     399,   165,   185,   131,   462,   463,    47,   465,   466,   467,
     468,   100,   100,   471,    71,   149,   767,   171,   769,    98,
      99,   100,    18,   133,   171,   154,   788,   137,   486,    87,
     140,   100,   174,     8,     9,   166,     8,     9,   496,   497,
     121,     4,   221,   180,   169,     8,   201,   174,   170,   999,
     281,   250,   140,   205,   206,   144,   987,   170,   170,    81,
     250,   144,   236,   237,   853,   144,   170,  1032,   236,   237,
      90,   601,   158,   114,   836,   724,   725,  1042,  1202,   234,
     248,   834,   197,   219,   228,  1181,   170,   137,   108,   250,
     110,   250,   950,  1147,   250,   846,  1113,   848,   921,   116,
     558,    94,   250,   184,   634,   202,   203,    94,     4,   712,
     967,   254,     8,   170,    34,    90,   950,   137,    90,    39,
     217,   141,   266,   267,   286,   204,    94,   289,   630,    94,
     240,   633,   719,   108,    94,   110,   108,   157,   110,   268,
     269,   137,    94,   286,   140,   108,   289,   110,   105,   228,
      94,   904,    94,    94,   335,   118,    94,   174,   178,    94,
     229,   342,   137,   221,   345,   137,   141,     8,     9,   141,
      94,   229,   288,    93,   137,    83,   196,   170,   294,    87,
     202,   203,   157,   170,   242,   157,   244,   266,   267,   258,
     259,   372,   261,   262,   201,   217,   254,   104,   341,   257,
      64,    65,   170,   178,    29,   170,   178,    83,   389,   390,
     170,   392,   108,   170,   110,   209,  1181,    59,   170,    83,
     214,   196,   118,   130,   196,   184,   170,   234,   170,   170,
     373,   137,   170,   153,   193,   170,   143,   418,   115,   420,
     121,   137,  1296,   701,   152,   209,   170,   211,    50,    90,
     708,   394,    94,   134,   160,    57,   437,   400,    60,    61,
    1318,   791,   792,    20,   140,   795,    68,   108,   917,   110,
     177,   452,   142,   920,   879,   122,    81,   458,  1136,   184,
     929,   132,   425,    29,   427,   428,     8,   246,   193,   159,
     137,    87,   435,   252,   140,   438,   137,    19,   149,   829,
     141,   260,  1136,   180,   100,   448,  1364,  1257,   129,    64,
      65,  1369,    67,   221,   140,  1373,   157,   122,   549,   550,
       8,   229,   127,   231,   232,   233,   784,   470,    83,   472,
     137,    19,   790,   241,   242,    83,   244,   178,   159,    87,
      97,   249,   142,    83,    62,    63,   254,   255,   256,   257,
     105,   153,   109,   155,   812,   196,   177,   225,   226,   159,
     100,    38,   216,   137,   218,   546,   140,   169,   826,   827,
     551,    48,   830,  1135,   832,   246,   133,   140,  1236,   247,
     137,   252,   182,   140,   565,   566,   108,   105,   110,   260,
    1179,   572,  1323,   195,   852,  1184,   122,   119,   246,   144,
     229,   127,  1236,   251,   152,   863,   864,   865,   137,   867,
     868,   869,   870,   871,   872,   137,   874,   875,   113,   114,
     108,   165,   110,   881,   165,    82,  1310,  1311,  1286,   258,
     259,   119,   261,   262,  1240,   179,    93,   580,   179,  1245,
     137,   105,   900,   140,   902,   903,   103,   105,   629,   137,
    1334,  1098,  1286,   105,   597,   112,  1340,   552,  1105,  1106,
     555,   182,   557,   184,   994,    39,    40,    41,  1117,   122,
      44,    60,   193,   221,   127,   175,   176,   227,  1267,   660,
     230,   229,  1271,   231,   232,   233,   944,    51,   227,   140,
      54,   230,   140,   209,   242,   211,   244,   205,   206,   207,
     105,   249,    64,    65,   647,   117,   254,   255,   256,   257,
     216,   137,   218,   125,   126,    14,   128,   137,   976,   199,
     663,   113,   114,   135,   140,  1314,   209,   139,   105,   141,
     397,   398,   105,   991,   146,   137,   528,   529,   535,   536,
    1070,  1303,   723,   748,   749,     0,  1004,   537,   538,   174,
     162,  1009,  1010,   267,  1012,  1238,  1239,   700,   267,  1017,
     267,   174,    79,   706,   151,   239,    74,    88,   183,  1216,
    1217,    89,   138,   140,   186,   187,   188,   189,   190,   191,
     761,   137,   137,   137,   170,   170,    39,    39,    20,   136,
     105,    18,   267,   137,   256,   256,   105,   137,   105,   140,
     170,   140,   140,   746,   747,   748,   749,   140,  1066,   140,
      25,    15,   170,   197,    20,   215,    38,   170,   153,  1077,
     105,    94,   154,    81,   767,   154,   769,   215,  1158,   140,
      81,    81,  1090,   167,   170,  1093,   137,  1095,  1285,   782,
     167,   167,   170,   167,   167,   167,    20,    94,    94,   144,
     144,   112,   117,    20,   170,   167,   270,   170,    83,    34,
     170,   117,    83,   127,    94,   167,   170,   170,    81,   167,
     170,   167,   221,   127,   167,   167,  1206,   174,   154,   209,
     240,   105,   105,   131,   245,   105,   105,   238,   257,   167,
      87,   168,   167,   167,   137,   167,   127,    81,   127,   181,
     259,   137,   144,   846,   167,   848,   117,   117,  1166,   105,
    1168,    83,   260,   131,   260,   105,  1174,    25,   127,    20,
     234,   137,   167,   105,   105,   137,    94,   167,    94,   170,
    1188,  1189,  1190,  1191,  1192,   223,  1194,   140,   140,   131,
     131,   260,   131,   886,   235,   235,   889,    53,    81,   129,
     167,   129,    20,    94,   897,  1213,   899,   127,   131,   105,
     174,   105,   170,   170,    67,   170,   117,     6,   217,   170,
     170,  1229,   953,  1231,   260,   170,   174,   221,   217,   217,
     217,   169,   140,    93,   965,   170,    93,   170,   131,   105,
     169,   253,    81,    20,  1252,    20,  1326,  1255,   167,   154,
     140,    83,   167,   167,   167,   167,   111,   950,   167,    81,
      20,   992,    83,    65,    93,   243,   169,   960,   105,   180,
     180,   105,   137,   180,   169,    80,   180,   166,   105,   105,
     484,   972,   170,   209,   484,   212,   783,   412,  1304,  1254,
    1137,   212,   778,  1024,   243,   488,  1304,   889,  1172,  1007,
     841,  1067,  1019,  1079,   881,  1077,  1074,  1038,  1001,   215,
     253,  1001,   508,  1321,  1007,   448,   216,   509,  1195,   951,
     530,   664,  1032,  1340,  1334,  1018,   749,   769,   782,   436,
     274,   724,  1060,   917,   436,   929,   725,  1064,  1117,   921,
    1348,   278,  1250,  1146,   918,  1112,  1039,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1060,    -1,    -1,
      -1,    -1,    -1,    -1,  1067,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1136,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1169,  1170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1180,    -1,    -1,
      -1,    -1,  1185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1230,    -1,    -1,
      -1,    -1,    -1,  1236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1268,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1286,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1330,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,  1365,    20,    -1,    -1,    -1,  1370,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92,    93,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,   109,    -1,   111,   112,   113,   114,    -1,   116,
      -1,    -1,    -1,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,   135,   136,
      -1,    -1,    -1,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    -1,   159,   160,    -1,    -1,   163,   164,   165,    -1,
      -1,    -1,   169,    -1,   171,   172,   173,    -1,   175,   176,
     177,    -1,   179,    -1,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,   194,   195,   196,
      -1,   198,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,    -1,   239,   240,    -1,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    93,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,   109,    -1,   111,   112,   113,   114,
      -1,   116,    -1,    -1,    -1,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
     135,   136,    -1,    -1,    -1,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    -1,   159,   160,    -1,    -1,   163,   164,
     165,    -1,    -1,    -1,   169,   170,   171,   172,   173,    -1,
     175,   176,   177,    -1,   179,    -1,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,   194,
     195,   196,    -1,   198,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,    -1,   239,   240,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
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
     164,   165,    -1,   167,    -1,   169,    -1,   171,   172,   173,
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
     263,   264,   265,   266,   267,   268,   269,   270,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      92,    93,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    -1,   109,    -1,   111,
     112,   113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,   135,   136,    -1,    -1,    -1,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    -1,   159,   160,    -1,
      -1,   163,   164,   165,    -1,   167,    -1,   169,    -1,   171,
     172,   173,    -1,   175,   176,   177,    -1,   179,    -1,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,   194,   195,   196,    -1,   198,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,    -1,   239,   240,    -1,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    93,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,   109,    -1,
     111,   112,   113,   114,    -1,   116,    -1,    -1,    -1,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,   135,   136,    -1,    -1,    -1,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    -1,   159,   160,
      -1,    -1,   163,   164,   165,    -1,   167,    -1,   169,    -1,
     171,   172,   173,    -1,   175,   176,   177,    -1,   179,    -1,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,   194,   195,   196,    -1,   198,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,    -1,   239,   240,
      -1,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    -1,    92,    93,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,   109,
      -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,    -1,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,   135,   136,    -1,    -1,    -1,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    -1,   159,
     160,    -1,    -1,   163,   164,   165,    -1,   167,    -1,   169,
      -1,   171,   172,   173,    -1,   175,   176,   177,    -1,   179,
      -1,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,   194,   195,   196,    -1,   198,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,    -1,   239,
     240,    -1,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    92,    93,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
     109,    -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,
      -1,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,   135,   136,    -1,    -1,
      -1,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
     159,   160,    -1,    -1,   163,   164,   165,    -1,   167,    -1,
     169,    -1,   171,   172,   173,    -1,   175,   176,   177,    -1,
     179,    -1,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,   194,   195,   196,    -1,   198,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,    -1,
     239,   240,    -1,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    92,    93,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      -1,   109,    -1,   111,   112,   113,   114,    -1,   116,    -1,
      -1,    -1,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,   135,   136,    -1,
      -1,    -1,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,   160,    -1,    -1,   163,   164,   165,    -1,   167,
      -1,   169,    -1,   171,   172,   173,    -1,   175,   176,   177,
      -1,   179,    -1,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,   194,   195,   196,    -1,
     198,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
      -1,   239,   240,    -1,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92,    93,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,   109,    -1,   111,   112,   113,   114,    -1,   116,
      -1,    -1,    -1,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,   135,   136,
      -1,    -1,    -1,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    -1,   159,   160,    -1,    -1,   163,   164,   165,    -1,
     167,    -1,   169,    -1,   171,   172,   173,    -1,   175,   176,
     177,    -1,   179,    -1,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,   194,   195,   196,
      -1,   198,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,    -1,   239,   240,    -1,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    92,    93,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,    -1,   109,    -1,   111,   112,   113,   114,    -1,
     116,    -1,    -1,    -1,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,   135,
     136,    -1,    -1,    -1,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    -1,   159,   160,    -1,    -1,   163,   164,   165,
      -1,    -1,    -1,   169,    -1,   171,   172,   173,    -1,   175,
     176,   177,    -1,   179,    -1,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,   194,   195,
     196,    -1,   198,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,    -1,   239,   240,    -1,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    93,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,   109,    -1,   111,   112,   113,   114,
      -1,   116,    -1,    -1,    -1,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
     135,   136,    -1,    -1,    -1,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    -1,   159,   160,    -1,    -1,   163,   164,
     165,    -1,    -1,    -1,   169,    -1,   171,   172,   173,    -1,
     175,   176,   177,    -1,   179,    -1,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,   194,
     195,   196,    -1,   198,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,    -1,   239,   240,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
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
     263,   264,   265,   266,   267,   268,   269,   270,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      92,    93,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    -1,   109,    -1,   111,
     112,   113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,   135,   136,    -1,    -1,    -1,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    -1,   159,   160,    -1,
      -1,   163,   164,   165,    -1,    -1,    -1,   169,    -1,   171,
     172,   173,    -1,   175,   176,   177,    -1,   179,    -1,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,   194,   195,   196,    -1,   198,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,    -1,   239,   240,    -1,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    93,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,   109,    -1,
     111,   112,   113,   114,    -1,   116,    -1,    -1,    -1,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,   135,   136,    -1,    -1,    -1,   140,
     141,    -1,   143,   144,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,   164,   165,    -1,    -1,    -1,   169,    -1,
     171,   172,   173,    -1,    -1,    -1,   177,    -1,   179,    -1,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,   194,   195,   196,    -1,   198,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,    -1,   239,   240,
      -1,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    79,
      -1,    81,    82,    83,    84,    -1,    -1,    87,    88,    89,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    98,    99,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,    -1,
     120,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,    -1,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,   169,
      -1,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,   179,
      -1,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,   194,   195,    -1,    -1,   198,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,    -1,   239,
     240,    -1,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
     169,    -1,   171,    -1,    -1,    -1,    -1,    -1,   177,    -1,
     179,    -1,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,   194,   195,    -1,    -1,   198,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,    -1,
     239,   240,    -1,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    79,    -1,    81,    82,    83,
      84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    98,    99,   100,    -1,    -1,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,    -1,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   165,    -1,    -1,    -1,   169,    -1,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,    -1,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
     194,   195,    -1,    -1,   198,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,    -1,   239,   240,    -1,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,    18,    -1,    -1,
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
     131,   132,    -1,   134,   135,   136,   137,    -1,    -1,   140,
      -1,    -1,   143,   144,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,   169,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,   194,   195,    -1,    -1,   198,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,    -1,   239,   240,
      -1,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,    87,
      88,    89,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,   116,    -1,
      -1,    -1,   120,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,    -1,   134,   135,   136,   137,
      -1,    -1,   140,    -1,    -1,   143,   144,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,
      -1,   169,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,    -1,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,   194,   195,    -1,    -1,
     198,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
      -1,   239,   240,    -1,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,    18,    -1,    -1,    -1,    -1,    -1,    -1,
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
     165,    -1,    -1,    -1,   169,   170,   171,    -1,    -1,    -1,
      -1,    -1,   177,    -1,   179,    -1,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,   194,
     195,    -1,    -1,   198,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,    -1,   239,   240,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    79,    -1,    81,
      82,    83,    84,    -1,    -1,    87,    88,    89,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,    -1,   116,    -1,    -1,    -1,   120,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   144,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   165,    -1,    -1,    -1,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,   177,    -1,   179,    -1,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,   194,   195,    -1,    -1,   198,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,    -1,   239,   240,    -1,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,    18,
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
     269,   270,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    79,    -1,    81,    82,    83,    84,    -1,
      -1,    87,    88,    89,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,    -1,
     116,    -1,    -1,    -1,   120,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,    -1,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,
      -1,    -1,    -1,   169,    -1,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,   179,    -1,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,   194,   195,
      -1,    -1,   198,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,    -1,   239,   240,    -1,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,    18,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,    -1,    -1,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    79,
      -1,    81,    82,    83,    84,    -1,    -1,    87,    88,    89,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    98,    99,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,    -1,
     120,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,    -1,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,   169,
      -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
      -1,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,   194,   195,    -1,    -1,   198,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,    -1,   239,
     240,    -1,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270
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
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   313,   314,   319,   321,   327,   329,
     331,   332,   333,   334,   335,   336,   344,   345,   347,   348,
     349,   354,   356,   358,   359,   360,   365,   386,   389,   392,
     393,   394,   395,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   442,   443,   444,   458,   459,   461,   462,
     463,   464,   465,   466,   467,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   486,   487,   488,   489,   490,
     491,   492,   495,   500,   501,   137,   330,   221,    29,    29,
     140,    81,   137,   205,   206,   140,    26,    27,    28,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    45,    46,
      48,    49,    51,    56,    57,    59,    60,    61,    71,    72,
      84,   120,   137,   140,   152,   185,   198,   208,   209,   210,
     212,   213,   220,   222,   224,   263,   264,   265,   500,   137,
     137,   140,   137,   140,    39,    40,    41,    42,    43,    44,
      52,    58,    69,    70,    73,    76,    98,    99,   100,   144,
     204,   228,   266,   267,   322,   323,   337,   338,   140,    18,
     137,   140,   499,    51,    54,   105,   144,   105,   105,   137,
      62,    63,   105,   351,    60,   140,   140,   137,   140,   500,
      34,    36,    37,    46,    84,   426,   500,   500,   105,   170,
     345,   500,   137,    14,    16,   500,   500,   418,   137,    21,
     197,   199,   209,   211,   140,   209,   211,   209,   209,   214,
     105,   137,   105,   267,   267,   267,   288,     0,   290,   291,
      38,    48,   293,   344,   174,   174,    94,   174,   346,    50,
      57,    60,    61,    68,   153,   155,   169,   195,   350,   355,
     356,   357,   374,   375,   379,   361,   362,   500,   151,    79,
     117,   125,   126,   128,   135,   139,   141,   146,   162,   186,
     187,   188,   189,   190,   191,   410,   411,   239,   142,   159,
     182,   104,   130,   143,   177,   184,   193,   121,   134,    74,
     183,    88,    89,   142,   159,   409,   137,   415,   418,   175,
     176,   138,   430,   431,   426,   430,   426,   430,   140,   345,
     348,   348,   484,   500,   345,   137,   137,   345,   345,   170,
     177,   500,   137,   345,   345,   170,   345,   170,   500,   338,
      39,   339,   337,   337,   338,   500,   165,   179,   152,   185,
      20,   498,   150,   165,   165,   179,   136,   105,   318,    34,
      39,    93,   153,   499,   205,   206,   207,    87,   221,   229,
     242,   244,   254,   257,   513,   514,   515,   516,   517,   520,
     525,   526,   323,   498,   345,   345,    20,   170,   499,   137,
     144,   498,   100,   144,   312,   498,   387,   388,   500,   499,
     500,   366,   368,   500,   348,   256,   256,   105,   369,   105,
     500,    34,    71,   170,   482,   483,   345,   170,   177,   500,
     137,   387,   170,    25,   446,   447,   448,   345,     7,   158,
      15,   170,   345,   197,    20,   348,   348,   170,   348,   348,
     348,   348,   215,   493,   494,   500,   348,   367,   373,   500,
     498,   498,   498,   295,   296,    38,   297,   348,   347,   153,
     105,   154,   154,   348,   348,    94,    81,    83,   131,   250,
     363,   364,   469,   394,   395,   397,   397,   397,   397,   396,
     397,   397,   397,   137,   140,   240,   433,   502,   504,   505,
     506,   507,   508,   509,   510,   400,   400,   399,   401,   401,
     401,   401,   402,   402,   403,   403,   215,    81,    81,    81,
     167,   345,   418,   418,   345,   431,   170,   348,   441,   167,
     170,   137,   167,   345,   345,   170,   167,    94,   170,    94,
     170,   167,   345,   167,   167,   167,   140,   328,   500,    20,
      94,    94,    81,   122,   127,   315,   316,   317,   500,   122,
     127,   144,   144,   498,   112,   117,   227,   230,   100,   229,
     258,   259,   261,   262,   227,   230,    20,   229,   258,   259,
     261,   262,   270,   170,   167,   170,   170,   167,   345,   499,
      83,    34,   499,   498,    83,    94,   171,   131,   469,   117,
     127,    94,   127,   364,   469,   167,   500,    66,   201,   234,
     352,   353,   170,   170,   170,   167,    94,   170,    94,   170,
     167,   345,   171,   500,   447,   448,   115,   180,   167,   167,
     116,   174,    81,   202,   203,   217,    81,   202,   203,   217,
      81,   221,   209,    94,   219,   127,   167,    59,    94,   174,
     174,   154,   500,   348,   380,   381,   105,   376,   377,   105,
     136,   194,   470,   472,   473,   474,   500,   105,   348,   105,
     131,   364,   131,   131,   363,   364,   397,   345,   502,   508,
     257,   536,    83,   152,   231,   232,   233,   241,   249,   255,
     256,   503,   511,   512,   513,   527,   530,   531,   533,   238,
     240,   245,   532,   225,   226,   247,   528,   470,   470,   468,
     473,   468,   167,   168,    94,   170,   330,   345,   167,   167,
      87,   390,   391,   137,   484,   485,   500,   484,   485,   167,
     105,   170,   340,   341,   122,   137,   343,   328,   132,   149,
     132,   149,   472,   317,   348,   469,   127,   348,   498,   498,
     113,   114,   498,   259,   260,    83,   100,   140,   519,   260,
     348,   181,   137,   167,   117,   311,   498,   144,   117,    83,
     311,   105,   348,   348,   131,   498,   348,   105,   348,   127,
     127,   364,   131,   469,   234,    64,    65,    67,   105,   363,
     370,   371,   372,   353,   137,   484,   484,   167,   348,    25,
     448,   115,   180,     8,     9,    90,   108,   110,   137,   178,
     342,   443,   445,   456,   457,   460,    20,   216,   218,   348,
     348,   348,   216,   218,   348,   348,   348,   348,   348,   348,
     105,   348,   348,   223,   496,   497,   137,   105,   380,    82,
      93,   103,   112,   382,   383,   384,   385,    94,   500,    94,
     362,   140,   140,   129,   159,   177,   471,   500,   500,   348,
     131,   348,   348,   131,   364,   131,   167,   170,   235,   201,
     234,   246,   251,   535,    83,   236,   237,   529,   235,   505,
     535,   398,   401,   255,   511,   513,   506,   131,   529,   260,
      53,   129,   348,   167,   105,   470,   100,   391,   167,   345,
     170,   170,   129,   170,   170,   500,    81,    94,   170,   345,
     330,   316,   348,   260,    83,   140,   522,    20,   100,   519,
     154,   268,   269,   320,   348,   167,   345,   498,    94,   311,
     388,   348,   174,   368,   348,   348,   127,   348,   131,   105,
     105,   348,   500,   372,    67,   167,   345,   170,   170,   117,
     178,   445,     6,   345,   500,   178,   456,   174,   217,   217,
     217,   217,   221,   494,   169,   140,   497,   348,   373,   498,
     113,   114,   384,   385,   385,   381,    93,   378,   377,   170,
     170,   348,   348,   131,   348,   401,    47,   114,   401,   401,
     246,   252,   260,   534,   534,   398,   507,   253,   500,   169,
     105,   169,   167,   469,   470,   341,    81,   167,   121,   184,
     521,   524,    20,    20,   523,   521,   248,   529,    94,   170,
      94,   170,   140,   326,   154,   111,   167,    83,   498,   348,
     348,   500,   500,   371,   348,   167,   448,   500,   178,   167,
     448,   500,   348,   348,   348,   348,   348,   348,   427,   167,
     385,   498,   348,   401,   401,   182,    81,   348,   500,   348,
     470,   522,   522,   524,    20,   170,    20,   243,   518,   519,
     518,   324,   325,   348,    94,   170,   326,   348,   311,    65,
      80,   166,   449,   448,   500,   180,   448,    94,   170,   401,
     470,   169,   529,    94,   170,   170,    93,   469,   324,   170,
     105,     4,   118,   452,   453,   455,   457,    19,   119,   450,
     451,   454,   457,   180,   448,   180,   105,   343,   169,   348,
     243,   519,   498,   500,    80,   118,   455,   166,   119,   454,
     180,   500,   348,    94,   170,   105,   343,   500,    94,   170,
     105,   343,   500,   170,   343
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
     314,   315,   315,   316,   316,   316,   317,   318,   318,   319,
     319,   319,   320,   320,   321,   322,   322,   323,   323,   324,
     324,   325,   325,   326,   326,   327,   327,   328,   328,   328,
     328,   329,   330,   331,   332,   333,   334,   334,   335,   335,
     335,   336,   336,   336,   337,   337,   337,   337,   338,   338,
     339,   340,   340,   341,   341,   342,   343,   344,   345,   345,
     346,   346,   347,   347,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   349,   350,   351,   351,   352,   352,   352,   353,
     353,   354,   354,   355,   356,   356,   356,   357,   357,   357,
     357,   357,   358,   358,   359,   359,   360,   361,   361,   362,
     362,   362,   362,   362,   362,   362,   362,   363,   364,   365,
     366,   366,   367,   367,   368,   368,   368,   368,   369,   369,
     370,   370,   370,   371,   371,   371,   372,   372,   372,   373,
     374,   375,   376,   376,   377,   377,   378,   379,   379,   380,
     380,   381,   381,   382,   382,   382,   382,   382,   382,   382,
     383,   383,   384,   384,   385,   386,   386,   387,   387,   388,
     388,   389,   389,   390,   390,   391,   391,   392,   393,   393,
     394,   394,   395,   395,   395,   395,   395,   396,   395,   395,
     395,   395,   397,   397,   397,   398,   398,   399,   399,   399,
     400,   400,   400,   400,   400,   401,   401,   401,   402,   402,
     402,   403,   403,   404,   404,   405,   405,   406,   406,   407,
     407,   408,   408,   408,   408,   409,   409,   409,   410,   410,
     410,   410,   410,   410,   411,   411,   411,   412,   412,   412,
     412,   413,   413,   414,   414,   415,   415,   416,   416,   416,
     416,   417,   418,   418,   418,   419,   419,   420,   420,   420,
     420,   421,   421,   422,   422,   422,   422,   422,   422,   422,
     423,   423,   424,   424,   425,   425,   425,   425,   425,   426,
     426,   427,   427,   428,   428,   428,   429,   429,   430,   430,
     431,   432,   432,   432,   432,   432,   432,   432,   432,   433,
     433,   434,   434,   434,   435,   436,   436,   437,   438,   439,
     440,   440,   441,   441,   442,   442,   443,   443,   443,   444,
     444,   444,   444,   444,   444,   445,   445,   446,   446,   447,
     448,   448,   449,   449,   450,   450,   451,   451,   451,   451,
     452,   452,   453,   453,   453,   453,   454,   454,   455,   455,
     456,   456,   456,   456,   457,   457,   457,   457,   458,   458,
     459,   459,   460,   461,   461,   461,   461,   461,   461,   462,
     463,   463,   463,   463,   464,   464,   464,   464,   465,   466,
     467,   467,   467,   467,   468,   468,   469,   470,   470,   470,
     471,   471,   471,   472,   472,   472,   473,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   475,   476,   476,   476,
     477,   478,   479,   479,   479,   480,   480,   480,   480,   480,
     481,   482,   482,   482,   482,   482,   482,   482,   483,   484,
     485,   486,   487,   487,   487,   488,   488,   488,   488,   488,
     488,   488,   488,   488,   488,   489,   489,   490,   490,   491,
     492,   493,   493,   494,   495,   496,   496,   497,   497,   497,
     497,   498,   499,   500,   500,   500,   500,   500,   500,   500,
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
     500,   500,   500,   500,   500,   500,   500,   500,   501,   501,
     502,   502,   502,   502,   503,   503,   503,   503,   504,   504,
     505,   505,   506,   506,   507,   507,   508,   508,   508,   509,
     509,   510,   510,   511,   511,   511,   511,   511,   512,   513,
     513,   513,   513,   513,   513,   513,   514,   514,   514,   514,
     515,   515,   515,   515,   516,   516,   517,   517,   517,   517,
     517,   517,   517,   518,   518,   519,   519,   519,   519,   520,
     520,   520,   520,   520,   521,   521,   522,   522,   523,   523,
     524,   524,   525,   526,   526,   527,   527,   527,   528,   528,
     528,   528,   528,   529,   529,   529,   529,   530,   531,   532,
     533,   533,   534,   534,   534,   535,   535,   536
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
       4,     6,     1,     1,     2,     1,     2,     7,     8,     1,
       3,     1,     2,     2,     3,     3,     3,     2,     3,     4,
       5,     2,     3,     5,     3,     5,     2,     2,     3,     3,
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
       1,     1,     1,     1,     1,     1,     1,     4,     5,     5,
       6,     3,     4,     1,     2,     3,     2,     1,     2,     2,
       1,     1,     1,     3,     3,     1,     1,     1,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     1,     4,     4,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     4,
       5,     8,     9,     9,    10,     1,     2,     1,     2,     6,
       0,     1,     3,     3,     0,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     4,
       4,     5,     6,     7,     4,     5,     6,     7,     4,     4,
       4,     5,     6,     7,     1,     2,     2,     1,     2,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     4,
       3,     3,     3,     4,     4,     3,     4,     6,     4,     6,
       3,     3,     4,     6,     6,     4,     6,     6,     4,     1,
       2,     1,     3,     3,     3,     5,     7,     7,     5,     5,
       5,     7,     7,     5,     5,     3,     3,     5,     7,     5,
       7,     1,     4,     3,     5,     1,     2,     5,     8,    11,
      14,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     7,     4,
       1,     2,     3,     4,     1,     1,     2,     2,     1,     3,
       1,     3,     1,     4,     1,     2,     1,     2,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     3,     5,     7,
       5,     7,     2,     1,     3,     2,     4,     4,     6,     4,
       5,     4,     5,     3,     1,     2,     2,     3,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       1,     2,     1,     2,     3,     3,     4,     3,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     3
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
  "\"'build'\"", "\"'drop'\"", "\"'unique'\"", "\"'index'\"", "\"'hash'\"",
  "\"'btree'\"", "\"'on'\"", "\"'BOM_UTF8'\"", "FTCONTAINS_REDUCE",
  "RANGE_REDUCE", "ADDITIVE_REDUCE", "MULTIPLICATIVE_REDUCE",
  "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE",
  "COMMA_DOLLAR", "UNARY_PREC", "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR",
  "OCCURS_PLUS", "OCCURS_HOOK", "STEP_REDUCE", "$accept", "Module",
  "ModuleWithoutBOM", "VersionDecl", "MainModule", "LibraryModule",
  "ModuleDecl", "Prolog", "SIND_DeclList", "VFO_DeclList", "SIND_Decl",
  "VFO_Decl", "Setter", "Import", "NamespaceDecl", "BoundarySpaceDecl",
  "DefaultNamespaceDecl", "OptionDecl", "FTOptionDecl", "OrderingModeDecl",
  "EmptyOrderDecl", "CopyNamespacesDecl", "DefaultCollationDecl",
  "BaseURIDecl", "SchemaImport", "URILiteralList", "SchemaPrefix",
  "ModuleImport", "CtxItemDecl", "CtxItemDecl2", "CtxItemDecl3",
  "CtxItemDecl4", "VarNameAndType", "VarDecl", "IndexingMethod",
  "IndexDecl", "IndexDecl2", "IndexDeclSuffix", "IndexField",
  "IndexField1", "IndexFieldList", "ConstructionDecl", "FunctionSig",
  "BlockExpr", "Block", "AssignExpr", "ExitExpr", "WhileExpr",
  "FlowCtlStatement", "IndexStatement", "FunctionDecl", "FunctionDecl2",
  "FunctionDecl3", "FunctionDecl4", "ParamList", "Param", "EnclosedExpr",
  "BracedExpr", "QueryBody", "Expr", "ApplyExpr", "ConcatExpr",
  "ExprSingle", "FLWORExpr", "ReturnExpr", "WindowType",
  "FLWORWinCondType", "FLWORWinCond", "WindowClause", "CountClause",
  "ForLetWinClause", "FLWORClause", "FLWORClauseList", "ForDollar",
  "ForClause", "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar",
  "LetClause", "VarGetsDeclList", "EvalVarDeclList", "VarGetsDecl",
  "WindowVarDecl", "WindowVars", "WindowVars3", "WindowVars2",
  "EvalVarDecl", "WhereClause", "GroupByClause", "GroupSpecList",
  "GroupSpec", "GroupCollationSpec", "OrderByClause", "OrderSpecList",
  "OrderSpec", "OrderModifier", "OrderDirSpec", "OrderEmptySpec",
  "OrderCollationSpec", "QuantifiedExpr", "QVarInDeclList", "QVarInDecl",
  "TypeswitchExpr", "CaseClauseList", "CaseClause", "IfExpr", "OrExpr",
  "AndExpr", "ComparisonExpr", "@1", "FTContainsExpr", "RangeExpr",
  "AdditiveExpr", "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "UnaryExpr",
  "SignList", "ValueExpr", "ValueComp", "NodeComp", "ValidateExpr",
  "ExtensionExpr", "PragmaList", "Pragma", "PathExpr", "LeadingSlash",
  "RelativePathExpr", "StepExpr", "AxisStep", "ForwardStep", "ForwardAxis",
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
       287,     0,    -1,   288,    -1,   271,   288,    -1,   290,    -1,
     289,   290,    -1,   291,    -1,   289,   291,    -1,   198,   199,
      20,   174,    -1,   198,   199,    20,   116,    20,   174,    -1,
     293,   344,    -1,   344,    -1,   292,   293,    -1,    51,   144,
     499,   117,   498,   174,    -1,   294,   174,    -1,   295,   174,
      -1,   294,   174,   295,   174,    -1,   296,    -1,   294,   174,
     296,    -1,   297,    -1,   295,   174,   297,    -1,   298,    -1,
     299,    -1,   300,    -1,   302,    -1,   319,    -1,   314,    -1,
     336,    -1,   303,    -1,   304,    -1,   321,    -1,   301,    -1,
     308,    -1,   309,    -1,   327,    -1,   305,    -1,   306,    -1,
     307,    -1,   487,    -1,   310,    -1,   313,    -1,    38,   144,
     499,   117,   498,    -1,    38,    76,   165,    -1,    38,    76,
     179,    -1,    38,   100,    34,   144,   498,    -1,    38,   100,
      39,   144,   498,    -1,    38,    52,   500,    20,    -1,    38,
     228,   513,    -1,    38,    69,   152,    -1,    38,    69,   185,
      -1,    38,   100,   153,   112,   113,    -1,    38,   100,   153,
     112,   114,    -1,    38,    73,   165,    94,   132,    -1,    38,
      73,   165,    94,   149,    -1,    38,    73,   150,    94,   132,
      -1,    38,    73,   150,    94,   149,    -1,    38,   100,    93,
     498,    -1,    38,    70,   498,    -1,    48,    54,   498,    -1,
      48,    54,   312,   498,    -1,    48,    54,   498,    83,   311,
      -1,    48,    54,   312,   498,    83,   311,    -1,   498,    -1,
     311,    94,   498,    -1,   144,   499,   117,    -1,   100,    34,
     144,    -1,    48,    51,   498,    -1,    48,    51,   144,   499,
     117,   498,    -1,    48,    51,   498,    83,   311,    -1,    48,
      51,   144,   499,   117,   498,    83,   311,    -1,    38,    98,
     136,   315,    -1,    81,   472,   316,    -1,   316,    -1,   317,
      -1,   122,    -1,   122,   317,    -1,   127,   348,    -1,   105,
     500,    -1,   105,   500,   469,    -1,    38,    99,   318,   127,
     348,    -1,    38,    99,   318,   122,    -1,    38,    99,   318,
     122,   127,   348,    -1,   268,    -1,   269,    -1,    38,   322,
      -1,   323,    -1,   266,   323,    -1,   267,   498,   270,   348,
     154,   326,   170,    -1,   267,   498,   270,   348,   320,   154,
     326,   170,    -1,   325,    -1,   325,    93,   498,    -1,   348,
      -1,   348,   469,    -1,   140,   324,    -1,   326,    94,   324,
      -1,    38,    58,   165,    -1,    38,    58,   179,    -1,   140,
     170,    -1,   140,   340,   170,    -1,   140,   170,    81,   470,
      -1,   140,   340,   170,    81,   470,    -1,    26,   330,    -1,
     137,   345,   167,    -1,    56,   105,   500,   127,   348,    -1,
      27,   221,   348,    -1,    31,   140,   348,   170,   330,    -1,
      28,    29,    -1,    30,    29,    -1,   263,   267,   498,    -1,
     265,   267,   498,    -1,   264,   267,   498,    -1,    38,   337,
      -1,    38,    43,   337,    -1,    38,    42,   337,    -1,   338,
      -1,    44,   338,    -1,    40,   338,    -1,    41,   339,    -1,
      39,   500,   328,   343,    -1,    39,   500,   328,   122,    -1,
      39,   500,   328,   330,    -1,   341,    -1,   340,    94,   341,
      -1,   105,   500,    -1,   105,   500,   469,    -1,   137,   345,
     167,    -1,   137,   345,   167,    -1,   345,    -1,   347,    -1,
     347,   346,    -1,   174,    -1,   346,   347,   174,    -1,   348,
      -1,   347,    94,   348,    -1,   349,    -1,   386,    -1,   389,
      -1,   392,    -1,   393,    -1,   488,    -1,   489,    -1,   491,
      -1,   490,    -1,   492,    -1,   495,    -1,   501,    -1,   332,
      -1,   333,    -1,   334,    -1,   331,    -1,   329,    -1,   335,
      -1,   358,   350,    -1,   169,   348,    -1,    62,   256,    -1,
      63,   256,    -1,   201,    -1,   234,    -1,    66,   234,    -1,
     352,   370,    67,   348,    -1,   352,    67,   348,    -1,    60,
     351,   369,   353,   353,    -1,    60,   351,   369,   353,    -1,
      68,   105,   500,    -1,   360,    -1,   365,    -1,   354,    -1,
     356,    -1,   374,    -1,   379,    -1,   375,    -1,   355,    -1,
     356,    -1,   358,   357,    -1,    60,   105,    -1,    61,    60,
     105,    -1,   359,   361,    -1,   362,    -1,   361,    94,   105,
     362,    -1,   500,   131,   348,    -1,   500,   469,   131,   348,
      -1,   500,   363,   131,   348,    -1,   500,   469,   363,   131,
     348,    -1,   500,   364,   131,   348,    -1,   500,   469,   364,
     131,   348,    -1,   500,   363,   364,   131,   348,    -1,   500,
     469,   363,   364,   131,   348,    -1,    83,   105,   500,    -1,
     250,   105,   500,    -1,    57,   105,   366,    -1,   368,    -1,
     366,    94,   105,   368,    -1,   373,    -1,   367,    94,   105,
     373,    -1,   500,   127,   348,    -1,   500,   469,   127,   348,
      -1,   500,   364,   127,   348,    -1,   500,   469,   364,   127,
     348,    -1,   105,   500,   131,   348,    -1,   105,   500,   469,
     131,   348,    -1,   371,    -1,   105,   500,    -1,   105,   500,
     371,    -1,   363,    -1,   363,   372,    -1,   372,    -1,    64,
     105,   500,    65,   105,   500,    -1,    65,   105,   500,    -1,
      64,   105,   500,    -1,   500,    -1,   195,   348,    -1,   155,
     154,   376,    -1,   377,    -1,   376,    94,   377,    -1,   105,
     500,    -1,   105,   500,   378,    -1,    93,   498,    -1,   153,
     154,   380,    -1,    50,   153,   154,   380,    -1,   381,    -1,
     380,    94,   381,    -1,   348,    -1,   348,   382,    -1,   383,
      -1,   384,    -1,   385,    -1,   383,   384,    -1,   383,   385,
      -1,   384,   385,    -1,   383,   384,   385,    -1,    82,    -1,
     103,    -1,   112,   113,    -1,   112,   114,    -1,    93,   498,
      -1,    49,   105,   387,   171,   348,    -1,   120,   105,   387,
     171,   348,    -1,   388,    -1,   387,    94,   105,   388,    -1,
     500,   131,   348,    -1,   500,   469,   131,   348,    -1,    33,
     140,   345,   170,   390,   100,   169,   348,    -1,    33,   140,
     345,   170,   390,   100,   105,   500,   169,   348,    -1,   391,
      -1,   390,   391,    -1,    87,   470,   169,   348,    -1,    87,
     105,   500,    81,   470,   169,   348,    -1,    45,   140,   345,
     170,   181,   348,   111,   348,    -1,   394,    -1,   393,   151,
     394,    -1,   395,    -1,   394,    79,   395,    -1,   397,    -1,
     397,   410,   397,    -1,   397,   411,   397,    -1,   397,   117,
     397,    -1,   397,   146,   397,    -1,    -1,   397,   141,   396,
     397,    -1,   397,   139,   397,    -1,   397,   128,   397,    -1,
     397,   126,   397,    -1,   398,    -1,   398,   239,   502,    -1,
     398,   239,   502,   536,    -1,   399,    -1,   399,   182,   399,
      -1,   400,    -1,   399,   159,   400,    -1,   399,   142,   400,
      -1,   401,    -1,   400,   177,   401,    -1,   400,   104,   401,
      -1,   400,   130,   401,    -1,   400,   143,   401,    -1,   402,
      -1,   401,   184,   402,    -1,   401,   193,   402,    -1,   403,
      -1,   402,   134,   403,    -1,   402,   121,   403,    -1,   404,
      -1,   404,    74,   215,   470,    -1,   405,    -1,   405,   183,
      81,   470,    -1,   406,    -1,   406,    88,    81,   468,    -1,
     407,    -1,   407,    89,    81,   468,    -1,   409,    -1,   408,
     409,    -1,   159,    -1,   142,    -1,   408,   159,    -1,   408,
     142,    -1,   412,    -1,   416,    -1,   413,    -1,   186,    -1,
     191,    -1,   190,    -1,   189,    -1,   188,    -1,   187,    -1,
     135,    -1,   162,    -1,   125,    -1,    32,   137,   345,   167,
      -1,    32,   206,   137,   345,   167,    -1,    32,   205,   137,
     345,   167,    -1,    32,    81,   484,   137,   345,   167,    -1,
     414,   137,   167,    -1,   414,   137,   345,   167,    -1,   415,
      -1,   414,   415,    -1,   160,   500,    15,    -1,   160,    16,
      -1,   417,    -1,   417,   418,    -1,   176,   418,    -1,   418,
      -1,   175,    -1,   419,    -1,   419,   175,   418,    -1,   419,
     176,   418,    -1,   420,    -1,   429,    -1,   421,    -1,   421,
     430,    -1,   424,    -1,   424,   430,    -1,   422,   426,    -1,
     423,    -1,    92,    -1,   101,    -1,    85,    -1,   173,    -1,
     102,    -1,   124,    -1,   123,    -1,   426,    -1,    86,   426,
      -1,   425,   426,    -1,   107,    -1,   156,    -1,    77,    -1,
     164,    -1,   163,    -1,    78,    -1,   474,    -1,   427,    -1,
     500,    -1,   428,    -1,   177,    -1,    10,    -1,    17,    -1,
     432,    -1,   432,   430,    -1,   431,    -1,   430,   431,    -1,
     138,   345,   168,    -1,   433,    -1,   435,    -1,   436,    -1,
     437,    -1,   440,    -1,   442,    -1,   438,    -1,   439,    -1,
     434,    -1,   486,    -1,    97,    -1,   133,    -1,   109,    -1,
     105,   500,    -1,   140,   170,    -1,   140,   345,   170,    -1,
     106,    -1,   152,   137,   345,   167,    -1,   185,   137,   345,
     167,    -1,   500,   140,   170,    -1,   500,   140,   441,   170,
      -1,   348,    -1,   441,    94,   348,    -1,   443,    -1,   461,
      -1,   444,    -1,   458,    -1,   459,    -1,   141,   500,   448,
     115,    -1,   141,   500,   446,   448,   115,    -1,   141,   500,
     448,   180,   178,   500,   448,   180,    -1,   141,   500,   448,
     180,   445,   178,   500,   448,   180,    -1,   141,   500,   446,
     448,   180,   178,   500,   448,   180,    -1,   141,   500,   446,
     448,   180,   445,   178,   500,   448,   180,    -1,   456,    -1,
     445,   456,    -1,   447,    -1,   446,   447,    -1,    25,   500,
     448,   117,   448,   449,    -1,    -1,    25,    -1,   166,   450,
     166,    -1,    80,   452,    80,    -1,    -1,   451,    -1,   119,
      -1,   454,    -1,   451,   119,    -1,   451,   454,    -1,    -1,
     453,    -1,   118,    -1,   455,    -1,   453,   118,    -1,   453,
     455,    -1,    19,    -1,   457,    -1,     4,    -1,   457,    -1,
     443,    -1,     9,    -1,   460,    -1,   457,    -1,     8,    -1,
     108,    -1,   110,    -1,   342,    -1,   196,    21,   197,    -1,
     196,   197,    -1,   157,    14,   158,    -1,   157,    14,     7,
      -1,    90,     6,    -1,   462,    -1,   463,    -1,   464,    -1,
     465,    -1,   466,    -1,   467,    -1,    35,   137,   345,   167,
      -1,    34,   500,   137,   167,    -1,    34,   500,   137,   345,
     167,    -1,    34,   137,   345,   167,   137,   167,    -1,    34,
     137,   345,   167,   137,   345,   167,    -1,    84,   500,   137,
     167,    -1,    84,   500,   137,   345,   167,    -1,    84,   137,
     345,   167,   137,   167,    -1,    84,   137,   345,   167,   137,
     345,   167,    -1,    36,   137,   345,   167,    -1,    37,   137,
     345,   167,    -1,    46,   499,   137,   167,    -1,    46,   499,
     137,   345,   167,    -1,    46,   137,   345,   167,   137,   167,
      -1,    46,   137,   345,   167,   137,   345,   167,    -1,   473,
      -1,   473,   129,    -1,    81,   470,    -1,   472,    -1,   472,
     471,    -1,   194,   140,   170,    -1,   129,    -1,   177,    -1,
     159,    -1,   473,    -1,   474,    -1,   136,   140,   170,    -1,
     500,    -1,   476,    -1,   482,    -1,   480,    -1,   483,    -1,
     481,    -1,   479,    -1,   478,    -1,   477,    -1,   475,    -1,
     209,   140,   170,    -1,    72,   140,   170,    -1,    72,   140,
     482,   170,    -1,    72,   140,   483,   170,    -1,    36,   140,
     170,    -1,    37,   140,   170,    -1,    46,   140,   170,    -1,
      46,   140,   499,   170,    -1,    46,   140,    20,   170,    -1,
      84,   140,   170,    -1,    84,   140,   500,   170,    -1,    84,
     140,   500,    94,   484,   170,    -1,    84,   140,   177,   170,
      -1,    84,   140,   177,    94,   484,   170,    -1,   172,   500,
     170,    -1,    34,   140,   170,    -1,    34,   140,   500,   170,
      -1,    34,   140,   500,    94,   484,   170,    -1,    34,   140,
     500,    94,   485,   170,    -1,    34,   140,   177,   170,    -1,
      34,   140,   177,    94,   484,   170,    -1,    34,   140,   177,
      94,   485,   170,    -1,    71,   140,   500,   170,    -1,   500,
      -1,   500,   129,    -1,    20,    -1,    38,   204,   205,    -1,
      38,   204,   206,    -1,    38,   204,   207,    -1,   210,   209,
     348,   217,   348,    -1,   210,   209,   348,    81,   216,   217,
     348,    -1,   210,   209,   348,    81,   218,   217,   348,    -1,
     210,   209,   348,   202,   348,    -1,   210,   209,   348,   203,
     348,    -1,   210,   211,   348,   217,   348,    -1,   210,   211,
     348,    81,   216,   217,   348,    -1,   210,   211,   348,    81,
     218,   217,   348,    -1,   210,   211,   348,   202,   348,    -1,
     210,   211,   348,   203,   348,    -1,   208,   209,   348,    -1,
     208,   211,   348,    -1,   213,   209,   348,   221,   348,    -1,
     213,   214,   215,   209,   348,   221,   348,    -1,   212,   209,
     348,    81,   348,    -1,   220,   105,   493,   219,   348,   169,
     348,    -1,   494,    -1,   493,    94,   105,   494,    -1,   500,
     127,   348,    -1,   222,   137,   348,   167,   496,    -1,   497,
      -1,   496,   497,    -1,   223,   140,   427,   170,   343,    -1,
     223,   140,   427,    94,   105,   500,   170,   343,    -1,   223,
     140,   427,    94,   105,   500,    94,   105,   500,   170,   343,
      -1,   223,   140,   427,    94,   105,   500,    94,   105,   500,
      94,   105,   500,   170,   343,    -1,    20,    -1,    18,    -1,
      18,    -1,   198,    -1,   112,    -1,    84,    -1,    37,    -1,
      72,    -1,    34,    -1,   136,    -1,    45,    -1,   209,    -1,
      46,    -1,    75,    -1,    71,    -1,    36,    -1,    33,    -1,
     194,    -1,    76,    -1,   228,    -1,    70,    -1,   206,    -1,
     205,    -1,   130,    -1,    35,    -1,   240,    -1,   227,    -1,
     230,    -1,   229,    -1,   257,    -1,   258,    -1,   261,    -1,
     259,    -1,   262,    -1,   233,    -1,   235,    -1,    53,    -1,
     201,    -1,   234,    -1,    47,    -1,   207,    -1,   220,    -1,
     214,    -1,   186,    -1,   191,    -1,   190,    -1,   189,    -1,
     188,    -1,   187,    -1,    83,    -1,    98,    -1,    99,    -1,
     169,    -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,
      64,    -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,
     131,    -1,    57,    -1,   195,    -1,   154,    -1,   155,    -1,
     153,    -1,    50,    -1,    82,    -1,   103,    -1,   113,    -1,
     114,    -1,    93,    -1,    49,    -1,   120,    -1,   171,    -1,
      87,    -1,    81,    -1,   181,    -1,   111,    -1,   151,    -1,
      79,    -1,    74,    -1,   215,    -1,    88,    -1,   182,    -1,
     104,    -1,   143,    -1,   184,    -1,   134,    -1,   121,    -1,
      32,    -1,    89,    -1,   183,    -1,   135,    -1,   165,    -1,
     179,    -1,   144,    -1,   122,    -1,   116,    -1,   150,    -1,
     132,    -1,   149,    -1,    38,    -1,    58,    -1,    69,    -1,
     100,    -1,    73,    -1,    52,    -1,   199,    -1,    48,    -1,
      54,    -1,    51,    -1,    39,    -1,   250,    -1,   239,    -1,
     255,    -1,   256,    -1,   232,    -1,   245,    -1,   253,    -1,
     249,    -1,   231,    -1,   244,    -1,   254,    -1,   248,    -1,
     243,    -1,   242,    -1,   226,    -1,   225,    -1,   247,    -1,
     236,    -1,   237,    -1,   260,    -1,   252,    -1,   251,    -1,
     246,    -1,   213,    -1,   219,    -1,   216,    -1,   210,    -1,
     203,    -1,   202,    -1,   204,    -1,   221,    -1,   211,    -1,
     212,    -1,   218,    -1,   208,    -1,   217,    -1,    44,    -1,
      41,    -1,    40,    -1,    42,    -1,    43,    -1,   152,    -1,
     185,    -1,    26,    -1,    27,    -1,    29,    -1,    31,    -1,
      28,    -1,    30,    -1,   222,    -1,   223,    -1,    59,    -1,
     224,    -1,    56,    -1,   267,    -1,   263,    -1,   264,    -1,
     266,    -1,   270,    -1,   268,    -1,   269,    -1,   265,    -1,
     224,   105,   367,    59,   137,   348,   167,    -1,    59,   137,
     348,   167,    -1,   504,    -1,   504,   503,    -1,   504,   255,
     398,    -1,   504,   503,   255,   398,    -1,   513,    -1,   511,
      -1,   503,   513,    -1,   503,   511,    -1,   505,    -1,   504,
     241,   505,    -1,   506,    -1,   505,   238,   506,    -1,   507,
      -1,   506,   240,   131,   507,    -1,   508,    -1,   240,   508,
      -1,   509,    -1,   509,   532,    -1,   140,   502,   170,    -1,
     510,    -1,   510,   528,    -1,   433,    -1,   137,   345,   167,
      -1,   512,    -1,   531,    -1,   530,    -1,   533,    -1,   527,
      -1,   152,    -1,   514,    -1,   515,    -1,   516,    -1,   517,
      -1,   520,    -1,   525,    -1,   526,    -1,   244,    -1,   254,
      -1,    87,   227,    -1,    87,   230,    -1,   221,   229,    -1,
     257,   229,    -1,   229,   227,    -1,   229,   230,    -1,   221,
     258,    -1,   257,   258,    -1,   221,   261,   519,    -1,   221,
     261,   100,    -1,   221,   261,   140,   519,   170,    -1,   221,
     261,   140,   519,    94,   518,   170,    -1,   221,   261,   140,
     100,   170,    -1,   221,   261,   140,   100,    94,   518,   170,
      -1,   257,   261,    -1,   519,    -1,   518,    94,   519,    -1,
      83,    20,    -1,    83,    20,   248,    20,    -1,    83,    20,
     529,   243,    -1,    83,    20,   248,    20,   529,   243,    -1,
     221,   259,   260,   522,    -1,   221,   259,   260,   522,   521,
      -1,   221,   100,   259,   260,    -1,   221,   100,   259,   260,
     521,    -1,   257,   259,   260,    -1,   524,    -1,   521,   524,
      -1,    83,    20,    -1,   140,   523,   170,    -1,    20,    -1,
     523,    20,    -1,   184,   522,    -1,   121,   522,    -1,   242,
      20,    -1,   221,   262,    -1,   257,   262,    -1,    83,   201,
      -1,    83,   234,    -1,   233,   235,    -1,   226,    -1,   226,
      53,    -1,   225,    -1,   225,   260,    -1,   247,    -1,   236,
     401,    -1,    83,   114,   401,    -1,    83,    47,   401,    -1,
     237,   401,   182,   401,    -1,   232,   529,   534,    -1,   256,
     401,   534,    -1,   245,   529,   253,    -1,   249,   535,    -1,
     231,   535,    -1,   260,    -1,   252,    -1,   246,    -1,   251,
      -1,   246,    -1,   257,   235,   401,    -1
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
     292,   297,   304,   306,   308,   311,   313,   316,   324,   333,
     335,   339,   341,   344,   347,   351,   355,   359,   362,   366,
     371,   377,   380,   384,   390,   394,   400,   403,   406,   410,
     414,   418,   421,   425,   429,   431,   434,   437,   440,   445,
     450,   455,   457,   461,   464,   468,   472,   476,   478,   480,
     483,   485,   489,   491,   495,   497,   499,   501,   503,   505,
     507,   509,   511,   513,   515,   517,   519,   521,   523,   525,
     527,   529,   531,   534,   537,   540,   543,   545,   547,   550,
     555,   559,   565,   570,   574,   576,   578,   580,   582,   584,
     586,   588,   590,   592,   595,   598,   602,   605,   607,   612,
     616,   621,   626,   632,   637,   643,   649,   656,   660,   664,
     668,   670,   675,   677,   682,   686,   691,   696,   702,   707,
     713,   715,   718,   722,   724,   727,   729,   736,   740,   744,
     746,   749,   753,   755,   759,   762,   766,   769,   773,   778,
     780,   784,   786,   789,   791,   793,   795,   798,   801,   804,
     808,   810,   812,   815,   818,   821,   827,   833,   835,   840,
     844,   849,   858,   869,   871,   874,   879,   887,   896,   898,
     902,   904,   908,   910,   914,   918,   922,   926,   927,   932,
     936,   940,   944,   946,   950,   955,   957,   961,   963,   967,
     971,   973,   977,   981,   985,   989,   991,   995,   999,  1001,
    1005,  1009,  1011,  1016,  1018,  1023,  1025,  1030,  1032,  1037,
    1039,  1042,  1044,  1046,  1049,  1052,  1054,  1056,  1058,  1060,
    1062,  1064,  1066,  1068,  1070,  1072,  1074,  1076,  1081,  1087,
    1093,  1100,  1104,  1109,  1111,  1114,  1118,  1121,  1123,  1126,
    1129,  1131,  1133,  1135,  1139,  1143,  1145,  1147,  1149,  1152,
    1154,  1157,  1160,  1162,  1164,  1166,  1168,  1170,  1172,  1174,
    1176,  1178,  1181,  1184,  1186,  1188,  1190,  1192,  1194,  1196,
    1198,  1200,  1202,  1204,  1206,  1208,  1210,  1212,  1215,  1217,
    1220,  1224,  1226,  1228,  1230,  1232,  1234,  1236,  1238,  1240,
    1242,  1244,  1246,  1248,  1250,  1253,  1256,  1260,  1262,  1267,
    1272,  1276,  1281,  1283,  1287,  1289,  1291,  1293,  1295,  1297,
    1302,  1308,  1317,  1327,  1337,  1348,  1350,  1353,  1355,  1358,
    1365,  1366,  1368,  1372,  1376,  1377,  1379,  1381,  1383,  1386,
    1389,  1390,  1392,  1394,  1396,  1399,  1402,  1404,  1406,  1408,
    1410,  1412,  1414,  1416,  1418,  1420,  1422,  1424,  1426,  1430,
    1433,  1437,  1441,  1444,  1446,  1448,  1450,  1452,  1454,  1456,
    1461,  1466,  1472,  1479,  1487,  1492,  1498,  1505,  1513,  1518,
    1523,  1528,  1534,  1541,  1549,  1551,  1554,  1557,  1559,  1562,
    1566,  1568,  1570,  1572,  1574,  1576,  1580,  1582,  1584,  1586,
    1588,  1590,  1592,  1594,  1596,  1598,  1600,  1604,  1608,  1613,
    1618,  1622,  1626,  1630,  1635,  1640,  1644,  1649,  1656,  1661,
    1668,  1672,  1676,  1681,  1688,  1695,  1700,  1707,  1714,  1719,
    1721,  1724,  1726,  1730,  1734,  1738,  1744,  1752,  1760,  1766,
    1772,  1778,  1786,  1794,  1800,  1806,  1810,  1814,  1820,  1828,
    1834,  1842,  1844,  1849,  1853,  1859,  1861,  1864,  1870,  1879,
    1891,  1906,  1908,  1910,  1912,  1914,  1916,  1918,  1920,  1922,
    1924,  1926,  1928,  1930,  1932,  1934,  1936,  1938,  1940,  1942,
    1944,  1946,  1948,  1950,  1952,  1954,  1956,  1958,  1960,  1962,
    1964,  1966,  1968,  1970,  1972,  1974,  1976,  1978,  1980,  1982,
    1984,  1986,  1988,  1990,  1992,  1994,  1996,  1998,  2000,  2002,
    2004,  2006,  2008,  2010,  2012,  2014,  2016,  2018,  2020,  2022,
    2024,  2026,  2028,  2030,  2032,  2034,  2036,  2038,  2040,  2042,
    2044,  2046,  2048,  2050,  2052,  2054,  2056,  2058,  2060,  2062,
    2064,  2066,  2068,  2070,  2072,  2074,  2076,  2078,  2080,  2082,
    2084,  2086,  2088,  2090,  2092,  2094,  2096,  2098,  2100,  2102,
    2104,  2106,  2108,  2110,  2112,  2114,  2116,  2118,  2120,  2122,
    2124,  2126,  2128,  2130,  2132,  2134,  2136,  2138,  2140,  2142,
    2144,  2146,  2148,  2150,  2152,  2154,  2156,  2158,  2160,  2162,
    2164,  2166,  2168,  2170,  2172,  2174,  2176,  2178,  2180,  2182,
    2184,  2186,  2188,  2190,  2192,  2194,  2196,  2198,  2200,  2202,
    2204,  2206,  2208,  2210,  2212,  2214,  2216,  2218,  2220,  2222,
    2224,  2226,  2228,  2230,  2232,  2234,  2236,  2238,  2240,  2242,
    2244,  2246,  2248,  2250,  2252,  2254,  2256,  2258,  2260,  2268,
    2273,  2275,  2278,  2282,  2287,  2289,  2291,  2294,  2297,  2299,
    2303,  2305,  2309,  2311,  2316,  2318,  2321,  2323,  2326,  2330,
    2332,  2335,  2337,  2341,  2343,  2345,  2347,  2349,  2351,  2353,
    2355,  2357,  2359,  2361,  2363,  2365,  2367,  2369,  2371,  2374,
    2377,  2380,  2383,  2386,  2389,  2392,  2395,  2399,  2403,  2409,
    2417,  2423,  2431,  2434,  2436,  2440,  2443,  2448,  2453,  2460,
    2465,  2471,  2476,  2482,  2486,  2488,  2491,  2494,  2498,  2500,
    2503,  2506,  2509,  2512,  2515,  2518,  2521,  2524,  2527,  2529,
    2532,  2534,  2537,  2539,  2542,  2546,  2550,  2555,  2559,  2563,
    2567,  2570,  2573,  2575,  2577,  2579,  2581,  2583
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   879,   879,   880,   890,   895,   901,   906,   918,   923,
     933,   940,   952,   964,   976,   982,   988,  1000,  1006,  1020,
    1026,  1040,  1041,  1042,  1043,  1049,  1050,  1051,  1052,  1055,
    1058,  1065,  1066,  1067,  1068,  1069,  1070,  1071,  1074,  1081,
    1082,  1094,  1106,  1111,  1122,  1128,  1140,  1153,  1164,  1169,
    1181,  1186,  1197,  1203,  1209,  1215,  1234,  1245,  1256,  1263,
    1270,  1277,  1290,  1296,  1311,  1315,  1325,  1331,  1338,  1344,
    1356,  1363,  1369,  1376,  1382,  1386,  1393,  1404,  1408,  1416,
    1425,  1432,  1442,  1444,  1451,  1459,  1463,  1471,  1476,  1486,
    1490,  1498,  1502,  1509,  1516,  1526,  1531,  1543,  1547,  1551,
    1555,  1562,  1569,  1576,  1583,  1590,  1602,  1606,  1613,  1617,
    1621,  1628,  1632,  1638,  1645,  1649,  1653,  1661,  1668,  1677,
    1689,  1703,  1711,  1725,  1731,  1743,  1751,  1762,  1774,  1778,
    1790,  1794,  1803,  1807,  1823,  1824,  1825,  1826,  1827,  1830,
    1831,  1832,  1833,  1834,  1836,  1837,  1840,  1841,  1842,  1843,
    1844,  1847,  1854,  1863,  1870,  1874,  1882,  1886,  1890,  1897,
    1901,  1908,  1913,  1922,  1931,  1932,  1933,  1937,  1937,  1937,
    1937,  1937,  1940,  1946,  1955,  1959,  1969,  1980,  1986,  2000,
    2007,  2015,  2024,  2034,  2042,  2051,  2060,  2075,  2087,  2098,
    2110,  2116,  2128,  2134,  2148,  2156,  2165,  2173,  2185,  2191,
    2201,  2202,  2206,  2214,  2218,  2223,  2227,  2231,  2235,  2242,
    2257,  2265,  2275,  2281,  2292,  2298,  2307,  2317,  2322,  2334,
    2340,  2354,  2360,  2372,  2379,  2386,  2393,  2400,  2407,  2414,
    2427,  2431,  2441,  2446,  2457,  2468,  2475,  2488,  2495,  2507,
    2513,  2526,  2533,  2547,  2553,  2565,  2571,  2584,  2595,  2599,
    2610,  2614,  2633,  2637,  2645,  2653,  2661,  2669,  2669,  2677,
    2685,  2693,  2707,  2711,  2718,  2731,  2735,  2746,  2750,  2754,
    2764,  2768,  2772,  2776,  2780,  2790,  2794,  2799,  2810,  2814,
    2818,  2828,  2832,  2844,  2848,  2860,  2864,  2876,  2880,  2892,
    2896,  2908,  2912,  2916,  2920,  2932,  2936,  2940,  2950,  2954,
    2958,  2962,  2966,  2970,  2980,  2984,  2988,  2998,  3002,  3006,
    3010,  3022,  3028,  3040,  3046,  3060,  3067,  3108,  3112,  3116,
    3120,  3132,  3142,  3153,  3158,  3168,  3172,  3182,  3188,  3194,
    3200,  3212,  3218,  3229,  3233,  3237,  3241,  3245,  3249,  3253,
    3263,  3267,  3277,  3283,  3295,  3299,  3303,  3307,  3311,  3326,
    3330,  3340,  3344,  3354,  3361,  3368,  3381,  3385,  3397,  3403,
    3417,  3428,  3432,  3436,  3440,  3444,  3448,  3452,  3456,  3466,
    3470,  3480,  3485,  3490,  3501,  3511,  3515,  3526,  3536,  3547,
    3603,  3609,  3621,  3627,  3639,  3643,  3653,  3657,  3661,  3671,
    3679,  3687,  3695,  3703,  3711,  3726,  3732,  3744,  3750,  3763,
    3772,  3774,  3780,  3785,  3797,  3800,  3807,  3813,  3819,  3827,
    3842,  3845,  3852,  3858,  3864,  3872,  3886,  3891,  3902,  3907,
    3918,  3923,  3928,  3934,  3946,  3952,  3957,  3962,  3973,  3978,
    3993,  3998,  4015,  4030,  4034,  4038,  4042,  4046,  4050,  4060,
    4071,  4077,  4083,  4088,  4110,  4116,  4122,  4127,  4138,  4148,
    4158,  4164,  4170,  4175,  4186,  4192,  4204,  4216,  4222,  4228,
    4265,  4270,  4275,  4286,  4290,  4294,  4304,  4315,  4319,  4323,
    4327,  4331,  4335,  4339,  4343,  4347,  4357,  4367,  4371,  4376,
    4387,  4397,  4407,  4411,  4415,  4425,  4431,  4437,  4443,  4449,
    4461,  4472,  4479,  4486,  4493,  4500,  4507,  4514,  4527,  4548,
    4555,  4575,  4615,  4620,  4623,  4631,  4637,  4643,  4649,  4655,
    4662,  4668,  4674,  4680,  4686,  4698,  4703,  4713,  4719,  4731,
    4757,  4768,  4774,  4787,  4801,  4808,  4815,  4826,  4833,  4841,
    4850,  4863,  4866,  4884,  4885,  4886,  4887,  4888,  4889,  4890,
    4891,  4892,  4893,  4894,  4895,  4896,  4897,  4898,  4899,  4900,
    4901,  4902,  4903,  4904,  4905,  4906,  4907,  4908,  4909,  4910,
    4911,  4912,  4913,  4914,  4915,  4916,  4917,  4918,  4919,  4920,
    4921,  4922,  4923,  4924,  4925,  4926,  4927,  4928,  4929,  4930,
    4931,  4932,  4933,  4934,  4935,  4936,  4937,  4938,  4939,  4940,
    4941,  4942,  4943,  4944,  4945,  4946,  4947,  4948,  4949,  4950,
    4951,  4952,  4953,  4954,  4955,  4956,  4957,  4958,  4959,  4960,
    4961,  4962,  4963,  4964,  4965,  4966,  4967,  4968,  4969,  4970,
    4971,  4972,  4973,  4974,  4975,  4976,  4977,  4978,  4979,  4980,
    4981,  4982,  4983,  4984,  4985,  4986,  4987,  4988,  4989,  4990,
    4991,  4992,  4993,  4994,  4995,  4996,  4997,  4998,  4999,  5000,
    5001,  5002,  5003,  5004,  5005,  5006,  5007,  5008,  5009,  5010,
    5011,  5012,  5013,  5014,  5015,  5016,  5017,  5018,  5019,  5020,
    5021,  5022,  5023,  5024,  5025,  5026,  5027,  5028,  5029,  5030,
    5031,  5032,  5033,  5034,  5035,  5036,  5037,  5038,  5039,  5040,
    5041,  5042,  5043,  5044,  5045,  5046,  5047,  5048,  5049,  5050,
    5051,  5052,  5053,  5054,  5055,  5056,  5057,  5058,  5069,  5075,
    5092,  5096,  5100,  5104,  5114,  5117,  5120,  5123,  5132,  5135,
    5144,  5147,  5156,  5159,  5168,  5171,  5180,  5183,  5186,  5195,
    5198,  5207,  5211,  5221,  5224,  5227,  5230,  5233,  5242,  5251,
    5255,  5259,  5263,  5267,  5271,  5275,  5285,  5288,  5291,  5294,
    5303,  5306,  5309,  5312,  5321,  5324,  5333,  5336,  5339,  5342,
    5345,  5348,  5351,  5360,  5363,  5372,  5375,  5378,  5381,  5390,
    5393,  5396,  5399,  5402,  5411,  5414,  5423,  5426,  5435,  5438,
    5447,  5450,  5459,  5468,  5471,  5480,  5483,  5486,  5495,  5498,
    5501,  5504,  5507,  5516,  5520,  5524,  5528,  5538,  5547,  5557,
    5566,  5569,  5578,  5581,  5584,  5593,  5596,  5605
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
  const int xquery_parser::yylast_ = 8320;
  const int xquery_parser::yynnts_ = 251;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 477;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 286;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 540;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5613 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"


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

