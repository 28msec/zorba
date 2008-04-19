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
#line 736 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 51 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"

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
        case 53: /* "\"'DECIMAL'\"" */
#line 636 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).decval; };
#line 211 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 80: /* "\"'DOUBLE'\"" */
#line 635 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).dval; };
#line 216 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 111: /* "\"'INTEGER'\"" */
#line 634 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).ival; };
#line 221 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "VersionDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 226 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "MainModule" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 231 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "LibraryModule" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 236 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "ModuleDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 241 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "Prolog" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 246 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "SIND_DeclList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 251 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "VFO_DeclList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 256 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "SIND_Decl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 261 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "VFO_Decl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 266 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "Setter" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 271 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "Import" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 276 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "NamespaceDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 281 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "BoundarySpaceDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 286 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "DefaultNamespaceDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 291 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "OptionDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 296 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "OrderingModeDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 301 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "EmptyOrderDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 306 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "CopyNamespacesDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 311 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "DefaultCollationDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 316 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "BaseURIDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 321 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "SchemaImport" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 326 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "URILiteralList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 331 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "SchemaPrefix" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 336 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "ModuleImport" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 341 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "VarDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 346 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "ConstructionDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 351 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "FunctionDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 356 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "ParamList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 361 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "Param" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 366 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "EnclosedExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 371 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "NonNodeEnclosedExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 376 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "QueryBody" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 381 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "Expr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 386 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "ExprSingle" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 391 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "FLWORExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 396 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "ForLetClauseList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 401 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "ForLetClause" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 406 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "ForClause" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 411 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "VarInDeclList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 416 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VarInDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 421 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "PositionalVar" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 426 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "LetClause" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 431 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "VarGetsDeclList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 436 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "VarGetsDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 441 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "WhereClause" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 446 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "GroupByClause" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 451 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "GroupSpecList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 456 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "GroupSpec" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 461 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "GroupCollationSpec" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 466 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "LetClauseList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 471 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OrderByClause" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 476 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "OrderSpecList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 481 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "OrderSpec" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 486 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "OrderModifier" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 491 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "OrderDirSpec" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 496 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "OrderEmptySpec" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 501 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "OrderCollationSpec" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 506 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "QuantifiedExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 511 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "QVarInDeclList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 516 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "QVarInDecl" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 521 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "TypeswitchExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 526 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CaseClauseList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 531 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CaseClause" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 536 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "IfExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 541 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "OrExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 546 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "AndExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 551 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "ComparisonExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 556 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "RangeExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 561 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "AdditiveExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 566 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "MultiplicativeExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 571 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "UnionExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 576 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IntersectExceptExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 581 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "InstanceofExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 586 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "TreatExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 591 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "CastableExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 596 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "CastExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 601 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "UnaryExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 606 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "SignList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 611 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "ValueExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 616 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "GeneralComp" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 621 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ValueComp" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 626 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "NodeComp" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 631 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "ValidateExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 636 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "ExtensionExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 641 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "PragmaList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 646 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "Pragma" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 651 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "PathExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 656 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "RelativePathExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 661 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "StepExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 666 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "AxisStep" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 671 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "ForwardStep" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 676 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ForwardAxis" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 681 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "AbbrevForwardStep" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 686 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "ReverseStep" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 691 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "ReverseAxis" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 696 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "NodeTest" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 701 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "NameTest" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 706 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Wildcard" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 711 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "FilterExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 716 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "PredicateList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 721 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "Predicate" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 726 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "PrimaryExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 731 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Literal" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 736 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "NumericLiteral" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 741 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "VarRef" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 746 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "ParenthesizedExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 751 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ContextItemExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 756 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "OrderedExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 761 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "UnorderedExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 766 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FunctionCall" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 771 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "ArgList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 776 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "Constructor" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 781 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "DirectConstructor" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 786 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "DirElemConstructor" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 791 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "DirElemContentList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 796 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "DirAttributeList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 801 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "DirAttr" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 806 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "DirAttributeValue" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 811 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "Opt_QuoteAttrContentList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 816 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "QuoteAttrContentList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 821 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "Opt_AposAttrContentList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 826 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "AposAttrContentList" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 831 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "QuoteAttrValueContent" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 836 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "AposAttrValueContent" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 841 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "DirElemContent" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 846 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "CommonContent" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 851 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "DirCommentConstructor" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 856 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "DirPIConstructor" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 861 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "CDataSection" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 866 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "ComputedConstructor" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 871 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "CompDocConstructor" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 876 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "CompElemConstructor" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 881 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "CompAttrConstructor" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 886 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "CompTextConstructor" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 891 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "CompCommentConstructor" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 896 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "CompPIConstructor" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 901 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "SingleType" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 906 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "TypeDeclaration" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 911 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "SequenceType" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 916 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "OccurrenceIndicator" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 921 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "ItemType" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 926 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "AtomicType" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 931 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "KindTest" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 936 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "AnyKindTest" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 941 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "DocumentTest" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 946 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "TextTest" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 951 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CommentTest" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 956 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "PITest" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 961 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "AttributeTest" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 966 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "SchemaAttributeTest" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 971 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "ElementTest" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 976 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "SchemaElementTest" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 981 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "TypeName" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 986 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "TypeName_WITH_HOOK" */
#line 640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 991 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "StringLiteral" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 996 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "TryExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 1001 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "CatchListExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 1006 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "CatchExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 1011 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "EvalExpr" */
#line 641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 1016 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 69 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename.getStore()->str());
}
  /* Line 547 of yacc.c.  */
#line 1097 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
#line 757 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 3:
#line 765 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.main]" << endl;
#endif
		;}
    break;

  case 4:
#line 774 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]" << endl;
#endif
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 5:
#line 781 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]" << endl;
#endif
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		;}
    break;

  case 6:
#line 794 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]" << endl;
#endif
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), encoding);
		;}
    break;

  case 7:
#line 802 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]" << endl;
#endif
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (2)].sval)), SYMTAB ((yysemantic_stack_[(5) - (4)].sval)));
    ;}
    break;

  case 8:
#line 815 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MainModule [prolog.querybody]" << endl;
#endif
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)));
		;}
    break;

  case 9:
#line 825 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MainModule [querybody]" << endl;
#endif
			(yyval.node) = new MainModule(LOC ((yyloc)),
								NULL,
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 10:
#line 840 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LibraryModule [ ]" << endl;
#endif
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 11:
#line 855 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleDecl [ ]" << endl;
#endif
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (4)].sval)));
		;}
    break;

  case 12:
#line 870 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [sind]" << endl;
#endif
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 13:
#line 879 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [vfo]" << endl;
#endif
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 14:
#line 888 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [sind.vfo]" << endl;
#endif
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 15:
#line 903 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_DeclList [single]" << endl;
#endif
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 16:
#line 912 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_DeclList [list]" << endl;
#endif
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 17:
#line 929 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_DeclList [single]" << endl;
#endif
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 18:
#line 938 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_DeclList [list]" << endl;
#endif
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 955 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 962 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 969 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 976 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 988 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 995 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 1002 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 1011 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 1024 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 1031 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 1038 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1045 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1052 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1059 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1066 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1075 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1088 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1095 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1113 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NamespaceDecl [ ]" << endl;
#endif
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 38:
#line 1128 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1136 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1150 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultNamespaceDecl [element]" << endl;
#endif
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 41:
#line 1159 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultNamespaceDecl [function]" << endl;
#endif
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 42:
#line 1174 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OptionDecl [ ]" << endl;
#endif
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 43:
#line 1190 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]" << endl;
#endif
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1204 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1212 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1227 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1235 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1249 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]" << endl;
#endif
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 49:
#line 1258 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]" << endl;
#endif
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 50:
#line 1267 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]" << endl;
#endif
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 51:
#line 1276 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]" << endl;
#endif
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 52:
#line 1298 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]" << endl;
#endif
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1312 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]" << endl;
#endif
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1326 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [uri]" << endl;
#endif
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 55:
#line 1336 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [prefix.uri]" << endl;
#endif
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(3) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 56:
#line 1346 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [uri.urilist]" << endl;
#endif
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 57:
#line 1356 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [prefix.uri.aturi]" << endl;
#endif
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(5) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 58:
#line 1372 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "URILiteralList [single]" << endl;
#endif
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 59:
#line 1381 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "URILiteralList [list]" << endl;
#endif
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 60:
#line 1399 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1406 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 62:
#line 1419 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [uri]" << endl;
#endif
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 63:
#line 1428 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [namespace.uri]" << endl;
#endif
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)),
								NULL);
		;}
    break;

  case 64:
#line 1438 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [uri.at_uri.list]" << endl;
#endif
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 65:
#line 1447 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [namespace.uri.at_uri.list]" << endl;
#endif
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(7) - (7)].node)));
		;}
    break;

  case 66:
#line 1464 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [expr]" << endl;
#endif
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 67:
#line 1474 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [external]" << endl;
#endif
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								NULL,
								NULL);
		;}
    break;

  case 68:
#line 1484 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [type.expr]" << endl;
#endif
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 69:
#line 1494 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [type.external]" << endl;
#endif
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (3)].node)),
								NULL);
		;}
    break;

  case 70:
#line 1510 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1518 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1532 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 73:
#line 1542 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,
								(yysemantic_stack_[(5) - (5)].expr),
								ParseConstants::fn_read);
		;}
    break;

  case 74:
#line 1553 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 75:
#line 1564 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_read);
		;}
    break;

  case 76:
#line 1576 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [as_type.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 77:
#line 1588 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								(yysemantic_stack_[(7) - (7)].expr),
								ParseConstants::fn_read);
		;}
    break;

  case 78:
#line 1600 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.as_type.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(8) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(8) - (7)].node)),
								NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 79:
#line 1612 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(8) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(8) - (7)].node)),
								(yysemantic_stack_[(8) - (8)].expr),
								ParseConstants::fn_read);
		;}
    break;

  case 80:
#line 1624 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 81:
#line 1634 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,
								(yysemantic_stack_[(5) - (5)].expr),
								ParseConstants::fn_update);
		;}
    break;

  case 82:
#line 1645 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 83:
#line 1656 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_update);
		;}
    break;

  case 84:
#line 1668 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) as_type.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 85:
#line 1680 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								(yysemantic_stack_[(7) - (7)].expr),
								ParseConstants::fn_update);
		;}
    break;

  case 86:
#line 1692 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.as_type.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(8) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(8) - (7)].node)),
								NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 87:
#line 1704 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(8) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(8) - (7)].node)),
								(yysemantic_stack_[(8) - (8)].expr),
								ParseConstants::fn_update);
		;}
    break;

  case 88:
#line 1722 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParamList [single]" << endl;
#endif
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 89:
#line 1733 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParamList [list]" << endl;
#endif
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 90:
#line 1750 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Param [varname]" << endl;
#endif
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 91:
#line 1759 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Param [varname.type]" << endl;
#endif
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 92:
#line 1774 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1785 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NonNodeEnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 94:
#line 1799 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]" << endl;
#endif
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 95:
#line 1813 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Expr [single]" << endl;
#endif
			Expr* expr_p = new Expr(LOC ((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 96:
#line 1822 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Expr [expr.single]" << endl;
#endif
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 97:
#line 1837 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1844 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1851 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1858 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1865 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1874 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1881 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1888 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1895 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1902 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 107:
#line 1909 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
      cout << "ExprSingle [TryExpr]" << endl;
#endif
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 108:
#line 1916 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 109:
#line 1926 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 110:
#line 1936 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 111:
#line 1947 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [orderby.return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								NULL,NULL,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 112:
#line 1958 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.orderby.return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(5) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(5) - (2)].node)),
                NULL,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 113:
#line 1970 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [groupby.return]" << endl;
#endif
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

  case 114:
#line 1985 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.groupby.return]" << endl;
#endif
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

  case 115:
#line 2000 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [groupby.orderby.return]" << endl;
#endif
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

  case 116:
#line 2015 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.groupby.orderby.return]" << endl;
#endif
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

  case 117:
#line 2036 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [single]" << endl;
#endif
			ForLetClauseList* flc_list_p = new ForLetClauseList(LOC ((yyloc)));
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = flc_list_p;
		;}
    break;

  case 118:
#line 2045 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [list]" << endl;
#endif
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(2) - (1)].node));
			if (flc_list_p) flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 119:
#line 2060 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 120:
#line 2067 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 121:
#line 2080 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]" << endl;
#endif
			(yyval.node) = new ForClause(LOC ((yyloc)),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 122:
#line 2094 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDeclList [single]" << endl;
#endif
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 123:
#line 2103 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDeclList [list]" << endl;
#endif
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 124:
#line 2120 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 125:
#line 2130 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 126:
#line 2141 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [posvar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 127:
#line 2153 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.posvar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 128:
#line 2166 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [scorevar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 129:
#line 2177 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.scorevar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 130:
#line 2189 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [posvar.scorevar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 131:
#line 2201 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.posvar.scorevar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 132:
#line 2219 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]" << endl;
#endif
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 133:
#line 2234 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]" << endl;
#endif
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 134:
#line 2248 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]" << endl;
#endif
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 135:
#line 2263 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [single]" << endl;
#endif
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 136:
#line 2272 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [list.single]" << endl;
#endif
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 137:
#line 2289 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [gets]" << endl;
#endif
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 138:
#line 2300 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [type.gets]" << endl;
#endif
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 139:
#line 2312 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [scorevar.gets]" << endl;
#endif
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 140:
#line 2323 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [type.scorevar.gets]" << endl;
#endif
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 141:
#line 2341 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]" << endl;
#endif
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 142:
#line 2352 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupByClause [groupspec]" << endl;
#endif
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(2) - (2)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 143:
#line 2362 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupByClause [groupspec.let]" << endl;
#endif
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (2)].node)),
                 dynamic_cast<LetClauseList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL);
    ;}
    break;

  case 144:
#line 2372 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupByClause [groupspec.where]" << endl;
#endif
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (2)].node)),
                 NULL,
                 dynamic_cast<WhereClause*>((yysemantic_stack_[(3) - (3)].node)));
    ;}
    break;

  case 145:
#line 2382 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupByClause [groupspec.let.where]" << endl;
#endif
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(4) - (2)].node)),
                 dynamic_cast<LetClauseList*>((yysemantic_stack_[(4) - (3)].node)),
                 dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 146:
#line 2395 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupSpecList [single]" << endl;
#endif
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 147:
#line 2404 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupSpecList [list]" << endl;
#endif
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 148:
#line 2418 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupSpec []" << endl;
#endif
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 149:
#line 2427 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupSpec [collation]" << endl;
#endif
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 150:
#line 2439 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupCollationSpec [ ]" << endl;
#endif
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 151:
#line 2449 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClauseList [single]" << endl;
#endif
      LetClauseList* lc_list_p = new LetClauseList(LOC((yyloc)));
      lc_list_p->push_back(dynamic_cast<LetClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = lc_list_p;
    ;}
    break;

  case 152:
#line 2459 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClauseList [list]" << endl;
#endif
      LetClauseList* lc_list_p = dynamic_cast<LetClauseList*>((yysemantic_stack_[(2) - (1)].node));
      if (lc_list_p) lc_list_p->push_back(dynamic_cast<LetClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    ;}
    break;

  case 153:
#line 2474 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]" << endl;
#endif
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 154:
#line 2482 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [stable]" << endl;
#endif
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)),
								true);
		;}
    break;

  case 155:
#line 2497 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpecList [single]" << endl;
#endif
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 156:
#line 2506 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpecList [list]" << endl;
#endif
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 157:
#line 2523 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single]" << endl;
#endif
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 158:
#line 2532 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single.modifier]" << endl;
#endif
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 159:
#line 2547 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir]" << endl;
#endif
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 160:
#line 2557 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [empty]" << endl;
#endif
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 161:
#line 2567 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [collation]" << endl;
#endif
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 162:
#line 2577 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.empty]" << endl;
#endif
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 163:
#line 2587 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.collation]" << endl;
#endif
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 164:
#line 2597 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [empty.collation]" << endl;
#endif
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 165:
#line 2607 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.empty.collation]" << endl;
#endif
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 166:
#line 2623 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 167:
#line 2630 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 168:
#line 2643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 169:
#line 2651 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 170:
#line 2665 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]" << endl;
#endif
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 171:
#line 2679 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuantifiedExpr [some]" << endl;
#endif
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 172:
#line 2689 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuantifiedExpr [every]" << endl;
#endif
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 173:
#line 2705 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [single]" << endl;
#endif
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 174:
#line 2715 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [list]" << endl;
#endif
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 175:
#line 2730 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDecl [in]" << endl;
#endif
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 176:
#line 2739 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDecl [type.in]" << endl;
#endif
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 177:
#line 2755 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeswitchExpr [cases.default.return]" << endl;
#endif
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(7) - (4)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 178:
#line 2765 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeswitchExpr [cases.default.varname.return]" << endl;
#endif
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(9) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(9) - (4)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval)),
								(yysemantic_stack_[(9) - (9)].expr));
		;}
    break;

  case 179:
#line 2782 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [single]" << endl;
#endif
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 180:
#line 2791 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [list]" << endl;
#endif
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 181:
#line 2806 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClause [case.return]" << endl;
#endif
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 182:
#line 2815 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClause [case.as.return]" << endl;
#endif
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 183:
#line 2831 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]" << endl;
#endif
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 184:
#line 2845 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 185:
#line 2852 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]" << endl;
#endif
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 186:
#line 2866 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 187:
#line 2873 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]" << endl;
#endif
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 188:
#line 2895 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 189:
#line 2902 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.valcomp.ftcontains]" << endl;
#endif
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 190:
#line 2913 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.gencomp.ftcontains]" << endl;
#endif
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<GeneralComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 191:
#line 2924 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "is" | "<<" | ">>" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.nodecomp.ftcontains]" << endl;
#endif
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 192:
#line 2941 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 193:
#line 2948 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range.ftselect]" << endl;
#endif
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 194:
#line 2958 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range.ftselect.ftignore]" << endl;
#endif
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 195:
#line 2974 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 196:
#line 2981 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]" << endl;
#endif
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 197:
#line 2995 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 198:
#line 3002 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 199:
#line 3009 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 200:
#line 3022 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]" << endl;
#endif
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 201:
#line 3029 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 202:
#line 3036 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 203:
#line 3043 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 204:
#line 3050 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 205:
#line 3063 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 206:
#line 3070 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 207:
#line 3078 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 208:
#line 3092 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 3099 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 210:
#line 3106 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 211:
#line 3119 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 212:
#line 3126 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat.seqtype]" << endl;
#endif
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 213:
#line 3141 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 214:
#line 3148 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable.seqtype]" << endl;
#endif
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 215:
#line 3163 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 216:
#line 3170 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast.singletype]" << endl;
#endif
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 217:
#line 3185 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 218:
#line 3192 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary.singletype]" << endl;
#endif
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 219:
#line 3207 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 220:
#line 3214 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [signlist.value]" << endl;
#endif
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 221:
#line 3229 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]" << endl;
#endif
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 222:
#line 3236 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]" << endl;
#endif
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 223:
#line 3243 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 224:
#line 3250 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.-]" << endl;
#endif
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 225:
#line 3265 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 226:
#line 3272 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 227:
#line 3279 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 228:
#line 3293 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq);
		;}
    break;

  case 229:
#line 3300 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne);
		;}
    break;

  case 230:
#line 3307 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt);
		;}
    break;

  case 231:
#line 3314 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_le);
		;}
    break;

  case 232:
#line 3321 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt);
		;}
    break;

  case 233:
#line 3328 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge);
		;}
    break;

  case 234:
#line 3341 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 235:
#line 3348 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 236:
#line 3355 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 237:
#line 3362 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 238:
#line 3369 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 239:
#line 3376 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 240:
#line 3389 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 241:
#line 3396 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 242:
#line 3403 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 243:
#line 3417 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 244:
#line 3424 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [mode.expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 245:
#line 3439 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist]" << endl;
#endif
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 246:
#line 3448 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist.expr]" << endl;
#endif
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 247:
#line 3463 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PragmaList [single]" << endl;
#endif
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 248:
#line 3472 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PragmaList [list]" << endl;
#endif
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 249:
#line 3489 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Pragma [ ]" << endl;
#endif
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 250:
#line 3497 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 251:
#line 3540 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 252:
#line 3547 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 253:
#line 3554 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 254:
#line 3561 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [relative]" << endl;
#endif
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = rpe == NULL ? (yysemantic_stack_[(1) - (1)].expr) : new PathExpr(LOC ((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 255:
#line 3575 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step]" << endl;
#endif
            AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = as != NULL ? new RelativePathExpr(LOC ((yyloc)), ParseConstants::st_slash, new ContextItemExpr(LOC ((yyloc))), (yysemantic_stack_[(1) - (1)].expr)) : (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 256:
#line 3583 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(LOC ((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 257:
#line 3590 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(LOC ((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 258:
#line 3603 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 259:
#line 3610 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 260:
#line 3623 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 261:
#line 3632 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward.predlist]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 262:
#line 3641 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 263:
#line 3650 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse.predlist]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 264:
#line 3665 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 265:
#line 3674 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]" << endl;
#endif
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 266:
#line 3688 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 267:
#line 3695 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 268:
#line 3702 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 269:
#line 3709 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 270:
#line 3716 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 271:
#line 3723 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 272:
#line 3730 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 273:
#line 3743 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 274:
#line 3750 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 275:
#line 3763 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [nodetest]" << endl;
#endif
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 276:
#line 3772 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [..]" << endl;
#endif
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 277:
#line 3787 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 278:
#line 3794 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 279:
#line 3801 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 280:
#line 3808 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 281:
#line 3815 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 282:
#line 3833 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 283:
#line 3840 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 284:
#line 3853 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]" << endl;
#endif
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 285:
#line 3860 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]" << endl;
#endif
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 286:
#line 3873 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [*]" << endl;
#endif
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 287:
#line 3883 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [pref:*]" << endl;
#endif
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 288:
#line 3893 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [*:qname]" << endl;
#endif
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 289:
#line 3909 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 290:
#line 3916 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary.predlist]" << endl;
#endif
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 291:
#line 3931 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [single]" << endl;
#endif
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 292:
#line 3940 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [list]" << endl;
#endif
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 293:
#line 3957 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 294:
#line 3971 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 295:
#line 3978 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 296:
#line 3985 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 297:
#line 3992 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 298:
#line 3999 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 4006 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 4013 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 4020 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 4033 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 4040 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 304:
#line 4053 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.decval);
      delete yylval.decval;
		;}
    break;

  case 305:
#line 4061 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.ival);
      delete yylval.ival;
		;}
    break;

  case 306:
#line 4069 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.dval);
      delete yylval.dval;
		;}
    break;

  case 307:
#line 4083 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]" << endl;
#endif
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 308:
#line 4096 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 309:
#line 4103 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 310:
#line 4117 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]" << endl;
#endif
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 311:
#line 4130 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 312:
#line 4144 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 313:
#line 4203 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [ ]" << endl;
#endif
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 314:
#line 4212 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [arglist]" << endl;
#endif
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 315:
#line 4227 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [single]" << endl;
#endif
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 316:
#line 4236 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [list]" << endl;
#endif
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 317:
#line 4251 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 318:
#line 4258 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 319:
#line 4271 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 320:
#line 4278 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 321:
#line 4285 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 322:
#line 4298 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname/> ]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 323:
#line 4309 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist/> ]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(4) - (3)].node)), 
								NULL);
		;}
    break;

  case 324:
#line 4320 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname></qname>]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 325:
#line 4331 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname>content</qname>]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (6)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(7) - (4)].node)));
		;}
    break;

  case 326:
#line 4342 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist></qname>]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (6)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(7) - (3)].node)),
								NULL);
		;}
    break;

  case 327:
#line 4353 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist>content</qname>]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(8) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(8) - (5)].node)));
		;}
    break;

  case 328:
#line 4371 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [single]" << endl;
#endif
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 329:
#line 4380 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [list]" << endl;
#endif
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 330:
#line 4395 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [single]" << endl;
#endif
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 331:
#line 4404 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [list]" << endl;
#endif
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 332:
#line 4421 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttr [ ]" << endl;
#endif
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 333:
#line 4436 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 334:
#line 4444 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 335:
#line 4458 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]" << endl;
#endif
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 336:
#line 4465 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 337:
#line 4472 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [""]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 338:
#line 4481 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [single]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 339:
#line 4490 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [list ""]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 340:
#line 4501 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [list]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 341:
#line 4518 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 342:
#line 4525 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 343:
#line 4532 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 344:
#line 4541 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [single]" << endl;
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 345:
#line 4550 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [list.'']" << endl;
#endif
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 346:
#line 4561 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [list.single]" << endl;
#endif
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 347:
#line 4578 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 348:
#line 4586 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 349:
#line 4600 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 350:
#line 4608 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 351:
#line 4622 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]" << endl;
#endif
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 352:
#line 4630 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]" << endl;
#endif
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 353:
#line 4638 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cdata]" << endl;
#endif
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 354:
#line 4647 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [common_content]" << endl;
#endif
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 355:
#line 4662 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [char_ref]\n";
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 356:
#line 4671 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 357:
#line 4679 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 358:
#line 4687 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 359:
#line 4701 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]" << endl;
#endif
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 360:
#line 4709 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "DirCommentConstructor [ ]" << endl;
#endif
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 361:
#line 4727 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 362:
#line 4735 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target.charlit]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 363:
#line 4755 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]" << endl;
#endif
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 364:
#line 4773 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 365:
#line 4780 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 366:
#line 4787 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 367:
#line 4794 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 368:
#line 4801 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 369:
#line 4808 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 370:
#line 4821 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 371:
#line 4835 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 372:
#line 4844 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 373:
#line 4853 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 374:
#line 4861 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 375:
#line 4889 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 376:
#line 4898 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 377:
#line 4907 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 378:
#line 4915 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 379:
#line 4929 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 380:
#line 4943 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 381:
#line 4957 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 382:
#line 4966 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 383:
#line 4975 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 384:
#line 4983 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 385:
#line 4997 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic]" << endl;
#endif
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 386:
#line 5006 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic ?]" << endl;
#endif
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 387:
#line 5021 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]" << endl;
#endif
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 388:
#line 5035 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 389:
#line 5044 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type.occurs]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 390:
#line 5053 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 391:
#line 5093 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 392:
#line 5101 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 393:
#line 5109 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 394:
#line 5123 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 395:
#line 5130 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 396:
#line 5137 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]" << endl;
#endif
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 397:
#line 5150 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]" << endl;
#endif
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 398:
#line 5164 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 399:
#line 5171 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 400:
#line 5178 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 401:
#line 5185 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 402:
#line 5192 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 403:
#line 5199 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 404:
#line 5206 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 405:
#line 5213 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 406:
#line 5220 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 407:
#line 5233 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]" << endl;
#endif
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 408:
#line 5246 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 409:
#line 5253 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 410:
#line 5261 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 411:
#line 5275 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]" << endl;
#endif
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 412:
#line 5288 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]" << endl;
#endif
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 413:
#line 5301 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 414:
#line 5308 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 415:
#line 5315 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 416:
#line 5328 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [ ]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 417:
#line 5337 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL);
		;}
    break;

  case 418:
#line 5346 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name.type]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 419:
#line 5355 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 420:
#line 5364 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*.type]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 421:
#line 5379 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 422:
#line 5393 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [ ]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL);
		;}
    break;

  case 423:
#line 5402 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
									NULL);
		;}
    break;

  case 424:
#line 5411 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 425:
#line 5420 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 426:
#line 5429 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 427:
#line 5439 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*.type]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 428:
#line 5449 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*.type]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 429:
#line 5465 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 430:
#line 5489 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]" << endl;
#endif
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 431:
#line 5499 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name?]" << endl;
#endif
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 432:
#line 5522 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]" << endl;
#endif
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 433:
#line 5565 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [strict]" << endl;
#endif
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 434:
#line 5573 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [lax]" << endl;
#endif
    ;}
    break;

  case 435:
#line 5579 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [skip]" << endl;
#endif
    ;}
    break;

  case 436:
#line 5590 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 437:
#line 5599 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.as_first]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 438:
#line 5608 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.as_last]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 439:
#line 5617 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.after]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 440:
#line 5626 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.before]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 441:
#line 5636 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 442:
#line 5645 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.as_first]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 443:
#line 5654 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.as_last]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 444:
#line 5663 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.after]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 445:
#line 5672 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.before]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 446:
#line 5687 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodeExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 447:
#line 5695 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodesExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 448:
#line 5708 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 449:
#line 5717 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceValueOfExpr [value.expr]" << endl;
#endif
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 450:
#line 5732 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 451:
#line 5761 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]" << endl;
#endif
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(6) - (2)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(6) - (4)].expr), (yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 452:
#line 5775 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [single]" << endl;
#endif
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 453:
#line 5784 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [list]" << endl;
#endif
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 454:
#line 5800 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "VarNameDecl [" << driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)) << "]" << endl;
#endif
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 455:
#line 5817 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TryExpr []" << endl;
#endif
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 456:
#line 5827 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchList [single]" << endl;
#endif
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 457:
#line 5837 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchList [list]" << endl;
#endif
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 458:
#line 5851 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchExpr [NameTest]" << endl;
#endif
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 459:
#line 5861 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchExpr [NameTest,VarName]" << endl;
#endif
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(7) - (2)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval)),
                          (yysemantic_stack_[(7) - (7)].expr));
    ;}
    break;

  case 460:
#line 5881 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 461:
#line 5901 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]" << endl;
#endif
		;}
    break;

  case 462:
#line 5907 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]" << endl;
#endif
		;}
    break;

  case 463:
#line 5913 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]" << endl;
#endif
		;}
    break;

  case 464:
#line 5919 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]" << endl;
#endif
		;}
    break;

  case 465:
#line 5931 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]" << endl;
#endif
		;}
    break;

  case 466:
#line 5937 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]" << endl;
#endif
		;}
    break;

  case 467:
#line 5943 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]" << endl;
#endif
		;}
    break;

  case 468:
#line 5949 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]" << endl;
#endif
		;}
    break;

  case 469:
#line 5961 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]" << endl;
#endif
		;}
    break;

  case 470:
#line 5967 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]" << endl;
#endif
		;}
    break;

  case 471:
#line 5979 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]" << endl;
#endif
		;}
    break;

  case 472:
#line 5985 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]" << endl;
#endif
		;}
    break;

  case 473:
#line 5997 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]" << endl;
#endif
		;}
    break;

  case 474:
#line 6003 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]" << endl;
#endif
		;}
    break;

  case 475:
#line 6015 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]" << endl;
#endif
		;}
    break;

  case 476:
#line 6021 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]" << endl;
#endif
		;}
    break;

  case 477:
#line 6033 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]" << endl;
#endif
		;}
    break;

  case 478:
#line 6039 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]" << endl;
#endif
		;}
    break;

  case 479:
#line 6045 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]" << endl;
#endif
		;}
    break;

  case 480:
#line 6057 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]" << endl;
#endif
		;}
    break;

  case 481:
#line 6063 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]" << endl;
#endif
		;}
    break;

  case 482:
#line 6075 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]" << endl;
#endif
		;}
    break;

  case 483:
#line 6081 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]" << endl;
#endif
		;}
    break;

  case 484:
#line 6093 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]" << endl;
#endif
		;}
    break;

  case 485:
#line 6099 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]" << endl;
#endif
		;}
    break;

  case 486:
#line 6105 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]" << endl;
#endif
		;}
    break;

  case 487:
#line 6111 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]" << endl;
#endif
		;}
    break;

  case 488:
#line 6117 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]" << endl;
#endif
		;}
    break;

  case 489:
#line 6129 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]" << endl;
#endif
		;}
    break;

  case 490:
#line 6141 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 491:
#line 6148 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 492:
#line 6155 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 493:
#line 6162 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 494:
#line 6169 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 495:
#line 6176 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 496:
#line 6183 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 497:
#line 6196 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]" << endl;
#endif
		;}
    break;

  case 498:
#line 6202 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]" << endl;
#endif
		;}
    break;

  case 499:
#line 6208 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]" << endl;
#endif
		;}
    break;

  case 500:
#line 6214 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]" << endl;
#endif
		;}
    break;

  case 501:
#line 6226 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]" << endl;
#endif
		;}
    break;

  case 502:
#line 6232 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]" << endl;
#endif
		;}
    break;

  case 503:
#line 6238 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]" << endl;
#endif
		;}
    break;

  case 504:
#line 6244 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]" << endl;
#endif
		;}
    break;

  case 505:
#line 6256 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]" << endl;
#endif
		;}
    break;

  case 506:
#line 6262 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]" << endl;
#endif
		;}
    break;

  case 507:
#line 6274 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]" << endl;
#endif
		;}
    break;

  case 508:
#line 6280 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]" << endl;
#endif
		;}
    break;

  case 509:
#line 6286 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]" << endl;
#endif
		;}
    break;

  case 510:
#line 6292 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]" << endl;
#endif
		;}
    break;

  case 511:
#line 6298 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]" << endl;
#endif
		;}
    break;

  case 512:
#line 6304 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]" << endl;
#endif
		;}
    break;

  case 513:
#line 6310 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]" << endl;
#endif
		;}
    break;

  case 514:
#line 6322 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]" << endl;
#endif
		;}
    break;

  case 515:
#line 6328 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]" << endl;
#endif
		;}
    break;

  case 516:
#line 6340 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]" << endl;
#endif
		;}
    break;

  case 517:
#line 6346 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]" << endl;
#endif
		;}
    break;

  case 518:
#line 6352 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]" << endl;
#endif
		;}
    break;

  case 519:
#line 6358 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]" << endl;
#endif
		;}
    break;

  case 520:
#line 6370 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]" << endl;
#endif
		;}
    break;

  case 521:
#line 6376 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]" << endl;
#endif
		;}
    break;

  case 522:
#line 6382 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]" << endl;
#endif
		;}
    break;

  case 523:
#line 6388 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]" << endl;
#endif
		;}
    break;

  case 524:
#line 6394 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]" << endl;
#endif
		;}
    break;

  case 525:
#line 6406 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 526:
#line 6412 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 527:
#line 6424 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]" << endl;
#endif
		;}
    break;

  case 528:
#line 6430 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]" << endl;
#endif
		;}
    break;

  case 529:
#line 6442 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 530:
#line 6448 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 531:
#line 6460 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]" << endl;
#endif
		;}
    break;

  case 532:
#line 6466 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]" << endl;
#endif
		;}
    break;

  case 533:
#line 6478 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]" << endl;
#endif
		;}
    break;

  case 534:
#line 6490 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]" << endl;
#endif
		;}
    break;

  case 535:
#line 6496 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]" << endl;
#endif
		;}
    break;

  case 536:
#line 6508 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]" << endl;
#endif
		;}
    break;

  case 537:
#line 6514 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]" << endl;
#endif
		;}
    break;

  case 538:
#line 6520 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]" << endl;
#endif
		;}
    break;

  case 539:
#line 6532 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]" << endl;
#endif
		;}
    break;

  case 540:
#line 6538 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]" << endl;
#endif
		;}
    break;

  case 541:
#line 6544 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]" << endl;
#endif
		;}
    break;

  case 542:
#line 6550 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]" << endl;
#endif
		;}
    break;

  case 543:
#line 6556 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]" << endl;
#endif
		;}
    break;

  case 544:
#line 6568 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 545:
#line 6575 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 546:
#line 6582 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 547:
#line 6589 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 548:
#line 6602 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]" << endl;
#endif
		;}
    break;

  case 549:
#line 6614 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]" << endl;
#endif
		;}
    break;

  case 550:
#line 6626 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]" << endl;
#endif
		;}
    break;

  case 551:
#line 6638 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]" << endl;
#endif
		;}
    break;

  case 552:
#line 6644 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]" << endl;
#endif
		;}
    break;

  case 553:
#line 6656 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]" << endl;
#endif
		;}
    break;

  case 554:
#line 6662 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]" << endl;
#endif
		;}
    break;

  case 555:
#line 6668 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 556:
#line 6680 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]" << endl;
#endif
		;}
    break;

  case 557:
#line 6686 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 558:
#line 6698 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ ]" << endl;
#endif
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 7380 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -673;
  const short int
  xquery_parser::yypact_[] =
  {
       770,  1190,  1400,  -673,  -673,    17,  -673,    45,  -673,  -673,
    -673,  3080,    84,   284,  -673,  3080,   151,  -673,   318,   314,
     321,   -12,   333,   202,   244,    38,   355,   376,   358,   -36,
     367,   399,  -673,  -673,  3080,   391,   435,  -673,  -673,  -673,
    3080,    87,   447,  -673,  -673,   451,  3080,   166,   363,  -673,
     455,  1610,  -673,   468,   352,  3080,  -673,   499,    77,  -673,
     542,  -673,  -673,   326,   502,   509,  -673,  3791,  3629,   447,
    -673,   515,  3080,   409,  3080,  3080,  3080,    15,   520,   421,
    3080,  3080,  3080,  3080,  3080,  3080,  3080,   531,   466,   455,
    3731,   587,   980,  -673,  -673,   207,  3080,   427,   433,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,   560,
    -673,  -673,   361,  -673,  -673,  -673,  -673,  -673,  -673,   475,
     586,  -673,  3794,   385,   410,   394,   145,     0,  -673,   523,
     464,   588,   606,  3290,  -673,  -673,  -673,     7,  -673,  -673,
    -673,   256,  -673,   536,   284,  -673,   536,   284,  -673,  -673,
    -673,  -673,   536,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,   235,  -673,   237,  1820,  3080,   241,    28,
    -673,    34,  -673,  -673,   262,  -673,  -673,  -673,  -673,  -673,
    -673,   608,   610,  -673,   637,   641,  -673,  -673,   546,   582,
     659,  -673,  -673,   569,    58,   267,  -673,   532,   533,  -673,
     269,   116,  -673,   121,    57,    16,  -673,   -13,   646,  -673,
     122,   663,   688,   674,   584,   696,   687,    -2,   665,  -673,
    -673,   126,   625,  -673,   270,   105,   556,   558,  -673,   701,
    -673,   605,  3080,   561,   562,  -673,  -673,    23,    43,   271,
    -673,   127,   272,   274,   528,  -673,   -18,  -673,  -673,  -673,
    -673,  -673,     5,    25,   693,   510,   514,   642,    19,  -673,
    3080,    -7,  -673,  -673,  -673,  -673,   720,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,   -24,  -673,  -673,   295,   294,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,   207,    65,  3080,  3080,   669,  3080,  3080,
    3080,  -673,   420,   162,   589,  3460,  3460,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  3460,  3460,  3460,     4,  3460,  3460,  3460,  3460,
    3460,  3460,  3460,  3460,  3460,  3460,  3460,   170,   170,   726,
     726,  -673,  -673,  -673,  2030,  -673,  3629,  3629,  3080,   536,
    -673,  -673,   536,  -673,   536,  -673,  -673,  -673,  -673,   128,
     276,   632,   729,  -673,   729,  -673,  -673,   373,   379,  -673,
    -673,   217,   725,  -673,   298,   170,  -673,  3080,   275,  -673,
    -673,  -673,   638,   732,  -673,   732,  -673,  3080,   647,   678,
    3080,   680,  3080,   681,   -61,   650,    -3,   683,   583,   736,
     673,   736,  -673,   675,   728,  3080,   664,   -21,   690,  -673,
     743,  -673,  -673,  -673,  -673,  -673,  -673,  2240,   277,  -673,
    -673,  3080,   682,  -673,    30,    68,  -673,  -673,   731,  -673,
    -673,  -673,   745,  -673,   402,  3080,  3080,  3080,   417,  3080,
    3080,  3080,  3080,  3080,  3080,  3080,   694,  3080,   616,  3080,
    -673,   295,   295,   -24,  -673,   751,   752,   -24,   753,  -673,
      73,  -673,   613,  -673,  -673,  -673,   521,   735,  -673,   754,
      24,  -673,  -673,   735,  -673,  3080,   350,   620,  3080,   626,
    3080,   586,  -673,  -673,  -673,  -673,  3080,     4,   389,  -673,
     524,   411,   547,   544,  -673,  -673,   545,   372,   394,   394,
      10,   145,   145,   145,   145,     0,     0,  -673,  -673,  -673,
    -673,  -673,  -673,    32,  -673,  -673,  -673,  -673,   689,  -673,
    -673,   279,  -673,  -673,   191,  -673,  3080,  -673,  -673,  2450,
    -673,   635,   636,  -673,  -673,  -673,  -673,   772,   412,   135,
    -673,  -673,   423,   138,  -673,  -673,  -673,  3080,  2660,   698,
     643,   644,   651,   653,  -673,  3080,   447,  -673,   776,  -673,
     780,  3080,   707,  3080,  3080,    -5,   709,   451,  3080,  -673,
     771,   793,   771,  -673,   736,  -673,  3080,  3080,   719,   455,
     677,  -673,   286,   723,  -673,    29,  -673,  -673,   832,  -673,
    -673,  3080,   823,  -673,  -673,    35,  -673,  -673,  -673,  -673,
      39,  -673,   456,    76,  -673,   684,  3080,  3080,  -673,  -673,
    -673,  3080,  3080,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
     531,   692,   639,  -673,  -673,  -673,  -673,  -673,  -673,   115,
     -24,   400,   195,   251,    65,  -673,   829,  -673,  -673,  -673,
    -673,    63,   808,  -673,  3080,   809,   669,  -673,  -673,   -32,
    -673,  3080,   700,  3080,  -673,  3080,  -673,   287,   697,  -673,
    3460,  -673,  -673,  -673,  -673,   296,   457,  -673,     4,   296,
    3460,  3460,   471,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
       4,     4,   457,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,   291,
    -673,  -673,   827,   170,  -673,  3080,  -673,   785,   431,   170,
    -673,  -673,   432,  -673,  -673,   300,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  3080,  -673,  -673,  3080,
     755,  3080,  -673,   783,   839,   834,   771,  -673,  -673,  3080,
    -673,  -673,  -673,  2870,    72,   461,  -673,  -673,   305,   699,
     850,  -673,   851,    56,   846,   724,    13,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  3080,    66,   639,  -673,  -673,  -673,
    3460,  3460,  3460,  3460,   854,   634,   847,  -673,   847,  -673,
    -673,   808,  -673,  -673,  -673,   859,  -673,  -673,  -673,  -673,
    -673,  3080,  -673,  -673,  -673,  -673,   145,  -673,  -673,  -673,
     200,   547,  -673,  -673,   310,  3460,  -673,  -673,   544,  -673,
     629,  -673,  -673,    46,   306,  -673,   170,  -673,  -673,   248,
     170,  -673,  -673,  -673,  -673,  -673,  3080,  -673,  3080,  -673,
     736,  -673,  -673,   309,  -673,  -673,   855,   303,  -673,  -673,
    -673,  -673,   730,   462,  -673,  -673,  -673,  -673,   714,   716,
     872,   861,  3080,   870,  3080,  -673,   257,  -673,   145,   145,
     145,   397,   457,  -673,   260,  -673,   261,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
     384,  -673,  -673,   419,  -673,  -673,   771,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,   727,   170,  -673,   738,
    -673,   822,   784,  3460,   657,   847,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,   744,  3080,   878,  -673,   145,  -673,  -673,
    3080,  -673,   746,  -673,   784,  -673
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     0,     0,   287,   288,   284,   432,     0,   278,   281,
     268,     0,     0,     0,   266,     0,     0,   304,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   267,   270,     0,     0,     0,   310,   276,   306,
       0,     0,     0,   272,   271,     0,     0,     0,     0,   305,
       0,     0,   222,     0,     0,     0,   277,     0,     0,   221,
       0,   280,   279,     0,     0,     0,   269,   251,     0,     0,
     286,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     4,     0,     0,     0,     0,    15,
      17,    19,    20,    21,    27,    22,    25,    26,    31,    32,
      33,    28,    29,    35,    36,    23,    30,    24,     9,    94,
      95,    97,     0,   117,   119,   120,    98,    99,   100,   101,
     184,   186,   188,   192,   195,   197,   200,   205,   208,   211,
     213,   215,   217,     0,   219,   225,   227,     0,   247,   226,
     254,   255,   258,   260,     0,   265,   262,     0,   273,   283,
     285,   259,   289,   294,   302,   295,   296,   297,   300,   301,
     298,   299,   317,   319,   320,   321,   318,   364,   365,   366,
     367,   368,   369,   282,   406,   398,   405,   404,   403,   400,
     402,   399,   401,   303,    34,   102,   103,   105,   104,   106,
     107,   108,   375,     0,   371,     0,     0,     0,     0,     0,
     416,     0,   284,   274,     0,   412,    53,    38,    39,    70,
      71,     0,     0,    52,     0,     0,    46,    47,     0,     0,
       0,    44,    45,     0,     0,     0,   408,     0,     0,   307,
       0,     0,   422,     0,     0,     0,   173,     0,   121,   122,
       0,    62,     0,    54,     0,     0,     0,     0,   134,   135,
     308,     0,     0,   407,     0,     0,     0,     0,   413,     0,
     250,     0,     0,     0,     0,   252,   253,     0,     0,     0,
     411,     0,     0,     0,     0,   360,     0,   433,   434,   435,
     446,   447,     0,     0,     0,     0,     0,     0,     0,   452,
       0,     0,   500,   499,   504,   503,     0,   497,   498,   502,
     506,   524,   513,   535,   522,   501,   505,     0,     0,   534,
      43,   490,   491,   492,   493,   494,   495,   496,     1,     3,
       5,    10,     8,    12,    13,     0,     0,     0,     0,     0,
       0,   118,     0,     0,     0,     0,     0,   228,   242,   233,
     232,   240,   231,   230,   229,   241,   234,   239,   238,   237,
     236,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   224,   223,   220,     0,   248,     0,     0,     0,   261,
     291,   264,   263,   275,   290,   376,   372,   313,   315,     0,
       0,     0,     0,   417,     0,   419,   380,     0,     0,    40,
      41,     0,     0,    42,     0,     0,    67,     0,     0,   370,
     409,   410,     0,     0,   423,     0,   426,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,     0,    55,     0,     0,     0,     0,   309,
       0,   311,   362,   361,   414,   415,   249,     0,     0,   421,
     429,     0,     0,   322,     0,     0,   330,   379,     0,   312,
     243,   359,     0,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     533,     0,     0,   523,   525,     0,     0,   520,     0,   508,
       0,   507,     0,    16,    18,    96,   157,   153,   155,     0,
     142,   146,   109,   154,   141,     0,     0,     0,     0,     0,
       0,   185,   187,   190,   189,   191,     0,     0,     0,   482,
     193,   461,   469,   471,   473,   475,   477,   480,   199,   198,
     196,   202,   203,   204,   201,   206,   207,   210,   209,   397,
     396,   390,   212,   388,   394,   395,   214,   216,   385,   218,
     245,     0,   256,   257,     0,   292,     0,   314,   244,     0,
     430,     0,     0,    50,    51,    48,    49,     0,     0,     0,
      88,    37,     0,     0,   387,    66,    69,     0,     0,   430,
       0,     0,     0,     0,   175,     0,     0,   172,     0,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      64,     0,    56,    60,     0,   137,     0,     0,     0,     0,
       0,   381,     0,     0,   171,     0,   355,   352,     0,   356,
     357,     0,     0,   358,   351,     0,   328,   354,   353,   323,
       0,   331,     0,     0,   179,     0,     0,     0,   439,   440,
     436,     0,     0,   444,   445,   441,   450,   448,   449,   454,
       0,     0,     0,   460,   532,   531,   526,   527,   529,     0,
     521,   516,     0,     0,    14,   166,     0,   167,   168,   169,
     158,   159,   160,   161,     0,   148,     0,   151,   144,   143,
     110,     0,     0,     0,   113,     0,   111,     0,     0,   476,
       0,   194,   489,   537,   536,     0,     0,   538,     0,     0,
       0,     0,   462,   466,   484,   465,   488,   486,   485,   487,
       0,     0,     0,   478,   541,   542,   539,   540,   543,   481,
     391,   393,   392,   389,   386,   246,   293,   316,   377,     0,
     418,   420,    90,     0,    72,     0,    73,     0,     0,     0,
      80,    81,     0,    68,   373,     0,   431,   424,   425,   427,
     428,   176,   174,   132,   133,   126,     0,   128,   125,     0,
       0,     0,   123,     0,     0,    63,    57,   139,   138,     0,
     136,    11,   382,     0,   341,   335,   332,   363,     0,     0,
       0,   329,     0,     0,     0,     0,     0,   180,     7,   437,
     438,   442,   443,   453,     0,     0,   455,   456,   530,   528,
       0,     0,     0,     0,     0,     0,     0,   511,     0,   509,
     170,   162,   163,   164,   156,     0,   149,   147,   152,   145,
     114,     0,   112,   115,   483,   479,   558,   557,   556,   552,
       0,   470,   551,   463,     0,     0,   468,   467,   472,   474,
       0,   378,    91,     0,     0,    89,     0,    74,    75,     0,
       0,    82,    83,   374,   130,   127,     0,   129,     0,    59,
       0,   140,   383,     0,   349,   343,     0,   342,   344,   350,
     347,   337,     0,   336,   338,   348,    92,   324,     0,     0,
       0,     0,     0,     0,     0,   451,     0,   457,   545,   546,
     544,     0,   517,   518,     0,   514,     0,   165,   150,   116,
     555,   554,   553,   548,   549,   464,   550,    76,    77,    93,
       0,    84,    85,     0,   131,   183,    65,   384,   334,   345,
     346,   333,   339,   340,   325,   326,     0,     0,   181,     0,
     177,     0,     0,     0,     0,     0,   512,   510,    78,    79,
      86,    87,   327,     0,     0,     0,   458,   547,   519,   515,
       0,   178,     0,   182,     0,   459
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -673,  -673,  -673,   813,   815,  -673,   816,  -673,   575,   577,
    -313,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -433,  -673,  -673,  -673,  -673,  -673,
     500,   168,  -673,  -552,   821,    22,   -80,  -673,  -673,   798,
    -673,  -673,   317,   485,  -239,  -474,   837,   311,  -468,   585,
    -673,   242,  -673,  -673,  -283,   590,   255,  -673,  -673,   250,
    -628,  -673,   866,   345,  -673,  -673,   301,  -673,  -673,   598,
     601,   297,  -604,   580,   218,  -360,   247,   289,  -673,  -673,
    -673,  -673,  -673,   806,  -673,  -673,  -673,  -673,  -673,  -673,
     804,  -673,   -42,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
     123,   147,  -673,  -673,   -28,   211,  -673,  -348,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -437,  -673,   315,
    -673,   489,  -673,  -673,  -673,  -673,  -673,    74,    79,  -580,
    -494,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,   578,  -228,  -363,  -673,  -673,   308,  -364,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,   924,   925,   176,   537,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,   304,  -673,  -673,
     157,  -673,   438,  -673,  -673,   259,   249,   252,   442,  -673,
    -673,   273,  -673,  -496,  -673,  -673,  -673,  -673,   154,  -311,
    -673,   477,   144,  -673,  -447,  -673,  -673,  -673,  -673,  -672,
    -673,  -673,  -673,  -673,   139,   278,  -673
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   610,   256,   114,   115,   116,   117,
     579,   580,   633,   746,   118,   119,   120,   121,   122,   123,
     124,   248,   249,   434,   435,   125,   258,   259,   342,   343,
     510,   511,   826,   689,   344,   507,   508,   680,   681,   682,
     683,   126,   245,   246,   127,   643,   644,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   362,   363,   364,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   389,   390,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   399,   171,   172,   173,   635,
     465,   466,   786,   882,   883,   876,   877,   884,   878,   636,
     637,   174,   175,   638,   176,   177,   178,   179,   180,   181,
     182,   557,   418,   552,   733,   553,   554,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   571,   591,   193,
     194,   195,   196,   197,   198,   199,   298,   299,   200,   806,
     807,   201,   530,   712,   531,   532,   533,   534,   535,   536,
     537,   713,   714,   320,   321,   322,   323,   324,   904,   905,
     325,   493,   497,   669,   494,   326,   327,   716,   729,   815,
     717,   718,   723,   719,   913,   839,   701
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       290,   291,   292,   293,   294,   295,   296,   501,   612,   541,
     542,   543,   544,   555,   555,   556,   428,   529,   446,   436,
     415,   504,   431,   203,   205,   275,   276,   634,     6,   447,
     751,   415,   431,   208,   840,   715,   687,   214,   474,   626,
     627,   448,   688,   284,   626,   627,   666,   601,   626,   627,
     850,   555,   584,   822,   823,   791,   235,    17,   478,   517,
     519,   784,   240,   462,   429,   626,   627,   486,   250,   491,
     472,   429,   686,   261,   628,   874,   402,   264,     3,   628,
     617,   626,   404,   628,    39,     4,   212,    50,   462,   893,
     415,   415,   266,   375,   279,   432,   281,   282,   283,   445,
     628,   267,   231,   769,   209,   604,   843,   241,   498,   629,
     676,   630,   376,   452,   629,    49,   630,   642,   629,   526,
     630,   221,   384,   226,   227,   527,   398,    26,   392,    28,
     463,    30,    31,   366,   394,   629,   213,   630,   206,   808,
     917,   672,   222,    50,   796,   631,   232,   473,   678,   679,
     631,   629,   416,   630,   631,   639,    60,   492,   367,   417,
     207,   745,   875,   340,   423,   427,   730,   731,   732,   425,
     335,   631,   894,    57,   335,   335,   566,   430,    57,   529,
     529,   776,    57,   747,   461,   785,   747,   631,   403,   673,
     549,   251,   433,   907,   405,   602,   858,   606,   634,    57,
     862,   632,    71,   634,   475,   476,   790,    71,   618,    12,
     792,    71,   285,   791,   489,   828,   847,   464,   477,   340,
     488,   829,    16,   666,   479,   480,    77,   890,    71,   400,
     944,    77,   433,   692,   487,    77,    70,   268,   481,   335,
     433,   915,   640,   816,   210,    35,   528,   242,   433,   453,
     433,   433,    77,    41,   211,   505,   506,   243,   512,   506,
     514,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   809,   424,   391,   555,   795,
     393,   426,   438,   335,   550,   335,   449,   468,   567,   335,
     879,   885,   252,   577,   458,   748,     3,    90,   752,   818,
      54,   918,   336,     4,   212,   941,   874,   922,   945,   945,
     335,   215,   626,    47,    48,   335,    58,   335,   335,   335,
     335,   518,   335,    12,   335,   335,   373,   335,   224,   498,
     495,   339,    64,    65,   335,   335,    16,   585,   374,   335,
     836,   271,   921,   216,   562,   563,    73,   594,   335,   736,
     597,   844,   599,   335,   335,   817,   634,   335,   223,    35,
     529,   504,   499,   745,   551,   615,   770,    41,   949,   586,
     225,   951,   529,   529,   577,   228,   587,   578,   230,   555,
     853,   624,   629,   879,   630,   555,   859,   233,   253,   885,
     956,   229,   395,   929,   396,   648,   649,   650,   401,   653,
     654,   655,   656,   657,   658,   659,   561,   661,    79,   663,
     564,   819,   965,     6,    54,   500,   496,   942,   631,   406,
     946,   947,   386,   387,   419,   234,   422,   451,   467,   469,
      58,   470,   254,   568,   623,   690,   735,   926,   694,    90,
     696,   272,    17,   782,   834,   743,    64,    65,   851,   910,
     898,   899,   900,   901,    70,   911,   749,   863,   582,    45,
      73,   239,   886,   919,   856,   860,   927,   369,   217,    39,
     626,   626,   912,   244,    41,   219,   549,   247,   948,   622,
      50,   257,   573,   262,   880,   880,   737,   218,   575,   255,
     336,   373,   555,   920,   220,    12,   555,   923,   370,   745,
      49,   336,   337,   374,   526,   574,   744,   753,    16,   691,
     527,   576,   263,   950,   852,   761,   265,   750,   371,   339,
     338,   765,   273,   767,   768,   857,   861,   745,   773,   274,
     339,    35,   794,   366,   745,   278,   777,   778,   745,    41,
     629,   629,   630,   630,   286,   837,   745,   745,   697,   702,
     838,   236,   881,   932,    65,   675,   340,   297,   367,   910,
     336,   337,   269,   270,   372,   911,   799,   800,   676,   280,
     550,   801,   802,   555,   953,   943,   631,   631,   373,   515,
     572,   300,   912,   957,   538,   539,    54,   328,   368,   339,
     374,   739,   333,   677,   724,   725,   726,   727,   334,   590,
     565,   592,    58,   565,   506,   565,   678,   679,   335,   702,
     755,   830,   345,   832,   646,   833,   647,   346,    64,    65,
     545,   546,   728,   287,   288,   289,   365,   810,   811,   651,
     379,   652,    73,   377,   959,   664,   665,   703,   812,   813,
     704,   302,   303,   378,   304,   305,   705,   706,   707,   380,
     551,   814,   388,   788,   708,   306,   407,   307,   408,   523,
     524,   525,   409,   709,   547,   548,   410,   411,   308,   710,
     711,   412,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   413,   810,   811,   864,   558,   558,   865,
     414,   867,   420,   421,   437,   812,   813,   703,   439,   871,
     704,   302,   303,   440,   304,   305,   705,   706,   707,   441,
     442,   443,   444,   448,   450,   306,   454,   307,   455,   456,
     457,   459,   460,   709,   895,   471,   482,   483,   308,   845,
     711,   484,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   485,   490,   509,   549,   569,   520,   570,
     581,   909,   589,   588,   596,   595,   598,   600,   603,   607,
     608,   609,   611,   614,   613,   616,   619,   854,   620,   645,
     660,   625,   642,   662,     1,   667,   668,   671,   674,   693,
     685,     2,     3,   684,   700,   695,   924,   720,   925,     4,
       5,   721,   734,   722,     6,   740,   741,     7,   742,     8,
       9,   756,   763,   757,   758,   873,   764,    10,    11,    12,
      13,   759,   938,   760,   940,   766,    14,   771,   775,   774,
     779,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,   783,   787,
      32,    33,   781,   789,    34,    35,    36,    37,    38,   798,
      39,   804,    40,    41,   820,   676,   825,   835,   805,   831,
     415,   577,    42,   866,   869,    43,    44,   868,    45,   870,
     888,   889,   891,   887,   961,    46,    47,    48,   902,   903,
     963,    49,   498,   892,   908,   916,   931,   928,   934,    50,
     935,    51,   936,    52,   937,    53,   939,   954,   955,   745,
      54,   952,   958,   960,   962,   329,   964,   330,   502,    55,
     503,   331,    56,    57,   583,   855,    58,   332,    59,    60,
     341,   605,    61,    62,   772,    63,   301,   516,   827,   513,
     780,   821,    64,    65,    66,   277,    67,    68,    69,   824,
      70,   762,    71,   521,   797,    72,    73,   522,   540,   383,
      74,   385,   896,    75,   641,   793,   930,   933,   559,   237,
     238,    76,   593,   897,   803,   698,    77,   841,    78,   848,
     699,    79,   906,   849,   670,    80,    81,    82,    83,    84,
      85,    86,     0,   914,     1,   846,    87,   842,    88,     0,
      89,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,    90,     0,     6,     0,     0,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,    46,    47,    48,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,    53,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,    69,     0,
      70,     0,    71,     0,     0,    72,    73,     0,     0,     0,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    77,     0,     0,     0,
       0,    79,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     1,     0,    87,     0,    88,     0,
      89,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,    90,     0,     6,     0,     0,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   202,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,    69,     0,
      70,     0,    71,     0,     0,    72,    73,     0,     0,     0,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     1,     0,    87,     0,    88,     0,
      89,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,     6,     0,     0,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   204,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,    69,     0,
      70,     0,    71,     0,     0,    72,    73,     0,     0,     0,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     1,     0,    87,     0,    88,     0,
      89,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,     6,     0,     0,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
     260,     0,    64,    65,    66,     0,    67,    68,    69,     0,
      70,     0,    71,     0,     0,    72,    73,     0,     0,     0,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     1,     0,    87,     0,    88,     0,
      89,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,     6,     0,     0,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
     397,     0,    64,    65,    66,     0,    67,    68,    69,     0,
      70,     0,    71,     0,     0,    72,    73,     0,     0,     0,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     1,     0,    87,     0,    88,     0,
      89,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,     6,     0,     0,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   560,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,    69,     0,
      70,     0,    71,     0,     0,    72,    73,     0,     0,     0,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     1,     0,    87,     0,    88,     0,
      89,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,     6,     0,     0,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   621,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,    69,     0,
      70,     0,    71,     0,     0,    72,    73,     0,     0,     0,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     1,     0,    87,     0,    88,     0,
      89,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,     6,     0,     0,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   738,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,    69,     0,
      70,     0,    71,     0,     0,    72,    73,     0,     0,     0,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     1,     0,    87,     0,    88,     0,
      89,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,     6,     0,     0,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   754,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,    69,     0,
      70,     0,    71,     0,     0,    72,    73,     0,     0,     0,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     1,     0,    87,     0,    88,     0,
      89,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,     6,     0,     0,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   872,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,    69,     0,
      70,     0,    71,     0,     0,    72,    73,     0,     0,     0,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     1,     0,    87,     0,    88,     0,
      89,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,     6,     0,     0,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,    69,     0,
      70,     0,    71,     0,     0,    72,    73,     0,     0,     0,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     1,     0,    87,     0,    88,     0,
      89,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,     6,     0,     0,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,   381,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,   382,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,     0,     0,
      70,     0,    71,     0,     1,    72,    73,     0,     0,     0,
       0,     2,     3,    75,     0,     0,     0,     0,     0,     4,
       5,    76,     0,     0,     6,     0,    77,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,    52,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,     0,     0,
      70,     0,    71,     1,     0,    72,    73,     0,     0,     0,
       2,     3,     0,    75,     0,     0,     0,     0,     4,     5,
       0,    76,     0,     6,     0,     0,    77,     0,     8,     9,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,    34,    35,    36,    37,    38,     0,    39,
       0,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,    56,    57,     0,     0,    58,     0,     0,     0,     0,
       0,    61,    62,     0,    63,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,     1,     0,     0,     0,    70,
       0,    71,     2,     3,    72,    73,     0,     0,     0,     0,
       4,     5,    75,     0,     0,     6,     0,     0,     0,     0,
       8,     9,     0,     0,     0,    77,     0,     0,    10,    11,
      12,    13,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,   347,     0,     0,    43,    44,     0,     0,
       0,   348,     0,     0,   349,     0,   350,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,   351,     0,     0,
       0,   352,    51,     0,     0,     0,   353,     0,     0,     0,
       0,    54,   354,     0,     0,     0,     0,     0,     0,     0,
      55,     0,     0,    56,    57,     0,     0,    58,     0,     0,
       0,     0,     0,    61,    62,   355,    63,     0,     0,     0,
       0,     0,     0,    64,    65,    66,     0,     0,     0,     0,
       0,   302,   303,    71,   304,   305,    72,    73,     0,     0,
       0,     0,     0,     0,    75,   306,     0,   307,     0,   356,
     357,   358,   359,   360,   361,     0,     0,    77,   308,     0,
       0,     0,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        80,    81,    82,    83,    84,    85,    86,   318,   441,   369,
     370,   371,   372,   377,   378,   378,   244,   365,   257,   247,
      33,   334,    35,     1,     2,    67,    68,   464,    24,   257,
     582,    33,    35,    11,   706,   531,   510,    15,    33,     9,
      10,    48,   510,    28,     9,    10,   493,   108,     9,    10,
     722,   415,   415,   681,   682,   635,    34,    53,    33,   342,
     343,    32,    40,    20,    48,     9,    10,    48,    46,    93,
      88,    48,    48,    51,    44,     3,    48,    55,    12,    44,
     101,     9,    48,    44,    80,    19,    20,   119,    20,    76,
      33,    33,    15,    93,    72,   108,    74,    75,    76,   101,
      44,    24,   138,   108,    20,   108,   710,    20,    35,    79,
      47,    81,   112,     8,    79,   111,    81,    41,    79,   115,
      81,   133,   115,    85,    86,   121,   206,    62,   156,    64,
      87,    66,    67,   123,   162,    79,    13,    81,   121,    24,
      94,    68,   154,   119,    68,   115,   182,   165,    85,    86,
     115,    79,    94,    81,   115,    87,   149,   181,   148,   101,
     115,   115,    90,   195,    48,   108,   134,   135,   136,    48,
      48,   115,   159,   143,    48,    48,    48,   161,   143,   527,
     528,   614,   143,    48,   161,   156,    48,   115,   160,   500,
      20,    25,   253,   821,   160,   434,   748,   436,   635,   143,
     752,   171,   172,   640,   199,   200,   171,   172,   447,    39,
     171,   172,   197,   793,   221,   689,   712,   174,   213,   195,
     300,   689,    52,   670,   199,   200,   196,   171,   172,   207,
     902,   196,   253,   516,   215,   196,   170,   160,   213,    48,
     253,   845,   174,    48,   160,    75,   242,   160,   253,   144,
     253,   253,   196,    83,   170,   335,   336,   170,   338,   339,
     340,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,   160,   160,   154,   642,   642,
     157,   160,   160,    48,   114,    48,   160,   160,   160,    48,
     784,   785,   126,    76,   272,   160,    12,   232,   160,    48,
     130,   853,   140,    19,    20,    48,     3,   859,    48,    48,
      48,   160,     9,   106,   107,    48,   146,    48,    48,    48,
      48,   159,    48,    39,    48,    48,   181,    48,   126,    35,
      35,   169,   162,   163,    48,    48,    52,   417,   193,    48,
     700,    15,    94,    25,   386,   387,   176,   427,    48,   158,
     430,   711,   432,    48,    48,   160,   793,    48,    25,    75,
     708,   674,    68,   115,   194,   445,   605,    83,   920,    94,
     126,   923,   720,   721,    76,    20,   101,   160,    20,   743,
     743,   461,    79,   877,    81,   749,   749,    20,    25,   883,
     942,    15,   157,    90,   157,   475,   476,   477,   157,   479,
     480,   481,   482,   483,   484,   485,   384,   487,   201,   489,
     388,   160,   964,    24,   130,   121,   121,   160,   115,   157,
     160,   160,   166,   167,   157,    26,   157,   157,   157,   157,
     146,   157,    69,   157,   157,   515,   157,   870,   518,   232,
     520,   115,    53,   157,   157,    33,   162,   163,   157,   249,
     810,   811,   812,   813,   170,   255,    33,   157,   160,    98,
     176,    26,   157,   157,    33,    33,   157,    73,   154,    80,
       9,     9,   272,    26,    83,   154,    20,    26,    94,   457,
     119,    26,   109,    15,    23,    23,   566,   173,   109,   126,
     140,   181,   856,   856,   173,    39,   860,   860,   104,   115,
     111,   140,   141,   193,   115,   132,    94,   587,    52,   159,
     121,   132,   160,    94,   742,   595,    17,    94,   124,   169,
     159,   601,    20,   603,   604,    94,    94,   115,   608,    20,
     169,    75,    76,   123,   115,    20,   616,   617,   115,    83,
      79,    79,    81,    81,    24,   249,   115,   115,   526,   138,
     254,   160,    91,    91,   163,    34,   195,    26,   148,   249,
     140,   141,    20,    21,   170,   255,   646,   647,    47,   160,
     114,   651,   652,   937,   937,   178,   115,   115,   181,   159,
     404,   115,   272,   943,   366,   367,   130,     0,   178,   169,
     193,   569,   165,    72,   222,   223,   224,   225,   165,   423,
     389,   425,   146,   392,   684,   394,    85,    86,    48,   138,
     588,   691,   137,   693,   212,   695,   214,    31,   162,   163,
     373,   374,   250,   202,   203,   204,   241,   227,   228,   212,
      42,   214,   176,   110,   945,   491,   492,   226,   238,   239,
     229,   230,   231,   179,   233,   234,   235,   236,   237,    43,
     194,   251,   116,   631,   243,   244,    48,   246,    48,   362,
     363,   364,    25,   252,   375,   376,    25,   121,   257,   258,
     259,    89,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,    24,   227,   228,   766,   379,   380,   769,
     121,   771,   160,   160,    48,   238,   239,   226,    35,   779,
     229,   230,   231,    15,   233,   234,   235,   236,   237,    35,
     126,    15,    25,    48,    89,   244,   160,   246,   160,    18,
     115,   160,   160,   252,   804,   197,    33,   217,   257,   258,
     259,   217,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   101,    24,    76,    20,   115,   159,    20,
      25,   831,    20,   115,    76,   108,    76,    76,   108,    76,
     177,    25,    89,    35,    89,   101,    76,   745,    25,    24,
      76,    89,    41,   157,     4,    24,    24,    24,   165,   159,
      26,    11,    12,    48,   260,   159,   866,   240,   868,    19,
      20,   247,   103,   248,    24,   160,   160,    27,    26,    29,
      30,   103,    26,   160,   160,   783,    26,    37,    38,    39,
      40,   160,   892,   160,   894,   108,    46,   108,    25,    48,
     101,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   115,     7,
      70,    71,   165,    20,    74,    75,    76,    77,    78,   165,
      80,   159,    82,    83,    25,    47,    47,   160,   219,   159,
      33,    76,    92,   108,    25,    95,    96,    84,    98,    35,
      20,    20,    26,   174,   954,   105,   106,   107,    24,   245,
     960,   111,    35,   159,    25,   256,   156,    32,   174,   119,
     174,   121,    20,   123,    33,   125,    26,   159,    76,   115,
     130,   174,   245,   159,    26,    92,   160,    92,   333,   139,
     333,    95,   142,   143,   414,   747,   146,    96,   148,   149,
     122,   436,   152,   153,   607,   155,    89,   342,   686,   339,
     619,   681,   162,   163,   164,    69,   166,   167,   168,   684,
     170,   596,   172,   345,   643,   175,   176,   346,   368,   143,
     180,   147,   805,   183,   465,   640,   877,   883,   380,    35,
      35,   191,   425,   806,   660,   527,   196,   708,   198,   720,
     528,   201,   818,   721,   497,   205,   206,   207,   208,   209,
     210,   211,    -1,   844,     4,   712,   216,   709,   218,    -1,
     220,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,   232,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,   166,   167,   168,    -1,
     170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,
     180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,     4,    -1,   216,    -1,   218,    -1,
     220,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,   232,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,   166,   167,   168,    -1,
     170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,
     180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,     4,    -1,   216,    -1,   218,    -1,
     220,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,   166,   167,   168,    -1,
     170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,
     180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,     4,    -1,   216,    -1,   218,    -1,
     220,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,
     160,    -1,   162,   163,   164,    -1,   166,   167,   168,    -1,
     170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,
     180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,     4,    -1,   216,    -1,   218,    -1,
     220,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,
     160,    -1,   162,   163,   164,    -1,   166,   167,   168,    -1,
     170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,
     180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,     4,    -1,   216,    -1,   218,    -1,
     220,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,   166,   167,   168,    -1,
     170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,
     180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,     4,    -1,   216,    -1,   218,    -1,
     220,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,   166,   167,   168,    -1,
     170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,
     180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,     4,    -1,   216,    -1,   218,    -1,
     220,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,   166,   167,   168,    -1,
     170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,
     180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,     4,    -1,   216,    -1,   218,    -1,
     220,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,   166,   167,   168,    -1,
     170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,
     180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,     4,    -1,   216,    -1,   218,    -1,
     220,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,   166,   167,   168,    -1,
     170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,
     180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,     4,    -1,   216,    -1,   218,    -1,
     220,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,   166,   167,   168,    -1,
     170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,
     180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,     4,    -1,   216,    -1,   218,    -1,
     220,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,   166,   167,    -1,    -1,
     170,    -1,   172,    -1,     4,   175,   176,    -1,    -1,    -1,
      -1,    11,    12,   183,    -1,    -1,    -1,    -1,    -1,    19,
      20,   191,    -1,    -1,    24,    -1,   196,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,   166,   167,    -1,    -1,
     170,    -1,   172,     4,    -1,   175,   176,    -1,    -1,    -1,
      11,    12,    -1,   183,    -1,    -1,    -1,    -1,    19,    20,
      -1,   191,    -1,    24,    -1,    -1,   196,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    -1,    74,    75,    76,    77,    78,    -1,    80,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,   142,   143,    -1,    -1,   146,    -1,    -1,    -1,    -1,
      -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,    -1,     4,    -1,    -1,    -1,   170,
      -1,   172,    11,    12,   175,   176,    -1,    -1,    -1,    -1,
      19,    20,   183,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,   196,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    95,    96,    -1,    -1,
      -1,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,   117,   121,    -1,    -1,    -1,   122,    -1,    -1,    -1,
      -1,   130,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,   142,   143,    -1,    -1,   146,    -1,    -1,
      -1,    -1,    -1,   152,   153,   151,   155,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,   230,   231,   172,   233,   234,   175,   176,    -1,    -1,
      -1,    -1,    -1,    -1,   183,   244,    -1,   246,    -1,   185,
     186,   187,   188,   189,   190,    -1,    -1,   196,   257,    -1,
      -1,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,     4,    11,    12,    19,    20,    24,    27,    29,    30,
      37,    38,    39,    40,    46,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    70,    71,    74,    75,    76,    77,    78,    80,
      82,    83,    92,    95,    96,    98,   105,   106,   107,   111,
     119,   121,   123,   125,   130,   139,   142,   143,   146,   148,
     149,   152,   153,   155,   162,   163,   164,   166,   167,   168,
     170,   172,   175,   176,   180,   183,   191,   196,   198,   201,
     205,   206,   207,   208,   209,   210,   211,   216,   218,   220,
     232,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   310,   311,   312,   313,   318,   319,
     320,   321,   322,   323,   324,   329,   345,   348,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   400,   401,   402,   415,   416,   418,   419,   420,   421,
     422,   423,   424,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   443,   444,   445,   446,   447,   448,   449,
     452,   455,   157,   319,   157,   319,   121,   115,   319,    20,
     160,   170,    20,   384,   319,   160,    25,   154,   173,   154,
     173,   133,   154,    25,   126,   126,    85,    86,    20,    15,
      20,   138,   182,    20,    26,   319,   160,   439,   440,    26,
     319,    20,   160,   170,    26,   346,   347,    26,   325,   326,
     319,    25,   126,    25,    69,   126,   309,    26,   330,   331,
     160,   319,    15,   160,   319,    17,    15,    24,   160,    20,
      21,    15,   115,    20,    20,   376,   376,   346,    20,   319,
     160,   319,   319,   319,    28,   197,    24,   202,   203,   204,
     320,   320,   320,   320,   320,   320,   320,    26,   450,   451,
     115,   330,   230,   231,   233,   234,   244,   246,   257,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     467,   468,   469,   470,   471,   474,   479,   480,     0,   287,
     288,   290,   318,   165,   165,    48,   140,   141,   159,   169,
     195,   323,   332,   333,   338,   137,    31,    89,    97,   100,
     102,   113,   117,   122,   128,   151,   185,   186,   187,   188,
     189,   190,   368,   369,   370,   241,   123,   148,   178,    73,
     104,   124,   170,   181,   193,    93,   112,   110,   179,    42,
      43,   123,   148,   367,   115,   374,   166,   167,   116,   388,
     389,   384,   388,   384,   388,   157,   157,   160,   320,   399,
     319,   157,    48,   160,    48,   160,   157,    48,    48,    25,
      25,   121,    89,    24,   121,    33,    94,   101,   426,   157,
     160,   160,   157,    48,   160,    48,   160,   108,   426,    48,
     161,    35,   108,   253,   327,   328,   426,    48,   160,    35,
      15,    35,   126,    15,    25,   101,   328,   426,    48,   160,
      89,   157,     8,   144,   160,   160,    18,   115,   319,   160,
     160,   161,    20,    87,   174,   404,   405,   157,   160,   157,
     157,   197,    88,   165,    33,   199,   200,   213,    33,   199,
     200,   213,    33,   217,   217,   101,    48,   215,   320,   221,
      24,    93,   181,   475,   478,    35,   121,   476,    35,    68,
     121,   473,   292,   293,   294,   320,   320,   339,   340,    76,
     334,   335,   320,   339,   320,   159,   333,   338,   159,   338,
     159,   353,   354,   355,   355,   355,   115,   121,   242,   391,
     456,   458,   459,   460,   461,   462,   463,   464,   358,   358,
     357,   359,   359,   359,   359,   360,   360,   361,   361,    20,
     114,   194,   427,   429,   430,   431,   427,   425,   430,   425,
     157,   319,   376,   376,   319,   389,    48,   160,   157,   115,
      20,   441,   441,   109,   132,   109,   132,    76,   160,   314,
     315,    25,   160,   314,   427,   320,    94,   101,   115,    20,
     441,   442,   441,   442,   320,   108,    76,   320,    76,   320,
      76,   108,   328,   108,   108,   327,   328,    76,   177,    25,
     308,    89,   308,    89,    35,   320,   101,   101,   328,    76,
      25,   157,   319,   157,   320,    89,     9,    10,    44,    79,
      81,   115,   171,   316,   401,   403,   413,   414,   417,    87,
     174,   405,    41,   349,   350,    24,   212,   214,   320,   320,
     320,   212,   214,   320,   320,   320,   320,   320,   320,   320,
      76,   320,   157,   320,   476,   476,   478,    24,    24,   477,
     475,    24,    68,   473,   165,    34,    47,    72,    85,    86,
     341,   342,   343,   344,    48,    26,    48,   329,   332,   337,
     320,   159,   338,   159,   320,   159,   320,   319,   456,   462,
     260,   490,   138,   226,   229,   235,   236,   237,   243,   252,
     258,   259,   457,   465,   466,   467,   481,   484,   485,   487,
     240,   247,   248,   486,   222,   223,   224,   225,   250,   482,
     134,   135,   136,   428,   103,   157,   158,   320,   157,   319,
     160,   160,    26,    33,    94,   115,   317,    48,   160,    33,
      94,   317,   160,   320,   157,   319,   103,   160,   160,   160,
     160,   320,   347,    26,    26,   320,   108,   320,   320,   108,
     328,   108,   326,   320,    48,    25,   308,   320,   320,   101,
     331,   165,   157,   115,    32,   156,   406,     7,   319,    20,
     171,   413,   171,   403,    76,   427,    68,   350,   165,   320,
     320,   320,   320,   451,   159,   219,   453,   454,    24,   160,
     227,   228,   238,   239,   251,   483,    48,   160,    48,   160,
      25,   343,   344,   344,   340,    47,   336,   335,   329,   332,
     320,   159,   320,   320,   157,   160,   359,   249,   254,   489,
     483,   459,   489,   356,   359,   258,   465,   467,   460,   461,
     483,   157,   426,   427,   319,   315,    33,    94,   317,   427,
      33,    94,   317,   157,   320,   320,   108,   320,    84,    25,
      35,   320,   157,   319,     3,    90,   409,   410,   412,   414,
      23,    91,   407,   408,   411,   414,   157,   174,    20,    20,
     171,    26,   159,    76,   159,   320,   385,   454,   359,   359,
     359,   359,    24,   245,   472,   473,   472,   344,    25,   320,
     249,   255,   272,   488,   488,   356,   256,    94,   317,   157,
     427,    94,   317,   427,   320,   320,   308,   157,    32,    90,
     412,   156,    91,   411,   174,   174,    20,    33,   320,    26,
     320,    48,   160,   178,   483,    48,   160,   160,    94,   317,
      94,   317,   174,   427,   159,    76,   317,   359,   245,   473,
     159,   320,    26,   320,   160,   317
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
     535,   536,   537,   538
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   284,   285,   285,   285,   285,   286,   286,   287,   287,
     288,   289,   290,   290,   290,   291,   291,   292,   292,   293,
     293,   293,   293,   294,   294,   294,   294,   295,   295,   295,
     295,   295,   295,   295,   295,   296,   296,   297,   298,   298,
     299,   299,   300,   301,   302,   302,   303,   303,   304,   304,
     304,   304,   305,   306,   307,   307,   307,   307,   308,   308,
     309,   309,   310,   310,   310,   310,   311,   311,   311,   311,
     312,   312,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   314,   314,
     315,   315,   316,   317,   318,   319,   319,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   321,
     321,   321,   321,   321,   321,   321,   321,   322,   322,   323,
     323,   324,   325,   325,   326,   326,   326,   326,   326,   326,
     326,   326,   327,   328,   329,   330,   330,   331,   331,   331,
     331,   332,   333,   333,   333,   333,   334,   334,   335,   335,
     336,   337,   337,   338,   338,   339,   339,   340,   340,   341,
     341,   341,   341,   341,   341,   341,   342,   342,   343,   343,
     344,   345,   345,   346,   346,   347,   347,   348,   348,   349,
     349,   350,   350,   351,   352,   352,   353,   353,   354,   354,
     354,   354,   355,   355,   355,   356,   356,   357,   357,   357,
     358,   358,   358,   358,   358,   359,   359,   359,   360,   360,
     360,   361,   361,   362,   362,   363,   363,   364,   364,   365,
     365,   366,   366,   366,   366,   367,   367,   367,   368,   368,
     368,   368,   368,   368,   369,   369,   369,   369,   369,   369,
     370,   370,   370,   371,   371,   372,   372,   373,   373,   374,
     374,   375,   375,   375,   375,   376,   376,   376,   377,   377,
     378,   378,   378,   378,   379,   379,   380,   380,   380,   380,
     380,   380,   380,   381,   381,   382,   382,   383,   383,   383,
     383,   383,   384,   384,   385,   385,   386,   386,   386,   387,
     387,   388,   388,   389,   390,   390,   390,   390,   390,   390,
     390,   390,   391,   391,   392,   392,   392,   393,   394,   394,
     395,   396,   397,   398,   398,   399,   399,   400,   400,   401,
     401,   401,   402,   402,   402,   402,   402,   402,   403,   403,
     404,   404,   405,   406,   406,   407,   407,   408,   408,   408,
     408,   409,   409,   410,   410,   410,   410,   411,   411,   412,
     412,   413,   413,   413,   413,   414,   414,   414,   414,   415,
     415,   416,   416,   417,   418,   418,   418,   418,   418,   418,
     419,   420,   420,   420,   420,   421,   421,   421,   421,   422,
     423,   424,   424,   424,   424,   425,   425,   426,   427,   427,
     427,   428,   428,   428,   429,   429,   429,   430,   431,   431,
     431,   431,   431,   431,   431,   431,   431,   432,   433,   433,
     433,   434,   435,   436,   436,   436,   437,   437,   437,   437,
     437,   438,   439,   439,   439,   439,   439,   439,   439,   440,
     441,   442,   443,   444,   444,   444,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   446,   446,   447,   447,
     448,   449,   450,   450,   451,   452,   453,   453,   454,   454,
     455,   456,   456,   456,   456,   457,   457,   457,   457,   458,
     458,   459,   459,   460,   460,   461,   461,   462,   462,   462,
     463,   463,   464,   464,   465,   465,   465,   465,   465,   466,
     467,   467,   467,   467,   467,   467,   467,   468,   468,   468,
     468,   469,   469,   469,   469,   470,   470,   471,   471,   471,
     471,   471,   471,   471,   472,   472,   473,   473,   473,   473,
     474,   474,   474,   474,   474,   475,   475,   476,   476,   477,
     477,   478,   478,   479,   480,   480,   481,   481,   481,   482,
     482,   482,   482,   482,   483,   483,   483,   483,   484,   485,
     486,   487,   487,   488,   488,   488,   489,   489,   490
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
       2,     2,     5,     5,     6,     6,     7,     7,     8,     8,
       5,     5,     6,     6,     7,     7,     8,     8,     1,     3,
       2,     3,     3,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     5,     4,     5,     5,     6,     1,     2,     1,
       1,     2,     1,     4,     3,     4,     4,     5,     4,     5,
       5,     6,     3,     3,     2,     1,     4,     3,     4,     4,
       5,     2,     2,     3,     3,     4,     1,     3,     2,     3,
       2,     1,     2,     2,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     2,     2,     3,     1,     1,     1,     1,
       2,     4,     4,     1,     4,     3,     4,     7,     9,     1,
       2,     4,     7,     7,     1,     3,     1,     3,     1,     3,
       3,     3,     1,     3,     4,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     4,     1,     2,     3,
       2,     1,     2,     2,     1,     1,     3,     3,     1,     1,
       1,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     3,     3,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     3,     4,     6,     7,     7,     8,     1,     2,
       1,     2,     3,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     5,     6,     2,     3,     5,     6,     3,
       3,     4,     5,     6,     7,     1,     2,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       3,     2,     2,     2,     3,     3,     2,     3,     5,     3,
       5,     3,     2,     3,     5,     5,     3,     5,     5,     3,
       1,     2,     1,     2,     2,     2,     4,     5,     5,     4,
       4,     4,     5,     5,     4,     4,     2,     2,     4,     4,
       4,     6,     1,     4,     3,     5,     1,     2,     4,     7,
       4,     1,     2,     3,     4,     1,     1,     2,     2,     1,
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
  "\"'quote attribute content'\"", "\"'STRING'\"", "\"'URI'\"",
  "\"'variable name'\"", "\"'validate mode'\"", "\"'XML comment'\"",
  "\"'ancestor::'\"", "\"'ancestor-or-self::'\"", "\"'and'\"", "\"'''\"",
  "\"'as'\"", "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"",
  "\"'attribute::'\"", "\"'<attribute {>'\"", "\"'<attribute (>'\"",
  "\"'@'\"", "\"'case'\"", "\"'<castable as>'\"", "\"'<cast as>'\"",
  "\"'CDATA[['\"", "\"']]'\"", "\"'child::'\"", "\"'collation'\"",
  "\"','\"", "\"'(:'\"", "\"':)'\"", "\"'<comment {>'\"",
  "\"'<comment (>'\"", "\"'DECIMAL'\"", "\"'<declare base URI>'\"",
  "\"'<declare boundary space>'\"", "\"'<declare construction>'\"",
  "\"'<declare copy namespaces>'\"", "\"'<declare default collation>'\"",
  "\"'<declare default element>'\"", "\"'<declare default function>'\"",
  "\"'<declare default order>'\"", "\"'<declare function>'\"",
  "\"'<declare namespace>'\"", "\"'<declare option>'\"",
  "\"'<declare ordering>'\"", "\"'<declare updating function>'\"",
  "\"'<declare var $>'\"", "\"'default'\"", "\"'<default element>'\"",
  "\"'descendant::'\"", "\"'descendant-or-self::'\"", "\"'descending'\"",
  "\"'div'\"", "\"'<document {>'\"", "\"'<document node (>'\"", "\"'$'\"",
  "\"'.'\"", "\"'..'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
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
  "\"'<first into>'\"", "\"'into'\"", "\"'<last into>'\"", "\"'modify'\"",
  "\"'<copy $>'\"", "\"'with'\"", "\"'<try>'\"", "\"'<catch (>'\"",
  "\"'<using>'\"", "\"'<eval>'\"", "\"'all'\"", "\"'<all words>'\"",
  "\"'any'\"", "\"'<any words>'\"", "\"'<at end>'\"", "\"'<at least>'\"",
  "\"'<at most>'\"", "\"'<at start>'\"", "\"'<case insensitive>'\"",
  "\"'<casesensitive>'\"", "\"'<declare ftoption>'\"",
  "\"'<diacritics insensitive>'\"", "\"'<diacritics sensitive>'\"",
  "\"'different'\"", "\"'distance'\"", "\"'<entire content>'\"",
  "\"'exactly'\"", "\"'from'\"", "\"'&&'\"", "\"'ftcontains'\"",
  "\"'ftnot'\"", "\"'||'\"", "\"'language'\"", "\"'levels'\"",
  "\"'lowercase'\"", "\"'<not in>'\"", "\"'occurs'\"", "\"'paragraph'\"",
  "\"'phrase'\"", "\"'relationship'\"", "\"'same'\"", "\"'score'\"",
  "\"'sentence'\"", "\"'sentences'\"", "\"'times'\"", "\"'uppercase'\"",
  "\"'weight'\"", "\"'window'\"", "\"'<without content>'\"",
  "\"'<without diacritics>'\"", "\"'<without stemming>'\"",
  "\"'<without stop words>'\"", "\"'<without thesaurus>'\"",
  "\"'<without wildcards>'\"", "\"'<with default stop words>'\"",
  "\"'<with diacritics>'\"", "\"'<with stemming>'\"",
  "\"'<with stop words>'\"", "\"'<with thesaurus>'\"",
  "\"'<with wildcards>'\"", "\"'words'\"", "FTCONTAINS_REDUCE",
  "RANGE_REDUCE", "ADDITIVE_REDUCE", "MULTIPLICATIVE_REDUCE",
  "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE",
  "COMMA_DOLLAR", "UNARY_PREC", "SEQUENCE_TYPE_REDUCE", "STEP_REDUCE",
  "$accept", "Module", "VersionDecl", "MainModule", "LibraryModule",
  "ModuleDecl", "Prolog", "SIND_DeclList", "VFO_DeclList", "SIND_Decl",
  "VFO_Decl", "Setter", "Import", "NamespaceDecl", "BoundarySpaceDecl",
  "DefaultNamespaceDecl", "OptionDecl", "FTOptionDecl", "OrderingModeDecl",
  "EmptyOrderDecl", "CopyNamespacesDecl", "DefaultCollationDecl",
  "BaseURIDecl", "SchemaImport", "URILiteralList", "SchemaPrefix",
  "ModuleImport", "VarDecl", "ConstructionDecl", "FunctionDecl",
  "ParamList", "Param", "EnclosedExpr", "NonNodeEnclosedExpr", "QueryBody",
  "Expr", "ExprSingle", "FLWORExpr", "ForLetClauseList", "ForLetClause",
  "ForClause", "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar",
  "LetClause", "VarGetsDeclList", "VarGetsDecl", "WhereClause",
  "GroupByClause", "GroupSpecList", "GroupSpec", "GroupCollationSpec",
  "LetClauseList", "OrderByClause", "OrderSpecList", "OrderSpec",
  "OrderModifier", "OrderDirSpec", "OrderEmptySpec", "OrderCollationSpec",
  "QuantifiedExpr", "QVarInDeclList", "QVarInDecl", "TypeswitchExpr",
  "CaseClauseList", "CaseClause", "IfExpr", "OrExpr", "AndExpr",
  "ComparisonExpr", "FTContainsExpr", "RangeExpr", "AdditiveExpr",
  "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
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
       285,     0,    -1,   287,    -1,   286,   287,    -1,   288,    -1,
     286,   288,    -1,   198,    24,   165,    -1,   198,    24,    88,
      24,   165,    -1,   290,   318,    -1,   318,    -1,   289,   290,
      -1,   125,    15,    89,    25,   165,    -1,   291,   165,    -1,
     292,   165,    -1,   291,   165,   292,   165,    -1,   293,    -1,
     291,   165,   293,    -1,   294,    -1,   292,   165,   294,    -1,
     295,    -1,   296,    -1,   297,    -1,   299,    -1,   311,    -1,
     313,    -1,   300,    -1,   301,    -1,   298,    -1,   305,    -1,
     306,    -1,   312,    -1,   302,    -1,   303,    -1,   304,    -1,
     444,    -1,   307,    -1,   310,    -1,    63,    15,    89,    25,
      -1,    55,   154,    -1,    55,   173,    -1,    59,   126,    25,
      -1,    60,   126,    25,    -1,    64,    20,    24,    -1,   232,
     467,    -1,    65,   138,    -1,    65,   182,    -1,    61,    85,
      -1,    61,    86,    -1,    57,   154,    48,   109,    -1,    57,
     154,    48,   132,    -1,    57,   133,    48,   109,    -1,    57,
     133,    48,   132,    -1,    58,    25,    -1,    54,    25,    -1,
     107,    25,    -1,   107,   309,    25,    -1,   107,    25,    35,
     308,    -1,   107,   309,    25,    35,   308,    -1,    25,    -1,
     308,    48,    25,    -1,   126,    15,    89,    -1,    69,   126,
      -1,   106,    25,    -1,   106,   126,    15,    89,    25,    -1,
     106,    25,    35,   308,    -1,   106,   126,    15,    89,    25,
      35,   308,    -1,    67,    26,   101,   320,    -1,    67,    26,
      94,    -1,    67,    26,   426,   101,   320,    -1,    67,    26,
     426,    94,    -1,    56,   154,    -1,    56,   173,    -1,    62,
      20,   121,   160,    94,    -1,    62,    20,   121,   160,   317,
      -1,    62,    20,   121,   314,   160,    94,    -1,    62,    20,
     121,   314,   160,   317,    -1,    62,    20,   121,   160,    33,
     427,    94,    -1,    62,    20,   121,   160,    33,   427,   317,
      -1,    62,    20,   121,   314,   160,    33,   427,    94,    -1,
      62,    20,   121,   314,   160,    33,   427,   317,    -1,    66,
      20,   121,   160,    94,    -1,    66,    20,   121,   160,   317,
      -1,    66,    20,   121,   314,   160,    94,    -1,    66,    20,
     121,   314,   160,   317,    -1,    66,    20,   121,   160,    33,
     427,    94,    -1,    66,    20,   121,   160,    33,   427,   317,
      -1,    66,    20,   121,   314,   160,    33,   427,    94,    -1,
      66,    20,   121,   314,   160,    33,   427,   317,    -1,   315,
      -1,   314,    48,   315,    -1,    76,    26,    -1,    76,    26,
     426,    -1,   115,   319,   157,    -1,   115,   319,   157,    -1,
     319,    -1,   320,    -1,   319,    48,   320,    -1,   321,    -1,
     345,    -1,   348,    -1,   351,    -1,   352,    -1,   445,    -1,
     446,    -1,   448,    -1,   447,    -1,   449,    -1,   452,    -1,
     455,    -1,   322,   159,   320,    -1,   322,   332,   159,   320,
      -1,   322,   338,   159,   320,    -1,   322,   332,   338,   159,
     320,    -1,   322,   333,   159,   320,    -1,   322,   332,   333,
     159,   320,    -1,   322,   333,   338,   159,   320,    -1,   322,
     332,   333,   338,   159,   320,    -1,   323,    -1,   322,   323,
      -1,   324,    -1,   329,    -1,    98,   325,    -1,   326,    -1,
     325,    48,    76,   326,    -1,    26,   108,   320,    -1,    26,
     426,   108,   320,    -1,    26,   327,   108,   320,    -1,    26,
     426,   327,   108,   320,    -1,    26,   328,   108,   320,    -1,
      26,   426,   328,   108,   320,    -1,    26,   327,   328,   108,
     320,    -1,    26,   426,   327,   328,   108,   320,    -1,    35,
      76,    26,    -1,   253,    76,    26,    -1,   119,   330,    -1,
     331,    -1,   330,    48,    76,   331,    -1,    26,   101,   320,
      -1,    26,   426,   101,   320,    -1,    26,   328,   101,   320,
      -1,    26,   426,   328,   101,   320,    -1,   195,   320,    -1,
     141,   334,    -1,   141,   334,   337,    -1,   141,   334,   332,
      -1,   141,   334,   337,   332,    -1,   335,    -1,   334,    48,
     335,    -1,    76,    26,    -1,    76,    26,   336,    -1,    47,
      25,    -1,   329,    -1,   337,   329,    -1,   140,   339,    -1,
     169,   339,    -1,   340,    -1,   339,    48,   340,    -1,   320,
      -1,   320,   341,    -1,   342,    -1,   343,    -1,   344,    -1,
     342,   343,    -1,   342,   344,    -1,   343,   344,    -1,   342,
     343,   344,    -1,    34,    -1,    72,    -1,    85,    -1,    86,
      -1,    47,    25,    -1,   168,   346,   161,   320,    -1,    92,
     346,   161,   320,    -1,   347,    -1,   346,    48,    76,   347,
      -1,    26,   108,   320,    -1,    26,   426,   108,   320,    -1,
     180,   319,   160,   349,    68,   159,   320,    -1,   180,   319,
     160,   349,    68,    76,    26,   159,   320,    -1,   350,    -1,
     349,   350,    -1,    41,   427,   159,   320,    -1,    41,    76,
      26,    33,   427,   159,   320,    -1,   105,   319,   160,   177,
     320,    84,   320,    -1,   353,    -1,   352,   137,   353,    -1,
     354,    -1,   353,    31,   354,    -1,   355,    -1,   355,   369,
     355,    -1,   355,   368,   355,    -1,   355,   370,   355,    -1,
     356,    -1,   356,   241,   456,    -1,   356,   241,   456,   490,
      -1,   357,    -1,   357,   178,   357,    -1,   358,    -1,   357,
     148,   358,    -1,   357,   123,   358,    -1,   359,    -1,   358,
     170,   359,    -1,   358,    73,   359,    -1,   358,   104,   359,
      -1,   358,   124,   359,    -1,   360,    -1,   359,   181,   360,
      -1,   359,   193,   360,    -1,   361,    -1,   360,   112,   361,
      -1,   360,    93,   361,    -1,   362,    -1,   362,   110,   427,
      -1,   363,    -1,   363,   179,   427,    -1,   364,    -1,   364,
      42,   425,    -1,   365,    -1,   365,    43,   425,    -1,   367,
      -1,   366,   367,    -1,   148,    -1,   123,    -1,   366,   148,
      -1,   366,   123,    -1,   371,    -1,   375,    -1,   372,    -1,
      89,    -1,   128,    -1,   122,    -1,   117,    -1,   102,    -1,
     100,    -1,   185,    -1,   190,    -1,   189,    -1,   188,    -1,
     187,    -1,   186,    -1,   113,    -1,   151,    -1,    97,    -1,
     191,   319,   157,    -1,    27,   115,   319,   157,    -1,   373,
     115,   157,    -1,   373,   115,   319,   157,    -1,   374,    -1,
     373,   374,    -1,   149,    20,    18,    -1,   149,    21,    -1,
     166,    -1,   166,   376,    -1,   167,   376,    -1,   376,    -1,
     377,    -1,   377,   166,   376,    -1,   377,   167,   376,    -1,
     378,    -1,   387,    -1,   379,    -1,   379,   388,    -1,   382,
      -1,   382,   388,    -1,   380,   384,    -1,   381,    -1,    46,
      -1,    70,    -1,    37,    -1,   164,    -1,    71,    -1,    96,
      -1,    95,    -1,   384,    -1,    40,   384,    -1,   383,   384,
      -1,    78,    -1,   142,    -1,    29,    -1,   153,    -1,   152,
      -1,    30,    -1,   431,    -1,   385,    -1,    20,    -1,   386,
      -1,   170,    -1,    12,    -1,    19,    -1,   390,    -1,   390,
     388,    -1,   389,    -1,   388,   389,    -1,   116,   319,   158,
      -1,   391,    -1,   393,    -1,   394,    -1,   395,    -1,   398,
      -1,   400,    -1,   396,    -1,   397,    -1,   392,    -1,   443,
      -1,    53,    -1,   111,    -1,    80,    -1,    76,    26,    -1,
     121,   160,    -1,   121,   319,   160,    -1,    77,    -1,   139,
     319,   157,    -1,   183,   319,   157,    -1,    20,   121,   160,
      -1,    20,   121,   399,   160,    -1,   320,    -1,   399,    48,
     320,    -1,   401,    -1,   418,    -1,   402,    -1,   415,    -1,
     416,    -1,   172,    20,    87,    -1,   172,    20,   404,    87,
      -1,   172,    20,   174,   171,    20,   174,    -1,   172,    20,
     174,   403,   171,    20,   174,    -1,   172,    20,   404,   174,
     171,    20,   174,    -1,   172,    20,   404,   174,   403,   171,
      20,   174,    -1,   413,    -1,   403,   413,    -1,   405,    -1,
     404,   405,    -1,    20,    89,   406,    -1,   156,   407,   156,
      -1,    32,   409,    32,    -1,    -1,   408,    -1,    91,    -1,
     411,    -1,   408,    91,    -1,   408,   411,    -1,    -1,   410,
      -1,    90,    -1,   412,    -1,   410,    90,    -1,   410,   412,
      -1,    23,    -1,   414,    -1,     3,    -1,   414,    -1,   401,
      -1,    10,    -1,   417,    -1,   414,    -1,     9,    -1,    79,
      -1,    81,    -1,   316,    -1,   196,    28,   197,    -1,   196,
     197,    -1,   143,    17,   144,    -1,   143,    17,     8,    -1,
      44,     7,    -1,   419,    -1,   420,    -1,   421,    -1,   422,
      -1,   423,    -1,   424,    -1,    74,   319,   157,    -1,    11,
     157,    -1,    11,   319,   157,    -1,    82,   319,   157,   115,
     157,    -1,    82,   319,   157,   115,   319,   157,    -1,     4,
     157,    -1,     4,   319,   157,    -1,    38,   319,   157,   115,
     157,    -1,    38,   319,   157,   115,   319,   157,    -1,   175,
     319,   157,    -1,    51,   319,   157,    -1,   155,    15,   115,
     157,    -1,   155,    15,   115,   319,   157,    -1,   155,   115,
     319,   157,   115,   157,    -1,   155,   115,   319,   157,   115,
     319,   157,    -1,   430,    -1,   430,   103,    -1,    33,   427,
      -1,   429,    -1,   429,   428,    -1,   194,    -1,   134,    -1,
     136,    -1,   135,    -1,   430,    -1,   431,    -1,   114,    -1,
      20,    -1,   433,    -1,   439,    -1,   437,    -1,   440,    -1,
     438,    -1,   436,    -1,   435,    -1,   434,    -1,   432,    -1,
     130,   160,    -1,    75,   160,    -1,    75,   439,   160,    -1,
      75,   440,   160,    -1,   176,   160,    -1,    52,   160,    -1,
     146,   160,    -1,   146,    15,   160,    -1,   146,    24,   160,
      -1,    39,   160,    -1,    39,    20,   160,    -1,    39,    20,
      48,   441,   160,    -1,    39,   170,   160,    -1,    39,   170,
      48,   441,   160,    -1,   162,    20,   160,    -1,    83,   160,
      -1,    83,    20,   160,    -1,    83,    20,    48,   441,   160,
      -1,    83,    20,    48,   442,   160,    -1,    83,   170,   160,
      -1,    83,   170,    48,   441,   160,    -1,    83,   170,    48,
     442,   160,    -1,   163,    20,   160,    -1,    20,    -1,    20,
     103,    -1,    24,    -1,   201,   202,    -1,   201,   203,    -1,
     201,   204,    -1,   207,   320,   213,   320,    -1,   207,   320,
      33,   212,   320,    -1,   207,   320,    33,   214,   320,    -1,
     207,   320,   199,   320,    -1,   207,   320,   200,   320,    -1,
     208,   320,   213,   320,    -1,   208,   320,    33,   212,   320,
      -1,   208,   320,    33,   214,   320,    -1,   208,   320,   199,
     320,    -1,   208,   320,   200,   320,    -1,   205,   320,    -1,
     206,   320,    -1,   210,   320,   217,   320,    -1,   211,   320,
     217,   320,    -1,   209,   320,    33,   320,    -1,   216,   450,
     215,   320,   159,   320,    -1,   451,    -1,   450,    48,    76,
     451,    -1,    26,   101,   320,    -1,   218,   115,   320,   157,
     453,    -1,   454,    -1,   453,   454,    -1,   219,   385,   160,
     317,    -1,   219,   385,    48,    76,    26,   160,   317,    -1,
     220,   330,   221,   320,    -1,   458,    -1,   458,   457,    -1,
     458,   258,   356,    -1,   458,   457,   258,   356,    -1,   467,
      -1,   465,    -1,   457,   467,    -1,   457,   465,    -1,   459,
      -1,   458,   243,   459,    -1,   460,    -1,   459,   240,   460,
      -1,   461,    -1,   460,   247,   461,    -1,   462,    -1,   242,
     462,    -1,   463,    -1,   463,   486,    -1,   121,   456,   160,
      -1,   464,    -1,   464,   482,    -1,   391,    -1,   115,   319,
     157,    -1,   466,    -1,   485,    -1,   484,    -1,   487,    -1,
     481,    -1,   138,    -1,   468,    -1,   469,    -1,   470,    -1,
     471,    -1,   474,    -1,   479,    -1,   480,    -1,   246,    -1,
     257,    -1,   231,    -1,   230,    -1,   267,    -1,   261,    -1,
     234,    -1,   233,    -1,   268,    -1,   262,    -1,   270,   473,
      -1,   270,    68,    -1,   270,   121,   473,   160,    -1,   270,
     121,   473,    48,   472,   160,    -1,   270,   121,    68,   160,
      -1,   270,   121,    68,    48,   472,   160,    -1,   264,    -1,
     473,    -1,   472,    48,   473,    -1,    35,    24,    -1,    35,
      24,   251,    24,    -1,    35,    24,   483,   245,    -1,    35,
      24,   251,    24,   483,   245,    -1,   269,   476,    -1,   269,
     476,   475,    -1,   266,    -1,   266,   475,    -1,   263,    -1,
     478,    -1,   475,   478,    -1,    35,    24,    -1,   121,   477,
     160,    -1,    24,    -1,   477,    24,    -1,   181,   476,    -1,
      93,   476,    -1,   244,    24,    -1,   271,    -1,   265,    -1,
     229,    -1,   226,    -1,   237,    -1,   224,    -1,   225,    -1,
     222,    -1,   223,    -1,   250,    -1,   238,   359,    -1,   227,
     359,    -1,   228,   359,    -1,   239,   359,   178,   359,    -1,
     236,   483,   488,    -1,   259,   359,   488,    -1,   248,   483,
     256,    -1,   252,   489,    -1,   235,   489,    -1,   272,    -1,
     255,    -1,   249,    -1,   254,    -1,   249,    -1,   260,   359,
      -1
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
     233,   236,   239,   245,   251,   258,   265,   273,   281,   290,
     299,   305,   311,   318,   325,   333,   341,   350,   359,   361,
     365,   368,   372,   376,   380,   382,   384,   388,   390,   392,
     394,   396,   398,   400,   402,   404,   406,   408,   410,   412,
     416,   421,   426,   432,   437,   443,   449,   456,   458,   461,
     463,   465,   468,   470,   475,   479,   484,   489,   495,   500,
     506,   512,   519,   523,   527,   530,   532,   537,   541,   546,
     551,   557,   560,   563,   567,   571,   576,   578,   582,   585,
     589,   592,   594,   597,   600,   603,   605,   609,   611,   614,
     616,   618,   620,   623,   626,   629,   633,   635,   637,   639,
     641,   644,   649,   654,   656,   661,   665,   670,   678,   688,
     690,   693,   698,   706,   714,   716,   720,   722,   726,   728,
     732,   736,   740,   742,   746,   751,   753,   757,   759,   763,
     767,   769,   773,   777,   781,   785,   787,   791,   795,   797,
     801,   805,   807,   811,   813,   817,   819,   823,   825,   829,
     831,   834,   836,   838,   841,   844,   846,   848,   850,   852,
     854,   856,   858,   860,   862,   864,   866,   868,   870,   872,
     874,   876,   878,   880,   884,   889,   893,   898,   900,   903,
     907,   910,   912,   915,   918,   920,   922,   926,   930,   932,
     934,   936,   939,   941,   944,   947,   949,   951,   953,   955,
     957,   959,   961,   963,   965,   968,   971,   973,   975,   977,
     979,   981,   983,   985,   987,   989,   991,   993,   995,   997,
     999,  1002,  1004,  1007,  1011,  1013,  1015,  1017,  1019,  1021,
    1023,  1025,  1027,  1029,  1031,  1033,  1035,  1037,  1040,  1043,
    1047,  1049,  1053,  1057,  1061,  1066,  1068,  1072,  1074,  1076,
    1078,  1080,  1082,  1086,  1091,  1098,  1106,  1114,  1123,  1125,
    1128,  1130,  1133,  1137,  1141,  1145,  1146,  1148,  1150,  1152,
    1155,  1158,  1159,  1161,  1163,  1165,  1168,  1171,  1173,  1175,
    1177,  1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,  1195,
    1199,  1202,  1206,  1210,  1213,  1215,  1217,  1219,  1221,  1223,
    1225,  1229,  1232,  1236,  1242,  1249,  1252,  1256,  1262,  1269,
    1273,  1277,  1282,  1288,  1295,  1303,  1305,  1308,  1311,  1313,
    1316,  1318,  1320,  1322,  1324,  1326,  1328,  1330,  1332,  1334,
    1336,  1338,  1340,  1342,  1344,  1346,  1348,  1350,  1353,  1356,
    1360,  1364,  1367,  1370,  1373,  1377,  1381,  1384,  1388,  1394,
    1398,  1404,  1408,  1411,  1415,  1421,  1427,  1431,  1437,  1443,
    1447,  1449,  1452,  1454,  1457,  1460,  1463,  1468,  1474,  1480,
    1485,  1490,  1495,  1501,  1507,  1512,  1517,  1520,  1523,  1528,
    1533,  1538,  1545,  1547,  1552,  1556,  1562,  1564,  1567,  1572,
    1580,  1585,  1587,  1590,  1594,  1599,  1601,  1603,  1606,  1609,
    1611,  1615,  1617,  1621,  1623,  1627,  1629,  1632,  1634,  1637,
    1641,  1643,  1646,  1648,  1652,  1654,  1656,  1658,  1660,  1662,
    1664,  1666,  1668,  1670,  1672,  1674,  1676,  1678,  1680,  1682,
    1684,  1686,  1688,  1690,  1692,  1694,  1696,  1698,  1701,  1704,
    1709,  1716,  1721,  1728,  1730,  1732,  1736,  1739,  1744,  1749,
    1756,  1759,  1763,  1765,  1768,  1770,  1772,  1775,  1778,  1782,
    1784,  1787,  1790,  1793,  1796,  1798,  1800,  1802,  1804,  1806,
    1808,  1810,  1812,  1814,  1816,  1819,  1822,  1825,  1830,  1834,
    1838,  1842,  1845,  1848,  1850,  1852,  1854,  1856,  1858
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   756,   756,   764,   773,   780,   793,   801,   814,   824,
     839,   854,   869,   878,   887,   902,   911,   928,   937,   954,
     961,   968,   975,   987,   994,  1001,  1010,  1023,  1030,  1037,
    1044,  1051,  1058,  1065,  1074,  1087,  1094,  1112,  1127,  1135,
    1149,  1158,  1173,  1189,  1203,  1211,  1226,  1234,  1248,  1257,
    1266,  1275,  1297,  1311,  1325,  1335,  1345,  1355,  1371,  1380,
    1398,  1405,  1418,  1427,  1437,  1446,  1463,  1473,  1483,  1493,
    1509,  1517,  1531,  1541,  1552,  1563,  1575,  1587,  1599,  1611,
    1623,  1633,  1644,  1655,  1667,  1679,  1691,  1703,  1721,  1732,
    1749,  1758,  1773,  1784,  1798,  1812,  1821,  1836,  1843,  1850,
    1857,  1864,  1873,  1880,  1887,  1894,  1901,  1908,  1915,  1925,
    1935,  1946,  1957,  1969,  1984,  1999,  2014,  2035,  2044,  2059,
    2066,  2079,  2093,  2102,  2119,  2129,  2140,  2152,  2165,  2176,
    2188,  2200,  2218,  2233,  2247,  2262,  2271,  2288,  2299,  2311,
    2322,  2340,  2351,  2361,  2371,  2381,  2394,  2403,  2417,  2426,
    2438,  2448,  2458,  2473,  2481,  2496,  2505,  2522,  2531,  2546,
    2556,  2566,  2576,  2586,  2596,  2606,  2622,  2629,  2642,  2650,
    2664,  2678,  2688,  2704,  2714,  2729,  2738,  2754,  2764,  2781,
    2790,  2805,  2814,  2830,  2844,  2851,  2865,  2872,  2894,  2901,
    2912,  2923,  2940,  2947,  2957,  2973,  2980,  2994,  3001,  3008,
    3021,  3028,  3035,  3042,  3049,  3062,  3069,  3077,  3091,  3098,
    3105,  3118,  3125,  3140,  3147,  3162,  3169,  3184,  3191,  3206,
    3213,  3228,  3235,  3242,  3249,  3264,  3271,  3278,  3292,  3299,
    3306,  3313,  3320,  3327,  3340,  3347,  3354,  3361,  3368,  3375,
    3388,  3395,  3402,  3416,  3423,  3438,  3447,  3462,  3471,  3488,
    3497,  3539,  3546,  3553,  3560,  3574,  3582,  3589,  3602,  3609,
    3622,  3631,  3640,  3649,  3664,  3673,  3687,  3694,  3701,  3708,
    3715,  3722,  3729,  3742,  3749,  3762,  3771,  3786,  3793,  3800,
    3807,  3814,  3832,  3839,  3852,  3859,  3872,  3882,  3892,  3908,
    3915,  3930,  3939,  3956,  3970,  3977,  3984,  3991,  3998,  4005,
    4012,  4019,  4032,  4039,  4052,  4060,  4068,  4082,  4095,  4102,
    4116,  4129,  4143,  4202,  4211,  4226,  4235,  4250,  4257,  4270,
    4277,  4284,  4297,  4308,  4319,  4330,  4341,  4352,  4370,  4379,
    4394,  4403,  4420,  4435,  4443,  4458,  4464,  4471,  4480,  4489,
    4500,  4518,  4524,  4531,  4540,  4549,  4560,  4577,  4585,  4599,
    4607,  4621,  4629,  4637,  4646,  4661,  4670,  4678,  4686,  4700,
    4708,  4726,  4734,  4754,  4772,  4779,  4786,  4793,  4800,  4807,
    4820,  4834,  4843,  4852,  4860,  4888,  4897,  4906,  4914,  4928,
    4942,  4956,  4965,  4974,  4982,  4996,  5005,  5020,  5034,  5043,
    5052,  5092,  5100,  5108,  5122,  5129,  5136,  5149,  5163,  5170,
    5177,  5184,  5191,  5198,  5205,  5212,  5219,  5232,  5245,  5252,
    5260,  5274,  5287,  5300,  5307,  5314,  5327,  5336,  5345,  5354,
    5363,  5378,  5392,  5401,  5410,  5419,  5428,  5438,  5448,  5464,
    5488,  5498,  5521,  5564,  5572,  5578,  5589,  5598,  5607,  5616,
    5625,  5635,  5644,  5653,  5662,  5671,  5686,  5694,  5707,  5716,
    5731,  5760,  5774,  5783,  5799,  5816,  5826,  5836,  5850,  5860,
    5880,  5900,  5906,  5912,  5918,  5930,  5936,  5942,  5948,  5960,
    5966,  5978,  5984,  5996,  6002,  6014,  6020,  6032,  6038,  6044,
    6056,  6062,  6074,  6080,  6092,  6098,  6104,  6110,  6116,  6128,
    6140,  6147,  6154,  6161,  6168,  6175,  6182,  6195,  6201,  6207,
    6213,  6225,  6231,  6237,  6243,  6255,  6261,  6273,  6279,  6285,
    6291,  6297,  6303,  6309,  6321,  6327,  6339,  6345,  6351,  6357,
    6369,  6375,  6381,  6387,  6393,  6405,  6411,  6423,  6429,  6441,
    6447,  6459,  6465,  6477,  6489,  6495,  6507,  6513,  6519,  6531,
    6537,  6543,  6549,  6555,  6567,  6574,  6581,  6588,  6601,  6613,
    6625,  6637,  6643,  6655,  6661,  6667,  6679,  6685,  6697
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
     275,   276,   277,   278,   279,   280,   281,   282,   283
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 4002;
  const int xquery_parser::yynnts_ = 207;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 328;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 284;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 538;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 6707 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"



/*
	The error member function registers the errors to the driver.
*/

void zorba::xquery_parser::error(
	zorba::xquery_parser::location_type const& loc,
	std::string const& msg)
{
  driver.error(loc, msg);
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

