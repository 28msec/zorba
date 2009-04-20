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
#line 885 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 51 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"

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
        case 108: /* "\"'DECIMAL'\"" */
#line 769 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 120: /* "\"'DOUBLE'\"" */
#line 768 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 144: /* "\"'INTEGER'\"" */
#line 767 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "VersionDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 226 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "MainModule" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 231 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "LibraryModule" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 236 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "ModuleDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 241 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "Prolog" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 246 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "SIND_DeclList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 251 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "VFO_DeclList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 256 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "SIND_Decl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 261 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "VFO_Decl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 266 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "Setter" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 271 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "Import" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 276 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "NamespaceDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 281 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "BoundarySpaceDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 286 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "DefaultNamespaceDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 291 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "OptionDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 296 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "OrderingModeDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 301 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "EmptyOrderDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 306 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "CopyNamespacesDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 311 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "DefaultCollationDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 316 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "BaseURIDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 321 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "SchemaImport" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 326 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "URILiteralList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 331 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "SchemaPrefix" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 336 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "ModuleImport" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 341 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "CtxItemDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 346 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "CtxItemDecl2" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 351 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "CtxItemDecl3" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 356 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "CtxItemDecl4" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 361 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "VarNameAndType" */
#line 781 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };
#line 366 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "VarDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 371 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "IndexDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 376 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "IndexDecl2" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 381 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "IndexDecl3" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 386 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "IndexDeclSuffix" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 391 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "IndexField" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 396 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "IndexField1" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 401 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "IndexFieldList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 406 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "ConstructionDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 411 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "FunctionSig" */
#line 781 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 416 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BlockExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 421 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "Block" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 426 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BlockDecls" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 431 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "BlockVarDeclList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 436 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "BlockVarDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 441 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "AssignExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 446 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "ExitExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 451 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "WhileExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 456 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "FlowCtlStatement" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 461 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "IndexStatement" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 466 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "FunctionDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 471 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "FunctionDecl2" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 476 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "FunctionDecl3" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 481 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "FunctionDecl4" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 486 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "ParamList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 491 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "Param" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 496 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "EnclosedExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 501 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "BracedExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 506 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "QueryBody" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 511 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "Expr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 516 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "ApplyExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 521 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "ConcatExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 526 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "ExprSingle" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 531 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FLWORExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 536 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ReturnExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 541 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FLWORWinCond" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 546 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "WindowClause" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 551 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "CountClause" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 556 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "ForLetWinClause" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 561 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FLWORClauseList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 566 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "ForClause" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 571 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "VarInDeclList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 576 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "VarInDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 581 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "PositionalVar" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 586 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "LetClause" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 591 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "VarGetsDeclList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 596 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "EvalVarDeclList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 601 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "VarGetsDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 606 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "WindowVarDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 611 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "WindowVars" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 616 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "WindowVars3" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 621 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "WindowVars2" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 626 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "EvalVarDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 631 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "WhereClause" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 636 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "GroupByClause" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 641 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "GroupSpecList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 646 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "GroupSpec" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 651 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "GroupCollationSpec" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 656 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "OrderByClause" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 661 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "OrderSpecList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 666 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "OrderSpec" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 671 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "OrderModifier" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 676 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "OrderDirSpec" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 681 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "OrderEmptySpec" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 686 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "OrderCollationSpec" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 691 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "QuantifiedExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 696 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "QVarInDeclList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 701 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "QVarInDecl" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 706 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "TypeswitchExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 711 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "CaseClauseList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 716 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CaseClause" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 721 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "IfExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 726 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "OrExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 731 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "AndExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 736 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ComparisonExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 741 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "FTContainsExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 746 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "RangeExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 751 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "AdditiveExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 756 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "MultiplicativeExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 761 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "UnionExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 766 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "IntersectExceptExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 771 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "InstanceofExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 776 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "TreatExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 781 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "CastableExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 786 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "CastExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 791 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "UnaryExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 796 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "SignList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 801 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "ValueExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 806 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "ValueComp" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 811 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "NodeComp" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 816 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "ValidateExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 821 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "ExtensionExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 826 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "PragmaList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 831 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "Pragma" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 836 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "PathExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 841 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "RelativePathExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 846 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "StepExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 851 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "AxisStep" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 856 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "ForwardStep" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 861 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "ForwardAxis" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 866 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "AbbrevForwardStep" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 871 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "ReverseStep" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 876 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "ReverseAxis" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 881 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "NodeTest" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 886 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "NameTest" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 891 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "Wildcard" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 896 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "FilterExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 901 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "PredicateList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 906 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "Predicate" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 911 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "PrimaryExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 916 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "Literal" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 921 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "NumericLiteral" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 926 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "VarRef" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 931 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ParenthesizedExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 936 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ContextItemExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 941 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "OrderedExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 946 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "UnorderedExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 951 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "FunctionCall" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 956 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ArgList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 961 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "Constructor" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 966 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "DirectConstructor" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 971 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "DirElemConstructor" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 976 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "DirElemContentList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 981 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "DirAttributeList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 986 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "DirAttr" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 991 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "DirAttributeValue" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 996 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "Opt_QuoteAttrContentList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1001 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "QuoteAttrContentList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1006 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "Opt_AposAttrContentList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1011 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "AposAttrContentList" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1016 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "QuoteAttrValueContent" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1021 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "AposAttrValueContent" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1026 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "DirElemContent" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1031 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "CommonContent" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1036 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "DirCommentConstructor" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1041 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "DirPIConstructor" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1046 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "CDataSection" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1051 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "ComputedConstructor" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1056 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "CompDocConstructor" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1061 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "CompElemConstructor" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1066 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "CompAttrConstructor" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1071 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "CompTextConstructor" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1076 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "CompCommentConstructor" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1081 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "CompPIConstructor" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1086 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "SingleType" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1091 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "TypeDeclaration" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1096 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "SequenceType" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1101 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "OccurrenceIndicator" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1106 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ItemType" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1111 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "AtomicType" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1116 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "KindTest" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1121 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "AnyKindTest" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1126 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DocumentTest" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1131 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "TextTest" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1136 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "CommentTest" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1141 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "PITest" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1146 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "AttributeTest" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1151 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "SchemaAttributeTest" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1156 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ElementTest" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1161 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "SchemaElementTest" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1166 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "TypeName" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1171 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "TypeName_WITH_HOOK" */
#line 777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1176 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "StringLiteral" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1181 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "InsertExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1186 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DeleteExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1191 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "ReplaceExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1196 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "RenameExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1201 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "TransformExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1206 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "VarNameList" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1211 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "VarNameDecl" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1216 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "TryExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1221 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "CatchListExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1226 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "CatchExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1231 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "EvalExpr" */
#line 779 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1236 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 113 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}
  /* Line 547 of yacc.c.  */
#line 1317 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
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
#line 903 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 4:
#line 913 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 918 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 924 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 7:
#line 929 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 8:
#line 941 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		;}
    break;

  case 9:
#line 946 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    ;}
    break;

  case 10:
#line 956 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 11:
#line 963 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		;}
    break;

  case 12:
#line 975 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 13:
#line 987 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), 
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
		;}
    break;

  case 14:
#line 999 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 15:
#line 1005 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 16:
#line 1011 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 17:
#line 1023 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 18:
#line 1029 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 1043 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 20:
#line 1049 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 32:
#line 1089 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
    ;}
    break;

  case 33:
#line 1093 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), (yysemantic_stack_[(4) - (4)].pair_vector)); 
    ;}
    break;

  case 34:
#line 1100 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
    ;}
    break;

  case 35:
#line 1105 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    ;}
    break;

  case 36:
#line 1113 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr))->get_strval());
    ;}
    break;

  case 37:
#line 1119 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; ;}
    break;

  case 38:
#line 1120 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; ;}
    break;

  case 39:
#line 1121 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; ;}
    break;

  case 40:
#line 1122 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; ;}
    break;

  case 41:
#line 1123 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; ;}
    break;

  case 42:
#line 1124 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; ;}
    break;

  case 43:
#line 1125 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; ;}
    break;

  case 44:
#line 1126 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; ;}
    break;

  case 45:
#line 1127 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; ;}
    break;

  case 46:
#line 1128 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; ;}
    break;

  case 57:
#line 1165 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 58:
#line 1177 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 59:
#line 1182 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 60:
#line 1193 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 61:
#line 1199 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 62:
#line 1211 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 63:
#line 1224 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		;}
    break;

  case 64:
#line 1235 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 65:
#line 1240 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 66:
#line 1252 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 67:
#line 1257 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 68:
#line 1268 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 69:
#line 1274 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 70:
#line 1280 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 71:
#line 1286 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 72:
#line 1305 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 73:
#line 1316 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 74:
#line 1327 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 75:
#line 1334 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		;}
    break;

  case 76:
#line 1341 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 77:
#line 1348 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 78:
#line 1361 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 79:
#line 1367 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 80:
#line 1382 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 81:
#line 1386 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 82:
#line 1396 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 83:
#line 1402 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		;}
    break;

  case 84:
#line 1409 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 85:
#line 1415 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		;}
    break;

  case 86:
#line 1427 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    ;}
    break;

  case 87:
#line 1434 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    ;}
    break;

  case 88:
#line 1440 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 89:
#line 1447 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    ;}
    break;

  case 90:
#line 1453 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    ;}
    break;

  case 91:
#line 1457 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 92:
#line 1464 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 93:
#line 1475 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (SYMTAB ((yysemantic_stack_[(2) - (2)].sval)), NULL);
    ;}
    break;

  case 94:
#line 1479 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
    ;}
    break;

  case 95:
#line 1487 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(5) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								nt->name,
								nt->type,
								(yysemantic_stack_[(5) - (5)].expr));
      delete nt;
		;}
    break;

  case 96:
#line 1496 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(4) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      delete nt;
		;}
    break;

  case 97:
#line 1503 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(6) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      delete nt;
		;}
    break;

  case 98:
#line 1513 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "hash"; ;}
    break;

  case 99:
#line 1515 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "btree"; ;}
    break;

  case 100:
#line 1522 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->create = false;
      (yyval.node) = d;
    ;}
    break;

  case 101:
#line 1530 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 102:
#line 1534 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->uniq = true;
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 103:
#line 1542 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 104:
#line 1546 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->method = (yysemantic_stack_[(2) - (1)].strval);
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 105:
#line 1554 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(7) - (2)].sval)), (yysemantic_stack_[(7) - (4)].expr), "",
                          dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(7) - (6)].node)));
    ;}
    break;

  case 106:
#line 1562 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 107:
#line 1566 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (1)].node))->coll = SYMTAB ((yysemantic_stack_[(3) - (3)].sval));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    ;}
    break;

  case 108:
#line 1574 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL);
    ;}
    break;

  case 109:
#line 1578 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<SequenceType *> ((yysemantic_stack_[(2) - (2)].node)));
    ;}
    break;

  case 110:
#line 1585 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      IndexFieldList *l = new IndexFieldList (LOC ((yyloc)));
      l->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
      
    ;}
    break;

  case 111:
#line 1592 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(3) - (1)].node))->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    ;}
    break;

  case 112:
#line 1602 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 113:
#line 1607 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 114:
#line 1619 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 115:
#line 1623 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 116:
#line 1627 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 117:
#line 1631 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 118:
#line 1638 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 119:
#line 1645 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      if ((yysemantic_stack_[(4) - (2)].node) == NULL)
        (yyval.expr) = (yysemantic_stack_[(4) - (3)].expr);
      else {
        BlockBody *b = dynamic_cast<BlockBody *> ((yysemantic_stack_[(4) - (3)].expr));
        VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(4) - (2)].node));
        if (b == NULL) {
          b = new BlockBody ((yysemantic_stack_[(4) - (3)].expr)->get_location (), vfo);
          b->add ((yysemantic_stack_[(4) - (3)].expr));
        } else {
          b->set_decls (vfo);
        }
        (yyval.expr) = b;
      }
    ;}
    break;

  case 120:
#line 1664 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      VFO_DeclList *vfo2 = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (2)].node));
      if ((yysemantic_stack_[(3) - (1)].node) == NULL)
        vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back (*vfo2);
      (yyval.node) = vfo;
    ;}
    break;

  case 121:
#line 1673 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    ;}
    break;

  case 122:
#line 1680 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    ;}
    break;

  case 123:
#line 1686 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    ;}
    break;

  case 124:
#line 1695 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(1) - (1)].varnametype);
      VarDecl *vd = new VarDecl(LOC ((yyloc)),
                       nt->name,
                       nt->type,
                       NULL);
      vd->set_global (false);
			(yyval.node) = vd;
      delete nt;
    ;}
    break;

  case 125:
#line 1706 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(3) - (1)].varnametype);
      VarDecl *vd = new VarDecl(LOC ((yyloc)),
                       nt->name,
                       nt->type,
                       (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global (false);
			(yyval.node) = vd;
    ;}
    break;

  case 126:
#line 1719 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (3)].sval)), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 127:
#line 1726 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 128:
#line 1733 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *b = dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr));
      if (b == NULL) {
        b = new BlockBody ((yysemantic_stack_[(5) - (5)].expr)->get_location ()); 
        b->add ((yysemantic_stack_[(5) - (5)].expr));
      }
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), b);
    ;}
    break;

  case 129:
#line 1745 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 130:
#line 1749 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 131:
#line 1756 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::create_stmt);
    ;}
    break;

  case 132:
#line 1760 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::drop_stmt);
    ;}
    break;

  case 133:
#line 1764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::build_stmt);
    ;}
    break;

  case 134:
#line 1771 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 135:
#line 1775 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->deterministic = false;
      (yyval.node) = d;
    ;}
    break;

  case 136:
#line 1781 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    ;}
    break;

  case 137:
#line 1788 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 138:
#line 1792 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 139:
#line 1796 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    ;}
    break;

  case 140:
#line 1804 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 141:
#line 1811 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 142:
#line 1820 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 143:
#line 1832 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 144:
#line 1846 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 145:
#line 1854 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 146:
#line 1868 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 147:
#line 1874 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 148:
#line 1886 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 149:
#line 1894 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 150:
#line 1905 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 151:
#line 1916 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 152:
#line 1920 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(2) - (2)].expr)),
        *blk2 = new BlockBody (LOC ((yyloc)));
      blk2->add ((yysemantic_stack_[(2) - (1)].expr));
      for (int i = 0; i < blk->size (); i++)
        blk2->add ((*blk) [i]);
      (yyval.expr) = blk2;
    ;}
    break;

  case 153:
#line 1932 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    ;}
    break;

  case 154:
#line 1936 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 155:
#line 1945 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 156:
#line 1949 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
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

  case 175:
#line 1996 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 176:
#line 2005 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 177:
#line 2012 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    ;}
    break;

  case 178:
#line 2016 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    ;}
    break;

  case 179:
#line 2024 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    ;}
    break;

  case 180:
#line 2028 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    ;}
    break;

  case 181:
#line 2032 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    ;}
    break;

  case 182:
#line 2039 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 183:
#line 2043 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 184:
#line 2050 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)), dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 185:
#line 2055 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    ;}
    break;

  case 186:
#line 2064 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 195:
#line 2082 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 196:
#line 2088 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 197:
#line 2097 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    ;}
    break;

  case 198:
#line 2101 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    ;}
    break;

  case 199:
#line 2111 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		;}
    break;

  case 200:
#line 2122 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 201:
#line 2128 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 202:
#line 2142 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 203:
#line 2149 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 204:
#line 2157 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 205:
#line 2166 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 206:
#line 2176 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 207:
#line 2184 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 208:
#line 2193 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 209:
#line 2202 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 210:
#line 2217 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 211:
#line 2229 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 212:
#line 2240 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 213:
#line 2252 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 214:
#line 2258 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 215:
#line 2270 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 216:
#line 2276 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 217:
#line 2290 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 218:
#line 2298 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 219:
#line 2307 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 220:
#line 2315 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 221:
#line 2327 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 222:
#line 2333 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 224:
#line 2344 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, SYMTAB ((yysemantic_stack_[(2) - (2)].sval)), "", "");
    ;}
    break;

  case 225:
#line 2348 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
    ;}
    break;

  case 226:
#line 2356 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    ;}
    break;

  case 227:
#line 2360 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    ;}
    break;

  case 229:
#line 2369 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (6)].sval)));
    ;}
    break;

  case 230:
#line 2373 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 231:
#line 2377 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), "");
    ;}
    break;

  case 232:
#line 2384 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      std::string name = SYMTAB ((yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 233:
#line 2399 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 234:
#line 2407 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    ;}
    break;

  case 235:
#line 2414 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 236:
#line 2420 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 237:
#line 2431 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 SYMTAB ((yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 238:
#line 2437 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 239:
#line 2446 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 240:
#line 2456 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 241:
#line 2461 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 242:
#line 2473 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 243:
#line 2479 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 244:
#line 2493 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 245:
#line 2499 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 246:
#line 2511 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 247:
#line 2518 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 248:
#line 2525 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 249:
#line 2532 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 250:
#line 2539 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 251:
#line 2546 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 252:
#line 2553 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 253:
#line 2566 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 254:
#line 2570 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 255:
#line 2580 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 256:
#line 2585 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 257:
#line 2596 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 258:
#line 2607 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 259:
#line 2614 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 260:
#line 2627 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 261:
#line 2634 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 262:
#line 2646 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 263:
#line 2652 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 264:
#line 2665 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 265:
#line 2672 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								SYMTAB ((yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 266:
#line 2686 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 267:
#line 2692 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 268:
#line 2704 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 269:
#line 2710 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 270:
#line 2723 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 271:
#line 2734 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 272:
#line 2738 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 273:
#line 2749 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 274:
#line 2753 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 275:
#line 2772 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 276:
#line 2776 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 277:
#line 2784 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 278:
#line 2792 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 279:
#line 2800 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 280:
#line 2807 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 281:
#line 2808 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 282:
#line 2816 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 283:
#line 2824 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 284:
#line 2832 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 285:
#line 2846 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 286:
#line 2850 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 287:
#line 2857 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 288:
#line 2870 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 289:
#line 2874 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 290:
#line 2885 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 291:
#line 2889 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 292:
#line 2893 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 293:
#line 2903 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 294:
#line 2907 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 295:
#line 2911 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 296:
#line 2915 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 297:
#line 2919 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 298:
#line 2929 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 2933 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 300:
#line 2938 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 301:
#line 2949 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 2953 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 303:
#line 2957 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 304:
#line 2967 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 305:
#line 2971 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 306:
#line 2983 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 307:
#line 2987 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 308:
#line 2999 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 309:
#line 3003 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 310:
#line 3015 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 311:
#line 3019 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 312:
#line 3031 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 313:
#line 3035 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 314:
#line 3047 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 315:
#line 3051 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 316:
#line 3055 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 317:
#line 3059 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 318:
#line 3071 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 319:
#line 3075 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 320:
#line 3079 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 321:
#line 3089 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 322:
#line 3093 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 323:
#line 3097 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 324:
#line 3101 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 325:
#line 3105 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 326:
#line 3109 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 327:
#line 3119 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 328:
#line 3123 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 329:
#line 3127 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 330:
#line 3137 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 331:
#line 3141 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 332:
#line 3145 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 333:
#line 3149 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    ;}
    break;

  case 334:
#line 3161 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 335:
#line 3167 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 336:
#line 3179 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 337:
#line 3185 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 338:
#line 3199 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(3) - (2)].sval))),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 339:
#line 3205 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 340:
#line 3247 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 341:
#line 3251 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 342:
#line 3255 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 343:
#line 3259 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 344:
#line 3271 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    ;}
    break;

  case 345:
#line 3281 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
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

  case 346:
#line 3292 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 347:
#line 3297 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 348:
#line 3307 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 3311 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 3321 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 351:
#line 3327 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 352:
#line 3333 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 353:
#line 3339 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 354:
#line 3351 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 355:
#line 3357 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 356:
#line 3368 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 357:
#line 3372 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 358:
#line 3376 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 359:
#line 3380 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 360:
#line 3384 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 361:
#line 3388 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 362:
#line 3392 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 363:
#line 3402 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 364:
#line 3406 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 365:
#line 3416 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 366:
#line 3422 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 367:
#line 3434 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 368:
#line 3438 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 369:
#line 3442 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 370:
#line 3446 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 371:
#line 3450 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 372:
#line 3465 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 373:
#line 3469 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 374:
#line 3479 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 375:
#line 3483 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 376:
#line 3493 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 377:
#line 3500 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 378:
#line 3507 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 379:
#line 3520 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 380:
#line 3524 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 381:
#line 3536 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 382:
#line 3542 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 383:
#line 3556 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 384:
#line 3567 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 385:
#line 3571 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 386:
#line 3575 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 387:
#line 3579 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 388:
#line 3583 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 389:
#line 3587 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 390:
#line 3591 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 391:
#line 3595 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 392:
#line 3605 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 393:
#line 3609 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 394:
#line 3619 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 395:
#line 3624 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 396:
#line 3629 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 397:
#line 3640 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 398:
#line 3650 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 399:
#line 3654 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 400:
#line 3665 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 401:
#line 3675 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 402:
#line 3686 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 403:
#line 3742 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 404:
#line 3748 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 405:
#line 3760 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 406:
#line 3766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 407:
#line 3778 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 408:
#line 3782 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 409:
#line 3792 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 410:
#line 3796 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 411:
#line 3800 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 412:
#line 3810 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 413:
#line 3818 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 414:
#line 3826 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 415:
#line 3834 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 416:
#line 3842 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 417:
#line 3850 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 418:
#line 3865 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 419:
#line 3871 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 420:
#line 3883 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 421:
#line 3889 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 422:
#line 3902 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 425:
#line 3919 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 426:
#line 3924 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 427:
#line 3935 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 428:
#line 3939 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 429:
#line 3946 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 430:
#line 3952 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 431:
#line 3958 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 432:
#line 3966 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 433:
#line 3980 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 434:
#line 3984 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 435:
#line 3991 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 436:
#line 3997 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 437:
#line 4003 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 438:
#line 4011 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 439:
#line 4025 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 440:
#line 4030 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 441:
#line 4041 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 442:
#line 4046 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 443:
#line 4057 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 444:
#line 4062 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 445:
#line 4067 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 446:
#line 4073 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 447:
#line 4085 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 448:
#line 4091 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 449:
#line 4096 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 450:
#line 4101 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 451:
#line 4112 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 452:
#line 4117 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 453:
#line 4132 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 454:
#line 4137 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 455:
#line 4154 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 456:
#line 4169 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 457:
#line 4173 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 458:
#line 4177 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 459:
#line 4181 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 460:
#line 4185 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 461:
#line 4189 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 462:
#line 4199 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 463:
#line 4210 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 464:
#line 4216 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 465:
#line 4222 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 466:
#line 4227 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 467:
#line 4249 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 468:
#line 4255 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 469:
#line 4261 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 470:
#line 4266 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 471:
#line 4277 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 472:
#line 4287 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 473:
#line 4297 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 474:
#line 4303 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 475:
#line 4309 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 476:
#line 4314 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 477:
#line 4325 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 478:
#line 4331 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 479:
#line 4343 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		;}
    break;

  case 480:
#line 4354 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 481:
#line 4360 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 482:
#line 4366 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 483:
#line 4403 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 484:
#line 4408 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 485:
#line 4413 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 486:
#line 4424 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 487:
#line 4428 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 488:
#line 4432 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 489:
#line 4442 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 490:
#line 4453 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 491:
#line 4457 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 492:
#line 4461 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 493:
#line 4465 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 494:
#line 4469 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 495:
#line 4473 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 496:
#line 4477 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 497:
#line 4481 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 498:
#line 4485 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 499:
#line 4495 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 500:
#line 4505 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 501:
#line 4509 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 502:
#line 4514 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 503:
#line 4525 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 504:
#line 4535 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 505:
#line 4545 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 506:
#line 4549 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 507:
#line 4553 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 508:
#line 4563 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 509:
#line 4569 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 510:
#line 4575 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 511:
#line 4581 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 512:
#line 4587 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 513:
#line 4599 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 514:
#line 4610 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		;}
    break;

  case 515:
#line 4617 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
                           NULL,
                           true);
		;}
    break;

  case 516:
#line 4624 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		;}
    break;

  case 517:
#line 4631 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		;}
    break;

  case 518:
#line 4638 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 519:
#line 4645 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		;}
    break;

  case 520:
#line 4652 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 521:
#line 4665 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 522:
#line 4686 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 523:
#line 4693 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 524:
#line 4713 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 525:
#line 4753 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 526:
#line 4758 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 527:
#line 4761 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 528:
#line 4769 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 529:
#line 4775 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 530:
#line 4781 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 531:
#line 4787 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 532:
#line 4793 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 533:
#line 4800 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 534:
#line 4806 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 535:
#line 4812 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 536:
#line 4818 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 537:
#line 4824 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 538:
#line 4836 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 539:
#line 4841 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 540:
#line 4851 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 541:
#line 4857 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 542:
#line 4869 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 543:
#line 4895 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 544:
#line 4906 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 545:
#line 4912 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 546:
#line 4925 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 547:
#line 4939 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 548:
#line 4946 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 549:
#line 4953 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 550:
#line 4964 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 551:
#line 4971 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 552:
#line 4979 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(11) - (6)].sval)),
                          SYMTAB ((yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 553:
#line 4988 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(14) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(14) - (6)].sval)),
                          SYMTAB ((yysemantic_stack_[(14) - (9)].sval)),
                          SYMTAB ((yysemantic_stack_[(14) - (12)].sval)),
                          (yysemantic_stack_[(14) - (14)].expr));
    ;}
    break;

  case 555:
#line 5004 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
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

  case 556:
#line 5021 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 557:
#line 5022 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); ;}
    break;

  case 558:
#line 5023 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); ;}
    break;

  case 559:
#line 5024 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); ;}
    break;

  case 560:
#line 5025 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); ;}
    break;

  case 561:
#line 5026 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); ;}
    break;

  case 562:
#line 5027 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); ;}
    break;

  case 563:
#line 5028 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); ;}
    break;

  case 564:
#line 5029 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); ;}
    break;

  case 565:
#line 5030 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); ;}
    break;

  case 566:
#line 5031 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); ;}
    break;

  case 567:
#line 5032 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); ;}
    break;

  case 568:
#line 5033 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); ;}
    break;

  case 569:
#line 5034 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); ;}
    break;

  case 570:
#line 5035 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); ;}
    break;

  case 571:
#line 5036 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); ;}
    break;

  case 572:
#line 5037 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); ;}
    break;

  case 573:
#line 5038 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); ;}
    break;

  case 574:
#line 5039 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); ;}
    break;

  case 575:
#line 5040 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); ;}
    break;

  case 576:
#line 5041 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); ;}
    break;

  case 577:
#line 5042 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); ;}
    break;

  case 578:
#line 5043 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); ;}
    break;

  case 579:
#line 5044 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); ;}
    break;

  case 580:
#line 5045 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); ;}
    break;

  case 581:
#line 5046 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); ;}
    break;

  case 582:
#line 5047 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); ;}
    break;

  case 583:
#line 5048 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); ;}
    break;

  case 584:
#line 5049 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); ;}
    break;

  case 585:
#line 5050 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); ;}
    break;

  case 586:
#line 5051 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); ;}
    break;

  case 587:
#line 5052 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); ;}
    break;

  case 588:
#line 5053 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); ;}
    break;

  case 589:
#line 5054 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); ;}
    break;

  case 590:
#line 5055 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); ;}
    break;

  case 591:
#line 5056 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); ;}
    break;

  case 592:
#line 5057 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); ;}
    break;

  case 593:
#line 5058 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); ;}
    break;

  case 594:
#line 5059 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); ;}
    break;

  case 595:
#line 5060 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); ;}
    break;

  case 596:
#line 5061 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); ;}
    break;

  case 597:
#line 5062 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); ;}
    break;

  case 598:
#line 5063 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); ;}
    break;

  case 599:
#line 5064 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); ;}
    break;

  case 600:
#line 5065 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); ;}
    break;

  case 601:
#line 5066 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); ;}
    break;

  case 602:
#line 5067 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); ;}
    break;

  case 603:
#line 5068 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); ;}
    break;

  case 604:
#line 5069 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); ;}
    break;

  case 605:
#line 5070 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); ;}
    break;

  case 606:
#line 5071 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); ;}
    break;

  case 607:
#line 5072 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); ;}
    break;

  case 608:
#line 5073 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); ;}
    break;

  case 609:
#line 5074 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); ;}
    break;

  case 610:
#line 5075 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); ;}
    break;

  case 611:
#line 5076 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); ;}
    break;

  case 612:
#line 5077 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); ;}
    break;

  case 613:
#line 5078 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); ;}
    break;

  case 614:
#line 5079 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); ;}
    break;

  case 615:
#line 5080 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); ;}
    break;

  case 616:
#line 5081 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); ;}
    break;

  case 617:
#line 5082 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); ;}
    break;

  case 618:
#line 5083 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); ;}
    break;

  case 619:
#line 5084 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); ;}
    break;

  case 620:
#line 5085 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); ;}
    break;

  case 621:
#line 5086 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); ;}
    break;

  case 622:
#line 5087 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); ;}
    break;

  case 623:
#line 5088 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); ;}
    break;

  case 624:
#line 5089 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); ;}
    break;

  case 625:
#line 5090 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); ;}
    break;

  case 626:
#line 5091 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); ;}
    break;

  case 627:
#line 5092 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); ;}
    break;

  case 628:
#line 5093 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); ;}
    break;

  case 629:
#line 5094 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); ;}
    break;

  case 630:
#line 5095 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); ;}
    break;

  case 631:
#line 5096 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); ;}
    break;

  case 632:
#line 5097 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); ;}
    break;

  case 633:
#line 5098 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); ;}
    break;

  case 634:
#line 5099 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); ;}
    break;

  case 635:
#line 5100 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); ;}
    break;

  case 636:
#line 5101 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); ;}
    break;

  case 637:
#line 5102 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); ;}
    break;

  case 638:
#line 5103 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); ;}
    break;

  case 639:
#line 5104 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); ;}
    break;

  case 640:
#line 5105 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); ;}
    break;

  case 641:
#line 5106 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); ;}
    break;

  case 642:
#line 5107 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); ;}
    break;

  case 643:
#line 5108 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); ;}
    break;

  case 644:
#line 5109 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); ;}
    break;

  case 645:
#line 5110 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); ;}
    break;

  case 646:
#line 5111 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); ;}
    break;

  case 647:
#line 5112 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); ;}
    break;

  case 648:
#line 5113 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); ;}
    break;

  case 649:
#line 5114 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); ;}
    break;

  case 650:
#line 5115 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); ;}
    break;

  case 651:
#line 5116 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); ;}
    break;

  case 652:
#line 5117 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); ;}
    break;

  case 653:
#line 5118 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); ;}
    break;

  case 654:
#line 5119 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); ;}
    break;

  case 655:
#line 5120 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); ;}
    break;

  case 656:
#line 5121 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); ;}
    break;

  case 657:
#line 5122 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); ;}
    break;

  case 658:
#line 5123 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); ;}
    break;

  case 659:
#line 5124 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); ;}
    break;

  case 660:
#line 5125 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); ;}
    break;

  case 661:
#line 5126 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); ;}
    break;

  case 662:
#line 5127 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); ;}
    break;

  case 663:
#line 5128 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); ;}
    break;

  case 664:
#line 5129 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); ;}
    break;

  case 665:
#line 5130 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); ;}
    break;

  case 666:
#line 5131 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); ;}
    break;

  case 667:
#line 5132 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); ;}
    break;

  case 668:
#line 5133 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); ;}
    break;

  case 669:
#line 5134 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); ;}
    break;

  case 670:
#line 5135 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); ;}
    break;

  case 671:
#line 5136 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); ;}
    break;

  case 672:
#line 5137 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); ;}
    break;

  case 673:
#line 5138 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); ;}
    break;

  case 674:
#line 5139 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); ;}
    break;

  case 675:
#line 5140 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); ;}
    break;

  case 676:
#line 5141 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); ;}
    break;

  case 677:
#line 5142 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); ;}
    break;

  case 678:
#line 5143 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); ;}
    break;

  case 679:
#line 5144 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); ;}
    break;

  case 680:
#line 5145 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); ;}
    break;

  case 681:
#line 5146 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); ;}
    break;

  case 682:
#line 5147 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); ;}
    break;

  case 683:
#line 5148 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); ;}
    break;

  case 684:
#line 5149 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); ;}
    break;

  case 685:
#line 5150 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); ;}
    break;

  case 686:
#line 5151 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); ;}
    break;

  case 687:
#line 5152 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); ;}
    break;

  case 688:
#line 5153 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); ;}
    break;

  case 689:
#line 5154 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); ;}
    break;

  case 690:
#line 5155 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); ;}
    break;

  case 691:
#line 5156 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); ;}
    break;

  case 692:
#line 5157 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); ;}
    break;

  case 693:
#line 5158 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); ;}
    break;

  case 694:
#line 5159 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); ;}
    break;

  case 695:
#line 5160 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); ;}
    break;

  case 696:
#line 5161 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); ;}
    break;

  case 697:
#line 5162 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); ;}
    break;

  case 698:
#line 5163 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); ;}
    break;

  case 699:
#line 5164 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); ;}
    break;

  case 700:
#line 5165 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); ;}
    break;

  case 701:
#line 5166 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); ;}
    break;

  case 702:
#line 5167 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); ;}
    break;

  case 703:
#line 5168 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); ;}
    break;

  case 704:
#line 5169 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); ;}
    break;

  case 705:
#line 5170 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); ;}
    break;

  case 706:
#line 5171 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); ;}
    break;

  case 707:
#line 5172 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); ;}
    break;

  case 708:
#line 5173 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); ;}
    break;

  case 709:
#line 5174 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); ;}
    break;

  case 710:
#line 5175 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); ;}
    break;

  case 711:
#line 5176 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); ;}
    break;

  case 712:
#line 5177 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); ;}
    break;

  case 713:
#line 5178 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); ;}
    break;

  case 714:
#line 5179 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); ;}
    break;

  case 715:
#line 5180 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); ;}
    break;

  case 716:
#line 5181 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); ;}
    break;

  case 717:
#line 5182 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); ;}
    break;

  case 718:
#line 5183 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); ;}
    break;

  case 719:
#line 5184 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); ;}
    break;

  case 720:
#line 5185 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); ;}
    break;

  case 721:
#line 5186 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); ;}
    break;

  case 722:
#line 5187 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); ;}
    break;

  case 723:
#line 5188 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); ;}
    break;

  case 724:
#line 5189 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("create"); ;}
    break;

  case 725:
#line 5190 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("build"); ;}
    break;

  case 726:
#line 5191 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); ;}
    break;

  case 727:
#line 5192 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); ;}
    break;

  case 728:
#line 5193 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("hash"); ;}
    break;

  case 729:
#line 5194 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("btree"); ;}
    break;

  case 730:
#line 5195 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("drop"); ;}
    break;

  case 731:
#line 5196 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); ;}
    break;

  case 732:
#line 5197 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); ;}
    break;

  case 733:
#line 5198 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); ;}
    break;

  case 734:
#line 5199 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); ;}
    break;

  case 735:
#line 5200 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); ;}
    break;

  case 736:
#line 5201 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); ;}
    break;

  case 737:
#line 5202 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); ;}
    break;

  case 738:
#line 5203 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); ;}
    break;

  case 739:
#line 5204 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); ;}
    break;

  case 740:
#line 5205 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); ;}
    break;

  case 741:
#line 5206 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); ;}
    break;

  case 742:
#line 5218 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 743:
#line 5224 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 744:
#line 5241 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 745:
#line 5245 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 746:
#line 5249 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 747:
#line 5253 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 748:
#line 5263 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 749:
#line 5266 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 750:
#line 5269 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 751:
#line 5272 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 752:
#line 5281 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 753:
#line 5284 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 754:
#line 5293 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 755:
#line 5296 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 756:
#line 5305 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 757:
#line 5308 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 758:
#line 5317 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 759:
#line 5320 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 760:
#line 5329 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 761:
#line 5332 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 762:
#line 5335 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 763:
#line 5344 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 764:
#line 5347 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 765:
#line 5356 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 766:
#line 5360 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 767:
#line 5370 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 768:
#line 5373 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 769:
#line 5376 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 770:
#line 5379 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 771:
#line 5382 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 772:
#line 5391 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 773:
#line 5400 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 774:
#line 5404 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 775:
#line 5408 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 776:
#line 5412 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 777:
#line 5416 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 778:
#line 5420 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 779:
#line 5424 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 780:
#line 5434 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 781:
#line 5437 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 782:
#line 5440 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 783:
#line 5443 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 784:
#line 5452 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 785:
#line 5455 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 786:
#line 5458 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 787:
#line 5461 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 788:
#line 5470 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 789:
#line 5473 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 790:
#line 5482 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 791:
#line 5485 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 792:
#line 5488 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 793:
#line 5491 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 794:
#line 5494 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 795:
#line 5497 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 796:
#line 5500 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 797:
#line 5509 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 798:
#line 5512 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 799:
#line 5521 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 800:
#line 5524 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 801:
#line 5527 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 802:
#line 5530 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 803:
#line 5539 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 804:
#line 5542 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 805:
#line 5545 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 806:
#line 5548 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 807:
#line 5551 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 808:
#line 5560 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 809:
#line 5563 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 810:
#line 5572 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 811:
#line 5575 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 812:
#line 5584 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 813:
#line 5587 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 814:
#line 5596 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 815:
#line 5599 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 816:
#line 5608 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 817:
#line 5617 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 818:
#line 5620 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 819:
#line 5629 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 820:
#line 5632 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 821:
#line 5635 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 822:
#line 5644 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 823:
#line 5647 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 824:
#line 5650 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 825:
#line 5653 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 826:
#line 5656 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 827:
#line 5665 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 828:
#line 5669 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 829:
#line 5673 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 830:
#line 5677 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 831:
#line 5687 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 832:
#line 5696 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 833:
#line 5706 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 834:
#line 5715 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 835:
#line 5718 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 836:
#line 5727 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 837:
#line 5730 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 838:
#line 5733 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 839:
#line 5742 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 840:
#line 5745 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 841:
#line 5754 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 7181 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1020;
  const short int
  xquery_parser::yypact_[] =
  {
      1375, -1020, -1020, -1020, -1020,   -25,   -57,   105, -1020,   221,
     311,    29,   322,  6802,   190,   348,   402,    -4, -1020, -1020,
   -1020, -1020, -1020, -1020,   364,   107, -1020,   535,   421, -1020,
     243, -1020, -1020, -1020,   427,   451, -1020,   432,   156,   536,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,   456,
     459, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020,  7066, -1020,  6000, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,  8650, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020,   500, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,  1648,
    8650, -1020, -1020, -1020, -1020, -1020, -1020,   474, -1020, -1020,
   -1020, -1020,   612, -1020,  6538, -1020, -1020, -1020, -1020, -1020,
    8650, -1020, -1020,  5728, -1020, -1020, -1020, -1020, -1020, -1020,
     483, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,    23,
     425, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,   372,
     489,   386, -1020,   422,   177, -1020, -1020, -1020, -1020, -1020,
   -1020,   539, -1020,   502, -1020,   545, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020,   387,   398,   405, -1020, -1020, -1020, -1020, -1020,
    4096,   663, -1020,  4368, -1020, -1020,   420,  4640,   503,   509,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
     -38, -1020, -1020, -1020, -1020,   328,  8650, -1020, -1020, -1020,
   -1020, -1020,   533,   608, -1020,   523,   449,   287,     3,   293,
     164, -1020,   626,   507,   603,   604,  4912, -1020, -1020, -1020,
     -22, -1020, -1020,  5728, -1020,   103, -1020,   556,  6000, -1020,
     556,  6000, -1020, -1020, -1020, -1020,   556, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020,   557, -1020, -1020, -1020,  4640,
   -1020, -1020,  4640,  8650,  4640,   561,   562,  4640, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020,  4640,  7330, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
     567,  4640,  4640,   537,  4640,   546,  8650,   677,   678,   534,
     534,   677,  8650,   228,   248,   706,     2,   238,  8650,   581,
     625,   266,   724,   383,    94,   325,   706, -1020, -1020,   465,
   -1020, -1020, -1020, -1020, -1020,  4640, -1020,  4640,    33,   596,
      74,    69,  8650,   724,  8650,  8650,  4640,   478,   479, -1020,
     631,   632,  8650,    42,  4640,  7594,   601,   599,   600,   606,
     607,   609, -1020, -1020, -1020,  8650, -1020,   571,   734,  4640,
      57, -1020,   746,   582, -1020,  4640,   554, -1020,   744,  4640,
    4640,   584,  4640,  4640,  4640,  4640,   540,  8650,  4640,  8650,
     706,   706,   706, -1020, -1020, -1020, -1020,    -4,   535, -1020,
   -1020,   420,   729,  4640, -1020,  4640,   605,   451,   156,   536,
     654,   610,   615,  4640,  4640, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020,   666, -1020,   -51,  5184,  5184,  5184, -1020,  5184,
    5184, -1020,  5184, -1020,  5184, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020,  5184,  5184,    11,  5184,  5184,  5184,  5184,  5184,
    5184,  5184,  5184,  5184,  5184,  5184,   547,   680,   682,   685,
   -1020, -1020, -1020,  1920, -1020, -1020,  5728,  5728,  4640,   556,
   -1020, -1020,   556, -1020,   556,  2192,  5456, -1020,   602,   633,
   -1020,   611,  4640,  4640,   613,   618, -1020,   -12,     9,  2464,
     621,   622, -1020,   623, -1020,   634, -1020,  8650, -1020, -1020,
   -1020, -1020,   762, -1020, -1020, -1020, -1020, -1020, -1020,   679,
     681, -1020, -1020,   653,   300,  8650,   308,   635,   638,   653,
     706,   664,   660, -1020, -1020, -1020,   350,    85,   352,   782,
   -1020, -1020,   269, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020,   522, -1020,   624,   628,   627, -1020,   629,  2736,
     724,   713,   775,   724,   706,   717,   -37, -1020,   275,   684,
     675,   709, -1020,   -36,   637, -1020, -1020,  8650,   -33, -1020,
     636,   599,   456, -1020,   639,   640,   641, -1020,    24,    27,
    3008,   -17, -1020,  8650,   734, -1020,   -10,   644, -1020, -1020,
   -1020, -1020,   645, -1020,   224, -1020, -1020, -1020,    56,   102,
     726,   592,   614,   -56, -1020,   688,   649,    77, -1020, -1020,
   -1020, -1020, -1020,   643, -1020,    43, -1020, -1020,    -2,   651,
    8650,  4640,   714, -1020, -1020,   715,  8122,   716,  4640,   719,
     -68,   687,   -44,   608, -1020, -1020, -1020, -1020, -1020,  5184,
   -1020, -1020, -1020,  4640,    11,   315, -1020,   568,   381,   588,
     587, -1020, -1020,   577,  -128,     3,     3,   -31,   293,   293,
     293,   293,   164,   164, -1020, -1020,  8122,  8122,  8650,  8650,
   -1020,   662, -1020, -1020,   665, -1020, -1020, -1020,    59,   625,
      30,   667,   -25,  4640, -1020,   668,   669,   743,   694,  8650,
   -1020,  8650, -1020, -1020,   670, -1020, -1020, -1020,    84,   258,
     634, -1020,   101,   247, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020,   653, -1020,   721,  8386,   705,  4640,
   -1020, -1020, -1020,   758,   718,  4640,   706,   706,   653, -1020,
     431,   706, -1020, -1020,   583, -1020, -1020,   580,   316, -1020,
   -1020, -1020, -1020, -1020, -1020,   586, -1020, -1020,  4640,   671,
     704, -1020, -1020, -1020,   676,   727,   706,   703,   731,   766,
     706,   745,  4640,  4640,   720,   706,  4640,   748,  4640,   728,
     -75, -1020,   282,   620, -1020, -1020,   438,   -33, -1020, -1020,
   -1020,   725,  8650, -1020,  8650, -1020, -1020,   689,  4640,   847,
   -1020,   111, -1020,   159, -1020, -1020,   854, -1020,   385,  4640,
    4640,  4640,   388,  4640,  4640,  4640,  4640,  4640,  4640,   759,
    4640,  4640,   646,   730,   761,   729,   802, -1020,  4640, -1020,
     400,   776, -1020,  8650,   777, -1020,  8650,   732,   733, -1020,
     233, -1020, -1020, -1020,  8650, -1020,  8650,  4640,   747,  4640,
    4640,   -27,   753, -1020,   707,   722, -1020,   642, -1020,   -85,
   -1020,   271,    16,   652,    11,   271,  5184,  5184,   424, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020,    11,   757,    16, -1020,
     616,   833, -1020, -1020, -1020, -1020, -1020,   760, -1020, -1020,
   -1020,  4640, -1020,   763, -1020,   625, -1020, -1020, -1020,   736,
   -1020, -1020,  7858,   358, -1020,  3280,   723,   735,   765,   737,
     738, -1020,  8650,   810,   127, -1020, -1020,  4640, -1020,   -25,
   -1020, -1020, -1020, -1020, -1020,   886,   362, -1020, -1020, -1020,
    4640, -1020, -1020, -1020, -1020, -1020, -1020,   655,     7,   887,
   -1020,    39, -1020, -1020,   752,  4640,  3552, -1020,   706,   803,
   -1020, -1020, -1020,   706,   803,  8650, -1020, -1020,  4640,   739,
   -1020,  8650, -1020,  4640,  4640,   773,  4640,   770, -1020,   804,
     806,  4640,  8650,   565,   858, -1020, -1020, -1020,  3824,   749,
     750, -1020, -1020, -1020,   799, -1020,   176, -1020, -1020,   922,
   -1020, -1020,  4640,  8650, -1020, -1020,   193, -1020, -1020, -1020,
     751,   701,   711, -1020, -1020, -1020,   712,   740, -1020, -1020,
   -1020, -1020, -1020,   710,  8650,   755, -1020,   786,   646, -1020,
    4640,  8650,   776, -1020,   706, -1020,   513, -1020,   175,   829,
   -1020,  4640,   837,   714, -1020,   764,   767, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020,  4640, -1020, -1020,  4640,   801,  4640,
   -1020, -1020,  5184, -1020, -1020, -1020, -1020, -1020,    31,  5184,
    5184,   254, -1020,   588, -1020, -1020,   256,  5184, -1020, -1020,
     587,    11,   683, -1020, -1020, -1020, -1020,  4640, -1020, -1020,
    8650,   769,   201, -1020, -1020,   768, -1020, -1020, -1020, -1020,
   -1020,   758,  8122,   828,   859,   772, -1020, -1020, -1020, -1020,
     134,   932,   933,   134,   -60,   182,   187,   805,   832, -1020,
     781,   866,   706,   803, -1020, -1020, -1020, -1020, -1020, -1020,
    4640, -1020,  4640,  8650,  8650, -1020,   407, -1020,  4640, -1020,
     783, -1020, -1020,   847,  8650,   212, -1020,   784,   847,  8650,
   -1020, -1020,  4640,  4640,  4640,  4640,  4640, -1020,  4640,  6272,
   -1020,   785, -1020, -1020, -1020, -1020,   829, -1020, -1020, -1020,
     706, -1020, -1020, -1020, -1020, -1020, -1020,  4640, -1020,   293,
    5184,  5184,   293,   377, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020,   872,  4640,  8650,  4640, -1020, -1020, -1020,
   -1020,  8122, -1020,     7,     7,   134, -1020, -1020, -1020,    32,
     134,   945,   741,   873, -1020,   873, -1020,  4640,   188,  4640,
   -1020,   706, -1020, -1020, -1020,   901, -1020, -1020, -1020, -1020,
      21,   847,  8650, -1020,   778,   847, -1020, -1020, -1020, -1020,
   -1020, -1020,   194, -1020, -1020, -1020, -1020,   293,   293,  5184,
    8122, -1020,   791, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
      16, -1020,   213, -1020,   214, -1020,   868,   758,  4640, -1020,
   -1020,   803,   857,   120,   334, -1020,   787,   847, -1020,   789,
     860,   826,   293,   795,  4640,   742,   873, -1020, -1020,   706,
   -1020, -1020,  8650, -1020, -1020,   890,   162, -1020, -1020, -1020,
   -1020,   800,   368, -1020, -1020, -1020,   792, -1020,  8650, -1020,
    4640, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020,   227, -1020,   869,   826,  8650, -1020,   231,
     870,   826,  8650, -1020,   807,   826, -1020
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   377,   378,   556,   524,   712,   713,   716,   714,   717,
     715,   646,   570,   562,   578,   569,   560,   658,   668,   707,
     706,   708,   709,   705,   564,   566,   593,   665,   628,   622,
     667,   663,   590,   666,   722,   617,   659,   720,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   660,   574,   568,
     561,   662,   637,   567,   572,   731,   732,   733,   734,   735,
     736,   737,   738,   739,   740,   741,   368,   371,   636,   632,
     623,   603,   559,   358,     0,   631,   639,   647,   356,   627,
     394,   604,   605,   661,   357,   360,   624,   641,     0,   400,
     366,   396,   634,   558,   625,   626,   654,   629,   645,   653,
     362,   361,   577,   616,   656,   395,   644,   649,   563,     0,
       0,   315,   642,   652,   657,   655,   635,   710,   621,   619,
     620,   367,     0,   314,     0,   370,   369,   650,   606,   630,
       0,   359,   344,     0,   376,   651,   633,   640,   648,   643,
     711,   597,   602,   601,   600,   599,   598,   571,   618,     0,
     557,   664,   591,   697,   696,   698,   576,   575,   594,   703,
     565,   695,   700,   701,   692,   596,   638,   694,   704,   702,
     693,   595,   699,   718,   719,   721,   684,   683,   580,   573,
     582,   581,   677,   673,   588,   592,   589,   686,   687,   670,
     579,   682,   681,   678,   674,   691,   685,   680,   676,   669,
     690,   689,   675,   679,   671,   672,   583,   584,   586,   688,
     585,   587,   724,   725,   730,   726,   723,   728,   729,   727,
       0,     0,     2,     0,     4,     6,     0,     0,     0,     0,
      17,    19,    31,    21,    22,    23,    47,    24,    28,    29,
      51,    52,    53,    48,    49,    55,    56,    26,    25,    30,
      50,   173,   172,   169,   170,   171,   174,    27,    11,   150,
     151,   155,   157,   189,   195,     0,     0,   187,   188,   158,
     159,   160,   161,   271,   273,   275,   285,   288,   290,   293,
     298,   301,   304,   306,   308,   310,     0,   312,   318,   320,
       0,   336,   319,   340,   343,   345,   348,   350,     0,   355,
     352,     0,   363,   373,   375,   349,   379,   384,   392,   385,
     386,   387,   390,   391,   388,   389,   407,   409,   410,   411,
     408,   456,   457,   458,   459,   460,   461,   372,   498,   490,
     497,   496,   495,   492,   494,   491,   493,   393,    54,   162,
     163,   165,   164,   166,   167,   374,   168,   121,   118,     0,
     129,   130,     0,     0,     0,     0,     0,     0,   712,   713,
     716,   717,   715,   646,   570,   562,   578,   569,   560,   658,
     564,   566,   665,   628,   667,   722,   617,   720,   607,   608,
     568,   561,   559,   629,     0,     0,   710,   711,   557,   703,
     565,   695,   701,   692,   595,   718,   721,   724,   725,   730,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,    99,     0,
     100,   101,   103,   134,   137,     0,   555,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   197,
       0,     0,     0,     0,     0,     0,     0,   562,   569,   560,
     566,   559,   364,   374,   397,     0,   398,     0,   423,     0,
       0,   339,     0,     0,   342,     0,     0,   452,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     1,     5,     7,     0,     0,    12,
      10,    14,    15,     0,   153,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,   194,   190,   196,   191,
     193,   192,   199,   200,     0,     0,     0,     0,   329,     0,
       0,   327,     0,   280,     0,   328,   321,   326,   325,   324,
     323,   322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     317,   316,   313,     0,   337,   341,     0,     0,     0,   351,
     381,   354,   353,   365,   380,     0,     0,   127,     0,     0,
     522,     0,     0,     0,     0,     0,   514,     0,     0,     0,
       0,     0,   503,     0,   504,     0,   139,     0,   140,   136,
     135,   138,     0,   112,   113,    64,    65,   554,    73,     0,
       0,    58,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   525,   526,   527,     0,     0,     0,     0,
     780,   781,     0,    63,   773,   774,   775,   776,   777,   778,
     779,   102,     0,   104,     0,     0,     0,   505,     0,     0,
       0,    82,     0,     0,     0,    74,     0,   260,     0,     0,
       0,   212,   213,     0,     0,   177,   178,     0,     0,   198,
       0,     0,     0,   500,     0,     0,     0,   508,     0,     0,
       0,     0,   399,   424,   423,   420,     0,     0,   454,   453,
     338,   513,     0,   451,     0,   538,   539,   499,     0,     0,
       0,     0,     0,     0,   544,     0,     0,     0,   215,   232,
     131,   133,   132,     0,    18,     0,    20,   156,     0,     0,
       0,     0,     0,   176,   233,     0,     0,     0,     0,     0,
       0,     0,     0,   272,   274,   278,   284,   283,   282,     0,
     279,   276,   277,     0,     0,     0,   765,   286,   744,   752,
     754,   756,   758,   760,   763,   292,   291,   289,   295,   296,
     297,   294,   299,   300,   303,   302,     0,     0,     0,     0,
     334,     0,   346,   347,     0,   382,   403,   405,     0,   658,
       0,     0,     0,     0,   330,     0,     0,     0,     0,     0,
     518,     0,   515,   463,     0,   462,   471,   472,     0,     0,
       0,    62,     0,     0,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    33,    34,     0,     0,    90,     0,
      86,    88,    89,    93,    96,     0,     0,     0,    32,    72,
       0,     0,   782,   783,     0,   784,   788,     0,     0,   817,
     786,   787,   816,   785,   789,     0,   796,   818,     0,     0,
       0,   507,   506,   473,     0,     0,     0,     0,     0,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   743,     0,     0,   179,   180,     0,   185,   521,   501,
     502,     0,     0,   511,     0,   509,   467,     0,     0,   423,
     421,     0,   412,     0,   401,   402,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,   154,     0,   186,
     244,   240,   242,     0,   234,   235,     0,   563,   571,   479,
     480,   486,   487,   489,     0,   202,     0,     0,     0,     0,
       0,     0,     0,   281,     0,     0,   759,     0,   287,     0,
     772,     0,     0,     0,     0,     0,     0,     0,   745,   749,
     767,   748,   771,   769,   768,   770,     0,     0,     0,   761,
     824,   822,   826,   764,   305,   307,   309,   477,   311,   335,
     383,     0,   404,   124,   123,     0,   120,   119,   128,     0,
     332,   331,     0,     0,   266,     0,     0,     0,   522,     0,
       0,   464,     0,   114,     0,   144,   142,     0,   141,     0,
      70,    71,    68,    69,    35,     0,     0,    91,    92,    94,
       0,    95,    60,    61,    66,    67,    57,     0,     0,     0,
     791,     0,   790,   807,     0,     0,     0,   474,     0,    84,
      78,    81,    80,     0,    76,     0,   258,   262,     0,     0,
     126,     0,   217,     0,     0,     0,     0,     0,   181,     0,
       0,     0,     0,   226,     0,   223,   228,   184,     0,     0,
       0,   468,   259,   424,     0,   413,     0,   447,   444,     0,
     448,   449,     0,     0,   450,   443,     0,   418,   446,   445,
       0,     0,     0,   531,   532,   528,     0,     0,   536,   537,
     533,   542,   540,     0,     0,     0,   546,     0,   547,   548,
       0,     0,   241,   253,     0,   254,     0,   245,   246,   247,
     248,     0,   237,     0,   201,     0,     0,   483,   485,   484,
     481,   210,   211,   204,     0,   206,   203,     0,     0,     0,
     766,   762,     0,   819,   820,   840,   839,   835,     0,     0,
       0,     0,   821,   753,   834,   746,     0,     0,   751,   750,
     755,     0,     0,   825,   823,   478,   406,     0,   122,   333,
       0,     0,     0,   267,   465,     0,   519,   520,   523,   516,
     517,   146,     0,     0,   115,     0,   143,    36,    87,    97,
     805,     0,     0,   803,   799,     0,     0,     0,     0,   475,
       0,    83,     0,    77,   261,   263,    13,   214,   219,   218,
       0,   221,     0,     0,     0,   183,   224,   227,     0,   469,
       0,   512,   510,   423,     0,     0,   455,     0,   423,     0,
     419,     9,     0,     0,     0,     0,     0,   545,     0,     0,
     549,     0,   216,   257,   255,   256,   249,   250,   251,   243,
       0,   238,   236,   488,   482,   208,   205,     0,   207,   841,
       0,     0,   827,     0,   838,   837,   836,   831,   832,   747,
     757,   833,   125,     0,     0,     0,     0,   466,   147,   116,
     145,     0,   149,     0,     0,   806,   808,   810,   812,     0,
     804,     0,     0,     0,   794,     0,   792,     0,     0,     0,
     476,     0,    79,   220,   222,   231,   230,   225,   182,   470,
       0,   423,     0,   148,     0,   423,   529,   530,   534,   535,
     541,   543,     0,   742,   252,   239,   209,   829,   828,     0,
       0,   268,     0,   264,   117,   815,   814,   809,   813,   811,
     800,   801,     0,   797,     0,   110,   106,   108,     0,   105,
     270,    85,     0,   433,   427,   422,     0,   423,   414,     0,
       0,     0,   830,     0,     0,     0,     0,   795,   793,     0,
     109,   111,     0,   441,   435,     0,   434,   436,   442,   439,
     429,     0,   428,   430,   440,   416,     0,   415,     0,   550,
       0,   265,   802,   798,   107,   229,   426,   437,   438,   425,
     431,   432,   417,     0,   269,     0,     0,     0,   551,     0,
       0,     0,     0,   552,     0,     0,   553
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1020, -1020,   771, -1020,   774,   779, -1020,   756, -1020,   486,
     491,  -493, -1020,   371,  -380, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,  -854,
   -1020, -1020, -1020, -1020,   -23,   180,   574, -1020, -1020, -1020,
   -1020,   575,   570,  -347, -1020, -1020, -1020,   203, -1020,  -757,
   -1020, -1020,    19, -1020, -1020, -1020, -1020, -1020, -1020,   234,
     172, -1020, -1020,  -178, -1020,  -925,   780,   -98, -1020,   504,
    -342, -1020, -1020, -1020, -1020,   131, -1020, -1020,   754, -1020,
   -1020, -1020, -1020, -1020,    86,  -496,  -640, -1020, -1020, -1020,
     -41, -1020, -1020,  -205,   -49,   -96, -1020, -1020, -1020,  -110,
   -1020, -1020,    98,  -104, -1020, -1020,  -100, -1019, -1020,   555,
     -24, -1020, -1020,    34, -1020, -1020,   498,   499, -1020,  -472,
    -929,   477,   112,  -531,   100,   117, -1020, -1020, -1020, -1020,
   -1020,   788, -1020, -1020, -1020, -1020, -1020,   790, -1020, -1020,
    -117, -1020, -1020, -1020, -1020, -1020, -1020, -1020,   -50,  -213,
   -1020, -1020,   229,   -62, -1020,  -541, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020,  -879, -1020,   -48, -1020,   345,
    -683, -1020, -1020, -1020, -1020, -1020,  -352,  -345, -1009,  -805,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
     264,  -650,  -745, -1020,   217,   -87,  -721, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020,   589,   590,  -439,   244,    22, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020,   -65, -1020, -1020,   -72,
    -411,  -396,   -13, -1020,   296, -1020, -1020,    87,    78,  -116,
     301, -1020, -1020,    89, -1020,  -716, -1020, -1020, -1020, -1020,
    -245,  -836, -1020,  -142,  -597, -1020,  -738, -1020, -1020, -1020,
   -1020,  -956, -1020, -1020, -1020, -1020,  -103,    97, -1020
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   814,   815,   816,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,  1039,
     654,   246,   247,   820,   821,   822,   983,   248,   429,   249,
     430,   431,   432,  1345,  1346,  1298,   250,   799,   251,   348,
     576,   780,   984,   252,   253,   254,   255,   256,   257,   433,
     434,   598,  1004,  1005,  1084,  1008,   258,   259,   505,   260,
     261,   262,   515,   450,   876,   877,   263,   516,   264,   518,
     265,   266,   267,   522,   523,  1063,   731,   268,   661,   707,
     662,   668,  1064,  1065,  1066,   708,   519,   520,   924,   925,
    1251,   521,   921,   922,  1117,  1118,  1119,  1120,   269,   656,
     657,   270,   993,   994,   271,   272,   273,   274,   739,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   542,   543,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   569,   570,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   778,   315,   316,   317,  1086,   684,   685,
     686,  1355,  1381,  1382,  1375,  1376,  1383,  1377,  1087,  1088,
     318,   319,  1089,   320,   321,   322,   323,   324,   325,   326,
     976,   732,   929,  1130,   930,   931,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   579,   997,   337,   338,
     339,   340,   341,   342,   343,   703,   704,   344,  1108,  1109,
    1040,   439,   345,   346,   747,   958,   748,   749,   750,   751,
     752,   753,   754,   959,   960,   633,   634,   635,   636,   637,
    1342,  1343,   638,  1285,  1193,  1289,  1286,   639,   640,   962,
     973,  1151,   963,   964,   969,   965,  1267,  1147,   948
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       400,   891,  1032,   746,   608,   932,  1044,   577,   864,   716,
     578,   467,  1162,   870,  1085,   642,   474,   758,   759,   760,
     761,   974,   975,   869,   462,   988,   622,  1155,   730,   651,
     655,     4,   961,   873,  1148,   406,   407,   408,   409,   410,
     411,   726,   648,   727,   476,   932,   932,   659,   412,   909,
     727,   436,  1338,   646,   413,   735,   726,   736,   737,   456,
     738,   463,   740,  1054,   688,   414,   415,   503,   861,   416,
     741,   742,   417,   418,   937,   464,   671,  1230,  1260,   710,
     711,   712,   406,   407,   408,   409,   410,   411,   861,   607,
     938,   728,   942,   789,   607,   412,   932,   468,   940,  1247,
    1248,  1191,   868,   503,   664,   419,   420,   421,   970,   971,
    1148,   472,  1353,   672,   791,  1137,   892,   473,   548,    80,
     418,   353,   545,   347,  1373,   436,   563,  1143,  1077,   882,
     972,    91,   884,  1029,   350,   985,   913,   695,   696,   546,
     698,   699,   700,   701,   549,   862,   706,   504,   898,   124,
    1195,   422,   419,   420,   916,   105,  1261,   550,  1192,   743,
    1144,   717,   744,   609,   981,   888,  1373,  1077,  1078,   790,
    1077,   723,   724,  1019,   910,   349,   565,   354,   610,   874,
     652,   893,   914,   917,  1077,  1078,   729,  1149,  1150,  1203,
     792,   551,   626,   729,   902,  1196,   834,  1085,  1354,  1291,
    1002,  1077,  1078,   746,   746,   883,  1074,  1085,   885,   829,
     729,   423,   875,  1339,   647,   986,  1230,   729,   447,   448,
    1077,  1078,  1057,   673,   653,   729,   689,  1324,  1269,   650,
    1055,   477,  1183,   777,   729,   424,   941,  1075,  1292,  1080,
     982,  1081,  1159,   859,  1010,   355,   356,  1171,   571,  1374,
     351,   573,  1186,   524,   855,   437,   581,   858,   438,   584,
    1079,  1011,   745,  1149,  1150,  1003,  1283,   943,  1082,   899,
     900,   932,   449,   425,   426,   427,   428,  1079,  1080,  1114,
    1081,  1080,   424,  1081,   901,   463,   585,  1293,   463,   566,
     567,  1397,  1295,  1348,  1079,  1080,   554,  1081,  1116,  1360,
     617,  1138,  1076,   590,   591,   618,   593,  1082,  1184,   555,
    1082,   110,  1080,  1079,  1081,   903,   904,  1275,  1366,  1366,
     425,   426,   427,   428,  1082,   835,   627,   122,   110,  1284,
     905,  1080,  1405,  1081,   628,     4,  1410,   644,   401,   645,
     580,  1082,  1077,   619,   122,   110,  1085,   629,  1083,   630,
     996,   896,   999,  1379,   836,   837,   676,   838,   839,   631,
    1082,   122,   632,  1294,   110,  1224,   149,   726,  1296,  1349,
     620,   687,   588,  1127,   726,  1361,  1077,   692,   506,   920,
     122,  1276,  1229,   149,  1365,   507,   935,  1379,   508,   509,
    1012,  1006,   817,   595,  1367,  1368,   510,   485,   443,   602,
     149,  1312,   486,  1128,   603,   613,  1007,  1013,  1406,   897,
    1029,   605,  1411,   746,   611,  1022,  1023,   863,   604,   149,
    1026,  1129,   716,    80,  1056,   746,  1156,  1030,   612,   658,
     621,   660,   663,   818,  1014,    91,  1389,  1279,   819,   670,
     545,   824,   679,  1069,   606,  1070,   825,  1351,  1014,   772,
     773,   552,   658,  1080,  1049,  1081,   992,   546,   497,   105,
     553,   932,   352,   743,  1380,   771,   744,  1031,   498,  1172,
     774,  1059,  1060,   357,   705,   949,   709,  1018,   781,   626,
     547,  1408,  1082,  1021,   785,   786,  1413,  1080,   552,  1081,
    1416,   794,   511,  1113,   512,   818,   402,   553,  1400,   403,
     819,   727,  1059,  1060,  1114,  1061,  1034,   775,   513,   843,
     775,  1264,   775,  1264,  1115,   435,  1082,  1265,   949,  1265,
    1046,  1047,   626,  1116,  1050,  1266,  1052,  1266,  1145,   572,
    1393,  1278,   727,  1146,   514,   574,  1334,   442,   844,   845,
    1310,   846,   847,   444,   950,  1314,  1072,  1337,  1378,  1384,
     404,   854,  1337,   405,  1062,  1024,  1025,  1093,  1094,  1095,
     932,  1098,  1099,  1100,  1101,  1102,  1103,   445,  1105,  1106,
    1329,  1378,   552,   406,   407,   408,   920,  1384,   411,   596,
     446,   553,   887,   601,   800,  1363,   440,   950,   832,   441,
     840,   833,   479,   841,   480,  1133,   451,  1135,  1136,   623,
     624,   625,   823,   426,   427,   428,   482,   452,   483,   932,
     453,  1259,  1091,   627,  1092,  1096,   465,  1097,  1262,  1263,
     746,   628,   469,   951,   952,   953,   470,  1201,  1356,  1059,
    1060,   475,  1359,   954,   629,   478,   630,  1244,  1245,  1166,
     481,   955,   484,   599,   600,   944,   631,   956,   957,   632,
     488,   527,   762,   763,   872,   487,   627,   755,   756,   528,
     529,   489,   530,   494,   628,   490,   951,   952,   953,   531,
     889,   764,   765,   532,  1386,   533,   491,   629,  1189,   630,
     534,   977,   977,   492,   955,   989,  1335,  1336,   501,   631,
    1157,   957,   632,  1198,   502,   525,   535,  1370,   526,   544,
     556,   557,   558,  1243,   559,   568,  1205,   919,   575,   582,
     583,  1208,  1209,   933,  1211,   589,   406,   597,   592,  1215,
     536,   537,   538,   539,   540,   541,   607,   594,   614,  1327,
    1328,   804,   805,   806,   807,   808,   809,   810,   811,   812,
     813,   615,   436,   426,   649,   665,   666,   667,   669,   680,
     385,   403,   682,   933,   933,   933,   933,   405,   438,   683,
     455,   690,   693,   691,   694,   697,   702,   715,  1241,   719,
     720,   725,   767,   766,   768,   721,   998,   769,   998,   920,
     722,   783,   801,   782,   802,   798,   803,   830,   831,   784,
     826,  1302,  1255,   827,   787,  1256,   788,  1258,  1362,   795,
     796,   797,   842,   848,   933,   849,   850,   856,   851,   857,
     852,   860,   865,   866,   867,   871,   918,   878,   906,   881,
     879,   880,   894,   895,   907,  1272,   911,   912,   915,   939,
     923,   926,   934,   968,   908,   936,   947,   966,   967,  1325,
     979,   992,   995,   819,   980,   987,   990,   991,  1001,  1015,
     726,  1028,  1036,  1027,  1037,  1038,  1020,  1033,  1041,  1042,
    1043,  1045,  1048,  1035,  1051,  1058,  1053,  1071,  1303,   580,
    1304,   580,  1073,  1068,  1090,  1104,  1308,  1111,  1110,   619,
    1107,  1121,  1123,  1125,  1126,  1140,  1164,  1163,  1142,  1134,
    1316,  1317,  1318,  1319,  1320,  1139,  1321,  1175,  1152,  1161,
    1165,  1167,  1182,  1141,  1176,  1178,     4,  1194,  1202,  1185,
    1122,  1210,  1212,   524,  1169,  1326,  1177,  1197,  1179,  1180,
    1213,  1131,  1214,  1132,  1206,  1218,  1190,  1223,  1226,  1232,
    1221,  1222,  1331,  1114,  1333,  1238,  1231,  1239,  1200,  1233,
    1234,  1250,  1236,  1257,  1002,  1253,  1277,  1271,  1254,  1274,
    1282,  1281,  1287,  1288,  1299,  1347,  1297,  1350,  1394,  1300,
    1301,  1309,  1313,  1323,  1330,  1340,  1352,  1029,  1235,  1358,
    1220,  1364,  1369,  1372,  1007,  1390,  1388,  1399,  1385,   933,
    1387,  1396,   499,  1402,  1227,  1407,  1412,   713,  1415,  1181,
     828,   493,   714,  1188,   616,  1341,  1392,   495,  1017,   643,
     641,  1371,   496,  1009,  1168,  1280,  1347,   500,  1067,   718,
    1207,  1307,  1124,  1252,  1217,  1242,  1112,  1249,  1246,   517,
     681,  1204,  1391,   733,   757,   734,  1322,  1173,  1225,   890,
    1401,  1398,   658,   978,  1016,  1000,  1240,  1187,   663,  1237,
     945,  1153,   674,   675,  1160,  1270,   946,  1158,  1404,  1216,
    1344,  1290,  1154,  1268,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1228,     0,     0,     0,   562,     0,     0,     0,     0,     0,
     564,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   705,     0,     0,     0,     0,     0,     0,   709,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1273,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   933,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1305,  1306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1311,     0,     0,     0,     0,  1315,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   463,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1332,     0,     0,     0,     0,     0,   933,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1357,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   933,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1395,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1403,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     2,     3,  1409,     4,     0,     0,     0,  1414,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,     0,    78,    79,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,    97,    98,    99,   100,
     101,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,   124,     0,     0,   125,
     126,   127,     0,     0,     0,   128,     0,   129,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   150,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   369,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   372,    28,    29,   374,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,    78,    79,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    91,     0,
      92,    93,    94,    95,     0,    96,     0,     0,     0,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,   109,
     110,   111,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,     0,     0,   128,   466,
     129,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   388,   151,     0,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   369,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   372,    28,
      29,   374,    31,    32,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,     0,    78,    79,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      91,     0,    92,    93,    94,    95,     0,    96,     0,     0,
       0,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,   770,     0,
     128,     0,   129,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   388,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     369,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     372,    28,    29,   374,    31,    32,    33,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,     0,    78,    79,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,     0,    92,    93,    94,    95,     0,    96,
       0,     0,     0,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
       0,     0,     0,   109,   110,   111,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
       0,     0,   128,   776,   129,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   388,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   369,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   372,    28,    29,   374,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,     0,    78,    79,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,     0,    92,    93,    94,    95,
       0,    96,     0,     0,     0,    97,    98,    99,   100,   101,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,   109,   110,   111,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,   793,     0,   128,     0,   129,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   388,   151,     0,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   369,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   372,    28,    29,   374,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,     0,    78,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,     0,     0,     0,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,   124,     0,     0,
     125,   126,   127,     0,   853,     0,   128,     0,   129,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   388,   151,     0,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   369,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   372,    28,    29,   374,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,    78,    79,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    91,     0,
      92,    93,    94,    95,     0,    96,     0,     0,     0,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,   109,
     110,   111,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,   886,     0,   128,     0,
     129,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   388,   151,     0,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   369,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   372,    28,
      29,   374,    31,    32,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,     0,    78,    79,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      91,     0,    92,    93,    94,    95,     0,    96,     0,     0,
       0,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,  1174,     0,
     128,     0,   129,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   388,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     369,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     372,    28,    29,   374,    31,    32,    33,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,     0,    78,    79,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,     0,    92,    93,    94,    95,     0,    96,
       0,     0,     0,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
       0,     0,     0,   109,   110,   111,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
    1199,     0,   128,     0,   129,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   388,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   369,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   372,    28,    29,   374,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,     0,    78,    79,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,     0,    92,    93,    94,    95,
       0,    96,     0,     0,     0,    97,    98,    99,   100,   101,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,   109,   110,   111,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,  1219,     0,   128,     0,   129,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   388,   151,     0,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,     0,    78,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,     0,     0,     0,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,   124,     0,     0,
     125,   126,   127,     0,     0,     0,   128,     0,   129,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   150,   151,     0,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,    78,    79,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    91,     0,
      92,    93,    94,    95,     0,    96,     0,     0,     0,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,   109,
     110,   111,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,     0,     0,   128,     0,
     129,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   388,   151,     0,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   369,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   372,    28,
      29,   374,    31,    32,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,     0,    78,    79,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      91,     0,    92,    93,    94,    95,     0,    96,     0,     0,
       0,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,     0,     0,
     128,     0,   129,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   388,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     0,   358,   359,
     360,     8,   361,   362,    11,   364,    13,    14,    15,    16,
     369,    18,    19,    20,    21,    22,    23,   370,    25,    26,
     372,   373,    29,   374,    31,    32,    33,     0,   375,   376,
      36,   377,   378,   379,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,     0,    78,    79,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,     0,    92,    93,    94,    95,     0,    96,
       0,     0,     0,   383,    98,    99,   100,   101,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
       0,     0,     0,   109,   110,   560,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   561,   124,     0,     0,   125,   126,   127,     0,
       0,     0,   128,     0,   129,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   388,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   389,   160,   391,   162,   392,   393,   165,   166,   167,
     168,   169,   170,   394,   172,   395,   174,   396,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   397,   398,   399,   215,
     216,   217,   218,   219,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,     0,
     358,   359,   360,     8,   361,   362,    11,   364,    13,    14,
      15,    16,   369,    18,    19,    20,    21,    22,    23,   370,
      25,    26,   372,   373,    29,   374,    31,    32,    33,     0,
     375,   376,    36,   377,   378,   379,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,     0,    78,    79,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,     0,    92,    93,    94,    95,
       0,    96,     0,     0,     0,   383,    98,    99,   100,   101,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,   109,   110,   111,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,     0,     0,   128,     0,   129,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   388,   151,     0,   152,   153,   154,   155,
     156,   157,   158,   389,   160,   391,   162,   392,   393,   165,
     166,   167,   168,   169,   170,   394,   172,   395,   174,   396,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   397,   398,
     399,   215,   216,   217,   218,   219,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   779,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   372,    28,    29,   374,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,     0,    78,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,     0,     0,     0,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,   124,     0,     0,
     125,   126,   127,     0,     0,     0,   128,     0,   129,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   388,   151,     0,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     0,   358,   359,   360,     8,   361,   362,
     363,   364,    13,    14,    15,    16,   369,    18,    19,    20,
      21,    22,    23,   370,    25,    26,   372,   373,    29,   374,
      31,    32,    33,     0,   375,   376,    36,   377,   378,   379,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,    78,    79,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    91,     0,
      92,    93,    94,    95,     0,    96,     0,     0,     0,   383,
      98,    99,   100,   101,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,   109,
     110,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,     0,     0,
       0,     0,   125,   126,   127,     0,     0,     0,   128,     0,
     129,   130,   131,     0,     0,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   388,   151,     0,
     152,   153,   154,   155,   156,   157,   158,   389,   160,   391,
     162,   392,   393,   165,   166,   167,   168,   169,   170,   394,
     172,   395,   174,   396,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   397,   398,   399,   215,   216,   217,   218,   219,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       0,     0,     0,     0,     0,     0,   358,   359,   360,     8,
     361,   362,   363,   364,   457,   366,   458,   459,   369,    18,
      19,    20,    21,    22,    23,   370,   460,    26,   372,   373,
      29,   374,    31,    32,    33,     0,   375,   376,    36,   377,
     378,   379,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     0,
      68,     0,    69,    70,    71,   461,     0,     0,    75,    76,
      77,     0,     0,     0,    79,     0,     0,     0,     0,    81,
      82,    83,     0,     0,    86,    87,     0,     0,     0,     0,
       0,     0,    92,    93,    94,    95,     0,    96,     0,     0,
       0,   383,    98,    99,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,     0,   106,   107,   108,     0,     0,
       0,     0,     0,     0,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   386,   118,   119,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,     0,     0,     0,
     128,     0,   129,   130,     0,     0,     0,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   387,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   388,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   389,
     160,   391,   162,   392,   393,   165,   166,   167,   168,   169,
     170,   394,   172,   395,   174,   396,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   397,   398,   399,   215,   216,   217,
     218,   219,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,     0,   358,   359,
     360,     8,   361,   362,   363,   364,   365,   366,   367,   368,
     369,    18,    19,    20,    21,    22,    23,   370,   371,    26,
     372,   373,    29,   374,    31,    32,    33,     0,   375,   376,
      36,   377,   378,   379,    40,    41,    42,    43,    44,    45,
      46,    47,    48,   380,   381,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,     0,    68,     0,    69,    70,    71,   382,     0,     0,
      75,    76,    77,     0,     0,     0,    79,     0,     0,     0,
       0,    81,    82,    83,     0,     0,    86,    87,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,     0,    96,
       0,     0,     0,   383,    98,    99,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,     0,   106,   107,   108,
       0,     0,     0,     0,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   386,   118,   119,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,     0,
       0,     0,   128,     0,   129,     0,     0,     0,     0,     0,
     134,     0,   135,     0,   136,   137,   138,   139,   387,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   388,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   389,   390,   391,   162,   392,   393,   165,   166,   167,
     168,   169,   170,   394,   172,   395,   174,   396,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   397,   398,   399,   215,
     216,   217,   218,   219,   471,     0,     3,     0,     0,     0,
       0,     0,     0,     0,   358,   359,   360,     8,   361,   362,
     363,   364,   365,   366,   367,   368,   369,    18,    19,    20,
      21,    22,    23,   370,   371,    26,   372,   373,    29,   374,
      31,    32,    33,     0,   375,   376,    36,   377,   378,   379,
      40,    41,    42,    43,    44,    45,    46,    47,    48,   380,
     381,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,     0,    68,     0,
      69,    70,    71,   382,     0,     0,    75,    76,    77,     0,
       0,     0,    79,     0,     0,     0,     0,    81,    82,    83,
       0,     0,    86,    87,     0,     0,     0,     0,     0,     0,
      92,    93,    94,    95,     0,    96,     0,     0,     0,   383,
      98,    99,     0,     0,     0,     0,     0,     0,     0,   102,
     103,   104,     0,   106,   107,   108,     0,     0,     0,     0,
       0,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   386,   118,   119,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,     0,     0,     0,   128,     0,
     129,     0,     0,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   387,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   388,   151,     0,
     152,   153,   154,   155,   156,   157,   158,   389,   390,   391,
     162,   392,   393,   165,   166,   167,   168,   169,   170,   394,
     172,   395,   174,   396,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   397,   398,   399,   215,   216,   217,   218,   219,
       3,     0,     0,     0,     0,     0,     0,     0,   358,   359,
     360,     8,   361,   362,   363,   364,   365,   366,   367,   368,
     369,    18,    19,    20,    21,    22,    23,   370,   371,    26,
     372,   373,    29,   374,    31,    32,    33,     0,   375,   376,
      36,   377,   378,   379,    40,    41,    42,    43,    44,    45,
      46,    47,    48,   380,   381,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,     0,    68,     0,    69,    70,    71,   382,     0,     0,
      75,    76,    77,     0,     0,     0,    79,     0,     0,     0,
       0,    81,    82,    83,     0,     0,    86,    87,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,     0,    96,
       0,     0,     0,   383,    98,    99,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,     0,   106,   107,   108,
     384,     0,     0,   385,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   386,   118,   119,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,     0,
       0,     0,   128,     0,   129,     0,     0,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   387,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   388,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   389,   390,   391,   162,   392,   393,   165,   166,   167,
     168,   169,   170,   394,   172,   395,   174,   396,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   397,   398,   399,   215,
     216,   217,   218,   219,     3,     0,     0,     0,     0,     0,
       0,     0,   358,   359,   360,     8,   361,   362,   363,   364,
     365,   366,   367,   368,   369,    18,    19,    20,    21,    22,
      23,   370,   371,    26,   372,   373,    29,   374,    31,    32,
      33,     0,   375,   376,    36,   377,   378,   379,    40,    41,
      42,    43,    44,    45,    46,    47,    48,   380,   381,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,     0,    68,     0,    69,    70,
      71,   382,     0,     0,    75,    76,    77,     0,     0,     0,
      79,     0,     0,     0,     0,    81,    82,    83,     0,     0,
      86,    87,     0,     0,     0,     0,     0,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,   383,    98,    99,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
       0,   106,   107,   108,   454,     0,     0,   455,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   386,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,     0,   128,     0,   129,     0,
       0,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   387,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   388,   151,     0,   152,   153,
     154,   155,   156,   157,   158,   389,   390,   391,   162,   392,
     393,   165,   166,   167,   168,   169,   170,   394,   172,   395,
     174,   396,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     397,   398,   399,   215,   216,   217,   218,   219,     3,     0,
       0,     0,     0,     0,     0,     0,   358,   359,   360,     8,
     361,   362,   363,   364,   365,   366,   367,   368,   369,    18,
      19,    20,    21,    22,    23,   370,   371,    26,   372,   373,
      29,   374,    31,    32,    33,     0,   375,   376,    36,   377,
     378,   379,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   380,   381,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     0,
      68,     0,    69,    70,    71,   382,     0,     0,    75,    76,
      77,     0,     0,     0,    79,     0,     0,     0,     0,    81,
      82,    83,     0,     0,    86,    87,     0,     0,     0,     0,
       0,     0,    92,    93,    94,    95,     0,    96,     0,     0,
       0,   383,    98,    99,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,     0,   106,   107,   108,     0,     0,
       0,     0,     0,     0,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   386,   118,   119,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,     0,     0,     0,
     128,   586,   129,     0,     0,     0,     0,     0,   587,     0,
     135,     0,   136,   137,   138,   139,   387,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   388,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   389,
     390,   391,   162,   392,   393,   165,   166,   167,   168,   169,
     170,   394,   172,   395,   174,   396,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   397,   398,   399,   215,   216,   217,
     218,   219,     3,     0,     0,     0,     0,     0,     0,     0,
     358,   359,   360,     8,   361,   362,   363,   364,   365,   366,
     367,   368,   369,    18,    19,    20,    21,    22,    23,   370,
     371,    26,   372,   373,    29,   374,    31,    32,    33,     0,
     375,   376,    36,   377,   378,   379,    40,    41,    42,    43,
      44,    45,    46,    47,    48,   380,   381,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,     0,    68,     0,    69,    70,    71,   382,
       0,     0,    75,    76,    77,     0,     0,     0,    79,     0,
       0,     0,     0,    81,    82,    83,     0,     0,    86,    87,
       0,     0,     0,     0,     0,     0,    92,    93,    94,    95,
       0,    96,     0,     0,     0,   383,    98,    99,     0,     0,
       0,     0,     0,     0,     0,   102,   103,   104,     0,   106,
     107,   108,     0,     0,     0,     0,     0,     0,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   386,   118,   119,
     120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,     0,     0,     0,   128,   677,   129,     0,     0,     0,
       0,     0,   678,     0,   135,     0,   136,   137,   138,   139,
     387,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   388,   151,     0,   152,   153,   154,   155,
     156,   157,   158,   389,   390,   391,   162,   392,   393,   165,
     166,   167,   168,   169,   170,   394,   172,   395,   174,   396,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   397,   398,
     399,   215,   216,   217,   218,   219,     3,     0,     0,     0,
       0,     0,     0,     0,   358,   359,   360,     8,   361,   362,
     363,   364,   457,   366,   458,   459,   369,    18,    19,    20,
      21,    22,    23,   370,   460,    26,   372,   373,    29,   374,
      31,    32,    33,     0,   375,   376,    36,   377,   378,   379,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,     0,    68,     0,
      69,    70,    71,   461,     0,     0,    75,    76,    77,     0,
       0,     0,    79,     0,     0,     0,     0,    81,    82,    83,
       0,     0,    86,    87,  1170,     0,     0,     0,     0,     0,
      92,    93,    94,    95,     0,    96,     0,     0,     0,   383,
      98,    99,     0,     0,     0,     0,     0,     0,     0,   102,
     103,   104,     0,   106,   107,   927,     0,     0,     0,     0,
       0,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   386,   118,   119,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,     0,     0,     0,   128,     0,
     129,   130,     0,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   387,   141,   142,   143,   144,   145,
     146,     0,     0,   928,   148,     0,     0,   388,   151,     0,
     152,   153,   154,   155,   156,   157,   158,   389,   160,   391,
     162,   392,   393,   165,   166,   167,   168,   169,   170,   394,
     172,   395,   174,   396,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   397,   398,   399,   215,   216,   217,   218,   219,
       3,     0,     0,     0,     0,     0,     0,     0,   358,   359,
     360,     8,   361,   362,   363,   364,   457,   366,   458,   459,
     369,    18,    19,    20,    21,    22,    23,   370,   460,    26,
     372,   373,    29,   374,    31,    32,    33,     0,   375,   376,
      36,   377,   378,   379,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,     0,    68,     0,    69,    70,    71,   461,     0,     0,
      75,    76,    77,     0,     0,     0,    79,     0,     0,     0,
       0,    81,    82,    83,     0,     0,    86,    87,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,     0,    96,
       0,     0,     0,   383,    98,    99,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,     0,   106,   107,   927,
       0,     0,     0,     0,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   386,   118,   119,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,     0,
       0,     0,   128,     0,   129,   130,     0,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   387,   141,
     142,   143,   144,   145,   146,     0,     0,   928,   148,     0,
       0,   388,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   389,   160,   391,   162,   392,   393,   165,   166,   167,
     168,   169,   170,   394,   172,   395,   174,   396,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   397,   398,   399,   215,
     216,   217,   218,   219,     3,     0,     0,     0,     0,     0,
       0,     0,   358,   359,   360,     8,   361,   362,   363,   364,
     457,   366,   458,   459,   369,    18,    19,    20,    21,    22,
      23,   370,   460,    26,   372,   373,    29,   374,    31,    32,
      33,     0,   375,   376,    36,   377,   378,   379,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,     0,    68,     0,    69,    70,
      71,   461,     0,     0,    75,    76,    77,     0,     0,     0,
      79,     0,     0,     0,     0,    81,    82,    83,     0,     0,
      86,    87,     0,     0,     0,     0,     0,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,   383,    98,    99,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
       0,   106,   107,   927,     0,     0,     0,     0,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   386,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,     0,   128,     0,   129,   130,
       0,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   387,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   388,   151,     0,   152,   153,
     154,   155,   156,   157,   158,   389,   160,   391,   162,   392,
     393,   165,   166,   167,   168,   169,   170,   394,   172,   395,
     174,   396,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     397,   398,   399,   215,   216,   217,   218,   219,     3,     0,
       0,     0,     0,     0,     0,     0,   358,   359,   360,     8,
     361,   362,   363,   364,   365,   366,   367,   368,   369,    18,
      19,    20,    21,    22,    23,   370,   371,    26,   372,   373,
      29,   374,    31,    32,    33,     0,   375,   376,    36,   377,
     378,   379,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   380,   381,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     0,
      68,     0,    69,    70,    71,   382,     0,     0,    75,    76,
      77,     0,     0,     0,    79,     0,     0,     0,     0,    81,
      82,    83,     0,     0,    86,    87,     0,     0,     0,     0,
       0,     0,    92,    93,    94,    95,     0,    96,     0,     0,
       0,   383,    98,    99,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,     0,   106,   107,   108,     0,     0,
       0,     0,     0,     0,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   386,   118,   119,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,     0,     0,     0,
     128,     0,   129,     0,     0,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   387,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   388,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   389,
     390,   391,   162,   392,   393,   165,   166,   167,   168,   169,
     170,   394,   172,   395,   174,   396,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   397,   398,   399,   215,   216,   217,
     218,   219
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        13,   684,   838,   544,   415,   726,   860,   349,   658,   502,
     352,   109,   968,   663,   893,   426,   133,   548,   549,   550,
     551,   766,   767,   663,    74,   782,   422,   956,   524,   440,
     441,    20,   748,    66,    94,    39,    40,    41,    42,    43,
      44,    92,   438,    94,    21,   766,   767,   443,    52,   105,
      94,    18,    20,    20,    58,   527,    92,   529,   530,    72,
     532,    74,   534,   138,     7,    69,    70,   105,   105,    73,
     542,   543,    76,    77,   142,    88,    34,  1086,    47,   490,
     491,   492,    39,    40,    41,    42,    43,    44,   105,    20,
     730,   142,   732,   105,    20,    52,   817,   110,   142,  1118,
    1119,    94,   138,   105,   446,   109,   110,   111,   236,   237,
      94,   124,    91,    71,   105,   142,   126,   130,   115,   108,
      77,    92,   153,   148,     4,    18,   148,   212,     8,   105,
     258,   120,   105,    94,    29,   105,    59,   479,   480,   170,
     482,   483,   484,   485,   141,   182,   488,   185,    92,   171,
     111,   155,   109,   110,   111,   144,   125,   154,   151,   148,
     245,   503,   151,   161,   105,   182,     4,     8,     9,   181,
       8,   513,   514,   823,   230,   232,   293,   148,   176,   212,
     111,   191,   105,   185,     8,     9,   261,   247,   248,  1043,
     181,   188,    98,   261,    92,  1031,   111,  1076,   177,   259,
     116,     8,     9,   744,   745,   181,   889,  1086,   181,   620,
     261,   215,   245,   181,   181,   185,  1225,   261,    62,    63,
       8,     9,   872,   181,   155,   261,   169,  1246,  1157,   155,
     870,   208,   105,   575,   261,   239,   732,   126,  1194,   119,
     181,   121,   958,   654,   143,   216,   217,   992,   298,   129,
      29,   301,  1009,   266,   650,   148,   354,   653,   151,   357,
     101,   160,   251,   247,   248,   181,   132,   739,   148,   213,
     214,   992,   116,   277,   278,   279,   280,   101,   119,   104,
     121,   119,   239,   121,   228,   298,   384,   105,   301,   186,
     187,   129,   105,   105,   101,   119,   132,   121,   123,   105,
      34,   941,   191,   401,   402,    39,   404,   148,   181,   145,
     148,   152,   119,   101,   121,   213,   214,   116,   105,   105,
     277,   278,   279,   280,   148,   240,   232,   168,   152,   195,
     228,   119,   105,   121,   240,    20,   105,   435,   148,   437,
     353,   148,     8,    77,   168,   152,  1225,   253,   189,   255,
     789,   127,   791,    19,   269,   270,   454,   272,   273,   265,
     148,   168,   268,   181,   152,   189,   207,    92,   181,   181,
     104,   469,   385,   140,    92,   181,     8,   475,    50,   721,
     168,   180,   189,   207,  1340,    57,   728,    19,    60,    61,
     143,   133,    92,   406,   181,   181,    68,   220,   155,   412,
     207,   189,   225,   170,   176,   418,   148,   160,   181,   185,
      94,   163,   181,   954,   176,   826,   827,   142,   190,   207,
     831,   188,   915,   108,   142,   966,   957,   111,   190,   442,
     164,   444,   445,   133,   814,   120,  1361,  1182,   138,   452,
     153,   133,   455,   882,   196,   884,   138,  1301,   828,   566,
     567,   195,   465,   119,   865,   121,    98,   170,    38,   144,
     204,  1182,   151,   148,   130,   563,   151,   151,    48,   111,
     568,    64,    65,   151,   487,    94,   489,   819,   576,    98,
     193,  1406,   148,   825,   582,   583,  1411,   119,   195,   121,
    1415,   589,   164,    93,   166,   133,   148,   204,   130,   151,
     138,    94,    64,    65,   104,    67,   848,   569,   180,   240,
     572,   257,   574,   257,   114,   151,   148,   263,    94,   263,
     862,   863,    98,   123,   866,   271,   868,   271,   257,   300,
    1366,  1181,    94,   262,   206,   306,  1281,   116,   269,   270,
    1223,   272,   273,   116,   163,  1228,   888,  1285,  1353,  1354,
     148,   649,  1290,   151,   116,   124,   125,   899,   900,   901,
    1281,   903,   904,   905,   906,   907,   908,   116,   910,   911,
     193,  1376,   195,    39,    40,    41,   918,  1382,    44,   407,
     148,   204,   680,   411,   597,  1330,    51,   163,   238,    54,
     238,   241,   220,   241,   222,   937,    60,   939,   940,   216,
     217,   218,   615,   278,   279,   280,   220,   151,   222,  1330,
     151,  1142,   227,   232,   229,   227,   116,   229,  1149,  1150,
    1161,   240,   148,   242,   243,   244,    14,  1038,  1311,    64,
      65,   148,  1315,   252,   253,   210,   255,   124,   125,   981,
     151,   260,   220,   409,   410,   743,   265,   266,   267,   268,
     148,   128,   552,   553,   667,   116,   232,   545,   546,   136,
     137,   116,   139,     0,   240,   278,   242,   243,   244,   146,
     683,   554,   555,   150,  1357,   152,   278,   253,  1020,   255,
     157,   768,   769,   278,   260,   783,  1283,  1284,   185,   265,
     266,   267,   268,  1035,   185,   162,   173,  1347,    90,   250,
      74,   194,    99,  1114,   100,   149,  1048,   720,   151,   148,
     148,  1053,  1054,   726,  1056,   148,    39,    39,   181,  1061,
     197,   198,   199,   200,   201,   202,    20,   181,   147,  1260,
    1261,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,   116,    18,   278,   148,   267,   267,   116,   116,   148,
     151,   151,   181,   766,   767,   768,   769,   151,   151,    25,
     151,    15,   208,   181,    20,   181,   226,    38,  1110,   164,
     116,   105,    92,   226,    92,   165,   789,    92,   791,  1121,
     165,   148,    20,   181,   105,   151,   105,   123,   128,   178,
     155,  1202,  1134,   155,   181,  1137,   178,  1139,  1329,   178,
     178,   178,    20,   281,   817,   181,   178,    94,   181,    34,
     181,    94,   128,   138,   105,   178,   165,   181,    92,   178,
     181,   181,   178,   178,   232,  1167,   138,   178,   185,   142,
     116,   116,   116,   256,   220,   116,   268,   249,   251,  1250,
     178,    98,   148,   138,   179,   178,   178,   178,   178,   128,
      92,   271,   148,   270,   178,   128,   138,   271,   155,   128,
      94,   116,   142,   192,   116,   245,   138,   178,  1210,   882,
    1212,   884,    25,   148,    20,   116,  1218,   116,   148,    77,
     234,   105,   105,   151,   151,   178,    53,   271,   246,   142,
    1232,  1233,  1234,  1235,  1236,   142,  1238,   995,   246,   142,
     140,   138,    92,   181,   181,   140,    20,    20,   105,  1007,
     923,   138,   142,   926,   178,  1257,   181,   165,   181,   181,
     116,   934,   116,   936,   185,    67,   271,   128,     6,   228,
     181,   181,  1274,   104,  1276,   180,   185,   151,  1036,   228,
     228,   104,   232,   142,   116,   181,   178,   264,   181,   180,
     178,    92,    20,    20,   122,  1297,   151,  1299,  1369,   178,
      94,   178,   178,   178,    92,    20,    65,    94,   228,   191,
    1068,   180,   104,   116,   148,   180,   116,   177,   191,   992,
     191,    91,   226,   191,  1082,   116,   116,   501,   181,  1002,
     619,   220,   501,  1016,   420,   254,   254,   223,   818,   429,
     425,  1348,   223,   800,   985,  1183,  1348,   227,   877,   505,
    1051,  1216,   926,  1123,  1063,  1111,   918,  1121,  1118,   265,
     465,  1045,  1364,   525,   547,   526,  1239,   993,  1076,   684,
    1382,  1376,  1045,   769,   817,   791,  1108,  1015,  1051,  1104,
     744,   954,   453,   453,   966,  1161,   745,   958,  1390,  1062,
    1295,  1193,   955,  1156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1083,    -1,    -1,    -1,   286,    -1,    -1,    -1,    -1,    -1,
     290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1104,    -1,    -1,    -1,    -1,    -1,    -1,  1111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1182,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1213,  1214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1224,    -1,    -1,    -1,    -1,  1229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1275,    -1,    -1,    -1,    -1,    -1,  1281,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1312,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1330,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1372,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1388,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,  1407,    20,    -1,    -1,    -1,  1412,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,    -1,   122,   123,   124,
     125,    -1,   127,    -1,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,   170,   171,    -1,    -1,   174,
     175,   176,    -1,    -1,    -1,   180,    -1,   182,   183,   184,
      -1,   186,   187,   188,    -1,   190,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,    -1,    -1,
     205,   206,   207,    -1,   209,   210,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,    -1,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,   120,    -1,
     122,   123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,   170,   171,
      -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,   181,
     182,   183,   184,    -1,   186,   187,   188,    -1,   190,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,    -1,   205,   206,   207,    -1,   209,   210,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,   250,   251,
      -1,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
     120,    -1,   122,   123,   124,   125,    -1,   127,    -1,    -1,
      -1,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
      -1,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
     170,   171,    -1,    -1,   174,   175,   176,    -1,   178,    -1,
     180,    -1,   182,   183,   184,    -1,   186,   187,   188,    -1,
     190,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,    -1,   205,   206,   207,    -1,   209,
     210,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
     250,   251,    -1,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,   120,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,   171,    -1,    -1,   174,   175,   176,    -1,
      -1,    -1,   180,   181,   182,   183,   184,    -1,   186,   187,
     188,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,   205,   206,   207,
      -1,   209,   210,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,   250,   251,    -1,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,   103,   104,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,   120,    -1,   122,   123,   124,   125,
      -1,   127,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,   170,   171,    -1,    -1,   174,   175,
     176,    -1,   178,    -1,   180,    -1,   182,   183,   184,    -1,
     186,   187,   188,    -1,   190,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,    -1,    -1,   205,
     206,   207,    -1,   209,   210,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,   250,   251,    -1,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,   120,    -1,   122,   123,
     124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,   170,   171,    -1,    -1,
     174,   175,   176,    -1,   178,    -1,   180,    -1,   182,   183,
     184,    -1,   186,   187,   188,    -1,   190,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,    -1,
      -1,   205,   206,   207,    -1,   209,   210,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,   250,   251,    -1,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,   120,    -1,
     122,   123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,   170,   171,
      -1,    -1,   174,   175,   176,    -1,   178,    -1,   180,    -1,
     182,   183,   184,    -1,   186,   187,   188,    -1,   190,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,    -1,   205,   206,   207,    -1,   209,   210,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,   250,   251,
      -1,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
     120,    -1,   122,   123,   124,   125,    -1,   127,    -1,    -1,
      -1,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
      -1,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
     170,   171,    -1,    -1,   174,   175,   176,    -1,   178,    -1,
     180,    -1,   182,   183,   184,    -1,   186,   187,   188,    -1,
     190,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,    -1,   205,   206,   207,    -1,   209,
     210,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
     250,   251,    -1,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,   120,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,   171,    -1,    -1,   174,   175,   176,    -1,
     178,    -1,   180,    -1,   182,   183,   184,    -1,   186,   187,
     188,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,   205,   206,   207,
      -1,   209,   210,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,   250,   251,    -1,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,   103,   104,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,   120,    -1,   122,   123,   124,   125,
      -1,   127,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,   170,   171,    -1,    -1,   174,   175,
     176,    -1,   178,    -1,   180,    -1,   182,   183,   184,    -1,
     186,   187,   188,    -1,   190,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,    -1,    -1,   205,
     206,   207,    -1,   209,   210,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,   250,   251,    -1,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,   120,    -1,   122,   123,
     124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,   170,   171,    -1,    -1,
     174,   175,   176,    -1,    -1,    -1,   180,    -1,   182,   183,
     184,    -1,   186,   187,   188,    -1,   190,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,    -1,
      -1,   205,   206,   207,    -1,   209,   210,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,   250,   251,    -1,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,   120,    -1,
     122,   123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,   170,   171,
      -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,    -1,
     182,   183,   184,    -1,   186,   187,   188,    -1,   190,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,    -1,   205,   206,   207,    -1,   209,   210,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,   250,   251,
      -1,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
     120,    -1,   122,   123,   124,   125,    -1,   127,    -1,    -1,
      -1,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
      -1,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
     170,   171,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,
     180,    -1,   182,   183,   184,    -1,   186,   187,   188,    -1,
     190,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,    -1,   205,   206,   207,    -1,   209,
     210,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
     250,   251,    -1,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,   120,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,   171,    -1,    -1,   174,   175,   176,    -1,
      -1,    -1,   180,    -1,   182,   183,   184,    -1,   186,   187,
     188,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,   205,   206,   207,
      -1,   209,   210,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,   250,   251,    -1,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,   103,   104,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,   120,    -1,   122,   123,   124,   125,
      -1,   127,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,   170,   171,    -1,    -1,   174,   175,
     176,    -1,    -1,    -1,   180,    -1,   182,   183,   184,    -1,
     186,   187,   188,    -1,   190,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,    -1,    -1,   205,
     206,   207,    -1,   209,   210,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,   250,   251,    -1,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,   120,    -1,   122,   123,
     124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,   170,   171,    -1,    -1,
     174,   175,   176,    -1,    -1,    -1,   180,    -1,   182,   183,
     184,    -1,   186,   187,   188,    -1,   190,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,    -1,
      -1,   205,   206,   207,    -1,   209,   210,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,   250,   251,    -1,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,   120,    -1,
     122,   123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,   151,
     152,    -1,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,    -1,   205,   206,   207,    -1,   209,   210,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,   250,   251,
      -1,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      90,    -1,    92,    93,    94,    95,    -1,    -1,    98,    99,
     100,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,    -1,   127,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,   142,   143,    -1,   145,   146,   147,    -1,    -1,
      -1,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,
     180,    -1,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
     190,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,    -1,   205,   206,    -1,    -1,   209,
     210,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
     250,   251,    -1,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    90,    -1,    92,    93,    94,    95,    -1,    -1,
      98,    99,   100,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,   109,   110,   111,    -1,    -1,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,    -1,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,   180,    -1,   182,    -1,    -1,    -1,    -1,    -1,
     188,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,   205,   206,    -1,
      -1,   209,   210,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,   250,   251,    -1,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,    16,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    -1,    90,    -1,
      92,    93,    94,    95,    -1,    -1,    98,    99,   100,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,    -1,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,   180,    -1,
     182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,    -1,   205,   206,    -1,    -1,   209,   210,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,   250,   251,
      -1,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    90,    -1,    92,    93,    94,    95,    -1,    -1,
      98,    99,   100,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,   109,   110,   111,    -1,    -1,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,    -1,   145,   146,   147,
     148,    -1,    -1,   151,    -1,    -1,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,   180,    -1,   182,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,   205,   206,    -1,
      -1,   209,   210,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,   250,   251,    -1,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    -1,    90,    -1,    92,    93,
      94,    95,    -1,    -1,    98,    99,   100,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,    -1,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,
     124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
      -1,   145,   146,   147,   148,    -1,    -1,   151,    -1,    -1,
     154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,    -1,    -1,    -1,   180,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,    -1,
      -1,   205,   206,    -1,    -1,   209,   210,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,   250,   251,    -1,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      90,    -1,    92,    93,    94,    95,    -1,    -1,    98,    99,
     100,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,    -1,   127,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,   142,   143,    -1,   145,   146,   147,    -1,    -1,
      -1,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,    -1,    -1,   188,    -1,
     190,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,    -1,   205,   206,    -1,    -1,   209,
     210,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
     250,   251,    -1,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    90,    -1,    92,    93,    94,    95,
      -1,    -1,    98,    99,   100,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,   110,   111,    -1,    -1,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,
      -1,   127,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   141,   142,   143,    -1,   145,
     146,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     176,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
      -1,    -1,   188,    -1,   190,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,    -1,    -1,   205,
     206,    -1,    -1,   209,   210,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,   250,   251,    -1,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    -1,    90,    -1,
      92,    93,    94,    95,    -1,    -1,    98,    99,   100,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,    -1,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
     122,   123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,    -1,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,   180,    -1,
     182,   183,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,    -1,   205,   206,    -1,    -1,   209,   210,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,   250,   251,
      -1,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    90,    -1,    92,    93,    94,    95,    -1,    -1,
      98,    99,   100,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,   109,   110,   111,    -1,    -1,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,    -1,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,   180,    -1,   182,   183,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,   205,   206,    -1,
      -1,   209,   210,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,   250,   251,    -1,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    -1,    90,    -1,    92,    93,
      94,    95,    -1,    -1,    98,    99,   100,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,    -1,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,
     124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
      -1,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
     154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,    -1,    -1,    -1,   180,    -1,   182,   183,
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,    -1,
      -1,   205,   206,    -1,    -1,   209,   210,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,   250,   251,    -1,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      90,    -1,    92,    93,    94,    95,    -1,    -1,    98,    99,
     100,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,    -1,   127,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,   142,   143,    -1,   145,   146,   147,    -1,    -1,
      -1,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,
     180,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,    -1,   205,   206,    -1,    -1,   209,
     210,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
     250,   251,    -1,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281
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
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   103,   104,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   120,   122,   123,   124,   125,   127,   131,   132,   133,
     134,   135,   141,   142,   143,   144,   145,   146,   147,   151,
     152,   153,   154,   155,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   170,   171,   174,   175,   176,   180,   182,
     183,   184,   186,   187,   188,   190,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   205,   206,   207,
     209,   210,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   250,
     251,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   328,   329,   334,   336,
     343,   345,   350,   351,   352,   353,   354,   355,   363,   364,
     366,   367,   368,   373,   375,   377,   378,   379,   384,   405,
     408,   411,   412,   413,   414,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   461,   462,   463,   477,   478,
     480,   481,   482,   483,   484,   485,   486,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   505,   506,   507,
     508,   509,   510,   511,   514,   519,   520,   148,   346,   232,
      29,    29,   151,    92,   148,   216,   217,   151,    26,    27,
      28,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      45,    46,    48,    49,    51,    56,    57,    59,    60,    61,
      71,    72,    95,   131,   148,   151,   163,   196,   209,   219,
     220,   221,   223,   224,   231,   233,   235,   274,   275,   276,
     519,   148,   148,   151,   148,   151,    39,    40,    41,    42,
      43,    44,    52,    58,    69,    70,    73,    76,    77,   109,
     110,   111,   155,   215,   239,   277,   278,   279,   280,   335,
     337,   338,   339,   356,   357,   151,    18,   148,   151,   518,
      51,    54,   116,   155,   116,   116,   148,    62,    63,   116,
     370,    60,   151,   151,   148,   151,   519,    34,    36,    37,
      46,    95,   445,   519,   519,   116,   181,   364,   519,   148,
      14,    16,   519,   519,   437,   148,    21,   208,   210,   220,
     222,   151,   220,   222,   220,   220,   225,   116,   148,   116,
     278,   278,   278,   299,     0,   301,   302,    38,    48,   304,
     363,   185,   185,   105,   185,   365,    50,    57,    60,    61,
      68,   164,   166,   180,   206,   369,   374,   375,   376,   393,
     394,   398,   380,   381,   519,   162,    90,   128,   136,   137,
     139,   146,   150,   152,   157,   173,   197,   198,   199,   200,
     201,   202,   429,   430,   250,   153,   170,   193,   115,   141,
     154,   188,   195,   204,   132,   145,    74,   194,    99,   100,
     153,   170,   428,   148,   434,   437,   186,   187,   149,   449,
     450,   445,   449,   445,   449,   151,   347,   367,   367,   503,
     519,   364,   148,   148,   364,   364,   181,   188,   519,   148,
     364,   364,   181,   364,   181,   519,   357,    39,   358,   356,
     356,   357,   519,   176,   190,   163,   196,    20,   517,   161,
     176,   176,   190,   519,   147,   116,   333,    34,    39,    77,
     104,   164,   518,   216,   217,   218,    98,   232,   240,   253,
     255,   265,   268,   532,   533,   534,   535,   536,   539,   544,
     545,   338,   517,   339,   364,   364,    20,   181,   518,   148,
     155,   517,   111,   155,   327,   517,   406,   407,   519,   518,
     519,   385,   387,   519,   367,   267,   267,   116,   388,   116,
     519,    34,    71,   181,   501,   502,   364,   181,   188,   519,
     148,   406,   181,    25,   465,   466,   467,   364,     7,   169,
      15,   181,   364,   208,    20,   367,   367,   181,   367,   367,
     367,   367,   226,   512,   513,   519,   367,   386,   392,   519,
     517,   517,   517,   306,   307,    38,   308,   367,   366,   164,
     116,   165,   165,   367,   367,   105,    92,    94,   142,   261,
     382,   383,   488,   413,   414,   416,   416,   416,   416,   415,
     416,   416,   416,   148,   151,   251,   452,   521,   523,   524,
     525,   526,   527,   528,   529,   419,   419,   418,   420,   420,
     420,   420,   421,   421,   422,   422,   226,    92,    92,    92,
     178,   364,   437,   437,   364,   450,   181,   367,   460,    38,
     348,   364,   181,   148,   178,   364,   364,   181,   178,   105,
     181,   105,   181,   178,   364,   178,   178,   178,   151,   344,
     519,    20,   105,   105,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   310,   311,   312,    92,   133,   138,
     330,   331,   332,   519,   133,   138,   155,   155,   310,   517,
     123,   128,   238,   241,   111,   240,   269,   270,   272,   273,
     238,   241,    20,   240,   269,   270,   272,   273,   281,   181,
     178,   181,   181,   178,   364,   518,    94,    34,   518,   517,
      94,   105,   182,   142,   488,   128,   138,   105,   138,   383,
     488,   178,   519,    66,   212,   245,   371,   372,   181,   181,
     181,   178,   105,   181,   105,   181,   178,   364,   182,   519,
     466,   467,   126,   191,   178,   178,   127,   185,    92,   213,
     214,   228,    92,   213,   214,   228,    92,   232,   220,   105,
     230,   138,   178,    59,   105,   185,   111,   185,   165,   519,
     367,   399,   400,   116,   395,   396,   116,   147,   205,   489,
     491,   492,   493,   519,   116,   367,   116,   142,   383,   142,
     142,   382,   383,   416,   364,   521,   527,   268,   555,    94,
     163,   242,   243,   244,   252,   260,   266,   267,   522,   530,
     531,   532,   546,   549,   550,   552,   249,   251,   256,   551,
     236,   237,   258,   547,   489,   489,   487,   492,   487,   178,
     179,   105,   181,   333,   349,   105,   185,   178,   346,   364,
     178,   178,    98,   409,   410,   148,   503,   504,   519,   503,
     504,   178,   116,   181,   359,   360,   133,   148,   362,   344,
     143,   160,   143,   160,   311,   128,   491,   332,   367,   488,
     138,   367,   517,   517,   124,   125,   517,   270,   271,    94,
     111,   151,   538,   271,   367,   192,   148,   178,   128,   326,
     517,   155,   128,    94,   326,   116,   367,   367,   142,   517,
     367,   116,   367,   138,   138,   383,   142,   488,   245,    64,
      65,    67,   116,   382,   389,   390,   391,   372,   148,   503,
     503,   178,   367,    25,   467,   126,   191,     8,     9,   101,
     119,   121,   148,   189,   361,   462,   464,   475,   476,   479,
      20,   227,   229,   367,   367,   367,   227,   229,   367,   367,
     367,   367,   367,   367,   116,   367,   367,   234,   515,   516,
     148,   116,   399,    93,   104,   114,   123,   401,   402,   403,
     404,   105,   519,   105,   381,   151,   151,   140,   170,   188,
     490,   519,   519,   367,   142,   367,   367,   142,   383,   142,
     178,   181,   246,   212,   245,   257,   262,   554,    94,   247,
     248,   548,   246,   524,   554,   417,   420,   266,   530,   532,
     525,   142,   548,   271,    53,   140,   367,   138,   349,   178,
     116,   489,   111,   410,   178,   364,   181,   181,   140,   181,
     181,   519,    92,   105,   181,   364,   346,   505,   331,   367,
     271,    94,   151,   541,    20,   111,   538,   165,   367,   178,
     364,   517,   105,   326,   407,   367,   185,   387,   367,   367,
     138,   367,   142,   116,   116,   367,   519,   391,    67,   178,
     364,   181,   181,   128,   189,   464,     6,   364,   519,   189,
     475,   185,   228,   228,   228,   228,   232,   513,   180,   151,
     516,   367,   392,   517,   124,   125,   403,   404,   404,   400,
     104,   397,   396,   181,   181,   367,   367,   142,   367,   420,
      47,   125,   420,   420,   257,   263,   271,   553,   553,   417,
     526,   264,   367,   519,   180,   116,   180,   178,   488,   489,
     360,    92,   178,   132,   195,   540,   543,    20,    20,   542,
     540,   259,   548,   105,   181,   105,   181,   151,   342,   122,
     178,    94,   517,   367,   367,   519,   519,   390,   367,   178,
     467,   519,   189,   178,   467,   519,   367,   367,   367,   367,
     367,   367,   446,   178,   404,   517,   367,   420,   420,   193,
      92,   367,   519,   367,   489,   541,   541,   543,    20,   181,
      20,   254,   537,   538,   537,   340,   341,   367,   105,   181,
     367,   326,    65,    91,   177,   468,   467,   519,   191,   467,
     105,   181,   420,   489,   180,   548,   105,   181,   181,   104,
     488,   340,   116,     4,   129,   471,   472,   474,   476,    19,
     130,   469,   470,   473,   476,   191,   467,   191,   116,   362,
     180,   367,   254,   538,   517,   519,    91,   129,   474,   177,
     130,   473,   191,   519,   367,   105,   181,   116,   362,   519,
     105,   181,   116,   362,   519,   181,   362
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
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   297,   298,   298,   299,   299,   299,   299,   300,   300,
     301,   301,   302,   303,   304,   304,   304,   305,   305,   306,
     306,   307,   307,   307,   307,   308,   308,   308,   308,   308,
     308,   308,   309,   309,   310,   310,   311,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   313,   313,   313,
     313,   313,   313,   313,   313,   314,   314,   315,   316,   316,
     317,   317,   318,   319,   320,   320,   321,   321,   322,   322,
     322,   322,   323,   324,   325,   325,   325,   325,   326,   326,
     327,   327,   328,   328,   328,   328,   329,   330,   330,   331,
     331,   331,   332,   333,   333,   334,   334,   334,   335,   335,
     336,   337,   337,   338,   338,   339,   340,   340,   341,   341,
     342,   342,   343,   343,   344,   344,   344,   344,   345,   346,
     347,   347,   348,   348,   349,   349,   350,   351,   352,   353,
     353,   354,   354,   354,   355,   355,   355,   356,   356,   356,
     356,   357,   357,   358,   359,   359,   360,   360,   361,   362,
     363,   364,   364,   365,   365,   366,   366,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   368,   369,   370,   370,   371,
     371,   371,   372,   372,   373,   373,   374,   375,   375,   375,
     376,   376,   376,   376,   376,   377,   377,   378,   378,   379,
     380,   380,   381,   381,   381,   381,   381,   381,   381,   381,
     382,   383,   384,   385,   385,   386,   386,   387,   387,   387,
     387,   388,   388,   389,   389,   389,   390,   390,   390,   391,
     391,   391,   392,   393,   394,   395,   395,   396,   396,   397,
     398,   398,   399,   399,   400,   400,   401,   401,   401,   401,
     401,   401,   401,   402,   402,   403,   403,   404,   405,   405,
     406,   406,   407,   407,   408,   408,   409,   409,   410,   410,
     411,   412,   412,   413,   413,   414,   414,   414,   414,   414,
     415,   414,   414,   414,   414,   416,   416,   416,   417,   417,
     418,   418,   418,   419,   419,   419,   419,   419,   420,   420,
     420,   421,   421,   421,   422,   422,   423,   423,   424,   424,
     425,   425,   426,   426,   427,   427,   427,   427,   428,   428,
     428,   429,   429,   429,   429,   429,   429,   430,   430,   430,
     431,   431,   431,   431,   432,   432,   433,   433,   434,   434,
     435,   435,   435,   435,   436,   437,   437,   437,   438,   438,
     439,   439,   439,   439,   440,   440,   441,   441,   441,   441,
     441,   441,   441,   442,   442,   443,   443,   444,   444,   444,
     444,   444,   445,   445,   446,   446,   447,   447,   447,   448,
     448,   449,   449,   450,   451,   451,   451,   451,   451,   451,
     451,   451,   452,   452,   453,   453,   453,   454,   455,   455,
     456,   457,   458,   459,   459,   460,   460,   461,   461,   462,
     462,   462,   463,   463,   463,   463,   463,   463,   464,   464,
     465,   465,   466,   467,   467,   468,   468,   469,   469,   470,
     470,   470,   470,   471,   471,   472,   472,   472,   472,   473,
     473,   474,   474,   475,   475,   475,   475,   476,   476,   476,
     476,   477,   477,   478,   478,   479,   480,   480,   480,   480,
     480,   480,   481,   482,   482,   482,   482,   483,   483,   483,
     483,   484,   485,   486,   486,   486,   486,   487,   487,   488,
     489,   489,   489,   490,   490,   490,   491,   491,   491,   492,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   494,
     495,   495,   495,   496,   497,   498,   498,   498,   499,   499,
     499,   499,   499,   500,   501,   501,   501,   501,   501,   501,
     501,   502,   503,   504,   505,   506,   506,   506,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   508,   508,
     509,   509,   510,   511,   512,   512,   513,   514,   515,   515,
     516,   516,   516,   516,   517,   518,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   520,   520,   521,   521,   521,   521,   522,   522,
     522,   522,   523,   523,   524,   524,   525,   525,   526,   526,
     527,   527,   527,   528,   528,   529,   529,   530,   530,   530,
     530,   530,   531,   532,   532,   532,   532,   532,   532,   532,
     533,   533,   533,   533,   534,   534,   534,   534,   535,   535,
     536,   536,   536,   536,   536,   536,   536,   537,   537,   538,
     538,   538,   538,   539,   539,   539,   539,   539,   540,   540,
     541,   541,   542,   542,   543,   543,   544,   545,   545,   546,
     546,   546,   547,   547,   547,   547,   547,   548,   548,   548,
     548,   549,   550,   551,   552,   552,   553,   553,   553,   554,
     554,   555
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     1,     2,     4,     6,
       2,     1,     2,     6,     2,     2,     4,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     3,     3,
       5,     5,     4,     3,     3,     3,     5,     5,     5,     5,
       5,     5,     4,     3,     3,     4,     5,     6,     1,     3,
       3,     3,     3,     6,     5,     8,     4,     3,     1,     1,
       1,     2,     2,     2,     3,     5,     4,     6,     1,     1,
       2,     1,     2,     1,     2,     7,     1,     3,     1,     2,
       2,     3,     3,     3,     2,     3,     4,     5,     2,     4,
       3,     0,     3,     2,     1,     3,     5,     3,     5,     2,
       2,     3,     3,     3,     2,     3,     3,     1,     2,     2,
       2,     4,     4,     4,     1,     3,     2,     3,     3,     3,
       1,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     2,     4,     3,     5,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     2,
       1,     4,     3,     4,     4,     5,     4,     5,     5,     6,
       3,     3,     3,     1,     4,     1,     4,     3,     4,     4,
       5,     4,     5,     1,     2,     3,     1,     2,     1,     6,
       3,     3,     1,     2,     3,     1,     3,     2,     3,     2,
       3,     4,     1,     3,     1,     2,     1,     1,     1,     2,
       2,     2,     3,     1,     1,     2,     2,     2,     5,     5,
       1,     4,     3,     4,     8,    10,     1,     2,     4,     7,
       8,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       0,     4,     3,     3,     3,     1,     3,     4,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     4,     1,     4,     1,     4,
       1,     4,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     5,     6,     3,     4,     1,     2,     3,     2,
       1,     2,     2,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     4,     4,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     4,     5,     8,     9,     9,    10,     1,     2,
       1,     2,     6,     0,     1,     3,     3,     0,     1,     1,
       1,     2,     2,     0,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     4,     4,     5,     6,     7,     4,     5,     6,
       7,     4,     4,     4,     5,     6,     7,     1,     2,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     4,     4,     3,     3,     3,     4,     4,     3,     4,
       6,     4,     6,     3,     3,     4,     6,     6,     4,     6,
       6,     4,     1,     2,     1,     3,     3,     3,     5,     7,
       7,     5,     5,     5,     7,     7,     5,     5,     3,     3,
       5,     7,     5,     7,     1,     4,     3,     5,     1,     2,
       5,     8,    11,    14,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     7,     4,     1,     2,     3,     4,     1,     1,
       2,     2,     1,     3,     1,     3,     1,     4,     1,     2,
       1,     2,     3,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     3,     5,     7,     5,     7,     2,     1,     3,     2,
       4,     4,     6,     4,     5,     4,     5,     3,     1,     2,
       2,     3,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     1,     2,     1,     2,     3,     3,
       4,     3,     3,     3,     2,     2,     1,     1,     1,     1,
       1,     3
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
  "\"'boundary-space'\"", "\"'decimal-format'\"",
  "\"'decimal-separator'\"", "\"'grouping-separator'\"", "\"'infinity'\"",
  "\"'minus-sign'\"", "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"",
  "\"'zero-digit'\"", "\"'digit'\"", "\"'pattern-separator'\"",
  "\"'ancestor::'\"", "\"'ancestor-or-self::'\"", "\"'and'\"", "\"'''\"",
  "\"'as'\"", "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"",
  "\"'attribute::'\"", "\"'@'\"", "\"'case'\"", "\"'castable'\"",
  "\"'cast'\"", "\"'CDATA[['\"", "\"']]'\"", "\"'child::'\"",
  "\"'collation'\"", "\"','\"", "\"'(:'\"", "\"':)'\"", "\"'DECIMAL'\"",
  "\"'context'\"", "\"'variable'\"", "\"'default'\"", "\"'descendant::'\"",
  "\"'descendant-or-self::'\"", "\"'descending'\"", "\"'div'\"", "\"'$'\"",
  "\"'.'\"", "\"'..'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
  "\"'else'\"", "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
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
  "\"'build'\"", "\"'drop'\"", "\"'unique'\"", "\"'index'\"", "\"'hash'\"",
  "\"'btree'\"", "\"'on'\"", "\"'BOM_UTF8'\"", "FTCONTAINS_REDUCE",
  "RANGE_REDUCE", "ADDITIVE_REDUCE", "MULTIPLICATIVE_REDUCE",
  "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE",
  "COMMA_DOLLAR", "UNARY_PREC", "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR",
  "OCCURS_PLUS", "OCCURS_HOOK", "STEP_REDUCE", "$accept", "Module",
  "ModuleWithoutBOM", "VersionDecl", "MainModule", "LibraryModule",
  "ModuleDecl", "Prolog", "SIND_DeclList", "VFO_DeclList", "SIND_Decl",
  "VFO_Decl", "DecimalFormatDecl", "DecimalFormatParamList",
  "DecimalFormatParam", "DecimalFormatParamName", "Setter", "Import",
  "NamespaceDecl", "BoundarySpaceDecl", "DefaultNamespaceDecl",
  "OptionDecl", "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "DefaultCollationDecl", "BaseURIDecl",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "CtxItemDecl", "CtxItemDecl2", "CtxItemDecl3", "CtxItemDecl4",
  "VarNameAndType", "VarDecl", "IndexingMethod", "IndexDecl", "IndexDecl2",
  "IndexDecl3", "IndexDeclSuffix", "IndexField", "IndexField1",
  "IndexFieldList", "ConstructionDecl", "FunctionSig", "BlockExpr",
  "Block", "BlockDecls", "BlockVarDeclList", "BlockVarDecl", "AssignExpr",
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
       298,     0,    -1,   299,    -1,   282,   299,    -1,   301,    -1,
     300,   301,    -1,   302,    -1,   300,   302,    -1,   209,   210,
      20,   185,    -1,   209,   210,    20,   127,    20,   185,    -1,
     304,   363,    -1,   363,    -1,   303,   304,    -1,    51,   155,
     518,   128,   517,   185,    -1,   305,   185,    -1,   306,   185,
      -1,   305,   185,   306,   185,    -1,   307,    -1,   305,   185,
     307,    -1,   308,    -1,   306,   185,   308,    -1,   313,    -1,
     314,    -1,   315,    -1,   317,    -1,   334,    -1,   329,    -1,
     355,    -1,   318,    -1,   319,    -1,   336,    -1,   309,    -1,
      38,   111,    77,   310,    -1,    38,    77,   519,   310,    -1,
     311,    -1,   310,   311,    -1,   312,   128,   505,    -1,    78,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,   316,
      -1,   323,    -1,   324,    -1,   343,    -1,   320,    -1,   321,
      -1,   322,    -1,   506,    -1,   325,    -1,   328,    -1,    38,
     155,   518,   128,   517,    -1,    38,    76,   176,    -1,    38,
      76,   190,    -1,    38,   111,    34,   155,   517,    -1,    38,
     111,    39,   155,   517,    -1,    38,    52,   519,    20,    -1,
      38,   239,   532,    -1,    38,    69,   163,    -1,    38,    69,
     196,    -1,    38,   111,   164,   123,   124,    -1,    38,   111,
     164,   123,   125,    -1,    38,    73,   176,   105,   143,    -1,
      38,    73,   176,   105,   160,    -1,    38,    73,   161,   105,
     143,    -1,    38,    73,   161,   105,   160,    -1,    38,   111,
     104,   517,    -1,    38,    70,   517,    -1,    48,    54,   517,
      -1,    48,    54,   327,   517,    -1,    48,    54,   517,    94,
     326,    -1,    48,    54,   327,   517,    94,   326,    -1,   517,
      -1,   326,   105,   517,    -1,   155,   518,   128,    -1,   111,
      34,   155,    -1,    48,    51,   517,    -1,    48,    51,   155,
     518,   128,   517,    -1,    48,    51,   517,    94,   326,    -1,
      48,    51,   155,   518,   128,   517,    94,   326,    -1,    38,
     109,   147,   330,    -1,    92,   491,   331,    -1,   331,    -1,
     332,    -1,   133,    -1,   133,   332,    -1,   138,   367,    -1,
     116,   519,    -1,   116,   519,   488,    -1,    38,   110,   333,
     138,   367,    -1,    38,   110,   333,   133,    -1,    38,   110,
     333,   133,   138,   367,    -1,   279,    -1,   280,    -1,    38,
     337,    -1,   338,    -1,   277,   338,    -1,   339,    -1,   335,
     339,    -1,   278,   517,   281,   367,   165,   342,   181,    -1,
     341,    -1,   341,   104,   517,    -1,   367,    -1,   367,   488,
      -1,   151,   340,    -1,   342,   105,   340,    -1,    38,    58,
     176,    -1,    38,    58,   190,    -1,   151,   181,    -1,   151,
     359,   181,    -1,   151,   181,    92,   489,    -1,   151,   359,
     181,    92,   489,    -1,    26,   346,    -1,   148,   347,   364,
     178,    -1,   347,   348,   185,    -1,    -1,   348,   105,   349,
      -1,    38,   349,    -1,   333,    -1,   333,   138,   367,    -1,
      56,   116,   519,   138,   367,    -1,    27,   232,   367,    -1,
      31,   151,   367,   181,   346,    -1,    28,    29,    -1,    30,
      29,    -1,   274,   278,   517,    -1,   276,   278,   517,    -1,
     275,   278,   517,    -1,    38,   356,    -1,    38,    43,   356,
      -1,    38,    42,   356,    -1,   357,    -1,    44,   357,    -1,
      40,   357,    -1,    41,   358,    -1,    39,   519,   344,   362,
      -1,    39,   519,   344,   133,    -1,    39,   519,   344,   346,
      -1,   360,    -1,   359,   105,   360,    -1,   116,   519,    -1,
     116,   519,   488,    -1,   148,   364,   178,    -1,   148,   364,
     178,    -1,   364,    -1,   366,    -1,   366,   365,    -1,   185,
      -1,   365,   366,   185,    -1,   367,    -1,   366,   105,   367,
      -1,   368,    -1,   405,    -1,   408,    -1,   411,    -1,   412,
      -1,   507,    -1,   508,    -1,   510,    -1,   509,    -1,   511,
      -1,   514,    -1,   520,    -1,   351,    -1,   352,    -1,   353,
      -1,   350,    -1,   345,    -1,   354,    -1,   377,   369,    -1,
     180,   367,    -1,    62,   267,    -1,    63,   267,    -1,   212,
      -1,   245,    -1,    66,   245,    -1,   371,   389,    67,   367,
      -1,   371,    67,   367,    -1,    60,   370,   388,   372,   372,
      -1,    60,   370,   388,   372,    -1,    68,   116,   519,    -1,
     379,    -1,   384,    -1,   373,    -1,   375,    -1,   393,    -1,
     398,    -1,   394,    -1,   374,    -1,   375,    -1,   377,   376,
      -1,    60,   116,    -1,    61,    60,   116,    -1,   378,   380,
      -1,   381,    -1,   380,   105,   116,   381,    -1,   519,   142,
     367,    -1,   519,   488,   142,   367,    -1,   519,   382,   142,
     367,    -1,   519,   488,   382,   142,   367,    -1,   519,   383,
     142,   367,    -1,   519,   488,   383,   142,   367,    -1,   519,
     382,   383,   142,   367,    -1,   519,   488,   382,   383,   142,
     367,    -1,    94,   116,   519,    -1,   261,   116,   519,    -1,
      57,   116,   385,    -1,   387,    -1,   385,   105,   116,   387,
      -1,   392,    -1,   386,   105,   116,   392,    -1,   519,   138,
     367,    -1,   519,   488,   138,   367,    -1,   519,   383,   138,
     367,    -1,   519,   488,   383,   138,   367,    -1,   116,   519,
     142,   367,    -1,   116,   519,   488,   142,   367,    -1,   390,
      -1,   116,   519,    -1,   116,   519,   390,    -1,   382,    -1,
     382,   391,    -1,   391,    -1,    64,   116,   519,    65,   116,
     519,    -1,    65,   116,   519,    -1,    64,   116,   519,    -1,
     519,    -1,   206,   367,    -1,   166,   165,   395,    -1,   396,
      -1,   395,   105,   396,    -1,   116,   519,    -1,   116,   519,
     397,    -1,   104,   517,    -1,   164,   165,   399,    -1,    50,
     164,   165,   399,    -1,   400,    -1,   399,   105,   400,    -1,
     367,    -1,   367,   401,    -1,   402,    -1,   403,    -1,   404,
      -1,   402,   403,    -1,   402,   404,    -1,   403,   404,    -1,
     402,   403,   404,    -1,    93,    -1,   114,    -1,   123,   124,
      -1,   123,   125,    -1,   104,   517,    -1,    49,   116,   406,
     182,   367,    -1,   131,   116,   406,   182,   367,    -1,   407,
      -1,   406,   105,   116,   407,    -1,   519,   142,   367,    -1,
     519,   488,   142,   367,    -1,    33,   151,   364,   181,   409,
     111,   180,   367,    -1,    33,   151,   364,   181,   409,   111,
     116,   519,   180,   367,    -1,   410,    -1,   409,   410,    -1,
      98,   489,   180,   367,    -1,    98,   116,   519,    92,   489,
     180,   367,    -1,    45,   151,   364,   181,   192,   367,   122,
     367,    -1,   413,    -1,   412,   162,   413,    -1,   414,    -1,
     413,    90,   414,    -1,   416,    -1,   416,   429,   416,    -1,
     416,   430,   416,    -1,   416,   128,   416,    -1,   416,   157,
     416,    -1,    -1,   416,   152,   415,   416,    -1,   416,   150,
     416,    -1,   416,   139,   416,    -1,   416,   137,   416,    -1,
     417,    -1,   417,   250,   521,    -1,   417,   250,   521,   555,
      -1,   418,    -1,   418,   193,   418,    -1,   419,    -1,   418,
     170,   419,    -1,   418,   153,   419,    -1,   420,    -1,   419,
     188,   420,    -1,   419,   115,   420,    -1,   419,   141,   420,
      -1,   419,   154,   420,    -1,   421,    -1,   420,   195,   421,
      -1,   420,   204,   421,    -1,   422,    -1,   421,   145,   422,
      -1,   421,   132,   422,    -1,   423,    -1,   423,    74,   226,
     489,    -1,   424,    -1,   424,   194,    92,   489,    -1,   425,
      -1,   425,    99,    92,   487,    -1,   426,    -1,   426,   100,
      92,   487,    -1,   428,    -1,   427,   428,    -1,   170,    -1,
     153,    -1,   427,   170,    -1,   427,   153,    -1,   431,    -1,
     435,    -1,   432,    -1,   197,    -1,   202,    -1,   201,    -1,
     200,    -1,   199,    -1,   198,    -1,   146,    -1,   173,    -1,
     136,    -1,    32,   148,   364,   178,    -1,    32,   217,   148,
     364,   178,    -1,    32,   216,   148,   364,   178,    -1,    32,
      92,   503,   148,   364,   178,    -1,   433,   148,   178,    -1,
     433,   148,   364,   178,    -1,   434,    -1,   433,   434,    -1,
     171,   519,    15,    -1,   171,    16,    -1,   436,    -1,   436,
     437,    -1,   187,   437,    -1,   437,    -1,   186,    -1,   438,
      -1,   438,   186,   437,    -1,   438,   187,   437,    -1,   439,
      -1,   448,    -1,   440,    -1,   440,   449,    -1,   443,    -1,
     443,   449,    -1,   441,   445,    -1,   442,    -1,   103,    -1,
     112,    -1,    96,    -1,   184,    -1,   113,    -1,   135,    -1,
     134,    -1,   445,    -1,    97,   445,    -1,   444,   445,    -1,
     118,    -1,   167,    -1,    88,    -1,   175,    -1,   174,    -1,
      89,    -1,   493,    -1,   446,    -1,   519,    -1,   447,    -1,
     188,    -1,    10,    -1,    17,    -1,   451,    -1,   451,   449,
      -1,   450,    -1,   449,   450,    -1,   149,   364,   179,    -1,
     452,    -1,   454,    -1,   455,    -1,   456,    -1,   459,    -1,
     461,    -1,   457,    -1,   458,    -1,   453,    -1,   505,    -1,
     108,    -1,   144,    -1,   120,    -1,   116,   519,    -1,   151,
     181,    -1,   151,   364,   181,    -1,   117,    -1,   163,   148,
     364,   178,    -1,   196,   148,   364,   178,    -1,   519,   151,
     181,    -1,   519,   151,   460,   181,    -1,   367,    -1,   460,
     105,   367,    -1,   462,    -1,   480,    -1,   463,    -1,   477,
      -1,   478,    -1,   152,   519,   467,   126,    -1,   152,   519,
     465,   467,   126,    -1,   152,   519,   467,   191,   189,   519,
     467,   191,    -1,   152,   519,   467,   191,   464,   189,   519,
     467,   191,    -1,   152,   519,   465,   467,   191,   189,   519,
     467,   191,    -1,   152,   519,   465,   467,   191,   464,   189,
     519,   467,   191,    -1,   475,    -1,   464,   475,    -1,   466,
      -1,   465,   466,    -1,    25,   519,   467,   128,   467,   468,
      -1,    -1,    25,    -1,   177,   469,   177,    -1,    91,   471,
      91,    -1,    -1,   470,    -1,   130,    -1,   473,    -1,   470,
     130,    -1,   470,   473,    -1,    -1,   472,    -1,   129,    -1,
     474,    -1,   472,   129,    -1,   472,   474,    -1,    19,    -1,
     476,    -1,     4,    -1,   476,    -1,   462,    -1,     9,    -1,
     479,    -1,   476,    -1,     8,    -1,   119,    -1,   121,    -1,
     361,    -1,   207,    21,   208,    -1,   207,   208,    -1,   168,
      14,   169,    -1,   168,    14,     7,    -1,   101,     6,    -1,
     481,    -1,   482,    -1,   483,    -1,   484,    -1,   485,    -1,
     486,    -1,    35,   148,   364,   178,    -1,    34,   519,   148,
     178,    -1,    34,   519,   148,   364,   178,    -1,    34,   148,
     364,   178,   148,   178,    -1,    34,   148,   364,   178,   148,
     364,   178,    -1,    95,   519,   148,   178,    -1,    95,   519,
     148,   364,   178,    -1,    95,   148,   364,   178,   148,   178,
      -1,    95,   148,   364,   178,   148,   364,   178,    -1,    36,
     148,   364,   178,    -1,    37,   148,   364,   178,    -1,    46,
     518,   148,   178,    -1,    46,   518,   148,   364,   178,    -1,
      46,   148,   364,   178,   148,   178,    -1,    46,   148,   364,
     178,   148,   364,   178,    -1,   492,    -1,   492,   140,    -1,
      92,   489,    -1,   491,    -1,   491,   490,    -1,   205,   151,
     181,    -1,   140,    -1,   188,    -1,   170,    -1,   492,    -1,
     493,    -1,   147,   151,   181,    -1,   519,    -1,   495,    -1,
     501,    -1,   499,    -1,   502,    -1,   500,    -1,   498,    -1,
     497,    -1,   496,    -1,   494,    -1,   220,   151,   181,    -1,
      72,   151,   181,    -1,    72,   151,   501,   181,    -1,    72,
     151,   502,   181,    -1,    36,   151,   181,    -1,    37,   151,
     181,    -1,    46,   151,   181,    -1,    46,   151,   518,   181,
      -1,    46,   151,    20,   181,    -1,    95,   151,   181,    -1,
      95,   151,   519,   181,    -1,    95,   151,   519,   105,   503,
     181,    -1,    95,   151,   188,   181,    -1,    95,   151,   188,
     105,   503,   181,    -1,   183,   519,   181,    -1,    34,   151,
     181,    -1,    34,   151,   519,   181,    -1,    34,   151,   519,
     105,   503,   181,    -1,    34,   151,   519,   105,   504,   181,
      -1,    34,   151,   188,   181,    -1,    34,   151,   188,   105,
     503,   181,    -1,    34,   151,   188,   105,   504,   181,    -1,
      71,   151,   519,   181,    -1,   519,    -1,   519,   140,    -1,
      20,    -1,    38,   215,   216,    -1,    38,   215,   217,    -1,
      38,   215,   218,    -1,   221,   220,   367,   228,   367,    -1,
     221,   220,   367,    92,   227,   228,   367,    -1,   221,   220,
     367,    92,   229,   228,   367,    -1,   221,   220,   367,   213,
     367,    -1,   221,   220,   367,   214,   367,    -1,   221,   222,
     367,   228,   367,    -1,   221,   222,   367,    92,   227,   228,
     367,    -1,   221,   222,   367,    92,   229,   228,   367,    -1,
     221,   222,   367,   213,   367,    -1,   221,   222,   367,   214,
     367,    -1,   219,   220,   367,    -1,   219,   222,   367,    -1,
     224,   220,   367,   232,   367,    -1,   224,   225,   226,   220,
     367,   232,   367,    -1,   223,   220,   367,    92,   367,    -1,
     231,   116,   512,   230,   367,   180,   367,    -1,   513,    -1,
     512,   105,   116,   513,    -1,   519,   138,   367,    -1,   233,
     148,   367,   178,   515,    -1,   516,    -1,   515,   516,    -1,
     234,   151,   446,   181,   362,    -1,   234,   151,   446,   105,
     116,   519,   181,   362,    -1,   234,   151,   446,   105,   116,
     519,   105,   116,   519,   181,   362,    -1,   234,   151,   446,
     105,   116,   519,   105,   116,   519,   105,   116,   519,   181,
     362,    -1,    20,    -1,    18,    -1,    18,    -1,   209,    -1,
     123,    -1,    95,    -1,    37,    -1,    72,    -1,    34,    -1,
     147,    -1,    45,    -1,   220,    -1,    46,    -1,    75,    -1,
      71,    -1,    36,    -1,    33,    -1,   205,    -1,    76,    -1,
     239,    -1,    70,    -1,   217,    -1,   216,    -1,   141,    -1,
      35,    -1,   251,    -1,   238,    -1,   241,    -1,   240,    -1,
     268,    -1,   269,    -1,   272,    -1,   270,    -1,   273,    -1,
     244,    -1,   246,    -1,    53,    -1,   212,    -1,   245,    -1,
      47,    -1,   218,    -1,   231,    -1,   225,    -1,   197,    -1,
     202,    -1,   201,    -1,   200,    -1,   199,    -1,   198,    -1,
      94,    -1,   109,    -1,   110,    -1,   180,    -1,    60,    -1,
      61,    -1,    62,    -1,    63,    -1,    64,    -1,    65,    -1,
      66,    -1,    67,    -1,    68,    -1,   142,    -1,    57,    -1,
     206,    -1,   165,    -1,   166,    -1,   164,    -1,    50,    -1,
      93,    -1,   114,    -1,   124,    -1,   125,    -1,   104,    -1,
      49,    -1,   131,    -1,   182,    -1,    98,    -1,    92,    -1,
     192,    -1,   122,    -1,   162,    -1,    90,    -1,    74,    -1,
     226,    -1,    99,    -1,   193,    -1,   115,    -1,   154,    -1,
     195,    -1,   145,    -1,   132,    -1,    32,    -1,   100,    -1,
     194,    -1,   146,    -1,   176,    -1,   190,    -1,   155,    -1,
     133,    -1,   127,    -1,   161,    -1,   143,    -1,   160,    -1,
      38,    -1,    58,    -1,    69,    -1,   111,    -1,    73,    -1,
      52,    -1,   210,    -1,    48,    -1,    54,    -1,    51,    -1,
      39,    -1,   261,    -1,   250,    -1,   266,    -1,   267,    -1,
     243,    -1,   256,    -1,   264,    -1,   260,    -1,   242,    -1,
     255,    -1,   265,    -1,   259,    -1,   254,    -1,   253,    -1,
     237,    -1,   236,    -1,   258,    -1,   247,    -1,   248,    -1,
     271,    -1,   263,    -1,   262,    -1,   257,    -1,   224,    -1,
     230,    -1,   227,    -1,   221,    -1,   214,    -1,   213,    -1,
     215,    -1,   232,    -1,   222,    -1,   223,    -1,   229,    -1,
     219,    -1,   228,    -1,    44,    -1,    41,    -1,    40,    -1,
      42,    -1,    43,    -1,   163,    -1,   196,    -1,    26,    -1,
      27,    -1,    29,    -1,    31,    -1,    28,    -1,    30,    -1,
     233,    -1,   234,    -1,    59,    -1,   235,    -1,    56,    -1,
     278,    -1,   274,    -1,   275,    -1,   277,    -1,   281,    -1,
     279,    -1,   280,    -1,   276,    -1,    77,    -1,    78,    -1,
      79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,    87,    -1,   235,   116,
     386,    59,   148,   367,   178,    -1,    59,   148,   367,   178,
      -1,   523,    -1,   523,   522,    -1,   523,   266,   417,    -1,
     523,   522,   266,   417,    -1,   532,    -1,   530,    -1,   522,
     532,    -1,   522,   530,    -1,   524,    -1,   523,   252,   524,
      -1,   525,    -1,   524,   249,   525,    -1,   526,    -1,   525,
     251,   142,   526,    -1,   527,    -1,   251,   527,    -1,   528,
      -1,   528,   551,    -1,   151,   521,   181,    -1,   529,    -1,
     529,   547,    -1,   452,    -1,   148,   364,   178,    -1,   531,
      -1,   550,    -1,   549,    -1,   552,    -1,   546,    -1,   163,
      -1,   533,    -1,   534,    -1,   535,    -1,   536,    -1,   539,
      -1,   544,    -1,   545,    -1,   255,    -1,   265,    -1,    98,
     238,    -1,    98,   241,    -1,   232,   240,    -1,   268,   240,
      -1,   240,   238,    -1,   240,   241,    -1,   232,   269,    -1,
     268,   269,    -1,   232,   272,   538,    -1,   232,   272,   111,
      -1,   232,   272,   151,   538,   181,    -1,   232,   272,   151,
     538,   105,   537,   181,    -1,   232,   272,   151,   111,   181,
      -1,   232,   272,   151,   111,   105,   537,   181,    -1,   268,
     272,    -1,   538,    -1,   537,   105,   538,    -1,    94,    20,
      -1,    94,    20,   259,    20,    -1,    94,    20,   548,   254,
      -1,    94,    20,   259,    20,   548,   254,    -1,   232,   270,
     271,   541,    -1,   232,   270,   271,   541,   540,    -1,   232,
     111,   270,   271,    -1,   232,   111,   270,   271,   540,    -1,
     268,   270,   271,    -1,   543,    -1,   540,   543,    -1,    94,
      20,    -1,   151,   542,   181,    -1,    20,    -1,   542,    20,
      -1,   195,   541,    -1,   132,   541,    -1,   253,    20,    -1,
     232,   273,    -1,   268,   273,    -1,    94,   212,    -1,    94,
     245,    -1,   244,   246,    -1,   237,    -1,   237,    53,    -1,
     236,    -1,   236,   271,    -1,   258,    -1,   247,   420,    -1,
      94,   125,   420,    -1,    94,    47,   420,    -1,   248,   420,
     193,   420,    -1,   243,   548,   553,    -1,   267,   420,   553,
      -1,   256,   548,   264,    -1,   260,   554,    -1,   242,   554,
      -1,   271,    -1,   263,    -1,   257,    -1,   262,    -1,   257,
      -1,   268,   246,   420,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    15,    18,    23,
      30,    33,    35,    38,    45,    48,    51,    56,    58,    62,
      64,    68,    70,    72,    74,    76,    78,    80,    82,    84,
      86,    88,    90,    95,   100,   102,   105,   109,   111,   113,
     115,   117,   119,   121,   123,   125,   127,   129,   131,   133,
     135,   137,   139,   141,   143,   145,   147,   149,   155,   159,
     163,   169,   175,   180,   184,   188,   192,   198,   204,   210,
     216,   222,   228,   233,   237,   241,   246,   252,   259,   261,
     265,   269,   273,   277,   284,   290,   299,   304,   308,   310,
     312,   314,   317,   320,   323,   327,   333,   338,   345,   347,
     349,   352,   354,   357,   359,   362,   370,   372,   376,   378,
     381,   384,   388,   392,   396,   399,   403,   408,   414,   417,
     422,   426,   427,   431,   434,   436,   440,   446,   450,   456,
     459,   462,   466,   470,   474,   477,   481,   485,   487,   490,
     493,   496,   501,   506,   511,   513,   517,   520,   524,   528,
     532,   534,   536,   539,   541,   545,   547,   551,   553,   555,
     557,   559,   561,   563,   565,   567,   569,   571,   573,   575,
     577,   579,   581,   583,   585,   587,   590,   593,   596,   599,
     601,   603,   606,   611,   615,   621,   626,   630,   632,   634,
     636,   638,   640,   642,   644,   646,   648,   651,   654,   658,
     661,   663,   668,   672,   677,   682,   688,   693,   699,   705,
     712,   716,   720,   724,   726,   731,   733,   738,   742,   747,
     752,   758,   763,   769,   771,   774,   778,   780,   783,   785,
     792,   796,   800,   802,   805,   809,   811,   815,   818,   822,
     825,   829,   834,   836,   840,   842,   845,   847,   849,   851,
     854,   857,   860,   864,   866,   868,   871,   874,   877,   883,
     889,   891,   896,   900,   905,   914,   925,   927,   930,   935,
     943,   952,   954,   958,   960,   964,   966,   970,   974,   978,
     982,   983,   988,   992,   996,  1000,  1002,  1006,  1011,  1013,
    1017,  1019,  1023,  1027,  1029,  1033,  1037,  1041,  1045,  1047,
    1051,  1055,  1057,  1061,  1065,  1067,  1072,  1074,  1079,  1081,
    1086,  1088,  1093,  1095,  1098,  1100,  1102,  1105,  1108,  1110,
    1112,  1114,  1116,  1118,  1120,  1122,  1124,  1126,  1128,  1130,
    1132,  1137,  1143,  1149,  1156,  1160,  1165,  1167,  1170,  1174,
    1177,  1179,  1182,  1185,  1187,  1189,  1191,  1195,  1199,  1201,
    1203,  1205,  1208,  1210,  1213,  1216,  1218,  1220,  1222,  1224,
    1226,  1228,  1230,  1232,  1234,  1237,  1240,  1242,  1244,  1246,
    1248,  1250,  1252,  1254,  1256,  1258,  1260,  1262,  1264,  1266,
    1268,  1271,  1273,  1276,  1280,  1282,  1284,  1286,  1288,  1290,
    1292,  1294,  1296,  1298,  1300,  1302,  1304,  1306,  1309,  1312,
    1316,  1318,  1323,  1328,  1332,  1337,  1339,  1343,  1345,  1347,
    1349,  1351,  1353,  1358,  1364,  1373,  1383,  1393,  1404,  1406,
    1409,  1411,  1414,  1421,  1422,  1424,  1428,  1432,  1433,  1435,
    1437,  1439,  1442,  1445,  1446,  1448,  1450,  1452,  1455,  1458,
    1460,  1462,  1464,  1466,  1468,  1470,  1472,  1474,  1476,  1478,
    1480,  1482,  1486,  1489,  1493,  1497,  1500,  1502,  1504,  1506,
    1508,  1510,  1512,  1517,  1522,  1528,  1535,  1543,  1548,  1554,
    1561,  1569,  1574,  1579,  1584,  1590,  1597,  1605,  1607,  1610,
    1613,  1615,  1618,  1622,  1624,  1626,  1628,  1630,  1632,  1636,
    1638,  1640,  1642,  1644,  1646,  1648,  1650,  1652,  1654,  1656,
    1660,  1664,  1669,  1674,  1678,  1682,  1686,  1691,  1696,  1700,
    1705,  1712,  1717,  1724,  1728,  1732,  1737,  1744,  1751,  1756,
    1763,  1770,  1775,  1777,  1780,  1782,  1786,  1790,  1794,  1800,
    1808,  1816,  1822,  1828,  1834,  1842,  1850,  1856,  1862,  1866,
    1870,  1876,  1884,  1890,  1898,  1900,  1905,  1909,  1915,  1917,
    1920,  1926,  1935,  1947,  1962,  1964,  1966,  1968,  1970,  1972,
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
    2214,  2216,  2218,  2220,  2222,  2224,  2226,  2228,  2230,  2232,
    2234,  2236,  2238,  2240,  2242,  2244,  2246,  2248,  2250,  2252,
    2254,  2256,  2258,  2260,  2262,  2264,  2266,  2268,  2270,  2272,
    2274,  2276,  2278,  2280,  2282,  2284,  2286,  2288,  2290,  2292,
    2294,  2296,  2298,  2300,  2302,  2304,  2306,  2308,  2310,  2312,
    2314,  2316,  2318,  2320,  2322,  2324,  2326,  2328,  2330,  2332,
    2334,  2336,  2338,  2346,  2351,  2353,  2356,  2360,  2365,  2367,
    2369,  2372,  2375,  2377,  2381,  2383,  2387,  2389,  2394,  2396,
    2399,  2401,  2404,  2408,  2410,  2413,  2415,  2419,  2421,  2423,
    2425,  2427,  2429,  2431,  2433,  2435,  2437,  2439,  2441,  2443,
    2445,  2447,  2449,  2452,  2455,  2458,  2461,  2464,  2467,  2470,
    2473,  2477,  2481,  2487,  2495,  2501,  2509,  2512,  2514,  2518,
    2521,  2526,  2531,  2538,  2543,  2549,  2554,  2560,  2564,  2566,
    2569,  2572,  2576,  2578,  2581,  2584,  2587,  2590,  2593,  2596,
    2599,  2602,  2605,  2607,  2610,  2612,  2615,  2617,  2620,  2624,
    2628,  2633,  2637,  2641,  2645,  2648,  2651,  2653,  2655,  2657,
    2659,  2661
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   901,   901,   902,   912,   917,   923,   928,   940,   945,
     955,   962,   974,   986,   998,  1004,  1010,  1022,  1028,  1042,
    1048,  1062,  1063,  1064,  1065,  1071,  1072,  1073,  1074,  1077,
    1080,  1082,  1088,  1092,  1099,  1104,  1112,  1119,  1120,  1121,
    1122,  1123,  1124,  1125,  1126,  1127,  1128,  1135,  1136,  1137,
    1138,  1139,  1140,  1141,  1144,  1151,  1152,  1164,  1176,  1181,
    1192,  1198,  1210,  1223,  1234,  1239,  1251,  1256,  1267,  1273,
    1279,  1285,  1304,  1315,  1326,  1333,  1340,  1347,  1360,  1366,
    1381,  1385,  1395,  1401,  1408,  1414,  1426,  1433,  1439,  1446,
    1452,  1456,  1463,  1474,  1478,  1486,  1495,  1502,  1512,  1514,
    1521,  1529,  1533,  1541,  1545,  1553,  1561,  1565,  1573,  1577,
    1584,  1591,  1601,  1606,  1618,  1622,  1626,  1630,  1637,  1644,
    1663,  1673,  1679,  1685,  1694,  1705,  1718,  1725,  1732,  1744,
    1748,  1755,  1759,  1763,  1770,  1774,  1780,  1787,  1791,  1795,
    1803,  1810,  1819,  1831,  1845,  1853,  1867,  1873,  1885,  1893,
    1904,  1915,  1919,  1931,  1935,  1944,  1948,  1964,  1965,  1966,
    1967,  1968,  1971,  1972,  1973,  1974,  1975,  1977,  1978,  1981,
    1982,  1983,  1984,  1985,  1988,  1995,  2004,  2011,  2015,  2023,
    2027,  2031,  2038,  2042,  2049,  2054,  2063,  2072,  2073,  2074,
    2078,  2078,  2078,  2078,  2078,  2081,  2087,  2096,  2100,  2110,
    2121,  2127,  2141,  2148,  2156,  2165,  2175,  2183,  2192,  2201,
    2216,  2228,  2239,  2251,  2257,  2269,  2275,  2289,  2297,  2306,
    2314,  2326,  2332,  2342,  2343,  2347,  2355,  2359,  2364,  2368,
    2372,  2376,  2383,  2398,  2406,  2413,  2419,  2430,  2436,  2445,
    2455,  2460,  2472,  2478,  2492,  2498,  2510,  2517,  2524,  2531,
    2538,  2545,  2552,  2565,  2569,  2579,  2584,  2595,  2606,  2613,
    2626,  2633,  2645,  2651,  2664,  2671,  2685,  2691,  2703,  2709,
    2722,  2733,  2737,  2748,  2752,  2771,  2775,  2783,  2791,  2799,
    2807,  2807,  2815,  2823,  2831,  2845,  2849,  2856,  2869,  2873,
    2884,  2888,  2892,  2902,  2906,  2910,  2914,  2918,  2928,  2932,
    2937,  2948,  2952,  2956,  2966,  2970,  2982,  2986,  2998,  3002,
    3014,  3018,  3030,  3034,  3046,  3050,  3054,  3058,  3070,  3074,
    3078,  3088,  3092,  3096,  3100,  3104,  3108,  3118,  3122,  3126,
    3136,  3140,  3144,  3148,  3160,  3166,  3178,  3184,  3198,  3205,
    3246,  3250,  3254,  3258,  3270,  3280,  3291,  3296,  3306,  3310,
    3320,  3326,  3332,  3338,  3350,  3356,  3367,  3371,  3375,  3379,
    3383,  3387,  3391,  3401,  3405,  3415,  3421,  3433,  3437,  3441,
    3445,  3449,  3464,  3468,  3478,  3482,  3492,  3499,  3506,  3519,
    3523,  3535,  3541,  3555,  3566,  3570,  3574,  3578,  3582,  3586,
    3590,  3594,  3604,  3608,  3618,  3623,  3628,  3639,  3649,  3653,
    3664,  3674,  3685,  3741,  3747,  3759,  3765,  3777,  3781,  3791,
    3795,  3799,  3809,  3817,  3825,  3833,  3841,  3849,  3864,  3870,
    3882,  3888,  3901,  3910,  3912,  3918,  3923,  3935,  3938,  3945,
    3951,  3957,  3965,  3980,  3983,  3990,  3996,  4002,  4010,  4024,
    4029,  4040,  4045,  4056,  4061,  4066,  4072,  4084,  4090,  4095,
    4100,  4111,  4116,  4131,  4136,  4153,  4168,  4172,  4176,  4180,
    4184,  4188,  4198,  4209,  4215,  4221,  4226,  4248,  4254,  4260,
    4265,  4276,  4286,  4296,  4302,  4308,  4313,  4324,  4330,  4342,
    4353,  4359,  4365,  4402,  4407,  4412,  4423,  4427,  4431,  4441,
    4452,  4456,  4460,  4464,  4468,  4472,  4476,  4480,  4484,  4494,
    4504,  4508,  4513,  4524,  4534,  4544,  4548,  4552,  4562,  4568,
    4574,  4580,  4586,  4598,  4609,  4616,  4623,  4630,  4637,  4644,
    4651,  4664,  4685,  4692,  4712,  4752,  4757,  4760,  4768,  4774,
    4780,  4786,  4792,  4799,  4805,  4811,  4817,  4823,  4835,  4840,
    4850,  4856,  4868,  4894,  4905,  4911,  4924,  4938,  4945,  4952,
    4963,  4970,  4978,  4987,  5000,  5003,  5021,  5022,  5023,  5024,
    5025,  5026,  5027,  5028,  5029,  5030,  5031,  5032,  5033,  5034,
    5035,  5036,  5037,  5038,  5039,  5040,  5041,  5042,  5043,  5044,
    5045,  5046,  5047,  5048,  5049,  5050,  5051,  5052,  5053,  5054,
    5055,  5056,  5057,  5058,  5059,  5060,  5061,  5062,  5063,  5064,
    5065,  5066,  5067,  5068,  5069,  5070,  5071,  5072,  5073,  5074,
    5075,  5076,  5077,  5078,  5079,  5080,  5081,  5082,  5083,  5084,
    5085,  5086,  5087,  5088,  5089,  5090,  5091,  5092,  5093,  5094,
    5095,  5096,  5097,  5098,  5099,  5100,  5101,  5102,  5103,  5104,
    5105,  5106,  5107,  5108,  5109,  5110,  5111,  5112,  5113,  5114,
    5115,  5116,  5117,  5118,  5119,  5120,  5121,  5122,  5123,  5124,
    5125,  5126,  5127,  5128,  5129,  5130,  5131,  5132,  5133,  5134,
    5135,  5136,  5137,  5138,  5139,  5140,  5141,  5142,  5143,  5144,
    5145,  5146,  5147,  5148,  5149,  5150,  5151,  5152,  5153,  5154,
    5155,  5156,  5157,  5158,  5159,  5160,  5161,  5162,  5163,  5164,
    5165,  5166,  5167,  5168,  5169,  5170,  5171,  5172,  5173,  5174,
    5175,  5176,  5177,  5178,  5179,  5180,  5181,  5182,  5183,  5184,
    5185,  5186,  5187,  5188,  5189,  5190,  5191,  5192,  5193,  5194,
    5195,  5196,  5197,  5198,  5199,  5200,  5201,  5202,  5203,  5204,
    5205,  5206,  5217,  5223,  5240,  5244,  5248,  5252,  5262,  5265,
    5268,  5271,  5280,  5283,  5292,  5295,  5304,  5307,  5316,  5319,
    5328,  5331,  5334,  5343,  5346,  5355,  5359,  5369,  5372,  5375,
    5378,  5381,  5390,  5399,  5403,  5407,  5411,  5415,  5419,  5423,
    5433,  5436,  5439,  5442,  5451,  5454,  5457,  5460,  5469,  5472,
    5481,  5484,  5487,  5490,  5493,  5496,  5499,  5508,  5511,  5520,
    5523,  5526,  5529,  5538,  5541,  5544,  5547,  5550,  5559,  5562,
    5571,  5574,  5583,  5586,  5595,  5598,  5607,  5616,  5619,  5628,
    5631,  5634,  5643,  5646,  5649,  5652,  5655,  5664,  5668,  5672,
    5676,  5686,  5695,  5705,  5714,  5717,  5726,  5729,  5732,  5741,
    5744,  5753
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 8931;
  const int xquery_parser::yynnts_ = 259;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 494;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 297;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 551;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5761 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"


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

