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
#line 865 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 51 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 749 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };
#line 211 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 109: /* "\"'DOUBLE'\"" */
#line 748 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };
#line 216 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 133: /* "\"'INTEGER'\"" */
#line 747 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };
#line 221 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "VersionDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 226 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "MainModule" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 231 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "LibraryModule" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 236 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "ModuleDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 241 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "Prolog" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 246 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "SIND_DeclList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 251 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "VFO_DeclList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 256 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "SIND_Decl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 261 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "VFO_Decl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 266 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "Setter" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 271 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "Import" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 276 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "NamespaceDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 281 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "BoundarySpaceDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 286 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "DefaultNamespaceDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 291 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "OptionDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 296 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "OrderingModeDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 301 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "EmptyOrderDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 306 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "CopyNamespacesDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 311 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "DefaultCollationDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 316 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "BaseURIDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 321 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "SchemaImport" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 326 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "URILiteralList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 331 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "SchemaPrefix" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 336 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "ModuleImport" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 341 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "CtxItemDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 346 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "CtxItemDecl2" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 351 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "CtxItemDecl3" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 356 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "CtxItemDecl4" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 361 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "VarNameAndType" */
#line 761 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };
#line 366 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "VarDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 371 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "IndexDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 376 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "IndexDecl2" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 381 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "IndexDecl3" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 386 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "IndexDeclSuffix" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 391 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "IndexField" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 396 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "IndexField1" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 401 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "IndexFieldList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 406 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "ConstructionDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 411 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "FunctionSig" */
#line 761 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };
#line 416 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "BlockExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 421 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "Block" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 426 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "BlockDecls" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 431 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "AssignExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 436 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "ExitExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 441 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "WhileExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 446 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "FlowCtlStatement" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 451 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "IndexStatement" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 456 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "FunctionDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 461 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "FunctionDecl2" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 466 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "FunctionDecl3" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 471 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "FunctionDecl4" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 476 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "ParamList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 481 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "Param" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 486 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "EnclosedExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 491 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BracedExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 496 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "QueryBody" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 501 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "Expr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 506 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ApplyExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 511 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "ConcatExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 516 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "ExprSingle" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 521 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "FLWORExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 526 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "ReturnExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 531 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "FLWORWinCond" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 536 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "WindowClause" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 541 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CountClause" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 546 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "ForLetWinClause" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 551 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "FLWORClauseList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 556 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "ForClause" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 561 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "VarInDeclList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 566 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "VarInDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 571 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "PositionalVar" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 576 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "LetClause" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 581 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "VarGetsDeclList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 586 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "EvalVarDeclList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 591 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "VarGetsDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 596 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "WindowVarDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 601 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "WindowVars" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 606 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "WindowVars3" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 611 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "WindowVars2" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 616 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "EvalVarDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 621 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "WhereClause" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 626 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "GroupByClause" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 631 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "GroupSpecList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 636 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "GroupSpec" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 641 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "GroupCollationSpec" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 646 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "OrderByClause" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 651 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "OrderSpecList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 656 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "OrderSpec" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 661 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "OrderModifier" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 666 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "OrderDirSpec" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 671 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "OrderEmptySpec" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 676 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "OrderCollationSpec" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 681 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "QuantifiedExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 686 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "QVarInDeclList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 691 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "QVarInDecl" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 696 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "TypeswitchExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 701 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "CaseClauseList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 706 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "CaseClause" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 711 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "IfExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 716 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "OrExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 721 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "AndExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 726 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ComparisonExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 731 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FTContainsExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 736 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "RangeExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 741 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "AdditiveExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 746 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "MultiplicativeExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 751 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "UnionExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 756 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "IntersectExceptExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 761 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "InstanceofExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 766 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "TreatExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 771 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "CastableExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 776 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "CastExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 781 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "UnaryExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 786 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "SignList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 791 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ValueExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 796 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "ValueComp" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 801 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "NodeComp" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 806 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ValidateExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 811 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ExtensionExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 816 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "PragmaList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 821 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "Pragma" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 826 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "PathExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 831 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "RelativePathExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 836 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "StepExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 841 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "AxisStep" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 846 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "ForwardStep" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 851 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "ForwardAxis" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 856 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "AbbrevForwardStep" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 861 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "ReverseStep" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 866 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "ReverseAxis" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 871 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "NodeTest" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 876 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "NameTest" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 881 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "Wildcard" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 886 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "FilterExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 891 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "PredicateList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 896 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "Predicate" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 901 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "PrimaryExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 906 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "Literal" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 911 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "NumericLiteral" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 916 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "VarRef" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 921 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "ParenthesizedExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 926 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "ContextItemExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 931 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "OrderedExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 936 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "UnorderedExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 941 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "FunctionCall" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 946 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "ArgList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 951 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "Constructor" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 956 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "DirectConstructor" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 961 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "DirElemConstructor" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 966 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "DirElemContentList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 971 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "DirAttributeList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 976 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "DirAttr" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 981 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "DirAttributeValue" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 986 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "Opt_QuoteAttrContentList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 991 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "QuoteAttrContentList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 996 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "Opt_AposAttrContentList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1001 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "AposAttrContentList" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1006 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "QuoteAttrValueContent" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1011 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "AposAttrValueContent" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1016 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "DirElemContent" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1021 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "CommonContent" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1026 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "DirCommentConstructor" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1031 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "DirPIConstructor" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1036 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CDataSection" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1041 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "ComputedConstructor" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1046 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "CompDocConstructor" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1051 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "CompElemConstructor" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1056 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "CompAttrConstructor" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1061 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "CompTextConstructor" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1066 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "CompCommentConstructor" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1071 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "CompPIConstructor" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1076 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "SingleType" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1081 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "TypeDeclaration" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1086 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "SequenceType" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1091 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "OccurrenceIndicator" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1096 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ItemType" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1101 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "AtomicType" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1106 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "KindTest" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1111 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "AnyKindTest" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1116 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "DocumentTest" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1121 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "TextTest" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1126 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "CommentTest" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1131 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "PITest" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1136 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "AttributeTest" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1141 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "SchemaAttributeTest" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1146 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "ElementTest" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1151 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "SchemaElementTest" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1156 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "TypeName" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1161 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "TypeName_WITH_HOOK" */
#line 757 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };
#line 1166 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "StringLiteral" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1171 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "InsertExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1176 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DeleteExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1181 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ReplaceExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1186 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "RenameExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1191 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "TransformExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1196 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "VarNameList" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1201 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "VarNameDecl" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1206 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "TryExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1211 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "CatchListExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1216 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "CatchExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1221 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "EvalExpr" */
#line 759 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };
#line 1226 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 113 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}
  /* Line 547 of yacc.c.  */
#line 1307 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 883 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 4:
#line 893 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 898 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 904 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 7:
#line 909 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 8:
#line 921 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		;}
    break;

  case 9:
#line 926 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    ;}
    break;

  case 10:
#line 936 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 11:
#line 943 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		;}
    break;

  case 12:
#line 955 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 13:
#line 967 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), 
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
		;}
    break;

  case 14:
#line 979 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 15:
#line 985 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 16:
#line 991 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 17:
#line 1003 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 18:
#line 1009 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 1023 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 20:
#line 1029 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 41:
#line 1097 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 42:
#line 1109 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 43:
#line 1114 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 44:
#line 1125 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 45:
#line 1131 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		;}
    break;

  case 46:
#line 1143 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 47:
#line 1156 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		;}
    break;

  case 48:
#line 1167 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 49:
#line 1172 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 50:
#line 1184 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 51:
#line 1189 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 52:
#line 1200 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 53:
#line 1206 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 54:
#line 1212 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 55:
#line 1218 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 56:
#line 1237 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 57:
#line 1248 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 58:
#line 1259 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 59:
#line 1266 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		;}
    break;

  case 60:
#line 1273 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 61:
#line 1280 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 62:
#line 1293 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 63:
#line 1299 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 64:
#line 1314 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 65:
#line 1318 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 66:
#line 1328 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 67:
#line 1334 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		;}
    break;

  case 68:
#line 1341 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 69:
#line 1347 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		;}
    break;

  case 70:
#line 1359 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    ;}
    break;

  case 71:
#line 1366 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    ;}
    break;

  case 72:
#line 1372 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 73:
#line 1379 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    ;}
    break;

  case 74:
#line 1385 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    ;}
    break;

  case 75:
#line 1389 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 76:
#line 1396 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 77:
#line 1407 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (SYMTAB ((yysemantic_stack_[(2) - (2)].sval)), NULL);
    ;}
    break;

  case 78:
#line 1411 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
                               dynamic_cast<TypeDeclaration *> ((yysemantic_stack_[(3) - (3)].node)));
    ;}
    break;

  case 79:
#line 1419 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1428 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(4) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      delete nt;
		;}
    break;

  case 81:
#line 1435 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(6) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      delete nt;
		;}
    break;

  case 82:
#line 1445 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "hash"; ;}
    break;

  case 83:
#line 1447 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "btree"; ;}
    break;

  case 84:
#line 1454 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->create = false;
      (yyval.node) = d;
    ;}
    break;

  case 85:
#line 1462 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 86:
#line 1466 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->uniq = true;
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 87:
#line 1474 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 88:
#line 1478 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->method = (yysemantic_stack_[(2) - (1)].strval);
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 89:
#line 1486 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(7) - (2)].sval)), (yysemantic_stack_[(7) - (4)].expr), "",
                          dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(7) - (6)].node)));
    ;}
    break;

  case 90:
#line 1494 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 91:
#line 1498 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (1)].node))->coll = SYMTAB ((yysemantic_stack_[(3) - (3)].sval));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    ;}
    break;

  case 92:
#line 1506 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL);
    ;}
    break;

  case 93:
#line 1510 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<TypeDeclaration *> ((yysemantic_stack_[(2) - (2)].node)));
    ;}
    break;

  case 94:
#line 1517 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexFieldList *l = new IndexFieldList (LOC ((yyloc)));
      l->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
      
    ;}
    break;

  case 95:
#line 1524 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(3) - (1)].node))->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    ;}
    break;

  case 96:
#line 1534 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 97:
#line 1539 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 98:
#line 1551 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    ;}
    break;

  case 99:
#line 1555 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    ;}
    break;

  case 100:
#line 1559 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 101:
#line 1563 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 102:
#line 1570 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 103:
#line 1577 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 104:
#line 1596 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 105:
#line 1606 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    ;}
    break;

  case 106:
#line 1613 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (3)].sval)), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 107:
#line 1620 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 108:
#line 1627 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *b = dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr));
      if (b == NULL) {
        b = new BlockBody ((yysemantic_stack_[(5) - (5)].expr)->get_location ()); 
        b->add ((yysemantic_stack_[(5) - (5)].expr));
      }
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), b);
    ;}
    break;

  case 109:
#line 1639 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    ;}
    break;

  case 110:
#line 1643 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    ;}
    break;

  case 111:
#line 1650 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::create_stmt);
    ;}
    break;

  case 112:
#line 1654 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::drop_stmt);
    ;}
    break;

  case 113:
#line 1658 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::build_stmt);
    ;}
    break;

  case 114:
#line 1665 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 115:
#line 1669 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->deterministic = false;
      (yyval.node) = d;
    ;}
    break;

  case 116:
#line 1675 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    ;}
    break;

  case 117:
#line 1682 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 118:
#line 1686 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 119:
#line 1690 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    ;}
    break;

  case 120:
#line 1698 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    ;}
    break;

  case 121:
#line 1705 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 122:
#line 1714 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 123:
#line 1726 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    ;}
    break;

  case 124:
#line 1740 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 125:
#line 1748 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 126:
#line 1762 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 127:
#line 1768 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 128:
#line 1780 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 129:
#line 1788 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 130:
#line 1799 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 131:
#line 1810 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 132:
#line 1814 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(2) - (2)].expr)),
        *blk2 = new BlockBody (LOC ((yyloc)));
      blk2->add ((yysemantic_stack_[(2) - (1)].expr));
      for (int i = 0; i < blk->size (); i++)
        blk2->add ((*blk) [i]);
      (yyval.expr) = blk2;
    ;}
    break;

  case 133:
#line 1826 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    ;}
    break;

  case 134:
#line 1830 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    ;}
    break;

  case 135:
#line 1839 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 136:
#line 1843 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 155:
#line 1890 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    ;}
    break;

  case 156:
#line 1899 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    ;}
    break;

  case 157:
#line 1906 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    ;}
    break;

  case 158:
#line 1910 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    ;}
    break;

  case 159:
#line 1918 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    ;}
    break;

  case 160:
#line 1922 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    ;}
    break;

  case 161:
#line 1926 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    ;}
    break;

  case 162:
#line 1933 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 163:
#line 1937 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    ;}
    break;

  case 164:
#line 1944 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)), dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    ;}
    break;

  case 165:
#line 1949 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)), ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    ;}
    break;

  case 166:
#line 1958 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 175:
#line 1976 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 176:
#line 1982 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    ;}
    break;

  case 177:
#line 1991 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    ;}
    break;

  case 178:
#line 1995 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    ;}
    break;

  case 179:
#line 2005 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		;}
    break;

  case 180:
#line 2016 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 181:
#line 2022 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 182:
#line 2036 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 183:
#line 2043 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 184:
#line 2051 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 185:
#line 2060 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 186:
#line 2070 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 187:
#line 2078 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 188:
#line 2087 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 189:
#line 2096 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 190:
#line 2111 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 191:
#line 2123 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 192:
#line 2134 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		;}
    break;

  case 193:
#line 2146 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 194:
#line 2152 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 195:
#line 2164 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 196:
#line 2170 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 197:
#line 2184 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 198:
#line 2192 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 199:
#line 2201 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 200:
#line 2209 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 201:
#line 2221 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 202:
#line 2227 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 204:
#line 2238 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, SYMTAB ((yysemantic_stack_[(2) - (2)].sval)), "", "");
    ;}
    break;

  case 205:
#line 2242 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
    ;}
    break;

  case 206:
#line 2250 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    ;}
    break;

  case 207:
#line 2254 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    ;}
    break;

  case 209:
#line 2263 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (6)].sval)));
    ;}
    break;

  case 210:
#line 2267 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
    ;}
    break;

  case 211:
#line 2271 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), "");
    ;}
    break;

  case 212:
#line 2278 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = SYMTAB ((yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 213:
#line 2293 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 214:
#line 2301 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 215:
#line 2311 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 216:
#line 2317 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 217:
#line 2328 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 SYMTAB ((yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 218:
#line 2334 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 219:
#line 2343 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 220:
#line 2353 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 221:
#line 2358 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		;}
    break;

  case 222:
#line 2370 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 223:
#line 2376 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 224:
#line 2390 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 225:
#line 2396 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 226:
#line 2408 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 227:
#line 2415 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 228:
#line 2422 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 229:
#line 2429 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 230:
#line 2436 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 231:
#line 2443 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 232:
#line 2450 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 233:
#line 2463 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 234:
#line 2467 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 235:
#line 2477 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 236:
#line 2482 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 237:
#line 2493 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 238:
#line 2504 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 239:
#line 2511 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 240:
#line 2524 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 241:
#line 2531 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 242:
#line 2543 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 243:
#line 2549 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 244:
#line 2562 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 245:
#line 2569 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								SYMTAB ((yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		;}
    break;

  case 246:
#line 2583 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 247:
#line 2589 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 248:
#line 2601 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 249:
#line 2607 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 250:
#line 2620 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		;}
    break;

  case 251:
#line 2631 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 252:
#line 2635 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 253:
#line 2646 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 254:
#line 2650 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 255:
#line 2669 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 256:
#line 2673 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 257:
#line 2681 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 258:
#line 2689 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 259:
#line 2697 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 260:
#line 2704 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); ;}
    break;

  case 261:
#line 2705 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 262:
#line 2713 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 263:
#line 2721 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 264:
#line 2729 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    ;}
    break;

  case 265:
#line 2743 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 266:
#line 2747 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 267:
#line 2754 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 268:
#line 2767 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 269:
#line 2771 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 270:
#line 2782 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 271:
#line 2786 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 272:
#line 2790 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 273:
#line 2800 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 274:
#line 2804 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 275:
#line 2808 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 276:
#line 2812 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 277:
#line 2816 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 278:
#line 2826 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 279:
#line 2830 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 280:
#line 2835 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 281:
#line 2846 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 2850 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 283:
#line 2854 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 284:
#line 2864 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 285:
#line 2868 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 286:
#line 2880 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 287:
#line 2884 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 288:
#line 2896 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 289:
#line 2900 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 290:
#line 2912 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 291:
#line 2916 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 292:
#line 2928 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 293:
#line 2932 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 294:
#line 2944 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 295:
#line 2948 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 296:
#line 2952 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 297:
#line 2956 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 298:
#line 2968 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 2972 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 2976 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 2986 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 302:
#line 2990 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 303:
#line 2994 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 304:
#line 2998 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 305:
#line 3002 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 306:
#line 3006 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 307:
#line 3016 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 308:
#line 3020 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 309:
#line 3024 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 310:
#line 3034 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 311:
#line 3038 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 312:
#line 3042 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 313:
#line 3046 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    ;}
    break;

  case 314:
#line 3058 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 315:
#line 3064 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 316:
#line 3076 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 317:
#line 3082 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 318:
#line 3096 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(3) - (2)].sval))),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 319:
#line 3102 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 320:
#line 3144 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 321:
#line 3148 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 322:
#line 3152 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 323:
#line 3156 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 324:
#line 3168 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    ;}
    break;

  case 325:
#line 3178 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 326:
#line 3189 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 327:
#line 3194 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 328:
#line 3204 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 329:
#line 3208 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 330:
#line 3218 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 331:
#line 3224 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 332:
#line 3230 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 333:
#line 3236 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 334:
#line 3248 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 335:
#line 3254 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 336:
#line 3265 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 337:
#line 3269 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 338:
#line 3273 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 339:
#line 3277 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 340:
#line 3281 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 341:
#line 3285 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 342:
#line 3289 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 343:
#line 3299 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 344:
#line 3303 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 345:
#line 3313 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 346:
#line 3319 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 347:
#line 3331 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 348:
#line 3335 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 349:
#line 3339 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 350:
#line 3343 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 351:
#line 3347 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 352:
#line 3362 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 353:
#line 3366 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 354:
#line 3376 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 355:
#line 3380 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 356:
#line 3390 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 357:
#line 3397 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 358:
#line 3404 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 359:
#line 3417 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 360:
#line 3421 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 361:
#line 3433 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 362:
#line 3439 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 363:
#line 3453 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 364:
#line 3464 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 365:
#line 3468 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 366:
#line 3472 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 367:
#line 3476 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 368:
#line 3480 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 369:
#line 3484 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 370:
#line 3488 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 371:
#line 3492 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 372:
#line 3502 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 373:
#line 3506 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 374:
#line 3516 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		;}
    break;

  case 375:
#line 3521 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		;}
    break;

  case 376:
#line 3526 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		;}
    break;

  case 377:
#line 3537 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 378:
#line 3547 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 379:
#line 3551 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 380:
#line 3562 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 381:
#line 3572 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 382:
#line 3583 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 383:
#line 3639 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 384:
#line 3645 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 385:
#line 3657 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 386:
#line 3663 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 387:
#line 3675 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 388:
#line 3679 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 389:
#line 3689 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 390:
#line 3693 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 391:
#line 3697 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 392:
#line 3707 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 393:
#line 3715 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		;}
    break;

  case 394:
#line 3723 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 395:
#line 3731 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		;}
    break;

  case 396:
#line 3739 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		;}
    break;

  case 397:
#line 3747 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		;}
    break;

  case 398:
#line 3762 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 399:
#line 3768 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 400:
#line 3780 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 401:
#line 3786 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 402:
#line 3799 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		;}
    break;

  case 405:
#line 3816 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 406:
#line 3821 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 407:
#line 3832 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 408:
#line 3836 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 409:
#line 3843 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 410:
#line 3849 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 411:
#line 3855 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 412:
#line 3863 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 413:
#line 3877 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 414:
#line 3881 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 415:
#line 3888 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 416:
#line 3894 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 417:
#line 3900 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 418:
#line 3908 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 419:
#line 3922 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 420:
#line 3927 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 421:
#line 3938 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 422:
#line 3943 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 423:
#line 3954 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 424:
#line 3959 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 425:
#line 3964 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 426:
#line 3970 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 427:
#line 3982 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 428:
#line 3988 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 429:
#line 3993 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 430:
#line 3998 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 431:
#line 4009 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 432:
#line 4014 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 433:
#line 4029 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 434:
#line 4034 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 435:
#line 4051 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 436:
#line 4066 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 437:
#line 4070 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 438:
#line 4074 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 439:
#line 4078 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 440:
#line 4082 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 441:
#line 4086 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 442:
#line 4096 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 443:
#line 4107 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 444:
#line 4113 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 445:
#line 4119 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 446:
#line 4124 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 447:
#line 4146 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		;}
    break;

  case 448:
#line 4152 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 449:
#line 4158 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 450:
#line 4163 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 451:
#line 4174 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 452:
#line 4184 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 453:
#line 4194 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 454:
#line 4200 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 455:
#line 4206 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 456:
#line 4211 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 457:
#line 4222 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 458:
#line 4228 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 459:
#line 4240 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 460:
#line 4252 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 461:
#line 4258 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 462:
#line 4264 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 463:
#line 4301 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 464:
#line 4306 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 465:
#line 4311 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 466:
#line 4322 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 467:
#line 4326 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 468:
#line 4330 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 469:
#line 4340 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 470:
#line 4351 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 471:
#line 4355 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 472:
#line 4359 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 473:
#line 4363 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 474:
#line 4367 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 475:
#line 4371 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 476:
#line 4375 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 477:
#line 4379 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 478:
#line 4383 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 479:
#line 4393 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 480:
#line 4403 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 481:
#line 4407 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 482:
#line 4412 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 483:
#line 4423 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 484:
#line 4433 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 485:
#line 4443 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 486:
#line 4447 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 487:
#line 4451 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 488:
#line 4461 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 489:
#line 4467 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		;}
    break;

  case 490:
#line 4473 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 491:
#line 4479 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 492:
#line 4485 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		;}
    break;

  case 493:
#line 4497 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 494:
#line 4508 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		;}
    break;

  case 495:
#line 4515 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
                           NULL,
                           true);
		;}
    break;

  case 496:
#line 4522 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		;}
    break;

  case 497:
#line 4529 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		;}
    break;

  case 498:
#line 4536 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 499:
#line 4543 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		;}
    break;

  case 500:
#line 4550 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		;}
    break;

  case 501:
#line 4563 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))));
		;}
    break;

  case 502:
#line 4584 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 503:
#line 4591 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 504:
#line 4611 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 505:
#line 4651 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 506:
#line 4656 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 507:
#line 4659 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 508:
#line 4667 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 509:
#line 4673 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 510:
#line 4679 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 511:
#line 4685 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 512:
#line 4691 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 513:
#line 4698 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 514:
#line 4704 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 515:
#line 4710 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 516:
#line 4716 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 517:
#line 4722 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 518:
#line 4734 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 519:
#line 4739 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 520:
#line 4749 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 521:
#line 4755 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 522:
#line 4767 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 523:
#line 4793 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 524:
#line 4804 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 525:
#line 4810 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 526:
#line 4823 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 527:
#line 4837 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 528:
#line 4844 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 529:
#line 4851 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 530:
#line 4862 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(5) - (3)].node)),
                          (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 531:
#line 4869 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(8) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
                          (yysemantic_stack_[(8) - (8)].expr));
    ;}
    break;

  case 532:
#line 4877 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(11) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(11) - (6)].sval)),
                          SYMTAB ((yysemantic_stack_[(11) - (9)].sval)),
                          (yysemantic_stack_[(11) - (11)].expr));
    ;}
    break;

  case 533:
#line 4886 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(14) - (3)].node)),
                          SYMTAB ((yysemantic_stack_[(14) - (6)].sval)),
                          SYMTAB ((yysemantic_stack_[(14) - (9)].sval)),
                          SYMTAB ((yysemantic_stack_[(14) - (12)].sval)),
                          (yysemantic_stack_[(14) - (14)].expr));
    ;}
    break;

  case 535:
#line 4902 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 536:
#line 4919 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); ;}
    break;

  case 537:
#line 4920 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); ;}
    break;

  case 538:
#line 4921 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); ;}
    break;

  case 539:
#line 4922 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); ;}
    break;

  case 540:
#line 4923 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); ;}
    break;

  case 541:
#line 4924 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); ;}
    break;

  case 542:
#line 4925 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); ;}
    break;

  case 543:
#line 4926 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); ;}
    break;

  case 544:
#line 4927 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); ;}
    break;

  case 545:
#line 4928 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); ;}
    break;

  case 546:
#line 4929 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); ;}
    break;

  case 547:
#line 4930 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); ;}
    break;

  case 548:
#line 4931 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); ;}
    break;

  case 549:
#line 4932 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); ;}
    break;

  case 550:
#line 4933 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); ;}
    break;

  case 551:
#line 4934 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); ;}
    break;

  case 552:
#line 4935 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); ;}
    break;

  case 553:
#line 4936 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); ;}
    break;

  case 554:
#line 4937 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); ;}
    break;

  case 555:
#line 4938 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); ;}
    break;

  case 556:
#line 4939 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); ;}
    break;

  case 557:
#line 4940 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); ;}
    break;

  case 558:
#line 4941 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); ;}
    break;

  case 559:
#line 4942 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); ;}
    break;

  case 560:
#line 4943 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); ;}
    break;

  case 561:
#line 4944 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); ;}
    break;

  case 562:
#line 4945 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); ;}
    break;

  case 563:
#line 4946 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); ;}
    break;

  case 564:
#line 4947 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); ;}
    break;

  case 565:
#line 4948 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); ;}
    break;

  case 566:
#line 4949 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); ;}
    break;

  case 567:
#line 4950 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); ;}
    break;

  case 568:
#line 4951 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); ;}
    break;

  case 569:
#line 4952 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); ;}
    break;

  case 570:
#line 4953 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); ;}
    break;

  case 571:
#line 4954 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); ;}
    break;

  case 572:
#line 4955 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); ;}
    break;

  case 573:
#line 4956 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); ;}
    break;

  case 574:
#line 4957 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); ;}
    break;

  case 575:
#line 4958 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); ;}
    break;

  case 576:
#line 4959 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); ;}
    break;

  case 577:
#line 4960 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); ;}
    break;

  case 578:
#line 4961 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); ;}
    break;

  case 579:
#line 4962 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); ;}
    break;

  case 580:
#line 4963 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); ;}
    break;

  case 581:
#line 4964 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); ;}
    break;

  case 582:
#line 4965 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); ;}
    break;

  case 583:
#line 4966 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); ;}
    break;

  case 584:
#line 4967 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); ;}
    break;

  case 585:
#line 4968 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); ;}
    break;

  case 586:
#line 4969 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); ;}
    break;

  case 587:
#line 4970 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); ;}
    break;

  case 588:
#line 4971 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); ;}
    break;

  case 589:
#line 4972 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); ;}
    break;

  case 590:
#line 4973 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); ;}
    break;

  case 591:
#line 4974 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); ;}
    break;

  case 592:
#line 4975 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); ;}
    break;

  case 593:
#line 4976 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); ;}
    break;

  case 594:
#line 4977 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); ;}
    break;

  case 595:
#line 4978 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); ;}
    break;

  case 596:
#line 4979 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); ;}
    break;

  case 597:
#line 4980 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); ;}
    break;

  case 598:
#line 4981 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); ;}
    break;

  case 599:
#line 4982 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); ;}
    break;

  case 600:
#line 4983 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); ;}
    break;

  case 601:
#line 4984 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); ;}
    break;

  case 602:
#line 4985 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); ;}
    break;

  case 603:
#line 4986 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); ;}
    break;

  case 604:
#line 4987 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); ;}
    break;

  case 605:
#line 4988 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); ;}
    break;

  case 606:
#line 4989 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); ;}
    break;

  case 607:
#line 4990 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); ;}
    break;

  case 608:
#line 4991 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); ;}
    break;

  case 609:
#line 4992 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); ;}
    break;

  case 610:
#line 4993 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); ;}
    break;

  case 611:
#line 4994 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); ;}
    break;

  case 612:
#line 4995 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); ;}
    break;

  case 613:
#line 4996 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); ;}
    break;

  case 614:
#line 4997 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); ;}
    break;

  case 615:
#line 4998 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); ;}
    break;

  case 616:
#line 4999 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); ;}
    break;

  case 617:
#line 5000 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); ;}
    break;

  case 618:
#line 5001 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); ;}
    break;

  case 619:
#line 5002 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); ;}
    break;

  case 620:
#line 5003 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); ;}
    break;

  case 621:
#line 5004 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); ;}
    break;

  case 622:
#line 5005 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); ;}
    break;

  case 623:
#line 5006 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); ;}
    break;

  case 624:
#line 5007 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); ;}
    break;

  case 625:
#line 5008 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); ;}
    break;

  case 626:
#line 5009 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); ;}
    break;

  case 627:
#line 5010 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); ;}
    break;

  case 628:
#line 5011 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); ;}
    break;

  case 629:
#line 5012 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); ;}
    break;

  case 630:
#line 5013 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); ;}
    break;

  case 631:
#line 5014 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); ;}
    break;

  case 632:
#line 5015 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); ;}
    break;

  case 633:
#line 5016 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); ;}
    break;

  case 634:
#line 5017 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); ;}
    break;

  case 635:
#line 5018 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); ;}
    break;

  case 636:
#line 5019 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); ;}
    break;

  case 637:
#line 5020 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); ;}
    break;

  case 638:
#line 5021 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); ;}
    break;

  case 639:
#line 5022 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); ;}
    break;

  case 640:
#line 5023 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); ;}
    break;

  case 641:
#line 5024 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); ;}
    break;

  case 642:
#line 5025 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); ;}
    break;

  case 643:
#line 5026 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); ;}
    break;

  case 644:
#line 5027 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); ;}
    break;

  case 645:
#line 5028 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); ;}
    break;

  case 646:
#line 5029 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); ;}
    break;

  case 647:
#line 5030 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); ;}
    break;

  case 648:
#line 5031 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); ;}
    break;

  case 649:
#line 5032 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); ;}
    break;

  case 650:
#line 5033 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); ;}
    break;

  case 651:
#line 5034 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); ;}
    break;

  case 652:
#line 5035 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); ;}
    break;

  case 653:
#line 5036 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); ;}
    break;

  case 654:
#line 5037 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); ;}
    break;

  case 655:
#line 5038 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); ;}
    break;

  case 656:
#line 5039 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); ;}
    break;

  case 657:
#line 5040 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); ;}
    break;

  case 658:
#line 5041 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); ;}
    break;

  case 659:
#line 5042 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); ;}
    break;

  case 660:
#line 5043 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); ;}
    break;

  case 661:
#line 5044 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); ;}
    break;

  case 662:
#line 5045 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); ;}
    break;

  case 663:
#line 5046 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); ;}
    break;

  case 664:
#line 5047 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); ;}
    break;

  case 665:
#line 5048 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); ;}
    break;

  case 666:
#line 5049 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); ;}
    break;

  case 667:
#line 5050 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); ;}
    break;

  case 668:
#line 5051 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); ;}
    break;

  case 669:
#line 5052 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); ;}
    break;

  case 670:
#line 5053 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); ;}
    break;

  case 671:
#line 5054 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); ;}
    break;

  case 672:
#line 5055 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); ;}
    break;

  case 673:
#line 5056 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); ;}
    break;

  case 674:
#line 5057 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); ;}
    break;

  case 675:
#line 5058 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); ;}
    break;

  case 676:
#line 5059 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); ;}
    break;

  case 677:
#line 5060 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); ;}
    break;

  case 678:
#line 5061 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); ;}
    break;

  case 679:
#line 5062 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); ;}
    break;

  case 680:
#line 5063 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); ;}
    break;

  case 681:
#line 5064 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); ;}
    break;

  case 682:
#line 5065 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); ;}
    break;

  case 683:
#line 5066 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); ;}
    break;

  case 684:
#line 5067 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); ;}
    break;

  case 685:
#line 5068 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); ;}
    break;

  case 686:
#line 5069 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); ;}
    break;

  case 687:
#line 5070 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); ;}
    break;

  case 688:
#line 5071 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); ;}
    break;

  case 689:
#line 5072 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); ;}
    break;

  case 690:
#line 5073 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); ;}
    break;

  case 691:
#line 5074 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); ;}
    break;

  case 692:
#line 5075 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); ;}
    break;

  case 693:
#line 5076 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); ;}
    break;

  case 694:
#line 5077 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); ;}
    break;

  case 695:
#line 5078 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); ;}
    break;

  case 696:
#line 5079 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); ;}
    break;

  case 697:
#line 5080 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); ;}
    break;

  case 698:
#line 5081 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); ;}
    break;

  case 699:
#line 5082 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); ;}
    break;

  case 700:
#line 5083 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); ;}
    break;

  case 701:
#line 5084 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); ;}
    break;

  case 702:
#line 5085 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); ;}
    break;

  case 703:
#line 5086 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); ;}
    break;

  case 704:
#line 5087 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("create"); ;}
    break;

  case 705:
#line 5088 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("build"); ;}
    break;

  case 706:
#line 5089 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); ;}
    break;

  case 707:
#line 5090 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); ;}
    break;

  case 708:
#line 5091 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("hash"); ;}
    break;

  case 709:
#line 5092 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("btree"); ;}
    break;

  case 710:
#line 5093 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("drop"); ;}
    break;

  case 711:
#line 5105 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    ;}
    break;

  case 712:
#line 5111 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    ;}
    break;

  case 713:
#line 5128 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		;}
    break;

  case 714:
#line 5132 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		;}
    break;

  case 715:
#line 5136 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;

  case 716:
#line 5140 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		;}
    break;

  case 717:
#line 5150 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 718:
#line 5153 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 719:
#line 5156 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 720:
#line 5159 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 721:
#line 5168 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 722:
#line 5171 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 723:
#line 5180 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 724:
#line 5183 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 725:
#line 5192 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 726:
#line 5195 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 727:
#line 5204 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 728:
#line 5207 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 729:
#line 5216 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 730:
#line 5219 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 731:
#line 5222 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 732:
#line 5231 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 733:
#line 5234 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 734:
#line 5243 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		;}
    break;

  case 735:
#line 5247 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 736:
#line 5257 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 737:
#line 5260 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 738:
#line 5263 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 739:
#line 5266 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 740:
#line 5269 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 741:
#line 5278 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 742:
#line 5287 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 743:
#line 5291 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 744:
#line 5295 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 745:
#line 5299 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 746:
#line 5303 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 747:
#line 5307 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 748:
#line 5311 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 749:
#line 5321 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 750:
#line 5324 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 751:
#line 5327 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 752:
#line 5330 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 753:
#line 5339 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 754:
#line 5342 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 755:
#line 5345 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 756:
#line 5348 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 757:
#line 5357 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 758:
#line 5360 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 759:
#line 5369 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 760:
#line 5372 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 761:
#line 5375 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 762:
#line 5378 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 763:
#line 5381 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 764:
#line 5384 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 765:
#line 5387 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 766:
#line 5396 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 767:
#line 5399 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 768:
#line 5408 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 769:
#line 5411 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 770:
#line 5414 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 771:
#line 5417 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 772:
#line 5426 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 773:
#line 5429 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 774:
#line 5432 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 775:
#line 5435 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 776:
#line 5438 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 777:
#line 5447 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 778:
#line 5450 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 779:
#line 5459 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 780:
#line 5462 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 781:
#line 5471 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 782:
#line 5474 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 783:
#line 5483 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 784:
#line 5486 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 785:
#line 5495 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 786:
#line 5504 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 787:
#line 5507 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 788:
#line 5516 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 789:
#line 5519 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 790:
#line 5522 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 791:
#line 5531 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 792:
#line 5534 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 793:
#line 5537 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 794:
#line 5540 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 795:
#line 5543 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 796:
#line 5552 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 797:
#line 5556 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 798:
#line 5560 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 799:
#line 5564 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 800:
#line 5574 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 801:
#line 5583 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 802:
#line 5593 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 803:
#line 5602 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 804:
#line 5605 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 805:
#line 5614 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 806:
#line 5617 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 807:
#line 5620 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 808:
#line 5629 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 809:
#line 5632 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 810:
#line 5641 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6989 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -993;
  const short int
  xquery_parser::yypact_[] =
  {
      1336,  -993,  -993,  -993,  -993,   -18,   -60,   234,  -993,   282,
     113,   -27,   200,  6543,   286,   395,   444,    55,  -993,  -993,
    -993,  -993,  -993,  -993,   361,    90,  -993,   536,   416,  -993,
     385,  -993,  -993,  -993,   480,   486,  -993,   460,   300,   482,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   459,
     475,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  6796,  -993,  5774,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  8314,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,   513,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  1598,  8314,
    -993,  -993,  -993,  -993,  -993,  -993,   500,  -993,  -993,  -993,
    -993,   609,  -993,  6290,  -993,  -993,  -993,  -993,  -993,  8314,
    -993,  -993,  5513,  -993,  -993,  -993,  -993,  -993,  -993,   503,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,    13,   448,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   327,   518,
     347,  -993,   451,   260,  -993,  -993,  -993,  -993,  -993,  -993,
     557,  -993,   526,  -993,   559,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,   398,   400,   401,  -993,  -993,  -993,  -993,  -993,  3947,
     670,  -993,  4208,  -993,  -993,   112,  4469,   501,   502,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   -37,  -993,
    -993,  -993,  -993,   298,  8314,  -993,  -993,  -993,  -993,  -993,
     527,   600,  -993,   591,   441,   249,   221,   302,   314,  -993,
     607,   506,   597,   602,  4730,  -993,  -993,  -993,   272,  -993,
    -993,  5513,  -993,   438,  -993,   548,  5774,  -993,   548,  5774,
    -993,  -993,  -993,  -993,   548,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,   553,  -993,  -993,  -993,  4469,  -993,  -993,
    4469,  8314,  4469,   560,   562,  4469,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  4469,  7049,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   563,  4469,
    4469,   524,  4469,   533,  8314,   657,   665,   522,   522,   657,
    8314,   127,   236,   685,   -61,   289,   570,   604,   259,   689,
     405,   -46,   306,   685,  -993,  -993,   443,  -993,  -993,  -993,
    -993,  -993,  4469,  -993,  4469,    22,   574,    71,    32,  8314,
     689,  8314,  8314,  4469,   456,   457,  -993,   610,   613,  8314,
      44,  4469,  7302,   577,   580,   581,   582,   583,   584,  -993,
    -993,  -993,  8314,  -993,   555,   702,  4469,    42,  -993,   713,
     564,  -993,  4469,   532,  -993,   711,  4469,  4469,   565,  4469,
    4469,  4469,  4469,   521,  8314,  4469,  8314,   685,   685,   685,
    -993,  -993,  -993,  -993,    55,   536,  -993,  -993,   112,   695,
    4469,  -993,  4469,   589,   486,   300,   482,   638,   592,   593,
    4469,  4469,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   651,
    -993,   -28,  4991,  4991,  4991,  -993,  4991,  4991,  -993,  4991,
    -993,  4991,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  4991,
    4991,    12,  4991,  4991,  4991,  4991,  4991,  4991,  4991,  4991,
    4991,  4991,  4991,   534,   667,   669,   671,  -993,  -993,  -993,
    1859,  -993,  -993,  5513,  5513,  4469,   548,  -993,  -993,   548,
    -993,   548,  2120,  5252,  -993,   586,   614,  -993,   587,  4469,
    4469,   588,   590,  -993,    -7,    80,  2381,   598,   599,  -993,
     603,  -993,   619,  -993,  8314,  -993,  -993,  -993,  -993,   740,
    -993,  -993,  -993,  -993,  -993,  -993,   673,   678,  -993,  -993,
     318,  8314,   367,   620,   630,   685,   663,   666,  -993,  -993,
    -993,   362,    56,   368,   764,  -993,  -993,   254,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,   515,  -993,   616,
     621,   617,  -993,   622,  2642,   689,   706,   756,   689,   685,
     708,    -6,  -993,    20,   676,   668,   700,  -993,   -48,   629,
    -993,  -993,  8314,   -29,  -993,   627,   580,   459,  -993,   628,
     631,   632,  -993,   161,   183,  2903,    23,  -993,  8314,   702,
    -993,   -69,   633,  -993,  -993,  -993,  -993,   635,  -993,    30,
    -993,  -993,  -993,    67,    86,   722,   585,   595,   -55,  -993,
     680,   641,    63,  -993,  -993,  -993,  -993,  -993,   637,  -993,
      28,  -993,  -993,   -12,   655,  8314,  4469,   707,  -993,  -993,
     709,  7808,   710,  4469,   712,   -11,   674,   -38,   600,  -993,
    -993,  -993,  -993,  -993,  4991,  -993,  -993,  -993,  4469,    12,
     270,  -993,   556,   375,   578,   579,  -993,  -993,   573,   305,
     221,   221,   230,   302,   302,   302,   302,   314,   314,  -993,
    -993,  7808,  7808,  8314,  8314,  -993,   653,  -993,  -993,   654,
    -993,  -993,  -993,   184,   724,   647,   658,   -18,  4469,  -993,
     659,   660,   737,   691,  8314,  -993,  8314,  -993,  -993,   662,
    -993,  -993,  -993,   104,    36,   619,  -993,   292,   323,  8061,
     703,  4469,  -993,  -993,  -993,   750,   705,  4469,   685,   685,
    -993,   508,   685,  -993,  -993,   575,  -993,  -993,   576,   290,
    -993,  -993,  -993,  -993,  -993,  -993,   594,  -993,  -993,  4469,
     652,   698,  -993,  -993,  -993,   672,   720,   685,   694,   727,
     762,   685,   741,  4469,  4469,   716,   685,  4469,   743,  4469,
     723,   -65,  -993,   239,   618,  -993,  -993,   392,   -29,  -993,
    -993,  -993,   714,  8314,  -993,  8314,  -993,  -993,   686,  4469,
     830,  -993,   164,  -993,    76,  -993,  -993,   836,  -993,    83,
    4469,  4469,  4469,   384,  4469,  4469,  4469,  4469,  4469,  4469,
     752,  4469,  4469,   636,   721,   755,   695,  -993,  4469,  -993,
     414,   767,  -993,  8314,   768,  -993,  8314,   728,   730,  -993,
     206,  -993,  -993,  -993,  8314,  -993,  8314,  4469,   742,  4469,
    4469,    -1,   744,  -993,   704,   715,  -993,   639,  -993,   135,
    -993,   308,    29,   643,    12,   308,  4991,  4991,   417,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,    12,   745,    29,  -993,
     612,   826,  -993,  -993,  -993,  -993,  -993,   753,  -993,  -993,
    -993,  4469,  -993,  -993,  -993,  -993,   717,  -993,  -993,  7555,
     437,  -993,  3164,   725,   726,   757,   729,   731,  -993,  8314,
     800,   187,  -993,  -993,  4469,  -993,   -18,  -993,  -993,  -993,
    -993,   445,  -993,  -993,  -993,  4469,  -993,  -993,  -993,  -993,
    -993,  -993,   634,   -17,   867,  -993,   381,  -993,  -993,   736,
    4469,  3425,  -993,   685,   798,  -993,  -993,  -993,   685,   798,
    8314,  -993,  -993,  4469,   733,  -993,  8314,  -993,  4469,  4469,
     770,  4469,   769,  -993,   793,   797,  4469,  8314,   561,   838,
    -993,  -993,  -993,  3686,   738,   739,  -993,  -993,  -993,   786,
    -993,   134,  -993,  -993,   904,  -993,  -993,  4469,  8314,  -993,
    -993,   172,  -993,  -993,  -993,   746,   696,   697,  -993,  -993,
    -993,   701,   718,  -993,  -993,  -993,  -993,  -993,   690,  8314,
     748,  -993,   772,   636,  -993,  4469,  8314,   767,  -993,   685,
    -993,   514,  -993,   155,   822,  -993,  4469,   828,   707,  -993,
     749,   754,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  4469,
    -993,  -993,  4469,   791,  4469,  -993,  -993,  4991,  -993,  -993,
    -993,  -993,  -993,     0,  4991,  4991,   273,  -993,   578,  -993,
    -993,   227,  4991,  -993,  -993,   579,    12,   677,  -993,  -993,
    -993,  -993,  -993,  8314,   763,   -22,  -993,  -993,   758,  -993,
    -993,  -993,  -993,  -993,   750,  7808,   818,   845,   766,  -993,
    -993,  -993,   -16,   911,   914,   -16,   -47,   214,   216,   796,
     827,  -993,   773,   854,   685,   798,  -993,  -993,  -993,  -993,
    -993,  -993,  4469,  -993,  4469,  8314,  8314,  -993,   363,  -993,
    4469,  -993,   774,  -993,  -993,   830,  8314,   237,  -993,   775,
     830,  8314,  -993,  -993,  4469,  4469,  4469,  4469,  4469,  -993,
    4469,  6035,  -993,   776,  -993,  -993,  -993,  -993,   822,  -993,
    -993,  -993,   685,  -993,  -993,  -993,  -993,  -993,  -993,  4469,
    -993,   302,  4991,  4991,   302,   371,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,   858,  4469,  8314,  4469,  -993,  -993,
    -993,  -993,  7808,  -993,   -17,   -17,   -16,  -993,  -993,  -993,
      18,   -16,   924,   732,   862,  -993,   862,  -993,  4469,   222,
    4469,  -993,   685,  -993,  -993,  -993,   882,  -993,  -993,  -993,
    -993,   -50,   830,  8314,  -993,   771,   830,  -993,  -993,  -993,
    -993,  -993,  -993,   225,  -993,  -993,  -993,  -993,   302,   302,
    4991,  7808,  -993,   780,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,    29,  -993,   232,  -993,   247,  -993,   857,   750,  4469,
    -993,  -993,   798,   847,   334,   110,  -993,   777,   830,  -993,
     778,   848,   817,   302,   790,  4469,   734,   862,  -993,  -993,
     685,  -993,  -993,  8314,  -993,  -993,   875,   372,  -993,  -993,
    -993,  -993,   794,   224,  -993,  -993,  -993,   781,  -993,  8314,
    -993,  4469,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,   252,  -993,   859,   817,  8314,  -993,
     255,   860,   817,  8314,  -993,   799,   817,  -993
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   357,   358,   536,   504,   692,   693,   696,   694,   697,
     695,   626,   550,   542,   558,   549,   540,   638,   648,   687,
     686,   688,   689,   685,   544,   546,   573,   645,   608,   602,
     647,   643,   570,   646,   702,   597,   639,   700,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   640,   554,   548,
     541,   642,   617,   547,   552,   348,   351,   616,   612,   603,
     583,   539,   338,     0,   611,   619,   627,   336,   607,   374,
     584,   585,   641,   337,   340,   604,   621,     0,   380,   346,
     376,   614,   538,   605,   606,   634,   609,   625,   633,   342,
     341,   557,   596,   636,   375,   624,   629,   543,     0,     0,
     295,   622,   632,   637,   635,   615,   690,   601,   599,   600,
     347,     0,   294,     0,   350,   349,   630,   586,   610,     0,
     339,   324,     0,   356,   631,   613,   620,   628,   623,   691,
     577,   582,   581,   580,   579,   578,   551,   598,     0,   537,
     644,   571,   677,   676,   678,   556,   555,   574,   683,   545,
     675,   680,   681,   672,   576,   618,   674,   684,   682,   673,
     575,   679,   698,   699,   701,   664,   663,   560,   553,   562,
     561,   657,   653,   568,   572,   569,   666,   667,   650,   559,
     662,   661,   658,   654,   671,   665,   660,   656,   649,   670,
     669,   655,   659,   651,   652,   563,   564,   566,   668,   565,
     567,   704,   705,   710,   706,   703,   708,   709,   707,     0,
       0,     2,     0,     4,     6,     0,     0,     0,     0,    17,
      19,    21,    22,    23,    31,    24,    28,    29,    35,    36,
      37,    32,    33,    39,    40,    26,    25,    30,    34,   153,
     152,   149,   150,   151,   154,    27,    11,   130,   131,   135,
     137,   169,   175,     0,     0,   167,   168,   138,   139,   140,
     141,   251,   253,   255,   265,   268,   270,   273,   278,   281,
     284,   286,   288,   290,     0,   292,   298,   300,     0,   316,
     299,   320,   323,   325,   328,   330,     0,   335,   332,     0,
     343,   353,   355,   329,   359,   364,   372,   365,   366,   367,
     370,   371,   368,   369,   387,   389,   390,   391,   388,   436,
     437,   438,   439,   440,   441,   352,   478,   470,   477,   476,
     475,   472,   474,   471,   473,   373,    38,   142,   143,   145,
     144,   146,   147,   354,   148,   105,   102,     0,   109,   110,
       0,     0,     0,     0,     0,     0,   692,   693,   696,   697,
     695,   626,   550,   542,   558,   549,   540,   638,   544,   546,
     645,   608,   647,   702,   597,   700,   587,   588,   548,   541,
     539,   609,     0,     0,   690,   691,   537,   683,   545,   675,
     681,   672,   575,   698,   701,   704,   705,   710,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    83,     0,    84,    85,    87,
     114,   117,     0,   535,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,     0,     0,     0,
       0,     0,     0,     0,   542,   549,   540,   546,   539,   344,
     354,   377,     0,   378,     0,   403,     0,     0,   319,     0,
       0,   322,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     1,     5,     7,     0,     0,    12,    10,    14,    15,
       0,   133,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,   174,   170,   176,   171,   173,   172,   179,
     180,     0,     0,     0,     0,   309,     0,     0,   307,     0,
     260,     0,   308,   301,   306,   305,   304,   303,   302,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,   296,   293,
       0,   317,   321,     0,     0,     0,   331,   361,   334,   333,
     345,   360,     0,     0,   107,     0,     0,   502,     0,     0,
       0,     0,     0,   494,     0,     0,     0,     0,     0,   483,
       0,   484,     0,   119,     0,   120,   116,   115,   118,     0,
      96,    97,    48,    49,   534,    57,     0,     0,    42,    43,
       0,     0,     0,     0,     0,     0,     0,     0,   505,   506,
     507,     0,     0,     0,     0,   749,   750,     0,    47,   742,
     743,   744,   745,   746,   747,   748,    86,     0,    88,     0,
       0,     0,   485,     0,     0,     0,    66,     0,     0,     0,
      58,     0,   240,     0,     0,     0,   192,   193,     0,     0,
     157,   158,     0,     0,   178,     0,     0,     0,   480,     0,
       0,     0,   488,     0,     0,     0,     0,   379,   404,   403,
     400,     0,     0,   434,   433,   318,   493,     0,   431,     0,
     518,   519,   479,     0,     0,     0,     0,     0,     0,   524,
       0,     0,     0,   195,   212,   111,   113,   112,     0,    18,
       0,    20,   136,     0,     0,     0,     0,     0,   156,   213,
       0,     0,     0,     0,     0,     0,     0,     0,   252,   254,
     258,   264,   263,   262,     0,   259,   256,   257,     0,     0,
       0,   734,   266,   713,   721,   723,   725,   727,   729,   732,
     272,   271,   269,   275,   276,   277,   274,   279,   280,   283,
     282,     0,     0,     0,     0,   314,     0,   326,   327,     0,
     362,   383,   385,     0,   638,     0,     0,     0,     0,   310,
       0,     0,     0,     0,     0,   498,     0,   495,   443,     0,
     442,   451,   452,     0,     0,     0,    46,     0,     0,     0,
      74,     0,    70,    72,    73,    77,    80,     0,     0,     0,
      56,     0,     0,   751,   752,     0,   753,   757,     0,     0,
     786,   755,   756,   785,   754,   758,     0,   765,   787,     0,
       0,     0,   487,   486,   453,     0,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   712,     0,     0,   159,   160,     0,   165,   501,
     481,   482,     0,     0,   491,     0,   489,   447,     0,     0,
     403,   401,     0,   392,     0,   381,   382,     0,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,   134,     0,   166,
     224,   220,   222,     0,   214,   215,     0,   543,   551,   459,
     460,   466,   467,   469,     0,   182,     0,     0,     0,     0,
       0,     0,     0,   261,     0,     0,   728,     0,   267,     0,
     741,     0,     0,     0,     0,     0,     0,     0,   714,   718,
     736,   717,   740,   738,   737,   739,     0,     0,     0,   730,
     793,   791,   795,   733,   285,   287,   289,   457,   291,   315,
     363,     0,   384,   104,   103,   108,     0,   312,   311,     0,
       0,   246,     0,     0,     0,   502,     0,     0,   444,     0,
      98,     0,   124,   122,     0,   121,     0,    54,    55,    52,
      53,     0,    75,    76,    78,     0,    79,    44,    45,    50,
      51,    41,     0,     0,     0,   760,     0,   759,   776,     0,
       0,     0,   454,     0,    68,    62,    65,    64,     0,    60,
       0,   238,   242,     0,     0,   106,     0,   197,     0,     0,
       0,     0,     0,   161,     0,     0,     0,     0,   206,     0,
     203,   208,   164,     0,     0,     0,   448,   239,   404,     0,
     393,     0,   427,   424,     0,   428,   429,     0,     0,   430,
     423,     0,   398,   426,   425,     0,     0,     0,   511,   512,
     508,     0,     0,   516,   517,   513,   522,   520,     0,     0,
       0,   526,     0,   527,   528,     0,     0,   221,   233,     0,
     234,     0,   225,   226,   227,   228,     0,   217,     0,   181,
       0,     0,   463,   465,   464,   461,   190,   191,   184,     0,
     186,   183,     0,     0,     0,   735,   731,     0,   788,   789,
     809,   808,   804,     0,     0,     0,     0,   790,   722,   803,
     715,     0,     0,   720,   719,   724,     0,     0,   794,   792,
     458,   386,   313,     0,     0,     0,   247,   445,     0,   499,
     500,   503,   496,   497,   126,     0,     0,    99,     0,   123,
      71,    81,   774,     0,     0,   772,   768,     0,     0,     0,
       0,   455,     0,    67,     0,    61,   241,   243,    13,   194,
     199,   198,     0,   201,     0,     0,     0,   163,   204,   207,
       0,   449,     0,   492,   490,   403,     0,     0,   435,     0,
     403,     0,   399,     9,     0,     0,     0,     0,     0,   525,
       0,     0,   529,     0,   196,   237,   235,   236,   229,   230,
     231,   223,     0,   218,   216,   468,   462,   188,   185,     0,
     187,   810,     0,     0,   796,     0,   807,   806,   805,   800,
     801,   716,   726,   802,     0,     0,     0,     0,   446,   127,
     100,   125,     0,   129,     0,     0,   775,   777,   779,   781,
       0,   773,     0,     0,     0,   763,     0,   761,     0,     0,
       0,   456,     0,    63,   200,   202,   211,   210,   205,   162,
     450,     0,   403,     0,   128,     0,   403,   509,   510,   514,
     515,   521,   523,     0,   711,   232,   219,   189,   798,   797,
       0,     0,   248,     0,   244,   101,   784,   783,   778,   782,
     780,   769,   770,     0,   766,     0,    94,    90,    92,     0,
      89,   250,    69,     0,   413,   407,   402,     0,   403,   394,
       0,     0,     0,   799,     0,     0,     0,     0,   764,   762,
       0,    93,    95,     0,   421,   415,     0,   414,   416,   422,
     419,   409,     0,   408,   410,   420,   396,     0,   395,     0,
     530,     0,   245,   771,   767,    91,   209,   406,   417,   418,
     405,   411,   412,   397,     0,   249,     0,     0,     0,   531,
       0,     0,     0,     0,   532,     0,     0,   533
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -993,  -993,   759,  -993,   751,   760,  -993,   761,  -993,   478,
     479,  -482,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -826,  -993,  -993,  -993,  -993,
     -10,   180,  -993,   410,  -993,  -993,  -993,   567,   558,  -329,
    -993,  -993,  -993,   196,  -993,  -740,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,   238,   115,  -993,  -993,  -164,  -993,  -929,
     779,   -85,  -993,   491,  -331,  -993,  -993,  -993,  -993,   136,
    -993,  -993,   735,  -993,  -993,  -993,  -993,  -993,    89,  -483,
    -625,  -993,  -993,  -993,   -30,  -993,  -993,  -191,   -39,   -86,
    -993,  -993,  -993,   -97,  -993,  -993,   105,   -94,  -993,  -993,
     -87,  -950,  -993,   546,    -9,  -993,  -993,    39,  -993,  -993,
     488,   489,  -993,  -456,  -897,   470,   101,  -521,   102,   103,
    -993,  -993,  -993,  -993,  -993,   747,  -993,  -993,  -993,  -993,
    -993,   765,  -993,  -993,  -104,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,   -51,  -196,  -993,  -993,   204,     9,  -993,  -523,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -854,
    -993,   -35,  -993,   338,  -667,  -993,  -993,  -993,  -993,  -993,
    -335,  -328,  -992,  -838,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,   256,  -624,  -731,  -993,   223,  -101,
    -708,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   571,   596,
    -553,   240,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
     -56,  -993,  -993,   -58,  -402,  -374,   -13,  -993,   288,  -993,
    -993,    94,    87,  -107,   294,  -993,  -993,    97,  -993,  -702,
    -993,  -993,  -993,  -993,  -234,  -805,  -993,  -129,  -588,  -993,
    -669,  -993,  -993,  -993,  -993,  -916,  -993,  -993,  -993,  -993,
     -93,   106,  -993
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,  1004,   639,   234,   235,   792,
     793,   794,   602,   236,   416,   237,   417,   418,   419,  1306,
    1307,  1259,   238,   784,   239,   336,   563,   240,   241,   242,
     243,   244,   245,   420,   421,   585,   971,   972,  1049,   975,
     246,   247,   492,   248,   249,   250,   502,   437,   847,   848,
     251,   503,   252,   505,   253,   254,   255,   509,   510,  1028,
     716,   256,   646,   692,   647,   653,  1029,  1030,  1031,   693,
     506,   507,   894,   895,  1213,   508,   891,   892,  1082,  1083,
    1084,  1085,   257,   641,   642,   258,   960,   961,   259,   260,
     261,   262,   724,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   529,   530,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   556,   557,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   763,   303,   304,
     305,  1051,   669,   670,   671,  1316,  1342,  1343,  1336,  1337,
    1344,  1338,  1052,  1053,   306,   307,  1054,   308,   309,   310,
     311,   312,   313,   314,   946,   717,   899,  1095,   900,   901,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     566,   964,   325,   326,   327,   328,   329,   330,   331,   688,
     689,   332,  1073,  1074,  1005,   426,   333,   334,   732,   928,
     733,   734,   735,   736,   737,   738,   739,   929,   930,   618,
     619,   620,   621,   622,  1303,  1304,   623,  1246,  1155,  1250,
    1247,   624,   625,   932,   943,  1116,   933,   934,   939,   935,
    1229,  1112,   918
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       388,   595,   862,   902,   997,  1009,   564,   701,   731,   565,
    1050,   627,   449,   454,   743,   744,   745,   746,   461,   835,
     944,   945,  1127,   840,   841,   636,   640,   955,   715,  1120,
    1314,   931,     4,   711,   463,   607,  1113,   844,  1299,   880,
     423,   611,   631,   902,   902,   712,   863,  1222,   443,   673,
     450,   633,   594,   711,   341,   712,   644,   490,   720,  1192,
     721,   722,  1019,   723,   451,   725,  1153,   394,   395,   396,
     397,   398,   399,   726,   727,   695,   696,   697,   656,   839,
     400,   902,   490,  1236,  1042,  1043,   455,   774,   832,   596,
     908,   594,   912,   910,   394,   395,   396,   397,   398,   399,
     459,   711,   649,   713,   597,  1244,   460,   400,   423,    69,
     342,   864,  1113,   401,  1223,   657,  1315,   832,  1042,   335,
     907,    80,   884,  1154,   402,   403,   406,   407,   404,  1340,
    1102,   405,   637,  1209,  1210,   680,   681,   491,   683,   684,
     685,   686,  1042,  1043,   691,    94,   867,  1237,   869,   728,
     484,   834,   729,   406,   407,   408,   805,   885,   973,   702,
     485,   337,   887,   775,   881,   833,  1044,   873,  1245,   708,
     709,   984,   845,   974,   776,   612,   638,   552,   343,   344,
    1042,  1043,  1165,   613,  1045,   714,  1046,  1050,  1300,  1114,
    1115,  1158,   632,  1039,   859,  1192,   614,  1050,   615,   409,
     674,  1252,   714,   800,   868,   846,   731,   731,   616,   969,
     464,   617,   714,  1047,   658,   635,  1020,    99,  1045,  1022,
    1046,   963,   714,   966,  1044,  1231,  1124,   424,  1134,  1341,
     425,   762,  1042,   111,   911,   558,  1149,   830,   560,   714,
    1253,   511,  1045,  1340,  1046,  1042,  1043,  1047,  1079,   714,
     777,   902,   730,   340,  1048,   853,   411,   568,  1285,   410,
     571,   826,  1044,   338,   829,  1114,  1115,  1081,   913,   870,
     871,  1047,   138,   450,   970,    99,   450,   855,   951,  1040,
    1045,  1146,  1046,   411,   872,   806,  1103,   572,   874,   875,
       4,   111,   590,   603,   412,   413,   414,   415,   604,  1056,
    1034,  1057,  1035,   876,   577,   578,   591,   580,  1254,  1047,
    1256,   339,  1186,    99,   807,   808,  1309,   809,   810,  1321,
     711,   412,   413,   414,   415,   535,  1327,  1044,   567,   111,
     138,   854,  1045,  1050,  1046,  1092,  1108,   629,  1334,   630,
     345,  1327,  1042,  1361,  1041,  1045,  1366,  1046,   493,  1371,
    1191,   536,   605,   856,   952,   494,   661,  1147,   495,   496,
     575,  1047,   434,   435,   537,  1093,   497,    69,   138,  1109,
    1021,   672,   532,   994,  1047,   890,  1334,   677,    99,    80,
    1042,   582,   905,  1094,  1255,  1326,  1257,   589,   592,   533,
     995,   532,  1310,  1350,   111,  1322,   987,   988,   538,   789,
     991,   731,  1328,    94,   701,   436,  1121,   728,   533,   550,
     729,   539,   606,   731,  1240,  1273,   643,  1329,   645,   648,
     540,   593,  1367,   389,   977,  1372,   655,  1024,  1025,   664,
     996,   534,   113,   138,  1014,   541,  1312,   902,  1369,   643,
     790,   978,  1045,  1374,  1046,   791,   712,  1377,   542,   757,
     758,   498,  1335,   499,   598,   979,  1024,  1025,   919,  1026,
     983,   690,   611,   694,   994,   756,   986,   500,   599,   472,
     759,  1047,   980,  1226,   473,   712,  1339,  1345,   766,  1227,
    1045,  1157,  1046,   814,   770,   771,   539,  1228,   999,   796,
    1358,   779,   559,   501,   797,   540,  1078,  1027,   561,  1339,
     919,   422,  1011,  1012,   611,  1345,  1015,  1079,  1017,  1047,
     583,  1295,   815,   816,   588,   817,   818,  1080,  1271,  1226,
    1239,   429,  1354,  1275,   959,  1227,  1081,   920,  1037,   430,
     940,   941,   390,  1228,   902,   391,   466,  1135,   467,  1058,
    1059,  1060,   438,  1063,  1064,  1065,  1066,  1067,  1068,   825,
    1070,  1071,   942,  1290,  1110,   539,   469,   890,   470,  1111,
    1324,   394,   395,   396,   540,   760,   399,   790,   760,   920,
     760,   785,   791,   413,   414,   415,  1098,  1298,  1100,  1101,
     858,   392,  1298,   902,   393,   431,  1221,   427,   795,   803,
     428,   432,   804,  1224,  1225,   811,   612,   433,   812,   439,
    1061,  1163,  1062,   731,   613,  1317,   921,   922,   923,  1320,
     608,   609,   610,   553,   554,   440,   924,   614,   452,   615,
    1131,   989,   990,   457,   925,  1024,  1025,  1206,  1207,   616,
     926,   927,   617,   740,   741,   586,   587,   456,   612,   843,
     462,   747,   748,   914,   749,   750,   613,   465,   921,   922,
     923,  1347,   947,   947,  1151,   860,  1296,  1297,   468,   614,
     471,   615,   474,   475,   476,   477,   925,   478,   479,  1160,
     481,   616,  1122,   927,   617,   488,   489,  1205,   512,   513,
     531,   543,  1167,   956,  1331,   545,   555,  1170,  1171,   544,
    1173,   546,   889,   562,   579,  1177,   394,   569,   903,   570,
     576,  1288,  1289,   581,   584,   594,   600,   423,   514,   601,
     413,   634,   650,   651,   665,   652,   515,   516,   654,   517,
     373,   391,   393,   425,   442,   667,   518,   668,   675,   678,
     519,   679,   520,   700,   676,   682,   687,   521,   903,   903,
     903,   903,   704,   705,  1203,   710,   706,   707,   752,   751,
     753,   768,   754,   522,   769,   890,   767,   773,   772,   783,
     786,   965,  1263,   965,   798,   780,   781,   787,  1217,  1323,
     782,  1218,   788,  1220,   799,   801,   903,   523,   524,   525,
     526,   527,   528,   802,   813,   819,   820,   822,   821,   827,
     828,   831,   823,   836,   838,   837,   842,   849,   850,   852,
     865,   851,   866,   877,   879,   909,   878,   882,   883,   888,
    1286,   886,   893,   917,   896,   904,   936,   906,   938,   937,
     949,   953,   950,   407,   959,   954,   957,   958,   962,   968,
     791,   711,   985,  1000,   992,  1001,   993,  1003,  1006,  1002,
     567,  1264,   567,  1265,  1007,  1008,  1010,  1013,  1016,  1269,
    1018,  1033,  1023,  1036,   998,  1038,  1055,  1069,  1075,  1072,
    1076,  1086,  1088,  1277,  1278,  1279,  1280,  1281,  1090,  1282,
    1091,  1105,  1128,  1099,  1107,  1104,  1126,  1138,  1117,  1129,
    1087,  1145,  1130,   511,  1132,  1106,  1141,  1156,  1287,  1148,
    1159,  1096,  1164,  1097,  1152,  1139,  1140,  1172,  1175,  1142,
    1174,  1143,  1176,  1185,  1292,  1180,  1294,  1168,  1183,  1184,
    1188,  1198,  1201,  1194,  1195,  1079,  1162,  1200,  1196,  1215,
    1193,  1212,  1219,   969,  1216,  1238,  1242,  1308,  1355,  1311,
    1233,  1248,  1235,  1243,  1249,  1197,  1258,  1262,  1260,  1291,
    1261,  1270,  1274,  1284,  1301,   994,   903,  1313,  1182,  1325,
    1330,  1319,  1333,  1349,   974,  1357,  1144,  1346,  1348,  1351,
    1360,  1363,  1189,   482,  1368,  1373,   698,   699,   480,  1376,
     982,  1150,   483,   765,   628,  1302,   486,  1353,  1308,   626,
    1332,   976,  1241,   703,  1032,  1089,  1169,  1268,   504,  1179,
    1204,  1214,  1211,  1077,  1352,   487,  1208,   643,   666,  1136,
     718,  1166,   719,   648,   742,  1283,  1187,   861,  1362,  1359,
     948,   659,   981,  1199,  1178,  1202,   967,   915,  1118,  1232,
    1365,   549,  1305,  1125,   916,  1123,  1251,     0,  1230,     0,
       0,  1119,     0,     0,     0,  1190,   660,     0,     0,     0,
       0,     0,     0,   551,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   690,     0,     0,     0,
       0,     0,     0,   694,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   903,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1266,  1267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1272,     0,     0,     0,     0,  1276,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   450,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1293,     0,     0,     0,     0,     0,   903,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   903,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1356,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1364,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     2,     3,  1370,     4,     0,     0,     0,
    1375,     0,     5,     6,     7,     8,     9,    10,    11,    12,
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
     202,   203,   204,   205,   206,   207,   208,   209,     1,     0,
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
       0,   114,   115,   116,     0,     0,     0,   117,   453,   118,
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
       0,     0,   114,   115,   116,     0,   755,     0,   117,     0,
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
     761,   118,   119,   120,     0,   121,   122,   123,     0,   124,
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
     112,   113,     0,     0,   114,   115,   116,     0,   778,     0,
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
       0,   112,   113,     0,     0,   114,   115,   116,     0,   824,
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
     857,     0,   117,     0,   118,   119,   120,     0,   121,   122,
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
       0,  1137,     0,   117,     0,   118,   119,   120,     0,   121,
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
     116,     0,  1161,     0,   117,     0,   118,   119,   120,     0,
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
     115,   116,     0,  1181,     0,   117,     0,   118,   119,   120,
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
       4,     0,     0,     0,     0,     0,   346,   347,   348,     8,
     349,   350,    11,   352,    13,    14,    15,    16,   357,    18,
      19,    20,    21,    22,    23,   358,    25,    26,   360,   361,
      29,   362,    31,    32,    33,     0,   363,   364,    36,   365,
     366,   367,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,     0,    67,    68,     0,     0,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,    80,
       0,    81,    82,    83,    84,     0,    85,     0,     0,     0,
     371,    87,    88,    89,    90,     0,     0,     0,     0,     0,
      91,    92,    93,    94,    95,    96,    97,     0,     0,     0,
      98,    99,   547,   101,   102,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   548,
     113,     0,     0,   114,   115,   116,     0,     0,     0,   117,
       0,   118,   119,   120,     0,   121,   122,   123,     0,   124,
       0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,   136,   137,   138,     0,   376,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   377,   149,
     379,   151,   380,   381,   154,   155,   156,   157,   158,   159,
     382,   161,   383,   163,   384,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,   178,
     179,     0,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   385,   386,   387,   204,   205,   206,   207,
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
       0,    98,    99,   100,   101,   102,     0,     0,     0,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,     0,
     112,   113,     0,     0,   114,   115,   116,     0,     0,     0,
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
       3,     0,     4,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     764,    18,    19,    20,    21,    22,    23,    24,    25,    26,
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
       0,   112,   113,     0,     0,   114,   115,   116,     0,     0,
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
       2,     3,     0,     4,     0,     0,     0,     0,     0,   346,
     347,   348,     8,   349,   350,   351,   352,    13,    14,    15,
      16,   357,    18,    19,    20,    21,    22,    23,   358,    25,
      26,   360,   361,    29,   362,    31,    32,    33,     0,   363,
     364,    36,   365,   366,   367,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     0,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,     0,    67,    68,     0,     0,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,    80,     0,    81,    82,    83,    84,     0,    85,
       0,     0,     0,   371,    87,    88,    89,    90,     0,     0,
       0,     0,     0,    91,    92,    93,    94,    95,    96,    97,
       0,     0,     0,    98,    99,     0,   101,   102,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,   114,   115,   116,     0,
       0,     0,   117,     0,   118,   119,   120,     0,     0,     0,
     123,     0,   124,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,   136,   137,   138,
       0,   376,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   377,   149,   379,   151,   380,   381,   154,   155,   156,
     157,   158,   159,   382,   161,   383,   163,   384,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,   179,     0,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   385,   386,   387,   204,
     205,   206,   207,   208,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     0,     0,     0,     0,     0,     0,
     346,   347,   348,     8,   349,   350,   351,   352,   444,   354,
     445,   446,   357,    18,    19,    20,    21,    22,    23,   358,
     447,    26,   360,   361,    29,   362,    31,    32,    33,     0,
     363,   364,    36,   365,   366,   367,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     0,     0,    57,     0,    58,    59,    60,   448,     0,
       0,    64,    65,    66,     0,     0,     0,    68,     0,     0,
       0,     0,    70,    71,    72,     0,     0,    75,    76,     0,
       0,     0,     0,     0,     0,    81,    82,    83,    84,     0,
      85,     0,     0,     0,   371,    87,    88,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,     0,    95,    96,
      97,     0,     0,     0,     0,     0,     0,   101,   102,     0,
       0,     0,     0,   103,   104,   105,   374,   107,   108,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,   117,     0,   118,   119,     0,     0,     0,
       0,   123,     0,   124,     0,   125,   126,   127,   128,   375,
     130,   131,   132,   133,   134,   135,     0,     0,   136,   137,
       0,     0,   376,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   377,   149,   379,   151,   380,   381,   154,   155,
     156,   157,   158,   159,   382,   161,   383,   163,   384,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,   178,   179,     0,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   385,   386,   387,
     204,   205,   206,   207,   208,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
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
       0,     0,   123,     0,   124,     0,   125,   126,   127,   128,
     375,   130,   131,   132,   133,   134,   135,     0,     0,   136,
     137,     0,     0,   376,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   377,   378,   379,   151,   380,   381,   154,
     155,   156,   157,   158,   159,   382,   161,   383,   163,   384,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,     0,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   385,   386,
     387,   204,   205,   206,   207,   208,   458,     0,     3,     0,
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
     372,     0,     0,   373,     0,     0,   101,   102,     0,     0,
       0,     0,   103,   104,   105,   374,   107,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116,     0,
       0,     0,   117,     0,   118,     0,     0,     0,     0,     0,
       0,     0,   124,     0,   125,   126,   127,   128,   375,   130,
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
      95,    96,    97,   441,     0,     0,   442,     0,     0,   101,
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
      92,    93,     0,    95,    96,    97,     0,     0,     0,     0,
       0,     0,   101,   102,     0,     0,     0,     0,   103,   104,
     105,   374,   107,   108,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,   117,   573,
     118,     0,     0,     0,     0,     0,   574,     0,   124,     0,
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
       0,     0,    91,    92,    93,     0,    95,    96,    97,     0,
       0,     0,     0,     0,     0,   101,   102,     0,     0,     0,
       0,   103,   104,   105,   374,   107,   108,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,     0,     0,
       0,   117,   662,   118,     0,     0,     0,     0,     0,   663,
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
       0,   346,   347,   348,     8,   349,   350,   351,   352,   444,
     354,   445,   446,   357,    18,    19,    20,    21,    22,    23,
     358,   447,    26,   360,   361,    29,   362,    31,    32,    33,
       0,   363,   364,    36,   365,   366,   367,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,     0,     0,    57,     0,    58,    59,    60,   448,
       0,     0,    64,    65,    66,     0,     0,     0,    68,     0,
       0,     0,     0,    70,    71,    72,     0,     0,    75,    76,
    1133,     0,     0,     0,     0,     0,    81,    82,    83,    84,
       0,    85,     0,     0,     0,   371,    87,    88,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,     0,    95,
      96,   897,     0,     0,     0,     0,     0,     0,   101,   102,
       0,     0,     0,     0,   103,   104,   105,   374,   107,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,     0,     0,     0,   117,     0,   118,   119,     0,     0,
       0,     0,     0,     0,   124,     0,   125,   126,   127,   128,
     375,   130,   131,   132,   133,   134,   135,     0,     0,   898,
     137,     0,     0,   376,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   377,   149,   379,   151,   380,   381,   154,
     155,   156,   157,   158,   159,   382,   161,   383,   163,   384,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,     0,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   385,   386,
     387,   204,   205,   206,   207,   208,     3,     0,     0,     0,
       0,     0,     0,     0,   346,   347,   348,     8,   349,   350,
     351,   352,   444,   354,   445,   446,   357,    18,    19,    20,
      21,    22,    23,   358,   447,    26,   360,   361,    29,   362,
      31,    32,    33,     0,   363,   364,    36,   365,   366,   367,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     0,     0,    57,     0,    58,
      59,    60,   448,     0,     0,    64,    65,    66,     0,     0,
       0,    68,     0,     0,     0,     0,    70,    71,    72,     0,
       0,    75,    76,     0,     0,     0,     0,     0,     0,    81,
      82,    83,    84,     0,    85,     0,     0,     0,   371,    87,
      88,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,     0,    95,    96,   897,     0,     0,     0,     0,     0,
       0,   101,   102,     0,     0,     0,     0,   103,   104,   105,
     374,   107,   108,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,     0,     0,     0,   117,     0,   118,
     119,     0,     0,     0,     0,     0,     0,   124,     0,   125,
     126,   127,   128,   375,   130,   131,   132,   133,   134,   135,
       0,     0,   898,   137,     0,     0,   376,   140,     0,   141,
     142,   143,   144,   145,   146,   147,   377,   149,   379,   151,
     380,   381,   154,   155,   156,   157,   158,   159,   382,   161,
     383,   163,   384,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,   178,   179,     0,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   385,   386,   387,   204,   205,   206,   207,   208,     3,
       0,     0,     0,     0,     0,     0,     0,   346,   347,   348,
       8,   349,   350,   351,   352,   444,   354,   445,   446,   357,
      18,    19,    20,    21,    22,    23,   358,   447,    26,   360,
     361,    29,   362,    31,    32,    33,     0,   363,   364,    36,
     365,   366,   367,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     0,     0,
      57,     0,    58,    59,    60,   448,     0,     0,    64,    65,
      66,     0,     0,     0,    68,     0,     0,     0,     0,    70,
      71,    72,     0,     0,    75,    76,     0,     0,     0,     0,
       0,     0,    81,    82,    83,    84,     0,    85,     0,     0,
       0,   371,    87,    88,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,     0,    95,    96,   897,     0,     0,
       0,     0,     0,     0,   101,   102,     0,     0,     0,     0,
     103,   104,   105,   374,   107,   108,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,     0,     0,
     117,     0,   118,   119,     0,     0,     0,     0,     0,     0,
     124,     0,   125,   126,   127,   128,   375,   130,   131,   132,
     133,   134,   135,     0,     0,   136,   137,     0,     0,   376,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   377,
     149,   379,   151,   380,   381,   154,   155,   156,   157,   158,
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
      97,     0,     0,     0,     0,     0,     0,   101,   102,     0,
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
     204,   205,   206,   207,   208
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        13,   403,   669,   711,   809,   831,   337,   489,   531,   340,
     864,   413,    63,    98,   535,   536,   537,   538,   122,   643,
     751,   752,   938,   648,   648,   427,   428,   767,   511,   926,
      80,   733,    20,    81,    21,   409,    83,    66,    20,    94,
      18,    87,    20,   751,   752,    83,   115,    47,    61,     7,
      63,   425,    20,    81,    81,    83,   430,    94,   514,  1051,
     516,   517,   127,   519,    77,   521,    83,    39,    40,    41,
      42,    43,    44,   529,   530,   477,   478,   479,    34,   127,
      52,   789,    94,   105,     8,     9,    99,    94,    94,   150,
     715,    20,   717,   131,    39,    40,    41,    42,    43,    44,
     113,    81,   433,   131,   165,   121,   119,    52,    18,    97,
     137,   180,    83,    58,   114,    71,   166,    94,     8,   137,
     131,   109,    59,   140,    69,    70,    98,    99,    73,    19,
     131,    76,   100,  1083,  1084,   466,   467,   174,   469,   470,
     471,   472,     8,     9,   475,   133,   116,   169,    81,   137,
      38,   131,   140,    98,    99,   100,   100,    94,   122,   490,
      48,   221,   174,   170,   219,   171,    90,    81,   184,   500,
     501,   795,   201,   137,    94,   221,   144,   281,   205,   206,
       8,     9,  1008,   229,   108,   250,   110,  1041,   170,   236,
     237,   996,   170,   860,   171,  1187,   242,  1051,   244,   144,
     158,   248,   250,   605,   174,   234,   729,   730,   254,   105,
     197,   257,   250,   137,   170,   144,   841,   141,   108,   843,
     110,   774,   250,   776,    90,  1122,   928,   137,   959,   119,
     140,   562,     8,   157,   717,   286,   976,   639,   289,   250,
    1156,   254,   108,    19,   110,     8,     9,   137,    93,   250,
     170,   959,   240,   140,   178,    94,   228,   342,  1208,   204,
     345,   635,    90,    29,   638,   236,   237,   112,   724,   202,
     203,   137,   196,   286,   170,   141,   289,    94,    94,   115,
     108,    94,   110,   228,   217,   229,   911,   372,   202,   203,
      20,   157,   165,    34,   266,   267,   268,   269,    39,   216,
     853,   218,   855,   217,   389,   390,   179,   392,    94,   137,
      94,    29,   178,   141,   258,   259,    94,   261,   262,    94,
      81,   266,   267,   268,   269,   104,    94,    90,   341,   157,
     196,   170,   108,  1187,   110,   129,   201,   422,     4,   424,
     140,    94,     8,   119,   180,   108,    94,   110,    50,    94,
     178,   130,    93,   170,   170,    57,   441,   170,    60,    61,
     373,   137,    62,    63,   143,   159,    68,    97,   196,   234,
     131,   456,   142,    83,   137,   706,     4,   462,   141,   109,
       8,   394,   713,   177,   170,  1301,   170,   400,   152,   159,
     100,   142,   170,  1322,   157,   170,   798,   799,   177,    81,
     802,   924,   170,   133,   886,   105,   927,   137,   159,   137,
     140,   184,   153,   936,  1145,   178,   429,   170,   431,   432,
     193,   185,   170,   137,   132,   170,   439,    64,    65,   442,
     140,   182,   160,   196,   836,   121,  1262,  1145,  1367,   452,
     122,   149,   108,  1372,   110,   127,    83,  1376,   134,   553,
     554,   153,   118,   155,   165,   132,    64,    65,    83,    67,
     791,   474,    87,   476,    83,   550,   797,   169,   179,   209,
     555,   137,   149,   246,   214,    83,  1314,  1315,   563,   252,
     108,   100,   110,   229,   569,   570,   184,   260,   819,   122,
     118,   576,   288,   195,   127,   193,    82,   105,   294,  1337,
      83,   140,   833,   834,    87,  1343,   837,    93,   839,   137,
     395,  1242,   258,   259,   399,   261,   262,   103,  1185,   246,
    1144,   105,  1327,  1190,    87,   252,   112,   152,   859,   144,
     225,   226,   137,   260,  1242,   140,   209,   100,   211,   870,
     871,   872,    60,   874,   875,   876,   877,   878,   879,   634,
     881,   882,   247,   182,   246,   184,   209,   888,   211,   251,
    1291,    39,    40,    41,   193,   556,    44,   122,   559,   152,
     561,   584,   127,   267,   268,   269,   907,  1246,   909,   910,
     665,   137,  1251,  1291,   140,   105,  1107,    51,   601,   227,
      54,   105,   230,  1114,  1115,   227,   221,   137,   230,   140,
     216,  1003,   218,  1126,   229,  1272,   231,   232,   233,  1276,
     205,   206,   207,   175,   176,   140,   241,   242,   105,   244,
     951,   113,   114,    14,   249,    64,    65,   113,   114,   254,
     255,   256,   257,   532,   533,   397,   398,   137,   221,   652,
     137,   539,   540,   728,   541,   542,   229,   199,   231,   232,
     233,  1318,   753,   754,   985,   668,  1244,  1245,   140,   242,
     209,   244,   105,   137,   105,   267,   249,   267,   267,  1000,
       0,   254,   255,   256,   257,   174,   174,  1079,   151,    79,
     239,    74,  1013,   768,  1308,    88,   138,  1018,  1019,   183,
    1021,    89,   705,   140,   170,  1026,    39,   137,   711,   137,
     137,  1222,  1223,   170,    39,    20,   136,    18,   117,   105,
     267,   137,   256,   256,   137,   105,   125,   126,   105,   128,
     140,   140,   140,   140,   140,   170,   135,    25,    15,   197,
     139,    20,   141,    38,   170,   170,   215,   146,   751,   752,
     753,   754,   153,   105,  1075,    94,   154,   154,    81,   215,
      81,   137,    81,   162,   167,  1086,   170,   167,   170,   140,
      20,   774,  1164,   776,   144,   167,   167,    94,  1099,  1290,
     167,  1102,    94,  1104,   144,   112,   789,   186,   187,   188,
     189,   190,   191,   117,    20,   270,   170,   170,   167,    83,
      34,    83,   170,   117,    94,   127,   167,   170,   170,   167,
     167,   170,   167,    81,   209,   131,   221,   127,   167,   154,
    1212,   174,   105,   257,   105,   105,   238,   105,   245,   240,
     167,   174,   168,    99,    87,   167,   167,   167,   137,   167,
     127,    81,   127,   181,   259,   137,   260,   117,   144,   167,
     853,  1172,   855,  1174,   117,    83,   105,   131,   105,  1180,
     127,   137,   234,   167,   260,    25,    20,   105,   137,   223,
     105,    94,    94,  1194,  1195,  1196,  1197,  1198,   140,  1200,
     140,   167,   260,   131,   235,   131,   131,   962,   235,    53,
     893,    81,   129,   896,   167,   170,   129,    20,  1219,   974,
     154,   904,    94,   906,   260,   170,   170,   127,   105,   170,
     131,   170,   105,   117,  1235,    67,  1237,   174,   170,   170,
       6,   221,   140,   217,   217,    93,  1001,   169,   217,   170,
     174,    93,   131,   105,   170,   167,    81,  1258,  1330,  1260,
     253,    20,   169,   167,    20,   217,   140,    83,   111,    81,
     167,   167,   167,   167,    20,    83,   959,    65,  1033,   169,
      93,   180,   105,   105,   137,    80,   969,   180,   180,   169,
     166,   180,  1047,   212,   105,   105,   488,   488,   209,   170,
     790,   981,   212,   563,   416,   243,   215,   243,  1309,   412,
    1309,   785,  1146,   492,   848,   896,  1016,  1178,   253,  1028,
    1076,  1088,  1086,   888,  1325,   216,  1083,  1010,   452,   960,
     512,  1010,   513,  1016,   534,  1201,  1041,   669,  1343,  1337,
     754,   440,   789,  1069,  1027,  1073,   776,   729,   924,  1126,
    1351,   274,  1256,   936,   730,   928,  1155,    -1,  1121,    -1,
      -1,   925,    -1,    -1,    -1,  1048,   440,    -1,    -1,    -1,
      -1,    -1,    -1,   278,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1069,    -1,    -1,    -1,
      -1,    -1,    -1,  1076,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1175,  1176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1186,    -1,    -1,    -1,    -1,  1191,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1236,    -1,    -1,    -1,    -1,    -1,  1242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1291,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1349,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,  1368,    20,    -1,    -1,    -1,
    1373,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
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
     264,   265,   266,   267,   268,   269,   270,   271,    10,    -1,
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
      -1,   163,   164,   165,    -1,    -1,    -1,   169,   170,   171,
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
     160,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,   169,
     170,   171,   172,   173,    -1,   175,   176,   177,    -1,   179,
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
      -1,    -1,    -1,   140,   141,    -1,   143,   144,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,    -1,
      -1,    -1,   169,    -1,   171,   172,   173,    -1,    -1,    -1,
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
      -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   177,    -1,   179,    -1,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,   194,   195,
      -1,    -1,   198,   199,    -1,   201,   202,   203,   204,   205,
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
     165,    -1,    -1,    -1,   169,    -1,   171,    -1,    -1,    -1,
      -1,    -1,   177,    -1,   179,    -1,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,   194,
     195,    -1,    -1,   198,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,    -1,   239,   240,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    16,    -1,    18,    -1,
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
     267,   268,   269,   270,    18,    -1,    -1,    -1,    -1,    -1,
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
     134,   135,   136,   137,    -1,    -1,   140,    -1,    -1,   143,
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
      -1,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,   177,
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
     105,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
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
      -1,    -1,    -1,   165,    -1,    -1,    -1,   169,    -1,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,   181,
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
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,
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
     266,   267,   268,   269,   270
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
     307,   308,   309,   310,   313,   314,   319,   321,   328,   330,
     333,   334,   335,   336,   337,   338,   346,   347,   349,   350,
     351,   356,   358,   360,   361,   362,   367,   388,   391,   394,
     395,   396,   397,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   444,   445,   446,   460,   461,   463,   464,
     465,   466,   467,   468,   469,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   488,   489,   490,   491,   492,
     493,   494,   497,   502,   503,   137,   331,   221,    29,    29,
     140,    81,   137,   205,   206,   140,    26,    27,    28,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    45,    46,
      48,    49,    51,    56,    57,    59,    60,    61,    71,    72,
      84,   120,   137,   140,   152,   185,   198,   208,   209,   210,
     212,   213,   220,   222,   224,   263,   264,   265,   502,   137,
     137,   140,   137,   140,    39,    40,    41,    42,    43,    44,
      52,    58,    69,    70,    73,    76,    98,    99,   100,   144,
     204,   228,   266,   267,   268,   269,   320,   322,   323,   324,
     339,   340,   140,    18,   137,   140,   501,    51,    54,   105,
     144,   105,   105,   137,    62,    63,   105,   353,    60,   140,
     140,   137,   140,   502,    34,    36,    37,    46,    84,   428,
     502,   502,   105,   170,   347,   502,   137,    14,    16,   502,
     502,   420,   137,    21,   197,   199,   209,   211,   140,   209,
     211,   209,   209,   214,   105,   137,   105,   267,   267,   267,
     288,     0,   290,   291,    38,    48,   293,   346,   174,   174,
      94,   174,   348,    50,    57,    60,    61,    68,   153,   155,
     169,   195,   352,   357,   358,   359,   376,   377,   381,   363,
     364,   502,   151,    79,   117,   125,   126,   128,   135,   139,
     141,   146,   162,   186,   187,   188,   189,   190,   191,   412,
     413,   239,   142,   159,   182,   104,   130,   143,   177,   184,
     193,   121,   134,    74,   183,    88,    89,   142,   159,   411,
     137,   417,   420,   175,   176,   138,   432,   433,   428,   432,
     428,   432,   140,   332,   350,   350,   486,   502,   347,   137,
     137,   347,   347,   170,   177,   502,   137,   347,   347,   170,
     347,   170,   502,   340,    39,   341,   339,   339,   340,   502,
     165,   179,   152,   185,    20,   500,   150,   165,   165,   179,
     136,   105,   318,    34,    39,    93,   153,   501,   205,   206,
     207,    87,   221,   229,   242,   244,   254,   257,   515,   516,
     517,   518,   519,   522,   527,   528,   323,   500,   324,   347,
     347,    20,   170,   501,   137,   144,   500,   100,   144,   312,
     500,   389,   390,   502,   501,   502,   368,   370,   502,   350,
     256,   256,   105,   371,   105,   502,    34,    71,   170,   484,
     485,   347,   170,   177,   502,   137,   389,   170,    25,   448,
     449,   450,   347,     7,   158,    15,   170,   347,   197,    20,
     350,   350,   170,   350,   350,   350,   350,   215,   495,   496,
     502,   350,   369,   375,   502,   500,   500,   500,   295,   296,
      38,   297,   350,   349,   153,   105,   154,   154,   350,   350,
      94,    81,    83,   131,   250,   365,   366,   471,   396,   397,
     399,   399,   399,   399,   398,   399,   399,   399,   137,   140,
     240,   435,   504,   506,   507,   508,   509,   510,   511,   512,
     402,   402,   401,   403,   403,   403,   403,   404,   404,   405,
     405,   215,    81,    81,    81,   167,   347,   420,   420,   347,
     433,   170,   350,   443,    38,   319,   347,   170,   137,   167,
     347,   347,   170,   167,    94,   170,    94,   170,   167,   347,
     167,   167,   167,   140,   329,   502,    20,    94,    94,    81,
     122,   127,   315,   316,   317,   502,   122,   127,   144,   144,
     500,   112,   117,   227,   230,   100,   229,   258,   259,   261,
     262,   227,   230,    20,   229,   258,   259,   261,   262,   270,
     170,   167,   170,   170,   167,   347,   501,    83,    34,   501,
     500,    83,    94,   171,   131,   471,   117,   127,    94,   127,
     366,   471,   167,   502,    66,   201,   234,   354,   355,   170,
     170,   170,   167,    94,   170,    94,   170,   167,   347,   171,
     502,   449,   450,   115,   180,   167,   167,   116,   174,    81,
     202,   203,   217,    81,   202,   203,   217,    81,   221,   209,
      94,   219,   127,   167,    59,    94,   174,   174,   154,   502,
     350,   382,   383,   105,   378,   379,   105,   136,   194,   472,
     474,   475,   476,   502,   105,   350,   105,   131,   366,   131,
     131,   365,   366,   399,   347,   504,   510,   257,   538,    83,
     152,   231,   232,   233,   241,   249,   255,   256,   505,   513,
     514,   515,   529,   532,   533,   535,   238,   240,   245,   534,
     225,   226,   247,   530,   472,   472,   470,   475,   470,   167,
     168,    94,   170,   174,   167,   331,   347,   167,   167,    87,
     392,   393,   137,   486,   487,   502,   486,   487,   167,   105,
     170,   342,   343,   122,   137,   345,   329,   132,   149,   132,
     149,   474,   317,   350,   471,   127,   350,   500,   500,   113,
     114,   500,   259,   260,    83,   100,   140,   521,   260,   350,
     181,   137,   167,   117,   311,   500,   144,   117,    83,   311,
     105,   350,   350,   131,   500,   350,   105,   350,   127,   127,
     366,   131,   471,   234,    64,    65,    67,   105,   365,   372,
     373,   374,   355,   137,   486,   486,   167,   350,    25,   450,
     115,   180,     8,     9,    90,   108,   110,   137,   178,   344,
     445,   447,   458,   459,   462,    20,   216,   218,   350,   350,
     350,   216,   218,   350,   350,   350,   350,   350,   350,   105,
     350,   350,   223,   498,   499,   137,   105,   382,    82,    93,
     103,   112,   384,   385,   386,   387,    94,   502,    94,   364,
     140,   140,   129,   159,   177,   473,   502,   502,   350,   131,
     350,   350,   131,   366,   131,   167,   170,   235,   201,   234,
     246,   251,   537,    83,   236,   237,   531,   235,   507,   537,
     400,   403,   255,   513,   515,   508,   131,   531,   260,    53,
     129,   350,   167,   105,   472,   100,   393,   167,   347,   170,
     170,   129,   170,   170,   502,    81,    94,   170,   347,   331,
     316,   350,   260,    83,   140,   524,    20,   100,   521,   154,
     350,   167,   347,   500,    94,   311,   390,   350,   174,   370,
     350,   350,   127,   350,   131,   105,   105,   350,   502,   374,
      67,   167,   347,   170,   170,   117,   178,   447,     6,   347,
     502,   178,   458,   174,   217,   217,   217,   217,   221,   496,
     169,   140,   499,   350,   375,   500,   113,   114,   386,   387,
     387,   383,    93,   380,   379,   170,   170,   350,   350,   131,
     350,   403,    47,   114,   403,   403,   246,   252,   260,   536,
     536,   400,   509,   253,   502,   169,   105,   169,   167,   471,
     472,   343,    81,   167,   121,   184,   523,   526,    20,    20,
     525,   523,   248,   531,    94,   170,    94,   170,   140,   327,
     111,   167,    83,   500,   350,   350,   502,   502,   373,   350,
     167,   450,   502,   178,   167,   450,   502,   350,   350,   350,
     350,   350,   350,   429,   167,   387,   500,   350,   403,   403,
     182,    81,   350,   502,   350,   472,   524,   524,   526,    20,
     170,    20,   243,   520,   521,   520,   325,   326,   350,    94,
     170,   350,   311,    65,    80,   166,   451,   450,   502,   180,
     450,    94,   170,   403,   472,   169,   531,    94,   170,   170,
      93,   471,   325,   105,     4,   118,   454,   455,   457,   459,
      19,   119,   452,   453,   456,   459,   180,   450,   180,   105,
     345,   169,   350,   243,   521,   500,   502,    80,   118,   457,
     166,   119,   456,   180,   502,   350,    94,   170,   105,   345,
     502,    94,   170,   105,   345,   502,   170,   345
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
     325,   325,   326,   326,   327,   327,   328,   328,   329,   329,
     329,   329,   330,   331,   332,   332,   333,   334,   335,   336,
     336,   337,   337,   337,   338,   338,   338,   339,   339,   339,
     339,   340,   340,   341,   342,   342,   343,   343,   344,   345,
     346,   347,   347,   348,   348,   349,   349,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   351,   352,   353,   353,   354,
     354,   354,   355,   355,   356,   356,   357,   358,   358,   358,
     359,   359,   359,   359,   359,   360,   360,   361,   361,   362,
     363,   363,   364,   364,   364,   364,   364,   364,   364,   364,
     365,   366,   367,   368,   368,   369,   369,   370,   370,   370,
     370,   371,   371,   372,   372,   372,   373,   373,   373,   374,
     374,   374,   375,   376,   377,   378,   378,   379,   379,   380,
     381,   381,   382,   382,   383,   383,   384,   384,   384,   384,
     384,   384,   384,   385,   385,   386,   386,   387,   388,   388,
     389,   389,   390,   390,   391,   391,   392,   392,   393,   393,
     394,   395,   395,   396,   396,   397,   397,   397,   397,   397,
     398,   397,   397,   397,   397,   399,   399,   399,   400,   400,
     401,   401,   401,   402,   402,   402,   402,   402,   403,   403,
     403,   404,   404,   404,   405,   405,   406,   406,   407,   407,
     408,   408,   409,   409,   410,   410,   410,   410,   411,   411,
     411,   412,   412,   412,   412,   412,   412,   413,   413,   413,
     414,   414,   414,   414,   415,   415,   416,   416,   417,   417,
     418,   418,   418,   418,   419,   420,   420,   420,   421,   421,
     422,   422,   422,   422,   423,   423,   424,   424,   424,   424,
     424,   424,   424,   425,   425,   426,   426,   427,   427,   427,
     427,   427,   428,   428,   429,   429,   430,   430,   430,   431,
     431,   432,   432,   433,   434,   434,   434,   434,   434,   434,
     434,   434,   435,   435,   436,   436,   436,   437,   438,   438,
     439,   440,   441,   442,   442,   443,   443,   444,   444,   445,
     445,   445,   446,   446,   446,   446,   446,   446,   447,   447,
     448,   448,   449,   450,   450,   451,   451,   452,   452,   453,
     453,   453,   453,   454,   454,   455,   455,   455,   455,   456,
     456,   457,   457,   458,   458,   458,   458,   459,   459,   459,
     459,   460,   460,   461,   461,   462,   463,   463,   463,   463,
     463,   463,   464,   465,   465,   465,   465,   466,   466,   466,
     466,   467,   468,   469,   469,   469,   469,   470,   470,   471,
     472,   472,   472,   473,   473,   473,   474,   474,   474,   475,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   477,
     478,   478,   478,   479,   480,   481,   481,   481,   482,   482,
     482,   482,   482,   483,   484,   484,   484,   484,   484,   484,
     484,   485,   486,   487,   488,   489,   489,   489,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   491,   491,
     492,   492,   493,   494,   495,   495,   496,   497,   498,   498,
     499,   499,   499,   499,   500,   501,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   503,   503,   504,   504,   504,   504,   505,   505,   505,
     505,   506,   506,   507,   507,   508,   508,   509,   509,   510,
     510,   510,   511,   511,   512,   512,   513,   513,   513,   513,
     513,   514,   515,   515,   515,   515,   515,   515,   515,   516,
     516,   516,   516,   517,   517,   517,   517,   518,   518,   519,
     519,   519,   519,   519,   519,   519,   520,   520,   521,   521,
     521,   521,   522,   522,   522,   522,   522,   523,   523,   524,
     524,   525,   525,   526,   526,   527,   528,   528,   529,   529,
     529,   530,   530,   530,   530,   530,   531,   531,   531,   531,
     532,   533,   534,   535,   535,   536,   536,   536,   537,   537,
     538
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
       4,     6,     1,     1,     2,     1,     2,     1,     2,     7,
       1,     3,     1,     2,     2,     3,     3,     3,     2,     3,
       4,     5,     2,     4,     3,     0,     5,     3,     5,     2,
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
       1,     7,     4,     1,     2,     3,     4,     1,     1,     2,
       2,     1,     3,     1,     3,     1,     4,     1,     2,     1,
       2,     3,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     5,     7,     5,     7,     2,     1,     3,     2,     4,
       4,     6,     4,     5,     4,     5,     3,     1,     2,     2,
       3,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     2,     1,     2,     1,     2,     3,     3,     4,
       3,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       3
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
  "IndexDecl", "IndexDecl2", "IndexDecl3", "IndexDeclSuffix", "IndexField",
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
     293,   346,    -1,   346,    -1,   292,   293,    -1,    51,   144,
     501,   117,   500,   174,    -1,   294,   174,    -1,   295,   174,
      -1,   294,   174,   295,   174,    -1,   296,    -1,   294,   174,
     296,    -1,   297,    -1,   295,   174,   297,    -1,   298,    -1,
     299,    -1,   300,    -1,   302,    -1,   319,    -1,   314,    -1,
     338,    -1,   303,    -1,   304,    -1,   321,    -1,   301,    -1,
     308,    -1,   309,    -1,   328,    -1,   305,    -1,   306,    -1,
     307,    -1,   489,    -1,   310,    -1,   313,    -1,    38,   144,
     501,   117,   500,    -1,    38,    76,   165,    -1,    38,    76,
     179,    -1,    38,   100,    34,   144,   500,    -1,    38,   100,
      39,   144,   500,    -1,    38,    52,   502,    20,    -1,    38,
     228,   515,    -1,    38,    69,   152,    -1,    38,    69,   185,
      -1,    38,   100,   153,   112,   113,    -1,    38,   100,   153,
     112,   114,    -1,    38,    73,   165,    94,   132,    -1,    38,
      73,   165,    94,   149,    -1,    38,    73,   150,    94,   132,
      -1,    38,    73,   150,    94,   149,    -1,    38,   100,    93,
     500,    -1,    38,    70,   500,    -1,    48,    54,   500,    -1,
      48,    54,   312,   500,    -1,    48,    54,   500,    83,   311,
      -1,    48,    54,   312,   500,    83,   311,    -1,   500,    -1,
     311,    94,   500,    -1,   144,   501,   117,    -1,   100,    34,
     144,    -1,    48,    51,   500,    -1,    48,    51,   144,   501,
     117,   500,    -1,    48,    51,   500,    83,   311,    -1,    48,
      51,   144,   501,   117,   500,    83,   311,    -1,    38,    98,
     136,   315,    -1,    81,   474,   316,    -1,   316,    -1,   317,
      -1,   122,    -1,   122,   317,    -1,   127,   350,    -1,   105,
     502,    -1,   105,   502,   471,    -1,    38,    99,   318,   127,
     350,    -1,    38,    99,   318,   122,    -1,    38,    99,   318,
     122,   127,   350,    -1,   268,    -1,   269,    -1,    38,   322,
      -1,   323,    -1,   266,   323,    -1,   324,    -1,   320,   324,
      -1,   267,   500,   270,   350,   154,   327,   170,    -1,   326,
      -1,   326,    93,   500,    -1,   350,    -1,   350,   471,    -1,
     140,   325,    -1,   327,    94,   325,    -1,    38,    58,   165,
      -1,    38,    58,   179,    -1,   140,   170,    -1,   140,   342,
     170,    -1,   140,   170,    81,   472,    -1,   140,   342,   170,
      81,   472,    -1,    26,   331,    -1,   137,   332,   347,   167,
      -1,   332,   319,   174,    -1,    -1,    56,   105,   502,   127,
     350,    -1,    27,   221,   350,    -1,    31,   140,   350,   170,
     331,    -1,    28,    29,    -1,    30,    29,    -1,   263,   267,
     500,    -1,   265,   267,   500,    -1,   264,   267,   500,    -1,
      38,   339,    -1,    38,    43,   339,    -1,    38,    42,   339,
      -1,   340,    -1,    44,   340,    -1,    40,   340,    -1,    41,
     341,    -1,    39,   502,   329,   345,    -1,    39,   502,   329,
     122,    -1,    39,   502,   329,   331,    -1,   343,    -1,   342,
      94,   343,    -1,   105,   502,    -1,   105,   502,   471,    -1,
     137,   347,   167,    -1,   137,   347,   167,    -1,   347,    -1,
     349,    -1,   349,   348,    -1,   174,    -1,   348,   349,   174,
      -1,   350,    -1,   349,    94,   350,    -1,   351,    -1,   388,
      -1,   391,    -1,   394,    -1,   395,    -1,   490,    -1,   491,
      -1,   493,    -1,   492,    -1,   494,    -1,   497,    -1,   503,
      -1,   334,    -1,   335,    -1,   336,    -1,   333,    -1,   330,
      -1,   337,    -1,   360,   352,    -1,   169,   350,    -1,    62,
     256,    -1,    63,   256,    -1,   201,    -1,   234,    -1,    66,
     234,    -1,   354,   372,    67,   350,    -1,   354,    67,   350,
      -1,    60,   353,   371,   355,   355,    -1,    60,   353,   371,
     355,    -1,    68,   105,   502,    -1,   362,    -1,   367,    -1,
     356,    -1,   358,    -1,   376,    -1,   381,    -1,   377,    -1,
     357,    -1,   358,    -1,   360,   359,    -1,    60,   105,    -1,
      61,    60,   105,    -1,   361,   363,    -1,   364,    -1,   363,
      94,   105,   364,    -1,   502,   131,   350,    -1,   502,   471,
     131,   350,    -1,   502,   365,   131,   350,    -1,   502,   471,
     365,   131,   350,    -1,   502,   366,   131,   350,    -1,   502,
     471,   366,   131,   350,    -1,   502,   365,   366,   131,   350,
      -1,   502,   471,   365,   366,   131,   350,    -1,    83,   105,
     502,    -1,   250,   105,   502,    -1,    57,   105,   368,    -1,
     370,    -1,   368,    94,   105,   370,    -1,   375,    -1,   369,
      94,   105,   375,    -1,   502,   127,   350,    -1,   502,   471,
     127,   350,    -1,   502,   366,   127,   350,    -1,   502,   471,
     366,   127,   350,    -1,   105,   502,   131,   350,    -1,   105,
     502,   471,   131,   350,    -1,   373,    -1,   105,   502,    -1,
     105,   502,   373,    -1,   365,    -1,   365,   374,    -1,   374,
      -1,    64,   105,   502,    65,   105,   502,    -1,    65,   105,
     502,    -1,    64,   105,   502,    -1,   502,    -1,   195,   350,
      -1,   155,   154,   378,    -1,   379,    -1,   378,    94,   379,
      -1,   105,   502,    -1,   105,   502,   380,    -1,    93,   500,
      -1,   153,   154,   382,    -1,    50,   153,   154,   382,    -1,
     383,    -1,   382,    94,   383,    -1,   350,    -1,   350,   384,
      -1,   385,    -1,   386,    -1,   387,    -1,   385,   386,    -1,
     385,   387,    -1,   386,   387,    -1,   385,   386,   387,    -1,
      82,    -1,   103,    -1,   112,   113,    -1,   112,   114,    -1,
      93,   500,    -1,    49,   105,   389,   171,   350,    -1,   120,
     105,   389,   171,   350,    -1,   390,    -1,   389,    94,   105,
     390,    -1,   502,   131,   350,    -1,   502,   471,   131,   350,
      -1,    33,   140,   347,   170,   392,   100,   169,   350,    -1,
      33,   140,   347,   170,   392,   100,   105,   502,   169,   350,
      -1,   393,    -1,   392,   393,    -1,    87,   472,   169,   350,
      -1,    87,   105,   502,    81,   472,   169,   350,    -1,    45,
     140,   347,   170,   181,   350,   111,   350,    -1,   396,    -1,
     395,   151,   396,    -1,   397,    -1,   396,    79,   397,    -1,
     399,    -1,   399,   412,   399,    -1,   399,   413,   399,    -1,
     399,   117,   399,    -1,   399,   146,   399,    -1,    -1,   399,
     141,   398,   399,    -1,   399,   139,   399,    -1,   399,   128,
     399,    -1,   399,   126,   399,    -1,   400,    -1,   400,   239,
     504,    -1,   400,   239,   504,   538,    -1,   401,    -1,   401,
     182,   401,    -1,   402,    -1,   401,   159,   402,    -1,   401,
     142,   402,    -1,   403,    -1,   402,   177,   403,    -1,   402,
     104,   403,    -1,   402,   130,   403,    -1,   402,   143,   403,
      -1,   404,    -1,   403,   184,   404,    -1,   403,   193,   404,
      -1,   405,    -1,   404,   134,   405,    -1,   404,   121,   405,
      -1,   406,    -1,   406,    74,   215,   472,    -1,   407,    -1,
     407,   183,    81,   472,    -1,   408,    -1,   408,    88,    81,
     470,    -1,   409,    -1,   409,    89,    81,   470,    -1,   411,
      -1,   410,   411,    -1,   159,    -1,   142,    -1,   410,   159,
      -1,   410,   142,    -1,   414,    -1,   418,    -1,   415,    -1,
     186,    -1,   191,    -1,   190,    -1,   189,    -1,   188,    -1,
     187,    -1,   135,    -1,   162,    -1,   125,    -1,    32,   137,
     347,   167,    -1,    32,   206,   137,   347,   167,    -1,    32,
     205,   137,   347,   167,    -1,    32,    81,   486,   137,   347,
     167,    -1,   416,   137,   167,    -1,   416,   137,   347,   167,
      -1,   417,    -1,   416,   417,    -1,   160,   502,    15,    -1,
     160,    16,    -1,   419,    -1,   419,   420,    -1,   176,   420,
      -1,   420,    -1,   175,    -1,   421,    -1,   421,   175,   420,
      -1,   421,   176,   420,    -1,   422,    -1,   431,    -1,   423,
      -1,   423,   432,    -1,   426,    -1,   426,   432,    -1,   424,
     428,    -1,   425,    -1,    92,    -1,   101,    -1,    85,    -1,
     173,    -1,   102,    -1,   124,    -1,   123,    -1,   428,    -1,
      86,   428,    -1,   427,   428,    -1,   107,    -1,   156,    -1,
      77,    -1,   164,    -1,   163,    -1,    78,    -1,   476,    -1,
     429,    -1,   502,    -1,   430,    -1,   177,    -1,    10,    -1,
      17,    -1,   434,    -1,   434,   432,    -1,   433,    -1,   432,
     433,    -1,   138,   347,   168,    -1,   435,    -1,   437,    -1,
     438,    -1,   439,    -1,   442,    -1,   444,    -1,   440,    -1,
     441,    -1,   436,    -1,   488,    -1,    97,    -1,   133,    -1,
     109,    -1,   105,   502,    -1,   140,   170,    -1,   140,   347,
     170,    -1,   106,    -1,   152,   137,   347,   167,    -1,   185,
     137,   347,   167,    -1,   502,   140,   170,    -1,   502,   140,
     443,   170,    -1,   350,    -1,   443,    94,   350,    -1,   445,
      -1,   463,    -1,   446,    -1,   460,    -1,   461,    -1,   141,
     502,   450,   115,    -1,   141,   502,   448,   450,   115,    -1,
     141,   502,   450,   180,   178,   502,   450,   180,    -1,   141,
     502,   450,   180,   447,   178,   502,   450,   180,    -1,   141,
     502,   448,   450,   180,   178,   502,   450,   180,    -1,   141,
     502,   448,   450,   180,   447,   178,   502,   450,   180,    -1,
     458,    -1,   447,   458,    -1,   449,    -1,   448,   449,    -1,
      25,   502,   450,   117,   450,   451,    -1,    -1,    25,    -1,
     166,   452,   166,    -1,    80,   454,    80,    -1,    -1,   453,
      -1,   119,    -1,   456,    -1,   453,   119,    -1,   453,   456,
      -1,    -1,   455,    -1,   118,    -1,   457,    -1,   455,   118,
      -1,   455,   457,    -1,    19,    -1,   459,    -1,     4,    -1,
     459,    -1,   445,    -1,     9,    -1,   462,    -1,   459,    -1,
       8,    -1,   108,    -1,   110,    -1,   344,    -1,   196,    21,
     197,    -1,   196,   197,    -1,   157,    14,   158,    -1,   157,
      14,     7,    -1,    90,     6,    -1,   464,    -1,   465,    -1,
     466,    -1,   467,    -1,   468,    -1,   469,    -1,    35,   137,
     347,   167,    -1,    34,   502,   137,   167,    -1,    34,   502,
     137,   347,   167,    -1,    34,   137,   347,   167,   137,   167,
      -1,    34,   137,   347,   167,   137,   347,   167,    -1,    84,
     502,   137,   167,    -1,    84,   502,   137,   347,   167,    -1,
      84,   137,   347,   167,   137,   167,    -1,    84,   137,   347,
     167,   137,   347,   167,    -1,    36,   137,   347,   167,    -1,
      37,   137,   347,   167,    -1,    46,   501,   137,   167,    -1,
      46,   501,   137,   347,   167,    -1,    46,   137,   347,   167,
     137,   167,    -1,    46,   137,   347,   167,   137,   347,   167,
      -1,   475,    -1,   475,   129,    -1,    81,   472,    -1,   474,
      -1,   474,   473,    -1,   194,   140,   170,    -1,   129,    -1,
     177,    -1,   159,    -1,   475,    -1,   476,    -1,   136,   140,
     170,    -1,   502,    -1,   478,    -1,   484,    -1,   482,    -1,
     485,    -1,   483,    -1,   481,    -1,   480,    -1,   479,    -1,
     477,    -1,   209,   140,   170,    -1,    72,   140,   170,    -1,
      72,   140,   484,   170,    -1,    72,   140,   485,   170,    -1,
      36,   140,   170,    -1,    37,   140,   170,    -1,    46,   140,
     170,    -1,    46,   140,   501,   170,    -1,    46,   140,    20,
     170,    -1,    84,   140,   170,    -1,    84,   140,   502,   170,
      -1,    84,   140,   502,    94,   486,   170,    -1,    84,   140,
     177,   170,    -1,    84,   140,   177,    94,   486,   170,    -1,
     172,   502,   170,    -1,    34,   140,   170,    -1,    34,   140,
     502,   170,    -1,    34,   140,   502,    94,   486,   170,    -1,
      34,   140,   502,    94,   487,   170,    -1,    34,   140,   177,
     170,    -1,    34,   140,   177,    94,   486,   170,    -1,    34,
     140,   177,    94,   487,   170,    -1,    71,   140,   502,   170,
      -1,   502,    -1,   502,   129,    -1,    20,    -1,    38,   204,
     205,    -1,    38,   204,   206,    -1,    38,   204,   207,    -1,
     210,   209,   350,   217,   350,    -1,   210,   209,   350,    81,
     216,   217,   350,    -1,   210,   209,   350,    81,   218,   217,
     350,    -1,   210,   209,   350,   202,   350,    -1,   210,   209,
     350,   203,   350,    -1,   210,   211,   350,   217,   350,    -1,
     210,   211,   350,    81,   216,   217,   350,    -1,   210,   211,
     350,    81,   218,   217,   350,    -1,   210,   211,   350,   202,
     350,    -1,   210,   211,   350,   203,   350,    -1,   208,   209,
     350,    -1,   208,   211,   350,    -1,   213,   209,   350,   221,
     350,    -1,   213,   214,   215,   209,   350,   221,   350,    -1,
     212,   209,   350,    81,   350,    -1,   220,   105,   495,   219,
     350,   169,   350,    -1,   496,    -1,   495,    94,   105,   496,
      -1,   502,   127,   350,    -1,   222,   137,   350,   167,   498,
      -1,   499,    -1,   498,   499,    -1,   223,   140,   429,   170,
     345,    -1,   223,   140,   429,    94,   105,   502,   170,   345,
      -1,   223,   140,   429,    94,   105,   502,    94,   105,   502,
     170,   345,    -1,   223,   140,   429,    94,   105,   502,    94,
     105,   502,    94,   105,   502,   170,   345,    -1,    20,    -1,
      18,    -1,    18,    -1,   198,    -1,   112,    -1,    84,    -1,
      37,    -1,    72,    -1,    34,    -1,   136,    -1,    45,    -1,
     209,    -1,    46,    -1,    75,    -1,    71,    -1,    36,    -1,
      33,    -1,   194,    -1,    76,    -1,   228,    -1,    70,    -1,
     206,    -1,   205,    -1,   130,    -1,    35,    -1,   240,    -1,
     227,    -1,   230,    -1,   229,    -1,   257,    -1,   258,    -1,
     261,    -1,   259,    -1,   262,    -1,   233,    -1,   235,    -1,
      53,    -1,   201,    -1,   234,    -1,    47,    -1,   207,    -1,
     220,    -1,   214,    -1,   186,    -1,   191,    -1,   190,    -1,
     189,    -1,   188,    -1,   187,    -1,    83,    -1,    98,    -1,
      99,    -1,   169,    -1,    60,    -1,    61,    -1,    62,    -1,
      63,    -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,
      68,    -1,   131,    -1,    57,    -1,   195,    -1,   154,    -1,
     155,    -1,   153,    -1,    50,    -1,    82,    -1,   103,    -1,
     113,    -1,   114,    -1,    93,    -1,    49,    -1,   120,    -1,
     171,    -1,    87,    -1,    81,    -1,   181,    -1,   111,    -1,
     151,    -1,    79,    -1,    74,    -1,   215,    -1,    88,    -1,
     182,    -1,   104,    -1,   143,    -1,   184,    -1,   134,    -1,
     121,    -1,    32,    -1,    89,    -1,   183,    -1,   135,    -1,
     165,    -1,   179,    -1,   144,    -1,   122,    -1,   116,    -1,
     150,    -1,   132,    -1,   149,    -1,    38,    -1,    58,    -1,
      69,    -1,   100,    -1,    73,    -1,    52,    -1,   199,    -1,
      48,    -1,    54,    -1,    51,    -1,    39,    -1,   250,    -1,
     239,    -1,   255,    -1,   256,    -1,   232,    -1,   245,    -1,
     253,    -1,   249,    -1,   231,    -1,   244,    -1,   254,    -1,
     248,    -1,   243,    -1,   242,    -1,   226,    -1,   225,    -1,
     247,    -1,   236,    -1,   237,    -1,   260,    -1,   252,    -1,
     251,    -1,   246,    -1,   213,    -1,   219,    -1,   216,    -1,
     210,    -1,   203,    -1,   202,    -1,   204,    -1,   221,    -1,
     211,    -1,   212,    -1,   218,    -1,   208,    -1,   217,    -1,
      44,    -1,    41,    -1,    40,    -1,    42,    -1,    43,    -1,
     152,    -1,   185,    -1,    26,    -1,    27,    -1,    29,    -1,
      31,    -1,    28,    -1,    30,    -1,   222,    -1,   223,    -1,
      59,    -1,   224,    -1,    56,    -1,   267,    -1,   263,    -1,
     264,    -1,   266,    -1,   270,    -1,   268,    -1,   269,    -1,
     265,    -1,   224,   105,   369,    59,   137,   350,   167,    -1,
      59,   137,   350,   167,    -1,   506,    -1,   506,   505,    -1,
     506,   255,   400,    -1,   506,   505,   255,   400,    -1,   515,
      -1,   513,    -1,   505,   515,    -1,   505,   513,    -1,   507,
      -1,   506,   241,   507,    -1,   508,    -1,   507,   238,   508,
      -1,   509,    -1,   508,   240,   131,   509,    -1,   510,    -1,
     240,   510,    -1,   511,    -1,   511,   534,    -1,   140,   504,
     170,    -1,   512,    -1,   512,   530,    -1,   435,    -1,   137,
     347,   167,    -1,   514,    -1,   533,    -1,   532,    -1,   535,
      -1,   529,    -1,   152,    -1,   516,    -1,   517,    -1,   518,
      -1,   519,    -1,   522,    -1,   527,    -1,   528,    -1,   244,
      -1,   254,    -1,    87,   227,    -1,    87,   230,    -1,   221,
     229,    -1,   257,   229,    -1,   229,   227,    -1,   229,   230,
      -1,   221,   258,    -1,   257,   258,    -1,   221,   261,   521,
      -1,   221,   261,   100,    -1,   221,   261,   140,   521,   170,
      -1,   221,   261,   140,   521,    94,   520,   170,    -1,   221,
     261,   140,   100,   170,    -1,   221,   261,   140,   100,    94,
     520,   170,    -1,   257,   261,    -1,   521,    -1,   520,    94,
     521,    -1,    83,    20,    -1,    83,    20,   248,    20,    -1,
      83,    20,   531,   243,    -1,    83,    20,   248,    20,   531,
     243,    -1,   221,   259,   260,   524,    -1,   221,   259,   260,
     524,   523,    -1,   221,   100,   259,   260,    -1,   221,   100,
     259,   260,   523,    -1,   257,   259,   260,    -1,   526,    -1,
     523,   526,    -1,    83,    20,    -1,   140,   525,   170,    -1,
      20,    -1,   525,    20,    -1,   184,   524,    -1,   121,   524,
      -1,   242,    20,    -1,   221,   262,    -1,   257,   262,    -1,
      83,   201,    -1,    83,   234,    -1,   233,   235,    -1,   226,
      -1,   226,    53,    -1,   225,    -1,   225,   260,    -1,   247,
      -1,   236,   403,    -1,    83,   114,   403,    -1,    83,    47,
     403,    -1,   237,   403,   182,   403,    -1,   232,   531,   536,
      -1,   256,   403,   536,    -1,   245,   531,   253,    -1,   249,
     537,    -1,   231,   537,    -1,   260,    -1,   252,    -1,   246,
      -1,   251,    -1,   246,    -1,   257,   235,   403,    -1
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
     292,   297,   304,   306,   308,   311,   313,   316,   318,   321,
     329,   331,   335,   337,   340,   343,   347,   351,   355,   358,
     362,   367,   373,   376,   381,   385,   386,   392,   396,   402,
     405,   408,   412,   416,   420,   423,   427,   431,   433,   436,
     439,   442,   447,   452,   457,   459,   463,   466,   470,   474,
     478,   480,   482,   485,   487,   491,   493,   497,   499,   501,
     503,   505,   507,   509,   511,   513,   515,   517,   519,   521,
     523,   525,   527,   529,   531,   533,   536,   539,   542,   545,
     547,   549,   552,   557,   561,   567,   572,   576,   578,   580,
     582,   584,   586,   588,   590,   592,   594,   597,   600,   604,
     607,   609,   614,   618,   623,   628,   634,   639,   645,   651,
     658,   662,   666,   670,   672,   677,   679,   684,   688,   693,
     698,   704,   709,   715,   717,   720,   724,   726,   729,   731,
     738,   742,   746,   748,   751,   755,   757,   761,   764,   768,
     771,   775,   780,   782,   786,   788,   791,   793,   795,   797,
     800,   803,   806,   810,   812,   814,   817,   820,   823,   829,
     835,   837,   842,   846,   851,   860,   871,   873,   876,   881,
     889,   898,   900,   904,   906,   910,   912,   916,   920,   924,
     928,   929,   934,   938,   942,   946,   948,   952,   957,   959,
     963,   965,   969,   973,   975,   979,   983,   987,   991,   993,
     997,  1001,  1003,  1007,  1011,  1013,  1018,  1020,  1025,  1027,
    1032,  1034,  1039,  1041,  1044,  1046,  1048,  1051,  1054,  1056,
    1058,  1060,  1062,  1064,  1066,  1068,  1070,  1072,  1074,  1076,
    1078,  1083,  1089,  1095,  1102,  1106,  1111,  1113,  1116,  1120,
    1123,  1125,  1128,  1131,  1133,  1135,  1137,  1141,  1145,  1147,
    1149,  1151,  1154,  1156,  1159,  1162,  1164,  1166,  1168,  1170,
    1172,  1174,  1176,  1178,  1180,  1183,  1186,  1188,  1190,  1192,
    1194,  1196,  1198,  1200,  1202,  1204,  1206,  1208,  1210,  1212,
    1214,  1217,  1219,  1222,  1226,  1228,  1230,  1232,  1234,  1236,
    1238,  1240,  1242,  1244,  1246,  1248,  1250,  1252,  1255,  1258,
    1262,  1264,  1269,  1274,  1278,  1283,  1285,  1289,  1291,  1293,
    1295,  1297,  1299,  1304,  1310,  1319,  1329,  1339,  1350,  1352,
    1355,  1357,  1360,  1367,  1368,  1370,  1374,  1378,  1379,  1381,
    1383,  1385,  1388,  1391,  1392,  1394,  1396,  1398,  1401,  1404,
    1406,  1408,  1410,  1412,  1414,  1416,  1418,  1420,  1422,  1424,
    1426,  1428,  1432,  1435,  1439,  1443,  1446,  1448,  1450,  1452,
    1454,  1456,  1458,  1463,  1468,  1474,  1481,  1489,  1494,  1500,
    1507,  1515,  1520,  1525,  1530,  1536,  1543,  1551,  1553,  1556,
    1559,  1561,  1564,  1568,  1570,  1572,  1574,  1576,  1578,  1582,
    1584,  1586,  1588,  1590,  1592,  1594,  1596,  1598,  1600,  1602,
    1606,  1610,  1615,  1620,  1624,  1628,  1632,  1637,  1642,  1646,
    1651,  1658,  1663,  1670,  1674,  1678,  1683,  1690,  1697,  1702,
    1709,  1716,  1721,  1723,  1726,  1728,  1732,  1736,  1740,  1746,
    1754,  1762,  1768,  1774,  1780,  1788,  1796,  1802,  1808,  1812,
    1816,  1822,  1830,  1836,  1844,  1846,  1851,  1855,  1861,  1863,
    1866,  1872,  1881,  1893,  1908,  1910,  1912,  1914,  1916,  1918,
    1920,  1922,  1924,  1926,  1928,  1930,  1932,  1934,  1936,  1938,
    1940,  1942,  1944,  1946,  1948,  1950,  1952,  1954,  1956,  1958,
    1960,  1962,  1964,  1966,  1968,  1970,  1972,  1974,  1976,  1978,
    1980,  1982,  1984,  1986,  1988,  1990,  1992,  1994,  1996,  1998,
    2000,  2002,  2004,  2006,  2008,  2010,  2012,  2014,  2016,  2018,
    2020,  2022,  2024,  2026,  2028,  2030,  2032,  2034,  2036,  2038,
    2040,  2042,  2044,  2046,  2048,  2050,  2052,  2054,  2056,  2058,
    2060,  2062,  2064,  2066,  2068,  2070,  2072,  2074,  2076,  2078,
    2080,  2082,  2084,  2086,  2088,  2090,  2092,  2094,  2096,  2098,
    2100,  2102,  2104,  2106,  2108,  2110,  2112,  2114,  2116,  2118,
    2120,  2122,  2124,  2126,  2128,  2130,  2132,  2134,  2136,  2138,
    2140,  2142,  2144,  2146,  2148,  2150,  2152,  2154,  2156,  2158,
    2160,  2162,  2164,  2166,  2168,  2170,  2172,  2174,  2176,  2178,
    2180,  2182,  2184,  2186,  2188,  2190,  2192,  2194,  2196,  2198,
    2200,  2202,  2204,  2206,  2208,  2210,  2212,  2214,  2216,  2218,
    2220,  2222,  2224,  2226,  2228,  2230,  2232,  2234,  2236,  2238,
    2240,  2242,  2244,  2246,  2248,  2250,  2252,  2254,  2256,  2258,
    2260,  2262,  2270,  2275,  2277,  2280,  2284,  2289,  2291,  2293,
    2296,  2299,  2301,  2305,  2307,  2311,  2313,  2318,  2320,  2323,
    2325,  2328,  2332,  2334,  2337,  2339,  2343,  2345,  2347,  2349,
    2351,  2353,  2355,  2357,  2359,  2361,  2363,  2365,  2367,  2369,
    2371,  2373,  2376,  2379,  2382,  2385,  2388,  2391,  2394,  2397,
    2401,  2405,  2411,  2419,  2425,  2433,  2436,  2438,  2442,  2445,
    2450,  2455,  2462,  2467,  2473,  2478,  2484,  2488,  2490,  2493,
    2496,  2500,  2502,  2505,  2508,  2511,  2514,  2517,  2520,  2523,
    2526,  2529,  2531,  2534,  2536,  2539,  2541,  2544,  2548,  2552,
    2557,  2561,  2565,  2569,  2572,  2575,  2577,  2579,  2581,  2583,
    2585
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   881,   881,   882,   892,   897,   903,   908,   920,   925,
     935,   942,   954,   966,   978,   984,   990,  1002,  1008,  1022,
    1028,  1042,  1043,  1044,  1045,  1051,  1052,  1053,  1054,  1057,
    1060,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1076,  1083,
    1084,  1096,  1108,  1113,  1124,  1130,  1142,  1155,  1166,  1171,
    1183,  1188,  1199,  1205,  1211,  1217,  1236,  1247,  1258,  1265,
    1272,  1279,  1292,  1298,  1313,  1317,  1327,  1333,  1340,  1346,
    1358,  1365,  1371,  1378,  1384,  1388,  1395,  1406,  1410,  1418,
    1427,  1434,  1444,  1446,  1453,  1461,  1465,  1473,  1477,  1485,
    1493,  1497,  1505,  1509,  1516,  1523,  1533,  1538,  1550,  1554,
    1558,  1562,  1569,  1576,  1595,  1606,  1612,  1619,  1626,  1638,
    1642,  1649,  1653,  1657,  1664,  1668,  1674,  1681,  1685,  1689,
    1697,  1704,  1713,  1725,  1739,  1747,  1761,  1767,  1779,  1787,
    1798,  1809,  1813,  1825,  1829,  1838,  1842,  1858,  1859,  1860,
    1861,  1862,  1865,  1866,  1867,  1868,  1869,  1871,  1872,  1875,
    1876,  1877,  1878,  1879,  1882,  1889,  1898,  1905,  1909,  1917,
    1921,  1925,  1932,  1936,  1943,  1948,  1957,  1966,  1967,  1968,
    1972,  1972,  1972,  1972,  1972,  1975,  1981,  1990,  1994,  2004,
    2015,  2021,  2035,  2042,  2050,  2059,  2069,  2077,  2086,  2095,
    2110,  2122,  2133,  2145,  2151,  2163,  2169,  2183,  2191,  2200,
    2208,  2220,  2226,  2236,  2237,  2241,  2249,  2253,  2258,  2262,
    2266,  2270,  2277,  2292,  2300,  2310,  2316,  2327,  2333,  2342,
    2352,  2357,  2369,  2375,  2389,  2395,  2407,  2414,  2421,  2428,
    2435,  2442,  2449,  2462,  2466,  2476,  2481,  2492,  2503,  2510,
    2523,  2530,  2542,  2548,  2561,  2568,  2582,  2588,  2600,  2606,
    2619,  2630,  2634,  2645,  2649,  2668,  2672,  2680,  2688,  2696,
    2704,  2704,  2712,  2720,  2728,  2742,  2746,  2753,  2766,  2770,
    2781,  2785,  2789,  2799,  2803,  2807,  2811,  2815,  2825,  2829,
    2834,  2845,  2849,  2853,  2863,  2867,  2879,  2883,  2895,  2899,
    2911,  2915,  2927,  2931,  2943,  2947,  2951,  2955,  2967,  2971,
    2975,  2985,  2989,  2993,  2997,  3001,  3005,  3015,  3019,  3023,
    3033,  3037,  3041,  3045,  3057,  3063,  3075,  3081,  3095,  3102,
    3143,  3147,  3151,  3155,  3167,  3177,  3188,  3193,  3203,  3207,
    3217,  3223,  3229,  3235,  3247,  3253,  3264,  3268,  3272,  3276,
    3280,  3284,  3288,  3298,  3302,  3312,  3318,  3330,  3334,  3338,
    3342,  3346,  3361,  3365,  3375,  3379,  3389,  3396,  3403,  3416,
    3420,  3432,  3438,  3452,  3463,  3467,  3471,  3475,  3479,  3483,
    3487,  3491,  3501,  3505,  3515,  3520,  3525,  3536,  3546,  3550,
    3561,  3571,  3582,  3638,  3644,  3656,  3662,  3674,  3678,  3688,
    3692,  3696,  3706,  3714,  3722,  3730,  3738,  3746,  3761,  3767,
    3779,  3785,  3798,  3807,  3809,  3815,  3820,  3832,  3835,  3842,
    3848,  3854,  3862,  3877,  3880,  3887,  3893,  3899,  3907,  3921,
    3926,  3937,  3942,  3953,  3958,  3963,  3969,  3981,  3987,  3992,
    3997,  4008,  4013,  4028,  4033,  4050,  4065,  4069,  4073,  4077,
    4081,  4085,  4095,  4106,  4112,  4118,  4123,  4145,  4151,  4157,
    4162,  4173,  4183,  4193,  4199,  4205,  4210,  4221,  4227,  4239,
    4251,  4257,  4263,  4300,  4305,  4310,  4321,  4325,  4329,  4339,
    4350,  4354,  4358,  4362,  4366,  4370,  4374,  4378,  4382,  4392,
    4402,  4406,  4411,  4422,  4432,  4442,  4446,  4450,  4460,  4466,
    4472,  4478,  4484,  4496,  4507,  4514,  4521,  4528,  4535,  4542,
    4549,  4562,  4583,  4590,  4610,  4650,  4655,  4658,  4666,  4672,
    4678,  4684,  4690,  4697,  4703,  4709,  4715,  4721,  4733,  4738,
    4748,  4754,  4766,  4792,  4803,  4809,  4822,  4836,  4843,  4850,
    4861,  4868,  4876,  4885,  4898,  4901,  4919,  4920,  4921,  4922,
    4923,  4924,  4925,  4926,  4927,  4928,  4929,  4930,  4931,  4932,
    4933,  4934,  4935,  4936,  4937,  4938,  4939,  4940,  4941,  4942,
    4943,  4944,  4945,  4946,  4947,  4948,  4949,  4950,  4951,  4952,
    4953,  4954,  4955,  4956,  4957,  4958,  4959,  4960,  4961,  4962,
    4963,  4964,  4965,  4966,  4967,  4968,  4969,  4970,  4971,  4972,
    4973,  4974,  4975,  4976,  4977,  4978,  4979,  4980,  4981,  4982,
    4983,  4984,  4985,  4986,  4987,  4988,  4989,  4990,  4991,  4992,
    4993,  4994,  4995,  4996,  4997,  4998,  4999,  5000,  5001,  5002,
    5003,  5004,  5005,  5006,  5007,  5008,  5009,  5010,  5011,  5012,
    5013,  5014,  5015,  5016,  5017,  5018,  5019,  5020,  5021,  5022,
    5023,  5024,  5025,  5026,  5027,  5028,  5029,  5030,  5031,  5032,
    5033,  5034,  5035,  5036,  5037,  5038,  5039,  5040,  5041,  5042,
    5043,  5044,  5045,  5046,  5047,  5048,  5049,  5050,  5051,  5052,
    5053,  5054,  5055,  5056,  5057,  5058,  5059,  5060,  5061,  5062,
    5063,  5064,  5065,  5066,  5067,  5068,  5069,  5070,  5071,  5072,
    5073,  5074,  5075,  5076,  5077,  5078,  5079,  5080,  5081,  5082,
    5083,  5084,  5085,  5086,  5087,  5088,  5089,  5090,  5091,  5092,
    5093,  5104,  5110,  5127,  5131,  5135,  5139,  5149,  5152,  5155,
    5158,  5167,  5170,  5179,  5182,  5191,  5194,  5203,  5206,  5215,
    5218,  5221,  5230,  5233,  5242,  5246,  5256,  5259,  5262,  5265,
    5268,  5277,  5286,  5290,  5294,  5298,  5302,  5306,  5310,  5320,
    5323,  5326,  5329,  5338,  5341,  5344,  5347,  5356,  5359,  5368,
    5371,  5374,  5377,  5380,  5383,  5386,  5395,  5398,  5407,  5410,
    5413,  5416,  5425,  5428,  5431,  5434,  5437,  5446,  5449,  5458,
    5461,  5470,  5473,  5482,  5485,  5494,  5503,  5506,  5515,  5518,
    5521,  5530,  5533,  5536,  5539,  5542,  5551,  5555,  5559,  5563,
    5573,  5582,  5592,  5601,  5604,  5613,  5616,  5619,  5628,  5631,
    5640
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
  const int xquery_parser::yylast_ = 8584;
  const int xquery_parser::yynnts_ = 253;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 481;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 286;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 540;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5648 "/home/vinayakb/work/repositories/external/zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"


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

