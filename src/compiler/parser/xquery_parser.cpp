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
#line 729 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"

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
#line 629 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).decval; };
#line 211 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 80: /* "\"'DOUBLE'\"" */
#line 628 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).dval; };
#line 216 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 111: /* "\"'INTEGER'\"" */
#line 627 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).ival; };
#line 221 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 284: /* "VersionDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 226 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 285: /* "MainModule" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 231 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "LibraryModule" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 236 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "ModuleDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 241 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "Prolog" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 246 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "SIND_DeclList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 251 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "VFO_DeclList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 256 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "SIND_Decl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 261 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "VFO_Decl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 266 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "Setter" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 271 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "Import" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 276 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "NamespaceDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 281 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "BoundarySpaceDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 286 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "DefaultNamespaceDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 291 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "OptionDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 296 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "OrderingModeDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 301 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "EmptyOrderDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 306 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "CopyNamespacesDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 311 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "DefaultCollationDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 316 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "BaseURIDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 321 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "SchemaImport" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 326 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "URILiteralList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 331 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "SchemaPrefix" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 336 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "ModuleImport" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 341 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "VarDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 346 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "ConstructionDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 351 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "FunctionDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 356 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "ParamList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 361 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "Param" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 366 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "EnclosedExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 371 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "NonNodeEnclosedExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 376 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "QueryBody" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 381 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "Expr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 386 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "ExprSingle" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 391 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "FLWORExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 396 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "ForLetClauseList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 401 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "ForLetClause" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 406 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "ForClause" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 411 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "VarInDeclList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 416 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "VarInDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 421 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "PositionalVar" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 426 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "LetClause" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 431 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "VarGetsDeclList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 436 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "VarGetsDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 441 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "WhereClause" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 446 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "GroupByClause" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 451 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "GroupSpecList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 456 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "GroupSpec" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 461 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "GroupCollationSpec" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 466 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "LetClauseList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 471 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "OrderByClause" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 476 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "OrderSpecList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 481 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OrderSpec" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 486 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "OrderModifier" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 491 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "OrderDirSpec" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 496 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "OrderEmptySpec" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 501 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "OrderCollationSpec" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 506 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "QuantifiedExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 511 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "QVarInDeclList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 516 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "QVarInDecl" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 521 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "TypeswitchExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 526 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CaseClauseList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 531 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CaseClause" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 536 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "IfExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 541 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "OrExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 546 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "AndExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 551 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "ComparisonExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 556 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "RangeExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 561 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "AdditiveExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 566 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "MultiplicativeExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 571 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "UnionExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 576 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "IntersectExceptExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 581 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "InstanceofExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 586 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "TreatExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 591 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "CastableExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 596 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "CastExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 601 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "UnaryExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 606 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "SignList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 611 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "ValueExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 616 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "GeneralComp" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 621 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "ValueComp" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 626 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "NodeComp" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 631 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ValidateExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 636 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ExtensionExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 641 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "PragmaList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 646 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "Pragma" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 651 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "PathExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 656 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "RelativePathExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 661 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "StepExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 666 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "AxisStep" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 671 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "ForwardStep" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 676 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ForwardAxis" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 681 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "AbbrevForwardStep" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 686 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ReverseStep" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 691 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ReverseAxis" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 696 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "NodeTest" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 701 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "NameTest" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 706 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "Wildcard" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 711 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "FilterExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 716 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "PredicateList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 721 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "Predicate" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 726 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "PrimaryExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 731 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "Literal" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 736 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "NumericLiteral" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 741 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "VarRef" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 746 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ParenthesizedExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 751 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ContextItemExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 756 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "OrderedExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 761 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "UnorderedExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 766 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "FunctionCall" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 771 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ArgList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 776 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "Constructor" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 781 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "DirectConstructor" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 786 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "DirElemConstructor" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 791 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "DirElemContentList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 796 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "DirAttributeList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 801 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "DirAttr" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 806 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "DirAttributeValue" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 811 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "Opt_QuoteAttrContentList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 816 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "QuoteAttrContentList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 821 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "Opt_AposAttrContentList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 826 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "AposAttrContentList" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 831 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "QuoteAttrValueContent" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 836 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "AposAttrValueContent" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 841 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "DirElemContent" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 846 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "CommonContent" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 851 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "DirCommentConstructor" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 856 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "DirPIConstructor" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 861 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "CDataSection" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 866 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "ComputedConstructor" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 871 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "CompDocConstructor" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 876 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "CompElemConstructor" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 881 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "CompAttrConstructor" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 886 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "CompTextConstructor" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 891 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "CompCommentConstructor" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 896 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "CompPIConstructor" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 901 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "SingleType" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 906 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "TypeDeclaration" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 911 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "SequenceType" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 916 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "OccurrenceIndicator" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 921 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "ItemType" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 926 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "AtomicType" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 931 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "KindTest" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 936 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "AnyKindTest" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 941 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "DocumentTest" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 946 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "TextTest" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 951 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "CommentTest" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 956 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "PITest" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 961 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "AttributeTest" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 966 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "SchemaAttributeTest" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 971 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "ElementTest" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 976 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "SchemaElementTest" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 981 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "TypeName" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 986 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "TypeName_WITH_HOOK" */
#line 633 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 991 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "StringLiteral" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 996 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "TryExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 1001 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CatchListExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 1006 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "CatchExpr" */
#line 634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 1011 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 69 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename.getStore()->str());
}
  /* Line 547 of yacc.c.  */
#line 1092 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
#line 750 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 3:
#line 758 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 767 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]" << endl;
#endif
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 5:
#line 774 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]" << endl;
#endif
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		;}
    break;

  case 6:
#line 787 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]" << endl;
#endif
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), encoding);
		;}
    break;

  case 7:
#line 795 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]" << endl;
#endif
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (2)].sval)), SYMTAB ((yysemantic_stack_[(5) - (4)].sval)));
    ;}
    break;

  case 8:
#line 808 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 818 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 833 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 848 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 863 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 872 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 881 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 896 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 905 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 922 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 931 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 948 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 955 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 962 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 969 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 981 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 988 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 995 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 1004 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 1017 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 1024 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 1031 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1038 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1045 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1052 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1059 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1068 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1081 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1088 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1106 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1121 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1129 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1143 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1152 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1167 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1183 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]" << endl;
#endif
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1197 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1205 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1220 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1228 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1242 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1251 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1260 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1269 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1291 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]" << endl;
#endif
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1305 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]" << endl;
#endif
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1319 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1329 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1339 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1349 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1365 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1374 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1392 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1399 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 62:
#line 1412 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1421 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1431 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1440 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1457 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1467 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1477 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1487 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1503 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1511 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1525 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1535 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1546 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1557 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1569 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1581 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1593 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1605 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1617 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1627 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1638 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1649 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1661 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1673 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1685 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1697 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1715 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1726 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1743 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1752 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1767 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1778 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NonNodeEnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 94:
#line 1792 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]" << endl;
#endif
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 95:
#line 1806 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1815 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1830 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1837 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1844 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1851 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1858 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1867 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1874 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1881 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1888 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1895 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 107:
#line 1902 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
      cout << "ExprSingle [TryExpr]" << endl;
#endif
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 108:
#line 1915 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 109:
#line 1925 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 110:
#line 1936 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 111:
#line 1947 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 112:
#line 1959 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 113:
#line 1974 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 114:
#line 1989 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 115:
#line 2004 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 116:
#line 2025 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [single]" << endl;
#endif
			ForLetClauseList* flc_list_p = new ForLetClauseList(LOC ((yyloc)));
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = flc_list_p;
		;}
    break;

  case 117:
#line 2034 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [list]" << endl;
#endif
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(2) - (1)].node));
			if (flc_list_p) flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 118:
#line 2049 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 119:
#line 2056 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 120:
#line 2069 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]" << endl;
#endif
			(yyval.node) = new ForClause(LOC ((yyloc)),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 121:
#line 2083 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDeclList [single]" << endl;
#endif
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 122:
#line 2092 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 123:
#line 2109 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 124:
#line 2119 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 125:
#line 2130 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 126:
#line 2142 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 127:
#line 2155 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 128:
#line 2166 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 129:
#line 2178 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 130:
#line 2190 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 131:
#line 2208 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]" << endl;
#endif
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 132:
#line 2223 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]" << endl;
#endif
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 133:
#line 2237 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]" << endl;
#endif
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 134:
#line 2252 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [single]" << endl;
#endif
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 135:
#line 2261 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 136:
#line 2278 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 137:
#line 2289 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 138:
#line 2301 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 139:
#line 2312 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 140:
#line 2330 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]" << endl;
#endif
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 141:
#line 2341 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 142:
#line 2351 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 143:
#line 2361 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 144:
#line 2371 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 145:
#line 2384 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupSpecList [single]" << endl;
#endif
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 146:
#line 2393 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 147:
#line 2407 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupSpec []" << endl;
#endif
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 148:
#line 2416 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupSpec [collation]" << endl;
#endif
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 149:
#line 2428 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupCollationSpec [ ]" << endl;
#endif
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 150:
#line 2438 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClauseList [single]" << endl;
#endif
      LetClauseList* lc_list_p = new LetClauseList(LOC((yyloc)));
      lc_list_p->push_back(dynamic_cast<LetClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = lc_list_p;
    ;}
    break;

  case 151:
#line 2448 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClauseList [list]" << endl;
#endif
      LetClauseList* lc_list_p = dynamic_cast<LetClauseList*>((yysemantic_stack_[(2) - (1)].node));
      if (lc_list_p) lc_list_p->push_back(dynamic_cast<LetClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    ;}
    break;

  case 152:
#line 2463 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]" << endl;
#endif
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 153:
#line 2471 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [stable]" << endl;
#endif
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)),
								true);
		;}
    break;

  case 154:
#line 2486 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpecList [single]" << endl;
#endif
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 155:
#line 2495 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 156:
#line 2512 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single]" << endl;
#endif
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 157:
#line 2521 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single.modifier]" << endl;
#endif
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 158:
#line 2536 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 159:
#line 2546 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 160:
#line 2556 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 161:
#line 2566 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 162:
#line 2576 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 163:
#line 2586 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 164:
#line 2596 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 165:
#line 2612 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 166:
#line 2619 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 167:
#line 2632 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 168:
#line 2640 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 169:
#line 2654 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]" << endl;
#endif
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 170:
#line 2668 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 171:
#line 2678 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 172:
#line 2694 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [single]" << endl;
#endif
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 173:
#line 2704 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [list]" << endl;
#endif
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 174:
#line 2719 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDecl [in]" << endl;
#endif
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 175:
#line 2728 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 176:
#line 2744 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 177:
#line 2754 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 178:
#line 2771 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [single]" << endl;
#endif
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 179:
#line 2780 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [list]" << endl;
#endif
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 180:
#line 2795 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClause [case.return]" << endl;
#endif
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 181:
#line 2804 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 182:
#line 2820 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]" << endl;
#endif
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 183:
#line 2834 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 184:
#line 2841 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]" << endl;
#endif
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 185:
#line 2855 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 186:
#line 2862 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]" << endl;
#endif
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 187:
#line 2884 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 188:
#line 2891 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 189:
#line 2902 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 190:
#line 2913 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 191:
#line 2930 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 192:
#line 2937 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 193:
#line 2947 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 194:
#line 2963 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 195:
#line 2970 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]" << endl;
#endif
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 196:
#line 2984 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 197:
#line 2991 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 198:
#line 2998 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 199:
#line 3011 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]" << endl;
#endif
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 200:
#line 3018 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 201:
#line 3025 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 202:
#line 3032 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 203:
#line 3039 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 204:
#line 3052 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 205:
#line 3059 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 206:
#line 3067 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 207:
#line 3081 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 208:
#line 3088 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 209:
#line 3095 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 210:
#line 3108 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 211:
#line 3115 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat.seqtype]" << endl;
#endif
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 212:
#line 3130 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 213:
#line 3137 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable.seqtype]" << endl;
#endif
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 214:
#line 3152 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 215:
#line 3159 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast.singletype]" << endl;
#endif
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 216:
#line 3174 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 217:
#line 3181 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary.singletype]" << endl;
#endif
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 218:
#line 3196 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 219:
#line 3203 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [signlist.value]" << endl;
#endif
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 220:
#line 3218 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]" << endl;
#endif
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 221:
#line 3225 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]" << endl;
#endif
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 222:
#line 3232 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 223:
#line 3239 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.-]" << endl;
#endif
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 224:
#line 3254 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 225:
#line 3261 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 226:
#line 3268 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 227:
#line 3282 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq);
		;}
    break;

  case 228:
#line 3289 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne);
		;}
    break;

  case 229:
#line 3296 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt);
		;}
    break;

  case 230:
#line 3303 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_le);
		;}
    break;

  case 231:
#line 3310 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt);
		;}
    break;

  case 232:
#line 3317 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge);
		;}
    break;

  case 233:
#line 3330 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 234:
#line 3337 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 235:
#line 3344 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 236:
#line 3351 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 237:
#line 3358 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 238:
#line 3365 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 239:
#line 3378 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 240:
#line 3385 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 241:
#line 3392 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 242:
#line 3406 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 243:
#line 3413 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [mode.expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 244:
#line 3428 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist]" << endl;
#endif
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 245:
#line 3437 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist.expr]" << endl;
#endif
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 246:
#line 3452 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PragmaList [single]" << endl;
#endif
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 247:
#line 3461 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 248:
#line 3478 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Pragma [ ]" << endl;
#endif
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 249:
#line 3486 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 250:
#line 3529 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 251:
#line 3536 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 252:
#line 3543 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 253:
#line 3550 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [relative]" << endl;
#endif
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = rpe == NULL ? (yysemantic_stack_[(1) - (1)].expr) : new PathExpr(LOC ((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 254:
#line 3564 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step]" << endl;
#endif
            AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = as != NULL ? new RelativePathExpr(LOC ((yyloc)), ParseConstants::st_slash, new ContextItemExpr(LOC ((yyloc))), (yysemantic_stack_[(1) - (1)].expr)) : (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 255:
#line 3572 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(LOC ((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 256:
#line 3579 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(LOC ((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 257:
#line 3592 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 258:
#line 3599 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 259:
#line 3612 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 260:
#line 3621 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward.predlist]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 261:
#line 3630 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 262:
#line 3639 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse.predlist]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 263:
#line 3654 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 264:
#line 3663 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]" << endl;
#endif
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 265:
#line 3677 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 266:
#line 3684 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 267:
#line 3691 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 268:
#line 3698 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 269:
#line 3705 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 270:
#line 3712 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 271:
#line 3719 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 272:
#line 3732 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 273:
#line 3739 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 274:
#line 3752 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [nodetest]" << endl;
#endif
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 275:
#line 3761 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [..]" << endl;
#endif
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 276:
#line 3776 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 277:
#line 3783 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 278:
#line 3790 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 279:
#line 3797 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 280:
#line 3804 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 281:
#line 3822 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 282:
#line 3829 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 283:
#line 3842 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]" << endl;
#endif
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 284:
#line 3849 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]" << endl;
#endif
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 285:
#line 3862 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 286:
#line 3872 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 287:
#line 3882 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 288:
#line 3898 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 289:
#line 3905 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary.predlist]" << endl;
#endif
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 290:
#line 3920 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [single]" << endl;
#endif
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 291:
#line 3929 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 292:
#line 3946 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 293:
#line 3960 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 294:
#line 3967 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 295:
#line 3974 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 296:
#line 3981 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 297:
#line 3988 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 298:
#line 3995 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 4002 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 4009 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 4022 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 4029 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 4042 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.decval);
      delete yylval.decval;
		;}
    break;

  case 304:
#line 4050 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.ival);
      delete yylval.ival;
		;}
    break;

  case 305:
#line 4058 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.dval);
      delete yylval.dval;
		;}
    break;

  case 306:
#line 4072 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]" << endl;
#endif
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 307:
#line 4085 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 308:
#line 4092 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 309:
#line 4106 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]" << endl;
#endif
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 310:
#line 4119 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 311:
#line 4133 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 312:
#line 4192 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [ ]" << endl;
#endif
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 313:
#line 4201 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [arglist]" << endl;
#endif
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 314:
#line 4216 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [single]" << endl;
#endif
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 315:
#line 4225 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [list]" << endl;
#endif
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 316:
#line 4240 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 317:
#line 4247 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 318:
#line 4260 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 319:
#line 4267 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 320:
#line 4274 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 321:
#line 4287 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 322:
#line 4298 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 323:
#line 4309 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 324:
#line 4320 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 325:
#line 4331 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 326:
#line 4342 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 327:
#line 4360 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [single]" << endl;
#endif
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 328:
#line 4369 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [list]" << endl;
#endif
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 329:
#line 4384 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [single]" << endl;
#endif
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 330:
#line 4393 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 331:
#line 4410 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttr [ ]" << endl;
#endif
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 332:
#line 4425 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 333:
#line 4433 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 334:
#line 4447 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]" << endl;
#endif
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 335:
#line 4454 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 336:
#line 4461 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [""]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 337:
#line 4470 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [single]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 338:
#line 4479 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 339:
#line 4490 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 340:
#line 4507 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 341:
#line 4514 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 342:
#line 4521 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 343:
#line 4530 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [single]" << endl;
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 344:
#line 4539 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 345:
#line 4550 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 346:
#line 4567 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 347:
#line 4575 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 348:
#line 4589 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 349:
#line 4597 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 350:
#line 4611 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]" << endl;
#endif
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 351:
#line 4619 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]" << endl;
#endif
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 352:
#line 4627 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cdata]" << endl;
#endif
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 353:
#line 4636 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [common_content]" << endl;
#endif
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 354:
#line 4651 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [char_ref]\n";
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 355:
#line 4660 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 356:
#line 4668 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 357:
#line 4676 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 358:
#line 4690 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]" << endl;
#endif
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 359:
#line 4698 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "DirCommentConstructor [ ]" << endl;
#endif
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 360:
#line 4716 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 361:
#line 4724 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target.charlit]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 362:
#line 4744 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]" << endl;
#endif
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 363:
#line 4762 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 364:
#line 4769 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 365:
#line 4776 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 366:
#line 4783 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 367:
#line 4790 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 368:
#line 4797 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 369:
#line 4810 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 370:
#line 4824 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 371:
#line 4833 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 372:
#line 4842 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 373:
#line 4850 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 374:
#line 4878 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 375:
#line 4887 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 376:
#line 4896 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 377:
#line 4904 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 378:
#line 4918 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 379:
#line 4932 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 380:
#line 4946 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 381:
#line 4955 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 382:
#line 4964 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 383:
#line 4972 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 384:
#line 4986 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic]" << endl;
#endif
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 385:
#line 4995 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic ?]" << endl;
#endif
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 386:
#line 5010 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]" << endl;
#endif
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 387:
#line 5024 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 388:
#line 5033 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type.occurs]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 389:
#line 5042 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 390:
#line 5082 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 391:
#line 5090 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 392:
#line 5098 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 393:
#line 5112 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 394:
#line 5119 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 395:
#line 5126 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]" << endl;
#endif
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 396:
#line 5139 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]" << endl;
#endif
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 397:
#line 5153 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 398:
#line 5160 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 399:
#line 5167 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 400:
#line 5174 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 401:
#line 5181 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 402:
#line 5188 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 403:
#line 5195 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 404:
#line 5202 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 405:
#line 5209 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 406:
#line 5222 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]" << endl;
#endif
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 407:
#line 5235 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 408:
#line 5242 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 409:
#line 5250 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 410:
#line 5264 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]" << endl;
#endif
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 411:
#line 5277 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]" << endl;
#endif
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 412:
#line 5290 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 413:
#line 5297 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 414:
#line 5304 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 415:
#line 5317 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [ ]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 416:
#line 5326 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL);
		;}
    break;

  case 417:
#line 5335 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name.type]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 418:
#line 5344 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 419:
#line 5353 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*.type]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 420:
#line 5368 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 421:
#line 5382 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [ ]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL);
		;}
    break;

  case 422:
#line 5391 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
									NULL);
		;}
    break;

  case 423:
#line 5400 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 424:
#line 5409 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5418 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 426:
#line 5428 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 427:
#line 5438 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5454 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 429:
#line 5478 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]" << endl;
#endif
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 430:
#line 5488 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name?]" << endl;
#endif
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 431:
#line 5511 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]" << endl;
#endif
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 432:
#line 5554 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [strict]" << endl;
#endif
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 433:
#line 5562 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [lax]" << endl;
#endif
    ;}
    break;

  case 434:
#line 5568 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [skip]" << endl;
#endif
    ;}
    break;

  case 435:
#line 5579 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 436:
#line 5588 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.as_first]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 437:
#line 5597 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.as_last]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 438:
#line 5606 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.after]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 439:
#line 5615 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.before]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 440:
#line 5625 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 441:
#line 5634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.as_first]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 442:
#line 5643 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.as_last]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 443:
#line 5652 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.after]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 444:
#line 5661 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.before]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 445:
#line 5676 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodeExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 446:
#line 5684 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodesExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 447:
#line 5697 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 448:
#line 5706 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceValueOfExpr [value.expr]" << endl;
#endif
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 449:
#line 5721 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 450:
#line 5750 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]" << endl;
#endif
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(6) - (2)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(6) - (4)].expr), (yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 451:
#line 5764 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [single]" << endl;
#endif
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 452:
#line 5773 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 453:
#line 5789 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "VarNameDecl [" << driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)) << "]" << endl;
#endif
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 454:
#line 5806 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TryExpr []" << endl;
#endif
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 455:
#line 5816 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchList [single]" << endl;
#endif
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 456:
#line 5826 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 457:
#line 5840 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchExpr [NameTest]" << endl;
#endif
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 458:
#line 5850 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
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

  case 459:
#line 5873 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]" << endl;
#endif
		;}
    break;

  case 460:
#line 5879 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]" << endl;
#endif
		;}
    break;

  case 461:
#line 5885 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]" << endl;
#endif
		;}
    break;

  case 462:
#line 5891 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]" << endl;
#endif
		;}
    break;

  case 463:
#line 5903 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]" << endl;
#endif
		;}
    break;

  case 464:
#line 5909 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]" << endl;
#endif
		;}
    break;

  case 465:
#line 5915 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]" << endl;
#endif
		;}
    break;

  case 466:
#line 5921 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]" << endl;
#endif
		;}
    break;

  case 467:
#line 5933 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]" << endl;
#endif
		;}
    break;

  case 468:
#line 5939 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]" << endl;
#endif
		;}
    break;

  case 469:
#line 5951 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]" << endl;
#endif
		;}
    break;

  case 470:
#line 5957 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]" << endl;
#endif
		;}
    break;

  case 471:
#line 5969 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]" << endl;
#endif
		;}
    break;

  case 472:
#line 5975 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]" << endl;
#endif
		;}
    break;

  case 473:
#line 5987 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]" << endl;
#endif
		;}
    break;

  case 474:
#line 5993 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]" << endl;
#endif
		;}
    break;

  case 475:
#line 6005 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]" << endl;
#endif
		;}
    break;

  case 476:
#line 6011 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]" << endl;
#endif
		;}
    break;

  case 477:
#line 6017 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]" << endl;
#endif
		;}
    break;

  case 478:
#line 6029 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]" << endl;
#endif
		;}
    break;

  case 479:
#line 6035 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]" << endl;
#endif
		;}
    break;

  case 480:
#line 6047 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]" << endl;
#endif
		;}
    break;

  case 481:
#line 6053 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]" << endl;
#endif
		;}
    break;

  case 482:
#line 6065 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]" << endl;
#endif
		;}
    break;

  case 483:
#line 6071 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]" << endl;
#endif
		;}
    break;

  case 484:
#line 6077 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]" << endl;
#endif
		;}
    break;

  case 485:
#line 6083 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]" << endl;
#endif
		;}
    break;

  case 486:
#line 6089 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]" << endl;
#endif
		;}
    break;

  case 487:
#line 6101 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]" << endl;
#endif
		;}
    break;

  case 488:
#line 6113 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 489:
#line 6120 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 490:
#line 6127 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 491:
#line 6134 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 492:
#line 6141 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 493:
#line 6148 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 494:
#line 6155 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 495:
#line 6168 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]" << endl;
#endif
		;}
    break;

  case 496:
#line 6174 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]" << endl;
#endif
		;}
    break;

  case 497:
#line 6180 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]" << endl;
#endif
		;}
    break;

  case 498:
#line 6186 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]" << endl;
#endif
		;}
    break;

  case 499:
#line 6198 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]" << endl;
#endif
		;}
    break;

  case 500:
#line 6204 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]" << endl;
#endif
		;}
    break;

  case 501:
#line 6210 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]" << endl;
#endif
		;}
    break;

  case 502:
#line 6216 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]" << endl;
#endif
		;}
    break;

  case 503:
#line 6228 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]" << endl;
#endif
		;}
    break;

  case 504:
#line 6234 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]" << endl;
#endif
		;}
    break;

  case 505:
#line 6246 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]" << endl;
#endif
		;}
    break;

  case 506:
#line 6252 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]" << endl;
#endif
		;}
    break;

  case 507:
#line 6258 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]" << endl;
#endif
		;}
    break;

  case 508:
#line 6264 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]" << endl;
#endif
		;}
    break;

  case 509:
#line 6270 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]" << endl;
#endif
		;}
    break;

  case 510:
#line 6276 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]" << endl;
#endif
		;}
    break;

  case 511:
#line 6282 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]" << endl;
#endif
		;}
    break;

  case 512:
#line 6294 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]" << endl;
#endif
		;}
    break;

  case 513:
#line 6300 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]" << endl;
#endif
		;}
    break;

  case 514:
#line 6312 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]" << endl;
#endif
		;}
    break;

  case 515:
#line 6318 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]" << endl;
#endif
		;}
    break;

  case 516:
#line 6324 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]" << endl;
#endif
		;}
    break;

  case 517:
#line 6330 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]" << endl;
#endif
		;}
    break;

  case 518:
#line 6342 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]" << endl;
#endif
		;}
    break;

  case 519:
#line 6348 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]" << endl;
#endif
		;}
    break;

  case 520:
#line 6354 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]" << endl;
#endif
		;}
    break;

  case 521:
#line 6360 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]" << endl;
#endif
		;}
    break;

  case 522:
#line 6366 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]" << endl;
#endif
		;}
    break;

  case 523:
#line 6378 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 524:
#line 6384 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 525:
#line 6396 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]" << endl;
#endif
		;}
    break;

  case 526:
#line 6402 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]" << endl;
#endif
		;}
    break;

  case 527:
#line 6414 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 528:
#line 6420 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 529:
#line 6432 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]" << endl;
#endif
		;}
    break;

  case 530:
#line 6438 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]" << endl;
#endif
		;}
    break;

  case 531:
#line 6450 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]" << endl;
#endif
		;}
    break;

  case 532:
#line 6462 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]" << endl;
#endif
		;}
    break;

  case 533:
#line 6468 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]" << endl;
#endif
		;}
    break;

  case 534:
#line 6480 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]" << endl;
#endif
		;}
    break;

  case 535:
#line 6486 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]" << endl;
#endif
		;}
    break;

  case 536:
#line 6492 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]" << endl;
#endif
		;}
    break;

  case 537:
#line 6504 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]" << endl;
#endif
		;}
    break;

  case 538:
#line 6510 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]" << endl;
#endif
		;}
    break;

  case 539:
#line 6516 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]" << endl;
#endif
		;}
    break;

  case 540:
#line 6522 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]" << endl;
#endif
		;}
    break;

  case 541:
#line 6528 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]" << endl;
#endif
		;}
    break;

  case 542:
#line 6540 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 543:
#line 6547 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 544:
#line 6554 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 545:
#line 6561 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 546:
#line 6574 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]" << endl;
#endif
		;}
    break;

  case 547:
#line 6586 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]" << endl;
#endif
		;}
    break;

  case 548:
#line 6598 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]" << endl;
#endif
		;}
    break;

  case 549:
#line 6610 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]" << endl;
#endif
		;}
    break;

  case 550:
#line 6616 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]" << endl;
#endif
		;}
    break;

  case 551:
#line 6628 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]" << endl;
#endif
		;}
    break;

  case 552:
#line 6634 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]" << endl;
#endif
		;}
    break;

  case 553:
#line 6640 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 554:
#line 6652 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]" << endl;
#endif
		;}
    break;

  case 555:
#line 6658 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 556:
#line 6670 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ ]" << endl;
#endif
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 7359 "/home/dagraf/Work/28msec/zorba4/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -669;
  const short int
  xquery_parser::yypact_[] =
  {
       760,  1176,  1384,  -669,  -669,   -28,  -669,    20,  -669,  -669,
    -669,  3048,    27,   368,  -669,  3048,   141,  -669,   317,   315,
     412,   171,   332,   163,   179,    40,   335,   360,   392,   -63,
     398,   404,  -669,  -669,  3048,   377,   444,  -669,  -669,  -669,
    3048,    67,   446,  -669,  -669,   471,  3048,   143,   258,  -669,
     474,  1592,  -669,   498,   369,  3048,  -669,   526,    91,  -669,
     325,  -669,  -669,   270,   529,   553,  -669,  3757,  3595,   446,
    -669,   578,  3048,   440,  3048,  3048,  3048,    11,   590,   415,
    3048,  3048,  3048,  3048,  3048,  3048,  3048,   607,   522,  3699,
     643,   968,  -669,  -669,   257,  3048,   485,   491,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,   610,  -669,
    -669,   417,  -669,  -669,  -669,  -669,  -669,  -669,   518,   628,
    -669,  3760,   421,   330,   382,   150,   479,  -669,   551,   486,
     635,   636,  3256,  -669,  -669,  -669,    -5,  -669,  -669,  -669,
     359,  -669,   562,   368,  -669,   562,   368,  -669,  -669,  -669,
    -669,   562,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,    85,  -669,   124,  1800,  3048,   125,    15,  -669,    24,
    -669,  -669,   129,  -669,  -669,  -669,  -669,  -669,  -669,   632,
     634,  -669,   658,   660,  -669,  -669,   566,   599,   665,  -669,
    -669,   569,   441,   130,  -669,   531,   532,  -669,   135,    80,
    -669,    88,   245,    -4,  -669,    -1,   645,  -669,    99,   661,
     680,   663,   573,   688,   684,   -12,   662,  -669,  -669,   101,
     622,  -669,   137,   105,   552,   554,  -669,   695,  -669,   601,
    3048,   558,   560,  -669,  -669,     8,    47,   142,  -669,   102,
     145,   217,   524,  -669,    -3,  -669,  -669,  -669,  -669,  -669,
       4,    12,   689,   508,   509,   623,    -2,  -669,  3048,  -669,
    -669,  -669,  -669,   703,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,   243,  -669,  -669,    61,   427,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
     257,     2,  3048,  3048,   655,  3048,  3048,  3048,  -669,   200,
     340,   584,  3426,  3426,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  3426,
    3426,  3426,     1,  3426,  3426,  3426,  3426,  3426,  3426,  3426,
    3426,  3426,  3426,  3426,   393,   393,   724,   724,  -669,  -669,
    -669,  2008,  -669,  3595,  3595,  3048,   562,  -669,  -669,   562,
    -669,   562,  -669,  -669,  -669,  -669,   103,   248,   630,   727,
    -669,   727,  -669,  -669,   294,   396,  -669,  -669,    10,   723,
    -669,   208,   393,  -669,  3048,   196,  -669,  -669,  -669,   637,
     729,  -669,   729,  -669,  3048,   642,   675,  3048,   677,  3048,
     678,   -25,   647,    -6,   681,   579,   733,   670,   733,  -669,
     671,   726,  3048,   666,   -46,   686,  -669,   738,  -669,  -669,
    -669,  -669,  -669,  -669,  2216,   259,  -669,  -669,  3048,   679,
    -669,    48,    59,  -669,  -669,   725,  -669,  -669,  -669,   745,
    -669,  -103,  3048,  3048,  3048,   347,  3048,  3048,  3048,  3048,
    3048,  3048,  3048,   694,  3048,   616,  -669,    61,    61,   243,
    -669,   750,   751,   243,   752,  -669,    63,  -669,   612,  -669,
    -669,  -669,   507,   730,  -669,   756,    36,  -669,  -669,   730,
    -669,  3048,   406,   626,  3048,   627,  3048,   628,  -669,  -669,
    -669,  -669,  3048,     1,   401,  -669,   530,   407,   555,   546,
    -669,  -669,   548,   374,   382,   382,   343,   150,   150,   150,
     150,   479,   479,  -669,  -669,  -669,  -669,  -669,  -669,   494,
    -669,  -669,  -669,  -669,   692,  -669,  -669,   260,  -669,  -669,
     117,  -669,  3048,  -669,  -669,  2424,  -669,   641,   644,  -669,
    -669,  -669,  -669,   766,   358,   104,  -669,  -669,   381,   108,
    -669,  -669,  -669,  3048,  2632,   693,   648,   650,   668,   669,
    -669,  3048,   446,  -669,   776,  -669,   779,  3048,   731,  3048,
    3048,   -17,   736,   471,  3048,  -669,   784,   808,   784,  -669,
     733,  -669,  3048,  3048,   740,   474,   682,  -669,   262,   734,
    -669,    30,  -669,  -669,   838,  -669,  -669,  3048,   826,  -669,
    -669,    51,  -669,  -669,  -669,  -669,    64,  -669,   388,    49,
    -669,   683,  3048,  3048,  -669,  -669,  -669,  3048,  3048,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,   607,   691,   638,  -669,
    -669,  -669,  -669,  -669,    94,   243,   352,   110,   111,     2,
    -669,   828,  -669,  -669,  -669,  -669,   399,   804,  -669,  3048,
     807,   655,  -669,  -669,   -31,  -669,  3048,   700,  3048,  -669,
    3048,  -669,   278,   701,  -669,  3426,  -669,  -669,  -669,  -669,
      46,   390,  -669,     1,    46,  3426,  3426,   473,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,     1,     1,   390,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,   280,  -669,  -669,   827,   393,  -669,
    3048,  -669,   786,   389,   393,  -669,  -669,   459,  -669,  -669,
     281,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  3048,  -669,  -669,  3048,   755,  3048,  -669,   780,   843,
     835,   784,  -669,  -669,  3048,  -669,  -669,  -669,  2840,   271,
     342,  -669,  -669,   282,   698,   853,  -669,   854,    95,   850,
     718,   212,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  3048,
      58,   638,  -669,  -669,  -669,  3426,  3426,  3426,  3426,   856,
     639,   849,  -669,   849,  -669,  -669,   804,  -669,  -669,  -669,
     861,  -669,  -669,  -669,  -669,  -669,  3048,  -669,  -669,  -669,
    -669,   150,  -669,  -669,  -669,  -133,   555,  -669,  -669,   -99,
    3426,  -669,  -669,   546,  -669,   624,  -669,  -669,   241,   284,
    -669,   393,  -669,  -669,   466,   393,  -669,  -669,  -669,  -669,
    -669,  3048,  -669,  3048,  -669,   733,  -669,  -669,   285,  -669,
    -669,   855,   300,  -669,  -669,  -669,  -669,   732,   386,  -669,
    -669,  -669,  -669,   715,   717,   872,   860,  3048,   868,  3048,
    -669,   112,  -669,   150,   150,   150,   -40,   390,  -669,   113,
    -669,   119,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,   489,  -669,  -669,   490,  -669,
    -669,   784,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,   721,   393,  -669,   737,  -669,   821,   783,  3426,   657,
     849,  -669,  -669,  -669,  -669,  -669,  -669,  -669,   742,  3048,
     878,  -669,   150,  -669,  -669,  3048,  -669,   747,  -669,   783,
    -669
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     0,     0,   286,   287,   283,   431,     0,   277,   280,
     267,     0,     0,     0,   265,     0,     0,   303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   266,   269,     0,     0,     0,   309,   275,   305,
       0,     0,     0,   271,   270,     0,     0,     0,     0,   304,
       0,     0,   221,     0,     0,     0,   276,     0,     0,   220,
       0,   279,   278,     0,     0,     0,   268,   250,     0,     0,
     285,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     4,     0,     0,     0,     0,    15,    17,
      19,    20,    21,    27,    22,    25,    26,    31,    32,    33,
      28,    29,    35,    36,    23,    30,    24,     9,    94,    95,
      97,     0,   116,   118,   119,    98,    99,   100,   101,   183,
     185,   187,   191,   194,   196,   199,   204,   207,   210,   212,
     214,   216,     0,   218,   224,   226,     0,   246,   225,   253,
     254,   257,   259,     0,   264,   261,     0,   272,   282,   284,
     258,   288,   293,   301,   294,   295,   296,   299,   300,   297,
     298,   316,   318,   319,   320,   317,   363,   364,   365,   366,
     367,   368,   281,   405,   397,   404,   403,   402,   399,   401,
     398,   400,   302,    34,   102,   103,   105,   104,   106,   107,
     374,     0,   370,     0,     0,     0,     0,     0,   415,     0,
     283,   273,     0,   411,    53,    38,    39,    70,    71,     0,
       0,    52,     0,     0,    46,    47,     0,     0,     0,    44,
      45,     0,     0,     0,   407,     0,     0,   306,     0,     0,
     421,     0,     0,     0,   172,     0,   120,   121,     0,    62,
       0,    54,     0,     0,     0,     0,   133,   134,   307,     0,
       0,   406,     0,     0,     0,     0,   412,     0,   249,     0,
       0,     0,     0,   251,   252,     0,     0,     0,   410,     0,
       0,     0,     0,   359,     0,   432,   433,   434,   445,   446,
       0,     0,     0,     0,     0,     0,     0,   451,     0,   498,
     497,   502,   501,     0,   495,   496,   500,   504,   522,   511,
     533,   520,   499,   503,     0,     0,   532,    43,   488,   489,
     490,   491,   492,   493,   494,     1,     3,     5,    10,     8,
      12,    13,     0,     0,     0,     0,     0,     0,   117,     0,
       0,     0,     0,     0,   227,   241,   232,   231,   239,   230,
     229,   228,   240,   233,   238,   237,   236,   235,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   223,   222,
     219,     0,   247,     0,     0,     0,   260,   290,   263,   262,
     274,   289,   375,   371,   312,   314,     0,     0,     0,     0,
     416,     0,   418,   379,     0,     0,    40,    41,     0,     0,
      42,     0,     0,    67,     0,     0,   369,   408,   409,     0,
       0,   422,     0,   425,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
       0,    55,     0,     0,     0,     0,   308,     0,   310,   361,
     360,   413,   414,   248,     0,     0,   420,   428,     0,     0,
     321,     0,     0,   329,   378,     0,   311,   242,   358,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   531,     0,     0,   521,
     523,     0,     0,   518,     0,   506,     0,   505,     0,    16,
      18,    96,   156,   152,   154,     0,   141,   145,   108,   153,
     140,     0,     0,     0,     0,     0,     0,   184,   186,   189,
     188,   190,     0,     0,     0,   480,   192,   459,   467,   469,
     471,   473,   475,   478,   198,   197,   195,   201,   202,   203,
     200,   205,   206,   209,   208,   396,   395,   389,   211,   387,
     393,   394,   213,   215,   384,   217,   244,     0,   255,   256,
       0,   291,     0,   313,   243,     0,   429,     0,     0,    50,
      51,    48,    49,     0,     0,     0,    88,    37,     0,     0,
     386,    66,    69,     0,     0,   429,     0,     0,     0,     0,
     174,     0,     0,   171,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    64,     0,    56,    60,
       0,   136,     0,     0,     0,     0,     0,   380,     0,     0,
     170,     0,   354,   351,     0,   355,   356,     0,     0,   357,
     350,     0,   327,   353,   352,   322,     0,   330,     0,     0,
     178,     0,     0,     0,   438,   439,   435,     0,     0,   443,
     444,   440,   449,   447,   448,   453,     0,     0,     0,   530,
     529,   524,   525,   527,     0,   519,   514,     0,     0,    14,
     165,     0,   166,   167,   168,   157,   158,   159,   160,     0,
     147,     0,   150,   143,   142,   109,     0,     0,     0,   112,
       0,   110,     0,     0,   474,     0,   193,   487,   535,   534,
       0,     0,   536,     0,     0,     0,     0,   460,   464,   482,
     463,   486,   484,   483,   485,     0,     0,     0,   476,   539,
     540,   537,   538,   541,   479,   390,   392,   391,   388,   385,
     245,   292,   315,   376,     0,   417,   419,    90,     0,    72,
       0,    73,     0,     0,     0,    80,    81,     0,    68,   372,
       0,   430,   423,   424,   426,   427,   175,   173,   131,   132,
     125,     0,   127,   124,     0,     0,     0,   122,     0,     0,
      63,    57,   138,   137,     0,   135,    11,   381,     0,   340,
     334,   331,   362,     0,     0,     0,   328,     0,     0,     0,
       0,     0,   179,     7,   436,   437,   441,   442,   452,     0,
       0,   454,   455,   528,   526,     0,     0,     0,     0,     0,
       0,     0,   509,     0,   507,   169,   161,   162,   163,   155,
       0,   148,   146,   151,   144,   113,     0,   111,   114,   481,
     477,   556,   555,   554,   550,     0,   468,   549,   461,     0,
       0,   466,   465,   470,   472,     0,   377,    91,     0,     0,
      89,     0,    74,    75,     0,     0,    82,    83,   373,   129,
     126,     0,   128,     0,    59,     0,   139,   382,     0,   348,
     342,     0,   341,   343,   349,   346,   336,     0,   335,   337,
     347,    92,   323,     0,     0,     0,     0,     0,     0,     0,
     450,     0,   456,   543,   544,   542,     0,   515,   516,     0,
     512,     0,   164,   149,   115,   553,   552,   551,   546,   547,
     462,   548,    76,    77,    93,     0,    84,    85,     0,   130,
     182,    65,   383,   333,   344,   345,   332,   338,   339,   324,
     325,     0,     0,   180,     0,   176,     0,     0,     0,     0,
       0,   510,   508,    78,    79,    86,    87,   326,     0,     0,
       0,   457,   545,   517,   513,     0,   177,     0,   181,     0,
     458
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -669,  -669,  -669,   814,   819,  -669,   817,  -669,   586,   587,
    -315,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -421,  -669,  -669,  -669,  -669,  -669,
     503,   176,  -669,  -548,   824,    25,   -80,  -669,  -669,   799,
    -669,  -669,   318,   492,  -235,  -482,  -669,   314,  -468,   592,
    -669,   252,  -669,  -669,  -298,   598,   263,  -669,  -669,   261,
    -624,  -669,   869,   349,  -669,  -669,   305,  -669,  -669,   597,
     602,   264,  -582,   581,   239,  -358,   250,   272,  -669,  -669,
    -669,  -669,  -669,   805,  -669,  -669,  -669,  -669,  -669,  -669,
     802,  -669,   -45,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
      90,   149,  -669,  -669,   452,    70,  -669,  -343,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -430,  -669,   316,
    -669,   488,  -669,  -669,  -669,  -669,  -669,    75,    82,  -588,
    -351,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,   580,  -227,  -361,  -669,  -669,   277,  -362,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,   920,   924,  -280,   538,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,   306,  -669,  -669,
     162,   450,  -669,  -669,   274,   249,   265,   451,  -669,  -669,
     267,  -669,  -492,  -669,  -669,  -669,  -669,   169,  -308,  -669,
     493,   159,  -669,  -441,  -669,  -669,  -669,  -669,  -668,  -669,
    -669,  -669,  -669,   144,   287,  -669
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   606,   254,   113,   114,   115,   116,
     575,   576,   629,   741,   117,   118,   119,   120,   121,   122,
     123,   246,   247,   431,   432,   124,   256,   257,   339,   340,
     506,   507,   821,   684,   341,   503,   504,   675,   676,   677,
     678,   125,   243,   244,   126,   639,   640,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   359,   360,   361,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   386,   387,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   396,   170,   171,   172,   631,
     462,   463,   781,   877,   878,   871,   872,   879,   873,   632,
     633,   173,   174,   634,   175,   176,   177,   178,   179,   180,
     181,   553,   415,   548,   728,   549,   550,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   567,   587,   192,
     193,   194,   195,   196,   197,   198,   296,   297,   199,   801,
     802,   526,   707,   527,   528,   529,   530,   531,   532,   533,
     708,   709,   317,   318,   319,   320,   321,   899,   900,   322,
     489,   493,   664,   490,   323,   324,   711,   724,   810,   712,
     713,   718,   714,   908,   834,   696
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       288,   289,   290,   291,   292,   293,   294,   497,   537,   538,
     539,   540,   551,   551,   552,   425,   500,   608,   433,   525,
     443,   412,   273,   274,   682,     6,   201,   203,   444,   428,
     746,   630,   412,   835,   428,   710,   206,   471,   683,   282,
     212,   513,   515,   786,   426,   475,   483,   207,   661,   845,
     551,   580,   817,   818,    17,   613,   426,   622,   623,   233,
     622,   623,   779,   399,    26,   238,    28,   459,    30,    31,
       3,   248,   401,   622,   623,   229,   259,     4,   210,   459,
     262,    39,   370,   597,   681,   469,   573,   239,    50,   442,
     638,   764,   624,   204,   371,   624,   491,   277,   494,   279,
     280,   281,   600,   211,   622,   623,   264,   429,   624,   642,
     381,   643,    49,   449,   905,   265,   522,   791,   803,   230,
     906,   568,   523,   838,   395,   224,   225,   625,   420,   626,
     625,   667,   626,   332,   460,   205,   422,   907,   938,   624,
     586,   370,   588,   625,    60,   626,   635,   332,   905,   332,
     332,   562,   742,   371,   906,    50,   742,   427,   811,   813,
     936,   940,   470,   627,   337,   332,   627,   940,   249,   458,
     574,   907,   332,   332,   625,   400,   626,   332,   332,   627,
     525,   525,   492,   332,   402,   332,   780,   208,   668,   771,
     332,    57,   902,   332,    57,   853,   598,   209,   602,   857,
     786,   630,   823,   472,   473,   430,   630,    57,   283,   614,
     627,   476,   477,   484,   687,   842,   824,   474,   485,   628,
      71,   461,   785,    71,   661,   478,   430,   240,    70,   939,
     397,   337,    89,   636,   430,   787,    71,   241,    57,   430,
     421,   524,   392,   388,    77,   430,   390,    77,   423,   450,
     430,   266,   501,   502,   804,   508,   502,   510,   910,   435,
      77,   446,   465,   563,   743,   332,   885,    71,   747,   250,
     812,   814,   937,   941,   869,   731,   551,   790,   412,   942,
     622,   393,   398,   251,   573,   269,   403,   416,   888,   222,
     582,    77,   419,   832,   448,   455,   332,   583,   833,   464,
     913,   213,   466,   869,   219,   223,   917,   332,   332,   622,
     332,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   220,   332,   252,   332,   332,
     332,   370,   332,   332,   581,   912,   487,   831,   558,   559,
     333,   334,   214,   371,   590,   267,   268,   593,   839,   595,
     625,   622,   626,   424,   500,   226,   740,   221,   630,   511,
     525,   870,   611,    47,    48,   875,   765,   944,   578,   336,
     946,   889,   525,   525,   467,   227,   551,   848,   620,   625,
       3,   626,   551,   854,   253,   270,   627,     4,   210,   951,
     924,   738,   644,   645,   646,   622,   649,   650,   651,   652,
     653,   654,   655,   569,   657,   564,   557,    12,   545,   875,
     560,   960,   228,   545,   744,   627,   619,   730,   231,   777,
      16,   625,   851,   626,   488,     6,   570,    12,   874,   880,
     232,   685,    12,   876,   689,   829,   691,   846,   858,   881,
      16,   914,   922,    35,   921,    16,   671,   893,   894,   895,
     896,    41,   739,   363,    17,   366,   561,   627,    79,   561,
      41,   561,   494,    35,   789,   625,   363,   626,    35,   215,
     237,    41,   242,   740,   412,   745,    41,   927,   364,   618,
     333,    39,   732,   852,   673,   674,   367,    89,   216,   551,
     915,   364,   855,   551,   918,   495,   740,   245,    54,   514,
     255,   627,   546,   748,   740,   571,   368,   546,   365,   336,
     847,   756,    49,   260,    58,    45,   522,   760,    54,   762,
     763,   874,   523,    54,   768,   383,   384,   880,   572,   261,
      64,    65,   772,   773,    58,   413,    50,   234,    70,    58,
      65,   670,   414,   263,    73,   697,   333,   692,   496,   271,
      64,    65,   369,   856,   671,    64,    65,   333,   334,   647,
     916,   648,   794,   795,    73,   686,   217,   796,   797,    73,
     551,   948,   372,   272,   740,   336,   335,   805,   806,   672,
     952,   740,   547,   943,   945,   218,   336,   547,   807,   808,
     734,   373,   673,   674,   719,   720,   721,   722,   276,   502,
     278,   809,   534,   535,   740,   740,   825,   389,   827,   750,
     828,   697,   337,   391,   284,   805,   806,   285,   286,   287,
     541,   542,   723,   519,   520,   521,   807,   808,   725,   726,
     727,   698,   954,   295,   699,   299,   300,   298,   301,   302,
     700,   701,   702,   325,   543,   544,   659,   660,   703,   303,
     330,   304,   783,   554,   554,   342,   331,   704,   332,   343,
     362,   374,   305,   705,   706,   375,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   376,   385,   377,
     404,   859,   405,   406,   860,   407,   862,   408,   409,   410,
     411,   417,   418,   434,   866,   437,   436,   698,   438,   439,
     699,   299,   300,   440,   301,   302,   700,   701,   702,   441,
     445,   447,   451,   453,   452,   303,   454,   304,   456,   890,
     457,   468,   479,   704,   482,   480,   481,   486,   305,   840,
     706,   505,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   516,   545,   565,   904,   566,   577,   585,
     591,   592,   584,   594,   596,   599,   604,   603,   605,   607,
     609,   610,   615,   616,     1,   849,   638,   612,   621,   641,
     656,     2,     3,   658,   662,   663,   666,   669,   679,     4,
       5,   919,   680,   920,     6,   688,   690,     7,   695,     8,
       9,   716,   737,   715,   717,   729,   751,    10,    11,    12,
      13,   735,   758,   868,   736,   759,    14,   933,   752,   935,
     753,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,   754,   755,
      32,    33,   769,   770,    34,    35,    36,    37,    38,   761,
      39,   774,    40,    41,   766,   782,   784,   776,   793,   778,
     799,   671,    42,   815,   820,    43,    44,   800,    45,   826,
     412,   830,   573,   861,   863,    46,    47,    48,   864,   956,
     865,    49,   882,   883,   884,   958,   886,   887,   911,    50,
     897,    51,   898,    52,   494,    53,   903,   923,   926,   929,
      54,   930,   931,   932,   934,   947,   949,   950,   740,    55,
     953,   955,    56,    57,   957,   326,    58,   959,    59,    60,
     327,   328,    61,    62,   579,    63,   498,   499,   850,   329,
     338,   767,    64,    65,    66,   601,    67,    68,    69,   775,
      70,   512,    71,   822,   509,    72,    73,   816,   275,   517,
      74,   757,   819,    75,   792,   518,   536,   380,   382,   891,
     637,    76,   788,   928,   925,   235,    77,   555,    78,   236,
     589,    79,   798,   892,   843,    80,    81,    82,    83,    84,
      85,    86,     1,   693,   841,   694,    87,   836,    88,     2,
       3,   844,   901,   909,     0,     0,   665,     4,     5,     0,
      89,   837,     6,     0,     0,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,     0,    32,    33,
       0,     0,    34,    35,    36,    37,    38,     0,    39,     0,
      40,    41,     0,     0,     0,     0,     0,     0,     0,     0,
      42,     0,     0,    43,    44,     0,    45,     0,     0,     0,
       0,     0,     0,    46,    47,    48,     0,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,    50,     0,    51,
       0,    52,     0,    53,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
      56,    57,     0,     0,    58,     0,    59,    60,     0,     0,
      61,    62,     0,    63,     0,     0,     0,     0,     0,     0,
      64,    65,    66,     0,    67,    68,    69,     0,    70,     0,
      71,     0,     0,    72,    73,     0,     0,     0,    74,     0,
       0,    75,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,     0,     0,    77,     0,     0,     0,     0,    79,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
       1,     0,     0,     0,    87,     0,    88,     2,     3,     0,
       0,     0,     0,     0,     0,     4,     5,     0,    89,     0,
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
       0,     0,     0,     0,     0,    55,     0,     0,    56,    57,
       0,     0,    58,     0,    59,    60,     0,     0,    61,    62,
       0,    63,     0,   200,     0,     0,     0,     0,    64,    65,
      66,     0,    67,    68,    69,     0,    70,     0,    71,     0,
       0,    72,    73,     0,     0,     0,    74,     0,     0,    75,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,     1,     0,
       0,     0,    87,     0,    88,     2,     3,     0,     0,     0,
       0,     0,     0,     4,     5,     0,     0,     0,     6,     0,
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
       0,     0,     0,    55,     0,     0,    56,    57,     0,     0,
      58,     0,    59,    60,     0,     0,    61,    62,     0,    63,
       0,   202,     0,     0,     0,     0,    64,    65,    66,     0,
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
       0,    55,     0,     0,    56,    57,     0,     0,    58,     0,
      59,    60,     0,     0,    61,    62,     0,    63,     0,     0,
       0,     0,   258,     0,    64,    65,    66,     0,    67,    68,
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
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
     394,     0,    64,    65,    66,     0,    67,    68,    69,     0,
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
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
      56,    57,     0,     0,    58,     0,    59,    60,     0,     0,
      61,    62,     0,    63,     0,   556,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,    55,     0,     0,    56,    57,
       0,     0,    58,     0,    59,    60,     0,     0,    61,    62,
       0,    63,     0,   617,     0,     0,     0,     0,    64,    65,
      66,     0,    67,    68,    69,     0,    70,     0,    71,     0,
       0,    72,    73,     0,     0,     0,    74,     0,     0,    75,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,     1,     0,
       0,     0,    87,     0,    88,     2,     3,     0,     0,     0,
       0,     0,     0,     4,     5,     0,     0,     0,     6,     0,
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
       0,     0,     0,    55,     0,     0,    56,    57,     0,     0,
      58,     0,    59,    60,     0,     0,    61,    62,     0,    63,
       0,   733,     0,     0,     0,     0,    64,    65,    66,     0,
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
       0,    55,     0,     0,    56,    57,     0,     0,    58,     0,
      59,    60,     0,     0,    61,    62,     0,    63,     0,   749,
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
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   867,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,    69,     0,
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
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
      56,    57,     0,     0,    58,     0,    59,    60,     0,     0,
      61,    62,     0,    63,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,   378,
       0,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,    56,    57,
       0,     0,    58,     0,   379,    60,     0,     0,    61,    62,
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
       0,     0,     0,     0,     0,    55,     0,     0,    56,    57,
       0,     0,    58,     0,    59,    60,     0,     0,    61,    62,
       0,    63,     0,     0,     0,     0,     0,     0,    64,    65,
      66,     0,    67,    68,     0,     0,    70,     0,    71,     1,
       0,    72,    73,     0,     0,     0,     2,     3,     0,    75,
       0,     0,     0,     0,     4,     5,     0,    76,     0,     6,
       0,     0,    77,     0,     8,     9,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,     0,     0,    34,
      35,    36,    37,    38,     0,    39,     0,    40,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,    56,    57,     0,
       0,    58,     0,     0,     0,     0,     0,    61,    62,     0,
      63,     0,     0,     0,     0,     0,     0,    64,    65,    66,
       0,     1,     0,     0,     0,    70,     0,    71,     2,     3,
      72,    73,     0,     0,     0,     0,     4,     5,    75,     0,
       0,     6,     0,     0,     0,     0,     8,     9,     0,     0,
       0,    77,     0,     0,    10,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       0,    34,    35,    36,    37,    38,     0,    39,     0,    40,
      41,     0,     0,     0,     0,     0,     0,     0,     0,   344,
       0,     0,    43,    44,     0,     0,     0,   345,     0,     0,
     346,     0,   347,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,   348,     0,     0,     0,   349,    51,     0,
       0,     0,   350,     0,     0,     0,     0,    54,   351,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,    56,
      57,     0,     0,    58,     0,     0,     0,     0,     0,    61,
      62,   352,    63,     0,     0,     0,     0,     0,     0,    64,
      65,    66,     0,     0,     0,     0,     0,   299,   300,    71,
     301,   302,    72,    73,     0,     0,     0,     0,     0,     0,
      75,   303,     0,   304,     0,   353,   354,   355,   356,   357,
     358,     0,     0,    77,   305,     0,     0,     0,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        80,    81,    82,    83,    84,    85,    86,   315,   366,   367,
     368,   369,   374,   375,   375,   242,   331,   438,   245,   362,
     255,    33,    67,    68,   506,    24,     1,     2,   255,    35,
     578,   461,    33,   701,    35,   527,    11,    33,   506,    28,
      15,   339,   340,   631,    48,    33,    48,    20,   489,   717,
     412,   412,   676,   677,    53,   101,    48,     9,    10,    34,
       9,    10,    32,    48,    62,    40,    64,    20,    66,    67,
      12,    46,    48,     9,    10,   138,    51,    19,    20,    20,
      55,    80,   181,   108,    48,    88,    76,    20,   119,   101,
      41,   108,    44,   121,   193,    44,    35,    72,    35,    74,
      75,    76,   108,    13,     9,    10,    15,   108,    44,   212,
     115,   214,   111,     8,   247,    24,   115,    68,    24,   182,
     253,   401,   121,   705,   204,    85,    86,    79,    48,    81,
      79,    68,    81,    48,    87,   115,    48,   270,   178,    44,
     420,   181,   422,    79,   149,    81,    87,    48,   247,    48,
      48,    48,    48,   193,   253,   119,    48,   161,    48,    48,
      48,    48,   165,   115,   195,    48,   115,    48,    25,   161,
     160,   270,    48,    48,    79,   160,    81,    48,    48,   115,
     523,   524,   121,    48,   160,    48,   156,   160,   496,   610,
      48,   143,   816,    48,   143,   743,   431,   170,   433,   747,
     788,   631,   684,   199,   200,   251,   636,   143,   197,   444,
     115,   199,   200,   215,   512,   707,   684,   213,   298,   171,
     172,   174,   171,   172,   665,   213,   251,   160,   170,   897,
     205,   195,   230,   174,   251,   171,   172,   170,   143,   251,
     160,   240,   157,   153,   196,   251,   156,   196,   160,   144,
     251,   160,   332,   333,   160,   335,   336,   337,   840,   160,
     196,   160,   160,   160,   160,    48,   171,   172,   160,   126,
     160,   160,   160,   160,     3,   158,   638,   638,    33,   160,
       9,   157,   157,    25,    76,    15,   157,   157,    76,   126,
      94,   196,   157,   247,   157,   270,    48,   101,   252,   157,
     848,   160,   157,     3,   133,   126,   854,    48,    48,     9,
      48,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,   154,    48,    69,    48,    48,
      48,   181,    48,    48,   414,    94,    93,   695,   383,   384,
     140,   141,    25,   193,   424,    20,    21,   427,   706,   429,
      79,     9,    81,   108,   669,    20,   115,    25,   788,   159,
     703,    90,   442,   106,   107,    23,   601,   915,   160,   169,
     918,   159,   715,   716,   157,    15,   738,   738,   458,    79,
      12,    81,   744,   744,   126,   115,   115,    19,    20,   937,
      90,    33,   472,   473,   474,     9,   476,   477,   478,   479,
     480,   481,   482,   109,   484,   157,   381,    39,    20,    23,
     385,   959,    20,    20,    33,   115,   157,   157,    20,   157,
      52,    79,    33,    81,   181,    24,   132,    39,   779,   780,
      26,   511,    39,    91,   514,   157,   516,   157,   157,   157,
      52,   157,   157,    75,   865,    52,    47,   805,   806,   807,
     808,    83,    94,   123,    53,    73,   386,   115,   201,   389,
      83,   391,    35,    75,    76,    79,   123,    81,    75,   154,
      26,    83,    26,   115,    33,    94,    83,    91,   148,   454,
     140,    80,   562,    94,    85,    86,   104,   230,   173,   851,
     851,   148,    33,   855,   855,    68,   115,    26,   130,   159,
      26,   115,   114,   583,   115,   109,   124,   114,   178,   169,
     737,   591,   111,    15,   146,    98,   115,   597,   130,   599,
     600,   872,   121,   130,   604,   166,   167,   878,   132,   160,
     162,   163,   612,   613,   146,    94,   119,   160,   170,   146,
     163,    34,   101,    17,   176,   138,   140,   522,   121,    20,
     162,   163,   170,    94,    47,   162,   163,   140,   141,   212,
      94,   214,   642,   643,   176,   159,   154,   647,   648,   176,
     932,   932,    93,    20,   115,   169,   159,   225,   226,    72,
     938,   115,   194,    94,    94,   173,   169,   194,   236,   237,
     565,   112,    85,    86,   220,   221,   222,   223,    20,   679,
     160,   249,   363,   364,   115,   115,   686,   155,   688,   584,
     690,   138,   195,   161,    24,   225,   226,   202,   203,   204,
     370,   371,   248,   359,   360,   361,   236,   237,   134,   135,
     136,   224,   940,    26,   227,   228,   229,   115,   231,   232,
     233,   234,   235,     0,   372,   373,   487,   488,   241,   242,
     165,   244,   627,   376,   377,   137,   165,   250,    48,    31,
     239,   110,   255,   256,   257,   179,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    42,   116,    43,
      48,   761,    48,    25,   764,    25,   766,   121,    89,    24,
     121,   160,   160,    48,   774,    15,    35,   224,    35,   126,
     227,   228,   229,    15,   231,   232,   233,   234,   235,    25,
      48,    89,   160,    18,   160,   242,   115,   244,   160,   799,
     160,   197,    33,   250,   101,   217,   217,    24,   255,   256,
     257,    76,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   159,    20,   115,   826,    20,    25,    20,
     108,    76,   115,    76,    76,   108,   177,    76,    25,    89,
      89,    35,    76,    25,     4,   740,    41,   101,    89,    24,
      76,    11,    12,   157,    24,    24,    24,   165,    48,    19,
      20,   861,    26,   863,    24,   159,   159,    27,   258,    29,
      30,   245,    26,   238,   246,   103,   103,    37,    38,    39,
      40,   160,    26,   778,   160,    26,    46,   887,   160,   889,
     160,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   160,   160,
      70,    71,    48,    25,    74,    75,    76,    77,    78,   108,
      80,   101,    82,    83,   108,     7,    20,   165,   165,   115,
     159,    47,    92,    25,    47,    95,    96,   219,    98,   159,
      33,   160,    76,   108,    84,   105,   106,   107,    25,   949,
      35,   111,   174,    20,    20,   955,    26,   159,   254,   119,
      24,   121,   243,   123,    35,   125,    25,    32,   156,   174,
     130,   174,    20,    33,    26,   174,   159,    76,   115,   139,
     243,   159,   142,   143,    26,    91,   146,   160,   148,   149,
      91,    94,   152,   153,   411,   155,   330,   330,   742,    95,
     121,   603,   162,   163,   164,   433,   166,   167,   168,   615,
     170,   339,   172,   681,   336,   175,   176,   676,    69,   342,
     180,   592,   679,   183,   639,   343,   365,   142,   146,   800,
     462,   191,   636,   878,   872,    35,   196,   377,   198,    35,
     422,   201,   656,   801,   715,   205,   206,   207,   208,   209,
     210,   211,     4,   523,   707,   524,   216,   703,   218,    11,
      12,   716,   813,   839,    -1,    -1,   493,    19,    20,    -1,
     230,   704,    24,    -1,    -1,    27,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    70,    71,
      -1,    -1,    74,    75,    76,    77,    78,    -1,    80,    -1,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    95,    96,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
      -1,   123,    -1,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     142,   143,    -1,    -1,   146,    -1,   148,   149,    -1,    -1,
     152,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,    -1,   166,   167,   168,    -1,   170,    -1,
     172,    -1,    -1,   175,   176,    -1,    -1,    -1,   180,    -1,
      -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,   205,   206,   207,   208,   209,   210,   211,
       4,    -1,    -1,    -1,   216,    -1,   218,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    -1,   230,    -1,
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
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,   143,
      -1,    -1,   146,    -1,   148,   149,    -1,    -1,   152,   153,
      -1,   155,    -1,   157,    -1,    -1,    -1,    -1,   162,   163,
     164,    -1,   166,   167,   168,    -1,   170,    -1,   172,    -1,
      -1,   175,   176,    -1,    -1,    -1,   180,    -1,    -1,   183,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   206,   207,   208,   209,   210,   211,     4,    -1,
      -1,    -1,   216,    -1,   218,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    24,    -1,
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
      -1,    -1,    -1,   139,    -1,    -1,   142,   143,    -1,    -1,
     146,    -1,   148,   149,    -1,    -1,   152,   153,    -1,   155,
      -1,   157,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,
     166,   167,   168,    -1,   170,    -1,   172,    -1,    -1,   175,
     176,    -1,    -1,    -1,   180,    -1,    -1,   183,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     206,   207,   208,   209,   210,   211,     4,    -1,    -1,    -1,
     216,    -1,   218,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
      -1,   139,    -1,    -1,   142,   143,    -1,    -1,   146,    -1,
     148,   149,    -1,    -1,   152,   153,    -1,   155,    -1,    -1,
      -1,    -1,   160,    -1,   162,   163,   164,    -1,   166,   167,
     168,    -1,   170,    -1,   172,    -1,    -1,   175,   176,    -1,
      -1,    -1,   180,    -1,    -1,   183,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,   207,
     208,   209,   210,   211,     4,    -1,    -1,    -1,   216,    -1,
     218,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
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
     210,   211,     4,    -1,    -1,    -1,   216,    -1,   218,    11,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     142,   143,    -1,    -1,   146,    -1,   148,   149,    -1,    -1,
     152,   153,    -1,   155,    -1,   157,    -1,    -1,    -1,    -1,
     162,   163,   164,    -1,   166,   167,   168,    -1,   170,    -1,
     172,    -1,    -1,   175,   176,    -1,    -1,    -1,   180,    -1,
      -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   206,   207,   208,   209,   210,   211,
       4,    -1,    -1,    -1,   216,    -1,   218,    11,    12,    -1,
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
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,   143,
      -1,    -1,   146,    -1,   148,   149,    -1,    -1,   152,   153,
      -1,   155,    -1,   157,    -1,    -1,    -1,    -1,   162,   163,
     164,    -1,   166,   167,   168,    -1,   170,    -1,   172,    -1,
      -1,   175,   176,    -1,    -1,    -1,   180,    -1,    -1,   183,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   206,   207,   208,   209,   210,   211,     4,    -1,
      -1,    -1,   216,    -1,   218,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    24,    -1,
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
      -1,    -1,    -1,   139,    -1,    -1,   142,   143,    -1,    -1,
     146,    -1,   148,   149,    -1,    -1,   152,   153,    -1,   155,
      -1,   157,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,
     166,   167,   168,    -1,   170,    -1,   172,    -1,    -1,   175,
     176,    -1,    -1,    -1,   180,    -1,    -1,   183,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     206,   207,   208,   209,   210,   211,     4,    -1,    -1,    -1,
     216,    -1,   218,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
      -1,   139,    -1,    -1,   142,   143,    -1,    -1,   146,    -1,
     148,   149,    -1,    -1,   152,   153,    -1,   155,    -1,   157,
      -1,    -1,    -1,    -1,   162,   163,   164,    -1,   166,   167,
     168,    -1,   170,    -1,   172,    -1,    -1,   175,   176,    -1,
      -1,    -1,   180,    -1,    -1,   183,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,   207,
     208,   209,   210,   211,     4,    -1,    -1,    -1,   216,    -1,
     218,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
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
     210,   211,     4,    -1,    -1,    -1,   216,    -1,   218,    11,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     142,   143,    -1,    -1,   146,    -1,   148,   149,    -1,    -1,
     152,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,    -1,   166,   167,   168,    -1,   170,    -1,
     172,    -1,    -1,   175,   176,    -1,    -1,    -1,   180,    -1,
      -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   206,   207,   208,   209,   210,   211,
       4,    -1,    -1,    -1,   216,    -1,   218,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,
      24,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,   143,
      -1,    -1,   146,    -1,   148,   149,    -1,    -1,   152,   153,
      -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
     164,    -1,   166,   167,    -1,    -1,   170,    -1,   172,    -1,
       4,   175,   176,    -1,    -1,    -1,    -1,    11,    12,   183,
      -1,    -1,    -1,    -1,    -1,    19,    20,   191,    -1,    -1,
      24,    -1,   196,    27,    -1,    29,    30,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,   143,
      -1,    -1,   146,    -1,   148,   149,    -1,    -1,   152,   153,
      -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
     164,    -1,   166,   167,    -1,    -1,   170,    -1,   172,     4,
      -1,   175,   176,    -1,    -1,    -1,    11,    12,    -1,   183,
      -1,    -1,    -1,    -1,    19,    20,    -1,   191,    -1,    24,
      -1,    -1,   196,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    74,
      75,    76,    77,    78,    -1,    80,    -1,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    -1,    -1,   142,   143,    -1,
      -1,   146,    -1,    -1,    -1,    -1,    -1,   152,   153,    -1,
     155,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
      -1,     4,    -1,    -1,    -1,   170,    -1,   172,    11,    12,
     175,   176,    -1,    -1,    -1,    -1,    19,    20,   183,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,   196,    -1,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,
      -1,    74,    75,    76,    77,    78,    -1,    80,    -1,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    95,    96,    -1,    -1,    -1,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,   117,   121,    -1,
      -1,    -1,   122,    -1,    -1,    -1,    -1,   130,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,
     143,    -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,   152,
     153,   151,   155,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,   228,   229,   172,
     231,   232,   175,   176,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   242,    -1,   244,    -1,   185,   186,   187,   188,   189,
     190,    -1,    -1,   196,   255,    -1,    -1,    -1,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269
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
     205,   206,   207,   208,   209,   210,   211,   216,   218,   230,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   308,   309,   310,   311,   316,   317,   318,
     319,   320,   321,   322,   327,   343,   346,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     398,   399,   400,   413,   414,   416,   417,   418,   419,   420,
     421,   422,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   441,   442,   443,   444,   445,   446,   447,   450,
     157,   317,   157,   317,   121,   115,   317,    20,   160,   170,
      20,   382,   317,   160,    25,   154,   173,   154,   173,   133,
     154,    25,   126,   126,    85,    86,    20,    15,    20,   138,
     182,    20,    26,   317,   160,   437,   438,    26,   317,    20,
     160,   170,    26,   344,   345,    26,   323,   324,   317,    25,
     126,    25,    69,   126,   307,    26,   328,   329,   160,   317,
      15,   160,   317,    17,    15,    24,   160,    20,    21,    15,
     115,    20,    20,   374,   374,   344,    20,   317,   160,   317,
     317,   317,    28,   197,    24,   202,   203,   204,   318,   318,
     318,   318,   318,   318,   318,    26,   448,   449,   115,   228,
     229,   231,   232,   242,   244,   255,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   464,   465,   466,
     467,   468,   471,   476,   477,     0,   285,   286,   288,   316,
     165,   165,    48,   140,   141,   159,   169,   195,   321,   330,
     331,   336,   137,    31,    89,    97,   100,   102,   113,   117,
     122,   128,   151,   185,   186,   187,   188,   189,   190,   366,
     367,   368,   239,   123,   148,   178,    73,   104,   124,   170,
     181,   193,    93,   112,   110,   179,    42,    43,   123,   148,
     365,   115,   372,   166,   167,   116,   386,   387,   382,   386,
     382,   386,   157,   157,   160,   318,   397,   317,   157,    48,
     160,    48,   160,   157,    48,    48,    25,    25,   121,    89,
      24,   121,    33,    94,   101,   424,   157,   160,   160,   157,
      48,   160,    48,   160,   108,   424,    48,   161,    35,   108,
     251,   325,   326,   424,    48,   160,    35,    15,    35,   126,
      15,    25,   101,   326,   424,    48,   160,    89,   157,     8,
     144,   160,   160,    18,   115,   317,   160,   160,   161,    20,
      87,   174,   402,   403,   157,   160,   157,   157,   197,    88,
     165,    33,   199,   200,   213,    33,   199,   200,   213,    33,
     217,   217,   101,    48,   215,   318,    24,    93,   181,   472,
     475,    35,   121,   473,    35,    68,   121,   470,   290,   291,
     292,   318,   318,   337,   338,    76,   332,   333,   318,   337,
     318,   159,   331,   336,   159,   336,   159,   351,   352,   353,
     353,   353,   115,   121,   240,   389,   453,   455,   456,   457,
     458,   459,   460,   461,   356,   356,   355,   357,   357,   357,
     357,   358,   358,   359,   359,    20,   114,   194,   425,   427,
     428,   429,   425,   423,   428,   423,   157,   317,   374,   374,
     317,   387,    48,   160,   157,   115,    20,   439,   439,   109,
     132,   109,   132,    76,   160,   312,   313,    25,   160,   312,
     425,   318,    94,   101,   115,    20,   439,   440,   439,   440,
     318,   108,    76,   318,    76,   318,    76,   108,   326,   108,
     108,   325,   326,    76,   177,    25,   306,    89,   306,    89,
      35,   318,   101,   101,   326,    76,    25,   157,   317,   157,
     318,    89,     9,    10,    44,    79,    81,   115,   171,   314,
     399,   401,   411,   412,   415,    87,   174,   403,    41,   347,
     348,    24,   212,   214,   318,   318,   318,   212,   214,   318,
     318,   318,   318,   318,   318,   318,    76,   318,   157,   473,
     473,   475,    24,    24,   474,   472,    24,    68,   470,   165,
      34,    47,    72,    85,    86,   339,   340,   341,   342,    48,
      26,    48,   327,   330,   335,   318,   159,   336,   159,   318,
     159,   318,   317,   453,   459,   258,   487,   138,   224,   227,
     233,   234,   235,   241,   250,   256,   257,   454,   462,   463,
     464,   478,   481,   482,   484,   238,   245,   246,   483,   220,
     221,   222,   223,   248,   479,   134,   135,   136,   426,   103,
     157,   158,   318,   157,   317,   160,   160,    26,    33,    94,
     115,   315,    48,   160,    33,    94,   315,   160,   318,   157,
     317,   103,   160,   160,   160,   160,   318,   345,    26,    26,
     318,   108,   318,   318,   108,   326,   108,   324,   318,    48,
      25,   306,   318,   318,   101,   329,   165,   157,   115,    32,
     156,   404,     7,   317,    20,   171,   411,   171,   401,    76,
     425,    68,   348,   165,   318,   318,   318,   318,   449,   159,
     219,   451,   452,    24,   160,   225,   226,   236,   237,   249,
     480,    48,   160,    48,   160,    25,   341,   342,   342,   338,
      47,   334,   333,   327,   330,   318,   159,   318,   318,   157,
     160,   357,   247,   252,   486,   480,   456,   486,   354,   357,
     256,   462,   464,   457,   458,   480,   157,   424,   425,   317,
     313,    33,    94,   315,   425,    33,    94,   315,   157,   318,
     318,   108,   318,    84,    25,    35,   318,   157,   317,     3,
      90,   407,   408,   410,   412,    23,    91,   405,   406,   409,
     412,   157,   174,    20,    20,   171,    26,   159,    76,   159,
     318,   383,   452,   357,   357,   357,   357,    24,   243,   469,
     470,   469,   342,    25,   318,   247,   253,   270,   485,   485,
     354,   254,    94,   315,   157,   425,    94,   315,   425,   318,
     318,   306,   157,    32,    90,   410,   156,    91,   409,   174,
     174,    20,    33,   318,    26,   318,    48,   160,   178,   480,
      48,   160,   160,    94,   315,    94,   315,   174,   425,   159,
      76,   315,   357,   243,   470,   159,   318,    26,   318,   160,
     315
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
     535,   536
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   282,   283,   283,   283,   283,   284,   284,   285,   285,
     286,   287,   288,   288,   288,   289,   289,   290,   290,   291,
     291,   291,   291,   292,   292,   292,   292,   293,   293,   293,
     293,   293,   293,   293,   293,   294,   294,   295,   296,   296,
     297,   297,   298,   299,   300,   300,   301,   301,   302,   302,
     302,   302,   303,   304,   305,   305,   305,   305,   306,   306,
     307,   307,   308,   308,   308,   308,   309,   309,   309,   309,
     310,   310,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   312,   312,
     313,   313,   314,   315,   316,   317,   317,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   319,   319,
     319,   319,   319,   319,   319,   319,   320,   320,   321,   321,
     322,   323,   323,   324,   324,   324,   324,   324,   324,   324,
     324,   325,   326,   327,   328,   328,   329,   329,   329,   329,
     330,   331,   331,   331,   331,   332,   332,   333,   333,   334,
     335,   335,   336,   336,   337,   337,   338,   338,   339,   339,
     339,   339,   339,   339,   339,   340,   340,   341,   341,   342,
     343,   343,   344,   344,   345,   345,   346,   346,   347,   347,
     348,   348,   349,   350,   350,   351,   351,   352,   352,   352,
     352,   353,   353,   353,   354,   354,   355,   355,   355,   356,
     356,   356,   356,   356,   357,   357,   357,   358,   358,   358,
     359,   359,   360,   360,   361,   361,   362,   362,   363,   363,
     364,   364,   364,   364,   365,   365,   365,   366,   366,   366,
     366,   366,   366,   367,   367,   367,   367,   367,   367,   368,
     368,   368,   369,   369,   370,   370,   371,   371,   372,   372,
     373,   373,   373,   373,   374,   374,   374,   375,   375,   376,
     376,   376,   376,   377,   377,   378,   378,   378,   378,   378,
     378,   378,   379,   379,   380,   380,   381,   381,   381,   381,
     381,   382,   382,   383,   383,   384,   384,   384,   385,   385,
     386,   386,   387,   388,   388,   388,   388,   388,   388,   388,
     388,   389,   389,   390,   390,   390,   391,   392,   392,   393,
     394,   395,   396,   396,   397,   397,   398,   398,   399,   399,
     399,   400,   400,   400,   400,   400,   400,   401,   401,   402,
     402,   403,   404,   404,   405,   405,   406,   406,   406,   406,
     407,   407,   408,   408,   408,   408,   409,   409,   410,   410,
     411,   411,   411,   411,   412,   412,   412,   412,   413,   413,
     414,   414,   415,   416,   416,   416,   416,   416,   416,   417,
     418,   418,   418,   418,   419,   419,   419,   419,   420,   421,
     422,   422,   422,   422,   423,   423,   424,   425,   425,   425,
     426,   426,   426,   427,   427,   427,   428,   429,   429,   429,
     429,   429,   429,   429,   429,   429,   430,   431,   431,   431,
     432,   433,   434,   434,   434,   435,   435,   435,   435,   435,
     436,   437,   437,   437,   437,   437,   437,   437,   438,   439,
     440,   441,   442,   442,   442,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   444,   444,   445,   445,   446,
     447,   448,   448,   449,   450,   451,   451,   452,   452,   453,
     453,   453,   453,   454,   454,   454,   454,   455,   455,   456,
     456,   457,   457,   458,   458,   459,   459,   459,   460,   460,
     461,   461,   462,   462,   462,   462,   462,   463,   464,   464,
     464,   464,   464,   464,   464,   465,   465,   465,   465,   466,
     466,   466,   466,   467,   467,   468,   468,   468,   468,   468,
     468,   468,   469,   469,   470,   470,   470,   470,   471,   471,
     471,   471,   471,   472,   472,   473,   473,   474,   474,   475,
     475,   476,   477,   477,   478,   478,   478,   479,   479,   479,
     479,   479,   480,   480,   480,   480,   481,   482,   483,   484,
     484,   485,   485,   485,   486,   486,   487
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
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       4,     5,     4,     5,     5,     6,     1,     2,     1,     1,
       2,     1,     4,     3,     4,     4,     5,     4,     5,     5,
       6,     3,     3,     2,     1,     4,     3,     4,     4,     5,
       2,     2,     3,     3,     4,     1,     3,     2,     3,     2,
       1,     2,     2,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     2,     2,     3,     1,     1,     1,     1,     2,
       4,     4,     1,     4,     3,     4,     7,     9,     1,     2,
       4,     7,     7,     1,     3,     1,     3,     1,     3,     3,
       3,     1,     3,     4,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     2,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     3,     4,     1,     2,     3,     2,
       1,     2,     2,     1,     1,     3,     3,     1,     1,     1,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     1,
       3,     3,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     3,     4,     6,     7,     7,     8,     1,     2,     1,
       2,     3,     3,     3,     0,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     5,     6,     2,     3,     5,     6,     3,     3,
       4,     5,     6,     7,     1,     2,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     3,
       2,     2,     2,     3,     3,     2,     3,     5,     3,     5,
       3,     2,     3,     5,     5,     3,     5,     5,     3,     1,
       2,     1,     2,     2,     2,     4,     5,     5,     4,     4,
       4,     5,     5,     4,     4,     2,     2,     4,     4,     4,
       6,     1,     4,     3,     5,     1,     2,     4,     7,     1,
       2,     3,     4,     1,     1,     2,     2,     1,     3,     1,
       3,     1,     3,     1,     2,     1,     2,     3,     1,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     4,     6,     4,
       6,     1,     1,     3,     2,     4,     4,     6,     2,     3,
       1,     2,     1,     1,     2,     2,     3,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     4,     3,     3,     3,     2,
       2,     1,     1,     1,     1,     1,     2
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
  "EnclosedExpr", "NonNodeEnclosedExpr", "QueryBody", "Expr", "ExprSingle",
  "FLWORExpr", "ForLetClauseList", "ForLetClause", "ForClause",
  "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
  "VarGetsDeclList", "VarGetsDecl", "WhereClause", "GroupByClause",
  "GroupSpecList", "GroupSpec", "GroupCollationSpec", "LetClauseList",
  "OrderByClause", "OrderSpecList", "OrderSpec", "OrderModifier",
  "OrderDirSpec", "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
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
       283,     0,    -1,   285,    -1,   284,   285,    -1,   286,    -1,
     284,   286,    -1,   198,    24,   165,    -1,   198,    24,    88,
      24,   165,    -1,   288,   316,    -1,   316,    -1,   287,   288,
      -1,   125,    15,    89,    25,   165,    -1,   289,   165,    -1,
     290,   165,    -1,   289,   165,   290,   165,    -1,   291,    -1,
     289,   165,   291,    -1,   292,    -1,   290,   165,   292,    -1,
     293,    -1,   294,    -1,   295,    -1,   297,    -1,   309,    -1,
     311,    -1,   298,    -1,   299,    -1,   296,    -1,   303,    -1,
     304,    -1,   310,    -1,   300,    -1,   301,    -1,   302,    -1,
     442,    -1,   305,    -1,   308,    -1,    63,    15,    89,    25,
      -1,    55,   154,    -1,    55,   173,    -1,    59,   126,    25,
      -1,    60,   126,    25,    -1,    64,    20,    24,    -1,   230,
     464,    -1,    65,   138,    -1,    65,   182,    -1,    61,    85,
      -1,    61,    86,    -1,    57,   154,    48,   109,    -1,    57,
     154,    48,   132,    -1,    57,   133,    48,   109,    -1,    57,
     133,    48,   132,    -1,    58,    25,    -1,    54,    25,    -1,
     107,    25,    -1,   107,   307,    25,    -1,   107,    25,    35,
     306,    -1,   107,   307,    25,    35,   306,    -1,    25,    -1,
     306,    48,    25,    -1,   126,    15,    89,    -1,    69,   126,
      -1,   106,    25,    -1,   106,   126,    15,    89,    25,    -1,
     106,    25,    35,   306,    -1,   106,   126,    15,    89,    25,
      35,   306,    -1,    67,    26,   101,   318,    -1,    67,    26,
      94,    -1,    67,    26,   424,   101,   318,    -1,    67,    26,
     424,    94,    -1,    56,   154,    -1,    56,   173,    -1,    62,
      20,   121,   160,    94,    -1,    62,    20,   121,   160,   315,
      -1,    62,    20,   121,   312,   160,    94,    -1,    62,    20,
     121,   312,   160,   315,    -1,    62,    20,   121,   160,    33,
     425,    94,    -1,    62,    20,   121,   160,    33,   425,   315,
      -1,    62,    20,   121,   312,   160,    33,   425,    94,    -1,
      62,    20,   121,   312,   160,    33,   425,   315,    -1,    66,
      20,   121,   160,    94,    -1,    66,    20,   121,   160,   315,
      -1,    66,    20,   121,   312,   160,    94,    -1,    66,    20,
     121,   312,   160,   315,    -1,    66,    20,   121,   160,    33,
     425,    94,    -1,    66,    20,   121,   160,    33,   425,   315,
      -1,    66,    20,   121,   312,   160,    33,   425,    94,    -1,
      66,    20,   121,   312,   160,    33,   425,   315,    -1,   313,
      -1,   312,    48,   313,    -1,    76,    26,    -1,    76,    26,
     424,    -1,   115,   317,   157,    -1,   115,   317,   157,    -1,
     317,    -1,   318,    -1,   317,    48,   318,    -1,   319,    -1,
     343,    -1,   346,    -1,   349,    -1,   350,    -1,   443,    -1,
     444,    -1,   446,    -1,   445,    -1,   447,    -1,   450,    -1,
     320,   159,   318,    -1,   320,   330,   159,   318,    -1,   320,
     336,   159,   318,    -1,   320,   330,   336,   159,   318,    -1,
     320,   331,   159,   318,    -1,   320,   330,   331,   159,   318,
      -1,   320,   331,   336,   159,   318,    -1,   320,   330,   331,
     336,   159,   318,    -1,   321,    -1,   320,   321,    -1,   322,
      -1,   327,    -1,    98,   323,    -1,   324,    -1,   323,    48,
      76,   324,    -1,    26,   108,   318,    -1,    26,   424,   108,
     318,    -1,    26,   325,   108,   318,    -1,    26,   424,   325,
     108,   318,    -1,    26,   326,   108,   318,    -1,    26,   424,
     326,   108,   318,    -1,    26,   325,   326,   108,   318,    -1,
      26,   424,   325,   326,   108,   318,    -1,    35,    76,    26,
      -1,   251,    76,    26,    -1,   119,   328,    -1,   329,    -1,
     328,    48,    76,   329,    -1,    26,   101,   318,    -1,    26,
     424,   101,   318,    -1,    26,   326,   101,   318,    -1,    26,
     424,   326,   101,   318,    -1,   195,   318,    -1,   141,   332,
      -1,   141,   332,   335,    -1,   141,   332,   330,    -1,   141,
     332,   335,   330,    -1,   333,    -1,   332,    48,   333,    -1,
      76,    26,    -1,    76,    26,   334,    -1,    47,    25,    -1,
     327,    -1,   335,   327,    -1,   140,   337,    -1,   169,   337,
      -1,   338,    -1,   337,    48,   338,    -1,   318,    -1,   318,
     339,    -1,   340,    -1,   341,    -1,   342,    -1,   340,   341,
      -1,   340,   342,    -1,   341,   342,    -1,   340,   341,   342,
      -1,    34,    -1,    72,    -1,    85,    -1,    86,    -1,    47,
      25,    -1,   168,   344,   161,   318,    -1,    92,   344,   161,
     318,    -1,   345,    -1,   344,    48,    76,   345,    -1,    26,
     108,   318,    -1,    26,   424,   108,   318,    -1,   180,   317,
     160,   347,    68,   159,   318,    -1,   180,   317,   160,   347,
      68,    76,    26,   159,   318,    -1,   348,    -1,   347,   348,
      -1,    41,   425,   159,   318,    -1,    41,    76,    26,    33,
     425,   159,   318,    -1,   105,   317,   160,   177,   318,    84,
     318,    -1,   351,    -1,   350,   137,   351,    -1,   352,    -1,
     351,    31,   352,    -1,   353,    -1,   353,   367,   353,    -1,
     353,   366,   353,    -1,   353,   368,   353,    -1,   354,    -1,
     354,   239,   453,    -1,   354,   239,   453,   487,    -1,   355,
      -1,   355,   178,   355,    -1,   356,    -1,   355,   148,   356,
      -1,   355,   123,   356,    -1,   357,    -1,   356,   170,   357,
      -1,   356,    73,   357,    -1,   356,   104,   357,    -1,   356,
     124,   357,    -1,   358,    -1,   357,   181,   358,    -1,   357,
     193,   358,    -1,   359,    -1,   358,   112,   359,    -1,   358,
      93,   359,    -1,   360,    -1,   360,   110,   425,    -1,   361,
      -1,   361,   179,   425,    -1,   362,    -1,   362,    42,   423,
      -1,   363,    -1,   363,    43,   423,    -1,   365,    -1,   364,
     365,    -1,   148,    -1,   123,    -1,   364,   148,    -1,   364,
     123,    -1,   369,    -1,   373,    -1,   370,    -1,    89,    -1,
     128,    -1,   122,    -1,   117,    -1,   102,    -1,   100,    -1,
     185,    -1,   190,    -1,   189,    -1,   188,    -1,   187,    -1,
     186,    -1,   113,    -1,   151,    -1,    97,    -1,   191,   317,
     157,    -1,    27,   115,   317,   157,    -1,   371,   115,   157,
      -1,   371,   115,   317,   157,    -1,   372,    -1,   371,   372,
      -1,   149,    20,    18,    -1,   149,    21,    -1,   166,    -1,
     166,   374,    -1,   167,   374,    -1,   374,    -1,   375,    -1,
     375,   166,   374,    -1,   375,   167,   374,    -1,   376,    -1,
     385,    -1,   377,    -1,   377,   386,    -1,   380,    -1,   380,
     386,    -1,   378,   382,    -1,   379,    -1,    46,    -1,    70,
      -1,    37,    -1,   164,    -1,    71,    -1,    96,    -1,    95,
      -1,   382,    -1,    40,   382,    -1,   381,   382,    -1,    78,
      -1,   142,    -1,    29,    -1,   153,    -1,   152,    -1,    30,
      -1,   429,    -1,   383,    -1,    20,    -1,   384,    -1,   170,
      -1,    12,    -1,    19,    -1,   388,    -1,   388,   386,    -1,
     387,    -1,   386,   387,    -1,   116,   317,   158,    -1,   389,
      -1,   391,    -1,   392,    -1,   393,    -1,   396,    -1,   398,
      -1,   394,    -1,   395,    -1,   390,    -1,   441,    -1,    53,
      -1,   111,    -1,    80,    -1,    76,    26,    -1,   121,   160,
      -1,   121,   317,   160,    -1,    77,    -1,   139,   317,   157,
      -1,   183,   317,   157,    -1,    20,   121,   160,    -1,    20,
     121,   397,   160,    -1,   318,    -1,   397,    48,   318,    -1,
     399,    -1,   416,    -1,   400,    -1,   413,    -1,   414,    -1,
     172,    20,    87,    -1,   172,    20,   402,    87,    -1,   172,
      20,   174,   171,    20,   174,    -1,   172,    20,   174,   401,
     171,    20,   174,    -1,   172,    20,   402,   174,   171,    20,
     174,    -1,   172,    20,   402,   174,   401,   171,    20,   174,
      -1,   411,    -1,   401,   411,    -1,   403,    -1,   402,   403,
      -1,    20,    89,   404,    -1,   156,   405,   156,    -1,    32,
     407,    32,    -1,    -1,   406,    -1,    91,    -1,   409,    -1,
     406,    91,    -1,   406,   409,    -1,    -1,   408,    -1,    90,
      -1,   410,    -1,   408,    90,    -1,   408,   410,    -1,    23,
      -1,   412,    -1,     3,    -1,   412,    -1,   399,    -1,    10,
      -1,   415,    -1,   412,    -1,     9,    -1,    79,    -1,    81,
      -1,   314,    -1,   196,    28,   197,    -1,   196,   197,    -1,
     143,    17,   144,    -1,   143,    17,     8,    -1,    44,     7,
      -1,   417,    -1,   418,    -1,   419,    -1,   420,    -1,   421,
      -1,   422,    -1,    74,   317,   157,    -1,    11,   157,    -1,
      11,   317,   157,    -1,    82,   317,   157,   115,   157,    -1,
      82,   317,   157,   115,   317,   157,    -1,     4,   157,    -1,
       4,   317,   157,    -1,    38,   317,   157,   115,   157,    -1,
      38,   317,   157,   115,   317,   157,    -1,   175,   317,   157,
      -1,    51,   317,   157,    -1,   155,    15,   115,   157,    -1,
     155,    15,   115,   317,   157,    -1,   155,   115,   317,   157,
     115,   157,    -1,   155,   115,   317,   157,   115,   317,   157,
      -1,   428,    -1,   428,   103,    -1,    33,   425,    -1,   427,
      -1,   427,   426,    -1,   194,    -1,   134,    -1,   136,    -1,
     135,    -1,   428,    -1,   429,    -1,   114,    -1,    20,    -1,
     431,    -1,   437,    -1,   435,    -1,   438,    -1,   436,    -1,
     434,    -1,   433,    -1,   432,    -1,   430,    -1,   130,   160,
      -1,    75,   160,    -1,    75,   437,   160,    -1,    75,   438,
     160,    -1,   176,   160,    -1,    52,   160,    -1,   146,   160,
      -1,   146,    15,   160,    -1,   146,    24,   160,    -1,    39,
     160,    -1,    39,    20,   160,    -1,    39,    20,    48,   439,
     160,    -1,    39,   170,   160,    -1,    39,   170,    48,   439,
     160,    -1,   162,    20,   160,    -1,    83,   160,    -1,    83,
      20,   160,    -1,    83,    20,    48,   439,   160,    -1,    83,
      20,    48,   440,   160,    -1,    83,   170,   160,    -1,    83,
     170,    48,   439,   160,    -1,    83,   170,    48,   440,   160,
      -1,   163,    20,   160,    -1,    20,    -1,    20,   103,    -1,
      24,    -1,   201,   202,    -1,   201,   203,    -1,   201,   204,
      -1,   207,   318,   213,   318,    -1,   207,   318,    33,   212,
     318,    -1,   207,   318,    33,   214,   318,    -1,   207,   318,
     199,   318,    -1,   207,   318,   200,   318,    -1,   208,   318,
     213,   318,    -1,   208,   318,    33,   212,   318,    -1,   208,
     318,    33,   214,   318,    -1,   208,   318,   199,   318,    -1,
     208,   318,   200,   318,    -1,   205,   318,    -1,   206,   318,
      -1,   210,   318,   217,   318,    -1,   211,   318,   217,   318,
      -1,   209,   318,    33,   318,    -1,   216,   448,   215,   318,
     159,   318,    -1,   449,    -1,   448,    48,    76,   449,    -1,
      26,   101,   318,    -1,   218,   115,   318,   157,   451,    -1,
     452,    -1,   451,   452,    -1,   219,   383,   160,   315,    -1,
     219,   383,    48,    76,    26,   160,   315,    -1,   455,    -1,
     455,   454,    -1,   455,   256,   354,    -1,   455,   454,   256,
     354,    -1,   464,    -1,   462,    -1,   454,   464,    -1,   454,
     462,    -1,   456,    -1,   455,   241,   456,    -1,   457,    -1,
     456,   238,   457,    -1,   458,    -1,   457,   245,   458,    -1,
     459,    -1,   240,   459,    -1,   460,    -1,   460,   483,    -1,
     121,   453,   160,    -1,   461,    -1,   461,   479,    -1,   389,
      -1,   115,   317,   157,    -1,   463,    -1,   482,    -1,   481,
      -1,   484,    -1,   478,    -1,   138,    -1,   465,    -1,   466,
      -1,   467,    -1,   468,    -1,   471,    -1,   476,    -1,   477,
      -1,   244,    -1,   255,    -1,   229,    -1,   228,    -1,   265,
      -1,   259,    -1,   232,    -1,   231,    -1,   266,    -1,   260,
      -1,   268,   470,    -1,   268,    68,    -1,   268,   121,   470,
     160,    -1,   268,   121,   470,    48,   469,   160,    -1,   268,
     121,    68,   160,    -1,   268,   121,    68,    48,   469,   160,
      -1,   262,    -1,   470,    -1,   469,    48,   470,    -1,    35,
      24,    -1,    35,    24,   249,    24,    -1,    35,    24,   480,
     243,    -1,    35,    24,   249,    24,   480,   243,    -1,   267,
     473,    -1,   267,   473,   472,    -1,   264,    -1,   264,   472,
      -1,   261,    -1,   475,    -1,   472,   475,    -1,    35,    24,
      -1,   121,   474,   160,    -1,    24,    -1,   474,    24,    -1,
     181,   473,    -1,    93,   473,    -1,   242,    24,    -1,   269,
      -1,   263,    -1,   227,    -1,   224,    -1,   235,    -1,   222,
      -1,   223,    -1,   220,    -1,   221,    -1,   248,    -1,   236,
     357,    -1,   225,   357,    -1,   226,   357,    -1,   237,   357,
     178,   357,    -1,   234,   480,   485,    -1,   257,   357,   485,
      -1,   246,   480,   254,    -1,   250,   486,    -1,   233,   486,
      -1,   270,    -1,   253,    -1,   247,    -1,   252,    -1,   247,
      -1,   258,   357,    -1
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
     394,   396,   398,   400,   402,   404,   406,   408,   410,   414,
     419,   424,   430,   435,   441,   447,   454,   456,   459,   461,
     463,   466,   468,   473,   477,   482,   487,   493,   498,   504,
     510,   517,   521,   525,   528,   530,   535,   539,   544,   549,
     555,   558,   561,   565,   569,   574,   576,   580,   583,   587,
     590,   592,   595,   598,   601,   603,   607,   609,   612,   614,
     616,   618,   621,   624,   627,   631,   633,   635,   637,   639,
     642,   647,   652,   654,   659,   663,   668,   676,   686,   688,
     691,   696,   704,   712,   714,   718,   720,   724,   726,   730,
     734,   738,   740,   744,   749,   751,   755,   757,   761,   765,
     767,   771,   775,   779,   783,   785,   789,   793,   795,   799,
     803,   805,   809,   811,   815,   817,   821,   823,   827,   829,
     832,   834,   836,   839,   842,   844,   846,   848,   850,   852,
     854,   856,   858,   860,   862,   864,   866,   868,   870,   872,
     874,   876,   878,   882,   887,   891,   896,   898,   901,   905,
     908,   910,   913,   916,   918,   920,   924,   928,   930,   932,
     934,   937,   939,   942,   945,   947,   949,   951,   953,   955,
     957,   959,   961,   963,   966,   969,   971,   973,   975,   977,
     979,   981,   983,   985,   987,   989,   991,   993,   995,   997,
    1000,  1002,  1005,  1009,  1011,  1013,  1015,  1017,  1019,  1021,
    1023,  1025,  1027,  1029,  1031,  1033,  1035,  1038,  1041,  1045,
    1047,  1051,  1055,  1059,  1064,  1066,  1070,  1072,  1074,  1076,
    1078,  1080,  1084,  1089,  1096,  1104,  1112,  1121,  1123,  1126,
    1128,  1131,  1135,  1139,  1143,  1144,  1146,  1148,  1150,  1153,
    1156,  1157,  1159,  1161,  1163,  1166,  1169,  1171,  1173,  1175,
    1177,  1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,  1197,
    1200,  1204,  1208,  1211,  1213,  1215,  1217,  1219,  1221,  1223,
    1227,  1230,  1234,  1240,  1247,  1250,  1254,  1260,  1267,  1271,
    1275,  1280,  1286,  1293,  1301,  1303,  1306,  1309,  1311,  1314,
    1316,  1318,  1320,  1322,  1324,  1326,  1328,  1330,  1332,  1334,
    1336,  1338,  1340,  1342,  1344,  1346,  1348,  1351,  1354,  1358,
    1362,  1365,  1368,  1371,  1375,  1379,  1382,  1386,  1392,  1396,
    1402,  1406,  1409,  1413,  1419,  1425,  1429,  1435,  1441,  1445,
    1447,  1450,  1452,  1455,  1458,  1461,  1466,  1472,  1478,  1483,
    1488,  1493,  1499,  1505,  1510,  1515,  1518,  1521,  1526,  1531,
    1536,  1543,  1545,  1550,  1554,  1560,  1562,  1565,  1570,  1578,
    1580,  1583,  1587,  1592,  1594,  1596,  1599,  1602,  1604,  1608,
    1610,  1614,  1616,  1620,  1622,  1625,  1627,  1630,  1634,  1636,
    1639,  1641,  1645,  1647,  1649,  1651,  1653,  1655,  1657,  1659,
    1661,  1663,  1665,  1667,  1669,  1671,  1673,  1675,  1677,  1679,
    1681,  1683,  1685,  1687,  1689,  1691,  1694,  1697,  1702,  1709,
    1714,  1721,  1723,  1725,  1729,  1732,  1737,  1742,  1749,  1752,
    1756,  1758,  1761,  1763,  1765,  1768,  1771,  1775,  1777,  1780,
    1783,  1786,  1789,  1791,  1793,  1795,  1797,  1799,  1801,  1803,
    1805,  1807,  1809,  1812,  1815,  1818,  1823,  1827,  1831,  1835,
    1838,  1841,  1843,  1845,  1847,  1849,  1851
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   749,   749,   757,   766,   773,   786,   794,   807,   817,
     832,   847,   862,   871,   880,   895,   904,   921,   930,   947,
     954,   961,   968,   980,   987,   994,  1003,  1016,  1023,  1030,
    1037,  1044,  1051,  1058,  1067,  1080,  1087,  1105,  1120,  1128,
    1142,  1151,  1166,  1182,  1196,  1204,  1219,  1227,  1241,  1250,
    1259,  1268,  1290,  1304,  1318,  1328,  1338,  1348,  1364,  1373,
    1391,  1398,  1411,  1420,  1430,  1439,  1456,  1466,  1476,  1486,
    1502,  1510,  1524,  1534,  1545,  1556,  1568,  1580,  1592,  1604,
    1616,  1626,  1637,  1648,  1660,  1672,  1684,  1696,  1714,  1725,
    1742,  1751,  1766,  1777,  1791,  1805,  1814,  1829,  1836,  1843,
    1850,  1857,  1866,  1873,  1880,  1887,  1894,  1901,  1914,  1924,
    1935,  1946,  1958,  1973,  1988,  2003,  2024,  2033,  2048,  2055,
    2068,  2082,  2091,  2108,  2118,  2129,  2141,  2154,  2165,  2177,
    2189,  2207,  2222,  2236,  2251,  2260,  2277,  2288,  2300,  2311,
    2329,  2340,  2350,  2360,  2370,  2383,  2392,  2406,  2415,  2427,
    2437,  2447,  2462,  2470,  2485,  2494,  2511,  2520,  2535,  2545,
    2555,  2565,  2575,  2585,  2595,  2611,  2618,  2631,  2639,  2653,
    2667,  2677,  2693,  2703,  2718,  2727,  2743,  2753,  2770,  2779,
    2794,  2803,  2819,  2833,  2840,  2854,  2861,  2883,  2890,  2901,
    2912,  2929,  2936,  2946,  2962,  2969,  2983,  2990,  2997,  3010,
    3017,  3024,  3031,  3038,  3051,  3058,  3066,  3080,  3087,  3094,
    3107,  3114,  3129,  3136,  3151,  3158,  3173,  3180,  3195,  3202,
    3217,  3224,  3231,  3238,  3253,  3260,  3267,  3281,  3288,  3295,
    3302,  3309,  3316,  3329,  3336,  3343,  3350,  3357,  3364,  3377,
    3384,  3391,  3405,  3412,  3427,  3436,  3451,  3460,  3477,  3486,
    3528,  3535,  3542,  3549,  3563,  3571,  3578,  3591,  3598,  3611,
    3620,  3629,  3638,  3653,  3662,  3676,  3683,  3690,  3697,  3704,
    3711,  3718,  3731,  3738,  3751,  3760,  3775,  3782,  3789,  3796,
    3803,  3821,  3828,  3841,  3848,  3861,  3871,  3881,  3897,  3904,
    3919,  3928,  3945,  3959,  3966,  3973,  3980,  3987,  3994,  4001,
    4008,  4021,  4028,  4041,  4049,  4057,  4071,  4084,  4091,  4105,
    4118,  4132,  4191,  4200,  4215,  4224,  4239,  4246,  4259,  4266,
    4273,  4286,  4297,  4308,  4319,  4330,  4341,  4359,  4368,  4383,
    4392,  4409,  4424,  4432,  4447,  4453,  4460,  4469,  4478,  4489,
    4507,  4513,  4520,  4529,  4538,  4549,  4566,  4574,  4588,  4596,
    4610,  4618,  4626,  4635,  4650,  4659,  4667,  4675,  4689,  4697,
    4715,  4723,  4743,  4761,  4768,  4775,  4782,  4789,  4796,  4809,
    4823,  4832,  4841,  4849,  4877,  4886,  4895,  4903,  4917,  4931,
    4945,  4954,  4963,  4971,  4985,  4994,  5009,  5023,  5032,  5041,
    5081,  5089,  5097,  5111,  5118,  5125,  5138,  5152,  5159,  5166,
    5173,  5180,  5187,  5194,  5201,  5208,  5221,  5234,  5241,  5249,
    5263,  5276,  5289,  5296,  5303,  5316,  5325,  5334,  5343,  5352,
    5367,  5381,  5390,  5399,  5408,  5417,  5427,  5437,  5453,  5477,
    5487,  5510,  5553,  5561,  5567,  5578,  5587,  5596,  5605,  5614,
    5624,  5633,  5642,  5651,  5660,  5675,  5683,  5696,  5705,  5720,
    5749,  5763,  5772,  5788,  5805,  5815,  5825,  5839,  5849,  5872,
    5878,  5884,  5890,  5902,  5908,  5914,  5920,  5932,  5938,  5950,
    5956,  5968,  5974,  5986,  5992,  6004,  6010,  6016,  6028,  6034,
    6046,  6052,  6064,  6070,  6076,  6082,  6088,  6100,  6112,  6119,
    6126,  6133,  6140,  6147,  6154,  6167,  6173,  6179,  6185,  6197,
    6203,  6209,  6215,  6227,  6233,  6245,  6251,  6257,  6263,  6269,
    6275,  6281,  6293,  6299,  6311,  6317,  6323,  6329,  6341,  6347,
    6353,  6359,  6365,  6377,  6383,  6395,  6401,  6413,  6419,  6431,
    6437,  6449,  6461,  6467,  6479,  6485,  6491,  6503,  6509,  6515,
    6521,  6527,  6539,  6546,  6553,  6560,  6573,  6585,  6597,  6609,
    6615,  6627,  6633,  6639,  6651,  6657,  6669
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
     275,   276,   277,   278,   279,   280,   281
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 3968;
  const int xquery_parser::yynnts_ = 206;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 325;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 282;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 536;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 6679 "/home/dagraf/Work/28msec/zorba4/xquery/src/compiler/parser/xquery_parser.y"



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

