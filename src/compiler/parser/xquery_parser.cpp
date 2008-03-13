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
#line 721 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 51 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"

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
#line 621 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).decval; };
#line 211 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 80: /* "\"'DOUBLE'\"" */
#line 620 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).dval; };
#line 216 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 111: /* "\"'INTEGER'\"" */
#line 619 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).ival; };
#line 221 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 283: /* "VersionDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 226 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 284: /* "MainModule" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 231 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 285: /* "LibraryModule" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 236 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "ModuleDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 241 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "Prolog" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 246 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "SIND_DeclList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 251 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "VFO_DeclList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 256 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "SIND_Decl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 261 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "VFO_Decl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 266 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "Setter" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 271 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "Import" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 276 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "NamespaceDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 281 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "BoundarySpaceDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 286 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "DefaultNamespaceDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 291 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "OptionDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 296 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "OrderingModeDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 301 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "EmptyOrderDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 306 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "CopyNamespacesDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 311 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "DefaultCollationDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 316 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "BaseURIDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 321 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "SchemaImport" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 326 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "URILiteralList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 331 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "SchemaPrefix" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 336 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "ModuleImport" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 341 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "VarDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 346 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "ConstructionDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 351 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "FunctionDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 356 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "ParamList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 361 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "Param" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 366 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "EnclosedExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 371 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "QueryBody" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 376 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "Expr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 381 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "ExprSingle" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 386 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "FLWORExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 391 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "ForLetClauseList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 396 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "ForLetClause" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 401 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "ForClause" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 406 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "VarInDeclList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 411 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "VarInDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 416 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "PositionalVar" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 421 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "LetClause" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 426 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VarGetsDeclList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 431 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VarGetsDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 436 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "WhereClause" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 441 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "OrderByClause" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 446 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "OrderSpecList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 451 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "OrderSpec" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 456 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "OrderModifier" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 461 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "OrderDirSpec" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 466 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "OrderEmptySpec" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 471 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "OrderCollationSpec" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 476 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "QuantifiedExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 481 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "QVarInDeclList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 486 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "QVarInDecl" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 491 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "TypeswitchExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 496 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "CaseClauseList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 501 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "CaseClause" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 506 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "IfExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 511 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "OrExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 516 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "AndExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 521 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ComparisonExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 526 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "RangeExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 531 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "AdditiveExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 536 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "MultiplicativeExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 541 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "UnionExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 546 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "IntersectExceptExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 551 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "InstanceofExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 556 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "TreatExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 561 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CastableExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 566 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CastExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 571 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "UnaryExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 576 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "SignList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 581 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "ValueExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 586 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "GeneralComp" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 591 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "ValueComp" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 596 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "NodeComp" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 601 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "ValidateExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 606 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "ExtensionExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 611 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "PragmaList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 616 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "Pragma" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 621 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "PathExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "RelativePathExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 631 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "StepExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 636 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "AxisStep" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 641 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ForwardStep" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 646 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "ForwardAxis" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 651 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "AbbrevForwardStep" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 656 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "ReverseStep" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 661 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "ReverseAxis" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 666 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "NodeTest" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 671 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "NameTest" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 676 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "Wildcard" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 681 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FilterExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 686 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "PredicateList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 691 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "Predicate" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 696 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "PrimaryExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 701 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Literal" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 706 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "NumericLiteral" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 711 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "VarRef" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 716 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "ParenthesizedExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 721 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ContextItemExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 726 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "OrderedExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 731 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "UnorderedExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 736 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "FunctionCall" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 741 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "ArgList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 746 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Constructor" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 751 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "DirectConstructor" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 756 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "DirElemConstructor" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 761 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "DirElemContentList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 766 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "DirAttributeList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 771 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "DirAttr" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 776 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "DirAttributeValue" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 781 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "Opt_QuoteAttrContentList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 786 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "QuoteAttrContentList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 791 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "Opt_AposAttrContentList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 796 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "AposAttrContentList" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 801 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "QuoteAttrValueContent" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 806 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "AposAttrValueContent" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 811 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "DirElemContent" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 816 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "CommonContent" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 821 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "DirCommentConstructor" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 826 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "DirPIConstructor" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 831 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "CDataSection" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 836 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "ComputedConstructor" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 841 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CompDocConstructor" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 846 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CompElemConstructor" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 851 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "CompAttrConstructor" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 856 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "CompTextConstructor" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 861 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "CompCommentConstructor" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 866 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "CompPIConstructor" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 871 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "SingleType" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 876 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "TypeDeclaration" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 881 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "SequenceType" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 886 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OccurrenceIndicator" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 891 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "ItemType" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 896 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "AtomicType" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 901 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "KindTest" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 906 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "AnyKindTest" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 911 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "DocumentTest" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 916 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "TextTest" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 921 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "CommentTest" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 926 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "PITest" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 931 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "AttributeTest" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 936 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "SchemaAttributeTest" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 941 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "ElementTest" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 946 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "SchemaElementTest" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 951 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "TypeName" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 956 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "TypeName_WITH_HOOK" */
#line 625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 961 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "StringLiteral" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 966 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "TryExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 971 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "CatchListExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 976 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "CatchExpr" */
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 981 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 68 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = driver.theFilename.getStore();
}
  /* Line 547 of yacc.c.  */
#line 1062 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
#line 742 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 3:
#line 750 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.main]" << endl;
#endif
		;}
    break;

  case 4:
#line 758 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]" << endl;
#endif
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 5:
#line 765 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]" << endl;
#endif
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		;}
    break;

  case 6:
#line 778 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]" << endl;
#endif
       std::string encoding;
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), encoding);
		;}
    break;

  case 7:
#line 786 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]" << endl;
#endif
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (2)].sval)), SYMTAB ((yysemantic_stack_[(5) - (4)].sval)));
    ;}
    break;

  case 8:
#line 799 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 809 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 824 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 839 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 854 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 863 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 872 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 887 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 896 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 913 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 922 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 939 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 946 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 953 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 960 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 972 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 979 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 986 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 995 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 1008 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 1015 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 1022 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1029 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1036 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1043 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1050 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1059 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1072 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1079 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1097 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1112 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1120 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1134 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1143 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1158 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1174 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]" << endl;
#endif
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1188 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1196 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1211 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1219 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1233 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1242 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1251 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1260 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1282 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]" << endl;
#endif
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1296 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]" << endl;
#endif
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1310 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1320 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1330 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1340 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1356 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1365 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1383 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1390 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 62:
#line 1403 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1412 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1422 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1431 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1448 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1458 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1468 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1478 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1494 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1502 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1516 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1526 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(5) - (5)].expr)),
								ParseConstants::fn_read);
		;}
    break;

  case 74:
#line 1537 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1548 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(6) - (6)].expr)),
								ParseConstants::fn_read);
		;}
    break;

  case 76:
#line 1560 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1572 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(7) - (7)].expr)),
								ParseConstants::fn_read);
		;}
    break;

  case 78:
#line 1584 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1596 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(8) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(8) - (7)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(8) - (8)].expr)),
								ParseConstants::fn_read);
		;}
    break;

  case 80:
#line 1608 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1618 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(5) - (5)].expr)),
								ParseConstants::fn_update);
		;}
    break;

  case 82:
#line 1629 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1640 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(6) - (6)].expr)),
								ParseConstants::fn_update);
		;}
    break;

  case 84:
#line 1652 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1664 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(7) - (7)].expr)),
								ParseConstants::fn_update);
		;}
    break;

  case 86:
#line 1676 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1688 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(8) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(8) - (7)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(8) - (8)].expr)),
								ParseConstants::fn_update);
		;}
    break;

  case 88:
#line 1706 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1717 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1734 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1743 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1758 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1772 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]" << endl;
#endif
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 94:
#line 1786 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Expr [single]" << endl;
#endif
			Expr* expr_p = new Expr(LOC ((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 95:
#line 1795 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Expr [expr.single]" << endl;
#endif
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 96:
#line 1810 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 97:
#line 1817 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1824 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1831 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1838 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1847 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1854 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1861 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1868 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1875 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1882 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
      cout << "ExprSingle [TryExpr]" << endl;
#endif
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 107:
#line 1895 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 108:
#line 1905 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 109:
#line 1916 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [orderby.return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								NULL,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 110:
#line 1927 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.orderby.return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(5) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 111:
#line 1944 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [single]" << endl;
#endif
			ForLetClauseList* flc_list_p = new ForLetClauseList(LOC ((yyloc)));
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = flc_list_p;
		;}
    break;

  case 112:
#line 1953 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [list]" << endl;
#endif
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(2) - (1)].node));
			if (flc_list_p) flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 113:
#line 1968 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 114:
#line 1975 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 115:
#line 1988 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]" << endl;
#endif
			(yyval.node) = new ForClause(LOC ((yyloc)),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 116:
#line 2002 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDeclList [single]" << endl;
#endif
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 117:
#line 2011 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 118:
#line 2028 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 119:
#line 2038 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 120:
#line 2049 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 121:
#line 2061 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 122:
#line 2074 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 123:
#line 2085 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 124:
#line 2097 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 125:
#line 2109 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 126:
#line 2127 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]" << endl;
#endif
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 127:
#line 2142 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]" << endl;
#endif
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 128:
#line 2156 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]" << endl;
#endif
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 129:
#line 2171 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [single]" << endl;
#endif
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 130:
#line 2180 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 131:
#line 2197 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 132:
#line 2208 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 133:
#line 2220 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 134:
#line 2231 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 135:
#line 2249 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]" << endl;
#endif
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 136:
#line 2263 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]" << endl;
#endif
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 137:
#line 2271 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [stable]" << endl;
#endif
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)),
								true);
		;}
    break;

  case 138:
#line 2286 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpecList [single]" << endl;
#endif
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 139:
#line 2295 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 140:
#line 2312 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single]" << endl;
#endif
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 141:
#line 2321 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single.modifier]" << endl;
#endif
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 142:
#line 2336 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 143:
#line 2346 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 144:
#line 2356 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 145:
#line 2366 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 146:
#line 2376 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 147:
#line 2386 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 148:
#line 2396 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 149:
#line 2412 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 150:
#line 2419 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 151:
#line 2432 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 152:
#line 2440 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 153:
#line 2454 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]" << endl;
#endif
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 154:
#line 2468 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 155:
#line 2478 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 156:
#line 2494 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [single]" << endl;
#endif
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 157:
#line 2504 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [list]" << endl;
#endif
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 158:
#line 2519 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDecl [in]" << endl;
#endif
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 159:
#line 2528 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 160:
#line 2544 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 161:
#line 2554 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 162:
#line 2571 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [single]" << endl;
#endif
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 163:
#line 2580 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [list]" << endl;
#endif
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 164:
#line 2595 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClause [case.return]" << endl;
#endif
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 165:
#line 2604 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 166:
#line 2620 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]" << endl;
#endif
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 167:
#line 2634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 168:
#line 2641 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]" << endl;
#endif
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 169:
#line 2655 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 170:
#line 2662 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]" << endl;
#endif
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 171:
#line 2684 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 172:
#line 2691 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 173:
#line 2702 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 174:
#line 2713 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 175:
#line 2730 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 176:
#line 2737 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 177:
#line 2747 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 178:
#line 2763 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 179:
#line 2770 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]" << endl;
#endif
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 180:
#line 2784 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 181:
#line 2791 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 182:
#line 2798 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 183:
#line 2811 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]" << endl;
#endif
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 184:
#line 2818 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 185:
#line 2825 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 186:
#line 2832 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 187:
#line 2839 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 188:
#line 2852 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 189:
#line 2859 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 190:
#line 2867 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 191:
#line 2881 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 192:
#line 2888 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 193:
#line 2895 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 194:
#line 2908 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 195:
#line 2915 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat.seqtype]" << endl;
#endif
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 196:
#line 2930 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 197:
#line 2937 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable.seqtype]" << endl;
#endif
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 198:
#line 2952 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 199:
#line 2959 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast.singletype]" << endl;
#endif
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 200:
#line 2974 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 201:
#line 2981 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary.singletype]" << endl;
#endif
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 202:
#line 2996 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 203:
#line 3003 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [signlist.value]" << endl;
#endif
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 204:
#line 3018 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]" << endl;
#endif
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 205:
#line 3025 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]" << endl;
#endif
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 206:
#line 3032 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 207:
#line 3039 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.-]" << endl;
#endif
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 208:
#line 3054 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 3061 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 3068 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 211:
#line 3082 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq);
		;}
    break;

  case 212:
#line 3089 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne);
		;}
    break;

  case 213:
#line 3096 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt);
		;}
    break;

  case 214:
#line 3103 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_le);
		;}
    break;

  case 215:
#line 3110 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt);
		;}
    break;

  case 216:
#line 3117 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge);
		;}
    break;

  case 217:
#line 3130 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 218:
#line 3137 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 219:
#line 3144 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 220:
#line 3151 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 221:
#line 3158 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 222:
#line 3165 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 223:
#line 3178 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 224:
#line 3185 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 225:
#line 3192 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 226:
#line 3206 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 227:
#line 3213 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [mode.expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 228:
#line 3228 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist]" << endl;
#endif
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 229:
#line 3237 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist.expr]" << endl;
#endif
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 230:
#line 3252 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PragmaList [single]" << endl;
#endif
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 231:
#line 3261 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 232:
#line 3278 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Pragma [ ]" << endl;
#endif
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 233:
#line 3286 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 234:
#line 3329 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 235:
#line 3336 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 236:
#line 3343 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 237:
#line 3350 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [relative]" << endl;
#endif
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = rpe == NULL ? (yysemantic_stack_[(1) - (1)].expr) : new PathExpr(LOC ((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 238:
#line 3364 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step]" << endl;
#endif
            AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = as != NULL ? new RelativePathExpr(LOC ((yyloc)), ParseConstants::st_slash, new ContextItemExpr(LOC ((yyloc))), (yysemantic_stack_[(1) - (1)].expr)) : (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 239:
#line 3372 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(LOC ((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 240:
#line 3379 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(LOC ((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 241:
#line 3392 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 242:
#line 3399 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 243:
#line 3412 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 244:
#line 3421 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward.predlist]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 245:
#line 3430 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 246:
#line 3439 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse.predlist]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 247:
#line 3454 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 248:
#line 3463 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]" << endl;
#endif
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 249:
#line 3477 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 250:
#line 3484 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 251:
#line 3491 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 252:
#line 3498 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 253:
#line 3505 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 254:
#line 3512 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 255:
#line 3519 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 256:
#line 3532 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 257:
#line 3539 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 258:
#line 3552 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [nodetest]" << endl;
#endif
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 259:
#line 3561 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [..]" << endl;
#endif
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 260:
#line 3576 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 261:
#line 3583 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 262:
#line 3590 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 263:
#line 3597 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 264:
#line 3604 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 265:
#line 3622 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 266:
#line 3629 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 267:
#line 3642 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]" << endl;
#endif
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 268:
#line 3649 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]" << endl;
#endif
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 269:
#line 3662 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 270:
#line 3672 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 271:
#line 3682 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 272:
#line 3698 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 273:
#line 3705 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary.predlist]" << endl;
#endif
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 274:
#line 3720 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [single]" << endl;
#endif
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 275:
#line 3729 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 276:
#line 3746 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 277:
#line 3760 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 278:
#line 3767 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 279:
#line 3774 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 280:
#line 3781 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 281:
#line 3788 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 3795 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 283:
#line 3802 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 284:
#line 3809 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 285:
#line 3822 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 286:
#line 3829 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 287:
#line 3842 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.decval);
      delete yylval.decval;
		;}
    break;

  case 288:
#line 3850 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.ival);
      delete yylval.ival;
		;}
    break;

  case 289:
#line 3858 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.dval);
      delete yylval.dval;
		;}
    break;

  case 290:
#line 3872 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]" << endl;
#endif
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 291:
#line 3885 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 292:
#line 3892 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 293:
#line 3906 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]" << endl;
#endif
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 294:
#line 3919 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 295:
#line 3933 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 296:
#line 3992 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [ ]" << endl;
#endif
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 297:
#line 4001 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [arglist]" << endl;
#endif
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 298:
#line 4016 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [single]" << endl;
#endif
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 299:
#line 4025 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [list]" << endl;
#endif
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 300:
#line 4040 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 4047 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 4060 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 4067 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 304:
#line 4074 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 305:
#line 4087 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 306:
#line 4098 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 307:
#line 4109 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 308:
#line 4120 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 309:
#line 4131 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 310:
#line 4142 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 311:
#line 4160 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [single]" << endl;
#endif
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 312:
#line 4169 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [list]" << endl;
#endif
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 313:
#line 4184 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [single]" << endl;
#endif
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 314:
#line 4193 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 315:
#line 4210 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttr [ ]" << endl;
#endif
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 316:
#line 4225 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 317:
#line 4233 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 318:
#line 4247 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]" << endl;
#endif
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 319:
#line 4254 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 320:
#line 4261 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [""]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 321:
#line 4270 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [single]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 322:
#line 4279 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 323:
#line 4290 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 324:
#line 4307 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 325:
#line 4314 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 326:
#line 4321 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 327:
#line 4330 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [single]" << endl;
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 328:
#line 4339 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 329:
#line 4350 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 330:
#line 4367 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 331:
#line 4375 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 332:
#line 4389 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 333:
#line 4397 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 334:
#line 4411 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]" << endl;
#endif
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 335:
#line 4419 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]" << endl;
#endif
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 336:
#line 4427 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cdata]" << endl;
#endif
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 337:
#line 4436 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [common_content]" << endl;
#endif
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 338:
#line 4451 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [char_ref]\n";
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 339:
#line 4460 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 340:
#line 4468 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 341:
#line 4476 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 342:
#line 4490 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]" << endl;
#endif
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 343:
#line 4498 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "DirCommentConstructor [ ]" << endl;
#endif
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 344:
#line 4516 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 345:
#line 4524 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target.charlit]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 346:
#line 4544 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]" << endl;
#endif
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 347:
#line 4562 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 348:
#line 4569 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 4576 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 4583 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 4590 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 352:
#line 4597 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 353:
#line 4610 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 354:
#line 4624 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 355:
#line 4633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 356:
#line 4642 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 357:
#line 4650 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 358:
#line 4678 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 359:
#line 4687 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 360:
#line 4696 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 361:
#line 4704 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 362:
#line 4718 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 363:
#line 4732 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 364:
#line 4746 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 365:
#line 4755 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 366:
#line 4764 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 367:
#line 4772 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 368:
#line 4786 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic]" << endl;
#endif
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 369:
#line 4795 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic ?]" << endl;
#endif
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 370:
#line 4810 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]" << endl;
#endif
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 371:
#line 4824 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 372:
#line 4833 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type.occurs]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 373:
#line 4842 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 374:
#line 4882 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 375:
#line 4890 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 376:
#line 4898 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 377:
#line 4912 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 378:
#line 4919 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 379:
#line 4926 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]" << endl;
#endif
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 380:
#line 4939 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]" << endl;
#endif
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 381:
#line 4953 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 382:
#line 4960 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 383:
#line 4967 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 384:
#line 4974 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 385:
#line 4981 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 386:
#line 4988 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 387:
#line 4995 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 388:
#line 5002 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 389:
#line 5009 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 390:
#line 5022 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]" << endl;
#endif
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 391:
#line 5035 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 392:
#line 5042 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 393:
#line 5050 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 394:
#line 5064 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]" << endl;
#endif
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 395:
#line 5077 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]" << endl;
#endif
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 396:
#line 5090 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 397:
#line 5097 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 398:
#line 5104 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 399:
#line 5117 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [ ]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 400:
#line 5126 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL);
		;}
    break;

  case 401:
#line 5135 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name.type]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 402:
#line 5144 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 403:
#line 5153 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*.type]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 404:
#line 5168 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 405:
#line 5182 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [ ]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL);
		;}
    break;

  case 406:
#line 5191 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
									NULL);
		;}
    break;

  case 407:
#line 5200 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 408:
#line 5209 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 409:
#line 5218 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 410:
#line 5228 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 411:
#line 5238 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 412:
#line 5254 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 413:
#line 5278 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]" << endl;
#endif
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 414:
#line 5288 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name?]" << endl;
#endif
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 415:
#line 5311 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]" << endl;
#endif
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 416:
#line 5354 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [strict]" << endl;
#endif
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 417:
#line 5362 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [lax]" << endl;
#endif
    ;}
    break;

  case 418:
#line 5368 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [skip]" << endl;
#endif
    ;}
    break;

  case 419:
#line 5379 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 420:
#line 5388 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.as_first]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 421:
#line 5397 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.as_last]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 422:
#line 5406 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.after]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 423:
#line 5415 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.before]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 424:
#line 5425 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 425:
#line 5434 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.as_first]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 426:
#line 5443 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.as_last]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 427:
#line 5452 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.after]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 428:
#line 5461 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.before]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 429:
#line 5476 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodeExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 430:
#line 5484 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodesExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 431:
#line 5497 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 432:
#line 5506 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceValueOfExpr [value.expr]" << endl;
#endif
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 433:
#line 5521 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 434:
#line 5550 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]" << endl;
#endif
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(6) - (2)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(6) - (4)].expr), (yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 435:
#line 5564 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [single]" << endl;
#endif
       (yyval.expr) = new VarNameList(LOC((yyloc)));
		;}
    break;

  case 436:
#line 5571 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 437:
#line 5587 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "VarNameDecl [" << driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)) << "]" << endl;
#endif
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 438:
#line 5604 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TryExpr []" << endl;
#endif
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 439:
#line 5614 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchList [single]" << endl;
#endif
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 440:
#line 5624 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 441:
#line 5638 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchExpr [NameTest]" << endl;
#endif
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 442:
#line 5648 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchExpr [NameTest,VarName]" << endl;
#endif
       QName* lQName = new QName(
                         LOC ((yyloc)), 
                         driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval))
                       );
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(7) - (2)].node)),
                          lQName,
                          (yysemantic_stack_[(7) - (7)].expr));
    ;}
    break;

  case 443:
#line 5675 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]" << endl;
#endif
		;}
    break;

  case 444:
#line 5681 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]" << endl;
#endif
		;}
    break;

  case 445:
#line 5687 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]" << endl;
#endif
		;}
    break;

  case 446:
#line 5693 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]" << endl;
#endif
		;}
    break;

  case 447:
#line 5705 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]" << endl;
#endif
		;}
    break;

  case 448:
#line 5711 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]" << endl;
#endif
		;}
    break;

  case 449:
#line 5717 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]" << endl;
#endif
		;}
    break;

  case 450:
#line 5723 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]" << endl;
#endif
		;}
    break;

  case 451:
#line 5735 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]" << endl;
#endif
		;}
    break;

  case 452:
#line 5741 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]" << endl;
#endif
		;}
    break;

  case 453:
#line 5753 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]" << endl;
#endif
		;}
    break;

  case 454:
#line 5759 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]" << endl;
#endif
		;}
    break;

  case 455:
#line 5771 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]" << endl;
#endif
		;}
    break;

  case 456:
#line 5777 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]" << endl;
#endif
		;}
    break;

  case 457:
#line 5789 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]" << endl;
#endif
		;}
    break;

  case 458:
#line 5795 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]" << endl;
#endif
		;}
    break;

  case 459:
#line 5807 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]" << endl;
#endif
		;}
    break;

  case 460:
#line 5813 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]" << endl;
#endif
		;}
    break;

  case 461:
#line 5819 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]" << endl;
#endif
		;}
    break;

  case 462:
#line 5831 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]" << endl;
#endif
		;}
    break;

  case 463:
#line 5837 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]" << endl;
#endif
		;}
    break;

  case 464:
#line 5849 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]" << endl;
#endif
		;}
    break;

  case 465:
#line 5855 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]" << endl;
#endif
		;}
    break;

  case 466:
#line 5867 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]" << endl;
#endif
		;}
    break;

  case 467:
#line 5873 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]" << endl;
#endif
		;}
    break;

  case 468:
#line 5879 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]" << endl;
#endif
		;}
    break;

  case 469:
#line 5885 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]" << endl;
#endif
		;}
    break;

  case 470:
#line 5891 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]" << endl;
#endif
		;}
    break;

  case 471:
#line 5903 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]" << endl;
#endif
		;}
    break;

  case 472:
#line 5915 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 473:
#line 5922 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 474:
#line 5929 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 475:
#line 5936 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 476:
#line 5943 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 477:
#line 5950 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 478:
#line 5957 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 479:
#line 5970 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]" << endl;
#endif
		;}
    break;

  case 480:
#line 5976 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]" << endl;
#endif
		;}
    break;

  case 481:
#line 5982 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]" << endl;
#endif
		;}
    break;

  case 482:
#line 5988 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]" << endl;
#endif
		;}
    break;

  case 483:
#line 6000 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]" << endl;
#endif
		;}
    break;

  case 484:
#line 6006 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]" << endl;
#endif
		;}
    break;

  case 485:
#line 6012 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]" << endl;
#endif
		;}
    break;

  case 486:
#line 6018 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]" << endl;
#endif
		;}
    break;

  case 487:
#line 6030 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]" << endl;
#endif
		;}
    break;

  case 488:
#line 6036 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]" << endl;
#endif
		;}
    break;

  case 489:
#line 6048 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]" << endl;
#endif
		;}
    break;

  case 490:
#line 6054 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]" << endl;
#endif
		;}
    break;

  case 491:
#line 6060 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]" << endl;
#endif
		;}
    break;

  case 492:
#line 6066 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]" << endl;
#endif
		;}
    break;

  case 493:
#line 6072 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]" << endl;
#endif
		;}
    break;

  case 494:
#line 6078 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]" << endl;
#endif
		;}
    break;

  case 495:
#line 6084 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]" << endl;
#endif
		;}
    break;

  case 496:
#line 6096 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]" << endl;
#endif
		;}
    break;

  case 497:
#line 6102 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]" << endl;
#endif
		;}
    break;

  case 498:
#line 6114 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]" << endl;
#endif
		;}
    break;

  case 499:
#line 6120 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]" << endl;
#endif
		;}
    break;

  case 500:
#line 6126 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]" << endl;
#endif
		;}
    break;

  case 501:
#line 6132 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]" << endl;
#endif
		;}
    break;

  case 502:
#line 6144 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]" << endl;
#endif
		;}
    break;

  case 503:
#line 6150 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]" << endl;
#endif
		;}
    break;

  case 504:
#line 6156 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]" << endl;
#endif
		;}
    break;

  case 505:
#line 6162 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]" << endl;
#endif
		;}
    break;

  case 506:
#line 6168 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]" << endl;
#endif
		;}
    break;

  case 507:
#line 6180 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 508:
#line 6186 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 509:
#line 6198 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]" << endl;
#endif
		;}
    break;

  case 510:
#line 6204 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]" << endl;
#endif
		;}
    break;

  case 511:
#line 6216 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 512:
#line 6222 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 513:
#line 6234 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]" << endl;
#endif
		;}
    break;

  case 514:
#line 6240 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]" << endl;
#endif
		;}
    break;

  case 515:
#line 6252 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]" << endl;
#endif
		;}
    break;

  case 516:
#line 6264 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]" << endl;
#endif
		;}
    break;

  case 517:
#line 6270 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]" << endl;
#endif
		;}
    break;

  case 518:
#line 6282 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]" << endl;
#endif
		;}
    break;

  case 519:
#line 6288 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]" << endl;
#endif
		;}
    break;

  case 520:
#line 6294 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]" << endl;
#endif
		;}
    break;

  case 521:
#line 6306 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]" << endl;
#endif
		;}
    break;

  case 522:
#line 6312 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]" << endl;
#endif
		;}
    break;

  case 523:
#line 6318 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]" << endl;
#endif
		;}
    break;

  case 524:
#line 6324 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]" << endl;
#endif
		;}
    break;

  case 525:
#line 6330 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]" << endl;
#endif
		;}
    break;

  case 526:
#line 6342 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 527:
#line 6349 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 528:
#line 6356 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 529:
#line 6363 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 530:
#line 6376 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]" << endl;
#endif
		;}
    break;

  case 531:
#line 6388 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]" << endl;
#endif
		;}
    break;

  case 532:
#line 6400 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]" << endl;
#endif
		;}
    break;

  case 533:
#line 6412 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]" << endl;
#endif
		;}
    break;

  case 534:
#line 6418 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]" << endl;
#endif
		;}
    break;

  case 535:
#line 6430 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]" << endl;
#endif
		;}
    break;

  case 536:
#line 6436 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]" << endl;
#endif
		;}
    break;

  case 537:
#line 6442 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 538:
#line 6454 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]" << endl;
#endif
		;}
    break;

  case 539:
#line 6460 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 540:
#line 6472 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ ]" << endl;
#endif
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 7111 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
	error (yylloc, yysyntax_error_ (yystate));
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
  xquery_parser::yysyntax_error_ (int yystate)
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
  const short int xquery_parser::yypact_ninf_ = -648;
  const short int
  xquery_parser::yypact_[] =
  {
       653,  1067,  1274,  -648,  -648,   -14,  -648,     4,  -648,  -648,
    -648,  2930,    25,   444,  -648,  2930,   -17,  -648,   239,   159,
     318,   -30,   292,    51,   153,    82,   300,   267,   307,   -52,
     310,   395,  -648,  -648,  2930,   340,   404,  -648,  -648,  -648,
    2930,    31,   428,  -648,  -648,   459,  2930,   116,   298,  -648,
     462,  1481,  -648,   362,   311,  2930,  -648,   480,    55,  -648,
     497,  -648,  -648,   142,   486,   522,  -648,  3635,  3474,   428,
    -648,   525,  2930,   389,  2930,  2930,  2930,    21,   526,   382,
    2930,  2930,  2930,  2930,  2930,  2930,  2930,   538,   437,   380,
     571,   860,  -648,  -648,   232,  2930,   415,   424,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,   544,  -648,
    -648,   235,  -648,  -648,  -648,  -648,  -648,  -648,   472,   581,
    -648,  1103,   384,   206,   210,   -79,   212,  -648,   510,   446,
     586,   587,  3137,  -648,  -648,  -648,   -42,  -648,  -648,  -648,
     435,  -648,   513,   444,  -648,   513,   444,  -648,  -648,  -648,
    -648,   513,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,    68,  -648,    69,  1688,  2930,    85,    84,  -648,    86,
    -648,  -648,   122,  -648,  -648,  -648,  -648,  -648,  -648,   583,
     584,  -648,   608,   612,  -648,  -648,   528,   561,   627,  -648,
    -648,   531,   432,   125,  -648,   494,   495,  -648,   128,    99,
    -648,   102,   323,    -7,  -648,    -3,   607,  -648,   104,   621,
     643,   624,   534,   646,   637,    -2,   619,  -648,  -648,   106,
     580,  -648,   147,    79,   511,   512,  -648,   656,  -648,   560,
    2930,   519,   520,  -648,  -648,    50,    40,   160,  -648,   107,
     214,   252,   485,  -648,     1,  -648,  -648,  -648,  -648,  -648,
      17,    34,   651,   469,   470,   588,    -9,  -648,  2930,  -648,
    -648,  -648,  -648,   663,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,    -8,  -648,  -648,    60,   280,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
     232,    30,  2930,  2930,  2930,  2930,  2930,  -648,   287,   530,
    3306,  3306,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  3306,  3306,  3306,
      10,  3306,  3306,  3306,  3306,  3306,  3306,  3306,  3306,  3306,
    3306,  3306,   368,   368,   674,   674,  -648,  -648,  -648,  1895,
    -648,  3474,  3474,  2930,   513,  -648,  -648,   513,  -648,   513,
    -648,  -648,  -648,  -648,   108,   253,   582,   675,  -648,   675,
    -648,  -648,    11,    13,  -648,  -648,   162,   671,  -648,   328,
     368,  -648,  2930,   224,  -648,  -648,  -648,   585,   678,  -648,
     678,  -648,  2930,   594,   645,  2930,   649,  2930,   650,   -61,
     595,     0,   658,   546,   707,   648,   707,  -648,   652,   703,
    2930,   638,   -57,   664,  -648,   717,  -648,  -648,  -648,  -648,
    -648,  -648,  2102,   254,  -648,  -648,  2930,   654,  -648,    33,
      64,  -648,  -648,   705,  -648,  -648,  -648,   720,  -648,   321,
    2930,  2930,  2930,   325,  2930,  2930,  2930,  2930,  2930,  2930,
    2930,   676,  2930,   591,  -648,    60,    60,    -8,  -648,   726,
     729,    -8,   731,  -648,   101,  -648,   593,  -648,  -648,  -648,
     481,   713,  -648,  -648,   713,  -648,  2930,   604,  2930,   581,
    -648,  -648,  -648,  -648,  2930,    10,   331,  -648,   506,  3588,
     532,   521,  -648,  -648,   523,   257,   210,   210,   -21,   -79,
     -79,   -79,   -79,   212,   212,  -648,  -648,  -648,  -648,  -648,
    -648,   460,  -648,  -648,  -648,  -648,   667,  -648,  -648,   256,
    -648,  -648,    28,  -648,  2930,  -648,  -648,  2309,  -648,   614,
     616,  -648,  -648,  -648,  -648,   741,   392,   110,  -648,  -648,
     406,   111,  -648,  -648,  -648,  2930,  2516,   668,   618,   620,
     622,   625,  -648,  2930,   428,  -648,   759,  -648,   760,  2930,
     679,  2930,  2930,   -54,   680,   459,  2930,  -648,   742,   764,
     742,  -648,   707,  -648,  2930,  2930,   690,   462,   629,  -648,
     258,   681,  -648,    37,  -648,  -648,   790,  -648,  -648,  2930,
     779,  -648,  -648,    49,  -648,  -648,  -648,  -648,    56,  -648,
     330,    47,  -648,   639,  2930,  2930,  -648,  -648,  -648,  2930,
    2930,  -648,  -648,  -648,  -648,  -648,  -648,  -648,   538,   644,
     590,  -648,  -648,  -648,  -648,  -648,    80,    -8,   333,   112,
     113,    30,  -648,   781,  -648,  -648,  -648,  -648,   288,   762,
    -648,  2930,  -648,  2930,  -648,   259,   662,  -648,  3306,  -648,
    -648,  -648,  -648,   135,   351,  -648,    10,   135,  3306,  3306,
    3634,  -648,  -648,  -648,  -648,  -648,  -648,  -648,    10,    10,
     351,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,   260,  -648,  -648,
     777,   368,  -648,  -648,   735,   416,   368,  -648,  -648,   420,
    -648,  -648,   261,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  2930,  -648,  -648,  2930,   704,  2930,  -648,
     733,   788,   791,   742,  -648,  -648,  2930,  -648,  -648,  -648,
    2723,    59,   458,  -648,  -648,   262,   657,   803,  -648,   805,
      65,   807,   673,   275,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  2930,    52,   590,  -648,  -648,  -648,  3306,  3306,  3306,
    3306,   810,   596,   794,  -648,   794,  -648,  -648,   762,  -648,
    -648,  -648,  -648,  -648,  -648,   -79,  -648,  -648,  -648,    67,
     532,  -648,  -648,   188,  3306,  -648,  -648,   521,  -648,   589,
    -648,  -648,    24,  -648,   368,  -648,  -648,   374,   368,  -648,
    -648,  -648,  -648,  -648,  2930,  -648,  2930,  -648,   707,  -648,
    -648,   263,  -648,  -648,   804,   369,  -648,  -648,  -648,  -648,
     682,   499,  -648,  -648,  -648,  -648,   683,   692,   820,   808,
    2930,   818,  2930,  -648,   114,  -648,   -79,   -79,   -79,   385,
     351,  -648,   115,  -648,   118,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,   378,  -648,  -648,   386,  -648,
    -648,   742,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,   693,   368,  -648,   688,  -648,   771,   734,  3306,   609,
     794,  -648,  -648,  -648,  -648,  -648,  -648,  -648,   694,  2930,
     828,  -648,   -79,  -648,  -648,  2930,  -648,   696,  -648,   734,
    -648
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     0,     0,   270,   271,   267,   415,     0,   261,   264,
     251,     0,     0,     0,   249,     0,     0,   287,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,   253,     0,     0,     0,   293,   259,   289,
       0,     0,     0,   255,   254,     0,     0,     0,     0,   288,
       0,     0,   205,     0,     0,     0,   260,     0,     0,   204,
       0,   263,   262,     0,     0,     0,   252,   234,     0,     0,
     269,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     4,     0,     0,     0,     0,    15,    17,
      19,    20,    21,    27,    22,    25,    26,    31,    32,    33,
      28,    29,    35,    36,    23,    30,    24,     9,    93,    94,
      96,     0,   111,   113,   114,    97,    98,    99,   100,   167,
     169,   171,   175,   178,   180,   183,   188,   191,   194,   196,
     198,   200,     0,   202,   208,   210,     0,   230,   209,   237,
     238,   241,   243,     0,   248,   245,     0,   256,   266,   268,
     242,   272,   277,   285,   278,   279,   280,   283,   284,   281,
     282,   300,   302,   303,   304,   301,   347,   348,   349,   350,
     351,   352,   265,   389,   381,   388,   387,   386,   383,   385,
     382,   384,   286,    34,   101,   102,   104,   103,   105,   106,
     358,     0,   354,     0,     0,     0,     0,     0,   399,     0,
     267,   257,     0,   395,    53,    38,    39,    70,    71,     0,
       0,    52,     0,     0,    46,    47,     0,     0,     0,    44,
      45,     0,     0,     0,   391,     0,     0,   290,     0,     0,
     405,     0,     0,     0,   156,     0,   115,   116,     0,    62,
       0,    54,     0,     0,     0,     0,   128,   129,   291,     0,
       0,   390,     0,     0,     0,     0,   396,     0,   233,     0,
       0,     0,     0,   235,   236,     0,     0,     0,   394,     0,
       0,     0,     0,   343,     0,   416,   417,   418,   429,   430,
       0,     0,     0,     0,     0,     0,     0,   435,     0,   482,
     481,   486,   485,     0,   479,   480,   484,   488,   506,   495,
     517,   504,   483,   487,     0,     0,   516,    43,   472,   473,
     474,   475,   476,   477,   478,     1,     3,     5,    10,     8,
      12,    13,     0,     0,     0,     0,     0,   112,     0,     0,
       0,     0,   211,   225,   216,   215,   223,   214,   213,   212,
     224,   217,   222,   221,   220,   219,   218,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,   206,   203,     0,
     231,     0,     0,     0,   244,   274,   247,   246,   258,   273,
     359,   355,   296,   298,     0,     0,     0,     0,   400,     0,
     402,   363,     0,     0,    40,    41,     0,     0,    42,     0,
       0,    67,     0,     0,   353,   392,   393,     0,     0,   406,
       0,   409,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,    55,
       0,     0,     0,     0,   292,     0,   294,   345,   344,   397,
     398,   232,     0,     0,   404,   412,     0,     0,   305,     0,
       0,   313,   362,     0,   295,   226,   342,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   515,     0,     0,   505,   507,     0,
       0,   502,     0,   490,     0,   489,     0,    16,    18,    95,
     140,   136,   138,   107,   137,   135,     0,     0,     0,   168,
     170,   173,   172,   174,     0,     0,     0,   464,   176,   443,
     451,   453,   455,   457,   459,   462,   182,   181,   179,   185,
     186,   187,   184,   189,   190,   193,   192,   380,   379,   373,
     195,   371,   377,   378,   197,   199,   368,   201,   228,     0,
     239,   240,     0,   275,     0,   297,   227,     0,   413,     0,
       0,    50,    51,    48,    49,     0,     0,     0,    88,    37,
       0,     0,   370,    66,    69,     0,     0,   413,     0,     0,
       0,     0,   158,     0,     0,   155,     0,   118,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    64,     0,
      56,    60,     0,   131,     0,     0,     0,     0,     0,   364,
       0,     0,   154,     0,   338,   335,     0,   339,   340,     0,
       0,   341,   334,     0,   311,   337,   336,   306,     0,   314,
       0,     0,   162,     0,     0,     0,   422,   423,   419,     0,
       0,   427,   428,   424,   433,   431,   432,   437,     0,     0,
       0,   514,   513,   508,   509,   511,     0,   503,   498,     0,
       0,    14,   149,     0,   150,   151,   152,   141,   142,   143,
     144,     0,   108,     0,   109,     0,     0,   458,     0,   177,
     471,   519,   518,     0,     0,   520,     0,     0,     0,     0,
     444,   448,   466,   447,   470,   468,   467,   469,     0,     0,
       0,   460,   523,   524,   521,   522,   525,   463,   374,   376,
     375,   372,   369,   229,   276,   299,   360,     0,   401,   403,
      90,     0,    72,    73,     0,     0,     0,    80,    81,     0,
      68,   356,     0,   414,   407,   408,   410,   411,   159,   157,
     126,   127,   120,     0,   122,   119,     0,     0,     0,   117,
       0,     0,    63,    57,   133,   132,     0,   130,    11,   365,
       0,   324,   318,   315,   346,     0,     0,     0,   312,     0,
       0,     0,     0,     0,   163,     7,   420,   421,   425,   426,
     436,     0,     0,   438,   439,   512,   510,     0,     0,     0,
       0,     0,     0,     0,   493,     0,   491,   153,   145,   146,
     147,   139,   110,   465,   461,   540,   539,   538,   534,     0,
     452,   533,   445,     0,     0,   450,   449,   454,   456,     0,
     361,    91,     0,    89,     0,    74,    75,     0,     0,    82,
      83,   357,   124,   121,     0,   123,     0,    59,     0,   134,
     366,     0,   332,   326,     0,   325,   327,   333,   330,   320,
       0,   319,   321,   331,    92,   307,     0,     0,     0,     0,
       0,     0,     0,   434,     0,   440,   527,   528,   526,     0,
     499,   500,     0,   496,     0,   148,   537,   536,   535,   530,
     531,   446,   532,    76,    77,     0,    84,    85,     0,   125,
     166,    65,   367,   317,   328,   329,   316,   322,   323,   308,
     309,     0,     0,   164,     0,   160,     0,     0,     0,     0,
       0,   494,   492,    78,    79,    86,    87,   310,     0,     0,
       0,   441,   529,   501,   497,     0,   161,     0,   165,     0,
     442
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -648,  -648,  -648,   776,   778,  -648,   780,  -648,   543,   545,
    -309,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -416,  -648,  -648,  -648,  -648,  -648,
     467,   154,  -542,   782,     6,   -80,  -648,  -648,   765,  -648,
    -648,   286,   452,  -230,  -648,  -648,   278,  -648,   550,   556,
     221,  -648,  -648,   225,  -558,  -648,   825,   312,  -648,  -648,
     264,  -648,  -648,   562,   563,   240,  -632,   540,   241,  -352,
     247,   265,  -648,  -648,  -648,  -648,  -648,   763,  -648,  -648,
    -648,  -648,  -648,  -648,   755,  -648,   -41,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,    78,   126,  -648,  -648,   167,   157,
    -648,  -337,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -426,  -648,   279,  -648,   449,  -648,  -648,  -648,  -648,
    -648,    77,    87,  -540,  -404,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,   535,  -226,  -355,  -648,  -648,
     243,  -362,  -648,  -648,  -648,  -648,  -648,  -648,  -648,   894,
     898,   152,   524,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,   291,  -648,  -648,   158,   430,  -648,  -648,   268,   248,
     249,   431,  -648,  -648,   269,  -648,  -481,  -648,  -648,  -648,
    -648,   155,  -306,  -648,   466,   141,  -648,  -451,  -648,  -648,
    -648,  -648,  -647,  -648,  -648,  -648,  -648,   136,   266,  -648
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   598,   254,   113,   114,   115,   116,
     567,   568,   621,   117,   118,   119,   120,   121,   122,   123,
     246,   247,   429,   430,   124,   256,   257,   338,   339,   501,
     502,   667,   668,   669,   670,   125,   243,   244,   126,   631,
     632,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   357,   358,
     359,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   384,   385,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   394,
     170,   171,   172,   623,   460,   461,   763,   850,   851,   844,
     845,   852,   846,   624,   625,   173,   174,   626,   175,   176,
     177,   178,   179,   180,   181,   545,   413,   540,   711,   541,
     542,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   559,   579,   192,   193,   194,   195,   196,   197,   198,
     296,   297,   199,   783,   784,   518,   690,   519,   520,   521,
     522,   523,   524,   525,   691,   692,   317,   318,   319,   320,
     321,   872,   873,   322,   487,   491,   656,   488,   323,   324,
     694,   707,   792,   695,   696,   701,   697,   879,   808,   679
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       288,   289,   290,   291,   292,   293,   294,   201,   203,   495,
     543,   543,   529,   530,   531,   532,   423,   206,   544,   431,
     600,   212,   498,   517,   723,   441,   273,   274,   728,   442,
     410,   410,   426,   622,     6,   426,   653,   809,   693,   481,
     233,   424,   614,   615,   605,   207,   238,   589,   543,   282,
     469,   239,   248,   819,   746,   572,   812,   259,   614,   615,
     457,   262,   842,    17,     3,   614,   615,   473,   614,   761,
     264,     4,   210,   379,   614,   615,   332,   616,   277,   265,
     279,   280,   281,   768,   457,   485,   229,   447,   630,   467,
      39,   211,    26,   616,    28,   489,    30,    31,   424,   440,
     616,   368,   361,   219,   785,   427,    60,   204,   592,   616,
     799,   800,   617,   369,   618,   773,   332,   332,   883,   205,
     561,    49,   563,   220,   393,   514,   362,   458,   617,   230,
     618,   515,   397,   332,   399,   617,   492,   618,   617,   619,
     618,   249,   213,   562,   617,   564,   618,   418,   619,   843,
     420,   627,   332,   425,   332,   332,   554,   269,   724,   724,
     793,   795,   906,   910,   619,   468,   910,   224,   225,   659,
     332,   619,   486,   332,   619,    57,   332,   222,   517,   517,
     619,   490,   881,   826,   208,   714,   753,   830,   660,   428,
     240,    57,   762,   428,   209,   332,   428,   622,    57,   590,
     241,   594,   622,   620,    71,   482,   653,    57,   332,   816,
     456,   395,   606,   459,   266,   470,   471,   283,   483,   767,
      71,    70,   448,   909,   390,   391,   769,    71,    77,   472,
     768,   386,   474,   475,   388,   858,    71,   628,   565,   786,
     875,   396,   250,   398,    77,   400,   476,   428,   428,   516,
     428,    77,   499,   500,   503,   500,   505,   270,   419,    89,
      77,   421,   332,   433,   214,   444,   463,   555,   543,   725,
     729,   794,   796,   907,   911,   772,   453,   912,   401,   223,
     884,   414,   227,   364,   417,   887,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
     332,   332,   332,   446,   332,   370,   332,   332,   332,   332,
     332,   332,   215,   876,   365,   492,   462,   221,   574,   877,
     226,   566,   387,   251,   371,   575,   805,   228,   389,   361,
     231,   216,   573,    45,   366,   663,   878,   813,    47,    48,
     550,   551,   582,   914,   622,   585,   916,   587,   493,   517,
     537,   861,   498,   362,    50,     6,   410,   847,   853,   543,
     603,   517,   517,   747,   543,   921,   822,   252,   368,    12,
     464,   827,   842,   665,   666,   333,   612,   260,   614,   367,
     369,   806,    16,   363,    17,   549,   807,   930,   537,   552,
     636,   637,   638,   334,   641,   642,   643,   644,   645,   646,
     647,   494,   649,   335,   565,    35,   771,    12,   465,   556,
     611,    39,   713,    41,   759,   803,   820,   831,   854,   892,
      16,   232,   891,    41,   253,   721,   672,   333,   674,   336,
     237,   422,    79,   862,   876,   866,   867,   868,   869,   726,
     877,   847,    49,    35,   538,   506,   514,   853,   617,   824,
     618,    41,   515,   828,   242,   335,     3,   878,   610,   894,
      54,    89,   543,     4,   210,   410,   543,   614,   886,   885,
     261,   217,   913,   888,   715,    58,   702,   703,   704,   705,
     915,   848,   538,    12,   619,   245,   722,   570,   255,   619,
     218,    64,    65,   619,   821,   730,    16,   263,    54,   234,
     727,   619,    65,   738,   706,    73,   271,   619,   614,   742,
     825,   744,   745,    58,   829,   662,   750,   267,   268,    35,
     675,   619,   848,   539,   754,   755,   411,    41,   663,    64,
      65,   619,   634,   412,   635,   619,   639,   617,   640,   618,
     543,   553,   272,    73,   553,   276,   553,   918,   278,   849,
     284,   560,   298,   664,   776,   777,   922,   787,   788,   778,
     779,   539,   908,   717,   295,   368,   665,   666,   789,   790,
     578,   325,   580,   619,    54,   787,   788,   369,   617,   330,
     618,   791,   732,   285,   286,   287,   789,   790,   331,    58,
     897,   500,   332,   802,   708,   709,   710,   511,   512,   513,
     381,   382,   526,   527,   924,    64,    65,   299,   300,   340,
     301,   302,   341,    70,   619,   533,   534,   546,   546,    73,
     372,   303,   360,   304,   373,   765,   651,   652,   374,   383,
     375,   402,   403,   404,   305,   535,   536,   405,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   406,
     407,   408,   409,   415,   416,   432,   434,     1,   435,   436,
     437,   438,   439,   832,     2,     3,   833,   443,   835,   445,
     449,   450,     4,     5,   451,   452,   839,     6,   454,   455,
       7,   466,     8,     9,   477,   478,   479,   484,   508,   480,
      10,    11,    12,    13,   537,   558,   569,   557,   577,    14,
     576,   863,   583,   591,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   584,   596,    32,    33,   586,   588,    34,    35,    36,
      37,    38,   597,    39,   595,    40,    41,   599,   602,   604,
     607,   601,   608,   613,   633,    42,   630,   650,    43,    44,
     654,    45,   648,   655,   889,   658,   890,   661,    46,    47,
      48,   671,   673,   678,    49,   699,   841,   720,   700,   698,
     712,   733,    50,   718,    51,   719,    52,   734,    53,   735,
     903,   736,   905,    54,   737,   740,   741,   743,   748,   752,
     751,   756,    55,   758,    56,    57,   760,   764,    58,   766,
      59,    60,   781,   775,    61,    62,   797,    63,   782,   663,
     410,   565,   834,   837,    64,    65,    66,   836,    67,    68,
      69,   804,    70,   856,    71,   857,   838,    72,    73,   492,
     855,   860,    74,   859,   870,    75,   893,   896,   871,   926,
     901,   902,   882,    76,   904,   928,   919,   920,    77,   619,
      78,   923,   925,    79,   927,   929,   899,    80,    81,    82,
      83,    84,    85,    86,     1,   900,   917,   326,    87,   327,
      88,     2,     3,   496,   328,   497,   571,   329,   823,     4,
       5,   749,    89,   593,     6,   757,   337,     7,   507,     8,
       9,   504,   801,   798,   275,   774,   739,    10,    11,    12,
      13,   380,   509,   528,   510,   378,    14,   770,   864,   629,
     547,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,   898,   235,
      32,    33,   895,   236,    34,    35,    36,    37,    38,   780,
      39,   865,    40,    41,   581,   676,   817,   677,   818,   880,
     874,     0,    42,   811,   810,    43,    44,   657,    45,   815,
       0,     0,     0,     0,     0,    46,    47,    48,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,    53,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,    56,    57,     0,     0,    58,     0,    59,    60,     0,
       0,    61,    62,     0,    63,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,    67,    68,    69,     0,    70,
       0,    71,     0,     0,    72,    73,     0,     0,     0,    74,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,    77,     0,     0,     0,     0,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     1,     0,     0,     0,    87,     0,    88,     2,     3,
       0,     0,     0,     0,     0,     0,     4,     5,     0,    89,
       0,     6,     0,     0,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       0,    34,    35,    36,    37,    38,     0,    39,     0,    40,
      41,     0,     0,     0,     0,     0,     0,     0,     0,    42,
       0,     0,    43,    44,     0,    45,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,    50,     0,    51,     0,
      52,     0,   342,     0,     0,     0,     0,    54,     0,     0,
     343,     0,     0,   344,     0,   345,    55,     0,    56,    57,
       0,     0,    58,     0,    59,    60,   346,     0,    61,    62,
     347,    63,     0,   200,     0,   348,     0,     0,    64,    65,
      66,   349,    67,    68,    69,     0,    70,     0,    71,     0,
       0,    72,    73,     0,     0,     0,    74,     0,     0,    75,
       0,     0,     0,   350,     0,     0,     0,    76,     0,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,     1,     0,
       0,     0,    87,     0,    88,     2,     3,   351,   352,   353,
     354,   355,   356,     4,     5,     0,     0,     0,     6,     0,
       0,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,    15,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    33,     0,     0,    34,    35,
      36,    37,    38,     0,    39,     0,    40,    41,     0,     0,
       0,     0,     0,     0,     0,     0,    42,     0,     0,    43,
      44,     0,    45,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,    50,     0,    51,     0,    52,     0,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,    56,    57,     0,     0,    58,
       0,    59,    60,     0,     0,    61,    62,     0,    63,     0,
     202,     0,     0,     0,     0,    64,    65,    66,     0,    67,
      68,    69,     0,    70,     0,    71,     0,     0,    72,    73,
       0,     0,     0,    74,     0,     0,    75,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,     1,     0,     0,     0,    87,
       0,    88,     2,     3,     0,     0,     0,     0,     0,     0,
       4,     5,     0,     0,     0,     6,     0,     0,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
     258,     0,    64,    65,    66,     0,    67,    68,    69,     0,
      70,     0,    71,     0,     0,    72,    73,     0,     0,     0,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,     1,     0,     0,     0,    87,     0,    88,     2,
       3,     0,     0,     0,     0,     0,     0,     4,     5,     0,
       0,     0,     6,     0,     0,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    33,
       0,     0,    34,    35,    36,    37,    38,     0,    39,     0,
      40,    41,     0,     0,     0,     0,     0,     0,     0,     0,
      42,     0,     0,    43,    44,     0,    45,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,    50,     0,    51,
       0,    52,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,    56,
      57,     0,     0,    58,     0,    59,    60,     0,     0,    61,
      62,     0,    63,     0,     0,     0,     0,   392,     0,    64,
      65,    66,     0,    67,    68,    69,     0,    70,     0,    71,
       0,     0,    72,    73,     0,     0,     0,    74,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,     1,
       0,     0,     0,    87,     0,    88,     2,     3,     0,     0,
       0,     0,     0,     0,     4,     5,     0,     0,     0,     6,
       0,     0,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,     0,     0,    34,
      35,    36,    37,    38,     0,    39,     0,    40,    41,     0,
       0,     0,     0,     0,     0,     0,     0,    42,     0,     0,
      43,    44,     0,    45,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,     0,     0,    49,     0,     0,     0,
       0,     0,     0,     0,    50,     0,    51,     0,    52,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,    56,    57,     0,     0,
      58,     0,    59,    60,     0,     0,    61,    62,     0,    63,
       0,   548,     0,     0,     0,     0,    64,    65,    66,     0,
      67,    68,    69,     0,    70,     0,    71,     0,     0,    72,
      73,     0,     0,     0,    74,     0,     0,    75,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,     1,     0,     0,     0,
      87,     0,    88,     2,     3,     0,     0,     0,     0,     0,
       0,     4,     5,     0,     0,     0,     6,     0,     0,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    33,     0,     0,    34,    35,    36,    37,
      38,     0,    39,     0,    40,    41,     0,     0,     0,     0,
       0,     0,     0,     0,    42,     0,     0,    43,    44,     0,
      45,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,     0,     0,
       0,    50,     0,    51,     0,    52,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,    56,    57,     0,     0,    58,     0,    59,
      60,     0,     0,    61,    62,     0,    63,     0,   609,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     0,    72,    73,     0,     0,
       0,    74,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,     1,     0,     0,     0,    87,     0,    88,
       2,     3,     0,     0,     0,     0,     0,     0,     4,     5,
       0,     0,     0,     6,     0,     0,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,    34,    35,    36,    37,    38,     0,    39,
       0,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,     0,    43,    44,     0,    45,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,    50,     0,
      51,     0,    52,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      56,    57,     0,     0,    58,     0,    59,    60,     0,     0,
      61,    62,     0,    63,     0,   716,     0,     0,     0,     0,
      64,    65,    66,     0,    67,    68,    69,     0,    70,     0,
      71,     0,     0,    72,    73,     0,     0,     0,    74,     0,
       0,    75,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
       1,     0,     0,     0,    87,     0,    88,     2,     3,     0,
       0,     0,     0,     0,     0,     4,     5,     0,     0,     0,
       6,     0,     0,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,    41,
       0,     0,     0,     0,     0,     0,     0,     0,    42,     0,
       0,    43,    44,     0,    45,     0,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,    50,     0,    51,     0,    52,
       0,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    56,    57,     0,
       0,    58,     0,    59,    60,     0,     0,    61,    62,     0,
      63,     0,   731,     0,     0,     0,     0,    64,    65,    66,
       0,    67,    68,    69,     0,    70,     0,    71,     0,     0,
      72,    73,     0,     0,     0,    74,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,    76,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,     1,     0,     0,
       0,    87,     0,    88,     2,     3,     0,     0,     0,     0,
       0,     0,     4,     5,     0,     0,     0,     6,     0,     0,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,     0,     0,     0,     0,     0,    14,
       0,     0,     0,     0,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,     0,     0,    34,    35,    36,
      37,    38,     0,    39,     0,    40,    41,     0,     0,     0,
       0,     0,     0,     0,     0,    42,     0,     0,    43,    44,
       0,    45,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,    50,     0,    51,     0,    52,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    56,    57,     0,     0,    58,     0,
      59,    60,     0,     0,    61,    62,     0,    63,     0,   840,
       0,     0,     0,     0,    64,    65,    66,     0,    67,    68,
      69,     0,    70,     0,    71,     0,     0,    72,    73,     0,
       0,     0,    74,     0,     0,    75,     0,     0,     0,     0,
       0,     0,     0,    76,     0,     0,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,     1,     0,     0,     0,    87,     0,
      88,     2,     3,     0,     0,     0,     0,     0,     0,     4,
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
       0,    56,    57,     0,     0,    58,     0,    59,    60,     0,
       0,    61,    62,     0,    63,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,    67,    68,    69,     0,    70,
       0,    71,     0,     0,    72,    73,     0,     0,     0,    74,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     1,     0,     0,     0,    87,     0,    88,     2,     3,
       0,     0,     0,     0,     0,     0,     4,     5,     0,     0,
       0,     6,     0,     0,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       0,    34,    35,    36,    37,    38,     0,    39,     0,    40,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
     376,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,    56,    57,
       0,     0,    58,     0,   377,    60,     0,     0,    61,    62,
       0,    63,     0,     0,     0,     0,     0,     0,    64,    65,
      66,     0,    67,    68,     0,     0,    70,     0,    71,     0,
       1,    72,    73,     0,     0,     0,     0,     2,     3,    75,
       0,     0,     0,     0,     0,     4,     5,    76,     0,     0,
       6,     0,    77,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,    52,
       0,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    56,    57,     0,
       0,    58,     0,    59,    60,     0,     0,    61,    62,     0,
      63,     0,     0,     0,     0,     0,     0,    64,    65,    66,
       0,    67,    68,     0,     0,    70,     0,    71,     1,     0,
      72,    73,     0,     0,     0,     2,     3,     0,    75,     0,
       0,     0,     0,     4,     5,     0,    76,     0,     6,     0,
       0,    77,     0,     8,     9,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,    15,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    33,     0,     0,    34,    35,
      36,    37,    38,     0,    39,     0,    40,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,    56,    57,     0,     0,    58,
       0,     0,     0,     0,     0,    61,    62,     0,    63,     0,
       0,     0,     0,     0,     0,    64,    65,    66,     0,     1,
       0,     0,     0,    70,     0,    71,     2,     3,    72,    73,
       0,     0,     0,     0,     4,     5,    75,     0,     0,     6,
       0,     0,     0,     0,     8,     9,     0,     0,     0,    77,
       0,     0,    10,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,     0,     0,    34,
      35,    36,    37,    38,     0,    39,     0,    40,    41,     0,
       0,     0,     0,     0,     0,     0,   680,     0,     0,     0,
      43,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,   680,     0,    55,     0,    56,    57,     0,     0,
      58,     0,     0,     0,     0,     0,    61,    62,     0,    63,
       0,     0,     0,     0,     0,     0,    64,    65,    66,     0,
       0,     0,     0,     0,     0,     0,    71,     0,     0,    72,
      73,   681,     0,     0,   682,   299,   300,    75,   301,   302,
     683,   684,   685,     0,     0,     0,     0,     0,   686,   303,
      77,   304,     0,     0,     0,     0,     0,   687,     0,     0,
       0,     0,   305,   688,   689,     0,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   681,     0,     0,
     682,   299,   300,     0,   301,   302,   683,   684,   685,     0,
       0,     0,     0,     0,     0,   303,     0,   304,     0,     0,
       0,     0,     0,   687,     0,     0,     0,     0,   305,   814,
     689,     0,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        80,    81,    82,    83,    84,    85,    86,     1,     2,   315,
     372,   373,   364,   365,   366,   367,   242,    11,   373,   245,
     436,    15,   331,   360,   566,   255,    67,    68,   570,   255,
      33,    33,    35,   459,    24,    35,   487,   684,   519,    48,
      34,    48,     9,    10,   101,    20,    40,   108,   410,    28,
      33,    20,    46,   700,   108,   410,   688,    51,     9,    10,
      20,    55,     3,    53,    12,     9,    10,    33,     9,    32,
      15,    19,    20,   115,     9,    10,    48,    44,    72,    24,
      74,    75,    76,   623,    20,    93,   138,     8,    41,    88,
      80,    13,    62,    44,    64,    35,    66,    67,    48,   101,
      44,   180,   123,   133,    24,   108,   148,   121,   108,    44,
     668,   669,    79,   192,    81,    68,    48,    48,    94,   115,
     109,   111,   109,   153,   204,   115,   147,    87,    79,   181,
      81,   121,    48,    48,    48,    79,    35,    81,    79,   115,
      81,    25,   159,   132,    79,   132,    81,    48,   115,    90,
      48,    87,    48,   160,    48,    48,    48,    15,    48,    48,
      48,    48,    48,    48,   115,   164,    48,    85,    86,    68,
      48,   115,   180,    48,   115,   142,    48,   126,   515,   516,
     115,   121,   814,   725,   159,   157,   602,   729,   494,   250,
     159,   142,   155,   250,   169,    48,   250,   623,   142,   429,
     169,   431,   628,   170,   171,   214,   657,   142,    48,   690,
     160,   205,   442,   173,   159,   198,   199,   196,   298,   170,
     171,   169,   143,   870,   156,   156,   170,   171,   195,   212,
     770,   153,   198,   199,   156,   170,   171,   173,    76,   159,
     798,   156,   126,   159,   195,   159,   212,   250,   250,   239,
     250,   195,   332,   333,   334,   335,   336,   115,   159,   229,
     195,   159,    48,   159,    25,   159,   159,   159,   630,   159,
     159,   159,   159,   159,   159,   630,   270,   159,   156,   126,
     822,   156,    15,    73,   156,   827,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      48,    48,    48,   156,    48,    93,    48,    48,    48,    48,
      48,    48,   153,   246,   104,    35,   156,    25,    94,   252,
      20,   159,   155,    25,   112,   101,   678,    20,   161,   123,
      20,   172,   412,    98,   124,    47,   269,   689,   106,   107,
     381,   382,   422,   885,   770,   425,   888,   427,    68,   686,
      20,    76,   661,   147,   119,    24,    33,   761,   762,   721,
     440,   698,   699,   593,   726,   907,   721,    69,   180,    39,
     156,   726,     3,    85,    86,   140,   456,    15,     9,   169,
     192,   246,    52,   177,    53,   379,   251,   929,    20,   383,
     470,   471,   472,   158,   474,   475,   476,   477,   478,   479,
     480,   121,   482,   168,    76,    75,    76,    39,   156,   156,
     156,    80,   156,    83,   156,   156,   156,   156,   156,   156,
      52,    26,   838,    83,   126,    33,   506,   140,   508,   194,
      26,   108,   200,   158,   246,   787,   788,   789,   790,    33,
     252,   845,   111,    75,   114,   158,   115,   851,    79,    33,
      81,    83,   121,    33,    26,   168,    12,   269,   452,    90,
     130,   229,   824,    19,    20,    33,   828,     9,    94,   824,
     159,   153,    94,   828,   554,   145,   219,   220,   221,   222,
      94,    23,   114,    39,   115,    26,    94,   159,    26,   115,
     172,   161,   162,   115,   720,   575,    52,    17,   130,   159,
      94,   115,   162,   583,   247,   175,    20,   115,     9,   589,
      94,   591,   592,   145,    94,    34,   596,    20,    21,    75,
     514,   115,    23,   193,   604,   605,    94,    83,    47,   161,
     162,   115,   211,   101,   213,   115,   211,    79,   213,    81,
     902,   384,    20,   175,   387,    20,   389,   902,   159,    91,
      24,   399,   115,    72,   634,   635,   908,   224,   225,   639,
     640,   193,   177,   557,    26,   180,    85,    86,   235,   236,
     418,     0,   420,   115,   130,   224,   225,   192,    79,   164,
      81,   248,   576,   201,   202,   203,   235,   236,   164,   145,
      91,   671,    48,   673,   134,   135,   136,   357,   358,   359,
     165,   166,   361,   362,   910,   161,   162,   227,   228,   137,
     230,   231,    31,   169,   115,   368,   369,   374,   375,   175,
     110,   241,   238,   243,   178,   619,   485,   486,    42,   116,
      43,    48,    48,    25,   254,   370,   371,    25,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   121,
      89,    24,   121,   159,   159,    48,    35,     4,    15,    35,
     126,    15,    25,   743,    11,    12,   746,    48,   748,    89,
     159,   159,    19,    20,    18,   115,   756,    24,   159,   159,
      27,   196,    29,    30,    33,   216,   216,    24,   158,   101,
      37,    38,    39,    40,    20,    20,    25,   115,    20,    46,
     115,   781,   108,   108,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    76,   176,    70,    71,    76,    76,    74,    75,    76,
      77,    78,    25,    80,    76,    82,    83,    89,    35,   101,
      76,    89,    25,    89,    24,    92,    41,   156,    95,    96,
      24,    98,    76,    24,   834,    24,   836,   164,   105,   106,
     107,    48,   158,   257,   111,   244,   760,    26,   245,   237,
     103,   103,   119,   159,   121,   159,   123,   159,   125,   159,
     860,   159,   862,   130,   159,    26,    26,   108,   108,    25,
      48,   101,   139,   164,   141,   142,   115,     7,   145,    20,
     147,   148,   158,   164,   151,   152,    25,   154,   218,    47,
      33,    76,   108,    25,   161,   162,   163,    84,   165,   166,
     167,   159,   169,    20,   171,    20,    35,   174,   175,    35,
     173,   158,   179,    26,    24,   182,    32,   155,   242,   919,
      20,    33,   253,   190,    26,   925,   158,    76,   195,   115,
     197,   242,   158,   200,    26,   159,   173,   204,   205,   206,
     207,   208,   209,   210,     4,   173,   173,    91,   215,    91,
     217,    11,    12,   330,    94,   330,   409,    95,   724,    19,
      20,   595,   229,   431,    24,   607,   121,    27,   338,    29,
      30,   335,   671,   668,    69,   631,   584,    37,    38,    39,
      40,   146,   340,   363,   341,   142,    46,   628,   782,   460,
     375,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   851,    35,
      70,    71,   845,    35,    74,    75,    76,    77,    78,   648,
      80,   783,    82,    83,   420,   515,   698,   516,   699,   813,
     795,    -1,    92,   687,   686,    95,    96,   491,    98,   690,
      -1,    -1,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,    -1,
      -1,   151,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,   165,   166,   167,    -1,   169,
      -1,   171,    -1,    -1,   174,   175,    -1,    -1,    -1,   179,
      -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
     200,    -1,    -1,    -1,   204,   205,   206,   207,   208,   209,
     210,     4,    -1,    -1,    -1,   215,    -1,   217,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,   229,
      -1,    24,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,
      -1,    74,    75,    76,    77,    78,    -1,    80,    -1,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    95,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,
     123,    -1,    89,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      97,    -1,    -1,   100,    -1,   102,   139,    -1,   141,   142,
      -1,    -1,   145,    -1,   147,   148,   113,    -1,   151,   152,
     117,   154,    -1,   156,    -1,   122,    -1,    -1,   161,   162,
     163,   128,   165,   166,   167,    -1,   169,    -1,   171,    -1,
      -1,   174,   175,    -1,    -1,    -1,   179,    -1,    -1,   182,
      -1,    -1,    -1,   150,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   205,   206,   207,   208,   209,   210,     4,    -1,
      -1,    -1,   215,    -1,   217,    11,    12,   184,   185,   186,
     187,   188,   189,    19,    20,    -1,    -1,    -1,    24,    -1,
      -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    74,    75,
      76,    77,    78,    -1,    80,    -1,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,   121,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    -1,   141,   142,    -1,    -1,   145,
      -1,   147,   148,    -1,    -1,   151,   152,    -1,   154,    -1,
     156,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,   165,
     166,   167,    -1,   169,    -1,   171,    -1,    -1,   174,   175,
      -1,    -1,    -1,   179,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,
     206,   207,   208,   209,   210,     4,    -1,    -1,    -1,   215,
      -1,   217,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,
      -1,    -1,   151,   152,    -1,   154,    -1,    -1,    -1,    -1,
     159,    -1,   161,   162,   163,    -1,   165,   166,   167,    -1,
     169,    -1,   171,    -1,    -1,   174,   175,    -1,    -1,    -1,
     179,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,
     209,   210,     4,    -1,    -1,    -1,   215,    -1,   217,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,
      -1,    -1,    24,    -1,    -1,    27,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      -1,    -1,    74,    75,    76,    77,    78,    -1,    80,    -1,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    95,    96,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,   141,
     142,    -1,    -1,   145,    -1,   147,   148,    -1,    -1,   151,
     152,    -1,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,
     162,   163,    -1,   165,   166,   167,    -1,   169,    -1,   171,
      -1,    -1,   174,   175,    -1,    -1,    -1,   179,    -1,    -1,
     182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209,   210,     4,
      -1,    -1,    -1,   215,    -1,   217,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    24,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    74,
      75,    76,    77,    78,    -1,    80,    -1,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,   121,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    -1,   141,   142,    -1,    -1,
     145,    -1,   147,   148,    -1,    -1,   151,   152,    -1,   154,
      -1,   156,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,
     165,   166,   167,    -1,   169,    -1,   171,    -1,    -1,   174,
     175,    -1,    -1,    -1,   179,    -1,    -1,   182,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     205,   206,   207,   208,   209,   210,     4,    -1,    -1,    -1,
     215,    -1,   217,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    -1,    -1,    -1,    24,    -1,    -1,    27,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    -1,    -1,    74,    75,    76,    77,
      78,    -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,
     148,    -1,    -1,   151,   152,    -1,   154,    -1,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,    -1,   165,   166,   167,
      -1,   169,    -1,   171,    -1,    -1,   174,   175,    -1,    -1,
      -1,   179,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,   205,   206,   207,
     208,   209,   210,     4,    -1,    -1,    -1,   215,    -1,   217,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    -1,    74,    75,    76,    77,    78,    -1,    80,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
     121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
     141,   142,    -1,    -1,   145,    -1,   147,   148,    -1,    -1,
     151,   152,    -1,   154,    -1,   156,    -1,    -1,    -1,    -1,
     161,   162,   163,    -1,   165,   166,   167,    -1,   169,    -1,
     171,    -1,    -1,   174,   175,    -1,    -1,    -1,   179,    -1,
      -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   205,   206,   207,   208,   209,   210,
       4,    -1,    -1,    -1,   215,    -1,   217,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,
      24,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,
      74,    75,    76,    77,    78,    -1,    80,    -1,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    95,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,   141,   142,    -1,
      -1,   145,    -1,   147,   148,    -1,    -1,   151,   152,    -1,
     154,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,   165,   166,   167,    -1,   169,    -1,   171,    -1,    -1,
     174,   175,    -1,    -1,    -1,   179,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,   205,   206,   207,   208,   209,   210,     4,    -1,    -1,
      -1,   215,    -1,   217,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    -1,    -1,    -1,    24,    -1,    -1,
      27,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    -1,    -1,    74,    75,    76,
      77,    78,    -1,    80,    -1,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,   121,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    -1,   141,   142,    -1,    -1,   145,    -1,
     147,   148,    -1,    -1,   151,   152,    -1,   154,    -1,   156,
      -1,    -1,    -1,    -1,   161,   162,   163,    -1,   165,   166,
     167,    -1,   169,    -1,   171,    -1,    -1,   174,   175,    -1,
      -1,    -1,   179,    -1,    -1,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,   206,
     207,   208,   209,   210,     4,    -1,    -1,    -1,   215,    -1,
     217,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
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
      -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,    -1,
      -1,   151,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,   165,   166,   167,    -1,   169,
      -1,   171,    -1,    -1,   174,   175,    -1,    -1,    -1,   179,
      -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,   209,
     210,     4,    -1,    -1,    -1,   215,    -1,   217,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,
      -1,    24,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,
      -1,    74,    75,    76,    77,    78,    -1,    80,    -1,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,   141,   142,
      -1,    -1,   145,    -1,   147,   148,    -1,    -1,   151,   152,
      -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,    -1,   165,   166,    -1,    -1,   169,    -1,   171,    -1,
       4,   174,   175,    -1,    -1,    -1,    -1,    11,    12,   182,
      -1,    -1,    -1,    -1,    -1,    19,    20,   190,    -1,    -1,
      24,    -1,   195,    27,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,
      74,    75,    76,    77,    78,    -1,    80,    -1,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,   141,   142,    -1,
      -1,   145,    -1,   147,   148,    -1,    -1,   151,   152,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,   165,   166,    -1,    -1,   169,    -1,   171,     4,    -1,
     174,   175,    -1,    -1,    -1,    11,    12,    -1,   182,    -1,
      -1,    -1,    -1,    19,    20,    -1,   190,    -1,    24,    -1,
      -1,   195,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    74,    75,
      76,    77,    78,    -1,    80,    -1,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    -1,   141,   142,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,   151,   152,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,     4,
      -1,    -1,    -1,   169,    -1,   171,    11,    12,   174,   175,
      -1,    -1,    -1,    -1,    19,    20,   182,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,   195,
      -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    74,
      75,    76,    77,    78,    -1,    80,    -1,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   139,    -1,   141,   142,    -1,    -1,
     145,    -1,    -1,    -1,    -1,    -1,   151,   152,    -1,   154,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,   174,
     175,   223,    -1,    -1,   226,   227,   228,   182,   230,   231,
     232,   233,   234,    -1,    -1,    -1,    -1,    -1,   240,   241,
     195,   243,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,   254,   255,   256,    -1,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   223,    -1,    -1,
     226,   227,   228,    -1,   230,   231,   232,   233,   234,    -1,
      -1,    -1,    -1,    -1,    -1,   241,    -1,   243,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,   254,   255,
     256,    -1,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268
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
     119,   121,   123,   125,   130,   139,   141,   142,   145,   147,
     148,   151,   152,   154,   161,   162,   163,   165,   166,   167,
     169,   171,   174,   175,   179,   182,   190,   195,   197,   200,
     204,   205,   206,   207,   208,   209,   210,   215,   217,   229,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   307,   308,   309,   310,   314,   315,   316,
     317,   318,   319,   320,   325,   336,   339,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     391,   392,   393,   406,   407,   409,   410,   411,   412,   413,
     414,   415,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   434,   435,   436,   437,   438,   439,   440,   443,
     156,   315,   156,   315,   121,   115,   315,    20,   159,   169,
      20,   375,   315,   159,    25,   153,   172,   153,   172,   133,
     153,    25,   126,   126,    85,    86,    20,    15,    20,   138,
     181,    20,    26,   315,   159,   430,   431,    26,   315,    20,
     159,   169,    26,   337,   338,    26,   321,   322,   315,    25,
     126,    25,    69,   126,   306,    26,   326,   327,   159,   315,
      15,   159,   315,    17,    15,    24,   159,    20,    21,    15,
     115,    20,    20,   367,   367,   337,    20,   315,   159,   315,
     315,   315,    28,   196,    24,   201,   202,   203,   316,   316,
     316,   316,   316,   316,   316,    26,   441,   442,   115,   227,
     228,   230,   231,   241,   243,   254,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   457,   458,   459,
     460,   461,   464,   469,   470,     0,   284,   285,   287,   314,
     164,   164,    48,   140,   158,   168,   194,   319,   328,   329,
     137,    31,    89,    97,   100,   102,   113,   117,   122,   128,
     150,   184,   185,   186,   187,   188,   189,   359,   360,   361,
     238,   123,   147,   177,    73,   104,   124,   169,   180,   192,
      93,   112,   110,   178,    42,    43,   123,   147,   358,   115,
     365,   165,   166,   116,   379,   380,   375,   379,   375,   379,
     156,   156,   159,   316,   390,   315,   156,    48,   159,    48,
     159,   156,    48,    48,    25,    25,   121,    89,    24,   121,
      33,    94,   101,   417,   156,   159,   159,   156,    48,   159,
      48,   159,   108,   417,    48,   160,    35,   108,   250,   323,
     324,   417,    48,   159,    35,    15,    35,   126,    15,    25,
     101,   324,   417,    48,   159,    89,   156,     8,   143,   159,
     159,    18,   115,   315,   159,   159,   160,    20,    87,   173,
     395,   396,   156,   159,   156,   156,   196,    88,   164,    33,
     198,   199,   212,    33,   198,   199,   212,    33,   216,   216,
     101,    48,   214,   316,    24,    93,   180,   465,   468,    35,
     121,   466,    35,    68,   121,   463,   289,   290,   291,   316,
     316,   330,   331,   316,   330,   316,   158,   329,   158,   344,
     345,   346,   346,   346,   115,   121,   239,   382,   446,   448,
     449,   450,   451,   452,   453,   454,   349,   349,   348,   350,
     350,   350,   350,   351,   351,   352,   352,    20,   114,   193,
     418,   420,   421,   422,   418,   416,   421,   416,   156,   315,
     367,   367,   315,   380,    48,   159,   156,   115,    20,   432,
     432,   109,   132,   109,   132,    76,   159,   311,   312,    25,
     159,   311,   418,   316,    94,   101,   115,    20,   432,   433,
     432,   433,   316,   108,    76,   316,    76,   316,    76,   108,
     324,   108,   108,   323,   324,    76,   176,    25,   305,    89,
     305,    89,    35,   316,   101,   101,   324,    76,    25,   156,
     315,   156,   316,    89,     9,    10,    44,    79,    81,   115,
     170,   313,   392,   394,   404,   405,   408,    87,   173,   396,
      41,   340,   341,    24,   211,   213,   316,   316,   316,   211,
     213,   316,   316,   316,   316,   316,   316,   316,    76,   316,
     156,   466,   466,   468,    24,    24,   467,   465,    24,    68,
     463,   164,    34,    47,    72,    85,    86,   332,   333,   334,
     335,    48,   316,   158,   316,   315,   446,   452,   257,   480,
     138,   223,   226,   232,   233,   234,   240,   249,   255,   256,
     447,   455,   456,   457,   471,   474,   475,   477,   237,   244,
     245,   476,   219,   220,   221,   222,   247,   472,   134,   135,
     136,   419,   103,   156,   157,   316,   156,   315,   159,   159,
      26,    33,    94,   313,    48,   159,    33,    94,   313,   159,
     316,   156,   315,   103,   159,   159,   159,   159,   316,   338,
      26,    26,   316,   108,   316,   316,   108,   324,   108,   322,
     316,    48,    25,   305,   316,   316,   101,   327,   164,   156,
     115,    32,   155,   397,     7,   315,    20,   170,   404,   170,
     394,    76,   418,    68,   341,   164,   316,   316,   316,   316,
     442,   158,   218,   444,   445,    24,   159,   224,   225,   235,
     236,   248,   473,    48,   159,    48,   159,    25,   334,   335,
     335,   331,   316,   156,   159,   350,   246,   251,   479,   473,
     449,   479,   347,   350,   255,   455,   457,   450,   451,   473,
     156,   417,   418,   312,    33,    94,   313,   418,    33,    94,
     313,   156,   316,   316,   108,   316,    84,    25,    35,   316,
     156,   315,     3,    90,   400,   401,   403,   405,    23,    91,
     398,   399,   402,   405,   156,   173,    20,    20,   170,    26,
     158,    76,   158,   316,   376,   445,   350,   350,   350,   350,
      24,   242,   462,   463,   462,   335,   246,   252,   269,   478,
     478,   347,   253,    94,   313,   418,    94,   313,   418,   316,
     316,   305,   156,    32,    90,   403,   155,    91,   402,   173,
     173,    20,    33,   316,    26,   316,    48,   159,   177,   473,
      48,   159,   159,    94,   313,    94,   313,   173,   418,   158,
      76,   313,   350,   242,   463,   158,   316,    26,   316,   159,
     313
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
         0,   281,   282,   282,   282,   282,   283,   283,   284,   284,
     285,   286,   287,   287,   287,   288,   288,   289,   289,   290,
     290,   290,   290,   291,   291,   291,   291,   292,   292,   292,
     292,   292,   292,   292,   292,   293,   293,   294,   295,   295,
     296,   296,   297,   298,   299,   299,   300,   300,   301,   301,
     301,   301,   302,   303,   304,   304,   304,   304,   305,   305,
     306,   306,   307,   307,   307,   307,   308,   308,   308,   308,
     309,   309,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   311,   311,
     312,   312,   313,   314,   315,   315,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   317,   317,   317,
     317,   318,   318,   319,   319,   320,   321,   321,   322,   322,
     322,   322,   322,   322,   322,   322,   323,   324,   325,   326,
     326,   327,   327,   327,   327,   328,   329,   329,   330,   330,
     331,   331,   332,   332,   332,   332,   332,   332,   332,   333,
     333,   334,   334,   335,   336,   336,   337,   337,   338,   338,
     339,   339,   340,   340,   341,   341,   342,   343,   343,   344,
     344,   345,   345,   345,   345,   346,   346,   346,   347,   347,
     348,   348,   348,   349,   349,   349,   349,   349,   350,   350,
     350,   351,   351,   351,   352,   352,   353,   353,   354,   354,
     355,   355,   356,   356,   357,   357,   357,   357,   358,   358,
     358,   359,   359,   359,   359,   359,   359,   360,   360,   360,
     360,   360,   360,   361,   361,   361,   362,   362,   363,   363,
     364,   364,   365,   365,   366,   366,   366,   366,   367,   367,
     367,   368,   368,   369,   369,   369,   369,   370,   370,   371,
     371,   371,   371,   371,   371,   371,   372,   372,   373,   373,
     374,   374,   374,   374,   374,   375,   375,   376,   376,   377,
     377,   377,   378,   378,   379,   379,   380,   381,   381,   381,
     381,   381,   381,   381,   381,   382,   382,   383,   383,   383,
     384,   385,   385,   386,   387,   388,   389,   389,   390,   390,
     391,   391,   392,   392,   392,   393,   393,   393,   393,   393,
     393,   394,   394,   395,   395,   396,   397,   397,   398,   398,
     399,   399,   399,   399,   400,   400,   401,   401,   401,   401,
     402,   402,   403,   403,   404,   404,   404,   404,   405,   405,
     405,   405,   406,   406,   407,   407,   408,   409,   409,   409,
     409,   409,   409,   410,   411,   411,   411,   411,   412,   412,
     412,   412,   413,   414,   415,   415,   415,   415,   416,   416,
     417,   418,   418,   418,   419,   419,   419,   420,   420,   420,
     421,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     423,   424,   424,   424,   425,   426,   427,   427,   427,   428,
     428,   428,   428,   428,   429,   430,   430,   430,   430,   430,
     430,   430,   431,   432,   433,   434,   435,   435,   435,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   437,
     437,   438,   438,   439,   440,   441,   441,   442,   443,   444,
     444,   445,   445,   446,   446,   446,   446,   447,   447,   447,
     447,   448,   448,   449,   449,   450,   450,   451,   451,   452,
     452,   452,   453,   453,   454,   454,   455,   455,   455,   455,
     455,   456,   457,   457,   457,   457,   457,   457,   457,   458,
     458,   458,   458,   459,   459,   459,   459,   460,   460,   461,
     461,   461,   461,   461,   461,   461,   462,   462,   463,   463,
     463,   463,   464,   464,   464,   464,   464,   465,   465,   466,
     466,   467,   467,   468,   468,   469,   470,   470,   471,   471,
     471,   472,   472,   472,   472,   472,   473,   473,   473,   473,
     474,   475,   476,   477,   477,   478,   478,   478,   479,   479,
     480
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
       2,     3,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     4,
       5,     1,     2,     1,     1,     2,     1,     4,     3,     4,
       4,     5,     4,     5,     5,     6,     3,     3,     2,     1,
       4,     3,     4,     4,     5,     2,     2,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     2,     2,     3,     1,
       1,     1,     1,     2,     4,     4,     1,     4,     3,     4,
       7,     9,     1,     2,     4,     7,     7,     1,     3,     1,
       3,     1,     3,     3,     3,     1,     3,     4,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     4,
       1,     2,     3,     2,     1,     2,     2,     1,     1,     3,
       3,     1,     1,     1,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     3,     3,     3,     4,     1,     3,
       1,     1,     1,     1,     1,     3,     4,     6,     7,     7,
       8,     1,     2,     1,     2,     3,     3,     3,     0,     1,
       1,     1,     2,     2,     0,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     5,     6,     2,     3,
       5,     6,     3,     3,     4,     5,     6,     7,     1,     2,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     3,     2,     2,     2,     3,     3,     2,
       3,     5,     3,     5,     3,     2,     3,     5,     5,     3,
       5,     5,     3,     1,     2,     1,     2,     2,     2,     4,
       5,     5,     4,     4,     4,     5,     5,     4,     4,     2,
       2,     4,     4,     4,     6,     1,     4,     3,     5,     1,
       2,     4,     7,     1,     2,     3,     4,     1,     1,     2,
       2,     1,     3,     1,     3,     1,     3,     1,     2,     1,
       2,     3,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     4,     6,     4,     6,     1,     1,     3,     2,     4,
       4,     6,     2,     3,     1,     2,     1,     1,     2,     2,
       3,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     4,
       3,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       2
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
  "\"'ordered {'\"", "\"'<order by>'\"", "\"'parent::'\"", "\"'<?'\"",
  "\"'?>'\"", "\"'<pi {>'\"", "\"'<pi (>'\"", "\"'PI TARGET'\"", "\"'+'\"",
  "\"'PRAGMA BEGIN'\"", "\"'PRAGMA END'\"", "\"'<<'\"",
  "\"'preceding::'\"", "\"'preceding-sibling::'\"", "\"'preserve'\"",
  "\"'processing instruction'\"", "\"'\\\"'\"", "\"'}'\"", "\"']'\"",
  "\"'return'\"", "\"')'\"", "\"'satisfies'\"",
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
  "\"'all'\"", "\"'<all words>'\"", "\"'any'\"", "\"'<any words>'\"",
  "\"'<at end>'\"", "\"'<at least>'\"", "\"'<at most>'\"",
  "\"'<at start>'\"", "\"'<case insensitive>'\"", "\"'<casesensitive>'\"",
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
  "VarDecl", "ConstructionDecl", "FunctionDecl", "ParamList", "Param",
  "EnclosedExpr", "QueryBody", "Expr", "ExprSingle", "FLWORExpr",
  "ForLetClauseList", "ForLetClause", "ForClause", "VarInDeclList",
  "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
  "VarGetsDeclList", "VarGetsDecl", "WhereClause", "OrderByClause",
  "OrderSpecList", "OrderSpec", "OrderModifier", "OrderDirSpec",
  "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
  "QVarInDeclList", "QVarInDecl", "TypeswitchExpr", "CaseClauseList",
  "CaseClause", "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr",
  "FTContainsExpr", "RangeExpr", "AdditiveExpr", "MultiplicativeExpr",
  "UnionExpr", "IntersectExceptExpr", "InstanceofExpr", "TreatExpr",
  "CastableExpr", "CastExpr", "UnaryExpr", "SignList", "ValueExpr",
  "GeneralComp", "ValueComp", "NodeComp", "ValidateExpr", "ExtensionExpr",
  "PragmaList", "Pragma", "PathExpr", "RelativePathExpr", "StepExpr",
  "AxisStep", "ForwardStep", "ForwardAxis", "AbbrevForwardStep",
  "ReverseStep", "ReverseAxis", "NodeTest", "NameTest", "Wildcard",
  "FilterExpr", "PredicateList", "Predicate", "PrimaryExpr", "Literal",
  "NumericLiteral", "VarRef", "ParenthesizedExpr", "ContextItemExpr",
  "OrderedExpr", "UnorderedExpr", "FunctionCall", "ArgList", "Constructor",
  "DirectConstructor", "DirElemConstructor", "DirElemContentList",
  "DirAttributeList", "DirAttr", "DirAttributeValue",
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
  "VarNameDecl", "TryExpr", "CatchListExpr", "CatchExpr", "FTSelection",
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
       282,     0,    -1,   284,    -1,   283,   284,    -1,   285,    -1,
     283,   285,    -1,   197,    24,   164,    -1,   197,    24,    88,
      24,   164,    -1,   287,   314,    -1,   314,    -1,   286,   287,
      -1,   125,    15,    89,    25,   164,    -1,   288,   164,    -1,
     289,   164,    -1,   288,   164,   289,   164,    -1,   290,    -1,
     288,   164,   290,    -1,   291,    -1,   289,   164,   291,    -1,
     292,    -1,   293,    -1,   294,    -1,   296,    -1,   308,    -1,
     310,    -1,   297,    -1,   298,    -1,   295,    -1,   302,    -1,
     303,    -1,   309,    -1,   299,    -1,   300,    -1,   301,    -1,
     435,    -1,   304,    -1,   307,    -1,    63,    15,    89,    25,
      -1,    55,   153,    -1,    55,   172,    -1,    59,   126,    25,
      -1,    60,   126,    25,    -1,    64,    20,    24,    -1,   229,
     457,    -1,    65,   138,    -1,    65,   181,    -1,    61,    85,
      -1,    61,    86,    -1,    57,   153,    48,   109,    -1,    57,
     153,    48,   132,    -1,    57,   133,    48,   109,    -1,    57,
     133,    48,   132,    -1,    58,    25,    -1,    54,    25,    -1,
     107,    25,    -1,   107,   306,    25,    -1,   107,    25,    35,
     305,    -1,   107,   306,    25,    35,   305,    -1,    25,    -1,
     305,    48,    25,    -1,   126,    15,    89,    -1,    69,   126,
      -1,   106,    25,    -1,   106,   126,    15,    89,    25,    -1,
     106,    25,    35,   305,    -1,   106,   126,    15,    89,    25,
      35,   305,    -1,    67,    26,   101,   316,    -1,    67,    26,
      94,    -1,    67,    26,   417,   101,   316,    -1,    67,    26,
     417,    94,    -1,    56,   153,    -1,    56,   172,    -1,    62,
      20,   121,   159,    94,    -1,    62,    20,   121,   159,   313,
      -1,    62,    20,   121,   311,   159,    94,    -1,    62,    20,
     121,   311,   159,   313,    -1,    62,    20,   121,   159,    33,
     418,    94,    -1,    62,    20,   121,   159,    33,   418,   313,
      -1,    62,    20,   121,   311,   159,    33,   418,    94,    -1,
      62,    20,   121,   311,   159,    33,   418,   313,    -1,    66,
      20,   121,   159,    94,    -1,    66,    20,   121,   159,   313,
      -1,    66,    20,   121,   311,   159,    94,    -1,    66,    20,
     121,   311,   159,   313,    -1,    66,    20,   121,   159,    33,
     418,    94,    -1,    66,    20,   121,   159,    33,   418,   313,
      -1,    66,    20,   121,   311,   159,    33,   418,    94,    -1,
      66,    20,   121,   311,   159,    33,   418,   313,    -1,   312,
      -1,   311,    48,   312,    -1,    76,    26,    -1,    76,    26,
     417,    -1,   115,   315,   156,    -1,   315,    -1,   316,    -1,
     315,    48,   316,    -1,   317,    -1,   336,    -1,   339,    -1,
     342,    -1,   343,    -1,   436,    -1,   437,    -1,   439,    -1,
     438,    -1,   440,    -1,   443,    -1,   318,   158,   316,    -1,
     318,   328,   158,   316,    -1,   318,   329,   158,   316,    -1,
     318,   328,   329,   158,   316,    -1,   319,    -1,   318,   319,
      -1,   320,    -1,   325,    -1,    98,   321,    -1,   322,    -1,
     321,    48,    76,   322,    -1,    26,   108,   316,    -1,    26,
     417,   108,   316,    -1,    26,   323,   108,   316,    -1,    26,
     417,   323,   108,   316,    -1,    26,   324,   108,   316,    -1,
      26,   417,   324,   108,   316,    -1,    26,   323,   324,   108,
     316,    -1,    26,   417,   323,   324,   108,   316,    -1,    35,
      76,    26,    -1,   250,    76,    26,    -1,   119,   326,    -1,
     327,    -1,   326,    48,    76,   327,    -1,    26,   101,   316,
      -1,    26,   417,   101,   316,    -1,    26,   324,   101,   316,
      -1,    26,   417,   324,   101,   316,    -1,   194,   316,    -1,
     140,   330,    -1,   168,   330,    -1,   331,    -1,   330,    48,
     331,    -1,   316,    -1,   316,   332,    -1,   333,    -1,   334,
      -1,   335,    -1,   333,   334,    -1,   333,   335,    -1,   334,
     335,    -1,   333,   334,   335,    -1,    34,    -1,    72,    -1,
      85,    -1,    86,    -1,    47,    25,    -1,   167,   337,   160,
     316,    -1,    92,   337,   160,   316,    -1,   338,    -1,   337,
      48,    76,   338,    -1,    26,   108,   316,    -1,    26,   417,
     108,   316,    -1,   179,   315,   159,   340,    68,   158,   316,
      -1,   179,   315,   159,   340,    68,    76,    26,   158,   316,
      -1,   341,    -1,   340,   341,    -1,    41,   418,   158,   316,
      -1,    41,    76,    26,    33,   418,   158,   316,    -1,   105,
     315,   159,   176,   316,    84,   316,    -1,   344,    -1,   343,
     137,   344,    -1,   345,    -1,   344,    31,   345,    -1,   346,
      -1,   346,   360,   346,    -1,   346,   359,   346,    -1,   346,
     361,   346,    -1,   347,    -1,   347,   238,   446,    -1,   347,
     238,   446,   480,    -1,   348,    -1,   348,   177,   348,    -1,
     349,    -1,   348,   147,   349,    -1,   348,   123,   349,    -1,
     350,    -1,   349,   169,   350,    -1,   349,    73,   350,    -1,
     349,   104,   350,    -1,   349,   124,   350,    -1,   351,    -1,
     350,   180,   351,    -1,   350,   192,   351,    -1,   352,    -1,
     351,   112,   352,    -1,   351,    93,   352,    -1,   353,    -1,
     353,   110,   418,    -1,   354,    -1,   354,   178,   418,    -1,
     355,    -1,   355,    42,   416,    -1,   356,    -1,   356,    43,
     416,    -1,   358,    -1,   357,   358,    -1,   147,    -1,   123,
      -1,   357,   147,    -1,   357,   123,    -1,   362,    -1,   366,
      -1,   363,    -1,    89,    -1,   128,    -1,   122,    -1,   117,
      -1,   102,    -1,   100,    -1,   184,    -1,   189,    -1,   188,
      -1,   187,    -1,   186,    -1,   185,    -1,   113,    -1,   150,
      -1,    97,    -1,   190,   315,   156,    -1,    27,   115,   315,
     156,    -1,   364,   115,   156,    -1,   364,   115,   315,   156,
      -1,   365,    -1,   364,   365,    -1,   148,    20,    18,    -1,
     148,    21,    -1,   165,    -1,   165,   367,    -1,   166,   367,
      -1,   367,    -1,   368,    -1,   368,   165,   367,    -1,   368,
     166,   367,    -1,   369,    -1,   378,    -1,   370,    -1,   370,
     379,    -1,   373,    -1,   373,   379,    -1,   371,   375,    -1,
     372,    -1,    46,    -1,    70,    -1,    37,    -1,   163,    -1,
      71,    -1,    96,    -1,    95,    -1,   375,    -1,    40,   375,
      -1,   374,   375,    -1,    78,    -1,   141,    -1,    29,    -1,
     152,    -1,   151,    -1,    30,    -1,   422,    -1,   376,    -1,
      20,    -1,   377,    -1,   169,    -1,    12,    -1,    19,    -1,
     381,    -1,   381,   379,    -1,   380,    -1,   379,   380,    -1,
     116,   315,   157,    -1,   382,    -1,   384,    -1,   385,    -1,
     386,    -1,   389,    -1,   391,    -1,   387,    -1,   388,    -1,
     383,    -1,   434,    -1,    53,    -1,   111,    -1,    80,    -1,
      76,    26,    -1,   121,   159,    -1,   121,   315,   159,    -1,
      77,    -1,   139,   315,   156,    -1,   182,   315,   156,    -1,
      20,   121,   159,    -1,    20,   121,   390,   159,    -1,   316,
      -1,   390,    48,   316,    -1,   392,    -1,   409,    -1,   393,
      -1,   406,    -1,   407,    -1,   171,    20,    87,    -1,   171,
      20,   395,    87,    -1,   171,    20,   173,   170,    20,   173,
      -1,   171,    20,   173,   394,   170,    20,   173,    -1,   171,
      20,   395,   173,   170,    20,   173,    -1,   171,    20,   395,
     173,   394,   170,    20,   173,    -1,   404,    -1,   394,   404,
      -1,   396,    -1,   395,   396,    -1,    20,    89,   397,    -1,
     155,   398,   155,    -1,    32,   400,    32,    -1,    -1,   399,
      -1,    91,    -1,   402,    -1,   399,    91,    -1,   399,   402,
      -1,    -1,   401,    -1,    90,    -1,   403,    -1,   401,    90,
      -1,   401,   403,    -1,    23,    -1,   405,    -1,     3,    -1,
     405,    -1,   392,    -1,    10,    -1,   408,    -1,   405,    -1,
       9,    -1,    79,    -1,    81,    -1,   313,    -1,   195,    28,
     196,    -1,   195,   196,    -1,   142,    17,   143,    -1,   142,
      17,     8,    -1,    44,     7,    -1,   410,    -1,   411,    -1,
     412,    -1,   413,    -1,   414,    -1,   415,    -1,    74,   315,
     156,    -1,    11,   156,    -1,    11,   315,   156,    -1,    82,
     315,   156,   115,   156,    -1,    82,   315,   156,   115,   315,
     156,    -1,     4,   156,    -1,     4,   315,   156,    -1,    38,
     315,   156,   115,   156,    -1,    38,   315,   156,   115,   315,
     156,    -1,   174,   315,   156,    -1,    51,   315,   156,    -1,
     154,    15,   115,   156,    -1,   154,    15,   115,   315,   156,
      -1,   154,   115,   315,   156,   115,   156,    -1,   154,   115,
     315,   156,   115,   315,   156,    -1,   421,    -1,   421,   103,
      -1,    33,   418,    -1,   420,    -1,   420,   419,    -1,   193,
      -1,   134,    -1,   136,    -1,   135,    -1,   421,    -1,   422,
      -1,   114,    -1,    20,    -1,   424,    -1,   430,    -1,   428,
      -1,   431,    -1,   429,    -1,   427,    -1,   426,    -1,   425,
      -1,   423,    -1,   130,   159,    -1,    75,   159,    -1,    75,
     430,   159,    -1,    75,   431,   159,    -1,   175,   159,    -1,
      52,   159,    -1,   145,   159,    -1,   145,    15,   159,    -1,
     145,    24,   159,    -1,    39,   159,    -1,    39,    20,   159,
      -1,    39,    20,    48,   432,   159,    -1,    39,   169,   159,
      -1,    39,   169,    48,   432,   159,    -1,   161,    20,   159,
      -1,    83,   159,    -1,    83,    20,   159,    -1,    83,    20,
      48,   432,   159,    -1,    83,    20,    48,   433,   159,    -1,
      83,   169,   159,    -1,    83,   169,    48,   432,   159,    -1,
      83,   169,    48,   433,   159,    -1,   162,    20,   159,    -1,
      20,    -1,    20,   103,    -1,    24,    -1,   200,   201,    -1,
     200,   202,    -1,   200,   203,    -1,   206,   316,   212,   316,
      -1,   206,   316,    33,   211,   316,    -1,   206,   316,    33,
     213,   316,    -1,   206,   316,   198,   316,    -1,   206,   316,
     199,   316,    -1,   207,   316,   212,   316,    -1,   207,   316,
      33,   211,   316,    -1,   207,   316,    33,   213,   316,    -1,
     207,   316,   198,   316,    -1,   207,   316,   199,   316,    -1,
     204,   316,    -1,   205,   316,    -1,   209,   316,   216,   316,
      -1,   210,   316,   216,   316,    -1,   208,   316,    33,   316,
      -1,   215,   441,   214,   316,   158,   316,    -1,   442,    -1,
     441,    48,    76,   442,    -1,    26,   101,   316,    -1,   217,
     115,   316,   156,   444,    -1,   445,    -1,   444,   445,    -1,
     218,   376,   159,   313,    -1,   218,   376,    48,    76,    26,
     159,   313,    -1,   448,    -1,   448,   447,    -1,   448,   255,
     347,    -1,   448,   447,   255,   347,    -1,   457,    -1,   455,
      -1,   447,   457,    -1,   447,   455,    -1,   449,    -1,   448,
     240,   449,    -1,   450,    -1,   449,   237,   450,    -1,   451,
      -1,   450,   244,   451,    -1,   452,    -1,   239,   452,    -1,
     453,    -1,   453,   476,    -1,   121,   446,   159,    -1,   454,
      -1,   454,   472,    -1,   382,    -1,   115,   315,   156,    -1,
     456,    -1,   475,    -1,   474,    -1,   477,    -1,   471,    -1,
     138,    -1,   458,    -1,   459,    -1,   460,    -1,   461,    -1,
     464,    -1,   469,    -1,   470,    -1,   243,    -1,   254,    -1,
     228,    -1,   227,    -1,   264,    -1,   258,    -1,   231,    -1,
     230,    -1,   265,    -1,   259,    -1,   267,   463,    -1,   267,
      68,    -1,   267,   121,   463,   159,    -1,   267,   121,   463,
      48,   462,   159,    -1,   267,   121,    68,   159,    -1,   267,
     121,    68,    48,   462,   159,    -1,   261,    -1,   463,    -1,
     462,    48,   463,    -1,    35,    24,    -1,    35,    24,   248,
      24,    -1,    35,    24,   473,   242,    -1,    35,    24,   248,
      24,   473,   242,    -1,   266,   466,    -1,   266,   466,   465,
      -1,   263,    -1,   263,   465,    -1,   260,    -1,   468,    -1,
     465,   468,    -1,    35,    24,    -1,   121,   467,   159,    -1,
      24,    -1,   467,    24,    -1,   180,   466,    -1,    93,   466,
      -1,   241,    24,    -1,   268,    -1,   262,    -1,   226,    -1,
     223,    -1,   234,    -1,   221,    -1,   222,    -1,   219,    -1,
     220,    -1,   247,    -1,   235,   350,    -1,   224,   350,    -1,
     225,   350,    -1,   236,   350,   177,   350,    -1,   233,   473,
     478,    -1,   256,   350,   478,    -1,   245,   473,   253,    -1,
     249,   479,    -1,   232,   479,    -1,   269,    -1,   252,    -1,
     246,    -1,   251,    -1,   246,    -1,   257,   350,    -1
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
     365,   368,   372,   376,   378,   380,   384,   386,   388,   390,
     392,   394,   396,   398,   400,   402,   404,   406,   410,   415,
     420,   426,   428,   431,   433,   435,   438,   440,   445,   449,
     454,   459,   465,   470,   476,   482,   489,   493,   497,   500,
     502,   507,   511,   516,   521,   527,   530,   533,   536,   538,
     542,   544,   547,   549,   551,   553,   556,   559,   562,   566,
     568,   570,   572,   574,   577,   582,   587,   589,   594,   598,
     603,   611,   621,   623,   626,   631,   639,   647,   649,   653,
     655,   659,   661,   665,   669,   673,   675,   679,   684,   686,
     690,   692,   696,   700,   702,   706,   710,   714,   718,   720,
     724,   728,   730,   734,   738,   740,   744,   746,   750,   752,
     756,   758,   762,   764,   767,   769,   771,   774,   777,   779,
     781,   783,   785,   787,   789,   791,   793,   795,   797,   799,
     801,   803,   805,   807,   809,   811,   813,   817,   822,   826,
     831,   833,   836,   840,   843,   845,   848,   851,   853,   855,
     859,   863,   865,   867,   869,   872,   874,   877,   880,   882,
     884,   886,   888,   890,   892,   894,   896,   898,   901,   904,
     906,   908,   910,   912,   914,   916,   918,   920,   922,   924,
     926,   928,   930,   932,   935,   937,   940,   944,   946,   948,
     950,   952,   954,   956,   958,   960,   962,   964,   966,   968,
     970,   973,   976,   980,   982,   986,   990,   994,   999,  1001,
    1005,  1007,  1009,  1011,  1013,  1015,  1019,  1024,  1031,  1039,
    1047,  1056,  1058,  1061,  1063,  1066,  1070,  1074,  1078,  1079,
    1081,  1083,  1085,  1088,  1091,  1092,  1094,  1096,  1098,  1101,
    1104,  1106,  1108,  1110,  1112,  1114,  1116,  1118,  1120,  1122,
    1124,  1126,  1128,  1132,  1135,  1139,  1143,  1146,  1148,  1150,
    1152,  1154,  1156,  1158,  1162,  1165,  1169,  1175,  1182,  1185,
    1189,  1195,  1202,  1206,  1210,  1215,  1221,  1228,  1236,  1238,
    1241,  1244,  1246,  1249,  1251,  1253,  1255,  1257,  1259,  1261,
    1263,  1265,  1267,  1269,  1271,  1273,  1275,  1277,  1279,  1281,
    1283,  1286,  1289,  1293,  1297,  1300,  1303,  1306,  1310,  1314,
    1317,  1321,  1327,  1331,  1337,  1341,  1344,  1348,  1354,  1360,
    1364,  1370,  1376,  1380,  1382,  1385,  1387,  1390,  1393,  1396,
    1401,  1407,  1413,  1418,  1423,  1428,  1434,  1440,  1445,  1450,
    1453,  1456,  1461,  1466,  1471,  1478,  1480,  1485,  1489,  1495,
    1497,  1500,  1505,  1513,  1515,  1518,  1522,  1527,  1529,  1531,
    1534,  1537,  1539,  1543,  1545,  1549,  1551,  1555,  1557,  1560,
    1562,  1565,  1569,  1571,  1574,  1576,  1580,  1582,  1584,  1586,
    1588,  1590,  1592,  1594,  1596,  1598,  1600,  1602,  1604,  1606,
    1608,  1610,  1612,  1614,  1616,  1618,  1620,  1622,  1624,  1626,
    1629,  1632,  1637,  1644,  1649,  1656,  1658,  1660,  1664,  1667,
    1672,  1677,  1684,  1687,  1691,  1693,  1696,  1698,  1700,  1703,
    1706,  1710,  1712,  1715,  1718,  1721,  1724,  1726,  1728,  1730,
    1732,  1734,  1736,  1738,  1740,  1742,  1744,  1747,  1750,  1753,
    1758,  1762,  1766,  1770,  1773,  1776,  1778,  1780,  1782,  1784,
    1786
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   741,   741,   749,   757,   764,   777,   785,   798,   808,
     823,   838,   853,   862,   871,   886,   895,   912,   921,   938,
     945,   952,   959,   971,   978,   985,   994,  1007,  1014,  1021,
    1028,  1035,  1042,  1049,  1058,  1071,  1078,  1096,  1111,  1119,
    1133,  1142,  1157,  1173,  1187,  1195,  1210,  1218,  1232,  1241,
    1250,  1259,  1281,  1295,  1309,  1319,  1329,  1339,  1355,  1364,
    1382,  1389,  1402,  1411,  1421,  1430,  1447,  1457,  1467,  1477,
    1493,  1501,  1515,  1525,  1536,  1547,  1559,  1571,  1583,  1595,
    1607,  1617,  1628,  1639,  1651,  1663,  1675,  1687,  1705,  1716,
    1733,  1742,  1757,  1771,  1785,  1794,  1809,  1816,  1823,  1830,
    1837,  1846,  1853,  1860,  1867,  1874,  1881,  1894,  1904,  1915,
    1926,  1943,  1952,  1967,  1974,  1987,  2001,  2010,  2027,  2037,
    2048,  2060,  2073,  2084,  2096,  2108,  2126,  2141,  2155,  2170,
    2179,  2196,  2207,  2219,  2230,  2248,  2262,  2270,  2285,  2294,
    2311,  2320,  2335,  2345,  2355,  2365,  2375,  2385,  2395,  2411,
    2418,  2431,  2439,  2453,  2467,  2477,  2493,  2503,  2518,  2527,
    2543,  2553,  2570,  2579,  2594,  2603,  2619,  2633,  2640,  2654,
    2661,  2683,  2690,  2701,  2712,  2729,  2736,  2746,  2762,  2769,
    2783,  2790,  2797,  2810,  2817,  2824,  2831,  2838,  2851,  2858,
    2866,  2880,  2887,  2894,  2907,  2914,  2929,  2936,  2951,  2958,
    2973,  2980,  2995,  3002,  3017,  3024,  3031,  3038,  3053,  3060,
    3067,  3081,  3088,  3095,  3102,  3109,  3116,  3129,  3136,  3143,
    3150,  3157,  3164,  3177,  3184,  3191,  3205,  3212,  3227,  3236,
    3251,  3260,  3277,  3286,  3328,  3335,  3342,  3349,  3363,  3371,
    3378,  3391,  3398,  3411,  3420,  3429,  3438,  3453,  3462,  3476,
    3483,  3490,  3497,  3504,  3511,  3518,  3531,  3538,  3551,  3560,
    3575,  3582,  3589,  3596,  3603,  3621,  3628,  3641,  3648,  3661,
    3671,  3681,  3697,  3704,  3719,  3728,  3745,  3759,  3766,  3773,
    3780,  3787,  3794,  3801,  3808,  3821,  3828,  3841,  3849,  3857,
    3871,  3884,  3891,  3905,  3918,  3932,  3991,  4000,  4015,  4024,
    4039,  4046,  4059,  4066,  4073,  4086,  4097,  4108,  4119,  4130,
    4141,  4159,  4168,  4183,  4192,  4209,  4224,  4232,  4247,  4253,
    4260,  4269,  4278,  4289,  4307,  4313,  4320,  4329,  4338,  4349,
    4366,  4374,  4388,  4396,  4410,  4418,  4426,  4435,  4450,  4459,
    4467,  4475,  4489,  4497,  4515,  4523,  4543,  4561,  4568,  4575,
    4582,  4589,  4596,  4609,  4623,  4632,  4641,  4649,  4677,  4686,
    4695,  4703,  4717,  4731,  4745,  4754,  4763,  4771,  4785,  4794,
    4809,  4823,  4832,  4841,  4881,  4889,  4897,  4911,  4918,  4925,
    4938,  4952,  4959,  4966,  4973,  4980,  4987,  4994,  5001,  5008,
    5021,  5034,  5041,  5049,  5063,  5076,  5089,  5096,  5103,  5116,
    5125,  5134,  5143,  5152,  5167,  5181,  5190,  5199,  5208,  5217,
    5227,  5237,  5253,  5277,  5287,  5310,  5353,  5361,  5367,  5378,
    5387,  5396,  5405,  5414,  5424,  5433,  5442,  5451,  5460,  5475,
    5483,  5496,  5505,  5520,  5549,  5563,  5570,  5586,  5603,  5613,
    5623,  5637,  5647,  5674,  5680,  5686,  5692,  5704,  5710,  5716,
    5722,  5734,  5740,  5752,  5758,  5770,  5776,  5788,  5794,  5806,
    5812,  5818,  5830,  5836,  5848,  5854,  5866,  5872,  5878,  5884,
    5890,  5902,  5914,  5921,  5928,  5935,  5942,  5949,  5956,  5969,
    5975,  5981,  5987,  5999,  6005,  6011,  6017,  6029,  6035,  6047,
    6053,  6059,  6065,  6071,  6077,  6083,  6095,  6101,  6113,  6119,
    6125,  6131,  6143,  6149,  6155,  6161,  6167,  6179,  6185,  6197,
    6203,  6215,  6221,  6233,  6239,  6251,  6263,  6269,  6281,  6287,
    6293,  6305,  6311,  6317,  6323,  6329,  6341,  6348,  6355,  6362,
    6375,  6387,  6399,  6411,  6417,  6429,  6435,  6441,  6453,  6459,
    6471
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
  const int xquery_parser::yylast_ = 3902;
  const int xquery_parser::yynnts_ = 200;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 325;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 281;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 535;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 6481 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"



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

