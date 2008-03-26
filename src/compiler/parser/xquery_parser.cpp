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
#line 722 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 51 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"

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
#line 622 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).decval; };
#line 211 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 80: /* "\"'DOUBLE'\"" */
#line 621 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).dval; };
#line 216 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 111: /* "\"'INTEGER'\"" */
#line 620 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).ival; };
#line 221 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 283: /* "VersionDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 226 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 284: /* "MainModule" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 231 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 285: /* "LibraryModule" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 236 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "ModuleDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 241 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "Prolog" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 246 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "SIND_DeclList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 251 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "VFO_DeclList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 256 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "SIND_Decl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 261 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "VFO_Decl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 266 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "Setter" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 271 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "Import" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 276 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "NamespaceDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 281 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "BoundarySpaceDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 286 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "DefaultNamespaceDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 291 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "OptionDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 296 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "OrderingModeDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 301 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "EmptyOrderDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 306 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "CopyNamespacesDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 311 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "DefaultCollationDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 316 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "BaseURIDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 321 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "SchemaImport" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 326 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "URILiteralList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 331 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "SchemaPrefix" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 336 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "ModuleImport" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 341 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "VarDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 346 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "ConstructionDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 351 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "FunctionDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 356 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "ParamList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 361 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "Param" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 366 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "EnclosedExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 371 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "NonNodeEnclosedExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 376 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "QueryBody" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 381 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "Expr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 386 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "ExprSingle" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 391 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "FLWORExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 396 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "ForLetClauseList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 401 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "ForLetClause" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 406 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "ForClause" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 411 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "VarInDeclList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 416 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "VarInDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 421 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "PositionalVar" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 426 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "LetClause" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 431 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VarGetsDeclList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 436 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "VarGetsDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 441 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "WhereClause" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 446 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "OrderByClause" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 451 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "OrderSpecList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 456 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "OrderSpec" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 461 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "OrderModifier" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 466 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "OrderDirSpec" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 471 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "OrderEmptySpec" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 476 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "OrderCollationSpec" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 481 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "QuantifiedExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 486 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "QVarInDeclList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 491 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "QVarInDecl" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 496 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "TypeswitchExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 501 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "CaseClauseList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 506 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "CaseClause" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 511 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "IfExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 516 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "OrExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 521 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "AndExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 526 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "ComparisonExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 531 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "RangeExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 536 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "AdditiveExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 541 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "MultiplicativeExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 546 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "UnionExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 551 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "IntersectExceptExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 556 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "InstanceofExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 561 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "TreatExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 566 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CastableExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 571 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CastExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 576 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "UnaryExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 581 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "SignList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 586 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "ValueExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 591 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "GeneralComp" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 596 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "ValueComp" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 601 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "NodeComp" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 606 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "ValidateExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 611 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "ExtensionExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 616 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "PragmaList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 621 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "Pragma" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "PathExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 631 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "RelativePathExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 636 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "StepExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 641 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "AxisStep" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 646 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "ForwardStep" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 651 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "ForwardAxis" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 656 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "AbbrevForwardStep" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 661 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "ReverseStep" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 666 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "ReverseAxis" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 671 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "NodeTest" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 676 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "NameTest" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 681 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "Wildcard" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 686 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FilterExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 691 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "PredicateList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 696 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "Predicate" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 701 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "PrimaryExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 706 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "Literal" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 711 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "NumericLiteral" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 716 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "VarRef" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 721 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ParenthesizedExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 726 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ContextItemExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 731 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "OrderedExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 736 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "UnorderedExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 741 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "FunctionCall" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 746 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ArgList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 751 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "Constructor" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 756 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "DirectConstructor" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 761 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "DirElemConstructor" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 766 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "DirElemContentList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 771 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "DirAttributeList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 776 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "DirAttr" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 781 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "DirAttributeValue" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 786 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "Opt_QuoteAttrContentList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 791 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "QuoteAttrContentList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 796 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "Opt_AposAttrContentList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 801 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "AposAttrContentList" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 806 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "QuoteAttrValueContent" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 811 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "AposAttrValueContent" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 816 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "DirElemContent" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 821 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "CommonContent" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 826 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "DirCommentConstructor" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 831 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "DirPIConstructor" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 836 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "CDataSection" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 841 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "ComputedConstructor" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 846 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CompDocConstructor" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 851 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "CompElemConstructor" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 856 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "CompAttrConstructor" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 861 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "CompTextConstructor" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 866 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "CompCommentConstructor" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 871 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "CompPIConstructor" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 876 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "SingleType" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 881 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "TypeDeclaration" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 886 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "SequenceType" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 891 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OccurrenceIndicator" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 896 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "ItemType" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 901 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "AtomicType" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 906 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "KindTest" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 911 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "AnyKindTest" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 916 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "DocumentTest" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 921 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "TextTest" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 926 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "CommentTest" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 931 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "PITest" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 936 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "AttributeTest" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 941 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "SchemaAttributeTest" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 946 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "ElementTest" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 951 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "SchemaElementTest" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 956 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "TypeName" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 961 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "TypeName_WITH_HOOK" */
#line 626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->node)->safeRemoveRef (); };
#line 966 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "StringLiteral" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 971 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "TryExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 976 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "CatchListExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 981 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "CatchExpr" */
#line 627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
	{ (yyvaluep->expr)->safeRemoveRef (); };
#line 986 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 68 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename.getStore()->str());
}
  /* Line 547 of yacc.c.  */
#line 1067 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
#line 743 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 3:
#line 751 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.main]" << endl;
#endif
		;}
    break;

  case 4:
#line 759 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]" << endl;
#endif
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 5:
#line 766 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]" << endl;
#endif
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		;}
    break;

  case 6:
#line 779 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]" << endl;
#endif
       std::string encoding;
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), encoding);
		;}
    break;

  case 7:
#line 787 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]" << endl;
#endif
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (2)].sval)), SYMTAB ((yysemantic_stack_[(5) - (4)].sval)));
    ;}
    break;

  case 8:
#line 800 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 810 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 825 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 840 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 855 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 864 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 873 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 888 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 897 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 914 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 923 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 940 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 947 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 954 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 961 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 973 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 980 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 987 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 996 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 1009 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 1016 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 1023 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1030 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1037 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1044 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1051 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1060 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1073 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1080 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1098 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1113 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1121 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1135 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1144 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1159 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1175 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]" << endl;
#endif
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1189 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1197 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1212 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1220 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1234 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1243 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1252 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1261 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1283 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]" << endl;
#endif
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1297 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]" << endl;
#endif
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1311 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1321 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1331 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1341 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1357 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1366 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1384 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1391 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 62:
#line 1404 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1413 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1423 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1432 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1449 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1459 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1469 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1479 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1495 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1503 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1517 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1527 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1538 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1549 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1561 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1573 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1585 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1597 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1609 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1619 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1630 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1641 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1653 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1665 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1677 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1689 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1707 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1718 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1735 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1744 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1759 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1770 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NonNodeEnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 94:
#line 1784 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]" << endl;
#endif
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 95:
#line 1798 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1807 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1822 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1829 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1836 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1843 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1850 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1859 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1866 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1873 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1880 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1887 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 107:
#line 1894 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
      cout << "ExprSingle [TryExpr]" << endl;
#endif
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 108:
#line 1907 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 109:
#line 1917 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 110:
#line 1928 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 111:
#line 1939 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 112:
#line 1956 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [single]" << endl;
#endif
			ForLetClauseList* flc_list_p = new ForLetClauseList(LOC ((yyloc)));
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = flc_list_p;
		;}
    break;

  case 113:
#line 1965 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [list]" << endl;
#endif
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(2) - (1)].node));
			if (flc_list_p) flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 114:
#line 1980 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 115:
#line 1987 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 116:
#line 2000 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]" << endl;
#endif
			(yyval.node) = new ForClause(LOC ((yyloc)),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 117:
#line 2014 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDeclList [single]" << endl;
#endif
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 118:
#line 2023 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 119:
#line 2040 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 120:
#line 2050 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 121:
#line 2061 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 122:
#line 2073 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 123:
#line 2086 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 124:
#line 2097 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 125:
#line 2109 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 126:
#line 2121 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 127:
#line 2139 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]" << endl;
#endif
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 128:
#line 2154 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]" << endl;
#endif
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 129:
#line 2168 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]" << endl;
#endif
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 130:
#line 2183 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [single]" << endl;
#endif
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 131:
#line 2192 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 132:
#line 2209 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 133:
#line 2220 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 134:
#line 2232 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 135:
#line 2243 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 136:
#line 2261 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]" << endl;
#endif
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 137:
#line 2275 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]" << endl;
#endif
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 138:
#line 2283 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [stable]" << endl;
#endif
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)),
								true);
		;}
    break;

  case 139:
#line 2298 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpecList [single]" << endl;
#endif
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 140:
#line 2307 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 141:
#line 2324 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single]" << endl;
#endif
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 142:
#line 2333 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single.modifier]" << endl;
#endif
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 143:
#line 2348 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 144:
#line 2358 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 145:
#line 2368 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 146:
#line 2378 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 147:
#line 2388 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 148:
#line 2398 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 149:
#line 2408 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 150:
#line 2424 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 151:
#line 2431 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 152:
#line 2444 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 153:
#line 2452 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 154:
#line 2466 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]" << endl;
#endif
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 155:
#line 2480 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 156:
#line 2490 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 157:
#line 2506 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [single]" << endl;
#endif
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 158:
#line 2516 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [list]" << endl;
#endif
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 159:
#line 2531 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDecl [in]" << endl;
#endif
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 160:
#line 2540 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 161:
#line 2556 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 162:
#line 2566 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 163:
#line 2583 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [single]" << endl;
#endif
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 164:
#line 2592 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [list]" << endl;
#endif
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 165:
#line 2607 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClause [case.return]" << endl;
#endif
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 166:
#line 2616 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 167:
#line 2632 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]" << endl;
#endif
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 168:
#line 2646 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 169:
#line 2653 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]" << endl;
#endif
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 170:
#line 2667 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 171:
#line 2674 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]" << endl;
#endif
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 172:
#line 2696 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 173:
#line 2703 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 174:
#line 2714 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 175:
#line 2725 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 176:
#line 2742 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 177:
#line 2749 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 178:
#line 2759 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 179:
#line 2775 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 180:
#line 2782 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]" << endl;
#endif
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 181:
#line 2796 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 182:
#line 2803 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 183:
#line 2810 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 184:
#line 2823 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]" << endl;
#endif
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 185:
#line 2830 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 186:
#line 2837 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 187:
#line 2844 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 188:
#line 2851 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 189:
#line 2864 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 190:
#line 2871 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 191:
#line 2879 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 192:
#line 2893 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 193:
#line 2900 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 194:
#line 2907 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 195:
#line 2920 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 196:
#line 2927 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat.seqtype]" << endl;
#endif
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 197:
#line 2942 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 198:
#line 2949 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable.seqtype]" << endl;
#endif
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 199:
#line 2964 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 200:
#line 2971 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast.singletype]" << endl;
#endif
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 201:
#line 2986 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 202:
#line 2993 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary.singletype]" << endl;
#endif
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 203:
#line 3008 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 204:
#line 3015 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [signlist.value]" << endl;
#endif
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 205:
#line 3030 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]" << endl;
#endif
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 206:
#line 3037 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]" << endl;
#endif
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 207:
#line 3044 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 208:
#line 3051 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.-]" << endl;
#endif
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 209:
#line 3066 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 3073 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 211:
#line 3080 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 212:
#line 3094 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq);
		;}
    break;

  case 213:
#line 3101 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne);
		;}
    break;

  case 214:
#line 3108 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt);
		;}
    break;

  case 215:
#line 3115 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_le);
		;}
    break;

  case 216:
#line 3122 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt);
		;}
    break;

  case 217:
#line 3129 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge);
		;}
    break;

  case 218:
#line 3142 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 219:
#line 3149 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 220:
#line 3156 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 221:
#line 3163 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 222:
#line 3170 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 223:
#line 3177 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 224:
#line 3190 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 225:
#line 3197 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 226:
#line 3204 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 227:
#line 3218 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 228:
#line 3225 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [mode.expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 229:
#line 3240 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist]" << endl;
#endif
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 230:
#line 3249 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist.expr]" << endl;
#endif
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 231:
#line 3264 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PragmaList [single]" << endl;
#endif
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 232:
#line 3273 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 233:
#line 3290 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Pragma [ ]" << endl;
#endif
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 234:
#line 3298 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 235:
#line 3341 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 236:
#line 3348 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 237:
#line 3355 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 238:
#line 3362 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [relative]" << endl;
#endif
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = rpe == NULL ? (yysemantic_stack_[(1) - (1)].expr) : new PathExpr(LOC ((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 239:
#line 3376 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step]" << endl;
#endif
            AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = as != NULL ? new RelativePathExpr(LOC ((yyloc)), ParseConstants::st_slash, new ContextItemExpr(LOC ((yyloc))), (yysemantic_stack_[(1) - (1)].expr)) : (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 240:
#line 3384 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(LOC ((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 241:
#line 3391 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(LOC ((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 242:
#line 3404 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 243:
#line 3411 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 244:
#line 3424 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 245:
#line 3433 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward.predlist]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 246:
#line 3442 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 247:
#line 3451 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse.predlist]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 248:
#line 3466 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 249:
#line 3475 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]" << endl;
#endif
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 250:
#line 3489 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 251:
#line 3496 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 252:
#line 3503 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 253:
#line 3510 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 254:
#line 3517 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 255:
#line 3524 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 256:
#line 3531 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 257:
#line 3544 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 258:
#line 3551 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 259:
#line 3564 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [nodetest]" << endl;
#endif
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 260:
#line 3573 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [..]" << endl;
#endif
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 261:
#line 3588 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 262:
#line 3595 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 263:
#line 3602 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 264:
#line 3609 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 265:
#line 3616 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 266:
#line 3634 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 267:
#line 3641 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 268:
#line 3654 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]" << endl;
#endif
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 269:
#line 3661 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]" << endl;
#endif
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 270:
#line 3674 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 271:
#line 3684 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 272:
#line 3694 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 273:
#line 3710 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 274:
#line 3717 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary.predlist]" << endl;
#endif
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 275:
#line 3732 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [single]" << endl;
#endif
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 276:
#line 3741 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 277:
#line 3758 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 278:
#line 3772 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 279:
#line 3779 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 280:
#line 3786 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 281:
#line 3793 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 3800 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 283:
#line 3807 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 284:
#line 3814 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 285:
#line 3821 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 286:
#line 3834 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 287:
#line 3841 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 288:
#line 3854 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.decval);
      delete yylval.decval;
		;}
    break;

  case 289:
#line 3862 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.ival);
      delete yylval.ival;
		;}
    break;

  case 290:
#line 3870 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.dval);
      delete yylval.dval;
		;}
    break;

  case 291:
#line 3884 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]" << endl;
#endif
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 292:
#line 3897 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 293:
#line 3904 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 294:
#line 3918 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]" << endl;
#endif
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 295:
#line 3931 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 296:
#line 3945 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 297:
#line 4004 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [ ]" << endl;
#endif
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 298:
#line 4013 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [arglist]" << endl;
#endif
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 299:
#line 4028 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [single]" << endl;
#endif
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 300:
#line 4037 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [list]" << endl;
#endif
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 301:
#line 4052 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 4059 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 4072 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 304:
#line 4079 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 305:
#line 4086 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 306:
#line 4099 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 307:
#line 4110 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 308:
#line 4121 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 309:
#line 4132 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 310:
#line 4143 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 311:
#line 4154 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 312:
#line 4172 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [single]" << endl;
#endif
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 313:
#line 4181 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [list]" << endl;
#endif
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 314:
#line 4196 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [single]" << endl;
#endif
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 315:
#line 4205 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 316:
#line 4222 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttr [ ]" << endl;
#endif
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 317:
#line 4237 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 318:
#line 4245 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 319:
#line 4259 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]" << endl;
#endif
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 320:
#line 4266 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 321:
#line 4273 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [""]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 322:
#line 4282 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [single]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 323:
#line 4291 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 324:
#line 4302 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 325:
#line 4319 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 326:
#line 4326 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 327:
#line 4333 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 328:
#line 4342 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [single]" << endl;
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 329:
#line 4351 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 330:
#line 4362 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 331:
#line 4379 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 332:
#line 4387 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 333:
#line 4401 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 334:
#line 4409 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 335:
#line 4423 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]" << endl;
#endif
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 336:
#line 4431 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]" << endl;
#endif
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 337:
#line 4439 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cdata]" << endl;
#endif
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 338:
#line 4448 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [common_content]" << endl;
#endif
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 339:
#line 4463 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [char_ref]\n";
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 340:
#line 4472 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 341:
#line 4480 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 342:
#line 4488 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 343:
#line 4502 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]" << endl;
#endif
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 344:
#line 4510 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "DirCommentConstructor [ ]" << endl;
#endif
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 345:
#line 4528 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 346:
#line 4536 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target.charlit]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 347:
#line 4556 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]" << endl;
#endif
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 348:
#line 4574 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 4581 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 4588 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 4595 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 352:
#line 4602 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 353:
#line 4609 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 354:
#line 4622 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 355:
#line 4636 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 356:
#line 4645 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 357:
#line 4654 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 358:
#line 4662 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 359:
#line 4690 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 360:
#line 4699 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 361:
#line 4708 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 362:
#line 4716 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 363:
#line 4730 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 364:
#line 4744 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 365:
#line 4758 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 366:
#line 4767 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 367:
#line 4776 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 368:
#line 4784 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 369:
#line 4798 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic]" << endl;
#endif
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 370:
#line 4807 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic ?]" << endl;
#endif
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 371:
#line 4822 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]" << endl;
#endif
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 372:
#line 4836 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 373:
#line 4845 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type.occurs]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 374:
#line 4854 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 375:
#line 4894 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 376:
#line 4902 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 377:
#line 4910 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 378:
#line 4924 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 379:
#line 4931 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 380:
#line 4938 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]" << endl;
#endif
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 381:
#line 4951 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]" << endl;
#endif
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 382:
#line 4965 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 383:
#line 4972 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 384:
#line 4979 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 385:
#line 4986 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 386:
#line 4993 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 387:
#line 5000 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 388:
#line 5007 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 389:
#line 5014 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 390:
#line 5021 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 391:
#line 5034 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]" << endl;
#endif
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 392:
#line 5047 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 393:
#line 5054 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 394:
#line 5062 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 395:
#line 5076 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]" << endl;
#endif
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 396:
#line 5089 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]" << endl;
#endif
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 397:
#line 5102 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 398:
#line 5109 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 399:
#line 5116 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 400:
#line 5129 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [ ]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 401:
#line 5138 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL);
		;}
    break;

  case 402:
#line 5147 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name.type]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 403:
#line 5156 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 404:
#line 5165 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*.type]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 405:
#line 5180 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 406:
#line 5194 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [ ]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL);
		;}
    break;

  case 407:
#line 5203 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
									NULL);
		;}
    break;

  case 408:
#line 5212 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5221 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 410:
#line 5230 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 411:
#line 5240 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5250 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 413:
#line 5266 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 414:
#line 5290 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]" << endl;
#endif
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 415:
#line 5300 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name?]" << endl;
#endif
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 416:
#line 5323 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]" << endl;
#endif
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 417:
#line 5366 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [strict]" << endl;
#endif
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 418:
#line 5374 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [lax]" << endl;
#endif
    ;}
    break;

  case 419:
#line 5380 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [skip]" << endl;
#endif
    ;}
    break;

  case 420:
#line 5391 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 421:
#line 5400 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.as_first]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 422:
#line 5409 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.as_last]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 423:
#line 5418 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.after]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 424:
#line 5427 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.before]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 425:
#line 5437 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 426:
#line 5446 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.as_first]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 427:
#line 5455 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.as_last]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 428:
#line 5464 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.after]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 429:
#line 5473 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.before]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 430:
#line 5488 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodeExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 431:
#line 5496 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodesExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 432:
#line 5509 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 433:
#line 5518 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceValueOfExpr [value.expr]" << endl;
#endif
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 434:
#line 5533 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 435:
#line 5562 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]" << endl;
#endif
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(6) - (2)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(6) - (4)].expr), (yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 436:
#line 5576 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [single]" << endl;
#endif
       (yyval.expr) = new VarNameList(LOC((yyloc)));
		;}
    break;

  case 437:
#line 5583 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 438:
#line 5599 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "VarNameDecl [" << driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)) << "]" << endl;
#endif
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 439:
#line 5616 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TryExpr []" << endl;
#endif
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 440:
#line 5626 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchList [single]" << endl;
#endif
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 441:
#line 5636 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 442:
#line 5650 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchExpr [NameTest]" << endl;
#endif
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 443:
#line 5660 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 444:
#line 5683 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]" << endl;
#endif
		;}
    break;

  case 445:
#line 5689 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]" << endl;
#endif
		;}
    break;

  case 446:
#line 5695 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]" << endl;
#endif
		;}
    break;

  case 447:
#line 5701 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]" << endl;
#endif
		;}
    break;

  case 448:
#line 5713 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]" << endl;
#endif
		;}
    break;

  case 449:
#line 5719 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]" << endl;
#endif
		;}
    break;

  case 450:
#line 5725 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]" << endl;
#endif
		;}
    break;

  case 451:
#line 5731 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]" << endl;
#endif
		;}
    break;

  case 452:
#line 5743 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]" << endl;
#endif
		;}
    break;

  case 453:
#line 5749 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]" << endl;
#endif
		;}
    break;

  case 454:
#line 5761 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]" << endl;
#endif
		;}
    break;

  case 455:
#line 5767 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]" << endl;
#endif
		;}
    break;

  case 456:
#line 5779 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]" << endl;
#endif
		;}
    break;

  case 457:
#line 5785 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]" << endl;
#endif
		;}
    break;

  case 458:
#line 5797 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]" << endl;
#endif
		;}
    break;

  case 459:
#line 5803 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]" << endl;
#endif
		;}
    break;

  case 460:
#line 5815 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]" << endl;
#endif
		;}
    break;

  case 461:
#line 5821 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]" << endl;
#endif
		;}
    break;

  case 462:
#line 5827 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]" << endl;
#endif
		;}
    break;

  case 463:
#line 5839 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]" << endl;
#endif
		;}
    break;

  case 464:
#line 5845 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]" << endl;
#endif
		;}
    break;

  case 465:
#line 5857 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]" << endl;
#endif
		;}
    break;

  case 466:
#line 5863 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]" << endl;
#endif
		;}
    break;

  case 467:
#line 5875 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]" << endl;
#endif
		;}
    break;

  case 468:
#line 5881 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]" << endl;
#endif
		;}
    break;

  case 469:
#line 5887 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]" << endl;
#endif
		;}
    break;

  case 470:
#line 5893 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]" << endl;
#endif
		;}
    break;

  case 471:
#line 5899 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]" << endl;
#endif
		;}
    break;

  case 472:
#line 5911 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]" << endl;
#endif
		;}
    break;

  case 473:
#line 5923 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 474:
#line 5930 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 475:
#line 5937 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 476:
#line 5944 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 477:
#line 5951 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 478:
#line 5958 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 479:
#line 5965 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 480:
#line 5978 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]" << endl;
#endif
		;}
    break;

  case 481:
#line 5984 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]" << endl;
#endif
		;}
    break;

  case 482:
#line 5990 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]" << endl;
#endif
		;}
    break;

  case 483:
#line 5996 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]" << endl;
#endif
		;}
    break;

  case 484:
#line 6008 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]" << endl;
#endif
		;}
    break;

  case 485:
#line 6014 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]" << endl;
#endif
		;}
    break;

  case 486:
#line 6020 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]" << endl;
#endif
		;}
    break;

  case 487:
#line 6026 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]" << endl;
#endif
		;}
    break;

  case 488:
#line 6038 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]" << endl;
#endif
		;}
    break;

  case 489:
#line 6044 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]" << endl;
#endif
		;}
    break;

  case 490:
#line 6056 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]" << endl;
#endif
		;}
    break;

  case 491:
#line 6062 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]" << endl;
#endif
		;}
    break;

  case 492:
#line 6068 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]" << endl;
#endif
		;}
    break;

  case 493:
#line 6074 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]" << endl;
#endif
		;}
    break;

  case 494:
#line 6080 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]" << endl;
#endif
		;}
    break;

  case 495:
#line 6086 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]" << endl;
#endif
		;}
    break;

  case 496:
#line 6092 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]" << endl;
#endif
		;}
    break;

  case 497:
#line 6104 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]" << endl;
#endif
		;}
    break;

  case 498:
#line 6110 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]" << endl;
#endif
		;}
    break;

  case 499:
#line 6122 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]" << endl;
#endif
		;}
    break;

  case 500:
#line 6128 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]" << endl;
#endif
		;}
    break;

  case 501:
#line 6134 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]" << endl;
#endif
		;}
    break;

  case 502:
#line 6140 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]" << endl;
#endif
		;}
    break;

  case 503:
#line 6152 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]" << endl;
#endif
		;}
    break;

  case 504:
#line 6158 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]" << endl;
#endif
		;}
    break;

  case 505:
#line 6164 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]" << endl;
#endif
		;}
    break;

  case 506:
#line 6170 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]" << endl;
#endif
		;}
    break;

  case 507:
#line 6176 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]" << endl;
#endif
		;}
    break;

  case 508:
#line 6188 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 509:
#line 6194 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 510:
#line 6206 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]" << endl;
#endif
		;}
    break;

  case 511:
#line 6212 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]" << endl;
#endif
		;}
    break;

  case 512:
#line 6224 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 513:
#line 6230 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 514:
#line 6242 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]" << endl;
#endif
		;}
    break;

  case 515:
#line 6248 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]" << endl;
#endif
		;}
    break;

  case 516:
#line 6260 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]" << endl;
#endif
		;}
    break;

  case 517:
#line 6272 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]" << endl;
#endif
		;}
    break;

  case 518:
#line 6278 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]" << endl;
#endif
		;}
    break;

  case 519:
#line 6290 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]" << endl;
#endif
		;}
    break;

  case 520:
#line 6296 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]" << endl;
#endif
		;}
    break;

  case 521:
#line 6302 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]" << endl;
#endif
		;}
    break;

  case 522:
#line 6314 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]" << endl;
#endif
		;}
    break;

  case 523:
#line 6320 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]" << endl;
#endif
		;}
    break;

  case 524:
#line 6326 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]" << endl;
#endif
		;}
    break;

  case 525:
#line 6332 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]" << endl;
#endif
		;}
    break;

  case 526:
#line 6338 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]" << endl;
#endif
		;}
    break;

  case 527:
#line 6350 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 528:
#line 6357 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 529:
#line 6364 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 530:
#line 6371 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 531:
#line 6384 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]" << endl;
#endif
		;}
    break;

  case 532:
#line 6396 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]" << endl;
#endif
		;}
    break;

  case 533:
#line 6408 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]" << endl;
#endif
		;}
    break;

  case 534:
#line 6420 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]" << endl;
#endif
		;}
    break;

  case 535:
#line 6426 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]" << endl;
#endif
		;}
    break;

  case 536:
#line 6438 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]" << endl;
#endif
		;}
    break;

  case 537:
#line 6444 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]" << endl;
#endif
		;}
    break;

  case 538:
#line 6450 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 539:
#line 6462 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]" << endl;
#endif
		;}
    break;

  case 540:
#line 6468 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 541:
#line 6480 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ ]" << endl;
#endif
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 7122 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -652;
  const short int
  xquery_parser::yypact_[] =
  {
       749,  1163,  1370,  -652,  -652,   171,  -652,   208,  -652,  -652,
    -652,  3026,    73,   332,  -652,  3026,   -27,  -652,   303,   -39,
     -26,   -16,   356,   262,   292,   319,   410,   437,   443,   -50,
     459,   456,  -652,  -652,  3026,     1,   463,  -652,  -652,  -652,
    3026,    74,   482,  -652,  -652,   491,  3026,   211,   252,  -652,
     504,  1577,  -652,   524,   345,  3026,  -652,   526,    75,  -652,
     478,  -652,  -652,    53,   525,   527,  -652,  3731,  3570,   482,
    -652,   529,  3026,   409,  3026,  3026,  3026,    20,   534,   369,
    3026,  3026,  3026,  3026,  3026,  3026,  3026,   547,   466,  3669,
     583,   956,  -652,  -652,   243,  3026,   428,   430,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,   551,  -652,
    -652,   347,  -652,  -652,  -652,  -652,  -652,  -652,   469,   581,
    -652,   649,   377,   309,   307,   142,    52,  -652,   509,   457,
     586,   591,  3233,  -652,  -652,  -652,    -7,  -652,  -652,  -652,
     399,  -652,   513,   332,  -652,   513,   332,  -652,  -652,  -652,
    -652,   513,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,    31,  -652,    81,  1784,  3026,   113,    17,  -652,    21,
    -652,  -652,   114,  -652,  -652,  -652,  -652,  -652,  -652,   589,
     590,  -652,   615,   616,  -652,  -652,   521,   554,   623,  -652,
    -652,   538,   450,   118,  -652,   501,   502,  -652,   119,    58,
    -652,    80,   249,    26,  -652,    -5,   614,  -652,    90,   628,
     650,   631,   542,   655,   646,    -9,   624,  -652,  -652,    91,
     584,  -652,   123,    46,   515,   517,  -652,   663,  -652,   572,
    3026,   530,   531,  -652,  -652,    41,    55,   124,  -652,   100,
     127,   130,   492,  -652,     9,  -652,  -652,  -652,  -652,  -652,
      10,    14,   658,   476,   480,   593,    11,  -652,  3026,  -652,
    -652,  -652,  -652,   673,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,   195,  -652,  -652,   256,   246,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
     243,     0,  3026,  3026,  3026,  3026,  3026,  -652,   -28,   540,
    3402,  3402,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  3402,  3402,  3402,
       5,  3402,  3402,  3402,  3402,  3402,  3402,  3402,  3402,  3402,
    3402,  3402,   439,   439,   679,   679,  -652,  -652,  -652,  1991,
    -652,  3570,  3570,  3026,   513,  -652,  -652,   513,  -652,   513,
    -652,  -652,  -652,  -652,   101,   134,   585,   683,  -652,   683,
    -652,  -652,    27,   250,  -652,  -652,   213,   680,  -652,   255,
     439,  -652,  3026,   193,  -652,  -652,  -652,   594,   684,  -652,
     684,  -652,  3026,   617,   647,  3026,   648,  3026,   651,   -53,
     618,    -4,   652,   555,   705,   645,   705,  -652,   653,   700,
    3026,   635,   -67,   661,  -652,   714,  -652,  -652,  -652,  -652,
    -652,  -652,  2198,   210,  -652,  -652,  3026,   654,  -652,    28,
      57,  -652,  -652,   699,  -652,  -652,  -652,   717,  -652,   -88,
    3026,  3026,  3026,   242,  3026,  3026,  3026,  3026,  3026,  3026,
    3026,   668,  3026,   592,  -652,   256,   256,   195,  -652,   723,
     726,   195,   728,  -652,   378,  -652,   595,  -652,  -652,  -652,
     489,   706,  -652,  -652,   706,  -652,  3026,   597,  3026,   581,
    -652,  -652,  -652,  -652,  3026,     5,   385,  -652,   500,   390,
     528,   519,  -652,  -652,   535,   389,   307,   307,   -25,   142,
     142,   142,   142,    52,    52,  -652,  -652,  -652,  -652,  -652,
    -652,   451,  -652,  -652,  -652,  -652,   667,  -652,  -652,   237,
    -652,  -652,    67,  -652,  3026,  -652,  -652,  2405,  -652,   605,
     613,  -652,  -652,  -652,  -652,   748,   346,   102,  -652,  -652,
     353,   103,  -652,  -652,  -652,  3026,  2612,   672,   622,   626,
     632,   633,  -652,  3026,   482,  -652,   757,  -652,   764,  3026,
     685,  3026,  3026,   -35,   686,   491,  3026,  -652,   750,   771,
     750,  -652,   705,  -652,  3026,  3026,   696,   504,   657,  -652,
     245,   702,  -652,    24,  -652,  -652,   811,  -652,  -652,  3026,
     802,  -652,  -652,    32,  -652,  -652,  -652,  -652,    77,  -652,
     405,    50,  -652,   664,  3026,  3026,  -652,  -652,  -652,  3026,
    3026,  -652,  -652,  -652,  -652,  -652,  -652,  -652,   547,   681,
     612,  -652,  -652,  -652,  -652,  -652,    36,   195,   497,   104,
     105,     0,  -652,   815,  -652,  -652,  -652,  -652,   270,   796,
    -652,  3026,  -652,  3026,  -652,   263,   687,  -652,  3402,  -652,
    -652,  -652,  -652,  -141,   302,  -652,     5,  -141,  3402,  3402,
     452,  -652,  -652,  -652,  -652,  -652,  -652,  -652,     5,     5,
     302,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,   264,  -652,  -652,
     816,   439,  -652,  3026,  -652,   774,   370,   439,  -652,  -652,
     416,  -652,  -652,   265,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  3026,  -652,  -652,  3026,   743,  3026,
    -652,   768,   828,   822,   750,  -652,  -652,  3026,  -652,  -652,
    -652,  2819,   248,   360,  -652,  -652,   267,   688,   838,  -652,
     839,   125,   836,   707,     7,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  3026,    51,   612,  -652,  -652,  -652,  3402,  3402,
    3402,  3402,   840,   621,   831,  -652,   831,  -652,  -652,   796,
    -652,  -652,  -652,  -652,  -652,  -652,   142,  -652,  -652,  -652,
    -150,   528,  -652,  -652,   310,  3402,  -652,  -652,   519,  -652,
     620,  -652,  -652,   224,   268,  -652,   439,  -652,  -652,   239,
     439,  -652,  -652,  -652,  -652,  -652,  3026,  -652,  3026,  -652,
     705,  -652,  -652,   271,  -652,  -652,   835,   327,  -652,  -652,
    -652,  -652,   716,   461,  -652,  -652,  -652,  -652,   703,   704,
     849,   842,  3026,   852,  3026,  -652,   106,  -652,   142,   142,
     142,   341,   302,  -652,   107,  -652,   109,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,   318,  -652,
    -652,   398,  -652,  -652,   750,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,   708,   439,  -652,   722,  -652,   806,
     769,  3402,   641,   831,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,   727,  3026,   860,  -652,   142,  -652,  -652,  3026,  -652,
     730,  -652,   769,  -652
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     0,     0,   271,   272,   268,   416,     0,   262,   265,
     252,     0,     0,     0,   250,     0,     0,   288,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   251,   254,     0,     0,     0,   294,   260,   290,
       0,     0,     0,   256,   255,     0,     0,     0,     0,   289,
       0,     0,   206,     0,     0,     0,   261,     0,     0,   205,
       0,   264,   263,     0,     0,     0,   253,   235,     0,     0,
     270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     4,     0,     0,     0,     0,    15,    17,
      19,    20,    21,    27,    22,    25,    26,    31,    32,    33,
      28,    29,    35,    36,    23,    30,    24,     9,    94,    95,
      97,     0,   112,   114,   115,    98,    99,   100,   101,   168,
     170,   172,   176,   179,   181,   184,   189,   192,   195,   197,
     199,   201,     0,   203,   209,   211,     0,   231,   210,   238,
     239,   242,   244,     0,   249,   246,     0,   257,   267,   269,
     243,   273,   278,   286,   279,   280,   281,   284,   285,   282,
     283,   301,   303,   304,   305,   302,   348,   349,   350,   351,
     352,   353,   266,   390,   382,   389,   388,   387,   384,   386,
     383,   385,   287,    34,   102,   103,   105,   104,   106,   107,
     359,     0,   355,     0,     0,     0,     0,     0,   400,     0,
     268,   258,     0,   396,    53,    38,    39,    70,    71,     0,
       0,    52,     0,     0,    46,    47,     0,     0,     0,    44,
      45,     0,     0,     0,   392,     0,     0,   291,     0,     0,
     406,     0,     0,     0,   157,     0,   116,   117,     0,    62,
       0,    54,     0,     0,     0,     0,   129,   130,   292,     0,
       0,   391,     0,     0,     0,     0,   397,     0,   234,     0,
       0,     0,     0,   236,   237,     0,     0,     0,   395,     0,
       0,     0,     0,   344,     0,   417,   418,   419,   430,   431,
       0,     0,     0,     0,     0,     0,     0,   436,     0,   483,
     482,   487,   486,     0,   480,   481,   485,   489,   507,   496,
     518,   505,   484,   488,     0,     0,   517,    43,   473,   474,
     475,   476,   477,   478,   479,     1,     3,     5,    10,     8,
      12,    13,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,   212,   226,   217,   216,   224,   215,   214,   213,
     225,   218,   223,   222,   221,   220,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   208,   207,   204,     0,
     232,     0,     0,     0,   245,   275,   248,   247,   259,   274,
     360,   356,   297,   299,     0,     0,     0,     0,   401,     0,
     403,   364,     0,     0,    40,    41,     0,     0,    42,     0,
       0,    67,     0,     0,   354,   393,   394,     0,     0,   407,
       0,   410,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,    55,
       0,     0,     0,     0,   293,     0,   295,   346,   345,   398,
     399,   233,     0,     0,   405,   413,     0,     0,   306,     0,
       0,   314,   363,     0,   296,   227,   343,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   516,     0,     0,   506,   508,     0,
       0,   503,     0,   491,     0,   490,     0,    16,    18,    96,
     141,   137,   139,   108,   138,   136,     0,     0,     0,   169,
     171,   174,   173,   175,     0,     0,     0,   465,   177,   444,
     452,   454,   456,   458,   460,   463,   183,   182,   180,   186,
     187,   188,   185,   190,   191,   194,   193,   381,   380,   374,
     196,   372,   378,   379,   198,   200,   369,   202,   229,     0,
     240,   241,     0,   276,     0,   298,   228,     0,   414,     0,
       0,    50,    51,    48,    49,     0,     0,     0,    88,    37,
       0,     0,   371,    66,    69,     0,     0,   414,     0,     0,
       0,     0,   159,     0,     0,   156,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    64,     0,
      56,    60,     0,   132,     0,     0,     0,     0,     0,   365,
       0,     0,   155,     0,   339,   336,     0,   340,   341,     0,
       0,   342,   335,     0,   312,   338,   337,   307,     0,   315,
       0,     0,   163,     0,     0,     0,   423,   424,   420,     0,
       0,   428,   429,   425,   434,   432,   433,   438,     0,     0,
       0,   515,   514,   509,   510,   512,     0,   504,   499,     0,
       0,    14,   150,     0,   151,   152,   153,   142,   143,   144,
     145,     0,   109,     0,   110,     0,     0,   459,     0,   178,
     472,   520,   519,     0,     0,   521,     0,     0,     0,     0,
     445,   449,   467,   448,   471,   469,   468,   470,     0,     0,
       0,   461,   524,   525,   522,   523,   526,   464,   375,   377,
     376,   373,   370,   230,   277,   300,   361,     0,   402,   404,
      90,     0,    72,     0,    73,     0,     0,     0,    80,    81,
       0,    68,   357,     0,   415,   408,   409,   411,   412,   160,
     158,   127,   128,   121,     0,   123,   120,     0,     0,     0,
     118,     0,     0,    63,    57,   134,   133,     0,   131,    11,
     366,     0,   325,   319,   316,   347,     0,     0,     0,   313,
       0,     0,     0,     0,     0,   164,     7,   421,   422,   426,
     427,   437,     0,     0,   439,   440,   513,   511,     0,     0,
       0,     0,     0,     0,     0,   494,     0,   492,   154,   146,
     147,   148,   140,   111,   466,   462,   541,   540,   539,   535,
       0,   453,   534,   446,     0,     0,   451,   450,   455,   457,
       0,   362,    91,     0,     0,    89,     0,    74,    75,     0,
       0,    82,    83,   358,   125,   122,     0,   124,     0,    59,
       0,   135,   367,     0,   333,   327,     0,   326,   328,   334,
     331,   321,     0,   320,   322,   332,    92,   308,     0,     0,
       0,     0,     0,     0,     0,   435,     0,   441,   528,   529,
     527,     0,   500,   501,     0,   497,     0,   149,   538,   537,
     536,   531,   532,   447,   533,    76,    77,    93,     0,    84,
      85,     0,   126,   167,    65,   368,   318,   329,   330,   317,
     323,   324,   309,   310,     0,     0,   165,     0,   161,     0,
       0,     0,     0,     0,   495,   493,    78,    79,    86,    87,
     311,     0,     0,     0,   442,   530,   502,   498,     0,   162,
       0,   166,     0,   443
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -652,  -652,  -652,   801,   804,  -652,   793,  -652,   563,   568,
    -308,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -418,  -652,  -652,  -652,  -652,  -652,
     490,   177,  -652,  -545,   809,     6,   -80,  -652,  -652,   784,
    -652,  -652,   311,   477,  -235,  -652,  -652,   300,  -652,   571,
     578,   251,  -652,  -652,   253,  -568,  -652,   848,   335,  -652,
    -652,   294,  -652,  -652,   587,   588,   238,  -638,   567,   216,
    -354,   220,   232,  -652,  -652,  -652,  -652,  -652,   790,  -652,
    -652,  -652,  -652,  -652,  -652,   780,  -652,   -41,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,    82,   150,  -652,  -652,   299,
     145,  -652,  -325,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -423,  -652,   306,  -652,   475,  -652,  -652,  -652,
    -652,  -652,    83,    93,  -578,  -437,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,   562,  -223,  -359,  -652,
    -652,   230,  -357,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
     903,   906,    30,   522,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,   295,  -652,  -652,   161,   432,  -652,  -652,   266,
     272,   273,   434,  -652,  -652,   258,  -652,  -480,  -652,  -652,
    -652,  -652,   155,  -306,  -652,   470,   141,  -652,  -443,  -652,
    -652,  -652,  -652,  -651,  -652,  -652,  -652,  -652,   148,   276,
    -652
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   598,   254,   113,   114,   115,   116,
     567,   568,   621,   724,   117,   118,   119,   120,   121,   122,
     123,   246,   247,   429,   430,   124,   256,   257,   338,   339,
     501,   502,   667,   668,   669,   670,   125,   243,   244,   126,
     631,   632,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   357,
     358,   359,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   384,
     385,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     394,   170,   171,   172,   623,   460,   461,   764,   852,   853,
     846,   847,   854,   848,   624,   625,   173,   174,   626,   175,
     176,   177,   178,   179,   180,   181,   545,   413,   540,   711,
     541,   542,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   559,   579,   192,   193,   194,   195,   196,   197,
     198,   296,   297,   199,   784,   785,   518,   690,   519,   520,
     521,   522,   523,   524,   525,   691,   692,   317,   318,   319,
     320,   321,   874,   875,   322,   487,   491,   656,   488,   323,
     324,   694,   707,   793,   695,   696,   701,   697,   881,   809,
     679
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       288,   289,   290,   291,   292,   293,   294,   201,   203,   495,
     529,   530,   531,   532,   544,   543,   543,   206,   600,   423,
     441,   212,   431,   498,   410,   729,   273,   274,   410,     6,
     426,   426,   442,   810,   605,   517,   622,   614,   615,   693,
     233,   614,   615,   469,   653,   769,   238,   473,   282,   820,
     813,   572,   248,   543,   447,   589,   762,   259,    17,   481,
     786,   262,    26,     3,    28,   397,    30,    31,   269,   399,
       4,   210,   616,   747,   424,   457,   616,   457,   277,   332,
     279,   280,   281,   863,    41,    39,   614,   615,   229,   424,
     264,   630,   440,   207,   239,   211,   878,   467,   361,   265,
     800,   801,   879,   427,   592,   807,   418,   617,   379,   618,
     808,   617,   333,   618,   215,   332,    49,   219,   774,   880,
     514,   616,   362,   634,   393,   635,   515,   217,   420,   332,
     506,   230,   213,   216,   614,   615,   561,   220,   332,   332,
     335,    60,   458,   619,   627,   370,   218,   619,   332,   554,
     725,   725,   794,   796,   909,   913,   617,   913,   618,   562,
     234,   332,   332,    65,   371,   864,   332,   332,   270,   616,
      57,   332,   332,   468,    57,   332,   398,   883,   332,   763,
     400,   828,   332,   428,   754,   832,   425,   390,   660,   448,
     517,   517,   619,   769,   590,   787,   594,   428,   620,    71,
     622,   456,   768,    71,   617,   622,   618,   606,   470,   471,
     817,   395,   474,   475,   653,   428,   283,   419,   483,    57,
      70,   912,   472,    77,   714,   482,   476,    77,   459,    89,
     628,   877,   208,   240,   266,   386,   249,   391,   388,   421,
     619,   428,   209,   241,   516,   428,   428,   770,    71,   433,
     444,   844,   499,   500,   503,   500,   505,   614,   332,   463,
     555,   726,   730,   795,   797,   910,   914,    57,   915,   396,
     401,   773,    77,   543,   414,   417,   453,   251,   886,   446,
     462,   492,   410,   464,   890,   332,   465,   574,   485,   565,
     556,   489,   204,   332,   575,   860,    71,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   332,   332,   332,   493,   332,   332,   663,   885,   332,
      77,   252,   368,   205,   806,   849,   855,   617,   214,   618,
     844,   565,   573,   889,   369,   814,   614,   250,   845,   723,
     550,   551,   582,   917,     3,   585,   919,   587,   622,    47,
      48,     4,   210,   498,   723,   665,   666,   422,   748,   563,
     603,   517,   823,   619,   543,   924,   611,   494,   829,   614,
     543,    12,   566,   517,   517,   486,   612,   490,   253,   721,
     364,   221,   564,   850,    16,   549,   727,   933,   222,   552,
     636,   637,   638,   713,   641,   642,   643,   644,   645,   646,
     647,   760,   649,   826,   224,   225,   617,    35,   618,     6,
     849,   365,   916,   492,   570,    41,   855,   897,   223,   804,
     821,   833,   894,   856,   887,   537,   672,   895,   674,   560,
     226,   366,   361,   723,   868,   869,   870,   871,    17,   617,
     722,   618,   619,    79,    12,    45,   659,   728,   578,   830,
     580,   851,   227,   639,   387,   640,   362,    16,   610,   537,
     389,   723,    54,   228,   827,    39,    50,   888,   723,   543,
     614,   891,    89,   543,   715,   619,   367,    58,    12,   231,
      35,   772,   232,   410,   850,   723,   363,   333,    41,   237,
     368,    16,   918,    64,    65,   731,    49,   822,   267,   268,
     514,    70,   369,   739,   261,   334,   515,    73,   242,   743,
     831,   745,   746,   723,    35,   335,   751,   245,   911,   538,
     675,   368,    41,   662,   755,   756,   788,   789,   680,   553,
     255,   723,   553,   369,   553,    54,   663,   790,   791,   260,
     617,   336,   618,   263,   411,   271,   921,   272,   543,   276,
      58,   412,   900,   538,   777,   778,   878,   925,   284,   779,
     780,   664,   879,   717,   381,   382,    64,    65,   278,    54,
     285,   286,   287,   295,   665,   666,   619,   526,   527,   880,
      73,   298,   733,   325,    58,   708,   709,   710,   533,   534,
     680,   500,   330,   803,   331,   511,   512,   513,   539,   332,
      64,    65,   535,   536,   546,   546,   340,   927,   702,   703,
     704,   705,   341,   681,    73,   360,   682,   299,   300,   372,
     301,   302,   683,   684,   685,   766,   651,   652,   374,   383,
     686,   303,   539,   304,   375,   373,   706,   402,   403,   687,
     404,   405,   406,   407,   305,   688,   689,   408,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   409,
     415,   416,   432,   434,   834,   435,   436,   835,   437,   837,
     438,   439,   443,   445,   449,   681,   450,   841,   682,   299,
     300,   451,   301,   302,   683,   684,   685,   452,   466,   454,
     455,   477,   478,   303,   480,   304,   479,   484,   508,   537,
     557,   687,   865,   558,   577,   569,   305,   815,   689,   576,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   788,   789,   584,   586,   583,   591,   588,   595,   824,
     597,   596,   790,   791,   599,   602,   604,   607,   342,   608,
     630,   633,   601,   613,   648,   792,   343,   654,   650,   344,
     655,   345,   658,     1,   671,   673,   892,   678,   893,   661,
       2,     3,   346,   699,   718,   698,   347,   843,     4,     5,
     712,   348,   719,     6,   720,   734,     7,   349,     8,     9,
     700,   735,   906,   741,   908,   736,    10,    11,    12,    13,
     742,   737,   738,   744,   749,    14,   753,   757,   752,   350,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,   761,   765,    32,
      33,   759,   767,    34,    35,    36,    37,    38,   776,    39,
     783,    40,    41,   351,   352,   353,   354,   355,   356,   782,
     798,    42,   929,   663,    43,    44,   805,    45,   931,   410,
     565,   836,   838,   839,    46,    47,    48,   840,   858,   859,
      49,   857,   861,   873,   872,   862,   492,   896,    50,   904,
      51,   899,    52,   884,    53,   905,   902,   903,   907,    54,
     922,   920,   923,   926,   723,   928,   930,   328,    55,   932,
      56,    57,   326,   496,    58,   327,    59,    60,   497,   571,
      61,    62,   825,    63,   329,   337,   750,   758,   593,   507,
      64,    65,    66,   504,    67,    68,    69,   275,    70,   740,
      71,   799,   802,    72,    73,   775,   380,   509,    74,   510,
     528,    75,   378,   866,   771,   629,   901,   547,   235,    76,
     898,   236,   581,   781,    77,   867,    78,   676,   816,    79,
     677,   876,   811,    80,    81,    82,    83,    84,    85,    86,
       1,   657,   882,   812,    87,     0,    88,     2,     3,     0,
     818,     0,   819,     0,     0,     4,     5,     0,    89,     0,
       6,     0,     0,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,     0,    32,    33,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,    41,
       0,     0,     0,     0,     0,     0,     0,     0,    42,     0,
       0,    43,    44,     0,    45,     0,     0,     0,     0,     0,
       0,    46,    47,    48,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,    50,     0,    51,     0,    52,
       0,    53,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    56,    57,     0,
       0,    58,     0,    59,    60,     0,     0,    61,    62,     0,
      63,     0,     0,     0,     0,     0,     0,    64,    65,    66,
       0,    67,    68,    69,     0,    70,     0,    71,     0,     0,
      72,    73,     0,     0,     0,    74,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,    76,     0,     0,     0,
       0,    77,     0,     0,     0,     0,    79,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,     1,     0,     0,
       0,    87,     0,    88,     2,     3,     0,     0,     0,     0,
       0,     0,     4,     5,     0,    89,     0,     6,     0,     0,
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
      59,    60,     0,     0,    61,    62,     0,    63,     0,   200,
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
       0,    61,    62,     0,    63,     0,   202,     0,     0,     0,
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
      41,     0,     0,     0,     0,     0,     0,     0,     0,    42,
       0,     0,    43,    44,     0,    45,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,    50,     0,    51,     0,
      52,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,    56,    57,
       0,     0,    58,     0,    59,    60,     0,     0,    61,    62,
       0,    63,     0,     0,     0,     0,   258,     0,    64,    65,
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
       0,     0,     0,    55,     0,    56,    57,     0,     0,    58,
       0,    59,    60,     0,     0,    61,    62,     0,    63,     0,
       0,     0,     0,   392,     0,    64,    65,    66,     0,    67,
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
       0,     0,    61,    62,     0,    63,     0,   548,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,    55,     0,    56,
      57,     0,     0,    58,     0,    59,    60,     0,     0,    61,
      62,     0,    63,     0,   609,     0,     0,     0,     0,    64,
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
       0,   716,     0,     0,     0,     0,    64,    65,    66,     0,
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
      60,     0,     0,    61,    62,     0,    63,     0,   732,     0,
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
      61,    62,     0,    63,     0,   842,     0,     0,     0,     0,
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
      63,     0,     0,     0,     0,     0,     0,    64,    65,    66,
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
       0,     0,     0,     0,     0,     0,     0,     0,    43,    44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,   376,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    56,    57,     0,     0,    58,     0,
     377,    60,     0,     0,    61,    62,     0,    63,     0,     0,
       0,     0,     0,     0,    64,    65,    66,     0,    67,    68,
       0,     0,    70,     0,    71,     0,     1,    72,    73,     0,
       0,     0,     0,     2,     3,    75,     0,     0,     0,     0,
       0,     4,     5,    76,     0,     0,     6,     0,    77,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    33,     0,     0,    34,    35,    36,    37,
      38,     0,    39,     0,    40,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    43,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    52,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,    56,    57,     0,     0,    58,     0,    59,
      60,     0,     0,    61,    62,     0,    63,     0,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,     0,
       0,    70,     0,    71,     1,     0,    72,    73,     0,     0,
       0,     2,     3,     0,    75,     0,     0,     0,     0,     4,
       5,     0,    76,     0,     6,     0,     0,    77,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
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
       0,     0,     0,     0,     0,     0,    43,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,     0,     0,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
       0,     0,    64,    65,    66,     0,   299,   300,     0,   301,
     302,     0,    71,     0,     0,    72,    73,     0,     0,     0,
     303,     0,   304,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   305,     0,     0,    77,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        80,    81,    82,    83,    84,    85,    86,     1,     2,   315,
     364,   365,   366,   367,   373,   372,   373,    11,   436,   242,
     255,    15,   245,   331,    33,   570,    67,    68,    33,    24,
      35,    35,   255,   684,   101,   360,   459,     9,    10,   519,
      34,     9,    10,    33,   487,   623,    40,    33,    28,   700,
     688,   410,    46,   410,     8,   108,    32,    51,    53,    48,
      24,    55,    62,    12,    64,    48,    66,    67,    15,    48,
      19,    20,    44,   108,    48,    20,    44,    20,    72,    48,
      74,    75,    76,    76,    83,    80,     9,    10,   138,    48,
      15,    41,   101,    20,    20,    13,   246,    88,   123,    24,
     668,   669,   252,   108,   108,   246,    48,    79,   115,    81,
     251,    79,   140,    81,   153,    48,   111,   133,    68,   269,
     115,    44,   147,   211,   204,   213,   121,   153,    48,    48,
     158,   181,   159,   172,     9,    10,   109,   153,    48,    48,
     168,   148,    87,   115,    87,    93,   172,   115,    48,    48,
      48,    48,    48,    48,    48,    48,    79,    48,    81,   132,
     159,    48,    48,   162,   112,   158,    48,    48,   115,    44,
     142,    48,    48,   164,   142,    48,   159,   815,    48,   155,
     159,   726,    48,   250,   602,   730,   160,   156,   494,   143,
     515,   516,   115,   771,   429,   159,   431,   250,   170,   171,
     623,   160,   170,   171,    79,   628,    81,   442,   198,   199,
     690,   205,   198,   199,   657,   250,   196,   159,   298,   142,
     169,   872,   212,   195,   157,   214,   212,   195,   173,   229,
     173,   799,   159,   159,   159,   153,    25,   156,   156,   159,
     115,   250,   169,   169,   239,   250,   250,   170,   171,   159,
     159,     3,   332,   333,   334,   335,   336,     9,    48,   159,
     159,   159,   159,   159,   159,   159,   159,   142,   159,   156,
     156,   630,   195,   630,   156,   156,   270,    25,   823,   156,
     156,    35,    33,   156,   829,    48,   156,    94,    93,    76,
     156,    35,   121,    48,   101,   170,   171,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    48,    48,    48,    68,    48,    48,    47,    94,    48,
     195,    69,   180,   115,   678,   762,   763,    79,    25,    81,
       3,    76,   412,    94,   192,   689,     9,   126,    90,   115,
     381,   382,   422,   888,    12,   425,   891,   427,   771,   106,
     107,    19,    20,   661,   115,    85,    86,   108,   593,   109,
     440,   686,   721,   115,   721,   910,   156,   121,   727,     9,
     727,    39,   159,   698,   699,   180,   456,   121,   126,    33,
      73,    25,   132,    23,    52,   379,    33,   932,   126,   383,
     470,   471,   472,   156,   474,   475,   476,   477,   478,   479,
     480,   156,   482,    33,    85,    86,    79,    75,    81,    24,
     847,   104,    94,    35,   159,    83,   853,    90,   126,   156,
     156,   156,   840,   156,   156,    20,   506,   156,   508,   399,
      20,   124,   123,   115,   788,   789,   790,   791,    53,    79,
      94,    81,   115,   200,    39,    98,    68,    94,   418,    33,
     420,    91,    15,   211,   155,   213,   147,    52,   452,    20,
     161,   115,   130,    20,    94,    80,   119,   826,   115,   826,
       9,   830,   229,   830,   554,   115,   169,   145,    39,    20,
      75,    76,    26,    33,    23,   115,   177,   140,    83,    26,
     180,    52,    94,   161,   162,   575,   111,   720,    20,    21,
     115,   169,   192,   583,   159,   158,   121,   175,    26,   589,
      94,   591,   592,   115,    75,   168,   596,    26,   177,   114,
     514,   180,    83,    34,   604,   605,   224,   225,   138,   384,
      26,   115,   387,   192,   389,   130,    47,   235,   236,    15,
      79,   194,    81,    17,    94,    20,   905,    20,   905,    20,
     145,   101,    91,   114,   634,   635,   246,   911,    24,   639,
     640,    72,   252,   557,   165,   166,   161,   162,   159,   130,
     201,   202,   203,    26,    85,    86,   115,   361,   362,   269,
     175,   115,   576,     0,   145,   134,   135,   136,   368,   369,
     138,   671,   164,   673,   164,   357,   358,   359,   193,    48,
     161,   162,   370,   371,   374,   375,   137,   913,   219,   220,
     221,   222,    31,   223,   175,   238,   226,   227,   228,   110,
     230,   231,   232,   233,   234,   619,   485,   486,    42,   116,
     240,   241,   193,   243,    43,   178,   247,    48,    48,   249,
      25,    25,   121,    89,   254,   255,   256,    24,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   121,
     159,   159,    48,    35,   744,    15,    35,   747,   126,   749,
      15,    25,    48,    89,   159,   223,   159,   757,   226,   227,
     228,    18,   230,   231,   232,   233,   234,   115,   196,   159,
     159,    33,   216,   241,   101,   243,   216,    24,   158,    20,
     115,   249,   782,    20,    20,    25,   254,   255,   256,   115,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   224,   225,    76,    76,   108,   108,    76,    76,   723,
      25,   176,   235,   236,    89,    35,   101,    76,    89,    25,
      41,    24,    89,    89,    76,   248,    97,    24,   156,   100,
      24,   102,    24,     4,    48,   158,   836,   257,   838,   164,
      11,    12,   113,   244,   159,   237,   117,   761,    19,    20,
     103,   122,   159,    24,    26,   103,    27,   128,    29,    30,
     245,   159,   862,    26,   864,   159,    37,    38,    39,    40,
      26,   159,   159,   108,   108,    46,    25,   101,    48,   150,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,   115,     7,    70,
      71,   164,    20,    74,    75,    76,    77,    78,   164,    80,
     218,    82,    83,   184,   185,   186,   187,   188,   189,   158,
      25,    92,   922,    47,    95,    96,   159,    98,   928,    33,
      76,   108,    84,    25,   105,   106,   107,    35,    20,    20,
     111,   173,    26,   242,    24,   158,    35,    32,   119,    20,
     121,   155,   123,   253,   125,    33,   173,   173,    26,   130,
     158,   173,    76,   242,   115,   158,    26,    94,   139,   159,
     141,   142,    91,   330,   145,    91,   147,   148,   330,   409,
     151,   152,   725,   154,    95,   121,   595,   607,   431,   338,
     161,   162,   163,   335,   165,   166,   167,    69,   169,   584,
     171,   668,   671,   174,   175,   631,   146,   340,   179,   341,
     363,   182,   142,   783,   628,   460,   853,   375,    35,   190,
     847,    35,   420,   648,   195,   784,   197,   515,   690,   200,
     516,   796,   686,   204,   205,   206,   207,   208,   209,   210,
       4,   491,   814,   687,   215,    -1,   217,    11,    12,    -1,
     698,    -1,   699,    -1,    -1,    19,    20,    -1,   229,    -1,
      24,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    70,    71,    -1,    -1,
      74,    75,    76,    77,    78,    -1,    80,    -1,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    95,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,   123,
      -1,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,   141,   142,    -1,
      -1,   145,    -1,   147,   148,    -1,    -1,   151,   152,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,   165,   166,   167,    -1,   169,    -1,   171,    -1,    -1,
     174,   175,    -1,    -1,    -1,   179,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,   200,    -1,    -1,    -1,
     204,   205,   206,   207,   208,   209,   210,     4,    -1,    -1,
      -1,   215,    -1,   217,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    -1,   229,    -1,    24,    -1,    -1,
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
      -1,   151,   152,    -1,   154,    -1,   156,    -1,    -1,    -1,
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
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    95,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,   141,   142,
      -1,    -1,   145,    -1,   147,   148,    -1,    -1,   151,   152,
      -1,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,   162,
     163,    -1,   165,   166,   167,    -1,   169,    -1,   171,    -1,
      -1,   174,   175,    -1,    -1,    -1,   179,    -1,    -1,   182,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   205,   206,   207,   208,   209,   210,     4,    -1,
      -1,    -1,   215,    -1,   217,    11,    12,    -1,    -1,    -1,
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
      -1,    -1,    -1,   139,    -1,   141,   142,    -1,    -1,   145,
      -1,   147,   148,    -1,    -1,   151,   152,    -1,   154,    -1,
      -1,    -1,    -1,   159,    -1,   161,   162,   163,    -1,   165,
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
      -1,    -1,   151,   152,    -1,   154,    -1,   156,    -1,    -1,
      -1,    -1,   161,   162,   163,    -1,   165,   166,   167,    -1,
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
     152,    -1,   154,    -1,   156,    -1,    -1,    -1,    -1,   161,
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
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    -1,   141,   142,    -1,    -1,   145,    -1,
     147,   148,    -1,    -1,   151,   152,    -1,   154,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,    -1,   165,   166,
      -1,    -1,   169,    -1,   171,    -1,     4,   174,   175,    -1,
      -1,    -1,    -1,    11,    12,   182,    -1,    -1,    -1,    -1,
      -1,    19,    20,   190,    -1,    -1,    24,    -1,   195,    27,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    -1,    -1,    74,    75,    76,    77,
      78,    -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,
     148,    -1,    -1,   151,   152,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,    -1,   165,   166,    -1,
      -1,   169,    -1,   171,     4,    -1,   174,   175,    -1,    -1,
      -1,    11,    12,    -1,   182,    -1,    -1,    -1,    -1,    19,
      20,    -1,   190,    -1,    24,    -1,    -1,   195,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,   141,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,     4,    -1,    -1,    -1,   169,
      -1,   171,    11,    12,   174,   175,    -1,    -1,    -1,    -1,
      19,    20,   182,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,   195,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,    -1,    -1,
      -1,    -1,   151,   152,    -1,   154,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,    -1,   227,   228,    -1,   230,
     231,    -1,   171,    -1,    -1,   174,   175,    -1,    -1,    -1,
     241,    -1,   243,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,    -1,    -1,   195,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268
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
     302,   303,   304,   307,   308,   309,   310,   315,   316,   317,
     318,   319,   320,   321,   326,   337,   340,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     392,   393,   394,   407,   408,   410,   411,   412,   413,   414,
     415,   416,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   435,   436,   437,   438,   439,   440,   441,   444,
     156,   316,   156,   316,   121,   115,   316,    20,   159,   169,
      20,   376,   316,   159,    25,   153,   172,   153,   172,   133,
     153,    25,   126,   126,    85,    86,    20,    15,    20,   138,
     181,    20,    26,   316,   159,   431,   432,    26,   316,    20,
     159,   169,    26,   338,   339,    26,   322,   323,   316,    25,
     126,    25,    69,   126,   306,    26,   327,   328,   159,   316,
      15,   159,   316,    17,    15,    24,   159,    20,    21,    15,
     115,    20,    20,   368,   368,   338,    20,   316,   159,   316,
     316,   316,    28,   196,    24,   201,   202,   203,   317,   317,
     317,   317,   317,   317,   317,    26,   442,   443,   115,   227,
     228,   230,   231,   241,   243,   254,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   458,   459,   460,
     461,   462,   465,   470,   471,     0,   284,   285,   287,   315,
     164,   164,    48,   140,   158,   168,   194,   320,   329,   330,
     137,    31,    89,    97,   100,   102,   113,   117,   122,   128,
     150,   184,   185,   186,   187,   188,   189,   360,   361,   362,
     238,   123,   147,   177,    73,   104,   124,   169,   180,   192,
      93,   112,   110,   178,    42,    43,   123,   147,   359,   115,
     366,   165,   166,   116,   380,   381,   376,   380,   376,   380,
     156,   156,   159,   317,   391,   316,   156,    48,   159,    48,
     159,   156,    48,    48,    25,    25,   121,    89,    24,   121,
      33,    94,   101,   418,   156,   159,   159,   156,    48,   159,
      48,   159,   108,   418,    48,   160,    35,   108,   250,   324,
     325,   418,    48,   159,    35,    15,    35,   126,    15,    25,
     101,   325,   418,    48,   159,    89,   156,     8,   143,   159,
     159,    18,   115,   316,   159,   159,   160,    20,    87,   173,
     396,   397,   156,   159,   156,   156,   196,    88,   164,    33,
     198,   199,   212,    33,   198,   199,   212,    33,   216,   216,
     101,    48,   214,   317,    24,    93,   180,   466,   469,    35,
     121,   467,    35,    68,   121,   464,   289,   290,   291,   317,
     317,   331,   332,   317,   331,   317,   158,   330,   158,   345,
     346,   347,   347,   347,   115,   121,   239,   383,   447,   449,
     450,   451,   452,   453,   454,   455,   350,   350,   349,   351,
     351,   351,   351,   352,   352,   353,   353,    20,   114,   193,
     419,   421,   422,   423,   419,   417,   422,   417,   156,   316,
     368,   368,   316,   381,    48,   159,   156,   115,    20,   433,
     433,   109,   132,   109,   132,    76,   159,   311,   312,    25,
     159,   311,   419,   317,    94,   101,   115,    20,   433,   434,
     433,   434,   317,   108,    76,   317,    76,   317,    76,   108,
     325,   108,   108,   324,   325,    76,   176,    25,   305,    89,
     305,    89,    35,   317,   101,   101,   325,    76,    25,   156,
     316,   156,   317,    89,     9,    10,    44,    79,    81,   115,
     170,   313,   393,   395,   405,   406,   409,    87,   173,   397,
      41,   341,   342,    24,   211,   213,   317,   317,   317,   211,
     213,   317,   317,   317,   317,   317,   317,   317,    76,   317,
     156,   467,   467,   469,    24,    24,   468,   466,    24,    68,
     464,   164,    34,    47,    72,    85,    86,   333,   334,   335,
     336,    48,   317,   158,   317,   316,   447,   453,   257,   481,
     138,   223,   226,   232,   233,   234,   240,   249,   255,   256,
     448,   456,   457,   458,   472,   475,   476,   478,   237,   244,
     245,   477,   219,   220,   221,   222,   247,   473,   134,   135,
     136,   420,   103,   156,   157,   317,   156,   316,   159,   159,
      26,    33,    94,   115,   314,    48,   159,    33,    94,   314,
     159,   317,   156,   316,   103,   159,   159,   159,   159,   317,
     339,    26,    26,   317,   108,   317,   317,   108,   325,   108,
     323,   317,    48,    25,   305,   317,   317,   101,   328,   164,
     156,   115,    32,   155,   398,     7,   316,    20,   170,   405,
     170,   395,    76,   419,    68,   342,   164,   317,   317,   317,
     317,   443,   158,   218,   445,   446,    24,   159,   224,   225,
     235,   236,   248,   474,    48,   159,    48,   159,    25,   335,
     336,   336,   332,   317,   156,   159,   351,   246,   251,   480,
     474,   450,   480,   348,   351,   255,   456,   458,   451,   452,
     474,   156,   418,   419,   316,   312,    33,    94,   314,   419,
      33,    94,   314,   156,   317,   317,   108,   317,    84,    25,
      35,   317,   156,   316,     3,    90,   401,   402,   404,   406,
      23,    91,   399,   400,   403,   406,   156,   173,    20,    20,
     170,    26,   158,    76,   158,   317,   377,   446,   351,   351,
     351,   351,    24,   242,   463,   464,   463,   336,   246,   252,
     269,   479,   479,   348,   253,    94,   314,   156,   419,    94,
     314,   419,   317,   317,   305,   156,    32,    90,   404,   155,
      91,   403,   173,   173,    20,    33,   317,    26,   317,    48,
     159,   177,   474,    48,   159,   159,    94,   314,    94,   314,
     173,   419,   158,    76,   314,   351,   242,   464,   158,   317,
      26,   317,   159,   314
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
     312,   312,   313,   314,   315,   316,   316,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   318,   318,
     318,   318,   319,   319,   320,   320,   321,   322,   322,   323,
     323,   323,   323,   323,   323,   323,   323,   324,   325,   326,
     327,   327,   328,   328,   328,   328,   329,   330,   330,   331,
     331,   332,   332,   333,   333,   333,   333,   333,   333,   333,
     334,   334,   335,   335,   336,   337,   337,   338,   338,   339,
     339,   340,   340,   341,   341,   342,   342,   343,   344,   344,
     345,   345,   346,   346,   346,   346,   347,   347,   347,   348,
     348,   349,   349,   349,   350,   350,   350,   350,   350,   351,
     351,   351,   352,   352,   352,   353,   353,   354,   354,   355,
     355,   356,   356,   357,   357,   358,   358,   358,   358,   359,
     359,   359,   360,   360,   360,   360,   360,   360,   361,   361,
     361,   361,   361,   361,   362,   362,   362,   363,   363,   364,
     364,   365,   365,   366,   366,   367,   367,   367,   367,   368,
     368,   368,   369,   369,   370,   370,   370,   370,   371,   371,
     372,   372,   372,   372,   372,   372,   372,   373,   373,   374,
     374,   375,   375,   375,   375,   375,   376,   376,   377,   377,
     378,   378,   378,   379,   379,   380,   380,   381,   382,   382,
     382,   382,   382,   382,   382,   382,   383,   383,   384,   384,
     384,   385,   386,   386,   387,   388,   389,   390,   390,   391,
     391,   392,   392,   393,   393,   393,   394,   394,   394,   394,
     394,   394,   395,   395,   396,   396,   397,   398,   398,   399,
     399,   400,   400,   400,   400,   401,   401,   402,   402,   402,
     402,   403,   403,   404,   404,   405,   405,   405,   405,   406,
     406,   406,   406,   407,   407,   408,   408,   409,   410,   410,
     410,   410,   410,   410,   411,   412,   412,   412,   412,   413,
     413,   413,   413,   414,   415,   416,   416,   416,   416,   417,
     417,   418,   419,   419,   419,   420,   420,   420,   421,   421,
     421,   422,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   424,   425,   425,   425,   426,   427,   428,   428,   428,
     429,   429,   429,   429,   429,   430,   431,   431,   431,   431,
     431,   431,   431,   432,   433,   434,   435,   436,   436,   436,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     438,   438,   439,   439,   440,   441,   442,   442,   443,   444,
     445,   445,   446,   446,   447,   447,   447,   447,   448,   448,
     448,   448,   449,   449,   450,   450,   451,   451,   452,   452,
     453,   453,   453,   454,   454,   455,   455,   456,   456,   456,
     456,   456,   457,   458,   458,   458,   458,   458,   458,   458,
     459,   459,   459,   459,   460,   460,   460,   460,   461,   461,
     462,   462,   462,   462,   462,   462,   462,   463,   463,   464,
     464,   464,   464,   465,   465,   465,   465,   465,   466,   466,
     467,   467,   468,   468,   469,   469,   470,   471,   471,   472,
     472,   472,   473,   473,   473,   473,   473,   474,   474,   474,
     474,   475,   476,   477,   478,   478,   479,   479,   479,   480,
     480,   481
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
       4,     5,     1,     2,     1,     1,     2,     1,     4,     3,
       4,     4,     5,     4,     5,     5,     6,     3,     3,     2,
       1,     4,     3,     4,     4,     5,     2,     2,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     2,     2,     3,
       1,     1,     1,     1,     2,     4,     4,     1,     4,     3,
       4,     7,     9,     1,     2,     4,     7,     7,     1,     3,
       1,     3,     1,     3,     3,     3,     1,     3,     4,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     2,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       4,     1,     2,     3,     2,     1,     2,     2,     1,     1,
       3,     3,     1,     1,     1,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     3,     3,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     3,     4,     6,     7,
       7,     8,     1,     2,     1,     2,     3,     3,     3,     0,
       1,     1,     1,     2,     2,     0,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     5,     6,     2,
       3,     5,     6,     3,     3,     4,     5,     6,     7,     1,
       2,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     3,     2,     2,     2,     3,     3,
       2,     3,     5,     3,     5,     3,     2,     3,     5,     5,
       3,     5,     5,     3,     1,     2,     1,     2,     2,     2,
       4,     5,     5,     4,     4,     4,     5,     5,     4,     4,
       2,     2,     4,     4,     4,     6,     1,     4,     3,     5,
       1,     2,     4,     7,     1,     2,     3,     4,     1,     1,
       2,     2,     1,     3,     1,     3,     1,     3,     1,     2,
       1,     2,     3,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     4,     6,     4,     6,     1,     1,     3,     2,
       4,     4,     6,     2,     3,     1,     2,     1,     1,     2,
       2,     3,     1,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       4,     3,     3,     3,     2,     2,     1,     1,     1,     1,
       1,     2
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
  "EnclosedExpr", "NonNodeEnclosedExpr", "QueryBody", "Expr", "ExprSingle",
  "FLWORExpr", "ForLetClauseList", "ForLetClause", "ForClause",
  "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
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
      24,   164,    -1,   287,   315,    -1,   315,    -1,   286,   287,
      -1,   125,    15,    89,    25,   164,    -1,   288,   164,    -1,
     289,   164,    -1,   288,   164,   289,   164,    -1,   290,    -1,
     288,   164,   290,    -1,   291,    -1,   289,   164,   291,    -1,
     292,    -1,   293,    -1,   294,    -1,   296,    -1,   308,    -1,
     310,    -1,   297,    -1,   298,    -1,   295,    -1,   302,    -1,
     303,    -1,   309,    -1,   299,    -1,   300,    -1,   301,    -1,
     436,    -1,   304,    -1,   307,    -1,    63,    15,    89,    25,
      -1,    55,   153,    -1,    55,   172,    -1,    59,   126,    25,
      -1,    60,   126,    25,    -1,    64,    20,    24,    -1,   229,
     458,    -1,    65,   138,    -1,    65,   181,    -1,    61,    85,
      -1,    61,    86,    -1,    57,   153,    48,   109,    -1,    57,
     153,    48,   132,    -1,    57,   133,    48,   109,    -1,    57,
     133,    48,   132,    -1,    58,    25,    -1,    54,    25,    -1,
     107,    25,    -1,   107,   306,    25,    -1,   107,    25,    35,
     305,    -1,   107,   306,    25,    35,   305,    -1,    25,    -1,
     305,    48,    25,    -1,   126,    15,    89,    -1,    69,   126,
      -1,   106,    25,    -1,   106,   126,    15,    89,    25,    -1,
     106,    25,    35,   305,    -1,   106,   126,    15,    89,    25,
      35,   305,    -1,    67,    26,   101,   317,    -1,    67,    26,
      94,    -1,    67,    26,   418,   101,   317,    -1,    67,    26,
     418,    94,    -1,    56,   153,    -1,    56,   172,    -1,    62,
      20,   121,   159,    94,    -1,    62,    20,   121,   159,   314,
      -1,    62,    20,   121,   311,   159,    94,    -1,    62,    20,
     121,   311,   159,   314,    -1,    62,    20,   121,   159,    33,
     419,    94,    -1,    62,    20,   121,   159,    33,   419,   314,
      -1,    62,    20,   121,   311,   159,    33,   419,    94,    -1,
      62,    20,   121,   311,   159,    33,   419,   314,    -1,    66,
      20,   121,   159,    94,    -1,    66,    20,   121,   159,   314,
      -1,    66,    20,   121,   311,   159,    94,    -1,    66,    20,
     121,   311,   159,   314,    -1,    66,    20,   121,   159,    33,
     419,    94,    -1,    66,    20,   121,   159,    33,   419,   314,
      -1,    66,    20,   121,   311,   159,    33,   419,    94,    -1,
      66,    20,   121,   311,   159,    33,   419,   314,    -1,   312,
      -1,   311,    48,   312,    -1,    76,    26,    -1,    76,    26,
     418,    -1,   115,   316,   156,    -1,   115,   316,   156,    -1,
     316,    -1,   317,    -1,   316,    48,   317,    -1,   318,    -1,
     337,    -1,   340,    -1,   343,    -1,   344,    -1,   437,    -1,
     438,    -1,   440,    -1,   439,    -1,   441,    -1,   444,    -1,
     319,   158,   317,    -1,   319,   329,   158,   317,    -1,   319,
     330,   158,   317,    -1,   319,   329,   330,   158,   317,    -1,
     320,    -1,   319,   320,    -1,   321,    -1,   326,    -1,    98,
     322,    -1,   323,    -1,   322,    48,    76,   323,    -1,    26,
     108,   317,    -1,    26,   418,   108,   317,    -1,    26,   324,
     108,   317,    -1,    26,   418,   324,   108,   317,    -1,    26,
     325,   108,   317,    -1,    26,   418,   325,   108,   317,    -1,
      26,   324,   325,   108,   317,    -1,    26,   418,   324,   325,
     108,   317,    -1,    35,    76,    26,    -1,   250,    76,    26,
      -1,   119,   327,    -1,   328,    -1,   327,    48,    76,   328,
      -1,    26,   101,   317,    -1,    26,   418,   101,   317,    -1,
      26,   325,   101,   317,    -1,    26,   418,   325,   101,   317,
      -1,   194,   317,    -1,   140,   331,    -1,   168,   331,    -1,
     332,    -1,   331,    48,   332,    -1,   317,    -1,   317,   333,
      -1,   334,    -1,   335,    -1,   336,    -1,   334,   335,    -1,
     334,   336,    -1,   335,   336,    -1,   334,   335,   336,    -1,
      34,    -1,    72,    -1,    85,    -1,    86,    -1,    47,    25,
      -1,   167,   338,   160,   317,    -1,    92,   338,   160,   317,
      -1,   339,    -1,   338,    48,    76,   339,    -1,    26,   108,
     317,    -1,    26,   418,   108,   317,    -1,   179,   316,   159,
     341,    68,   158,   317,    -1,   179,   316,   159,   341,    68,
      76,    26,   158,   317,    -1,   342,    -1,   341,   342,    -1,
      41,   419,   158,   317,    -1,    41,    76,    26,    33,   419,
     158,   317,    -1,   105,   316,   159,   176,   317,    84,   317,
      -1,   345,    -1,   344,   137,   345,    -1,   346,    -1,   345,
      31,   346,    -1,   347,    -1,   347,   361,   347,    -1,   347,
     360,   347,    -1,   347,   362,   347,    -1,   348,    -1,   348,
     238,   447,    -1,   348,   238,   447,   481,    -1,   349,    -1,
     349,   177,   349,    -1,   350,    -1,   349,   147,   350,    -1,
     349,   123,   350,    -1,   351,    -1,   350,   169,   351,    -1,
     350,    73,   351,    -1,   350,   104,   351,    -1,   350,   124,
     351,    -1,   352,    -1,   351,   180,   352,    -1,   351,   192,
     352,    -1,   353,    -1,   352,   112,   353,    -1,   352,    93,
     353,    -1,   354,    -1,   354,   110,   419,    -1,   355,    -1,
     355,   178,   419,    -1,   356,    -1,   356,    42,   417,    -1,
     357,    -1,   357,    43,   417,    -1,   359,    -1,   358,   359,
      -1,   147,    -1,   123,    -1,   358,   147,    -1,   358,   123,
      -1,   363,    -1,   367,    -1,   364,    -1,    89,    -1,   128,
      -1,   122,    -1,   117,    -1,   102,    -1,   100,    -1,   184,
      -1,   189,    -1,   188,    -1,   187,    -1,   186,    -1,   185,
      -1,   113,    -1,   150,    -1,    97,    -1,   190,   316,   156,
      -1,    27,   115,   316,   156,    -1,   365,   115,   156,    -1,
     365,   115,   316,   156,    -1,   366,    -1,   365,   366,    -1,
     148,    20,    18,    -1,   148,    21,    -1,   165,    -1,   165,
     368,    -1,   166,   368,    -1,   368,    -1,   369,    -1,   369,
     165,   368,    -1,   369,   166,   368,    -1,   370,    -1,   379,
      -1,   371,    -1,   371,   380,    -1,   374,    -1,   374,   380,
      -1,   372,   376,    -1,   373,    -1,    46,    -1,    70,    -1,
      37,    -1,   163,    -1,    71,    -1,    96,    -1,    95,    -1,
     376,    -1,    40,   376,    -1,   375,   376,    -1,    78,    -1,
     141,    -1,    29,    -1,   152,    -1,   151,    -1,    30,    -1,
     423,    -1,   377,    -1,    20,    -1,   378,    -1,   169,    -1,
      12,    -1,    19,    -1,   382,    -1,   382,   380,    -1,   381,
      -1,   380,   381,    -1,   116,   316,   157,    -1,   383,    -1,
     385,    -1,   386,    -1,   387,    -1,   390,    -1,   392,    -1,
     388,    -1,   389,    -1,   384,    -1,   435,    -1,    53,    -1,
     111,    -1,    80,    -1,    76,    26,    -1,   121,   159,    -1,
     121,   316,   159,    -1,    77,    -1,   139,   316,   156,    -1,
     182,   316,   156,    -1,    20,   121,   159,    -1,    20,   121,
     391,   159,    -1,   317,    -1,   391,    48,   317,    -1,   393,
      -1,   410,    -1,   394,    -1,   407,    -1,   408,    -1,   171,
      20,    87,    -1,   171,    20,   396,    87,    -1,   171,    20,
     173,   170,    20,   173,    -1,   171,    20,   173,   395,   170,
      20,   173,    -1,   171,    20,   396,   173,   170,    20,   173,
      -1,   171,    20,   396,   173,   395,   170,    20,   173,    -1,
     405,    -1,   395,   405,    -1,   397,    -1,   396,   397,    -1,
      20,    89,   398,    -1,   155,   399,   155,    -1,    32,   401,
      32,    -1,    -1,   400,    -1,    91,    -1,   403,    -1,   400,
      91,    -1,   400,   403,    -1,    -1,   402,    -1,    90,    -1,
     404,    -1,   402,    90,    -1,   402,   404,    -1,    23,    -1,
     406,    -1,     3,    -1,   406,    -1,   393,    -1,    10,    -1,
     409,    -1,   406,    -1,     9,    -1,    79,    -1,    81,    -1,
     313,    -1,   195,    28,   196,    -1,   195,   196,    -1,   142,
      17,   143,    -1,   142,    17,     8,    -1,    44,     7,    -1,
     411,    -1,   412,    -1,   413,    -1,   414,    -1,   415,    -1,
     416,    -1,    74,   316,   156,    -1,    11,   156,    -1,    11,
     316,   156,    -1,    82,   316,   156,   115,   156,    -1,    82,
     316,   156,   115,   316,   156,    -1,     4,   156,    -1,     4,
     316,   156,    -1,    38,   316,   156,   115,   156,    -1,    38,
     316,   156,   115,   316,   156,    -1,   174,   316,   156,    -1,
      51,   316,   156,    -1,   154,    15,   115,   156,    -1,   154,
      15,   115,   316,   156,    -1,   154,   115,   316,   156,   115,
     156,    -1,   154,   115,   316,   156,   115,   316,   156,    -1,
     422,    -1,   422,   103,    -1,    33,   419,    -1,   421,    -1,
     421,   420,    -1,   193,    -1,   134,    -1,   136,    -1,   135,
      -1,   422,    -1,   423,    -1,   114,    -1,    20,    -1,   425,
      -1,   431,    -1,   429,    -1,   432,    -1,   430,    -1,   428,
      -1,   427,    -1,   426,    -1,   424,    -1,   130,   159,    -1,
      75,   159,    -1,    75,   431,   159,    -1,    75,   432,   159,
      -1,   175,   159,    -1,    52,   159,    -1,   145,   159,    -1,
     145,    15,   159,    -1,   145,    24,   159,    -1,    39,   159,
      -1,    39,    20,   159,    -1,    39,    20,    48,   433,   159,
      -1,    39,   169,   159,    -1,    39,   169,    48,   433,   159,
      -1,   161,    20,   159,    -1,    83,   159,    -1,    83,    20,
     159,    -1,    83,    20,    48,   433,   159,    -1,    83,    20,
      48,   434,   159,    -1,    83,   169,   159,    -1,    83,   169,
      48,   433,   159,    -1,    83,   169,    48,   434,   159,    -1,
     162,    20,   159,    -1,    20,    -1,    20,   103,    -1,    24,
      -1,   200,   201,    -1,   200,   202,    -1,   200,   203,    -1,
     206,   317,   212,   317,    -1,   206,   317,    33,   211,   317,
      -1,   206,   317,    33,   213,   317,    -1,   206,   317,   198,
     317,    -1,   206,   317,   199,   317,    -1,   207,   317,   212,
     317,    -1,   207,   317,    33,   211,   317,    -1,   207,   317,
      33,   213,   317,    -1,   207,   317,   198,   317,    -1,   207,
     317,   199,   317,    -1,   204,   317,    -1,   205,   317,    -1,
     209,   317,   216,   317,    -1,   210,   317,   216,   317,    -1,
     208,   317,    33,   317,    -1,   215,   442,   214,   317,   158,
     317,    -1,   443,    -1,   442,    48,    76,   443,    -1,    26,
     101,   317,    -1,   217,   115,   317,   156,   445,    -1,   446,
      -1,   445,   446,    -1,   218,   377,   159,   314,    -1,   218,
     377,    48,    76,    26,   159,   314,    -1,   449,    -1,   449,
     448,    -1,   449,   255,   348,    -1,   449,   448,   255,   348,
      -1,   458,    -1,   456,    -1,   448,   458,    -1,   448,   456,
      -1,   450,    -1,   449,   240,   450,    -1,   451,    -1,   450,
     237,   451,    -1,   452,    -1,   451,   244,   452,    -1,   453,
      -1,   239,   453,    -1,   454,    -1,   454,   477,    -1,   121,
     447,   159,    -1,   455,    -1,   455,   473,    -1,   383,    -1,
     115,   316,   156,    -1,   457,    -1,   476,    -1,   475,    -1,
     478,    -1,   472,    -1,   138,    -1,   459,    -1,   460,    -1,
     461,    -1,   462,    -1,   465,    -1,   470,    -1,   471,    -1,
     243,    -1,   254,    -1,   228,    -1,   227,    -1,   264,    -1,
     258,    -1,   231,    -1,   230,    -1,   265,    -1,   259,    -1,
     267,   464,    -1,   267,    68,    -1,   267,   121,   464,   159,
      -1,   267,   121,   464,    48,   463,   159,    -1,   267,   121,
      68,   159,    -1,   267,   121,    68,    48,   463,   159,    -1,
     261,    -1,   464,    -1,   463,    48,   464,    -1,    35,    24,
      -1,    35,    24,   248,    24,    -1,    35,    24,   474,   242,
      -1,    35,    24,   248,    24,   474,   242,    -1,   266,   467,
      -1,   266,   467,   466,    -1,   263,    -1,   263,   466,    -1,
     260,    -1,   469,    -1,   466,   469,    -1,    35,    24,    -1,
     121,   468,   159,    -1,    24,    -1,   468,    24,    -1,   180,
     467,    -1,    93,   467,    -1,   241,    24,    -1,   268,    -1,
     262,    -1,   226,    -1,   223,    -1,   234,    -1,   221,    -1,
     222,    -1,   219,    -1,   220,    -1,   247,    -1,   235,   351,
      -1,   224,   351,    -1,   225,   351,    -1,   236,   351,   177,
     351,    -1,   233,   474,   479,    -1,   256,   351,   479,    -1,
     245,   474,   253,    -1,   249,   480,    -1,   232,   480,    -1,
     269,    -1,   252,    -1,   246,    -1,   251,    -1,   246,    -1,
     257,   351,    -1
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
     419,   424,   430,   432,   435,   437,   439,   442,   444,   449,
     453,   458,   463,   469,   474,   480,   486,   493,   497,   501,
     504,   506,   511,   515,   520,   525,   531,   534,   537,   540,
     542,   546,   548,   551,   553,   555,   557,   560,   563,   566,
     570,   572,   574,   576,   578,   581,   586,   591,   593,   598,
     602,   607,   615,   625,   627,   630,   635,   643,   651,   653,
     657,   659,   663,   665,   669,   673,   677,   679,   683,   688,
     690,   694,   696,   700,   704,   706,   710,   714,   718,   722,
     724,   728,   732,   734,   738,   742,   744,   748,   750,   754,
     756,   760,   762,   766,   768,   771,   773,   775,   778,   781,
     783,   785,   787,   789,   791,   793,   795,   797,   799,   801,
     803,   805,   807,   809,   811,   813,   815,   817,   821,   826,
     830,   835,   837,   840,   844,   847,   849,   852,   855,   857,
     859,   863,   867,   869,   871,   873,   876,   878,   881,   884,
     886,   888,   890,   892,   894,   896,   898,   900,   902,   905,
     908,   910,   912,   914,   916,   918,   920,   922,   924,   926,
     928,   930,   932,   934,   936,   939,   941,   944,   948,   950,
     952,   954,   956,   958,   960,   962,   964,   966,   968,   970,
     972,   974,   977,   980,   984,   986,   990,   994,   998,  1003,
    1005,  1009,  1011,  1013,  1015,  1017,  1019,  1023,  1028,  1035,
    1043,  1051,  1060,  1062,  1065,  1067,  1070,  1074,  1078,  1082,
    1083,  1085,  1087,  1089,  1092,  1095,  1096,  1098,  1100,  1102,
    1105,  1108,  1110,  1112,  1114,  1116,  1118,  1120,  1122,  1124,
    1126,  1128,  1130,  1132,  1136,  1139,  1143,  1147,  1150,  1152,
    1154,  1156,  1158,  1160,  1162,  1166,  1169,  1173,  1179,  1186,
    1189,  1193,  1199,  1206,  1210,  1214,  1219,  1225,  1232,  1240,
    1242,  1245,  1248,  1250,  1253,  1255,  1257,  1259,  1261,  1263,
    1265,  1267,  1269,  1271,  1273,  1275,  1277,  1279,  1281,  1283,
    1285,  1287,  1290,  1293,  1297,  1301,  1304,  1307,  1310,  1314,
    1318,  1321,  1325,  1331,  1335,  1341,  1345,  1348,  1352,  1358,
    1364,  1368,  1374,  1380,  1384,  1386,  1389,  1391,  1394,  1397,
    1400,  1405,  1411,  1417,  1422,  1427,  1432,  1438,  1444,  1449,
    1454,  1457,  1460,  1465,  1470,  1475,  1482,  1484,  1489,  1493,
    1499,  1501,  1504,  1509,  1517,  1519,  1522,  1526,  1531,  1533,
    1535,  1538,  1541,  1543,  1547,  1549,  1553,  1555,  1559,  1561,
    1564,  1566,  1569,  1573,  1575,  1578,  1580,  1584,  1586,  1588,
    1590,  1592,  1594,  1596,  1598,  1600,  1602,  1604,  1606,  1608,
    1610,  1612,  1614,  1616,  1618,  1620,  1622,  1624,  1626,  1628,
    1630,  1633,  1636,  1641,  1648,  1653,  1660,  1662,  1664,  1668,
    1671,  1676,  1681,  1688,  1691,  1695,  1697,  1700,  1702,  1704,
    1707,  1710,  1714,  1716,  1719,  1722,  1725,  1728,  1730,  1732,
    1734,  1736,  1738,  1740,  1742,  1744,  1746,  1748,  1751,  1754,
    1757,  1762,  1766,  1770,  1774,  1777,  1780,  1782,  1784,  1786,
    1788,  1790
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   742,   742,   750,   758,   765,   778,   786,   799,   809,
     824,   839,   854,   863,   872,   887,   896,   913,   922,   939,
     946,   953,   960,   972,   979,   986,   995,  1008,  1015,  1022,
    1029,  1036,  1043,  1050,  1059,  1072,  1079,  1097,  1112,  1120,
    1134,  1143,  1158,  1174,  1188,  1196,  1211,  1219,  1233,  1242,
    1251,  1260,  1282,  1296,  1310,  1320,  1330,  1340,  1356,  1365,
    1383,  1390,  1403,  1412,  1422,  1431,  1448,  1458,  1468,  1478,
    1494,  1502,  1516,  1526,  1537,  1548,  1560,  1572,  1584,  1596,
    1608,  1618,  1629,  1640,  1652,  1664,  1676,  1688,  1706,  1717,
    1734,  1743,  1758,  1769,  1783,  1797,  1806,  1821,  1828,  1835,
    1842,  1849,  1858,  1865,  1872,  1879,  1886,  1893,  1906,  1916,
    1927,  1938,  1955,  1964,  1979,  1986,  1999,  2013,  2022,  2039,
    2049,  2060,  2072,  2085,  2096,  2108,  2120,  2138,  2153,  2167,
    2182,  2191,  2208,  2219,  2231,  2242,  2260,  2274,  2282,  2297,
    2306,  2323,  2332,  2347,  2357,  2367,  2377,  2387,  2397,  2407,
    2423,  2430,  2443,  2451,  2465,  2479,  2489,  2505,  2515,  2530,
    2539,  2555,  2565,  2582,  2591,  2606,  2615,  2631,  2645,  2652,
    2666,  2673,  2695,  2702,  2713,  2724,  2741,  2748,  2758,  2774,
    2781,  2795,  2802,  2809,  2822,  2829,  2836,  2843,  2850,  2863,
    2870,  2878,  2892,  2899,  2906,  2919,  2926,  2941,  2948,  2963,
    2970,  2985,  2992,  3007,  3014,  3029,  3036,  3043,  3050,  3065,
    3072,  3079,  3093,  3100,  3107,  3114,  3121,  3128,  3141,  3148,
    3155,  3162,  3169,  3176,  3189,  3196,  3203,  3217,  3224,  3239,
    3248,  3263,  3272,  3289,  3298,  3340,  3347,  3354,  3361,  3375,
    3383,  3390,  3403,  3410,  3423,  3432,  3441,  3450,  3465,  3474,
    3488,  3495,  3502,  3509,  3516,  3523,  3530,  3543,  3550,  3563,
    3572,  3587,  3594,  3601,  3608,  3615,  3633,  3640,  3653,  3660,
    3673,  3683,  3693,  3709,  3716,  3731,  3740,  3757,  3771,  3778,
    3785,  3792,  3799,  3806,  3813,  3820,  3833,  3840,  3853,  3861,
    3869,  3883,  3896,  3903,  3917,  3930,  3944,  4003,  4012,  4027,
    4036,  4051,  4058,  4071,  4078,  4085,  4098,  4109,  4120,  4131,
    4142,  4153,  4171,  4180,  4195,  4204,  4221,  4236,  4244,  4259,
    4265,  4272,  4281,  4290,  4301,  4319,  4325,  4332,  4341,  4350,
    4361,  4378,  4386,  4400,  4408,  4422,  4430,  4438,  4447,  4462,
    4471,  4479,  4487,  4501,  4509,  4527,  4535,  4555,  4573,  4580,
    4587,  4594,  4601,  4608,  4621,  4635,  4644,  4653,  4661,  4689,
    4698,  4707,  4715,  4729,  4743,  4757,  4766,  4775,  4783,  4797,
    4806,  4821,  4835,  4844,  4853,  4893,  4901,  4909,  4923,  4930,
    4937,  4950,  4964,  4971,  4978,  4985,  4992,  4999,  5006,  5013,
    5020,  5033,  5046,  5053,  5061,  5075,  5088,  5101,  5108,  5115,
    5128,  5137,  5146,  5155,  5164,  5179,  5193,  5202,  5211,  5220,
    5229,  5239,  5249,  5265,  5289,  5299,  5322,  5365,  5373,  5379,
    5390,  5399,  5408,  5417,  5426,  5436,  5445,  5454,  5463,  5472,
    5487,  5495,  5508,  5517,  5532,  5561,  5575,  5582,  5598,  5615,
    5625,  5635,  5649,  5659,  5682,  5688,  5694,  5700,  5712,  5718,
    5724,  5730,  5742,  5748,  5760,  5766,  5778,  5784,  5796,  5802,
    5814,  5820,  5826,  5838,  5844,  5856,  5862,  5874,  5880,  5886,
    5892,  5898,  5910,  5922,  5929,  5936,  5943,  5950,  5957,  5964,
    5977,  5983,  5989,  5995,  6007,  6013,  6019,  6025,  6037,  6043,
    6055,  6061,  6067,  6073,  6079,  6085,  6091,  6103,  6109,  6121,
    6127,  6133,  6139,  6151,  6157,  6163,  6169,  6175,  6187,  6193,
    6205,  6211,  6223,  6229,  6241,  6247,  6259,  6271,  6277,  6289,
    6295,  6301,  6313,  6319,  6325,  6331,  6337,  6349,  6356,  6363,
    6370,  6383,  6395,  6407,  6419,  6425,  6437,  6443,  6449,  6461,
    6467,  6479
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
  const int xquery_parser::yylast_ = 3937;
  const int xquery_parser::yynnts_ = 201;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 325;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 281;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 535;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 6489 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"



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

