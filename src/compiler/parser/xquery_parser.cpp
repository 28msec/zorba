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
#line 864 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"

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
#line 748 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 109: /* "\"'DOUBLE'\"" */
#line 747 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 133: /* "\"'INTEGER'\"" */
#line 746 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "VersionDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 226 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "MainModule" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 231 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "LibraryModule" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 236 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "ModuleDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 241 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "Prolog" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 246 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "SIND_DeclList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 251 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "VFO_DeclList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 256 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "SIND_Decl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 261 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "VFO_Decl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 266 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "Setter" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 271 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "Import" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 276 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "NamespaceDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 281 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "BoundarySpaceDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 286 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "DefaultNamespaceDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 291 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "OptionDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 296 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "OrderingModeDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 301 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "EmptyOrderDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 306 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "CopyNamespacesDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 311 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "DefaultCollationDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 316 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "BaseURIDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 321 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "SchemaImport" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 326 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "URILiteralList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 331 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "SchemaPrefix" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 336 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "ModuleImport" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 341 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "CtxItemDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 346 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "CtxItemDecl2" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 351 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "CtxItemDecl3" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 356 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "CtxItemDecl4" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 361 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "VarNameAndType" */
#line 760 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };
#line 366 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "VarDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 371 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "IndexDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 376 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "IndexDecl2" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 381 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "IndexDeclSuffix" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 386 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "IndexField" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 391 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "IndexField1" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 396 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "IndexFieldList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 401 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "ConstructionDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 406 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "FunctionSig" */
#line 760 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 411 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "BlockExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 416 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "Block" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 421 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "BlockDecls" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 426 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "AssignExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 431 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "ExitExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 436 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "WhileExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 441 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "FlowCtlStatement" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 446 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "IndexStatement" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 451 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "FunctionDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 456 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "FunctionDecl2" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 461 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "FunctionDecl3" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 466 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "FunctionDecl4" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 471 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "ParamList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 476 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "Param" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 481 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "EnclosedExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 486 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "BracedExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 491 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "QueryBody" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 496 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "Expr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 501 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "ApplyExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 506 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ConcatExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 511 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "ExprSingle" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 516 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "FLWORExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 521 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "ReturnExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 526 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "FLWORWinCond" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 531 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "WindowClause" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 536 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CountClause" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 541 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "ForLetWinClause" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 546 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "FLWORClauseList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 551 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "ForClause" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 556 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "VarInDeclList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 561 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "VarInDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 566 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "PositionalVar" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 571 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "LetClause" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 576 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "VarGetsDeclList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 581 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "EvalVarDeclList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 586 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "VarGetsDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 591 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "WindowVarDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 596 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "WindowVars" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 601 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "WindowVars3" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 606 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "WindowVars2" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 611 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "EvalVarDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 616 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "WhereClause" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 621 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "GroupByClause" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 626 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "GroupSpecList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 631 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "GroupSpec" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 636 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "GroupCollationSpec" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 641 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "OrderByClause" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 646 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "OrderSpecList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 651 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "OrderSpec" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 656 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "OrderModifier" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 661 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "OrderDirSpec" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 666 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "OrderEmptySpec" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 671 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "OrderCollationSpec" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 676 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "QuantifiedExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 681 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "QVarInDeclList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 686 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "QVarInDecl" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 691 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "TypeswitchExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 696 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "CaseClauseList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 701 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "CaseClause" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 706 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "IfExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 711 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "OrExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 716 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "AndExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 721 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ComparisonExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 726 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FTContainsExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 731 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "RangeExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 736 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "AdditiveExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 741 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "MultiplicativeExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 746 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "UnionExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 751 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "IntersectExceptExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 756 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "InstanceofExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 761 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "TreatExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 766 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "CastableExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 771 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "CastExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 776 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "UnaryExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 781 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "SignList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 786 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "ValueExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 791 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ValueComp" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 796 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "NodeComp" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 801 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ValidateExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 806 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ExtensionExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 811 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "PragmaList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 816 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "Pragma" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 821 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "PathExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 826 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "RelativePathExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 831 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "StepExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 836 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "AxisStep" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 841 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "ForwardStep" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 846 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "ForwardAxis" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 851 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "AbbrevForwardStep" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 856 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "ReverseStep" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 861 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "ReverseAxis" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 866 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "NodeTest" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 871 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "NameTest" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 876 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "Wildcard" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 881 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "FilterExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 886 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "PredicateList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 891 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "Predicate" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 896 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "PrimaryExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 901 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "Literal" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 906 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "NumericLiteral" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 911 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "VarRef" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 916 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "ParenthesizedExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 921 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "ContextItemExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 926 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OrderedExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 931 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "UnorderedExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 936 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "FunctionCall" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 941 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "ArgList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 946 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "Constructor" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 951 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "DirectConstructor" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 956 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "DirElemConstructor" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 961 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "DirElemContentList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 966 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "DirAttributeList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 971 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "DirAttr" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 976 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "DirAttributeValue" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 981 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "Opt_QuoteAttrContentList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 986 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "QuoteAttrContentList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 991 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "Opt_AposAttrContentList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 996 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "AposAttrContentList" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1001 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "QuoteAttrValueContent" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1006 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "AposAttrValueContent" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1011 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "DirElemContent" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1016 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "CommonContent" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1021 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "DirCommentConstructor" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1026 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "DirPIConstructor" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1031 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "CDataSection" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1036 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ComputedConstructor" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1041 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "CompDocConstructor" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1046 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "CompElemConstructor" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1051 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "CompAttrConstructor" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1056 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "CompTextConstructor" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1061 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "CompCommentConstructor" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1066 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "CompPIConstructor" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1071 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "SingleType" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1076 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "TypeDeclaration" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1081 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "SequenceType" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1086 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "OccurrenceIndicator" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1091 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ItemType" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1096 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "AtomicType" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1101 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "KindTest" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1106 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "AnyKindTest" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1111 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "DocumentTest" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1116 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "TextTest" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1121 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "CommentTest" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1126 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "PITest" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1131 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "AttributeTest" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1136 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "SchemaAttributeTest" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1141 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "ElementTest" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1146 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "SchemaElementTest" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1151 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "TypeName" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1156 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "TypeName_WITH_HOOK" */
#line 756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1161 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "StringLiteral" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1166 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "InsertExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1171 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DeleteExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1176 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ReplaceExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1181 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "RenameExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1186 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "TransformExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1191 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "VarNameList" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1196 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "VarNameDecl" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1201 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "TryExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1206 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "CatchListExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1211 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "CatchExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1216 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "EvalExpr" */
#line 758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1221 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
#line 1302 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
#line 882 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 4:
#line 892 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 897 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 903 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 7:
#line 908 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 8:
#line 920 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		;}
    break;

  case 9:
#line 925 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    ;}
    break;

  case 10:
#line 935 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 11:
#line 942 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		;}
    break;

  case 12:
#line 954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 13:
#line 966 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), 
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
		;}
    break;

  case 14:
#line 978 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 15:
#line 984 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 16:
#line 990 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 17:
#line 1002 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 18:
#line 1008 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 1022 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 20:
#line 1028 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 41:
#line 1096 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 42:
#line 1108 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 43:
#line 1113 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 44:
#line 1124 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 45:
#line 1130 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 46:
#line 1142 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 47:
#line 1155 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		;}
    break;

  case 48:
#line 1166 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 49:
#line 1171 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 50:
#line 1183 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 51:
#line 1188 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 52:
#line 1199 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 53:
#line 1205 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 54:
#line 1211 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 55:
#line 1217 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 56:
#line 1236 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 57:
#line 1247 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 58:
#line 1258 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 59:
#line 1265 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		;}
    break;

  case 60:
#line 1272 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 61:
#line 1279 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 62:
#line 1292 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 63:
#line 1298 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 64:
#line 1313 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 65:
#line 1317 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 66:
#line 1327 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 67:
#line 1333 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		;}
    break;

  case 68:
#line 1340 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 69:
#line 1346 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		;}
    break;

  case 70:
#line 1358 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    ;}
    break;

  case 71:
#line 1365 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    ;}
    break;

  case 72:
#line 1371 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 73:
#line 1378 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    ;}
    break;

  case 74:
#line 1384 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    ;}
    break;

  case 75:
#line 1388 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 76:
#line 1395 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 77:
#line 1406 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (SYMTAB ((yysemantic_stack_[(2) - (2)].sval)), NULL);
    ;}
    break;

  case 78:
#line 1410 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
                               dynamic_cast<TypeDeclaration *> ((yysemantic_stack_[(3) - (3)].node)));
    ;}
    break;

  case 79:
#line 1418 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1427 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(4) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      delete nt;
		;}
    break;

  case 81:
#line 1434 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(6) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      delete nt;
		;}
    break;

  case 82:
#line 1444 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "hash"; ;}
    break;

  case 83:
#line 1446 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "btree"; ;}
    break;

  case 84:
#line 1453 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->create = false;
      (yyval.node) = d;
    ;}
    break;

  case 85:
#line 1461 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 86:
#line 1465 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->uniq = true;
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 87:
#line 1473 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(7) - (2)].sval)), (yysemantic_stack_[(7) - (4)].expr), "",
                          dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(7) - (6)].node)));
    ;}
    break;

  case 88:
#line 1478 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = new IndexDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(8) - (2)].sval)), (yysemantic_stack_[(8) - (4)].expr), (yysemantic_stack_[(8) - (5)].strval),
                                    dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(8) - (7)].node)));
      d->method = (yysemantic_stack_[(8) - (5)].strval);
      (yyval.node) = d;
    ;}
    break;

  case 89:
#line 1488 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 90:
#line 1492 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (1)].node))->coll = SYMTAB ((yysemantic_stack_[(3) - (3)].sval));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    ;}
    break;

  case 91:
#line 1500 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL);
    ;}
    break;

  case 92:
#line 1504 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<TypeDeclaration *> ((yysemantic_stack_[(2) - (2)].node)));
    ;}
    break;

  case 93:
#line 1511 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexFieldList *l = new IndexFieldList (LOC ((yyloc)));
      l->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
      
    ;}
    break;

  case 94:
#line 1518 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(3) - (1)].node))->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    ;}
    break;

  case 95:
#line 1528 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 96:
#line 1533 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 97:
#line 1545 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 98:
#line 1549 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 99:
#line 1553 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 100:
#line 1557 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 101:
#line 1564 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 102:
#line 1571 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      if ((yysemantic_stack_[(4) - (2)].node) == NULL)
        (yyval.expr) = (yysemantic_stack_[(4) - (3)].expr);
      else {
        BlockBody *b = dynamic_cast<BlockBody *> ((yysemantic_stack_[(4) - (3)].expr));
        if (b == NULL) {
          b = new BlockBody ((yysemantic_stack_[(4) - (3)].expr)->get_location (),
                             dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(4) - (2)].node)));
          b->add ((yysemantic_stack_[(4) - (3)].expr));
        }
        (yyval.expr) = b;
      }
    ;}
    break;

  case 103:
#line 1588 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      VarDecl *d = dynamic_cast<VarDecl *> ((yysemantic_stack_[(3) - (2)].node));
      d->set_global (false);
      if ((yysemantic_stack_[(3) - (1)].node) == NULL)
        vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(3) - (2)].node));
      (yyval.node) = vfo;
    ;}
    break;

  case 104:
#line 1598 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    ;}
    break;

  case 105:
#line 1605 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (3)].sval)), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 106:
#line 1612 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 107:
#line 1619 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *b = dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr));
      if (b == NULL) {
        b = new BlockBody ((yysemantic_stack_[(5) - (5)].expr)->get_location ()); 
        b->add ((yysemantic_stack_[(5) - (5)].expr));
      }
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), b);
    ;}
    break;

  case 108:
#line 1631 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 109:
#line 1635 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 110:
#line 1642 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::create_stmt);
    ;}
    break;

  case 111:
#line 1646 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::drop_stmt);
    ;}
    break;

  case 112:
#line 1650 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::build_stmt);
    ;}
    break;

  case 113:
#line 1657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 114:
#line 1661 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->deterministic = false;
      (yyval.node) = d;
    ;}
    break;

  case 115:
#line 1667 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    ;}
    break;

  case 116:
#line 1674 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 117:
#line 1678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 118:
#line 1682 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    ;}
    break;

  case 119:
#line 1690 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 120:
#line 1697 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 121:
#line 1706 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 122:
#line 1718 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 123:
#line 1732 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 124:
#line 1740 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 125:
#line 1754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 126:
#line 1760 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 127:
#line 1772 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 128:
#line 1780 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 129:
#line 1791 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 130:
#line 1802 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 131:
#line 1806 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(2) - (2)].expr)),
        *blk2 = new BlockBody (LOC ((yyloc)));
      blk2->add ((yysemantic_stack_[(2) - (1)].expr));
      for (int i = 0; i < blk->size (); i++)
        blk2->add ((*blk) [i]);
      (yyval.expr) = blk2;
    ;}
    break;

  case 132:
#line 1818 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    ;}
    break;

  case 133:
#line 1822 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 134:
#line 1831 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 135:
#line 1835 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 154:
#line 1882 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 155:
#line 1891 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 156:
#line 1898 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    ;}
    break;

  case 157:
#line 1902 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    ;}
    break;

  case 158:
#line 1910 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    ;}
    break;

  case 159:
#line 1914 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    ;}
    break;

  case 160:
#line 1918 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    ;}
    break;

  case 161:
#line 1925 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 162:
#line 1929 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 163:
#line 1936 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)), dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 164:
#line 1941 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    ;}
    break;

  case 165:
#line 1950 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 174:
#line 1968 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 175:
#line 1974 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 176:
#line 1983 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    ;}
    break;

  case 177:
#line 1987 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    ;}
    break;

  case 178:
#line 1997 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		;}
    break;

  case 179:
#line 2008 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 180:
#line 2014 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 181:
#line 2028 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 182:
#line 2035 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 183:
#line 2043 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 184:
#line 2052 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 185:
#line 2062 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 186:
#line 2070 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 187:
#line 2079 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 188:
#line 2088 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 189:
#line 2103 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 190:
#line 2115 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 191:
#line 2126 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 192:
#line 2138 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 193:
#line 2144 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 194:
#line 2156 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 195:
#line 2162 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 196:
#line 2176 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 197:
#line 2184 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 198:
#line 2193 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 199:
#line 2201 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 200:
#line 2213 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 201:
#line 2219 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 203:
#line 2230 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, SYMTAB ((yysemantic_stack_[(2) - (2)].sval)), "", "");
    ;}
    break;

  case 204:
#line 2234 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
    ;}
    break;

  case 205:
#line 2242 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    ;}
    break;

  case 206:
#line 2246 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    ;}
    break;

  case 208:
#line 2255 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (6)].sval)));
    ;}
    break;

  case 209:
#line 2259 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 210:
#line 2263 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), "");
    ;}
    break;

  case 211:
#line 2270 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = SYMTAB ((yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 212:
#line 2285 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 213:
#line 2293 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 214:
#line 2303 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 215:
#line 2309 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 216:
#line 2320 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 SYMTAB ((yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 217:
#line 2326 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 218:
#line 2335 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 219:
#line 2345 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 220:
#line 2350 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 221:
#line 2362 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 222:
#line 2368 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 223:
#line 2382 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 224:
#line 2388 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 225:
#line 2400 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 226:
#line 2407 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 227:
#line 2414 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 228:
#line 2421 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 229:
#line 2428 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 230:
#line 2435 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 231:
#line 2442 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 232:
#line 2455 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 233:
#line 2459 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 234:
#line 2469 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 235:
#line 2474 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 236:
#line 2485 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 237:
#line 2496 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 238:
#line 2503 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 239:
#line 2516 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 240:
#line 2523 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 241:
#line 2535 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 242:
#line 2541 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 243:
#line 2554 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 244:
#line 2561 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								SYMTAB ((yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 245:
#line 2575 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 246:
#line 2581 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 247:
#line 2593 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 248:
#line 2599 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 249:
#line 2612 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 250:
#line 2623 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 251:
#line 2627 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 252:
#line 2638 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 253:
#line 2642 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 254:
#line 2661 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 255:
#line 2665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 256:
#line 2673 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 257:
#line 2681 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 258:
#line 2689 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 259:
#line 2696 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 260:
#line 2697 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 261:
#line 2705 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 262:
#line 2713 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 263:
#line 2721 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 264:
#line 2735 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 265:
#line 2739 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 266:
#line 2746 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 267:
#line 2759 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 268:
#line 2763 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 269:
#line 2774 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 270:
#line 2778 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 271:
#line 2782 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 272:
#line 2792 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 273:
#line 2796 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 274:
#line 2800 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 275:
#line 2804 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 276:
#line 2808 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 277:
#line 2818 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 278:
#line 2822 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 279:
#line 2827 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 280:
#line 2838 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 281:
#line 2842 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 282:
#line 2846 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 283:
#line 2856 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 284:
#line 2860 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 285:
#line 2872 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 286:
#line 2876 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 287:
#line 2888 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 288:
#line 2892 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 289:
#line 2904 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 290:
#line 2908 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 291:
#line 2920 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 292:
#line 2924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 293:
#line 2936 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 294:
#line 2940 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 295:
#line 2944 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 296:
#line 2948 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 297:
#line 2960 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 298:
#line 2964 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 2968 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 2978 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 301:
#line 2982 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 302:
#line 2986 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 303:
#line 2990 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 304:
#line 2994 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 305:
#line 2998 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 306:
#line 3008 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 307:
#line 3012 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 308:
#line 3016 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 309:
#line 3026 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 310:
#line 3030 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 311:
#line 3034 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 312:
#line 3038 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    ;}
    break;

  case 313:
#line 3050 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 314:
#line 3056 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 315:
#line 3068 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 316:
#line 3074 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 317:
#line 3088 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(3) - (2)].sval))),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 318:
#line 3094 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 319:
#line 3136 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 320:
#line 3140 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 321:
#line 3144 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 322:
#line 3148 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 323:
#line 3160 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    ;}
    break;

  case 324:
#line 3170 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 325:
#line 3181 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 326:
#line 3186 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 327:
#line 3196 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 328:
#line 3200 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 329:
#line 3210 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 330:
#line 3216 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 331:
#line 3222 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 332:
#line 3228 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 333:
#line 3240 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 334:
#line 3246 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 335:
#line 3257 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 336:
#line 3261 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 337:
#line 3265 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 338:
#line 3269 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 339:
#line 3273 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 340:
#line 3277 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 341:
#line 3281 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 342:
#line 3291 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 343:
#line 3295 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 344:
#line 3305 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 345:
#line 3311 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 346:
#line 3323 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 347:
#line 3327 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 348:
#line 3331 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 349:
#line 3335 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 350:
#line 3339 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 351:
#line 3354 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 352:
#line 3358 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 353:
#line 3368 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 354:
#line 3372 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 355:
#line 3382 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 356:
#line 3389 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 357:
#line 3396 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 358:
#line 3409 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 359:
#line 3413 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 360:
#line 3425 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 361:
#line 3431 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 362:
#line 3445 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 363:
#line 3456 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 364:
#line 3460 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 365:
#line 3464 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 366:
#line 3468 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 367:
#line 3472 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 368:
#line 3476 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 369:
#line 3480 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 370:
#line 3484 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 371:
#line 3494 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 372:
#line 3498 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 373:
#line 3508 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 374:
#line 3513 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 375:
#line 3518 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 376:
#line 3529 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 377:
#line 3539 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 378:
#line 3543 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 379:
#line 3554 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 380:
#line 3564 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 381:
#line 3575 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 382:
#line 3631 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 383:
#line 3637 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 384:
#line 3649 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 385:
#line 3655 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 386:
#line 3667 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 387:
#line 3671 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 388:
#line 3681 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 389:
#line 3685 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 390:
#line 3689 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 391:
#line 3699 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 392:
#line 3707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 393:
#line 3715 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 394:
#line 3723 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 395:
#line 3731 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 396:
#line 3739 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 397:
#line 3754 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 398:
#line 3760 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 399:
#line 3772 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 400:
#line 3778 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 401:
#line 3791 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 404:
#line 3808 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 405:
#line 3813 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 406:
#line 3824 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 407:
#line 3828 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 408:
#line 3835 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 409:
#line 3841 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 410:
#line 3847 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 411:
#line 3855 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 412:
#line 3869 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 413:
#line 3873 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 414:
#line 3880 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 415:
#line 3886 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 416:
#line 3892 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 417:
#line 3900 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 418:
#line 3914 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 419:
#line 3919 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 420:
#line 3930 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 421:
#line 3935 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 422:
#line 3946 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 423:
#line 3951 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 424:
#line 3956 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 425:
#line 3962 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 426:
#line 3974 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 427:
#line 3980 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 428:
#line 3985 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 429:
#line 3990 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 430:
#line 4001 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 431:
#line 4006 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 432:
#line 4021 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 433:
#line 4026 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 434:
#line 4043 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 435:
#line 4058 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 436:
#line 4062 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 437:
#line 4066 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 438:
#line 4070 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 439:
#line 4074 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 440:
#line 4078 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 441:
#line 4088 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 442:
#line 4099 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 443:
#line 4105 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 444:
#line 4111 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 445:
#line 4116 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 446:
#line 4138 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 447:
#line 4144 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 448:
#line 4150 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 449:
#line 4155 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 450:
#line 4166 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 451:
#line 4176 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 452:
#line 4186 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 453:
#line 4192 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 454:
#line 4198 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 455:
#line 4203 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 456:
#line 4214 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 457:
#line 4220 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 458:
#line 4232 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 459:
#line 4244 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 460:
#line 4250 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 461:
#line 4256 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 462:
#line 4293 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 463:
#line 4298 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 464:
#line 4303 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 465:
#line 4314 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 466:
#line 4318 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 467:
#line 4322 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 468:
#line 4332 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 469:
#line 4343 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 470:
#line 4347 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 471:
#line 4351 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 472:
#line 4355 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 473:
#line 4359 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 474:
#line 4363 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 475:
#line 4367 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 476:
#line 4371 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 477:
#line 4375 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 478:
#line 4385 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 479:
#line 4395 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 480:
#line 4399 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 481:
#line 4404 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 482:
#line 4415 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 483:
#line 4425 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 484:
#line 4435 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 485:
#line 4439 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 486:
#line 4443 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 487:
#line 4453 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 488:
#line 4459 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 489:
#line 4465 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 490:
#line 4471 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 491:
#line 4477 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 492:
#line 4489 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 493:
#line 4500 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		;}
    break;

  case 494:
#line 4507 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
                           NULL,
                           true);
		;}
    break;

  case 495:
#line 4514 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		;}
    break;

  case 496:
#line 4521 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		;}
    break;

  case 497:
#line 4528 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 498:
#line 4535 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		;}
    break;

  case 499:
#line 4542 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 500:
#line 4555 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 501:
#line 4576 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 502:
#line 4583 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 503:
#line 4603 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 504:
#line 4643 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 505:
#line 4648 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 506:
#line 4651 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 507:
#line 4659 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 508:
#line 4665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 509:
#line 4671 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 510:
#line 4677 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 511:
#line 4683 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 512:
#line 4690 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 513:
#line 4696 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 514:
#line 4702 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 515:
#line 4708 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 516:
#line 4714 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 517:
#line 4726 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 518:
#line 4731 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 519:
#line 4741 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 520:
#line 4747 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 521:
#line 4759 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 522:
#line 4785 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 523:
#line 4796 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 524:
#line 4802 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 525:
#line 4815 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 526:
#line 4829 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 527:
#line 4836 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 528:
#line 4843 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 529:
#line 4854 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 530:
#line 4861 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 531:
#line 4869 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(11) - (6)].sval)),
                          SYMTAB ((yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 532:
#line 4878 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(14) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(14) - (6)].sval)),
                          SYMTAB ((yysemantic_stack_[(14) - (9)].sval)),
                          SYMTAB ((yysemantic_stack_[(14) - (12)].sval)),
                          (yysemantic_stack_[(14) - (14)].expr));
    ;}
    break;

  case 534:
#line 4894 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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

  case 535:
#line 4911 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 536:
#line 4912 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); ;}
    break;

  case 537:
#line 4913 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); ;}
    break;

  case 538:
#line 4914 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); ;}
    break;

  case 539:
#line 4915 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); ;}
    break;

  case 540:
#line 4916 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); ;}
    break;

  case 541:
#line 4917 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); ;}
    break;

  case 542:
#line 4918 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); ;}
    break;

  case 543:
#line 4919 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); ;}
    break;

  case 544:
#line 4920 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); ;}
    break;

  case 545:
#line 4921 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); ;}
    break;

  case 546:
#line 4922 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); ;}
    break;

  case 547:
#line 4923 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); ;}
    break;

  case 548:
#line 4924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); ;}
    break;

  case 549:
#line 4925 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); ;}
    break;

  case 550:
#line 4926 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); ;}
    break;

  case 551:
#line 4927 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); ;}
    break;

  case 552:
#line 4928 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); ;}
    break;

  case 553:
#line 4929 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); ;}
    break;

  case 554:
#line 4930 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); ;}
    break;

  case 555:
#line 4931 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); ;}
    break;

  case 556:
#line 4932 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); ;}
    break;

  case 557:
#line 4933 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); ;}
    break;

  case 558:
#line 4934 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); ;}
    break;

  case 559:
#line 4935 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); ;}
    break;

  case 560:
#line 4936 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); ;}
    break;

  case 561:
#line 4937 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); ;}
    break;

  case 562:
#line 4938 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); ;}
    break;

  case 563:
#line 4939 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); ;}
    break;

  case 564:
#line 4940 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); ;}
    break;

  case 565:
#line 4941 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); ;}
    break;

  case 566:
#line 4942 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); ;}
    break;

  case 567:
#line 4943 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); ;}
    break;

  case 568:
#line 4944 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); ;}
    break;

  case 569:
#line 4945 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); ;}
    break;

  case 570:
#line 4946 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); ;}
    break;

  case 571:
#line 4947 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); ;}
    break;

  case 572:
#line 4948 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); ;}
    break;

  case 573:
#line 4949 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); ;}
    break;

  case 574:
#line 4950 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); ;}
    break;

  case 575:
#line 4951 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); ;}
    break;

  case 576:
#line 4952 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); ;}
    break;

  case 577:
#line 4953 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); ;}
    break;

  case 578:
#line 4954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); ;}
    break;

  case 579:
#line 4955 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); ;}
    break;

  case 580:
#line 4956 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); ;}
    break;

  case 581:
#line 4957 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); ;}
    break;

  case 582:
#line 4958 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); ;}
    break;

  case 583:
#line 4959 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); ;}
    break;

  case 584:
#line 4960 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); ;}
    break;

  case 585:
#line 4961 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); ;}
    break;

  case 586:
#line 4962 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); ;}
    break;

  case 587:
#line 4963 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); ;}
    break;

  case 588:
#line 4964 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); ;}
    break;

  case 589:
#line 4965 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); ;}
    break;

  case 590:
#line 4966 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); ;}
    break;

  case 591:
#line 4967 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); ;}
    break;

  case 592:
#line 4968 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); ;}
    break;

  case 593:
#line 4969 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); ;}
    break;

  case 594:
#line 4970 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); ;}
    break;

  case 595:
#line 4971 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); ;}
    break;

  case 596:
#line 4972 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); ;}
    break;

  case 597:
#line 4973 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); ;}
    break;

  case 598:
#line 4974 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); ;}
    break;

  case 599:
#line 4975 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); ;}
    break;

  case 600:
#line 4976 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); ;}
    break;

  case 601:
#line 4977 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); ;}
    break;

  case 602:
#line 4978 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); ;}
    break;

  case 603:
#line 4979 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); ;}
    break;

  case 604:
#line 4980 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); ;}
    break;

  case 605:
#line 4981 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); ;}
    break;

  case 606:
#line 4982 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); ;}
    break;

  case 607:
#line 4983 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); ;}
    break;

  case 608:
#line 4984 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); ;}
    break;

  case 609:
#line 4985 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); ;}
    break;

  case 610:
#line 4986 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); ;}
    break;

  case 611:
#line 4987 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); ;}
    break;

  case 612:
#line 4988 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); ;}
    break;

  case 613:
#line 4989 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); ;}
    break;

  case 614:
#line 4990 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); ;}
    break;

  case 615:
#line 4991 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); ;}
    break;

  case 616:
#line 4992 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); ;}
    break;

  case 617:
#line 4993 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); ;}
    break;

  case 618:
#line 4994 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); ;}
    break;

  case 619:
#line 4995 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); ;}
    break;

  case 620:
#line 4996 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); ;}
    break;

  case 621:
#line 4997 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); ;}
    break;

  case 622:
#line 4998 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); ;}
    break;

  case 623:
#line 4999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); ;}
    break;

  case 624:
#line 5000 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); ;}
    break;

  case 625:
#line 5001 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); ;}
    break;

  case 626:
#line 5002 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); ;}
    break;

  case 627:
#line 5003 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); ;}
    break;

  case 628:
#line 5004 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); ;}
    break;

  case 629:
#line 5005 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); ;}
    break;

  case 630:
#line 5006 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); ;}
    break;

  case 631:
#line 5007 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); ;}
    break;

  case 632:
#line 5008 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); ;}
    break;

  case 633:
#line 5009 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); ;}
    break;

  case 634:
#line 5010 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); ;}
    break;

  case 635:
#line 5011 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); ;}
    break;

  case 636:
#line 5012 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); ;}
    break;

  case 637:
#line 5013 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); ;}
    break;

  case 638:
#line 5014 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); ;}
    break;

  case 639:
#line 5015 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); ;}
    break;

  case 640:
#line 5016 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); ;}
    break;

  case 641:
#line 5017 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); ;}
    break;

  case 642:
#line 5018 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); ;}
    break;

  case 643:
#line 5019 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); ;}
    break;

  case 644:
#line 5020 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); ;}
    break;

  case 645:
#line 5021 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); ;}
    break;

  case 646:
#line 5022 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); ;}
    break;

  case 647:
#line 5023 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); ;}
    break;

  case 648:
#line 5024 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); ;}
    break;

  case 649:
#line 5025 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); ;}
    break;

  case 650:
#line 5026 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); ;}
    break;

  case 651:
#line 5027 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); ;}
    break;

  case 652:
#line 5028 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); ;}
    break;

  case 653:
#line 5029 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); ;}
    break;

  case 654:
#line 5030 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); ;}
    break;

  case 655:
#line 5031 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); ;}
    break;

  case 656:
#line 5032 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); ;}
    break;

  case 657:
#line 5033 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); ;}
    break;

  case 658:
#line 5034 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); ;}
    break;

  case 659:
#line 5035 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); ;}
    break;

  case 660:
#line 5036 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); ;}
    break;

  case 661:
#line 5037 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); ;}
    break;

  case 662:
#line 5038 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); ;}
    break;

  case 663:
#line 5039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); ;}
    break;

  case 664:
#line 5040 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); ;}
    break;

  case 665:
#line 5041 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); ;}
    break;

  case 666:
#line 5042 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); ;}
    break;

  case 667:
#line 5043 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); ;}
    break;

  case 668:
#line 5044 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); ;}
    break;

  case 669:
#line 5045 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); ;}
    break;

  case 670:
#line 5046 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); ;}
    break;

  case 671:
#line 5047 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); ;}
    break;

  case 672:
#line 5048 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); ;}
    break;

  case 673:
#line 5049 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); ;}
    break;

  case 674:
#line 5050 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); ;}
    break;

  case 675:
#line 5051 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); ;}
    break;

  case 676:
#line 5052 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); ;}
    break;

  case 677:
#line 5053 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); ;}
    break;

  case 678:
#line 5054 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); ;}
    break;

  case 679:
#line 5055 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); ;}
    break;

  case 680:
#line 5056 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); ;}
    break;

  case 681:
#line 5057 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); ;}
    break;

  case 682:
#line 5058 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); ;}
    break;

  case 683:
#line 5059 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); ;}
    break;

  case 684:
#line 5060 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); ;}
    break;

  case 685:
#line 5061 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); ;}
    break;

  case 686:
#line 5062 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); ;}
    break;

  case 687:
#line 5063 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); ;}
    break;

  case 688:
#line 5064 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); ;}
    break;

  case 689:
#line 5065 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); ;}
    break;

  case 690:
#line 5066 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); ;}
    break;

  case 691:
#line 5067 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); ;}
    break;

  case 692:
#line 5068 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); ;}
    break;

  case 693:
#line 5069 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); ;}
    break;

  case 694:
#line 5070 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); ;}
    break;

  case 695:
#line 5071 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); ;}
    break;

  case 696:
#line 5072 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); ;}
    break;

  case 697:
#line 5073 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); ;}
    break;

  case 698:
#line 5074 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); ;}
    break;

  case 699:
#line 5075 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); ;}
    break;

  case 700:
#line 5076 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); ;}
    break;

  case 701:
#line 5077 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); ;}
    break;

  case 702:
#line 5078 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); ;}
    break;

  case 703:
#line 5079 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("create"); ;}
    break;

  case 704:
#line 5080 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("build"); ;}
    break;

  case 705:
#line 5081 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); ;}
    break;

  case 706:
#line 5082 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); ;}
    break;

  case 707:
#line 5083 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("hash"); ;}
    break;

  case 708:
#line 5084 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("btree"); ;}
    break;

  case 709:
#line 5085 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("drop"); ;}
    break;

  case 710:
#line 5097 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 711:
#line 5103 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 712:
#line 5120 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 713:
#line 5124 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 714:
#line 5128 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 715:
#line 5132 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 716:
#line 5142 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 717:
#line 5145 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 718:
#line 5148 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 719:
#line 5151 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 720:
#line 5160 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 721:
#line 5163 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 722:
#line 5172 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 723:
#line 5175 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 724:
#line 5184 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 725:
#line 5187 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 726:
#line 5196 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 727:
#line 5199 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 728:
#line 5208 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 729:
#line 5211 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 730:
#line 5214 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 731:
#line 5223 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 732:
#line 5226 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 733:
#line 5235 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 734:
#line 5239 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 735:
#line 5249 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 736:
#line 5252 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 737:
#line 5255 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 738:
#line 5258 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 739:
#line 5261 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 740:
#line 5270 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 741:
#line 5279 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 742:
#line 5283 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 743:
#line 5287 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 744:
#line 5291 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 745:
#line 5295 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 746:
#line 5299 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 747:
#line 5303 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 748:
#line 5313 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 749:
#line 5316 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 750:
#line 5319 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 751:
#line 5322 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 752:
#line 5331 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 753:
#line 5334 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 754:
#line 5337 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 755:
#line 5340 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 756:
#line 5349 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 757:
#line 5352 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 758:
#line 5361 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 759:
#line 5364 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 760:
#line 5367 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 761:
#line 5370 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 762:
#line 5373 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 763:
#line 5376 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 764:
#line 5379 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 765:
#line 5388 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 766:
#line 5391 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 767:
#line 5400 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 768:
#line 5403 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 769:
#line 5406 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 770:
#line 5409 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 771:
#line 5418 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 772:
#line 5421 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 773:
#line 5424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 774:
#line 5427 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 775:
#line 5430 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 776:
#line 5439 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 777:
#line 5442 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 778:
#line 5451 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 779:
#line 5454 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 780:
#line 5463 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 781:
#line 5466 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 782:
#line 5475 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 783:
#line 5478 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 784:
#line 5487 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 785:
#line 5496 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 786:
#line 5499 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 787:
#line 5508 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 788:
#line 5511 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 789:
#line 5514 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 790:
#line 5523 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 791:
#line 5526 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 792:
#line 5529 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 793:
#line 5532 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 794:
#line 5535 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 795:
#line 5544 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 796:
#line 5548 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 797:
#line 5552 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 798:
#line 5556 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 799:
#line 5566 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 800:
#line 5575 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 801:
#line 5585 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 802:
#line 5594 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 803:
#line 5597 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 804:
#line 5606 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 805:
#line 5609 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 806:
#line 5612 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 807:
#line 5621 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 808:
#line 5624 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 809:
#line 5633 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6977 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1022;
  const short int
  xquery_parser::yypact_[] =
  {
      1337, -1022, -1022, -1022, -1022,   -55,  -103,   241, -1022,   249,
      23,    33,    76,  6544,   184,   165,   406,    68, -1022, -1022,
   -1022, -1022, -1022, -1022,   235,   131, -1022,   534,   278, -1022,
     289, -1022, -1022, -1022,   350,   371, -1022,   378,   251,   487,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,   385,
     415, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022,  6797, -1022,  5775, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022,  8315, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022,   460, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,  1599,  8315,
   -1022, -1022, -1022, -1022, -1022, -1022,   444, -1022, -1022, -1022,
   -1022,   572, -1022,  6291, -1022, -1022, -1022, -1022, -1022,  8315,
   -1022, -1022,  5514, -1022, -1022, -1022, -1022, -1022, -1022,   456,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,    18,   413,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,   -84,   475,
      -3, -1022,   416,   266, -1022, -1022, -1022, -1022, -1022, -1022,
     523, -1022,   496, -1022,   532, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022,   372,   373,   374, -1022, -1022, -1022, -1022, -1022,  3948,
     638, -1022,  4209, -1022, -1022,    36,  4470,   468,   470, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,     5, -1022,
   -1022, -1022, -1022,    90,  8315, -1022, -1022, -1022, -1022, -1022,
     494,   567, -1022,   661,   408,   202,   296,   330,   377, -1022,
     575,   469,   563,   564,  4731, -1022, -1022, -1022,   187, -1022,
   -1022,  5514, -1022,   328, -1022,   516,  5775, -1022,   516,  5775,
   -1022, -1022, -1022, -1022,   516, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022,   515, -1022, -1022, -1022,  4470, -1022, -1022,
    4470,  8315,  4470,   520,   521,  4470, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022,  4470,  7050, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,   522,  4470,
    4470,   490,  4470,   491,  8315,   623,   625,   538,   538,   623,
    8315,   302,   170,   645,   300,   329,   530,   562,   293,   650,
     398,   -33,   402,   645, -1022, -1022, -1022, -1022,  4470, -1022,
    4470,    74,   533,    45,    59,  8315,   650,  8315,  8315,  4470,
     418,   421, -1022,   570,   573,  8315,    53,  4470,  7303,   542,
     540,   545,   548,   550,   551, -1022, -1022, -1022,  8315, -1022,
     525,   667,  4470,    34, -1022,   684,   535, -1022,  4470,   503,
   -1022,   683,  4470,  4470,   541,  4470,  4470,  4470,  4470,   489,
    8315,  4470,  8315,   645,   645,   645, -1022, -1022, -1022, -1022,
      68,   534, -1022, -1022,    36,   670,  4470, -1022,  4470,   557,
     371,   251,   487,   607,   559,   561,  4470,  4470, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022,   622, -1022,   -28,  4992,  4992,
    4992, -1022,  4992,  4992, -1022,  4992, -1022,  4992, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022,  4992,  4992,    20,  4992,  4992,
    4992,  4992,  4992,  4992,  4992,  4992,  4992,  4992,  4992,   502,
     637,   642,   643, -1022, -1022, -1022,  1860, -1022, -1022,  5514,
    5514,  4470,   516, -1022, -1022,   516, -1022,   516,  2121,  5253,
   -1022,   555,   589, -1022,   560,  4470,  4470,   558,   565, -1022,
     -24,     4,  2382,   574,   576, -1022,   577, -1022,   590, -1022,
    8315, -1022, -1022, -1022, -1022,   709, -1022, -1022, -1022, -1022,
   -1022, -1022,   648,   651, -1022, -1022,   315,  8315,   405,   587,
     593,   645,   627,   629, -1022, -1022, -1022,   368,    32,   370,
     727, -1022, -1022,   295, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022,   483,   584,   588,   594, -1022,   596,  2643,
     650,   674,   725,   650,   645,   686,    -9, -1022,   -15,   655,
     652,   687, -1022,   -25,   610, -1022, -1022,  8315,   -14, -1022,
     612,   540,   385, -1022,   613,   614,   618, -1022,    49,   113,
    2904,     1, -1022,  8315,   667, -1022,     6,   621, -1022, -1022,
   -1022, -1022,   624, -1022,   -26, -1022, -1022, -1022,   -12,    64,
     699,   569,   583,   -17, -1022,   666,   628,    21, -1022, -1022,
   -1022, -1022, -1022,   620, -1022,   -10, -1022, -1022,     7,   644,
    8315,  4470,   692, -1022, -1022,   694,  7809,   696,  4470,   698,
      24,   673,    -8,   567, -1022, -1022, -1022, -1022, -1022,  4992,
   -1022, -1022, -1022,  4470,    20,   257, -1022,   549,   465,   571,
     578, -1022, -1022,   566,   180,   296,   296,   -46,   330,   330,
     330,   330,   377,   377, -1022, -1022,  7809,  7809,  8315,  8315,
   -1022,   646, -1022, -1022,   647, -1022, -1022, -1022,   155,   706,
     636,   649,   -55,  4470, -1022,   653,   654,   730,   675,  8315,
   -1022,  8315, -1022, -1022,   657, -1022, -1022, -1022,   153,   379,
     590, -1022,   279,   285,  8062,   695,  4470, -1022, -1022, -1022,
     733,   700,  4470,   645,   645, -1022,   461,   645, -1022, -1022,
     580, -1022, -1022,   568,   233, -1022, -1022, -1022, -1022, -1022,
   -1022,   581, -1022, -1022,  4470,   662,   682, -1022, -1022, -1022,
     658,   712,   645,   688,   713,   743,   645,   726,  4470,  4470,
     702,   645,  4470,   729,  4470,   715,   -66, -1022,   219,   602,
   -1022, -1022,   445,   -14, -1022, -1022, -1022,   707,  8315, -1022,
    8315, -1022, -1022,   678,  4470,   828, -1022,   121, -1022,   174,
   -1022, -1022,   834, -1022,   383,  4470,  4470,  4470,   400,  4470,
    4470,  4470,  4470,  4470,  4470,   750,  4470,  4470,   633,   720,
     753,   670, -1022,  4470, -1022,   381,   765, -1022,  8315,   771,
   -1022,  8315,   728,   731, -1022,   239, -1022, -1022, -1022,  8315,
   -1022,  8315,  4470,   736,  4470,  4470,    30,   738, -1022,   703,
     704, -1022,   641, -1022,   -82, -1022,   313,    -7,   656,    20,
     313,  4992,  4992,   519, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022,    20,   741,    -7, -1022,   619,   820, -1022, -1022, -1022,
   -1022, -1022,   751, -1022, -1022, -1022,  4470, -1022, -1022, -1022,
   -1022,   714, -1022, -1022,  7556,   419, -1022,  3165,   717,   722,
     754,   723,   724, -1022,  8315,   801,   169, -1022, -1022,  4470,
   -1022,   -55, -1022, -1022, -1022, -1022,   409, -1022, -1022, -1022,
    4470, -1022, -1022, -1022, -1022, -1022, -1022,   630,   203,   864,
   -1022,   253, -1022, -1022,   -91,  4470,  3426, -1022,   645,   802,
   -1022, -1022, -1022,   645,   802,  8315, -1022, -1022,  4470,   721,
   -1022,  8315, -1022,  4470,  4470,   770,  4470,   767, -1022,   794,
     795,  4470,  8315,   543,   835, -1022, -1022, -1022,  3687,   734,
     735, -1022, -1022, -1022,   789, -1022,   189, -1022, -1022,   901,
   -1022, -1022,  4470,  8315, -1022, -1022,   299, -1022, -1022, -1022,
     737,   691,   693, -1022, -1022, -1022,   697,   701, -1022, -1022,
   -1022, -1022, -1022,   705,  8315,   740, -1022,   772,   633, -1022,
    4470,  8315,   765, -1022,   645, -1022,   506, -1022,   236,   822,
   -1022,  4470,   824,   692, -1022,   749,   752, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022,  4470, -1022, -1022,  4470,   782,  4470,
   -1022, -1022,  4992, -1022, -1022, -1022, -1022, -1022,    57,  4992,
    4992,   316, -1022,   571, -1022, -1022,   158,  4992, -1022, -1022,
     578,    20,   668, -1022, -1022, -1022, -1022, -1022,  8315,   756,
     -27, -1022, -1022,   762, -1022, -1022, -1022, -1022, -1022,   733,
    7809,   815,   842,   763, -1022, -1022, -1022,   134,   911,   912,
     134,    -2,   175,   194,   793, -1022, -1022,   780,   825, -1022,
     768,   854,   645,   802, -1022, -1022, -1022, -1022, -1022, -1022,
    4470, -1022,  4470,  8315,  8315, -1022,   366, -1022,  4470, -1022,
     773, -1022, -1022,   828,  8315,   311, -1022,   775,   828,  8315,
   -1022, -1022,  4470,  4470,  4470,  4470,  4470, -1022,  4470,  6036,
   -1022,   776, -1022, -1022, -1022, -1022,   822, -1022, -1022, -1022,
     645, -1022, -1022, -1022, -1022, -1022, -1022,  4470, -1022,   330,
    4992,  4992,   330,   336, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022,   857,  4470,  8315,  4470, -1022, -1022, -1022, -1022,
    7809, -1022,   203,   203,   134, -1022, -1022, -1022,    25,   134,
     919,   710,   861, -1022,   861, -1022,  4470,   195,   793,  4470,
   -1022,   645, -1022, -1022, -1022,   880, -1022, -1022, -1022, -1022,
       3,   828,  8315, -1022,   766,   828, -1022, -1022, -1022, -1022,
   -1022, -1022,   201, -1022, -1022, -1022, -1022,   330,   330,  4992,
    7809, -1022,   778, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
      -7, -1022,   204, -1022,   209, -1022,   856,   733,  4470, -1022,
     210, -1022,   802,   845,   333,   380, -1022,   774,   828, -1022,
     777,   847,   818,   330,   787,  4470,   716,   861, -1022, -1022,
     645, -1022, -1022, -1022,  8315, -1022, -1022,   878,   354, -1022,
   -1022, -1022, -1022,   797,   450, -1022, -1022, -1022,   781, -1022,
    8315, -1022,  4470, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022,   212, -1022,   855,   818,  8315,
   -1022,   223,   859,   818,  8315, -1022,   796,   818, -1022
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   356,   357,   535,   503,   691,   692,   695,   693,   696,
     694,   625,   549,   541,   557,   548,   539,   637,   647,   686,
     685,   687,   688,   684,   543,   545,   572,   644,   607,   601,
     646,   642,   569,   645,   701,   596,   638,   699,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   639,   553,   547,
     540,   641,   616,   546,   551,   347,   350,   615,   611,   602,
     582,   538,   337,     0,   610,   618,   626,   335,   606,   373,
     583,   584,   640,   336,   339,   603,   620,     0,   379,   345,
     375,   613,   537,   604,   605,   633,   608,   624,   632,   341,
     340,   556,   595,   635,   374,   623,   628,   542,     0,     0,
     294,   621,   631,   636,   634,   614,   689,   600,   598,   599,
     346,     0,   293,     0,   349,   348,   629,   585,   609,     0,
     338,   323,     0,   355,   630,   612,   619,   627,   622,   690,
     576,   581,   580,   579,   578,   577,   550,   597,     0,   536,
     643,   570,   676,   675,   677,   555,   554,   573,   682,   544,
     674,   679,   680,   671,   575,   617,   673,   683,   681,   672,
     574,   678,   697,   698,   700,   663,   662,   559,   552,   561,
     560,   656,   652,   567,   571,   568,   665,   666,   649,   558,
     661,   660,   657,   653,   670,   664,   659,   655,   648,   669,
     668,   654,   658,   650,   651,   562,   563,   565,   667,   564,
     566,   703,   704,   709,   705,   702,   707,   708,   706,     0,
       0,     2,     0,     4,     6,     0,     0,     0,     0,    17,
      19,    21,    22,    23,    31,    24,    28,    29,    35,    36,
      37,    32,    33,    39,    40,    26,    25,    30,    34,   152,
     151,   148,   149,   150,   153,    27,    11,   129,   130,   134,
     136,   168,   174,     0,     0,   166,   167,   137,   138,   139,
     140,   250,   252,   254,   264,   267,   269,   272,   277,   280,
     283,   285,   287,   289,     0,   291,   297,   299,     0,   315,
     298,   319,   322,   324,   327,   329,     0,   334,   331,     0,
     342,   352,   354,   328,   358,   363,   371,   364,   365,   366,
     369,   370,   367,   368,   386,   388,   389,   390,   387,   435,
     436,   437,   438,   439,   440,   351,   477,   469,   476,   475,
     474,   471,   473,   470,   472,   372,    38,   141,   142,   144,
     143,   145,   146,   353,   147,   104,   101,     0,   108,   109,
       0,     0,     0,     0,     0,     0,   691,   692,   695,   696,
     694,   625,   549,   541,   557,   548,   539,   637,   543,   545,
     644,   607,   646,   701,   596,   699,   586,   587,   547,   540,
     538,   608,     0,     0,   689,   690,   536,   682,   544,   674,
     680,   671,   574,   697,   700,   703,   704,   709,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,   113,   116,     0,   534,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,     0,     0,     0,     0,     0,     0,     0,
     541,   548,   539,   545,   538,   343,   353,   376,     0,   377,
       0,   402,     0,     0,   318,     0,     0,   321,     0,     0,
     431,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     1,     5,     7,
       0,     0,    12,    10,    14,    15,     0,   132,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,   173,
     169,   175,   170,   172,   171,   178,   179,     0,     0,     0,
       0,   308,     0,     0,   306,     0,   259,     0,   307,   300,
     305,   304,   303,   302,   301,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   296,   295,   292,     0,   316,   320,     0,
       0,     0,   330,   360,   333,   332,   344,   359,     0,     0,
     106,     0,     0,   501,     0,     0,     0,     0,     0,   493,
       0,     0,     0,     0,     0,   482,     0,   483,     0,   118,
       0,   119,   115,   114,   117,     0,    95,    96,    48,    49,
     533,    57,     0,     0,    42,    43,     0,     0,     0,     0,
       0,     0,     0,     0,   504,   505,   506,     0,     0,     0,
       0,   748,   749,     0,    47,   741,   742,   743,   744,   745,
     746,   747,    86,     0,     0,     0,     0,   484,     0,     0,
       0,    66,     0,     0,     0,    58,     0,   239,     0,     0,
       0,   191,   192,     0,     0,   156,   157,     0,     0,   177,
       0,     0,     0,   479,     0,     0,     0,   487,     0,     0,
       0,     0,   378,   403,   402,   399,     0,     0,   433,   432,
     317,   492,     0,   430,     0,   517,   518,   478,     0,     0,
       0,     0,     0,     0,   523,     0,     0,     0,   194,   211,
     110,   112,   111,     0,    18,     0,    20,   135,     0,     0,
       0,     0,     0,   155,   212,     0,     0,     0,     0,     0,
       0,     0,     0,   251,   253,   257,   263,   262,   261,     0,
     258,   255,   256,     0,     0,     0,   733,   265,   712,   720,
     722,   724,   726,   728,   731,   271,   270,   268,   274,   275,
     276,   273,   278,   279,   282,   281,     0,     0,     0,     0,
     313,     0,   325,   326,     0,   361,   382,   384,     0,   637,
       0,     0,     0,     0,   309,     0,     0,     0,     0,     0,
     497,     0,   494,   442,     0,   441,   450,   451,     0,     0,
       0,    46,     0,     0,     0,    74,     0,    70,    72,    73,
      77,    80,     0,     0,     0,    56,     0,     0,   750,   751,
       0,   752,   756,     0,     0,   785,   754,   755,   784,   753,
     757,     0,   764,   786,     0,     0,     0,   486,   485,   452,
       0,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   711,     0,     0,
     158,   159,     0,   164,   500,   480,   481,     0,     0,   490,
       0,   488,   446,     0,     0,   402,   400,     0,   391,     0,
     380,   381,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,   133,     0,   165,   223,   219,   221,     0,   213,
     214,     0,   542,   550,   458,   459,   465,   466,   468,     0,
     181,     0,     0,     0,     0,     0,     0,     0,   260,     0,
       0,   727,     0,   266,     0,   740,     0,     0,     0,     0,
       0,     0,     0,   713,   717,   735,   716,   739,   737,   736,
     738,     0,     0,     0,   729,   792,   790,   794,   732,   284,
     286,   288,   456,   290,   314,   362,     0,   383,   103,   102,
     107,     0,   311,   310,     0,     0,   245,     0,     0,     0,
     501,     0,     0,   443,     0,    97,     0,   123,   121,     0,
     120,     0,    54,    55,    52,    53,     0,    75,    76,    78,
       0,    79,    44,    45,    50,    51,    41,     0,     0,     0,
     759,     0,   758,   775,     0,     0,     0,   453,     0,    68,
      62,    65,    64,     0,    60,     0,   237,   241,     0,     0,
     105,     0,   196,     0,     0,     0,     0,     0,   160,     0,
       0,     0,     0,   205,     0,   202,   207,   163,     0,     0,
       0,   447,   238,   403,     0,   392,     0,   426,   423,     0,
     427,   428,     0,     0,   429,   422,     0,   397,   425,   424,
       0,     0,     0,   510,   511,   507,     0,     0,   515,   516,
     512,   521,   519,     0,     0,     0,   525,     0,   526,   527,
       0,     0,   220,   232,     0,   233,     0,   224,   225,   226,
     227,     0,   216,     0,   180,     0,     0,   462,   464,   463,
     460,   189,   190,   183,     0,   185,   182,     0,     0,     0,
     734,   730,     0,   787,   788,   808,   807,   803,     0,     0,
       0,     0,   789,   721,   802,   714,     0,     0,   719,   718,
     723,     0,     0,   793,   791,   457,   385,   312,     0,     0,
       0,   246,   444,     0,   498,   499,   502,   495,   496,   125,
       0,     0,    98,     0,   122,    71,    81,   773,     0,     0,
     771,   767,     0,     0,     0,    82,    83,     0,     0,   454,
       0,    67,     0,    61,   240,   242,    13,   193,   198,   197,
       0,   200,     0,     0,     0,   162,   203,   206,     0,   448,
       0,   491,   489,   402,     0,     0,   434,     0,   402,     0,
     398,     9,     0,     0,     0,     0,     0,   524,     0,     0,
     528,     0,   195,   236,   234,   235,   228,   229,   230,   222,
       0,   217,   215,   467,   461,   187,   184,     0,   186,   809,
       0,     0,   795,     0,   806,   805,   804,   799,   800,   715,
     725,   801,     0,     0,     0,     0,   445,   126,    99,   124,
       0,   128,     0,     0,   774,   776,   778,   780,     0,   772,
       0,     0,     0,   762,     0,   760,     0,     0,     0,     0,
     455,     0,    63,   199,   201,   210,   209,   204,   161,   449,
       0,   402,     0,   127,     0,   402,   508,   509,   513,   514,
     520,   522,     0,   710,   231,   218,   188,   797,   796,     0,
       0,   247,     0,   243,   100,   783,   782,   777,   781,   779,
     768,   769,     0,   765,     0,    93,    89,    91,     0,    87,
       0,   249,    69,     0,   412,   406,   401,     0,   402,   393,
       0,     0,     0,   798,     0,     0,     0,     0,   763,   761,
       0,    92,    94,    88,     0,   420,   414,     0,   413,   415,
     421,   418,   408,     0,   407,   409,   419,   395,     0,   394,
       0,   529,     0,   244,   770,   766,    90,   208,   405,   416,
     417,   404,   410,   411,   396,     0,   248,     0,     0,     0,
     530,     0,     0,     0,     0,   531,     0,     0,   532
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1022, -1022,   758, -1022,   757,   759, -1022,   755, -1022,   481,
     484,  -479, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022, -1022, -1022,  -823, -1022, -1022, -1022, -1022,
      -4,   188, -1022,   420, -1022, -1022, -1022,   579,  -334, -1022,
    -283, -1022,   197, -1022,  -734, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022,   224,   -36, -1022, -1022,  -163, -1022,  -890,   764,
     -80, -1022,   493,  -332, -1022, -1022, -1022, -1022,   139, -1022,
   -1022,   732, -1022, -1022, -1022, -1022, -1022,    93,  -472,  -619,
   -1022, -1022, -1022,   -23, -1022, -1022,  -193,   -37,   -81, -1022,
   -1022, -1022,   -96, -1022, -1022,   106,   -87, -1022, -1022,   -83,
   -1021, -1022,   552,    -6, -1022, -1022,    41, -1022, -1022,   495,
     488, -1022,  -466,  -884,   471,    95,  -519,    91,    92, -1022,
   -1022, -1022, -1022, -1022,   739, -1022, -1022, -1022, -1022, -1022,
     744, -1022, -1022,  -105, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022,   -38,  -197, -1022, -1022,  -166,    37, -1022,  -511, -1022,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,  -836, -1022,
     -32, -1022,   341,  -662, -1022, -1022, -1022, -1022, -1022,  -338,
    -331,  -984,  -891, -1022, -1022, -1022, -1022, -1022, -1022, -1022,
   -1022, -1022, -1022,   259,  -634,  -727, -1022,   226,  -117,  -679,
   -1022, -1022, -1022, -1022, -1022, -1022, -1022,   582,   585,  -596,
     240, -1022, -1022, -1022, -1022, -1022, -1022, -1022, -1022,   -52,
   -1022, -1022,   -54,  -402,  -383,   -13, -1022,   291, -1022, -1022,
      97,    86,  -102,   298, -1022, -1022,   101, -1022,  -692, -1022,
   -1022, -1022, -1022,  -229,  -797, -1022,  -124,  -607, -1022,  -678,
   -1022, -1022, -1022, -1022,  -923, -1022, -1022, -1022, -1022,   -89,
     108, -1022
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   999,   634,   234,   235,   787,
     788,   789,   598,   236,  1157,   237,   414,   415,  1305,  1306,
    1257,   238,   779,   239,   336,   559,   240,   241,   242,   243,
     244,   245,   416,   417,   581,   966,   967,  1044,   970,   246,
     247,   488,   248,   249,   250,   498,   433,   842,   843,   251,
     499,   252,   501,   253,   254,   255,   505,   506,  1023,   711,
     256,   641,   687,   642,   648,  1024,  1025,  1026,   688,   502,
     503,   889,   890,  1211,   504,   886,   887,  1077,  1078,  1079,
    1080,   257,   636,   637,   258,   955,   956,   259,   260,   261,
     262,   719,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   525,   526,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   552,   553,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   758,   303,   304,   305,
    1046,   664,   665,   666,  1316,  1343,  1344,  1337,  1338,  1345,
    1339,  1047,  1048,   306,   307,  1049,   308,   309,   310,   311,
     312,   313,   314,   941,   712,   894,  1090,   895,   896,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   562,
     959,   325,   326,   327,   328,   329,   330,   331,   683,   684,
     332,  1068,  1069,  1000,   422,   333,   334,   727,   923,   728,
     729,   730,   731,   732,   733,   734,   924,   925,   614,   615,
     616,   617,   618,  1302,  1303,   619,  1244,  1150,  1248,  1245,
     620,   621,   927,   938,  1111,   928,   929,   934,   930,  1227,
    1107,   913
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       388,   591,   857,  1004,   830,   560,   696,   992,   561,   836,
    1122,   623,   738,   739,   740,   741,   726,   457,   450,   939,
     940,   631,   635,  1045,   835,   445,   603,   897,   950,   394,
     395,   396,   397,   398,   399,   710,   926,  1115,   628,   459,
       4,   668,   400,   639,   715,  1298,   716,   717,   439,   718,
     446,   720,   839,   706,   607,   707,   706,  1207,  1208,   721,
     722,  1014,  1190,  1154,   447,   590,   706,   897,   897,   864,
     769,   690,   691,   692,   480,   707,  1108,   875,  1234,   590,
     879,  1108,   335,  1314,   481,   827,   451,   651,   406,   407,
     862,   903,   419,   907,   626,   827,   528,   644,   771,   486,
     455,   486,   834,   708,  1220,   897,   456,   394,   395,   396,
     397,   398,   399,   529,   341,   880,   829,    69,   337,  1103,
     400,   858,   555,   905,   652,   462,   401,   463,   557,    80,
     675,   676,   800,   678,   679,   680,   681,   402,   403,   686,
     489,   404,  1235,   848,   405,   868,   770,   490,   863,   419,
     491,   492,  1104,    94,   697,   902,   979,   723,   493,   632,
     724,  1097,   828,   340,   703,   704,   406,   407,   408,  1315,
     342,  1221,   854,   958,   772,   961,   548,  1155,  1156,   487,
    1163,   882,  1037,  1038,   709,  1284,   859,   840,   608,   630,
     865,   866,   669,  1034,  1153,  1299,   609,  1037,  1038,   795,
    1045,  1190,   876,   633,  1017,   867,   465,   850,   466,   610,
    1045,   611,   409,   726,   726,   460,   345,  1015,   411,   849,
     841,   612,   709,   653,   613,   709,   757,  1129,  1251,  1109,
    1110,  1119,   825,  1229,  1109,  1110,  1035,  1144,   343,   344,
     906,   507,   709,   494,   627,   495,  1250,   821,   554,   946,
     824,   556,  1029,   908,  1030,  1242,   412,   413,   964,   496,
     725,   801,   564,  1141,  1039,   567,   869,   870,   420,  1252,
     338,   421,   410,   446,   709,   897,   446,     4,   339,  1039,
     709,   871,  1040,   851,  1041,   497,  1148,  1098,  1254,  1308,
     802,   803,   568,   804,   805,  1321,   411,  1040,  1327,  1041,
     706,  1036,   390,  1327,  1308,   391,  1367,  1037,  1038,   573,
     574,  1042,   576,   430,   431,    99,   989,  1372,  1243,  1037,
    1038,   389,   588,   965,   546,   947,  1042,   599,   563,  1074,
      99,   111,   600,   990,   412,   413,   989,  1335,   624,  1142,
     625,  1037,   535,  1149,   528,  1253,   111,   113,  1076,  1045,
    1016,   536,  1043,  1152,    69,   589,   432,   656,  1335,   579,
     571,   529,  1037,   584,  1255,  1309,    80,  1184,  1087,   885,
     138,  1322,   667,   991,  1328,   418,   900,  1326,   672,  1329,
    1333,   578,  1368,   425,   530,   138,   601,   585,  1037,  1039,
      94,   982,   983,  1373,   723,   986,   784,   724,  1088,  1341,
     531,  1039,   696,  1116,  1224,   935,   936,  1040,   726,  1041,
    1225,   972,   638,  1238,   640,   643,  1089,   974,  1226,  1040,
     726,  1041,   650,  1340,  1346,   659,   532,   937,   973,  1009,
    1019,  1020,  1351,   426,   975,   638,  1042,   785,  1312,   533,
      99,  1040,   786,  1041,   752,   753,   602,  1340,  1042,   707,
     592,  1336,    99,  1346,   978,   427,   111,   685,  1037,   689,
     981,   897,  1040,  1073,  1041,   593,   751,   586,   111,  1341,
    1042,   754,  1359,   534,  1074,   468,   428,  1189,  1370,   761,
     469,   587,   994,  1375,  1075,   765,   766,  1378,  1040,  1272,
    1041,  1042,   774,  1076,   594,   138,  1006,  1007,   537,  1342,
    1010,   968,  1012,   549,   550,  1237,   954,   138,   595,  1019,
    1020,   538,  1021,  1294,   535,   429,   969,  1042,  1289,  1130,
     535,  1270,  1032,   536,   809,   435,  1274,   791,   707,   536,
    1355,   785,   792,  1053,  1054,  1055,   786,  1058,  1059,  1060,
    1061,  1062,  1063,   392,  1065,  1066,   393,   434,   914,   820,
    1022,   885,   607,   810,   811,   436,   812,   813,  1040,  1105,
    1041,   897,  1224,  1324,  1106,   448,  1297,   780,  1225,  1362,
    1093,  1297,  1095,  1096,   984,   985,  1226,   394,   395,   396,
     853,   452,   399,  1219,   790,   423,   453,  1042,   424,   755,
    1222,  1223,   755,   458,   755,   798,  1161,   806,   799,  1051,
     807,  1052,   914,   604,   605,   606,   607,  1019,  1020,  1317,
     726,   897,   461,  1320,  1126,   464,  1056,   915,  1057,  1204,
    1205,   582,   583,   735,   736,   467,   742,   743,   470,   744,
     745,   942,   942,   471,   838,  1295,  1296,   472,   477,   473,
     474,   475,   484,   909,   485,   508,   509,   527,  1146,   539,
     855,   541,   540,   542,   551,   558,  1348,   565,   566,   572,
     575,   577,   394,  1158,   580,   590,   596,   597,   419,   413,
     629,   915,  1203,  1331,   645,   647,  1165,   646,   649,   660,
     373,  1168,  1169,   951,  1171,   391,   608,   884,   393,  1175,
     421,   438,   663,   898,   609,   662,   916,   917,   918,   670,
     673,  1287,  1288,   674,   682,   671,   919,   610,   695,   611,
     699,   677,   700,   701,   920,   702,   705,   746,   747,   612,
     921,   922,   613,   748,   749,   762,   763,   764,   767,   781,
     778,   793,   768,   898,   898,   898,   898,   794,  1201,   796,
     608,   775,   782,   776,   777,   783,   797,   808,   609,   885,
     916,   917,   918,   814,   815,   816,   960,   822,   960,   823,
    1262,   610,  1215,   611,   817,  1216,   818,  1218,   920,   826,
    1323,   898,   831,   612,  1117,   922,   613,   837,   510,   832,
     872,   833,   844,   845,   846,   847,   511,   512,   860,   513,
     873,   861,   874,   877,   881,   878,   514,   888,   883,   891,
     515,   899,   516,   901,   904,   407,   912,   517,  1285,   931,
     948,   933,   957,   944,   706,   945,   949,   954,   932,   996,
     952,   953,   786,   518,   963,   997,  1003,   980,   988,   998,
    1002,  1005,  1001,  1008,  1011,   563,  1018,   563,  1263,   987,
    1264,   993,  1013,   995,  1028,  1031,  1268,   519,   520,   521,
     522,   523,   524,  1033,  1050,  1064,  1067,  1070,  1071,  1081,
    1276,  1277,  1278,  1279,  1280,  1083,  1281,  1094,  1085,  1099,
    1100,  1086,  1121,  1124,  1101,  1082,  1102,  1133,   507,  1123,
    1125,  1127,  1140,  1136,  1151,  1286,  1091,  1134,  1092,  1143,
    1147,  1112,  1135,  1137,  1138,  1166,  1162,  1170,  1172,  1173,
    1174,  1291,  1178,  1293,  1181,  1182,  1183,  1186,  1192,  1198,
    1193,  1191,  1199,  1217,  1194,  1074,  1160,  1210,  1195,  1213,
     964,  1231,  1214,  1240,  1307,  1233,  1196,  1311,  1356,  1236,
    1241,  1246,  1247,  1256,  1258,  1260,  1259,  1261,  1290,  1300,
    1269,   898,  1273,  1283,   989,  1313,  1319,  1325,  1180,  1330,
    1334,  1139,  1350,  1301,  1347,   969,  1352,  1349,  1358,  1354,
    1369,  1364,  1187,  1361,  1374,   693,  1377,   476,   694,   478,
     482,   479,  1145,   977,  1332,  1310,  1307,   971,  1239,   760,
     483,   698,  1027,  1267,  1084,   500,  1177,  1212,  1167,  1072,
    1202,   622,   638,  1353,  1209,  1206,  1131,   714,   643,  1164,
     661,   737,  1282,   713,  1185,   856,  1363,  1360,   943,  1176,
     976,   962,  1197,   545,  1200,   910,  1113,  1120,   654,  1230,
    1366,   655,   547,   911,  1118,  1304,  1249,  1228,  1114,     0,
    1188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   685,     0,     0,     0,     0,     0,     0,   689,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   898,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1265,  1266,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1271,     0,     0,     0,     0,  1275,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1292,     0,     0,     0,     0,     0,   898,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1318,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   898,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1357,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1365,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     2,     3,  1371,     4,     0,     0,
       0,  1376,     0,     5,     6,     7,     8,     9,    10,    11,
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
     201,   202,   203,   204,   205,   206,   207,   208,   209,     1,
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
       0,     0,   114,   115,   116,     0,     0,     0,   117,   449,
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
     113,     0,     0,   114,   115,   116,     0,   750,     0,   117,
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
     112,   113,     0,     0,   114,   115,   116,     0,     0,     0,
     117,   756,   118,   119,   120,     0,   121,   122,   123,     0,
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
       0,   112,   113,     0,     0,   114,   115,   116,     0,   773,
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
     819,     0,   117,     0,   118,   119,   120,     0,   121,   122,
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
      15,    16,   357,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   360,    28,    29,   362,    31,    32,    33,     0,
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
       0,   852,     0,   117,     0,   118,   119,   120,     0,   121,
     122,   123,     0,   124,     0,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,   136,   137,
     138,     0,   376,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,   178,   179,     0,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,     1,     0,     0,     0,     0,
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
     116,     0,  1132,     0,   117,     0,   118,   119,   120,     0,
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
     115,   116,     0,  1159,     0,   117,     0,   118,   119,   120,
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
     114,   115,   116,     0,  1179,     0,   117,     0,   118,   119,
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
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
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
       0,   114,   115,   116,     0,     0,     0,   117,     0,   118,
     119,   120,     0,   121,   122,   123,     0,   124,     0,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,   136,   137,   138,     0,   139,   140,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,   178,   179,     0,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,    34,    35,    36,    37,    38,
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
       0,     0,   114,   115,   116,     0,     0,     0,   117,     0,
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
     113,     0,     0,   114,   115,   116,     0,     0,     0,   117,
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
       0,     4,     0,     0,     0,     0,     0,   346,   347,   348,
       8,   349,   350,    11,   352,    13,    14,    15,    16,   357,
      18,    19,    20,    21,    22,    23,   358,    25,    26,   360,
     361,    29,   362,    31,    32,    33,     0,   363,   364,    36,
     365,   366,   367,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,     0,    67,    68,     0,     0,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
      80,     0,    81,    82,    83,    84,     0,    85,     0,     0,
       0,   371,    87,    88,    89,    90,     0,     0,     0,     0,
       0,    91,    92,    93,    94,    95,    96,    97,     0,     0,
       0,    98,    99,   543,   101,   102,     0,     0,     0,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,     0,
     544,   113,     0,     0,   114,   115,   116,     0,     0,     0,
     117,     0,   118,   119,   120,     0,   121,   122,   123,     0,
     124,     0,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,     0,     0,   136,   137,   138,     0,   376,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   377,
     149,   379,   151,   380,   381,   154,   155,   156,   157,   158,
     159,   382,   161,   383,   163,   384,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,     0,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   385,   386,   387,   204,   205,   206,
     207,   208,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     0,   346,   347,
     348,     8,   349,   350,    11,   352,    13,    14,    15,    16,
     357,    18,    19,    20,    21,    22,    23,   358,    25,    26,
     360,   361,    29,   362,    31,    32,    33,     0,   363,   364,
      36,   365,   366,   367,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,     0,    67,    68,     0,     0,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,    80,     0,    81,    82,    83,    84,     0,    85,     0,
       0,     0,   371,    87,    88,    89,    90,     0,     0,     0,
       0,     0,    91,    92,    93,    94,    95,    96,    97,     0,
       0,     0,    98,    99,   100,   101,   102,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
       0,   112,   113,     0,     0,   114,   115,   116,     0,     0,
       0,   117,     0,   118,   119,   120,     0,   121,   122,   123,
       0,   124,     0,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,   136,   137,   138,     0,
     376,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     377,   149,   379,   151,   380,   381,   154,   155,   156,   157,
     158,   159,   382,   161,   383,   163,   384,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
       0,   178,   179,     0,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   385,   386,   387,   204,   205,
     206,   207,   208,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   759,    18,    19,    20,    21,    22,    23,    24,    25,
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
       0,     0,   117,     0,   118,   119,   120,     0,   121,   122,
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
     346,   347,   348,     8,   349,   350,   351,   352,    13,    14,
      15,    16,   357,    18,    19,    20,    21,    22,    23,   358,
      25,    26,   360,   361,    29,   362,    31,    32,    33,     0,
     363,   364,    36,   365,   366,   367,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     0,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,     0,    67,    68,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,    80,     0,    81,    82,    83,    84,     0,
      85,     0,     0,     0,   371,    87,    88,    89,    90,     0,
       0,     0,     0,     0,    91,    92,    93,    94,    95,    96,
      97,     0,     0,     0,    98,    99,     0,   101,   102,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,     0,     0,     0,     0,     0,   114,   115,   116,
       0,     0,     0,   117,     0,   118,   119,   120,     0,     0,
       0,   123,     0,   124,     0,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,   136,   137,
     138,     0,   376,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   377,   149,   379,   151,   380,   381,   154,   155,
     156,   157,   158,   159,   382,   161,   383,   163,   384,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,   178,   179,     0,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   385,   386,   387,
     204,   205,   206,   207,   208,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
       0,   346,   347,   348,     8,   349,   350,   351,   352,   440,
     354,   441,   442,   357,    18,    19,    20,    21,    22,    23,
     358,   443,    26,   360,   361,    29,   362,    31,    32,    33,
       0,   363,   364,    36,   365,   366,   367,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,     0,     0,    57,     0,    58,    59,    60,   444,
       0,     0,    64,    65,    66,     0,     0,     0,    68,     0,
       0,     0,     0,    70,    71,    72,     0,     0,    75,    76,
       0,     0,     0,     0,     0,     0,    81,    82,    83,    84,
       0,    85,     0,     0,     0,   371,    87,    88,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,     0,    95,
      96,    97,     0,     0,     0,     0,     0,     0,   101,   102,
       0,     0,     0,     0,   103,   104,   105,   374,   107,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,     0,     0,     0,   117,     0,   118,   119,     0,     0,
       0,     0,   123,     0,   124,     0,   125,   126,   127,   128,
     375,   130,   131,   132,   133,   134,   135,     0,     0,   136,
     137,     0,     0,   376,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   377,   149,   379,   151,   380,   381,   154,
     155,   156,   157,   158,   159,   382,   161,   383,   163,   384,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,     0,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   385,   386,
     387,   204,   205,   206,   207,   208,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     0,     0,     0,     0,
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
       0,     0,     0,   123,     0,   124,     0,   125,   126,   127,
     128,   375,   130,   131,   132,   133,   134,   135,     0,     0,
     136,   137,     0,     0,   376,   140,     0,   141,   142,   143,
     144,   145,   146,   147,   377,   378,   379,   151,   380,   381,
     154,   155,   156,   157,   158,   159,   382,   161,   383,   163,
     384,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   178,   179,     0,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   385,
     386,   387,   204,   205,   206,   207,   208,   454,     0,     3,
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
     117,     0,   118,     0,     0,     0,     0,     0,     0,     0,
     124,     0,   125,   126,   127,   128,   375,   130,   131,   132,
     133,   134,   135,     0,     0,   136,   137,     0,     0,   376,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   377,
     378,   379,   151,   380,   381,   154,   155,   156,   157,   158,
     159,   382,   161,   383,   163,   384,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,     0,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   385,   386,   387,   204,   205,   206,
     207,   208,     3,     0,     0,     0,     0,     0,     0,     0,
     346,   347,   348,     8,   349,   350,   351,   352,   353,   354,
     355,   356,   357,    18,    19,    20,    21,    22,    23,   358,
     359,    26,   360,   361,    29,   362,    31,    32,    33,     0,
     363,   364,    36,   365,   366,   367,    40,    41,    42,    43,
      44,    45,    46,    47,    48,   368,   369,    51,    52,    53,
      54,     0,     0,    57,     0,    58,    59,    60,   370,     0,
       0,    64,    65,    66,     0,     0,     0,    68,     0,     0,
       0,     0,    70,    71,    72,     0,     0,    75,    76,     0,
       0,     0,     0,     0,     0,    81,    82,    83,    84,     0,
      85,     0,     0,     0,   371,    87,    88,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,     0,    95,    96,
      97,   372,     0,     0,   373,     0,     0,   101,   102,     0,
       0,     0,     0,   103,   104,   105,   374,   107,   108,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,   117,     0,   118,     0,     0,     0,     0,
       0,     0,     0,   124,     0,   125,   126,   127,   128,   375,
     130,   131,   132,   133,   134,   135,     0,     0,   136,   137,
       0,     0,   376,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   377,   378,   379,   151,   380,   381,   154,   155,
     156,   157,   158,   159,   382,   161,   383,   163,   384,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,   178,   179,     0,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   385,   386,   387,
     204,   205,   206,   207,   208,     3,     0,     0,     0,     0,
       0,     0,     0,   346,   347,   348,     8,   349,   350,   351,
     352,   353,   354,   355,   356,   357,    18,    19,    20,    21,
      22,    23,   358,   359,    26,   360,   361,    29,   362,    31,
      32,    33,     0,   363,   364,    36,   365,   366,   367,    40,
      41,    42,    43,    44,    45,    46,    47,    48,   368,   369,
      51,    52,    53,    54,     0,     0,    57,     0,    58,    59,
      60,   370,     0,     0,    64,    65,    66,     0,     0,     0,
      68,     0,     0,     0,     0,    70,    71,    72,     0,     0,
      75,    76,     0,     0,     0,     0,     0,     0,    81,    82,
      83,    84,     0,    85,     0,     0,     0,   371,    87,    88,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
       0,    95,    96,    97,   437,     0,     0,   438,     0,     0,
     101,   102,     0,     0,     0,     0,   103,   104,   105,   374,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,   117,     0,   118,     0,
       0,     0,     0,     0,     0,     0,   124,     0,   125,   126,
     127,   128,   375,   130,   131,   132,   133,   134,   135,     0,
       0,   136,   137,     0,     0,   376,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   377,   378,   379,   151,   380,
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
     569,   118,     0,     0,     0,     0,     0,   570,     0,   124,
       0,   125,   126,   127,   128,   375,   130,   131,   132,   133,
     134,   135,     0,     0,   136,   137,     0,     0,   376,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   377,   378,
     379,   151,   380,   381,   154,   155,   156,   157,   158,   159,
     382,   161,   383,   163,   384,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,   178,
     179,     0,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   385,   386,   387,   204,   205,   206,   207,
     208,     3,     0,     0,     0,     0,     0,     0,     0,   346,
     347,   348,     8,   349,   350,   351,   352,   353,   354,   355,
     356,   357,    18,    19,    20,    21,    22,    23,   358,   359,
      26,   360,   361,    29,   362,    31,    32,    33,     0,   363,
     364,    36,   365,   366,   367,    40,    41,    42,    43,    44,
      45,    46,    47,    48,   368,   369,    51,    52,    53,    54,
       0,     0,    57,     0,    58,    59,    60,   370,     0,     0,
      64,    65,    66,     0,     0,     0,    68,     0,     0,     0,
       0,    70,    71,    72,     0,     0,    75,    76,     0,     0,
       0,     0,     0,     0,    81,    82,    83,    84,     0,    85,
       0,     0,     0,   371,    87,    88,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,     0,    95,    96,    97,
       0,     0,     0,     0,     0,     0,   101,   102,     0,     0,
       0,     0,   103,   104,   105,   374,   107,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116,     0,
       0,     0,   117,   657,   118,     0,     0,     0,     0,     0,
     658,     0,   124,     0,   125,   126,   127,   128,   375,   130,
     131,   132,   133,   134,   135,     0,     0,   136,   137,     0,
       0,   376,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   377,   378,   379,   151,   380,   381,   154,   155,   156,
     157,   158,   159,   382,   161,   383,   163,   384,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,   179,     0,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   385,   386,   387,   204,
     205,   206,   207,   208,     3,     0,     0,     0,     0,     0,
       0,     0,   346,   347,   348,     8,   349,   350,   351,   352,
     440,   354,   441,   442,   357,    18,    19,    20,    21,    22,
      23,   358,   443,    26,   360,   361,    29,   362,    31,    32,
      33,     0,   363,   364,    36,   365,   366,   367,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,     0,     0,    57,     0,    58,    59,    60,
     444,     0,     0,    64,    65,    66,     0,     0,     0,    68,
       0,     0,     0,     0,    70,    71,    72,     0,     0,    75,
      76,  1128,     0,     0,     0,     0,     0,    81,    82,    83,
      84,     0,    85,     0,     0,     0,   371,    87,    88,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,     0,
      95,    96,   892,     0,     0,     0,     0,     0,     0,   101,
     102,     0,     0,     0,     0,   103,   104,   105,   374,   107,
     108,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,     0,     0,     0,   117,     0,   118,   119,     0,
       0,     0,     0,     0,     0,   124,     0,   125,   126,   127,
     128,   375,   130,   131,   132,   133,   134,   135,     0,     0,
     893,   137,     0,     0,   376,   140,     0,   141,   142,   143,
     144,   145,   146,   147,   377,   149,   379,   151,   380,   381,
     154,   155,   156,   157,   158,   159,   382,   161,   383,   163,
     384,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   178,   179,     0,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   385,
     386,   387,   204,   205,   206,   207,   208,     3,     0,     0,
       0,     0,     0,     0,     0,   346,   347,   348,     8,   349,
     350,   351,   352,   440,   354,   441,   442,   357,    18,    19,
      20,    21,    22,    23,   358,   443,    26,   360,   361,    29,
     362,    31,    32,    33,     0,   363,   364,    36,   365,   366,
     367,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,     0,     0,    57,     0,
      58,    59,    60,   444,     0,     0,    64,    65,    66,     0,
       0,     0,    68,     0,     0,     0,     0,    70,    71,    72,
       0,     0,    75,    76,     0,     0,     0,     0,     0,     0,
      81,    82,    83,    84,     0,    85,     0,     0,     0,   371,
      87,    88,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,     0,    95,    96,   892,     0,     0,     0,     0,
       0,     0,   101,   102,     0,     0,     0,     0,   103,   104,
     105,   374,   107,   108,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,   117,     0,
     118,   119,     0,     0,     0,     0,     0,     0,   124,     0,
     125,   126,   127,   128,   375,   130,   131,   132,   133,   134,
     135,     0,     0,   893,   137,     0,     0,   376,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   377,   149,   379,
     151,   380,   381,   154,   155,   156,   157,   158,   159,   382,
     161,   383,   163,   384,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,   178,   179,
       0,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   385,   386,   387,   204,   205,   206,   207,   208,
       3,     0,     0,     0,     0,     0,     0,     0,   346,   347,
     348,     8,   349,   350,   351,   352,   440,   354,   441,   442,
     357,    18,    19,    20,    21,    22,    23,   358,   443,    26,
     360,   361,    29,   362,    31,    32,    33,     0,   363,   364,
      36,   365,   366,   367,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,     0,
       0,    57,     0,    58,    59,    60,   444,     0,     0,    64,
      65,    66,     0,     0,     0,    68,     0,     0,     0,     0,
      70,    71,    72,     0,     0,    75,    76,     0,     0,     0,
       0,     0,     0,    81,    82,    83,    84,     0,    85,     0,
       0,     0,   371,    87,    88,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,     0,    95,    96,   892,     0,
       0,     0,     0,     0,     0,   101,   102,     0,     0,     0,
       0,   103,   104,   105,   374,   107,   108,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,     0,     0,
       0,   117,     0,   118,   119,     0,     0,     0,     0,     0,
       0,   124,     0,   125,   126,   127,   128,   375,   130,   131,
     132,   133,   134,   135,     0,     0,   136,   137,     0,     0,
     376,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     377,   149,   379,   151,   380,   381,   154,   155,   156,   157,
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
     116,     0,     0,     0,   117,     0,   118,     0,     0,     0,
       0,     0,     0,     0,   124,     0,   125,   126,   127,   128,
     375,   130,   131,   132,   133,   134,   135,     0,     0,   136,
     137,     0,     0,   376,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   377,   378,   379,   151,   380,   381,   154,
     155,   156,   157,   158,   159,   382,   161,   383,   163,   384,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,     0,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   385,   386,
     387,   204,   205,   206,   207,   208
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        13,   403,   664,   826,   638,   337,   485,   804,   340,   643,
     933,   413,   531,   532,   533,   534,   527,   122,    98,   746,
     747,   423,   424,   859,   643,    63,   409,   706,   762,    39,
      40,    41,    42,    43,    44,   507,   728,   921,   421,    21,
      20,     7,    52,   426,   510,    20,   512,   513,    61,   515,
      63,   517,    66,    81,    87,    83,    81,  1078,  1079,   525,
     526,   127,  1046,   154,    77,    20,    81,   746,   747,    81,
      94,   473,   474,   475,    38,    83,    83,    94,   105,    20,
      59,    83,   137,    80,    48,    94,    99,    34,    98,    99,
     116,   710,    18,   712,    20,    94,   142,   429,    94,    94,
     113,    94,   127,   131,    47,   784,   119,    39,    40,    41,
      42,    43,    44,   159,    81,    94,   131,    97,   221,   201,
      52,   115,   288,   131,    71,   209,    58,   211,   294,   109,
     462,   463,   100,   465,   466,   467,   468,    69,    70,   471,
      50,    73,   169,    94,    76,    81,   170,    57,   174,    18,
      60,    61,   234,   133,   486,   131,   790,   137,    68,   100,
     140,   131,   171,   140,   496,   497,    98,    99,   100,   166,
     137,   114,   171,   769,   170,   771,   281,   268,   269,   174,
    1003,   174,     8,     9,   250,  1206,   180,   201,   221,   144,
     202,   203,   158,   855,   991,   170,   229,     8,     9,   601,
    1036,  1185,   219,   144,   838,   217,   209,    94,   211,   242,
    1046,   244,   144,   724,   725,   197,   140,   836,   228,   170,
     234,   254,   250,   170,   257,   250,   558,   954,  1151,   236,
     237,   923,   634,  1117,   236,   237,   115,   971,   205,   206,
     712,   254,   250,   153,   170,   155,   248,   630,   286,    94,
     633,   289,   848,   719,   850,   121,   266,   267,   105,   169,
     240,   229,   342,    94,    90,   345,   202,   203,   137,    94,
      29,   140,   204,   286,   250,   954,   289,    20,    29,    90,
     250,   217,   108,   170,   110,   195,    83,   906,    94,    94,
     258,   259,   372,   261,   262,    94,   228,   108,    94,   110,
      81,   180,   137,    94,    94,   140,    94,     8,     9,   389,
     390,   137,   392,    62,    63,   141,    83,    94,   184,     8,
       9,   137,   152,   170,   137,   170,   137,    34,   341,    93,
     141,   157,    39,   100,   266,   267,    83,     4,   418,   170,
     420,     8,   184,   140,   142,   170,   157,   160,   112,  1185,
     131,   193,   178,   100,    97,   185,   105,   437,     4,   395,
     373,   159,     8,   399,   170,   170,   109,   178,   129,   701,
     196,   170,   452,   140,   170,   140,   708,  1300,   458,   170,
     170,   394,   170,   105,   182,   196,    93,   400,     8,    90,
     133,   793,   794,   170,   137,   797,    81,   140,   159,    19,
     104,    90,   881,   922,   246,   225,   226,   108,   919,   110,
     252,   132,   425,  1140,   427,   428,   177,   132,   260,   108,
     931,   110,   435,  1314,  1315,   438,   130,   247,   149,   831,
      64,    65,  1322,   144,   149,   448,   137,   122,  1261,   143,
     141,   108,   127,   110,   549,   550,   153,  1338,   137,    83,
     150,   118,   141,  1344,   786,   105,   157,   470,     8,   472,
     792,  1140,   108,    82,   110,   165,   546,   165,   157,    19,
     137,   551,   118,   177,    93,   209,   105,   178,  1368,   559,
     214,   179,   814,  1373,   103,   565,   566,  1377,   108,   178,
     110,   137,   572,   112,   165,   196,   828,   829,   121,   119,
     832,   122,   834,   175,   176,  1139,    87,   196,   179,    64,
      65,   134,    67,  1240,   184,   137,   137,   137,   182,   100,
     184,  1183,   854,   193,   229,   140,  1188,   122,    83,   193,
    1327,   122,   127,   865,   866,   867,   127,   869,   870,   871,
     872,   873,   874,   137,   876,   877,   140,    60,    83,   629,
     105,   883,    87,   258,   259,   140,   261,   262,   108,   246,
     110,  1240,   246,  1290,   251,   105,  1244,   580,   252,   119,
     902,  1249,   904,   905,   113,   114,   260,    39,    40,    41,
     660,   137,    44,  1102,   597,    51,    14,   137,    54,   552,
    1109,  1110,   555,   137,   557,   227,   998,   227,   230,   216,
     230,   218,    83,   205,   206,   207,    87,    64,    65,  1271,
    1121,  1290,   199,  1275,   946,   140,   216,   152,   218,   113,
     114,   397,   398,   528,   529,   209,   535,   536,   105,   537,
     538,   748,   749,   137,   647,  1242,  1243,   105,     0,   267,
     267,   267,   174,   723,   174,   151,    79,   239,   980,    74,
     663,    88,   183,    89,   138,   140,  1318,   137,   137,   137,
     170,   170,    39,   995,    39,    20,   136,   105,    18,   267,
     137,   152,  1074,  1307,   256,   105,  1008,   256,   105,   137,
     140,  1013,  1014,   763,  1016,   140,   221,   700,   140,  1021,
     140,   140,    25,   706,   229,   170,   231,   232,   233,    15,
     197,  1220,  1221,    20,   215,   170,   241,   242,    38,   244,
     153,   170,   105,   154,   249,   154,    94,   215,    81,   254,
     255,   256,   257,    81,    81,   170,   137,   167,   170,    20,
     140,   144,   167,   746,   747,   748,   749,   144,  1070,   112,
     221,   167,    94,   167,   167,    94,   117,    20,   229,  1081,
     231,   232,   233,   270,   170,   167,   769,    83,   771,    34,
    1162,   242,  1094,   244,   170,  1097,   170,  1099,   249,    83,
    1289,   784,   117,   254,   255,   256,   257,   167,   117,   127,
      81,    94,   170,   170,   170,   167,   125,   126,   167,   128,
     221,   167,   209,   127,   174,   167,   135,   105,   154,   105,
     139,   105,   141,   105,   131,    99,   257,   146,  1210,   238,
     174,   245,   137,   167,    81,   168,   167,    87,   240,   137,
     167,   167,   127,   162,   167,   167,    83,   127,   260,   117,
     117,   105,   144,   131,   105,   848,   234,   850,  1170,   259,
    1172,   260,   127,   181,   137,   167,  1178,   186,   187,   188,
     189,   190,   191,    25,    20,   105,   223,   137,   105,    94,
    1192,  1193,  1194,  1195,  1196,    94,  1198,   131,   140,   131,
     167,   140,   131,    53,   170,   888,   235,   957,   891,   260,
     129,   167,    81,   129,    20,  1217,   899,   170,   901,   969,
     260,   235,   170,   170,   170,   174,    94,   127,   131,   105,
     105,  1233,    67,  1235,   170,   170,   117,     6,   217,   169,
     217,   174,   140,   131,   217,    93,   996,    93,   217,   170,
     105,   253,   170,    81,  1256,   169,   221,  1259,  1330,   167,
     167,    20,    20,   140,   154,   167,   111,    83,    81,    20,
     167,   954,   167,   167,    83,    65,   180,   169,  1028,    93,
     105,   964,   105,   243,   180,   137,   169,   180,    80,   243,
     105,   180,  1042,   166,   105,   484,   170,   209,   484,   212,
     215,   212,   976,   785,  1308,  1258,  1308,   780,  1141,   559,
     216,   488,   843,  1176,   891,   253,  1023,  1083,  1011,   883,
    1071,   412,  1005,  1325,  1081,  1078,   955,   509,  1011,  1005,
     448,   530,  1199,   508,  1036,   664,  1344,  1338,   749,  1022,
     784,   771,  1064,   274,  1068,   724,   919,   931,   436,  1121,
    1352,   436,   278,   725,   923,  1254,  1150,  1116,   920,    -1,
    1043,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1064,    -1,    -1,    -1,    -1,    -1,    -1,  1071,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1173,  1174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1184,    -1,    -1,    -1,    -1,  1189,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1234,    -1,    -1,    -1,    -1,    -1,  1240,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1272,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1290,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1350,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,  1369,    20,    -1,    -1,
      -1,  1374,    -1,    26,    27,    28,    29,    30,    31,    32,
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
     263,   264,   265,   266,   267,   268,   269,   270,   271,    10,
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
      -1,    -1,   163,   164,   165,    -1,    -1,    -1,   169,   170,
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
     159,   160,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,
     169,   170,   171,   172,   173,    -1,   175,   176,   177,    -1,
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
      -1,   167,    -1,   169,    -1,   171,   172,   173,    -1,   175,
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
     165,    -1,   167,    -1,   169,    -1,   171,   172,   173,    -1,
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
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    -1,   159,   160,
      -1,    -1,   163,   164,   165,    -1,    -1,    -1,   169,    -1,
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
     160,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,   169,
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
     159,   160,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,
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
      -1,   159,   160,    -1,    -1,   163,   164,   165,    -1,    -1,
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
     136,    -1,    -1,    -1,   140,   141,    -1,   143,   144,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,
      -1,    -1,    -1,   169,    -1,   171,   172,   173,    -1,    -1,
      -1,   177,    -1,   179,    -1,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,   194,   195,
     196,    -1,   198,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,    -1,   239,   240,    -1,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   177,    -1,   179,    -1,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,   194,
     195,    -1,    -1,   198,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,    -1,   239,   240,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   177,    -1,   179,    -1,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
     194,   195,    -1,    -1,   198,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,    -1,   239,   240,    -1,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,    16,    -1,    18,
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
     136,   137,    -1,    -1,   140,    -1,    -1,   143,   144,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,
      -1,    -1,    -1,   169,    -1,   171,    -1,    -1,    -1,    -1,
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
      -1,   134,   135,   136,   137,    -1,    -1,   140,    -1,    -1,
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
     170,   171,    -1,    -1,    -1,    -1,    -1,   177,    -1,   179,
      -1,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,   194,   195,    -1,    -1,   198,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,    -1,   239,
     240,    -1,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
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
      -1,    -1,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,
     177,    -1,   179,    -1,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,   194,   195,    -1,
      -1,   198,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,    -1,   239,   240,    -1,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    79,    -1,    81,    82,    83,
      84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    98,    99,   100,    -1,    -1,   103,
     104,   105,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,    -1,   116,    -1,    -1,    -1,   120,   121,   122,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,    -1,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   165,    -1,    -1,    -1,   169,    -1,   171,   172,    -1,
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
     131,   132,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,   169,    -1,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,
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
      -1,    -1,   130,   131,   132,    -1,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,
      -1,   169,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,
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
     265,   266,   267,   268,   269,   270
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
     332,   333,   334,   335,   336,   337,   345,   346,   348,   349,
     350,   355,   357,   359,   360,   361,   366,   387,   390,   393,
     394,   395,   396,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   443,   444,   445,   459,   460,   462,   463,
     464,   465,   466,   467,   468,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   487,   488,   489,   490,   491,
     492,   493,   496,   501,   502,   137,   330,   221,    29,    29,
     140,    81,   137,   205,   206,   140,    26,    27,    28,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    45,    46,
      48,    49,    51,    56,    57,    59,    60,    61,    71,    72,
      84,   120,   137,   140,   152,   185,   198,   208,   209,   210,
     212,   213,   220,   222,   224,   263,   264,   265,   501,   137,
     137,   140,   137,   140,    39,    40,    41,    42,    43,    44,
      52,    58,    69,    70,    73,    76,    98,    99,   100,   144,
     204,   228,   266,   267,   322,   323,   338,   339,   140,    18,
     137,   140,   500,    51,    54,   105,   144,   105,   105,   137,
      62,    63,   105,   352,    60,   140,   140,   137,   140,   501,
      34,    36,    37,    46,    84,   427,   501,   501,   105,   170,
     346,   501,   137,    14,    16,   501,   501,   419,   137,    21,
     197,   199,   209,   211,   140,   209,   211,   209,   209,   214,
     105,   137,   105,   267,   267,   267,   288,     0,   290,   291,
      38,    48,   293,   345,   174,   174,    94,   174,   347,    50,
      57,    60,    61,    68,   153,   155,   169,   195,   351,   356,
     357,   358,   375,   376,   380,   362,   363,   501,   151,    79,
     117,   125,   126,   128,   135,   139,   141,   146,   162,   186,
     187,   188,   189,   190,   191,   411,   412,   239,   142,   159,
     182,   104,   130,   143,   177,   184,   193,   121,   134,    74,
     183,    88,    89,   142,   159,   410,   137,   416,   419,   175,
     176,   138,   431,   432,   427,   431,   427,   431,   140,   331,
     349,   349,   485,   501,   346,   137,   137,   346,   346,   170,
     177,   501,   137,   346,   346,   170,   346,   170,   501,   339,
      39,   340,   338,   338,   339,   501,   165,   179,   152,   185,
      20,   499,   150,   165,   165,   179,   136,   105,   318,    34,
      39,    93,   153,   500,   205,   206,   207,    87,   221,   229,
     242,   244,   254,   257,   514,   515,   516,   517,   518,   521,
     526,   527,   323,   499,   346,   346,    20,   170,   500,   137,
     144,   499,   100,   144,   312,   499,   388,   389,   501,   500,
     501,   367,   369,   501,   349,   256,   256,   105,   370,   105,
     501,    34,    71,   170,   483,   484,   346,   170,   177,   501,
     137,   388,   170,    25,   447,   448,   449,   346,     7,   158,
      15,   170,   346,   197,    20,   349,   349,   170,   349,   349,
     349,   349,   215,   494,   495,   501,   349,   368,   374,   501,
     499,   499,   499,   295,   296,    38,   297,   349,   348,   153,
     105,   154,   154,   349,   349,    94,    81,    83,   131,   250,
     364,   365,   470,   395,   396,   398,   398,   398,   398,   397,
     398,   398,   398,   137,   140,   240,   434,   503,   505,   506,
     507,   508,   509,   510,   511,   401,   401,   400,   402,   402,
     402,   402,   403,   403,   404,   404,   215,    81,    81,    81,
     167,   346,   419,   419,   346,   432,   170,   349,   442,    38,
     319,   346,   170,   137,   167,   346,   346,   170,   167,    94,
     170,    94,   170,   167,   346,   167,   167,   167,   140,   328,
     501,    20,    94,    94,    81,   122,   127,   315,   316,   317,
     501,   122,   127,   144,   144,   499,   112,   117,   227,   230,
     100,   229,   258,   259,   261,   262,   227,   230,    20,   229,
     258,   259,   261,   262,   270,   170,   167,   170,   170,   167,
     346,   500,    83,    34,   500,   499,    83,    94,   171,   131,
     470,   117,   127,    94,   127,   365,   470,   167,   501,    66,
     201,   234,   353,   354,   170,   170,   170,   167,    94,   170,
      94,   170,   167,   346,   171,   501,   448,   449,   115,   180,
     167,   167,   116,   174,    81,   202,   203,   217,    81,   202,
     203,   217,    81,   221,   209,    94,   219,   127,   167,    59,
      94,   174,   174,   154,   501,   349,   381,   382,   105,   377,
     378,   105,   136,   194,   471,   473,   474,   475,   501,   105,
     349,   105,   131,   365,   131,   131,   364,   365,   398,   346,
     503,   509,   257,   537,    83,   152,   231,   232,   233,   241,
     249,   255,   256,   504,   512,   513,   514,   528,   531,   532,
     534,   238,   240,   245,   533,   225,   226,   247,   529,   471,
     471,   469,   474,   469,   167,   168,    94,   170,   174,   167,
     330,   346,   167,   167,    87,   391,   392,   137,   485,   486,
     501,   485,   486,   167,   105,   170,   341,   342,   122,   137,
     344,   328,   132,   149,   132,   149,   473,   317,   349,   470,
     127,   349,   499,   499,   113,   114,   499,   259,   260,    83,
     100,   140,   520,   260,   349,   181,   137,   167,   117,   311,
     499,   144,   117,    83,   311,   105,   349,   349,   131,   499,
     349,   105,   349,   127,   127,   365,   131,   470,   234,    64,
      65,    67,   105,   364,   371,   372,   373,   354,   137,   485,
     485,   167,   349,    25,   449,   115,   180,     8,     9,    90,
     108,   110,   137,   178,   343,   444,   446,   457,   458,   461,
      20,   216,   218,   349,   349,   349,   216,   218,   349,   349,
     349,   349,   349,   349,   105,   349,   349,   223,   497,   498,
     137,   105,   381,    82,    93,   103,   112,   383,   384,   385,
     386,    94,   501,    94,   363,   140,   140,   129,   159,   177,
     472,   501,   501,   349,   131,   349,   349,   131,   365,   131,
     167,   170,   235,   201,   234,   246,   251,   536,    83,   236,
     237,   530,   235,   506,   536,   399,   402,   255,   512,   514,
     507,   131,   530,   260,    53,   129,   349,   167,   105,   471,
     100,   392,   167,   346,   170,   170,   129,   170,   170,   501,
      81,    94,   170,   346,   330,   316,   349,   260,    83,   140,
     523,    20,   100,   520,   154,   268,   269,   320,   349,   167,
     346,   499,    94,   311,   389,   349,   174,   369,   349,   349,
     127,   349,   131,   105,   105,   349,   501,   373,    67,   167,
     346,   170,   170,   117,   178,   446,     6,   346,   501,   178,
     457,   174,   217,   217,   217,   217,   221,   495,   169,   140,
     498,   349,   374,   499,   113,   114,   385,   386,   386,   382,
      93,   379,   378,   170,   170,   349,   349,   131,   349,   402,
      47,   114,   402,   402,   246,   252,   260,   535,   535,   399,
     508,   253,   501,   169,   105,   169,   167,   470,   471,   342,
      81,   167,   121,   184,   522,   525,    20,    20,   524,   522,
     248,   530,    94,   170,    94,   170,   140,   326,   154,   111,
     167,    83,   499,   349,   349,   501,   501,   372,   349,   167,
     449,   501,   178,   167,   449,   501,   349,   349,   349,   349,
     349,   349,   428,   167,   386,   499,   349,   402,   402,   182,
      81,   349,   501,   349,   471,   523,   523,   525,    20,   170,
      20,   243,   519,   520,   519,   324,   325,   349,    94,   170,
     326,   349,   311,    65,    80,   166,   450,   449,   501,   180,
     449,    94,   170,   402,   471,   169,   530,    94,   170,   170,
      93,   470,   324,   170,   105,     4,   118,   453,   454,   456,
     458,    19,   119,   451,   452,   455,   458,   180,   449,   180,
     105,   344,   169,   349,   243,   520,   499,   501,    80,   118,
     456,   166,   119,   455,   180,   501,   349,    94,   170,   105,
     344,   501,    94,   170,   105,   344,   501,   170,   344
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
     328,   329,   330,   331,   331,   332,   333,   334,   335,   335,
     336,   336,   336,   337,   337,   337,   338,   338,   338,   338,
     339,   339,   340,   341,   341,   342,   342,   343,   344,   345,
     346,   346,   347,   347,   348,   348,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   350,   351,   352,   352,   353,   353,
     353,   354,   354,   355,   355,   356,   357,   357,   357,   358,
     358,   358,   358,   358,   359,   359,   360,   360,   361,   362,
     362,   363,   363,   363,   363,   363,   363,   363,   363,   364,
     365,   366,   367,   367,   368,   368,   369,   369,   369,   369,
     370,   370,   371,   371,   371,   372,   372,   372,   373,   373,
     373,   374,   375,   376,   377,   377,   378,   378,   379,   380,
     380,   381,   381,   382,   382,   383,   383,   383,   383,   383,
     383,   383,   384,   384,   385,   385,   386,   387,   387,   388,
     388,   389,   389,   390,   390,   391,   391,   392,   392,   393,
     394,   394,   395,   395,   396,   396,   396,   396,   396,   397,
     396,   396,   396,   396,   398,   398,   398,   399,   399,   400,
     400,   400,   401,   401,   401,   401,   401,   402,   402,   402,
     403,   403,   403,   404,   404,   405,   405,   406,   406,   407,
     407,   408,   408,   409,   409,   409,   409,   410,   410,   410,
     411,   411,   411,   411,   411,   411,   412,   412,   412,   413,
     413,   413,   413,   414,   414,   415,   415,   416,   416,   417,
     417,   417,   417,   418,   419,   419,   419,   420,   420,   421,
     421,   421,   421,   422,   422,   423,   423,   423,   423,   423,
     423,   423,   424,   424,   425,   425,   426,   426,   426,   426,
     426,   427,   427,   428,   428,   429,   429,   429,   430,   430,
     431,   431,   432,   433,   433,   433,   433,   433,   433,   433,
     433,   434,   434,   435,   435,   435,   436,   437,   437,   438,
     439,   440,   441,   441,   442,   442,   443,   443,   444,   444,
     444,   445,   445,   445,   445,   445,   445,   446,   446,   447,
     447,   448,   449,   449,   450,   450,   451,   451,   452,   452,
     452,   452,   453,   453,   454,   454,   454,   454,   455,   455,
     456,   456,   457,   457,   457,   457,   458,   458,   458,   458,
     459,   459,   460,   460,   461,   462,   462,   462,   462,   462,
     462,   463,   464,   464,   464,   464,   465,   465,   465,   465,
     466,   467,   468,   468,   468,   468,   469,   469,   470,   471,
     471,   471,   472,   472,   472,   473,   473,   473,   474,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   476,   477,
     477,   477,   478,   479,   480,   480,   480,   481,   481,   481,
     481,   481,   482,   483,   483,   483,   483,   483,   483,   483,
     484,   485,   486,   487,   488,   488,   488,   489,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   490,   490,   491,
     491,   492,   493,   494,   494,   495,   496,   497,   497,   498,
     498,   498,   498,   499,   500,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     502,   502,   503,   503,   503,   503,   504,   504,   504,   504,
     505,   505,   506,   506,   507,   507,   508,   508,   509,   509,
     509,   510,   510,   511,   511,   512,   512,   512,   512,   512,
     513,   514,   514,   514,   514,   514,   514,   514,   515,   515,
     515,   515,   516,   516,   516,   516,   517,   517,   518,   518,
     518,   518,   518,   518,   518,   519,   519,   520,   520,   520,
     520,   521,   521,   521,   521,   521,   522,   522,   523,   523,
     524,   524,   525,   525,   526,   527,   527,   528,   528,   528,
     529,   529,   529,   529,   529,   530,   530,   530,   530,   531,
     532,   533,   534,   534,   535,   535,   535,   536,   536,   537
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
       5,     2,     4,     3,     0,     5,     3,     5,     2,     2,
       3,     3,     3,     2,     3,     3,     1,     2,     2,     2,
       4,     4,     4,     1,     3,     2,     3,     3,     3,     1,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       2,     4,     3,     5,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     2,     1,
       4,     3,     4,     4,     5,     4,     5,     5,     6,     3,
       3,     3,     1,     4,     1,     4,     3,     4,     4,     5,
       4,     5,     1,     2,     3,     1,     2,     1,     6,     3,
       3,     1,     2,     3,     1,     3,     2,     3,     2,     3,
       4,     1,     3,     1,     2,     1,     1,     1,     2,     2,
       2,     3,     1,     1,     2,     2,     2,     5,     5,     1,
       4,     3,     4,     8,    10,     1,     2,     4,     7,     8,
       1,     3,     1,     3,     1,     3,     3,     3,     3,     0,
       4,     3,     3,     3,     1,     3,     4,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     4,     1,     4,     1,     4,     1,
       4,     1,     2,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       5,     5,     6,     3,     4,     1,     2,     3,     2,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       7,     4,     1,     2,     3,     4,     1,     1,     2,     2,
       1,     3,     1,     3,     1,     4,     1,     2,     1,     2,
       3,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     3,
       5,     7,     5,     7,     2,     1,     3,     2,     4,     4,
       6,     4,     5,     4,     5,     3,     1,     2,     2,     3,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     1,     2,     1,     2,     3,     3,     4,     3,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     3
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
  "BlockExpr", "Block", "BlockDecls", "AssignExpr", "ExitExpr",
  "WhileExpr", "FlowCtlStatement", "IndexStatement", "FunctionDecl",
  "FunctionDecl2", "FunctionDecl3", "FunctionDecl4", "ParamList", "Param",
  "EnclosedExpr", "BracedExpr", "QueryBody", "Expr", "ApplyExpr",
  "ConcatExpr", "ExprSingle", "FLWORExpr", "ReturnExpr", "WindowType",
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
     293,   345,    -1,   345,    -1,   292,   293,    -1,    51,   144,
     500,   117,   499,   174,    -1,   294,   174,    -1,   295,   174,
      -1,   294,   174,   295,   174,    -1,   296,    -1,   294,   174,
     296,    -1,   297,    -1,   295,   174,   297,    -1,   298,    -1,
     299,    -1,   300,    -1,   302,    -1,   319,    -1,   314,    -1,
     337,    -1,   303,    -1,   304,    -1,   321,    -1,   301,    -1,
     308,    -1,   309,    -1,   327,    -1,   305,    -1,   306,    -1,
     307,    -1,   488,    -1,   310,    -1,   313,    -1,    38,   144,
     500,   117,   499,    -1,    38,    76,   165,    -1,    38,    76,
     179,    -1,    38,   100,    34,   144,   499,    -1,    38,   100,
      39,   144,   499,    -1,    38,    52,   501,    20,    -1,    38,
     228,   514,    -1,    38,    69,   152,    -1,    38,    69,   185,
      -1,    38,   100,   153,   112,   113,    -1,    38,   100,   153,
     112,   114,    -1,    38,    73,   165,    94,   132,    -1,    38,
      73,   165,    94,   149,    -1,    38,    73,   150,    94,   132,
      -1,    38,    73,   150,    94,   149,    -1,    38,   100,    93,
     499,    -1,    38,    70,   499,    -1,    48,    54,   499,    -1,
      48,    54,   312,   499,    -1,    48,    54,   499,    83,   311,
      -1,    48,    54,   312,   499,    83,   311,    -1,   499,    -1,
     311,    94,   499,    -1,   144,   500,   117,    -1,   100,    34,
     144,    -1,    48,    51,   499,    -1,    48,    51,   144,   500,
     117,   499,    -1,    48,    51,   499,    83,   311,    -1,    48,
      51,   144,   500,   117,   499,    83,   311,    -1,    38,    98,
     136,   315,    -1,    81,   473,   316,    -1,   316,    -1,   317,
      -1,   122,    -1,   122,   317,    -1,   127,   349,    -1,   105,
     501,    -1,   105,   501,   470,    -1,    38,    99,   318,   127,
     349,    -1,    38,    99,   318,   122,    -1,    38,    99,   318,
     122,   127,   349,    -1,   268,    -1,   269,    -1,    38,   322,
      -1,   323,    -1,   266,   323,    -1,   267,   499,   270,   349,
     154,   326,   170,    -1,   267,   499,   270,   349,   320,   154,
     326,   170,    -1,   325,    -1,   325,    93,   499,    -1,   349,
      -1,   349,   470,    -1,   140,   324,    -1,   326,    94,   324,
      -1,    38,    58,   165,    -1,    38,    58,   179,    -1,   140,
     170,    -1,   140,   341,   170,    -1,   140,   170,    81,   471,
      -1,   140,   341,   170,    81,   471,    -1,    26,   330,    -1,
     137,   331,   346,   167,    -1,   331,   319,   174,    -1,    -1,
      56,   105,   501,   127,   349,    -1,    27,   221,   349,    -1,
      31,   140,   349,   170,   330,    -1,    28,    29,    -1,    30,
      29,    -1,   263,   267,   499,    -1,   265,   267,   499,    -1,
     264,   267,   499,    -1,    38,   338,    -1,    38,    43,   338,
      -1,    38,    42,   338,    -1,   339,    -1,    44,   339,    -1,
      40,   339,    -1,    41,   340,    -1,    39,   501,   328,   344,
      -1,    39,   501,   328,   122,    -1,    39,   501,   328,   330,
      -1,   342,    -1,   341,    94,   342,    -1,   105,   501,    -1,
     105,   501,   470,    -1,   137,   346,   167,    -1,   137,   346,
     167,    -1,   346,    -1,   348,    -1,   348,   347,    -1,   174,
      -1,   347,   348,   174,    -1,   349,    -1,   348,    94,   349,
      -1,   350,    -1,   387,    -1,   390,    -1,   393,    -1,   394,
      -1,   489,    -1,   490,    -1,   492,    -1,   491,    -1,   493,
      -1,   496,    -1,   502,    -1,   333,    -1,   334,    -1,   335,
      -1,   332,    -1,   329,    -1,   336,    -1,   359,   351,    -1,
     169,   349,    -1,    62,   256,    -1,    63,   256,    -1,   201,
      -1,   234,    -1,    66,   234,    -1,   353,   371,    67,   349,
      -1,   353,    67,   349,    -1,    60,   352,   370,   354,   354,
      -1,    60,   352,   370,   354,    -1,    68,   105,   501,    -1,
     361,    -1,   366,    -1,   355,    -1,   357,    -1,   375,    -1,
     380,    -1,   376,    -1,   356,    -1,   357,    -1,   359,   358,
      -1,    60,   105,    -1,    61,    60,   105,    -1,   360,   362,
      -1,   363,    -1,   362,    94,   105,   363,    -1,   501,   131,
     349,    -1,   501,   470,   131,   349,    -1,   501,   364,   131,
     349,    -1,   501,   470,   364,   131,   349,    -1,   501,   365,
     131,   349,    -1,   501,   470,   365,   131,   349,    -1,   501,
     364,   365,   131,   349,    -1,   501,   470,   364,   365,   131,
     349,    -1,    83,   105,   501,    -1,   250,   105,   501,    -1,
      57,   105,   367,    -1,   369,    -1,   367,    94,   105,   369,
      -1,   374,    -1,   368,    94,   105,   374,    -1,   501,   127,
     349,    -1,   501,   470,   127,   349,    -1,   501,   365,   127,
     349,    -1,   501,   470,   365,   127,   349,    -1,   105,   501,
     131,   349,    -1,   105,   501,   470,   131,   349,    -1,   372,
      -1,   105,   501,    -1,   105,   501,   372,    -1,   364,    -1,
     364,   373,    -1,   373,    -1,    64,   105,   501,    65,   105,
     501,    -1,    65,   105,   501,    -1,    64,   105,   501,    -1,
     501,    -1,   195,   349,    -1,   155,   154,   377,    -1,   378,
      -1,   377,    94,   378,    -1,   105,   501,    -1,   105,   501,
     379,    -1,    93,   499,    -1,   153,   154,   381,    -1,    50,
     153,   154,   381,    -1,   382,    -1,   381,    94,   382,    -1,
     349,    -1,   349,   383,    -1,   384,    -1,   385,    -1,   386,
      -1,   384,   385,    -1,   384,   386,    -1,   385,   386,    -1,
     384,   385,   386,    -1,    82,    -1,   103,    -1,   112,   113,
      -1,   112,   114,    -1,    93,   499,    -1,    49,   105,   388,
     171,   349,    -1,   120,   105,   388,   171,   349,    -1,   389,
      -1,   388,    94,   105,   389,    -1,   501,   131,   349,    -1,
     501,   470,   131,   349,    -1,    33,   140,   346,   170,   391,
     100,   169,   349,    -1,    33,   140,   346,   170,   391,   100,
     105,   501,   169,   349,    -1,   392,    -1,   391,   392,    -1,
      87,   471,   169,   349,    -1,    87,   105,   501,    81,   471,
     169,   349,    -1,    45,   140,   346,   170,   181,   349,   111,
     349,    -1,   395,    -1,   394,   151,   395,    -1,   396,    -1,
     395,    79,   396,    -1,   398,    -1,   398,   411,   398,    -1,
     398,   412,   398,    -1,   398,   117,   398,    -1,   398,   146,
     398,    -1,    -1,   398,   141,   397,   398,    -1,   398,   139,
     398,    -1,   398,   128,   398,    -1,   398,   126,   398,    -1,
     399,    -1,   399,   239,   503,    -1,   399,   239,   503,   537,
      -1,   400,    -1,   400,   182,   400,    -1,   401,    -1,   400,
     159,   401,    -1,   400,   142,   401,    -1,   402,    -1,   401,
     177,   402,    -1,   401,   104,   402,    -1,   401,   130,   402,
      -1,   401,   143,   402,    -1,   403,    -1,   402,   184,   403,
      -1,   402,   193,   403,    -1,   404,    -1,   403,   134,   404,
      -1,   403,   121,   404,    -1,   405,    -1,   405,    74,   215,
     471,    -1,   406,    -1,   406,   183,    81,   471,    -1,   407,
      -1,   407,    88,    81,   469,    -1,   408,    -1,   408,    89,
      81,   469,    -1,   410,    -1,   409,   410,    -1,   159,    -1,
     142,    -1,   409,   159,    -1,   409,   142,    -1,   413,    -1,
     417,    -1,   414,    -1,   186,    -1,   191,    -1,   190,    -1,
     189,    -1,   188,    -1,   187,    -1,   135,    -1,   162,    -1,
     125,    -1,    32,   137,   346,   167,    -1,    32,   206,   137,
     346,   167,    -1,    32,   205,   137,   346,   167,    -1,    32,
      81,   485,   137,   346,   167,    -1,   415,   137,   167,    -1,
     415,   137,   346,   167,    -1,   416,    -1,   415,   416,    -1,
     160,   501,    15,    -1,   160,    16,    -1,   418,    -1,   418,
     419,    -1,   176,   419,    -1,   419,    -1,   175,    -1,   420,
      -1,   420,   175,   419,    -1,   420,   176,   419,    -1,   421,
      -1,   430,    -1,   422,    -1,   422,   431,    -1,   425,    -1,
     425,   431,    -1,   423,   427,    -1,   424,    -1,    92,    -1,
     101,    -1,    85,    -1,   173,    -1,   102,    -1,   124,    -1,
     123,    -1,   427,    -1,    86,   427,    -1,   426,   427,    -1,
     107,    -1,   156,    -1,    77,    -1,   164,    -1,   163,    -1,
      78,    -1,   475,    -1,   428,    -1,   501,    -1,   429,    -1,
     177,    -1,    10,    -1,    17,    -1,   433,    -1,   433,   431,
      -1,   432,    -1,   431,   432,    -1,   138,   346,   168,    -1,
     434,    -1,   436,    -1,   437,    -1,   438,    -1,   441,    -1,
     443,    -1,   439,    -1,   440,    -1,   435,    -1,   487,    -1,
      97,    -1,   133,    -1,   109,    -1,   105,   501,    -1,   140,
     170,    -1,   140,   346,   170,    -1,   106,    -1,   152,   137,
     346,   167,    -1,   185,   137,   346,   167,    -1,   501,   140,
     170,    -1,   501,   140,   442,   170,    -1,   349,    -1,   442,
      94,   349,    -1,   444,    -1,   462,    -1,   445,    -1,   459,
      -1,   460,    -1,   141,   501,   449,   115,    -1,   141,   501,
     447,   449,   115,    -1,   141,   501,   449,   180,   178,   501,
     449,   180,    -1,   141,   501,   449,   180,   446,   178,   501,
     449,   180,    -1,   141,   501,   447,   449,   180,   178,   501,
     449,   180,    -1,   141,   501,   447,   449,   180,   446,   178,
     501,   449,   180,    -1,   457,    -1,   446,   457,    -1,   448,
      -1,   447,   448,    -1,    25,   501,   449,   117,   449,   450,
      -1,    -1,    25,    -1,   166,   451,   166,    -1,    80,   453,
      80,    -1,    -1,   452,    -1,   119,    -1,   455,    -1,   452,
     119,    -1,   452,   455,    -1,    -1,   454,    -1,   118,    -1,
     456,    -1,   454,   118,    -1,   454,   456,    -1,    19,    -1,
     458,    -1,     4,    -1,   458,    -1,   444,    -1,     9,    -1,
     461,    -1,   458,    -1,     8,    -1,   108,    -1,   110,    -1,
     343,    -1,   196,    21,   197,    -1,   196,   197,    -1,   157,
      14,   158,    -1,   157,    14,     7,    -1,    90,     6,    -1,
     463,    -1,   464,    -1,   465,    -1,   466,    -1,   467,    -1,
     468,    -1,    35,   137,   346,   167,    -1,    34,   501,   137,
     167,    -1,    34,   501,   137,   346,   167,    -1,    34,   137,
     346,   167,   137,   167,    -1,    34,   137,   346,   167,   137,
     346,   167,    -1,    84,   501,   137,   167,    -1,    84,   501,
     137,   346,   167,    -1,    84,   137,   346,   167,   137,   167,
      -1,    84,   137,   346,   167,   137,   346,   167,    -1,    36,
     137,   346,   167,    -1,    37,   137,   346,   167,    -1,    46,
     500,   137,   167,    -1,    46,   500,   137,   346,   167,    -1,
      46,   137,   346,   167,   137,   167,    -1,    46,   137,   346,
     167,   137,   346,   167,    -1,   474,    -1,   474,   129,    -1,
      81,   471,    -1,   473,    -1,   473,   472,    -1,   194,   140,
     170,    -1,   129,    -1,   177,    -1,   159,    -1,   474,    -1,
     475,    -1,   136,   140,   170,    -1,   501,    -1,   477,    -1,
     483,    -1,   481,    -1,   484,    -1,   482,    -1,   480,    -1,
     479,    -1,   478,    -1,   476,    -1,   209,   140,   170,    -1,
      72,   140,   170,    -1,    72,   140,   483,   170,    -1,    72,
     140,   484,   170,    -1,    36,   140,   170,    -1,    37,   140,
     170,    -1,    46,   140,   170,    -1,    46,   140,   500,   170,
      -1,    46,   140,    20,   170,    -1,    84,   140,   170,    -1,
      84,   140,   501,   170,    -1,    84,   140,   501,    94,   485,
     170,    -1,    84,   140,   177,   170,    -1,    84,   140,   177,
      94,   485,   170,    -1,   172,   501,   170,    -1,    34,   140,
     170,    -1,    34,   140,   501,   170,    -1,    34,   140,   501,
      94,   485,   170,    -1,    34,   140,   501,    94,   486,   170,
      -1,    34,   140,   177,   170,    -1,    34,   140,   177,    94,
     485,   170,    -1,    34,   140,   177,    94,   486,   170,    -1,
      71,   140,   501,   170,    -1,   501,    -1,   501,   129,    -1,
      20,    -1,    38,   204,   205,    -1,    38,   204,   206,    -1,
      38,   204,   207,    -1,   210,   209,   349,   217,   349,    -1,
     210,   209,   349,    81,   216,   217,   349,    -1,   210,   209,
     349,    81,   218,   217,   349,    -1,   210,   209,   349,   202,
     349,    -1,   210,   209,   349,   203,   349,    -1,   210,   211,
     349,   217,   349,    -1,   210,   211,   349,    81,   216,   217,
     349,    -1,   210,   211,   349,    81,   218,   217,   349,    -1,
     210,   211,   349,   202,   349,    -1,   210,   211,   349,   203,
     349,    -1,   208,   209,   349,    -1,   208,   211,   349,    -1,
     213,   209,   349,   221,   349,    -1,   213,   214,   215,   209,
     349,   221,   349,    -1,   212,   209,   349,    81,   349,    -1,
     220,   105,   494,   219,   349,   169,   349,    -1,   495,    -1,
     494,    94,   105,   495,    -1,   501,   127,   349,    -1,   222,
     137,   349,   167,   497,    -1,   498,    -1,   497,   498,    -1,
     223,   140,   428,   170,   344,    -1,   223,   140,   428,    94,
     105,   501,   170,   344,    -1,   223,   140,   428,    94,   105,
     501,    94,   105,   501,   170,   344,    -1,   223,   140,   428,
      94,   105,   501,    94,   105,   501,    94,   105,   501,   170,
     344,    -1,    20,    -1,    18,    -1,    18,    -1,   198,    -1,
     112,    -1,    84,    -1,    37,    -1,    72,    -1,    34,    -1,
     136,    -1,    45,    -1,   209,    -1,    46,    -1,    75,    -1,
      71,    -1,    36,    -1,    33,    -1,   194,    -1,    76,    -1,
     228,    -1,    70,    -1,   206,    -1,   205,    -1,   130,    -1,
      35,    -1,   240,    -1,   227,    -1,   230,    -1,   229,    -1,
     257,    -1,   258,    -1,   261,    -1,   259,    -1,   262,    -1,
     233,    -1,   235,    -1,    53,    -1,   201,    -1,   234,    -1,
      47,    -1,   207,    -1,   220,    -1,   214,    -1,   186,    -1,
     191,    -1,   190,    -1,   189,    -1,   188,    -1,   187,    -1,
      83,    -1,    98,    -1,    99,    -1,   169,    -1,    60,    -1,
      61,    -1,    62,    -1,    63,    -1,    64,    -1,    65,    -1,
      66,    -1,    67,    -1,    68,    -1,   131,    -1,    57,    -1,
     195,    -1,   154,    -1,   155,    -1,   153,    -1,    50,    -1,
      82,    -1,   103,    -1,   113,    -1,   114,    -1,    93,    -1,
      49,    -1,   120,    -1,   171,    -1,    87,    -1,    81,    -1,
     181,    -1,   111,    -1,   151,    -1,    79,    -1,    74,    -1,
     215,    -1,    88,    -1,   182,    -1,   104,    -1,   143,    -1,
     184,    -1,   134,    -1,   121,    -1,    32,    -1,    89,    -1,
     183,    -1,   135,    -1,   165,    -1,   179,    -1,   144,    -1,
     122,    -1,   116,    -1,   150,    -1,   132,    -1,   149,    -1,
      38,    -1,    58,    -1,    69,    -1,   100,    -1,    73,    -1,
      52,    -1,   199,    -1,    48,    -1,    54,    -1,    51,    -1,
      39,    -1,   250,    -1,   239,    -1,   255,    -1,   256,    -1,
     232,    -1,   245,    -1,   253,    -1,   249,    -1,   231,    -1,
     244,    -1,   254,    -1,   248,    -1,   243,    -1,   242,    -1,
     226,    -1,   225,    -1,   247,    -1,   236,    -1,   237,    -1,
     260,    -1,   252,    -1,   251,    -1,   246,    -1,   213,    -1,
     219,    -1,   216,    -1,   210,    -1,   203,    -1,   202,    -1,
     204,    -1,   221,    -1,   211,    -1,   212,    -1,   218,    -1,
     208,    -1,   217,    -1,    44,    -1,    41,    -1,    40,    -1,
      42,    -1,    43,    -1,   152,    -1,   185,    -1,    26,    -1,
      27,    -1,    29,    -1,    31,    -1,    28,    -1,    30,    -1,
     222,    -1,   223,    -1,    59,    -1,   224,    -1,    56,    -1,
     267,    -1,   263,    -1,   264,    -1,   266,    -1,   270,    -1,
     268,    -1,   269,    -1,   265,    -1,   224,   105,   368,    59,
     137,   349,   167,    -1,    59,   137,   349,   167,    -1,   505,
      -1,   505,   504,    -1,   505,   255,   399,    -1,   505,   504,
     255,   399,    -1,   514,    -1,   512,    -1,   504,   514,    -1,
     504,   512,    -1,   506,    -1,   505,   241,   506,    -1,   507,
      -1,   506,   238,   507,    -1,   508,    -1,   507,   240,   131,
     508,    -1,   509,    -1,   240,   509,    -1,   510,    -1,   510,
     533,    -1,   140,   503,   170,    -1,   511,    -1,   511,   529,
      -1,   434,    -1,   137,   346,   167,    -1,   513,    -1,   532,
      -1,   531,    -1,   534,    -1,   528,    -1,   152,    -1,   515,
      -1,   516,    -1,   517,    -1,   518,    -1,   521,    -1,   526,
      -1,   527,    -1,   244,    -1,   254,    -1,    87,   227,    -1,
      87,   230,    -1,   221,   229,    -1,   257,   229,    -1,   229,
     227,    -1,   229,   230,    -1,   221,   258,    -1,   257,   258,
      -1,   221,   261,   520,    -1,   221,   261,   100,    -1,   221,
     261,   140,   520,   170,    -1,   221,   261,   140,   520,    94,
     519,   170,    -1,   221,   261,   140,   100,   170,    -1,   221,
     261,   140,   100,    94,   519,   170,    -1,   257,   261,    -1,
     520,    -1,   519,    94,   520,    -1,    83,    20,    -1,    83,
      20,   248,    20,    -1,    83,    20,   530,   243,    -1,    83,
      20,   248,    20,   530,   243,    -1,   221,   259,   260,   523,
      -1,   221,   259,   260,   523,   522,    -1,   221,   100,   259,
     260,    -1,   221,   100,   259,   260,   522,    -1,   257,   259,
     260,    -1,   525,    -1,   522,   525,    -1,    83,    20,    -1,
     140,   524,   170,    -1,    20,    -1,   524,    20,    -1,   184,
     523,    -1,   121,   523,    -1,   242,    20,    -1,   221,   262,
      -1,   257,   262,    -1,    83,   201,    -1,    83,   234,    -1,
     233,   235,    -1,   226,    -1,   226,    53,    -1,   225,    -1,
     225,   260,    -1,   247,    -1,   236,   402,    -1,    83,   114,
     402,    -1,    83,    47,   402,    -1,   237,   402,   182,   402,
      -1,   232,   530,   535,    -1,   256,   402,   535,    -1,   245,
     530,   253,    -1,   249,   536,    -1,   231,   536,    -1,   260,
      -1,   252,    -1,   246,    -1,   251,    -1,   246,    -1,   257,
     235,   402,    -1
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
     371,   377,   380,   385,   389,   390,   396,   400,   406,   409,
     412,   416,   420,   424,   427,   431,   435,   437,   440,   443,
     446,   451,   456,   461,   463,   467,   470,   474,   478,   482,
     484,   486,   489,   491,   495,   497,   501,   503,   505,   507,
     509,   511,   513,   515,   517,   519,   521,   523,   525,   527,
     529,   531,   533,   535,   537,   540,   543,   546,   549,   551,
     553,   556,   561,   565,   571,   576,   580,   582,   584,   586,
     588,   590,   592,   594,   596,   598,   601,   604,   608,   611,
     613,   618,   622,   627,   632,   638,   643,   649,   655,   662,
     666,   670,   674,   676,   681,   683,   688,   692,   697,   702,
     708,   713,   719,   721,   724,   728,   730,   733,   735,   742,
     746,   750,   752,   755,   759,   761,   765,   768,   772,   775,
     779,   784,   786,   790,   792,   795,   797,   799,   801,   804,
     807,   810,   814,   816,   818,   821,   824,   827,   833,   839,
     841,   846,   850,   855,   864,   875,   877,   880,   885,   893,
     902,   904,   908,   910,   914,   916,   920,   924,   928,   932,
     933,   938,   942,   946,   950,   952,   956,   961,   963,   967,
     969,   973,   977,   979,   983,   987,   991,   995,   997,  1001,
    1005,  1007,  1011,  1015,  1017,  1022,  1024,  1029,  1031,  1036,
    1038,  1043,  1045,  1048,  1050,  1052,  1055,  1058,  1060,  1062,
    1064,  1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,  1082,
    1087,  1093,  1099,  1106,  1110,  1115,  1117,  1120,  1124,  1127,
    1129,  1132,  1135,  1137,  1139,  1141,  1145,  1149,  1151,  1153,
    1155,  1158,  1160,  1163,  1166,  1168,  1170,  1172,  1174,  1176,
    1178,  1180,  1182,  1184,  1187,  1190,  1192,  1194,  1196,  1198,
    1200,  1202,  1204,  1206,  1208,  1210,  1212,  1214,  1216,  1218,
    1221,  1223,  1226,  1230,  1232,  1234,  1236,  1238,  1240,  1242,
    1244,  1246,  1248,  1250,  1252,  1254,  1256,  1259,  1262,  1266,
    1268,  1273,  1278,  1282,  1287,  1289,  1293,  1295,  1297,  1299,
    1301,  1303,  1308,  1314,  1323,  1333,  1343,  1354,  1356,  1359,
    1361,  1364,  1371,  1372,  1374,  1378,  1382,  1383,  1385,  1387,
    1389,  1392,  1395,  1396,  1398,  1400,  1402,  1405,  1408,  1410,
    1412,  1414,  1416,  1418,  1420,  1422,  1424,  1426,  1428,  1430,
    1432,  1436,  1439,  1443,  1447,  1450,  1452,  1454,  1456,  1458,
    1460,  1462,  1467,  1472,  1478,  1485,  1493,  1498,  1504,  1511,
    1519,  1524,  1529,  1534,  1540,  1547,  1555,  1557,  1560,  1563,
    1565,  1568,  1572,  1574,  1576,  1578,  1580,  1582,  1586,  1588,
    1590,  1592,  1594,  1596,  1598,  1600,  1602,  1604,  1606,  1610,
    1614,  1619,  1624,  1628,  1632,  1636,  1641,  1646,  1650,  1655,
    1662,  1667,  1674,  1678,  1682,  1687,  1694,  1701,  1706,  1713,
    1720,  1725,  1727,  1730,  1732,  1736,  1740,  1744,  1750,  1758,
    1766,  1772,  1778,  1784,  1792,  1800,  1806,  1812,  1816,  1820,
    1826,  1834,  1840,  1848,  1850,  1855,  1859,  1865,  1867,  1870,
    1876,  1885,  1897,  1912,  1914,  1916,  1918,  1920,  1922,  1924,
    1926,  1928,  1930,  1932,  1934,  1936,  1938,  1940,  1942,  1944,
    1946,  1948,  1950,  1952,  1954,  1956,  1958,  1960,  1962,  1964,
    1966,  1968,  1970,  1972,  1974,  1976,  1978,  1980,  1982,  1984,
    1986,  1988,  1990,  1992,  1994,  1996,  1998,  2000,  2002,  2004,
    2006,  2008,  2010,  2012,  2014,  2016,  2018,  2020,  2022,  2024,
    2026,  2028,  2030,  2032,  2034,  2036,  2038,  2040,  2042,  2044,
    2046,  2048,  2050,  2052,  2054,  2056,  2058,  2060,  2062,  2064,
    2066,  2068,  2070,  2072,  2074,  2076,  2078,  2080,  2082,  2084,
    2086,  2088,  2090,  2092,  2094,  2096,  2098,  2100,  2102,  2104,
    2106,  2108,  2110,  2112,  2114,  2116,  2118,  2120,  2122,  2124,
    2126,  2128,  2130,  2132,  2134,  2136,  2138,  2140,  2142,  2144,
    2146,  2148,  2150,  2152,  2154,  2156,  2158,  2160,  2162,  2164,
    2166,  2168,  2170,  2172,  2174,  2176,  2178,  2180,  2182,  2184,
    2186,  2188,  2190,  2192,  2194,  2196,  2198,  2200,  2202,  2204,
    2206,  2208,  2210,  2212,  2214,  2216,  2218,  2220,  2222,  2224,
    2226,  2228,  2230,  2232,  2234,  2236,  2238,  2240,  2242,  2244,
    2246,  2248,  2250,  2252,  2254,  2256,  2258,  2260,  2262,  2264,
    2266,  2274,  2279,  2281,  2284,  2288,  2293,  2295,  2297,  2300,
    2303,  2305,  2309,  2311,  2315,  2317,  2322,  2324,  2327,  2329,
    2332,  2336,  2338,  2341,  2343,  2347,  2349,  2351,  2353,  2355,
    2357,  2359,  2361,  2363,  2365,  2367,  2369,  2371,  2373,  2375,
    2377,  2380,  2383,  2386,  2389,  2392,  2395,  2398,  2401,  2405,
    2409,  2415,  2423,  2429,  2437,  2440,  2442,  2446,  2449,  2454,
    2459,  2466,  2471,  2477,  2482,  2488,  2492,  2494,  2497,  2500,
    2504,  2506,  2509,  2512,  2515,  2518,  2521,  2524,  2527,  2530,
    2533,  2535,  2538,  2540,  2543,  2545,  2548,  2552,  2556,  2561,
    2565,  2569,  2573,  2576,  2579,  2581,  2583,  2585,  2587,  2589
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   880,   880,   881,   891,   896,   902,   907,   919,   924,
     934,   941,   953,   965,   977,   983,   989,  1001,  1007,  1021,
    1027,  1041,  1042,  1043,  1044,  1050,  1051,  1052,  1053,  1056,
    1059,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1075,  1082,
    1083,  1095,  1107,  1112,  1123,  1129,  1141,  1154,  1165,  1170,
    1182,  1187,  1198,  1204,  1210,  1216,  1235,  1246,  1257,  1264,
    1271,  1278,  1291,  1297,  1312,  1316,  1326,  1332,  1339,  1345,
    1357,  1364,  1370,  1377,  1383,  1387,  1394,  1405,  1409,  1417,
    1426,  1433,  1443,  1445,  1452,  1460,  1464,  1472,  1477,  1487,
    1491,  1499,  1503,  1510,  1517,  1527,  1532,  1544,  1548,  1552,
    1556,  1563,  1570,  1587,  1598,  1604,  1611,  1618,  1630,  1634,
    1641,  1645,  1649,  1656,  1660,  1666,  1673,  1677,  1681,  1689,
    1696,  1705,  1717,  1731,  1739,  1753,  1759,  1771,  1779,  1790,
    1801,  1805,  1817,  1821,  1830,  1834,  1850,  1851,  1852,  1853,
    1854,  1857,  1858,  1859,  1860,  1861,  1863,  1864,  1867,  1868,
    1869,  1870,  1871,  1874,  1881,  1890,  1897,  1901,  1909,  1913,
    1917,  1924,  1928,  1935,  1940,  1949,  1958,  1959,  1960,  1964,
    1964,  1964,  1964,  1964,  1967,  1973,  1982,  1986,  1996,  2007,
    2013,  2027,  2034,  2042,  2051,  2061,  2069,  2078,  2087,  2102,
    2114,  2125,  2137,  2143,  2155,  2161,  2175,  2183,  2192,  2200,
    2212,  2218,  2228,  2229,  2233,  2241,  2245,  2250,  2254,  2258,
    2262,  2269,  2284,  2292,  2302,  2308,  2319,  2325,  2334,  2344,
    2349,  2361,  2367,  2381,  2387,  2399,  2406,  2413,  2420,  2427,
    2434,  2441,  2454,  2458,  2468,  2473,  2484,  2495,  2502,  2515,
    2522,  2534,  2540,  2553,  2560,  2574,  2580,  2592,  2598,  2611,
    2622,  2626,  2637,  2641,  2660,  2664,  2672,  2680,  2688,  2696,
    2696,  2704,  2712,  2720,  2734,  2738,  2745,  2758,  2762,  2773,
    2777,  2781,  2791,  2795,  2799,  2803,  2807,  2817,  2821,  2826,
    2837,  2841,  2845,  2855,  2859,  2871,  2875,  2887,  2891,  2903,
    2907,  2919,  2923,  2935,  2939,  2943,  2947,  2959,  2963,  2967,
    2977,  2981,  2985,  2989,  2993,  2997,  3007,  3011,  3015,  3025,
    3029,  3033,  3037,  3049,  3055,  3067,  3073,  3087,  3094,  3135,
    3139,  3143,  3147,  3159,  3169,  3180,  3185,  3195,  3199,  3209,
    3215,  3221,  3227,  3239,  3245,  3256,  3260,  3264,  3268,  3272,
    3276,  3280,  3290,  3294,  3304,  3310,  3322,  3326,  3330,  3334,
    3338,  3353,  3357,  3367,  3371,  3381,  3388,  3395,  3408,  3412,
    3424,  3430,  3444,  3455,  3459,  3463,  3467,  3471,  3475,  3479,
    3483,  3493,  3497,  3507,  3512,  3517,  3528,  3538,  3542,  3553,
    3563,  3574,  3630,  3636,  3648,  3654,  3666,  3670,  3680,  3684,
    3688,  3698,  3706,  3714,  3722,  3730,  3738,  3753,  3759,  3771,
    3777,  3790,  3799,  3801,  3807,  3812,  3824,  3827,  3834,  3840,
    3846,  3854,  3869,  3872,  3879,  3885,  3891,  3899,  3913,  3918,
    3929,  3934,  3945,  3950,  3955,  3961,  3973,  3979,  3984,  3989,
    4000,  4005,  4020,  4025,  4042,  4057,  4061,  4065,  4069,  4073,
    4077,  4087,  4098,  4104,  4110,  4115,  4137,  4143,  4149,  4154,
    4165,  4175,  4185,  4191,  4197,  4202,  4213,  4219,  4231,  4243,
    4249,  4255,  4292,  4297,  4302,  4313,  4317,  4321,  4331,  4342,
    4346,  4350,  4354,  4358,  4362,  4366,  4370,  4374,  4384,  4394,
    4398,  4403,  4414,  4424,  4434,  4438,  4442,  4452,  4458,  4464,
    4470,  4476,  4488,  4499,  4506,  4513,  4520,  4527,  4534,  4541,
    4554,  4575,  4582,  4602,  4642,  4647,  4650,  4658,  4664,  4670,
    4676,  4682,  4689,  4695,  4701,  4707,  4713,  4725,  4730,  4740,
    4746,  4758,  4784,  4795,  4801,  4814,  4828,  4835,  4842,  4853,
    4860,  4868,  4877,  4890,  4893,  4911,  4912,  4913,  4914,  4915,
    4916,  4917,  4918,  4919,  4920,  4921,  4922,  4923,  4924,  4925,
    4926,  4927,  4928,  4929,  4930,  4931,  4932,  4933,  4934,  4935,
    4936,  4937,  4938,  4939,  4940,  4941,  4942,  4943,  4944,  4945,
    4946,  4947,  4948,  4949,  4950,  4951,  4952,  4953,  4954,  4955,
    4956,  4957,  4958,  4959,  4960,  4961,  4962,  4963,  4964,  4965,
    4966,  4967,  4968,  4969,  4970,  4971,  4972,  4973,  4974,  4975,
    4976,  4977,  4978,  4979,  4980,  4981,  4982,  4983,  4984,  4985,
    4986,  4987,  4988,  4989,  4990,  4991,  4992,  4993,  4994,  4995,
    4996,  4997,  4998,  4999,  5000,  5001,  5002,  5003,  5004,  5005,
    5006,  5007,  5008,  5009,  5010,  5011,  5012,  5013,  5014,  5015,
    5016,  5017,  5018,  5019,  5020,  5021,  5022,  5023,  5024,  5025,
    5026,  5027,  5028,  5029,  5030,  5031,  5032,  5033,  5034,  5035,
    5036,  5037,  5038,  5039,  5040,  5041,  5042,  5043,  5044,  5045,
    5046,  5047,  5048,  5049,  5050,  5051,  5052,  5053,  5054,  5055,
    5056,  5057,  5058,  5059,  5060,  5061,  5062,  5063,  5064,  5065,
    5066,  5067,  5068,  5069,  5070,  5071,  5072,  5073,  5074,  5075,
    5076,  5077,  5078,  5079,  5080,  5081,  5082,  5083,  5084,  5085,
    5096,  5102,  5119,  5123,  5127,  5131,  5141,  5144,  5147,  5150,
    5159,  5162,  5171,  5174,  5183,  5186,  5195,  5198,  5207,  5210,
    5213,  5222,  5225,  5234,  5238,  5248,  5251,  5254,  5257,  5260,
    5269,  5278,  5282,  5286,  5290,  5294,  5298,  5302,  5312,  5315,
    5318,  5321,  5330,  5333,  5336,  5339,  5348,  5351,  5360,  5363,
    5366,  5369,  5372,  5375,  5378,  5387,  5390,  5399,  5402,  5405,
    5408,  5417,  5420,  5423,  5426,  5429,  5438,  5441,  5450,  5453,
    5462,  5465,  5474,  5477,  5486,  5495,  5498,  5507,  5510,  5513,
    5522,  5525,  5528,  5531,  5534,  5543,  5547,  5551,  5555,  5565,
    5574,  5584,  5593,  5596,  5605,  5608,  5611,  5620,  5623,  5632
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
  const int xquery_parser::yylast_ = 8585;
  const int xquery_parser::yynnts_ = 252;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 477;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 286;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 540;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5640 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"


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

